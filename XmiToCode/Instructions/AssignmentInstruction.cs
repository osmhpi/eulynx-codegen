using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Instructions;

record AssignmentInstruction(IAssignable Lhs, IAccessible Rhs, IProgramContext Context) : Instruction(Context)
{
    internal override string ToCSharp()
    {
        return Lhs.Assign(Context, Rhs, TargetLanguage.CSharp);
    }
    internal override string ToC()
    {
        return Lhs.Assign(Context, Rhs, TargetLanguage.C);
    }
    internal override string ToRust()
    {
        return Lhs.Assign(Context, Rhs, TargetLanguage.Rust);
    }
}
