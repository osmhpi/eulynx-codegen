using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationItem;

public class DataTypeHelper {

    public Dictionary<string, PropertyOrPort> Properties { get; private set; }
    public Dictionary<string, PropertyOrPort> Ports { get; }
    // public Dictionary<string, PropertyOrPort> SignalProperties { get; }
    public List<Operation> Operations { get; }
    public List<OwnedReception> Receptions { get; }
    public Dictionary<string, PackagedElement> ChangeEvents { get; }
    public Dictionary<string, PackagedElement> TimeEvents { get; }
    public Dictionary<string, PackagedElement> PackageEvents { get; }
    public Dictionary<string, PackagedElement> Signals { get; }
    public Dictionary<string, PackagedElement> DataTypes { get; }
    public HashSet<PackagedElement> UsedChangeEvents { get; }
    public Dictionary<PackagedElement, Dictionary<string, PropertyOrPort>> UsedSignals { get; }

    private readonly Dictionary<string, HashSet<string>> _allowedMessages;
    private readonly Dictionary<string, PropertyOrPort> _coalescedValues;
    private readonly Dictionary<string, HashSet<string>> _allowedMessageValues;
    private readonly Dictionary<string, string> _coalescedMessageValues;
    // Externally provided aliases for types
    private readonly Dictionary<string, string> _typeAliases;

    public DataTypeHelper(
        List<OwnedAttribute> properties,
        List<OwnedAttribute> ports,
        List<Operation> operations,
        List<OwnedReception> receptions,
        Dictionary<string, PackagedElement> changeEvents,
        Dictionary<string, PackagedElement> timeEvents,
        Dictionary<string, PackagedElement> packageEvents,
        Dictionary<string, PackagedElement> signals,
        Dictionary<string, PackagedElement> dataTypes,
        Dictionary<string, string> typeAliases)
    {
        Properties = properties.Select(x => PropertyOrPort.Create(x, dataTypes, false)).ToDictionary(x => x.Name);
        Ports = ports.Select(x => PropertyOrPort.Create(x, dataTypes, true)).ToDictionary(x => x.Name);
        // SignalProperties = receptions.SelectMany(x => signals[x.Signal].OwnedAttribute.Select(attribute => PropertyOrPort.Create(attribute, dataTypes))).ToDictionary(x => x.Name);

        Operations = operations;
        Receptions = receptions;
        ChangeEvents = changeEvents;
        TimeEvents = timeEvents;
        PackageEvents = packageEvents;
        Signals = signals;
        DataTypes = dataTypes;
        _typeAliases = typeAliases;

        _allowedMessages = new Dictionary<string, HashSet<string>>();
        _coalescedValues = new Dictionary<string, PropertyOrPort>();
        _allowedMessageValues = new Dictionary<string, HashSet<string>>();
        _coalescedMessageValues = new Dictionary<string, string>();
        UsedChangeEvents = new HashSet<PackagedElement>();
        UsedSignals = new Dictionary<PackagedElement, Dictionary<string, PropertyOrPort>>();
    }

    public bool IsPropertyOrPort(string identifier) {
        return Properties.ContainsKey(identifier) || Ports.ContainsKey(identifier);
    }

    public void RecordCoalesceValues(string lhs, string rhs, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal = null)
    {
        // Filter out symbols of the specification language
        if (rhs == "True" || rhs == "False") {
            return;
        }

        if (_coalescedValues.ContainsKey(lhs) == false) {
            _coalescedValues[lhs] = GetPropertyOrPort(lhs, attributesOfCurrentSignal);
        }

        if (_coalescedValues.ContainsKey(rhs) == false) {
            _coalescedValues[rhs] = GetPropertyOrPort(rhs, attributesOfCurrentSignal);
        }

        var lhsPointsTo = _coalescedValues[lhs];
        var rhsPointsTo = _coalescedValues[rhs];

        foreach (var keyValue in _coalescedValues) {
            if (keyValue.Value == lhsPointsTo) {
                _coalescedValues[keyValue.Key] = rhsPointsTo;
            }
        }
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

    public void RecordPossibleValueForProperty(string lhs, string rhs, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal = null)
    {
        var pp = LookupPropertyValueType(lhs, attributesOfCurrentSignal);
        pp.RecordPossibleValue(new LiteralIdentifier(rhs));
    }

    public static string GenerateEnumMemberName(string value) {
        var sanitizedValue = InPascalCase(value.Replace("-", " ").Replace(",", " And ").Replace("/", " Or "));

        if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
            sanitizedValue = "_" + sanitizedValue;
        }

        return sanitizedValue;
    }

    public string GeneratePropertyValueTypes()
    {
        return JoinLines(Properties
            .Concat(Ports)
            .Concat(UsedSignals.SelectMany(x => x.Value))
            .Select(x => GeneratePropertyValueType(x))
        );
    }

    private string GeneratePropertyValueType(KeyValuePair<string, PropertyOrPort> x)
    {
        if (_typeAliases.ContainsKey(x.Key)) {
            // An alias for this type was provided externally, don't generate anything
            return "";
        }

        // Collect all of the field values that point to the same alias
        if (x.Value is PropertyOrPort.StringPropertyOrPort stringPropertyOrPort) {
            if (_coalescedValues.ContainsKey(x.Key)) {
                foreach (var allowedValue in _coalescedValues.Keys.Where(key => _coalescedValues[key] == _coalescedValues[x.Key])
                    .Select(key => _coalescedValues[key])
                    .Cast<PropertyOrPort.StringPropertyOrPort>()
                    .SelectMany(pp => pp.AllowedValues).ToHashSet()) {
                        stringPropertyOrPort.RecordPossibleValue(allowedValue);
                }
            }
        }

        return x.Value.GeneratePropertyValueType();
    }

    public bool IsMessagePort(string v) {
        return _allowedMessages.ContainsKey(v);
    }

    public string GetFinalDataType(PropertyOrPort pp) {
        var dataType = pp.DataType;
        if (_typeAliases.ContainsKey(dataType)) {
            return _typeAliases[dataType];
        }
        return dataType;
    }

    public string GetFinalDataType(string v, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal = null) {
        return GetFinalDataType(LookupPropertyValueType(v, attributesOfCurrentSignal));
    }

    public PropertyOrPort LookupPropertyValueType(string v, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal = null, PackagedElement? enumeration = null)
    {
        var pp = GetPropertyOrPort(v, attributesOfCurrentSignal);

        if (_coalescedValues.ContainsKey(v) == false) {
            _coalescedValues[v] = pp;
        }

        return _coalescedValues[v];
    }

    public void RecordPossibleMessageForPort(string port, string value)
    {
        if (_allowedMessages.ContainsKey(port) == false) {
            _allowedMessages[port] = new HashSet<string>();
        }

        _allowedMessages[port].Add(value.Trim());
    }

    public string GenerateMessages()
    {
        var receptions = Ports.Select(x => DataTypes[x.Value.Property.Type])
            .SelectMany(x => x.OwnedReception)
            .Select(x => new MessageSchema(new TypeIdentifier(x.Name), Signals[x.Signal], this))
            .ToList();

        return JoinLines(receptions.Select(x => {
            var deconstruct = "";

            var attributes = x.Members;

            if (attributes.Count >= 2) {
                // C# only allows deconstruct syntax for two or more properties
                var propsOut = string.Join(", ", attributes.Select(x => $"out {x.TypeIdentifier.Name} {x.MemberName.Name}"));
                var propsOutAssignments = JoinLines(attributes.Select(x => $"{x.MemberName.Name} = this.{x.MemberName.Name};"));
                deconstruct = @$"public void Deconstruct({propsOut}) {{
                    {propsOutAssignments}
                }}";
            }

            var propsDecl = string.Join(", ", attributes.Select(x => $"{x.TypeIdentifier.Name} {x.MemberName.Name}"));
            return @$"public record {x.Identifier.Name}({propsDecl}) : Message {{
                {deconstruct}
            }}";
        }));

        // return JoinLines(UsedSignals.Select(x => {
        //     var deconstruct = "";

        //     if (x.Value.Count >= 2) {
        //         // C# only allows deconstruct syntax for two or more properties
        //         var propsOut = string.Join(", ", x.Value.Select(x => $"out {x.Value.DataType} {x.Value.Name}"));
        //         var propsOutAssignments = JoinLines(x.Value.Select(x => $"{x.Value.Name} = this.{x.Value.Name};"));
        //         deconstruct = @$"public void Deconstruct({propsOut}) {{
        //             {propsOutAssignments}
        //         }}";
        //     }

        //     var propsDecl = string.Join(", ", x.Value.Select(x => $"{x.Value.DataType} {x.Value.Name}"));
        //     return @$"public record {InPascalCase(x.Key.Name)}({propsDecl}) : Message {{
        //         {deconstruct}
        //     }}";
        // }));

        // return signals + JoinLines(_allowedMessages.SelectMany(x => {
        //     var (port, messages) = x;
        //     return messages.Select(message => {
        //         // Temporary workaround, need to unify the two types of message generators
        //         if (UsedSignals.Any(x => InPascalCase(x.Key.Name) == message))
        //             return "";

        //         var values = "";

        //         if (_allowedMessageValues.ContainsKey(message)) {
        //             values = @$"public enum Values {{
        //                 {string.Join(",\n", _allowedMessageValues[message])}
        //             }}";
        //         }

        //         var props = string.IsNullOrEmpty(values) ? "" : $"{message}.Values Value";
        //         if (_coalescedMessageValues.ContainsKey(message)) {
        //             var valueType = GetFinalDataType(_coalescedMessageValues[message]);
        //             props = $"{valueType} Value";
        //         }

        //         return @$"public record {message}({props}) : Message {{
        //             {values}
        //         }}";
        //     });
        // }));
    }

    public void RecordPossibleInitializerForMessage(string messageName, string messageInitializerValue)
    {
        if (_allowedMessageValues.ContainsKey(messageName) == false) {
            _allowedMessageValues[messageName] = new HashSet<string>();
        }

        _allowedMessageValues[messageName].Add(messageInitializerValue);
    }

    public void RecordCoalesceMessageValues(string parsedMessageName, string messageInitializerValue)
    {
        _coalescedMessageValues[parsedMessageName] = messageInitializerValue;
    }

    public void RecordChangeEventUsed(PackagedElement packagedElement)
    {
        UsedChangeEvents.Add(packagedElement);
    }

    public void RecordSignalUsed(PackagedElement packagedElement, Dictionary<string, PropertyOrPort> attributesOfCurrentSignal)
    {
        UsedSignals[packagedElement] = attributesOfCurrentSignal;
    }

    public string GenerateReceptions()
    {
        return JoinLines(Receptions.Select(x => {
            var signal = Signals[x.Signal];

            return @$"// {x.Name}
                // {string.Join(",\n", signal.OwnedAttribute.Select(a => a.Name))}";
        }));
    }

    public string GenerateAssignment(string propertyOrPort, string value)
    {
        return LookupPropertyValueType(propertyOrPort).GenerateAssignment(value);
    }

    public string GeneratePropertyDeclarations()
    {
        return JoinLines(Properties.Select(x => x.Value.GenerateDeclaration(GetFinalDataType(x.Key))));
    }

    public string GeneratePortDeclarations()
    {
        return JoinLines(Ports.Select(x => x.Value.GenerateDeclaration(GetFinalDataType(x.Key))));
    }

    public string GeneratePortInitializers()
    {
        return JoinLines(Ports.Select(x => x.Value.GenerateInitializer(GetFinalDataType(x.Key))));
    }

    public string GenerateSignals()
    {
        var m = $@"public bool ReceiveMessage(Message message) {{
            switch (message) {{
                {JoinLines(UsedSignals.Select(x => $@"case Message.{InPascalCase(x.Key.Name)} specific: {{
                    {InPascalCase(x.Key.Name)} = specific;
                    return true;
                }}"))}
                default: return false;
            }};
        }}";

        var m1 = $@"private bool IsMessageArrived(Message message) {{
            return message != null;
        }}";

        var m2 = $@"private bool ReceivedMessage<T>(T message, Func<T, bool> expr) {{
            return message != null && expr(message);
        }}";

        return JoinLines(UsedSignals.Select(x => $"public Message.{InPascalCase(x.Key.Name)} {InPascalCase(x.Key.Name)} {{ get; set; }}").Append(m).Append(m1).Append(m2));
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
