record TransitionFunction(string TheRootBehaviorName, string Name, List<ICodeTransition> Transitions) {
    public string Write() {
        // {GenerateConditions(thisName, fromState, dataTypes, context)}
        return $@"private {TheRootBehaviorName} TransitionFrom{Name.Replace(".", "__")}() {{

            {string.Join("\n", Transitions.Select(x => x.Write()))}

        // Do not transition
        return _state;
        }}
";
    }
}

record Condition() {

}

interface ICodeTransition {
    public string Write();
}

record CodeTransition(string stateName, ProgramContext context, DeconstructMessageInstruction DeconstructMessageInstruction, List<Instruction> Activities) : ICodeTransition
{
    public string Write()
    {
        return $@"{{
            {DeconstructMessageInstruction.Write()}
            {string.Join("\n", Activities.Select(x => x.ToCSharp(context)))}
            return {stateName}.New({context.InstanceReference});
        }}";
    }
}

record JunctionTransition(ProgramContext context, DeconstructMessageInstruction DeconstructMessageInstruction, List<Instruction> Activities, List<ICodeTransition> CodeTransitions) : ICodeTransition
{
    public string Write()
    {
        return $@"{{
            {DeconstructMessageInstruction.Write()}
            {string.Join("\n", Activities.Select(x => x.ToCSharp(context)))}
            {string.Join("\n", CodeTransitions.Select(x => x.Write()))}
        }}";
    }
}

record DeconstructMessageInstruction(string? currentSignalName, Dictionary<string, PropertyOrPort> attributesOfCurrentSignal, ProgramContext context) {
    public string Write() {
        if (currentSignalName != null && attributesOfCurrentSignal != null && attributesOfCurrentSignal.Count > 0) {
            if (attributesOfCurrentSignal.Count >= 2) {
                return
                    @$"var ({string.Join(", ", attributesOfCurrentSignal.Select(x => x.Value.Name))}) = {context.InstanceReference}.{currentSignalName};";
            } else if (attributesOfCurrentSignal.Count == 1) {
                return
                    @$"var {attributesOfCurrentSignal.Single().Value.Name} = {context.InstanceReference}.{currentSignalName}.{attributesOfCurrentSignal.Single().Value.Name};";
            }
        }

        return "";
    }
}
