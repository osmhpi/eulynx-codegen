using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;
using XmiToCode.Instructions;
using XmiToCode.Identifiers;

namespace XmiToCode.Codegen;

public record TransitionFunction(TypeIdentifier TheRootBehaviorName, TypeIdentifier ClassName, string Name, List<ICodeTransition> Transitions);

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
