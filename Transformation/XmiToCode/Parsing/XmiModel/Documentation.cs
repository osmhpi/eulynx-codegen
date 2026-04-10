using System.Xml.Serialization;
#nullable disable annotations

namespace XmiToCode.Parsing.XmiModel
{
    [XmlRoot(ElementName="documentation")]
    public class Documentation {
        [XmlElement(ElementName="exporter")]
        public string Exporter { get; set; }
        [XmlElement(ElementName="exporterVersion")]
        public string ExporterVersion { get; set; }
        [XmlAttribute(AttributeName="type", Namespace="http://www.omg.org/spec/XMI/20110701")]
        public string Type { get; set; }
    }

}
#nullable restore annotations
