using XmiToCode;

public record EnumerationMember(TypeIdentifier EnumerationType, GlobalEnumIdentifier Member) : IAccessible {

    public string Accessor(IProgramContext context, TargetLanguage targetLanguage)
        => $"{EnumerationType.Name}__{Member.Name}";

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
