using XmiToCode.Identifiers;
using XmiToCode.Transformation.Model;

namespace XmiToCode.Codegen.Model;

public record BehaviorRecord(
    IState? State,
    IRegion Region,
    string Name,
    string? parentBehaviorName,
    TypeIdentifier ClassName,
    ICodeTransition Initializer,
    List<IBehaviorRecord> Subrecords
) : IBehaviorRecord;
