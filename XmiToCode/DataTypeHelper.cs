using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationItem;

public class DataTypeHelper {

    public Dictionary<string, PropertyOrPort> Properties { get; private set; }
    public Dictionary<string, PropertyOrPort> Ports { get; }
    // public Dictionary<string, PropertyOrPort> SignalProperties { get; }
    public List<Operation> Operations { get; }
    public Dictionary<string, PackagedElement> ChangeEvents { get; }
    public Dictionary<string, PackagedElement> TimeEvents { get; }
    public Dictionary<string, PackagedElement> PackageEvents { get; }
    public Dictionary<string, PackagedElement> Signals { get; }
    public Dictionary<string, PackagedElement> DataTypes { get; }
    public HashSet<PackagedElement> UsedChangeEvents { get; }

    private readonly Dictionary<string, PropertyOrPort> _coalescedValues;
    // Externally provided aliases for types
    private readonly Dictionary<(string, string), (string, string)> _typeAliases;

    public DataTypeHelper(
        List<OwnedAttribute> properties,
        List<OwnedAttribute> ports,
        List<Operation> operations,
        Dictionary<string, PackagedElement> changeEvents,
        Dictionary<string, PackagedElement> timeEvents,
        Dictionary<string, PackagedElement> packageEvents,
        Dictionary<string, PackagedElement> signals,
        Dictionary<string, PackagedElement> dataTypes,
        Dictionary<(string, string), (string, string)> typeAliases,
        ClassInfo classInfo)
    {
        Properties = properties.Select(x => PropertyOrPort.Create(x, dataTypes, false, classInfo, new ClassAccessor())).ToDictionary(x => x.Name);
        Ports = ports.Select(x => PropertyOrPort.Create(x, dataTypes, true, classInfo, new ClassAccessor())).ToDictionary(x => x.Name);
        // SignalProperties = receptions.SelectMany(x => signals[x.Signal].OwnedAttribute.Select(attribute => PropertyOrPort.Create(attribute, dataTypes))).ToDictionary(x => x.Name);

        Operations = operations;
        ChangeEvents = changeEvents;
        TimeEvents = timeEvents;
        PackageEvents = packageEvents;
        Signals = signals;
        DataTypes = dataTypes;
        _typeAliases = typeAliases;

        _coalescedValues = new Dictionary<string, PropertyOrPort>();
        UsedChangeEvents = new HashSet<PackagedElement>();
    }

    private PropertyOrPort GetPropertyOrPort(string identifier, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal = null) {
        if (attributesOfCurrentSignal != null && attributesOfCurrentSignal.ContainsKey(identifier)) {
            return attributesOfCurrentSignal[identifier];
        }
        // if (SignalProperties.ContainsKey(identifier)) {
        //     return SignalProperties[identifier];
        // }
        if (Properties.ContainsKey(identifier)) {
            return Properties[identifier];
        }
        if (Ports.ContainsKey(identifier)) {
            return Ports[identifier];
        }


        throw new KeyNotFoundException(identifier);
    }

    public static string GenerateEnumMemberName(string value) {
        var sanitizedValue = InPascalCase(value.Replace("-", " ").Replace(",", " And ").Replace("/", " Or "));

        if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
            sanitizedValue = "_" + sanitizedValue;
        }

        return sanitizedValue;
    }

    public PropertyOrPort LookupPropertyValueType(string v, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal = null, PackagedElement? enumeration = null)
    {
        var pp = GetPropertyOrPort(v, attributesOfCurrentSignal);

        if (_coalescedValues.ContainsKey(v) == false) {
            _coalescedValues[v] = pp;
        }

        return _coalescedValues[v];
    }

    public static async Task GenerateDataTypes(Dictionary<string, PackagedElement> dataTypes) {
        var whitelist = new [] {"ResetReason", "CloseReason", "AbilityToMoveState", "PointPositionState", "PointPositionDegradedState"};
        var enumerations = dataTypes.Where(x => x.Value.Type == "uml:Enumeration")
            // There are two enumerations which map to the same name (but are not used currently)
            // - Line Direction Control Information
            // - Line_Direction_Control_Information
            // This behavior is possibly dangerous...
            // Temporary workaround:
            .Where(x => whitelist.Contains(x.Value.Name));

        var result = $@"namespace Eulynx;

        {JoinLines(enumerations.Select(x => $@"
            public enum {InPascalCase(x.Value.Name)} {{
                {string.Join(",\n", x.Value.OwnedLiteral.Select(lit => GenerateEnumMemberName(lit.Name)))}
            }}"))}
        ";

        using var file = File.Create($"../Eulynx/DataTypes.cs");
        using var writer = new StreamWriter(file);
        await writer.WriteAsync(result);
    }
}
