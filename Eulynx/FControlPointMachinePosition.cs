using System.Threading.Channels;
using EulynxMessages = EulynxLive.Messages.Baseline4R1;

namespace Eulynx;

public class FControlPointMachinePosition : IStateMachine<FControlPointMachinePosition.FControlPointMachinePositionBehaviour>
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
            This.D21outMoveLeft.Value = false;
            This.D22outMoveRight.Value = false;

            return FControlPointMachinePositionBehaviour.Operating.New(This);
        }

        private FControlPointMachinePositionBehaviour() { }
    }


    private FControlPointMachinePositionBehaviour _state;
    public FControlPointMachinePositionBehaviour State => _state;

    private readonly IMessageFactory _messageConverter;

    public FControlPointMachinePosition(IMessageFactory messageConverter)
    {
        _messageConverter = messageConverter;

        // Initialize ports
        D2inRequiredPointPosition = new Port<MemLastCommandedPointPositionValue>();
        D35outDriveStop = new Port<bool>();
        D21outMoveLeft = new Port<bool>();
        D22outMoveRight = new Port<bool>();
        D29inConUseRedrive = new Port<bool>();
        D51inEstEfesState = new Port<D51inEstEfesStateValue>();
        D10inPmPosition = new Port<MemLastCommandedPointPositionValue>();
        D34inConActive = new Port<bool>();
        D44inConDriveCapability = new Port<bool>();
        D6inObservedAbilityToMovePoint = new Port<D6inObservedAbilityToMovePointValue>();
        D39inConTmaxPmOperation = new Port<object>();
        D40outMsgPmTimeout = new Port<bool>();
        D41inObservedPointEndPosition = new Port<D41inObservedPointEndPositionValue>();

        // Initialize change events
        Change387 = new Event(() => D51inEstEfesState.Value.Equals(D51inEstEfesStateValue.NoOperatingVoltage) || D51inEstEfesState.Value.Equals(D51inEstEfesStateValue.Booting) || D51inEstEfesState.Value.Equals(D51inEstEfesStateValue.FallbackMode));
        Change34 = new Event(() => D10inPmPosition.Value == MemLastCommandedPointPosition);
        Change188 = new Event(() => D2inRequiredPointPosition.Value.Equals(MemLastCommandedPointPositionValue.Right) && (D2inRequiredPointPosition.Value != D10inPmPosition.Value));
        Change189 = new Event(() => D2inRequiredPointPosition.Value.Equals(MemLastCommandedPointPositionValue.Uncommanded));
        Change192 = new Event(() => D2inRequiredPointPosition.Value == D10inPmPosition.Value);
        Change460 = new Event(() => D6inObservedAbilityToMovePoint.Value.Equals(D6inObservedAbilityToMovePointValue.UnableToMove));
        Change33 = new Event(() => D10inPmPosition.Value == MemLastCommandedPointPosition);
        Change184 = new Event(() => D2inRequiredPointPosition.Value.Equals(MemLastCommandedPointPositionValue.Left) && (D2inRequiredPointPosition.Value != D10inPmPosition.Value));
        Change190 = new Event(() => D2inRequiredPointPosition.Value.Equals(MemLastCommandedPointPositionValue.Uncommanded));
        Change191 = new Event(() => D2inRequiredPointPosition.Value == D10inPmPosition.Value);
        Change461 = new Event(() => D6inObservedAbilityToMovePoint.Value.Equals(D6inObservedAbilityToMovePointValue.UnableToMove));
        Change31 = new Event(() => D10inPmPosition.Value.Equals(MemLastCommandedPointPositionValue.NoEndPosition));
        Change32 = new Event(() => D10inPmPosition.Value.Equals(MemLastCommandedPointPositionValue.NoEndPosition));
        Change183 = new Event(() => D2inRequiredPointPosition.Value.Equals(MemLastCommandedPointPositionValue.Left));
        Change185 = new Event(() => D2inRequiredPointPosition.Value.Equals(MemLastCommandedPointPositionValue.Right));
        Change373 = new Event(() => D51inEstEfesState.Value.Equals(D51inEstEfesStateValue.Initialising));
    }

    public void Init()
    {
        _state = FControlPointMachinePositionBehaviour.New(this);
    }

    public IEnumerable<AbstractPort> GetPorts()
    {
        return new AbstractPort[] {
            // TODO: Skip message ports
            D2inRequiredPointPosition, D35outDriveStop, D21outMoveLeft, D22outMoveRight, D29inConUseRedrive, D51inEstEfesState, D10inPmPosition, D34inConActive, D44inConDriveCapability, D6inObservedAbilityToMovePoint, D39inConTmaxPmOperation, D40outMsgPmTimeout, D41inObservedPointEndPosition
        };
    }

    public IEnumerable<Event> GetChangeEvents()
    {
        return new Event[] {
            Change387, Change34, Change188, Change189, Change192, Change460, Change33, Change184, Change190, Change191, Change461, Change31, Change32, Change183, Change185, Change373
        };
    }

    private bool IsTimeoutExpired(object timeout)
    {
        // TODO
        return false;
    }

    private void SendMessage(Message message, Port<Channel<EulynxMessages.Message>> port)
    {
        port.Value.Writer.TryWrite(_messageConverter.Convert<Message>(message));
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
        if (Change387.IsTriggered)
        {
            {

                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;

                return FControlPointMachinePositionBehaviour.Operating.New(this);
            }
        }
        if (IsTimeoutExpired(D39inConTmaxPmOperation))
        {
            {

                D35outDriveStop.Value = false;

                D40outMsgPmTimeout.Value = true;

                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;
                D35outDriveStop.Value = true;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (Change34.IsTriggered)
        {
            {

                D35outDriveStop.Value = false;

                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;
                D35outDriveStop.Value = true;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (Change188.IsTriggered)
        {
            {

                D21outMoveLeft.Value = false;
                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Right;

                D22outMoveRight.Value = true;
                D40outMsgPmTimeout.Value = false;

                return FControlPointMachinePositionBehaviour.Operating.MovingRight.New(this);
            }
        }
        if (Change189.IsTriggered)
        {
            {

                D35outDriveStop.Value = false;

                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;
                D35outDriveStop.Value = true;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (Change192.IsTriggered)
        {
            {

                D35outDriveStop.Value = false;

                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Right;

                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;
                D35outDriveStop.Value = true;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (Change460.IsTriggered)
        {
            {

                D35outDriveStop.Value = false;

                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;
                D35outDriveStop.Value = true;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private FControlPointMachinePositionBehaviour TransitionFromFControlPointMachinePositionBehaviour__Operating__MovingRight()
    {
        if (Change387.IsTriggered)
        {
            {

                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;

                return FControlPointMachinePositionBehaviour.Operating.New(this);
            }
        }
        if (IsTimeoutExpired(D39inConTmaxPmOperation))
        {
            {

                D35outDriveStop.Value = false;

                D40outMsgPmTimeout.Value = true;

                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;
                D35outDriveStop.Value = true;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (Change33.IsTriggered)
        {
            {

                D35outDriveStop.Value = false;

                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;
                D35outDriveStop.Value = true;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (Change184.IsTriggered)
        {
            {

                D22outMoveRight.Value = false;
                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Left;

                D21outMoveLeft.Value = true;
                D40outMsgPmTimeout.Value = false;

                return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New(this);
            }
        }
        if (Change190.IsTriggered)
        {
            {

                D35outDriveStop.Value = false;

                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;
                D35outDriveStop.Value = true;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (Change191.IsTriggered)
        {
            {

                D35outDriveStop.Value = false;

                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Left;

                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;
                D35outDriveStop.Value = true;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }
        if (Change461.IsTriggered)
        {
            {

                D35outDriveStop.Value = false;

                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;
                D35outDriveStop.Value = true;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private FControlPointMachinePositionBehaviour TransitionFromFControlPointMachinePositionBehaviour__Operating__Stopped()
    {
        if (Change387.IsTriggered)
        {
            {

                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;

                return FControlPointMachinePositionBehaviour.Operating.New(this);
            }
        }
        if (Change31.IsTriggered)
        {
            if (D41inObservedPointEndPosition.Value.Equals(D41inObservedPointEndPositionValue.Right) && MemLastCommandedPointPosition.Equals(MemLastCommandedPointPositionValue.Right) && D29inConUseRedrive.Value && D6inObservedAbilityToMovePoint.Value.Equals(D6inObservedAbilityToMovePointValue.AbleToMove) && D51inEstEfesState.Value.Equals(D51inEstEfesStateValue.Operational))
            {

                D22outMoveRight.Value = true;
                D40outMsgPmTimeout.Value = false;

                return FControlPointMachinePositionBehaviour.Operating.MovingRight.New(this);
            }
        }
        if (Change32.IsTriggered)
        {
            if (D41inObservedPointEndPosition.Value.Equals(D41inObservedPointEndPositionValue.Left) && MemLastCommandedPointPosition.Equals(MemLastCommandedPointPositionValue.Left) && D29inConUseRedrive.Value && D6inObservedAbilityToMovePoint.Value.Equals(D6inObservedAbilityToMovePointValue.AbleToMove) && D51inEstEfesState.Value.Equals(D51inEstEfesStateValue.Operational))
            {

                D21outMoveLeft.Value = true;
                D40outMsgPmTimeout.Value = false;

                return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New(this);
            }
        }
        if (Change183.IsTriggered)
        {
            {

                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Left;

                if (!D2inRequiredPointPosition.Value.Equals(D10inPmPosition.Value) && D6inObservedAbilityToMovePoint.Value.Equals(D6inObservedAbilityToMovePointValue.AbleToMove))
                {

                    D21outMoveLeft.Value = true;
                    D40outMsgPmTimeout.Value = false;

                    return FControlPointMachinePositionBehaviour.Operating.MovingLeft.New(this);
                }
                else
                {

                    D35outDriveStop.Value = false;

                    D21outMoveLeft.Value = false;
                    D22outMoveRight.Value = false;
                    D35outDriveStop.Value = true;

                    return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
                }
            }
        }
        if (Change185.IsTriggered)
        {
            {

                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Right;

                if (!D2inRequiredPointPosition.Value.Equals(D10inPmPosition.Value) && D6inObservedAbilityToMovePoint.Value.Equals(D6inObservedAbilityToMovePointValue.AbleToMove))
                {

                    D22outMoveRight.Value = true;
                    D40outMsgPmTimeout.Value = false;

                    return FControlPointMachinePositionBehaviour.Operating.MovingRight.New(this);
                }
                else
                {

                    D35outDriveStop.Value = false;

                    D21outMoveLeft.Value = false;
                    D22outMoveRight.Value = false;
                    D35outDriveStop.Value = true;

                    return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
                }
            }
        }

        // Do not transition
        return _state;
    }

    private FControlPointMachinePositionBehaviour TransitionFromFControlPointMachinePositionBehaviour__Operating__Waiting()
    {
        if (Change387.IsTriggered)
        {
            {

                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;

                return FControlPointMachinePositionBehaviour.Operating.New(this);
            }
        }
        if (Change373.IsTriggered)
        {
            if (D34inConActive.Value && D44inConDriveCapability.Value)
            {

                D35outDriveStop.Value = false;

                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;
                D35outDriveStop.Value = true;

                return FControlPointMachinePositionBehaviour.Operating.Stopped.New(this);
            }
        }

        // Do not transition
        return _state;
    }

    private FControlPointMachinePositionBehaviour TransitionFromFControlPointMachinePositionBehaviour__Operating()
    {
        if (Change387.IsTriggered)
        {
            {

                MemLastCommandedPointPosition = MemLastCommandedPointPositionValue.Undefined;
                D21outMoveLeft.Value = false;
                D22outMoveRight.Value = false;

                return FControlPointMachinePositionBehaviour.Operating.New(this);
            }
        }

        // Do not transition
        return _state;
    }


    // Properties
    public MemLastCommandedPointPositionValue MemLastCommandedPointPosition { get; set; }

    // Ports
    public Port<MemLastCommandedPointPositionValue> D2inRequiredPointPosition { get; set; }
    public Port<bool> D35outDriveStop { get; set; }
    public Port<bool> D21outMoveLeft { get; set; }
    public Port<bool> D22outMoveRight { get; set; }
    public Port<bool> D29inConUseRedrive { get; set; }
    public Port<D51inEstEfesStateValue> D51inEstEfesState { get; set; }
    public Port<MemLastCommandedPointPositionValue> D10inPmPosition { get; set; }
    public Port<bool> D34inConActive { get; set; }
    public Port<bool> D44inConDriveCapability { get; set; }
    public Port<D6inObservedAbilityToMovePointValue> D6inObservedAbilityToMovePoint { get; set; }
    public Port<object> D39inConTmaxPmOperation { get; set; }
    public Port<bool> D40outMsgPmTimeout { get; set; }
    public Port<D41inObservedPointEndPositionValue> D41inObservedPointEndPosition { get; set; }

    // Operations


    // Value Types

    public enum MemLastCommandedPointPositionValue
    {
        Undefined,
        Right,
        Left,
        Uncommanded,
        NoEndPosition
    }

    public enum D2inRequiredPointPositionValue
    {
        Undefined,
        Right,
        Left,
        Uncommanded,
        NoEndPosition
    }

    public enum D51inEstEfesStateValue
    {
        Operational,
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
        Uncommanded,
        NoEndPosition
    }

    public enum D6inObservedAbilityToMovePointValue
    {
        AbleToMove,
        UnableToMove
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

    // Signals
    public bool ReceiveMessage(Message message)
    {
        switch (message)
        {

            default: return false;
        };
    }
    private bool IsMessageArrived(Message message)
    {
        return message != null;
    }
    private bool ReceivedMessage<T>(T message, Func<T, bool> expr)
    {
        return message != null && expr(message);
    }

    // Events
    public Event Change387 { get; }
    public Event Change34 { get; }
    public Event Change188 { get; }
    public Event Change189 { get; }
    public Event Change192 { get; }
    public Event Change460 { get; }
    public Event Change33 { get; }
    public Event Change184 { get; }
    public Event Change190 { get; }
    public Event Change191 { get; }
    public Event Change461 { get; }
    public Event Change31 { get; }
    public Event Change32 { get; }
    public Event Change183 { get; }
    public Event Change185 { get; }
    public Event Change373 { get; }
}
