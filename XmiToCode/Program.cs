using System.Xml.Serialization;
using XmiToCode;

using var infile = File.OpenRead("../cleaned.xmi");

var xmlSerializer = new XmlSerializer(typeof(XMI), "");
var xmi = xmlSerializer.Deserialize(infile) as XMI;

var packages = xmi.Model.PackagedElements.Where(x => x.Type == "uml:Package").ToList();
// foreach (var package in packages) {
//   Console.WriteLine(package.Name);
// }

var eulynxSystem = packages.Single(x => x.Name == "EULYNX System");

var interestingPackages = eulynxSystem.PackagedElements
    .Where(x => x.Name == "Subsystem Point");

var changeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:ChangeEvent").ToDictionary(x => x.Id);
var timeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:TimeEvent").ToDictionary(x => x.Id);

foreach (var umlClassPackage in interestingPackages.SelectMany(FindAllClasses)) {
    var umlClass = new UmlClass(umlClassPackage, changeEvents, timeEvents);
    await umlClass.Generate();
}

static IEnumerable<PackagedElement> FindAllClasses(PackagedElement package) {
    var classes = package.PackagedElements
        .Where(x => x.Type == "uml:Class")
        .Where(x => x.StateMachine != null);
    var subpackages = package.PackagedElements.Where(x => x.Type == "uml:Package");
    return classes.Concat(subpackages.SelectMany(FindAllClasses));
}
