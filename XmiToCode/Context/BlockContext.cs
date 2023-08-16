public record BlockContext : ProgramContext
{
    public ProgramContext Parent { get; }
    private readonly string? _overrideInstanceReference;
    private readonly Dictionary<string, PropertyOrPort>? _newAttributes;

    public override string InstanceReference => _overrideInstanceReference ?? Parent.InstanceReference;

    public Dictionary<string, PropertyOrPort>? NewAttributes => _newAttributes;

    public BlockContext(ProgramContext parent, Dictionary<string, PropertyOrPort>? newAttributes = null, string? overrideInstanceReference = null)
    {
        Parent = parent;
        _overrideInstanceReference = overrideInstanceReference;
        _newAttributes = newAttributes;
    }

    // Deconstructed Message Members
    public override IAccessible ResolveIdentifier(Identifier identifier)
    {
        if (NewAttributes != null && NewAttributes.ContainsKey(identifier.Name)) {
            return NewAttributes[identifier.Name];
        }

        return Parent.ResolveIdentifier(identifier);
    }

    public override IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        if (NewAttributes != null && NewAttributes.ContainsKey(identifier.Name)) {
            return NewAttributes[identifier.Name];
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
        if (accessible is PropertyOrPort prop && NewAttributes != null && NewAttributes.ContainsValue(prop))
            return true;
        return Parent.IsLocalVariable(accessible);
    }

    internal override MessageSchema ResolveIncomingMessageSchema(TypeIdentifier signal)
    {
        return Parent.ResolveIncomingMessageSchema(signal);
    }
}
