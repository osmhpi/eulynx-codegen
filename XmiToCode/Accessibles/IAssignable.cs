public interface IAssignable : IAccessible {
    IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier);
    public string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage);
}
