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

    public string GenerateDeclaration(string finalType) {
        if (IsPort) {
            return $"public Port<{finalType}> {Name} {{ get; set; }}";
        }
        return $"public {finalType} {Name} {{ get; set; }}";
    }

    public string GenerateInitializer(string finalType) {
        if (IsPort) {
            return $"{Name} = new Port<{finalType}>({GenerateInitialValue()});";
        }
        return $"{Name} = new {finalType}();";
    }

    protected virtual string GenerateInitialValue() {
        return "";
    }

    public abstract void RecordPossibleValue(string value);

    public virtual string GeneratePropertyValueType()
    {
         return "";
    }

    public abstract string GenerateAssignment(string value);

    public abstract string DataType { get; }

    public string Name => CodeGenerationItem.InPascalCase(Property.Name);
    public string Accessor => IsPort ? $"{Name}.Value" : Name;

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
        // public ComplexPropertyOrPort(OwnedAttribute Property, bool IsPort, PackagedElement UmlType) : base(Property, IsPort)
        // {
            // Console.WriteLine(InPascalCase(UmlType.Name));
            // if (UmlType.Type == "uml:Class") {
            //     foreach (var reception in UmlType.OwnedReception) {
            //         Console.WriteLine("  ->" + reception.Name);
            //     }
            // } else if (UmlType.Type == "uml:Enumeration") {
            //     foreach (var literal in UmlType.OwnedLiteral) {
            //         Console.WriteLine("  --" + literal.Name);
            //     }
            // }
        // }

        public override string DataType => UmlType.Type switch {
            "uml:Class" => "Channel<EulynxMessages.Message>",
            "uml:Enumeration" => InPascalCase(UmlType.Name),
            _ => "object"
        };

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

        protected override string GenerateInitialValue()
        {
            return "new PulsedIn(false)";
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

        protected override string GenerateInitialValue()
        {
            return "new PulsedOut(false)";
        }

        public override void RecordPossibleValue(string value)
        {
            if (value != "TRUE" && value != "FALSE")
                throw new ArgumentException($"Invalid pulsed out value: {value}");
        }
    }
}
