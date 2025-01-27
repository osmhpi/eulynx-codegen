using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;

namespace XmiToCode.Parsing.Accessibles;

public record MethodCall(Identifier Identifier, Operation Operation) : ICallable
{
    public string Call(IProgramContext context, TargetLanguage targetLanguage) => targetLanguage switch
    {
        TargetLanguage.CSharp => $"{Identifier.Name}(this)",
        TargetLanguage.C => $"{Identifier.Name}(self)",
        TargetLanguage.Rust => $"self.{Identifier.Name}()",
        _ => throw new NotImplementedException()
    };

    public void EnsureReturnTypeMatches(IAccessible accessible)
    {
        Operation.EnsureReturnTypeMatches(accessible);
    }
}
