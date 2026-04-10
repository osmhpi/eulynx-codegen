using XmiToCode.Identifiers;

namespace XmiToCode.Codegen.Model;

public interface IBehaviorRecord
{
    IState? State { get; }
    string Name { get; }
    List<IBehaviorRecord> Subrecords { get; }
    TypeIdentifier ClassName { get; }
}
