public interface ICodeWriter
{
    string DefaultInstanceReference { get; }

    string Write<T>(T element);
    Task WriteAllFilesAsync(UmlClass umlClass, Class klass);
    public string GenerateFileName(UmlClass uml);
}
