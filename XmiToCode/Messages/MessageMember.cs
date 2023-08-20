using XmiToCode;

public record MessageMember(TypeIdentifier Message, Identifier MemberName, PackagedElement Type, PropertyOrPort Member) : IAccessible, IAssignable
{
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage)
    {
        return Member.Accessor(context, targetLanguage);
    }

    public string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        // return $"{Accessor(context, targetLanguage)} = {other.Accessor(context, targetLanguage)};";
        return Member.Assign(context, other, targetLanguage);
    }

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        return Member.Comparator(context, other, targetLanguage);
    }

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        Member.EnsureComparableTypes(rhsIdentifier);
    }

    public IAccessible LookupValidIdentifier(Identifier identifier, ProgramContext context) => Member.LookupValidIdentifier(identifier, context);

    public IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier) => Member.LookupValidLiteral(literalIdentifier);
}
