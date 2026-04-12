
#include "FControlNon4wPm.h"

// Value Conversion Functions

static FControlNon4wPm_D12inRequiredPmPositionValue map_D35inPmPosition_to_D12inRequiredPmPosition(
    FControlNon4wPm_D35inPmPositionValue value)
{
    switch (value)
    {
    case FControlNon4wPm_D35inPmPositionValue__NULL__:
        return FControlNon4wPm_D12inRequiredPmPositionValue__NULL__;
    case FControlNon4wPm_D35inPmPositionValue__UNKNOWN__:
        return FControlNon4wPm_D12inRequiredPmPositionValue__UNKNOWN__;
    case FControlNon4wPm_D35inPmPositionValue__Right:
        return FControlNon4wPm_D12inRequiredPmPositionValue__Right;
    case FControlNon4wPm_D35inPmPositionValue__Uncommanded:
        return FControlNon4wPm_D12inRequiredPmPositionValue__Uncommanded;
    case FControlNon4wPm_D35inPmPositionValue__Left:
        return FControlNon4wPm_D12inRequiredPmPositionValue__Left;
    default:
        abort();
    }
}

// Operations

void make_state_FControlNon4wPm__root__Operating__root__MovingLeft(
    FControlNon4wPm *self, FControlNon4wPm__root__Operating__root__state_struct *region)
{
    LOG("[FControlNon4wPm] Entering state MovingLeft in region root__Operating__root");
    region->state = FControlNon4wPm__root__Operating__root__MovingLeft;
};

void make_state_FControlNon4wPm__root__Operating__root__MovingRight(
    FControlNon4wPm *self, FControlNon4wPm__root__Operating__root__state_struct *region)
{
    LOG("[FControlNon4wPm] Entering state MovingRight in region root__Operating__root");
    region->state = FControlNon4wPm__root__Operating__root__MovingRight;
};

void make_state_FControlNon4wPm__root__Operating__root__Stopped(
    FControlNon4wPm *self, FControlNon4wPm__root__Operating__root__state_struct *region)
{
    LOG("[FControlNon4wPm] Entering state Stopped in region root__Operating__root");
    region->state = FControlNon4wPm__root__Operating__root__Stopped;
};

void make_state_FControlNon4wPm__root__Operating__root__Waiting(
    FControlNon4wPm *self, FControlNon4wPm__root__Operating__root__state_struct *region)
{
    LOG("[FControlNon4wPm] Entering state Waiting in region root__Operating__root");
    region->state = FControlNon4wPm__root__Operating__root__Waiting;
};

void make_state_FControlNon4wPm__root__Operating__root(FControlNon4wPm *self,
                                                       FControlNon4wPm__root__Operating__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlNon4wPm__root__Operating__root__state_struct));

    make_state_FControlNon4wPm__root__Operating__root__Waiting(self, x);
    return;
}

void make_state_FControlNon4wPm__root__Operating(FControlNon4wPm *self, FControlNon4wPm__root__state_struct *region)
{
    LOG("[FControlNon4wPm] Entering state Operating in region root");
    region->state = FControlNon4wPm__root__Operating;
    make_state_FControlNon4wPm__root__Operating__root(self, &region->Operating.root);
};

void make_state_FControlNon4wPm__root(FControlNon4wPm *self, FControlNon4wPm__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlNon4wPm__root__state_struct));
    self->D39outMoveLeft.Value = false;
    self->D38outMoveRight.Value = false;
    self->D34outDriveStop.Value = true;
    make_state_FControlNon4wPm__root__Operating(self, x);
    return;
}

void transition_from_FControlNon4wPm__root__Operating__root__MovingLeft(FControlNon4wPm *self,
                                                                        FControlNon4wPm__root__state_struct *x)
{

    if (self->Change75.IsTriggered)
    {
        if ((!(self->D12inRequiredPmPosition.Value ==
               map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value))) ||
            ((self->D12inRequiredPmPosition.Value ==
              map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value)) &&
             (self->D37inConCommonDrive.Value)))
        {
            self->D39outMoveLeft.Value = false;
            self->D38outMoveRight.Value = true;
            self->D34outDriveStop.Value = false;
            make_state_FControlNon4wPm__root__Operating__root__MovingRight(self, &x->Operating.root);
            return;
        }
    }
    if (self->Change85.IsTriggered)
    {
        self->D39outMoveLeft.Value = false;
        self->D38outMoveRight.Value = false;
        self->D34outDriveStop.Value = true;
        make_state_FControlNon4wPm__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change88.IsTriggered)
    {
        if (!(self->D37inConCommonDrive.Value))
        {
            self->D39outMoveLeft.Value = false;
            self->D38outMoveRight.Value = false;
            self->D34outDriveStop.Value = true;
            make_state_FControlNon4wPm__root__Operating__root__Stopped(self, &x->Operating.root);
            return;
        }
    }
}

void transition_from_FControlNon4wPm__root__Operating__root__MovingRight(FControlNon4wPm *self,
                                                                         FControlNon4wPm__root__state_struct *x)
{

    if (self->Change69.IsTriggered)
    {
        if ((!(self->D12inRequiredPmPosition.Value ==
               map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value))) ||
            ((self->D12inRequiredPmPosition.Value ==
              map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value)) &&
             (self->D37inConCommonDrive.Value)))
        {
            self->D38outMoveRight.Value = false;
            self->D39outMoveLeft.Value = true;
            self->D34outDriveStop.Value = false;
            make_state_FControlNon4wPm__root__Operating__root__MovingLeft(self, &x->Operating.root);
            return;
        }
    }
    if (self->Change86.IsTriggered)
    {
        self->D39outMoveLeft.Value = false;
        self->D38outMoveRight.Value = false;
        self->D34outDriveStop.Value = true;
        make_state_FControlNon4wPm__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
    if (self->Change87.IsTriggered)
    {
        if (!(self->D37inConCommonDrive.Value))
        {
            self->D39outMoveLeft.Value = false;
            self->D38outMoveRight.Value = false;
            self->D34outDriveStop.Value = true;
            make_state_FControlNon4wPm__root__Operating__root__Stopped(self, &x->Operating.root);
            return;
        }
    }
}

void transition_from_FControlNon4wPm__root__Operating__root__Stopped(FControlNon4wPm *self,
                                                                     FControlNon4wPm__root__state_struct *x)
{

    if (self->Change72.IsTriggered)
    {
        if ((self->D40inConActive.Value) && (self->D36inConDriveCapability.Value))
        {
            self->D39outMoveLeft.Value = true;
            self->D34outDriveStop.Value = false;
            make_state_FControlNon4wPm__root__Operating__root__MovingLeft(self, &x->Operating.root);
            return;
        }
    }
    if (self->Change79.IsTriggered)
    {
        if ((self->D40inConActive.Value) && (self->D36inConDriveCapability.Value))
        {
            self->D38outMoveRight.Value = true;
            self->D34outDriveStop.Value = false;
            make_state_FControlNon4wPm__root__Operating__root__MovingRight(self, &x->Operating.root);
            return;
        }
    }
}

void transition_from_FControlNon4wPm__root__Operating__root__Waiting(FControlNon4wPm *self,
                                                                     FControlNon4wPm__root__state_struct *x)
{

    if (self->Change361.IsTriggered)
    {
        self->D39outMoveLeft.Value = false;
        self->D38outMoveRight.Value = false;
        self->D34outDriveStop.Value = true;
        make_state_FControlNon4wPm__root__Operating__root__Stopped(self, &x->Operating.root);
        return;
    }
}

void transition_from_FControlNon4wPm__root__Operating__root(FControlNon4wPm *self,
                                                            FControlNon4wPm__root__state_struct *x)
{
    switch (x->Operating.root.state)
    {
    case FControlNon4wPm__root__Operating__root__MovingLeft:
        transition_from_FControlNon4wPm__root__Operating__root__MovingLeft(self, x);
        break;
    case FControlNon4wPm__root__Operating__root__MovingRight:
        transition_from_FControlNon4wPm__root__Operating__root__MovingRight(self, x);
        break;
    case FControlNon4wPm__root__Operating__root__Stopped:
        transition_from_FControlNon4wPm__root__Operating__root__Stopped(self, x);
        break;
    case FControlNon4wPm__root__Operating__root__Waiting:
        transition_from_FControlNon4wPm__root__Operating__root__Waiting(self, x);
        break;
    }
}

void transition_from_FControlNon4wPm__root__Operating(FControlNon4wPm *self, FControlNon4wPm__root__state_struct *x)
{
    transition_from_FControlNon4wPm__root__Operating__root(self, x);
    if (self->Change370.IsTriggered)
    {
        self->D39outMoveLeft.Value = false;
        self->D38outMoveRight.Value = false;
        self->D34outDriveStop.Value = true;
        make_state_FControlNon4wPm__root__Operating(self, x);
        return;
    }
}

void transition_from_FControlNon4wPm__root(FControlNon4wPm *self, FControlNon4wPm__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlNon4wPm__root__Operating:
        transition_from_FControlNon4wPm__root__Operating(self, x);
        break;
    }
}

static void evaluateChangeEvents(FControlNon4wPm *self)
{
    self->Change75.IsTriggered = IsTriggered(
        MakeChange(self->D12inRequiredPmPosition.IsSignalled,
                   self->D12inRequiredPmPosition.Value == FControlNon4wPm_D12inRequiredPmPositionValue__Right));
    self->Change85.IsTriggered = IsTriggered(
        MakeChange(self->D12inRequiredPmPosition.IsSignalled,
                   self->D12inRequiredPmPosition.Value == FControlNon4wPm_D12inRequiredPmPositionValue__Uncommanded));
    self->Change88.IsTriggered =
        IsTriggered(MakeChange(self->D12inRequiredPmPosition.IsSignalled || self->D35inPmPosition.IsSignalled,
                               self->D12inRequiredPmPosition.Value ==
                                   map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value)));
    self->Change69.IsTriggered = IsTriggered(
        MakeChange(self->D12inRequiredPmPosition.IsSignalled,
                   self->D12inRequiredPmPosition.Value == FControlNon4wPm_D12inRequiredPmPositionValue__Left));
    self->Change86.IsTriggered = IsTriggered(
        MakeChange(self->D12inRequiredPmPosition.IsSignalled,
                   self->D12inRequiredPmPosition.Value == FControlNon4wPm_D12inRequiredPmPositionValue__Uncommanded));
    self->Change87.IsTriggered =
        IsTriggered(MakeChange(self->D12inRequiredPmPosition.IsSignalled || self->D35inPmPosition.IsSignalled,
                               self->D12inRequiredPmPosition.Value ==
                                   map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value)));
    self->Change72.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D12inRequiredPmPosition.IsSignalled,
                   self->D12inRequiredPmPosition.Value == FControlNon4wPm_D12inRequiredPmPositionValue__Left),
        OrChange(MakeChange(self->D12inRequiredPmPosition.IsSignalled || self->D35inPmPosition.IsSignalled,
                            !(self->D12inRequiredPmPosition.Value ==
                              map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value))),
                 AndChange(MakeChange(self->D12inRequiredPmPosition.IsSignalled || self->D35inPmPosition.IsSignalled,
                                      self->D12inRequiredPmPosition.Value ==
                                          map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value)),
                           MakeChange(self->D37inConCommonDrive.IsSignalled, self->D37inConCommonDrive.Value)))));
    self->Change79.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D12inRequiredPmPosition.IsSignalled,
                   self->D12inRequiredPmPosition.Value == FControlNon4wPm_D12inRequiredPmPositionValue__Right),
        OrChange(MakeChange(self->D12inRequiredPmPosition.IsSignalled || self->D35inPmPosition.IsSignalled,
                            !(self->D12inRequiredPmPosition.Value ==
                              map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value))),
                 AndChange(MakeChange(self->D12inRequiredPmPosition.IsSignalled || self->D35inPmPosition.IsSignalled,
                                      self->D12inRequiredPmPosition.Value ==
                                          map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value)),
                           MakeChange(self->D37inConCommonDrive.IsSignalled, self->D37inConCommonDrive.Value)))));
    self->Change361.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value == FControlNon4wPm_D51inEstEfesStateValue__Initialising));
    self->Change370.IsTriggered = IsTriggered(
        OrChange(OrChange(MakeChange(self->D51inEstEfesState.IsSignalled,
                                     self->D51inEstEfesState.Value ==
                                         FControlNon4wPm_D51inEstEfesStateValue__NoOperatingVoltage),
                          MakeChange(self->D51inEstEfesState.IsSignalled,
                                     self->D51inEstEfesState.Value == FControlNon4wPm_D51inEstEfesStateValue__Booting)),
                 MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value == FControlNon4wPm_D51inEstEfesStateValue__FallbackMode)));
}

static void resetOutputs(FControlNon4wPm *self)
{

    self->D34outDriveStop.IsSignalled = false;
    self->D39outMoveLeft.IsSignalled = false;
    self->D38outMoveRight.IsSignalled = false;
}

static void resetTriggers(FControlNon4wPm *self)
{

    self->D12inRequiredPmPosition.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
    self->D35inPmPosition.IsSignalled = false;
    self->D40inConActive.IsSignalled = false;
    self->D36inConDriveCapability.IsSignalled = false;
    self->D37inConCommonDrive.IsSignalled = false;
}

void transition_FControlNon4wPm(FControlNon4wPm *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FControlNon4wPm__root(self, &self->state);
    resetTriggers(self);
}

void new_FControlNon4wPm(FControlNon4wPm *self)
{
    make_state_FControlNon4wPm__root(self, &self->state);
}
