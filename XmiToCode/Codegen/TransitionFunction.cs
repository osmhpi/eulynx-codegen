public record TransitionFunction(ClassInfo TheRootBehaviorName, string Name, List<ICodeTransition> Transitions);

public record Condition();

// interface ITransitionTrigger{

// }

// record ChangeTrigger() : ITransitionTrigger;

public interface ICodeTransition {
    // public ClassInfo ClassInfo { get; }
    public Transition Transition { get; }
}

public record CodeTransition(string stateName, ProgramContext context, DeconstructMessageInstruction DeconstructMessageInstruction, List<Instruction> Activities, Transition Transition) : ICodeTransition;

public record JunctionTransition(ProgramContext context, DeconstructMessageInstruction DeconstructMessageInstruction, List<Instruction> Activities, List<ICodeTransition> CodeTransitions, Transition Transition) : ICodeTransition;

public record DeconstructMessageInstruction(string? currentSignalName, Dictionary<string, PropertyOrPort> attributesOfCurrentSignal, ProgramContext context);
