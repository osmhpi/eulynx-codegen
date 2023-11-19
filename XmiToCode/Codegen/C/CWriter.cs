using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;
using XmiToCode.Messages;
using static XmiToCode.Codegen.CodeGenerationHelper;
using XmiToCode.Transformation;
using XmiToCode.Parsing.Model;
using XmiToCode.Codegen.Model;
using XmiToCode.Parsing.XmiModel;

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

    public async Task WriteCommonFilesAsync(GlobalContext global, List<Parsing.XmiModel.PackagedElement> interestingPackages) {
        var filename = $"{_outputDir}/eulynx_common.h";

        foreach (var umlPackage in interestingPackages) {
            var pkg = Package.CreateFromUml(umlPackage, global);
            // This has side effects
            pkg.TryParseAllClasses();
        }

        using var file = File.Create(filename);
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(WriteCommonHeader(global));
    }

    public async Task WritePackageFilesAsync(Package pkg) {
        var successfulClassNames = new List<string>();
        foreach (var klass in pkg.TryParseAllClasses()) {
            var transfomer = new ClassTransformer(klass);
            var classFile = transfomer.TransformClassIntoFile();
            await WriteClassFilesAsync(classFile, pkg);
            successfulClassNames.Add(klass.ClassName.Name);
        }

        if (successfulClassNames.Count > 0) {
            Console.WriteLine($"Package {pkg.Name.Name} - successfully generated {successfulClassNames.Count} classes:");
            foreach (var success in successfulClassNames)
                Console.WriteLine($"   - {success}");
            Console.WriteLine();
        }
    }


    private string WriteCommonHeader(GlobalContext global) {
        return @$"
#include <stdbool.h>
#include <string.h>

#define MessagePort(X) struct {{ bool HasMessage; X Value; }}
#define DataPort(X) struct {{ bool IsSignalled; X Value; }}

typedef struct PulsedIn
{{
    bool IsTriggered;
}} PulsedIn;

typedef struct PulsedOut
{{
    bool Trigger;
}} PulsedOut;


typedef struct ChangeOp {{ bool T; bool V }} ChangeOp;

ChangeOp AndChange(ChangeOp lhs, ChangeOp rhs) {{
  ChangeOp result = {{ .T = lhs.T || rhs.T, .V = lhs.V && rhs.V }};
  return result;
}}

ChangeOp OrChange(ChangeOp lhs, ChangeOp rhs) {{
  ChangeOp result = {{ .T = lhs.V && lhs.T || rhs.V && rhs.T, .V = lhs.V || rhs.V }};
  return result;
}}

ChangeOp NegateChange(ChangeOp c) {{
  ChangeOp result = {{ .T = c.T, .V = !c.V }};
  return result;
}}

ChangeOp MakeChange(bool t, bool v) {{
  ChangeOp result = {{ .T = t, .V = v }};
  return result;
}}

bool IsTriggered(ChangeOp op) {{
    return op.T && op.V;
}}

typedef struct ChangeEvent
{{
  int IsTriggered;
}} ChangeEvent;

typedef struct TimeoutEvent
{{
  int IsTimeoutExpired;
}} TimeoutEvent;

// Enumerations
{string.Join("\n", global.Enumerations.Values.Select(WriteGlobalEnumeration))}

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

        await writer.WriteAsync(WriteClass(klass));

        var headerFilename = $"{_outputDir}/{pkg.Name.Name}/{klass.ClassName.Name}.h";
        using var headerFile = File.Create(headerFilename);
        using var headerWriter = new StreamWriter(headerFile);

        await headerWriter.WriteAsync(WriteHeader(klass));
    }

    private static string WriteOperation(Operation operation, ClassFile klass)
    {
        return @$"void {operation.Identifier.Name}({klass.ClassName.Name} *self) {{
            {JoinLines(operation.Instructions.Select(x => x.ToC()))}
        }}";
    }

    private static string WriteMessageSchema(MessageSchema messageSchema)
    {
        return @$"
        {string.Join("\n", messageSchema.GetValueTypes().Select(WriteValueType))}

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
        var states = klass.Behavior.EnumerateSubrecords(TargetLanguage.C)
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
    {string.Join("\n", klass.GetChangeEvents().Select(x => CheckForTriggeredDataChange(x, klass)))}
}}

void resetTriggers({klass.ClassName.Name} *self) {{
    {string.Join("\n", klass.GetIncomingMessageTypes().Select(x => $"self->In{x.Identifier.Name}.HasMessage = false;"))}

    {string.Join("\n", klass.GetPropertiesAndPorts().Values.OfType<PulsedInPropertyOrPort>().Select(x => $"self->{x.Identifier.Name}.IsTriggered = false;"))}

    {string.Join("\n", klass.GetTimeoutEvents().Select(x => $"self->{x}.IsTimeoutExpired = false;"))}
}}

void transition_{klass.ClassName.Name}({klass.ClassName.Name} *self) {{
  evaluateChangeEvents(self);

  switch (self->state)
  {{
        {string.Join("\n", klass.TransitionFunctions.Select(t =>
            $"case {t.fromStateName}: \n self->state = {t.Name(TargetLanguage.C)}(self);\nbreak;"))}
  }}

  resetTriggers(self);
}}
";
    }

    private static string? CheckForTriggeredDataChange((PackagedElement Event, IAccessible Condition) x, ClassFile klass)
    {
        var checker = new DataPortSignallingChecker(x.Event, x.Condition, klass);
        return checker.Check();
    }

    private string WriteBehaviorRecord(BehaviorRecord behaviorRecord, Dictionary<IState, string> states)
    {
        return
            string.Join("\n", behaviorRecord.EnumerateSubrecords(TargetLanguage.C)
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

    private static string WriteBehaviorFunctionSignatures(BehaviorRecord behaviorRecord) {
        return string.Join("\n", behaviorRecord.EnumerateSubrecords(TargetLanguage.C)
            .Append((behaviorRecord.Name, behaviorRecord))
            .Select(x => $"{behaviorRecord.Name} make_state_{x.Name}({x.record.ClassName.Name} *self);"));
    }

    private string WriteICodeTransition(ICodeTransition initializer, Dictionary<IState, string> states)
    {
        return initializer switch
        {
            JunctionCodeTransition junction => WriteJunctionTransition(junction, states),
            CodeTransition code => WriteCodeTransition(code, states),
            _ => throw new NotImplementedException()
        };
    }

    protected virtual string WriteTransitionFunction(TransitionFunction transitionFunction, Dictionary<IState, string> states)
    {
        return $@"{transitionFunction.TheRootBehaviorName.Name} {transitionFunction.Name(TargetLanguage.C)}({transitionFunction.ClassName.Name} *self) {{

            {string.Join("\n", transitionFunction.Transitions.Select(x => WriteICodeTransition(x, states)))}

            // Do not transition
            return self->state;
        }}
";
    }

    private static string WriteIfOrElse(List<Constraint> expression) {
        if (expression.All(c => c.Condition is BooleanExpression.Else)) {
            return "else";
        }

        if (expression.Count == 1) {
            return $"if ({expression.Single().Accessor(TargetLanguage.C)})";
        }

        var conditionsInParens = expression.Select(x => $"({x.Accessor(TargetLanguage.C)})");
        return $"if ({string.Join(" && ", conditionsInParens)})";
    }

    protected static string WrapWithGuard(Transition transition, List<Constraint> c, string instructions) {
        var condition = transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self->In{messageEvent.MessageType.Name}.HasMessage)",
            InitialTransition => "", // TODO
            JunctionTransition => "", // no triggers necessary from transitioning from a junction state
            _ => throw new NotImplementedException()
        };

        var constraint = c.Count > 0 ? WriteIfOrElse(c) : null;

        static string WrapWithIfElseExpression(string? expr, string block) =>
            string.IsNullOrWhiteSpace(expr) ? block : @$"{expr} {{
                {block}
            }}";

        return WrapWithIfElseExpression(condition, WrapWithIfElseExpression(constraint, instructions));
    }

    private string WriteJunctionTransition(JunctionCodeTransition junctionTransition, Dictionary<IState, string> states)
    {
        // Outgoing transitions must be sorted, so that the 'else' branch (if any) comes last
        var sortedTransitions = junctionTransition.CodeTransitions
            .OrderBy(x => x.Constraint.All(c => c.Condition is BooleanExpression.Else));

        return WrapWithGuard(junctionTransition.Transition, junctionTransition.Constraint,
            $@"{string.Join("\n", junctionTransition.Activities.Select(x => x.ToC()))}
                    {string.Join("\n", sortedTransitions.Select(x => WriteICodeTransition(x, states)))}"
        );
    }

    private static string WriteCodeTransition(CodeTransition codeTransition, Dictionary<IState, string> states)
    {
        return WrapWithGuard(codeTransition.Transition, codeTransition.Constraint,
            $@"{string.Join("\n", codeTransition.Activities.Select(x => x.ToC()))}
                return make_state_{states[codeTransition.Transition.To]}(self);"
        );
    }

    protected virtual string WriteHeader(ClassFile klass)
    {
        return @$"
#include ""../eulynx_common.h""

// Value Types

{string.Join("\n", klass.GetValueTypes().Select(WriteValueType))}

{WriteBehaviorEnum(klass.Behavior)}

/// Contained in:
{JoinLines(klass.PackageHierarchy.Select(x => $"/// {x.Name}"))}
typedef struct {klass.ClassName.Name} {{
    {klass.BehaviorName.Name} state;

    {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => x.Value switch {
        ComplexPropertyOrPort complex => null,
        PulsedInPropertyOrPort pulsedIn => $@"// {x.Key.RawName}
        // Trigger: {x.Value.IsTriggerPort}, DataPort: {x.Value.IsDataPort}, In: {x.Value.IsInPort}, Out: {x.Value.IsOutPort}, External: {x.Value.IsExternalInterface}
        {x.Value.DataType(TargetLanguage.C).Item1} {x.Key.Name}{x.Value.DataType(TargetLanguage.C).Item2};
        ",
        PulsedOutPropertyOrPort pulsedOut => $@"// {x.Key.RawName}
        // Trigger: {x.Value.IsTriggerPort}, DataPort: {x.Value.IsDataPort}, In: {x.Value.IsInPort}, Out: {x.Value.IsOutPort}, External: {x.Value.IsExternalInterface}
        {x.Value.DataType(TargetLanguage.C).Item1} {x.Key.Name}{x.Value.DataType(TargetLanguage.C).Item2};
        ",
        _ => $@"// {x.Key.RawName}
        // Trigger: {x.Value.IsTriggerPort}, DataPort: {x.Value.IsDataPort}, In: {x.Value.IsInPort}, Out: {x.Value.IsOutPort}, External: {x.Value.IsExternalInterface}
        DataPort({x.Value.DataType(TargetLanguage.C).Item1}{x.Value.DataType(TargetLanguage.C).Item2}) {x.Key.Name};
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
        {string.Join(",\n", behaviorRecord.EnumerateSubrecords(TargetLanguage.C).Select(x => x.Name))}
}} {behaviorRecord.Name};";
    }
}
