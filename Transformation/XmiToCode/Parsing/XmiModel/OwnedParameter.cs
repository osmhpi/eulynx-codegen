using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
    [XmlRoot(ElementName="ownedParameter")]
    public class OwnedParameter : IAttributeOrParameter {
        [XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string XmiType { get; set; }
        [XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string Id { get; set; }
        [XmlAttribute(AttributeName="name")]
        public string Name { get; set; }
        [XmlAttribute(AttributeName="type")]
        public string Type { get; set; }
    }
}
#nullable restore annotations
