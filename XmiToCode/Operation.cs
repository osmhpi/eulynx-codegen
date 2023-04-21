using System.Text.RegularExpressions;

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
            m => $"{m.Groups[1].Value} = {dataTypes.LookupPropertyValueType(m.Groups[1].Value)}.{DataTypeHelper.GenerateEnumMemberName(m.Groups[2].Value)}");

        return @$"public void {CodeGenerationItem.InPascalCase(Op.Name)}() {{
            {insns}
        }}";
    }
}
