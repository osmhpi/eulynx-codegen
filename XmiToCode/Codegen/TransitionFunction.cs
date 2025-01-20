using XmiToCode.Instructions;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.Model;

namespace XmiToCode.Codegen;

public record TransitionFunction(
    TypeIdentifier TheRootBehaviorName,
    TypeIdentifier ClassName,
    string fromStateName,
    IState State,
    List<ICodeTransition> Transitions
) {
    public string Name(TargetLanguage targetLanguage) =>
        targetLanguage switch {
            TargetLanguage.CSharp => $"TransitionFrom{fromStateName}",
            TargetLanguage.C => $"transition_from_{fromStateName}",
            TargetLanguage.Rust => $"transition_from_{fromStateName}",
            _ => throw new NotImplementedException()
        };

    public static bool RegionContainsState(IRegion region, IState state) {
        if (region.States.Contains(state)) {
            return true;
        }

        return region.States.Where(x => x.Regions.Any()).Select(x => RegionContainsState(x.Regions.Single(), state)).Any();
    }

    public static IEnumerable<(Transition Transition, IState ToState)> GetAllTransitionsFromState(IRegion region, IState fromState) {
        // Does fromState match one of our child state machines?
        // var childStateMachineTransitions = region.States
        //     .Where(x => x.Regions.Any(region => RegionContainsState(region, fromState)))
        //     // we can safely assume that the initial state does not
        //     // transition out of the child state machine
        //     .Where(x => !x.IsInitialState)
        //     .SelectMany(state => state.Regions.Select(region => new {
        //         FromState = state,
        //         Transitions = GetAllTransitionsFromState(region, fromState).ToList()
        //     }))
        //     .ToList();

        var transitionsOnCurrentLevel = region.Transitions
            .Where(x => x is not InitialTransition)
            .Where(x => x.From == fromState) // || childStateMachineTransitions.Any(child => x.From == child.FromState))
            .Select(x => (Transition: x, ToState: x.To));
            // .ToList();

        var result = transitionsOnCurrentLevel;
        // .Concat(
        //     childStateMachineTransitions.SelectMany(childStateMachineTransition =>
        //         childStateMachineTransition.Transitions.Select(x => (x.Transition, x.ToState))
        //     )
        // );

        // Special handling for junction states
        if (fromState.IsJunction) {
            // We must only include transitions that are directly attached to the junction state
            // (i.e. not to any parent state)
            result = result.Where(x => fromState.IsSourceOfTransition(x.Transition.SingleTransition));
        }

        return result;
    }

    public static TransitionFunction Create(TypeIdentifier className, TypeIdentifier behaviorName, string fromStateName, IState fromState, IRegion region) {
        var transitions = GetCodeTransitions(region, fromState, className);

        return new TransitionFunction(
            behaviorName,
            className,
            fromStateName,
            fromState,
            transitions);
    }

    public static List<ICodeTransition> GetCodeTransitions(IRegion region, IState fromState, TypeIdentifier className) {
        var transitions = GetAllTransitionsFromState(region, fromState).ToList();
        return transitions.Select(x => CreateCodeTransition(x.Transition, region, fromState, x.ToState, className)).ToList();
    }

    public static List<Instruction> SelectActivities(IState fromState, IState toState, Transition transition)
    {
        // TODO: Partial transitions, exit/entry for compound states
        var exit = fromState.Exit;
        var transitionEffect = transition.Instructions;
        var entry = toState.Entry;

        return new [] {exit, transitionEffect, entry}.SelectMany(x => x).ToList();
    }

    public static ICodeTransition CreateCodeTransition(
        Transition theTransition,
        IRegion region,
        IState fromState,
        IState toState,
        TypeIdentifier className) {

        if (toState.IsRegularState) {
            return new CodeTransition(
                SelectActivities(fromState, toState, theTransition), theTransition.Constraints, theTransition);
        }

        if (toState.IsJunction) {
            var subsequentTransitions = GetCodeTransitions(region, toState, className);
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
