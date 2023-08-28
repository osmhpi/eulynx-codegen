using XmiToCode.Accessibles;
using XmiToCode.Context;

namespace XmiToCode.Instructions;

record IfThenElseInstruction(IAccessible Condition) : Instruction
{
    internal override string ToC(IProgramContext context)
    {
        throw new NotImplementedException();
    }

    internal override string ToCSharp(IProgramContext context)
    {
        throw new NotImplementedException();
    }

    internal override string ToRust(IProgramContext context)
    {
        throw new NotImplementedException();
    }
}
