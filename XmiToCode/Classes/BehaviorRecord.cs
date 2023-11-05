using XmiToCode.Codegen;

namespace XmiToCode.Classes;

public record BehaviorRecord(
    IState? State,
    StateMachine StateMachine,
    string Name,
    string? parentBehaviorName,
    ClassInfo ClassName,
    ICodeTransition Initializer,
    List<IBehaviorRecord> Subrecords
) : IBehaviorRecord;
