using System.Globalization;
using System.Text.RegularExpressions;
using XmiToCode;

record CompoundState(List<PartialState> PartialStates, StateMachine? InternalStateMachine) : IState
{
    public bool IsInitialState => PartialStates.All(x => x.Vertex.Name.Contains("Initial") && x.Vertex.Type == "uml:Pseudostate");

    public bool IsJunction => PartialStates.Any(x => x.IsJunction);

    public bool IsRegularState => PartialStates.All(x => x.Vertex.Type == "uml:State");

    public string Name => string.Join("_", PartialStates.Select(x => InPascalCase(x.Vertex.Name)));

    public static string ConvertInstructions(string instructions) {
        return string.Join(";\n", instructions.Split(";").Select(instruction => {
            var fixedSyntax = instruction
                .Replace("TRUE", "\"TRUE\"")
                .Replace("FALSE", "\"FALSE\"")
                .Replace(" := ", " = ")
                .Trim();

            var fixedIdentifiers = Regex.Replace(fixedSyntax, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
            var fixedMessages = Regex.Replace(fixedIdentifiers, "^Send (.+)\\s?To (.+)$", m => $"SendMessage(\"{m.Groups[1].Value}\", \"{m.Groups[2].Value}\")");
            return fixedMessages;
        }));
    }

    private string? NullWhitespace(string value) {
        return string.IsNullOrWhiteSpace(value) ? null : value;
    }

    public string? GenerateExit(IState next, Transition transition)
    {
        return NullWhitespace(string.Join("\n", PartialStates.Select(x => ConvertInstructions(x.Vertex.Exit?.Name ?? ""))));
    }

    public string? GenerateTransition(IState next, Transition transition)
    {
        return NullWhitespace(string.Join("\n", transition.Transitions.Select(transition => ConvertInstructions(transition.Effect?.Body ?? ""))));
    }

    public string? GenerateEntry(IState previous, Transition transition)
    {
        return NullWhitespace(string.Join("\n", PartialStates.Select(x => ConvertInstructions(x.Vertex.Entry?.Name ?? ""))));
    }

    private static string InPascalCase(string value)
    {
        var result = value.ToLower().Replace("_", " ").Replace("-", " ").Replace("\t", " ");
        var info = CultureInfo.CurrentCulture.TextInfo;
        result = info.ToTitleCase(result).Replace(" ", string.Empty);
        return result;
    }

    public bool IsSourceOfTransition(UmlTransition transition)
    {
        return PartialStates.Any(x => x.Vertex.Id == transition.Source);
    }

    public bool IsTargetOfTransition(UmlTransition transition)
    {
        return PartialStates.Any(x => x.Vertex.Id == transition.Target);
    }

    internal bool IsNextStateAfterTransition(CompoundState fromState, UmlTransition transition)
    {
        UmlSubvertex? requireTransitionFromVertex = null;
        if (fromState.IsJunction) {
            // Special handling for transitions after junctions
            // we must only include such transitions that
            // change the partial state which is currently in a junction

            var junctionPartialState = fromState.PartialStates.Single(x => x.IsJunction);
            requireTransitionFromVertex = junctionPartialState.Vertex;
        }

        bool isTransitioned = false;
        foreach (var (from, to) in fromState.PartialStates.Zip(PartialStates)) {
            if (from.Vertex != to.Vertex) {
                if (isTransitioned) {
                    return false;
                }

                if (requireTransitionFromVertex != null && from.Vertex != requireTransitionFromVertex) {
                    return false;
                }

                if (transition.Source != from.Vertex.Id
                        && transition.Target != to.Vertex.Id) {
                    return false;
                }

                isTransitioned = true;
            }
        }

        return true;
    }
}

record PartialState(UmlSubvertex Vertex, UmlRegion EnclosingRegion) {
    public bool IsJunction => Vertex.Name.Contains("Junction") && Vertex.Type == "uml:Pseudostate";
}
