
#include "FControlPointMachinePosition.h"

// Value Conversion Functions

static FControlPointMachinePosition_D2inRequiredPointPositionValue map_D10inPmPosition_to_D2inRequiredPointPosition(
    FControlPointMachinePosition_D10inPmPositionValue value)
{
    switch (value)
    {
    case FControlPointMachinePosition_D10inPmPositionValue__NULL__:
        return FControlPointMachinePosition_D2inRequiredPointPositionValue__NULL__;
    case FControlPointMachinePosition_D10inPmPositionValue__UNKNOWN__:
        return FControlPointMachinePosition_D2inRequiredPointPositionValue__UNKNOWN__;
    case FControlPointMachinePosition_D10inPmPositionValue__NoEndPosition:
        return FControlPointMachinePosition_D2inRequiredPointPositionValue__NoEndPosition;
    case FControlPointMachinePosition_D10inPmPositionValue__Undefined:
        return FControlPointMachinePosition_D2inRequiredPointPositionValue__Undefined;
    case FControlPointMachinePosition_D10inPmPositionValue__Right:
        return FControlPointMachinePosition_D2inRequiredPointPositionValue__Right;
    case FControlPointMachinePosition_D10inPmPositionValue__Left:
        return FControlPointMachinePosition_D2inRequiredPointPositionValue__Left;
    case FControlPointMachinePosition_D10inPmPositionValue__Uncommanded:
        return FControlPointMachinePosition_D2inRequiredPointPositionValue__Uncommanded;
    default:
        abort();
    }
}
static FControlPointMachinePosition_D10inPmPositionValue map_MemLastCommandedPointPosition_to_D10inPmPosition(
    FControlPointMachinePosition_MemLastCommandedPointPositionValue value)
{
    switch (value)
    {
    case FControlPointMachinePosition_MemLastCommandedPointPositionValue__NULL__:
        return FControlPointMachinePosition_D10inPmPositionValue__NULL__;
    case FControlPointMachinePosition_MemLastCommandedPointPositionValue__UNKNOWN__:
        return FControlPointMachinePosition_D10inPmPositionValue__UNKNOWN__;
    case FControlPointMachinePosition_MemLastCommandedPointPositionValue__Undefined:
        return FControlPointMachinePosition_D10inPmPositionValue__Undefined;
    case FControlPointMachinePosition_MemLastCommandedPointPositionValue__Right:
        return FControlPointMachinePosition_D10inPmPositionValue__Right;
    case FControlPointMachinePosition_MemLastCommandedPointPositionValue__Left:
        return FControlPointMachinePosition_D10inPmPositionValue__Left;
    case FControlPointMachinePosition_MemLastCommandedPointPositionValue__NoEndPosition:
        return FControlPointMachinePosition_D10inPmPositionValue__NoEndPosition;
    case FControlPointMachinePosition_MemLastCommandedPointPositionValue__Uncommanded:
        return FControlPointMachinePosition_D10inPmPositionValue__Uncommanded;
    default:
        abort();
    }
}

// Operations

void make_state_FControlPointMachinePosition__root__Operating__root__MovingLeft(
    FControlPointMachinePosition *self, FControlPointMachinePosition__root__Operating__root__state_struct *region)
{
    LOG("[FControlPointMachinePosition] Entering state MovingLeft in region root__Operating__root");
    region->state = FControlPointMachinePosition__root__Operating__root__MovingLeft;
};

void make_state_FControlPointMachinePosition__root__Operating__root__MovingRight(
    FControlPointMachinePosition *self, FControlPointMachinePosition__root__Operating__root__state_struct *region)
{
    LOG("[FControlPointMachinePosition] Entering state MovingRight in region root__Operating__root");
    region->state = FControlPointMachinePosition__root__Operating__root__MovingRight;
};

void make_state_FControlPointMachinePosition__root__Operating__root__Stopped(
    FControlPointMachinePosition *self, FControlPointMachinePosition__root__Operating__root__state_struct *region)
{
    LOG("[FControlPointMachinePosition] Entering state Stopped in region root__Operating__root");
    region->state = FControlPointMachinePosition__root__Operating__root__Stopped;
};

void make_state_FControlPointMachinePosition__root__Operating__root__Waiting(
    FControlPointMachinePosition *self, FControlPointMachinePosition__root__Operating__root__state_struct *region)
{
    LOG("[FControlPointMachinePosition] Entering state Waiting in region root__Operating__root");
    region->state = FControlPointMachinePosition__root__Operating__root__Waiting;
};

void make_state_FControlPointMachinePosition__root__Operating__root(
    FControlPointMachinePosition *self, FControlPointMachinePosition__root__Operating__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlPointMachinePosition__root__Operating__root__state_struct));

    make_state_FControlPointMachinePosition__root__Operating__root__Waiting(self, x);
    return;
}

void make_state_FControlPointMachinePosition__root__Operating(FControlPointMachinePosition *self,
                                                              FControlPointMachinePosition__root__state_struct *region)
{
    LOG("[FControlPointMachinePosition] Entering state Operating in region root");
    region->state = FControlPointMachinePosition__root__Operating;
    make_state_FControlPointMachinePosition__root__Operating__root(self, &region->Operating.root);
};

void make_state_FControlPointMachinePosition__root(FControlPointMachinePosition *self,
                                                   FControlPointMachinePosition__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlPointMachinePosition__root__state_struct));
    self->MemLastCommandedPointPosition = FControlPointMachinePosition_MemLastCommandedPointPositionValue__Undefined;
    self->D21outMoveLeft.Value = false;
    self->D22outMoveRight.Value = false;
    make_state_FControlPointMachinePosition__root__Operating(self, x);
    return;
}

void transition_from_FControlPointMachinePosition__root__Operating__root__MovingLeft(
    FControlPointMachinePosition *self, FControlPointMachinePosition__root__state_struct *x)
{

    if (self->Time28.IsTimeoutExpired)
    {
        self->D40outMsgPmTimeout.Value = true;
        self->D21outMoveLeft.Value = false;
        self->D22outMoveRight.Value = false;
        self->D35outDriveStop.Value = true;
        make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change34.IsTriggered)
    {
        self->D21outMoveLeft.Value = false;
        self->D22outMoveRight.Value = false;
        self->D35outDriveStop.Value = true;
        make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change188.IsTriggered)
    {
        self->D21outMoveLeft.Value = false;
        self->MemLastCommandedPointPosition = FControlPointMachinePosition_MemLastCommandedPointPositionValue__Right;
        self->D22outMoveRight.Value = true;
        self->D40outMsgPmTimeout.Value = false;
        make_state_FControlPointMachinePosition__root__Operating__root__MovingRight(self, &x->Operating.root);
        return;
    }
    if (self->Change189.IsTriggered)
    {
        self->D21outMoveLeft.Value = false;
        self->D22outMoveRight.Value = false;
        self->D35outDriveStop.Value = true;
        make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change192.IsTriggered)
    {
        self->MemLastCommandedPointPosition = FControlPointMachinePosition_MemLastCommandedPointPositionValue__Right;
        self->D21outMoveLeft.Value = false;
        self->D22outMoveRight.Value = false;
        self->D35outDriveStop.Value = true;
        make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change460.IsTriggered)
    {
        self->D21outMoveLeft.Value = false;
        self->D22outMoveRight.Value = false;
        self->D35outDriveStop.Value = true;
        make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
}

void transition_from_FControlPointMachinePosition__root__Operating__root__MovingRight(
    FControlPointMachinePosition *self, FControlPointMachinePosition__root__state_struct *x)
{

    if (self->Time29.IsTimeoutExpired)
    {
        self->D40outMsgPmTimeout.Value = true;
        self->D21outMoveLeft.Value = false;
        self->D22outMoveRight.Value = false;
        self->D35outDriveStop.Value = true;
        make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change33.IsTriggered)
    {
        self->D21outMoveLeft.Value = false;
        self->D22outMoveRight.Value = false;
        self->D35outDriveStop.Value = true;
        make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change184.IsTriggered)
    {
        self->D22outMoveRight.Value = false;
        self->MemLastCommandedPointPosition = FControlPointMachinePosition_MemLastCommandedPointPositionValue__Left;
        self->D21outMoveLeft.Value = true;
        self->D40outMsgPmTimeout.Value = false;
        make_state_FControlPointMachinePosition__root__Operating__root__MovingLeft(self, &x->Operating.root);
        return;
    }
    if (self->Change190.IsTriggered)
    {
        self->D21outMoveLeft.Value = false;
        self->D22outMoveRight.Value = false;
        self->D35outDriveStop.Value = true;
        make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change191.IsTriggered)
    {
        self->MemLastCommandedPointPosition = FControlPointMachinePosition_MemLastCommandedPointPositionValue__Left;
        self->D21outMoveLeft.Value = false;
        self->D22outMoveRight.Value = false;
        self->D35outDriveStop.Value = true;
        make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change461.IsTriggered)
    {
        self->D21outMoveLeft.Value = false;
        self->D22outMoveRight.Value = false;
        self->D35outDriveStop.Value = true;
        make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
}

void transition_from_FControlPointMachinePosition__root__Operating__root__Stopped(
    FControlPointMachinePosition *self, FControlPointMachinePosition__root__state_struct *x)
{

    if (self->Change31.IsTriggered)
    {
        if (((((self->D41inObservedPointEndPosition.Value ==
                FControlPointMachinePosition_D41inObservedPointEndPositionValue__Right) &&
               (self->MemLastCommandedPointPosition ==
                FControlPointMachinePosition_MemLastCommandedPointPositionValue__Right)) &&
              (self->D29inConUseRedrive.Value)) &&
             (self->D6inObservedAbilityToMovePoint.Value ==
              FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__AbleToMove)) &&
            (self->D51inEstEfesState.Value == FControlPointMachinePosition_D51inEstEfesStateValue__Operational))
        {
            self->D35outDriveStop.Value = false;
            self->D22outMoveRight.Value = true;
            self->D40outMsgPmTimeout.Value = false;
            make_state_FControlPointMachinePosition__root__Operating__root__MovingRight(self, &x->Operating.root);
            return;
        }
    }
    if (self->Change32.IsTriggered)
    {
        if (((((self->D41inObservedPointEndPosition.Value ==
                FControlPointMachinePosition_D41inObservedPointEndPositionValue__Left) &&
               (self->MemLastCommandedPointPosition ==
                FControlPointMachinePosition_MemLastCommandedPointPositionValue__Left)) &&
              (self->D29inConUseRedrive.Value)) &&
             (self->D6inObservedAbilityToMovePoint.Value ==
              FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__AbleToMove)) &&
            (self->D51inEstEfesState.Value == FControlPointMachinePosition_D51inEstEfesStateValue__Operational))
        {
            self->D35outDriveStop.Value = false;
            self->D21outMoveLeft.Value = true;
            self->D40outMsgPmTimeout.Value = false;
            make_state_FControlPointMachinePosition__root__Operating__root__MovingLeft(self, &x->Operating.root);
            return;
        }
    }
    if (self->Change183.IsTriggered)
    {
        self->D35outDriveStop.Value = false;
        self->MemLastCommandedPointPosition = FControlPointMachinePosition_MemLastCommandedPointPositionValue__Left;
        if ((!(self->D2inRequiredPointPosition.Value ==
               map_D10inPmPosition_to_D2inRequiredPointPosition(self->D10inPmPosition.Value))) &&
            (self->D6inObservedAbilityToMovePoint.Value ==
             FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__AbleToMove))
        {
            self->D21outMoveLeft.Value = true;
            self->D40outMsgPmTimeout.Value = false;
            make_state_FControlPointMachinePosition__root__Operating__root__MovingLeft(self, &x->Operating.root);
            return;
        }
        else
        {
            self->D21outMoveLeft.Value = false;
            self->D22outMoveRight.Value = false;
            self->D35outDriveStop.Value = true;
            make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
            return;
        }
    }
    if (self->Change185.IsTriggered)
    {
        self->D35outDriveStop.Value = false;
        self->MemLastCommandedPointPosition = FControlPointMachinePosition_MemLastCommandedPointPositionValue__Right;
        if ((!(self->D2inRequiredPointPosition.Value ==
               map_D10inPmPosition_to_D2inRequiredPointPosition(self->D10inPmPosition.Value))) &&
            (self->D6inObservedAbilityToMovePoint.Value ==
             FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__AbleToMove))
        {
            self->D22outMoveRight.Value = true;
            self->D40outMsgPmTimeout.Value = false;
            make_state_FControlPointMachinePosition__root__Operating__root__MovingRight(self, &x->Operating.root);
            return;
        }
        else
        {
            self->D21outMoveLeft.Value = false;
            self->D22outMoveRight.Value = false;
            self->D35outDriveStop.Value = true;
            make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
            return;
        }
    }
}

void transition_from_FControlPointMachinePosition__root__Operating__root__Waiting(
    FControlPointMachinePosition *self, FControlPointMachinePosition__root__state_struct *x)
{

    if (self->Change373.IsTriggered)
    {
        if ((self->D34inConActive.Value) && (self->D44inConDriveCapability.Value))
        {
            self->D21outMoveLeft.Value = false;
            self->D22outMoveRight.Value = false;
            self->D35outDriveStop.Value = true;
            make_state_FControlPointMachinePosition__root__Operating__root__Stopped(self, &x->Operating.root);
            return;
        }
    }
}

void transition_from_FControlPointMachinePosition__root__Operating__root(
    FControlPointMachinePosition *self, FControlPointMachinePosition__root__state_struct *x)
{
    switch (x->Operating.root.state)
    {
    case FControlPointMachinePosition__root__Operating__root__MovingLeft:
        transition_from_FControlPointMachinePosition__root__Operating__root__MovingLeft(self, x);
        break;
    case FControlPointMachinePosition__root__Operating__root__MovingRight:
        transition_from_FControlPointMachinePosition__root__Operating__root__MovingRight(self, x);
        break;
    case FControlPointMachinePosition__root__Operating__root__Stopped:
        transition_from_FControlPointMachinePosition__root__Operating__root__Stopped(self, x);
        break;
    case FControlPointMachinePosition__root__Operating__root__Waiting:
        transition_from_FControlPointMachinePosition__root__Operating__root__Waiting(self, x);
        break;
    }
}

void transition_from_FControlPointMachinePosition__root__Operating(FControlPointMachinePosition *self,
                                                                   FControlPointMachinePosition__root__state_struct *x)
{
    transition_from_FControlPointMachinePosition__root__Operating__root(self, x);
    if (self->Change387.IsTriggered)
    {
        self->MemLastCommandedPointPosition =
            FControlPointMachinePosition_MemLastCommandedPointPositionValue__Undefined;
        self->D21outMoveLeft.Value = false;
        self->D22outMoveRight.Value = false;
        make_state_FControlPointMachinePosition__root__Operating(self, x);
        return;
    }
}

void transition_from_FControlPointMachinePosition__root(FControlPointMachinePosition *self,
                                                        FControlPointMachinePosition__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlPointMachinePosition__root__Operating:
        transition_from_FControlPointMachinePosition__root__Operating(self, x);
        break;
    }
}

static void evaluateChangeEvents(FControlPointMachinePosition *self)
{
    self->Change34.IsTriggered =
        IsTriggered(MakeChange(self->D10inPmPosition.IsSignalled,
                               self->D10inPmPosition.Value == map_MemLastCommandedPointPosition_to_D10inPmPosition(
                                                                  self->MemLastCommandedPointPosition)));
    self->Change188.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D2inRequiredPointPosition.IsSignalled,
                             self->D2inRequiredPointPosition.Value ==
                                 FControlPointMachinePosition_D2inRequiredPointPositionValue__Right),
                  MakeChange(self->D2inRequiredPointPosition.IsSignalled || self->D10inPmPosition.IsSignalled,
                             !(self->D2inRequiredPointPosition.Value ==
                               map_D10inPmPosition_to_D2inRequiredPointPosition(self->D10inPmPosition.Value)))));
    self->Change189.IsTriggered =
        IsTriggered(MakeChange(self->D2inRequiredPointPosition.IsSignalled,
                               self->D2inRequiredPointPosition.Value ==
                                   FControlPointMachinePosition_D2inRequiredPointPositionValue__Uncommanded));
    self->Change192.IsTriggered =
        IsTriggered(MakeChange(self->D2inRequiredPointPosition.IsSignalled || self->D10inPmPosition.IsSignalled,
                               self->D2inRequiredPointPosition.Value ==
                                   map_D10inPmPosition_to_D2inRequiredPointPosition(self->D10inPmPosition.Value)));
    self->Change460.IsTriggered =
        IsTriggered(MakeChange(self->D6inObservedAbilityToMovePoint.IsSignalled,
                               self->D6inObservedAbilityToMovePoint.Value ==
                                   FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__UnableToMove));
    self->Change33.IsTriggered =
        IsTriggered(MakeChange(self->D10inPmPosition.IsSignalled,
                               self->D10inPmPosition.Value == map_MemLastCommandedPointPosition_to_D10inPmPosition(
                                                                  self->MemLastCommandedPointPosition)));
    self->Change184.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D2inRequiredPointPosition.IsSignalled,
                             self->D2inRequiredPointPosition.Value ==
                                 FControlPointMachinePosition_D2inRequiredPointPositionValue__Left),
                  MakeChange(self->D2inRequiredPointPosition.IsSignalled || self->D10inPmPosition.IsSignalled,
                             !(self->D2inRequiredPointPosition.Value ==
                               map_D10inPmPosition_to_D2inRequiredPointPosition(self->D10inPmPosition.Value)))));
    self->Change190.IsTriggered =
        IsTriggered(MakeChange(self->D2inRequiredPointPosition.IsSignalled,
                               self->D2inRequiredPointPosition.Value ==
                                   FControlPointMachinePosition_D2inRequiredPointPositionValue__Uncommanded));
    self->Change191.IsTriggered =
        IsTriggered(MakeChange(self->D2inRequiredPointPosition.IsSignalled || self->D10inPmPosition.IsSignalled,
                               self->D2inRequiredPointPosition.Value ==
                                   map_D10inPmPosition_to_D2inRequiredPointPosition(self->D10inPmPosition.Value)));
    self->Change461.IsTriggered =
        IsTriggered(MakeChange(self->D6inObservedAbilityToMovePoint.IsSignalled,
                               self->D6inObservedAbilityToMovePoint.Value ==
                                   FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__UnableToMove));
    self->Change31.IsTriggered = IsTriggered(
        MakeChange(self->D10inPmPosition.IsSignalled,
                   self->D10inPmPosition.Value == FControlPointMachinePosition_D10inPmPositionValue__NoEndPosition));
    self->Change32.IsTriggered = IsTriggered(
        MakeChange(self->D10inPmPosition.IsSignalled,
                   self->D10inPmPosition.Value == FControlPointMachinePosition_D10inPmPositionValue__NoEndPosition));
    self->Change183.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredPointPosition.IsSignalled,
        self->D2inRequiredPointPosition.Value == FControlPointMachinePosition_D2inRequiredPointPositionValue__Left));
    self->Change185.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredPointPosition.IsSignalled,
        self->D2inRequiredPointPosition.Value == FControlPointMachinePosition_D2inRequiredPointPositionValue__Right));
    self->Change373.IsTriggered = IsTriggered(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlPointMachinePosition_D51inEstEfesStateValue__Initialising));
    self->Change387.IsTriggered = IsTriggered(
        OrChange(OrChange(MakeChange(self->D51inEstEfesState.IsSignalled,
                                     self->D51inEstEfesState.Value ==
                                         FControlPointMachinePosition_D51inEstEfesStateValue__NoOperatingVoltage),
                          MakeChange(self->D51inEstEfesState.IsSignalled,
                                     self->D51inEstEfesState.Value ==
                                         FControlPointMachinePosition_D51inEstEfesStateValue__Booting)),
                 MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value ==
                                FControlPointMachinePosition_D51inEstEfesStateValue__FallbackMode)));
}

static void resetOutputs(FControlPointMachinePosition *self)
{

    self->D35outDriveStop.IsSignalled = false;
    self->D21outMoveLeft.IsSignalled = false;
    self->D22outMoveRight.IsSignalled = false;
    self->D40outMsgPmTimeout.IsSignalled = false;
}

static void resetTriggers(FControlPointMachinePosition *self)
{

    self->D2inRequiredPointPosition.IsSignalled = false;
    self->D29inConUseRedrive.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
    self->D10inPmPosition.IsSignalled = false;
    self->D34inConActive.IsSignalled = false;
    self->D44inConDriveCapability.IsSignalled = false;
    self->D6inObservedAbilityToMovePoint.IsSignalled = false;
    self->D39inConTmaxPmOperation.IsSignalled = false;
    self->D41inObservedPointEndPosition.IsSignalled = false;

    self->Time28.IsTimeoutExpired = false;
    self->Time29.IsTimeoutExpired = false;
}

void transition_FControlPointMachinePosition(FControlPointMachinePosition *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FControlPointMachinePosition__root(self, &self->state);
    resetTriggers(self);
}

void new_FControlPointMachinePosition(FControlPointMachinePosition *self)
{
    make_state_FControlPointMachinePosition__root(self, &self->state);
}
