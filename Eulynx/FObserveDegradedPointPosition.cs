namespace Eulynx;

public class FObserveDegradedPointPosition {
    public record FObserveDegradedPointPositionBehaviour : object {
    public record ObserveDegradedPointPosition : FObserveDegradedPointPositionBehaviour {
    public record WaitingForInitialisation() : ObserveDegradedPointPosition() {
        public static new WaitingForInitialisation New() => new WaitingForInitialisation();
      }
    public record DegradedRight() : ObserveDegradedPointPosition() {
        public static new DegradedRight New() => new DegradedRight();
      }
    public record NotDegraded() : ObserveDegradedPointPosition() {
        public static new NotDegraded New() => new NotDegraded();
      }
    public record DegradedLeft() : ObserveDegradedPointPosition() {
        public static new DegradedLeft New() => new DegradedLeft();
      }
    public record DegradedDenied() : ObserveDegradedPointPosition() {
        public static new DegradedDenied New() => new DegradedDenied();
      }

    public static new ObserveDegradedPointPosition New() => Observedegradedpointposition.WaitingForInitialisation.New();

    private ObserveDegradedPointPosition() {}
}


    public static new FObserveDegradedPointPositionBehaviour New() => FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.New();

    private FObserveDegradedPointPositionBehaviour() {}
}


    private FObserveDegradedPointPositionBehaviour _state;
    public FObserveDegradedPointPositionBehaviour State { get { return _state; } }

    public FObserveDegradedPointPosition() {
      
      _state = FObserveDegradedPointPositionBehaviour.New();
    }

    private bool IsTimeoutExpired(object timeout) {
        // TODO
        return false;
    }

    private bool IsConditionChanged(bool condition) {
        // TODO: Keep in mind that this should only evaluate to true once
        return condition;
    }

    public void Transition() {
        _state = _state switch {
            FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.WaitingForInitialisation => TransitionFromWaitingForInitialisation(),
FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.DegradedRight => TransitionFromDegradedRight(),
FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.NotDegraded => TransitionFromNotDegraded(),
FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.DegradedLeft => TransitionFromDegradedLeft(),
FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.DegradedDenied => TransitionFromDegradedDenied()
      };
    }

    private FObserveDegradedPointPositionBehaviour TransitionFromWaitingForInitialisation() {
      if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode)) {
             {
                


                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.New();
            }
          }if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Initialising)) {
         {
          
D4outObservedDegradedPointPosition = D4outObservedDegradedPointPositionValue.Undefined;

          if (Not D8inConPm2NonCrucialActivation &&!D9inConPm2nNonCrucialActivation) {
                

D4outObservedDegradedPointPosition = D4outObservedDegradedPointPositionValue.DegradedDenied;
                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.DegradedDenied.New();
            }
if (D10inPm1CrucialPosition == D10inPm1nCrucialPositionValue.Left && (D10inPm1nCrucialPosition == D10inPm1nCrucialPositionValue.Left ||!D7inConPm1nCrucialActivation) && ((D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed) || (D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed))) {
                

D4outObservedDegradedPointPosition = D4outObservedDegradedPointPositionValue.DegradedLeft;
                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.DegradedLeft.New();
            }
if (D10inPm1CrucialPosition == D10inPm1nCrucialPositionValue.Right && (D10inPm1nCrucialPosition == D10inPm1nCrucialPositionValue.Right ||!D7inConPm1nCrucialActivation) && ((D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed) || (D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed))) {
                

D4outObservedDegradedPointPosition = D4outObservedDegradedPointPositionValue.DegradedRight;
                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.DegradedRight.New();
            }
else {
                

D4outObservedDegradedPointPosition = D4outObservedDegradedPointPositionValue.NotDegraded;
                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.NotDegraded.New();
            }
        }
      }

      // Do not transition
      return _state;
    }

private FObserveDegradedPointPositionBehaviour TransitionFromDegradedRight() {
      if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode)) {
             {
                


                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.New();
            }
          }
if (IsConditionChanged((D5inObservedPointPosition == D5inObservedPointPositionValue.Left || D5inObservedPointPosition == D5inObservedPointPositionValue.Right) || ((D10inPm1CrucialPosition != D10inPm1nCrucialPosition) && D7inConPm1nCrucialActivation) || ((D10inPm2NonCrucialPosition != D10inPm1CrucialPosition && D10inPm2NonCrucialPosition != D10inPm1nCrucialPositionValue.Trailed && D10inPm2NonCrucialPosition != D10inPm1nCrucialPositionValue.NoEndPosition)And D8inConPm2NonCrucialActivation) || ((D10inPm2nNonCrucialPosition != D10inPm1CrucialPosition && D10inPm2nNonCrucialPosition != D10inPm1nCrucialPositionValue.Trailed && D10inPm2nNonCrucialPosition != D10inPm1nCrucialPositionValue.NoEndPosition)And D9inConPm2nNonCrucialActivation))) {
             {
                

D4outObservedDegradedPointPosition = D4outObservedDegradedPointPositionValue.NotDegraded;
                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.NotDegraded.New();
            }
          }
if (IsConditionChanged(D10inPm1CrucialPosition == D10inPm1nCrucialPositionValue.Left && (D10inPm1nCrucialPosition == D10inPm1nCrucialPositionValue.Left ||!D7inConPm1nCrucialActivation) && ((D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed) || (D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed)))) {
             {
                

D4outObservedDegradedPointPosition = D4outObservedDegradedPointPositionValue.DegradedLeft;
                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.DegradedLeft.New();
            }
          }

      // Do not transition
      return _state;
    }

private FObserveDegradedPointPositionBehaviour TransitionFromNotDegraded() {
      if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode)) {
             {
                


                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.New();
            }
          }
if (IsConditionChanged(D10inPm1CrucialPosition == D10inPm1nCrucialPositionValue.Left && (D10inPm1nCrucialPosition == D10inPm1nCrucialPositionValue.Left ||!D7inConPm1nCrucialActivation) && ((((D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed) && D10inPm2NonCrucialPosition != D10inPm1nCrucialPositionValue.Right)) || (((D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed) && D10inPm2nNonCrucialPosition != D10inPm1nCrucialPositionValue.Right))))) {
             {
                

D4outObservedDegradedPointPosition = D4outObservedDegradedPointPositionValue.DegradedLeft;
                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.DegradedLeft.New();
            }
          }
if (IsConditionChanged(D10inPm1CrucialPosition == D10inPm1nCrucialPositionValue.Right && (D10inPm1nCrucialPosition == D10inPm1nCrucialPositionValue.Right ||!D7inConPm1nCrucialActivation) && ((((D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed) && D10inPm2NonCrucialPosition != D10inPm1nCrucialPositionValue.Left)) || (((D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed) && D10inPm2nNonCrucialPosition != D10inPm1nCrucialPositionValue.Left))))) {
             {
                

D4outObservedDegradedPointPosition = D4outObservedDegradedPointPositionValue.DegradedRight;
                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.DegradedRight.New();
            }
          }

      // Do not transition
      return _state;
    }

private FObserveDegradedPointPositionBehaviour TransitionFromDegradedLeft() {
      if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode)) {
             {
                


                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.New();
            }
          }
if (IsConditionChanged((D5inObservedPointPosition == D5inObservedPointPositionValue.Left || D5inObservedPointPosition == D5inObservedPointPositionValue.Right) || ((D10inPm1CrucialPosition != D10inPm1nCrucialPosition) && D7inConPm1nCrucialActivation) || 
((D10inPm2NonCrucialPosition != D10inPm1CrucialPosition && D10inPm2NonCrucialPosition != D10inPm1nCrucialPositionValue.Trailed && D10inPm2NonCrucialPosition != D10inPm1nCrucialPositionValue.NoEndPosition)And D8inConPm2NonCrucialActivation) Or
((D10inPm2nNonCrucialPosition != D10inPm1CrucialPosition && D10inPm2nNonCrucialPosition != D10inPm1nCrucialPositionValue.Trailed && D10inPm2nNonCrucialPosition != D10inPm1nCrucialPositionValue.NoEndPosition)And D9inConPm2nNonCrucialActivation))) {
             {
                

D4outObservedDegradedPointPosition = D4outObservedDegradedPointPositionValue.NotDegraded;
                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.NotDegraded.New();
            }
          }
if (IsConditionChanged(D10inPm1CrucialPosition == D10inPm1nCrucialPositionValue.Right && (D10inPm1nCrucialPosition == D10inPm1nCrucialPositionValue.Right ||!D7inConPm1nCrucialActivation) && ((D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2nNonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed) || (D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.NoEndPosition || D10inPm2NonCrucialPosition == D10inPm1nCrucialPositionValue.Trailed)))) {
             {
                

D4outObservedDegradedPointPosition = D4outObservedDegradedPointPositionValue.DegradedRight;
                return FObserveDegradedPointPositionBehaviour.ObserveDegradedPointPosition.DegradedRight.New();
            }
          }

      // Do not transition
      return _state;
    }

private FObserveDegradedPointPositionBehaviour TransitionFromDegradedDenied() {
      

      // Do not transition
      return _state;
    }


    public D10inPm1nCrucialPositionValue D10inPm1CrucialPosition { get; set; }
public D10inPm1nCrucialPositionValue D10inPm1nCrucialPosition { get; set; }
public D51inEstEfesStateValue D51inEstEfesState { get; set; }
public bool D8inConPm2NonCrucialActivation { get; set; }
public D10inPm1nCrucialPositionValue D10inPm2nNonCrucialPosition { get; set; }
public D4outObservedDegradedPointPositionValue D4outObservedDegradedPointPosition { get; set; }
public D10inPm1nCrucialPositionValue D10inPm2NonCrucialPosition { get; set; }
public bool D9inConPm2nNonCrucialActivation { get; set; }
public bool D7inConPm1nCrucialActivation { get; set; }
public D5inObservedPointPositionValue D5inObservedPointPosition { get; set; }

    
        public enum D10inPm1CrucialPositionValue {
            Left,
Right,
NoEndPosition,
Trailed
        }

        public enum D10inPm1nCrucialPositionValue {
            Left,
Right,
NoEndPosition,
Trailed
        }

        public enum D51inEstEfesStateValue {
            NoOperatingVoltage,
Booting,
FallbackMode,
Initialising
        }


        public enum D10inPm2nNonCrucialPositionValue {
            Left,
Right,
NoEndPosition,
Trailed
        }

        public enum D4outObservedDegradedPointPositionValue {
            Undefined,
DegradedDenied,
DegradedLeft,
DegradedRight,
NotDegraded
        }

        public enum D10inPm2NonCrucialPositionValue {
            Left,
Right,
NoEndPosition,
Trailed
        }



        public enum D5inObservedPointPositionValue {
            Left,
Right
        }
}
