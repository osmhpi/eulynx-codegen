using XmiToCode.Classes;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Codegen;

public interface ICodeWriter
{
    Task WriteCommonFilesAsync(GlobalContext global);
    Task WritePackageFilesAsync(Package pkg);
}
