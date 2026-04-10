using XmiToCode.Parsing.Model;

namespace XmiToCode.Codegen;

public interface ICodeTransition {
    public Transition Transition { get; }
    public List<Constraint> Constraint { get; }
}
