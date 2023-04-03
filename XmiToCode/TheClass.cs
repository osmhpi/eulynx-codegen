using System.Text.RegularExpressions;
using XmiToCode;

internal class TheClass : CodeGenerationItem
{
  private PackagedElement _class;
  private readonly Dictionary<string, PackagedElement> _changeEvents;
  private readonly Dictionary<string, PackagedElement> _timeEvents;
  private readonly TheRegion _behavior;

  public TheClass(PackagedElement theClass, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
  {
    _class = theClass;
    _changeEvents = changeEvents;
    _timeEvents = timeEvents;
    _behavior = new TheRegion(_class.OwnedBehavior.Region, _class.OwnedBehavior.Name, changeEvents, timeEvents);
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

  private string GenerateConditions(Subvertex fromState)
  {
     var transitions = _behavior.GetTransitionsFromState(fromState)
      // Temporarily only process change events, will take care of
      // timed events later
      .Where(x => _changeEvents.ContainsKey(x.transition.Trigger.Event));

     return string.Join("\n", transitions.Select(x =>
     $@"if ({GetTransitionConditions(x.transition)}) {{
      return {x.stateName}.New();
     }}"));
  }

  private string GetTransitionConditions(Transition transition) {
    var evt = transition.Trigger.Event;
    if (_changeEvents.ContainsKey(evt)) {
      var expression = _changeEvents[evt].ChangeExpression.Body
        .Replace(" AND ", " && ")
        .Replace(" OR ", " || ")
        .Replace(" = ", " == ")
        .Replace(" <> ", " != ");

      return Regex.Replace(expression, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
    }

    if (_timeEvents.ContainsKey(evt)) {
      return $"WHEN: {_timeEvents[evt].When.Expr.Body}";
    }

    throw new Exception("Invalid event reference.");
  }

  public override string Write() {
    var className = InPascalCase(_class.Name);
    var properties = _class.OwnedAttribute.ToList();
      //.Where(x => x.XmiType.SingleOrDefault() == "uml:Property").ToList();

    var states = _behavior.GetStates();
    var behaviorName = _behavior.GetName();

    return @$"using System;
using System.Text;
using System.Linq;

namespace Eulynx;

class {className} {{
{string.Join("\n", properties.Select(x => $"public string {CodeGenerationItem.InPascalCase(x.Name)} {{ get; set; }}"))}

{_behavior.Write()}

    private {behaviorName} _state;

    public void Transition() {{
        _state = _state switch {{
{string.Join(",\n", states.Select(t =>
  string.Join(",\n", $"{t.name} => TransitionFrom{InPascalCase(t.subvertex.Name)}()")))}
      }};
    }}

{string.Join("\n", states.Select(fromState => GenerateTransition(behaviorName, fromState.subvertex)))}
}}";
  }
}
