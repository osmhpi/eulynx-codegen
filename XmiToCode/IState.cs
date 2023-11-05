using XmiToCode.Parsing.Context;
using XmiToCode.Instructions;
using XmiToCode.Parsing.XmiModel;
using XmiToCode.Identifiers;

namespace XmiToCode;

public interface IState
{
    bool IsInitialState { get; }
    bool IsJunction { get; }
    bool IsRegularState { get; }
    string Name { get; }
    public TypeIdentifier StateName { get; }

    StateMachine? InternalStateMachine { get; }

    List<Instruction> ParseExit(IState next, Transition transition, IProgramContext context);
    List<Instruction> ParseTransition(IState next, Transition transition, IProgramContext context);
    List<Instruction> ParseEntry(IState previous, Transition transition, IProgramContext context);

    bool IsSourceOfTransition(UmlTransition transition);
    bool IsTargetOfTransition(UmlTransition transition);
}
