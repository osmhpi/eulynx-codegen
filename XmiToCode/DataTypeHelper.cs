using XmiToCode;

public class DataTypeHelper {

    public Dictionary<string, PropertyOrPort> Properties { get; private set; }
    public Dictionary<string, PropertyOrPort> Ports { get; }
    public List<Identifier> Operations { get; }
    public Dictionary<string, PackagedElement> ChangeEvents { get; }
    public Dictionary<string, PackagedElement> TimeEvents { get; }
    public Dictionary<string, PackagedElement> PackageEvents { get; }
    public Dictionary<string, PackagedElement> Signals { get; }
    public Dictionary<string, PackagedElement> DataTypes { get; }
    public HashSet<PackagedElement> UsedChangeEvents { get; }

    private readonly Dictionary<string, PropertyOrPort> _coalescedValues;
    // Externally provided aliases for types
    private readonly Dictionary<(string, string), (string, string)> _typeAliases;

    public DataTypeHelper(
        List<OwnedAttribute> properties,
        List<OwnedAttribute> ports,
        List<Identifier> operationNames,
        Dictionary<string, PackagedElement> changeEvents,
        Dictionary<string, PackagedElement> timeEvents,
        Dictionary<string, PackagedElement> packageEvents,
        Dictionary<string, PackagedElement> signals,
        Dictionary<string, PackagedElement> dataTypes,
        Dictionary<(string, string), (string, string)> typeAliases,
        ClassInfo classInfo)
    {
        Properties = properties.Select(x => PropertyOrPort.Create(x, dataTypes, false, classInfo, new ClassAccessor())).ToDictionary(x => x.Name);
        Ports = ports.Select(x => PropertyOrPort.Create(x, dataTypes, true, classInfo, new ClassAccessor())).ToDictionary(x => x.Name);

        Operations = operationNames;
        ChangeEvents = changeEvents;
        TimeEvents = timeEvents;
        PackageEvents = packageEvents;
        Signals = signals;
        DataTypes = dataTypes;
        _typeAliases = typeAliases;

        _coalescedValues = new Dictionary<string, PropertyOrPort>();
        UsedChangeEvents = new HashSet<PackagedElement>();
    }
}
