using XmiToCode.Instructions;
using XmiToCode.Parsing.Model;

namespace XmiToCode.Codegen;

public record CodeTransition(
    List<Instruction> Activities,
    List<Constraint> Constraint,
    Transition Transition
) : ICodeTransition;
