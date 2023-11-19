using XmiToCode.Parsing.Accessibles;
using XmiToCode.Identifiers;
using XmiToCode.Messages;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Context;

// From the implementations, it looks like this class is not needed.
public record PackageContext(GlobalContext Parent, PackagedElement UmlPackage, Dictionary<string, PackagedElement> PackageEvents) : IProgramContext
{
    public bool IsLocalVariable(IAccessible accessible)
    {
        return Parent.IsLocalVariable(accessible);
    }

    public IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        return Parent.ResolveAssignableIdentifier(identifier);
    }

    public IAccessible ResolveIdentifier(Identifier identifier)
    {
        return Parent.ResolveIdentifier(identifier);
    }

    public MessageSchema ResolveSignal(string signalId)
    {
        return Parent.ResolveSignal(signalId);
    }

    public ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        return Parent.ResolveCallableIdentifier(identifier);
    }

    public MessageSchema ResolveIncomingMessageSchema(TypeIdentifier signal)
    {
        return Parent.ResolveIncomingMessageSchema(signal);
    }

    public (TypeIdentifier, List<MessageMember>) ResolveOutgoingMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        return Parent.ResolveOutgoingMessageSchema(port, messageTypeIdentifier);
    }
}
