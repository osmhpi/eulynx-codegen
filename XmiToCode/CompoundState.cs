using XmiToCode;

record CompoundState(List<PartialState> PartialStates) : IState
{
    public bool IsInitialState => throw new NotImplementedException();

    public bool IsJunction => throw new NotImplementedException();

    public bool IsRegularState => throw new NotImplementedException();

    public string Name => string.Join("_", PartialStates.Select(x => x.Vertex.Name));

    public OurRegion Region => throw new NotImplementedException();

    public string VertexId => throw new NotImplementedException();

    public StateMachine CreateChildStateMachine(Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
    {
        throw new NotImplementedException();
    }

    public string GenerateEntry(IState previous, Transition transition)
    {
        throw new NotImplementedException();
    }

    public string GenerateExit(IState next, Transition transition)
    {
        throw new NotImplementedException();
    }

    public string GenerateTransition(IState next, Transition transition)
    {
        throw new NotImplementedException();
    }
}

record PartialState(Subvertex Vertex, Region EnclosingRegion, List<Transition> Transitions);
