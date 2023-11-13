using XmiToCode.Codegen.C;
using XmiToCode.Parsing;

namespace XmiToCode.Test;

public class CWriterTest
{
    public const string SubsystemLevelCrossingPackageName = "Subsystem Level Crossing";
    public const string FObserveFailureStateClassName = "F_Observe_Failure_State";
    private readonly CWriter _writer;

    public CWriterTest()
    {
        _writer = new CWriter("./out");
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
}
