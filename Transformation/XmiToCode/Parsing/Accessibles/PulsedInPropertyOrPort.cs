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

public record PulsedInPropertyOrPort(IAttributeOrParameter Property, PropertyOrPort? ProxyFor) : PropertyOrPort(Property, ProxyFor)
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
        if (rhsIdentifier is not PulsedInLiteral)
        {
            throw new Exception("Incomparable types");
        }
    }

    public override string Assign(IProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor)
    {
        throw new InvalidOperationException("PulsedIn cannot be assigned to");
    }

    public override string Accessor(IProgramContext context, TargetLanguage targetLanguage)
    {
        return $"{base.Accessor(context, targetLanguage)}.IsTriggered";
    }
}
