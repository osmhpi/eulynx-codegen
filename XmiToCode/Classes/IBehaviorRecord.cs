namespace XmiToCode.Classes;

public interface IBehaviorRecord
{
    IState? State { get; }
    string Name { get; }
    List<IBehaviorRecord> subrecords { get; }
    ClassInfo className { get; }
}
