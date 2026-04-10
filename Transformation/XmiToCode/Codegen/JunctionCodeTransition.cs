using XmiToCode.Instructions;
using XmiToCode.Parsing.Model;

namespace XmiToCode.Codegen;

public record JunctionCodeTransition(
    List<Instruction> Activities,
    List<ICodeTransition> CodeTransitions,
    List<Constraint> Constraint,
    Transition Transition
) : ICodeTransition;
