using XmiToCode.Parsing.Context;

namespace XmiToCode.Accessibles;

public interface IAccessor {
    public string Accessor(PropertyOrPort propertyOrPort, IProgramContext context, TargetLanguage targetLanguage);
}
