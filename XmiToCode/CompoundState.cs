using XmiToCode;

class CompoundState : Subvertex {
  public List<Subvertex> State { get; private set; }

  public CompoundState(List<Subvertex> state)
  {
      State = state;
  }
}
