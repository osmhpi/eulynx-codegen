using System.Text.RegularExpressions;
using XmiToCode;

internal class UmlClass : CodeGenerationItem
{
    private PackagedElement _class;
    private readonly Dictionary<string, PackagedElement> _changeEvents;
    private readonly Dictionary<string, PackagedElement> _timeEvents;
    private readonly StateMachine _stateMachine;
    private readonly DataTypeHelper _dataTypes;

    public UmlClass(PackagedElement classPackage, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
    {
        _class = classPackage;
        _changeEvents = changeEvents;
        _timeEvents = timeEvents;
        _stateMachine = new StateMachine(TransformSubverticesIntoCompoundStates(classPackage.StateMachine.Region, changeEvents, timeEvents), classPackage.StateMachine.Name, changeEvents, timeEvents);

        var properties = _class.OwnedAttribute
            //.Where(x => x.XmiType.SingleOrDefault() == "uml:Property")
            .ToList();
        _dataTypes = new DataTypeHelper(properties);
    }

    public static Region TransformSubverticesIntoCompoundStates(UmlRegion region, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents) {
        var states = region.Subvertices.Select(x => {
            var subRegion = FlattenRegions(x.Regions, changeEvents, timeEvents);
            return new CompoundState(
                new List<PartialState>() { new PartialState(x, region) },
                subRegion != null ? new StateMachine(subRegion, x.Name, changeEvents, timeEvents) : null);
        }).OfType<IState>().ToList();

        var transitions = region.Transitions
            .Select(transition => new Transition(
                states.Single(x => x.IsSourceOfTransition(transition)),
                states.Single(x => x.IsTargetOfTransition(transition)),
                new List<UmlTransition> {transition}
            ))
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

    private static Region? FlattenRegions(List<UmlRegion> regions, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents) {
        if (regions.Count == 0) {
            return null;
        }

        var states = regions.Select(region =>
            region.Subvertices.Select(x => {
                var subRegion = FlattenRegions(x.Regions, changeEvents, timeEvents);
                return new CompoundState(
                    new List<PartialState>() { new PartialState(x, region) },
                    subRegion != null ? new StateMachine(subRegion, x.Name, changeEvents, timeEvents) : null);
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

        var transitions = regions.SelectMany(region => region.Transitions
            .SelectMany(transition => flattenedStates
                .Where(x => x.IsSourceOfTransition(transition) && !x.IsInitialState)
                .SelectMany(from => flattenedStates
                    .Where(x => x.IsTargetOfTransition(transition))
                    .Where(x => x.IsNextStateAfterTransition(from, transition))
                    .Select(to => new Transition(from, to, new List<UmlTransition> { transition }))
                )
            ).ToList()).Append(initialTransition).ToList();

        return new Region(flattenedStates.OfType<IState>().ToList(), transitions);
    }

    public string GetName() {
        return InPascalCase(_class.Name);
    }

  public override string Write() {
    var className = InPascalCase(_class.Name);
    var behaviorName = GetName();

    // Initialize property types
    {
        // Perform a dry run of generating transitions (which includes comparisons and assignments,
        // where property types are coerced)
        var ignored = _stateMachine.GenerateTransitionFunctions(_dataTypes);
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

    {_stateMachine.GenerateBar(_dataTypes)}

    {string.Join("\n", _dataTypes.Properties.Select(x => $"public {_dataTypes.LookupPropertyValueType(InPascalCase(x.Name))} {CodeGenerationItem.InPascalCase(x.Name)} {{ get; set; }}"))}

    {_dataTypes.GeneratePropertyValueTypes()}
}}
";
  }

  private string GenerateInitialEntry(StateMachine behavior, DataTypeHelper dataTypes)
  {
      var (x, y, z) = behavior.GetTransitionsFromState(behavior.InitialState).Single();
      var entry = y.GenerateEntry(null, null);

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
