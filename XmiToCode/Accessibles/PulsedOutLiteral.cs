public record PulsedOutLiteral() : IAccessible
{
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage) => targetLanguage switch {
        TargetLanguage.C => "true",
        _ => "1"
    };

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
