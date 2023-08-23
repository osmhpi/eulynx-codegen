using System.Text.RegularExpressions;
using static CodeGenerationHelper;

// Could be an enum member
public record LiteralIdentifier(string RawName) : Identifier(RawName)
{
    public override string Name => InPascalCase(Sanitize(RawName));

    protected virtual string Sanitize(string value) {
        var sanitizedValue = InPascalCase(value.Replace("-", " ").Replace(",", " And "));

        if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
            sanitizedValue = "_" + sanitizedValue;
        }

        return sanitizedValue;
    }
}

public record GlobalEnumIdentifier(string RawName) : LiteralIdentifier(RawName) {
    protected override string Sanitize(string value)
    {
        var sanitizedValue = InPascalCase(value.Replace("-", " ").Replace(",", " And ").Replace("/", " Or "));

        if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
            sanitizedValue = "_" + sanitizedValue;
        }

        return sanitizedValue;
    }
}
