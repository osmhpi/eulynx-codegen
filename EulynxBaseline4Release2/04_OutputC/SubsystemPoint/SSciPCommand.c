
#include "SSciPCommand.h"

// Value Conversion Functions

// Operations

void make_state_SSciPCommand__root__SendingCommands(SSciPCommand *self, SSciPCommand__root__state_struct *region)
{
    LOG("[SSciPCommand] Entering state SendingCommands in region root");
    region->state = SSciPCommand__root__SendingCommands;
};

void make_state_SSciPCommand__root(SSciPCommand *self, SSciPCommand__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciPCommand__root__state_struct));

    make_state_SSciPCommand__root__SendingCommands(self, x);
    return;
}

void transition_from_SSciPCommand__root__SendingCommands(SSciPCommand *self, SSciPCommand__root__state_struct *x)
{

    if (self->Change874.IsTriggered)
    {
        if ((self->D2inMovePoint.Value == SSciPCommand_D2inMovePointValue__Right) &&
            (self->D50inPdiConnectionState.Value == SSciPCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdMovePoint__342e.Value.CommandedPointPositionState = PointPositionControlableState__14bc__Right;
            self->OutCdMovePoint__342e.HasMessage = 1;
            make_state_SSciPCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change875.IsTriggered)
    {
        if ((self->D2inMovePoint.Value == SSciPCommand_D2inMovePointValue__Left) &&
            (self->D50inPdiConnectionState.Value == SSciPCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdMovePoint__342e.Value.CommandedPointPositionState = PointPositionControlableState__14bc__Left;
            self->OutCdMovePoint__342e.HasMessage = 1;
            make_state_SSciPCommand__root__SendingCommands(self, x);
            return;
        }
    }
}

void transition_from_SSciPCommand__root(SSciPCommand *self, SSciPCommand__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciPCommand__root__SendingCommands:
        transition_from_SSciPCommand__root__SendingCommands(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciPCommand *self)
{
    self->Change874.IsTriggered = self->T1inMovePoint.IsTriggered;
    self->Change875.IsTriggered = self->T1inMovePoint.IsTriggered;
}

static void resetOutputs(SSciPCommand *self)
{
    self->OutCdMovePoint__342e.HasMessage = false;
}

static void resetTriggers(SSciPCommand *self)
{

    self->T1inMovePoint.IsTriggered = false;

    self->D2inMovePoint.IsSignalled = false;
    self->D50inPdiConnectionState.IsSignalled = false;
}

void transition_SSciPCommand(SSciPCommand *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciPCommand__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciPCommand(SSciPCommand *self)
{
    make_state_SSciPCommand__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemPoint/SSciPCommand.c"
#endif
