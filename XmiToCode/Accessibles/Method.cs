using XmiToCode;

public record Method(Identifier Identifier, Operation Operation) : ICallable
{
    public string Call(ProgramContext context, TargetLanguage targetLanguage) => targetLanguage switch
    {
        TargetLanguage.CSharp => $"{Identifier.Name}(this)",
        TargetLanguage.C => $"{Identifier.Name}(self)",
        TargetLanguage.Rust => $"self.{Identifier.Name}()",
        _ => throw new NotImplementedException()
    };
}
