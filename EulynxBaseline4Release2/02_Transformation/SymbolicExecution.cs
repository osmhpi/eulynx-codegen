using System.Diagnostics;
using XmiToCode.Identifiers;
using XmiToCode.Parsing;
using XmiToCode.Parsing.Model;

namespace Eulynx.Validation;

[TestClass]
public class SymbolicExecution
{
    public static IEnumerable<object[]> UmlClasses
    {
        get
        {
            var processor = new EulynxV22XmiParser(ClassParsing.EULYNX_XMI_FILE);
            foreach (var package in processor.InterestingPackages) {
                var classes = Package.ClassElements(package);
                foreach (var (Element, _) in classes)
                    yield return new object[] { package.Name, Element.Name };
            }
        }
    }

    [TestMethod, TestCategory("execute-klee")]
    [DynamicData(nameof(UmlClasses))]
    public void ExecuteKlee(string package, string className)
    {
        using var process = new Process();

        var output = Environment.GetEnvironmentVariable("CODEGEN_OUTPUT_DIR") ?? throw new Exception("CODEGEN_OUTPUT_DIR not set");
        var workingDir = $"{output}/{new TypeIdentifier(package).Name}";
        var inFile = $"{new TypeIdentifier(className).Name}.bc";
        var outFile = $"{new TypeIdentifier(className).Name}.klee";

        var info = new FileInfo($"{workingDir}/{inFile}");
        if (!info.Exists)
            Assert.Inconclusive();

        process.StartInfo.FileName = "make";
        process.StartInfo.Arguments = $"-f {Environment.CurrentDirectory}/../../../../Klee/Makefile -C {workingDir} {outFile}";
        process.StartInfo.UseShellExecute = false;
        process.StartInfo.RedirectStandardOutput = true;
        process.StartInfo.RedirectStandardError = true;
        process.Start();

        Console.WriteLine(process.StandardOutput.ReadToEnd());
        Console.WriteLine(process.StandardError.ReadToEnd());

        process.WaitForExit();
        Assert.AreEqual(0, process.ExitCode);
    }
}
