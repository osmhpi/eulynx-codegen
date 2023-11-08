using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Messages;
using static XmiToCode.Codegen.CodeGenerationHelper;

namespace XmiToCode.Instructions;

record MessageInitializer(TypeIdentifier Message, List<MessageMember> Schema, List<IAccessible> Values)
{
    internal string ToCSharp(IProgramContext context)
    {
        return $"new Message.{Message.Name}({string.Join(", ", Values.Select(x => x.Accessor(context, TargetLanguage.CSharp)))})";
    }

    internal string ToC(IProgramContext context)
    {
        var valuesAndProperties = Schema.Zip(Values);
        return JoinLines(valuesAndProperties.Select(x => x.First.Assign(context, x.Second, TargetLanguage.C)));
    }

    internal string ToRust(IProgramContext context)
    {
        var valuesAndProperties = Schema.Zip(Values);
        return $"Message__{Message.Name} msg = {{ {string.Join(", ", valuesAndProperties.Select(x => $".{x.First.Member.Identifier.Name} = {x.Second.Accessor(context, TargetLanguage.Rust)}"))} }};";
    }
}
