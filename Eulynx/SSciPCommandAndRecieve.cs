using System.Threading.Channels;
using EulynxMessages = EulynxLive.Messages.Baseline4R1;

namespace Eulynx;

public class SSciPCommandAndRecieve : IStateMachine<SSciPCommandAndRecieve.SSciPCommandAndRecieveBehaviour>
{
    public record SSciPCommandAndRecieveBehaviour : object
    {
        public record Operating : SSciPCommandAndRecieveBehaviour
        {
            public record SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport() : Operating()
            {
                public static new SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport New(SSciPCommandAndRecieve This) => new SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport();
            }

            public static new Operating New(SSciPCommandAndRecieve This)
            {
                {


                    return Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(This);
                }
            }

            private Operating() { }
        }


        public static new SSciPCommandAndRecieveBehaviour New(SSciPCommandAndRecieve This)
        {
            {
                {


                    return SSciPCommandAndRecieveBehaviour.Operating.New(This);
                }
            }
        }

        private SSciPCommandAndRecieveBehaviour() { }
    }


    private SSciPCommandAndRecieveBehaviour _state;
    public SSciPCommandAndRecieveBehaviour State => _state;

    private readonly IMessageFactory _messageConverter;

    public SSciPCommandAndRecieve(IMessageFactory messageConverter)
    {
        _messageConverter = messageConverter;

        // Initialize ports
        D30inMovePoint = new Port<D30inMovePointValue>();
        T31outTimeout = new Port<PulsedOut>(new PulsedOut(false));
        D32outPointPosition = new Port<D32outPointPositionValue>();
        D50inPdiConnectionState = new Port<SSciEfesPrim.D50outPdiConnectionStateValue>();
        D33outAbilityToMove = new Port<D33outAbilityToMoveValue>();
        P11in = new Port<Channel<EulynxMessages.Message>>();
        T30inMovePoint = new Port<PulsedIn>(new PulsedIn(false));
        P10inout = new Port<Channel<EulynxMessages.Message>>();
        T32outPointPosition = new Port<PulsedOut>(new PulsedOut(false));
        T33outAbilityToMove = new Port<PulsedOut>(new PulsedOut(false));

        // Initialize change events
        Change1079 = new Event(() => T30inMovePoint.Value);
        Change1080 = new Event(() => T30inMovePoint.Value);
    }

    public void Init()
    {
        _state = SSciPCommandAndRecieveBehaviour.New(this);
    }

    public IEnumerable<AbstractPort> GetPorts()
    {
        return new AbstractPort[] {
            // TODO: Skip message ports
            D30inMovePoint, T31outTimeout, D32outPointPosition, D50inPdiConnectionState, D33outAbilityToMove, P11in, T30inMovePoint, P10inout, T32outPointPosition, T33outAbilityToMove
        };
    }

    public IEnumerable<Event> GetChangeEvents()
    {
        return new Event[] {
            Change1079, Change1080
        };
    }

    private bool IsTimeoutExpired(object timeout)
    {
        // TODO
        return false;
    }

    private void SendMessage(Message message, Port<Channel<EulynxMessages.Message>> port)
    {
        port.Value.Writer.TryWrite(_messageConverter.Convert<Message>(message));
    }


    public void Transition()
    {
        _state = _state switch
        {
            SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport => TransitionFromSSciPCommandAndRecieveBehaviour__Operating__SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport(),
            SSciPCommandAndRecieveBehaviour.Operating => TransitionFromSSciPCommandAndRecieveBehaviour__Operating()
        };
    }

    private SSciPCommandAndRecieveBehaviour TransitionFromSSciPCommandAndRecieveBehaviour__Operating__SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport()
    {
        if (Change1079.IsTriggered)
        {
            if (D30inMovePoint.Value.Equals(D30inMovePointValue.Right) && D50inPdiConnectionState.Value.Equals(SSciEfesPrim.D50outPdiConnectionStateValue.Established))
            {

                this.SendMessage(new Message.CdMovePoint(Message.CdMovePoint.Values.Right), this.P10inout);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (Change1080.IsTriggered)
        {
            if (D30inMovePoint.Value.Equals(D30inMovePointValue.Left) && D50inPdiConnectionState.Value.Equals(SSciEfesPrim.D50outPdiConnectionStateValue.Established))
            {

                this.SendMessage(new Message.CdMovePoint(Message.CdMovePoint.Values.Left), this.P10inout);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.Left) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.NotApplicable)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.LeftAndNotApplicable;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.Left) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.NotDegraded)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.LeftAndNotDegraded;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.Right) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.NotApplicable)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.RightAndNotApplicable;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.Right) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.NotDegraded)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.RightAndNotDegraded;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.NoEndPosition) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.DegradedLeft)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.NoEndPositionAndDegradedLeft;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.NoEndPosition) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.DegradedRight)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.NoEndPositionAndDegradedRight;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.NoEndPosition) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.NotDegraded)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.NoEndPositionAndNotDegraded;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.NoEndPosition) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.NotApplicable)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.NoEndPositionAndNotApplicable;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.Trailed) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.DegradedLeft)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.TrailedAndDegradedLeft;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.Trailed) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.DegradedRight)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.TrailedAndDegradedRight;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.Trailed) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.NotDegraded)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.TrailedAndNotDegraded;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgPointPosition))
        {
            if (ReceivedMessage(MsgPointPosition, x => x.ReportedPointPositionState.Equals(PointPositionState.Trailed) && x.ReportedDegradedPointPosition.Equals(PointPositionDegradedState.NotApplicable)))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = MsgPointPosition;
                MsgPointPosition = null;
                this.D32outPointPosition.Value = D32outPointPositionValue.TrailedAndNotApplicable;
                this.T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgAbilityToMovePoint))
        {
            if (ReceivedMessage(MsgAbilityToMovePoint, x => x.ReportedAbilityToMoveState.Equals(AbilityToMoveState.UnableToMove)))
            {
                var ReportedAbilityToMoveState = MsgAbilityToMovePoint.ReportedAbilityToMoveState;
                MsgAbilityToMovePoint = null;
                this.D33outAbilityToMove.Value = D33outAbilityToMoveValue.UnableToMove;
                this.T33outAbilityToMove.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgAbilityToMovePoint))
        {
            if (ReceivedMessage(MsgAbilityToMovePoint, x => x.ReportedAbilityToMoveState.Equals(AbilityToMoveState.AbleToMove)))
            {
                var ReportedAbilityToMoveState = MsgAbilityToMovePoint.ReportedAbilityToMoveState;
                MsgAbilityToMovePoint = null;
                this.D33outAbilityToMove.Value = D33outAbilityToMoveValue.AbleToMove;
                this.T33outAbilityToMove.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived(MsgTimeout))
        {
            {

                this.T31outTimeout.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciPCommandAndRecieveBehaviour TransitionFromSSciPCommandAndRecieveBehaviour__Operating()
    {


        // Do not transition
        return _state;
    }


    // Properties


    // Ports
    public Port<D30inMovePointValue> D30inMovePoint { get; set; }
    public Port<PulsedOut> T31outTimeout { get; set; }
    public Port<D32outPointPositionValue> D32outPointPosition { get; set; }
    public Port<SSciEfesPrim.D50outPdiConnectionStateValue> D50inPdiConnectionState { get; set; }
    public Port<D33outAbilityToMoveValue> D33outAbilityToMove { get; set; }
    public Port<Channel<EulynxMessages.Message>> P11in { get; set; }
    public Port<PulsedIn> T30inMovePoint { get; set; }
    public Port<Channel<EulynxMessages.Message>> P10inout { get; set; }
    public Port<PulsedOut> T32outPointPosition { get; set; }
    public Port<PulsedOut> T33outAbilityToMove { get; set; }

    // Operations


    // Value Types

    public enum D30inMovePointValue
    {
        Right,
        Left
    }

    public enum D32outPointPositionValue
    {
        LeftAndNotApplicable,
        LeftAndNotDegraded,
        RightAndNotApplicable,
        RightAndNotDegraded,
        NoEndPositionAndDegradedLeft,
        NoEndPositionAndDegradedRight,
        NoEndPositionAndNotDegraded,
        NoEndPositionAndNotApplicable,
        TrailedAndDegradedLeft,
        TrailedAndDegradedRight,
        TrailedAndNotDegraded,
        TrailedAndNotApplicable
    }

    public enum D50inPdiConnectionStateValue
    {
        Established
    }

    public enum D33outAbilityToMoveValue
    {
        UnableToMove,
        AbleToMove
    }

    // Messages
    public record Message
    {
        public record MsgPointPosition(PointPositionState ReportedPointPositionState, PointPositionDegradedState ReportedDegradedPointPosition) : Message
        {
            public void Deconstruct(out PointPositionState ReportedPointPositionState, out PointPositionDegradedState ReportedDegradedPointPosition)
            {
                ReportedPointPositionState = this.ReportedPointPositionState;
                ReportedDegradedPointPosition = this.ReportedDegradedPointPosition;
            }
        }
        public record MsgAbilityToMovePoint(AbilityToMoveState ReportedAbilityToMoveState) : Message
        {

        }
        public record MsgTimeout() : Message
        {

        }
        public record CdMovePoint(CdMovePoint.Values Value) : Message
        {
            public enum Values
            {
                Right,
                Left
            }
        }
    }

    // Signals
    public Message.MsgPointPosition MsgPointPosition { get; set; }
    public Message.MsgAbilityToMovePoint MsgAbilityToMovePoint { get; set; }
    public Message.MsgTimeout MsgTimeout { get; set; }
    public bool ReceiveMessage(Message message)
    {
        switch (message)
        {
            case Message.MsgPointPosition specific:
                {
                    MsgPointPosition = specific;
                    return true;
                }
            case Message.MsgAbilityToMovePoint specific:
                {
                    MsgAbilityToMovePoint = specific;
                    return true;
                }
            case Message.MsgTimeout specific:
                {
                    MsgTimeout = specific;
                    return true;
                }
            default: return false;
        };
    }
    private bool IsMessageArrived(Message message)
    {
        return message != null;
    }
    private bool ReceivedMessage<T>(T message, Func<T, bool> expr)
    {
        return message != null && expr(message);
    }

    // Events
    public Event Change1079 { get; }
    public Event Change1080 { get; }
}
