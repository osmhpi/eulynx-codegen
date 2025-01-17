namespace XmiToCode.Parsing;

public class EulynxV28XmiParser : EulynxV22XmiParser
{
    public override string[] PackageWhitelist { get; } = new[] {
        "Generic requirements for SCI",
        "Generic requirements for subsystems",
        "Subsystem - Point",
        "Subsystem - Generic IO",
        "Subsystem - Light Signal",
        "Subsystem - Level Crossing",
        "Subsystem - Train Detection System",
    };
    public EulynxV28XmiParser(string filename, string[]? classWhitelist = null, string[]? classBlacklist = null)
        : base(filename, classWhitelist, classBlacklist)
    {
    }
}
