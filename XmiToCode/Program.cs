using XmiToCode;
using XmiToCode.Codegen;
using XmiToCode.Codegen.C;
using XmiToCode.Codegen.CSharp;
using XmiToCode.Codegen.Rust;

var processor = new XmiProcessor("../cleaned_23.xmi");

// Test if input arguments were supplied.
if (args.Length == 1 && args[0] == "validate")
{
    return 0;
}
else if (args.Length == 1 && Enum.TryParse<TargetLanguage>(args[0], out var targetLanguage))
{
    ICodeWriter writer = targetLanguage switch {
        TargetLanguage.CSharp => new CSharpWriter(),
        TargetLanguage.C => new CWriter(),
        TargetLanguage.Rust => new RustWriter(),
        _ => throw new NotImplementedException()
    };

    await writer.WriteCommonFilesAsync(processor.Global);

    foreach (var package in processor.ParsedPackages) {
        await writer.WritePackageFilesAsync(package);
    }
}
else
{
    Console.WriteLine("Please provide the validate argument or enter the programming language to generate: CSharp, C or Rust.");
    Console.WriteLine("Usage: XmiToCode (validate | <language>)");
    return 1;
}

return 0;
