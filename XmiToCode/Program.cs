using System.Xml.Serialization;
using XmiToCode;


// Test if input arguments were supplied.
if (args.Length == 0)
{
    Console.WriteLine("Please enter the programming language to generate: CSharp, C or Rust.");
    Console.WriteLine("Usage: XmiToCode <language>");
    return 1;
}

if (!Enum.TryParse<TargetLanguage>(args[0], out var targetLanguage)) {
    Console.WriteLine("Please enter the programming language to generate: CSharp, C or Rust.");
    Console.WriteLine("Usage: XmiToCode <language>");
    return 1;
}

using var inFile = File.OpenRead("../cleaned_23.xmi");

var xmlSerializer = new XmlSerializer(typeof(XMI), "");
var xmi = xmlSerializer.Deserialize(inFile) as XMI;


if (xmi == null) {
    throw new Exception("Could not deserialize input");
}

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
// packageWhitelist = new [] { "Subsystem Point", "Generic requirements for SCI", "Generic requirements for subsystems"};

var interestingPackages = eulynxSystem.PackagedElements
    .Where(x => !packageWhitelist.Any() || packageWhitelist.Contains(x.Name))
    .ToList();

var changeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:ChangeEvent").ToDictionary(x => x.Id);
var timeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:TimeEvent").ToDictionary(x => x.Id);
var signals = FindAllSignals(eulynxSystem).ToDictionary(x => x.Id);

var classWhitelist = new string[] {};
// classWhitelist = new [] {
//     // "F_Control_Point_Machine_Position",
//     // "S_SCI_P_Command_And_Recieve",
//     "S_SCI_EfeS_Prim",
//     // "S_SCI_Adj_Prim"
//     "F_EST_EfeS"
// };

var classBlacklist = new string[] {
    // seem to cause endless loops
    "F_Observe_Overall_Point_Position",
    "F_SCI_TDS_Report_TVPS",

    // Demo data
    "Block1"
};

var typeAliases = new Dictionary<(string, string), (string, string)>() {
    { ("D50inPdiConnectionStateValue", ""), ("SSciEfesPrim.D50outPdiConnectionStateValue", "") }
};

var csharp = new CSharpWriter();
var rust = new RustWriter();
var c = new KleeWriter();

// var whitelist = new [] {"ResetReason", "CloseReason", "AbilityToMoveState", "PointPositionState", "PointPositionDegradedState"};
var enumerations = dataTypes.Where(x => x.Value.Type == "uml:Enumeration")
    .Select(x => new GlobalEnumeration(x.Value))
    // There are two enumerations which map to the same name (but are not used currently)
    // - Line Direction Control Information
    // - Line_Direction_Control_Information
    // This behavior is dangerous...
    // Temporary workaround:
    .Where(x => x.Name.Name != "LineDirectionControlInformation")
    .ToList();

var global = new GlobalContext(enumerations);

var successful = new List<string>();
var all = 0;
var modelIssues = 0;

foreach (var interestingPackage in interestingPackages) {
    var packageEvents = FindAllEvents(interestingPackage).Concat(genericEvents).ToDictionary(x => x.Id);

    foreach (var umlClassPackage in FindAllClassesWithStateMachines(interestingPackage)
        .Where(x => !classWhitelist.Any() || classWhitelist.Contains(x.Name))
        .Where(x => !classBlacklist.Contains(x.Name))) {
        Console.Write($"Writing {umlClassPackage.Name}...");
        all++;

        try {
            var properties = umlClassPackage.OwnedAttribute
                .Where(x => x.XmiType == "uml:Property")
                .ToList();
            var ports = umlClassPackage.OwnedAttribute
                .Where(x => x.XmiType == "uml:Port")
                .ToList();
            var operationNames = umlClassPackage.OwnedOperation
                .Where(x => x.XmiType == "uml:Operation")
                .Select(x => new Identifier(x.Name))
                .ToList();

            var className = new TypeIdentifier(umlClassPackage.Name);
            // HACK
            var classInfo = new ClassInfo(className.Name, "");
            var dth = new DataTypeHelper(properties, ports, operationNames, changeEvents, timeEvents, packageEvents, signals, dataTypes, typeAliases, classInfo);
            var classContext = new ClassContext(global, dth);

            var operations = umlClassPackage.OwnedOperation
                .Where(x => x.XmiType == "uml:Operation")
                .Select(x => (x, umlClassPackage.OwnedBehavior.Single(behavior => behavior.Id == x.Method)))
                .Select(x => new Operation(x.x, x.Item2, Operation.ParseInstructions(x.Item2, classContext)))
                .ToList();

            var umlClass = new UmlClass(umlClassPackage, changeEvents, timeEvents, packageEvents, signals, dth, classContext);
            await umlClass.Generate(targetLanguage switch {
                TargetLanguage.CSharp => csharp,
                TargetLanguage.C => c,
                TargetLanguage.Rust => rust,
                _ => throw new NotImplementedException()
            }, classContext, operations);

            successful.Add(className.Name);
            Console.WriteLine(" done.");
        } catch (ModelException ex) {
            Console.WriteLine($" failed due to model issue: ({ex.Message})");
            modelIssues++;
        } catch (Exception ex) {
            Console.WriteLine($" failed: ({ex.Message})");
        }
    }
}

Console.WriteLine($"Successfully generated {successful.Count} out of {all} ({all-modelIssues} valid) classes:");
foreach (var success in successful)
    Console.WriteLine($" - {success}");

return 0;

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
