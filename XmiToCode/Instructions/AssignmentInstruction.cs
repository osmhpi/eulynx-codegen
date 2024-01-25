using XmiToCode.Messages;
using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Instructions;

record AssignmentInstruction(IAssignable Lhs, IAccessible Rhs, IProgramContext Context) : Instruction(Context)
{
    public static AssignmentInstruction Create(IAssignable lhs, IAccessible rhs, IProgramContext context) {
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

        return new AssignmentInstruction(lhs, rhs, context);
    }

    internal override string ToCSharp()
    {
        return Lhs.Assign(Context, Rhs, TargetLanguage.CSharp);
    }
    internal override string ToC()
    {
        return Lhs.Assign(Context, Rhs, TargetLanguage.C);
    }
    internal override string ToRust()
    {
        return Lhs.Assign(Context, Rhs, TargetLanguage.Rust);
    }
}
