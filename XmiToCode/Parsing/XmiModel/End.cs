using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
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

}
#nullable restore annotations
