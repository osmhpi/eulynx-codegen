using static PropertyOrPort;

public record ClassContext(GlobalContext Parent, DataTypeHelper DataTypes) : ProgramContext
{
    // Signals
    // Ports
    // Properties
    // Enums ?

    // public Dictionary<TypeIdentifier, MessageSchema> Signals { get; }
    //     = DataTypes.Signals.Values
    //         .Select(x => (Key: new TypeIdentifier(x.Name), Value: x))
    //         .Select(x => (x.Key, Value: new MessageSchema(x.Key)))
    //         .ToDictionary(x => x.Key, x => x.Value);

    public override string InstanceReference { get; } = "this";

    public Dictionary<TypeIdentifier, MessageSchema> UsedMessageTypes { get; } = new();

    public Dictionary<Identifier, PropertyOrPort> Ports { get; }
        = DataTypes.Ports.Values
            .Select(x => (Key: new Identifier(x.Property.Name), Value: x))
            .ToDictionary(x => x.Key, x => x.Value);

    public Dictionary<Identifier, PropertyOrPort> Properties { get; }
        = DataTypes.Properties.Values
            .Select(x => (Key: new Identifier(x.Property.Name), Value: x))
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
        var operation = DataTypes.Operations.SingleOrDefault(x => new Identifier(x.Op.Name) == identifier);
        if (operation != null) {
            return new Method(new Identifier(operation.Op.Name), operation);
        }

        return Parent.ResolveCallableIdentifier(identifier);
    }

    internal override MessageSchema ResolveMessageSchema(Identifier portIdentifier, TypeIdentifier messageTypeIdentifier)
    {
        if (UsedMessageTypes.ContainsKey(messageTypeIdentifier)) {
            return UsedMessageTypes[messageTypeIdentifier];
        }

        var port = Ports[portIdentifier];
        if (port is ComplexPropertyOrPort complexPort) {
            var result = Parent.ResolveMessageSchema(complexPort, messageTypeIdentifier);
            UsedMessageTypes[messageTypeIdentifier] = result;
            return result;
        }

        throw new NotImplementedException();
    }
}
