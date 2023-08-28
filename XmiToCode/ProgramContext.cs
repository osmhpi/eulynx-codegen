using XmiToCode;

public interface ProgramContext {
    public IAccessible ResolveIdentifier(Identifier identifier);
    public IAssignable ResolveAssignableIdentifier(Identifier identifier);
    // public MessageSchema ResolveIncomingMessageSchema(TypeIdentifier signal);
    public List<MessageMember> ResolveOutgoingMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier);
    public ICallable ResolveCallableIdentifier(Identifier identifier);
    public bool IsLocalVariable(IAccessible accessible);
    public MessageSchema ResolveSignal(string signalId);
}
