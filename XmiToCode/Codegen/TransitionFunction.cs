record TransitionFunction(string TheRootBehaviorName, string Name, List<ICodeTransition> Transitions);

record Condition();

// interface ITransitionTrigger{

// }

// record ChangeTrigger() : ITransitionTrigger;

interface ICodeTransition {
    public Transition Transition { get; }
}

record CodeTransition(string stateName, ProgramContext context, DeconstructMessageInstruction DeconstructMessageInstruction, List<Instruction> Activities, Transition Transition) : ICodeTransition;

record JunctionTransition(ProgramContext context, DeconstructMessageInstruction DeconstructMessageInstruction, List<Instruction> Activities, List<ICodeTransition> CodeTransitions, Transition Transition) : ICodeTransition;

record DeconstructMessageInstruction(string? currentSignalName, Dictionary<string, PropertyOrPort> attributesOfCurrentSignal, ProgramContext context);
