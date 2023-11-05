using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
    [XmlRoot(ElementName="packagedElement")]
    public class PackagedElement {
        public OwnedBehavior StateMachine => OwnedBehavior.SingleOrDefault(x => x.Type == "uml:StateMachine");

        [XmlElement(ElementName="ownedAttribute")]
        public List<OwnedAttribute> OwnedAttribute { get; set; }

        [XmlElement(ElementName="ownedOperation")]
        public List<OwnedOperation> OwnedOperation { get; set; }
        [XmlElement(ElementName="ownedConnector")]
        public List<OwnedConnector> OwnedConnector { get; set; }
        [XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string Type { get; set; }
        [XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string Id { get; set; }
        [XmlAttribute(AttributeName="name")]
        public string Name { get; set; }
        [XmlElement(ElementName="ownedBehavior")]
        public List<OwnedBehavior> OwnedBehavior { get; set; }
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
        [XmlAttribute(AttributeName="signal")]
        public string Signal { get; set; }
        [XmlElement(ElementName="ownedReception")]
        public List<OwnedReception> OwnedReception { get; set; }
        [XmlElement(ElementName="ownedLiteral")]
        public List<OwnedLiteral> OwnedLiteral { get; set; }

    }

}
#nullable restore annotations
