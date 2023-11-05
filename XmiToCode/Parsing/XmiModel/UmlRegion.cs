using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
    [XmlRoot(ElementName="region")]
    public class UmlRegion {
        [XmlElement(ElementName="subvertex")]
        public List<UmlSubvertex> Subvertices { get; set; }
        [XmlElement(ElementName="transition")]
        public List<UmlTransition> Transitions { get; set; }
        [XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string Type { get; set; }
        [XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string Id { get; set; }
    }

}
#nullable restore annotations
