public record MessageMember(TypeIdentifier Message, PropertyOrPort Member, IAccessor TheAccessor) : IAccessible, IAssignable
{
    public string Accessor(IProgramContext context, TargetLanguage targetLanguage)
    {
        return Member.Accessor(context, targetLanguage, TheAccessor);
    }

    public string Assign(IProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        return Member.Assign(context, other, targetLanguage, TheAccessor);
    }

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        return Member.Comparator(context, other, targetLanguage, TheAccessor);
    }

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        Member.EnsureComparableTypes(rhsIdentifier);
    }

    public IAccessible LookupValidIdentifier(Identifier identifier, IProgramContext context) => Member.LookupValidIdentifier(identifier, context);

    public IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier) => Member.LookupValidLiteral(literalIdentifier);
}
