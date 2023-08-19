public record BlockContext : ProgramContext
{
    public ProgramContext Parent { get; }
    private readonly string? _overrideInstanceReference;
    private readonly MessageSchema? _newAttributes;

    public MessageSchema? NewAttributes => _newAttributes;

    public BlockContext(ProgramContext parent, MessageSchema? newAttributes = null, string? overrideInstanceReference = null)
    {
        Parent = parent;
        _overrideInstanceReference = overrideInstanceReference;
        _newAttributes = newAttributes;
    }

    // Deconstructed Message Members
    public override IAccessible ResolveIdentifier(Identifier identifier)
    {
        if (NewAttributes != null && NewAttributes.MembersDict.ContainsKey(identifier)) {
            return NewAttributes.MembersDict[identifier];
        }

        return Parent.ResolveIdentifier(identifier);
    }

    public override IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        if (NewAttributes != null && NewAttributes.MembersDict.ContainsKey(identifier)) {
            return NewAttributes.MembersDict[identifier];
        }

        return Parent.ResolveAssignableIdentifier(identifier);
    }

    internal override MessageSchema ResolveOutgoingMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        return Parent.ResolveOutgoingMessageSchema(port, messageTypeIdentifier);
    }

    internal override ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        return Parent.ResolveCallableIdentifier(identifier);
    }

    public override bool IsLocalVariable(IAccessible accessible)
    {
        if (accessible is MessageMember member && NewAttributes != null && NewAttributes.Members.Contains(member))
            return true;
        return Parent.IsLocalVariable(accessible);
    }

    internal override MessageSchema ResolveIncomingMessageSchema(TypeIdentifier signal)
    {
        return Parent.ResolveIncomingMessageSchema(signal);
    }
}
