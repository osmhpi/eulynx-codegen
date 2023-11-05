using XmiToCode.Classes;
using XmiToCode.Parsing;

namespace XmiToCode.Test;

public class PackageTest
{
    public const string GenericSciPackageName = "Generic requirements for SCI";
    public const string SubsystemPointPackageName = "Subsystem Point";
    private readonly List<Package> _packages;

    public PackageTest()
    {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        _packages = parser.ParsePackages();
    }

    [Fact]
    public void PopulatesEvents() {
        var pointPackage = _packages.Single(x => x.Name.RawName == SubsystemPointPackageName);
        Assert.NotEmpty(pointPackage.Context.PackageEvents);
    }

    [Fact]
    public void ParsesPointClasses() {
        var pointPackage = _packages.Single(x => x.Name.RawName == SubsystemPointPackageName);
        var classes = pointPackage.TryParseAllClasses();
        Assert.NotEmpty(classes);
    }

    [Fact]
    public void ParsesFSciEfesSec() {
        var genericSciPackage = _packages.Single(x => x.Name.RawName == GenericSciPackageName);
        var success = genericSciPackage.TryParseClass("F_SCI_EfeS_Sec", out var parsedClass);
        Assert.True(success);
        Assert.NotNull(parsedClass);
    }
}
