using static PropertyOrPort;

// What does this thing do ??
// Probably we should resolve global enumerations here...
public record GlobalContext() : ProgramContext
{
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
