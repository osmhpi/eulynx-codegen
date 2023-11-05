namespace XmiToCode.Classes;

public interface IBehaviorRecord
{
    IState? State { get; }
    string Name { get; }
    List<IBehaviorRecord> Subrecords { get; }
    ClassInfo ClassName { get; }
}
