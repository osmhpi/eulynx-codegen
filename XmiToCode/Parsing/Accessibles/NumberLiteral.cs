using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Accessibles;

public record NumberLiteral(int Value) : IAccessible
{
    public string Accessor(IProgramContext context, TargetLanguage targetLanguage) => Value.ToString();

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
