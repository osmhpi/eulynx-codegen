using static PropertyOrPort;

public record ClassContext(GlobalContext Global, DataTypeHelper DataTypes) : ProgramContext
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
        var port = Ports.ContainsKey(identifier) ? Ports[identifier] : null;
        if (port != null) {
            return port;
        }

        var property = Properties.ContainsKey(identifier) ? Properties[identifier] : null;
        if (property != null) {
            return property;
        }

        return Global.ResolveAssignableIdentifier(identifier);
    }

    public override IAccessible ResolveIdentifier(Identifier identifier)
    {
        var port = Ports.ContainsKey(identifier) ? Ports[identifier] : null;
        if (port != null) {
            return port;
        }

        var property = Properties.ContainsKey(identifier) ? Properties[identifier] : null;
        if (property != null) {
            return property;
        }

        return Global.ResolveIdentifier(identifier);
    }

    internal override ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        if (DataTypes.Operations.Contains(identifier)) {
            return new MethodCall(identifier);
        }

        return Global.ResolveCallableIdentifier(identifier);
    }

    internal override MessageSchema ResolveIncomingMessageSchema(TypeIdentifier signal)
    {
        return MessageSchema[signal];
    }

    internal override MessageSchema ResolveOutgoingMessageSchema(Identifier portIdentifier, TypeIdentifier messageTypeIdentifier)
    {
        if (UsedOutgoingMessageTypes.ContainsKey(messageTypeIdentifier)) {
            return new OutgoingMessageSchema(UsedOutgoingMessageTypes[messageTypeIdentifier]);
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
            return new OutgoingMessageSchema(result);
        }

        throw new NotImplementedException();
    }
}
