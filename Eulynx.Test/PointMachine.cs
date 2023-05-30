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

        Prim.StateMachine.Init();
        CommandAndReceive.StateMachine.Init();
    }

    public void SetScpConnectionEstablished(bool established) {
        Prim.StateMachine.T5inScpConnectionEstablished.Value = established;
        PerformUpdate();
    }

    public void PerformUpdate() {
        Prim.ReevaluateChangeEvents();
        CommandAndReceive.ReevaluateChangeEvents();

        Prim.StateMachine.Transition();
        CommandAndReceive.StateMachine.Transition();
    }
}
