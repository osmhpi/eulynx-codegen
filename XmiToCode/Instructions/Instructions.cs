
record Instruction;

record MessageInitializer(MessageSchema Schema, List<IAccessible> Values)
{
    internal string ToCSharp(ProgramContext context)
    {
        return $"new Message.{Schema.Identifier.Name}({string.Join(", ", Values.Select(x => x.Accessor(context)))})";
    }
}

record SendMessageInstruction(MessageInitializer initialize, IAccessible port) : Instruction
{
    internal string ToCSharp(ProgramContext context)
    {
        return $"{context.InstanceReference}.SendMessage({initialize.ToCSharp(context)}, {port.Accessor(context)});";
    }
}

record AssignmentInstruction(IAssignable Lhs, IAccessible Rhs) : Instruction
{
    internal string ToCSharp(ProgramContext context)
    {
        return $"{Lhs.Accessor(context)} = {Rhs.Accessor(context)};";
    }
}

record MethodCallInstruction(ICallable Callable) : Instruction
{
    internal string ToCSharp(ProgramContext context)
    {
        return $"{Callable.Call(context)};";
    }
}

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
            BinaryExpressionOperator.Equal => $"{Lhs.Accessor(context)}.Equals({Rhs.Accessor(context)})",
            BinaryExpressionOperator.NotEqual => $"!{Lhs.Accessor(context)}.Equals({Rhs.Accessor(context)})",
            _ => throw new NotImplementedException()
        };
    }
}
