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
                foreach (var (Element, _) in classes)
                    yield return new object[] { package.Name, Element.Name };
            }
        }
    }

    [TestMethod, TestCategory("generate-c")]
    public async Task GenerateCommonFilesC()
    {
        XmiProcessor? processor;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            processor = new XmiProcessor(xmiPath);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var outDir = new DirectoryInfo("../Eulynx/C");
        if (!outDir.Exists) outDir.Create();

        var c = new CWriter();
        await c.WriteCommonFilesAsync(processor.Global);
    }

    [TestMethod, TestCategory("generate-c")]
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

    [TestMethod, TestCategory("generate-klee")]
    public async Task GenerateCommonFilesKlee()
    {
        XmiProcessor? processor;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            processor = new XmiProcessor(xmiPath);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var outDir = new DirectoryInfo("../Klee");
        if (!outDir.Exists) outDir.Create();

        var c = new KleeWriter();
        await c.WriteCommonFilesAsync(processor.Global);
    }

    [TestMethod, TestCategory("generate-klee")]
    [DynamicData(nameof(UmlClasses))]
    public async Task GenerateKlee(string package, string className)
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

        var c = new KleeWriter();
        var packageDir = Path.Combine("../Klee", pkg.Name.Name);
        await c.WriteClassFilesAsync(klass, packageDir);
    }

    [TestMethod, TestCategory("generate-rust")]
    public async Task GenerateCommonFilesRust()
    {
        XmiProcessor? processor;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            processor = new XmiProcessor(xmiPath);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var rust = new RustWriter();
        await rust.WriteCommonFilesAsync(processor.Global);
    }

    [TestMethod, TestCategory("generate-rust")]
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

    [TestMethod, TestCategory("generate-csharp")]
    public async Task GenerateCommonFilesCSharp()
    {
        XmiProcessor? processor;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            processor = new XmiProcessor(xmiPath);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var outDir = new DirectoryInfo("../Eulynx");
        if (!outDir.Exists) outDir.Create();

        var csharp = new CSharpWriter();
        await csharp.WriteCommonFilesAsync(processor.Global);
    }

    [TestMethod, TestCategory("generate-csharp")]
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
