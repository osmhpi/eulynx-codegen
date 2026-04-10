using XmiToCode.Codegen.Model;
using XmiToCode.Parsing;
using XmiToCode.Transformation;

namespace XmiToCode.Test;

public class BehaviorRecordTest
{
    public const string SubsystemTrainDetectionSystemPackageName = "Subsystem Train Detection System";
    public const string FObserveTrackCircuitsClassName = "F_Observe_Track_Circuits";

    [Fact]
    public void NestedStateNamesShouldBeDistinct() {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        var packages = parser.ParsePackages();
        var subsystemTrainDetectionSystemPackage = packages.Single(x => x.Name.RawName == SubsystemTrainDetectionSystemPackageName);
        _ = subsystemTrainDetectionSystemPackage.TryParseClass(FObserveTrackCircuitsClassName, out var parsedClass);
        var transformer = new ClassTransformer(parsedClass);

        var classFile = transformer.TransformClassIntoFile();

        var stateNames = classFile.Behavior.EnumerateSubrecords(TargetLanguage.C).Select(x => x.Name);
        Assert.Distinct(stateNames);
    }
}
