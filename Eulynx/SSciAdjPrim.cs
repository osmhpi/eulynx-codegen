namespace Eulynx;

public class SSciAdjPrim
{
    public record SSciAdjsPrimBehaviour : object
    {
        public record RequestedNoScp() : SSciAdjsPrimBehaviour()
        {
            public static new RequestedNoScp New() => new RequestedNoScp();
        }
        public record ImpermissibleNoScp() : SSciAdjsPrimBehaviour()
        {
            public static new ImpermissibleNoScp New() => new ImpermissibleNoScp();
        }
        public record Impermissible() : SSciAdjsPrimBehaviour()
        {
            public static new Impermissible New() => new Impermissible();
        }
        public record Active : SSciAdjsPrimBehaviour
        {
            public record Establishing : Active
            {
                public record WaitingForVersionCheck() : Establishing()
                {
                    public static new WaitingForVersionCheck New() => new WaitingForVersionCheck();
                }
                public record WaitingForInitialisation() : Establishing()
                {
                    public static new WaitingForInitialisation New() => new WaitingForInitialisation();
                }
                public record ReceivingSecStatus() : Establishing()
                {
                    public static new ReceivingSecStatus New() => new ReceivingSecStatus();
                }
                public record CheckingSecStatus() : Establishing()
                {
                    public static new CheckingSecStatus New() => new CheckingSecStatus();
                }
                public record SendingPrimStatus() : Establishing()
                {
                    public static new SendingPrimStatus New() => new SendingPrimStatus();
                }
                public record WaitingForInitCompletion() : Establishing()
                {
                    public static new WaitingForInitCompletion New() => new WaitingForInitCompletion();
                }

                public static new Establishing New() => Establishing.WaitingForVersionCheck.New();

                private Establishing() { }
            }

            public record Established() : Active()
            {
                public static new Established New() => new Established();
            }

            public static new Active New() => Active.Establishing.New();

            private Active() { }
        }


        public static new SSciAdjsPrimBehaviour New() => SSciAdjsPrimBehaviour.RequestedNoScp.New();

        private SSciAdjsPrimBehaviour() { }
    }


    private SSciAdjsPrimBehaviour _state;
    public SSciAdjsPrimBehaviour State { get { return _state; } }

    public SSciAdjPrim()
    {
        D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
        T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

        _state = SSciAdjsPrimBehaviour.New();
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

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New();
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");
                SendMessage("CdClosePdi(Timeout) ", "P1inout");
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New();
            }
        }
        if (IsMessageArrived("Msg_PDI_Version_Check"))
        {
            if (ReceivedMessage("Msg_PDI_Version_Check[Result == \"match\"  && ChecksumData == D4in_Con_Checksum_Data]"))
            {
                SendMessage("CdInitialisationRequest ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.WaitingForInitialisation;

                return SSciAdjsPrimBehaviour.Active.Establishing.WaitingForInitialisation.New();
            }
        }
        if (IsMessageArrived("Msg_PDI_Version_Check"))
        {
            if (ReceivedMessage("Msg_PDI_Version_Check[Result == \"match\"  && !(ChecksumData == D4in_Con_Checksum_Data)]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiChecksumMismatch;
                SendMessage("CdClosePdi(Checksummismatch) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_PDI_Version_Check"))
        {
            if (ReceivedMessage("Msg_PDI_Version_Check[Result == \"not match\"]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiOtherVersionRequired;
                SendMessage("CdClosePdi(Otherversionrequired) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
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

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New();
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");
                SendMessage("CdClosePdi(Timeout) ", "P1inout");
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New();
            }
        }
        if (IsMessageArrived("Msg_Start_Initialisation"))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.ReceivingSecStatus;

                return SSciAdjsPrimBehaviour.Active.Establishing.ReceivingSecStatus.New();
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

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New();
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");
                SendMessage("CdClosePdi(Timeout) ", "P1inout");
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New();
            }
        }
        if (IsMessageArrived("Msg_Status_Report_Completed"))
        {
            {
                T27outCheckSecStatus = T27outCheckSecStatusValue.True;
                D50outPdiConnectionState = D50outPdiConnectionStateValue.CheckingSecStatus;

                return SSciAdjsPrimBehaviour.Active.Establishing.CheckingSecStatus.New();
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

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New();
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");
                SendMessage("CdClosePdi(Timeout) ", "P1inout");
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New();
            }
        }
        if (IsConditionChanged(T25inSecStatusReportComplete))
        {
            {
                SendMessage("StartPrimStatusReport ", "P2inout");
                D50outPdiConnectionState = D50outPdiConnectionStateValue.SendingPrimStatus;

                return SSciAdjsPrimBehaviour.Active.Establishing.SendingPrimStatus.New();
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

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New();
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsTimeoutExpired(D2inConTmaxPdiConnection))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");
                SendMessage("CdClosePdi(Timeout) ", "P1inout");
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PdiTimeout;

                return SSciAdjsPrimBehaviour.Active.Establishing.New();
            }
        }
        if (IsMessageArrived("Prim_Status_Report_Completed"))
        {
            {
                SendMessage("MsgStatusReportCompleted ", "P1inout");
                D50outPdiConnectionState = D50outPdiConnectionStateValue.WaitingForInitCompletion;

                return SSciAdjsPrimBehaviour.Active.Establishing.WaitingForInitCompletion.New();
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

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == ContentTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecContentTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Reset_PDI"))
        {
            if (ReceivedMessage("Msg_Reset_PDI[ReportedResetReason == FormalTelegramError]"))
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.SecFormalTelegramError;

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T10inScpConnectionTerminated))
        {
            {
                D50outPdiConnectionState = D50outPdiConnectionStateValue.RequestedNoScp;
                T6outEstablishScpConnection = T6outEstablishScpConnectionValue.True;

                return SSciAdjsPrimBehaviour.RequestedNoScp.New();
            }
        }
        if (IsConditionChanged(T20inProtocolError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimProtocolError;
                SendMessage("CdClosePdi(Protocolerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T21inFormalTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimFormalTelegramError;
                SendMessage("CdClosePdi(Formaltelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsConditionChanged(T22inContentTelegramError))
        {
            {
                D60outPdiCloseReason = D60outPdiCloseReasonValue.PrimContentTelegramError;
                SendMessage("CdClosePdi(Contenttelegramerror) ", "P1inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Impermissible;

                return SSciAdjsPrimBehaviour.Impermissible.New();
            }
        }
        if (IsMessageArrived("Msg_Initialisation_Completed"))
        {
            {
                SendMessage("PdiConnectionClosed ", "P2inout");

                D50outPdiConnectionState = D50outPdiConnectionStateValue.Established;
                SendMessage("PdiConnectionEstablished ", "P2inout");

                return SSciAdjsPrimBehaviour.Active.Established.New();
            }
        }

        // Do not transition
        return _state;
    }


    // Properties
    public bool MemPdiVersionCheckResult { get; set; }
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







    public enum D50outPdiConnectionStateValue
    {
        Impermissible,
        RequestedNoScp,
        WaitingForInitialisation,
        ReceivingSecStatus,
        CheckingSecStatus,
        SendingPrimStatus,
        WaitingForInitCompletion,
        Established
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
