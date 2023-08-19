public interface IAccessible {
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage);
    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage);
    void EnsureComparableTypes(IAccessible rhsIdentifier);
}
