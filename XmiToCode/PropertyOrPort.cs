using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationItem;

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

    public record StringPropertyOrPort(OwnedAttribute Property, bool IsPort) : PropertyOrPort(Property, IsPort)
    {
        public HashSet<string> AllowedValues = new HashSet<string>();
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
