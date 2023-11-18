using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Accessibles;

public record UntypedPropertyOrPort(OwnedAttribute Property, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, ProxyFor)
{
    public override (string, string) DataType(TargetLanguage language)
    {
        return ("void*", "");
    }

    public override void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new Exception("Untyped property");
    }

    public override IAccessible RecordPossibleValue(LiteralIdentifier value)
    {
        throw new Exception("Untyped property");
    }
}

