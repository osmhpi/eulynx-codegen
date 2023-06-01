using System.Threading.Channels;
using EulynxMessages = EulynxLive.Messages.Baseline4R1;

namespace Eulynx;

public class SSciAdjPrim : IStateMachine<SSciAdjPrim.SSciAdjsPrimBehaviour>
{
    public record SSciAdjsPrimBehaviour : object
    {
        public record RequestedNoScp() : SSciAdjsPrimBehaviour()
        {
            public static new RequestedNoScp New(SSciAdjPrim This) => new RequestedNoScp();
        }
        public record ImpermissibleNoScp() : SSciAdjsPrimBehaviour()
        {
            public static new ImpermissibleNoScp New(SSciAdjPrim This) => new ImpermissibleNoScp();
        }
        public record Impermissible() : SSciAdjsPrimBehaviour()
        {
            public static new Impermissible New(SSciAdjPrim This) => new Impermissible();
        }
        public record Active : SSciAdjsPrimBehaviour
        {
            public record Establishing : Active
            {
                public record WaitingForVersionCheck() : Establishing()
                {
                    public static new WaitingForVersionCheck New(SSciAdjPrim This) => new WaitingForVersionCheck();
                }
                public record WaitingForInitialisation() : Establishing()
                {
                    public static new WaitingForInitialisation New(SSciAdjPrim This) => new WaitingForInitialisation();
                }
                public record ReceivingSecStatus() : Establishing()
                {
                    public static new ReceivingSecStatus New(SSciAdjPrim This) => new ReceivingSecStatus();
                }
                public record CheckingSecStatus() : Establishing()
                {
                    public static new CheckingSecStatus New(SSciAdjPrim This) => new CheckingSecStatus();
                }
                public record SendingPrimStatus() : Establishing()
                {
                    public static new SendingPrimStatus New(SSciAdjPrim This) => new SendingPrimStatus();
                }
                public record WaitingForInitCompletion() : Establishing()
                {
                    public static new WaitingForInitCompletion New(SSciAdjPrim This) => new WaitingForInitCompletion();
                }

                public static new Establishing New(SSciAdjPrim This)
                {
                    This.SendMessage(new Message.EstablishingPdiConnection(), This.P2inout);
                    This.SendMessage(new Message.CdPdiVersionCheck(This.D3inConPdiVersion.Value), This.P1inout);

                    This.D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.WaitingForVersionCheck;

                    return Establishing.WaitingForVersionCheck.New(This);
                }

                private Establishing() { }
            }

            public record Established() : Active()
            {
                public static new Established New(SSciAdjPrim This) => new Established();
            }

            public static new Active New(SSciAdjPrim This)
            {

                return Active.Establishing.New(This);
            }

            private Active() { }
        }


        public static new SSciAdjsPrimBehaviour New(SSciAdjPrim This)
        {
            This.Cop1Init();

            This.D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
            This.T6outEstablishScpConnection.Value = new PulsedOut(true);

            return SSciAdjsPrimBehaviour.RequestedNoScp.New(This);
        }

        private SSciAdjsPrimBehaviour() { }
    }


    private SSciAdjsPrimBehaviour _state;
    public SSciAdjsPrimBehaviour State => _state;

    private readonly IMessageFactory _messageConverter;

    public SSciAdjPrim(IMessageFactory messageConverter)
    {
        _messageConverter = messageConverter;

        // Initialize ports
        T5inScpConnectionEstablished = new Port<PulsedIn>(new PulsedIn(false));
        T10inScpConnectionTerminated = new Port<PulsedIn>(new PulsedIn(false));
        D4inConChecksumData = new Port<byte[]>();
        D50outPdiConnectionState = new Port<D50outPdiConnectionStateValue>();
        T6outEstablishScpConnection = new Port<PulsedOut>(new PulsedOut(false));
        T22inContentTelegramError = new Port<PulsedIn>(new PulsedIn(false));
        T20inProtocolError = new Port<PulsedIn>(new PulsedIn(false));
        T21inFormalTelegramError = new Port<PulsedIn>(new PulsedIn(false));
        D2inConTmaxPdiConnection = new Port<object>();
        D3inConPdiVersion = new Port<byte[]>();
        T45inResetSevereError = new Port<PulsedIn>(new PulsedIn(false));
        D60outPdiCloseReason = new Port<D60outPdiCloseReasonValue>();
        T27outCheckSecStatus = new Port<PulsedOut>(new PulsedOut(false));
        P1inout = new Port<Channel<EulynxMessages.Message>>();
        P2inout = new Port<Channel<EulynxMessages.Message>>();
        T25inSecStatusReportComplete = new Port<PulsedIn>(new PulsedIn(false));

        // Initialize change events
        Change746 = new Event(() => T10inScpConnectionTerminated.Value);
        Change979 = new Event(() => T20inProtocolError.Value);
        Change985 = new Event(() => T21inFormalTelegramError.Value);
        Change997 = new Event(() => T22inContentTelegramError.Value);
        Change1020 = new Event(() => T25inSecStatusReportComplete.Value);
        Change1228 = new Event(() => T5inScpConnectionEstablished.Value);
        Change1169 = new Event(() => T45inResetSevereError.Value);
        Change1226 = new Event(() => T5inScpConnectionEstablished.Value);
        Change748 = new Event(() => T10inScpConnectionTerminated.Value);
        Change1170 = new Event(() => T45inResetSevereError.Value);
    }

    public void Init()
    {
        _state = SSciAdjsPrimBehaviour.New(this);
    }

    public IEnumerable<AbstractPort> GetPorts()
    {
        return new AbstractPort[] {
            // TODO: Skip message ports
            T5inScpConnectionEstablished, T10inScpConnectionTerminated, D4inConChecksumData, D50outPdiConnectionState, T6outEstablishScpConnection, T22inContentTelegramError, T20inProtocolError, T21inFormalTelegramError, D2inConTmaxPdiConnection, D3inConPdiVersion, T45inResetSevereError, D60outPdiCloseReason, T27outCheckSecStatus, P1inout, P2inout, T25inSecStatusReportComplete
        };
    }

    public IEnumerable<Event> GetChangeEvents()
    {
        return new Event[] {
            Change746, Change979, Change985, Change997, Change1020, Change1228, Change1169, Change1226, Change748, Change1170
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

    private bool IsMessageArrived<T>()
    {
        return false;
    }

    private bool ReceivedMessage<T>(Func<T, bool> expr)
    {
        // TODO: Implement
        return false;
    }


    public void Transition()
    {
        _state = _state switch
        {
            SSciAdjsPrimBehaviour.Active.Establishing.WaitingForVersionCheck => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForVersionCheck(),
            SSciAdjsPrimBehaviour.Active.Establishing.WaitingForInitialisation => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForInitialisation(),
            SSciAdjsPrimBehaviour.Active.Establishing.ReceivingSecStatus => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__ReceivingSecStatus(),
            SSciAdjsPrimBehaviour.Active.Establishing.CheckingSecStatus => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__CheckingSecStatus(),
            SSciAdjsPrimBehaviour.Active.Establishing.SendingPrimStatus => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__SendingPrimStatus(),
            SSciAdjsPrimBehaviour.Active.Establishing.WaitingForInitCompletion => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForInitCompletion(),
            SSciAdjsPrimBehaviour.Active.Establishing => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing(),
            SSciAdjsPrimBehaviour.Active.Established => TransitionFromSSciAdjsPrimBehaviour__Active__Established(),
            SSciAdjsPrimBehaviour.RequestedNoScp => TransitionFromSSciAdjsPrimBehaviour__RequestedNoScp(),
            SSciAdjsPrimBehaviour.ImpermissibleNoScp => TransitionFromSSciAdjsPrimBehaviour__ImpermissibleNoScp(),
            SSciAdjsPrimBehaviour.Impermissible => TransitionFromSSciAdjsPrimBehaviour__Impermissible(),
            SSciAdjsPrimBehaviour.Active => TransitionFromSSciAdjsPrimBehaviour__Active()
        };
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForVersionCheck()
    {
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ProtocolError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ContentTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.FormalTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change746.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change979.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change985.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change997.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {

                SendMessage(new Message.PdiConnectionClosed(), P2inout);
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.Timeout), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgPdiVersionCheck>())
        {
            if (ReceivedMessage<Message.MsgPdiVersionCheck>(x => x.Result == ResultValue.Match && x.ChecksumData == D4inConChecksumData.Value))
            {
                var (Result, ChecksumData, PDIVersion) = MsgPdiVersionCheck;
                SendMessage(new Message.CdInitialisationRequest(), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.WaitingForInitialisation;

                return SSciAdjsPrimBehaviour.Active.Establishing.WaitingForInitialisation.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgPdiVersionCheck>())
        {
            if (ReceivedMessage<Message.MsgPdiVersionCheck>(x => x.Result == ResultValue.Match && !(x.ChecksumData == D4inConChecksumData.Value)))
            {
                var (Result, ChecksumData, PDIVersion) = MsgPdiVersionCheck;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiChecksumMismatch;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ChecksumMismatch), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgPdiVersionCheck>())
        {
            if (ReceivedMessage<Message.MsgPdiVersionCheck>(x => x.Result == ResultValue.NotMatch))
            {
                var (Result, ChecksumData, PDIVersion) = MsgPdiVersionCheck;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiOtherVersionRequired;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.OtherVersionRequired), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForInitialisation()
    {
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ProtocolError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ContentTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.FormalTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change746.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change979.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change985.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change997.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {

                SendMessage(new Message.PdiConnectionClosed(), P2inout);
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.Timeout), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgStartInitialisation>())
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.ReceivingSecStatus;

                return SSciAdjsPrimBehaviour.Active.Establishing.ReceivingSecStatus.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__ReceivingSecStatus()
    {
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ProtocolError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ContentTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.FormalTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change746.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change979.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change985.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change997.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {

                SendMessage(new Message.PdiConnectionClosed(), P2inout);
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.Timeout), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgStatusReportCompleted>())
        {
            {

                T27outCheckSecStatus.Value = new PulsedOut(true);
                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.CheckingSecStatus;

                return SSciAdjsPrimBehaviour.Active.Establishing.CheckingSecStatus.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__CheckingSecStatus()
    {
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ProtocolError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ContentTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.FormalTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change746.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change979.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change985.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change997.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {

                SendMessage(new Message.PdiConnectionClosed(), P2inout);
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.Timeout), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (Change1020.IsTriggered)
        {
            {

                SendMessage(new Message.StartPrimStatusReport(), P2inout);
                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.SendingPrimStatus;

                return SSciAdjsPrimBehaviour.Active.Establishing.SendingPrimStatus.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__SendingPrimStatus()
    {
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ProtocolError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ContentTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.FormalTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change746.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change979.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change985.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change997.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {

                SendMessage(new Message.PdiConnectionClosed(), P2inout);
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.Timeout), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (IsMessageArrived<Message.PrimStatusReportCompleted>())
        {
            {

                SendMessage(new Message.MsgStatusReportCompleted(), P1inout);
                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.WaitingForInitCompletion;

                return SSciAdjsPrimBehaviour.Active.Establishing.WaitingForInitCompletion.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForInitCompletion()
    {
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ProtocolError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ContentTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.FormalTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change746.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change979.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change985.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change997.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgInitialisationCompleted>())
        {
            {

                SendMessage(new Message.PdiConnectionClosed(), P2inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Established;
                SendMessage(new Message.PdiConnectionEstablished(), P2inout);

                return SSciAdjsPrimBehaviour.Active.Established.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing()
    {
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ProtocolError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ContentTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.FormalTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change746.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change979.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change985.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change997.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {

                SendMessage(new Message.PdiConnectionClosed(), P2inout);
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.Timeout), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Established()
    {


        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__RequestedNoScp()
    {
        if (Change1228.IsTriggered)
        {
            {


                return SSciAdjsPrimBehaviour.Active.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__ImpermissibleNoScp()
    {
        if (Change1169.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change1226.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Impermissible()
    {
        if (Change748.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.ImpermissibleNoScp;

                return SSciAdjsPrimBehaviour.ImpermissibleNoScp.New(this);
            }
        }
        if (Change1170.IsTriggered)
        {
            {


                return SSciAdjsPrimBehaviour.Active.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active()
    {
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ProtocolError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.ContentTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived<Message.MsgResetPdi>())
        {
            if (ReceivedMessage<Message.MsgResetPdi>(x => x.ReportedResetReason == ResetReason.FormalTelegramError))
            {
                var ReportedResetReason = MsgResetPdi.ReportedResetReason;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change746.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change979.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change985.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change997.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }

        // Do not transition
        return _state;
    }


    // Properties
    public MemPdiVersionCheckResultValue MemPdiVersionCheckResult { get; set; }
    public byte[] MemPdiVersionChecksumdata { get; set; }

    // Ports
    public Port<PulsedIn> T5inScpConnectionEstablished { get; set; }
    public Port<PulsedIn> T10inScpConnectionTerminated { get; set; }
    public Port<byte[]> D4inConChecksumData { get; set; }
    public Port<D50outPdiConnectionStateValue> D50outPdiConnectionState { get; set; }
    public Port<PulsedOut> T6outEstablishScpConnection { get; set; }
    public Port<PulsedIn> T22inContentTelegramError { get; set; }
    public Port<PulsedIn> T20inProtocolError { get; set; }
    public Port<PulsedIn> T21inFormalTelegramError { get; set; }
    public Port<object> D2inConTmaxPdiConnection { get; set; }
    public Port<byte[]> D3inConPdiVersion { get; set; }
    public Port<PulsedIn> T45inResetSevereError { get; set; }
    public Port<D60outPdiCloseReasonValue> D60outPdiCloseReason { get; set; }
    public Port<PulsedOut> T27outCheckSecStatus { get; set; }
    public Port<Channel<EulynxMessages.Message>> P1inout { get; set; }
    public Port<Channel<EulynxMessages.Message>> P2inout { get; set; }
    public Port<PulsedIn> T25inSecStatusReportComplete { get; set; }

    // Operations
    public void Cop1Init()
    {
        MemPdiVersionCheckResult = MemPdiVersionCheckResultValue.Unknown;
        MemPdiVersionChecksumdata = D4inConChecksumData.Value;

    }

    // Value Types

    public enum MemPdiVersionCheckResultValue
    {
        Unknown
    }

    public enum D50outPdiConnectionStateValue
    {
        Impermissible,
        RequestedNoScp,
        WaitingForInitialisation,
        ReceivingSecStatus,
        CheckingSecStatus,
        SendingPrimStatus,
        WaitingForInitCompletion,
        Established,
        ImpermissibleNoScp,
        WaitingForVersionCheck
    }

    public enum D60outPdiCloseReasonValue
    {
        SecProtocolError,
        SecContentTelegramError,
        SecFormalTelegramError,
        PrimProtocolError,
        PrimFormalTelegramError,
        PrimContentTelegramError,
        PdiTimeout,
        PdiChecksumMismatch,
        PdiOtherVersionRequired
    }

    public enum ResultValue
    {
        Match,
        NotMatch
    }

    // Messages
    public record Message
    {
        public record MsgResetPdi(ResetReason ReportedResetReason) : Message
        {

        }
        public record MsgPdiVersionCheck(ResultValue Result, byte[] ChecksumData, byte[] PDIVersion) : Message
        {
            public void Deconstruct(out ResultValue Result, out byte[] ChecksumData, out byte[] PDIVersion)
            {
                Result = this.Result;
                ChecksumData = this.ChecksumData;
                PDIVersion = this.PDIVersion;
            }
        }
        public record MsgStartInitialisation() : Message
        {

        }
        public record MsgStatusReportCompleted() : Message
        {

        }
        public record PrimStatusReportCompleted() : Message
        {

        }
        public record MsgInitialisationCompleted() : Message
        {

        }
        public record CdClosePdi(CdClosePdi.Values Value) : Message
        {
            public enum Values
            {
                ProtocolError,
                FormalTelegramError,
                ContentTelegramError,
                Timeout,
                ChecksumMismatch,
                OtherVersionRequired
            }
        }
        public record CdInitialisationRequest() : Message
        {

        }
        public record CdPdiVersionCheck(byte[] Value) : Message
        {

        }
        public record PdiConnectionClosed() : Message
        {

        }
        public record StartPrimStatusReport() : Message
        {

        }
        public record PdiConnectionEstablished() : Message
        {

        }
        public record EstablishingPdiConnection() : Message
        {

        }
    }

    // Signals
    public Message.MsgResetPdi MsgResetPdi { get; set; }
    public Message.MsgPdiVersionCheck MsgPdiVersionCheck { get; set; }
    public Message.MsgStartInitialisation MsgStartInitialisation { get; set; }
    public Message.MsgStatusReportCompleted MsgStatusReportCompleted { get; set; }
    public Message.PrimStatusReportCompleted PrimStatusReportCompleted { get; set; }
    public Message.MsgInitialisationCompleted MsgInitialisationCompleted { get; set; }

    // Events
    public Event Change746 { get; }
    public Event Change979 { get; }
    public Event Change985 { get; }
    public Event Change997 { get; }
    public Event Change1020 { get; }
    public Event Change1228 { get; }
    public Event Change1169 { get; }
    public Event Change1226 { get; }
    public Event Change748 { get; }
    public Event Change1170 { get; }
}
