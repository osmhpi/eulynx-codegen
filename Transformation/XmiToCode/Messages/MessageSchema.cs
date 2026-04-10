using XmiToCode.Parsing.Accessibles;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Messages;

public record MessageSchema(PackagedElement Signal, Dictionary<string, PackagedElement> DataTypes)
{
    public TypeIdentifier Identifier { get; } = new UniqueTypeIdentifier(Signal.Name, Signal.Id);

    public virtual List<PropertyOrPort> Members { get; } = Signal.OwnedAttribute
        .Select(x => PropertyOrPort.CreatePropertyOrPort(new UniqueTypeIdentifier(Signal.Name, Signal.Id), x, DataTypes))
        .ToList();

    public IEnumerable<Codegen.Model.ValueType> GetValueTypes() {
        return Members
            .Where(x => x is StringPropertyOrPort)
            .Select(x => new Codegen.Model.ValueType(
                Identifier,
                x.Identifier,
                // x.MemberName,
                ((StringPropertyOrPort)x).AllowedValues))
            .Where(x => x.AllowedValues.Count > 0);
    }

    public Dictionary<Identifier, PropertyOrPort> MembersDict => Members.ToDictionary(x => x.Identifier);

}
