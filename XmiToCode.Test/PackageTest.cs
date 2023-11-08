using XmiToCode.Parsing;
using XmiToCode.Parsing.Model;

namespace XmiToCode.Test;

public class PackageTest
{
    public const string GenericSciPackageName = "Generic requirements for SCI";
    public const string SubsystemPointPackageName = "Subsystem Point";
    public const string FSciEfesSecClassName = "F_SCI_EfeS_Sec";
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
        var success = genericSciPackage.TryParseClass(FSciEfesSecClassName, out var parsedClass);
        Assert.True(success);
        Assert.NotNull(parsedClass);
    }
}
