using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.Model;

namespace XmiToCode.Codegen;

public interface ICodeWriter
{
    Task WriteCommonFilesAsync(GlobalContext global);
    Task WritePackageFilesAsync(Package pkg);
}
