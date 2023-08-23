
record MessageInitializer(MessageSchema Schema, List<IAccessible> Values)
{
    internal string ToCSharp(ProgramContext context)
    {
        return $"new Message.{Schema.Identifier.Name}({string.Join(", ", Values.Select(x => x.Accessor(context, TargetLanguage.CSharp)))})";
    }

    internal string ToC(ProgramContext context)
    {
        var valuesAndProperties = Schema.Members.Zip(Values);
        return string.Join("\n", valuesAndProperties.Select(x => x.First.Assign(context, x.Second, TargetLanguage.C)));
    }

    internal string ToRust(ProgramContext context)
    {
        var valuesAndProperties = Schema.Members.Zip(Values);
        return $"Message__{Schema.Identifier.Name} msg = {{ {string.Join(", ", valuesAndProperties.Select(x => $".{x.First.MemberName.Name} = {x.Second.Accessor(context, TargetLanguage.Rust)}"))} }};";
    }
}
