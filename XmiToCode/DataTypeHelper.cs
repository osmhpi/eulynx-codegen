using XmiToCode.Accessibles;
using XmiToCode.Classes;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode;

public class DataTypeHelper {

    public Dictionary<string, PropertyOrPort> Properties { get; private set; }
    public Dictionary<string, PropertyOrPort> Ports { get; }
    public List<Identifier> Operations { get; }
    public Dictionary<string, PackagedElement> ChangeEvents { get; }
    public Dictionary<string, PackagedElement> TimeEvents { get; }
    public Dictionary<string, PackagedElement> PackageEvents { get; }
    public Dictionary<string, PackagedElement> DataTypes { get; }
    public HashSet<PackagedElement> UsedChangeEvents { get; }

    public DataTypeHelper(
        List<OwnedAttribute> properties,
        List<OwnedAttribute> ports,
        List<Identifier> operationNames,
        Dictionary<string, PackagedElement> changeEvents,
        Dictionary<string, PackagedElement> timeEvents,
        Dictionary<string, PackagedElement> packageEvents,
        Dictionary<string, PackagedElement> dataTypes,
        ClassInfo classInfo)
    {
        Properties = properties.Select(x => PropertyOrPort.Create(x, dataTypes, classInfo)).ToDictionary(x => x.Name);
        Ports = ports.Select(x => PropertyOrPort.Create(x, dataTypes, classInfo)).ToDictionary(x => x.Name);

        Operations = operationNames;
        ChangeEvents = changeEvents;
        TimeEvents = timeEvents;
        PackageEvents = packageEvents;
        DataTypes = dataTypes;
        UsedChangeEvents = new HashSet<PackagedElement>();
    }
}
