using XmiToCode.Codegen.C;
using XmiToCode.Codegen.CSharp;
using XmiToCode.Codegen.Model;
using XmiToCode.Codegen.Rust;
using XmiToCode.Parsing;
using XmiToCode.Parsing.Model;
using XmiToCode.Transformation;

namespace Eulynx.Validation;

[TestClass]
public class CodeGeneration
{
    public static IEnumerable<object[]> UmlClasses
    {
        get
        {
            var processor = new EulynxV22XmiParser(ClassParsing.EULYNX_V22_FILE);
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
            processor = new EulynxV22XmiParser(ClassParsing.EULYNX_V22_FILE);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var c = new CWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await c.WriteCommonFilesAsync(processor.GlobalContext, processor.InterestingPackages);
    }

    [TestMethod, TestCategory("generate-c")]
    [DynamicData(nameof(UmlClasses))]
    public async Task GenerateC(string package, string className)
    {
        Package? pkg = null;
        ClassFile? klass = null;
        try {
            var processor = new EulynxV22XmiParser(ClassParsing.EULYNX_V22_FILE);

            foreach (var _umlPackage in processor.InterestingPackages) {
                var _pkg = Package.CreateFromUml(_umlPackage, processor.GlobalContext);
                // This has side effects
                _pkg.TryParseAllClasses();
            }

            var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
            pkg = Package.CreateFromUml(umlPackage, processor.GlobalContext);
            var (Element, Hierarchy) = pkg.ClassElements().Single(x => x.Element.Name == className);
            klass = new ClassTransformer(Package.ParseClass(Element, pkg.Context, Hierarchy)).TransformClassIntoFile();
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
            processor = new EulynxV22XmiParser(ClassParsing.EULYNX_V22_FILE);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var c = new KleeCheckUniqueTransitionsWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await c.WriteCommonFilesAsync(processor.GlobalContext, processor.InterestingPackages);
    }

    [TestMethod, TestCategory("generate-klee")]
    [DynamicData(nameof(UmlClasses))]
    public async Task GenerateKlee(string package, string className)
    {
        Package? pkg = null;
        ClassFile? klass = null;
        try {
            var processor = new EulynxV22XmiParser(ClassParsing.EULYNX_V22_FILE);

            foreach (var _umlPackage in processor.InterestingPackages) {
                var _pkg = Package.CreateFromUml(_umlPackage, processor.GlobalContext);
                // This has side effects
                _pkg.TryParseAllClasses();
            }

            var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
            pkg = Package.CreateFromUml(umlPackage, processor.GlobalContext);
            var (Element, Hierarchy) = pkg.ClassElements().Single(x => x.Element.Name == className);
            klass = new ClassTransformer(Package.ParseClass(Element, pkg.Context, Hierarchy)).TransformClassIntoFile();
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var c = new KleeCheckUniqueTransitionsWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await c.WriteClassFilesAsync(klass, pkg);
    }

    [TestMethod, TestCategory("generate-rust")]
    public async Task GenerateCommonFilesRust()
    {
        XmiParser? processor;
        try {
            processor = new EulynxV22XmiParser(ClassParsing.EULYNX_V22_FILE);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var rust = new RustWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await rust.WriteCommonFilesAsync(processor.GlobalContext, processor.InterestingPackages);
    }

    [TestMethod, TestCategory("generate-rust")]
    [DynamicData(nameof(UmlClasses))]
    public async Task GenerateRust(string package, string className)
    {
        Package? pkg = null;
        ClassFile? klass = null;
        try {
            var processor = new EulynxV22XmiParser(ClassParsing.EULYNX_V22_FILE);
            var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
            pkg = Package.CreateFromUml(umlPackage, processor.GlobalContext);
            var (Element, Hierarchy) = pkg.ClassElements().Single(x => x.Element.Name == className);
            klass = new ClassTransformer(Package.ParseClass(Element, pkg.Context, Hierarchy)).TransformClassIntoFile();
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
            processor = new EulynxV22XmiParser(ClassParsing.EULYNX_V22_FILE);
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var csharp = new CSharpWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await csharp.WriteCommonFilesAsync(processor.GlobalContext, processor.InterestingPackages);
    }

    [TestMethod, TestCategory("generate-csharp")]
    [DynamicData(nameof(UmlClasses))]
    public async Task GenerateCSharp(string package, string className)
    {
        Package? pkg = null;
        ClassFile? klass = null;
        try {
            var processor = new EulynxV22XmiParser(ClassParsing.EULYNX_V22_FILE);
            var umlPackage = processor.InterestingPackages.Single(x => x.Name == package);
            pkg = Package.CreateFromUml(umlPackage, processor.GlobalContext);
            var (Element, Hierarchy) = pkg.ClassElements().Single(x => x.Element.Name == className);
            klass = new ClassTransformer(Package.ParseClass(Element, pkg.Context, Hierarchy)).TransformClassIntoFile();
        } catch (Exception) {
            // Parsing is tested elsewhere
            Assert.Inconclusive();
            return;
        }

        var csharp = new CSharpWriter(Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set"));
        await csharp.WriteClassFilesAsync(klass);
    }
}
