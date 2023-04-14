using XmiToCode;

record OurRegion(Region Region, List<IState> States) {
    public IState InitialState => States.Single(x => x.IsInitialState);
}
