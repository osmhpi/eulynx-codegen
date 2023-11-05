using XmiToCode.Accessibles;
using XmiToCode.Identifiers;
using XmiToCode.Messages;
using static XmiToCode.Accessibles.PropertyOrPort;

namespace XmiToCode.Parsing.Context;

public record ClassContext(PackageContext Global, DataTypeHelper DataTypes) : IProgramContext
{
    public Dictionary<TypeIdentifier, MessageSchema> IncomingMessages { get; }
        = DataTypes.Ports.Values.OfType<ComplexPropertyOrPort>()
            .SelectMany(x => x.UmlType.OwnedReception)
            .Select(x => Global.ResolveSignal(x.Signal))
            .ToDictionary(x => x.Identifier);

    public Dictionary<TypeIdentifier, MessageSchema> OutgoingMessages { get; } = new();

    public Dictionary<Identifier, PropertyOrPort> Ports { get; }
        = DataTypes.Ports.Values
            .Select(x => (Key: x.Identifier, Value: x))
            .ToDictionary(x => x.Key, x => x.Value);

    public Dictionary<Identifier, PropertyOrPort> Properties { get; }
        = DataTypes.Properties.Values
            .Select(x => (Key: x.Identifier, Value: x))
            .ToDictionary(x => x.Key, x => x.Value);

    public bool IsLocalVariable(IAccessible accessible) => false;

    public IAssignable ResolveAssignableIdentifier(Identifier identifier)
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

    public IAccessible ResolveIdentifier(Identifier identifier)
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

    public ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        if (DataTypes.Operations.Contains(identifier)) {
            return new MethodCall(identifier);
        }

        return Global.ResolveCallableIdentifier(identifier);
    }

    public (TypeIdentifier, List<MessageMember>) ResolveOutgoingMessageSchema(Identifier portIdentifier, TypeIdentifier messageTypeIdentifier)
    {
        if (OutgoingMessages.ContainsKey(messageTypeIdentifier)) {
            var uniqueMessageIdentifier = OutgoingMessages[messageTypeIdentifier].Identifier;
            return (uniqueMessageIdentifier, OutgoingMessages[messageTypeIdentifier].Members.Select(x =>
                new MessageMember(uniqueMessageIdentifier, x, new MessageAccessor(uniqueMessageIdentifier, x.Identifier, true))
            ).ToList());
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
            var signal = ResolveSignal(reception.Signal);

            OutgoingMessages[messageTypeIdentifier] = signal;

            // signal.Identifier is different from messageTypeIdentifier (uniqueness)
            return (signal.Identifier, signal.Members.Select(x => new MessageMember(signal.Identifier, x, new MessageAccessor(signal.Identifier, x.Identifier, true))).ToList());
        }

        throw new NotImplementedException();
    }

    public MessageSchema ResolveSignal(string signalId)
    {
        return Global.ResolveSignal(signalId);
    }
}
