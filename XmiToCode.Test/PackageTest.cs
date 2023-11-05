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
    public void ReadsXmiFile()
    {
        var pointPackage = _packages.Single(x => x.Name.RawName == SubsystemPointPackageName);
        var fscipreport = pointPackage.ParseAllClasses().Single(x => x.Info.ClassName == "FSciPReport");

        Assert.Contains(fscipreport.States, x => x.Name == "FSciPReportBehaviour.InterfaceConnectionNotEstablished");
        Assert.Contains(fscipreport.States, x => x.Name == "FSciPReportBehaviour.ReportingOverallPointStates");
        Assert.Contains(fscipreport.States, x => x.Name == "FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_Waiting_MsgMovementFailed");
        Assert.Contains(fscipreport.States, x => x.Name == "FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_MsgOverallPointPosition_MsgMovementFailed");
        Assert.Equal(4, fscipreport.States.Count);

        Assert.Equal(3, fscipreport.Operations.Count);
    }

    [Fact]
    public void PopulatesEvents() {
        var pointPackage = _packages.Single(x => x.Name.RawName == SubsystemPointPackageName);
        Assert.NotEmpty(pointPackage.Context.PackageEvents);
    }

    [Fact]
    public void ParsesPointClasses() {
        var pointPackage = _packages.Single(x => x.Name.RawName == SubsystemPointPackageName);
        var classes = pointPackage.ParseAllClasses();
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
