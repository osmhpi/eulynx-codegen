using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationItem;

public record ClassInfo(string ClassName, string BehaviorName);

public record Class(
    ClassInfo Info,
    ClassContext ClassContext,
    IBehaviorRecord Behavior,
    List<TransitionFunction> TransitionFunctions,
    List<StateName> States,
    List<GlobalEnumeration> GlobalEnumerations)
{
    public IEnumerable<ValueType> GetValueTypes() {
        return ClassContext.Ports
            .Concat(ClassContext.Properties)
            .Where(x => x.Value is PropertyOrPort.StringPropertyOrPort)
            .Select(x => new ValueType(
                Info,
                x.Key,
                ((PropertyOrPort.StringPropertyOrPort)x.Value).AllowedValues))
            .Where(x => x.AllowedValues.Count > 0);
    }

    public Dictionary<Identifier, PropertyOrPort> GetPropertiesAndPorts() {
        return ClassContext.Ports
            .Concat(ClassContext.Properties)
            .ToDictionary(x => x.Key, x => x.Value);
    }

    internal IEnumerable<MessageSchema> GetOutgoingMessageTypes()
    {
        return ClassContext.UsedOutgoingMessageTypes.Values;
    }

    internal IEnumerable<MessageSchema> GetIncomingMessageTypes()
    {
        return TransitionFunctions
            .SelectMany(x => x.Transitions)
            .Select(x => x.Transition)
            .OfType<MessageEventTransition>()
            .Select(x => x.MessageSchema)
            .GroupBy(x => x.Identifier)
            .Select(x => x.First())
            .ToList();
    }

    internal IEnumerable<PackagedElement> GetChangeEvents() {
        return TransitionFunctions
            .SelectMany(x => x.Transitions)
            .Select(x => x.Transition)
            .OfType<ChangeEventTransition>()
            .Select(x => x.theEvent)
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

    internal List<Operation> GetOperations()
    {
        return ClassContext.DataTypes.Operations;
    }
}

public record ValueType(ClassInfo Class, Identifier Identifier, HashSet<LiteralIdentifier> AllowedValues);

public record GlobalEnumeration(PackagedElement Enumeration) {

    public string Name => InPascalCase(Enumeration.Name);
    public IEnumerable<string> Members => Enumeration.OwnedLiteral.Select(lit => GenerateEnumMemberName(lit.Name));

    private static string GenerateEnumMemberName(string value) {
        var sanitizedValue = InPascalCase(value.Replace("-", " ").Replace(",", " And ").Replace("/", " Or "));

        if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
            sanitizedValue = "_" + sanitizedValue;
        }

        return sanitizedValue;
    }
}

public interface IBehaviorRecord
{
    string Name { get; }
    List<IBehaviorRecord> subrecords { get; }
    ClassInfo className { get; }
}

public record SimpleBehaviorRecord(string Name, string recordName, ClassInfo className) : IBehaviorRecord
{
    public List<IBehaviorRecord> subrecords { get; } = new();
}


public record BehaviorRecord(StateMachine StateMachine, string Name, string parentBehaviorName, ClassInfo className, ICodeTransition initializer, List<IBehaviorRecord> subrecords) : IBehaviorRecord;
