
record SendMessageInstruction(MessageInitializer Initializer, IAccessible port) : Instruction
{
    internal override string ToCSharp(ProgramContext context)
    {
        return $"this.SendMessage({Initializer.ToCSharp(context)}, {port.Accessor(context, TargetLanguage.CSharp)});";
    }

    internal override string ToC(ProgramContext context)
    {
        return $@"
  {Initializer.ToC(context)}
  self->Out{Initializer.Message.Name}.Some = 1;";
    }

    internal override string ToRust(ProgramContext context)
    {
        return $@"
        {port.Accessor(context, TargetLanguage.Rust)} = {Initializer.Message.Name};
        ";
    }
}
