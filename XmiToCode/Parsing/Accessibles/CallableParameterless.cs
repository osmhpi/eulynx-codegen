using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Accessibles;

public record CallableParameterless(ICallable Callable) : IAccessible
{
    public string Accessor(IProgramContext context, TargetLanguage targetLanguage) => Callable.Call(context, [], targetLanguage);

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage) => throw new NotImplementedException();

    public void EnsureComparableTypes(IAccessible rhsIdentifier) => Callable.EnsureReturnTypeMatches(rhsIdentifier);
}
