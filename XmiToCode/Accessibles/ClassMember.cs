using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;

namespace XmiToCode.Accessibles;

public record ClassMember(Identifier Identifier) : IAccessible {
    public string Accessor(IProgramContext context, TargetLanguage targetLanguage) =>
        targetLanguage switch {
            TargetLanguage.Rust => Identifier.Name,
            TargetLanguage.C => context.IsLocalVariable(this)
                ? Identifier.Name
                : $"self->{Identifier.Name}",
            _ => context.IsLocalVariable(this)
                ? Identifier.Name
                : $"this.{Identifier.Name}"
        };

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage) =>
        $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }
}
