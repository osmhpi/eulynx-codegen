using System.Text.RegularExpressions;
using static CodeGenerationItem;

namespace XmiToCode;

public record Operation(OwnedOperation Op, OwnedBehavior Behavior) {
    public string Write(DataTypeHelper dataTypes, ProgramContext context) {
        var instructions = CompoundState.ConvertInstructions(Behavior.Body, dataTypes, context);

        // foreach (Match m in Regex.Matches(instructions, "(\\w+) = \"([^\"]*)\"")) {
        //     var lhs = m.Groups[1].Value;
        //     var rhs = m.Groups[2].Value;
        //     dataTypes.RecordPossibleValueForProperty(lhs, rhs);
        // }

        // instructions = Regex.Replace(instructions, "(\\w+) = \"([^\"]*)\"",
        //     m => $"{m.Groups[1].Value} = {dataTypes.GetFinalDataType(m.Groups[1].Value)}.{DataTypeHelper.GenerateEnumMemberName(m.Groups[2].Value)}");

        // var portOrDirectAccess = (string prop) => dataTypes.Ports.ContainsKey(prop) ? $"{prop}.Value" : prop;
        // instructions = Regex.Replace(instructions, "\\w+", m => $"{portOrDirectAccess(m.Groups[0].Value)}");

        // instructions = instructions
        //     .Replace("Then", ") {")
        //     .Replace("Elseif", "} else if (")
        //     .Replace("Else", "} else {")
        //     .Replace("End If", "}")
        //     .Replace("If", "if (")
        //     .Replace("Return", "return");

        return @$"public void {InPascalCase(Op.Name)}() {{
            {instructions}
        }}";
    }
}
