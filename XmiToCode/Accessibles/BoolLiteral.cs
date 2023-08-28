using XmiToCode.Context;

namespace XmiToCode.Accessibles;

public record BoolLiteral(bool Value) : IAccessible
{
    public string Accessor(IProgramContext context, TargetLanguage targetLanguage) => Value ? "true" : "false";

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
