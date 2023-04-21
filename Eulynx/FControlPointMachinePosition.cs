using System.Threading.Channels;
using EulynxMessages = EulynxLive.Messages.Baseline4R1;

namespace Eulynx;

public class FControlPointMachinePosition
{
    public record FControlPointMachinePositionBehaviour : object
    {
        public record Operating : FControlPointMachinePositionBehaviour
        {
            public record MovingLeft() : Operating()
            {
                public static new MovingLeft New(FControlPointMachinePosition This) => new MovingLeft();
            }
            public record MovingRight() : Operating()
            {
                public static new MovingRight New(FControlPointMachinePosition This) => new MovingRight();
            }
            public record Stopped() : Operating()
            {
                public static new Stopped New(FControlPointMachinePosition This) => new Stopped();
            }
            public record Waiting() : Operating()
            {
                public static new Waiting New(FControlPointMachinePosition This) => new Waiting();
            }

            public static new Operating New(FControlPointMachinePosition This)
            {

                return Operating.Waiting.New(This);
            }

            private Operating() { }
        }


        public static new FControlPointMachinePositionBehaviour New(FControlPointMachinePosition This)
        {
            This.MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
            This.D21outMoveLeft = D21outMoveLeftValue.False;
            This.D22outMoveRight = D22outMoveRightValue.False;

            return FControlPointMachinePositionBehaviour.Operating.New(This);
        }

        private FControlPointMachinePositionBehaviour() { }
    }


    private FControlPointMachinePositionBehaviour _state;
    public FControlPointMachinePositionBehaviour State { get { return _state; } }

    private readonly MessageConverter _messageConverter;

    public FControlPointMachinePosition(MessageConverter messageConverter)
    {
        _messageConverter = messageConverter;
    }

    public void Init()
    {
        _state = FControlPointMachinePositionBehaviour.New(this);
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

    private void SendMessage(Message message, Channel<EulynxMessages.Message> port)
    {
        port.Writer.TryWrite(_messageConverter.Convert<Message>(message));
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
            FControlPointMachinePositionBehaviour.Operating.MovingLeft => TransitionFromFControlPointMachinePositionBehaviour__Operating__MovingLeft(),
            FControlPointMachinePositionBehaviour.Operating.MovingRight => TransitionFromFControlPointMachinePositionBehaviour__Operating__MovingRight(),
            FControlPointMachinePositionBehaviour.Operating.Stopped => TransitionFromFControlPointMachinePositionBehaviour__Operating__Stopped(),
            FControlPointMachinePositionBehaviour.Operating.Waiting => TransitionFromFControlPointMachinePositionBehaviour__Operating__Waiting(),
            FControlPointMachinePositionBehaviour.Operating => TransitionFromFControlPointMachinePositionBehaviour__Operating()
        };
    }

    private FControlPointMachinePositionBehaviour TransitionFromFControlPointMachinePositionBehaviour__Operating__MovingLeft()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {
                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;

                return FControlPointMachinePositionBehaviour.Operating.New(this);
            }
        }
        if (IsTimeoutExpired(D39inConTmaxPmOperation))
        {
            {
                D35outDriveStop = D35outDriveStopValue.False;

                D40outMsgPmTimeout = D40outMsgPmTimeoutValue.True;

                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;
                D35outDriveStop = D35outDriveStopValue.True;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (IsConditionChanged(D10inPmPosition == MemLastCommandedPointPosition))
        {
            {
                D35outDriveStop = D35outDriveStopValue.False;

                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;
                D35outDriveStop = D35outDriveStopValue.True;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Right && (D2inRequiredPointPosition != D10inPmPosition)))
        {
            {
                D21outMoveLeft = D21outMoveLeftValue.False;
                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Right;

                D22outMoveRight = D22outMoveRightValue.True;
                D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;

                return FControlPointMachinePositionBehaviour.Operating.MovingRight.New(this);
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Uncommanded))
        {
            {
                D35outDriveStop = D35outDriveStopValue.False;

                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;
                D35outDriveStop = D35outDriveStopValue.True;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D10inPmPosition))
        {
            {
                D35outDriveStop = D35outDriveStopValue.False;

                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Right;

                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;
                D35outDriveStop = D35outDriveStopValue.True;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (IsConditionChanged(D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove))
        {
            {
                D35outDriveStop = D35outDriveStopValue.False;

                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;
                D35outDriveStop = D35outDriveStopValue.True;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private FControlPointMachinePositionBehaviour TransitionFromFControlPointMachinePositionBehaviour__Operating__MovingRight()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {
                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;

                return FControlPointMachinePositionBehaviour.Operating.New(this);
            }
        }
        if (IsTimeoutExpired(D39inConTmaxPmOperation))
        {
            {
                D35outDriveStop = D35outDriveStopValue.False;

                D40outMsgPmTimeout = D40outMsgPmTimeoutValue.True;

                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;
                D35outDriveStop = D35outDriveStopValue.True;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (IsConditionChanged(D10inPmPosition == MemLastCommandedPointPosition))
        {
            {
                D35outDriveStop = D35outDriveStopValue.False;

                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;
                D35outDriveStop = D35outDriveStopValue.True;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Left && (D2inRequiredPointPosition != D10inPmPosition)))
        {
            {
                D22outMoveRight = D22outMoveRightValue.False;
                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Left;

                D21outMoveLeft = D21outMoveLeftValue.True;
                D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;

                return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New(this);
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Uncommanded))
        {
            {
                D35outDriveStop = D35outDriveStopValue.False;

                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;
                D35outDriveStop = D35outDriveStopValue.True;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == D10inPmPosition))
        {
            {
                D35outDriveStop = D35outDriveStopValue.False;

                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Left;

                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;
                D35outDriveStop = D35outDriveStopValue.True;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (IsConditionChanged(D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.UnableToMove))
        {
            {
                D35outDriveStop = D35outDriveStopValue.False;

                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;
                D35outDriveStop = D35outDriveStopValue.True;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private FControlPointMachinePositionBehaviour TransitionFromFControlPointMachinePositionBehaviour__Operating__Stopped()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {
                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;

                return FControlPointMachinePositionBehaviour.Operating.New(this);
            }
        }
        if (IsConditionChanged(D10inPmPosition == MemLastCommandedPointPositionValue.NoEndPosition))
        {
            if (D41inObservedPointEndPosition == D41inObservedPointEndPositionValue.Right && MemLastCommandedPointPosition == MemLastCommandedPointPositionValue.Right && D29inConUseRedrive && D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.AbleToMove && D51inEstEfesState == D51inEstEfesStateValue.Operational)
            {
                D22outMoveRight = D22outMoveRightValue.True;
                D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;

                return FControlPointMachinePositionBehaviour.Operating.MovingRight.New(this);
            }
        }
        if (IsConditionChanged(D10inPmPosition == MemLastCommandedPointPositionValue.NoEndPosition))
        {
            if (D41inObservedPointEndPosition == D41inObservedPointEndPositionValue.Left && MemLastCommandedPointPosition == MemLastCommandedPointPositionValue.Left && D29inConUseRedrive && D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.AbleToMove && D51inEstEfesState == D51inEstEfesStateValue.Operational)
            {
                D21outMoveLeft = D21outMoveLeftValue.True;
                D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;

                return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New(this);
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Left))
        {
            {
                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Left;

                if (D2inRequiredPointPosition != D10inPmPosition && D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.AbleToMove)
                {
                    D21outMoveLeft = D21outMoveLeftValue.True;
                    D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;

                    return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New(this);
                }
                else
                {
                    D35outDriveStop = D35outDriveStopValue.False;

                    D21outMoveLeft = D21outMoveLeftValue.False;
                    D22outMoveRight = D22outMoveRightValue.False;
                    D35outDriveStop = D35outDriveStopValue.True;

                    return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
                }
            }
        }
        if (IsConditionChanged(D2inRequiredPointPosition == MemLastCommandedPointPositionValue.Right))
        {
            {
                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Right;

                if (D2inRequiredPointPosition != D10inPmPosition && D6inObservedAbilityToMovePoint == D6inObservedAbilityToMovePointValue.AbleToMove)
                {
                    D22outMoveRight = D22outMoveRightValue.True;
                    D40outMsgPmTimeout = D40outMsgPmTimeoutValue.False;

                    return FControlPointMachinePositionBehaviour.Operating.MovingRight.New(this);
                }
                else
                {
                    D35outDriveStop = D35outDriveStopValue.False;

                    D21outMoveLeft = D21outMoveLeftValue.False;
                    D22outMoveRight = D22outMoveRightValue.False;
                    D35outDriveStop = D35outDriveStopValue.True;

                    return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlPointMachinePositionBehaviour TransitionFromFControlPointMachinePositionBehaviour__Operating__Waiting()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {
                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;

                return FControlPointMachinePositionBehaviour.Operating.New(this);
            }
        }
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.Initialising))
        {
            if (D34inConActive && D44inConDriveCapability)
            {
                D35outDriveStop = D35outDriveStopValue.False;

                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;
                D35outDriveStop = D35outDriveStopValue.True;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private FControlPointMachinePositionBehaviour TransitionFromFControlPointMachinePositionBehaviour__Operating()
    {
        if (IsConditionChanged(D51inEstEfesState == D51inEstEfesStateValue.NoOperatingVoltage || D51inEstEfesState == D51inEstEfesStateValue.Booting || D51inEstEfesState == D51inEstEfesStateValue.FallbackMode))
        {
            {
                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
                D21outMoveLeft = D21outMoveLeftValue.False;
                D22outMoveRight = D22outMoveRightValue.False;

                return FControlPointMachinePositionBehaviour.Operating.New(this);
            }
        }

        // Do not transition
        return _state;
    }


    // Properties
    public MemLastCommandedPointPositionValue MemLastCommandedPointPosition { get; set; }

    // Ports
    public MemLastCommandedPointPositionValue D2inRequiredPointPosition { get; set; }
    public D35outDriveStopValue D35outDriveStop { get; set; }
    public D21outMoveLeftValue D21outMoveLeft { get; set; }
    public D22outMoveRightValue D22outMoveRight { get; set; }
    public bool D29inConUseRedrive { get; set; }
    public D51inEstEfesStateValue D51inEstEfesState { get; set; }
    public MemLastCommandedPointPositionValue D10inPmPosition { get; set; }
    public bool D34inConActive { get; set; }
    public bool D44inConDriveCapability { get; set; }
    public D6inObservedAbilityToMovePointValue D6inObservedAbilityToMovePoint { get; set; }
    public bool D39inConTmaxPmOperation { get; set; }
    public D40outMsgPmTimeoutValue D40outMsgPmTimeout { get; set; }
    public D41inObservedPointEndPositionValue D41inObservedPointEndPosition { get; set; }

    // Operations


    // Value Types

    public enum MemLastCommandedPointPositionValue
    {
        Undefined,
        Right,
        Left,
        NoEndPosition,
        Uncommanded
    }

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


    public enum D51inEstEfesStateValue
    {
        NoOperatingVoltage,
        Booting,
        FallbackMode,
        Operational,
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



    public enum D6inObservedAbilityToMovePointValue
    {
        UnableToMove,
        AbleToMove
    }


    public enum D40outMsgPmTimeoutValue
    {
        True,
        False
    }

    public enum D41inObservedPointEndPositionValue
    {
        Right,
        Left
    }

    // Messages
    public record Message
    {

    }
}
