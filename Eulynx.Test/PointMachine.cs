using System.Threading.Channels;
using Eulynx.Runtime;
using EulynxLive.Messages.Baseline4R1;

namespace Eulynx.Test;

class PointMachine {

    public Container<SSciEfesPrim, SSciEfesPrim.SSciEfesPrimBehaviour> Prim { get; }
    public Container<SSciPCommandAndRecieve, SSciPCommandAndRecieve.SSciPCommandAndRecieveBehaviour> CommandAndReceive { get; }
    public Channel<Message> OutgoingMessages { get; }
    public Channel<Message> IncomingMessages { get; }

    public PointMachine()
    {
        OutgoingMessages = Channel.CreateUnbounded<Message>();
        IncomingMessages = Channel.CreateUnbounded<Message>();

        var otherChannel = Channel.CreateUnbounded<Message>();

        var messageConverter = new MessageFactory("", "", ProtocolType.Point);

        Prim = new Container<SSciEfesPrim, SSciEfesPrim.SSciEfesPrimBehaviour>(new SSciEfesPrim(messageConverter));
        CommandAndReceive = new Container<SSciPCommandAndRecieve, SSciPCommandAndRecieve.SSciPCommandAndRecieveBehaviour>(new SSciPCommandAndRecieve(messageConverter));

        Prim.StateMachine.P1inout = new Port<Channel<Message>>(OutgoingMessages);
        // Prim.StateMachine.P2inout = otherChannel;
        // CommandAndReceive.StateMachine.P10inout = OutgoingMessages;

        // Prim.P1inout = outgoingMessages;
        // CommandAndReceive.P10inout = outgoingMessages;

        // According to Eu.P.3286
        CommandAndReceive.StateMachine.D50inPdiConnectionState.Connect(Prim.StateMachine.D50outPdiConnectionState);
        // Prim.T25inSecStatusReportComplete

        Prim.StateMachine.Init();
        CommandAndReceive.StateMachine.Init();
    }

    public void SetScpConnectionEstablished(bool established) {
        Prim.StateMachine.T5inScpConnectionEstablished.Value = new PulsedIn(established);
        PerformUpdate();
    }

    public void PerformUpdate() {
        Prim.ReevaluateChangeEvents();
        CommandAndReceive.ReevaluateChangeEvents();

        Prim.StateMachine.Transition();
        CommandAndReceive.StateMachine.Transition();
    }

    internal void SetEnableOrConnectPdiEfes(bool enable)
    {
        Prim.StateMachine.T49inEnableOrConnectPdiEfes.Value = new PulsedIn(enable);
        PerformUpdate();
    }

    internal void SetConPdiVersion(byte[] bytes)
    {
        Prim.StateMachine.D3inConPdiVersion.Value = bytes;
        PerformUpdate();
    }
}
