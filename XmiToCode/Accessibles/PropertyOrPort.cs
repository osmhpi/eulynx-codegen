using XmiToCode;
using static CodeGenerationHelper;

/***
Eu.ModSt.7510
    In ports and out ports are described according to the port definition schema below:
        <Port information type><PNo><Port direction>_<Port information>:<Data type>
Eu.ModSt.7511
    Port information type
        Used port information type:
         - D or d: data ports (D-Ports),
         - T or t: trigger ports (T-Ports).
Eu.ModSt.7512
    Data ports and trigger ports start with a small letter (such as d3in_Point_Position or t4out_Timeout)
    if they are part of an internal connection between two FEs or between a FE and a TFE. In this case they
    are referred to as functional ports and have the colour green like the corresponding F E (5).
Eu.ModSt.7513
    Data ports and trigger ports start with a capital letter if they are part of an external connection between
    a FE and the system environment (system interface) or if it is an open port (such as D4in_ Normal_Mode or
    T1in_SIL_not_fulfiled). In this case they are refered to as logical ports and have the colour blue (6).
Eu.ModSt.7514
    Data ports and trigger ports which are part of a connection between TFEs or a TFE and the system environment
    (technical system interface) are referred to as technical functional ports and have the colour Yellow (10).
    They start with a small letter if they are part of an internal connection between two TFEs and with a capital
    letter if they are part of an external connection between a TFE and the system environment (technical system interface).
Eu.ModSt.7515
    Data ports (5), (6)
        Data ports are especially suited to indicate permanently available information.
        The value of a D-port only changes if it is explicitly changed.
Eu.ModSt.7516
    Data in ports are used as arguments of Boolean expressions in change events or transition guards.
    They may represent arguments in data transformations or other data, that need to be permanently reachable by
    the behaviour of a FE (e.g configuration data: d21in_Con_Downgrade_Most_Restrict). Their values can be
    permanently regarded as valid.
Eu.ModSt.7517
    Data out ports are used to provide continuous data created within a FE for its environment (e.g. to be available
    for adjacent FEs, reachable via their data in ports).
Eu.ModSt.7518
    Trigger ports (8)
        Trigger ports are especially suited to indicate singular events. They have a Boolean value that always enters
        false and only briefly changes to true when the event occurs (data types PulsedIn or PulsedOut). Afterwards the
        value is automatically returned to false.
Eu.ModSt.7519
    Trigger in ports are mainly used as arguments of Boolean expressions in change events.
***/

public abstract record PropertyOrPort(OwnedAttribute Property, bool IsPort, ClassInfo Class, IAccessor TheAccessor, PropertyOrPort? ProxyFor) : IAccessible, IAssignable {
    public static PropertyOrPort Create(OwnedAttribute property, Dictionary<string, PackagedElement> types, bool IsPort, ClassInfo Class, IAccessor TheAccessor, PropertyOrPort? ProxyFor = null)
    {
        var umlType = types[property.Type];
        return umlType.Name switch {
            "Boolean" => new BoolPropertyOrPort(property, IsPort, Class, TheAccessor, ProxyFor),
            // "DateTime",
            // "Decimal",
            // "Double",
            // "Integer",
            // "Long",
            // "Single",
            "String" => new StringPropertyOrPort(property, IsPort, Class, TheAccessor, ProxyFor),
            "PulsedIn" => new PulsedInPropertyOrPort(property, IsPort, Class, TheAccessor, ProxyFor),
            "PulsedOut" => new PulsedOutPropertyOrPort(property, IsPort, Class, TheAccessor, ProxyFor),
            // "Timespan",
            _ => new ComplexPropertyOrPort(property, IsPort, umlType, Class, TheAccessor, ProxyFor)
        };
    }

    public string GenerateDeclaration((string, string) finalType) {
        if (IsPort) {
            return $"public Port<{finalType.Item1}> {Name} {{ get; set; }}";
        }
        return $"public {finalType.Item1} {Name} {{ get; set; }}";
    }

    public string GenerateInitializer((string, string) finalType) {
        if (IsPort) {
            return $"{Name} = new Port<{finalType.Item1}>({GenerateInitialValue()});";
        }
        return $"{Name} = new {finalType.Item1}();";
    }

    protected virtual string GenerateInitialValue() {
        return "";
    }

    public abstract IAccessible RecordPossibleValue(LiteralIdentifier value);

    public abstract (string, string) DataType(TargetLanguage language);

    public string Name => InPascalCase(Property.Name);

    public virtual string Accessor(ProgramContext context, TargetLanguage targetLanguage) => TheAccessor.Accessor(this, context, targetLanguage);

    public virtual string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";


    public IAccessible LookupValidLiteral(LiteralIdentifier literal)
    {
        return RecordPossibleValue(literal);
    }

    public virtual string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        return $"{Accessor(context, targetLanguage)} = {other.Accessor(context, targetLanguage)};";
    }

    public abstract void EnsureComparableTypes(IAccessible rhsIdentifier);


    public record StringPropertyOrPort(OwnedAttribute Property, bool IsPort, ClassInfo Class, IAccessor TheAccessor, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, IsPort, Class, TheAccessor, ProxyFor)
    {
        private HashSet<StringPropertyOrPort> FindAllWithEqualDataTypes() {
            var result = new HashSet<StringPropertyOrPort>();
            var toBeProcessed = new HashSet<StringPropertyOrPort>() { this };

            while (toBeProcessed.Count > 0) {
                var item = toBeProcessed.First();
                toBeProcessed.Remove(item);
                result.Add(item);
                foreach (var other in item._equalTypes) {
                    if (result.Contains(other))
                        continue;
                    toBeProcessed.Add(other);
                }
            }

            return result;
        }
        public HashSet<LiteralIdentifier> AllowedValues { get; } = new HashSet<LiteralIdentifier>();
        public HashSet<LiteralIdentifier> GetAllowedValues() {
            var result = new HashSet<LiteralIdentifier>();
            foreach (var source in FindAllWithEqualDataTypes()) {
                result.UnionWith(source.AllowedValues);
            }
            return result;
        }
        public override (string, string) DataType(TargetLanguage language) => GetAllowedValues().Count > 0 ? ($"{Name}Value", "") : ("char", "[4]");

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            AllowedValues.Add(literal);
            return new ImplicitEnumMember($"{Name}Value", literal, Class);
        }

        public static string GenerateEnumMemberName(LiteralIdentifier literal) {
            return literal.Name;
        }

        public override string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
            GetAllowedValues().Count == 0 ?
                $"memcmp({Accessor(context, targetLanguage)}, {other.Accessor(context, targetLanguage)}, sizeof({Accessor(context, targetLanguage)})) == 0" :
                base.Comparator(context, other, targetLanguage);

        public override string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
            GetAllowedValues().Count == 0 ?
                $"memcpy({Accessor(context, targetLanguage)}, {other.Accessor(context, targetLanguage)}, sizeof({Accessor(context, targetLanguage)}));" :
                base.Assign(context, other, targetLanguage);

        private HashSet<StringPropertyOrPort> _equalTypes = new HashSet<StringPropertyOrPort>();
        private void RecordEqualTypes(StringPropertyOrPort other) {
            _equalTypes.Add(other);
            other._equalTypes.Add(this);
        }

        public override void EnsureComparableTypes(IAccessible rhsIdentifier)
        {
            switch (rhsIdentifier) {
                case MessageMember messageMember:
                    EnsureComparableTypes(messageMember.Member);
                    break;
                case StringPropertyOrPort stringPropertyOrPort:
                    // e.g. checksum data
                    RecordEqualTypes(stringPropertyOrPort);
                    break;
                case ImplicitEnumMember implicitEnumMember:
                    // most likely created from RecordPossibleValue, so probably already in set
                    AllowedValues.Add(implicitEnumMember.Literal);
                    break;
                default:
                    throw new Exception("Incomparable types");
            }

            if (ProxyFor != null) {
                ProxyFor.EnsureComparableTypes(rhsIdentifier);
            }
        }
    }

    public record ComplexPropertyOrPort(OwnedAttribute Property, bool IsPort, PackagedElement UmlType, ClassInfo Class, IAccessor TheAccessor, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, IsPort, Class, TheAccessor, ProxyFor)
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

        public override (string, string) DataType(TargetLanguage language) => UmlType.Type switch {
            "uml:Class" => ("Channel<EulynxMessages.Message>", ""),
            "uml:Enumeration" => (InPascalCase(UmlType.Name), ""),
            _ => ("int", "")
        };

        public override void EnsureComparableTypes(IAccessible rhsIdentifier)
        {
            if (rhsIdentifier is EnumerationMember enumerationMember) {
                // TODO: Perform further checks
                return;
            }

            throw new Exception("Incomparable types");
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

    public record BoolPropertyOrPort(OwnedAttribute Property, bool IsPort, ClassInfo Class, IAccessor TheAccessor, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, IsPort, Class, TheAccessor, ProxyFor)
    {
        public override (string, string) DataType(TargetLanguage language) => ("bool", "");

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

        public override void EnsureComparableTypes(IAccessible rhsIdentifier)
        {
            if (rhsIdentifier is not BoolPropertyOrPort && rhsIdentifier is not BoolLiteral) {
                throw new Exception("Incomparable types");
            }
        }
    }

    /***
    Eu.ModSt.7546
        The data types "PulsedIn" and "PulsedOut" represent redefinitions of the data type Boolean and are
        exclusively reserved to be assigned to Trigger Ports (T-Ports). That is, a Trigger In Port is typed
        with the data type "PulsedIn" and a Trigger Out Port with the data type "PulsedOut".
    Eu.ModSt.7547
        Outgoing data typed with "PulsedOut" (as default false) that are set to true (for example,
        T1out_Cd_indicate_signal_aspect := true) automatically change back to false after a defined time.
        The defined time frame is sufficient to trigger a transition in a receiving state machine.
    Eu.ModSt.7548
        Incoming data at receiver side typed with "PulsedIn" apply the behaviour of the corresponding outgoing
        data at sender side typed with "PulsedOut".
    ***/

    record PulsedInPropertyOrPort(OwnedAttribute Property, bool IsPort, ClassInfo Class, IAccessor TheAccessor, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, IsPort, Class, TheAccessor, ProxyFor)
    {
        public override (string, string) DataType(TargetLanguage language) => language switch
        {
            TargetLanguage.CSharp => ("PulsedIn", ""),
            TargetLanguage.C => ("PulsedIn", ""),
            TargetLanguage.Rust => ("bool /*PulsedIn*/", ""),
            _ => throw new NotImplementedException(),
        };

        // TODO: Language-specific
        protected override string GenerateInitialValue()
        {
            return "0";
        }

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            if (literal.Name == "True")
                return new PulsedInLiteral();

            throw new ArgumentException($"Invalid pulsed in value: {literal}");
        }

        public override void EnsureComparableTypes(IAccessible rhsIdentifier)
        {
            if (rhsIdentifier is not PulsedInLiteral) {
                throw new Exception("Incomparable types");
            }
        }

        public override string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
        {
            throw new InvalidOperationException("PulsedIn cannot be assigned to");
        }

        public override string Accessor(ProgramContext context, TargetLanguage targetLanguage)
        {
            return $"{base.Accessor(context, targetLanguage)}.IsTriggered";
        }
    }

    record PulsedOutPropertyOrPort(OwnedAttribute Property, bool IsPort, ClassInfo Class, IAccessor TheAccessor, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, IsPort, Class, TheAccessor, ProxyFor)
    {
        public override (string, string) DataType(TargetLanguage language) => language switch
        {
            TargetLanguage.CSharp => ("PulsedOut", ""),
            TargetLanguage.C => ("PulsedOut", ""),
            TargetLanguage.Rust => ("bool /*PulsedOut*/", ""),
            _ => throw new NotImplementedException(),
        };

        // TODO: Language-specific
        protected override string GenerateInitialValue()
        {
            return "0";
        }

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            if (literal.Name == "True")
                return new PulsedOutLiteral();

            throw new ArgumentException($"Invalid pulsed out value: {literal}");
        }

        public override void EnsureComparableTypes(IAccessible rhsIdentifier)
        {
            if (rhsIdentifier is not PulsedOutLiteral) {
                throw new Exception("Incomparable types");
            }
        }

        public override string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
        {
            return targetLanguage switch {
                TargetLanguage.C => $"{Accessor(context, targetLanguage)}.Trigger = {other.Accessor(context, targetLanguage)};",
                _ => base.Assign(context, other, targetLanguage)
            };
        }
    }
}
