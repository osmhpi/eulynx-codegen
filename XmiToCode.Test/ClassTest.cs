using XmiToCode.Classes;
using XmiToCode.Parsing;

namespace XmiToCode.Test;

public class ClassTest
{
    public const string FSciEfesSecClassName = "F_SCI_EfeS_Sec";
    private readonly Class _parsedClass;

    public ClassTest()
    {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        var packages = parser.ParsePackages();
        var genericSciPackage = packages.Single(x => x.Name.RawName == PackageTest.GenericSciPackageName);
        _ = genericSciPackage.TryParseClass(FSciEfesSecClassName, out _parsedClass);
    }

    [Fact]
    public void AssignsClassNameInPascalCase() {
        Assert.Equal("FSciEfesSec", _parsedClass.Info.ClassName);
    }

    [Fact]
    public void AssignsBehaviorNameInPascalCase() {
        Assert.Equal("FSciEfesSecBehaviour", _parsedClass.Info.BehaviorName);
    }

    [Fact]
    public void AssignsIncomingMessagesToContext() {
        Assert.NotEmpty(_parsedClass.ClassContext.IncomingMessages);
    }

    [Fact]
    public void AssignsOutgoingMessagesToContext() {
        Assert.NotEmpty(_parsedClass.ClassContext.OutgoingMessages);
    }

    [Fact]
    public void AssignsPortsToContext() {
        Assert.NotEmpty(_parsedClass.ClassContext.Ports);
    }

    [Fact]
    public void AssignsPropertiesToContext() {
        Assert.NotEmpty(_parsedClass.ClassContext.Properties);
    }

    [Fact]
    public void AssignsOperations() {
        Assert.NotEmpty(_parsedClass.Operations);
    }

    [Fact]
    public void ParsesInitOperation() {
        Assert.NotEmpty(_parsedClass.Operations);
        var operationNames = _parsedClass.Operations.Select(x => x.Identifier.Name);
        Assert.Contains("Cop1Init", operationNames);
    }
}
