using XmiToCode.Codegen.C;
using XmiToCode.Parsing;

namespace XmiToCode.Test;

public class CWriterTest
{
    public const string SubsystemLevelCrossingPackageName = "Subsystem Level Crossing";
    public const string FObserveFailureStateClassName = "F_Observe_Failure_State";
    public const string FControlTimerClassName = "F_Control_Timer";
    private readonly CWriter _writer;

    public CWriterTest()
    {
        _writer = new CWriter("./out");
    }

    [Fact]
    public async Task WritesCommonFiles() {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        await _writer.WriteCommonFilesAsync(parser.GlobalContext, parser.InterestingPackages);
    }

    [Fact]
    public async Task WritesClassesInPackage() {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        var packages = parser.ParsePackages();
        var genericSciPackage = packages.Single(x => x.Name.RawName == PackageTest.GenericSciPackageName);
        await _writer.WritePackageFilesAsync(genericSciPackage);
    }

    [Fact]
    public async Task DoesNotThrowStackOverflowException() {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE, classWhitelist: new [] { FObserveFailureStateClassName });
        var packages = parser.ParsePackages();
        var levelCrossingPackage = packages.Single(x => x.Name.RawName == SubsystemLevelCrossingPackageName);
        await _writer.WritePackageFilesAsync(levelCrossingPackage);
    }

    [Fact]
    public async Task GeneratesBooleanExpressionComparators() {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE, classWhitelist: new [] { FControlTimerClassName });
        var packages = parser.ParsePackages();
        var levelCrossingPackage = packages.Single(x => x.Name.RawName == BehaviorRecordTest.SubsystemTrainDetectionSystemPackageName);
        await _writer.WritePackageFilesAsync(levelCrossingPackage);
    }
}
