using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{

    [XmlRoot(ElementName="XMI", Namespace="http://www.omg.org/spec/XMI/20110701")]
    public class XMI {
        [XmlElement(ElementName="documentation")]
        public Documentation Documentation { get; set; }
        [XmlElement(ElementName="Model", Namespace="http://www.omg.org/spec/UML/20110701")]
        public Model Model { get; set; }
        [XmlAttribute(AttributeName="xmi", Namespace="http://www.w3.org/2000/xmlns/")]
        public string Xmi { get; set; }
        [XmlAttribute(AttributeName="uml", Namespace="http://www.w3.org/2000/xmlns/")]
        public string Uml { get; set; }
        [XmlAttribute(AttributeName="sysml", Namespace="http://www.w3.org/2000/xmlns/")]
        public string Sysml { get; set; }
        [XmlAttribute(AttributeName="StandardProfileL2", Namespace="http://www.w3.org/2000/xmlns/")]
        public string StandardProfileL2 { get; set; }
    }

}
#nullable restore annotations
