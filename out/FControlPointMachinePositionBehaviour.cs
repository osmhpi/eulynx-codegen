using System;
using System.Text;
using System.Linq;

namespace Eulynx;

record FControlPointMachinePositionBehaviour
{
  record Operating
  {
    private record MovingLeft() : Operating();
    private record MovingRight() : Operating();
    private record Stopped() : Operating();
    private record Waiting() : Operating();

    public Operating New() =>
      Operating.Waiting();

    private Operating() { }

    public Operating Transition()
    {
      return this switch
      {
        MovingLeft => TransitionFromMovingLeft(),
        MovingRight => TransitionFromMovingRight(),
        Stopped => TransitionFromStopped(),
        Waiting => TransitionFromWaiting()
      };
    }
  }

  private Operating TransitionFromMovingLeft()
  {
    if (D10in_PM_Position == Mem_Last_Commanded_Point_Position)
    {
      return Stopped();
    }
    if (d2in_Required_Point_Position == "RIGHT" && (d2in_Required_Point_Position != D10in_PM_Position))
    {
      return MovingRight();
    }
    if (d2in_Required_Point_Position == "UNCOMMANDED")
    {
      return Stopped();
    }
    if (d2in_Required_Point_Position == D10in_PM_Position)
    {
      return Stopped();
    }
    if (d6in_Observed_Ability_To_Move_Point == "UNABLE_TO_MOVE")
    {
      return Stopped();
    }

    // Do not transition
    return this;
  }

  private Operating TransitionFromMovingRight()
  {
    if (D10in_PM_Position == Mem_Last_Commanded_Point_Position)
    {
      return Stopped();
    }
    if (d2in_Required_Point_Position == "LEFT" && (d2in_Required_Point_Position != D10in_PM_Position))
    {
      return MovingLeft();
    }
    if (d2in_Required_Point_Position == "UNCOMMANDED")
    {
      return Stopped();
    }
    if (d2in_Required_Point_Position == D10in_PM_Position)
    {
      return Stopped();
    }
    if (d6in_Observed_Ability_To_Move_Point == "UNABLE_TO_MOVE")
    {
      return Stopped();
    }

    // Do not transition
    return this;
  }

  private Operating TransitionFromStopped()
  {
    if (D10in_PM_Position == "NO_END_POSITION")
    {
      return MovingRight();
    }
    if (D10in_PM_Position == "NO_END_POSITION")
    {
      return MovingLeft();
    }
    if (d2in_Required_Point_Position == "LEFT")
    {
      return Junction1();
    }
    if (d2in_Required_Point_Position == "RIGHT")
    {
      return Junction2();
    }

    // Do not transition
    return this;
  }

  private Operating TransitionFromWaiting()
  {
    if (d51in_EST_EfeS_State == "INITIALISING")
    {
      return Stopped();
    }

    // Do not transition
    return this;
  }



  public FControlPointMachinePositionBehaviour New() =>
    FControlPointMachinePositionBehaviour.Operating();

  private FControlPointMachinePositionBehaviour() { }

  public FControlPointMachinePositionBehaviour Transition()
  {
    return this switch
    {
      Operating => TransitionFromOperating()
    };
  }
}

private FControlPointMachinePositionBehaviour TransitionFromOperating()
{
  if (d51in_EST_EfeS_State == "NO_OPERATING_VOLTAGE" || d51in_EST_EfeS_State == "BOOTING" || d51in_EST_EfeS_State == "FALLBACK_MODE")
  {
    return Operating();
  }

  // Do not transition
  return this;
}


