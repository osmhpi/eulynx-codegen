internal class RustWriter : ICodeWriter
{
    public string GenerateFileName(UmlClass uml) => $"../Eulynx/{uml.GetName()}.rs";

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
            Class klass => WriteClass(klass),
            _ => throw new NotImplementedException($"Writing not implemented for {element.GetType()}")
        };
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
struct {klass.Info.ClassName} {{
    state: {klass.Info.BehaviorName}
}}

impl {klass.Info.ClassName} {{
    fn new() -> {klass.Info.ClassName} {{
        let mut x: {klass.Info.ClassName} = {klass.Info.ClassName} {{
        }}

        x.make_state()

        x
    }}

    fn make_state(&mut self) -> {klass.Info.ClassName} {{

    }}

    {string.Join("\n", klass.TransitionFunctions.Select(x => Write(x)))}

    fn transition(&mut self) {{
        match self.state {{
            {string.Join(",\n", klass.States.Select(t =>
                string.Join(",\n", $"{t.Name} => self.transition_from_{t.Name.Replace(".", "__")}()")))}
    }}
}}
";
    }

    private string WriteBehaviorRecord(BehaviorRecord behaviorRecord)
    {
        return @$"public record {behaviorRecord.Name} : {behaviorRecord.parentBehaviorName} {{
        {string.Join("\n", behaviorRecord.subrecords.Select(x => Write(x)))}


    public static new {behaviorRecord.Name} New({behaviorRecord.className} This) {{
        {Write(behaviorRecord.initializer)}
    }}

    private {behaviorRecord.Name}() {{}}
}}
";
    }

    private string WriteTransitionFunction(TransitionFunction transitionFunction)
    {
        // {GenerateConditions(thisName, fromState, dataTypes, context)}
        return $@"fn transition_from_{transitionFunction.Name.Replace(".", "__")}(&mut self) {{

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
        return $@"{{
            {Write(codeTransition.DeconstructMessageInstruction)}
            {string.Join("\n", codeTransition.Activities.Select(x => x.ToCSharp(codeTransition.context)))}
            return {codeTransition.stateName}.New({codeTransition.context.InstanceReference});
        }}";
    }
}
