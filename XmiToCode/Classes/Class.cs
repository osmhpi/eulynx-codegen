using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationHelper;

public record Class(
    ClassInfo Info,
    ClassContext ClassContext,
    BehaviorRecord Behavior,
    List<TransitionFunction> TransitionFunctions,
    List<StateName> States,
    List<Operation> Operations,
    List<GlobalEnumeration> GlobalEnumerations)
{
    public IEnumerable<ValueType> GetValueTypes() {
        return ClassContext.Ports
            .Concat(ClassContext.Properties)
            .Where(x => x.Value is PropertyOrPort.StringPropertyOrPort)
            .Select(x => new ValueType(
                Info,
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
        return ClassContext.UsedOutgoingMessageTypes.Values;
    }

    internal IEnumerable<MessageSchema> GetIncomingMessageTypes()
    {
        return TransitionFunctions
            .SelectMany(x => x.Transitions)
            .Select(x => x.Transition)
            .OfType<MessageEventTransition>()
            .Select(x => x.MessageSchema)
            .Distinct()
            // .GroupBy(x => x.Identifier)
            // .Select(x => x.First())
            .Select(x => ClassContext.MessageSchema[x])
            .ToList();
    }

    internal IEnumerable<(PackagedElement Event, BooleanExpression Condition)> GetChangeEvents() {
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
