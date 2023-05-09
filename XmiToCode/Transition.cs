using System.Text.RegularExpressions;
using XmiToCode;

using static CodeGenerationItem;

record Transition(IState From, IState To, List<UmlTransition> Transitions) {
    public UmlTransition SingleTransition => Transitions.Single();

    private string GetMessageTriggeredTransitionConstraint(DataTypeHelper dataTypes, PackagedElement evt) {
        var expression = SingleTransition.OwnedRule.Specification.Body
            .ReplaceLineEndings(" ")
            .Replace("AND ", " && ")
            .Replace(" OR ", " || ")
            .Replace("NOT ", "!")
            .Replace(" = ", " == ")
            .Replace(" <> ", " != ")
            .Replace("\"", "\\\"");
        return $"if (ReceivedMessage(\"{evt.Name}[{expression}]\"))";
    }

    public string GetTransitionConstraints(DataTypeHelper dataTypes) {
        if (SingleTransition.OwnedRule != null && SingleTransition.OwnedRule.Specification != null) {
            var specification = SingleTransition.OwnedRule.Specification.Body;

            if (SingleTransition.Trigger != null && SingleTransition.Trigger.Event != null) {
                var evt = SingleTransition.Trigger.Event;
                if (dataTypes.TimeEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.TimeEvents[evt];
                } else if (dataTypes.ChangeEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.ChangeEvents[evt];
                } else if (dataTypes.PackageEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.PackageEvents[evt];
                    return GetMessageTriggeredTransitionConstraint(dataTypes, theEvent);
                } else {
                    throw new Exception("Could not resolve trigger event");
                }
            }

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

            var portOrDirectAccess = (string prop) => dataTypes.Ports.Any(x => InPascalCase(x.Name) == prop) ? $"{prop}.Value" : prop;

            expression = Regex.Replace(expression, "(\\w+) (==|!=) \"(\\w*)\"", m => $"{portOrDirectAccess(m.Groups[1].Value)} {m.Groups[2].Value} {dataTypes.LookupPropertyValueType(m.Groups[1].Value)}.{DataTypeHelper.GenerateEnumMemberName(m.Groups[3].Value)}");

            // Accessors for singular boolean expressions
            // expression = Regex.Replace(expression, "(?<!((==|!=)))\\s+(\\w+(\\.\\w+)*)\\s+(?!((==|!=)))", m => $" {m.Groups[3].Value}.Value ");
            // expression = Regex.Replace(expression, "^(.*)(([\\(\\)]|&&|\\|\\|))?\\s*(\\w+(\\.\\w+)*)\\s*([\\(\\)]|&&|\\|\\|)(.*)$", m => $" {m.Groups[3].Value}.Value ");
            expression = Regex.Replace(expression, "(?<!((==|!=)))\\s*(\\w+(\\.\\w+)*)\\s*(?!((==|\\!=)))", m => $"{portOrDirectAccess(m.Groups[3].Value)}");

            return $"if ({expression})";
        }
        return "";
    }
}
