
public abstract record Instruction {
    internal abstract string ToCSharp(ProgramContext context);
    internal abstract string ToC(ProgramContext context);
    internal abstract string ToRust(ProgramContext context);
}


record IfThenElseInstruction(IAccessible Condition) : Instruction
{
    internal override string ToC(ProgramContext context)
    {
        throw new NotImplementedException();
    }

    internal override string ToCSharp(ProgramContext context)
    {
        throw new NotImplementedException();
    }

    internal override string ToRust(ProgramContext context)
    {
        throw new NotImplementedException();
    }
}
