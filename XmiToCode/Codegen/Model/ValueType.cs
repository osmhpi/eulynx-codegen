using XmiToCode.Identifiers;

namespace XmiToCode.Codegen.Model;

public record ValueType(TypeIdentifier ClassName, Identifier Identifier, HashSet<LiteralIdentifier> AllowedValues);
