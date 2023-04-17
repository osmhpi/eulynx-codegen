namespace Eulynx;

public class FSciPRecieveAndReportTimeout
{
    public record FSciPRecieveAndReportTimeoutBehaviour : object
    {
        public record RecievingCommandsAndReportingTimeout : FSciPRecieveAndReportTimeoutBehaviour
        {
            public record CommandedLeft_ReportingPointTimeout() : RecievingCommandsAndReportingTimeout()
            {
                public static new CommandedLeft_ReportingPointTimeout New() => new CommandedLeft_ReportingPointTimeout();
            }
            public record Uncommanded_ReportingPointTimeout() : RecievingCommandsAndReportingTimeout()
            {
                public static new Uncommanded_ReportingPointTimeout New() => new Uncommanded_ReportingPointTimeout();
            }
            public record CommandedRight_ReportingPointTimeout() : RecievingCommandsAndReportingTimeout()
            {
                public static new CommandedRight_ReportingPointTimeout New() => new CommandedRight_ReportingPointTimeout();
            }
            public record Waiting_ReportingPointTimeout() : RecievingCommandsAndReportingTimeout()
            {
                public static new Waiting_ReportingPointTimeout New() => new Waiting_ReportingPointTimeout();
            }

            public static new RecievingCommandsAndReportingTimeout New() => RecievingCommandsAndReportingTimeout.Waiting_ReportingPointTimeout.New();

            private RecievingCommandsAndReportingTimeout() { }
        }


        public static new FSciPRecieveAndReportTimeoutBehaviour New() => FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.New();

        private FSciPRecieveAndReportTimeoutBehaviour() { }
    }


    private FSciPRecieveAndReportTimeout _state;
    public FSciPRecieveAndReportTimeout State { get { return _state; } }

    public FSciPRecieveAndReportTimeout()
    {

        _state = FSciPRecieveAndReportTimeout.New();
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


    public void Transition()
    {
        _state = _state switch
        {
            FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedLeft_ReportingPointTimeout => TransitionFromCommandedleftReportingpointtimeout(),
            FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout => TransitionFromUncommandedReportingpointtimeout(),
            FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedRight_ReportingPointTimeout => TransitionFromCommandedrightReportingpointtimeout(),
            FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Waiting_ReportingPointTimeout => TransitionFromWaitingReportingpointtimeout()
        };
    }

    private FSciPRecieveAndReportTimeoutBehaviour TransitionFromCommandedLeft_ReportingPointTimeout()
    {
        if (IsConditionChanged(D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.Suspended))
        {
            {



                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.New();
            }
        }
        {
            if (D5inObservedPointPosition == D5inObservedPointPositionValue.Left)
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }
        if (IsTimeoutExpired(D28inConTmaxPointOperation))
        {
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Commandedpointpositionstate == Right && D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Right;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedRight_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D35inPm1DriveStop && (D35inPm1nDriveStop || !D36inPm1nActivation) && (D35inPm2DriveStop || !D37inPm2Activation)
        And(D35inPm2nDriveStop || !D38inPm2nActivation)))
        {
            if (D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D5inObservedPointPosition == D5inObservedPointPositionValue.Left))
        {
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm1MsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Left;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedLeft_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm1nMsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Left;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedLeft_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm2MsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Left;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedLeft_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm2nMsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Left;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedLeft_ReportingPointTimeout.New();
            }
        }

        // Do not transition
        return _state;
    }

    private FSciPRecieveAndReportTimeoutBehaviour TransitionFromUncommanded_ReportingPointTimeout()
    {
        if (IsConditionChanged(D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.Suspended))
        {
            {



                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Commandedpointpositionstate == Left && D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Left;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedLeft_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Commandedpointpositionstate == Right && D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Right;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedRight_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm1MsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm1nMsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm2MsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm2nMsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }

        // Do not transition
        return _state;
    }

    private FSciPRecieveAndReportTimeoutBehaviour TransitionFromCommandedRight_ReportingPointTimeout()
    {
        if (IsConditionChanged(D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.Suspended))
        {
            {



                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.New();
            }
        }
        {
            if (D5inObservedPointPosition == D5inObservedPointPositionValue.Right)
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }
        if (IsTimeoutExpired(D28inConTmaxPointOperation))
        {
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Commandedpointpositionstate == Left && D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Left;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedLeft_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D35inPm1DriveStop && (D35inPm1nDriveStop || !D36inPm1nActivation) && (D35inPm2DriveStop || !D37inPm2Activation)
        And(D35inPm2nDriveStop || !D38inPm2nActivation)))
        {
            if (D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D5inObservedPointPosition == D5inObservedPointPositionValue.Right))
        {
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Uncommanded;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Uncommanded_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm1MsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Right;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedRight_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm1nMsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Right;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedRight_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm2MsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Right;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedRight_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm2nMsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Right;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedRight_ReportingPointTimeout.New();
            }
        }

        // Do not transition
        return _state;
    }

    private FSciPRecieveAndReportTimeoutBehaviour TransitionFromWaiting_ReportingPointTimeout()
    {
        if (IsConditionChanged(D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.Suspended))
        {
            {



                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Commandedpointpositionstate == Left && D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Left;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedLeft_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Commandedpointpositionstate == Right && D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Right;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.CommandedRight_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm1MsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D34outPm1ConActive = D34outPm1ConActiveValue.True;
                D44outPm1ConDriveCapability = D44outPm1ConDriveCapabilityValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Initial;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Waiting_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm1nMsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D34outPm1ConActive = D34outPm1ConActiveValue.True;
                D44outPm1ConDriveCapability = D44outPm1ConDriveCapabilityValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Initial;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Waiting_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm2MsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D34outPm1ConActive = D34outPm1ConActiveValue.True;
                D44outPm1ConDriveCapability = D44outPm1ConDriveCapabilityValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Initial;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Waiting_ReportingPointTimeout.New();
            }
        }
        if (IsConditionChanged(D40inPm2nMsgPmTimeout))
        {
            if (
D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {


                Send MsgTimeout To P10inout; D41outMsgTimeout = D41outMsgTimeoutValue.True;
                D34outPm1ConActive = D34outPm1ConActiveValue.True;
                D44outPm1ConDriveCapability = D44outPm1ConDriveCapabilityValue.True;
                D2outRequiredPointPosition = D2outRequiredPointPositionValue.Initial;

                return FSciPRecieveAndReportTimeoutBehaviour.RecievingCommandsAndReportingTimeout.Waiting_ReportingPointTimeout.New();
            }
        }

        // Do not transition
        return _state;
    }


    public D2outRequiredPointPositionValue D2outRequiredPointPosition { get; set; }
    public D50inPdiConnectionStateValue D50inPdiConnectionState { get; set; }
    public D5inObservedPointPositionValue D5inObservedPointPosition { get; set; }
    public bool D35inPm1DriveStop { get; set; }
    public bool D35inPm1nDriveStop { get; set; }
    public bool D35inPm2DriveStop { get; set; }
    public bool D35inPm2nDriveStop { get; set; }
    public bool D36inPm1nActivation { get; set; }
    public bool D37inPm2Activation { get; set; }
    public bool D38inPm2nActivation { get; set; }
    public D34outPm1ConActiveValue D34outPm1ConActive { get; set; }
    public D44outPm1ConDriveCapabilityValue D44outPm1ConDriveCapability { get; set; }
    public bool D28inConTmaxPointOperation { get; set; }
    public bool P10inout { get; set; }
    public bool D40inPm1MsgPmTimeout { get; set; }
    public bool D40inPm1nMsgPmTimeout { get; set; }
    public bool D40inPm2MsgPmTimeout { get; set; }
    public bool D40inPm2nMsgPmTimeout { get; set; }
    public D41outMsgTimeoutValue D41outMsgTimeout { get; set; }


    public enum D2outRequiredPointPositionValue
    {
        Uncommanded,
        Right,
        Left,
        Initial
    }

    public enum D50inPdiConnectionStateValue
    {
        NotReadyForPdiNoScp,
        ReadyForPdiNoScp,
        NotReadyForPdi,
        ReadyForPdi,
        Suspended,
        Established
    }

    public enum D5inObservedPointPositionValue
    {
        Left,
        Right
    }








    public enum D34outPm1ConActiveValue
    {
        True
    }

    public enum D44outPm1ConDriveCapabilityValue
    {
        True
    }







    public enum D41outMsgTimeoutValue
    {
        True
    }
}
