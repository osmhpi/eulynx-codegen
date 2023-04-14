using System.Globalization;
using System.Text.RegularExpressions;
using XmiToCode;

record State(Subvertex Vertex, OurRegion? Region) : IState
{
    public bool IsInitialState => Vertex.Name.Contains("Initial") && Vertex.Type == "uml:Pseudostate";
    public bool IsJunction => Vertex.Name.Contains("Junction") && Vertex.Type == "uml:Pseudostate";
    public bool IsRegularState => Vertex.Type == "uml:State";

    public string Name => Vertex.Name;

    public string VertexId => Vertex.Id;

    public string GenerateExit(IState next, Transition transition)
    {
        var exit = (Vertex.Exit?.Name ?? "")
          .Replace("TRUE", "\"TRUE\"")
          .Replace("FALSE", "\"FALSE\"")
          .Replace(" := ", " = ");
        return Regex.Replace(exit, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
    }

    public string GenerateTransition(IState next, Transition transition)
    {
        var transitionEffect = (transition.Effect?.Body ?? "")
            .Replace("TRUE", "\"TRUE\"")
            .Replace("FALSE", "\"FALSE\"")
            .Replace(" := ", " = ");
        return Regex.Replace(transitionEffect, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
    }

    public string GenerateEntry(IState previous, Transition transition)
    {
        var entry = (Vertex.Entry?.Name ?? "")
            .Replace("TRUE", "\"TRUE\"")
            .Replace("FALSE", "\"FALSE\"")
            .Replace(" := ", " = ");
        return Regex.Replace(entry, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
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
            // return Region.States
            //     .Where(x => x.Region != null)
                // .Select(x => new StateMachine(x.Region, x.Name, changeEvents, timeEvents));
        }

        throw new InvalidOperationException("State has no region");
    }
}
