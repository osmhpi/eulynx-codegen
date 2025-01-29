using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;

namespace XmiToCode.Parsing.Accessibles;

public record ImplicitEnumMember(string Scope, string EnumType, LiteralIdentifier Literal) : IAccessible {
    public string TypeName => $"{Scope}_{EnumType}Value";

    public string Accessor(IProgramContext context, TargetLanguage targetLanguage) => $"{TypeName}__{Literal.Name}";

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
