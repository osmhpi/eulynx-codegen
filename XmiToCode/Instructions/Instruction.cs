
public abstract record Instruction {
    internal abstract string ToCSharp(ProgramContext context);
    internal abstract string ToC(ProgramContext context);
    internal abstract string ToRust(ProgramContext context);
}

