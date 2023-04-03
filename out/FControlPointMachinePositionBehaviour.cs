using System;
using System.Text;
using System.Linq;

namespace Eulynx;

class FControlPointMachinePosition {
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

public record FControlPointMachinePositionBehaviour : object {
    public record Operating : FControlPointMachinePositionBehaviour {
    public record MovingLeft() : Operating() {
        public static new MovingLeft New() => new MovingLeft();
      }
    public record MovingRight() : Operating() {
        public static new MovingRight New() => new MovingRight();
      }
    public record Stopped() : Operating() {
        public static new Stopped New() => new Stopped();
      }
    public record Waiting() : Operating() {
        public static new Waiting New() => new Waiting();
      }

    public static new Operating New() =>
      Operating.Operating.Waiting.New();

    private Operating() {}
}


    public static new FControlPointMachinePositionBehaviour New() =>
      FControlPointMachinePositionBehaviour.FControlPointMachinePositionBehaviour.Operating.New();

    private FControlPointMachinePositionBehaviour() {}
}


    private FControlPointMachinePositionBehaviour _state;

    public void Transition() {
        _state = _state switch {
FControlPointMachinePositionBehaviour.Operating.MovingLeft => TransitionFromMovingLeft(),
FControlPointMachinePositionBehaviour.Operating.MovingRight => TransitionFromMovingRight(),
FControlPointMachinePositionBehaviour.Operating.Stopped => TransitionFromStopped(),
FControlPointMachinePositionBehaviour.Operating.Waiting => TransitionFromWaiting()
      };
    }

private FControlPointMachinePositionBehaviour TransitionFromMovingLeft() {
      if (D51inEstEfesState == "NO_OPERATING_VOLTAGE" || d51in_EST_EfeS_State == "BOOTING" || d51in_EST_EfeS_State == "FALLBACK_MODE") {
      return FControlPointMachinePositionBehaviour.Operating.New();
     }
if (D10inPmPosition == MemLastCommandedPointPosition) {
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
     }
if (D2inRequiredPointPosition == "RIGHT" && (d2in_Required_Point_Position != D10in_PM_Position)) {
      return FControlPointMachinePositionBehaviour.Operating.MovingRight.New();
     }
if (D2inRequiredPointPosition == "UNCOMMANDED") {
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
     }
if (D2inRequiredPointPosition == D10inPmPosition) {
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
     }
if (D6inObservedAbilityToMovePoint == "UNABLE_TO_MOVE") {
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
     }

      // Do not transition
      return _state;
    }

private FControlPointMachinePositionBehaviour TransitionFromMovingRight() {
      if (D51inEstEfesState == "NO_OPERATING_VOLTAGE" || d51in_EST_EfeS_State == "BOOTING" || d51in_EST_EfeS_State == "FALLBACK_MODE") {
      return FControlPointMachinePositionBehaviour.Operating.New();
     }
if (D10inPmPosition == MemLastCommandedPointPosition) {
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
     }
if (D2inRequiredPointPosition == "LEFT" && (d2in_Required_Point_Position != D10in_PM_Position)) {
      return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New();
     }
if (D2inRequiredPointPosition == "UNCOMMANDED") {
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
     }
if (D2inRequiredPointPosition == D10inPmPosition) {
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
     }
if (D6inObservedAbilityToMovePoint == "UNABLE_TO_MOVE") {
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
     }

      // Do not transition
      return _state;
    }

private FControlPointMachinePositionBehaviour TransitionFromStopped() {
      if (D51inEstEfesState == "NO_OPERATING_VOLTAGE" || d51in_EST_EfeS_State == "BOOTING" || d51in_EST_EfeS_State == "FALLBACK_MODE") {
      return FControlPointMachinePositionBehaviour.Operating.New();
     }
if (D10inPmPosition == "NO_END_POSITION" ) {
      return FControlPointMachinePositionBehaviour.Operating.MovingRight.New();
     }
if (D10inPmPosition == "NO_END_POSITION" ) {
      return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New();
     }
if (D2inRequiredPointPosition == "LEFT" ) {
      return FControlPointMachinePositionBehaviour.Operating.Junction1.New();
     }
if (D2inRequiredPointPosition == "RIGHT") {
      return FControlPointMachinePositionBehaviour.Operating.Junction2.New();
     }

      // Do not transition
      return _state;
    }

private FControlPointMachinePositionBehaviour TransitionFromWaiting() {
      if (D51inEstEfesState == "NO_OPERATING_VOLTAGE" || d51in_EST_EfeS_State == "BOOTING" || d51in_EST_EfeS_State == "FALLBACK_MODE") {
      return FControlPointMachinePositionBehaviour.Operating.New();
     }
if (D51inEstEfesState == "INITIALISING") {
      return FControlPointMachinePositionBehaviour.Operating.Stopped.New();
     }

      // Do not transition
      return _state;
    }

}
