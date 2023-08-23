using XmiToCode;

public record EnumerationMember(PackagedElement UmlEnumeration, GlobalEnumIdentifier Member) : IAccessible {
    public TypeIdentifier EnumerationType => new TypeIdentifier(UmlEnumeration.Name);

    public string Accessor(ProgramContext context, TargetLanguage targetLanguage)
        => $"{EnumerationType.Name}__{Member.Name}";

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
