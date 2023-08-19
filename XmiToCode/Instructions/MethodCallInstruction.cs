
record MethodCallInstruction(ICallable Callable) : Instruction
{
    internal override string ToCSharp(ProgramContext context)
    {
        return $"{Callable.Call(context, TargetLanguage.CSharp)};";
    }
    internal override string ToC(ProgramContext context)
    {
        return $"{Callable.Call(context, TargetLanguage.C)};";
    }
    internal override string ToRust(ProgramContext context)
    {
        return $"{Callable.Call(context, TargetLanguage.Rust)};";
    }
}
