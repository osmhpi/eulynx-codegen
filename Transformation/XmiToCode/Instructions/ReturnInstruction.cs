using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Instructions;

record ReturnInstruction(IAccessible Value, IProgramContext Context) : Instruction(Context)
{
    internal override string ToC()
    {
        return @$"return {Value.Accessor(Context, TargetLanguage.C)};";
    }

    internal override string ToCSharp()
    {
        throw new NotImplementedException();
    }

    internal override string ToRust()
    {
        throw new NotImplementedException();
    }
}

