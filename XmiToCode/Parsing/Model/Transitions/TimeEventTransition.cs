using XmiToCode.Parsing.XmiModel;
using XmiToCode.Instructions;

namespace XmiToCode.Parsing.Model;

public record TimeEventTransition(IState From, IState To, UmlTransition Transition, PackagedElement theEvent, List<Instruction> Instructions, List<Constraint> Constraints) : Transition(From, To, new List<UmlTransition> { Transition }, Instructions, Constraints);
