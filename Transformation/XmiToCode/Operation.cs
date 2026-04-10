using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Instructions;
using XmiToCode.Parsing.XmiModel;
using XmiToCode.Transformation.Model;
using XmiToCode.Parsing.Accessibles;

namespace XmiToCode;

public record Operation(OwnedOperation Op, OwnedBehavior Behavior, OperationContext Context) {
    public List<Instruction> Instructions { get; set; } = null!;
    public Identifier Identifier { get; } = new Identifier(Op.Name);

    public static List<Instruction> ParseInstructions(OwnedBehavior behavior, IProgramContext context) {
        return CompoundState.ParseInstructions(behavior.Body, context);
    }

    internal void EnsureReturnTypeMatches(IAccessible accessible)
    {
        // if (accessible is ComplexPropertyOrPort)
        // {
        //     return;
        // }

        Context.EnsureReturnType(accessible);

        // throw new Exception("Types cannot be matched");
    }
}
