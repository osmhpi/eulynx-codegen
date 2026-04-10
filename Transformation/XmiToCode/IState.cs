using XmiToCode.Instructions;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode;

public interface IState
{
    bool IsInitialState { get; }
    bool IsJunction { get; }
    bool IsRegularState { get; }
    string Name { get; }
    List<IRegion> Regions { get; }
    List<Instruction> Entry { get; }
    List<Instruction> Exit { get; }

    IState WithRegion(IRegion? region);

    bool IsSourceOfTransition(UmlTransition transition);
    bool IsTargetOfTransition(UmlTransition transition);
}
