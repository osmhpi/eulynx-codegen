namespace Eulynx;

public class FObserveOverallPointPosition
{
    public record FObserveOverallPointPositionBehaviour : object
    {
        public record ObserveOverallPointPosition : FObserveOverallPointPositionBehaviour
        {
            public record Left() : ObserveOverallPointPosition()
            {
                public static new Left New() => new Left();
            }
            public record Right() : ObserveOverallPointPosition()
            {
                public static new Right New() => new Right();
            }
            public record NoEndPosition() : ObserveOverallPointPosition()
            {
                public static new NoEndPosition New() => new NoEndPosition();
            }
            public record Trailed() : ObserveOverallPointPosition()
            {
                public static new Trailed New() => new Trailed();
            }

            public static new ObserveOverallPointPosition New() => ObserveOverallPointPosition.Junction.New();

            private ObserveOverallPointPosition() { }
        }


        public static new FObserveOverallPointPositionBehaviour New() => FObserveOverallPointPositionBehaviour.ObserveOverallPointPosition.New();

        private FObserveOverallPointPositionBehaviour() { }
    }


    private FObserveOverallPointPosition _state;
    public FObserveOverallPointPosition State { get { return _state; } }

    public FObserveOverallPointPosition()
    {

        _state = FObserveOverallPointPosition.New();
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
            FObserveOverallPointPositionBehaviour.ObserveOverallPointPosition.Left => TransitionFromLeft(),
            FObserveOverallPointPositionBehaviour.ObserveOverallPointPosition.Right => TransitionFromRight(),
            FObserveOverallPointPositionBehaviour.ObserveOverallPointPosition.NoEndPosition => TransitionFromNoendposition(),
            FObserveOverallPointPositionBehaviour.ObserveOverallPointPosition.Trailed => TransitionFromTrailed()
        };
    }

    private FObserveOverallPointPositionBehaviour TransitionFromLeft()
    {


        // Do not transition
        return _state;
    }

    private FObserveOverallPointPositionBehaviour TransitionFromRight()
    {


        // Do not transition
        return _state;
    }

    private FObserveOverallPointPositionBehaviour TransitionFromNoEndPosition()
    {


        // Do not transition
        return _state;
    }

    private FObserveOverallPointPositionBehaviour TransitionFromTrailed()
    {


        // Do not transition
        return _state;
    }


    public bool D5outObservedPointPosition { get; set; }
    public bool D10inPm1CrucialPosition { get; set; }
    public bool D10inPm1nCrucialPosition { get; set; }
    public bool D51inEstEfesState { get; set; }
    public bool D11inConPm1nCrucialActivation { get; set; }
    public bool D10inPm2nNonCrucialPosition { get; set; }
    public bool D10inPm2NonCrucialPosition { get; set; }
    public bool D14inConUseTrailing { get; set; }
    public bool D12inConPm2NonCrucialActivation { get; set; }
    public bool D13inConPm2nNonCrucialActivation { get; set; }
    public bool MemPm1CrucialPosition { get; set; }
    public bool MemPm1nCrucialPosition { get; set; }
    public bool MemPm2NonCrucialPosition { get; set; }
    public bool MemPm2nNonCrucialPosition { get; set; }
    public bool D41outObservedPointEndPosition { get; set; }
















}
