using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Accessibles;

public interface ICallable {
    public string Call(IProgramContext context, TargetLanguage targetLanguage);
}
