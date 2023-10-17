using XmiToCode.Accessibles;
using XmiToCode.Classes;
using XmiToCode.Context;
using XmiToCode.Messages;
using static XmiToCode.Codegen.CodeGenerationHelper;

namespace XmiToCode.Codegen.C;

public class CWriter : ICodeWriter
{
    public async Task WriteCommonFilesAsync(GlobalContext global) {
        var filename = $"../Eulynx/C/eulynx_common.h";

        using var file = File.Create(filename);
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(WriteCommonHeader(global));
    }

    public async Task WritePackageFilesAsync(Package pkg) {
        var packageDir = Path.Combine("../Eulynx/C/", pkg.Name.Name);

        foreach (var klass in pkg.Classes) {
            await WriteClassFilesAsync(klass, packageDir);
        }

        if (pkg.Classes.Count > 0) {
            Console.WriteLine($"Package {pkg.Name.Name} - successfully generated {pkg.Classes.Count} classes:");
            foreach (var success in pkg.Classes.Select(x => x.Info.ClassName))
                Console.WriteLine($"   - {success}");
            Console.WriteLine();
        }
    }


    private string WriteCommonHeader(GlobalContext global) {
        return @$"
#include <stdbool.h>
#include <string.h>

#define Option(X) struct {{ bool Some; X Value; }}

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

    public virtual async Task WriteClassFilesAsync(Class klass, string? prefix)
    {
        var cFilename = $"../Eulynx/C/{klass.Info.ClassName}.c";
        if (prefix != null) {
            cFilename = Path.Combine(prefix, $"{klass.Info.ClassName}.c");
        }

        var fileinfo = new FileInfo(cFilename);
        if (fileinfo.Directory != null && !fileinfo.Directory.Exists) fileinfo.Directory.Create();

        using var file = File.Create(cFilename);
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(Write(klass));

        var headerFilename = $"../Eulynx/C/{klass.Info.ClassName}.h";
        if (prefix != null) {
            headerFilename = Path.Combine(prefix, $"{klass.Info.ClassName}.h");
        }
        using var headerFile = File.Create(headerFilename);
        using var headerWriter = new StreamWriter(headerFile);

        await headerWriter.WriteAsync(WriteHeader(klass));
    }

    public string Write<T>(T element)
    {
        return element switch
        {
            Classes.ValueType valueType => WriteValueType(valueType),
            Class klass => WriteClass(klass),
            null => "",
            _ => throw new NotImplementedException($"Writing not implemented for {element.GetType()}")
        };
    }

    private string WriteOperation(Operation operation, Class klass)
    {
        return @$"void {operation.Identifier.Name}({klass.Info.ClassName} *self) {{
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

    private string WriteValueType(Classes.ValueType valueType)
    {
        return @$"typedef enum {valueType.Identifier.Name}Value {{
            {string.Join(",\n", valueType.AllowedValues.Select(x => $"{valueType.Identifier.Name}Value__{x.Name}"))}
        }} {valueType.Identifier.Name}Value;";
    }

    private string WriteGlobalEnumeration(GlobalEnumeration globalEnumeration)
    {
        return @$"/// {globalEnumeration.Name.RawName}
        /// UML Identifier: {globalEnumeration.Enumeration.Id}
        typedef enum {globalEnumeration.Name.Name} {{
            {string.Join(",\n\n", globalEnumeration.Members.Select(x => @$"/// {x.RawName}
            {globalEnumeration.Name.Name}__{x.Name}"))}
        }} {globalEnumeration.Name.Name};
        ";
    }

    protected virtual string WriteClass(Class klass)
    {
        var states = PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior))
            .Where(x => x.record.State != null)
            .ToDictionary(x => x.record.State!, x => x.Name);

        return @$"
#include ""{klass.Info.ClassName}.h""

// Operations

{string.Join("\n", klass.Operations.Select(x => WriteOperation(x, klass)))}

{WriteBehaviorRecord(klass.Behavior, states)}

void new_{klass.Info.ClassName}({klass.Info.ClassName} *x) {{
    x->state = make_state_{klass.Info.BehaviorName}(x);
}}

{string.Join("\n", klass.TransitionFunctions.Select(x => WriteTransitionFunction(x, states)))}

void evaluateChangeEvents({klass.Info.ClassName} *self) {{
    {string.Join("\n", klass.GetChangeEvents().Select(x => $"self->{x.Event.Name}.IsTriggered = ({x.Condition.Accessor(klass.ClassContext, TargetLanguage.C)});"))}
}}

void resetTriggers({klass.Info.ClassName} *self) {{
    {string.Join("\n", klass.GetIncomingMessageTypes().Select(x => $"self->In{x.Identifier.Name}.Some = false;"))}

    {string.Join("\n", klass.GetPropertiesAndPorts().Values.OfType<PropertyOrPort.PulsedInPropertyOrPort>().Select(x => $"self->{x.Identifier.Name}.IsTriggered = false;"))}

    {string.Join("\n", klass.GetTimeoutEvents().Select(x => $"self->{x}.IsTimeoutExpired = false;"))}
}}

void transition_{klass.Info.ClassName}({klass.Info.ClassName} *self) {{
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
                        {behaviorRecord.Name} make_state_{x.Name} ({simple.className.ClassName} *self) {{
                            return {x.Name};
                        }}",
                    BehaviorRecord record => $@"
                        {behaviorRecord.Name} make_state_{x.Name}({record.className.ClassName} *self) {{
                            {WriteICodeTransition(record.initializer, states)}
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
        foreach (var s in record.subrecords)
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
        return $@"{transitionFunction.TheRootBehaviorName.BehaviorName} transition_from_{transitionFunction.Name.Replace(".", "__")}({transitionFunction.TheRootBehaviorName.ClassName} *self) {{

            {string.Join("\n", transitionFunction.Transitions.Select(x => WriteICodeTransition(x, states)))}

            // Do not transition
            return self->state;
        }}
";
    }

    private string WriteIfOrElse(List<IAccessible> expression, IProgramContext context) {
        if (expression.SingleOrDefault() is BooleanExpression.Else) {
            return "else";
        }

        var conditionsInParens = expression.Select(x => $"({x.Accessor(context, TargetLanguage.C)})");
        return $"if ({string.Join(" && ", conditionsInParens)})";
    }

    protected string WrapWithGuard(Transition transition, List<IAccessible> c, IProgramContext context, string instructions) {
        var condition = transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self->In{messageEvent.MessageType.Name}.Some)",
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

    private string WriteCodeTransition(CodeTransition codeTransition, Dictionary<IState, string> states)
    {
        return WrapWithGuard(codeTransition.Transition, codeTransition.Constraint, codeTransition.context,
            $@"{string.Join("\n", codeTransition.Activities.Select(x => x.ToC(codeTransition.context)))}
                return make_state_{states[codeTransition.Transition.To]}(self);"
        );
    }

    protected virtual string WriteHeader(Class klass)
    {
        return @$"
#include ""../eulynx_common.h""

// Value Types

{string.Join("\n", klass.GetValueTypes().Select(x => Write(x)))}

{WriteBehaviorEnum(klass.Behavior)}

/// Contained in:
{JoinLines(klass.PackageHierarchy.Select(x => $"/// {x.Name}"))}
typedef struct {klass.Info.ClassName} {{
    {klass.Info.BehaviorName} state;

    {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => x.Value switch {
        PropertyOrPort.ComplexPropertyOrPort complex => null,
        _ => $@"// {x.Key.RawName}
        // Trigger: {x.Value.IsTriggerPort}, DataPort: {x.Value.IsDataPort}, In: {x.Value.IsInPort}, Out: {x.Value.IsOutPort}, External: {x.Value.IsExternalInterface}
        {x.Value.DataType(TargetLanguage.C).Item1} {x.Key.Name}{x.Value.DataType(TargetLanguage.C).Item2};
        "
        }))}

    // Messages -- Incoming
    {string.Join("\n", klass.GetIncomingMessageTypes().Select(x => $"Option(Message__{x.Identifier.Name}) In{x.Identifier.Name};"))}
    // Messages -- Outgoing
    {string.Join("\n", klass.GetOutgoingMessageTypes().Select(x => $"Option(Message__{x.Identifier.Name}) Out{x.Identifier.Name};"))}

    // Change Events
    {string.Join("\n", klass.GetChangeEvents().Select(x => $"ChangeEvent {x.Event.Name}; // {x.Event.ChangeExpression.Body.ReplaceLineEndings("")}"))}

    // Timeout Events
    {string.Join("\n", klass.GetTimeoutEvents().Select(x => $"TimeoutEvent {x};"))}

}} {klass.Info.ClassName};

void new_{klass.Info.ClassName}({klass.Info.ClassName} *x);
void transition_{klass.Info.ClassName}({klass.Info.ClassName} *self);

{WriteBehaviorFunctionSignatures(klass.Behavior)}
";
    }

    private string WriteBehaviorEnum(BehaviorRecord behaviorRecord)
    {
        return @$"typedef enum {behaviorRecord.Name} {{
        {string.Join(",\n", PrefixWith(behaviorRecord, EnumerateSubrecords(behaviorRecord)).Select(x => x.Name))}
}} {behaviorRecord.Name};";
    }

    private string WriteBehaviorFunctionSignatures(BehaviorRecord behaviorRecord) {
        return string.Join("\n", EnumerateSubrecords(behaviorRecord).Append((behaviorRecord.Name, behaviorRecord)).Select(x => $"{behaviorRecord.Name} make_state_{behaviorRecord.Name}__{x.Name} ({x.record.className.ClassName} *self);"));
    }

    public virtual Task WriteClassFilesAsync(UmlClass umlClass, Class klass)
    {
        return WriteClassFilesAsync(klass, null);
    }
}
