using System.Globalization;

namespace XmiToCode.Codegen;

public static class CodeGenerationHelper {

    public static string InPascalCase(string s) {

        if (!s.Contains(" ") && !s.Contains("_")
            && s.Length > 0 && s.Substring(0, 1) == s.Substring(0, 1).ToUpper()
            && s != s.ToUpper()) {
            // This already seems to be in pascal case
            return s;
        }

        var result = s.ToLower().Replace("_", " ").Replace("-", " ").Replace("\t", " ");
        var info = CultureInfo.CurrentCulture.TextInfo;
        result = info.ToTitleCase(result).Replace(" ", string.Empty);
        return result;
    }

    public static string JoinLines(IEnumerable<string> lines, string delimiter = "") {
        return string.Join($"{delimiter} \n", lines.Where(x => !string.IsNullOrWhiteSpace(x)));
    }
}
