using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationItem;

record Class(
    string ClassName,
    string BehaviorName,
    ClassContext ClassContext,
    IBehaviorRecord Behavior,
    IEnumerable<TransitionFunction> TransitionFunctions,
    IEnumerable<StateName> States,
    List<GlobalEnumeration> GlobalEnumerations)
{
    public IEnumerable<ValueType> GetValueTypes() {
        return ClassContext.Ports
            .Concat(ClassContext.Properties)
            .Where(x => x.Value is PropertyOrPort.StringPropertyOrPort)
            .Select(x => new ValueType(
                ClassName,
                x.Key,
                ((PropertyOrPort.StringPropertyOrPort)x.Value).AllowedValues))
            .Where(x => x.AllowedValues.Count > 0);
    }

    public Dictionary<Identifier, PropertyOrPort> GetPropertiesAndPorts() {
        return ClassContext.Ports
            .Concat(ClassContext.Properties)
            .ToDictionary(x => x.Key, x => x.Value);
    }

    internal IEnumerable<MessageSchema> GetMessageTypes()
    {
        return ClassContext.UsedMessageTypes.Values;
    }
}

record ValueType(string ClassName, Identifier Identifier, HashSet<LiteralIdentifier> AllowedValues);

record GlobalEnumeration(PackagedElement Enumeration) {

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

interface IBehaviorRecord
{
    string Name { get; }
    List<IBehaviorRecord> subrecords { get; }
}

record SimpleBehaviorRecord(string Name, string recordName, string className) : IBehaviorRecord
{
    public List<IBehaviorRecord> subrecords { get; } = new();
}


record BehaviorRecord(StateMachine StateMachine, string Name, string parentBehaviorName, string className, ICodeTransition initializer, List<IBehaviorRecord> subrecords) : IBehaviorRecord;
