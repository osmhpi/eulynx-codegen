internal interface ICodeWriter
{
    string Write<T>(T element);
    public string GenerateFileName(UmlClass uml);
}
