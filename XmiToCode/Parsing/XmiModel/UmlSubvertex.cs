using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
    [XmlRoot(ElementName="subvertex")]
    public class UmlSubvertex {
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
        public UmlSubvertex Entry { get; set; }
        [XmlElement(ElementName = "exit")]
        public UmlSubvertex Exit { get; set; }
        [XmlElement(ElementName="region")]
        public List<UmlRegion> Regions { get; set; }
    }

}
#nullable restore annotations
