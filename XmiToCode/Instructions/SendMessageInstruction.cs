using XmiToCode.Accessibles;
using XmiToCode.Context;

namespace XmiToCode.Instructions;

record SendMessageInstruction(MessageInitializer Initializer, IAccessible port) : Instruction
{
    internal override string ToCSharp(IProgramContext context)
    {
        return $"this.SendMessage({Initializer.ToCSharp(context)}, {port.Accessor(context, TargetLanguage.CSharp)});";
    }

    internal override string ToC(IProgramContext context)
    {
        return $@"
  {Initializer.ToC(context)}
  self->Out{Initializer.Message.Name}.Some = 1;";
    }

    internal override string ToRust(IProgramContext context)
    {
        return $@"
        {port.Accessor(context, TargetLanguage.Rust)} = {Initializer.Message.Name};
        ";
    }
}
