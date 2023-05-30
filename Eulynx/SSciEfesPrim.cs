using System.Threading.Channels;
using EulynxMessages = EulynxLive.Messages.Baseline4R1;

namespace Eulynx;

public class SSciEfesPrim : IStateMachine<SSciEfesPrim.SSciEfesPrimBehaviour>
{
    public record SSciEfesPrimBehaviour : object
    {
        public record RequestedNoScp() : SSciEfesPrimBehaviour()
        {
            public static new RequestedNoScp New(SSciEfesPrim This) => new RequestedNoScp();
        }
        public record ImpermissibleNoScp() : SSciEfesPrimBehaviour()
        {
            public static new ImpermissibleNoScp New(SSciEfesPrim This) => new ImpermissibleNoScp();
        }
        public record Impermissible() : SSciEfesPrimBehaviour()
        {
            public static new Impermissible New(SSciEfesPrim This) => new Impermissible();
        }
        public record Disconnected() : SSciEfesPrimBehaviour()
        {
            public static new Disconnected New(SSciEfesPrim This) => new Disconnected();
        }
        public record DisconnectedNoScp() : SSciEfesPrimBehaviour()
        {
            public static new DisconnectedNoScp New(SSciEfesPrim This) => new DisconnectedNoScp();
        }
        public record Active : SSciEfesPrimBehaviour
        {
            public record Establishing : Active
            {
                public record WaitingForVersionCheck() : Establishing()
                {
                    public static new WaitingForVersionCheck New(SSciEfesPrim This) => new WaitingForVersionCheck();
                }
                public record WaitingForInitialisation() : Establishing()
                {
                    public static new WaitingForInitialisation New(SSciEfesPrim This) => new WaitingForInitialisation();
                }
                public record ReceivingStatus() : Establishing()
                {
                    public static new ReceivingStatus New(SSciEfesPrim This) => new ReceivingStatus();
                }
                public record OtherVersionRequired() : Establishing()
                {
                    public static new OtherVersionRequired New(SSciEfesPrim This) => new OtherVersionRequired();
                }

                public static new Establishing New(SSciEfesPrim This)
                {
                    This.SendMessage(new Message.CdPdiVersionCheck(This.D3inConPdiVersion.Value), This.P1inout);

                    This.D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.WaitingForVersionCheck;

                    return Establishing.WaitingForVersionCheck.New(This);
                }

                private Establishing() { }
            }

            public record Established() : Active()
            {
                public static new Established New(SSciEfesPrim This) => new Established();
            }

            public static new Active New(SSciEfesPrim This)
            {

                return Active.Establishing.New(This);
            }

            private Active() { }
        }

        public record Suspended() : SSciEfesPrimBehaviour()
        {
            public static new Suspended New(SSciEfesPrim This) => new Suspended();
        }

        public static new SSciEfesPrimBehaviour New(SSciEfesPrim This)
        {
            This.Cop1Init();

            This.D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.DisconnectedNoScp;

            return SSciEfesPrimBehaviour.DisconnectedNoScp.New(This);
        }

        private SSciEfesPrimBehaviour() { }
    }


    private SSciEfesPrimBehaviour _state;
    public SSciEfesPrimBehaviour State => _state;

    private readonly IMessageFactory _messageConverter;

    public SSciEfesPrim(IMessageFactory messageConverter)
    {
        _messageConverter = messageConverter;

        // Initialize ports
        P1inout = new Port<object>();
        D3inConPdiVersion = new Port<byte[]>();
        D4inConChecksumData = new Port<byte[]>();
        T20inProtocolError = new Port<PulsedIn>();
        T21inFormalTelegramError = new Port<PulsedIn>();
        T22inContentTelegramError = new Port<PulsedIn>();
        T5inScpConnectionEstablished = new Port<PulsedIn>();
        T10inScpConnectionTerminated = new Port<PulsedIn>();
        T12outTerminateScpConnection = new Port<PulsedOut>();
        D50outPdiConnectionState = new Port<D50outPdiConnectionStateValue>();
        D2inConTmaxPdiConnection = new Port<object>();
        T6outEstablishScpConnection = new Port<PulsedOut>();
        T48inDisableOrDisconnectPdiEfes = new Port<PulsedIn>();
        T49inEnableOrConnectPdiEfes = new Port<PulsedIn>();
        T45inResetSevereError = new Port<PulsedIn>();
        T47inConOtherPdiVersionAvailable = new Port<PulsedIn>();
        D39inConLastPdiVersion = new Port<bool>();
        T46outConOtherPdiVersionRequest = new Port<PulsedOut>();
        T44inInitiateMaintenance = new Port<PulsedIn>();
        D60outPdiCloseReason = new Port<D60outPdiCloseReasonValue>();

        // Initialize change events
        Change749 = new Event(() => T10inScpConnectionTerminated.Value);
        Change980 = new Event(() => T20inProtocolError.Value);
        Change987 = new Event(() => T21inFormalTelegramError.Value);
        Change999 = new Event(() => T22inContentTelegramError.Value);
        Change1162 = new Event(() => T44inInitiateMaintenance.Value);
        Change1179 = new Event(() => T48inDisableOrDisconnectPdiEfes.Value);
        Change1175 = new Event(() => T47inConOtherPdiVersionAvailable.Value);
        Change1178 = new Event(() => T48inDisableOrDisconnectPdiEfes.Value);
        Change1225 = new Event(() => T5inScpConnectionEstablished.Value);
        Change1172 = new Event(() => T45inResetSevereError.Value);
        Change1223 = new Event(() => T5inScpConnectionEstablished.Value);
        Change743 = new Event(() => T10inScpConnectionTerminated.Value);
        Change1171 = new Event(() => T45inResetSevereError.Value);
        Change745 = new Event(() => T10inScpConnectionTerminated.Value);
        Change1180 = new Event(() => T49inEnableOrConnectPdiEfes.Value);
        Change1181 = new Event(() => T49inEnableOrConnectPdiEfes.Value);
        Change1227 = new Event(() => T5inScpConnectionEstablished.Value);
        Change742 = new Event(() => T10inScpConnectionTerminated.Value);
        Change1177 = new Event(() => T48inDisableOrDisconnectPdiEfes.Value);
    }

    public void Init()
    {
        _state = SSciEfesPrimBehaviour.New(this);
    }

    public IEnumerable<AbstractPort> GetPorts()
    {
        return new AbstractPort[] {
            // TODO: Skip message ports
            P1inout, D3inConPdiVersion, D4inConChecksumData, T20inProtocolError, T21inFormalTelegramError, T22inContentTelegramError, T5inScpConnectionEstablished, T10inScpConnectionTerminated, T12outTerminateScpConnection, D50outPdiConnectionState, D2inConTmaxPdiConnection, T6outEstablishScpConnection, T48inDisableOrDisconnectPdiEfes, T49inEnableOrConnectPdiEfes, T45inResetSevereError, T47inConOtherPdiVersionAvailable, D39inConLastPdiVersion, T46outConOtherPdiVersionRequest, T44inInitiateMaintenance, D60outPdiCloseReason
        };
    }

    public IEnumerable<Event> GetChangeEvents()
    {
        return new Event[] {
            Change749, Change980, Change987, Change999, Change1162, Change1179, Change1175, Change1178, Change1225, Change1172, Change1223, Change743, Change1171, Change745, Change1180, Change1181, Change1227, Change742, Change1177
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
            SSciEfesPrimBehaviour.Active.Establishing.WaitingForVersionCheck => TransitionFromSSciEfesPrimBehaviour__Active__Establishing__WaitingForVersionCheck(),
            SSciEfesPrimBehaviour.Active.Establishing.WaitingForInitialisation => TransitionFromSSciEfesPrimBehaviour__Active__Establishing__WaitingForInitialisation(),
            SSciEfesPrimBehaviour.Active.Establishing.ReceivingStatus => TransitionFromSSciEfesPrimBehaviour__Active__Establishing__ReceivingStatus(),
            SSciEfesPrimBehaviour.Active.Establishing.OtherVersionRequired => TransitionFromSSciEfesPrimBehaviour__Active__Establishing__OtherVersionRequired(),
            SSciEfesPrimBehaviour.Active.Establishing => TransitionFromSSciEfesPrimBehaviour__Active__Establishing(),
            SSciEfesPrimBehaviour.Active.Established => TransitionFromSSciEfesPrimBehaviour__Active__Established(),
            SSciEfesPrimBehaviour.RequestedNoScp => TransitionFromSSciEfesPrimBehaviour__RequestedNoScp(),
            SSciEfesPrimBehaviour.ImpermissibleNoScp => TransitionFromSSciEfesPrimBehaviour__ImpermissibleNoScp(),
            SSciEfesPrimBehaviour.Impermissible => TransitionFromSSciEfesPrimBehaviour__Impermissible(),
            SSciEfesPrimBehaviour.Disconnected => TransitionFromSSciEfesPrimBehaviour__Disconnected(),
            SSciEfesPrimBehaviour.DisconnectedNoScp => TransitionFromSSciEfesPrimBehaviour__DisconnectedNoScp(),
            SSciEfesPrimBehaviour.Active => TransitionFromSSciEfesPrimBehaviour__Active(),
            SSciEfesPrimBehaviour.Suspended => TransitionFromSSciEfesPrimBehaviour__Suspended()
        };
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__Active__Establishing__WaitingForVersionCheck()
    {
        if (IsMessageArrived("Msg_PDI_Not_Available"))
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change749.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciEfesPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change980.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change987.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change999.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change1162.IsTriggered)
        {
            {

                SendMessage(new Message.CdReleasePdiForMaintenance(), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (Change1179.IsTriggered)
        {
            {

                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.NormalClose), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiNormalClose;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Disconnected;

                return SSciEfesPrimBehaviour.Disconnected.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {

                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.Timeout), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciEfesPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (IsMessageArrived("Msg_PDI_Version_Check"))
        {
            {
                var (Result, ChecksumData, PDIVersion, _, _) = MsgPdiVersionCheck;
                MemPdiVersionResult = Result;
                MemChecksumData = ChecksumData;

                {
                    if (Result == ResultValue.Match)
                    {


                        if (ChecksumData == D4inConChecksumData.Value)
                        {

                            SendMessage(new Message.CdInitialisationRequest(), P1inout);

                            D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.WaitingForInitialisation;

                            return SSciEfesPrimBehaviour.Active.Establishing.WaitingForInitialisation.New(this);
                        }
                    }
                }
                {
                    if (Result == ResultValue.NotMatch)
                    {


                        if (D39inConLastPdiVersion.Value == false)
                        {

                            T46outConOtherPdiVersionRequest.Value = new PulsedOut(true);
                            SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.OtherVersionRequired), P1inout);
                            D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiOtherVersionRequired;

                            D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.OtherVersionRequired;

                            return SSciEfesPrimBehaviour.Active.Establishing.OtherVersionRequired.New(this);
                        }
                    }
                }
            }
        }

        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__Active__Establishing__WaitingForInitialisation()
    {
        if (IsMessageArrived("Msg_PDI_Not_Available"))
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change749.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciEfesPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change980.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change987.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change999.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change1162.IsTriggered)
        {
            {

                SendMessage(new Message.CdReleasePdiForMaintenance(), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (Change1179.IsTriggered)
        {
            {

                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.NormalClose), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiNormalClose;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Disconnected;

                return SSciEfesPrimBehaviour.Disconnected.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {

                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.Timeout), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciEfesPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (IsMessageArrived("Msg_Start_Initialisation"))
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.ReceivingStatus;

                return SSciEfesPrimBehaviour.Active.Establishing.ReceivingStatus.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__Active__Establishing__ReceivingStatus()
    {
        if (IsMessageArrived("Msg_PDI_Not_Available"))
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change749.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciEfesPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change980.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change987.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change999.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change1162.IsTriggered)
        {
            {

                SendMessage(new Message.CdReleasePdiForMaintenance(), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (Change1179.IsTriggered)
        {
            {

                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.NormalClose), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiNormalClose;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Disconnected;

                return SSciEfesPrimBehaviour.Disconnected.New(this);
            }
        }
        if (IsMessageArrived("Msg_Initialisation_Completed"))
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Established;

                return SSciEfesPrimBehaviour.Active.Established.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__Active__Establishing__OtherVersionRequired()
    {
        if (IsMessageArrived("Msg_PDI_Not_Available"))
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change749.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciEfesPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change980.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change987.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change999.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change1162.IsTriggered)
        {
            {

                SendMessage(new Message.CdReleasePdiForMaintenance(), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (Change1179.IsTriggered)
        {
            {

                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.NormalClose), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiNormalClose;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Disconnected;

                return SSciEfesPrimBehaviour.Disconnected.New(this);
            }
        }
        if (Change1175.IsTriggered)
        {
            {


                return SSciEfesPrimBehaviour.Active.Establishing.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__Active__Establishing()
    {
        if (IsMessageArrived("Msg_PDI_Not_Available"))
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change749.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciEfesPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change980.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change987.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change999.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change1162.IsTriggered)
        {
            {

                SendMessage(new Message.CdReleasePdiForMaintenance(), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (Change1179.IsTriggered)
        {
            {

                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.NormalClose), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiNormalClose;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Disconnected;

                return SSciEfesPrimBehaviour.Disconnected.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {

                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.Timeout), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciEfesPrimBehaviour.Active.Establishing.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__Active__Established()
    {


        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__RequestedNoScp()
    {
        if (Change1178.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.DisconnectedNoScp;

                return SSciEfesPrimBehaviour.DisconnectedNoScp.New(this);
            }
        }
        if (Change1225.IsTriggered)
        {
            {


                return SSciEfesPrimBehaviour.Active.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__ImpermissibleNoScp()
    {
        if (Change1172.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciEfesPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change1223.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__Impermissible()
    {
        if (Change743.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.ImpermissibleNoScp;

                return SSciEfesPrimBehaviour.ImpermissibleNoScp.New(this);
            }
        }
        if (Change1171.IsTriggered)
        {
            {


                return SSciEfesPrimBehaviour.Active.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__Disconnected()
    {
        if (Change745.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.DisconnectedNoScp;

                return SSciEfesPrimBehaviour.DisconnectedNoScp.New(this);
            }
        }
        if (Change1180.IsTriggered)
        {
            {


                return SSciEfesPrimBehaviour.Active.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__DisconnectedNoScp()
    {
        if (Change1181.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciEfesPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change1227.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Disconnected;

                return SSciEfesPrimBehaviour.Disconnected.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__Active()
    {
        if (IsMessageArrived("Msg_PDI_Not_Available"))
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesProtocolError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesContentTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                var (ReportedResetReason, _, _) = MsgResetPdi;
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EfesFormalTelegramError;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change749.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciEfesPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change980.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilProtocolError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ProtocolError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change987.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilFormalTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.FormalTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change999.IsTriggered)
        {
            {

                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.EilContentTelegramError;
                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.ContentTelegramError), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Impermissible;

                return SSciEfesPrimBehaviour.Impermissible.New(this);
            }
        }
        if (Change1162.IsTriggered)
        {
            {

                SendMessage(new Message.CdReleasePdiForMaintenance(), P1inout);

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Suspended;

                return SSciEfesPrimBehaviour.Suspended.New(this);
            }
        }
        if (Change1179.IsTriggered)
        {
            {

                SendMessage(new Message.CdClosePdi(Message.CdClosePdi.Values.NormalClose), P1inout);
                D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.PdiNormalClose;

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Disconnected;

                return SSciEfesPrimBehaviour.Disconnected.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciEfesPrimBehaviour TransitionFromSSciEfesPrimBehaviour__Suspended()
    {
        if (IsMessageArrived("Msg_PDI_Available"))
        {
            {


                return SSciEfesPrimBehaviour.Active.New(this);
            }
        }
        if (Change742.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection.Value = new PulsedOut(true);

                return SSciEfesPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (Change1177.IsTriggered)
        {
            {

                D50outPdiConnectionState.Value = D50outPdiConnectionStateValue.Disconnected;

                return SSciEfesPrimBehaviour.Disconnected.New(this);
            }
        }

        // Do not transition
        return _state;
    }


    // Properties
    public ResultValue MemPdiVersionResult { get; set; }
    public byte[] MemChecksumData { get; set; }

    // Ports
    public Port<object> P1inout { get; set; }
    public Port<byte[]> D3inConPdiVersion { get; set; }
    public Port<byte[]> D4inConChecksumData { get; set; }
    public Port<PulsedIn> T20inProtocolError { get; set; }
    public Port<PulsedIn> T21inFormalTelegramError { get; set; }
    public Port<PulsedIn> T22inContentTelegramError { get; set; }
    public Port<PulsedIn> T5inScpConnectionEstablished { get; set; }
    public Port<PulsedIn> T10inScpConnectionTerminated { get; set; }
    public Port<PulsedOut> T12outTerminateScpConnection { get; set; }
    public Port<D50outPdiConnectionStateValue> D50outPdiConnectionState { get; set; }
    public Port<object> D2inConTmaxPdiConnection { get; set; }
    public Port<PulsedOut> T6outEstablishScpConnection { get; set; }
    public Port<PulsedIn> T48inDisableOrDisconnectPdiEfes { get; set; }
    public Port<PulsedIn> T49inEnableOrConnectPdiEfes { get; set; }
    public Port<PulsedIn> T45inResetSevereError { get; set; }
    public Port<PulsedIn> T47inConOtherPdiVersionAvailable { get; set; }
    public Port<bool> D39inConLastPdiVersion { get; set; }
    public Port<PulsedOut> T46outConOtherPdiVersionRequest { get; set; }
    public Port<PulsedIn> T44inInitiateMaintenance { get; set; }
    public Port<D60outPdiCloseReasonValue> D60outPdiCloseReason { get; set; }

    // Operations
    public void Cop1Init()
    {
        D60outPdiCloseReason.Value = D60outPdiCloseReasonValue.NoError;
        MemPdiVersionResult = ResultValue.Unknown;
        MemChecksumData = D4inConChecksumData.Value;

    }

    // Value Types

    public enum MemPdiVersionResultValue
    {
        Match,
        NotMatch,
        Unknown
    }











    public enum D50outPdiConnectionStateValue
    {
        Suspended,
        Impermissible,
        RequestedNoScp,
        Disconnected,
        WaitingForInitialisation,
        OtherVersionRequired,
        ReceivingStatus,
        Established,
        DisconnectedNoScp,
        ImpermissibleNoScp,
        WaitingForVersionCheck
    }










    public enum D60outPdiCloseReasonValue
    {
        EfesProtocolError,
        EfesContentTelegramError,
        EfesFormalTelegramError,
        EilProtocolError,
        EilFormalTelegramError,
        EilContentTelegramError,
        PdiNormalClose,
        PdiTimeout,
        PdiOtherVersionRequired,
        NoError
    }


    public enum ResultValue
    {
        Match,
        NotMatch,
        Unknown
    }



    // Messages
    public record Message
    {
        public record MsgPdiNotAvailable() : Message
        {
            public void Deconstruct(out bool discard1, out bool discard2)
            {

                discard1 = false;
                discard2 = false;
            }
        }
        public record MsgResetPdi(object ReportedResetReason) : Message
        {
            public void Deconstruct(out object ReportedResetReason, out bool discard1, out bool discard2)
            {
                ReportedResetReason = this.ReportedResetReason;
                discard1 = false;
                discard2 = false;
            }
        }
        public record MsgPdiVersionCheck(ResultValue Result, byte[] ChecksumData, byte[] PDIVersion) : Message
        {
            public void Deconstruct(out ResultValue Result, out byte[] ChecksumData, out byte[] PDIVersion, out bool discard1, out bool discard2)
            {
                Result = this.Result;
                ChecksumData = this.ChecksumData;
                PDIVersion = this.PDIVersion;
                discard1 = false;
                discard2 = false;
            }
        }
        public record MsgStartInitialisation() : Message
        {
            public void Deconstruct(out bool discard1, out bool discard2)
            {

                discard1 = false;
                discard2 = false;
            }
        }
        public record MsgInitialisationCompleted() : Message
        {
            public void Deconstruct(out bool discard1, out bool discard2)
            {

                discard1 = false;
                discard2 = false;
            }
        }
        public record MsgPdiAvailable() : Message
        {
            public void Deconstruct(out bool discard1, out bool discard2)
            {

                discard1 = false;
                discard2 = false;
            }
        }
        public record CdClosePdi(CdClosePdi.Values Value) : Message
        {
            public enum Values
            {
                ProtocolError,
                FormalTelegramError,
                ContentTelegramError,
                NormalClose,
                Timeout,
                OtherVersionRequired
            }
        }
        public record CdReleasePdiForMaintenance() : Message
        {

        }
        public record CdInitialisationRequest() : Message
        {

        }
        public record CdPdiVersionCheck(byte[] Value) : Message
        {

        }
    }

    // Signals
    public Message.MsgPdiNotAvailable MsgPdiNotAvailable { get; set; }
    public Message.MsgResetPdi MsgResetPdi { get; set; }
    public Message.MsgPdiVersionCheck MsgPdiVersionCheck { get; set; }
    public Message.MsgStartInitialisation MsgStartInitialisation { get; set; }
    public Message.MsgInitialisationCompleted MsgInitialisationCompleted { get; set; }
    public Message.MsgPdiAvailable MsgPdiAvailable { get; set; }

    // Events
    public Event Change749 { get; }
    public Event Change980 { get; }
    public Event Change987 { get; }
    public Event Change999 { get; }
    public Event Change1162 { get; }
    public Event Change1179 { get; }
    public Event Change1175 { get; }
    public Event Change1178 { get; }
    public Event Change1225 { get; }
    public Event Change1172 { get; }
    public Event Change1223 { get; }
    public Event Change743 { get; }
    public Event Change1171 { get; }
    public Event Change745 { get; }
    public Event Change1180 { get; }
    public Event Change1181 { get; }
    public Event Change1227 { get; }
    public Event Change742 { get; }
    public Event Change1177 { get; }
}
