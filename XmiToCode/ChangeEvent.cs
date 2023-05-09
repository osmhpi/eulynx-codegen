using System.Text.RegularExpressions;
using static CodeGenerationItem;

namespace XmiToCode;

record ChangeEvent(PackagedElement Event) {
    public string WriteInitializer(DataTypeHelper dataTypes) {
        var expression = Event.ChangeExpression.Body
                            .ReplaceLineEndings(" ")
                            .Replace("AND ", " && ")
                            .Replace(" OR ", " || ")
                            .Replace("NOT ", "!")
                            .Replace(" = ", " == ")
                            .Replace(" <> ", " != ");

        var result = Regex.Replace(expression, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));

        foreach (Match m in Regex.Matches(result, "(\\w+) (==|!=) (?<!\")(\\w*)(?!\")")) {
            var lhs = m.Groups[1].Value;
            var rhs = m.Groups[3].Value;
            dataTypes.RecordCoalesceValues(lhs, rhs);
        }

        foreach (Match m in Regex.Matches(result, "(\\w+) (==|!=) \"(\\w*)\"")) {
            var lhs = m.Groups[1].Value;
            var rhs = m.Groups[3].Value;
            dataTypes.RecordPossibleValueForProperty(lhs, rhs);
        }

        var portOrDirectAccess = (string prop) => dataTypes.Ports.Any(x => InPascalCase(x.Name) == prop) ? $"{prop}.Value" : prop;

        result = Regex.Replace(result, "(\\w+) (==|!=) \"(\\w*)\"", m => $"{m.Groups[1].Value} {m.Groups[2].Value} {dataTypes.LookupPropertyValueType(m.Groups[1].Value)}.{InPascalCase(m.Groups[3].Value)}");
        result = Regex.Replace(result, "\\w+", m => $"{portOrDirectAccess(m.Groups[0].Value)}");

        return $"{Event.Name} = new Event(() => {result});";
    }

    public string WriteProperty() {
        return $"public Event {Event.Name} {{ get; }}";
    }
}
