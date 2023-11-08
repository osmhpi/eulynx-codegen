using XmiToCode.Identifiers;

namespace XmiToCode.Codegen.Model;

public record SimpleBehaviorRecord(IState? State, string Name, string RecordName, TypeIdentifier ClassName) : IBehaviorRecord
{
    public List<IBehaviorRecord> Subrecords { get; } = new();
}
