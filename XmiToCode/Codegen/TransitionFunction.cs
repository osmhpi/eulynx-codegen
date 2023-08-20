public record TransitionFunction(ClassInfo TheRootBehaviorName, string Name, List<ICodeTransition> Transitions);

public record Condition();

public interface ICodeTransition {
    public Transition Transition { get; }
    public IAccessible? Constraint { get; }
}

public record CodeTransition(string stateName, ProgramContext context, List<Instruction> Activities, IAccessible? Constraint, Transition Transition) : ICodeTransition;

public record JunctionTransition(ProgramContext context, List<Instruction> Activities, List<ICodeTransition> CodeTransitions, IAccessible? Constraint, Transition Transition) : ICodeTransition;

