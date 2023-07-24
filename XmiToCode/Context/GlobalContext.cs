using static PropertyOrPort;

public record GlobalContext(DataTypeHelper DataTypes) : ProgramContext
{
    public override string InstanceReference => throw new NotImplementedException();

    public override bool IsLocalVariable(IAccessible accessible) => false;

    public override IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        return null;
    }

    // Signals
    // Enums
    public override IAccessible ResolveIdentifier(Identifier identifier)
    {
        return null;
    }

    internal override ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        throw new NotImplementedException();
    }

    internal override MessageSchema ResolveMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        throw new NotImplementedException();
    }

    internal MessageSchema ResolveMessageSchema(ComplexPropertyOrPort port, TypeIdentifier messageTypeIdentifier)
    {
        var umlType = port.UmlType;
        var receptions = umlType.OwnedReception
            .Select(x => (Key: new TypeIdentifier(x.Name), Value: x))
            .ToDictionary(x => x.Key, x => x.Value);

        // A complex port has a class type with many receptions,
        // each of which designate a possible message type
        var reception = receptions[messageTypeIdentifier];
        var signal = DataTypes.Signals[reception.Signal];
        return new MessageSchema(messageTypeIdentifier, signal, DataTypes);
    }
}
