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

    internal override MessageSchema ResolveIncomingMessageSchema(TypeIdentifier signal)
    {
        throw new NotImplementedException();
    }

    internal override MessageSchema ResolveOutgoingMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        throw new NotImplementedException();
    }
}
