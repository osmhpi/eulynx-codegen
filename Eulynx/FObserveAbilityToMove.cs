namespace Eulynx;

public class FObserveAbilityToMove
{
    public record FObserveAbilityToMoveBehaviour : object
    {
        public record WaitingForInitialising() : FObserveAbilityToMoveBehaviour()
        {
            public static new WaitingForInitialising New() => new WaitingForInitialising();
        }
        public record AbleToMove() : FObserveAbilityToMoveBehaviour()
        {
            public static new AbleToMove New() => new AbleToMove();
        }
        public record UnableToMove() : FObserveAbilityToMoveBehaviour()
        {
            public static new UnableToMove New() => new UnableToMove();
        }

        public static new FObserveAbilityToMoveBehaviour New() => FObserveAbilityToMoveBehaviour.WaitingForInitialising.New();

        private FObserveAbilityToMoveBehaviour() { }
    }


    private FObserveAbilityToMove _state;
    public FObserveAbilityToMove State { get { return _state; } }

    public FObserveAbilityToMove()
    {

        _state = FObserveAbilityToMove.New();
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
            FObserveAbilityToMoveBehaviour.WaitingForInitialising => TransitionFromWaitingforinitialising(),
            FObserveAbilityToMoveBehaviour.AbleToMove => TransitionFromAbletomove(),
            FObserveAbilityToMoveBehaviour.UnableToMove => TransitionFromUnabletomove()
        };
    }

    private FObserveAbilityToMoveBehaviour TransitionFromWaitingForInitialising()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Initialising))
        {
            {



                if (D19inAbilityToMovePm1Crucial == D19inAbilityToMovePm1CrucialValue.Able
  And(D19inAbilityToMovePm1nCrucial == D19inAbilityToMovePm1nCrucialValue.Able || D19inAbilityToMovePm1nCrucial == D19inAbilityToMovePm1nCrucialValue.NotUsed || !D46inConPm1nCrucialActivation)
And(D19inAbilityToMovePm2nNonCrucial == D19inAbilityToMovePm2nNonCrucialValue.Able || D19inAbilityToMovePm2nNonCrucial == D19inAbilityToMovePm2nNonCrucialValue.NotUsed || !D48inConPm2nNonCrucialActivation)
And(D19inAbilityToMovePm2NonCrucial == D19inAbilityToMovePm2NonCrucialValue.Able || D19inAbilityToMovePm2NonCrucial == D19inAbilityToMovePm2NonCrucialValue.NotUsed || !D47inConPm2NonCrucialActivation)
And D18inInternalTriggerAbilityToMovePointAvailable) {


                    D6outObservedAbilityToMovePoint = D6outObservedAbilityToMovePointValue.AbleToMove;
                    return FObserveAbilityToMoveBehaviour.AbleToMove.New();
                }
                if (D19inAbilityToMovePm1Crucial == D19inAbilityToMovePm1CrucialValue.Unable || D19inAbilityToMovePm1nCrucial == D19inAbilityToMovePm1nCrucialValue.Unable || D19inAbilityToMovePm2NonCrucial == D19inAbilityToMovePm2NonCrucialValue.Unable
                Or D19inAbilityToMovePm2nNonCrucial == D19inAbilityToMovePm2nNonCrucialValue.Unable || !D18inInternalTriggerAbilityToMovePointAvailable) {


                    D6outObservedAbilityToMovePoint = D6outObservedAbilityToMovePointValue.UnableToMove;
                    return FObserveAbilityToMoveBehaviour.UnableToMove.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FObserveAbilityToMoveBehaviour TransitionFromAbleToMove()
    {
        if (IsConditionChanged(D19inAbilityToMovePm1Crucial == D19inAbilityToMovePm1CrucialValue.Unable || D19inAbilityToMovePm1nCrucial == D19inAbilityToMovePm1nCrucialValue.Unable || D19inAbilityToMovePm2NonCrucial == D19inAbilityToMovePm2NonCrucialValue.Unable
Or D19inAbilityToMovePm2nNonCrucial == D19inAbilityToMovePm2nNonCrucialValue.Unable || !D18inInternalTriggerAbilityToMovePointAvailable))
        {
            {


                D6outObservedAbilityToMovePoint = D6outObservedAbilityToMovePointValue.UnableToMove;
                return FObserveAbilityToMoveBehaviour.UnableToMove.New();
            }
        }

        // Do not transition
        return _state;
    }

    private FObserveAbilityToMoveBehaviour TransitionFromUnableToMove()
    {
        if (IsConditionChanged(D19inAbilityToMovePm1Crucial == D19inAbilityToMovePm1CrucialValue.Able
And(D19inAbilityToMovePm1nCrucial == D19inAbilityToMovePm1nCrucialValue.Able || D19inAbilityToMovePm1nCrucial == D19inAbilityToMovePm1nCrucialValue.NotUsed || !D46inConPm1nCrucialActivation)
And(D19inAbilityToMovePm2nNonCrucial == D19inAbilityToMovePm2nNonCrucialValue.Able || D19inAbilityToMovePm2nNonCrucial == D19inAbilityToMovePm2nNonCrucialValue.NotUsed || !D48inConPm2nNonCrucialActivation)
And(D19inAbilityToMovePm2NonCrucial == D19inAbilityToMovePm2NonCrucialValue.Able || D19inAbilityToMovePm2NonCrucial == D19inAbilityToMovePm2NonCrucialValue.NotUsed || !D47inConPm2NonCrucialActivation)
And D18inInternalTriggerAbilityToMovePointAvailable))
        {
            {


                D6outObservedAbilityToMovePoint = D6outObservedAbilityToMovePointValue.AbleToMove;
                return FObserveAbilityToMoveBehaviour.AbleToMove.New();
            }
        }

        // Do not transition
        return _state;
    }


    public D19inAbilityToMovePm1nCrucialValue D19inAbilityToMovePm1nCrucial { get; set; }
    public D19inAbilityToMovePm1CrucialValue D19inAbilityToMovePm1Crucial { get; set; }
    public D6outObservedAbilityToMovePointValue D6outObservedAbilityToMovePoint { get; set; }
    public bool D18inInternalTriggerAbilityToMovePointAvailable { get; set; }
    public D19inAbilityToMovePm2nNonCrucialValue D19inAbilityToMovePm2nNonCrucial { get; set; }
    public D19inAbilityToMovePm2NonCrucialValue D19inAbilityToMovePm2NonCrucial { get; set; }
    public D51inEstEfesStateValue D51inEstEfesState { get; set; }
    public bool D46inConPm1nCrucialActivation { get; set; }
    public bool D47inConPm2NonCrucialActivation { get; set; }
    public bool D48inConPm2nNonCrucialActivation { get; set; }


    public enum D19inAbilityToMovePm1nCrucialValue
    {
        Able,
        NotUsed,
        Unable
    }

    public enum D19inAbilityToMovePm1CrucialValue
    {
        Able,
        Unable
    }

    public enum D6outObservedAbilityToMovePointValue
    {
        AbleToMove,
        UnableToMove
    }


    public enum D19inAbilityToMovePm2nNonCrucialValue
    {
        Able,
        NotUsed,
        Unable
    }

    public enum D19inAbilityToMovePm2NonCrucialValue
    {
        Able,
        NotUsed,
        Unable
    }

    public enum D51inEstEfesStateValue
    {
        Initialising
    }



}
