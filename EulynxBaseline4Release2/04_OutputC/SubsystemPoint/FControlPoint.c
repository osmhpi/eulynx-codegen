
#include "FControlPoint.h"

// Value Conversion Functions

static FControlPoint_D10inRequiredPointPositionValue map_D14inObservedPointPosition_to_D10inRequiredPointPosition(
    FControlPoint_D14inObservedPointPositionValue value)
{
    switch (value)
    {
    case FControlPoint_D14inObservedPointPositionValue__NULL__:
        return FControlPoint_D10inRequiredPointPositionValue__NULL__;
    case FControlPoint_D14inObservedPointPositionValue__UNKNOWN__:
        return FControlPoint_D10inRequiredPointPositionValue__UNKNOWN__;
    case FControlPoint_D14inObservedPointPositionValue__Right:
        return FControlPoint_D10inRequiredPointPositionValue__Right;
    case FControlPoint_D14inObservedPointPositionValue__Uncommanded:
        return FControlPoint_D10inRequiredPointPositionValue__Uncommanded;
    case FControlPoint_D14inObservedPointPositionValue__Left:
        return FControlPoint_D10inRequiredPointPositionValue__Left;
    default:
        abort();
    }
}
static FControlPoint_D14inObservedPointPositionValue map_D10inRequiredPointPosition_to_D14inObservedPointPosition(
    FControlPoint_D10inRequiredPointPositionValue value)
{
    switch (value)
    {
    case FControlPoint_D10inRequiredPointPositionValue__NULL__:
        return FControlPoint_D14inObservedPointPositionValue__NULL__;
    case FControlPoint_D10inRequiredPointPositionValue__UNKNOWN__:
        return FControlPoint_D14inObservedPointPositionValue__UNKNOWN__;
    case FControlPoint_D10inRequiredPointPositionValue__Right:
        return FControlPoint_D14inObservedPointPositionValue__Right;
    case FControlPoint_D10inRequiredPointPositionValue__Uncommanded:
        return FControlPoint_D14inObservedPointPositionValue__Uncommanded;
    case FControlPoint_D10inRequiredPointPositionValue__Left:
        return FControlPoint_D14inObservedPointPositionValue__Left;
    default:
        abort();
    }
}
static FControlPoint_D14inObservedPointPositionValue map_MemLastRequiredPointPosition_to_D14inObservedPointPosition(
    FControlPoint_MemLastRequiredPointPositionValue value)
{
    switch (value)
    {
    case FControlPoint_MemLastRequiredPointPositionValue__NULL__:
        return FControlPoint_D14inObservedPointPositionValue__NULL__;
    case FControlPoint_MemLastRequiredPointPositionValue__UNKNOWN__:
        return FControlPoint_D14inObservedPointPositionValue__UNKNOWN__;
    case FControlPoint_MemLastRequiredPointPositionValue__Uncommanded:
        return FControlPoint_D14inObservedPointPositionValue__Uncommanded;
    case FControlPoint_MemLastRequiredPointPositionValue__Left:
        return FControlPoint_D14inObservedPointPositionValue__Left;
    case FControlPoint_MemLastRequiredPointPositionValue__Right:
        return FControlPoint_D14inObservedPointPositionValue__Right;
    default:
        abort();
    }
}
static FControlPoint_MemLastRequiredPointPositionValue map_D14inObservedPointPosition_to_MemLastRequiredPointPosition(
    FControlPoint_D14inObservedPointPositionValue value)
{
    switch (value)
    {
    case FControlPoint_D14inObservedPointPositionValue__NULL__:
        return FControlPoint_MemLastRequiredPointPositionValue__NULL__;
    case FControlPoint_D14inObservedPointPositionValue__UNKNOWN__:
        return FControlPoint_MemLastRequiredPointPositionValue__UNKNOWN__;
    case FControlPoint_D14inObservedPointPositionValue__Right:
        return FControlPoint_MemLastRequiredPointPositionValue__Right;
    case FControlPoint_D14inObservedPointPositionValue__Uncommanded:
        return FControlPoint_MemLastRequiredPointPositionValue__Uncommanded;
    case FControlPoint_D14inObservedPointPositionValue__Left:
        return FControlPoint_MemLastRequiredPointPositionValue__Left;
    default:
        abort();
    }
}

// Operations

void make_state_FControlPoint__root__Operating__root__MovingLeft(
    FControlPoint *self, FControlPoint__root__Operating__root__state_struct *region)
{
    LOG("[FControlPoint] Entering state MovingLeft in region root__Operating__root");
    region->state = FControlPoint__root__Operating__root__MovingLeft;
};

void make_state_FControlPoint__root__Operating__root__MovingRight(
    FControlPoint *self, FControlPoint__root__Operating__root__state_struct *region)
{
    LOG("[FControlPoint] Entering state MovingRight in region root__Operating__root");
    region->state = FControlPoint__root__Operating__root__MovingRight;
};

void make_state_FControlPoint__root__Operating__root__Stopped(
    FControlPoint *self, FControlPoint__root__Operating__root__state_struct *region)
{
    LOG("[FControlPoint] Entering state Stopped in region root__Operating__root");
    region->state = FControlPoint__root__Operating__root__Stopped;
};

void make_state_FControlPoint__root__Operating__root__Waiting(
    FControlPoint *self, FControlPoint__root__Operating__root__state_struct *region)
{
    LOG("[FControlPoint] Entering state Waiting in region root__Operating__root");
    region->state = FControlPoint__root__Operating__root__Waiting;
};

void make_state_FControlPoint__root__Operating__root(FControlPoint *self,
                                                     FControlPoint__root__Operating__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlPoint__root__Operating__root__state_struct));

    make_state_FControlPoint__root__Operating__root__Waiting(self, x);
    return;
}

void make_state_FControlPoint__root__Operating(FControlPoint *self, FControlPoint__root__state_struct *region)
{
    LOG("[FControlPoint] Entering state Operating in region root");
    region->state = FControlPoint__root__Operating;
    make_state_FControlPoint__root__Operating__root(self, &region->Operating.root);
};

void make_state_FControlPoint__root(FControlPoint *self, FControlPoint__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlPoint__root__state_struct));
    self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
    self->D12outRequiredPmPosition.IsSignalled = true;
    self->MemLastRequiredPointPosition = FControlPoint_MemLastRequiredPointPositionValue__Uncommanded;
    make_state_FControlPoint__root__Operating(self, x);
    return;
}

void transition_from_FControlPoint__root__Operating__root__MovingLeft(FControlPoint *self,
                                                                      FControlPoint__root__state_struct *x)
{

    if (self->Change28.IsTriggered)
    {
        if (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove)
        {
            self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Right;
            self->D12outRequiredPmPosition.IsSignalled = true;
            make_state_FControlPoint__root__Operating__root__MovingRight(self, &x->Operating.root);
            return;
        }
    }
    if (self->Change30.IsTriggered)
    {
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        make_state_FControlPoint__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change33.IsTriggered)
    {
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        make_state_FControlPoint__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change89.IsTriggered)
    {
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        make_state_FControlPoint__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change107.IsTriggered)
    {
        self->MemLastRequiredPointPosition =
            map_D14inObservedPointPosition_to_MemLastRequiredPointPosition(self->D14inObservedPointPosition.Value);
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        make_state_FControlPoint__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change108.IsTriggered)
    {
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        make_state_FControlPoint__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
}

void transition_from_FControlPoint__root__Operating__root__MovingRight(FControlPoint *self,
                                                                       FControlPoint__root__state_struct *x)
{

    if (self->Change26.IsTriggered)
    {
        if (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove)
        {
            self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Left;
            self->D12outRequiredPmPosition.IsSignalled = true;
            make_state_FControlPoint__root__Operating__root__MovingLeft(self, &x->Operating.root);
            return;
        }
    }
    if (self->Change29.IsTriggered)
    {
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        make_state_FControlPoint__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change35.IsTriggered)
    {
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        make_state_FControlPoint__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change88.IsTriggered)
    {
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        make_state_FControlPoint__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change106.IsTriggered)
    {
        self->MemLastRequiredPointPosition =
            map_D14inObservedPointPosition_to_MemLastRequiredPointPosition(self->D14inObservedPointPosition.Value);
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        make_state_FControlPoint__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change109.IsTriggered)
    {
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        make_state_FControlPoint__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
}

void transition_from_FControlPoint__root__Operating__root__Stopped(FControlPoint *self,
                                                                   FControlPoint__root__state_struct *x)
{

    if (self->Change25.IsTriggered)
    {
        if ((!(self->D10inRequiredPointPosition.Value ==
               map_D14inObservedPointPosition_to_D10inRequiredPointPosition(self->D14inObservedPointPosition.Value))) &&
            (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove))
        {
            self->MemLastRequiredPointPosition = FControlPoint_MemLastRequiredPointPositionValue__Left;
            self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Left;
            self->D12outRequiredPmPosition.IsSignalled = true;
            make_state_FControlPoint__root__Operating__root__MovingLeft(self, &x->Operating.root);
            return;
        }
    }
    if (self->Change27.IsTriggered)
    {
        if ((!(self->D10inRequiredPointPosition.Value ==
               map_D14inObservedPointPosition_to_D10inRequiredPointPosition(self->D14inObservedPointPosition.Value))) &&
            (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove))
        {
            self->MemLastRequiredPointPosition = FControlPoint_MemLastRequiredPointPositionValue__Right;
            self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Right;
            self->D12outRequiredPmPosition.IsSignalled = true;
            make_state_FControlPoint__root__Operating__root__MovingRight(self, &x->Operating.root);
            return;
        }
    }
    if (self->Change105.IsTriggered)
    {
        if (((self->MemLastRequiredPointPosition == FControlPoint_MemLastRequiredPointPositionValue__Right) &&
             (self->D18inConUseRedrive.Value)) &&
            (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove))
        {
            self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Right;
            self->D12outRequiredPmPosition.IsSignalled = true;
            make_state_FControlPoint__root__Operating__root__MovingRight(self, &x->Operating.root);
            return;
        }
    }
    if (self->Change104.IsTriggered)
    {
        if (((self->MemLastRequiredPointPosition == FControlPoint_MemLastRequiredPointPositionValue__Left) &&
             (self->D18inConUseRedrive.Value)) &&
            (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove))
        {
            self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Left;
            self->D12outRequiredPmPosition.IsSignalled = true;
            make_state_FControlPoint__root__Operating__root__MovingLeft(self, &x->Operating.root);
            return;
        }
    }
}

void transition_from_FControlPoint__root__Operating__root__Waiting(FControlPoint *self,
                                                                   FControlPoint__root__state_struct *x)
{

    if (self->Change380.IsTriggered)
    {
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        make_state_FControlPoint__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
}

void transition_from_FControlPoint__root__Operating__root(FControlPoint *self, FControlPoint__root__state_struct *x)
{
    switch (x->Operating.root.state)
    {
    case FControlPoint__root__Operating__root__MovingLeft:
        transition_from_FControlPoint__root__Operating__root__MovingLeft(self, x);
        break;
    case FControlPoint__root__Operating__root__MovingRight:
        transition_from_FControlPoint__root__Operating__root__MovingRight(self, x);
        break;
    case FControlPoint__root__Operating__root__Stopped:
        transition_from_FControlPoint__root__Operating__root__Stopped(self, x);
        break;
    case FControlPoint__root__Operating__root__Waiting:
        transition_from_FControlPoint__root__Operating__root__Waiting(self, x);
        break;
    }
}

void transition_from_FControlPoint__root__Operating(FControlPoint *self, FControlPoint__root__state_struct *x)
{
    transition_from_FControlPoint__root__Operating__root(self, x);
    if (self->Change390.IsTriggered)
    {
        self->D12outRequiredPmPosition.Value = FControlPoint_D12outRequiredPmPositionValue__Uncommanded;
        self->D12outRequiredPmPosition.IsSignalled = true;
        self->MemLastRequiredPointPosition = FControlPoint_MemLastRequiredPointPositionValue__Uncommanded;
        make_state_FControlPoint__root__Operating(self, x);
        return;
    }
}

void transition_from_FControlPoint__root(FControlPoint *self, FControlPoint__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlPoint__root__Operating:
        transition_from_FControlPoint__root__Operating(self, x);
        break;
    }
}

static void evaluateChangeEvents(FControlPoint *self)
{
    self->Change28.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D10inRequiredPointPosition.IsSignalled,
                   self->D10inRequiredPointPosition.Value == FControlPoint_D10inRequiredPointPositionValue__Right),
        MakeChange(
            self->D10inRequiredPointPosition.IsSignalled || self->D14inObservedPointPosition.IsSignalled,
            !(self->D10inRequiredPointPosition.Value ==
              map_D14inObservedPointPosition_to_D10inRequiredPointPosition(self->D14inObservedPointPosition.Value)))));
    self->Change30.IsTriggered = IsTriggered(MakeChange(
        self->D10inRequiredPointPosition.IsSignalled,
        self->D10inRequiredPointPosition.Value == FControlPoint_D10inRequiredPointPositionValue__Uncommanded));
    self->Change33.IsTriggered = IsTriggered(MakeChange(
        self->D11inObservedAbilityToMove.IsSignalled,
        self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__UnableToMove));
    self->Change89.IsTriggered =
        IsTriggered(MakeChange(self->D13inObservedMovementFailed.IsSignalled, self->D13inObservedMovementFailed.Value));
    self->Change107.IsTriggered = IsTriggered(MakeChange(
        self->D14inObservedPointPosition.IsSignalled || self->D10inRequiredPointPosition.IsSignalled,
        self->D14inObservedPointPosition.Value ==
            map_D10inRequiredPointPosition_to_D14inObservedPointPosition(self->D10inRequiredPointPosition.Value)));
    self->Change108.IsTriggered = IsTriggered(MakeChange(
        self->D14inObservedPointPosition.IsSignalled,
        self->D14inObservedPointPosition.Value ==
            map_MemLastRequiredPointPosition_to_D14inObservedPointPosition(self->MemLastRequiredPointPosition)));
    self->Change26.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D10inRequiredPointPosition.IsSignalled,
                   self->D10inRequiredPointPosition.Value == FControlPoint_D10inRequiredPointPositionValue__Left),
        MakeChange(
            self->D10inRequiredPointPosition.IsSignalled || self->D14inObservedPointPosition.IsSignalled,
            !(self->D10inRequiredPointPosition.Value ==
              map_D14inObservedPointPosition_to_D10inRequiredPointPosition(self->D14inObservedPointPosition.Value)))));
    self->Change29.IsTriggered = IsTriggered(MakeChange(
        self->D10inRequiredPointPosition.IsSignalled,
        self->D10inRequiredPointPosition.Value == FControlPoint_D10inRequiredPointPositionValue__Uncommanded));
    self->Change35.IsTriggered = IsTriggered(MakeChange(
        self->D11inObservedAbilityToMove.IsSignalled,
        self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__UnableToMove));
    self->Change88.IsTriggered =
        IsTriggered(MakeChange(self->D13inObservedMovementFailed.IsSignalled, self->D13inObservedMovementFailed.Value));
    self->Change106.IsTriggered = IsTriggered(MakeChange(
        self->D14inObservedPointPosition.IsSignalled || self->D10inRequiredPointPosition.IsSignalled,
        self->D14inObservedPointPosition.Value ==
            map_D10inRequiredPointPosition_to_D14inObservedPointPosition(self->D10inRequiredPointPosition.Value)));
    self->Change109.IsTriggered = IsTriggered(MakeChange(
        self->D14inObservedPointPosition.IsSignalled,
        self->D14inObservedPointPosition.Value ==
            map_MemLastRequiredPointPosition_to_D14inObservedPointPosition(self->MemLastRequiredPointPosition)));
    self->Change25.IsTriggered = IsTriggered(
        MakeChange(self->D10inRequiredPointPosition.IsSignalled,
                   self->D10inRequiredPointPosition.Value == FControlPoint_D10inRequiredPointPositionValue__Left));
    self->Change27.IsTriggered = IsTriggered(
        MakeChange(self->D10inRequiredPointPosition.IsSignalled,
                   self->D10inRequiredPointPosition.Value == FControlPoint_D10inRequiredPointPositionValue__Right));
    self->Change105.IsTriggered = IsTriggered(MakeChange(
        self->D14inObservedPointPosition.IsSignalled,
        !(self->D14inObservedPointPosition.Value ==
          map_MemLastRequiredPointPosition_to_D14inObservedPointPosition(self->MemLastRequiredPointPosition))));
    self->Change104.IsTriggered = IsTriggered(MakeChange(
        self->D14inObservedPointPosition.IsSignalled,
        !(self->D14inObservedPointPosition.Value ==
          map_MemLastRequiredPointPosition_to_D14inObservedPointPosition(self->MemLastRequiredPointPosition))));
    self->Change380.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value == FControlPoint_D51inEstEfesStateValue__Initialising));
    self->Change390.IsTriggered = IsTriggered(OrChange(
        OrChange(MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value == FControlPoint_D51inEstEfesStateValue__NoOperatingVoltage),
                 MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value == FControlPoint_D51inEstEfesStateValue__Booting)),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlPoint_D51inEstEfesStateValue__FallbackMode)));
}

static void resetOutputs(FControlPoint *self)
{

    self->D12outRequiredPmPosition.IsSignalled = false;
}

static void resetTriggers(FControlPoint *self)
{

    self->D10inRequiredPointPosition.IsSignalled = false;
    self->D18inConUseRedrive.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
    self->D14inObservedPointPosition.IsSignalled = false;
    self->D11inObservedAbilityToMove.IsSignalled = false;
    self->D13inObservedMovementFailed.IsSignalled = false;
}

void transition_FControlPoint(FControlPoint *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FControlPoint__root(self, &self->state);
    resetTriggers(self);
}

void new_FControlPoint(FControlPoint *self)
{
    make_state_FControlPoint__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemPoint/FControlPoint.c"
#endif
