using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Model;

public abstract record BooleanExpression() : IAccessible {
    public abstract string Accessor(IProgramContext context, TargetLanguage targetLanguage);
    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        throw new NotImplementedException();
    }

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }

    public record Else() : BooleanExpression()
    {
        public override string Accessor(IProgramContext context, TargetLanguage targetLanguage) => "else";
    }

    public record Equality(IAccessible Lhs, IAccessible Rhs, bool Positive) : BooleanExpression()
    {
        public override string Accessor(IProgramContext context, TargetLanguage targetLanguage) =>
            Positive ? Lhs.Comparator(context, Rhs, targetLanguage) : $"!({Lhs.Comparator(context, Rhs, targetLanguage)})";
    }

    public record Negation(IAccessible Variable) : BooleanExpression()
    {
        public override string Accessor(IProgramContext context, TargetLanguage targetLanguage)
            => $"!({Variable.Accessor(context, targetLanguage)})";
    }

    public record Conjunction(IAccessible Lhs, IAccessible Rhs) : BooleanExpression()
    {
        public override string Accessor(IProgramContext context, TargetLanguage targetLanguage)
            => $"({Lhs.Accessor(context, targetLanguage)}) && ({Rhs.Accessor(context, targetLanguage)})";
    }

    public record Disjunction(IAccessible Lhs, IAccessible Rhs) : BooleanExpression() {
        public override string Accessor(IProgramContext context, TargetLanguage targetLanguage)
            => $"({Lhs.Accessor(context, targetLanguage)}) || ({Rhs.Accessor(context, targetLanguage)})";
    }
}
