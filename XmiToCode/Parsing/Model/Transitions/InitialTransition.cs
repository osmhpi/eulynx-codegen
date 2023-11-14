using XmiToCode.Parsing.XmiModel;
using XmiToCode.Instructions;

namespace XmiToCode.Parsing.Model;

public record InitialTransition(IState From, IState To, List<UmlTransition> Transitions, List<Instruction> Instructions, List<Constraint> Constraints) : Transition(From, To, Transitions, Instructions, Constraints);
