using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing;

public class EulynxV19XmiParser : XmiParser
{
    public EulynxV19XmiParser(string filename, string[]? classWhitelist = null, string[]? classBlacklist = null)
        : base(filename, classWhitelist, classBlacklist)
    {
    }

    public override List<PackagedElement> ResolveGenericEvents(List<PackagedElement> packages)
    {
        var genericFunctions = packages.SingleOrDefault(x => x.Name == "Generic Functions");
        if (genericFunctions != null)
        {
            return FindAllEvents(genericFunctions).ToList();
        }
        throw new Exception("Could not resolve generic functions package");
    }
}
