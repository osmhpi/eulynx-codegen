using System.Threading.Channels;
using Eulynx.Runtime;
using EulynxLive.Messages.Baseline4R1;

namespace Eulynx.Test;

class PointMachine {

    public Container<SSciAdjPrim, SSciAdjPrim.SSciAdjsPrimBehaviour> Prim { get; }
    public Container<SSciPCommandAndRecieve, SSciPCommandAndRecieve.SSciPCommandAndRecieveBehaviour> CommandAndReceive { get; }
    public Channel<Message> OutgoingMessages { get; }
    public Channel<Message> IncomingMessages { get; }

    public PointMachine()
    {
        OutgoingMessages = Channel.CreateUnbounded<Message>();
        IncomingMessages = Channel.CreateUnbounded<Message>();

        var otherChannel = Channel.CreateUnbounded<Message>();

        var messageConverter = new MessageFactory("", "", ProtocolType.Point);

        Prim = new Container<SSciAdjPrim, SSciAdjPrim.SSciAdjsPrimBehaviour>(new SSciAdjPrim(messageConverter));
        CommandAndReceive = new Container<SSciPCommandAndRecieve, SSciPCommandAndRecieve.SSciPCommandAndRecieveBehaviour>(new SSciPCommandAndRecieve(messageConverter));

        Prim.StateMachine.P1inout = OutgoingMessages;
        Prim.StateMachine.P2inout = otherChannel;
        CommandAndReceive.StateMachine.P10inout = OutgoingMessages;

        // Prim.P1inout = outgoingMessages;
        // CommandAndReceive.P10inout = outgoingMessages;

        // According to Eu.P.3286
        CommandAndReceive.StateMachine.D50inPdiConnectionState.Connect(Prim.StateMachine.D50outPdiConnectionState);
        // Prim.T25inSecStatusReportComplete
    }

    public async Task Process() {
        await Task.WhenAny(Prim.Process(), CommandAndReceive.Process());
    }

    public void PerformUpdate(Action<PointMachine> update) {
        update(this);

        // This will cause Transition to be called
        Prim.ReevaluateChangeEvents();
        CommandAndReceive.ReevaluateChangeEvents();
    }
}

[TestClass]
public class PointMachineTest
{
    [TestMethod]
    public async Task InitialMemLastCommandedPointPositionShouldBeUndefined()
    {
        var point = new PointMachine();

        var pointTask = Task.Run(() => point.Process());

        // var pointTask = point.Process();

        point.PerformUpdate((p) => {
            // Got an incoming RaSTA connection.
            p.Prim.StateMachine.T5inScpConnectionEstablished.Value = true;
        });

        var msg = await point.OutgoingMessages.Reader.ReadAsync();

        Assert.IsInstanceOfType(point.Prim.StateMachine.State, typeof(SSciAdjPrim.SSciAdjsPrimBehaviour.Active));

        // Todo:
        // 4. Implement sending and receiving EULYNX messages, including handling conditions
        // 5. Implement timeout triggers
    }
}
