using XmiToCode.Parsing.Accessibles;
using XmiToCode.Identifiers;
using XmiToCode.Messages;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Context;

public record OperationContext(ClassContext Parent, List<OwnedParameter> ownedParameter) : IProgramContext
{
    public TypeIdentifier? ReturnType { get; private set; }

    public Dictionary<Identifier, OperationParameter> Parameters { get; }
        = ownedParameter.ToDictionary(
            x => new Identifier(x.Name),
            x => new OperationParameter(x, PropertyOrPort.CreatePropertyOrPort(Parent.ClassName, x, Parent.Package.Parent.DataTypes), new ParameterAccessor()));

    public IAccessible ResolveIdentifier(Identifier identifier)
    {
        if (Parameters.TryGetValue(identifier, out var p))
        {
            return p;
        }

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
        else if (value is IntegerPropertyOrPort || value is NumberLiteral)
        {
            if (ReturnType == null)
            {
                ReturnType = new TypeIdentifier("int");
            }
            else if (ReturnType != new TypeIdentifier("int"))
            {
                throw new InvalidOperationException("Return type mismatch");
            }
        }
        else if (value is ComplexPropertyOrPort complexPropertyOrPort)
        {
            if (ReturnType == null)
            {
                ReturnType = new UniqueTypeIdentifier(complexPropertyOrPort.UmlType.Name, complexPropertyOrPort.UmlType.Id);
            }
            else if (ReturnType != new UniqueTypeIdentifier(complexPropertyOrPort.UmlType.Name, complexPropertyOrPort.UmlType.Id))
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
