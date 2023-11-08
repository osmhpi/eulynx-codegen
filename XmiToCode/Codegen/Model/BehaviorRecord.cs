using XmiToCode.Classes;
using XmiToCode.Transformation.Model;

namespace XmiToCode.Codegen.Model;

public record BehaviorRecord(
    IState? State,
    StateMachine StateMachine,
    string Name,
    string? parentBehaviorName,
    ClassInfo ClassName,
    ICodeTransition Initializer,
    List<IBehaviorRecord> Subrecords
) : IBehaviorRecord;
