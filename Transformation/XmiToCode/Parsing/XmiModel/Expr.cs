using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
    [XmlRoot(ElementName="expr")]
    public class Expr {
        [XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string Id { get; set; }
        [XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string Type { get; set; }
        [XmlAttribute(AttributeName="body")]
        public string Body { get; set; }
    }

}
#nullable restore annotations
