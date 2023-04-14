using System.Globalization;
using System.Text.RegularExpressions;
using XmiToCode;

record OurRegion(Region Region, List<State> States) {
    public State InitialState => States.Single(x => x.IsInitialState);
}

record State(Subvertex Vertex, List<OurRegion> Regions)
{
    public bool IsInitialState = Vertex.Name.Contains("Initial") && Vertex.Type == "uml:Pseudostate";
    public bool IsJunction = Vertex.Name.Contains("Junction") && Vertex.Type == "uml:Pseudostate";
    public bool IsRegularState = Vertex.Type == "uml:State";

    public string Name = Vertex.Name;

    public string GenerateExit(State next, Transition transition)
    {
        var exit = (Vertex.Exit?.Name ?? "")
          .Replace("TRUE", "\"TRUE\"")
          .Replace("FALSE", "\"FALSE\"")
          .Replace(" := ", " = ");
        return Regex.Replace(exit, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
    }

    public string GenerateTransition(State next, Transition transition)
    {
        var transitionEffect = (transition.Effect?.Body ?? "")
            .Replace("TRUE", "\"TRUE\"")
            .Replace("FALSE", "\"FALSE\"")
            .Replace(" := ", " = ");
        return Regex.Replace(transitionEffect, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
    }

    public string GenerateEntry(State previous, Transition transition)
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
}
