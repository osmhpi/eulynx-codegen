using System.Globalization;
using System.Text.RegularExpressions;
using XmiToCode;

record CompoundState(List<PartialState> PartialStates, OurRegion? Region) : IState
{
    public bool IsInitialState => PartialStates.All(x => x.Vertex.Name.Contains("Initial") && x.Vertex.Type == "uml:Pseudostate");

    public bool IsJunction => PartialStates.Any(x => x.Vertex.Name.Contains("Junction") && x.Vertex.Type == "uml:Pseudostate");

    public bool IsRegularState => PartialStates.All(x => x.Vertex.Type == "uml:State");

    public string Name => string.Join("_", PartialStates.Select(x => x.Vertex.Name));

    public string GenerateExit(IState next, OurTransition transition)
    {
        return string.Join("\n", PartialStates.Select(x => {
           var exit = (x.Vertex.Exit?.Name ?? "")
                .Replace("TRUE", "\"TRUE\"")
                .Replace("FALSE", "\"FALSE\"")
                .Replace(" := ", " = ");
            return Regex.Replace(exit, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
        }));
    }

    public string GenerateTransition(IState next, OurTransition transition)
    {
        var transitionEffect = (transition.Transition.Effect?.Body ?? "")
            .Replace("TRUE", "\"TRUE\"")
            .Replace("FALSE", "\"FALSE\"")
            .Replace(" := ", " = ");
        return Regex.Replace(transitionEffect, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
    }

    public string GenerateEntry(IState previous, OurTransition transition)
    {
        return string.Join("\n", PartialStates.Select(x => {
           var entry = (x.Vertex.Entry?.Name ?? "")
                .Replace("TRUE", "\"TRUE\"")
                .Replace("FALSE", "\"FALSE\"")
                .Replace(" := ", " = ");
            return Regex.Replace(entry, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
        }));
    }

    private static string InPascalCase(string value)
    {
        var result = value.ToLower().Replace("_", " ").Replace("-", " ").Replace("\t", " ");
        var info = CultureInfo.CurrentCulture.TextInfo;
        result = info.ToTitleCase(result).Replace(" ", string.Empty);
        return result;
    }

    public StateMachine CreateChildStateMachine(Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
    {
        if (Region != null) {
            return new StateMachine(Region, Name, changeEvents, timeEvents);
        }

        throw new InvalidOperationException("State has no region");
    }

    public bool IsSourceOfTransition(Transition transition)
    {
        return PartialStates.Any(x => x.Vertex.Id == transition.Source);
    }

    public bool IsTargetOfTransition(Transition transition)
    {
        return PartialStates.Any(x => x.Vertex.Id == transition.Target);
    }
}

record PartialState(Subvertex Vertex, Region EnclosingRegion);
