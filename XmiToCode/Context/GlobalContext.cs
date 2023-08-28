using XmiToCode;

public record GlobalContext(List<GlobalEnumeration> Enumerations, Dictionary<string, (PackagedElement, PackagedElement Signal)> signals, Dictionary<string, XmiToCode.PackagedElement> DataTypes, Dictionary<string, XmiToCode.PackagedElement> changeEvents, Dictionary<string, XmiToCode.PackagedElement> timeEvents, List<XmiToCode.PackagedElement> genericEvents) : ProgramContext
{
    public bool IsLocalVariable(IAccessible accessible) => false;

    public Dictionary<(string, TypeIdentifier), MessageSchema> Messages { get; } =
        signals.Values
            .Select(x => (x.Item1, new MessageSchema(x.Signal, DataTypes)))
            .ToDictionary(x => (x.Item1.Id, x.Item2.Identifier), x => x.Item2);

    public IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        throw new ModelException($"Could not resolve assignable identifier {identifier.Name}");
    }

    // Signals
    // Enums
    public IAccessible ResolveIdentifier(Identifier identifier)
    {
        var matchingEnumerations = Enumerations
            .Where(x => x.Members.Any(x => x.RawName == identifier.RawName))
            .ToList();

        if (matchingEnumerations.Count > 0) {
            if (matchingEnumerations.Count > 1) {
                throw new ModelException($"Identifier {identifier} is ambiguous between global enum types");
            }
            var result = matchingEnumerations.Single();

            return new EnumerationMember(result.Enumeration, result.Members.Single(x => x.RawName == identifier.RawName));
        }

        throw new ModelException($"Could not resolve accessible identifier {identifier.Name}");
    }

    public MessageSchema ResolveSignal(string signalId)
    {
        return Messages.Values.Single(x => x.Signal.Id == signalId);
    }

    public ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        throw new NotImplementedException();
    }

    public MessageSchema ResolveIncomingMessageSchema(TypeIdentifier signal)
    {
        throw new NotImplementedException();
    }

    public List<MessageMember> ResolveOutgoingMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        throw new NotImplementedException();
    }
}
