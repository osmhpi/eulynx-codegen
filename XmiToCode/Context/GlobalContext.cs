using XmiToCode.Accessibles;
using XmiToCode.Classes;
using XmiToCode.Identifiers;
using XmiToCode.Messages;

namespace XmiToCode.Context;

public record GlobalContext(Dictionary<TypeIdentifier, GlobalEnumeration> Enumerations, Dictionary<string, (PackagedElement, PackagedElement Signal)> signals, Dictionary<string, XmiToCode.PackagedElement> DataTypes, Dictionary<string, XmiToCode.PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents, List<PackagedElement> genericEvents) : IProgramContext
{
    public bool IsLocalVariable(IAccessible accessible) => false;

    public Dictionary<TypeIdentifier, MessageSchema> Messages { get; } =
        signals.Values
            .Select(x => new MessageSchema(x.Signal, DataTypes))
            .ToDictionary(x => x.Identifier);

    public IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        throw new ModelException($"Could not resolve assignable identifier {identifier.Name}");
    }

    // Signals
    // Enums
    public IAccessible ResolveIdentifier(Identifier identifier)
    {
        if (identifier.RawName.Contains(".")) {
            // Fully qualified identifier
            var nameParts = identifier.RawName.Split(".");
            if (nameParts.Length == 2) {
                var result = Enumerations.Values.SingleOrDefault(x => x.Name.RawName == nameParts.First());
                if (result != null) {
                    return new EnumerationMember(result.Name, result.Members.Single(x => x.RawName == nameParts.Last()));
                }
            }
        }

        var matchingEnumerations = Enumerations.Values
            .Where(x => x.Members.Any(x => x.RawName == identifier.RawName))
            .ToList();

        if (matchingEnumerations.Count > 0) {
            if (matchingEnumerations.Count > 1) {
                throw new ModelException($"Identifier {identifier} is ambiguous between global enum types");
            }
            var result = matchingEnumerations.Single();

            return new EnumerationMember(result.Name, result.Members.Single(x => x.RawName == identifier.RawName));
        }


        throw new ModelException($"Could not resolve accessible identifier {identifier.Name}");
    }

    public MessageSchema ResolveSignal(string signalId)
    {
        return Messages.Values.Single(x => x.Signal.Id == signalId);
    }

    public ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        throw new NotImplementedException();
    }

    public MessageSchema ResolveIncomingMessageSchema(TypeIdentifier signal)
    {
        throw new NotImplementedException();
    }

    public (TypeIdentifier, List<MessageMember>) ResolveOutgoingMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        throw new NotImplementedException();
    }
}
