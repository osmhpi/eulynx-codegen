using XmiToCode.Classes;
using XmiToCode.Codegen;
using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;
using XmiToCode.Codegen.Model;

namespace XmiToCode.Transformation.Model;

public record StateName(IState Subvertex, string Name);

public class StateMachine
{
    public IRegion Region { get { return _region; } }
    public IState InitialState { get { return _initialState; } }
    private readonly IRegion _region;
    private readonly string _name;
    private readonly IState _initialState;
    private readonly List<IState> _states;
    private readonly List<(IState State, StateMachine StateMachine)> _childStateMachines;

    public StateMachine(IRegion region, string name)
    {
        _region = region;
        _name = name;

        _initialState = region.InitialState;
        _states = region.States.Where(x => x.IsRegularState).ToList();

        _childStateMachines = (
            from state in _states
            where state.Regions.Any()
            select (state, new StateMachine(state.Regions.Single(), state.Name))
        ).ToList();
    }

    // public IEnumerable<(Transition transition, IState state, string stateName)> GetTransitionsFromState(string thisName, IState fromState, bool skipParentTransitions = false) {
    //     var transitionsOnCurrentLevel = _region.Transitions.Where(x => x.From == fromState)
    //         .Select(x => (x, x.To, $"{thisName}.{x.To.Name}"));

    //     // Does fromState match one of our child state machines?
    //     var childStateMachineTransitions = _states
    //         .Where(x => x.InternalStateMachine != null)
    //         .Select(state => new {
    //             FromState = state,
    //             ChildStateMachine = state.InternalStateMachine!,
    //             Transitions = state.InternalStateMachine!.GetTransitionsFromState(state.Name, fromState, skipParentTransitions).ToList()
    //         })
    //         .Where(x => x.Transitions.Any())
    //         .ToList();

    //     return childStateMachineTransitions.SelectMany(childStateMachineTransition => {
    //         var result = childStateMachineTransition.Transitions.Select(x => (x.transition, x.state, $"{thisName}.{x.stateName}"));

    //         if (skipParentTransitions) {
    //             return result;
    //         }

    //         // Prepend the transitions from the enclosing state of the child state machine
    //         return _region.Transitions.Where(x => x.From == childStateMachineTransition.FromState)
    //             .Select(x => (x, x.To, $"{thisName}.{x.To.Name}"))
    //             .Concat(result);
    //     }).Concat(transitionsOnCurrentLevel);
    // }

    // public TransitionFunction ParseTransitionFunction(string thisName, IState fromState, ClassInfo theRootBehaviorName, string name, IInstructionContext context)
    // {
    //     return new TransitionFunction(theRootBehaviorName, name, ParseTransitions(thisName, fromState, context, theRootBehaviorName));
    // }

    // public List<ICodeTransition> ParseTransitions(string thisName, IState fromState, IInstructionContext context, ClassInfo classInfo, bool skipParentTransitions=false)
    // {
    //     var transitions = GetTransitionsFromState(thisName, fromState, skipParentTransitions);

    //     var regularTransitions = transitions.Where(x => x.state.IsRegularState);
    //     var noTriggerConditions = regularTransitions.All(x => x.transition.SingleTransition.Trigger == null);

    //     return transitions.Select(x => x.transition.ParseTransition(thisName, fromState, x.state, x.stateName, noTriggerConditions, this, context, classInfo)).ToList();
    // }

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

    private static IBehaviorRecord MakeSubrecord(string recordName, ClassInfo className, IState state, IInstructionContext context) {
        if (state.Regions.SingleOrDefault() != null) {
            return ParseStateRecord(state, state.Regions.Single(), state.Name, recordName, className, context);
        } else {
            return new SimpleBehaviorRecord(state, state.Name, recordName, className);
        }
    }

    private static IBehaviorRecord ParseStateRecord(IState state, IRegion region, string name, string recordName, ClassInfo className, IInstructionContext context)
    {
        throw new NotImplementedException();
    }

    // private BehaviorRecord ParseStateRecord(IState? x, string name, string? parentBehaviorName, ClassInfo className, IInstructionContext context) {
    //     var newContext = new BlockContext(context);

    //     var subrecords = _states.Select(x => MakeSubrecord(name, className, x, context)).ToList();
    //     var (transition, state, stateName) = GetTransitionsFromState((parentBehaviorName != null ? parentBehaviorName + "." : "") + name, _initialState).Single();
    //     var initializer = transition.ParseTransition(name,
    //         _initialState, state, stateName,
    //         false, this, newContext, className);

    //     return new BehaviorRecord(x, this, name, parentBehaviorName, className, initializer, subrecords);
    // }

    // public BehaviorRecord Parse(ClassInfo className, ClassContext context) {
    //     return ParseStateRecord(null, GetName(), null, className, context);
    // }

    // public IEnumerable<(CompoundState FromState, UmlTransition Transition)> GetTransitionsOriginatingFromAnyState() {
    //     return _states.OfType<CompoundState>()
    //         .SelectMany(state =>
    //             state.PartialStates.SelectMany(partial =>
    //                 partial.EnclosingRegion.Transitions
    //                     .Where(transition => state.IsSourceOfTransition(transition))
    //                     .Select(transition => (state, transition))))
    //         .Concat( // Recurse
    //             _childStateMachines.SelectMany(child => child.StateMachine.GetTransitionsOriginatingFromAnyState())
    //         );
    // }

    // internal IEnumerable<TransitionFunction> ParseTransitionFunctions(ClassInfo theRootBehaviorName, IInstructionContext context)
    // {
    //     var behaviorName = GetName();
    //     var states = GetStates(behaviorName);
    //     return states.Select(fromState => ParseTransitionFunction(behaviorName, fromState.Subvertex, theRootBehaviorName, fromState.Name, context));
    // }
}
