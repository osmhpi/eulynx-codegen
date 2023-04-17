namespace Eulynx;

public class FControlAndObserve4WPm
{
    public record FControlAndObserve4WPmBehaviour : object
    {
        public record Operating : FControlAndObserve4WPmBehaviour
        {
            public record DetectionRight_NotUsed : Operating
            {
                public record NoEndPosition() : DetectionRight_NotUsed()
                {
                    public static new NoEndPosition New() => new NoEndPosition();
                }
                public record Trailed() : DetectionRight_NotUsed()
                {
                    public static new Trailed New() => new Trailed();
                }
                public record Initialising() : DetectionRight_NotUsed()
                {
                    public static new Initialising New() => new Initialising();
                }
                public record Right() : DetectionRight_NotUsed()
                {
                    public static new Right New() => new Right();
                }

                public static new DetectionRight_NotUsed New() => DetectionRight.Initialising.New();

                private DetectionRight_NotUsed() { }
            }

            public record DetectionLeft_NotUsed : Operating
            {
                public record Left() : DetectionLeft_NotUsed()
                {
                    public static new Left New() => new Left();
                }
                public record NoEndPosition() : DetectionLeft_NotUsed()
                {
                    public static new NoEndPosition New() => new NoEndPosition();
                }
                public record Trailed() : DetectionLeft_NotUsed()
                {
                    public static new Trailed New() => new Trailed();
                }
                public record Initialising() : DetectionLeft_NotUsed()
                {
                    public static new Initialising New() => new Initialising();
                }

                public static new DetectionLeft_NotUsed New() => DetectionLeft.Initialising.New();

                private DetectionLeft_NotUsed() { }
            }

            public record InitialisingWithoutTarget_NotUsed() : Operating()
            {
                public static new InitialisingWithoutTarget_NotUsed New() => new InitialisingWithoutTarget_NotUsed();
            }
            public record Waiting_NotUsed() : Operating()
            {
                public static new Waiting_NotUsed New() => new Waiting_NotUsed();
            }
            public record MovingRightPm_NotUsed() : Operating()
            {
                public static new MovingRightPm_NotUsed New() => new MovingRightPm_NotUsed();
            }
            public record MovingLeftPm_NotUsed() : Operating()
            {
                public static new MovingLeftPm_NotUsed New() => new MovingLeftPm_NotUsed();
            }
            public record DetectionRight_Able : Operating
            {
                public record NoEndPosition() : DetectionRight_Able()
                {
                    public static new NoEndPosition New() => new NoEndPosition();
                }
                public record Trailed() : DetectionRight_Able()
                {
                    public static new Trailed New() => new Trailed();
                }
                public record Initialising() : DetectionRight_Able()
                {
                    public static new Initialising New() => new Initialising();
                }
                public record Right() : DetectionRight_Able()
                {
                    public static new Right New() => new Right();
                }

                public static new DetectionRight_Able New() => DetectionRight.Initialising.New();

                private DetectionRight_Able() { }
            }

            public record DetectionLeft_Able : Operating
            {
                public record Left() : DetectionLeft_Able()
                {
                    public static new Left New() => new Left();
                }
                public record NoEndPosition() : DetectionLeft_Able()
                {
                    public static new NoEndPosition New() => new NoEndPosition();
                }
                public record Trailed() : DetectionLeft_Able()
                {
                    public static new Trailed New() => new Trailed();
                }
                public record Initialising() : DetectionLeft_Able()
                {
                    public static new Initialising New() => new Initialising();
                }

                public static new DetectionLeft_Able New() => DetectionLeft.Initialising.New();

                private DetectionLeft_Able() { }
            }

            public record InitialisingWithoutTarget_Able() : Operating()
            {
                public static new InitialisingWithoutTarget_Able New() => new InitialisingWithoutTarget_Able();
            }
            public record Waiting_Able() : Operating()
            {
                public static new Waiting_Able New() => new Waiting_Able();
            }
            public record MovingRightPm_Able() : Operating()
            {
                public static new MovingRightPm_Able New() => new MovingRightPm_Able();
            }
            public record MovingLeftPm_Able() : Operating()
            {
                public static new MovingLeftPm_Able New() => new MovingLeftPm_Able();
            }
            public record DetectionRight_Waiting : Operating
            {
                public record NoEndPosition() : DetectionRight_Waiting()
                {
                    public static new NoEndPosition New() => new NoEndPosition();
                }
                public record Trailed() : DetectionRight_Waiting()
                {
                    public static new Trailed New() => new Trailed();
                }
                public record Initialising() : DetectionRight_Waiting()
                {
                    public static new Initialising New() => new Initialising();
                }
                public record Right() : DetectionRight_Waiting()
                {
                    public static new Right New() => new Right();
                }

                public static new DetectionRight_Waiting New() => DetectionRight.Initialising.New();

                private DetectionRight_Waiting() { }
            }

            public record DetectionLeft_Waiting : Operating
            {
                public record Left() : DetectionLeft_Waiting()
                {
                    public static new Left New() => new Left();
                }
                public record NoEndPosition() : DetectionLeft_Waiting()
                {
                    public static new NoEndPosition New() => new NoEndPosition();
                }
                public record Trailed() : DetectionLeft_Waiting()
                {
                    public static new Trailed New() => new Trailed();
                }
                public record Initialising() : DetectionLeft_Waiting()
                {
                    public static new Initialising New() => new Initialising();
                }

                public static new DetectionLeft_Waiting New() => DetectionLeft.Initialising.New();

                private DetectionLeft_Waiting() { }
            }

            public record InitialisingWithoutTarget_Waiting() : Operating()
            {
                public static new InitialisingWithoutTarget_Waiting New() => new InitialisingWithoutTarget_Waiting();
            }
            public record Waiting_Waiting() : Operating()
            {
                public static new Waiting_Waiting New() => new Waiting_Waiting();
            }
            public record MovingRightPm_Waiting() : Operating()
            {
                public static new MovingRightPm_Waiting New() => new MovingRightPm_Waiting();
            }
            public record MovingLeftPm_Waiting() : Operating()
            {
                public static new MovingLeftPm_Waiting New() => new MovingLeftPm_Waiting();
            }
            public record DetectionRight_Unable : Operating
            {
                public record NoEndPosition() : DetectionRight_Unable()
                {
                    public static new NoEndPosition New() => new NoEndPosition();
                }
                public record Trailed() : DetectionRight_Unable()
                {
                    public static new Trailed New() => new Trailed();
                }
                public record Initialising() : DetectionRight_Unable()
                {
                    public static new Initialising New() => new Initialising();
                }
                public record Right() : DetectionRight_Unable()
                {
                    public static new Right New() => new Right();
                }

                public static new DetectionRight_Unable New() => DetectionRight.Initialising.New();

                private DetectionRight_Unable() { }
            }

            public record DetectionLeft_Unable : Operating
            {
                public record Left() : DetectionLeft_Unable()
                {
                    public static new Left New() => new Left();
                }
                public record NoEndPosition() : DetectionLeft_Unable()
                {
                    public static new NoEndPosition New() => new NoEndPosition();
                }
                public record Trailed() : DetectionLeft_Unable()
                {
                    public static new Trailed New() => new Trailed();
                }
                public record Initialising() : DetectionLeft_Unable()
                {
                    public static new Initialising New() => new Initialising();
                }

                public static new DetectionLeft_Unable New() => DetectionLeft.Initialising.New();

                private DetectionLeft_Unable() { }
            }

            public record InitialisingWithoutTarget_Unable() : Operating()
            {
                public static new InitialisingWithoutTarget_Unable New() => new InitialisingWithoutTarget_Unable();
            }
            public record Waiting_Unable() : Operating()
            {
                public static new Waiting_Unable New() => new Waiting_Unable();
            }
            public record MovingRightPm_Unable() : Operating()
            {
                public static new MovingRightPm_Unable New() => new MovingRightPm_Unable();
            }
            public record MovingLeftPm_Unable() : Operating()
            {
                public static new MovingLeftPm_Unable New() => new MovingLeftPm_Unable();
            }

            public static new Operating New() => Operating.Waiting_Waiting.New();

            private Operating() { }
        }


        public static new FControlAndObserve4WPmBehaviour New() => FControlAndObserve4WPmBehaviour.Operating.New();

        private FControlAndObserve4WPmBehaviour() { }
    }


    private FControlAndObserve4WPm _state;
    public FControlAndObserve4WPm State { get { return _state; } }

    public FControlAndObserve4WPm()
    {

        _state = FControlAndObserve4WPm.New();
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
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition => TransitionFromNoendposition(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed => TransitionFromTrailed(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Initialising => TransitionFromInitialising(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right => TransitionFromRight(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left => TransitionFromLeft(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition => TransitionFromNoendposition(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed => TransitionFromTrailed(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Initialising => TransitionFromInitialising(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition => TransitionFromNoendposition(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed => TransitionFromTrailed(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Initialising => TransitionFromInitialising(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right => TransitionFromRight(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left => TransitionFromLeft(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition => TransitionFromNoendposition(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed => TransitionFromTrailed(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Initialising => TransitionFromInitialising(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition => TransitionFromNoendposition(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed => TransitionFromTrailed(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Initialising => TransitionFromInitialising(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right => TransitionFromRight(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left => TransitionFromLeft(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition => TransitionFromNoendposition(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed => TransitionFromTrailed(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Initialising => TransitionFromInitialising(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition => TransitionFromNoendposition(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed => TransitionFromTrailed(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Initialising => TransitionFromInitialising(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right => TransitionFromRight(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left => TransitionFromLeft(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition => TransitionFromNoendposition(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed => TransitionFromTrailed(),
            FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Initialising => TransitionFromInitialising()
        };
    }

    private FControlAndObserve4WPmBehaviour TransitionFromNoEndPosition()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromTrailed()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromInitialising()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromRight()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromLeft()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromNoEndPosition()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromTrailed()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromInitialising()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromNoEndPosition()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromTrailed()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromInitialising()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromRight()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromLeft()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromNoEndPosition()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromTrailed()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromInitialising()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromNoEndPosition()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromTrailed()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromInitialising()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromRight()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromLeft()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromNoEndPosition()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromTrailed()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromInitialising()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromNoEndPosition()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromTrailed()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromInitialising()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0101) {


                D10outPmPosition = D10outPmPositionValue.Right;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Right.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromRight()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Left))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1100) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.1010 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromLeft()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromNoEndPosition()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromTrailed()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlAndObserve4WPmBehaviour TransitionFromInitialising()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {



                return FControlAndObserve4WPmBehaviour.Operating.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_NotUsed.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_NotUsed.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Able.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Able.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Able.New();
            }
        }
        if (IsConditionChanged(Not D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;

                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Waiting.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {





                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Waiting.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D21inMoveLeftPm))
        {
            if (D20inConDriveCapability)
            {
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D23outDriveVoltageLeft = D23outDriveVoltageLeftValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingLeftPm_Unable.New();
            }
        }
        if (IsConditionChanged(D22inMoveRightPm))
        {
            if (D20inConDriveCapability)
            {
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.False;


                D25outDetectionVoltage = D25outDetectionVoltageValue.False;
                D24outDriveVoltageRight = D24outDriveVoltageRightValue.True;
                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.MovingRightPm_Unable.New();
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D2inRequiredPointPositionValue.Right))
        {
            if (Not D20inConDriveCapability || D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove) {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionRight_Unable.New();
            }
        }
        if (IsConditionChanged(D26inDriveVoltageAvailable))
        {
            {




                D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.1010) {


                D10outPmPosition = D10outPmPositionValue.Left;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Left.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0000 Or
       D27in4WPattern == D27in4WPatternValue.0010 Or
       D27in4WPattern == D27in4WPatternValue.0011 Or
       D27in4WPattern == D27in4WPatternValue.0110 Or
       D27in4WPattern == D27in4WPatternValue.1000 Or
       D27in4WPattern == D27in4WPatternValue.1100 ) {


                D10outPmPosition = D10outPmPositionValue.NoEndPosition;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.NoEndPosition.New();
            }
        }
        {
            if (D27in4WPattern == D27in4WPatternValue.0001 Or
       D27in4WPattern == D27in4WPatternValue.0100 Or
       D27in4WPattern == D27in4WPatternValue.0111 Or
       D27in4WPattern == D27in4WPatternValue.1011 Or
       D27in4WPattern == D27in4WPatternValue.1101 Or
       D27in4WPattern == D27in4WPatternValue.1001 Or
       D27in4WPattern == D27in4WPatternValue.0101 Or
       D27in4WPattern == D27in4WPatternValue.1110 Or
       D27in4WPattern == D27in4WPatternValue.1111) {


                D10outPmPosition = D10outPmPositionValue.Trailed;
                return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft.Trailed.New();
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Booting))
        {
            if (
D45inConActive)
            {





                if (D20inConDriveCapability && D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Able;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Able.New();
                }
                if (Not D20inConDriveCapability) {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.NotUsed;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_NotUsed.New();
                }
                if (D20inConDriveCapability && !D26inDriveVoltageAvailable)
                {




                    D19outAbilityToMovePm = D19outAbilityToMovePmValue.Unable;
                    return FControlAndObserve4WPmBehaviour.Operating.DetectionLeft_Unable.New();
                }
            }
        }

        // Do not transition
        return _state;
    }


    public D10outPmPositionValue D10outPmPosition { get; set; }
    public bool D21inMoveLeftPm { get; set; }
    public bool D22inMoveRightPm { get; set; }
    public D19outAbilityToMovePmValue D19outAbilityToMovePm { get; set; }
    public bool D26inDriveVoltageAvailable { get; set; }
    public D24outDriveVoltageRightValue D24outDriveVoltageRight { get; set; }
    public D23outDriveVoltageLeftValue D23outDriveVoltageLeft { get; set; }
    public D25outDetectionVoltageValue D25outDetectionVoltage { get; set; }
    public bool D20inConDriveCapability { get; set; }
    public D27in4WPatternValue D27in4WPattern { get; set; }
    public D51inEstEfesStateValue D51inEstEfesState { get; set; }
    public bool D35inLastTargetPosition { get; set; }
    public D2inRequiredPointPositionValue D2inRequiredPointPosition { get; set; }
    public bool D45inConActive { get; set; }
    public D6inObservedAbilityToMovePointValue D6inObservedAbilityToMovePoint { get; set; }
    public bool D41inMsgTimeout { get; set; }


    public enum D10outPmPositionValue
    {
        NoEndPosition,
        Right,
        Trailed,
        Left
    }



    public enum D19outAbilityToMovePmValue
    {
        NotUsed,
        Able,
        Unable
    }


    public enum D24outDriveVoltageRightValue
    {
        False,
        True
    }

    public enum D23outDriveVoltageLeftValue
    {
        False,
        True
    }

    public enum D25outDetectionVoltageValue
    {
        False
    }


    public enum D27in4WPatternValue
    {
                0101,
0010,
0111,
1000,
1011,
1101,
1001,
1010,
1110,
1111,
0000,
0001,
0011,
0100,
0110,
1100
            }

    public enum D51inEstEfesStateValue
    {
        NoOperatingVoltage,
        Booting,
        FallbackMode
    }


    public enum D2inRequiredPointPositionValue
    {
        Left,
        Right
    }


    public enum D6inObservedAbilityToMovePointValue
    {
        UnableToMove
    }

}
