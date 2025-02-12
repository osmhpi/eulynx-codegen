using System.Reflection;
using XmiToCode;
using XmiToCode.Codegen;
using XmiToCode.Codegen.C;
using XmiToCode.Codegen.CSharp;
using XmiToCode.Codegen.Rust;
using XmiToCode.Parsing;

var classWhitelist = new string[] {
    // "F_Control_Point_Machine_Position",
    // "S_SCI_P_Command_And_Recieve",
    // "S_SCI_EfeS_Prim",
    // "S_SCI_Adj_Prim"
    // "F_EST_EfeS",
    // "F_SCI_EfeS_Sec"
    // "FControlTimer"
};

var classBlacklist = new string[] {
    // Demo data
    // "Block1"
    "F_Control_Timer",

    // Simulation Package
    "Hilfsblock",
    "Point_Helpblock",
};

var assemblyDir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location) ?? throw new Exception("Could not resolve assembly directory");
var processor = new EulynxV28XmiParser(Path.Combine(assemblyDir, "cleaned_28.xmi"), null, classBlacklist);

// Test if input arguments were supplied.
if (args.Length == 1 && args[0] == "validate")
{
    return 0;
}
else if (args.Length == 2 && Enum.TryParse<TargetLanguage>(args[0], out var targetLanguage))
{
    ICodeWriter writer = targetLanguage switch {
        TargetLanguage.CSharp => new CSharpWriter(args[1]),
        TargetLanguage.C => new CWriter(args[1]),
        TargetLanguage.Rust => new RustWriter(args[1]),
        _ => throw new NotImplementedException()
    };

    await writer.WriteCommonFilesAsync(processor.GlobalContext, processor.InterestingPackages);

    foreach (var package in processor.ParsePackages()) {
        await writer.WritePackageFilesAsync(package);
    }
}
else
{
    Console.WriteLine("Please provide the validate argument or enter the programming language to generate: CSharp, C or Rust.");
    Console.WriteLine("Usage: XmiToCode (validate | <language> <outputDirectory>)");
    return 1;
}

return 0;
