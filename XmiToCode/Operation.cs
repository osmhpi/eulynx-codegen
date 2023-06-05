using System.Text.RegularExpressions;
using static CodeGenerationItem;

namespace XmiToCode;

public record Operation(OwnedOperation Op, OwnedBehavior Behavior) {
    public string Write(DataTypeHelper dataTypes) {
        var insns = CompoundState.ConvertInstructions(Behavior.Body, null, dataTypes);

        foreach (Match m in Regex.Matches(insns, "(\\w+) = \"([^\"]*)\"")) {
            var lhs = m.Groups[1].Value;
            var rhs = m.Groups[2].Value;
            dataTypes.RecordPossibleValueForProperty(lhs, rhs);
        }

        insns = Regex.Replace(insns, "(\\w+) = \"([^\"]*)\"",
            m => $"{m.Groups[1].Value} = {dataTypes.GetFinalDataType(m.Groups[1].Value)}.{DataTypeHelper.GenerateEnumMemberName(m.Groups[2].Value)}");

        var portOrDirectAccess = (string prop) => dataTypes.Ports.ContainsKey(prop) ? $"{prop}.Value" : prop;
        insns = Regex.Replace(insns, "\\w+", m => $"{portOrDirectAccess(m.Groups[0].Value)}");

        insns = insns
            .Replace("Then", ") {")
            .Replace("Elseif", "} else if (")
            .Replace("Else", "} else {")
            .Replace("End If", "}")
            .Replace("If", "if (")
            .Replace("Return", "return");

        return @$"public void {InPascalCase(Op.Name)}() {{
            {insns}
        }}";
    }
}
