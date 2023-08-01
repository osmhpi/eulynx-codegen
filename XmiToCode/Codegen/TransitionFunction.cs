record TransitionFunction(string TheRootBehaviorName, string Name, List<ICodeTransition> Transitions);

record Condition();

interface ICodeTransition {
}

record CodeTransition(string stateName, ProgramContext context, DeconstructMessageInstruction DeconstructMessageInstruction, List<Instruction> Activities) : ICodeTransition;

record JunctionTransition(ProgramContext context, DeconstructMessageInstruction DeconstructMessageInstruction, List<Instruction> Activities, List<ICodeTransition> CodeTransitions) : ICodeTransition;

record DeconstructMessageInstruction(string? currentSignalName, Dictionary<string, PropertyOrPort> attributesOfCurrentSignal, ProgramContext context);
