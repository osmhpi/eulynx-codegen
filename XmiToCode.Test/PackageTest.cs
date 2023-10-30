namespace XmiToCode.Test;

public class PackageTest
{
    [Fact]
    public void ReadsXmiFile()
    {
        var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");
        var proc = new XmiProcessor(xmiPath);
        var point = proc.ParsedPackages.Single(x => x.Name.RawName == "Subsystem Point");
        var fscipreport = point.Classes.Single(x => x.Info.ClassName == "FSciPReport");

        Assert.Contains(fscipreport.States, x => x.Name == "FSciPReportBehaviour.InterfaceConnectionNotEstablished");
        Assert.Contains(fscipreport.States, x => x.Name == "FSciPReportBehaviour.ReportingOverallPointStates");
        Assert.Contains(fscipreport.States, x => x.Name == "FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_Waiting_MsgMovementFailed");
        Assert.Contains(fscipreport.States, x => x.Name == "FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_MsgOverallPointPosition_MsgMovementFailed");
        Assert.Equal(4, fscipreport.States.Count);

        Assert.Equal(3, fscipreport.Operations.Count);
    }
}
