using static CodeGenerationHelper;
// Could be an enumeration or message class
public record TypeIdentifier (string RawName)
{
    public string Name { get; } = InPascalCase(RawName);
}
