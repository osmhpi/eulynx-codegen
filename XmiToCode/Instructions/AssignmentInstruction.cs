
record AssignmentInstruction(IAssignable Lhs, IAccessible Rhs) : Instruction
{
    internal override string ToCSharp(ProgramContext context)
    {
        return Lhs.Assign(context, Rhs, TargetLanguage.CSharp);
    }
    internal override string ToC(ProgramContext context)
    {
        return Lhs.Assign(context, Rhs, TargetLanguage.C);
    }
    internal override string ToRust(ProgramContext context)
    {
        return Lhs.Assign(context, Rhs, TargetLanguage.Rust);
    }
}
