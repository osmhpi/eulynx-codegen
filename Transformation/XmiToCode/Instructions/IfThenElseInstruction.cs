using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Instructions;

record IfThenInstruction(IAccessible Condition, IProgramContext Context) : Instruction(Context)
{
    internal override string ToC()
    {
        return @$"if ({Condition.Accessor(Context, TargetLanguage.C)}) {{";
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

record ElseInstruction(IProgramContext Context) : Instruction(Context)
{
    internal override string ToC()
    {
        return "} else {";
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

record ElseIfThenInstruction(IAccessible Condition, IProgramContext Context) : Instruction(Context)
{
    internal override string ToC()
    {
        return @$"}} else if ({Condition.Accessor(Context, TargetLanguage.C)}) {{";
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

record EndIfInstruction(IProgramContext Context) : Instruction(Context)
{
    internal override string ToC()
    {
        return "}";
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
