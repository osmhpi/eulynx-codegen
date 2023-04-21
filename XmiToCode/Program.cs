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

var eulynxSystem = packages.Single(x => x.Name == "EULYNX System");
var genericFunctions = packages.Single(x => x.Name == "Generic Functions");

var genericEvents = FindAllEvents(genericFunctions).ToList();

var packageWhitelist = new [] { "Subsystem Point", "Generic requirements for SCI" };

var interestingPackages = eulynxSystem.PackagedElements
    .Where(x => !packageWhitelist.Any() || packageWhitelist.Contains(x.Name));

var changeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:ChangeEvent").ToDictionary(x => x.Id);
var timeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:TimeEvent").ToDictionary(x => x.Id);

var classWhitelist = new [] { "F_Control_Point_Machine_Position", "S_SCI_P_Command_And_Recieve", "S_SCI_Adj_Prim" };
// var classWhitelist = new List<string>();

var typeAliases = new Dictionary<string, string>() {
    { "D50inPdiConnectionState", "SSciAdjPrim.D50outPdiConnectionStateValue" }
};

foreach (var interestingPackage in interestingPackages) {
    // var eventsSubpackage = interestingPackage.PackagedElements.SingleOrDefault(x => x.Name == "Events");
    // Dictionary<string, PackagedElement> packageEvents = new Dictionary<string, PackagedElement>();
    // if (eventsSubpackage != null) {
    //     packageEvents = eventsSubpackage.PackagedElements.Where(x => x.Type == "uml:SignalEvent").ToDictionary(x => x.Id);
    // }
    var packageEvents = FindAllEvents(interestingPackage).Concat(genericEvents).ToDictionary(x => x.Id);

    foreach (var umlClassPackage in FindAllClasses(interestingPackage).Where(x => !classWhitelist.Any() || classWhitelist.Contains(x.Name))) {
        var umlClass = new UmlClass(umlClassPackage, changeEvents, timeEvents, packageEvents, typeAliases);
        await umlClass.Generate();
    }
}

static IEnumerable<PackagedElement> FindAllClasses(PackagedElement package) {
    var classes = package.PackagedElements
        .Where(x => x.Type == "uml:Class")
        .Where(x => x.StateMachine != null);
    var subpackages = package.PackagedElements.Where(x => x.Type == "uml:Package");
    return classes.Concat(subpackages.SelectMany(FindAllClasses));
}

static IEnumerable<PackagedElement> FindAllEvents(PackagedElement package) {
    var events = package.PackagedElements
        .Where(x => x.Type == "uml:SignalEvent");
    var subpackages = package.PackagedElements.Where(x => x.Type == "uml:Package");
    return events.Concat(subpackages.SelectMany(x => FindAllEvents(x)));
}
