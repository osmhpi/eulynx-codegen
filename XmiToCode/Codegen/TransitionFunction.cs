public record TransitionFunction(ClassInfo TheRootBehaviorName, string Name, List<ICodeTransition> Transitions);

public record Condition();

public interface ICodeTransition {
    public Transition Transition { get; }
}

public record CodeTransition(string stateName, ProgramContext context, DeconstructMessageInstruction? DeconstructMessageInstruction, List<Instruction> Activities, TransitionConstraint? Constraint, Transition Transition) : ICodeTransition;

public record JunctionTransition(ProgramContext context, DeconstructMessageInstruction? DeconstructMessageInstruction, List<Instruction> Activities, List<ICodeTransition> CodeTransitions, TransitionConstraint? Constraint, Transition Transition) : ICodeTransition;

public record DeconstructMessageInstruction(string? currentSignalName, MessageSchema attributesOfCurrentSignal, BlockContext Context);
