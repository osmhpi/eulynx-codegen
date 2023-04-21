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
    private readonly List<(IState State, StateMachine StateMachine)> _childStateMachines;

    public StateMachine(Region region, string name)
    {
        _region = region;
        _name = name;

        _initialState = region.InitialState;
        _states = region.States.Where(x => x.IsRegularState).ToList();

        _childStateMachines = _states
            .Where(x => x.InternalStateMachine != null)
            .Select(x => (x, x.InternalStateMachine!)).ToList();
    }

    public IEnumerable<(Transition transition, IState state, string stateName)> GetTransitionsFromState(string thisName, IState fromState, bool skipParentTransitions = false) {
        var transitionsOnCurrentLevel = _region.Transitions.Where(x => x.From == fromState)
            .Select(x => (x, x.To, $"{thisName}.{x.To.Name}"));

        // Does fromState match one of our child state machines?
        var childStateMachineTransitions = _states
            .Where(x => x.InternalStateMachine != null)
            .Select(state => new {
                FromState = state,
                ChildStateMachine = state.InternalStateMachine!,
                Transitions = state.InternalStateMachine!.GetTransitionsFromState(state.Name, fromState, skipParentTransitions).ToList()
            })
            .Where(x => x.Transitions.Any())
            .ToList();

        return childStateMachineTransitions.SelectMany(childStateMachineTransition => {
            var result = childStateMachineTransition.Transitions.Select(x => (x.transition, x.state, $"{thisName}.{x.stateName}"));

            if (skipParentTransitions) {
                return result;
            }

            // Prepend the transitions from the enclosing state of the child state machine
            return _region.Transitions.Where(x => x.From == childStateMachineTransition.FromState)
                    .Select(x => (x, x.To, $"{thisName}.{x.To.Name}"))
                    .Concat(result);
        }).Concat(transitionsOnCurrentLevel);
    }

    public string GenerateTransitionFunction(string thisName, IState fromState, string theRootBehaviorName, string name, string behaviorName, DataTypeHelper dataTypes)
    {
        return $@"private {theRootBehaviorName} TransitionFrom{name.Replace(".", "__")}() {{
        {GenerateConditions(thisName, fromState, dataTypes)}

        // Do not transition
        return _state;
        }}
";
    }

    private string GenerateConditions(string thisName, IState fromState, DataTypeHelper dataTypes, bool skipParentTransitions=false)
    {
        var transitions = GetTransitionsFromState(thisName, fromState, skipParentTransitions);

        var regularTransitions = transitions.Where(x => x.state.IsRegularState);
        var noTriggerConditions = regularTransitions.All(x => x.transition.SingleTransition.Trigger == null);
        var regularConditions = string.Join("\n", noTriggerConditions
            ? regularTransitions.Select(x =>
                $@"{x.transition.GetTransitionConstraints(dataTypes)} {{
                    {GenerateActivities(fromState, x, dataTypes)}
                    return {x.stateName}.New(this);
                }}")
            : regularTransitions.Select(x =>
                $@"{GetTransitionChangeTriggerExpression(x.transition, dataTypes)} {{
                    {x.transition.GetTransitionConstraints(dataTypes)} {{
                        {GenerateActivities(fromState, x, dataTypes)}
                        return {x.stateName}.New(this);
                    }}
                }}"));

          var junctions = transitions.Where(x => x.state.IsJunction);
          var junctionConditions = string.Join("\n", junctions.Select(x =>
          $@"{GetTransitionChangeTriggerExpression(x.transition, dataTypes)} {{
            {x.transition.GetTransitionConstraints(dataTypes)} {{
              {GenerateActivities(fromState, x, dataTypes)}
              {GenerateConditions(thisName, x.state, dataTypes, true)}
            }}
          }}"));

        return regularConditions + junctionConditions;
    }

    public string GetName() {
        return InPascalCase(_name);
    }

    public IEnumerable<(IState subvertex, string name)> GetStates(string thisName) {
        foreach (var (subvertex, name) in _childStateMachines.SelectMany(x => x.StateMachine.GetStates(x.State.Name))) {
            yield return (subvertex, $"{thisName}.{name}");
        }

        foreach (var state in _states) {
            yield return (state, $"{thisName}.{state.Name}");
        }
    }

    public string GenerateActivities(IState fromState, (Transition transition, IState state, string stateName) x, DataTypeHelper dataTypes, string? prefixAssignments = null)
    {
        // TODO: These signatures look implausible.
        var exit = x.state.GenerateExit(x.state, x.transition);
        var transitionEffect = x.state.GenerateTransition(x.state, x.transition);
        var entry = x.state.GenerateEntry(fromState, x.transition);

        var result = string.Join("\n", new [] {exit, transitionEffect, entry}.Where(x => x != null));

        foreach (Match m in Regex.Matches(result, "(\\w+) = \"([^\"]*)\"")) {
            var lhs = m.Groups[1].Value;
            var rhs = m.Groups[2].Value;
            dataTypes.RecordPossibleValueForProperty(lhs, rhs);
        }

        result = Regex.Replace(result, "(\\w+) = \"([^\"]*)\"",
            m => $"{m.Groups[1].Value} = {dataTypes.LookupPropertyValueType(m.Groups[1].Value)}.{DataTypeHelper.GenerateEnumMemberName(m.Groups[2].Value)}");

        if (prefixAssignments != null) {
            result = Regex.Replace(result, "(\\w+)(.*)",
                m => $"{prefixAssignments}.{m.Groups[1].Value}{m.Groups[2].Value}");
        }

        return result;
    }

    private string GetTransitionChangeTriggerExpression(Transition transition, DataTypeHelper dataTypes) {
        if (transition.SingleTransition.Trigger != null) {
            // Regular transition
            string? result = null;

            var evt = transition.SingleTransition.Trigger.Event;
            if (evt != null) {
                if (dataTypes.ChangeEvents.ContainsKey(evt)) {
                    var expression = dataTypes.ChangeEvents[evt].ChangeExpression.Body
                        .ReplaceLineEndings(" ")
                        .Replace("AND ", " && ")
                        .Replace(" OR ", " || ")
                        .Replace("NOT ", "!")
                        .Replace(" = ", " == ")
                        .Replace(" <> ", " != ");

                    result = Regex.Replace(expression, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
                    result = $"IsConditionChanged({result})";
                } else if (dataTypes.TimeEvents.ContainsKey(evt)) {
                    result = $"IsTimeoutExpired({InPascalCase(dataTypes.TimeEvents[evt].When.Expr.Body)})";
                } else if (dataTypes.PackageEvents.ContainsKey(evt)) {
                    result = $"IsMessageArrived(\"{dataTypes.PackageEvents[evt].Name}\")";
                } else {
                    throw new NotImplementedException();
                }
            } else {
                // Event is null, interesting, moving on...
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

    private string MakeSubrecord(string recordName, string className, IState x, DataTypeHelper dataTypes) {
        if (x.InternalStateMachine != null) {
            return x.InternalStateMachine.MakeStateRecord(x.Name, recordName, className, dataTypes);
        } else {
            return $@"public record {x.Name}() : {recordName}() {{
                public static new {x.Name} New({className} This) => new {x.Name}();
            }}";
        }
    }

    private string MakeStateRecord(string name, string parentBehaviorName, string className, DataTypeHelper dataTypes) {
        var subrecords = _states.Select(x => MakeSubrecord(name, className, x, dataTypes));
        var initialTransition = GetTransitionsFromState(name, _initialState).Single();
        var activities = GenerateActivities(_initialState, initialTransition, dataTypes, "This");

        return @$"public record {name} : {parentBehaviorName} {{
        {string.Join("\n    ", subrecords)}

    public static new {name} New({className} This) {{
        {activities}
        return {initialTransition.stateName}.New(This);
    }}

    private {name}() {{}}
}}
";
    }

    public override string Write()
    {
        throw new NotImplementedException();
    }

    public string Write(string className, DataTypeHelper dataTypes) {
        return MakeStateRecord(GetName(), "object", className, dataTypes);
    }

    public IEnumerable<(CompoundState FromState, UmlTransition Transition)> GetTransitionsOriginatingFromAnyState() {
        return _states.OfType<CompoundState>()
            .SelectMany(state =>
                state.PartialStates.SelectMany(partial =>
                    partial.EnclosingRegion.Transitions
                        .Where(transition => state.IsSourceOfTransition(transition))
                        .Select(transition => (state, transition))))
            .Concat( // Recurse
                _childStateMachines.SelectMany(child => child.StateMachine.GetTransitionsOriginatingFromAnyState())
            );
    }

    internal string GenerateTransitionFunctions(string theRootBehaviorName, DataTypeHelper dataTypes)
    {
        var behaviorName = GetName();
        var states = GetStates(behaviorName);

        return $@"
    public void Transition() {{
        _state = _state switch {{
            {string.Join(",\n", states.Select(t =>
              string.Join(",\n", $"{t.name} => TransitionFrom{t.name.Replace(".", "__")}()")))}
      }};
    }}

    {string.Join("\n", states.Select(fromState => GenerateTransitionFunction(behaviorName, fromState.subvertex, theRootBehaviorName, fromState.name, behaviorName, dataTypes)))}";
    }
}
