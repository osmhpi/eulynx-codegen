using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Accessibles;

public interface IAccessor {
    public string Accessor(PropertyOrPort propertyOrPort, IProgramContext context, TargetLanguage targetLanguage);
}
