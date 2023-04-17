namespace Eulynx;

public class SSciPCommandAndRecieve
{
    public record SSciPCommandAndRecieveBehaviour : object
    {
        public record Operating : SSciPCommandAndRecieveBehaviour
        {
            public record SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport() : Operating()
            {
                public static new SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport New() => new SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport();
            }

            public static new Operating New() => Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();

            private Operating() { }
        }


        public static new SSciPCommandAndRecieveBehaviour New() => SSciPCommandAndRecieveBehaviour.Operating.New();

        private SSciPCommandAndRecieveBehaviour() { }
    }


    private SSciPCommandAndRecieve _state;
    public SSciPCommandAndRecieve State { get { return _state; } }

    public SSciPCommandAndRecieve()
    {

        _state = SSciPCommandAndRecieve.New();
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
            SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport => TransitionFromSendingcommandsRecieveoverallpointpositionanddegradedpointpositionreportRecieveabilitytomovereportRecievetimeoutreport()
        };
    }

    private SSciPCommandAndRecieveBehaviour TransitionFromSendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport()
    {
        if (IsConditionChanged(T30inMovePoint))
        {
            if (D30inMovePoint == D30inMovePointValue.Right && D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {





                Send CdMovePoint(Right)To P10inout;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged(T30inMovePoint))
        {
            if (D30inMovePoint == D30inMovePointValue.Left && D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {





                Send CdMovePoint(Left) To P10inout;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Left && Reporteddegradedpointposition == Notapplicable)
            {




                D32outPointPosition = "LEFT, NOT_APPLICABLE";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Left && Reporteddegradedpointposition == Notdegraded)
            {




                D32outPointPosition = "LEFT, NOT_DEGRADED";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Right && Reporteddegradedpointposition == Notapplicable)
            {




                D32outPointPosition = "RIGHT, NOT_APPLICABLE";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Right && Reporteddegradedpointposition == Notdegraded)
            {




                D32outPointPosition = "RIGHT, NOT_DEGRADED";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Noendposition && Reporteddegradedpointposition == Degradedleft)
            {




                D32outPointPosition = "NO_END_POSITION, DEGRADED_LEFT";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Noendposition && Reporteddegradedpointposition == Degradedright)
            {




                D32outPointPosition = "NO_END_POSITION, DEGRADED_RIGHT";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Noendposition && Reporteddegradedpointposition == Notdegraded)
            {




                D32outPointPosition = "NO_END_POSITION, NOT_DEGRADED";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Noendposition && Reporteddegradedpointposition == Notapplicable)
            {




                D32outPointPosition = "NO_END_POSITION, NOT_APPLICABLE";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Trailed && Reporteddegradedpointposition == Degradedleft)
            {




                D32outPointPosition = "TRAILED, DEGRADED_LEFT";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Trailed && Reporteddegradedpointposition == Degradedright)
            {




                D32outPointPosition = "TRAILED, DEGRADED_RIGHT";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Trailed && Reporteddegradedpointposition == Notdegraded)
            {




                D32outPointPosition = "TRAILED, NOT_DEGRADED";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedpointpositionstate == Trailed && Reporteddegradedpointposition == Notapplicable)
            {




                D32outPointPosition = "TRAILED, NOT_APPLICABLE";
                T32outPointPosition = T32outPointPositionValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedabilitytomovestate == Unabletomove)
            {




                D33outAbilityToMove = D33outAbilityToMoveValue.UnableToMove;
                T33outAbilityToMove = T33outAbilityToMoveValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            if (Reportedabilitytomovestate == Abletomove)
            {




                D33outAbilityToMove = D33outAbilityToMoveValue.AbleToMove;
                T33outAbilityToMove = T33outAbilityToMoveValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged())
        {
            {




                T31outTimeout = T31outTimeoutValue.True;




                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }

        // Do not transition
        return _state;
    }


    public D30inMovePointValue D30inMovePoint { get; set; }
    public T31outTimeoutValue T31outTimeout { get; set; }
    public bool D32outPointPosition { get; set; }
    public D50inPdiConnectionStateValue D50inPdiConnectionState { get; set; }
    public D33outAbilityToMoveValue D33outAbilityToMove { get; set; }
    public bool P11in { get; set; }
    public bool T30inMovePoint { get; set; }
    public bool P10inout { get; set; }
    public T32outPointPositionValue T32outPointPosition { get; set; }
    public T33outAbilityToMoveValue T33outAbilityToMove { get; set; }


    public enum D30inMovePointValue
    {
        Right,
        Left
    }

    public enum T31outTimeoutValue
    {
        True
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




    public enum T32outPointPositionValue
    {
        True
    }

    public enum T33outAbilityToMoveValue
    {
        True
    }
}
