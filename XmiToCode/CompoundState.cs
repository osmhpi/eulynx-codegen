using XmiToCode;

class CompoundState : Subvertex {
  public List<Subvertex> State { get; private set; }

  public CompoundState(List<Subvertex> state)
  {
      State = state;
  }

  // public string GetName() {
  //   return string.Join("_", State.Select(y => InPascalCase(y.Name)));
  // }

  // public override string Write()
  // {
  //   throw new NotImplementedException();
  // }
}
