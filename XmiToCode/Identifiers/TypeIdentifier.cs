using static CodeGenerationHelper;
// Could be an enumeration or message class
public record TypeIdentifier (string RawName)
{
    public string Name { get; } = InPascalCase(Sanitize(RawName));

    protected static string Sanitize(string value) {
        return value.Replace("(", "").Replace(")", "").Replace("/", "__");
    }
}
