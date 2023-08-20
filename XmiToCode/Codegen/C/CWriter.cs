using XmiToCode;
using static CodeGenerationHelper;

internal class CWriter : ICodeWriter
{
    public string DefaultInstanceReference => "self";

    public string GenerateFileName(UmlClass uml) => $"../Eulynx/{uml.GetName()}.c";

    public async Task WriteAllFilesAsync(UmlClass umlClass, Class klass)
    {
        using var file = File.Create(GenerateFileName(umlClass));
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(Write(klass));

        using var headerFile = File.Create($"../Eulynx/{umlClass.GetName()}.h");
        using var headerWriter = new StreamWriter(headerFile);

        await headerWriter.WriteAsync(WriteHeader(klass));
    }

    public string Write<T>(T element)
    {
        return element switch
        {
            GlobalEnumeration globalEnumeration => WriteGlobalEnumeration(globalEnumeration),
            ValueType valueType => WriteValueType(valueType),
            MessageSchema messageSchema => WriteMessageSchema(messageSchema),
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

        typedef struct Message__{messageSchema.Identifier.Name} {{
            {string.Join("\n", messageSchema.Members.Select(x => $"{x.Member.DataType(TargetLanguage.C).Item1} {x.MemberName.Name}{x.Member.DataType(TargetLanguage.C).Item2};"))}
        }} Message__{messageSchema.Identifier.Name};";
    }

    private string WriteValueType(ValueType valueType)
    {
        return @$"typedef enum {valueType.Identifier.Name}Value {{
            {string.Join(",\n", valueType.AllowedValues.Select(x => $"{valueType.Identifier.Name}Value__{x.Name}"))}
        }} {valueType.Identifier.Name}Value;";
    }

    private string WriteGlobalEnumeration(GlobalEnumeration globalEnumeration)
    {
        return @$"typedef enum {globalEnumeration.Name.Name} {{
            {string.Join(",\n", globalEnumeration.Members.Select(x => $"{globalEnumeration.Name.Name}__{x.Name}"))}
        }} {globalEnumeration.Name.Name};
        ";
    }

    protected virtual string WriteClass(Class klass)
    {
        var states = PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior))
            .Where(x => x.record.State != null)
            .ToDictionary(x => x.record.State!, x => x.Name);

        //  #include ""{klass.Info.ClassName}.h""
        return @$"
{WriteHeader(klass)}

// Operations

{string.Join("\n", klass.Operations.Select(x => WriteOperation(x, klass)))}

{WriteBehaviorRecord(klass.Behavior, states)}

void new({klass.Info.ClassName} *x) {{
    x->state = make_state_{klass.Info.BehaviorName}(x);
}}

{string.Join("\n", klass.TransitionFunctions.Select(x => WriteTransitionFunction(x, states)))}

void evaluateChangeEvents({klass.Info.ClassName} *self) {{
    {string.Join("\n", klass.GetChangeEvents().Select(x => $"self->{x.Event.Name}.IsTriggered = ({x.Condition.Accessor(klass.ClassContext, TargetLanguage.C)});"))}
}}

void transition({klass.Info.ClassName} *self) {{
  evaluateChangeEvents(self);

  switch (self->state)
  {{
        {string.Join("\n", PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior)).Select(t =>
            $"case {t.Name}: \n self->state = transition_from_{t.Name}(self);\nbreak;"))}
  }}
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

    private string WriteJunctionTransition(JunctionTransition junctionTransition, Dictionary<IState, string> states)
    {
        var condition = junctionTransition.Transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self->{messageEvent.MessageSchema.Name}.Some)",
            InitialTransition => "", // TODO
            _ => throw new NotImplementedException()
        };

        var constraint = junctionTransition.Constraint != null ? WriteIfOrElse(junctionTransition.Constraint, junctionTransition.context) : null;

        var wrapWithIfElseExpression = (string? expr, string block) =>
            string.IsNullOrWhiteSpace(expr) ? block : @$"{expr} {{
                {block}
            }}";

        return wrapWithIfElseExpression(condition,
            wrapWithIfElseExpression(constraint,
                $@"{string.Join("\n", junctionTransition.Activities.Select(x => x.ToC(junctionTransition.context)))}
                {string.Join("\n", junctionTransition.CodeTransitions.Select(x => WriteICodeTransition(x, states)))}"));
    }

    private string WriteIfOrElse(IAccessible expression, ProgramContext context) {
        return expression switch {
            BooleanExpression.Else => "else",
            _ => $"if ({expression.Accessor(context, TargetLanguage.C)})"
        };
    }

    // private string WriteBooleanExpression(BooleanExpression expression, ProgramContext context) {
    //     return expression switch {
    //         BooleanExpression.Equality equality =>
    //             equality.Positive ?
    //                 equality.Lhs.Comparator(context, equality.Rhs, TargetLanguage.C) :
    //                 $"!({equality.Lhs.Comparator(context, equality.Rhs, TargetLanguage.C)})",
    //         BooleanExpression.SingleVariable single =>
    //             single.Positive ?
    //                 single.Variable.Accessor(context, TargetLanguage.C) :
    //                 $"!{single.Variable.Accessor(context, TargetLanguage.C)}",
    //         BooleanExpression.Conjunction conjunction =>
    //             $"({conjunction.Lhs.Accessor(context, TargetLanguage.C)}) && ({conjunction.Rhs.Accessor(context, TargetLanguage.C)})",
    //         BooleanExpression.Disjunction conjunction =>
    //             $"({conjunction.Lhs.Accessor(context, TargetLanguage.C)}) || ({conjunction.Rhs.Accessor(context, TargetLanguage.C)})",
    //         _ => throw new NotImplementedException()
    //     };
    // }

    private string WriteCodeTransition(CodeTransition codeTransition, Dictionary<IState, string> states)
    {
        var condition = codeTransition.Transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self->{messageEvent.MessageSchema.Name}.Some)",
            InitialTransition => "", // TODO
            _ => throw new NotImplementedException()
        };

        var constraint = codeTransition.Constraint != null ? WriteIfOrElse(codeTransition.Constraint, codeTransition.context) : null;

        var wrapWithIfElseExpression = (string? expr, string block) =>
            string.IsNullOrWhiteSpace(expr) ? block : @$"{expr} {{
                {block}
            }}";

        return wrapWithIfElseExpression(condition, wrapWithIfElseExpression(constraint,
            $@"{string.Join("\n", codeTransition.Activities.Select(x => x.ToC(codeTransition.context)))}
                return make_state_{states[codeTransition.Transition.To]}(self);"));
    }

    protected virtual string WriteHeader(Class klass)
    {
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

{string.Join("\n", klass.ClassContext.Global.Enumerations.Select(x => Write(x)))}

// Value Types

{string.Join("\n", klass.GetValueTypes().Select(x => Write(x)))}

// Message Types
{string.Join("\n", klass.GetIncomingMessageTypes().Select(x => Write(x)))}
{string.Join("\n", klass.GetOutgoingMessageTypes().Select(x => Write(x)))}

{WriteBehaviorEnum(klass.Behavior)}

typedef struct {klass.Info.ClassName} {{
    {klass.Info.BehaviorName} state;

    {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => x.Value switch {
        PropertyOrPort.ComplexPropertyOrPort complex => null,
        _ => $"{x.Value.DataType(TargetLanguage.C).Item1} {x.Key.Name}{x.Value.DataType(TargetLanguage.C).Item2};"
        }))}

    // Messages -- Incoming
    {string.Join("\n", klass.GetIncomingMessageTypes().Select(x => $"Option(Message__{x.Identifier.Name}) {x.Identifier.Name};"))}
    // Messages -- Outgoing
    {string.Join("\n", klass.GetOutgoingMessageTypes().Select(x => $"Option(Message__{x.Identifier.Name}) {x.Identifier.Name};"))}

    // Change Events
    {string.Join("\n", klass.GetChangeEvents().Select(x => $"ChangeEvent {x.Event.Name}; // {x.Event.ChangeExpression.Body}"))}

    // Timeout Events
    {string.Join("\n", klass.GetTimeoutEvents().Select(x => $"TimeoutEvent {x};"))}

}} {klass.Info.ClassName};

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
}
