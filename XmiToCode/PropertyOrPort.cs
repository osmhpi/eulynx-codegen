using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationItem;

public enum TargetLanguage {
    CSharp,
    C,
    Rust
}

public interface IAccessible {
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage);
    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage);
    void EnsureComparableTypes(IAccessible rhsIdentifier);
}

public interface IAssignable : IAccessible {
    IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier);
    public string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage);
}

public interface ICallable {
    public string Call(ProgramContext context, TargetLanguage targetLanguage);
}

public interface IAccessor {
    public string Accessor(PropertyOrPort propertyOrPort, ProgramContext context, TargetLanguage targetLanguage);
}

public class ClassAccessor : IAccessor {
    public string Accessor(PropertyOrPort propertyOrPort, ProgramContext context, TargetLanguage targetLanguage) {
        return targetLanguage switch
        {
            TargetLanguage.Rust => $"{propertyOrPort.Name}",
            _ => context.IsLocalVariable(propertyOrPort) ?
            // IsPort ?
            //     $"{propertyOrPort.Name}.Value" :
                $"{propertyOrPort.Name}" :
            // IsPort ?
            //     $"{context.InstanceReference}->{propertyOrPort.Name}.Value" :
                $"{context.InstanceReference}->{propertyOrPort.Name}"
        };
    }
}

public class MessageAccessor : IAccessor {
    private readonly TypeIdentifier _messageType;
    private readonly Identifier _memberName;

    public MessageAccessor(TypeIdentifier messageType, Identifier memberName)
    {
        _messageType = messageType;
        _memberName = memberName;
    }
    public string Accessor(PropertyOrPort propertyOrPort, ProgramContext context, TargetLanguage targetLanguage) {
        return $"{context.InstanceReference}->{_messageType.Name}.Value.{_memberName.Name}";
    }
}

public record MessageMember(TypeIdentifier Message, Identifier MemberName, PackagedElement Type, PropertyOrPort Member) : IAccessible, IAssignable
{
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage)
    {
        return Member.Accessor(context, targetLanguage);
    }

    public string Assign(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        // return $"{Accessor(context, targetLanguage)} = {other.Accessor(context, targetLanguage)};";
        return Member.Assign(context, other, targetLanguage);
    }

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        return Member.Comparator(context, other, targetLanguage);
    }

    // public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    // {
    //     return $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";
    // }

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        Member.EnsureComparableTypes(rhsIdentifier);
    }

    public IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier) => Member.LookupValidLiteral(literalIdentifier);
}

public record MessageSchema(TypeIdentifier Identifier, PackagedElement Signal, DataTypeHelper DataTypes)
{
    public List<MessageMember> Members { get; } = Signal.OwnedAttribute
        .Select(x => new MessageMember(Identifier, new Identifier(x.Name), DataTypes.DataTypes[x.Type],
            PropertyOrPort.Create(x, DataTypes.DataTypes, false, new ClassInfo("Message", ""), new MessageAccessor(Identifier, new Identifier(x.Name)))))
        .ToList();

    public IEnumerable<ValueType> GetValueTypes() {
        return Members
            .Where(x => x.Member is PropertyOrPort.StringPropertyOrPort)
            .Select(x => new ValueType(
                new ClassInfo(Identifier.Name, ""),
                x.MemberName,
                ((PropertyOrPort.StringPropertyOrPort)x.Member).AllowedValues))
            .Where(x => x.AllowedValues.Count > 0);
    }

    public Dictionary<Identifier, MessageMember> MembersDict => Members.ToDictionary(x => x.MemberName);

    internal MessageMember GetMemberByIndex(int i)
    {
        return Members[i];
    }
}

// Could be an enum member
public record LiteralIdentifier (string RawName)
{
    public string Name => InPascalCase(Sanitize(RawName));

    private static string Sanitize(string value) {
        var sanitizedValue = InPascalCase(value.Replace(",", " And "));

        if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
            sanitizedValue = "_" + sanitizedValue;
        }

        return sanitizedValue;
    }
}

// Could be a reference to a port or variable
public record Identifier (string RawName)
{
    public string Name { get; } = InPascalCase(RawName);
}

// Could be an enumeration or message class
public record TypeIdentifier (string RawName)
{
    public string Name { get; } = InPascalCase(RawName);
}

public record ClassMember(Identifier Identifier) : IAccessible {
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage) =>
        targetLanguage switch {
            TargetLanguage.Rust => Identifier.Name,
            _ => context.IsLocalVariable(this)
                ? Identifier.Name
                : $"{context.InstanceReference}->{Identifier.Name}"
        };

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}

public record EnumerationMember(PackagedElement UmlEnumeration, OwnedLiteral Member) : IAccessible {
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage) => $"{UmlEnumeration.Name}__{Member.Name}";

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}

public record ImplicitEnumMember(string EnumType, LiteralIdentifier Literal, ClassInfo Class) : IAccessible {
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage) => $"{EnumType}__{Literal.Name}";

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}

public record BoolLiteral(bool Value) : IAccessible
{
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage) => Value ? "true" : "false";

    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}

public record PulsedInLiteral(bool Value) : IAccessible
{
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage) => Value ? "1" : "0";
    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}

public record PulsedOutLiteral(bool Value) : IAccessible
{
    public string Accessor(ProgramContext context, TargetLanguage targetLanguage) => Value ? "1" : "0";
    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}

public record Method(Identifier Identifier, Operation Operation) : ICallable
{
    public string Call(ProgramContext context, TargetLanguage targetLanguage) => targetLanguage switch
    {
        TargetLanguage.CSharp => $"{Identifier.Name}({context.InstanceReference})",
        TargetLanguage.C => $"{Identifier.Name}({context.InstanceReference})",
        TargetLanguage.Rust => $"self.{Identifier.Name}()",
        _ => throw new NotImplementedException()
    };
}

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

    public abstract string GenerateAssignment(string value);

    public abstract (string, string) DataType(TargetLanguage language);

    public string Name => InPascalCase(Property.Name);

    public string Accessor(ProgramContext context, TargetLanguage targetLanguage) => TheAccessor.Accessor(this, context, targetLanguage);

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

        // TODO: This is language-specific
        public override string GenerateAssignment(string value) =>
            $"{DataType}.{DataTypeHelper.GenerateEnumMemberName(value)}";

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

    public record BoolPropertyOrPort(OwnedAttribute Property, bool IsPort, ClassInfo Class, IAccessor TheAccessor, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, IsPort, Class, TheAccessor, ProxyFor)
    {
        public override (string, string) DataType(TargetLanguage language) => ("bool", "");

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

        public override void EnsureComparableTypes(IAccessible rhsIdentifier)
        {
            if (rhsIdentifier is not BoolPropertyOrPort && rhsIdentifier is not BoolLiteral) {
                throw new Exception("Incomparable types");
            }
        }
    }

    record PulsedInPropertyOrPort(OwnedAttribute Property, bool IsPort, ClassInfo Class, IAccessor TheAccessor, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, IsPort, Class, TheAccessor, ProxyFor)
    {
        public override (string, string) DataType(TargetLanguage language) => language switch
        {
            TargetLanguage.CSharp => ("PulsedIn", ""),
            TargetLanguage.C => ("int /*PulsedIn*/", ""),
            TargetLanguage.Rust => ("bool /*PulsedIn*/", ""),
            _ => throw new NotImplementedException(),
        };

        // TODO: Language-specific
        public override string GenerateAssignment(string value)
        {
            if (value == "TRUE")
                return "1";
            if (value == "FALSE")
                return "0";
            throw new ArgumentException(value);
        }

        // TODO: Language-specific
        protected override string GenerateInitialValue()
        {
            return "0";
        }

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            if (literal.Name == "True")
                return new PulsedInLiteral(true);

            if (literal.Name == "False")
                return new PulsedInLiteral(false);

            throw new ArgumentException($"Invalid pulsed in value: {literal}");
        }

        public override void EnsureComparableTypes(IAccessible rhsIdentifier)
        {
            if (rhsIdentifier is not PulsedInLiteral) {
                throw new Exception("Incomparable types");
            }
        }
    }

    record PulsedOutPropertyOrPort(OwnedAttribute Property, bool IsPort, ClassInfo Class, IAccessor TheAccessor, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, IsPort, Class, TheAccessor, ProxyFor)
    {
        public override (string, string) DataType(TargetLanguage language) => language switch
        {
            TargetLanguage.CSharp => ("PulsedOut", ""),
            TargetLanguage.C => ("int /*PulsedOut*/", ""),
            TargetLanguage.Rust => ("bool /*PulsedOut*/", ""),
            _ => throw new NotImplementedException(),
        };

        // TODO: Language-specific
        public override string GenerateAssignment(string value)
        {
            if (value == "TRUE")
                return "1";
            if (value == "FALSE")
                return "0";
            throw new ArgumentException(value);
        }

        // TODO: Language-specific
        protected override string GenerateInitialValue()
        {
            return "0";
        }

        public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
        {
            if (literal.Name == "True")
                return new PulsedOutLiteral(true);

            if (literal.Name == "False")
                return new PulsedOutLiteral(false);

            throw new ArgumentException($"Invalid pulsed out value: {literal}");
        }

        public override void EnsureComparableTypes(IAccessible rhsIdentifier)
        {
            if (rhsIdentifier is not PulsedOutLiteral) {
                throw new Exception("Incomparable types");
            }
        }
    }
}
