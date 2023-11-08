using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;
using XmiToCode.Messages;
using static XmiToCode.Codegen.CodeGenerationHelper;
using XmiToCode.Transformation;
using XmiToCode.Parsing.Model;
using XmiToCode.Codegen.Model;

namespace XmiToCode.Codegen.C;

public class CWriter : ICodeWriter
{
    protected readonly string _outputDir;

    public CWriter(string outputDir)
    {
        _outputDir = outputDir;

        var outDir = new DirectoryInfo(_outputDir);
        if (!outDir.Exists) outDir.Create();
    }

    public async Task WriteCommonFilesAsync(GlobalContext global) {
        var filename = $"{_outputDir}/eulynx_common.h";

        using var file = File.Create(filename);
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(WriteCommonHeader(global));
    }

    public async Task WritePackageFilesAsync(Package pkg) {
        foreach (var klass in pkg.TryParseAllClasses()) {
            await WriteClassFilesAsync(new ClassTransformer(klass).TransformClassIntoFile(), pkg);
        }

        var classes = pkg.TryParseAllClasses().Select(klass => new ClassTransformer(klass).TransformClassIntoFile()).ToList();

        if (classes.Count > 0) {
            Console.WriteLine($"Package {pkg.Name.Name} - successfully generated {classes.Count} classes:");
            foreach (var success in classes.Select(x => x.ClassName.Name))
                Console.WriteLine($"   - {success}");
            Console.WriteLine();
        }
    }


    private string WriteCommonHeader(GlobalContext global) {
        return @$"
#include <stdbool.h>
#include <string.h>

#define MessagePort(X) struct {{ bool HasMessage; X Value; }}

typedef struct PulsedIn
{{
    bool IsTriggered;
}} PulsedIn;

typedef struct PulsedOut
{{
    bool Trigger;
}} PulsedOut;

typedef struct ChangeEvent
{{
  int IsTriggered;
}} ChangeEvent;

typedef struct TimeoutEvent
{{
  int IsTimeoutExpired;
}} TimeoutEvent;

// Enumerations
{string.Join("\n", global.Enumerations.Values.Select(x => WriteGlobalEnumeration(x)))}

// Message Types
{JoinLines(global.Messages.Select(x => WriteMessageSchema(x.Value)))}
";
    }

    public virtual async Task WriteClassFilesAsync(ClassFile klass, Package pkg)
    {
        var cFilename = $"{_outputDir}/{pkg.Name.Name}/{klass.ClassName.Name}.c";

        var fileinfo = new FileInfo(cFilename);
        if (fileinfo.Directory != null && !fileinfo.Directory.Exists) fileinfo.Directory.Create();

        using var file = File.Create(cFilename);
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(Write(klass));

        var headerFilename = $"{_outputDir}/{pkg.Name.Name}/{klass.ClassName.Name}.h";
        using var headerFile = File.Create(headerFilename);
        using var headerWriter = new StreamWriter(headerFile);

        await headerWriter.WriteAsync(WriteHeader(klass));
    }

    public string Write<T>(T element)
    {
        return element switch
        {
            Model.ValueType valueType => WriteValueType(valueType),
            ClassFile klass => WriteClass(klass),
            null => "",
            _ => throw new NotImplementedException($"Writing not implemented for {element.GetType()}")
        };
    }

    private static string WriteOperation(Operation operation, ClassFile klass)
    {
        return @$"void {operation.Identifier.Name}({klass.ClassName.Name} *self) {{
            {JoinLines(operation.Instructions.Select(x => x.ToC(klass.ClassContext)))}
        }}";
    }

    private string WriteMessageSchema(MessageSchema messageSchema)
    {
        return @$"
        {string.Join("\n", messageSchema.GetValueTypes().Select(x => Write(x)))}

        /// {messageSchema.Identifier.RawName}
        /// UML Identifier: {messageSchema.Signal.Id}
        typedef struct Message__{messageSchema.Identifier.Name} {{
            {string.Join("\n", messageSchema.Members.Select(x => $"{x.DataType(TargetLanguage.C).Item1} {x.Identifier.Name}{x.DataType(TargetLanguage.C).Item2};"))}
        }} Message__{messageSchema.Identifier.Name};";
    }

    private static string WriteValueType(Model.ValueType valueType)
    {
        return @$"typedef enum {valueType.Identifier.Name}Value {{
            {string.Join(",\n", valueType.AllowedValues.Select(x => $"{valueType.Identifier.Name}Value__{x.Name}"))}
        }} {valueType.Identifier.Name}Value;";
    }

    private static string WriteGlobalEnumeration(GlobalEnumeration globalEnumeration)
    {
        return @$"/// {globalEnumeration.Name.RawName}
        /// UML Identifier: {globalEnumeration.Enumeration.Id}
        typedef enum {globalEnumeration.Name.Name} {{
            {string.Join(",\n\n", globalEnumeration.Members.Select(x => @$"/// {x.RawName}
            {globalEnumeration.Name.Name}__{x.Name}"))}
        }} {globalEnumeration.Name.Name};
        ";
    }

    protected virtual string WriteClass(ClassFile klass)
    {
        var states = PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior))
            .Where(x => x.record.State != null)
            .ToDictionary(x => x.record.State!, x => x.Name);

        return @$"
#include ""{klass.ClassName.Name}.h""

// Operations

{string.Join("\n", klass.Operations.Select(x => WriteOperation(x, klass)))}

{WriteBehaviorRecord(klass.Behavior, states)}

void new_{klass.ClassName.Name}({klass.ClassName.Name} *x) {{
    x->state = make_state_{klass.BehaviorName.Name}(x);
}}

{string.Join("\n", klass.TransitionFunctions.Select(x => WriteTransitionFunction(x, states)))}

void evaluateChangeEvents({klass.ClassName.Name} *self) {{
    {string.Join("\n", klass.GetChangeEvents().Select(x => $"self->{x.Event.Name}.IsTriggered = ({x.Condition.Accessor(klass.ClassContext, TargetLanguage.C)});"))}
}}

void resetTriggers({klass.ClassName.Name} *self) {{
    {string.Join("\n", klass.GetIncomingMessageTypes().Select(x => $"self->In{x.Identifier.Name}.HasMessage = false;"))}

    {string.Join("\n", klass.GetPropertiesAndPorts().Values.OfType<PropertyOrPort.PulsedInPropertyOrPort>().Select(x => $"self->{x.Identifier.Name}.IsTriggered = false;"))}

    {string.Join("\n", klass.GetTimeoutEvents().Select(x => $"self->{x}.IsTimeoutExpired = false;"))}
}}

void transition_{klass.ClassName.Name}({klass.ClassName.Name} *self) {{
  evaluateChangeEvents(self);

  switch (self->state)
  {{
        {string.Join("\n", PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior)).Select(t =>
            $"case {t.Name}: \n self->state = transition_from_{t.Name}(self);\nbreak;"))}
  }}

  resetTriggers(self);
}}
";
    }

    private string WriteBehaviorRecord(BehaviorRecord behaviorRecord, Dictionary<IState, string> states)
    {
        return
            string.Join("\n", PrefixWith(behaviorRecord, EnumerateSubrecords(behaviorRecord))
                .Append((behaviorRecord.Name, behaviorRecord))
                .Select(x => x.record switch {
                    SimpleBehaviorRecord simple => $@"
                        {behaviorRecord.Name} make_state_{x.Name} ({simple.ClassName.Name} *self) {{
                            return {x.Name};
                        }}",
                    BehaviorRecord record => $@"
                        {behaviorRecord.Name} make_state_{x.Name}({record.ClassName.Name} *self) {{
                            {WriteICodeTransition(record.Initializer, states)}
                        }}",
                    _ => throw new NotImplementedException()
                }));
    }

    private string WriteICodeTransition(ICodeTransition initializer, Dictionary<IState, string> states)
    {
        return initializer switch
        {
            JunctionTransition j => WriteJunctionTransition(j, states),
            CodeTransition c => WriteCodeTransition(c, states),
            _ => throw new NotImplementedException()
        };
    }

    protected static IEnumerable<(string Name, IBehaviorRecord record)> PrefixWith(BehaviorRecord behaviorRecord, IEnumerable<(string Name, IBehaviorRecord record)> records) {
        foreach (var (Name, record) in records) {
            yield return ($"{behaviorRecord.Name}__{Name}", record);
        }
    }

    protected static IEnumerable<(string Name, IBehaviorRecord record)> EnumerateSubrecords(IBehaviorRecord record)
    {
        foreach (var s in record.Subrecords)
        {
            yield return (s.Name, s);
            foreach (var subsubrecord in EnumerateSubrecords(s))
            {
                yield return ($"{s.Name}__{subsubrecord.Name}", subsubrecord.record);
            }
        }
    }

    protected virtual string WriteTransitionFunction(TransitionFunction transitionFunction, Dictionary<IState, string> states)
    {
        return $@"{transitionFunction.TheRootBehaviorName.Name} transition_from_{transitionFunction.Name.Replace(".", "__")}({transitionFunction.ClassName.Name} *self) {{

            {string.Join("\n", transitionFunction.Transitions.Select(x => WriteICodeTransition(x, states)))}

            // Do not transition
            return self->state;
        }}
";
    }

    private static string WriteIfOrElse(List<IAccessible> expression, IProgramContext context) {
        if (expression.SingleOrDefault() is BooleanExpression.Else) {
            return "else";
        }

        if (expression.Count == 1) {
            return $"if ({expression.Single().Accessor(context, TargetLanguage.C)})";
        }

        var conditionsInParens = expression.Select(x => $"({x.Accessor(context, TargetLanguage.C)})");
        return $"if ({string.Join(" && ", conditionsInParens)})";
    }

    protected static string WrapWithGuard(Transition transition, List<IAccessible> c, IProgramContext context, string instructions) {
        var condition = transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self->In{messageEvent.MessageType.Name}.HasMessage)",
            InitialTransition => "", // TODO
            _ => throw new NotImplementedException()
        };

        var constraint = c.Count > 0 ? WriteIfOrElse(c, context) : null;

        var wrapWithIfElseExpression = (string? expr, string block) =>
            string.IsNullOrWhiteSpace(expr) ? block : @$"{expr} {{
                {block}
            }}";

        return wrapWithIfElseExpression(condition, wrapWithIfElseExpression(constraint, instructions));
    }

    private string WriteJunctionTransition(JunctionTransition junctionTransition, Dictionary<IState, string> states)
    {
        // Outgoing transitions must be sorted, so that the 'else' branch (if any) comes last
        var sortedTransitions = junctionTransition.CodeTransitions
            .OrderBy(x => x.Constraint.SingleOrDefault() is BooleanExpression.Else);

        return WrapWithGuard(junctionTransition.Transition, junctionTransition.Constraint, junctionTransition.context,
            $@"{string.Join("\n", junctionTransition.Activities.Select(x => x.ToC(junctionTransition.context)))}
                    {string.Join("\n", sortedTransitions.Select(x => WriteICodeTransition(x, states)))}"
        );
    }

    private static string WriteCodeTransition(CodeTransition codeTransition, Dictionary<IState, string> states)
    {
        return WrapWithGuard(codeTransition.Transition, codeTransition.Constraint, codeTransition.context,
            $@"{string.Join("\n", codeTransition.Activities.Select(x => x.ToC(codeTransition.context)))}
                return make_state_{states[codeTransition.Transition.To]}(self);"
        );
    }

    protected virtual string WriteHeader(ClassFile klass)
    {
        return @$"
#include ""../eulynx_common.h""

// Value Types

{string.Join("\n", klass.GetValueTypes().Select(x => Write(x)))}

{WriteBehaviorEnum(klass.Behavior)}

/// Contained in:
{JoinLines(klass.PackageHierarchy.Select(x => $"/// {x.Name}"))}
typedef struct {klass.ClassName.Name} {{
    {klass.BehaviorName.Name} state;

    {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => x.Value switch {
        PropertyOrPort.ComplexPropertyOrPort complex => null,
        _ => $@"// {x.Key.RawName}
        // Trigger: {x.Value.IsTriggerPort}, DataPort: {x.Value.IsDataPort}, In: {x.Value.IsInPort}, Out: {x.Value.IsOutPort}, External: {x.Value.IsExternalInterface}
        {x.Value.DataType(TargetLanguage.C).Item1} {x.Key.Name}{x.Value.DataType(TargetLanguage.C).Item2};
        "
        }))}

    // Messages -- Incoming
    {string.Join("\n", klass.GetIncomingMessageTypes().Select(x => $"MessagePort(Message__{x.Identifier.Name}) In{x.Identifier.Name};"))}
    // Messages -- Outgoing
    {string.Join("\n", klass.GetOutgoingMessageTypes().Select(x => $"MessagePort(Message__{x.Identifier.Name}) Out{x.Identifier.Name};"))}

    // Change Events
    {string.Join("\n", klass.GetChangeEvents().Select(x => $"ChangeEvent {x.Event.Name}; // {x.Event.ChangeExpression.Body.ReplaceLineEndings("")}"))}

    // Timeout Events
    {string.Join("\n", klass.GetTimeoutEvents().Select(x => $"TimeoutEvent {x};"))}

}} {klass.ClassName.Name};

void new_{klass.ClassName.Name}({klass.ClassName.Name} *x);
void transition_{klass.ClassName.Name}({klass.ClassName.Name} *self);

{WriteBehaviorFunctionSignatures(klass.Behavior)}
";
    }

    private static string WriteBehaviorEnum(BehaviorRecord behaviorRecord)
    {
        return @$"typedef enum {behaviorRecord.Name} {{
        {string.Join(",\n", PrefixWith(behaviorRecord, EnumerateSubrecords(behaviorRecord)).Select(x => x.Name))}
}} {behaviorRecord.Name};";
    }

    private static string WriteBehaviorFunctionSignatures(BehaviorRecord behaviorRecord) {
        return string.Join("\n", EnumerateSubrecords(behaviorRecord).Append((behaviorRecord.Name, behaviorRecord)).Select(x => $"{behaviorRecord.Name} make_state_{behaviorRecord.Name}__{x.Name} ({x.record.ClassName.Name} *self);"));
    }
}
