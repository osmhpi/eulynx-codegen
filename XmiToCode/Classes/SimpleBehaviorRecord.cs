namespace XmiToCode.Classes;

public record SimpleBehaviorRecord(IState? State, string Name, string RecordName, ClassInfo ClassName) : IBehaviorRecord
{
    public List<IBehaviorRecord> Subrecords { get; } = new();
}
