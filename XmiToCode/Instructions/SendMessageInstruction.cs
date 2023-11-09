using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Instructions;

record SendMessageInstruction(MessageInitializer Initializer, IAccessible port, IProgramContext Context) : Instruction(Context)
{
    internal override string ToCSharp()
    {
        return $"this.SendMessage({Initializer.ToCSharp(Context)}, {port.Accessor(Context, TargetLanguage.CSharp)});";
    }

    internal override string ToC()
    {
        return $@"
  {Initializer.ToC(Context)}
  self->Out{Initializer.Message.Name}.HasMessage = 1;";
    }

    internal override string ToRust()
    {
        return $@"
        {port.Accessor(Context, TargetLanguage.Rust)} = {Initializer.Message.Name};
        ";
    }
}
