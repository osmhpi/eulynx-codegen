namespace XmiToCode.Test;

public class PackageTest
{
    [Fact]
    public void ReadsXmiFile()
    {
        var proc = new XmiProcessor("/Users/robert/dkw/XmiToCode/cleaned_23.xmi");
        var point = proc.ParsedPackages.Single(x => x.Name.RawName == "Subsystem Point");
        var fscipreport = point.Classes.Single(x => x.Info.ClassName == "FSciPReport");

        Assert.True(fscipreport.States.Any(x => x.Name == "FSciPReportBehaviour.InterfaceConnectionNotEstablished"));
        Assert.True(fscipreport.States.Any(x => x.Name == "FSciPReportBehaviour.ReportingOverallPointStates"));
        Assert.True(fscipreport.States.Any(x => x.Name == "FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_Waiting_MsgMovementFailed"));
        Assert.True(fscipreport.States.Any(x => x.Name == "FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_MsgOverallPointPosition_MsgMovementFailed"));
        Assert.Equal(4, fscipreport.States.Count);

        Assert.Equal(3, fscipreport.Operations.Count);
    }
}
