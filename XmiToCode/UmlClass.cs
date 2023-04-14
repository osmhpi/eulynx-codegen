using System.Text.RegularExpressions;
using XmiToCode;

internal class UmlClass : CodeGenerationItem
{
  private PackagedElement _class;
  private readonly Dictionary<string, PackagedElement> _changeEvents;
  private readonly Dictionary<string, PackagedElement> _timeEvents;
  private readonly StateMachine _behavior;
  private readonly Dictionary<string, HashSet<string>> _allowedPropertyValues;
  private readonly Dictionary<string, string> _coercedValues;

  public UmlClass(PackagedElement classPackage, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
  {
    _class = classPackage;
    _changeEvents = changeEvents;
    _timeEvents = timeEvents;
    _behavior = new StateMachine(TransformSubverticesIntoCompoundStates(classPackage.StateMachine.Region), classPackage.StateMachine.Name, changeEvents, timeEvents);
    _allowedPropertyValues = new Dictionary<string, HashSet<string>>();
    _coercedValues = new Dictionary<string, string>();
  }

    public static OurRegion TransformSubverticesIntoCompoundStates(Region region) {
        var states = region.Subvertices.Select(
            x => new CompoundState(new List<PartialState>() { new PartialState(x, region) }, x.Regions.Select(TransformSubverticesIntoCompoundStates).SingleOrDefault())
        ).OfType<IState>().ToList();

        var transitions = region.Transitions
            .Select(transition => new OurTransition(
                states.Single(x => x.IsSourceOfTransition(transition)),
                states.Single(x => x.IsTargetOfTransition(transition)),
                transition))
            .ToList();

      return new OurRegion(region, states, transitions);
  }

//   private IEnumerable<CompoundState> FlattenStates(List<List<CompoundState>> regionStates) {
//     if (regionStates.Count == 0) {
//       yield break;
//     }

//     if (regionStates.Count == 1) {
//       foreach (var s in regionStates.First()) {
//         // s.Regions = FlattenRegions(s.Regions);
//         yield return s;
//       }
//       yield break;
//     }

//     var last = regionStates.Last();
//     var rest = regionStates.Take(regionStates.Count-1).ToList();

//     foreach (var regionAState in last) {
//       // regionAState.Regions = FlattenRegions(regionAState.Regions);
//       foreach (var regionBState in FlattenStates(rest)) {
//         var newState = regionBState.State.Append(regionAState).ToList();
//         yield return new CompoundState(newState);
//       }
//     }
//   }

//   private List<Region> FlattenRegions(List<Region> regions) {
//       return new List<Region> {
//         new Region {
//           Subvertices = FlattenStates(regions.Select(x => x.Subvertices.OfType<CompoundState>().ToList()).ToList()).OfType<Subvertex>().ToList()
//         }
//       };
//   }

  public string GetName() {
    return InPascalCase(_class.Name);
  }

  private string GenerateTransition(string name, IState fromState)
  {
    return $@"private {name} TransitionFrom{InPascalCase(fromState.Name)}() {{
      {GenerateConditions(fromState)}

      // Do not transition
      return _state;
    }}
";
  }

  private string GenerateConditions(IState fromState, bool skipParentTransitions=false)
  {
      var transitions = _behavior.GetTransitionsFromState(fromState, skipParentTransitions);

      var regularTransitions = transitions.Where(x => x.state.IsRegularState);
      var noTriggerConditions = regularTransitions.All(x => x.transition.Transition.Trigger == null);
      var regularConditions = string.Join("\n", noTriggerConditions
        ? regularTransitions.Select(x =>
            $@"{GetTransitionConstraints(x.transition)} {{
                {GenerateActivities(fromState, x)}
                return {x.stateName}.New();
            }}")
        : regularTransitions.Select(x =>
          $@"{GetTransitionChangeTriggerExpression(x.transition)} {{
            {GetTransitionConstraints(x.transition)} {{
                {GenerateActivities(fromState, x)}
                return {x.stateName}.New();
            }}
          }}"));

      var junctions = transitions.Where(x => x.state.IsJunction);
      var junctionConditions = string.Join("\n", junctions.Select(x =>
      $@"{GetTransitionChangeTriggerExpression(x.transition)} {{
        {GetTransitionConstraints(x.transition)} {{
          {GenerateActivities(fromState, x)}
          {GenerateConditions(x.state, true)}
        }}
      }}"));

      return regularConditions + junctionConditions;
  }

  private string GenerateActivities(IState fromState, (OurTransition transition, IState state, string stateName) x)
  {
      // TODO: These signatures look implausible.
      var exit = x.state.GenerateExit(x.state, x.transition);
      var transitionEffect = x.state.GenerateTransition(x.state, x.transition);
      var entry = x.state.GenerateEntry(fromState, x.transition);

      var result = string.Join("\n", exit, transitionEffect, entry);

      foreach (Match m in Regex.Matches(result, "(\\w+) = \"(\\w*)\"")) {
          var lhs = m.Groups[1].Value;
          var rhs = m.Groups[2].Value;
          RecordPossibleValueForProperty(lhs, rhs);
      }

      result = Regex.Replace(result, "(\\w+) = \"(\\w*)\"", m => $"{m.Groups[1].Value} = {LookupPropertyValueType(m.Groups[1].Value)}.{InPascalCase(m.Groups[2].Value)}");

      return result;
  }

  private string GetTransitionChangeTriggerExpression(OurTransition transition) {
    if (transition.Transition.Trigger != null) {
      // Regular transition
      string? result = null;

      var evt = transition.Transition.Trigger.Event;
      if (_changeEvents.ContainsKey(evt)) {
        var expression = _changeEvents[evt].ChangeExpression.Body
          .Replace(" AND ", " && ")
          .Replace(" OR ", " || ")
          .Replace(" NOT ", "!")
          .Replace(" = ", " == ")
          .Replace(" <> ", " != ");

        result = Regex.Replace(expression, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
      }

      if (_timeEvents.ContainsKey(evt)) {
        result = $"IsTimeoutExpired({InPascalCase(_timeEvents[evt].When.Expr.Body)})";
      } else {
        result = $"IsConditionChanged({result})";
      }

      if (result != null) {
          foreach (Match m in Regex.Matches(result, "(\\w+) (==|!=) (?<!\")(\\w*)(?!\")")) {
            var lhs = m.Groups[1].Value;
            var rhs = m.Groups[3].Value;
            RecordCoerceValues(lhs, rhs);
          }

          foreach (Match m in Regex.Matches(result, "(\\w+) (==|!=) \"(\\w*)\"")) {
            var lhs = m.Groups[1].Value;
            var rhs = m.Groups[3].Value;
            RecordPossibleValueForProperty(lhs, rhs);
          }
          result = Regex.Replace(result, "(\\w+) (==|!=) \"(\\w*)\"", m => $"{m.Groups[1].Value} {m.Groups[2].Value} {LookupPropertyValueType(m.Groups[1].Value)}.{InPascalCase(m.Groups[3].Value)}");

          return $"if ({result})";
      }

    }

    return "";
  }

  private string GetTransitionConstraints(OurTransition transition) {
    if (transition.Transition.OwnedRule != null && transition.Transition.OwnedRule.Specification != null) {
        var specification = transition.Transition.OwnedRule.Specification.Body;

        if (specification == "else") {
          return "else";
        }

        var expression = transition.Transition.OwnedRule.Specification.Body
          .Replace(" AND ", " && ")
          .Replace(" OR ", " || ")
          .Replace(" NOT ", "!")
          .Replace(" = ", " == ")
          .Replace(" <> ", " != ");

        expression = Regex.Replace(expression, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));

        foreach (Match m in Regex.Matches(expression, "(\\w+) (==|!=) (?<!\")(\\w*)(?!\")")) {
            var lhs = m.Groups[1].Value;
            var rhs = m.Groups[3].Value;
            RecordCoerceValues(lhs, rhs);
          }

        foreach (Match m in Regex.Matches(expression, "(\\w+) (==|!=) \"(\\w*)\"")) {
          var lhs = m.Groups[1].Value;
          var rhs = m.Groups[3].Value;
          RecordPossibleValueForProperty(lhs, rhs);
        }
        expression = Regex.Replace(expression, "(\\w+) (==|!=) \"(\\w*)\"", m => $"{m.Groups[1].Value} {m.Groups[2].Value} {LookupPropertyValueType(m.Groups[1].Value)}.{InPascalCase(m.Groups[3].Value)}");

        return $"if ({expression})";
    }
    return "";
  }

  private void RecordCoerceValues(string lhs, string rhs)
  {
      if (_coercedValues.ContainsKey(lhs) == false) {
        _coercedValues[lhs] = lhs;
      }

      if (_coercedValues.ContainsKey(rhs) == false) {
        _coercedValues[rhs] = rhs;
      }

      var lhsPointsTo = _coercedValues[lhs];
      var rhsPointsTo = _coercedValues[rhs];

      foreach (var keyValue in _coercedValues) {
        if (keyValue.Value == lhsPointsTo) {
          _coercedValues[keyValue.Key] = rhsPointsTo;
        }
      }
  }

  private void RecordPossibleValueForProperty(string lhs, string rhs)
  {
      if (_allowedPropertyValues.ContainsKey(lhs) == false) {
        _allowedPropertyValues[lhs] = new HashSet<string>();
      }

      _allowedPropertyValues[lhs].Add(rhs);
  }

  public override string Write() {
    var className = InPascalCase(_class.Name);
    var properties = _class.OwnedAttribute
      //.Where(x => x.XmiType.SingleOrDefault() == "uml:Property")
      .ToList();

    var states = _behavior.GetStates();
    var behaviorName = _behavior.GetName();

    // Initialize property types
    {
      foreach (var property in properties) {
        _allowedPropertyValues.Add(InPascalCase(property.Name), new HashSet<string>());
      }
      // Perform a dry run of generating transitions (which includes comparisons and assignments,
      // where property types are coerced)
      var ignored = states.Select(fromState => GenerateTransition(behaviorName, fromState.subvertex)).ToList();
    }

    return @$"namespace Eulynx;

public class {className} {{
    {_behavior.Write()}

    private {behaviorName} _state;
    public {behaviorName} State {{ get {{ return _state; }} }}

    public {className}() {{
      {GenerateInitialEntry(_behavior)}
      _state = {behaviorName}.New();
    }}

    private bool IsTimeoutExpired(object timeout) {{
        // TODO
        return false;
    }}

    private bool IsConditionChanged(bool condition) {{
        // TODO: Keep in mind that this should only evaluate to true once
        return condition;
    }}

    public void Transition() {{
        _state = _state switch {{
            {string.Join(",\n", states.Select(t =>
              string.Join(",\n", $"{t.name} => TransitionFrom{InPascalCase(t.subvertex.Name)}()")))}
      }};
    }}

    {string.Join("\n", states.Select(fromState => GenerateTransition(behaviorName, fromState.subvertex)))}

    {string.Join("\n", properties.Select(x => $"public {LookupPropertyValueType(InPascalCase(x.Name))} {CodeGenerationItem.InPascalCase(x.Name)} {{ get; set; }}"))}

    {GeneratePropertyValueTypes()}
}}
";
  }

  private string GenerateInitialEntry(StateMachine behavior)
  {
      var (x, y, z) = behavior.GetTransitionsFromState(behavior.InitialState).Single();
      var entry = y.GenerateEntry(null, null);

      foreach (Match m in Regex.Matches(entry, "(\\w+) = \"(\\w*)\"")) {
          var lhs = m.Groups[1].Value;
          var rhs = m.Groups[2].Value;
          RecordPossibleValueForProperty(lhs, rhs);
      }

      entry = Regex.Replace(entry, "(\\w+) = \"(\\w*)\"", m => $"{m.Groups[1].Value} = {LookupPropertyValueType(m.Groups[1].Value)}.{InPascalCase(m.Groups[2].Value)}");

      return entry;
  }

  private string LookupPropertyValueType(string v)
  {
    if (_coercedValues.ContainsKey(v) == false) {
      _coercedValues[v] = v;
    }
    var result = _coercedValues[v];

    if (_allowedPropertyValues[result].Count == 0) {
      return "bool";
    }

    return $"{result}Value";
  }

  private string GeneratePropertyValueTypes()
  {
    return string.Join("\n", _allowedPropertyValues.Select(x => {
      // Collect all of the field values that point to the same alias
      var aliases = _coercedValues.ContainsKey(x.Key)
          ? _coercedValues.Keys.Where(key => _coercedValues[key] == _coercedValues[x.Key])
            .SelectMany(key => _allowedPropertyValues[key]).ToHashSet() : _allowedPropertyValues[x.Key];

      if (aliases.Count == 0) {
        return "";
      }

      return $@"
        public enum {x.Key}Value {{
            {string.Join(",\n", aliases.Select(InPascalCase))}
        }}";
    }));
  }

  internal async Task Generate()
  {
    using var file = File.Create($"../Eulynx/{GetName()}.cs");
    using var writer = new StreamWriter(file);
    await writer.WriteAsync(Write());
  }
}
