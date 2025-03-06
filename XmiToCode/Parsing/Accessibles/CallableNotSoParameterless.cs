using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Accessibles;

public record CallableNotSoParameterless(ICallable Callable, List<IAccessible> Parameters) : IAccessible
{
    public string Accessor(IProgramContext context, TargetLanguage targetLanguage) => Callable.Call(context, Parameters, targetLanguage);

    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage) => throw new NotImplementedException();

    public void EnsureComparableTypes(IAccessible rhsIdentifier) => Callable.EnsureReturnTypeMatches(rhsIdentifier);
}
