public abstract record ProgramContext {
    public abstract string InstanceReference { get; }
    public abstract IAccessible ResolveIdentifier(Identifier identifier);
    public abstract IAssignable ResolveAssignableIdentifier(Identifier identifier);
    internal abstract MessageSchema ResolveMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier);
    internal abstract ICallable ResolveCallableIdentifier(Identifier identifier);
    public abstract bool IsLocalVariable(IAccessible accessible);
}
