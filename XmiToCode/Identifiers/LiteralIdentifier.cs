using System.Text.RegularExpressions;
using static CodeGenerationHelper;
// Could be an enum member
public record LiteralIdentifier (string RawName)
{
    public string Name => InPascalCase(Sanitize(RawName));

    private static string Sanitize(string value) {
        var sanitizedValue = InPascalCase(value.Replace(",", " And "));

        if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
            sanitizedValue = "_" + sanitizedValue;
        }

        return sanitizedValue;
    }
}
