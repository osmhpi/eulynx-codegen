using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Model;

public record Constraint(IProgramContext Context, IAccessible Condition)
{
    internal string Accessor(TargetLanguage targetLanguage)
    {
        return Condition.Accessor(Context, targetLanguage);
    }
}
