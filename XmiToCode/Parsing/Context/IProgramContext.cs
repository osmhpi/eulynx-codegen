using XmiToCode.Parsing.Accessibles;
using XmiToCode.Identifiers;
using XmiToCode.Messages;
using XmiToCode.Instructions;

namespace XmiToCode.Parsing.Context;

public interface IProgramContext {
    public IAccessible ResolveIdentifier(Identifier identifier);
    public IAssignable ResolveAssignableIdentifier(Identifier identifier);
    public (TypeIdentifier MessageIdentifier, List<MessageMember> Members) ResolveOutgoingMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier);
    public ICallable ResolveCallableIdentifier(Identifier identifier);
    public bool IsLocalVariable(IAccessible accessible);
    public MessageSchema ResolveSignal(string signalId);
    void EnsureReturnType(IAccessible value);
}
