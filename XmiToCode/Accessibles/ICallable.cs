using XmiToCode.Context;

namespace XmiToCode.Accessibles;

public interface ICallable {
    public string Call(IProgramContext context, TargetLanguage targetLanguage);
}
