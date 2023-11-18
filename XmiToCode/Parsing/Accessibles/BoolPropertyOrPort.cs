using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Accessibles;

public record BoolPropertyOrPort(OwnedAttribute Property, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, ProxyFor)
{
    public override (string, string) DataType(TargetLanguage language) => ("bool", "");

    public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
    {
        if (literal.Name == "True")
            return new BoolLiteral(true);

        if (literal.Name == "False")
            return new BoolLiteral(false);

        throw new ArgumentException($"Invalid bool value: {literal}");
    }

    public override IAccessible LookupValidIdentifier(Identifier identifier, IProgramContext context)
    {
        if (identifier.Name == "True")
            return new BoolLiteral(true);

        if (identifier.Name == "False")
            return new BoolLiteral(false);

        return base.LookupValidIdentifier(identifier, context);
    }

    public override void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        if (rhsIdentifier is not BoolPropertyOrPort && rhsIdentifier is not BoolLiteral)
        {
            throw new Exception("Incomparable types");
        }
    }
}
