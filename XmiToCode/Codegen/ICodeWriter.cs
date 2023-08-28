using XmiToCode.Classes;
using XmiToCode.Context;

namespace XmiToCode.Codegen;

public interface ICodeWriter
{
    Task WriteCommonFilesAsync(GlobalContext global);
    Task WritePackageFilesAsync(Package pkg);
}
