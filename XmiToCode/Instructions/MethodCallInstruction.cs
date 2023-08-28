using XmiToCode.Accessibles;
using XmiToCode.Context;

namespace XmiToCode.Instructions;

record MethodCallInstruction(ICallable Callable) : Instruction
{
    internal override string ToCSharp(IProgramContext context)
    {
        return $"{Callable.Call(context, TargetLanguage.CSharp)};";
    }
    internal override string ToC(IProgramContext context)
    {
        return $"{Callable.Call(context, TargetLanguage.C)};";
    }
    internal override string ToRust(IProgramContext context)
    {
        return $"{Callable.Call(context, TargetLanguage.Rust)};";
    }
}
