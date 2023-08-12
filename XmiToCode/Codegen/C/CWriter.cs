internal class CWriter : ICodeWriter
{
    public string GenerateFileName(UmlClass uml) => $"../Eulynx/{uml.GetName()}.c";

    public string Write<T>(T element)
    {
        return element switch
        {
            CodeTransition codeTransition => WriteCodeTransition(codeTransition),
            JunctionTransition junctionTransition => WriteJunctionTransition(junctionTransition),
            DeconstructMessageInstruction deconstructMessageInstruction => WriteDeconstructMessageInstruction(deconstructMessageInstruction),
            SimpleBehaviorRecord simpleBehaviorRecord => WriteSimpleBehaviorRecord(simpleBehaviorRecord),
            TransitionFunction transitionFunction => WriteTransitionFunction(transitionFunction),
            BehaviorRecord behaviorRecord => WriteBehaviorRecord(behaviorRecord),
            GlobalEnumeration globalEnumeration => WriteGlobalEnumeration(globalEnumeration),
            ValueType valueType => WriteValueType(valueType),
            MessageSchema messageSchema => WriteMessageSchema(messageSchema),
            Class klass => WriteClass(klass),
            _ => throw new NotImplementedException($"Writing not implemented for {element.GetType()}")
        };
    }

    private string WriteMessageSchema(MessageSchema messageSchema)
    {
        var translateType = (string type) => type switch {
            "String" => ("char", "[4]"),
            _ => (type, "")
        };

        return @$"typedef struct Message__{messageSchema.Identifier.Name} {{
            {string.Join("\n", messageSchema.Members.Select(x => $"{translateType(x.TypeIdentifier.Name).Item1} {x.MemberName.Name}{translateType(x.TypeIdentifier.Name).Item2};"))}
        }} Message__{messageSchema.Identifier.Name};";
    }

    private string WriteValueType(ValueType valueType)
    {
        return @$"typedef enum {valueType.ClassName}__{valueType.Identifier.Name}Value {{
            {string.Join(",\n", valueType.AllowedValues.Select(x => $"{valueType.ClassName}__{valueType.Identifier.Name}Value__{x.Name}"))}
        }} {valueType.ClassName}__{valueType.Identifier.Name}Value;";
    }

    private string WriteGlobalEnumeration(GlobalEnumeration globalEnumeration)
    {
        return @$"typedef enum {globalEnumeration.Name} {{
            {string.Join(",\n", globalEnumeration.Members.Select(x => $"{globalEnumeration.Name}__{x}"))}
        }} {globalEnumeration.Name};
        ";
    }

    private string WriteSimpleBehaviorRecord(SimpleBehaviorRecord simpleBehaviorRecord)
    {
        return $@"public record {simpleBehaviorRecord.Name}() : {simpleBehaviorRecord.recordName}() {{
            public static new {simpleBehaviorRecord.Name} New({simpleBehaviorRecord.className} This) => new {simpleBehaviorRecord.Name}();
        }}";
    }

    private string WriteClass(Class klass)
    {
        return @$"
#define Option(X) \\
  struct          \\
  {{               \\
    int Some;     \\
    X Value;      \\
  }}

typedef struct ChangeEvent
{{
  int IsTriggered;
}} ChangeEvent;

{string.Join("\n", klass.GlobalEnumerations.Select(x => Write(x)))}

{Write(klass.Behavior)}

// Value Types

{string.Join("\n", klass.GetValueTypes().Select(x => Write(x)))}

// Message Types

{string.Join("\n", klass.GetMessageTypes().Select(x => Write(x)))}

typedef struct {klass.ClassName} {{
    {klass.BehaviorName} state;

    {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => $"{x.Value.DataType} {x.Key.Name};"))}

/*
    {string.Join("\n", klass.GetMessageTypes().Select(x => $"Option(Message__{x.Identifier.Name}) {x.Identifier.Name};"))}
*/
}} {klass.ClassName};

void new({klass.ClassName} *x) {{
    x->state = make_state(x);
}}

{klass.BehaviorName} make_state({klass.ClassName} *self) {{

}}

{string.Join("\n", klass.TransitionFunctions.Select(x => Write(x)))}

void transition({klass.ClassName} *self) {{
  switch (self->state)
  {{
        {string.Join("\n", klass.States.Select(t =>
            string.Join("\n", $"case {t.Name.Replace(".", "__")}: \n self.transition_from_{t.Name.Replace(".", "__")}(self);\nbreak;")))}
}}
";
    }

    private string WriteBehaviorRecord(BehaviorRecord behaviorRecord)
    {

        return @$"typedef enum {behaviorRecord.Name} {{
        {string.Join(",\n", EnumerateSubrecords(behaviorRecord).Select(x => $"{behaviorRecord.Name}__{x}"))}
}} {behaviorRecord.Name};
";
    }

    private static IEnumerable<string> EnumerateSubrecords(IBehaviorRecord record)
    {
        foreach (var s in record.subrecords)
        {
            yield return s.Name;
            foreach (var subsubrecord in EnumerateSubrecords(s))
            {
                yield return $"{s.Name}__{subsubrecord}";
            }
        }
    }

    private string WriteTransitionFunction(TransitionFunction transitionFunction)
    {
        // {GenerateConditions(thisName, fromState, dataTypes, context)}
        return $@"void transition_from_{transitionFunction.Name.Replace(".", "__")}({transitionFunction.TheRootBehaviorName} *self) {{

            {string.Join("\n", transitionFunction.Transitions.Select(x => Write(x)))}
        }}
";
    }

    private string WriteDeconstructMessageInstruction(DeconstructMessageInstruction deconstructMessageInstruction)
    {
        if (deconstructMessageInstruction.currentSignalName != null && deconstructMessageInstruction.attributesOfCurrentSignal != null && deconstructMessageInstruction.attributesOfCurrentSignal.Count > 0)
        {
            if (deconstructMessageInstruction.attributesOfCurrentSignal.Count >= 2)
            {
                return
                    @$"var ({string.Join(", ", deconstructMessageInstruction.attributesOfCurrentSignal.Select(x => x.Value.Name))}) = {deconstructMessageInstruction.context.InstanceReference}.{deconstructMessageInstruction.currentSignalName};";
            }
            else if (deconstructMessageInstruction.attributesOfCurrentSignal.Count == 1)
            {
                return
                    @$"var {deconstructMessageInstruction.attributesOfCurrentSignal.Single().Value.Name} = {deconstructMessageInstruction.context.InstanceReference}.{deconstructMessageInstruction.currentSignalName}.{deconstructMessageInstruction.attributesOfCurrentSignal.Single().Value.Name};";
            }
        }

        return "";
    }

    private string WriteJunctionTransition(JunctionTransition junctionTransition)
    {
        return $@"{{
            {Write(junctionTransition.DeconstructMessageInstruction)}
            {string.Join("\n", junctionTransition.Activities.Select(x => x.ToCSharp(junctionTransition.context)))}
            {string.Join("\n", junctionTransition.CodeTransitions.Select(x => Write(x)))}
        }}";
    }

    private string WriteCodeTransition(CodeTransition codeTransition)
    {
        var condition = codeTransition.Transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            _ => null
        };

        return $@"{condition} {{
            {Write(codeTransition.DeconstructMessageInstruction)}
            {string.Join("\n", codeTransition.Activities.Select(x => x.ToCSharp(codeTransition.context)))}
            return make_state{codeTransition.stateName}(self);
        }}";
    }
}
