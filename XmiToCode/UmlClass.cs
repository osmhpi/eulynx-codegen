using XmiToCode.Context;
using static XmiToCode.Codegen.CodeGenerationHelper;

namespace XmiToCode;

public class UmlClass
{
    private readonly PackagedElement _class;
    public readonly StateMachine _stateMachine;
    private readonly DataTypeHelper _dataTypes;

    public PackagedElement ParentPackage { get; }

    public UmlClass(PackagedElement classPackage,
        DataTypeHelper dataTypes,
        IProgramContext context,
        PackagedElement parentPackage)
    {
        _class = classPackage;
        _dataTypes = dataTypes;
        ParentPackage = parentPackage;
        _stateMachine = new StateMachine(TransformSubverticesIntoCompoundStates(classPackage.StateMachine.Region, context), classPackage.StateMachine.Name);
    }

    public Region TransformSubverticesIntoCompoundStates(UmlRegion region, IProgramContext context) {
        var states = region.Subvertices.Select(x => {
            var subRegion = FlattenRegions(x.Regions, context);
            return new CompoundState(
                new List<PartialState>() { new PartialState(x, region) },
                subRegion != null ? new StateMachine(subRegion, x.Name) : null);
        }).OfType<IState>().ToList();

        var allSubstateTransitions = states.Where(x => x.InternalStateMachine != null)
            .SelectMany(x => x.InternalStateMachine!.GetTransitionsOriginatingFromAnyState()).ToList();
        var substateTransitionsToStates = allSubstateTransitions.SelectMany(t =>
            states.OfType<CompoundState>()
                .Where(x => x.IsTargetOfTransition(t.Transition))
                .Where(x => x.IsNextStateAfterTransition(t.FromState, t.Transition))
                .Select(to => Transition.Parse(t.FromState, to, new List<UmlTransition> { t.Transition }, _dataTypes, context))).ToList();

        var transitions = region.Transitions
            .Select(transition => Transition.Parse(
                states.Single(x => x.IsSourceOfTransition(transition)),
                states.Single(x => x.IsTargetOfTransition(transition)),
                new List<UmlTransition> { transition },
                _dataTypes,
                context
            ))
            .Concat(substateTransitionsToStates)
            .ToList();

        return new Region(states, transitions);
    }

    private static IEnumerable<CompoundState> FlattenStates(List<List<CompoundState>> regionStates) {
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
            foreach (var regionBState in FlattenStates(rest)) {
                yield return regionBState with {
                    PartialStates = regionBState.PartialStates.Concat(regionAState.PartialStates).ToList()
                };
            }
        }
    }

    private Region? FlattenRegions(List<UmlRegion> regions, IProgramContext context) {
        if (regions.Count == 0) {
            return null;
        }

        var states = regions.Select(region =>
            region.Subvertices.Select(x => {
                var subregion = FlattenRegions(x.Regions, context);
                return new CompoundState(
                    new List<PartialState>() { new PartialState(x, region) },
                    subregion != null ? new StateMachine(subregion, x.Name) : null);
            }).ToList()).ToList();

        var flattenedStates = FlattenStates(states)
            .ToList();

        // Combine initial transitions into one
        var initialTransitions = regions.SelectMany(region => region.Transitions
            .Where(transition => flattenedStates.Any(x => x.IsSourceOfTransition(transition) && x.IsInitialState)))
            .ToList();

        var initialTransition = new InitialTransition(
            flattenedStates.Single(x => initialTransitions.All(transition => x.IsSourceOfTransition(transition))),
            flattenedStates.Single(x => initialTransitions.All(transition => x.IsTargetOfTransition(transition))),
            initialTransitions
        );

        // TODO: Some code duplication with TransformSubverticesIntoCompoundStates
        // There may be open-ended transitions in the subvertices (also deeply nested) that point towards a
        // state in the current region.
        var allSubstateTransitions = flattenedStates.Where(x => x.InternalStateMachine != null)
            .SelectMany(x => x.InternalStateMachine!.GetTransitionsOriginatingFromAnyState()).ToList();
        var substateTransitionsToFlattenedStates = allSubstateTransitions.SelectMany(t =>
            flattenedStates
                .Where(x => x.IsTargetOfTransition(t.Transition))
                .Where(x => x.IsNextStateAfterTransition(t.FromState, t.Transition))
                .Select(to => Transition.Parse(t.FromState, to, new List<UmlTransition> { t.Transition }, _dataTypes, context))).ToList();

        var transitions = regions.SelectMany(region => region.Transitions
            .SelectMany(transition => flattenedStates
                .Where(x => x.IsSourceOfTransition(transition) && !x.IsInitialState)
                .SelectMany(from => flattenedStates
                    .Where(x => x.IsTargetOfTransition(transition))
                    .Where(x => x.IsNextStateAfterTransition(from, transition))
                    .Select(to => Transition.Parse(from, to, new List<UmlTransition> { transition }, _dataTypes, context))
                )
            )).Concat(substateTransitionsToFlattenedStates).Append(initialTransition).ToList();

        return new Region(flattenedStates.OfType<IState>().ToList(), transitions);
    }

    public string GetName() {
        return InPascalCase(_class.Name);
    }
}
