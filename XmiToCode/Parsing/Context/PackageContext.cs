using XmiToCode.Accessibles;
using XmiToCode.Identifiers;
using XmiToCode.Messages;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Context;

public record PackageContext(GlobalContext Parent, PackagedElement UmlPackage, Dictionary<string, PackagedElement> PackageEvents) : IProgramContext
{
    // public Dictionary<string, PackagedElement> Signals { get; } =
    //     GetElements(UmlPackage, "uml:Signal")
    //         .ToDictionary(x => x.Id);

    // private static List<PackagedElement> GetElements(PackagedElement package, string umlType) {
    //     return package.PackagedElements
    //         .Where(x => x.Type == umlType)
    //         .ToList();
    // }

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
