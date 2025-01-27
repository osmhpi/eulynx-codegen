using System.Xml.Serialization;
using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.Model;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing;

public abstract class XmiParser {
    private readonly string[]? _classWhitelist;
    private readonly string[]? _classBlacklist;

    public GlobalContext GlobalContext { get; }
    public List<PackagedElement> InterestingPackages { get; }
    public virtual string[] PackageWhitelist { get; } = [
        "Generic requirements for SCI",
        "Generic requirements for subsystems",
        "Subsystem Point",
        "Subsystem IO",
        "Subsystem Light Signal",
        "Subsystem Level Crossing",
        "Subsystem Train Detection System",
    ];

    public string[] PackageBlacklist { get; } = [
        "Generic recycle bin",
    ];

    // Other blacklisted packages:
    // "Recycle bin",
    // "Recycle Bin",
    // "Not synchronized model elements"

    public abstract List<PackagedElement> ResolveGenericEvents(List<PackagedElement> packages);

    public XmiParser(string filename, string[]? classWhitelist, string[]? classBlacklist)
    {
        using var inFile = File.OpenRead(filename);

        var xmlSerializer = new XmlSerializer(typeof(XMI), "");
        var xmi = xmlSerializer.Deserialize(inFile) as XMI ?? throw new Exception("Could not deserialize input");

        // This only selects top-level packages
        var packages = xmi.Model.PackagedElements.Where(x => x.Type == "uml:Package").ToList();

        var sysimProfile = xmi.Model.PackagedElements
            .Single(x => x.Type == "uml:Profile" && x.Name == "SySim Profile");
        var eulynxProfile = xmi.Model.PackagedElements
            .Single(x => x.Type == "uml:Package" && x.Name == "EULYNX_Profile");

        var eulynxSystem = packages.Single(x => x.Name == "EULYNX System");
        var simulation = packages.Single(x => x.Name == "Simulation_Package");

        var genericEvents = ResolveGenericEvents(packages);

        var dataTypes = FindAllDataTypes(sysimProfile)
            .Concat(FindAllDataTypes(eulynxProfile))
            .Concat(FindAllClasses(simulation))
            .Concat(FindAllClasses(eulynxSystem))
            .Concat(FindAllEnumerations(eulynxSystem))
            // TODO: Shouldn't this be x.Name? Then, we start to have duplicates, which is a problem later on anyways
            .ToDictionary(x => x.Id);

        InterestingPackages = eulynxSystem.PackagedElements
            .Where(x => !PackageWhitelist.Any() || PackageWhitelist.Contains(x.Name))
            .Where(x => !PackageBlacklist.Contains(x.Name))
            .Concat([simulation])
            .ToList();

        var changeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:ChangeEvent").ToDictionary(x => x.Id);
        var timeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:TimeEvent").ToDictionary(x => x.Id);
        var signals = FindAllSignals(eulynxSystem)
            .Concat(FindAllSignals(simulation))
            .ToDictionary(x => x.Signal.Id, x => (x.Hierarchy.Last(), x.Signal));
        var s = signals.Single(x => x.Value.Signal.Id == "_d803971d-349b-416b-954b-4a23407817d3");
        var enumerations = dataTypes.Where(x => x.Value.Type == "uml:Enumeration")
            .Select(x => new GlobalEnumeration(x.Value))
            .ToDictionary(x => x.Name);

        GlobalContext = new GlobalContext(enumerations, signals, dataTypes, changeEvents, timeEvents, genericEvents);
        _classWhitelist = classWhitelist;
        _classBlacklist = classBlacklist;
    }

    public List<Package> ParsePackages() {
        return InterestingPackages
            .Select(x => Package.CreateFromUml(x, GlobalContext, _classWhitelist, _classBlacklist))
            .ToList();
    }

    public static IEnumerable<PackagedElement> FindAllClasses(PackagedElement package) {
        return FindAllElements(package, "uml:Class").Select(x => x.Element);
    }

    public static IEnumerable<PackagedElement> FindAllEvents(PackagedElement package) {
        return FindAllElements(package, "uml:SignalEvent").Select(x => x.Element);
    }

    public static IEnumerable<(PackagedElement Signal, List<PackagedElement> Hierarchy)> FindAllSignals(PackagedElement package) {
        return FindAllElements(package, "uml:Signal");
    }

    public static IEnumerable<PackagedElement> FindAllDataTypes(PackagedElement package) {
        return FindAllElements(package, "uml:DataType").Select(x => x.Element);
    }

    public static IEnumerable<PackagedElement> FindAllEnumerations(PackagedElement package) {
        return FindAllElements(package, "uml:Enumeration").Select(x => x.Element);
    }

    public static IEnumerable<(PackagedElement Element, List<PackagedElement> Hierarchy)> FindAllElements(PackagedElement package, string umlType) {
        var elements = package.PackagedElements
            .Where(x => x.Type == umlType)
            .Select(x => (x, new List<PackagedElement> { package }));
        var subpackages = package.PackagedElements.Where(x => x.Type == "uml:Package");
        return elements.Concat(subpackages.SelectMany(x => FindAllElements(x, umlType).Select(x => (x.Element, new List<PackagedElement> { package }.Concat(x.Hierarchy).ToList()))));
    }
}
