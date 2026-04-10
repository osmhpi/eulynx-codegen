using XmiToCode.Parsing;
using XmiToCode.Parsing.Model;

namespace XmiToCode.Test;

public class PackageTest
{
    public const string GenericSciPackageName = "Generic requirements for SCI";
    public const string GenericSubsystemsPackageName = "Generic requirements for subsystems";
    public const string FEstEfesClassName = "F_EST_EfeS";
    public const string SubsystemPointPackageName = "Subsystem Point";
    public const string SSciEfesPrimClassName = "S_SCI_EfeS_Prim";
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
    public void ParsesFEstEfes() {
        var genericSciPackage = _packages.Single(x => x.Name.RawName == GenericSubsystemsPackageName);
        var success = genericSciPackage.TryParseClass(FEstEfesClassName, out var parsedClass);
        Assert.True(success);
        Assert.NotNull(parsedClass);
        // TODO: After transformation, the transitions from Operational to
        // WaitingForNoMaintenanceTimeout and WaitingForPdiOrMaintenance are lost.
    }

    [Fact]
    public void ParsesSSciEfesPrim() {
        var genericSciPackage = _packages.Single(x => x.Name.RawName == GenericSciPackageName);
        var success = genericSciPackage.TryParseClass(SSciEfesPrimClassName, out var parsedClass);
        Assert.True(success);
        Assert.NotNull(parsedClass);
        // TODO: This makes use of a HACK in the Parser
    }

    [Fact]
    public void ParsesFSciEfesSec() {
        var genericSciPackage = _packages.Single(x => x.Name.RawName == GenericSciPackageName);
        var success = genericSciPackage.TryParseClass(FSciEfesSecClassName, out var parsedClass);
        Assert.True(success);
        Assert.NotNull(parsedClass);
    }
}
