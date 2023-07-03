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
        {GenerateConditions(thisName, fromState, dataTypes, "this")}

        // Do not transition
        return _state;
        }}
";
    }

    public string GenerateConditions(string thisName, IState fromState, DataTypeHelper dataTypes, string instanceReference, bool skipParentTransitions=false, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal = null)
    {
        var transitions = GetTransitionsFromState(thisName, fromState, skipParentTransitions);

        var regularTransitions = transitions.Where(x => x.state.IsRegularState);
        var noTriggerConditions = regularTransitions.All(x => x.transition.SingleTransition.Trigger == null);

        return string.Join("\n", transitions.Select(x => x.transition.GenerateTransition(thisName, fromState, x.state, x.stateName, dataTypes, noTriggerConditions, this, attributesOfCurrentSignal, instanceReference)));
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
        var initializer = initialTransition.transition.GenerateTransition(name,
            _initialState, initialTransition.state, initialTransition.stateName,
            dataTypes, false, this, null, "This");

        return @$"public record {name} : {parentBehaviorName} {{
        {string.Join("\n    ", subrecords)}

    public static new {name} New({className} This) {{
        {initializer}
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

    {JoinLines(states.Select(fromState => GenerateTransitionFunction(behaviorName, fromState.subvertex, theRootBehaviorName, fromState.name, behaviorName, dataTypes)))}";
    }
}
