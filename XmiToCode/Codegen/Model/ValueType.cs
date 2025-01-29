using XmiToCode.Identifiers;
using XmiToCode.Parsing.Accessibles;

namespace XmiToCode.Codegen.Model;

public record ValueType(TypeIdentifier ClassName, Identifier Identifier, HashSet<ImplicitEnumMember> AllowedValues);
