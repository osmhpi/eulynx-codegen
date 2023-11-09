
using XmiToCode.Parsing.Model;

namespace XmiToCode;

public interface IRegion
{
    IState InitialState { get; }
    List<IState> States { get; }
    List<Transition> Transitions { get; }
}
