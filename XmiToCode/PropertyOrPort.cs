using XmiToCode;
using static CodeGenerationItem;

public interface IAccessible {
    public string Accessor(ProgramContext context);
}

public record ClassMember(Identifier Identifier) : IAccessible {
    public string Accessor(ProgramContext context) => context.IsLocalVariable(this)
        ? Identifier.Name
        : $"{context.InstanceReference}.{Identifier.Name}";
}

public record EnumerationMember(PackagedElement UmlEnumeration, OwnedLiteral Member) : IAccessible {
    public string Accessor(ProgramContext context) => $"{UmlEnumeration.Name}.{Member.Name}";
}

public record ImplicitEnumMember(string EnumType, LiteralIdentifier Literal) : IAccessible {
    public string Accessor(ProgramContext context) => $"{EnumType}.{Literal.Name}";
}

public record BoolLiteral(bool Value) : IAccessible
{
    public string Accessor(ProgramContext context) => Value ? "true" : "false";
}

public record PulsedInLiteral(bool Value) : IAccessible
{
    public string Accessor(ProgramContext context) => Value ? "new PulsedIn(true)" : "new PulsedIn(false)";
}

public record PulsedOutLiteral(bool Value) : IAccessible
{
    public string Accessor(ProgramContext context) => Value ? "new PulsedOut(true)" : "new PulsedOut(false)";
}

public record Method(Identifier Identifier, Operation Operation) : ICallable
{
    public string Call(ProgramContext context) => $"{context.InstanceReference}.{Identifier.Name}()";
}

public abstract record PropertyOrPort(OwnedAttribute Property, bool IsPort) : IAccessible, IAssignable {
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

    public string GenerateCondition(ProgramContext context, string otherInstance, IAccessible other, bool negate) {
        var negateOrNot = negate ? "" : "!";
        return $"{negateOrNot}{context.InstanceReference}.{Accessor(context)}.{EqualityComparer}({otherInstance}.{other.Accessor(context)})";
    }

    protected virtual string GenerateInitialValue() {
        return "";
    }

    public abstract IAccessible RecordPossibleValue(LiteralIdentifier value);

    public virtual string GeneratePropertyValueType()
    {
         return "";
    }

    public abstract string GenerateAssignment(string value);

    public abstract string DataType { get; }

    public string Name => CodeGenerationItem.InPascalCase(Property.Name);
    public string Accessor(ProgramContext context) =>
        context.IsLocalVariable(this)
            ? IsPort
                ? $"{Name}.Value"
                : $"{Name}"
            : IsPort
                ? $"{context.InstanceReference}.{Name}.Value"
                : $"{context.InstanceReference}.{Name}";

    public IAccessible LookupValidLiteral(LiteralIdentifier literal)
    {
        return RecordPossibleValue(literal);
    }

    public virtual string EqualityComparer => "Equals";

    public record StringPropertyOrPort(OwnedAttribute Property, bool IsPort) : PropertyOrPort(Property, IsPort)
    {
        public HashSet<LiteralIdentifier> AllowedValues = new HashSet<LiteralIdentifier>();
        public override string DataType => AllowedValues.Count > 0 ? $"{Name}Value" : "byte[]";
        public override string EqualityComparer => AllowedValues.Count > 0 ? "Equals" : "SequenceEqual";

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            AllowedValues.Add(literal);
            return new ImplicitEnumMember(DataType, literal);
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

        public static string GenerateEnumMemberName(LiteralIdentifier literal) {
            // var sanitizedValue = InPascalCase(value.Replace(",", " And "));

            // if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
            //     sanitizedValue = "_" + sanitizedValue;
            // }

            return literal.Name;
        }

        public override string GenerateAssignment(string value)
        {
            return $"{DataType}.{DataTypeHelper.GenerateEnumMemberName(value)}";
        }
    }

    public record ComplexPropertyOrPort(OwnedAttribute Property, bool IsPort, PackagedElement UmlType) : PropertyOrPort(Property, IsPort)
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

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            if (UmlType.Type != "uml:Enumeration") {
                throw new NotImplementedException();
            }

            var literals = UmlType.OwnedLiteral
                .Select(x => (Key: new LiteralIdentifier(x.Name), Value: x))
                .ToDictionary(x => x.Key, x => x.Value);
            var theIdentifier = literals[literal];
            return new EnumerationMember(UmlType, theIdentifier);
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

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            // if (value != "TRUE" && value != "FALSE")
            //     throw new ArgumentException($"Invalid bool value: {value}");
            if (literal.Name == "True")
                return new BoolLiteral(true);

            if (literal.Name == "False")
                return new BoolLiteral(false);

            throw new ArgumentException($"Invalid bool value: {literal}");
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

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            if (literal.Name == "True")
                return new PulsedInLiteral(true);

            if (literal.Name == "False")
                return new PulsedInLiteral(false);

            throw new ArgumentException($"Invalid pulsed in value: {literal}");
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

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            if (literal.Name == "True")
                return new PulsedOutLiteral(true);

            if (literal.Name == "False")
                return new PulsedOutLiteral(false);

            throw new ArgumentException($"Invalid pulsed out value: {literal}");
        }
    }
}
