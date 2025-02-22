using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Accessibles;

public class ParameterAccessor : IAccessor {
    public string Accessor(PropertyOrPort propertyOrPort, IProgramContext context, TargetLanguage targetLanguage) {
        return propertyOrPort.Name;
    }
}
