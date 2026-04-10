using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;
using XmiToCode.Instructions;

namespace XmiToCode.Parsing.Model;

public record MessageEventTransition(IState From, IState To, UmlTransition Transition, PackagedElement evt, TypeIdentifier MessageType, List<Instruction> Instructions, List<Constraint> Constraints) : Transition(From, To, new List<UmlTransition> { Transition }, Instructions, Constraints);
