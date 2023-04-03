namespace Eulynx;

class FControlPointMachinePosition
{
  public string D2inRequiredPointPosition { get; set; }
  public string D35outDriveStop { get; set; }
  public string D21outMoveLeft { get; set; }
  public string D22outMoveRight { get; set; }
  public string D29inConUseRedrive { get; set; }
  public string D51inEstEfesState { get; set; }
  public string D10inPmPosition { get; set; }
  public string MemLastCommandedPointPosition { get; set; }
  public string D34inConActive { get; set; }
  public string D44inConDriveCapability { get; set; }
  public string D6inObservedAbilityToMovePoint { get; set; }
  public string D39inConTmaxPmOperation { get; set; }
  public string D40outMsgPmTimeout { get; set; }
  public string D41inObservedPointEndPosition { get; set; }

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

      public static new Operating New() =>
        Operating.Waiting.New();

      private Operating() { }
    }


    public static new FControlPointMachinePositionBehaviour New() =>
      FControlPointMachinePositionBehaviour.Operating.New();

    private FControlPointMachinePositionBehaviour() { }
  }


  private FControlPointMachinePositionBehaviour _state;

  public FControlPointMachinePosition()
  {
    _state = FControlPointMachinePositionBehaviour.New();
  }

  private bool IsTimeoutExpired(string timeout)
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
    if (D51inEstEfesState == "NO_OPERATING_VOLTAGE" || D51inEstEfesState == "BOOTING" || D51inEstEfesState == "FALLBACK_MODE")
    {


      MemLastCommandedPointPosition = "UNDEFINED";
      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      return FControlPointMachinePositionBehaviour.Operating.New();
    }
    if (IsTimeoutExpired(D39inConTmaxPmOperation))
    {
      D35outDriveStop = "FALSE";
      D40outMsgPmTimeout = "TRUE";
      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      D35outDriveStop = "TRUE";
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D10inPmPosition == MemLastCommandedPointPosition)
    {
      D35outDriveStop = "FALSE";

      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      D35outDriveStop = "TRUE";
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D2inRequiredPointPosition == "RIGHT" && (D2inRequiredPointPosition != D10inPmPosition))
    {

      D21outMoveLeft = "FALSE";
      MemLastCommandedPointPosition = "RIGHT";
      D22outMoveRight = "TRUE";
      D40outMsgPmTimeout = "FALSE";
      return FControlPointMachinePositionBehaviour.Operating.MovingRight.New();
    }
    if (D2inRequiredPointPosition == "UNCOMMANDED")
    {
      D35outDriveStop = "FALSE";

      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      D35outDriveStop = "TRUE";
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D2inRequiredPointPosition == D10inPmPosition)
    {
      D35outDriveStop = "FALSE";
      MemLastCommandedPointPosition = "RIGHT";
      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      D35outDriveStop = "TRUE";
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D6inObservedAbilityToMovePoint == "UNABLE_TO_MOVE")
    {
      D35outDriveStop = "FALSE";

      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      D35outDriveStop = "TRUE";
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }

    // Do not transition
    return _state;
  }

  private FControlPointMachinePositionBehaviour TransitionFromMovingRight()
  {
    if (D51inEstEfesState == "NO_OPERATING_VOLTAGE" || D51inEstEfesState == "BOOTING" || D51inEstEfesState == "FALLBACK_MODE")
    {


      MemLastCommandedPointPosition = "UNDEFINED";
      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      return FControlPointMachinePositionBehaviour.Operating.New();
    }
    if (IsTimeoutExpired(D39inConTmaxPmOperation))
    {
      D35outDriveStop = "FALSE";
      D40outMsgPmTimeout = "TRUE";
      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      D35outDriveStop = "TRUE";
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D10inPmPosition == MemLastCommandedPointPosition)
    {
      D35outDriveStop = "FALSE";

      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      D35outDriveStop = "TRUE";
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D2inRequiredPointPosition == "LEFT" && (D2inRequiredPointPosition != D10inPmPosition))
    {

      D22outMoveRight = "FALSE";
      MemLastCommandedPointPosition = "LEFT";
      D21outMoveLeft = "TRUE";
      D40outMsgPmTimeout = "FALSE";
      return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New();
    }
    if (D2inRequiredPointPosition == "UNCOMMANDED")
    {
      D35outDriveStop = "FALSE";

      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      D35outDriveStop = "TRUE";
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D2inRequiredPointPosition == D10inPmPosition)
    {
      D35outDriveStop = "FALSE";
      MemLastCommandedPointPosition = "LEFT";
      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      D35outDriveStop = "TRUE";
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }
    if (D6inObservedAbilityToMovePoint == "UNABLE_TO_MOVE")
    {
      D35outDriveStop = "FALSE";

      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      D35outDriveStop = "TRUE";
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }

    // Do not transition
    return _state;
  }

  private FControlPointMachinePositionBehaviour TransitionFromStopped()
  {
    if (D51inEstEfesState == "NO_OPERATING_VOLTAGE" || D51inEstEfesState == "BOOTING" || D51inEstEfesState == "FALLBACK_MODE")
    {


      MemLastCommandedPointPosition = "UNDEFINED";
      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      return FControlPointMachinePositionBehaviour.Operating.New();
    }
    if (D10inPmPosition == "NO_END_POSITION")
    {


      D22outMoveRight = "TRUE";
      D40outMsgPmTimeout = "FALSE";
      return FControlPointMachinePositionBehaviour.Operating.MovingRight.New();
    }
    if (D10inPmPosition == "NO_END_POSITION")
    {


      D21outMoveLeft = "TRUE";
      D40outMsgPmTimeout = "FALSE";
      return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New();
    }
    if (D2inRequiredPointPosition == "LEFT")
    {
      if (D2inRequiredPointPosition != D10inPmPosition && D6inObservedAbilityToMovePoint == "ABLE_TO_MOVE")
      {


        D21outMoveLeft = "TRUE";
        D40outMsgPmTimeout = "FALSE";
        return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New();
      }
      else
      {
        D35outDriveStop = "FALSE";

        D21outMoveLeft = "FALSE";
        D22outMoveRight = "FALSE";
        D35outDriveStop = "TRUE";
        return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
      }
    }
    if (D2inRequiredPointPosition == "RIGHT")
    {
      if (D2inRequiredPointPosition != D10inPmPosition && D6inObservedAbilityToMovePoint == "ABLE_TO_MOVE")
      {


        D22outMoveRight = "TRUE";
        D40outMsgPmTimeout = "FALSE";
        return FControlPointMachinePositionBehaviour.Operating.MovingRight.New();
      }
      else
      {
        D35outDriveStop = "FALSE";

        D21outMoveLeft = "FALSE";
        D22outMoveRight = "FALSE";
        D35outDriveStop = "TRUE";
        return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
      }
    }

    // Do not transition
    return _state;
  }

  private FControlPointMachinePositionBehaviour TransitionFromWaiting()
  {
    if (D51inEstEfesState == "NO_OPERATING_VOLTAGE" || D51inEstEfesState == "BOOTING" || D51inEstEfesState == "FALLBACK_MODE")
    {


      MemLastCommandedPointPosition = "UNDEFINED";
      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      return FControlPointMachinePositionBehaviour.Operating.New();
    }
    if (D51inEstEfesState == "INITIALISING")
    {
      D35outDriveStop = "FALSE";

      D21outMoveLeft = "FALSE";
      D22outMoveRight = "FALSE";
      D35outDriveStop = "TRUE";
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
    }

    // Do not transition
    return _state;
  }

}
