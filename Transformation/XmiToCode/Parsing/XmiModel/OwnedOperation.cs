using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
    [XmlRoot(ElementName="ownedOperation")]
    public class OwnedOperation {

        [XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string XmiType { get; set; }
        [XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string Id { get; set; }
        [XmlAttribute(AttributeName="name")]
        public string Name { get; set; }
        [XmlAttribute(AttributeName="visibility")]
        public string Visibility { get; set; }
        [XmlAttribute(AttributeName="method")]
        public string Method { get; set; }
        [XmlElement(ElementName="ownedComment")]
        public OwnedComment OwnedComment { get; set; }
    }

}
#nullable restore annotations
