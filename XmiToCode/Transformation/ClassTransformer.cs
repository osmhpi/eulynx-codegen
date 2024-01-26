using XmiToCode.Codegen;
using XmiToCode.Codegen.Model;
using XmiToCode.Identifiers;
using XmiToCode.Instructions;
using XmiToCode.Parsing.Accessibles;
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

        var openEndedTransitions = new List<(List<CompoundState>, Transition, CompoundRegion)>();

        CompoundRegion UpdateTransitions(CompoundRegion region) {
            var transitions = new List<Transition>();
            var currentOpenEndedTransitions = new List<(List<CompoundState>, Transition)>();
            foreach (var transition in region.Transitions) {
                if (transition is InitialTransition)
                    // Initial transitions receive special care below
                    continue;

                var sourceStates = region.States.Cast<CompoundState>()
                    .Where(x => x.IsSourceOfTransition(transition.SingleTransition));
                var targetStates = region.States.Cast<CompoundState>()
                    .Where(x => x.IsTargetOfTransition(transition.SingleTransition));

                if (!sourceStates.Any()) {
                    throw new Exception("We expect that transitions are always contained in the source state region.");
                }
                if (!targetStates.Any()) {
                    currentOpenEndedTransitions.Add((sourceStates.ToList(), transition));
                }

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
                initialTransitions.SelectManyIndependentInstructions().ToList(),
                initialTransitions.SelectMany(x => x.Constraints).ToList()
            );

            transitions.Add(initialTransition);

            var result = region with { Transitions = transitions };
            openEndedTransitions.AddRange(currentOpenEndedTransitions.Select(x => (x.Item1, x.Item2, result)));
            return result;
        }

        CompoundRegion TransformRegionRecursively(CompoundRegion region, Func<CompoundRegion, CompoundRegion> transformer) {
            var states = region.States.Cast<CompoundState>()
                .Select(x =>
                    x.Region == null
                        ? x
                        : x.WithRegion(TransformRegionRecursively(x.Region, transformer)));

            var result = transformer(region with { States = states.ToList() });

            // Insert transitions from nested states to states on the current level
            foreach (var (sourceStates, transition, targetTransitionCollection) in openEndedTransitions) {
                var targetStates = result.States.Cast<CompoundState>()
                    .Where(x => x.IsTargetOfTransition(transition.SingleTransition));

                targetTransitionCollection.Transitions.AddRange(
                    from source in sourceStates
                    from target in targetStates
                    where target.IsNextStateAfterTransition(source, transition.SingleTransition)
                    select transition with { From = source, To = target });
            }

            return result;
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
        var initializer = TransitionFunction.CreateCodeTransition(initialTransition, region, region.InitialState, initialTransition.To, className);

        return new BehaviorRecord(x, region, name, parentBehaviorName, className, initializer, subrecords);
    }

    public ClassFile TransformClassIntoFile() {
        var flatRegion = FlattenRegions();
        var behaviorName = new TypeIdentifier(_parsedClass.UmlClass.StateMachine.Name);

        var behaviorRecord = ParseStateRecord(null, flatRegion, behaviorName.Name, null, _parsedClass.ClassName);

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


public static class TransitionTransformerExtensions {
    public static IEnumerable<Instruction> SelectManyIndependentInstructions(this List<InitialTransition> transitions) {
        // Check for the independence of the instructions in the transitions

        foreach (var transition in transitions) {
            var assignedVariables = new HashSet<IAssignable>();
            foreach (var instruction in transition.Instructions.OfType<AssignmentInstruction>()) {
                assignedVariables.Add(instruction.Lhs);
            }

            void AssertAccessibleNotPartOfSet(IAccessible accessible) {
                if (assignedVariables.Contains(accessible)) {
                    throw new ModelException("Combining non-independent transitions");
                }
                switch (accessible) {
                    case BooleanExpression.Conjunction conjunction:
                        if (assignedVariables.Contains(conjunction.Lhs)) {
                            throw new ModelException("Combining non-independent transitions");
                        }
                        AssertAccessibleNotPartOfSet(conjunction.Rhs);
                        break;
                    case BooleanExpression.Disjunction disjunction:
                        if (assignedVariables.Contains(disjunction.Lhs)) {
                            throw new ModelException("Combining non-independent transitions");
                        }
                        AssertAccessibleNotPartOfSet(disjunction.Rhs);
                        break;
                    case BooleanExpression.Negation negation:
                        AssertAccessibleNotPartOfSet(negation.Variable);
                        break;
                    case BooleanExpression.Equality equality:
                        AssertAccessibleNotPartOfSet(equality.Lhs);
                        AssertAccessibleNotPartOfSet(equality.Rhs);
                        break;
                }
            }

            foreach (var otherTransition in transitions.Where(x => x != transition)) {
                foreach (var instruction in otherTransition.Instructions) {
                    switch (instruction) {
                        case AssignmentInstruction assignment:
                            if (assignedVariables.Contains(assignment.Lhs)) {
                                throw new ModelException("Combining non-independent transitions");
                            }
                            AssertAccessibleNotPartOfSet(assignment.Rhs);
                            break;
                        case IfThenInstruction ifThen:
                            AssertAccessibleNotPartOfSet(ifThen.Condition);
                            break;
                        case ElseIfThenInstruction elseIfThen:
                            AssertAccessibleNotPartOfSet(elseIfThen.Condition);
                            break;
                        case MethodCallInstruction call:
                            if (call.Callable is MethodCall methodCall) {
                                // Nothing to do since method parameters are not yet supported.
                            }
                            break;
                        case ReturnInstruction returnInstruction:
                            AssertAccessibleNotPartOfSet(returnInstruction.Value);
                            break;
                        case SendMessageInstruction sendMessage:
                            foreach (var initializer in sendMessage.Initializer.Values) {
                                AssertAccessibleNotPartOfSet(initializer);
                            }
                            break;
                        default: break;
                    }
                }
            }
        }

        // All good, concatenate instructions
        return transitions.SelectMany(x => x.Instructions);
    }
}
