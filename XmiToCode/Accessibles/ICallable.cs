using XmiToCode.Parsing.Context;

namespace XmiToCode.Accessibles;

public interface ICallable {
    public string Call(IProgramContext context, TargetLanguage targetLanguage);
}
