using XmiToCode.Parsing.Accessibles;
using XmiToCode.Identifiers;
using XmiToCode.Messages;

namespace XmiToCode.Parsing.Context;

public record OperationContext : IProgramContext
{
    public TypeIdentifier? ReturnType { get; private set; }

    public IProgramContext Parent { get; }

    public OperationContext(IProgramContext parent)
    {
        Parent = parent;
    }

    public IAccessible ResolveIdentifier(Identifier identifier)
    {
        return Parent.ResolveIdentifier(identifier);
    }

    public IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        return Parent.ResolveAssignableIdentifier(identifier);
    }

    public (TypeIdentifier, List<MessageMember>) ResolveOutgoingMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        return Parent.ResolveOutgoingMessageSchema(port, messageTypeIdentifier);
    }

    public ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        return Parent.ResolveCallableIdentifier(identifier);
    }

    public bool IsLocalVariable(IAccessible accessible)
    {
        return Parent.IsLocalVariable(accessible);
    }

    MessageSchema IProgramContext.ResolveSignal(string signalId)
    {
        return Parent.ResolveSignal(signalId);
    }

    public void EnsureReturnType(IAccessible value)
    {
        if (value is EnumerationMember enumerationMember)
        {
            if (ReturnType == null)
            {
                ReturnType = enumerationMember.EnumerationType;
            }
            else if (ReturnType != enumerationMember.EnumerationType)
            {
                throw new InvalidOperationException("Return type mismatch");
            }
        }
        else
        {
            throw new InvalidOperationException("Return type must be enumeration member.");
        }

    }
}
