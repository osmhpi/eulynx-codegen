using XmiToCode;

record CompoundState(List<PartialState> PartialStates, OurRegion? Region) : IState
{
    public bool IsInitialState => PartialStates.Any(x => x.Vertex.Name.Contains("Initial") && x.Vertex.Type == "uml:Pseudostate");

    public bool IsJunction => PartialStates.Any(x => x.Vertex.Name.Contains("Junction") && x.Vertex.Type == "uml:Pseudostate");

    public bool IsRegularState => PartialStates.All(x => x.Vertex.Type == "uml:State");

    public string Name => string.Join("_", PartialStates.Select(x => x.Vertex.Name));


    public List<OurTransition> Transitions => throw new NotImplementedException();

    public StateMachine CreateChildStateMachine(Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
    {
        throw new NotImplementedException();
    }

    public string GenerateEntry(IState previous, Transition transition)
    {
        throw new NotImplementedException();
    }

    public string GenerateEntry(IState previous, OurTransition transition)
    {
        throw new NotImplementedException();
    }

    public string GenerateExit(IState next, Transition transition)
    {
        throw new NotImplementedException();
    }

    public string GenerateExit(IState next, OurTransition transition)
    {
        throw new NotImplementedException();
    }

    public string GenerateTransition(IState next, Transition transition)
    {
        throw new NotImplementedException();
    }

    public string GenerateTransition(IState next, OurTransition transition)
    {
        throw new NotImplementedException();
    }

    public bool IsSourceOfTransition(Transition transition)
    {
        throw new NotImplementedException();
    }

    public bool IsTargetOfTransition(Transition transition)
    {
        throw new NotImplementedException();
    }
}

record PartialState(Subvertex Vertex, Region EnclosingRegion, List<Transition> Transitions);
