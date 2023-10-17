using XmiToCode;
using XmiToCode.Classes;

namespace Eulynx.Validation;

[TestClass]
public class UnitTest1
{
    public static IEnumerable<object[]> AdditionData
    {
        get
        {
            var xmiPath = Environment.GetEnvironmentVariable("XMI_PATH") ?? throw new Exception("XMI_PATH not set");

            var processor = new XmiProcessor(xmiPath);
            foreach (var package in processor.ParsedPackages)
                yield return new object[] { package };
        }
    }

    [TestMethod]
    [DynamicData(nameof(AdditionData))]
    public void TestMethod1(Package package)
    {
        Assert.AreEqual("Subsystem Point", package.Name.RawName);
    }
}
