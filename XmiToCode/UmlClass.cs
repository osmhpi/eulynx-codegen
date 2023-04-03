using System.Text.RegularExpressions;
using XmiToCode;

internal class UmlClass : CodeGenerationItem
{
  private PackagedElement _class;
  private readonly Dictionary<string, PackagedElement> _changeEvents;
  private readonly Dictionary<string, PackagedElement> _timeEvents;
  private readonly TheRegion _behavior;

  public UmlClass(PackagedElement theClass, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
  {
    _class = theClass;
    _changeEvents = changeEvents;
    _timeEvents = timeEvents;
    _behavior = new TheRegion(_class.OwnedBehavior.Region, _class.OwnedBehavior.Name, changeEvents, timeEvents);
  }

  public string GetName() {
    return InPascalCase(_class.Name);
  }

  private string GenerateTransition(string name, Subvertex fromState)
  {
    return $@"private {name} TransitionFrom{InPascalCase(fromState.Name)}() {{
      {GenerateConditions(fromState)}

      // Do not transition
      return _state;
    }}
";
  }

  private string GenerateConditions(Subvertex fromState, bool skipParentTransitions=false)
  {
      var transitions = _behavior.GetTransitionsFromState(fromState, skipParentTransitions);

      var regularTransitions = transitions.Where(x => x.state.Type == "uml:State");
      var regularConditions = string.Join("\n", regularTransitions.Select(x =>
      $@"{GetTransitionConditions(x.transition)} {{
        {GenerateActivities(fromState, x)}
        return {x.stateName}.New();
      }}"));

      var junctions = transitions.Where(x => x.state.Kind == "junction");
      var junctionConditions = string.Join("\n", junctions.Select(x =>
      $@"{GetTransitionConditions(x.transition)} {{
        {GenerateConditions(x.state, true)}
      }}"));

      return regularConditions + junctionConditions;
  }

  private string GenerateActivities(Subvertex fromState, (Transition transition, Subvertex state, string stateName) x)
  {
      var exit = (x.state.Exit?.Name ?? "")
          .Replace("TRUE", "\"TRUE\"")
          .Replace("FALSE", "\"FALSE\"")
          .Replace(" := ", " = ");
      exit = Regex.Replace(exit, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));

      var transitionEffect = (x.transition.Effect?.Body ?? "")
          .Replace("TRUE", "\"TRUE\"")
          .Replace("FALSE", "\"FALSE\"")
          .Replace(" := ", " = ");
      transitionEffect = Regex.Replace(transitionEffect, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));

      var entry = (x.state.Entry?.Name ?? "")
          .Replace("TRUE", "\"TRUE\"")
          .Replace("FALSE", "\"FALSE\"")
          .Replace(" := ", " = ");
      entry = Regex.Replace(entry, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));

      return string.Join("\n", exit, transitionEffect, entry);
  }

  private string GetTransitionConditions(Transition transition) {
    if (transition.Trigger != null) {
      // Regular transition
      string? result = null;

      var evt = transition.Trigger.Event;
      if (_changeEvents.ContainsKey(evt)) {
        var expression = _changeEvents[evt].ChangeExpression.Body
          .Replace(" AND ", " && ")
          .Replace(" OR ", " || ")
          .Replace(" = ", " == ")
          .Replace(" <> ", " != ");

        result = Regex.Replace(expression, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
      }

      if (_timeEvents.ContainsKey(evt)) {
        result = $"IsTimeoutExpired({InPascalCase(_timeEvents[evt].When.Expr.Body)})";
      }

      if (result != null) {
          return $"if ({result})";
      }

    } else if (transition.OwnedRule != null && transition.OwnedRule.Specification != null) {
        // Special constrained transition for junction elements
        var specification = transition.OwnedRule.Specification.Body;

        if (specification == "else") {
          return "else";
        }

        var expression = transition.OwnedRule.Specification.Body
          .Replace(" AND ", " && ")
          .Replace(" OR ", " || ")
          .Replace(" = ", " == ")
          .Replace(" <> ", " != ");

        expression = Regex.Replace(expression, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));

        return $"if ({expression})";
    }

    throw new Exception("Invalid event reference.");
  }

  public override string Write() {
    var className = InPascalCase(_class.Name);
    var properties = _class.OwnedAttribute
      //.Where(x => x.XmiType.SingleOrDefault() == "uml:Property")
      .ToList();

    var states = _behavior.GetStates();
    var behaviorName = _behavior.GetName();

    return @$"namespace Eulynx;

class {className} {{
{string.Join("\n", properties.Select(x => $"public string {CodeGenerationItem.InPascalCase(x.Name)} {{ get; set; }}"))}

{_behavior.Write()}

    private {behaviorName} _state;

    public {className}() {{
      _state = {behaviorName}.New();
    }}

    private bool IsTimeoutExpired(string timeout) {{
        // TODO
        return false;
    }}

    public void Transition() {{
        _state = _state switch {{
{string.Join(",\n", states.Select(t =>
  string.Join(",\n", $"{t.name} => TransitionFrom{InPascalCase(t.subvertex.Name)}()")))}
      }};
    }}

{string.Join("\n", states.Select(fromState => GenerateTransition(behaviorName, fromState.subvertex)))}
}}";
  }

  internal async Task Generate()
  {
    using var file = File.Create($"../out/{GetName()}.cs");
    using var writer = new StreamWriter(file);
    await writer.WriteAsync(Write());
  }
}
