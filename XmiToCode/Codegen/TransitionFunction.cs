using XmiToCode.Parsing.Accessibles;
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
    public static IEnumerable<(Transition transition, IState state, string stateName)> GetTransitionsFromState(IRegion region, string thisName, IState fromState, bool skipParentTransitions = false) {
        var transitionsOnCurrentLevel = region.Transitions.Where(x => x.From == fromState)
            .Select(x => (x, x.To, $"{thisName}.{x.To.Name}"));

        // Does fromState match one of our child state machines?
        var childStateMachineTransitions = region.States
            .Where(x => x.Regions.Any())
            .Select(state => new {
                FromState = state,
                ChildStateMachine = state.Regions.Single(),
                Transitions = GetTransitionsFromState(state.Regions.Single(), state.Name, fromState, skipParentTransitions).ToList()
            })
            .Where(x => x.Transitions.Any())
            .ToList();

        return childStateMachineTransitions.SelectMany(childStateMachineTransition => {
            var result = childStateMachineTransition.Transitions.Select(x => (x.transition, x.state, $"{thisName}.{x.stateName}"));

            if (skipParentTransitions) {
                return result;
            }

            // Prepend the transitions from the enclosing state of the child state machine
            return region.Transitions.Where(x => x.From == childStateMachineTransition.FromState)
                .Select(x => (x, x.To, $"{thisName}.{x.To.Name}"))
                .Concat(result);
        }).Concat(transitionsOnCurrentLevel);
    }

    public static TransitionFunction Parse(TypeIdentifier className, TypeIdentifier behaviorName, IState fromState, IRegion region) {
        var thisName = "this";
        var transitions = GetCodeTransitions(region, thisName, fromState, className, false);

        return new TransitionFunction(
            behaviorName,
            className,
            fromState.Name,
            transitions);
            // region.Transitions.Where(x => fromState.IsSourceOfTransition(x.SingleTransition)).ToList());
    }

    public static List<ICodeTransition> GetCodeTransitions(IRegion region, string thisName, IState fromState, TypeIdentifier className, bool skipParentTransitions) {
        var transitions = GetTransitionsFromState(region, fromState.Name, fromState, false);

        var regularTransitions = transitions.Where(x => x.state.IsRegularState);
        var noTriggerConditions = regularTransitions.All(x => x.transition.SingleTransition.Trigger == null);

        return transitions.Select(x => ParseTransition(x.transition, region, thisName, fromState, x.state, x.stateName, noTriggerConditions, className)).ToList();
    }

    public static List<Instruction> ParseActivities(IState fromState, IState toState, Transition transition)
    {
        // TODO: These signatures look implausible.
        // TODO: Partial transitions, exit/entry for compound states
        var exit = fromState.Exit;
        var transitionEffect = transition.Instructions;
        var entry = toState.Entry;

        return new [] {exit, transitionEffect, entry}.SelectMany(x => x).ToList();
    }

    public static ICodeTransition ParseTransition(
        Transition theTransition,
        IRegion region,
        string thisName,
        IState fromState,
        IState state,
        string stateName,
        bool noTriggerConditions,
        TypeIdentifier className) {

        if (state.IsRegularState) {
            if (noTriggerConditions) {
                return new CodeTransition(stateName,
                    ParseActivities(fromState, state, theTransition), theTransition.Constraints, theTransition);
            } else {
                return new CodeTransition(stateName,
                    ParseActivities(fromState, state, theTransition), theTransition.Constraints, theTransition);
            }
        }

        if (state.IsJunction) {
            return new JunctionTransition(
                ParseActivities(fromState, state, theTransition),
                // GetTransitionsFromState(state.Regions.Single(), thisName, state, false).ToList(),
                GetCodeTransitions(region, thisName, state, className, true),
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

public record JunctionTransition(
    List<Instruction> Activities,
    List<ICodeTransition> CodeTransitions,
    List<Constraint> Constraint,
    Transition Transition
) : ICodeTransition;
