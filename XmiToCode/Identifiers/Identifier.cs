using static CodeGenerationHelper;

// Could be a reference to a port or variable
public record Identifier (string RawName)
{
    public virtual string Name { get; } = InPascalCase(RawName);
}
