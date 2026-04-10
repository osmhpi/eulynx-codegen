using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Accessibles;

public record Addition(IAccessible lhs, IAccessible rhs) : IAccessible
{
    public string Accessor(IProgramContext context, TargetLanguage targetLanguage) =>
        $"{lhs.Accessor(context, targetLanguage)} + {rhs.Accessor(context, targetLanguage)}";

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
