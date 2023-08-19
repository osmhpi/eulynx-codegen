public record ImplicitEnumMember(string EnumType, LiteralIdentifier Literal, ClassInfo Class) : IAccessible {
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage) => $"{EnumType}__{Literal.Name}";

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
