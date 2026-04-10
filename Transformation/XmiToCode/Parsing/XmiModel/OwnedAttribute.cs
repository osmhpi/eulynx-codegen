using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
    [XmlRoot(ElementName="ownedAttribute")]
    public class OwnedAttribute : IAttributeOrParameter {
        [XmlAttribute(AttributeName="type", Namespace="")]
        public string Type { get; set; }

        [XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string XmiType { get; set; }
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

}
#nullable restore annotations
