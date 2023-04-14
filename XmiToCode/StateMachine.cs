using XmiToCode;

class StateMachine : CodeGenerationItem
{
    public OurRegion Region { get { return _region; } }
    public IState InitialState { get { return _initialState; } }
    private readonly OurRegion _region;
    private readonly string _name;
    private readonly IState _initialState;
    private readonly List<IState> _junctions;
    private readonly List<IState> _states;
    private readonly List<StateMachine> _childStateMachines;
    private readonly Dictionary<string, PackagedElement> _changeEvents;
    private readonly Dictionary<string, PackagedElement> _timeEvents;

    public StateMachine(OurRegion region, string name, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
    {
        _region = region;
        _name = name;
        _changeEvents = changeEvents;
        _timeEvents = timeEvents;

        _initialState = region.InitialState;
        _junctions = region.States.Where(x => x.IsJunction).ToList();
        _states = region.States.Where(x => x.IsRegularState).ToList();

        _childStateMachines = _states
            .Where(x => x.InternalStateMachine != null)
            .Select(x => x.InternalStateMachine!).ToList();
    }

    public IEnumerable<(OurTransition transition, IState state, string stateName)> GetTransitionsFromState(IState fromState, bool skipParentTransitions = false) {
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
}
