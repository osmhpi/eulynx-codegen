namespace XmiToCode.Transformation.Model;

public record CompoundRegion(List<IState> States, List<Transition> Transitions) : IRegion {
    public IState InitialState => States.Single(x => x.IsInitialState);
}
