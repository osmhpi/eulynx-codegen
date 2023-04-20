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


    private SSciPCommandAndRecieveBehaviour _state;
    public SSciPCommandAndRecieveBehaviour State { get { return _state; } }

    public SSciPCommandAndRecieve()
    {

        _state = SSciPCommandAndRecieveBehaviour.New();
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
            SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport => TransitionFromSSciPCommandAndRecieveBehaviour__Operating__SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport()
        };
    }

    private SSciPCommandAndRecieveBehaviour TransitionFromSSciPCommandAndRecieveBehaviour__Operating__SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport()
    {
        if (IsConditionChanged(T30inMovePoint))
        {
            if (D30inMovePoint == D30inMovePointValue.Right && D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {
                SendMessage("CdMovePoint (Right)", "P10inout");

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsConditionChanged(T30inMovePoint))
        {
            if (D30inMovePoint == D30inMovePointValue.Left && D50inPdiConnectionState == D50inPdiConnectionStateValue.Established)
            {
                SendMessage("CdMovePoint (Left) ", "P10inout");

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Left  && ReportedDegradedPointPosition == NotApplicable]"))
            {
                D32outPointPosition = D32outPointPositionValue.LeftAndNotApplicable;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Left  && ReportedDegradedPointPosition == NotDegraded]"))
            {
                D32outPointPosition = D32outPointPositionValue.LeftAndNotDegraded;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Right  && ReportedDegradedPointPosition == NotApplicable]"))
            {
                D32outPointPosition = D32outPointPositionValue.RightAndNotApplicable;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Right  && ReportedDegradedPointPosition == NotDegraded]"))
            {
                D32outPointPosition = D32outPointPositionValue.RightAndNotDegraded;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == NoEndPosition  && ReportedDegradedPointPosition == DegradedLeft]"))
            {
                D32outPointPosition = D32outPointPositionValue.NoEndPositionAndDegradedLeft;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == NoEndPosition  && ReportedDegradedPointPosition == DegradedRight]"))
            {
                D32outPointPosition = D32outPointPositionValue.NoEndPositionAndDegradedRight;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == NoEndPosition  && ReportedDegradedPointPosition == NotDegraded]"))
            {
                D32outPointPosition = D32outPointPositionValue.NoEndPositionAndNotDegraded;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == NoEndPosition  && ReportedDegradedPointPosition == NotApplicable]"))
            {
                D32outPointPosition = D32outPointPositionValue.NoEndPositionAndNotApplicable;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Trailed  && ReportedDegradedPointPosition == DegradedLeft]"))
            {
                D32outPointPosition = D32outPointPositionValue.TrailedAndDegradedLeft;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Trailed  && ReportedDegradedPointPosition == DegradedRight]"))
            {
                D32outPointPosition = D32outPointPositionValue.TrailedAndDegradedRight;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Trailed  && ReportedDegradedPointPosition == NotDegraded]"))
            {
                D32outPointPosition = D32outPointPositionValue.TrailedAndNotDegraded;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Point_Position"))
        {
            if (ReceivedMessage("Msg_Point_Position[ReportedPointPositionState == Trailed  && ReportedDegradedPointPosition == NotApplicable]"))
            {
                D32outPointPosition = D32outPointPositionValue.TrailedAndNotApplicable;
                T32outPointPosition = T32outPointPositionValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Ability_To_Move_Point"))
        {
            if (ReceivedMessage("Msg_Ability_To_Move_Point[ReportedAbilityToMoveState == UnableToMove]"))
            {
                D33outAbilityToMove = D33outAbilityToMoveValue.UnableToMove;
                T33outAbilityToMove = T33outAbilityToMoveValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Ability_To_Move_Point"))
        {
            if (ReceivedMessage("Msg_Ability_To_Move_Point[ReportedAbilityToMoveState == AbleToMove]"))
            {
                D33outAbilityToMove = D33outAbilityToMoveValue.AbleToMove;
                T33outAbilityToMove = T33outAbilityToMoveValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }
        if (IsMessageArrived("Msg_Timeout"))
        {
            {
                T31outTimeout = T31outTimeoutValue.True;

                return SSciPCommandAndRecieveBehaviour.Operating.SendingCommands_RecieveOverallPointPositionAndDegradedPointPositionReport_RecieveAbilityToMoveReport_RecieveTimeOutReport.New();
            }
        }

        // Do not transition
        return _state;
    }


    // Properties


    // Ports
    public D30inMovePointValue D30inMovePoint { get; set; }
    public T31outTimeoutValue T31outTimeout { get; set; }
    public D32outPointPositionValue D32outPointPosition { get; set; }
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




    public enum T32outPointPositionValue
    {
        True
    }

    public enum T33outAbilityToMoveValue
    {
        True
    }
}
