using System.Xml.Serialization;

namespace XmiToCode
{
  [XmlRoot(ElementName="documentation")]
	public class Documentation {
		[XmlElement(ElementName="exporter")]
		public string Exporter { get; set; }
		[XmlElement(ElementName="exporterVersion")]
		public string ExporterVersion { get; set; }
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
	}

	[XmlRoot(ElementName="ownedAttribute")]
	public class OwnedAttribute {
		[XmlElement(ElementName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public List<string> Type { get; set; }
		// [XmlElement(ElementName="type", Namespace="")]
		// public List<string> Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="name")]
		public string Name { get; set; }
		[XmlAttribute(AttributeName="visibility")]
		public string Visibility { get; set; }
		[XmlAttribute(AttributeName="aggregation")]
		public string Aggregation { get; set; }
		[XmlAttribute(AttributeName="association")]
		public string Association { get; set; }
		[XmlElement(ElementName="ownedComment")]
		public OwnedComment OwnedComment { get; set; }
		[XmlAttribute(AttributeName="isConjugated")]
		public string IsConjugated { get; set; }
	}

	[XmlRoot(ElementName="end")]
	public class End {
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="partWithPort")]
		public string PartWithPort { get; set; }
		[XmlAttribute(AttributeName="role")]
		public string Role { get; set; }
	}

	[XmlRoot(ElementName="ownedConnector")]
	public class OwnedConnector {
		[XmlElement(ElementName="end")]
		public List<End> End { get; set; }
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="name")]
		public string Name { get; set; }
	}

	[XmlRoot(ElementName="packagedElement")]
	public class PackagedElement {
		[XmlElement(ElementName="ownedAttribute")]
		public List<OwnedAttribute> OwnedAttribute { get; set; }
		[XmlElement(ElementName="ownedConnector")]
		public List<OwnedConnector> OwnedConnector { get; set; }
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="name")]
		public string Name { get; set; }
		[XmlElement(ElementName="ownedBehavior")]
		public OwnedBehavior OwnedBehavior { get; set; }
		[XmlElement(ElementName="ownedEnd")]
		public OwnedEnd OwnedEnd { get; set; }
		[XmlAttribute(AttributeName="memberEnd")]
		public string MemberEnd { get; set; }
		[XmlElement(ElementName="packagedElement", Namespace = "")]
		public List<PackagedElement> PackagedElements { get; set; }
		[XmlAttribute(AttributeName="operation")]
		public string Operation { get; set; }
		[XmlElement(ElementName="changeExpression")]
		public ChangeExpression ChangeExpression { get; set; }
    [XmlElement(ElementName="when")]
		public When When { get; set; }
	}

	[XmlRoot(ElementName="expr")]
	public class Expr {
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="body")]
		public string Body { get; set; }
	}

	[XmlRoot(ElementName="when")]
	public class When {
		[XmlElement(ElementName="expr")]
		public Expr Expr { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
	}

	[XmlRoot(ElementName="changeExpression")]
	public class ChangeExpression {
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="body")]
		public string Body { get; set; }
	}

	[XmlRoot(ElementName="ownedComment")]
	public class OwnedComment {
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="body")]
		public string Body { get; set; }
	}

	[XmlRoot(ElementName="subvertex")]
	public class Subvertex {
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="kind")]
		public string Kind { get; set; }
		[XmlAttribute(AttributeName="name")]
		public string Name { get; set; }
		[XmlElement(ElementName="ownedRule")]
		public List<OwnedRule> OwnedRule { get; set; }
    [XmlElement(ElementName = "entry")]
    public Subvertex Entry { get; set; }
    [XmlElement(ElementName="region")]
    public List<Region> Regions { get; set; }
	}

	[XmlRoot(ElementName="transition")]
	public class Transition {
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="source")]
		public string Source { get; set; }
		[XmlAttribute(AttributeName="target")]
		public string Target { get; set; }
		[XmlElement(ElementName="trigger")]
		public Trigger Trigger { get; set; }
		[XmlElement(ElementName="ownedRule")]
		public OwnedRule OwnedRule { get; set; }
		[XmlElement(ElementName="effect")]
		public Effect Effect { get; set; }
		[XmlAttribute(AttributeName="kind")]
		public string Kind { get; set; }
	}

	[XmlRoot(ElementName="trigger")]
	public class Trigger {
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="event")]
		public string Event { get; set; }
	}

	[XmlRoot(ElementName="effect")]
	public class Effect {
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="body")]
		public string Body { get; set; }
	}

	[XmlRoot(ElementName="region")]
	public class Region {
		[XmlElement(ElementName="subvertex")]
		public List<Subvertex> Subvertices { get; set; }
		[XmlElement(ElementName="transition")]
		public List<Transition> Transition { get; set; }
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
	}

	[XmlRoot(ElementName="ownedBehavior")]
	public class OwnedBehavior {
		[XmlElement(ElementName="region")]
		public Region Region { get; set; }
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="name")]
		public string Name { get; set; }
	}

	[XmlRoot(ElementName="ownedEnd")]
	public class OwnedEnd {
		[XmlElement(ElementName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public List<string> Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="visibility")]
		public string Visibility { get; set; }
		[XmlAttribute(AttributeName="association")]
		public string Association { get; set; }
	}

	[XmlRoot(ElementName="specification")]
	public class Specification {
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="body")]
		public string Body { get; set; }
	}

	[XmlRoot(ElementName="ownedRule")]
	public class OwnedRule {
		[XmlElement(ElementName="specification")]
		public Specification Specification { get; set; }
		[XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Type { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
		[XmlAttribute(AttributeName="name")]
		public string Name { get; set; }
		[XmlAttribute(AttributeName="constrainedElement")]
		public string ConstrainedElement { get; set; }
	}

	[XmlRoot(ElementName="Model", Namespace="http://www.omg.org/spec/UML/20110701")]
	public class Model {
		[XmlElement(ElementName="packagedElement", Namespace = "")]
		public List<PackagedElement> PackagedElements { get; set; }
		[XmlAttribute(AttributeName="name")]
		public string Name { get; set; }
		[XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
		public string Id { get; set; }
	}

	[XmlRoot(ElementName="XMI", Namespace="http://www.omg.org/spec/XMI/20110701")]
	public class XMI {
		[XmlElement(ElementName="documentation")]
		public Documentation Documentation { get; set; }
		[XmlElement(ElementName="Model", Namespace="http://www.omg.org/spec/UML/20110701")]
		public Model Model { get; set; }
		[XmlAttribute(AttributeName="xmi", Namespace="http://www.w3.org/2000/xmlns/")]
		public string Xmi { get; set; }
		[XmlAttribute(AttributeName="uml", Namespace="http://www.w3.org/2000/xmlns/")]
		public string Uml { get; set; }
		[XmlAttribute(AttributeName="sysml", Namespace="http://www.w3.org/2000/xmlns/")]
		public string Sysml { get; set; }
		[XmlAttribute(AttributeName="StandardProfileL2", Namespace="http://www.w3.org/2000/xmlns/")]
		public string StandardProfileL2 { get; set; }
	}

}

