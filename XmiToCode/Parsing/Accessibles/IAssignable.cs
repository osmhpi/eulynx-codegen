using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;

namespace XmiToCode.Parsing.Accessibles;

public interface IAssignable : IAccessible {
    IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier);
    IAccessible LookupValidIdentifier(Identifier identifier, IProgramContext context);
    public string Assign(IProgramContext context, IAccessible other, TargetLanguage targetLanguage);
}
