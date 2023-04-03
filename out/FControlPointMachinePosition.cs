namespace Eulynx;

class FControlPointMachinePosition
{
  public record FControlPointMachinePositionBehaviour : object
  {
    public record Operating : FControlPointMachinePositionBehaviour
    {
      public record MovingLeft() : Operating()
      {
        public static new MovingLeft New() => new MovingLeft();
      }
      public record MovingRight() : Operating()
      {
        public static new MovingRight New() => new MovingRight();
      }
      public record Stopped() : Operating()
      {
        public static new Stopped New() => new Stopped();
      }
      public record Waiting() : Operating()
      {
        public static new Waiting New() => new Waiting();
      }

      public static new Operating New() => Operating.Waiting.New();

      private Operating() { }
    }


    public static new FControlPointMachinePositionBehaviour New() => FControlPointMachinePositionBehaviour.Operating.New();

    private FControlPointMachinePositionBehaviour() { }
  }


  private FControlPointMachinePositionBehaviour _state;

  public FControlPointMachinePosition()
  {
    MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
    D21outMoveLeft = D21outMoveLeftValue.False;
    D22outMoveRight = D22outMoveRightValue.False;
    _state = FControlPointMachinePositionBehaviour.New();
  }

  private bool IsTimeoutExpired(object timeout)
  {
    // TODO
    return false;
  }

  public void Transition()
  {
    _state = _state switch
    {
      FControlPointMachinePositionBehaviour.Operating.MovingLeft => TransitionFromMovingLeft(),
      FControlPointMachinePositionBehaviour.Operating.MovingRight => TransitionFromMovingRight(),
      FControlPointMachinePositionBehaviour.Operating.Stopped => TransitionFromStopped(),
      FControlPointMachinePositionBehaviour.Operating.Waiting => TransitionFromWaiting()
    };
  }

  private FControlPointMachinePositionBehaviour TransitionFromMovingLeft()
  {
    if (D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode)
    {


      MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      return FControlPointMachinePositionBehaviour.Operating.New();
    }
    if (IsTimeoutExpired(D39inConTmaxPmOperation))
    {
      D35outDriveStop = D35outDriveStopValue.False;
      D40outMsgPmTimeout = D40outMsgPmTimeoutValue.True;
      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      D35outDriveStop = D35outDriveStopValue.True;
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D10inPmPosition == MemLastCommandedPointPosition)
    {
      D35outDriveStop = D35outDriveStopValue.False;

      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      D35outDriveStop = D35outDriveStopValue.True;
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Right && (D2inRequiredPointPosition != D10inPmPosition))
    {

      D21outMoveLeft = D21outMoveLeftValue.False;
      MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Right;
      D22outMoveRight = D22outMoveRightValue.True;
      D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;
      return FControlPointMachinePositionBehaviour.Operating.MovingRight.New();
    }
    if (D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Uncommanded)
    {
      D35outDriveStop = D35outDriveStopValue.False;

      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      D35outDriveStop = D35outDriveStopValue.True;
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D2inRequiredPointPosition == D10inPmPosition)
    {
      D35outDriveStop = D35outDriveStopValue.False;
      MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Right;
      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      D35outDriveStop = D35outDriveStopValue.True;
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove)
    {
      D35outDriveStop = D35outDriveStopValue.False;

      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      D35outDriveStop = D35outDriveStopValue.True;
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }

    // Do not transition
    return _state;
  }

  private FControlPointMachinePositionBehaviour TransitionFromMovingRight()
  {
    if (D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode)
    {


      MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      return FControlPointMachinePositionBehaviour.Operating.New();
    }
    if (IsTimeoutExpired(D39inConTmaxPmOperation))
    {
      D35outDriveStop = D35outDriveStopValue.False;
      D40outMsgPmTimeout = D40outMsgPmTimeoutValue.True;
      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      D35outDriveStop = D35outDriveStopValue.True;
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D10inPmPosition == MemLastCommandedPointPosition)
    {
      D35outDriveStop = D35outDriveStopValue.False;

      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      D35outDriveStop = D35outDriveStopValue.True;
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Left && (D2inRequiredPointPosition != D10inPmPosition))
    {

      D22outMoveRight = D22outMoveRightValue.False;
      MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Left;
      D21outMoveLeft = D21outMoveLeftValue.True;
      D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;
      return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New();
    }
    if (D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Uncommanded)
    {
      D35outDriveStop = D35outDriveStopValue.False;

      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      D35outDriveStop = D35outDriveStopValue.True;
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D2inRequiredPointPosition == D10inPmPosition)
    {
      D35outDriveStop = D35outDriveStopValue.False;
      MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Left;
      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      D35outDriveStop = D35outDriveStopValue.True;
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove)
    {
      D35outDriveStop = D35outDriveStopValue.False;

      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      D35outDriveStop = D35outDriveStopValue.True;
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }

    // Do not transition
    return _state;
  }

  private FControlPointMachinePositionBehaviour TransitionFromStopped()
  {
    if (D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode)
    {


      MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      return FControlPointMachinePositionBehaviour.Operating.New();
    }
    if (D10inPmPosition == MemLastCommandedPointPositionValue.NoEndPosition)
    {


      D22outMoveRight = D22outMoveRightValue.True;
      D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;
      return FControlPointMachinePositionBehaviour.Operating.MovingRight.New();
    }
    if (D10inPmPosition == MemLastCommandedPointPositionValue.NoEndPosition)
    {


      D21outMoveLeft = D21outMoveLeftValue.True;
      D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;
      return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New();
    }
    if (D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Left)
    {
      if (D2inRequiredPointPosition != D10inPmPosition && D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.AbleToMove)
      {


        D21outMoveLeft = D21outMoveLeftValue.True;
        D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;
        return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New();
      }
      else
      {
        D35outDriveStop = D35outDriveStopValue.False;

        D21outMoveLeft = D21outMoveLeftValue.False;
        D22outMoveRight = D22outMoveRightValue.False;
        D35outDriveStop = D35outDriveStopValue.True;
        return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
      }
    }
    if (D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Right)
    {
      if (D2inRequiredPointPosition != D10inPmPosition && D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.AbleToMove)
      {


        D22outMoveRight = D22outMoveRightValue.True;
        D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;
        return FControlPointMachinePositionBehaviour.Operating.MovingRight.New();
      }
      else
      {
        D35outDriveStop = D35outDriveStopValue.False;

        D21outMoveLeft = D21outMoveLeftValue.False;
        D22outMoveRight = D22outMoveRightValue.False;
        D35outDriveStop = D35outDriveStopValue.True;
        return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
      }
    }

    // Do not transition
    return _state;
  }

  private FControlPointMachinePositionBehaviour TransitionFromWaiting()
  {
    if (D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode)
    {


      MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      return FControlPointMachinePositionBehaviour.Operating.New();
    }
    if (D51inEstEfesState == D51inEstEfesStateValue.Initialising)
    {
      D35outDriveStop = D35outDriveStopValue.False;

      D21outMoveLeft = D21outMoveLeftValue.False;
      D22outMoveRight = D22outMoveRightValue.False;
      D35outDriveStop = D35outDriveStopValue.True;
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }

    // Do not transition
    return _state;
  }


  public MemLastCommandedPointPositionValue D2inRequiredPointPosition { get; set; }
  public D35outDriveStopValue D35outDriveStop { get; set; }
  public D21outMoveLeftValue D21outMoveLeft { get; set; }
  public D22outMoveRightValue D22outMoveRight { get; set; }
  public D29inConUseRedriveValue D29inConUseRedrive { get; set; }
  public D51inEstEfesStateValue D51inEstEfesState { get; set; }
  public MemLastCommandedPointPositionValue D10inPmPosition { get; set; }
  public MemLastCommandedPointPositionValue MemLastCommandedPointPosition { get; set; }
  public D34inConActiveValue D34inConActive { get; set; }
  public D44inConDriveCapabilityValue D44inConDriveCapability { get; set; }
  public D6inObservedAbilityToMovePointValue D6inObservedAbilityToMovePoint { get; set; }
  public D39inConTmaxPmOperationValue D39inConTmaxPmOperation { get; set; }
  public D40outMsgPmTimeoutValue D40outMsgPmTimeout { get; set; }
  public D41inObservedPointEndPositionValue D41inObservedPointEndPosition { get; set; }


  public enum D2inRequiredPointPositionValue
  {
    Undefined,
    Right,
    Left,
    NoEndPosition,
    Uncommanded
  }

  public enum D35outDriveStopValue
  {
    False,
    True
  }

  public enum D21outMoveLeftValue
  {
    False,
    True
  }

  public enum D22outMoveRightValue
  {
    False,
    True
  }

  public enum D29inConUseRedriveValue
  {

  }

  public enum D51inEstEfesStateValue
  {
    NoOperatingVoltage,
    Booting,
    FallbackMode,
    Initialising
  }

  public enum D10inPmPositionValue
  {
    Undefined,
    Right,
    Left,
    NoEndPosition,
    Uncommanded
  }

  public enum MemLastCommandedPointPositionValue
  {
    Undefined,
    Right,
    Left,
    NoEndPosition,
    Uncommanded
  }

  public enum D34inConActiveValue
  {

  }

  public enum D44inConDriveCapabilityValue
  {

  }

  public enum D6inObservedAbilityToMovePointValue
  {
    UnableToMove,
    AbleToMove
  }

  public enum D39inConTmaxPmOperationValue
  {

  }

  public enum D40outMsgPmTimeoutValue
  {
    True,
    False
  }

  public enum D41inObservedPointEndPositionValue
  {

  }
}
