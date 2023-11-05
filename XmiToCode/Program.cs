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
};

var classBlacklist = new string[] {
    // Demo data
    // "Block1"
};

var processor = new EulynxV22XmiParser(Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set"));

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

    await writer.WriteCommonFilesAsync(processor.GlobalContext);

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
