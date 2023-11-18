using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Accessibles;

public record ComplexPropertyOrPort(OwnedAttribute Property, PackagedElement UmlType, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, ProxyFor)
{
    // TODO: We re-implement three times an implemention detail of GlobalEnumeration:
    // new UniqueTypeIdentifier(UmlType.Name, UmlType.Id)
    // Better look it up and use property

    public override (string, string) DataType(TargetLanguage language) => UmlType.Type switch
    {
        "uml:Class" => ("Channel<EulynxMessages.Message>", ""),
        "uml:Enumeration" => (new UniqueTypeIdentifier(UmlType.Name, UmlType.Id).Name, ""),
        _ => ("int", "")
    };

    public override void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        if (rhsIdentifier is EnumerationMember enumerationMember)
        {
            // TODO: Perform further checks
            return;
        }

        throw new Exception("Incomparable types");
    }

    public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
    {
        if (UmlType.Type != "uml:Enumeration")
        {
            throw new NotImplementedException();
        }

        var enumLiteral = UmlType.OwnedLiteral
            .Select(x => new GlobalEnumIdentifier(x.Name))
            .Single(x => x.RawName == literal.RawName);
        return new EnumerationMember(new UniqueTypeIdentifier(UmlType.Name, UmlType.Id), enumLiteral);
    }

    public override IAccessible LookupValidIdentifier(Identifier identifier, IProgramContext context)
    {
        var enumLiteral = UmlType.OwnedLiteral
            .Select(x => new GlobalEnumIdentifier(x.Name))
            .SingleOrDefault(x => x.RawName == identifier.RawName);
        if (enumLiteral != null)
        {
            return new EnumerationMember(new UniqueTypeIdentifier(UmlType.Name, UmlType.Id), enumLiteral);
        }

        return base.LookupValidIdentifier(identifier, context);
    }
}
