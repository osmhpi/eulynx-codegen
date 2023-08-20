public interface IAssignable : IAccessible {
    IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier);
    IAccessible LookupValidIdentifier(Identifier identifier, ProgramContext context);
    public string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage);
}
