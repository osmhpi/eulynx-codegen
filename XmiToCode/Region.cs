public record Region(List<IState> States, List<Transition> Transitions) {
    public IState InitialState => States.Single(x => x.IsInitialState);
}
