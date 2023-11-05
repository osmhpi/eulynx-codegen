using XmiToCode.Context;
using XmiToCode.Identifiers;
using XmiToCode.Instructions;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode;

public record Operation(OwnedOperation Op, OwnedBehavior Behavior, List<Instruction> Instructions) {
    public Identifier Identifier { get; } = new Identifier(Op.Name);

    public static List<Instruction> ParseInstructions(OwnedBehavior behavior, IProgramContext context) {
        return CompoundState.ParseInstructions(behavior.Body, context);
    }
}
