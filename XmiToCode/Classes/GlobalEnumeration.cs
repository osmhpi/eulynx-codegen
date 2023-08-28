using XmiToCode.Identifiers;

namespace XmiToCode.Classes;

public record GlobalEnumeration(PackagedElement Enumeration) {

    public TypeIdentifier Name { get; } = new UniqueTypeIdentifier(Enumeration.Name, Enumeration.Id);
    public IEnumerable<GlobalEnumIdentifier> Members { get; } =
        Enumeration.OwnedLiteral.Select(lit => new GlobalEnumIdentifier(lit.Name));
}
