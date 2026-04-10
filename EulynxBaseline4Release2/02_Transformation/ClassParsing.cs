using XmiToCode.Parsing;
using XmiToCode.Parsing.Model;

namespace Eulynx.Validation;

[TestClass]
public class ClassParsing
{
    public const string EULYNX_XMI_FILE = "cleaned.xmi";
    public static IEnumerable<object[]> UmlClasses
    {
        get
        {
            var processor = new EulynxV22XmiParser(EULYNX_XMI_FILE);
            foreach (var package in processor.InterestingPackages) {
                var classes = Package.ClassElements(package);
                foreach (var (Element, _) in classes)
                    yield return new object[] { package.Name, Element.Name };
            }
        }
    }

    [TestMethod, TestCategory("parse-classes")]
    [DynamicData(nameof(UmlClasses))]
    public void ParseClass(string package, string className)
    {
        var processor = new EulynxV22XmiParser(EULYNX_XMI_FILE);
        var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
        var pkg = Package.CreateFromUml(umlPackage, processor.GlobalContext);
        var (Element, Hierarchy) = pkg.ClassElements().Single(x => x.Element.Name == className);
        // Assert that this doesn't throw
        Package.ParseClass(Element, pkg.Context, Hierarchy);
    }
}
