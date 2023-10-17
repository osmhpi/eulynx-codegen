using XmiToCode;
using XmiToCode.Codegen;
using XmiToCode.Codegen.C;
using XmiToCode.Codegen.CSharp;
using XmiToCode.Codegen.Rust;

// Test if input arguments were supplied.
if (args.Length == 0 || !Enum.TryParse<TargetLanguage>(args[0], out var targetLanguage))
{
    Console.WriteLine("Please enter the programming language to generate: CSharp, C or Rust.");
    Console.WriteLine("Usage: XmiToCode <language>");
    return 1;
}

var processor = new XmiProcessor("../cleaned_23.xmi");

var typeAliases = new Dictionary<(string, string), (string, string)>() {
    { ("D50inPdiConnectionStateValue", ""), ("SSciEfesPrim.D50outPdiConnectionStateValue", "") }
};

var csharp = new CSharpWriter();
var rust = new RustWriter();
var c = new CWriter();

ICodeWriter writer = targetLanguage switch {
    TargetLanguage.CSharp => csharp,
    TargetLanguage.C => c,
    TargetLanguage.Rust => rust,
    _ => throw new NotImplementedException()
};

await writer.WriteCommonFilesAsync(processor.Global);

foreach (var package in processor.ParsedPackages) {
    await writer.WritePackageFilesAsync(package);
}

return 0;
