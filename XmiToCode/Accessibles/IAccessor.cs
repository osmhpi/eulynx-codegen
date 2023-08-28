using XmiToCode.Context;

namespace XmiToCode.Accessibles;

public interface IAccessor {
    public string Accessor(PropertyOrPort propertyOrPort, IProgramContext context, TargetLanguage targetLanguage);
}
