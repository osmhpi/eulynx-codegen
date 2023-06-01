namespace Eulynx;


public enum ResetReason
{
    ProtocolError,
    FormalTelegramError,
    ContentTelegramError
}

public enum AbilityToMoveState
{
    AbleToMove,
    UnableToMove
}

public enum PointPositionDegradedState
{
    DegradedLeft,
    DegradedRight,
    NotDegraded,
    NotApplicable
}

public enum PointPositionState
{
    Left,
    Right,
    NoEndPosition,
    Trailed
}
