using System.Xml.Serialization;
using XmiToCode;
using XmiToCode.Classes;
using XmiToCode.Codegen;
using XmiToCode.Codegen.C;
using XmiToCode.Codegen.CSharp;
using XmiToCode.Codegen.Rust;
using XmiToCode.Context;

// Test if input arguments were supplied.
if (args.Length == 0 || !Enum.TryParse<TargetLanguage>(args[0], out var targetLanguage))
{
    Console.WriteLine("Please enter the programming language to generate: CSharp, C or Rust.");
    Console.WriteLine("Usage: XmiToCode <language>");
    return 1;
}

using var inFile = File.OpenRead("../cleaned_23.xmi");

var xmlSerializer = new XmlSerializer(typeof(XMI), "");
var xmi = xmlSerializer.Deserialize(inFile) as XMI ?? throw new Exception("Could not deserialize input");

// This only selects top-level packages
var packages = xmi.Model.PackagedElements.Where(x => x.Type == "uml:Package").ToList();

var sysimProfile = xmi.Model.PackagedElements
    .Single(x => x.Type == "uml:Profile" && x.Name == "SySim Profile");
var eulynxProfile = xmi.Model.PackagedElements
    .Single(x => x.Type == "uml:Package" && x.Name == "EULYNX_Profile");

var eulynxSystem = packages.Single(x => x.Name == "EULYNX System");

var genericEvents = new List<PackagedElement>();

// v19
var genericFunctions = packages.SingleOrDefault(x => x.Name == "Generic Functions");
if (genericFunctions != null) {
    genericEvents = FindAllEvents(genericFunctions).ToList();
}

// v23
var collectionOfSignalEvents = packages.SingleOrDefault(x => x.Name == "Collection of signal events");
if (collectionOfSignalEvents != null) {
    // Collection of signal events
    // Internal subsystem events
    genericEvents = FindAllEvents(collectionOfSignalEvents).ToList();
}

var dataTypes = FindAllDataTypes(sysimProfile)
    .Concat(FindAllDataTypes(eulynxProfile))
    .Concat(FindAllClasses(eulynxSystem))
    .Concat(FindAllEnumerations(eulynxSystem))
    // TODO: Shouldn't this be x.Name? Then, we start to have duplicates, which is a problem later on anyways
    .ToDictionary(x => x.Id);

var packageWhitelist = new string[] {};
packageWhitelist = new [] {
    "Generic requirements for SCI",
    "Generic requirements for subsystems",
    "Subsystem Point",
    "Subsystem IO",
    "Subsystem Light Signal",
    "Subsystem Level Crossing",
    "Subsystem Train Detection System",
};
var packageBlacklist = new string[] {
    "Generic recycle bin",
};

var interestingPackages = eulynxSystem.PackagedElements
    .Where(x => !packageWhitelist.Any() || packageWhitelist.Contains(x.Name))
    .Where(x => !packageBlacklist.Contains(x.Name))
    .ToList();

var changeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:ChangeEvent").ToDictionary(x => x.Id);
var timeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:TimeEvent").ToDictionary(x => x.Id);
var signals = FindAllSignals(eulynxSystem).ToDictionary(x => x.Signal.Id, x => (x.Hierarchy.Last(), x.Signal));

var classWhitelist = new string[] {};
classWhitelist = new [] {
    // "F_Control_Point_Machine_Position",
    // "S_SCI_P_Command_And_Recieve",
    // "S_SCI_EfeS_Prim",
    // "S_SCI_Adj_Prim"
    // "F_EST_EfeS",
    "F_SCI_EfeS_Sec"
};

var classBlacklist = new string[] {
    // Demo data
    // "Block1"
};

var typeAliases = new Dictionary<(string, string), (string, string)>() {
    { ("D50inPdiConnectionStateValue", ""), ("SSciEfesPrim.D50outPdiConnectionStateValue", "") }
};

var csharp = new CSharpWriter();
var rust = new RustWriter();
var c = new CWriter();

var enumerations = dataTypes.Where(x => x.Value.Type == "uml:Enumeration")
    .Select(x => new GlobalEnumeration(x.Value))
    .ToDictionary(x => x.Name);

var global = new GlobalContext(enumerations, signals, dataTypes, changeEvents, timeEvents, genericEvents);
var parsedPackages = interestingPackages.Select(x => Package.CreateFromUml(x, global)).ToList();

ICodeWriter writer = targetLanguage switch {
    TargetLanguage.CSharp => csharp,
    TargetLanguage.C => c,
    TargetLanguage.Rust => rust,
    _ => throw new NotImplementedException()
};

await writer.WriteCommonFilesAsync(global);

foreach (var package in parsedPackages) {
    await writer.WritePackageFilesAsync(package);
}

return 0;

static IEnumerable<PackagedElement> FindAllClasses(PackagedElement package) {
    return FindAllElements(package, "uml:Class").Select(x => x.Element);
}

static IEnumerable<PackagedElement> FindAllEvents(PackagedElement package) {
    return FindAllElements(package, "uml:SignalEvent").Select(x => x.Element);
}

static IEnumerable<(PackagedElement Signal, List<PackagedElement> Hierarchy)> FindAllSignals(PackagedElement package) {
    return FindAllElements(package, "uml:Signal");
}

static IEnumerable<PackagedElement> FindAllDataTypes(PackagedElement package) {
    return FindAllElements(package, "uml:DataType").Select(x => x.Element);
}

static IEnumerable<PackagedElement> FindAllEnumerations(PackagedElement package) {
    return FindAllElements(package, "uml:Enumeration").Select(x => x.Element);
}

static IEnumerable<(PackagedElement Element, List<PackagedElement> Hierarchy)> FindAllElements(PackagedElement package, string umlType) {
    var elements = package.PackagedElements
        .Where(x => x.Type == umlType)
        .Select(x => (x, new List<PackagedElement> { package }));
    var subpackages = package.PackagedElements.Where(x => x.Type == "uml:Package");
    return elements.Concat(subpackages.SelectMany(x => FindAllElements(x, umlType).Select(x => (x.Element, new List<PackagedElement> { package }.Concat(x.Hierarchy).ToList()))));
}
