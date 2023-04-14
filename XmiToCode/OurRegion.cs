using XmiToCode;

record OurRegion(Region Region, List<IState> States, List<OurTransition> Transitions) {
    public IState InitialState => States.Single(x => x.IsInitialState);
}
