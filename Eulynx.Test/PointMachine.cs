using System.Threading.Channels;
using Eulynx.Runtime;
using EulynxLive.Messages.Baseline4R1;

namespace Eulynx.Test;

class PointMachine {
    private readonly MessageFactory _messageConverter;

    public Container<SSciEfesPrim, SSciEfesPrim.SSciEfesPrimBehaviour> Prim { get; }
    public Container<SSciPCommandAndRecieve, SSciPCommandAndRecieve.SSciPCommandAndRecieveBehaviour> CommandAndReceive { get; }
    public Channel<Message> OutgoingMessages { get; }

    public PointMachine()
    {
        OutgoingMessages = Channel.CreateUnbounded<Message>();

        var otherChannel = Channel.CreateUnbounded<Message>();

        _messageConverter = new MessageFactory("", "", ProtocolType.Point);

        Prim = new Container<SSciEfesPrim, SSciEfesPrim.SSciEfesPrimBehaviour>(new SSciEfesPrim(_messageConverter));
        CommandAndReceive = new Container<SSciPCommandAndRecieve, SSciPCommandAndRecieve.SSciPCommandAndRecieveBehaviour>(new SSciPCommandAndRecieve(_messageConverter));

        Prim.StateMachine.P1inout = new Port<Channel<Message>>(OutgoingMessages);
        CommandAndReceive.StateMachine.P10inout = new Port<Channel<Message>>(OutgoingMessages);
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

    public void PerformUpdate() {
        Prim.ReevaluateChangeEvents();
        CommandAndReceive.ReevaluateChangeEvents();

        Prim.StateMachine.Transition();
        CommandAndReceive.StateMachine.Transition();
    }

    internal void SetScpConnectionEstablished(bool established) {
        Prim.StateMachine.T5inScpConnectionEstablished.Value = new PulsedIn(established);
        PerformUpdate();
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

    internal void SetChecksumData(byte[] bytes)
    {
        Prim.StateMachine.D4inConChecksumData.Value = bytes;
        PerformUpdate();
    }

    internal void SetMovePoint(SSciPCommandAndRecieve.D30inMovePointValue v)
    {
        CommandAndReceive.StateMachine.D30inMovePoint.Value = v;
        CommandAndReceive.StateMachine.T30inMovePoint.Value.Set();
        PerformUpdate();
        CommandAndReceive.StateMachine.T30inMovePoint.Value.Unset();
    }

    internal SSciPCommandAndRecieve.D32outPointPositionValue GetPointPosition() {
        return CommandAndReceive.StateMachine.D32outPointPosition.Value;
    }

    internal void ReceiveMessage(Message message) {
        if (_messageConverter.ConvertToEfesPrimMessage(message, out var efesPrimMessage)) {
            if (Prim.StateMachine.ReceiveMessage(efesPrimMessage)) {
                PerformUpdate();
            }
        } else if (_messageConverter.ConvertToSciPCommandAndReceiveMessage(message, out var commandAndReceiveMessage)) {
            if (CommandAndReceive.StateMachine.ReceiveMessage(commandAndReceiveMessage)) {
                PerformUpdate();
            }
        } else {
            throw new ArgumentException("Unexpected message");
        }
    }
}
