using XmiToCode.Identifiers;
using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Model;

public record Class(
    PackagedElement UmlClass,
    ClassContext ClassContext,
    List<Operation> Operations,
    Region Region,
    List<PackagedElement> Hierarchy) {
    public TypeIdentifier ClassName { get; } = new TypeIdentifier(UmlClass.Name);


    public Dictionary<Identifier, PropertyOrPort> GetPropertiesAndPorts() {
        return ClassContext.Ports
            .Concat(ClassContext.Properties)
            .ToDictionary(x => x.Key, x => x.Value);
    }

    // internal IEnumerable<MessageSchema> GetOutgoingMessageTypes()
    // {
    //     return ClassContext.OutgoingMessages.Values;
    // }

    // internal IEnumerable<MessageSchema> GetIncomingMessageTypes()
    // {
    //     return TransitionFunctions
    //         .SelectMany(x => x.Transitions)
    //         .Select(x => x.Transition)
    //         .OfType<MessageEventTransition>()
    //         .Select(x => x.MessageType)
    //         .Distinct()
    //         .Select(x => ClassContext.IncomingMessages[x])
    //         .ToList();
    // }

    // internal IEnumerable<(PackagedElement Event, IAccessible Condition)> GetChangeEvents() {
    //     return TransitionFunctions
    //         .SelectMany(x => x.Transitions)
    //         .Select(x => x.Transition)
    //         .OfType<ChangeEventTransition>()
    //         .Select(x => (x.theEvent, x.Condition))
    //         .Distinct()
    //         .ToList();
    // }

    // internal IEnumerable<string> GetTimeoutEvents() {
    //     return TransitionFunctions
    //         .SelectMany(x => x.Transitions)
    //         .Select(x => x.Transition)
    //         .OfType<TimeEventTransition>()
    //         .Select(x => x.theEvent.Name)
    //         .Distinct()
    //         .ToList();
    // }
}
