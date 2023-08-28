namespace XmiToCode.Classes;

public record SimpleBehaviorRecord(IState? State, string Name, string recordName, ClassInfo className) : IBehaviorRecord
{
    public List<IBehaviorRecord> subrecords { get; } = new();
}
