using XmiToCode.Accessibles;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Instructions;

record ReturnInstruction(IAccessible Value) : Instruction
{
    internal override string ToC(IProgramContext context)
    {
        return @$"return {Value.Accessor(context, TargetLanguage.C)};";
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

