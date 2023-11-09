using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Messages;
using XmiToCode.Parsing.XmiModel;
using XmiToCode.Transformation.Model;
using XmiToCode.Parsing.Model;

namespace XmiToCode.Codegen.Model;

public record ClassFile(
    TypeIdentifier ClassName,
    TypeIdentifier BehaviorName,
    ClassContext ClassContext,
    CompoundRegion FlatRegion,
    BehaviorRecord Behavior,
    List<TransitionFunction> TransitionFunctions,
    List<TypeIdentifier> States,
    List<Operation> Operations,
    List<PackagedElement> PackageHierarchy)
{
    public IEnumerable<ValueType> GetValueTypes() {
        return ClassContext.Ports
            .Concat(ClassContext.Properties)
            .Where(x => x.Value is PropertyOrPort.StringPropertyOrPort)
            .Select(x => new ValueType(
                ClassName,
                x.Key,
                ((PropertyOrPort.StringPropertyOrPort)x.Value).GetAllowedValues()))
            .Where(x => x.AllowedValues.Count > 0);
    }

    public Dictionary<Identifier, PropertyOrPort> GetPropertiesAndPorts() {
        return ClassContext.Ports
            .Concat(ClassContext.Properties)
            .ToDictionary(x => x.Key, x => x.Value);
    }

    internal IEnumerable<MessageSchema> GetOutgoingMessageTypes()
    {
        return ClassContext.OutgoingMessages.Values;
    }

    internal IEnumerable<MessageSchema> GetIncomingMessageTypes()
    {
        return TransitionFunctions
            .SelectMany(x => x.Transitions)
            .Select(x => x.Transition)
            .OfType<MessageEventTransition>()
            .Select(x => x.MessageType)
            .Distinct()
            .Select(x => ClassContext.IncomingMessages[x])
            .ToList();
    }

    internal IEnumerable<(PackagedElement Event, IAccessible Condition)> GetChangeEvents() {
        return TransitionFunctions
            .SelectMany(x => x.Transitions)
            .Select(x => x.Transition)
            .OfType<ChangeEventTransition>()
            .Select(x => (x.theEvent, x.Condition))
            .Distinct()
            .ToList();
    }

    internal IEnumerable<string> GetTimeoutEvents() {
        return TransitionFunctions
            .SelectMany(x => x.Transitions)
            .Select(x => x.Transition)
            .OfType<TimeEventTransition>()
            .Select(x => x.theEvent.Name)
            .Distinct()
            .ToList();
    }
}

public record ValueType(TypeIdentifier ClassName, Identifier Identifier, HashSet<LiteralIdentifier> AllowedValues);
