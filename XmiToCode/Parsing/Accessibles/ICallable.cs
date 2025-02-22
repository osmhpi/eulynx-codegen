using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Accessibles;

public interface ICallable {
    Operation Operation { get; }
    public string Call(IProgramContext context, List<IAccessible> arguments, TargetLanguage targetLanguage);
    public void EnsureReturnTypeMatches(IAccessible accessible);
}
