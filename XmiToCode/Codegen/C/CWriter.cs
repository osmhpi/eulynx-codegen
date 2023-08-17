using XmiToCode;

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
            CodeTransition codeTransition => WriteCodeTransition(codeTransition),
            JunctionTransition junctionTransition => WriteJunctionTransition(junctionTransition),
            TransitionFunction transitionFunction => WriteTransitionFunction(transitionFunction),
            BehaviorRecord behaviorRecord => WriteBehaviorRecord(behaviorRecord),
            GlobalEnumeration globalEnumeration => WriteGlobalEnumeration(globalEnumeration),
            ValueType valueType => WriteValueType(valueType),
            MessageSchema messageSchema => WriteMessageSchema(messageSchema),
            Operation operation => WriteOperation(operation),
            Class klass => WriteClass(klass),
            null => "",
            _ => throw new NotImplementedException($"Writing not implemented for {element.GetType()}")
        };
    }

    private string WriteOperation(Operation operation)
    {
        // var instructions = CompoundState.ParseInstructions(operation.Behavior.Body, context);
        var instructions = "";
        return @$"void {CodeGenerationItem.InPascalCase(operation.Op.Name)}(void *) {{
            {instructions}
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
        return @$"typedef enum {globalEnumeration.Name} {{
            {string.Join(",\n", globalEnumeration.Members.Select(x => $"{globalEnumeration.Name}__{x}"))}
        }} {globalEnumeration.Name};
        ";
    }

    private string WriteClass(Class klass)
    {
        //  #include ""{klass.Info.ClassName}.h""
        return @$"
{WriteHeader(klass)}

// Operations

{string.Join("\n", klass.GetOperations().Select(x => Write(x)))}

{Write(klass.Behavior)}

void new({klass.Info.ClassName} *x) {{
    x->state = make_state_{klass.Info.BehaviorName}(x);
}}

{string.Join("\n", klass.TransitionFunctions.Select(x => Write(x)))}

void transition({klass.Info.ClassName} *self) {{
  switch (self->state)
  {{
        {string.Join("\n", klass.States.Select(t =>
            string.Join("\n", $"case {t.Name.Replace(".", "__")}: \n self->state = transition_from_{t.Name.Replace(".", "__")}(self);\nbreak;")))}
  }}
}}
";
    }

    private string WriteBehaviorRecord(BehaviorRecord behaviorRecord)
    {
        return
            string.Join("\n", EnumerateSubrecords(behaviorRecord).Append(("", behaviorRecord)).Select(x => x.record switch {
                SimpleBehaviorRecord simple => $@"
                    {behaviorRecord.Name} make_state_{behaviorRecord.Name}__{x.Name} ({simple.className.ClassName} *self) {{
                        return {behaviorRecord.Name}__{x.Name};
                    }}",
                BehaviorRecord record => $@"
                    {behaviorRecord.Name} make_state_{behaviorRecord.Name}__{x.Name}({record.className.ClassName} *self) {{
                        {Write(record.initializer)}
                    }}",
                _ => throw new NotImplementedException()
            }));
    }

    private static IEnumerable<(string Name, IBehaviorRecord record)> EnumerateSubrecords(IBehaviorRecord record)
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

    private string WriteTransitionFunction(TransitionFunction transitionFunction)
    {
        // {GenerateConditions(thisName, fromState, dataTypes, context)}
        return $@"{transitionFunction.TheRootBehaviorName.BehaviorName} transition_from_{transitionFunction.Name.Replace(".", "__")}({transitionFunction.TheRootBehaviorName.ClassName} *self) {{

            {string.Join("\n", transitionFunction.Transitions.Select(x => Write(x)))}

            // Do not transition
            return self->state;
        }}
";
    }

    private string WriteJunctionTransition(JunctionTransition junctionTransition)
    {
        var condition = junctionTransition.Transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self->{messageEvent.MessageSchema.Name}.Some)",
            InitialTransition => "", // TODO
            _ => throw new NotImplementedException()
        };

        var constraint = junctionTransition.Constraint switch {
            TransitionConstraint.Else => "else",
            TransitionConstraint.Equality equality =>
                $"if ({equality.Lhs.Comparator(junctionTransition.context, equality.Rhs, TargetLanguage.C)})",
            TransitionConstraint.SingleVariable single =>
                single.Positive ?
                    $"if ({single.Variable.Accessor(junctionTransition.context, TargetLanguage.C)})" :
                    $"if (!{single.Variable.Accessor(junctionTransition.context, TargetLanguage.C)})",
            null => null,
            _ => throw new NotImplementedException()
        };

        var wrapWithIfElseExpression = (string? expr, string block) =>
            string.IsNullOrWhiteSpace(expr) ? block : @$"{expr} {{
                {block}
            }}";

        return wrapWithIfElseExpression(condition,
            wrapWithIfElseExpression(constraint,
                $@"{string.Join("\n", junctionTransition.Activities.Select(x => x.ToCSharp(junctionTransition.context)))}
                {string.Join("\n", junctionTransition.CodeTransitions.Select(x => Write(x)))}"));
    }

    private string WriteCodeTransition(CodeTransition codeTransition)
    {
        var condition = codeTransition.Transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self->{messageEvent.MessageSchema.Name}.Some)",
            InitialTransition => "", // TODO
            _ => throw new NotImplementedException()
        };

        var constraint = codeTransition.Constraint switch {
            TransitionConstraint.Else => "else",
            TransitionConstraint.Equality equality =>
                $"if ({equality.Lhs.Comparator(codeTransition.context, equality.Rhs, TargetLanguage.C)})",
            TransitionConstraint.SingleVariable single =>
                single.Positive ?
                    $"if ({single.Variable.Accessor(codeTransition.context, TargetLanguage.C)})" :
                    $"if (!{single.Variable.Accessor(codeTransition.context, TargetLanguage.C)})",
            null => null,
            _ => throw new NotImplementedException()
        };

        var wrapWithIfElseExpression = (string? expr, string block) =>
            string.IsNullOrWhiteSpace(expr) ? block : @$"{expr} {{
                {block}
            }}";

            return wrapWithIfElseExpression(condition,
            wrapWithIfElseExpression(constraint,
         $@"{string.Join("\n", codeTransition.Activities.Select(x => x.ToC(codeTransition.context)))}
            return make_state_{codeTransition.stateName.Replace(".", "__")}(self);"));
    }

    private string WriteHeader(Class klass)
    {
        return @$"
#include <stdbool.h>
#include <string.h>
#define Option(X) struct {{ int Some; X Value; }}

typedef struct ChangeEvent
{{
  int IsTriggered;
}} ChangeEvent;

typedef struct TimeoutEvent
{{
  int IsTimeoutExpired;
}} TimeoutEvent;

{string.Join("\n", klass.GlobalEnumerations.Select(x => Write(x)))}

typedef enum {klass.Info.BehaviorName} {klass.Info.BehaviorName};

// Value Types

{string.Join("\n", klass.GetValueTypes().Select(x => Write(x)))}

// Message Types
{string.Join("\n", klass.GetIncomingMessageTypes().Select(x => Write(x)))}
{string.Join("\n", klass.GetOutgoingMessageTypes().Select(x => Write(x)))}

{WriteBehaviorEnum((BehaviorRecord)klass.Behavior)}

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
    {string.Join("\n", klass.GetChangeEvents().Select(x => $"ChangeEvent {x.Name}; // {x.ChangeExpression.Body}"))}

    // Timeout Events
    {string.Join("\n", klass.GetTimeoutEvents().Select(x => $"TimeoutEvent {x};"))}

}} {klass.Info.ClassName};

{WriteBehaviorFunctionSignatures((BehaviorRecord)klass.Behavior)}
";
    }

    private string WriteBehaviorEnum(BehaviorRecord behaviorRecord)
    {
        return @$"typedef enum {behaviorRecord.Name} {{
        {string.Join(",\n", EnumerateSubrecords(behaviorRecord).Select(x => $"{behaviorRecord.Name}__{x.Name}"))}
}} {behaviorRecord.Name};";
    }

    private string WriteBehaviorFunctionSignatures(BehaviorRecord behaviorRecord) {
        return string.Join("\n", EnumerateSubrecords(behaviorRecord).Select(x => $"{behaviorRecord.Name} make_state_{behaviorRecord.Name}__{x.Name} ({x.record.className.ClassName} *self);"));
    }
}
