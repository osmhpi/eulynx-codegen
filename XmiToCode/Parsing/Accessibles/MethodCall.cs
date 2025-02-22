using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;

namespace XmiToCode.Parsing.Accessibles;

public record MethodCall(Identifier Identifier, Operation Operation) : ICallable
{
    public string Call(IProgramContext context, List<IAccessible> arguments, TargetLanguage targetLanguage) {
        if (targetLanguage == TargetLanguage.C) {
            List<string> parameters = ["self", ..arguments.Select(a => a.Accessor(context, targetLanguage))];
            return $"{Identifier.Name}({string.Join(", ", parameters)})";
        }

        return targetLanguage switch
        {
            TargetLanguage.CSharp => $"{Identifier.Name}(this)",
            TargetLanguage.Rust => $"self.{Identifier.Name}()",
            _ => throw new NotImplementedException()
        };
    }

    public void EnsureReturnTypeMatches(IAccessible accessible)
    {
        Operation.EnsureReturnTypeMatches(accessible);
    }
}
