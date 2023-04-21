using System.Threading.Channels;
using static Eulynx.FControlPointMachinePosition;

namespace Eulynx.Test;

class PointMachine {
    public PointMachine()
    {
        var outgoingMessages = Channel.CreateUnbounded<object>();
        var incomingMessages = Channel.CreateUnbounded<object>();

        CommandAndReceive = new SSciPCommandAndRecieve();
        Prim = new SSciAdjPrim();

        // According to Eu.P.3286
        CommandAndReceive.D50inPdiConnectionState = Prim.D50outPdiConnectionState;
        // Prim.T25inSecStatusReportComplete
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

        // Got an incoming RaSTA connection.
        {
            point.Prim.T5inScpConnectionEstablished = true;
        }

        // Todo:
        // 3. Implement exchange of information via ports, and triggering updates
        // 4. Implement sending and receiving EULYNX messages, including handling conditions
        // 5. Implement timeout triggers
    }
}
