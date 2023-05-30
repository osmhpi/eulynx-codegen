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

                return Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(This);
            }

            private Operating() { }
        }


        public static new SSciPCommandAndRecieveBehaviour New(SSciPCommandAndRecieve This)
        {

            return SSciPCommandAndRecieveBehaviour.Operating.New(This);
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
        T31outTimeout = new Port<PulsedOut>();
        D32outPointPosition = new Port<D32outPointPositionValue>();
        D50inPdiConnectionState = new Port<D50inPdiConnectionStateValue>();
        D33outAbilityToMove = new Port<D33outAbilityToMoveValue>();
        P11in = new Port<object>();
        T30inMovePoint = new Port<PulsedIn>();
        P10inout = new Port<object>();
        T32outPointPosition = new Port<PulsedOut>();
        T33outAbilityToMove = new Port<PulsedOut>();

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

    private void SendMessage(Message message, /*Channel<EulynxMessages.Message>*/ Port<object> port)
    {
        // port.Writer.TryWrite(_messageConverter.Convert<Message>(message));
    }

    private bool IsMessageArrived(string message)
    {
        // TODO: Implement
        return false;
    }

    private bool ReceivedMessage(string message)
    {
        // TODO: Implement
        return false;
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
            if (D30inMovePoint.Value == D30inMovePointValue.Right && D50inPdiConnectionState.Value == D50inPdiConnectionStateValue.Established)
            {

                SendMessage(new Message.CdMovePoint(Message.CdMovePoint.Values.Right), P10inout);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (Change1080.IsTriggered)
        {
            if (D30inMovePoint.Value == D30inMovePointValue.Left && D50inPdiConnectionState.Value == D50inPdiConnectionStateValue.Established)
            {

                SendMessage(new Message.CdMovePoint(Message.CdMovePoint.Values.Left), P10inout);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Left  && ReportedDegradedPointPosition == NotApplicable]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.LeftAndNotApplicable;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Left  && ReportedDegradedPointPosition == NotDegraded]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.LeftAndNotDegraded;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Right  && ReportedDegradedPointPosition == NotApplicable]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.RightAndNotApplicable;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Right  && ReportedDegradedPointPosition == NotDegraded]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.RightAndNotDegraded;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == NoEndPosition  && ReportedDegradedPointPosition == DegradedLeft]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.NoEndPositionAndDegradedLeft;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == NoEndPosition  && ReportedDegradedPointPosition == DegradedRight]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.NoEndPositionAndDegradedRight;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == NoEndPosition  && ReportedDegradedPointPosition == NotDegraded]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.NoEndPositionAndNotDegraded;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == NoEndPosition  && ReportedDegradedPointPosition == NotApplicable]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.NoEndPositionAndNotApplicable;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Trailed  && ReportedDegradedPointPosition == DegradedLeft]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.TrailedAndDegradedLeft;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Trailed  && ReportedDegradedPointPosition == DegradedRight]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.TrailedAndDegradedRight;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Trailed  && ReportedDegradedPointPosition == NotDegraded]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.TrailedAndNotDegraded;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Trailed  && ReportedDegradedPointPosition == NotApplicable]"))
            {
                var (ReportedPointPositionState, ReportedDegradedPointPosition) = message;
                D32outPointPosition.Value = D32outPointPositionValue.TrailedAndNotApplicable;
                T32outPointPosition.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Ability_To_Move_Point"))
        {
            if (ReceivedMessage("Msg_Ability_To_Move_Point[ReportedAbilityToMoveState == UnableToMove]"))
            {
                var (ReportedAbilityToMoveState) = message;
                D33outAbilityToMove.Value = D33outAbilityToMoveValue.UnableToMove;
                T33outAbilityToMove.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Ability_To_Move_Point"))
        {
            if (ReceivedMessage("Msg_Ability_To_Move_Point[ReportedAbilityToMoveState == AbleToMove]"))
            {
                var (ReportedAbilityToMoveState) = message;
                D33outAbilityToMove.Value = D33outAbilityToMoveValue.AbleToMove;
                T33outAbilityToMove.Value = new PulsedOut(true);

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New(this);
            }
        }
        if (IsMessageArrived("Msg_Timeout"))
        {
            {

                T31outTimeout.Value = new PulsedOut(true);

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
    public Port<D50inPdiConnectionStateValue> D50inPdiConnectionState { get; set; }
    public Port<D33outAbilityToMoveValue> D33outAbilityToMove { get; set; }
    public Port<object> P11in { get; set; }
    public Port<PulsedIn> T30inMovePoint { get; set; }
    public Port<object> P10inout { get; set; }
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
        public record CdMovePoint(CdMovePoint.Values Value) : Message
        {
            public enum Values
            {
                Right,
                Left
            }
        }
    }

    // Events
    public Event Change1079 { get; }
    public Event Change1080 { get; }
}
