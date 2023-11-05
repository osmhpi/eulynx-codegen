using XmiToCode.Accessibles;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Instructions;

record IfThenInstruction(IAccessible Condition) : Instruction
{
    internal override string ToC(IProgramContext context)
    {
        return @$"if ({Condition.Accessor(context, TargetLanguage.C)}) {{";
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

record ElseInstruction() : Instruction
{
    internal override string ToC(IProgramContext context)
    {
        return "} else {";
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

record ElseIfThenInstruction(IAccessible Condition) : Instruction
{
    internal override string ToC(IProgramContext context)
    {
        return @$"}} else if ({Condition.Accessor(context, TargetLanguage.C)}) {{";
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

record EndIfInstruction() : Instruction
{
    internal override string ToC(IProgramContext context)
    {
        return "}";
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
