using static CodeGenerationHelper;
// Could be an enumeration or message class
public record TypeIdentifier (string RawName)
{
    public virtual string Name { get; } = InPascalCase(Sanitize(RawName));

    protected static string Sanitize(string value) {
        return value.Replace("(", "").Replace(")", "").Replace("/", "__");
    }
}

public record UniqueTypeIdentifier (string RawName, string Id) : TypeIdentifier(RawName) {
    public override string Name => InPascalCase(Sanitize(RawName)) + "_" + Id[..5];
}
