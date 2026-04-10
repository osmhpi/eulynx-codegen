using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
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

}
#nullable restore annotations
