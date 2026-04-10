using XmiToCode.Parsing.Context;

namespace XmiToCode.Instructions;

public abstract record Instruction(IProgramContext Context) {
    internal abstract string ToCSharp();
    internal abstract string ToC();
    internal abstract string ToRust();
}
