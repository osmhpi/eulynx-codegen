using XmiToCode.Identifiers;
using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Model;

public record Class(
    PackagedElement UmlClass,
    ClassContext ClassContext,
    List<Operation> Operations,
    Region Region
) {
    public TypeIdentifier ClassName { get; } = new TypeIdentifier(UmlClass.Name);
}
