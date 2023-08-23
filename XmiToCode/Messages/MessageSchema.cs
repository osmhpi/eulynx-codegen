using XmiToCode;

public record MessageSchema(TypeIdentifier Identifier, PackagedElement Signal, DataTypeHelper DataTypes)
{
    public virtual List<MessageMember> Members { get; } = Signal.OwnedAttribute
        .Select(x => new MessageMember(Identifier, new Identifier(x.Name), DataTypes.DataTypes[x.Type],
            PropertyOrPort.Create(x, DataTypes.DataTypes, new ClassInfo("Message", ""), new MessageAccessor(Identifier, new Identifier(x.Name), false))))
        .ToList();

    public IEnumerable<ValueType> GetValueTypes() {
        return Members
            .Where(x => x.Member is PropertyOrPort.StringPropertyOrPort)
            .Select(x => new ValueType(
                new ClassInfo(Identifier.Name, ""),
                x.MemberName,
                ((PropertyOrPort.StringPropertyOrPort)x.Member).AllowedValues))
            .Where(x => x.AllowedValues.Count > 0);
    }

    public Dictionary<Identifier, MessageMember> MembersDict => Members.ToDictionary(x => x.MemberName);

    internal MessageMember GetMemberByIndex(int i)
    {
        return Members[i];
    }
}

public record OutgoingMessageSchema(MessageSchema Inner) : MessageSchema(Inner.Identifier, Inner.Signal, Inner.DataTypes) {
    public override List<MessageMember> Members { get; } = Inner.Signal.OwnedAttribute
        .Select(x => new MessageMember(Inner.Identifier, new Identifier(x.Name), Inner.DataTypes.DataTypes[x.Type],
            PropertyOrPort.Create(x, Inner.DataTypes.DataTypes, new ClassInfo("Message", ""), new MessageAccessor(Inner.Identifier, new Identifier(x.Name), true))))
        .ToList();
}
