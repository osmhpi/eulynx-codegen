namespace Eulynx;

public class FSciPReport
{
    public record FSciPReportBehaviour : object
    {
        public record ReportingOverallPointStates : FSciPReportBehaviour
        {
            public record MsgAbilityToMove_MsgOverallPointPosition() : ReportingOverallPointStates()
            {
                public static new MsgAbilityToMove_MsgOverallPointPosition New() => new MsgAbilityToMove_MsgOverallPointPosition();
            }
            public record MsgAbilityToMove_Waiting() : ReportingOverallPointStates()
            {
                public static new MsgAbilityToMove_Waiting New() => new MsgAbilityToMove_Waiting();
            }

            public static new ReportingOverallPointStates New() => ReportingOverallPointStates.MsgAbilityToMove_Waiting.New();

            private ReportingOverallPointStates() { }
        }

        public record InterfaceConnectionNotEstablished() : FSciPReportBehaviour()
        {
            public static new InterfaceConnectionNotEstablished New() => new InterfaceConnectionNotEstablished();
        }

        public static new FSciPReportBehaviour New() => FSciPReportBehaviour.InterfaceConnectionNotEstablished.New();

        private FSciPReportBehaviour() { }
    }


    private FSciPReport _state;
    public FSciPReport State { get { return _state; } }

    public FSciPReport()
    {

        _state = FSciPReport.New();
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
            FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_MsgOverallPointPosition => TransitionFromMsgabilitytomoveMsgoverallpointposition(),
            FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_Waiting => TransitionFromMsgabilitytomoveWaiting()
        };
    }

    private FSciPReportBehaviour TransitionFromMsgAbilityToMove_MsgOverallPointPosition()
    {
        if (IsConditionChanged(D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.Suspended))
        {
            {



                return FSciPReportBehaviour.InterfaceConnectionNotEstablished.New();
            }
        }
        if (IsConditionChanged(D6inObservedAbilityToMove == D6inObservedAbilityToMoveValue.AbleToMove))
        {
            if (D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                Send MsgAbilityToMovePoint(Abletomove) To P11out;

                Send MsgPointPosition(Cop1PointPosition, Cop2DegradedPointPosition) To P11out;
                MemLastReportedPointPosition = D5inObservedPointPosition;
                MemLastReportedDegradedPointPosition = D4inObservedDegradedPointPosition;
                return FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_MsgOverallPointPosition.New();
            }
        }
        if (IsConditionChanged(D6inObservedAbilityToMove == D6inObservedAbilityToMoveValue.UnableToMove))
        {
            if (D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                Send MsgAbilityToMovePoint(Unabletomove) To P11out;

                Send MsgPointPosition(Cop1PointPosition, Cop2DegradedPointPosition) To P11out;
                MemLastReportedPointPosition = D5inObservedPointPosition;
                MemLastReportedDegradedPointPosition = D4inObservedDegradedPointPosition;
                return FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_MsgOverallPointPosition.New();
            }
        }
        if (IsConditionChanged((D4inObservedDegradedPointPosition != MemLastReportedDegradedPointPosition)))
        {
            if (D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {




                Send MsgPointPosition(Cop1PointPosition, Cop2DegradedPointPosition) To P11out;
                MemLastReportedPointPosition = D5inObservedPointPosition;
                MemLastReportedDegradedPointPosition = D4inObservedDegradedPointPosition;
                return FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_MsgOverallPointPosition.New();
            }
        }
        if (IsConditionChanged((D5inObservedPointPosition != MemLastReportedPointPosition)))
        {
            if (D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {




                Send MsgPointPosition(Cop1PointPosition, Cop2DegradedPointPosition) To P11out;
                MemLastReportedPointPosition = D5inObservedPointPosition;
                MemLastReportedDegradedPointPosition = D4inObservedDegradedPointPosition;
                return FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_MsgOverallPointPosition.New();
            }
        }

        // Do not transition
        return _state;
    }

    private FSciPReportBehaviour TransitionFromMsgAbilityToMove_Waiting()
    {
        if (IsConditionChanged(D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdiNoScp || D50inPdiConnectionState == D50inPdiConnectionStateValue.NotReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.ReadyForPdi || D50inPdiConnectionState == D50inPdiConnectionStateValue.Suspended))
        {
            {



                return FSciPReportBehaviour.InterfaceConnectionNotEstablished.New();
            }
        }
        if (IsConditionChanged(D6inObservedAbilityToMove == D6inObservedAbilityToMoveValue.AbleToMove))
        {
            if (D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                Send MsgAbilityToMovePoint(Abletomove) To P11out;


                return FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_Waiting.New();
            }
        }
        if (IsConditionChanged(D6inObservedAbilityToMove == D6inObservedAbilityToMoveValue.UnableToMove))
        {
            if (D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {



                Send MsgAbilityToMovePoint(Unabletomove) To P11out;


                return FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_Waiting.New();
            }
        }
        if (IsConditionChanged(D4inObservedDegradedPointPosition != MemLastReportedDegradedPointPosition))
        {
            if (D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {




                Send MsgPointPosition(Cop1PointPosition, Cop2DegradedPointPosition) To P11out;
                MemLastReportedPointPosition = D5inObservedPointPosition;
                MemLastReportedDegradedPointPosition = D4inObservedDegradedPointPosition;
                return FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_MsgOverallPointPosition.New();
            }
        }
        if (IsConditionChanged(D5inObservedPointPosition != MemLastReportedPointPosition))
        {
            if (D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {




                Send MsgPointPosition(Cop1PointPosition, Cop2DegradedPointPosition) To P11out;
                MemLastReportedPointPosition = D5inObservedPointPosition;
                MemLastReportedDegradedPointPosition = D4inObservedDegradedPointPosition;
                return FSciPReportBehaviour.ReportingOverallPointStates.MsgAbilityToMove_MsgOverallPointPosition.New();
            }
        }

        // Do not transition
        return _state;
    }


    public D50inPdiConnectionStateValue D50inPdiConnectionState { get; set; }
    public bool D5inObservedPointPosition { get; set; }
    public D6inObservedAbilityToMoveValue D6inObservedAbilityToMove { get; set; }
    public bool P11out { get; set; }
    public bool D4inObservedDegradedPointPosition { get; set; }
    public bool MemLastReportedPointPosition { get; set; }
    public bool MemLastReportedDegradedPointPosition { get; set; }
    public bool P3inout { get; set; }


    public enum D50inPdiConnectionStateValue
    {
        NotReadyForPdiNoScp,
        ReadyForPdiNoScp,
        NotReadyForPdi,
        ReadyForPdi,
        Suspended,
        Established
    }


    public enum D6inObservedAbilityToMoveValue
    {
        AbleToMove,
        UnableToMove
    }





}
