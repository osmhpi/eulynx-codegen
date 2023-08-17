using XmiToCode;

public record StateName(IState Subvertex, string Name);

public class StateMachine : CodeGenerationItem
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

    public TransitionFunction GenerateTransitionFunction(string thisName, IState fromState, ClassInfo theRootBehaviorName, string name, string behaviorName, DataTypeHelper dataTypes, ProgramContext context)
    {
        return new TransitionFunction(theRootBehaviorName, name, GenerateConditions(thisName, fromState, dataTypes, context, theRootBehaviorName));
    }

    public List<ICodeTransition> GenerateConditions(string thisName, IState fromState, DataTypeHelper dataTypes, ProgramContext context, ClassInfo classInfo, bool skipParentTransitions=false)
    {
        var transitions = GetTransitionsFromState(thisName, fromState, skipParentTransitions);

        var regularTransitions = transitions.Where(x => x.state.IsRegularState);
        var noTriggerConditions = regularTransitions.All(x => x.transition.SingleTransition.Trigger == null);

        return transitions.Select(x => x.transition.GenerateTransition(thisName, fromState, x.state, x.stateName, dataTypes, noTriggerConditions, this, context, classInfo)).ToList();
    }

    public string GetName() {
        return new TypeIdentifier(_name).Name;
    }

    public IEnumerable<StateName> GetStates(string thisName) {
        foreach (var (subvertex, name) in _childStateMachines.SelectMany(x => x.StateMachine.GetStates(x.State.Name))) {
            yield return new StateName(subvertex, $"{thisName}.{name}");
        }

        foreach (var state in _states) {
            yield return new StateName(state, $"{thisName}.{state.Name}");
        }
    }

    private IBehaviorRecord MakeSubrecord(string recordName, ClassInfo className, IState x, DataTypeHelper dataTypes, ProgramContext context) {
        if (x.InternalStateMachine != null) {
            return x.InternalStateMachine.ParseStateRecord(x, x.Name, recordName, className, dataTypes, context);
        } else {
            return new SimpleBehaviorRecord(x, x.Name, recordName, className);
        }
    }

    private BehaviorRecord ParseStateRecord(IState? x, string name, string? parentBehaviorName, ClassInfo className, DataTypeHelper dataTypes, ProgramContext context) {
        var newContext = new BlockContext(context); // , overrideInstanceReference: "This"

        var subrecords = _states.Select(x => MakeSubrecord(name, className, x, dataTypes, context)).ToList();
        var initialTransition = GetTransitionsFromState((parentBehaviorName != null ? parentBehaviorName + "." : "") + name, _initialState).Single();
        var initializer = initialTransition.transition.GenerateTransition(name,
            _initialState, initialTransition.state, initialTransition.stateName,
            dataTypes, false, this, newContext, className);

        return new BehaviorRecord(x, this, name, parentBehaviorName, className, initializer, subrecords);
    }

    public BehaviorRecord Parse(ClassInfo className, DataTypeHelper dataTypes, ClassContext context) {
        return ParseStateRecord(null, GetName(), null, className, dataTypes, context);
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

    internal IEnumerable<TransitionFunction> ParseTransitionFunctions(ClassInfo theRootBehaviorName, DataTypeHelper dataTypes, ProgramContext context)
    {
        var behaviorName = GetName();
        var states = GetStates(behaviorName);
        return states.Select(fromState => GenerateTransitionFunction(behaviorName, fromState.Subvertex, theRootBehaviorName, fromState.Name, behaviorName, dataTypes, context));
    }
}
