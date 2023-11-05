using XmiToCode.Accessibles;
using XmiToCode.Classes;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Messages;

public record MessageSchema(PackagedElement Signal, Dictionary<string, PackagedElement> DataTypes)
{
    public TypeIdentifier Identifier { get; } = new UniqueTypeIdentifier(Signal.Name, Signal.Id);

    public virtual List<PropertyOrPort> Members { get; } = Signal.OwnedAttribute
        .Select(x => PropertyOrPort.CreatePropertyOrPort(x, DataTypes))
        .ToList();

    public IEnumerable<Classes.ValueType> GetValueTypes() {
        return Members
            .Where(x => x is PropertyOrPort.StringPropertyOrPort)
            .Select(x => new Classes.ValueType(
                new ClassInfo(Identifier.Name, ""),
                x.Identifier,
                // x.MemberName,
                ((PropertyOrPort.StringPropertyOrPort)x).AllowedValues))
            .Where(x => x.AllowedValues.Count > 0);
    }

    public Dictionary<Identifier, PropertyOrPort> MembersDict => Members.ToDictionary(x => x.Identifier);

}
