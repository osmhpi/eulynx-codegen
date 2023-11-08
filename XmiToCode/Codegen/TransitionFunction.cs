using XmiToCode.Parsing.Accessibles;
using XmiToCode.Classes;
using XmiToCode.Parsing.Context;
using XmiToCode.Instructions;

namespace XmiToCode.Codegen;

public record TransitionFunction(ClassInfo TheRootBehaviorName, string Name, List<ICodeTransition> Transitions);

public record Condition();

public interface ICodeTransition {
    public Transition Transition { get; }
    public List<IAccessible> Constraint { get; }
    public IProgramContext context { get; }
}

public record CodeTransition(
    string stateName,
    IProgramContext context,
    List<Instruction> Activities,
    List<IAccessible> Constraint,
    Transition Transition
) : ICodeTransition;

public record JunctionTransition(
    IProgramContext context,
    List<Instruction> Activities,
    List<ICodeTransition> CodeTransitions,
    List<IAccessible> Constraint,
    Transition Transition
) : ICodeTransition;
