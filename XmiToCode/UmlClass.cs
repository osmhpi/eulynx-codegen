using XmiToCode;

public class UmlClass : CodeGenerationItem
{
    private readonly PackagedElement _class;
    private readonly Dictionary<string, PackagedElement> _changeEvents;
    private readonly Dictionary<string, PackagedElement> _timeEvents;
    private readonly Dictionary<string, PackagedElement> _packageEvents;
    private readonly Dictionary<string, PackagedElement> _signals;
    private readonly StateMachine _stateMachine;
    private readonly DataTypeHelper _dataTypes;

    public UmlClass(PackagedElement classPackage,
        Dictionary<string, PackagedElement> changeEvents,
        Dictionary<string, PackagedElement> timeEvents,
        Dictionary<string, PackagedElement> packageEvents,
        Dictionary<string, PackagedElement> signals,
        Dictionary<string, PackagedElement> dataTypes,
        Dictionary<(string, string), (string, string)> typeAliases)
    {
        _class = classPackage;
        _changeEvents = changeEvents;
        _timeEvents = timeEvents;
        _packageEvents = packageEvents;
        _signals = signals;

        var properties = _class.OwnedAttribute
            .Where(x => x.XmiType == "uml:Property")
            .ToList();
        var ports = _class.OwnedAttribute
            .Where(x => x.XmiType == "uml:Port")
            .ToList();
        var operations = _class.OwnedOperation
            .Where(x => x.XmiType == "uml:Operation")
            .Select(x => new Operation(x, _class.OwnedBehavior.Single(behavior => behavior.Id == x.Method)))
            .ToList();
        var receptions = _class.OwnedReception
            .Where(x => x.XmiType == "uml:Reception")
            .ToList();

        var className = InPascalCase(_class.Name);
        // HACK
        var classInfo = new ClassInfo(className, "");
        _dataTypes = new DataTypeHelper(properties, ports, operations, receptions, _changeEvents, _timeEvents, _packageEvents, _signals, dataTypes, typeAliases, classInfo);

        _stateMachine = new StateMachine(TransformSubverticesIntoCompoundStates(classPackage.StateMachine.Region, changeEvents, timeEvents), classPackage.StateMachine.Name);
    }

    public Region TransformSubverticesIntoCompoundStates(UmlRegion region, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents) {
        var states = region.Subvertices.Select(x => {
            var subRegion = FlattenRegions(x.Regions);
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
                .Select(to => Transition.Create(t.FromState, to, new List<UmlTransition> { t.Transition }, _dataTypes))).ToList();

        var transitions = region.Transitions
            .Select(transition => Transition.Create(
                states.Single(x => x.IsSourceOfTransition(transition)),
                states.Single(x => x.IsTargetOfTransition(transition)),
                new List<UmlTransition> { transition },
                _dataTypes
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

    private Region? FlattenRegions(List<UmlRegion> regions) {
        if (regions.Count == 0) {
            return null;
        }

        var states = regions.Select(region =>
            region.Subvertices.Select(x => {
                var subregion = FlattenRegions(x.Regions);
                return new CompoundState(
                    new List<PartialState>() { new PartialState(x, region) },
                    subregion != null ? new StateMachine(subregion, x.Name) : null);
            }).ToList()).ToList();

        var flattenedStates = FlattenStates(states)
            // States with more than one junction component are invalid (we can ignore them)
            .Where(x => x.PartialStates.Count(partialState => partialState.IsJunction) <= 1)
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
                .Select(to => Transition.Create(t.FromState, to, new List<UmlTransition> { t.Transition }, _dataTypes))).ToList();

        var transitions = regions.SelectMany(region => region.Transitions
            .SelectMany(transition => flattenedStates
                .Where(x => x.IsSourceOfTransition(transition) && !x.IsInitialState)
                .SelectMany(from => flattenedStates
                    .Where(x => x.IsTargetOfTransition(transition))
                    .Where(x => x.IsNextStateAfterTransition(from, transition))
                    .Select(to => Transition.Create(from, to, new List<UmlTransition> { transition }, _dataTypes))
                )
            )).Concat(substateTransitionsToFlattenedStates).Append(initialTransition).ToList();

        return new Region(flattenedStates.OfType<IState>().ToList(), transitions);
    }

    public string GetName() {
        return InPascalCase(_class.Name);
    }

    public string Write(CSharpWriter w) {
        var className = InPascalCase(_class.Name);
        var behaviorName = _stateMachine.GetName();

        var global = new GlobalContext(_dataTypes);
        var classContext = new ClassContext(global, _dataTypes, w);

        var info = new ClassInfo(className, behaviorName);

        var klass = new Class(
            info,
            classContext,
            _stateMachine.Parse(info, _dataTypes, classContext),
            _stateMachine.ParseTransitionFunctions(info, _dataTypes, classContext).ToList(),
            _stateMachine.GetStates(behaviorName).ToList(),
            new()
        );

        return w.Write(klass);
    }

    internal async Task Generate(ICodeWriter w)
    {
        var className = InPascalCase(_class.Name);
        var behaviorName = _stateMachine.GetName();

        var global = new GlobalContext(_dataTypes);
        var classContext = new ClassContext(global, _dataTypes, w);

        var whitelist = new [] {"ResetReason", "CloseReason", "AbilityToMoveState", "PointPositionState", "PointPositionDegradedState"};
        var enumerations = _dataTypes.DataTypes.Where(x => x.Value.Type == "uml:Enumeration")
            // There are two enumerations which map to the same name (but are not used currently)
            // - Line Direction Control Information
            // - Line_Direction_Control_Information
            // This behavior is possibly dangerous...
            // Temporary workaround:
            .Where(x => whitelist.Contains(x.Value.Name))
            .Select(x => new GlobalEnumeration(x.Value)).ToList();

        var info = new ClassInfo(className, behaviorName);

        var klass = new Class(
            info,
            classContext,
            _stateMachine.Parse(info, _dataTypes, classContext),
            _stateMachine.ParseTransitionFunctions(info, _dataTypes, classContext).ToList(),
            _stateMachine.GetStates(behaviorName).ToList(),
            enumerations
        );

        await w.WriteAllFilesAsync(this, klass);
    }
}
