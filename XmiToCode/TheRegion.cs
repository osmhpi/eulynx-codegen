using XmiToCode;

class TheRegion : CodeGenerationItem
{
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

  private IEnumerable<(Transition transition, Subvertex state)> GetTransitionsFromState(Subvertex fromState) {
      return _region.Transition.Where(x => x.Source == fromState.Id)
        .Select(x => (x, _region.Subvertices.Single(state => state.Id == x.Target)));
  }

  private string GetTransitionConditions(Transition transition) {
    var evt = transition.Trigger.Event;
    if (_changeEvents.ContainsKey(evt)) {
      return _changeEvents[evt].ChangeExpression.Body
        .Replace(" AND ", " && ")
        .Replace(" OR ", " || ")
        .Replace(" = ", " == ")
        .Replace(" <> ", " != ");
    }
    if (_timeEvents.ContainsKey(evt)) {
      return $"WHEN: {_timeEvents[evt].When.Expr.Body}";
    }
    throw new Exception("Invalid event reference.");
  }

  private string MakeSubrecord(string recordName, Subvertex x) {
    var isRegion = x.Regions.Any();
    var name = InPascalCase(x.Name);
    if (isRegion) {
      return new TheRegion(x.Regions.Single(), name, _changeEvents, _timeEvents).MakeStateRecord(name);
    } else {
      return $@"private record {name}() : {recordName}() {{
        public new static {name} New() => new {name}();
      }}";
    }
  }

  private string MakeStateRecord(string name) {
    var subrecords = _states.Select(x => MakeSubrecord(name, x));
    var (x, y) = GetTransitionsFromState(_initialState).Single();

    return @$"record {name} {{
    {string.Join("\n    ", subrecords)}

    public static {name} New() =>
      {name}.{InPascalCase(y.Name)}.New();

    private {name}() {{}}

    public {name} Transition() {{
        return this switch {{
{string.Join(",\n", _states.Select(fromState =>
  string.Join(",\n", $"{InPascalCase(fromState.Name)} => TransitionFrom{InPascalCase(fromState.Name)}()")))}
      }};
    }}

{string.Join("\n", _states.Select(fromState => GenerateTransition(name, fromState)))}
}}
";

  }

  private string GenerateTransition(string name, Subvertex fromState)
  {
    return $@"private {name} TransitionFrom{InPascalCase(fromState.Name)}() {{
      {GenerateConditions(fromState)}

      // Do not transition
      return this;
    }}
";
  }

  private string GenerateConditions(Subvertex fromState)
  {
     var transitions = GetTransitionsFromState(fromState)
      // Temporarily only process change events, will take care of
      // timed events later
      .Where(x => _changeEvents.ContainsKey(x.transition.Trigger.Event));
     return string.Join("\n", transitions.Select(x =>
     $@"if ({GetTransitionConditions(x.transition)}) {{
      return {InPascalCase(x.state.Name)}();
     }}"));
  }

  public override string Write()
  {
    return MakeStateRecord(InPascalCase(_name));
  }
}
