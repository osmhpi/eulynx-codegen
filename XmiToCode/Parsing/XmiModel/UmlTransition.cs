using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
    [XmlRoot(ElementName="transition")]
    public class UmlTransition {
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

}
#nullable restore annotations
