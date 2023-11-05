using XmiToCode;
using XmiToCode.Classes;
using XmiToCode.Parsing;

namespace Eulynx.Validation;

[TestClass]
public class ClassParsing
{
    public static IEnumerable<object[]> UmlClasses
    {
        get
        {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");

            var processor = new EulynxV22XmiParser(xmiPath);
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
        var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
        var processor = new EulynxV22XmiParser(xmiPath);
        var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
        var pkg = Package.CreateFromUml(umlPackage, processor.GlobalContext);
        var (Element, Hierarchy) = pkg.ClassElements().Single(x => x.Element.Name == className);
        // Assert that this doesn't throw
        Package.ParseClass(Element, processor.GlobalContext, pkg.Context, pkg.Events, pkg.Context.UmlPackage, Hierarchy);
    }
}
