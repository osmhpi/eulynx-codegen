using XmiToCode.Codegen;
using XmiToCode.Codegen.Model;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.Model;
using XmiToCode.Transformation.Model;

namespace XmiToCode.Transformation;

public class ClassTransformer {
    private readonly Class _parsedClass;

    public ClassTransformer(Class parsedClass)
    {
        _parsedClass = parsedClass;
    }

    public CompoundRegion FlattenRegions() {
        var result = FlattenRegions(new List<IRegion> { _parsedClass.Region })!;

        CompoundRegion UpdateTransitions(CompoundRegion region) {
            var transitions = new List<Transition>();
            foreach (var transition in region.Transitions) {
                if (transition is InitialTransition)
                    // Initial transitions receive special care below
                    continue;

                var sourceStates = region.States.Cast<CompoundState>()
                    .Where(x => x.IsSourceOfTransition(transition.SingleTransition));
                var targetStates = region.States.Cast<CompoundState>()
                    .Where(x => x.IsTargetOfTransition(transition.SingleTransition));
                transitions.AddRange(
                    from source in sourceStates
                    from target in targetStates
                    where target.IsNextStateAfterTransition(source, transition.SingleTransition)
                    select transition with { From = source, To = target }
                );
            }

            // Combine initial transitions into one
            var initialTransitions = region.Transitions.OfType<InitialTransition>().ToList();
            var initialTransition = new InitialTransition(
                region.States.Single(x => initialTransitions.All(transition => x.IsSourceOfTransition(transition.Transitions.Single()))),
                region.States.Single(x => initialTransitions.All(transition => x.IsTargetOfTransition(transition.Transitions.Single()))),
                initialTransitions.SelectMany(x => x.Transitions).ToList(),
                initialTransitions.SelectMany(x => x.Instructions).ToList(),
                initialTransitions.SelectMany(x => x.Constraints).ToList()
            );

            transitions.Add(initialTransition);

            return region with { Transitions = transitions };
        }

        static CompoundRegion TransformRegionRecursively(CompoundRegion region, Func<CompoundRegion, CompoundRegion> transformer) {
            var states = region.States.Cast<CompoundState>()
                .Select(x =>
                    x.Region == null
                        ? x
                        : x.WithRegion(TransformRegionRecursively(x.Region, transformer)));
            return transformer(region with { States = states.ToList() });
        }

        return TransformRegionRecursively(result, UpdateTransitions);
    }


    private IBehaviorRecord MakeSubrecord(string recordName, TypeIdentifier className, IState x) {
        var region = x.Regions.SingleOrDefault();
        if (region != null) {
            return ParseStateRecord(x, region, x.Name, recordName, className);
        } else {
            return new SimpleBehaviorRecord(x, x.Name, recordName, className);
        }
    }

    private BehaviorRecord ParseStateRecord(IState? x, IRegion region, string name, string? parentBehaviorName, TypeIdentifier className) {
        var subrecords = region.States
            // We will inline pseudostates in the generated code
            .Where(x => x.IsRegularState)
            .Select(x => MakeSubrecord(name, className, x)).ToList();
        var initialTransition = region.Transitions.OfType<InitialTransition>().Single();
        var initializer = TransitionFunction.CreateCodeTransition(initialTransition, region,
            region.InitialState.Name, region.InitialState, initialTransition.To, initialTransition.To.Name,
            false, className);

        return new BehaviorRecord(x, region, name, parentBehaviorName, className, initializer, subrecords);
    }

    public ClassFile TransformClassIntoFile() {
        var flatRegion = FlattenRegions();
        var behaviorName = new TypeIdentifier(_parsedClass.UmlClass.StateMachine.Name);

        var behaviorRecord = ParseStateRecord(null, flatRegion, behaviorName.Name, null, _parsedClass.ClassName);

        // TODO: This class should only flatten the regions, move the rest to ClassFile
        var transitionFunction = behaviorRecord.EnumerateSubrecords(TargetLanguage.C) // TODO obviously
            .Where(x => x.record.State?.IsRegularState ?? false)
            .Select(x => TransitionFunction.Create(_parsedClass.ClassName, behaviorName, x.Name, x.record.State!, flatRegion))
            .ToList();

        return new ClassFile(
            _parsedClass.ClassName,
            behaviorName,
            _parsedClass.ClassContext,
            flatRegion,
            behaviorRecord,
            transitionFunction,
            flatRegion.States.Select(x => x.Name).ToList(),
            _parsedClass.Operations,
            _parsedClass.Hierarchy
        );
    }

    /// <summary>
    /// Combine (multiply-out) multiple 'OR'-connected state machines
    /// </summary>
    /// <param name="regions"></param>
    /// <returns>null if regions is empty</returns>
    private static CompoundRegion? FlattenRegions(List<IRegion> regions) {
        if (!regions.Any())
            return null;

        // Enumerate all states for each region
        var states = regions.Select(region => (
            from state in region.States
            let subregion = FlattenRegions(state.Regions)
            let stateWithAtMostOneRegion = state.WithRegion(subregion)
            select new CompoundState(
                new List<IState>() { stateWithAtMostOneRegion },
                stateWithAtMostOneRegion.Regions.SingleOrDefault()
            )
            ).ToList()
        ).ToList();

        // Create the cross product of states
        var flattenedStates = CompoundStateCrossProduct(states)
            // Remove invalid states from the cross product
            .Where(x => x.IsInitialState || x.IsJunction || x.IsRegularState)
            .ToList();

        // Concatenate all transitions of all regions, fix them later
        var transitions = regions.SelectMany(x => x.Transitions).ToList();

        return new CompoundRegion(flattenedStates.Cast<IState>().ToList(), transitions);
    }

    private static IEnumerable<CompoundState> CompoundStateCrossProduct(List<List<CompoundState>> regionStates)
    {
        if (regionStates.Count == 0) {
            yield break;
        }

        if (regionStates.Count == 1) {
            foreach (var s in regionStates.First()) {
                yield return s;
            }
            yield break;
        }

        var last = regionStates.Last();
        var rest = regionStates.Take(regionStates.Count-1).ToList();

        foreach (var regionAState in last) {
            foreach (var regionBState in CompoundStateCrossProduct(rest)) {
                // Set the region reference once the FlatRegion was created
                yield return new CompoundState(regionBState.PartialStates.Concat(regionAState.PartialStates).ToList(), null);
            }
        }
    }
}
