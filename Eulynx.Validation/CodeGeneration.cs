using XmiToCode;
using XmiToCode.Classes;
using XmiToCode.Codegen.C;
using XmiToCode.Codegen.CSharp;
using XmiToCode.Codegen.Rust;
using XmiToCode.Parsing;

namespace Eulynx.Validation;

[TestClass]
public class CodeGeneration
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

    [TestMethod, TestCategory("generate-c")]
    public async Task GenerateCommonFilesC()
    {
        XmiParser? processor;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            processor = new EulynxV22XmiParser(xmiPath);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var c = new CWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await c.WriteCommonFilesAsync(processor.GlobalContext);
    }

    [TestMethod, TestCategory("generate-c")]
    [DynamicData(nameof(UmlClasses))]
    public async Task GenerateC(string package, string className)
    {
        Package? pkg = null;
        ClassFile? klass = null;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            var processor = new EulynxV22XmiParser(xmiPath);
            var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
            pkg = Package.CreateFromUml(umlPackage, processor.GlobalContext);
            var (Element, Hierarchy) = pkg.ClassElements().Single(x => x.Element.Name == className);
            klass = Package.ParseClass(Element, pkg.Context, Hierarchy);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var c = new CWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await c.WriteClassFilesAsync(klass, pkg);
    }

    [TestMethod, TestCategory("generate-klee")]
    public async Task GenerateCommonFilesKlee()
    {
        XmiParser? processor;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            processor = new EulynxV22XmiParser(xmiPath);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var c = new KleeWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await c.WriteCommonFilesAsync(processor.GlobalContext);
    }

    [TestMethod, TestCategory("generate-klee")]
    [DynamicData(nameof(UmlClasses))]
    public async Task GenerateKlee(string package, string className)
    {
        Package? pkg = null;
        ClassFile? klass = null;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            var processor = new EulynxV22XmiParser(xmiPath);
            var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
            pkg = Package.CreateFromUml(umlPackage, processor.GlobalContext);
            var (Element, Hierarchy) = pkg.ClassElements().Single(x => x.Element.Name == className);
            klass = Package.ParseClass(Element, pkg.Context, Hierarchy);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var c = new KleeWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await c.WriteClassFilesAsync(klass, pkg);
    }

    [TestMethod, TestCategory("generate-rust")]
    public async Task GenerateCommonFilesRust()
    {
        XmiParser? processor;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            processor = new EulynxV22XmiParser(xmiPath);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var rust = new RustWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await rust.WriteCommonFilesAsync(processor.GlobalContext);
    }

    [TestMethod, TestCategory("generate-rust")]
    [DynamicData(nameof(UmlClasses))]
    public async Task GenerateRust(string package, string className)
    {
        Package? pkg = null;
        ClassFile? klass = null;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            var processor = new EulynxV22XmiParser(xmiPath);
            var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
            pkg = Package.CreateFromUml(umlPackage, processor.GlobalContext);
            var (Element, Hierarchy) = pkg.ClassElements().Single(x => x.Element.Name == className);
            klass = Package.ParseClass(Element, pkg.Context, Hierarchy);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var rust = new RustWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await rust.WriteClassFilesAsync(klass);
    }

    [TestMethod, TestCategory("generate-csharp")]
    public async Task GenerateCommonFilesCSharp()
    {
        XmiParser? processor;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            processor = new EulynxV22XmiParser(xmiPath);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var csharp = new CSharpWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await csharp.WriteCommonFilesAsync(processor.GlobalContext);
    }

    [TestMethod, TestCategory("generate-csharp")]
    [DynamicData(nameof(UmlClasses))]
    public async Task GenerateCSharp(string package, string className)
    {
        Package? pkg = null;
        ClassFile? klass = null;
        try {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
            var processor = new EulynxV22XmiParser(xmiPath);
            var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
            pkg = Package.CreateFromUml(umlPackage, processor.GlobalContext);
            var (Element, Hierarchy) = pkg.ClassElements().Single(x => x.Element.Name == className);
            klass = Package.ParseClass(Element, pkg.Context, Hierarchy);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var csharp = new CSharpWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await csharp.WriteClassFilesAsync(klass);
    }
}
