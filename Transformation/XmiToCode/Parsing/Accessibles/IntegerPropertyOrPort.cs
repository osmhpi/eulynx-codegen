using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;
using XmiToCode.Messages;

namespace XmiToCode.Parsing.Accessibles;

public record IntegerPropertyOrPort(IAttributeOrParameter Property, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, ProxyFor)
{
    public override (string, string) DataType(TargetLanguage language) => ("int", "");

    public override IAccessible RecordPossibleValue(LiteralIdentifier literal)
    {
        throw new ArgumentException($"Invalid integer value: {literal}");
    }

    public override string Accessor(IProgramContext context, TargetLanguage targetLanguage) =>
        TheAccessor switch {
            ClassAccessor => TheAccessor.Accessor(this, context, targetLanguage) + (IsDataPort ? ".Value" : ""),
            _ => TheAccessor.Accessor(this, context, targetLanguage),
        };

    public override string Accessor(IProgramContext context, TargetLanguage targetLanguage, IAccessor accessor) =>
        accessor switch {
            ClassAccessor => accessor.Accessor(this, context, targetLanguage) + (IsDataPort ? ".Value" : ""),
            _ => accessor.Accessor(this, context, targetLanguage),
        };

    public string IsSignalledAccessor(IProgramContext context, TargetLanguage targetLanguage)
        => TheAccessor.Accessor(this, context, targetLanguage) + ".IsSignalled";

    public override void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        var theRhs = rhsIdentifier;
        if (rhsIdentifier is MessageMember messageMember)
        {
            theRhs = messageMember.Member;
        }

        if (rhsIdentifier is CallableNotSoParameterless callableParameterless)
        {
            callableParameterless.Callable.Operation.EnsureReturnTypeMatches(this);
            return;
        }

        if (theRhs is not IntegerPropertyOrPort && theRhs is not NumberLiteral)
        {
            throw new Exception("Incomparable types");
        }
    }
}
