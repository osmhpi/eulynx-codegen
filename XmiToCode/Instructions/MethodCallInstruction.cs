using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Instructions;

record MethodCallInstruction(ICallable Callable, IProgramContext Context) : Instruction(Context)
{
    internal override string ToCSharp()
    {
        return $"{Callable.Call(Context, TargetLanguage.CSharp)};";
    }
    internal override string ToC()
    {
        return $"{Callable.Call(Context, TargetLanguage.C)};";
    }
    internal override string ToRust()
    {
        return $"{Callable.Call(Context, TargetLanguage.Rust)};";
    }
}
