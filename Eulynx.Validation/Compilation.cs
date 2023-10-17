using System.Diagnostics;
using XmiToCode;
using XmiToCode.Classes;
using XmiToCode.Identifiers;

namespace Eulynx.Validation;

[TestClass]
public class Compilation
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

    [TestMethod, TestCategory("compile-c")]
    [DynamicData(nameof(UmlClasses))]
    public void CompileClass(string package, string className)
    {
        using var process = new Process();

        var workingDir = $"{Environment.CurrentDirectory}/../Eulynx/C/{new TypeIdentifier(package).Name}";
        var file = $"{new TypeIdentifier(className).Name}.o";

        var info = new FileInfo($"{workingDir}/{file}");
        if (!info.Exists)
            Assert.Inconclusive();

        process.StartInfo.FileName = "make";
        process.StartInfo.Arguments = $"-C {workingDir} {file}";
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
