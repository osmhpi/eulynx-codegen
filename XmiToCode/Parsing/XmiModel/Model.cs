using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
    [XmlRoot(ElementName="Model", Namespace="http://www.omg.org/spec/UML/20110701")]
    public class Model {
        [XmlElement(ElementName="packagedElement", Namespace = "")]
        public List<PackagedElement> PackagedElements { get; set; }
        [XmlAttribute(AttributeName="name")]
        public string Name { get; set; }
        [XmlAttribute(AttributeName="id", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string Id { get; set; }
    }

}
#nullable restore annotations
