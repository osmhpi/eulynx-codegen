using System.Text.RegularExpressions;
using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;
using static XmiToCode.Codegen.CodeGenerationHelper;

namespace XmiToCode.Parsing.Accessibles;

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

public abstract partial record PropertyOrPort(OwnedAttribute Property, PropertyOrPort? ProxyFor) : IAccessible, IAssignable {

    public Identifier Identifier { get; } = new Identifier(Property.Name);
    public IAccessor TheAccessor { get; } = new ClassAccessor();

    public bool IsExternalInterface => Identifier.RawName.StartsWith("T") || Identifier.RawName.StartsWith("D");
    public bool IsDataPort => Identifier.RawName.StartsWith("d") || Identifier.RawName.StartsWith("D");
    public bool IsTriggerPort => Identifier.RawName.StartsWith("t") || Identifier.RawName.StartsWith("T");
    public bool IsInPort => IsInPortRegex().IsMatch(Identifier.RawName);
    public bool IsOutPort => IsOutPortRegex().IsMatch(Identifier.RawName);

    public static PropertyOrPort CreatePropertyOrPort(OwnedAttribute property, Dictionary<string, PackagedElement> types, PropertyOrPort? ProxyFor = null)
    {
        if (property.Type == null) {
            Console.WriteLine($"Warn: Property {property.Name} has no type, assuming string.");
            return new StringPropertyOrPort(property, ProxyFor);

            // return new UntypedPropertyOrPort(property, ProxyFor);
        }

        var umlType = types[property.Type];
        PropertyOrPort result = umlType.Name switch {
            "Boolean" => new BoolPropertyOrPort(property, ProxyFor),
            // "DateTime",
            // "Decimal",
            // "Double",
            "Integer" => new IntegerPropertyOrPort(property, ProxyFor),
            // "Long",
            // "Single",
            "String" => new StringPropertyOrPort(property, ProxyFor),
            "PulsedIn" => new PulsedInPropertyOrPort(property, ProxyFor),
            "PulsedOut" => new PulsedOutPropertyOrPort(property, ProxyFor),
            // "Timespan",
            _ => new ComplexPropertyOrPort(property, umlType, ProxyFor)
        };

        // Extra validation of naming conventions
        if (result is PulsedInPropertyOrPort && (!result.IsTriggerPort || !result.IsInPort)) {
            Console.WriteLine($"Warn: Naming convention was violated for {result.Identifier.RawName}");
            // throw new ModelException($"Naming convention was violated for {result.Identifier.RawName}");
        }

        if (result is PulsedOutPropertyOrPort && (!result.IsTriggerPort || !result.IsOutPort)) {
            Console.WriteLine($"Warn: Naming convention was violated for {result.Identifier.RawName}");
            // throw new ModelException($"Naming convention was violated for {result.Identifier.RawName}");
        }

        return result;
    }

    protected virtual string GenerateInitialValue() {
        return "";
    }

    public abstract IAccessible RecordPossibleValue(LiteralIdentifier value);

    public abstract (string, string) DataType(TargetLanguage language);

    public string Name => InPascalCase(Property.Name);

    public virtual string Accessor(IProgramContext context, TargetLanguage targetLanguage) =>
        TheAccessor.Accessor(this, context, targetLanguage);

    public virtual string Accessor(IProgramContext context, TargetLanguage targetLanguage, IAccessor accessor)
        => accessor.Accessor(this, context, targetLanguage);

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        Comparator(context, other, targetLanguage, TheAccessor);

    public virtual string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor) =>
        $"{Accessor(context, targetLanguage, accessor)} == {other.Accessor(context, targetLanguage)}";

    public IAccessible LookupValidLiteral(LiteralIdentifier literal)
    {
        return RecordPossibleValue(literal);
    }

    public string Assign(IProgramContext context, IAccessible other, TargetLanguage targetLanguage)
        => Assign(context, other, targetLanguage, TheAccessor);

    public virtual string Assign(IProgramContext context, IAccessible other, TargetLanguage targetLanguage, IAccessor accessor)
        => $"{Accessor(context, targetLanguage, accessor)} = {other.Accessor(context, targetLanguage)};";

    public abstract void EnsureComparableTypes(IAccessible rhsIdentifier);

    public virtual IAccessible LookupValidIdentifier(Identifier identifier, IProgramContext context)
    {
        return context.ResolveIdentifier(identifier);
    }

    [GeneratedRegex("^[dDtT](\\d+)in_([\\w_]+)$")]
    private static partial Regex IsInPortRegex();
    [GeneratedRegex("^[dDtT](\\d+)out_([\\w_]+)$")]
    private static partial Regex IsOutPortRegex();
}
