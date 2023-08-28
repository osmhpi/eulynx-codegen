using XmiToCode;

public record MessageSchema(PackagedElement Signal, Dictionary<string, PackagedElement> DataTypes)
{
    public TypeIdentifier Identifier { get; } = new TypeIdentifier(Signal.Name);

    public virtual List<PropertyOrPort> Members { get; } = Signal.OwnedAttribute
        .Select(x =>
            PropertyOrPort.Create(x, DataTypes, new ClassInfo("Message", "")))
        .ToList();

    public IEnumerable<ValueType> GetValueTypes() {
        return Members
            .Where(x => x is PropertyOrPort.StringPropertyOrPort)
            .Select(x => new ValueType(
                new ClassInfo(Identifier.Name, ""),
                x.Identifier,
                // x.MemberName,
                ((PropertyOrPort.StringPropertyOrPort)x).AllowedValues))
            .Where(x => x.AllowedValues.Count > 0);
    }

    public Dictionary<Identifier, PropertyOrPort> MembersDict => Members.ToDictionary(x => x.Identifier);

}
