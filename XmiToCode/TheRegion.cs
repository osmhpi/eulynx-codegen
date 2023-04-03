using XmiToCode;

class TheRegion : CodeGenerationItem
{
  public Region Region { get { return _region; } }
  private readonly Region _region;
  private readonly string _name;
  private readonly Subvertex _initialState;
  private readonly List<Subvertex> _junctions;
  private readonly List<Subvertex> _states;
  private readonly IEnumerable<string> _stateEnum;
  private readonly IEnumerable<TheRegion> _subregions;
  private readonly Dictionary<string, PackagedElement> _changeEvents;
  private readonly Dictionary<string, PackagedElement> _timeEvents;

  public TheRegion(Region region, string name, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
  {
    _region = region;
    _name = name;
    _changeEvents = changeEvents;
    _timeEvents = timeEvents;

    _initialState = region.Subvertices.Single(x => x.Name.Contains("Initial") && x.Type == "uml:Pseudostate");
    _junctions = region.Subvertices.Where(x => x.Name.Contains("Junction") && x.Type == "uml:Pseudostate").ToList();
    _states = region.Subvertices.Where(x => x.Type == "uml:State").ToList();

    _stateEnum = _states.Select(x => x.Name).Select(InPascalCase);

    _subregions = _states.SelectMany(x => x.Regions.Select(region => new TheRegion(region, x.Name, changeEvents, timeEvents)));
  }

  public IEnumerable<(Transition transition, Subvertex state, string stateName)> GetTransitionsFromState(Subvertex fromState, bool skipParentTransitions = false) {
      // Does fromState match one of our subregions?
      var subregionTransitions = _subregions
        .Select(subregion => new { Subregion = subregion, Transitions = subregion.GetTransitionsFromState(fromState, skipParentTransitions) })
        .SingleOrDefault(x => x.Transitions.Any());

      if (subregionTransitions != null) {
        if (skipParentTransitions) {
          return subregionTransitions.Transitions.Select(x => (x.transition, x.state, $"{GetName()}.{x.stateName}"));
        }

        // Prepend the transitions from the enclosing state of the subregion
        var subregionState = _states.Single(x => x.Regions.Contains(subregionTransitions.Subregion.Region));
        return _region.Transition.Where(x => x.Source == subregionState.Id)
          .Select(x => (x, _region.Subvertices.Single(state => state.Id == x.Target), $"{GetName()}.{InPascalCase(_region.Subvertices.Single(state => state.Id == x.Target).Name)}"))
          .Concat(subregionTransitions.Transitions.Select(x => (x.transition, x.state, $"{GetName()}.{x.stateName}")));
      }

      return _region.Transition.Where(x => x.Source == fromState.Id)
        .Select(x => (x, _region.Subvertices.Single(state => state.Id == x.Target), $"{GetName()}.{InPascalCase(_region.Subvertices.Single(state => state.Id == x.Target).Name)}"));
  }

  public string GetName() {
    return InPascalCase(_name);
  }

  public IEnumerable<(Subvertex subvertex, string name)> GetStates() {
    var hasSubstates = false;
    foreach (var (subvertex, name) in _subregions.SelectMany(x => x.GetStates())) {
      yield return (subvertex, $"{GetName()}.{name}");
      hasSubstates = true;
    }

    if (!hasSubstates) {
      foreach (var state in _states) {
        yield return (state, $"{GetName()}.{InPascalCase(state.Name)}");
      }
    }
  }

  private string MakeSubrecord(string recordName, Subvertex x) {
    var isRegion = x.Regions.Any();
    var name = InPascalCase(x.Name);
    if (isRegion) {
      return new TheRegion(x.Regions.Single(), name, _changeEvents, _timeEvents).MakeStateRecord(name, recordName);
    } else {
      return $@"public record {name}() : {recordName}() {{
        public static new {name} New() => new {name}();
      }}";
    }
  }

  private string MakeStateRecord(string name, string basename) {
    var subrecords = _states.Select(x => MakeSubrecord(name, x));
    var (x, y, z) = GetTransitionsFromState(_initialState).Single();

    return @$"public record {name} : {basename} {{
    {string.Join("\n    ", subrecords)}

    public static new {name} New() => {z}.New();

    private {name}() {{}}
}}
";

  }

  public override string Write()
  {
    return MakeStateRecord(InPascalCase(_name), "object");
  }
}
