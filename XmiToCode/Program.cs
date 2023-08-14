using System.Xml.Serialization;
using XmiToCode;

using var inFile = File.OpenRead("../cleaned.xmi");

var xmlSerializer = new XmlSerializer(typeof(XMI), "");
var xmi = xmlSerializer.Deserialize(inFile) as XMI;

if (xmi == null) {
    throw new Exception("Could not deserialize input");
}

var packages = xmi.Model.PackagedElements.Where(x => x.Type == "uml:Package").ToList();
// foreach (var package in packages) {
//   Console.WriteLine(package.Name);
// }

var sysimProfile = xmi.Model.PackagedElements
    .Single(x => x.Type == "uml:Profile" && x.Name == "SySim Profile");
var eulynxProfile = xmi.Model.PackagedElements
    .Single(x => x.Type == "uml:Package" && x.Name == "EULYNX_Profile");

var eulynxSystem = packages.Single(x => x.Name == "EULYNX System");
var genericFunctions = packages.Single(x => x.Name == "Generic Functions");

var genericEvents = FindAllEvents(genericFunctions).ToList();

var dataTypes = FindAllDataTypes(sysimProfile)
    .Concat(FindAllDataTypes(eulynxProfile))
    .Concat(FindAllClasses(eulynxSystem))
    .Concat(FindAllEnumerations(eulynxSystem))
    // TODO: Shouldn't this be x.Name? Then, we start to have duplicates, which is a problem later on anyways
    .ToDictionary(x => x.Id);

var packageWhitelist = new [] { "Subsystem Point", "Generic requirements for SCI" };

var interestingPackages = eulynxSystem.PackagedElements
    .Where(x => !packageWhitelist.Any() || packageWhitelist.Contains(x.Name));

var changeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:ChangeEvent").ToDictionary(x => x.Id);
var timeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:TimeEvent").ToDictionary(x => x.Id);
var signals = FindAllSignals(eulynxSystem).ToDictionary(x => x.Id);

var classWhitelist = new [] {
    // "F_Control_Point_Machine_Position",
    // "S_SCI_P_Command_And_Recieve",
    "S_SCI_EfeS_Prim",
    // "S_SCI_Adj_Prim"
};
// var classWhitelist = new List<string>();

var typeAliases = new Dictionary<(string, string), (string, string)>() {
    { ("D50inPdiConnectionStateValue", ""), ("SSciEfesPrim.D50outPdiConnectionStateValue", "") }
};

var csharp = new CSharpWriter();
var rust = new RustWriter();
var c = new CWriter();

foreach (var interestingPackage in interestingPackages) {
    // var eventsSubpackage = interestingPackage.PackagedElements.SingleOrDefault(x => x.Name == "Events");
    // Dictionary<string, PackagedElement> packageEvents = new Dictionary<string, PackagedElement>();
    // if (eventsSubpackage != null) {
    //     packageEvents = eventsSubpackage.PackagedElements.Where(x => x.Type == "uml:SignalEvent").ToDictionary(x => x.Id);
    // }
    var packageEvents = FindAllEvents(interestingPackage).Concat(genericEvents).ToDictionary(x => x.Id);

    foreach (var umlClassPackage in FindAllClassesWithStateMachines(interestingPackage).Where(x => !classWhitelist.Any() || classWhitelist.Contains(x.Name))) {
        var umlClass = new UmlClass(umlClassPackage, changeEvents, timeEvents, packageEvents, signals, dataTypes, typeAliases);
        try {
            await umlClass.Generate(c);
        } catch (Exception ex) {
            Console.WriteLine($"Could not generate class: {umlClass.GetName()} ({ex.Message})");
        }
    }
}

await DataTypeHelper.GenerateDataTypes(dataTypes);

static IEnumerable<PackagedElement> FindAllClasses(PackagedElement package) {
    return FindAllElements(package, "uml:Class");
}

static IEnumerable<PackagedElement> FindAllClassesWithStateMachines(PackagedElement package) {
    return FindAllClasses(package)
        .Where(x => x.StateMachine != null);
}

static IEnumerable<PackagedElement> FindAllEvents(PackagedElement package) {
    return FindAllElements(package, "uml:SignalEvent");
}

static IEnumerable<PackagedElement> FindAllSignals(PackagedElement package) {
    return FindAllElements(package, "uml:Signal");
}

static IEnumerable<PackagedElement> FindAllDataTypes(PackagedElement package) {
    return FindAllElements(package, "uml:DataType");
}

static IEnumerable<PackagedElement> FindAllEnumerations(PackagedElement package) {
    return FindAllElements(package, "uml:Enumeration");
}

static IEnumerable<PackagedElement> FindAllElements(PackagedElement package, string umlType) {
    var elements = package.PackagedElements
        .Where(x => x.Type == umlType);
    var subpackages = package.PackagedElements.Where(x => x.Type == "uml:Package");
    return elements.Concat(subpackages.SelectMany(x => FindAllElements(x, umlType)));
}
