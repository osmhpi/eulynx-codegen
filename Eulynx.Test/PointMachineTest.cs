using static Eulynx.FControlPointMachinePosition;

namespace Eulynx.Test;

[TestClass]
public class PointMachienTest
{
    [TestMethod]
    public void InitialMemLastCommandedPointPositionShouldBeUndefined()
    {
        var commandAndReceive = new SSciPCommandAndRecieve();
        var prim = new SSciAdjPrim();

        // According to Eu.P.3286
        // commandAndReceive.D50inPdiConnectionState = prim.D50outPdiConnectionState;
    }
}
