
public abstract record Instruction {
    internal abstract string ToCSharp(IProgramContext context);
    internal abstract string ToC(IProgramContext context);
    internal abstract string ToRust(IProgramContext context);
}


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
