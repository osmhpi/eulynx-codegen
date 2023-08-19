public record BoolLiteral(bool Value) : IAccessible
{
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage) => Value ? "true" : "false";

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
