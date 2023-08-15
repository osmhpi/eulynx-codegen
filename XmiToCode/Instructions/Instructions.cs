
public abstract record Instruction {
    internal abstract string ToCSharp(ProgramContext context);
    internal abstract string ToC(ProgramContext context);
    internal abstract string ToRust(ProgramContext context);
}

record MessageInitializer(MessageSchema Schema, List<IAccessible> Values)
{
    internal string ToCSharp(ProgramContext context)
    {
        return $"new Message.{Schema.Identifier.Name}({string.Join(", ", Values.Select(x => x.Accessor(context)))})";
    }

    internal string ToC(ProgramContext context)
    {
        var valuesAndProperties = Schema.Members.Zip(Values);
        return $"Message__{Schema.Identifier.Name} msg = {{ {string.Join(", ", valuesAndProperties.Select(x => $".{x.First.MemberName.Name} = {x.Second.Accessor(context)}"))} }};";
    }

    internal string ToRust(ProgramContext context)
    {
        var valuesAndProperties = Schema.Members.Zip(Values);
        return $"Message__{Schema.Identifier.Name} msg = {{ {string.Join(", ", valuesAndProperties.Select(x => $".{x.First.MemberName.Name} = {x.Second.Accessor(context)}"))} }};";
    }
}

record SendMessageInstruction(MessageInitializer initialize, IAccessible port) : Instruction
{
    internal override string ToCSharp(ProgramContext context)
    {
        return $"{context.InstanceReference}.SendMessage({initialize.ToCSharp(context)}, {port.Accessor(context)});";
    }

    internal override string ToC(ProgramContext context)
    {
        return $@"
  {initialize.ToC(context)}
  {context.InstanceReference}->{initialize.Schema.Identifier.Name}.Value = msg;
  {context.InstanceReference}->{initialize.Schema.Identifier.Name}.Some = 1;";
    }

    internal override string ToRust(ProgramContext context)
    {
        return $@"
  {initialize.ToRust(context)}
  {context.InstanceReference}->{initialize.Schema.Identifier.Name}.Value = msg;
  {context.InstanceReference}->{initialize.Schema.Identifier.Name}.Some = 1;";
    }
}

record AssignmentInstruction(IAssignable Lhs, IAccessible Rhs) : Instruction
{
    internal override string ToCSharp(ProgramContext context)
    {
        return $"{Lhs.Accessor(context)} = {Rhs.Accessor(context)};";
    }
    internal override string ToC(ProgramContext context)
    {
        return $"{Lhs.Accessor(context)} = {Rhs.Accessor(context)};";
    }
    internal override string ToRust(ProgramContext context)
    {
        return $"{Lhs.Accessor(context)} = {Rhs.Accessor(context)};";
    }
}

record MethodCallInstruction(ICallable Callable) : Instruction
{
    internal override string ToCSharp(ProgramContext context)
    {
        return $"{Callable.Call(context, TargetLanguage.CSharp)};";
    }
    internal override string ToC(ProgramContext context)
    {
        return $"{Callable.Call(context, TargetLanguage.C)};";
    }
    internal override string ToRust(ProgramContext context)
    {
        return $"{Callable.Call(context, TargetLanguage.Rust)};";
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
