using System.Xml;


using var infile = File.OpenRead("EULYNX System BL4 v19 - BL4.xmi");

var xmldoc = new XmlDocument();
var settings = new XmlReaderSettings { NameTable = new NameTable() };
var xmlns = new XmlNamespaceManager(settings.NameTable);
// Fake missing namespace declarations
xmlns.AddNamespace("VB_Profile", "http://ptc.org/VB_Profile");
xmlns.AddNamespace("SySim_Profile", "http://ptc.org/SySim_Profile");
xmlns.AddNamespace("ACS_Profile", "http://ptc.org/ACS_Profile");
var context = new XmlParserContext(null, xmlns, "", XmlSpace.Default);
var reader = XmlReader.Create(infile, settings, context);
xmldoc.Load(reader);

var stateMachines = xmldoc.SelectNodes("//ownedBehavior")
  .OfType<XmlNode>().Where(x => x.Attributes["xmi:type"].Value == "uml:StateMachine");
foreach (var node in stateMachines)
{
  Console.WriteLine(node.Attributes["name"].Value);
  var smc = new StateMachineCreator(node);
  smc.Create();
}

Console.WriteLine("Done.");



class StateMachineCreator
{
  private XmlNode _node;

  public StateMachineCreator(XmlNode node)
  {
    _node = node;
  }

  public void Create() {
    foreach (var region in _node.SelectNodes("region").OfType<XmlNode>()) {
      foreach (var element in region.ChildNodes.OfType<XmlNode>()) {
        var type = element.Attributes["xmi:type"].Value;
        var _ = type switch {
          "uml:State" => ParseState(element),
          "uml:Pseudostate" => ParseState(element),
          "uml:FinalState" => ParseState(element),
          "uml:Transition" => ParseTransition(element)
        };
      }
    }
  }

  private string ParseTransition(XmlNode e)
  {
    Console.WriteLine(e.Name);
    return "";
  }

  private string ParseState(XmlNode element)
  {
    Console.WriteLine(element.Name);
    return "";
  }
}
