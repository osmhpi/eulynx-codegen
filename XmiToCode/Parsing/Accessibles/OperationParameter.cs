using System.Net.Http.Headers;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Accessibles;

public record OperationParameter(OwnedParameter UmlParameter, PropertyOrPort Parameter, IAccessor TheAccessor) : IAccessible, IAssignable
{
    public string Accessor(IProgramContext context, TargetLanguage targetLanguage)
    {
        return Parameter.Accessor(context, targetLanguage, TheAccessor);
    }

    public string Assign(IProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        // Not actually assignable, just used for checking types in equations
        throw new NotImplementedException();
    }

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        return Parameter.Comparator(context, other, targetLanguage, TheAccessor);
    }

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        Parameter.EnsureComparableTypes(rhsIdentifier);
    }

    public IAccessible LookupValidIdentifier(Identifier identifier, IProgramContext context)
    {
        return Parameter.LookupValidIdentifier(identifier, context);
    }

    public IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier)
    {
        return Parameter.LookupValidLiteral(literalIdentifier);
    }
}
