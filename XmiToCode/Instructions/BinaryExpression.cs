
enum BinaryExpressionOperator {
    Equal,
    NotEqual
}

record BinaryExpression(IAccessible Lhs, IAccessible Rhs, BinaryExpressionOperator Operator) {
    public static BinaryExpressionOperator ParseOperator(string op) => op switch {
        "==" => BinaryExpressionOperator.Equal,
        "!=" => BinaryExpressionOperator.NotEqual,
        _ => throw new NotImplementedException()
    };

    internal string ToCSharp(ProgramContext context)
    {
        return Operator switch {
            BinaryExpressionOperator.Equal => $"{Lhs.Accessor(context, TargetLanguage.CSharp)}.Equals({Rhs.Accessor(context, TargetLanguage.CSharp)})",
            BinaryExpressionOperator.NotEqual => $"!{Lhs.Accessor(context, TargetLanguage.CSharp)}.Equals({Rhs.Accessor(context, TargetLanguage.CSharp)})",
            _ => throw new NotImplementedException()
        };
    }
}
