using System.Text.RegularExpressions;
using XmiToCode;

internal class UmlClass : CodeGenerationItem
{
    private PackagedElement _class;
    private readonly Dictionary<string, PackagedElement> _changeEvents;
    private readonly Dictionary<string, PackagedElement> _timeEvents;
    private readonly Dictionary<string, PackagedElement> _packageEvents;
    private readonly StateMachine _stateMachine;
    private readonly DataTypeHelper _dataTypes;

    public UmlClass(PackagedElement classPackage, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents, Dictionary<string, PackagedElement> packageEvents)
    {
        _class = classPackage;
        _changeEvents = changeEvents;
        _timeEvents = timeEvents;
        _packageEvents = packageEvents;

        _stateMachine = new StateMachine(TransformSubverticesIntoCompoundStates(classPackage.StateMachine.Region, changeEvents, timeEvents), classPackage.StateMachine.Name);

        var properties = _class.OwnedAttribute
            .Where(x => x.XmiType == "uml:Property")
            .ToList();
        var ports = _class.OwnedAttribute
            .Where(x => x.XmiType == "uml:Port")
            .ToList();
        _dataTypes = new DataTypeHelper(properties, ports, _changeEvents, _timeEvents, _packageEvents);
    }

    public static Region TransformSubverticesIntoCompoundStates(UmlRegion region, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents) {
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
                .Select(to => new Transition(t.FromState, to, new List<UmlTransition> { t.Transition }))).ToList();

        var transitions = region.Transitions
            .Select(transition => new Transition(
                states.Single(x => x.IsSourceOfTransition(transition)),
                states.Single(x => x.IsTargetOfTransition(transition)),
                new List<UmlTransition> { transition }
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

    private static Region? FlattenRegions(List<UmlRegion> regions) {
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
            // States with more than one junction component are invalid
            .Where(x => x.PartialStates.Count(partialState => partialState.IsJunction) <= 1)
            .ToList();

        // Combine initial transitions into one
        var initialTransitions = regions.SelectMany(region => region.Transitions
            .Where(transition => flattenedStates.Any(x => x.IsSourceOfTransition(transition) && x.IsInitialState)))
            .ToList();

        var initialTransition = new Transition(
            flattenedStates.Single(x => initialTransitions.All(transition => x.IsSourceOfTransition(transition))),
            flattenedStates.Single(x => initialTransitions.All(transition => x.IsTargetOfTransition(transition))),
            initialTransitions
        );

        // TODO: Move this to TransformSubverticesIntoCompoundStates (?)
        // There may be open-ended transitions in the subvertices (also deeply nested) that point towards a
        // state in the current region.
        var allSubstateTransitions = flattenedStates.Where(x => x.InternalStateMachine != null)
            .SelectMany(x => x.InternalStateMachine!.GetTransitionsOriginatingFromAnyState()).ToList();
        var substateTransitionsToFlattenedStates = allSubstateTransitions.SelectMany(t =>
            flattenedStates
                .Where(x => x.IsTargetOfTransition(t.Transition))
                .Where(x => x.IsNextStateAfterTransition(t.FromState, t.Transition))
                .Select(to => new Transition(t.FromState, to, new List<UmlTransition> { t.Transition }))).ToList();

        var transitions = regions.SelectMany(region => region.Transitions
            .SelectMany(transition => flattenedStates
                .Where(x => x.IsSourceOfTransition(transition) && !x.IsInitialState)
                .SelectMany(from => flattenedStates
                    .Where(x => x.IsTargetOfTransition(transition))
                    .Where(x => x.IsNextStateAfterTransition(from, transition))
                    .Select(to => new Transition(from, to, new List<UmlTransition> { transition }))
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

    // Initialize property types
    {
        // Perform a dry run of generating transitions (which includes comparisons and assignments,
        // where property types are coalesced)
        var ignored = _stateMachine.GenerateTransitionFunctions(behaviorName, _dataTypes);
    }

    return @$"namespace Eulynx;

public class {className} {{
    {_stateMachine.Write()}

    private {behaviorName} _state;
    public {behaviorName} State {{ get {{ return _state; }} }}

    public {className}() {{
        {GenerateInitialEntry(_stateMachine, _dataTypes)}
        _state = {behaviorName}.New();
    }}

    private bool IsTimeoutExpired(object timeout) {{
        // TODO
        return false;
    }}

    private bool IsConditionChanged(bool condition) {{
        // TODO: Keep in mind that this should only evaluate to true once
        return condition;
    }}

    private void SendMessage(string message, string port) {{
        // TODO: Implement
    }}

    private bool IsMessageArrived(string message) {{
        // TODO: Implement
        return false;
    }}

    private bool ReceivedMessage(string message) {{
        // TODO: Implement
        return false;
    }}

    {_stateMachine.GenerateTransitionFunctions(behaviorName, _dataTypes)}

    // Properties
    {string.Join("\n", _dataTypes.Properties.Select(x => $"public {_dataTypes.LookupPropertyValueType(InPascalCase(x.Name))} {CodeGenerationItem.InPascalCase(x.Name)} {{ get; set; }}"))}

    // Ports
    {string.Join("\n", _dataTypes.Ports.Select(x => $"public {_dataTypes.LookupPropertyValueType(InPascalCase(x.Name))} {CodeGenerationItem.InPascalCase(x.Name)} {{ get; set; }}"))}

    {_dataTypes.GeneratePropertyValueTypes()}
}}
";
  }

  private string GenerateInitialEntry(StateMachine behavior, DataTypeHelper dataTypes)
  {
      var (x, y, z) = behavior.GetTransitionsFromState(behavior.GetName(), behavior.InitialState).Single();
      var entry = y.GenerateEntry(null, null) ?? "";

      foreach (Match m in Regex.Matches(entry, "(\\w+) = \"(\\w*)\"")) {
          var lhs = m.Groups[1].Value;
          var rhs = m.Groups[2].Value;
          dataTypes.RecordPossibleValueForProperty(lhs, rhs);
      }

      entry = Regex.Replace(entry, "(\\w+) = \"(\\w*)\"", m => $"{m.Groups[1].Value} = {dataTypes.LookupPropertyValueType(m.Groups[1].Value)}.{InPascalCase(m.Groups[2].Value)}");

      return entry;
  }

  internal async Task Generate()
  {
    using var file = File.Create($"../Eulynx/{GetName()}.cs");
    using var writer = new StreamWriter(file);
    await writer.WriteAsync(Write());
  }
}
