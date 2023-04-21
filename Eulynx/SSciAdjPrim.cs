namespace Eulynx;

public class SSciAdjPrim
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
                    This.SendMessage("EstablishingPdiConnection ", "P2inout");
                    This.SendMessage("CdPdiVersionCheck(D3inConPdiVersion) ", "P1inout");

                    This.D50outPdiConnectionState = D50outPdiConnectionStateValue.WaitingForVersionCheck;

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

            This.D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
            This.T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

            return SSciAdjsPrimBehaviour.RequestedNoScp.New(This);
        }

        private SSciAdjsPrimBehaviour() { }
    }


    private SSciAdjsPrimBehaviour _state;
    public SSciAdjsPrimBehaviour State { get { return _state; } }

    public void Init()
    {
        _state = SSciAdjsPrimBehaviour.New(this);
    }

    private bool IsTimeoutExpired(object timeout)
    {
        // TODO
        return false;
    }

    private bool IsConditionChanged(bool condition)
    {
        // TODO: Keep in mind that this should only evaluate to true once
        return condition;
    }

    private void SendMessage(string message, string port)
    {
        // TODO: Implement
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
            SSciAdjsPrimBehaviour.Active.Establishing.WaitingForVersionCheck => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForVersionCheck(),
            SSciAdjsPrimBehaviour.Active.Establishing.WaitingForInitialisation => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForInitialisation(),
            SSciAdjsPrimBehaviour.Active.Establishing.ReceivingSecStatus => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__ReceivingSecStatus(),
            SSciAdjsPrimBehaviour.Active.Establishing.CheckingSecStatus => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__CheckingSecStatus(),
            SSciAdjsPrimBehaviour.Active.Establishing.SendingPrimStatus => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__SendingPrimStatus(),
            SSciAdjsPrimBehaviour.Active.Establishing.WaitingForInitCompletion => TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForInitCompletion()
        };
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForVersionCheck()
    {
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");
                SendMessage("CdClosePdi(Timeout) ", "P1inout");
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (IsMessageArrived("Msg_PDI_Version_Check"))
        {
            if (ReceivedMessage("Msg_PDI_Version_Check[Result == \"match\"  && ChecksumData == D4in_Con_Checksum_Data]"))
            {
                SendMessage("CdInitialisationRequest ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.WaitingForInitialisation;

                return SSciAdjsPrimBehaviour.Active.Establishing.WaitingForInitialisation.New(this);
            }
        }
        if (IsMessageArrived("Msg_PDI_Version_Check"))
        {
            if (ReceivedMessage("Msg_PDI_Version_Check[Result == \"match\"  && !(ChecksumData == D4in_Con_Checksum_Data)]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiChecksumMismatch;
                SendMessage("CdClosePdi(Checksummismatch) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_PDI_Version_Check"))
        {
            if (ReceivedMessage("Msg_PDI_Version_Check[Result == \"not match\"]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiOtherVersionRequired;
                SendMessage("CdClosePdi(Otherversionrequired) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForInitialisation()
    {
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");
                SendMessage("CdClosePdi(Timeout) ", "P1inout");
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (IsMessageArrived("Msg_Start_Initialisation"))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.ReceivingSecStatus;

                return SSciAdjsPrimBehaviour.Active.Establishing.ReceivingSecStatus.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__ReceivingSecStatus()
    {
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");
                SendMessage("CdClosePdi(Timeout) ", "P1inout");
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (IsMessageArrived("Msg_Status_Report_Completed"))
        {
            {
                T27outCheckSecStatus = T27outCheckSecStatusValue.True;
                D50outPdiConnectionState = D50outPdiConnectionStateValue.CheckingSecStatus;

                return SSciAdjsPrimBehaviour.Active.Establishing.CheckingSecStatus.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__CheckingSecStatus()
    {
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");
                SendMessage("CdClosePdi(Timeout) ", "P1inout");
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (IsConditionChanged(T25inSecStatusReportComplete))
        {
            {
                SendMessage("StartPrimStatusReport ", "P2inout");
                D50outPdiConnectionState = D50outPdiConnectionStateValue.SendingPrimStatus;

                return SSciAdjsPrimBehaviour.Active.Establishing.SendingPrimStatus.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__SendingPrimStatus()
    {
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");
                SendMessage("CdClosePdi(Timeout) ", "P1inout");
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New(this);
            }
        }
        if (IsMessageArrived("Prim_Status_Report_Completed"))
        {
            {
                SendMessage("MsgStatusReportCompleted ", "P1inout");
                D50outPdiConnectionState = D50outPdiConnectionStateValue.WaitingForInitCompletion;

                return SSciAdjsPrimBehaviour.Active.Establishing.WaitingForInitCompletion.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private SSciAdjsPrimBehaviour TransitionFromSSciAdjsPrimBehaviour__Active__Establishing__WaitingForInitCompletion()
    {
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ProtocolError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecProtocolError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New(this);
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New(this);
            }
        }
        if (IsMessageArrived("Msg_Initialisation_Completed"))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Established;
                SendMessage("PdiConnectionEstablished ", "P2inout");

                return SSciAdjsPrimBehaviour.Active.Established.New(this);
            }
        }

        // Do not transition
        return _state;
    }


    // Properties
    public MemPdiVersionCheckResultValue MemPdiVersionCheckResult { get; set; }
    public bool MemPdiVersionChecksumdata { get; set; }

    // Ports
    public bool T5inScpConnectionEstablished { get; set; }
    public bool T10inScpConnectionTerminated { get; set; }
    public bool D4inConChecksumData { get; set; }
    public D50outPdiConnectionStateValue D50outPdiConnectionState { get; set; }
    public T6outEstablishScpConnectionValue T6outEstablishScpConnection { get; set; }
    public bool T22inContentTelegramError { get; set; }
    public bool T20inProtocolError { get; set; }
    public bool T21inFormalTelegramError { get; set; }
    public bool D2inConTmaxPdiConnection { get; set; }
    public bool D3inConPdiVersion { get; set; }
    public bool T45inResetSevereError { get; set; }
    public D60outPdiCloseReasonValue D60outPdiCloseReason { get; set; }
    public T27outCheckSecStatusValue T27outCheckSecStatus { get; set; }
    public bool P1inout { get; set; }
    public bool P2inout { get; set; }
    public bool T25inSecStatusReportComplete { get; set; }

    // Operations
    public void Cop1Init()
    {
        MemPdiVersionCheckResult = MemPdiVersionCheckResultValue.Unknown;
        MemPdiVersionChecksumdata = D4inConChecksumData;

    }


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
        WaitingForVersionCheck
    }

    public enum T6outEstablishScpConnectionValue
    {
        True
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

    public enum T27outCheckSecStatusValue
    {
        True
    }



}
