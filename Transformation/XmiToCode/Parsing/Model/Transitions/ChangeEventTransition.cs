using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.XmiModel;
using XmiToCode.Instructions;

namespace XmiToCode.Parsing.Model;

public record ChangeEventTransition(IState From, IState To, UmlTransition Transition, PackagedElement theEvent, IAccessible Condition, List<Instruction> Instructions, List<Constraint> Constraints) : Transition(From, To, new List<UmlTransition> { Transition }, Instructions, Constraints);
