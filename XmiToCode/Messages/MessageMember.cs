public record MessageMember(TypeIdentifier Message, PropertyOrPort Member, IAccessor TheAccessor) : IAccessible, IAssignable
{
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage)
    {
        return Member.Accessor(context, targetLanguage, TheAccessor);
    }

    public string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        return Member.Assign(context, other, targetLanguage, TheAccessor);
    }

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        return Member.Comparator(context, other, targetLanguage, TheAccessor);
    }

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        Member.EnsureComparableTypes(rhsIdentifier);
    }

    public IAccessible LookupValidIdentifier(Identifier identifier, ProgramContext context) => Member.LookupValidIdentifier(identifier, context);

    public IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier) => Member.LookupValidLiteral(literalIdentifier);
}
