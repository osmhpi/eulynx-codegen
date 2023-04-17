using System.Text.RegularExpressions;
using XmiToCode;

using static CodeGenerationItem;

record Transition(IState From, IState To, List<UmlTransition> Transitions) {
    public UmlTransition SingleTransition => Transitions.Single();

    public string GetTransitionConstraints(DataTypeHelper dataTypes) {
        if (SingleTransition.OwnedRule != null && SingleTransition.OwnedRule.Specification != null) {
            var specification = SingleTransition.OwnedRule.Specification.Body;

            if (specification == "else") {
                return "else";
            }

            var expression = SingleTransition.OwnedRule.Specification.Body
                .ReplaceLineEndings(" ")
                .Replace("AND ", " && ")
                .Replace(" OR ", " || ")
                .Replace("NOT ", "!")
                .Replace(" = ", " == ")
                .Replace(" <> ", " != ");

            expression = Regex.Replace(expression, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));

            foreach (Match m in Regex.Matches(expression, "(\\w+) (==|!=) (?<!\")(\\w*)(?!\")")) {
                var lhs = m.Groups[1].Value;
                var rhs = m.Groups[3].Value;
                dataTypes.RecordCoalesceValues(lhs, rhs);
            }

            foreach (Match m in Regex.Matches(expression, "(\\w+) (==|!=) \"(\\w*)\"")) {
                var lhs = m.Groups[1].Value;
                var rhs = m.Groups[3].Value;
                dataTypes.RecordPossibleValueForProperty(lhs, rhs);
            }
            expression = Regex.Replace(expression, "(\\w+) (==|!=) \"(\\w*)\"", m => $"{m.Groups[1].Value} {m.Groups[2].Value} {dataTypes.LookupPropertyValueType(m.Groups[1].Value)}.{DataTypeHelper.GenerateEnumMemberName(m.Groups[3].Value)}");

            return $"if ({expression})";
        }
        return "";
    }
}
