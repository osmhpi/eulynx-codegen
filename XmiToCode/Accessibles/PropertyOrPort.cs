using System.Text.RegularExpressions;
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
    a FE and the system environment (system interface) or if it is an open port (such as D4in_Normal_Mode or
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

public abstract record PropertyOrPort(OwnedAttribute Property, ClassInfo Class, PropertyOrPort? ProxyFor) : IAccessible, IAssignable {

    public Identifier Identifier { get; } = new Identifier(Property.Name);
    public IAccessor TheAccessor { get; } = new ClassAccessor();

    public bool IsExternalInterface => Identifier.RawName.StartsWith("T") || Identifier.RawName.StartsWith("D");
    public bool IsDataPort => Identifier.RawName.StartsWith("d") || Identifier.RawName.StartsWith("D");
    public bool IsTriggerPort => Identifier.RawName.StartsWith("t") || Identifier.RawName.StartsWith("T");
    public bool IsInPort => Regex.IsMatch(Identifier.RawName, "^[dDtT](\\d+)in_([\\w_]+)$");
    public bool IsOutPort => Regex.IsMatch(Identifier.RawName, "^[dDtT](\\d+)out_([\\w_]+)$");

    public static PropertyOrPort Create(OwnedAttribute property, Dictionary<string, PackagedElement> types, ClassInfo Class, PropertyOrPort? ProxyFor = null)
    {
        if (property.Type == null) {
            return new UntypedPropertyOrPort(property, Class, ProxyFor);
        }

        var umlType = types[property.Type];
        PropertyOrPort result = umlType.Name switch {
            "Boolean" => new BoolPropertyOrPort(property, Class, ProxyFor),
            // "DateTime",
            // "Decimal",
            // "Double",
            // "Integer",
            // "Long",
            // "Single",
            "String" => new StringPropertyOrPort(property, Class, ProxyFor),
            "PulsedIn" => new PulsedInPropertyOrPort(property, Class, ProxyFor),
            "PulsedOut" => new PulsedOutPropertyOrPort(property, Class, ProxyFor),
            // "Timespan",
            _ => new ComplexPropertyOrPort(property, umlType, Class, ProxyFor)
        };

        // Extra validation of naming conventions
        // if (result is PulsedInPropertyOrPort && (!result.IsTriggerPort || !result.IsInPort)) {
        //     throw new ModelException($"Naming convention was violated for {result.Identifier.RawName}");
        // }

        // if (result is PulsedOutPropertyOrPort && (!result.IsTriggerPort || !result.IsOutPort)) {
        //     throw new ModelException($"Naming convention was violated for {result.Identifier.RawName}");
        // }

        return result;
    }

    protected virtual string GenerateInitialValue() {
        return "";
    }

    public abstract IAccessible RecordPossibleValue(LiteralIdentifier value);

    public abstract (string, string) DataType(TargetLanguage language);

    public string Name => InPascalCase(Property.Name);

    public virtual string Accessor(ProgramContext context, TargetLanguage targetLanguage) =>
        TheAccessor.Accessor(this, context, targetLanguage);

    public virtual string Accessor(ProgramContext context, TargetLanguage targetLanguage, IAccessor accessor)
        => accessor.Accessor(this, context, targetLanguage);

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        Comparator(context, other, targetLanguage, TheAccessor);

    public virtual string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor) =>
        $"{Accessor(context, targetLanguage, accessor)} == {other.Accessor(context, targetLanguage)}";

    public IAccessible LookupValidLiteral(LiteralIdentifier literal)
    {
        return RecordPossibleValue(literal);
    }

    public string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
        => Assign(context, other, targetLanguage, TheAccessor);

    public virtual string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor)
        => $"{Accessor(context, targetLanguage, accessor)} = {other.Accessor(context, targetLanguage)};";

    public abstract void EnsureComparableTypes(IAccessible rhsIdentifier);

    public virtual IAccessible LookupValidIdentifier(Identifier identifier, ProgramContext context)
    {
        return context.ResolveIdentifier(identifier);
    }

    public record StringPropertyOrPort(OwnedAttribute Property, ClassInfo Class, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, Class, ProxyFor)
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

        public override (string, string) DataType(TargetLanguage language) {
            // TODO: fallback should be ("void*", "") except for whitelisted PDI version etc.
            return GetAllowedValues().Count > 0 ? ($"{Name}Value", "") : ("char", "[4]");
        }

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            AllowedValues.Add(literal);
            return new ImplicitEnumMember($"{Name}Value", literal, Class);
        }

        public static string GenerateEnumMemberName(LiteralIdentifier literal) {
            return literal.Name;
        }

        public override string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor) =>
            GetAllowedValues().Count == 0 ?
                $"memcmp({Accessor(context, targetLanguage, accessor)}, {other.Accessor(context, targetLanguage)}, sizeof({Accessor(context, targetLanguage, accessor)})) == 0" :
                base.Comparator(context, other, targetLanguage, accessor);

        public override string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor) =>
            GetAllowedValues().Count == 0 ?
                $"memcpy({Accessor(context, targetLanguage, accessor)}, {other.Accessor(context, targetLanguage)}, sizeof({Accessor(context, targetLanguage, accessor)}));" :
                base.Assign(context, other, targetLanguage, accessor);

        private HashSet<StringPropertyOrPort> _equalTypes = new();
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

            ProxyFor?.EnsureComparableTypes(rhsIdentifier);
        }
    }

    public record UntypedPropertyOrPort(OwnedAttribute Property, ClassInfo Class, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, Class, ProxyFor)
    {
        public override (string, string) DataType(TargetLanguage language)
        {
            return ("void*", "");
        }

        public override void EnsureComparableTypes(IAccessible rhsIdentifier)
        {
            throw new Exception("Untyped property");
        }

        public override IAccessible RecordPossibleValue(LiteralIdentifier value)
        {
            throw new Exception("Untyped property");
        }
    }

    public record ComplexPropertyOrPort(OwnedAttribute Property, PackagedElement UmlType, ClassInfo Class, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, Class, ProxyFor)
    {
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

            var enumLiteral = UmlType.OwnedLiteral
                .Select(x => new GlobalEnumIdentifier(x.Name))
                .Single(x => x.RawName == literal.RawName);
            return new EnumerationMember(UmlType, enumLiteral);
        }

        public override IAccessible LookupValidIdentifier(Identifier identifier, ProgramContext context)
        {
            var enumLiteral = UmlType.OwnedLiteral
                .Select(x => new GlobalEnumIdentifier(x.Name))
                .SingleOrDefault(x => x.RawName == identifier.RawName);
            if (enumLiteral != null) {
                return new EnumerationMember(UmlType, enumLiteral);
            }

            return base.LookupValidIdentifier(identifier, context);
        }
    }

    public record BoolPropertyOrPort(OwnedAttribute Property, ClassInfo Class, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, Class, ProxyFor)
    {
        public override (string, string) DataType(TargetLanguage language) => ("bool", "");

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            if (literal.Name == "True")
                return new BoolLiteral(true);

            if (literal.Name == "False")
                return new BoolLiteral(false);

            throw new ArgumentException($"Invalid bool value: {literal}");
        }

        public override IAccessible LookupValidIdentifier(Identifier identifier, ProgramContext context)
        {
            if (identifier.Name == "True")
                return new BoolLiteral(true);

            if (identifier.Name == "False")
                return new BoolLiteral(false);

            return base.LookupValidIdentifier(identifier, context);
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

    public record PulsedInPropertyOrPort(OwnedAttribute Property, ClassInfo Class, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, Class, ProxyFor)
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

        public override string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor)
        {
            throw new InvalidOperationException("PulsedIn cannot be assigned to");
        }

        public override string Accessor(ProgramContext context, TargetLanguage targetLanguage)
        {
            return $"{base.Accessor(context, targetLanguage)}.IsTriggered";
        }
    }

    public record PulsedOutPropertyOrPort(OwnedAttribute Property, ClassInfo Class, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, Class, ProxyFor)
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

        public override IAccessible LookupValidIdentifier(Identifier identifier, ProgramContext context)
        {
            if (identifier.Name == "True")
                return new PulsedOutLiteral();

            return base.LookupValidIdentifier(identifier, context);
        }

        public override void EnsureComparableTypes(IAccessible rhsIdentifier)
        {
            if (rhsIdentifier is not PulsedOutLiteral) {
                throw new Exception("Incomparable types");
            }
        }

        public override string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor)
        {
            return targetLanguage switch {
                TargetLanguage.C => $"{Accessor(context, targetLanguage, accessor)}.Trigger = {other.Accessor(context, targetLanguage)};",
                _ => base.Assign(context, other, targetLanguage, accessor)
            };
        }
    }
}
