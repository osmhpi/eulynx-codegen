using System.Threading.Channels;
using EulynxLive.Messages.Baseline4R1;

namespace Eulynx.Test;

class PointMachine {
    public PointMachine()
    {
        var outgoingMessages = Channel.CreateUnbounded<object>();
        var incomingMessages = Channel.CreateUnbounded<object>();

        var messageConverter = new MessageConverter("", "", ProtocolType.Point);

        CommandAndReceive = new SSciPCommandAndRecieve(messageConverter);
        Prim = new SSciAdjPrim(messageConverter);

        // According to Eu.P.3286
        CommandAndReceive.D50inPdiConnectionState = Prim.D50outPdiConnectionState;
        // Prim.T25inSecStatusReportComplete

        // Wiring is done, init
        CommandAndReceive.Init();
        Prim.Init();
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
