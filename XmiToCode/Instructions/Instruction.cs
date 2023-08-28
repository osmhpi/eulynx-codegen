using XmiToCode.Context;

namespace XmiToCode.Instructions;

public abstract record Instruction {
    internal abstract string ToCSharp(IProgramContext context);
    internal abstract string ToC(IProgramContext context);
    internal abstract string ToRust(IProgramContext context);
}
