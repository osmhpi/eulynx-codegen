public record BlockContext : ProgramContext
{
    public ProgramContext Parent { get; }
    private readonly string? _overrideInstanceReference;
    private readonly Dictionary<string, PropertyOrPort>? _newAttributes;

    public override string InstanceReference => _overrideInstanceReference ?? Parent.InstanceReference;

    public BlockContext(ProgramContext parent, Dictionary<string, PropertyOrPort>? newAttributes = null, string? overrideInstanceReference = null)
    {
        Parent = parent;
        _overrideInstanceReference = overrideInstanceReference;
        _newAttributes = newAttributes;
    }

    // Deconstructed Message Members
    public override IAccessible ResolveIdentifier(Identifier identifier)
    {
        if (_newAttributes != null && _newAttributes.ContainsKey(identifier.Name)) {
            return _newAttributes[identifier.Name];
        }

        return Parent.ResolveIdentifier(identifier);
    }

    public override IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        if (_newAttributes != null && _newAttributes.ContainsKey(identifier.Name)) {
            return _newAttributes[identifier.Name];
        }

        return Parent.ResolveAssignableIdentifier(identifier);
    }

    internal override MessageSchema ResolveMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        return Parent.ResolveMessageSchema(port, messageTypeIdentifier);
    }

    internal override ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        return Parent.ResolveCallableIdentifier(identifier);
    }

    public override bool IsLocalVariable(IAccessible accessible)
    {
        if (accessible is PropertyOrPort prop && _newAttributes != null && _newAttributes.ContainsValue(prop))
            return true;
        return Parent.IsLocalVariable(accessible);
    }
}
