using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing;

public class EulynxV22XmiParser : XmiParser
{
    public EulynxV22XmiParser(string filename, string[]? classWhitelist = null, string[]? classBlacklist = null)
        : base(filename, classWhitelist, classBlacklist)
    {
    }

    public override List<PackagedElement> ResolveGenericEvents(List<PackagedElement> packages)
    {
        var collectionOfSignalEvents = packages.SingleOrDefault(x => x.Name == "Collection of signal events");
        if (collectionOfSignalEvents != null)
        {
            // Collection of signal events
            // Internal subsystem events
            return FindAllEvents(collectionOfSignalEvents).ToList();
        }
        throw new Exception("Could not resolve Collection of signal events package");
    }
}
