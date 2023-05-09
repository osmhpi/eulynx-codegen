using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationItem;

public class DataTypeHelper {

    public List<XmiToCode.OwnedAttribute> Properties { get; private set; }
    public List<OwnedAttribute> Ports { get; }
    public List<Operation> Operations { get; }
    public Dictionary<string, PackagedElement> ChangeEvents { get; }
    public Dictionary<string, PackagedElement> TimeEvents { get; }
    public Dictionary<string, PackagedElement> PackageEvents { get; }
    public HashSet<PackagedElement> UsedChangeEvents { get; }

    private readonly Dictionary<string, HashSet<string>> _allowedPropertyValues;
    private readonly Dictionary<string, HashSet<string>> _allowedMessages;
    private readonly Dictionary<string, string> _coalescedValues;
    private readonly Dictionary<string, HashSet<string>> _allowedMessageValues;
    private readonly Dictionary<string, string> _coalescedMessageValues;
    private readonly Dictionary<string, string> _typeAliases;

    public DataTypeHelper(
        List<OwnedAttribute> properties,
        List<OwnedAttribute> ports,
        List<Operation> operations,
        Dictionary<string, PackagedElement> changeEvents,
        Dictionary<string, PackagedElement> timeEvents,
        Dictionary<string, PackagedElement> packageEvents,
        Dictionary<string, string> typeAliases)
    {
        Properties = properties;
        Ports = ports;
        Operations = operations;
        ChangeEvents = changeEvents;
        TimeEvents = timeEvents;
        PackageEvents = packageEvents;
        _typeAliases = typeAliases;

        _allowedPropertyValues = new Dictionary<string, HashSet<string>>();
        _allowedMessages = new Dictionary<string, HashSet<string>>();
        _coalescedValues = new Dictionary<string, string>();
        _allowedMessageValues = new Dictionary<string, HashSet<string>>();
        _coalescedMessageValues = new Dictionary<string, string>();
        UsedChangeEvents = new HashSet<PackagedElement>();

        foreach (var property in Properties) {
            _allowedPropertyValues.Add(InPascalCase(property.Name), new HashSet<string>());
        }

        foreach (var port in Ports) {
            _allowedPropertyValues.Add(InPascalCase(port.Name), new HashSet<string>());
        }
    }

    public bool IsPropertyOrPort(string identifier) {
        return _allowedPropertyValues.ContainsKey(identifier);
    }

    public void RecordCoalesceValues(string lhs, string rhs)
    {
        if (_coalescedValues.ContainsKey(lhs) == false) {
            _coalescedValues[lhs] = lhs;
        }

        if (_coalescedValues.ContainsKey(rhs) == false) {
            _coalescedValues[rhs] = rhs;
        }

        var lhsPointsTo = _coalescedValues[lhs];
        var rhsPointsTo = _coalescedValues[rhs];

        foreach (var keyValue in _coalescedValues) {
            if (keyValue.Value == lhsPointsTo) {
                _coalescedValues[keyValue.Key] = rhsPointsTo;
            }
        }
    }

    public void RecordPossibleValueForProperty(string lhs, string rhs)
    {
        if (_allowedPropertyValues.ContainsKey(lhs) == false) {
            _allowedPropertyValues[lhs] = new HashSet<string>();
        }

        _allowedPropertyValues[lhs].Add(rhs);
    }

    public static string GenerateEnumMemberName(string value) {
        var sanitizedValue = InPascalCase(value.Replace(",", " And "));

        if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
            sanitizedValue = "_" + sanitizedValue;
        }

        return sanitizedValue;
    }

    public string GeneratePropertyValueTypes()
    {
        return string.Join("\n", _allowedPropertyValues.Select(x => {
            if (_typeAliases.ContainsKey(x.Key)) {
                return "";
            }

            // Collect all of the field values that point to the same alias
            var aliases = _coalescedValues.ContainsKey(x.Key)
                ? _coalescedValues.Keys.Where(key => _coalescedValues[key] == _coalescedValues[x.Key])
                    .SelectMany(key => _allowedPropertyValues[key]).ToHashSet() : _allowedPropertyValues[x.Key];

            if (aliases.Count == 0) {
                return "";
            }

            return $@"
                public enum {x.Key}Value {{
                    {string.Join(",\n", aliases.Select(GenerateEnumMemberName))}
                }}";
            })
        );
    }

    public bool IsMessagePort(string v) {
        return _allowedMessages.ContainsKey(v);
    }

    public string LookupPropertyValueType(string v)
    {
        if (_typeAliases.ContainsKey(v)) {
            return _typeAliases[v];
        }

        if (_allowedMessages.ContainsKey(v)) {
            return "Channel<EulynxMessages.Message>";
        }

        if (_coalescedValues.ContainsKey(v) == false) {
            _coalescedValues[v] = v;
        }
        var result = _coalescedValues[v];

        if (_allowedPropertyValues[result].Count == 0) {
            return "bool";
        }

        return $"{result}Value";
    }

    internal void RecordPossibleMessageForPort(string port, string value)
    {
        if (_allowedMessages.ContainsKey(port) == false) {
            _allowedMessages[port] = new HashSet<string>();
        }

        _allowedMessages[port].Add(value.Trim());
    }

    internal string GenerateMessages()
    {
        return string.Join("\n", _allowedMessages.SelectMany(x => {
            var (port, messages) = x;
            return messages.Select(message => {
                var values = "";

                if (_allowedMessageValues.ContainsKey(message)) {
                    values = @$"public enum Values {{
                        {string.Join(",\n", _allowedMessageValues[message])}
                    }}";
                }

                var props = string.IsNullOrEmpty(values) ? "" : $"{message}.Values Value";
                if (_coalescedMessageValues.ContainsKey(message)) {
                    var valueType = LookupPropertyValueType(_coalescedMessageValues[message]);
                    props = $"{valueType} Value";
                }

                return @$"public record {message}({props}) : Message {{
                    {values}
                }}";
            });
        }));
    }

    internal void RecordPossibleInitializerForMessage(string messageName, string messageInitializerValue)
    {
        if (_allowedMessageValues.ContainsKey(messageName) == false) {
            _allowedMessageValues[messageName] = new HashSet<string>();
        }

        _allowedMessageValues[messageName].Add(messageInitializerValue);
    }

    internal void RecordCoalesceMessageValues(string parsedMessageName, string messageInitializerValue)
    {
        _coalescedMessageValues[parsedMessageName] = messageInitializerValue;
    }

    internal void RecordChangeEventUsed(PackagedElement packagedElement)
    {
        UsedChangeEvents.Add(packagedElement);
    }
}
