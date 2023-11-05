using XmiToCode.Parsing;

namespace XmiToCode.Test;

public class EulynxV22XmiParserTest
{
    public const string EULYNX_V22_FILE = "cleaned_22.xmi";
    private readonly EulynxV22XmiParser _parser;

    public EulynxV22XmiParserTest()
    {
        _parser = new EulynxV22XmiParser(EULYNX_V22_FILE);
    }

    [Fact]
    public void ReadsAllInterestingPackages()
    {
        var packageNames = _parser.InterestingPackages.Select(x => x.Name).ToList();

        Assert.Contains("Generic requirements for SCI", packageNames);
        Assert.Contains("Generic requirements for subsystems", packageNames);
        Assert.Contains("Subsystem Point", packageNames);
        Assert.Contains("Subsystem IO", packageNames);
        Assert.Contains("Subsystem Light Signal", packageNames);
        Assert.Contains("Subsystem Level Crossing", packageNames);
        Assert.Contains("Subsystem Train Detection System", packageNames);
    }

    [Fact]
    public void PopulatesGlobalContextWithSySimDataTypes()
    {
        var global = _parser.GlobalContext;

        var dataTypeNames = global.DataTypes.Values.Select(x => x.Name).ToList();
        Assert.Contains("Boolean", dataTypeNames);
        Assert.Contains("DateTime", dataTypeNames);
        Assert.Contains("Decimal", dataTypeNames);
        Assert.Contains("Double", dataTypeNames);
        Assert.Contains("Integer", dataTypeNames);
        Assert.Contains("Long", dataTypeNames);
        Assert.Contains("Single", dataTypeNames);
        Assert.Contains("String", dataTypeNames);
        Assert.Contains("Timespan", dataTypeNames);
        Assert.Contains("Message", dataTypeNames);
        Assert.Contains("Permanent_Information", dataTypeNames);
        Assert.Contains("PulsedIn", dataTypeNames);
        Assert.Contains("PulsedOut", dataTypeNames);
    }

    [Fact]
    public void PopulatesGlobalContextWithChangeEvents()
    {
        var global = _parser.GlobalContext;
        Assert.NotEmpty(global.ChangeEvents);
    }

    [Fact]
    public void PopulatesGlobalContextWithTimeEvents()
    {
        var global = _parser.GlobalContext;
        Assert.NotEmpty(global.TimeEvents);
    }

    [Fact]
    public void PopulatesGlobalContextWithEnumerations()
    {
        var global = _parser.GlobalContext;
        Assert.NotEmpty(global.Enumerations);
    }

    [Fact]
    public void PopulatesGlobalContextWithSignals()
    {
        var global = _parser.GlobalContext;
        Assert.NotEmpty(global.Signals);
    }

    [Fact]
    public void PopulatesGlobalContextWithGenericEvents()
    {
        var global = _parser.GlobalContext;
        Assert.NotEmpty(global.GenericEvents);
    }

    [Fact]
    public void ParsesPackages()
    {
        var packages = _parser.ParsePackages();
        Assert.NotEmpty(packages);
    }
}
