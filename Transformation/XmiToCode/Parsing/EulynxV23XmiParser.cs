namespace XmiToCode.Parsing;

public class EulynxV23XmiParser : EulynxV22XmiParser
{
    public EulynxV23XmiParser(string filename, string[]? classWhitelist = null, string[]? classBlacklist = null)
        : base(filename, classWhitelist, classBlacklist)
    {
    }
}
