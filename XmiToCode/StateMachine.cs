using System.Text.RegularExpressions;
using XmiToCode;

class StateMachine : CodeGenerationItem
{
    public Region Region { get { return _region; } }
    public IState InitialState { get { return _initialState; } }
    private readonly Region _region;
    private readonly string _name;
    private readonly IState _initialState;
    private readonly List<IState> _states;
    private readonly List<StateMachine> _childStateMachines;
    private readonly Dictionary<string, PackagedElement> _changeEvents;
    private readonly Dictionary<string, PackagedElement> _timeEvents;

    public StateMachine(Region region, string name, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
    {
        _region = region;
        _name = name;
        _changeEvents = changeEvents;
        _timeEvents = timeEvents;

        _initialState = region.InitialState;
        _states = region.States.Where(x => x.IsRegularState).ToList();

        _childStateMachines = _states
            .Where(x => x.InternalStateMachine != null)
            .Select(x => x.InternalStateMachine!).ToList();
    }

    public IEnumerable<(Transition transition, IState state, string stateName)> GetTransitionsFromState(IState fromState, bool skipParentTransitions = false) {
        // Does fromState match one of our child state machines?
        var childStateMachineTransitions = _states
            .Where(x => x.InternalStateMachine != null)
            .Select(state => new {
                FromState = state,
                ChildStateMachine = state.InternalStateMachine!,
                Transitions = state.InternalStateMachine!.GetTransitionsFromState(fromState, skipParentTransitions).ToList()
            })
            .Where(x => x.Transitions.Any())
            .ToList();

        if (childStateMachineTransitions.Count > 0) {
            return childStateMachineTransitions.SelectMany(childStateMachineTransition => {
                var result = childStateMachineTransition.Transitions.Select(x => (x.transition, x.state, $"{GetName()}.{x.stateName}"));

                if (skipParentTransitions) {
                    return result;
                }

                // Prepend the transitions from the enclosing state of the child state machine
                return _region.Transitions.Where(x => x.From == childStateMachineTransition.FromState)
                        .Select(x => (x, x.To, $"{GetName()}.{x.To.Name}"))
                        .Concat(result);
            });
        }

        return _region.Transitions.Where(x => x.From == fromState)
            .Select(x => (x, x.To, $"{GetName()}.{x.To.Name}"));
    }

    public string GenerateTransitionFunction(IState fromState, string name, string behaviorName, DataTypeHelper dataTypes)
    {
        return $@"private {name} TransitionFrom{name.Replace(".", "__")}() {{
        {GenerateConditions(fromState, dataTypes)}

        // Do not transition
        return _state;
        }}
";
    }

    private string GenerateConditions(IState fromState, DataTypeHelper dataTypes, bool skipParentTransitions=false)
    {
        var transitions = GetTransitionsFromState(fromState, skipParentTransitions);

        var regularTransitions = transitions.Where(x => x.state.IsRegularState);
        var noTriggerConditions = regularTransitions.All(x => x.transition.SingleTransition.Trigger == null);
        var regularConditions = string.Join("\n", noTriggerConditions
            ? regularTransitions.Select(x =>
                $@"{x.transition.GetTransitionConstraints(dataTypes)} {{
                    {GenerateActivities(fromState, x, dataTypes)}
                    return {x.stateName}.New();
                }}")
            : regularTransitions.Select(x =>
                $@"{GetTransitionChangeTriggerExpression(x.transition, dataTypes)} {{
                    {x.transition.GetTransitionConstraints(dataTypes)} {{
                        {GenerateActivities(fromState, x, dataTypes)}
                        return {x.stateName}.New();
                    }}
                }}"));

          var junctions = transitions.Where(x => x.state.IsJunction);
          var junctionConditions = string.Join("\n", junctions.Select(x =>
          $@"{GetTransitionChangeTriggerExpression(x.transition, dataTypes)} {{
            {x.transition.GetTransitionConstraints(dataTypes)} {{
              {GenerateActivities(fromState, x, dataTypes)}
              {GenerateConditions(x.state, dataTypes, true)}
            }}
          }}"));

        return regularConditions + junctionConditions;
    }

    public string GetName() {
        return InPascalCase(_name);
    }

    public IEnumerable<(IState subvertex, string name)> GetStates() {
        var hasSubstates = false;
        foreach (var (subvertex, name) in _childStateMachines.SelectMany(x => x.GetStates())) {
            yield return (subvertex, $"{GetName()}.{name}");
            hasSubstates = true;
        }

        if (!hasSubstates) {
            foreach (var state in _states) {
                yield return (state, $"{GetName()}.{state.Name}");
            }
        }
    }

    private string GenerateActivities(IState fromState, (Transition transition, IState state, string stateName) x, DataTypeHelper dataTypes)
    {
        // TODO: These signatures look implausible.
        var exit = x.state.GenerateExit(x.state, x.transition);
        var transitionEffect = x.state.GenerateTransition(x.state, x.transition);
        var entry = x.state.GenerateEntry(fromState, x.transition);

        var result = string.Join("\n", exit, transitionEffect, entry);

        foreach (Match m in Regex.Matches(result, "(\\w+) = \"(\\w*)\"")) {
            var lhs = m.Groups[1].Value;
            var rhs = m.Groups[2].Value;
            dataTypes.RecordPossibleValueForProperty(lhs, rhs);
        }

        result = Regex.Replace(result, "(\\w+) = \"(\\w*)\"", m => $"{m.Groups[1].Value} = {dataTypes.LookupPropertyValueType(m.Groups[1].Value)}.{InPascalCase(m.Groups[2].Value)}");

        return result;
    }

    private string GetTransitionChangeTriggerExpression(Transition transition, DataTypeHelper dataTypes) {
        if (transition.SingleTransition.Trigger != null) {
            // Regular transition
            string? result = null;

            var evt = transition.SingleTransition.Trigger.Event;
            if (_changeEvents.ContainsKey(evt)) {
                var expression = _changeEvents[evt].ChangeExpression.Body
                .ReplaceLineEndings(" ")
                .Replace("AND ", " && ")
                .Replace(" OR ", " || ")
                .Replace("NOT ", "!")
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
                    dataTypes.RecordCoalesceValues(lhs, rhs);
                }

                foreach (Match m in Regex.Matches(result, "(\\w+) (==|!=) \"(\\w*)\"")) {
                    var lhs = m.Groups[1].Value;
                    var rhs = m.Groups[3].Value;
                    dataTypes.RecordPossibleValueForProperty(lhs, rhs);
                }
                result = Regex.Replace(result, "(\\w+) (==|!=) \"(\\w*)\"", m => $"{m.Groups[1].Value} {m.Groups[2].Value} {dataTypes.LookupPropertyValueType(m.Groups[1].Value)}.{InPascalCase(m.Groups[3].Value)}");

                return $"if ({result})";
            }
        }

        return "";
    }

    private string MakeSubrecord(string recordName, IState x) {
        if (x.InternalStateMachine != null) {
            return x.InternalStateMachine.MakeStateRecord(x.Name, recordName);
        } else {
            return $@"public record {x.Name}() : {recordName}() {{
                public static new {x.Name} New() => new {x.Name}();
            }}";
        }
    }

    private string MakeStateRecord(string name, string basename) {
        var subrecords = _states.Select(x => MakeSubrecord(name, x));
        var (x, y, z) = GetTransitionsFromState(_initialState).Single();

        return @$"public record {name} : {basename} {{
        {string.Join("\n    ", subrecords)}

    public static new {name} New() => {z}.New();

    private {name}() {{}}
}}
";
    }

    public override string Write()
    {
        return MakeStateRecord(InPascalCase(_name), "object");
    }

    internal string GenerateTransitionFunctions(DataTypeHelper dataTypes)
    {
        var states = GetStates();
        var behaviorName = GetName();

        return $@"
    public void Transition() {{
        _state = _state switch {{
            {string.Join(",\n", states.Select(t =>
              string.Join(",\n", $"{t.name} => TransitionFrom{t.name.Replace(".", "__")}()")))}
      }};
    }}

    {string.Join("\n", states.Select(fromState => GenerateTransitionFunction(fromState.subvertex, fromState.name, behaviorName, dataTypes)))}";
    }
}
