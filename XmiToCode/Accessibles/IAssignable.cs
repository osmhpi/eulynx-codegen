using XmiToCode.Context;
using XmiToCode.Identifiers;

namespace XmiToCode.Accessibles;

public interface IAssignable : IAccessible {
    IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier);
    IAccessible LookupValidIdentifier(Identifier identifier, IProgramContext context);
    public string Assign(IProgramContext context, IAccessible other, TargetLanguage targetLanguage);
}
