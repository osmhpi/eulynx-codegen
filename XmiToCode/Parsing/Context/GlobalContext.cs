using XmiToCode.Parsing.Accessibles;
using XmiToCode.Identifiers;
using XmiToCode.Messages;
using XmiToCode.Parsing.Model;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Context;

public record GlobalContext(Dictionary<TypeIdentifier, GlobalEnumeration> Enumerations, Dictionary<string, (PackagedElement, PackagedElement Signal)> Signals, Dictionary<string, PackagedElement> DataTypes, Dictionary<string, PackagedElement> ChangeEvents, Dictionary<string, PackagedElement> TimeEvents, List<PackagedElement> GenericEvents) : IProgramContext
{
    public bool IsLocalVariable(IAccessible accessible) => false;

    public Dictionary<TypeIdentifier, MessageSchema> Messages { get; } =
        Signals.Values
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
        if (identifier.RawName.Contains('.')) {
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
            #if !DISABLE_HACKS
            // F_SCI_TDS_Report_Track_Circuit
            if (identifier.Name == "Technical"
                && matchingEnumerations.Count == 2
                && matchingEnumerations.First().Name.RawName == "DisturbanceStatus"
                && matchingEnumerations.Skip(1).First().Name.RawName == "ReasonForRejection"
            ) {
                // Actually, they mean something entirely different.
                identifier = new Identifier("TechnicalFailure");
                matchingEnumerations = Enumerations.Values
                    .Where(x => x.Members.Any(x => x.RawName == identifier.RawName))
                    .ToList();
            }
            #endif

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
        throw new ModelException($"Could not resolve callable identifier {identifier.Name}");
    }

    public MessageSchema ResolveIncomingMessageSchema(TypeIdentifier signal)
    {
        throw new NotImplementedException();
    }

    public (TypeIdentifier, List<MessageMember>) ResolveOutgoingMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        throw new NotImplementedException();
    }

    public void EnsureReturnType(IAccessible value)
    {
        throw new InvalidOperationException("Can not ensure return type in global context");
    }
}
