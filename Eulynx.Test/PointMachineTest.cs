using static Eulynx.FControlPointMachinePosition;

namespace Eulynx.Test;

class PointMachine {
    public PointMachine()
    {
        CommandAndReceive = new SSciPCommandAndRecieve();
        Prim = new SSciAdjPrim();

        // According to Eu.P.3286
        CommandAndReceive.D50inPdiConnectionState = Prim.D50outPdiConnectionState;
    }

    public SSciPCommandAndRecieve CommandAndReceive { get; }
    public SSciAdjPrim Prim { get; }
}

[TestClass]
public class PointMachineTest
{
    [TestMethod]
    public void InitialMemLastCommandedPointPositionShouldBeUndefined()
    {
        var point = new PointMachine();

        // Todo:
        // 2. Fix type of connection state (permitted values)
        // 3. Implement exchange of information via ports, and triggering updates
        // 4. Implement sending and receiving EULYNX messages, including handling conditions
        // 5. Implement timeout triggers
    }
}
