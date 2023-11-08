using XmiToCode.Classes;

namespace XmiToCode.Codegen.Model;

public record SimpleBehaviorRecord(IState? State, string Name, string RecordName, ClassInfo ClassName) : IBehaviorRecord
{
    public List<IBehaviorRecord> Subrecords { get; } = new();
}
