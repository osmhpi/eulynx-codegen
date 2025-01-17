using XmiToCode.Messages;
using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Model;

public abstract record BooleanExpression() : IAccessible {
    public abstract string Accessor(IProgramContext context, TargetLanguage targetLanguage);
    public virtual string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        return $"{Accessor(context, targetLanguage)} == {other.Accessor(context, targetLanguage)}";
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
        public static Equality Create(IAccessible lhs, IAccessible rhs, bool positive) {
            if (lhs is StringPropertyOrPort lhsString) {
                if  (rhs is StringPropertyOrPort rhsString)
                    lhsString.RequireConversionFrom(rhsString);
                if (rhs is MessageMember rhsMessageMember && rhsMessageMember.Member is StringPropertyOrPort rhsMessageMemberString)
                    lhsString.RequireConversionFrom(rhsMessageMemberString);
            }
            if (lhs is MessageMember lhsMessageMember && lhsMessageMember.Member is StringPropertyOrPort lhsMessageMemberString) {
                if  (rhs is StringPropertyOrPort rhsString)
                    lhsMessageMemberString.RequireConversionFrom(rhsString);
                if (rhs is MessageMember rhsMessageMember && rhsMessageMember.Member is StringPropertyOrPort rhsMessageMemberString)
                    lhsMessageMemberString.RequireConversionFrom(rhsMessageMemberString);
            }

            return new Equality(lhs, rhs, positive);
        }
        public override string Accessor(IProgramContext context, TargetLanguage targetLanguage) =>
            Positive ? Lhs.Comparator(context, Rhs, targetLanguage) : $"!({Lhs.Comparator(context, Rhs, targetLanguage)})";
    }

    public record Negation(IAccessible Variable) : BooleanExpression()
    {
        public override string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage)
        {
            return $"{Variable.Accessor(context, targetLanguage)} != {other.Accessor(context, targetLanguage)}";
        }

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
