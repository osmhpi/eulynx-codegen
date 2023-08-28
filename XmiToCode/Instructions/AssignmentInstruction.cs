using XmiToCode.Accessibles;
using XmiToCode.Context;

namespace XmiToCode.Instructions;

record AssignmentInstruction(IAssignable Lhs, IAccessible Rhs) : Instruction
{
    internal override string ToCSharp(IProgramContext context)
    {
        return Lhs.Assign(context, Rhs, TargetLanguage.CSharp);
    }
    internal override string ToC(IProgramContext context)
    {
        return Lhs.Assign(context, Rhs, TargetLanguage.C);
    }
    internal override string ToRust(IProgramContext context)
    {
        return Lhs.Assign(context, Rhs, TargetLanguage.Rust);
    }
}
