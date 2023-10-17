using XmiToCode;
using XmiToCode.Classes;

namespace Eulynx.Validation;

[TestClass]
public class ClassParsing
{
    public static IEnumerable<object[]> UmlClasses
    {
        get
        {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");

            var processor = new XmiProcessor(xmiPath);
            foreach (var package in processor.InterestingPackages) {
                var classes = Package.ClassNames(package);
                foreach (var theClass in classes)
                    yield return new object[] { package.Name, theClass.Element.Name };
            }
        }
    }

    [TestMethod]
    [DynamicData(nameof(UmlClasses))]
    public void ParseClass(string package, string className)
    {
        var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
        var processor = new XmiProcessor(xmiPath);
        var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
        var pkg = Package.CreateFromUml(umlPackage, processor.Global);
        var (Element, Hierarchy) = Package.ClassNames(pkg.UmlPackage).Single(x => x.Element.Name == className);
        // Assert that this doesn't throw
        Package.ParseClass(Element, processor.Global, pkg.Context, pkg.Events, pkg.UmlPackage, Hierarchy);
    }
}
