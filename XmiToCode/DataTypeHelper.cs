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

        // foreach (var reception in Receptions) {
        //     var signal = Signals[reception.Signal];
        //     foreach (var signalAttribute in signal.OwnedAttribute) {
        //         Console.WriteLine(InPascalCase(signalAttribute.Name));
        //         _allowedPropertyValues.Add(InPascalCase(signalAttribute.Name), new HashSet<string>());
        //     }
        // }
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
        pp.RecordPossibleValue(rhs);
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
        return string.Join("\n", Properties.Concat(Ports).Select(x => GeneratePropertyValueType(x)));
    }

    private string GeneratePropertyValueType(KeyValuePair<string, PropertyOrPort> x)
    {
        if (_typeAliases.ContainsKey(x.Key)) {
            // An alias for this type was provided externally, don't generate anything
            return "";
        }

        // Collect all of the field values that point to the same alias
        // var aliases = _coalescedValues.ContainsKey(x.Key)
        //     ? _coalescedValues.Keys.Where(key => _coalescedValues[key] == _coalescedValues[x.Key])
        //         .SelectMany(key => _allowedPropertyValues[key]).ToHashSet() : _allowedPropertyValues[x.Key];

        // if (aliases.Count == 0) {
        //     // TODO: Why does this happen?
        //     return "";
        // }

        return x.Value.GeneratePropertyValueType();
    }

    public bool IsMessagePort(string v) {
        return _allowedMessages.ContainsKey(v);
    }

    // TODO: Remove
    public PropertyOrPort LookupPropertyValueType(string v, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal = null)
    {
        var pp = GetPropertyOrPort(v, attributesOfCurrentSignal);
        // if (_typeAliases.ContainsKey(v)) {
        //     return _typeAliases[v];
        // }

        // if (_allowedMessages.ContainsKey(v)) {
        //     return "Channel<EulynxMessages.Message>";
        // }

        if (_coalescedValues.ContainsKey(v) == false) {
            _coalescedValues[v] = pp;
        }
        var result = _coalescedValues[v];

        // if (_allowedPropertyValues[result].Count == 0) {
        //     return "bool";
        // }

        // return $"{result}Value";
        return result;
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
                    var valueType = LookupPropertyValueType(_coalescedMessageValues[message]).DataType;
                    props = $"{valueType} Value";
                }

                return @$"public record {message}({props}) : Message {{
                    {values}
                }}";
            });
        }));
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

    public string GenerateReceptions()
    {
        return string.Join("\n", Receptions.Select(x => {
            var signal = Signals[x.Signal];

            return @$"// {x.Name}
                // {string.Join(",\n", signal.OwnedAttribute.Select(a => a.Name))}";
        }
        ));
    }

    public string GenerateAssignment(string propertyOrPort, string value)
    {
        return LookupPropertyValueType(propertyOrPort).GenerateAssignment(value);
    }

    public string GeneratePropertyDeclarations()
    {
        return string.Join("\n", Properties.Select(x => x.Value.GenerateDeclaration(LookupPropertyValueType(x.Key))));
    }

    public string GeneratePortDeclarations()
    {
        return string.Join("\n", Ports.Select(x => x.Value.GenerateDeclaration(LookupPropertyValueType(x.Key))));
    }

    public string GeneratePortInitializers()
    {
        return string.Join("\n", Ports.Select(x => x.Value.GenerateInitializer(LookupPropertyValueType(x.Key))));
    }
}

public abstract record PropertyOrPort(OwnedAttribute Property, bool IsPort) {
    public static PropertyOrPort Create(OwnedAttribute property, Dictionary<string, PackagedElement> types, bool IsPort)
    {
        var umlType = types[property.Type];
        return umlType.Name switch {
            "Boolean" => new BoolPropertyOrPort(property, IsPort),
            // "DateTime",
            // "Decimal",
            // "Double",
            // "Integer",
            // "Long",
            // "Single",
            "String" => new StringPropertyOrPort(property, IsPort),
            "PulsedIn" => new PulsedInPropertyOrPort(property, IsPort),
            "PulsedOut" => new PulsedOutPropertyOrPort(property, IsPort),
            // "Timespan",
            _ => new ComplexPropertyOrPort(property, IsPort, umlType)
        };
    }

    public string GenerateDeclaration(PropertyOrPort coalescedProperty) {
        if (IsPort) {
            return $"public Port<{coalescedProperty.DataType}> {Name} {{ get; set; }}";
        }
        return $"public {coalescedProperty.DataType} {Name} {{ get; set; }}";
    }

    public string GenerateInitializer(PropertyOrPort coalescedProperty) {
        if (IsPort) {
            return $"{Name} = new Port<{coalescedProperty.DataType}>();";
        }
        return $"{Name} = new {coalescedProperty.DataType}();";
    }

    public abstract void RecordPossibleValue(string value);

    public virtual string GeneratePropertyValueType()
    {
         return "";
    }

    public abstract string GenerateAssignment(string value);

    public abstract string DataType { get; }

    public string Name => CodeGenerationItem.InPascalCase(Property.Name);

    record StringPropertyOrPort(OwnedAttribute Property, bool IsPort) : PropertyOrPort(Property, IsPort)
    {
        private HashSet<string> AllowedValues = new HashSet<string>();
        public override string DataType => AllowedValues.Count > 0 ? $"{Name}Value" : "byte[]";

        public override void RecordPossibleValue(string value)
        {
            AllowedValues.Add(value);
        }

        public override string GeneratePropertyValueType()
        {
            if (AllowedValues.Count == 0) {
                return "";
            }

            return $@"
            public enum {Name}Value {{
                {string.Join(",\n", AllowedValues.Select(GenerateEnumMemberName))}
            }}";
        }

        public static string GenerateEnumMemberName(string value) {
            var sanitizedValue = InPascalCase(value.Replace(",", " And "));

            if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
                sanitizedValue = "_" + sanitizedValue;
            }

            return sanitizedValue;
        }

        public override string GenerateAssignment(string value)
        {
            return $"{DataType}.{DataTypeHelper.GenerateEnumMemberName(value)}";
        }
    }

    record ComplexPropertyOrPort(OwnedAttribute Property, bool IsPort, PackagedElement UmlType) : PropertyOrPort(Property, IsPort)
    {
        public override string DataType => $"object";

        public override string GenerateAssignment(string value)
        {
            throw new NotImplementedException();
        }

        public override void RecordPossibleValue(string value)
        {
            throw new NotImplementedException();
        }
    }

    record BoolPropertyOrPort(OwnedAttribute Property, bool IsPort) : PropertyOrPort(Property, IsPort)
    {
        public override string DataType => "bool";

        public override string GenerateAssignment(string value)
        {
            if (value == "TRUE")
                return "true";
            if (value == "FALSE")
                return "false";
            throw new ArgumentException(value);
        }

        public override void RecordPossibleValue(string value)
        {
            if (value != "TRUE" && value != "FALSE")
                throw new ArgumentException($"Invalid bool value: {value}");
        }
    }

    record PulsedInPropertyOrPort(OwnedAttribute Property, bool IsPort) : PropertyOrPort(Property, IsPort)
    {
        public override string DataType => "PulsedIn";

        public override string GenerateAssignment(string value)
        {
            if (value == "TRUE")
                return "new PulsedIn(true)";
            if (value == "FALSE")
                return "new PulsedIn(false)";
            throw new ArgumentException(value);
        }

        public override void RecordPossibleValue(string value)
        {
            if (value != "TRUE" && value != "FALSE")
                throw new ArgumentException($"Invalid pulsed in value: {value}");
        }
    }

    record PulsedOutPropertyOrPort(OwnedAttribute Property, bool IsPort) : PropertyOrPort(Property, IsPort)
    {
        public override string DataType => "PulsedOut";

        public override string GenerateAssignment(string value)
        {
            if (value == "TRUE")
                return "new PulsedOut(true)";
            if (value == "FALSE")
                return "new PulsedOut(false)";
            throw new ArgumentException(value);
        }

        public override void RecordPossibleValue(string value)
        {
            if (value != "TRUE" && value != "FALSE")
                throw new ArgumentException($"Invalid pulsed out value: {value}");
        }
    }
}
