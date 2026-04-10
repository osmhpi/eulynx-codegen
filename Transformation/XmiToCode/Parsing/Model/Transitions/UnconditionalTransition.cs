using XmiToCode.Parsing.XmiModel;
using XmiToCode.Instructions;

namespace XmiToCode.Parsing.Model;

public record UnconditionalTransition(IState From, IState To, UmlTransition Transition, List<Instruction> Instructions) : Transition(From, To, [Transition], Instructions, []);
