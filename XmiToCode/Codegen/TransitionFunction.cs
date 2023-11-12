using XmiToCode.Instructions;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.Model;

namespace XmiToCode.Codegen;

public record TransitionFunction(
    TypeIdentifier TheRootBehaviorName,
    TypeIdentifier ClassName,
    string Name,
    List<ICodeTransition> Transitions
) {
    public static IEnumerable<(Transition Transition, IState ToState, string ToStateName)> GetAllTransitionsFromState(IRegion region, string thisName, IState fromState, bool skipParentTransitions = false) {
        var transitionsOnCurrentLevel = region.Transitions
            .Where(x => x is not InitialTransition)
            .Where(x => fromState.IsSourceOfTransitions(x.Transitions.ToArray()))
            .Select(x => (x, x.To, $"{thisName}.{x.To.Name}"))
            .ToList();

        // Does fromState match one of our child state machines?
        var childStateMachineTransitions = region.States
            .Where(x => x.Regions.Any())
            // we can safely assume that the initial state does not
            // transition out of the child state machine
            .Where(x => !x.IsInitialState)
            .Select(state => new {
                FromState = state,
                ChildStateMachine = state.Regions.Single(),
                Transitions = GetAllTransitionsFromState(state.Regions.Single(), state.Name, fromState, skipParentTransitions).ToList()
            })
            .Where(x => x.Transitions.Any())
            .ToList();

        return childStateMachineTransitions.SelectMany(childStateMachineTransition => {
            var result = childStateMachineTransition.Transitions.Select(x => (x.Transition, x.ToState, $"{thisName}.{x.ToStateName}"));

            if (skipParentTransitions) {
                return result;
            }

            // Prepend the transitions from the enclosing state of the child state machine
            return region.Transitions.Where(x => x.From == childStateMachineTransition.FromState)
                .Select(x => (x, x.To, $"{thisName}.{x.To.Name}"))
                .Concat(result);
        }).Concat(transitionsOnCurrentLevel);
    }

    public static TransitionFunction Create(TypeIdentifier className, TypeIdentifier behaviorName, IState fromState, IRegion region) {
        var thisName = "this";
        var transitions = GetCodeTransitions(region, thisName, fromState, className, false);

        return new TransitionFunction(
            behaviorName,
            className,
            fromState.Name,
            transitions);
    }

    public static List<ICodeTransition> GetCodeTransitions(IRegion region, string thisName, IState fromState, TypeIdentifier className, bool skipParentTransitions) {
        var transitions = GetAllTransitionsFromState(region, fromState.Name, fromState, skipParentTransitions).ToList();

        // TODO
        // var regularTransitions = transitions.Where(x => x.ToState.IsRegularState);
        // var noTriggerConditions = regularTransitions.All(x => x.Transition.SingleTransition.Trigger == null);
        var noTriggerConditions = false;

        return transitions.Select(x => CreateCodeTransition(x.Transition, region, thisName, fromState, x.ToState, x.ToStateName, noTriggerConditions, className)).ToList();
    }

    public static List<Instruction> SelectActivities(IState fromState, IState toState, Transition transition)
    {
        // TODO: These signatures look implausible.
        // TODO: Partial transitions, exit/entry for compound states
        var exit = fromState.Exit;
        var transitionEffect = transition.Instructions;
        var entry = toState.Entry;

        return new [] {exit, transitionEffect, entry}.SelectMany(x => x).ToList();
    }

    public static ICodeTransition CreateCodeTransition(
        Transition theTransition,
        IRegion region,
        string thisName,
        IState fromState,
        IState toState,
        string toStateName,
        bool noTriggerConditions,
        TypeIdentifier className) {

        if (toState.IsRegularState) {
            if (noTriggerConditions) {
                return new CodeTransition(toStateName,
                    SelectActivities(fromState, toState, theTransition), theTransition.Constraints, theTransition);
            } else {
                return new CodeTransition(toStateName,
                    SelectActivities(fromState, toState, theTransition), theTransition.Constraints, theTransition);
            }
        }

        if (toState.IsJunction) {
            var subsequentTransitions = GetCodeTransitions(region, thisName, toState, className, true);
            return new JunctionCodeTransition(
                SelectActivities(fromState, toState, theTransition),
                subsequentTransitions,
                theTransition.Constraints,
                theTransition
            );
        }

        throw new NotImplementedException();
    }
}

public interface ICodeTransition {
    public Transition Transition { get; }
    public List<Constraint> Constraint { get; }
}

public record CodeTransition(
    string stateName,
    List<Instruction> Activities,
    List<Constraint> Constraint,
    Transition Transition
) : ICodeTransition;

public record JunctionCodeTransition(
    List<Instruction> Activities,
    List<ICodeTransition> CodeTransitions,
    List<Constraint> Constraint,
    Transition Transition
) : ICodeTransition;
