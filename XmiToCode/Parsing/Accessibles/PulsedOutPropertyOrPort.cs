using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Accessibles;

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

public record PulsedOutPropertyOrPort(OwnedAttribute Property, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, ProxyFor)
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

    public override IAccessible LookupValidIdentifier(Identifier identifier, IProgramContext context)
    {
        if (identifier.Name == "True")
            return new PulsedOutLiteral();

        return base.LookupValidIdentifier(identifier, context);
    }

    public override void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        if (rhsIdentifier is not PulsedOutLiteral)
        {
            throw new Exception("Incomparable types");
        }
    }

    public override string Assign(IProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor)
    {
        return targetLanguage switch
        {
            TargetLanguage.C => $"{Accessor(context, targetLanguage, accessor)}.Trigger = {other.Accessor(context, targetLanguage)};",
            _ => base.Assign(context, other, targetLanguage, accessor)
        };
    }
}
