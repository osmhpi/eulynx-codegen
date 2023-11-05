namespace XmiToCode;

public record FlatRegion(List<IState> States, List<Transition> Transitions) : IRegion {
    public IState InitialState => States.Single(x => x.IsInitialState);
}
