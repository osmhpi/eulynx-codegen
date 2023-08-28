using XmiToCode.Context;

namespace XmiToCode.Accessibles;

public interface IAccessible {
    public string Accessor(IProgramContext context, TargetLanguage targetLanguage);
    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage);
    void EnsureComparableTypes(IAccessible rhsIdentifier);
}
