using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Context;

public interface IInstructionContext : IProgramContext
{
    Dictionary<string, PackagedElement> PackageEvents { get; }
    PackageContext Package { get; }
}
