public interface ICodeWriter
{
    Task WriteCommonFilesAsync(GlobalContext global);
    Task WriteClassFilesAsync(UmlClass umlClass, Class klass);
}
