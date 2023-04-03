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
var subsystemPoint = eulynxSystem.PackagedElements.Single(x => x.Name == "Subsystem Point");
var requirements = subsystemPoint.PackagedElements.Single(x => x.Name == "Functional requirements specification");
var functionalViewpoint = requirements.PackagedElements.Single(x => x.Name == "Subsystem Point - Functional Viewpoint");
var entities = functionalViewpoint.PackagedElements.Single(x => x.Name == "Subsystem Point - Functional Entities");
var fControlPointPosition = entities.PackagedElements.Single(x => x.Name == "F_Control_Point_Machine_Position");

var changeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:ChangeEvent").ToDictionary(x => x.Id);
var timeEvents = xmi.Model.PackagedElements.Where(x => x.Type == "uml:TimeEvent").ToDictionary(x => x.Id);

var theClass = new UmlClass(fControlPointPosition, changeEvents, timeEvents);
await theClass.Generate();

Console.WriteLine("Done.");
