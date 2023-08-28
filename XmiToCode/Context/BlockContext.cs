using XmiToCode;

public record BlockContext : ProgramContext
{
    public ProgramContext Parent { get; }
    private readonly MessageSchema? _locals;

    public MessageSchema? Locals => _locals;

    public BlockContext(ProgramContext parent, MessageSchema? locals = null)
    {
        Parent = parent;
        _locals = locals;
    }

    public IAccessible ResolveIdentifier(Identifier identifier)
    {
        if (Locals != null && Locals.MembersDict.ContainsKey(identifier)) {
            var messageProperty = Locals.MembersDict[identifier];
            return new MessageMember(Locals.Identifier, messageProperty,
                new MessageAccessor(Locals.Identifier, identifier, false));
        }

        return Parent.ResolveIdentifier(identifier);
    }

    public IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        if (Locals != null && Locals.MembersDict.ContainsKey(identifier)) {
            var messageProperty = Locals.MembersDict[identifier];
            return new MessageMember(Locals.Identifier, messageProperty,
                new MessageAccessor(Locals.Identifier, identifier, false));
        }

        return Parent.ResolveAssignableIdentifier(identifier);
    }

    public List<MessageMember> ResolveOutgoingMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        return Parent.ResolveOutgoingMessageSchema(port, messageTypeIdentifier);
    }

    public ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        return Parent.ResolveCallableIdentifier(identifier);
    }

    public bool IsLocalVariable(IAccessible accessible)
    {
        if (accessible is MessageMember member && Locals != null && Locals.Members.Contains(member.Member))
            return true;
        return Parent.IsLocalVariable(accessible);
    }

    MessageSchema ProgramContext.ResolveSignal(string signalId)
    {
        return Parent.ResolveSignal(signalId);
    }
}
