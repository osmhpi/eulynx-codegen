using static CodeGenerationHelper;

record MessageInitializer(TypeIdentifier Message, List<MessageMember> Schema, List<IAccessible> Values)
{
    internal string ToCSharp(ProgramContext context)
    {
        return $"new Message.{Message.Name}({string.Join(", ", Values.Select(x => x.Accessor(context, TargetLanguage.CSharp)))})";
    }

    internal string ToC(ProgramContext context)
    {
        var valuesAndProperties = Schema.Zip(Values);
        return JoinLines(valuesAndProperties.Select(x => x.First.Assign(context, x.Second, TargetLanguage.C)));
    }

    internal string ToRust(ProgramContext context)
    {
        var valuesAndProperties = Schema.Zip(Values);
        return $"Message__{Message.Name} msg = {{ {string.Join(", ", valuesAndProperties.Select(x => $".{x.First.Member.Identifier.Name} = {x.Second.Accessor(context, TargetLanguage.Rust)}"))} }};";
    }
}
