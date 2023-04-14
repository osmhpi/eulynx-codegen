using XmiToCode;

record OurRegion(List<IState> States, List<OurTransition> Transitions) {
    public IState InitialState => States.Single(x => x.IsInitialState);
}
