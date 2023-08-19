using static PropertyOrPort;

public record ClassContext(GlobalContext Parent, DataTypeHelper DataTypes) : ProgramContext
{
    // Signals
    // Ports
    // Properties
    // Enums ?

    public Dictionary<TypeIdentifier, MessageSchema> MessageSchema { get; }
        = DataTypes.Ports.Values.OfType<ComplexPropertyOrPort>()
            .SelectMany(x => x.UmlType.OwnedReception)
            .Select(x => DataTypes.Signals[x.Signal])
            .Select(x => new MessageSchema(new TypeIdentifier(x.Name), x, DataTypes))
            .ToDictionary(x => x.Identifier);

    // public override string InstanceReference { get; } = Writer.DefaultInstanceReference;

    public Dictionary<TypeIdentifier, MessageSchema> UsedOutgoingMessageTypes { get; } = new();

    public Dictionary<Identifier, PropertyOrPort> Ports { get; }
        = DataTypes.Ports.Values
            .Select(x => (Key: x.Identifier, Value: x))
            .ToDictionary(x => x.Key, x => x.Value);

    public Dictionary<Identifier, PropertyOrPort> Properties { get; }
        = DataTypes.Properties.Values
            .Select(x => (Key: x.Identifier, Value: x))
            .ToDictionary(x => x.Key, x => x.Value);

    public override bool IsLocalVariable(IAccessible accessible) => false;

    public override IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        var port = DataTypes.Ports.Values.SingleOrDefault(x => x.Name == identifier.Name);
        if (port != null) {
            return port;
        }

        var property = DataTypes.Properties.Values.SingleOrDefault(x => x.Name == identifier.Name);
        if (property != null) {
            return property;
        }

        return Parent.ResolveAssignableIdentifier(identifier);
    }

    public override IAccessible ResolveIdentifier(Identifier identifier)
    {
        var port = DataTypes.Ports.Values.SingleOrDefault(x => x.Name == identifier.Name);
        if (port != null) {
            return port;
        }

        return Parent.ResolveIdentifier(identifier);
    }

    internal override ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        if (DataTypes.Operations.Contains(identifier)) {
            return new MethodCall(identifier);
        }

        return Parent.ResolveCallableIdentifier(identifier);
    }

    internal override MessageSchema ResolveIncomingMessageSchema(TypeIdentifier signal)
    {
        return MessageSchema[signal];
    }

    internal override MessageSchema ResolveOutgoingMessageSchema(Identifier portIdentifier, TypeIdentifier messageTypeIdentifier)
    {
        if (UsedOutgoingMessageTypes.ContainsKey(messageTypeIdentifier)) {
            return UsedOutgoingMessageTypes[messageTypeIdentifier];
        }

        var port = Ports[portIdentifier];
        if (port is ComplexPropertyOrPort complexPort) {

            var umlType = complexPort.UmlType;
            var receptions = umlType.OwnedReception
                .Select(x => (Key: new TypeIdentifier(x.Name), Value: x))
                .ToDictionary(x => x.Key, x => x.Value);

            // A complex port has a class type with many receptions,
            // each of which designate a possible message type
            var reception = receptions[messageTypeIdentifier];
            var signal = DataTypes.Signals[reception.Signal];
            var result = MessageSchema[new TypeIdentifier(signal.Name)];

            UsedOutgoingMessageTypes[messageTypeIdentifier] = result;
            return result;
        }

        throw new NotImplementedException();
    }
}
