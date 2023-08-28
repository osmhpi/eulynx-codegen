using XmiToCode.Codegen;

namespace XmiToCode.Classes;

public record BehaviorRecord(
    IState? State,
    StateMachine StateMachine,
    string Name,
    string? parentBehaviorName,
    ClassInfo className,
    ICodeTransition initializer,
    List<IBehaviorRecord> subrecords
) : IBehaviorRecord;
