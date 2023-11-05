using XmiToCode.Parsing.Context;

namespace XmiToCode.Accessibles;

public record PulsedInLiteral() : IAccessible
{
    public string Accessor(IProgramContext context, TargetLanguage targetLanguage) => targetLanguage switch {
        TargetLanguage.C => "true",
        _ => "1"
    };

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
