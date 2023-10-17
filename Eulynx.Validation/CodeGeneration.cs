using XmiToCode;
using XmiToCode.Classes;
using XmiToCode.Codegen.C;
using XmiToCode.Codegen.CSharp;
using XmiToCode.Codegen.Rust;

namespace Eulynx.Validation;

[TestClass]
public class CodeGeneration
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
    public async Task GenerateC(string package, string className)
    {
        Package? pkg = null;
        Class? klass = null;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            var processor = new XmiProcessor(xmiPath);
            var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
            pkg = Package.CreateFromUml(umlPackage, processor.Global);
            var (Element, Hierarchy) = Package.ClassNames(pkg.UmlPackage).Single(x => x.Element.Name == className);
            klass = Package.ParseClass(Element, processor.Global, pkg.Context, pkg.Events, pkg.UmlPackage, Hierarchy);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var c = new CWriter();
        var packageDir = Path.Combine("../Eulynx/C/", pkg.Name.Name);
        await c.WriteClassFilesAsync(klass, packageDir);
    }

    [TestMethod]
    [DynamicData(nameof(UmlClasses))]
    public async Task GenerateRust(string package, string className)
    {
        Package? pkg = null;
        Class? klass = null;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            var processor = new XmiProcessor(xmiPath);
            var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
            pkg = Package.CreateFromUml(umlPackage, processor.Global);
            var (Element, Hierarchy) = Package.ClassNames(pkg.UmlPackage).Single(x => x.Element.Name == className);
            klass = Package.ParseClass(Element, processor.Global, pkg.Context, pkg.Events, pkg.UmlPackage, Hierarchy);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var outDir = new DirectoryInfo("../Eulynx/rust/src");
        if (!outDir.Exists) outDir.Create();

        var rust = new RustWriter();
        await rust.WriteClassFilesAsync(klass);
    }

    [TestMethod]
    [DynamicData(nameof(UmlClasses))]
    public async Task GenerateCSharp(string package, string className)
    {
        Package? pkg = null;
        Class? klass = null;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            var processor = new XmiProcessor(xmiPath);
            var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
            pkg = Package.CreateFromUml(umlPackage, processor.Global);
            var (Element, Hierarchy) = Package.ClassNames(pkg.UmlPackage).Single(x => x.Element.Name == className);
            klass = Package.ParseClass(Element, processor.Global, pkg.Context, pkg.Events, pkg.UmlPackage, Hierarchy);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var csharp = new CSharpWriter();
        await csharp.WriteClassFilesAsync(klass);
    }
}
