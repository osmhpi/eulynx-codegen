using XmiToCode.Classes;
using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;

namespace XmiToCode.Accessibles;

public record ImplicitEnumMember(string EnumType, LiteralIdentifier Literal) : IAccessible {
    public string Accessor(IProgramContext context, TargetLanguage targetLanguage) => $"{EnumType}__{Literal.Name}";

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
