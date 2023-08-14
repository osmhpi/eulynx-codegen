public interface ICodeWriter
{
    string DefaultInstanceReference { get; }

    string Write<T>(T element);
    public string GenerateFileName(UmlClass uml);
}
