using XmiToCode;

internal class UmlClass : CodeGenerationItem
{
    private PackagedElement _class;
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
        Dictionary<string, string> typeAliases)
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

        _dataTypes = new DataTypeHelper(properties, ports, operations, receptions, _changeEvents, _timeEvents, _packageEvents, _signals, dataTypes, typeAliases);

        _stateMachine = new StateMachine(TransformSubverticesIntoCompoundStates(classPackage.StateMachine.Region, changeEvents, timeEvents), classPackage.StateMachine.Name);

        // var messageSchema = Ports.Select(x => DataTypes[x.Value.Property.Type])
        //     .SelectMany(x => x.OwnedReception)
        //     .Select(x => new MessageSchema(new TypeIdentifier(x.Name), Signals[x.Signal], this))
        //     .ToList();

        // var transitionFunctions = _stateMachine.GenerateTransitionFunctionsQuery();
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

    public override string Write() {
        var className = InPascalCase(_class.Name);
        var behaviorName = _stateMachine.GetName();

        var global = new GlobalContext(_dataTypes);
        var classContext = new ClassContext(global, _dataTypes);

        // Initialize property types
        {
            // Perform a dry run of generating transitions (which includes comparisons and assignments,
            // where property types are coalesced)
            var ignored = _stateMachine.GenerateTransitionFunctions(behaviorName, _dataTypes, classContext);
            _dataTypes.Operations.Select(x => x.Write(_dataTypes, classContext)).ToList();
            // TODO: I think side effects of initial transitions are still missing here

        }

        var events = _dataTypes.UsedChangeEvents.Select(x => new ChangeEvent(x)).ToList();
        events.Select(x => x.WriteInitializer(_dataTypes)).ToList(); // also ignore

        return @$"using System.Threading.Channels;
using EulynxMessages = EulynxLive.Messages.Baseline4R1;

namespace Eulynx;

public class {className} : IStateMachine<{className}.{behaviorName}> {{
    {_stateMachine.Write(className, _dataTypes, classContext)}

    private {behaviorName} _state;
    public {behaviorName} State => _state;

    private readonly IMessageFactory _messageConverter;

    public {className}(IMessageFactory messageConverter) {{
        _messageConverter = messageConverter;

        // Initialize ports
        {_dataTypes.GeneratePortInitializers()}

        // Initialize change events
        {JoinLines(events.Select(x => x.WriteInitializer(_dataTypes)))}
    }}

    public void Init() {{
        _state = {behaviorName}.New(this);
    }}

    public IEnumerable<AbstractPort> GetPorts() {{
        return new AbstractPort[] {{
            // TODO: Skip message ports
            {string.Join(", ", _dataTypes.Ports.Select(x => x.Value.Name))}
        }};
    }}

    public IEnumerable<Event> GetChangeEvents() {{
        return new Event[] {{
            {string.Join(", ", events.Select(x => x.Event.Name))}
        }};
    }}

    private bool IsTimeoutExpired(object timeout) {{
        // TODO
        return false;
    }}

    private void SendMessage(Message message, Port<Channel<EulynxMessages.Message>> port) {{
        port.Value.Writer.TryWrite(_messageConverter.Convert<Message>(message));
    }}

    {_stateMachine.GenerateTransitionFunctions(behaviorName, _dataTypes, classContext)}

    // Properties
    {_dataTypes.GeneratePropertyDeclarations()}

    // Ports
    {_dataTypes.GeneratePortDeclarations()}

    // Operations
    {JoinLines(_dataTypes.Operations.Select(x => x.Write(_dataTypes, classContext)))}

    // Value Types
    {_dataTypes.GeneratePropertyValueTypes()}

    // Messages
    public record Message {{
        {_dataTypes.GenerateMessages()}
    }}

    // Signals
    {_dataTypes.GenerateSignals()}

    // Events
    {JoinLines(events.Select(x => x.WriteProperty()))}
}}
";
    }

    internal async Task Generate()
    {
        using var file = File.Create($"../Eulynx/{GetName()}.cs");
        using var writer = new StreamWriter(file);
        await writer.WriteAsync(Write());
    }
}
