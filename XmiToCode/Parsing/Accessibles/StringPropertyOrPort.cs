using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Messages;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Accessibles;

public record StringPropertyOrPort(OwnedAttribute Property, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, ProxyFor)
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
        var allowedValues = GetAllowedValues();
        #if !DISABLE_HACKS
        if (allowedValues.Count == 0 && (Name == "PdiVersion" || Name == "PDIVersion")) {
            return ("char", "");
        }
        if (allowedValues.Count == 0 && (Name == "ChecksumData" || Name == "MemChecksumData")) {
            return ("char", "[16]");
        }
        #endif
        return allowedValues.Count > 0 ? ($"{Name}Value", "") : ("void*", "");
    }

    public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
    {
        AllowedValues.Add(literal);
        return new ImplicitEnumMember($"{Name}Value", literal);
    }

    public static string GenerateEnumMemberName(LiteralIdentifier literal) {
        return literal.Name;
    }

    public override string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor) =>
        GetAllowedValues().Count == 0 ?
            $"memcmp({Accessor(context, targetLanguage, accessor)}, {other.Accessor(context, targetLanguage)}, sizeof({Accessor(context, targetLanguage, accessor)})) == 0" :
            base.Comparator(context, other, targetLanguage, accessor);

    public override string Assign(IProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor) =>
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
