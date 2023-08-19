
record SendMessageInstruction(MessageInitializer initialize, IAccessible port) : Instruction
{
    internal override string ToCSharp(ProgramContext context)
    {
        return $"this.SendMessage({initialize.ToCSharp(context)}, {port.Accessor(context, TargetLanguage.CSharp)});";
    }

    internal override string ToC(ProgramContext context)
    {
        return $@"
  {initialize.ToC(context)}
  self->{initialize.Schema.Identifier.Name}.Some = 1;";
    }

    internal override string ToRust(ProgramContext context)
    {
        return $@"
        ports.{port.Accessor(context, TargetLanguage.Rust)} = {initialize.Schema.Identifier.Name}
        ";
    }
}
