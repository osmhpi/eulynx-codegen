public interface ICodeWriter
{
    Task WriteCommonFilesAsync(GlobalContext global);
    Task WritePackageFilesAsync(Package pkg);
}
