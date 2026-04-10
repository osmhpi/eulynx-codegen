
#include "Hilfsblock.h"

// Value Conversion Functions

// Operations

void make_state_Hilfsblock__root__AtomicState(Hilfsblock *self, Hilfsblock__root__state_struct *region)
{
    LOG("[Hilfsblock] Entering state AtomicState in region root");
    region->state = Hilfsblock__root__AtomicState;
};

void make_state_Hilfsblock__root(Hilfsblock *self, Hilfsblock__root__state_struct *x)
{
    memset(x, 0, sizeof(Hilfsblock__root__state_struct));

    make_state_Hilfsblock__root__AtomicState(self, x);
    return;
}

void transition_from_Hilfsblock__root__AtomicState(Hilfsblock *self, Hilfsblock__root__state_struct *x)
{

    if (self->Change517.IsTriggered)
    {

        self->OutDataUpdateFinished__0937.HasMessage = 1;
        make_state_Hilfsblock__root__AtomicState(self, x);
        return;
    }
    if (self->Change518.IsTriggered)
    {

        self->OutMdmCommandedMaintenance__a992.HasMessage = 1;
        make_state_Hilfsblock__root__AtomicState(self, x);
        return;
    }
    if (self->Change519.IsTriggered)
    {

        self->OutRebootRequired__bc8e.HasMessage = 1;
        make_state_Hilfsblock__root__AtomicState(self, x);
        return;
    }
    if (self->Change520.IsTriggered)
    {

        self->OutMdmTriggeredReset__00d0.HasMessage = 1;
        make_state_Hilfsblock__root__AtomicState(self, x);
        return;
    }
    if (self->Change521.IsTriggered)
    {

        self->OutStatusReportCompleted__b457.HasMessage = 1;
        make_state_Hilfsblock__root__AtomicState(self, x);
        return;
    }
}

void transition_from_Hilfsblock__root(Hilfsblock *self, Hilfsblock__root__state_struct *x)
{
    switch (x->state)
    {
    case Hilfsblock__root__AtomicState:
        transition_from_Hilfsblock__root__AtomicState(self, x);
        break;
    }
}

static void evaluateChangeEvents(Hilfsblock *self)
{
    self->Change517.IsTriggered = self->HilffinishedDataUpdate.IsTriggered;
    self->Change518.IsTriggered = self->HilfmdmMaintenanceCommanded.IsTriggered;
    self->Change519.IsTriggered = self->HilfmdmRebootRequired.IsTriggered;
    self->Change520.IsTriggered = self->HilfmdmTriggeredReset.IsTriggered;
    self->Change521.IsTriggered = self->HilfstatusUpdateCompleted.IsTriggered;
}

static void resetOutputs(Hilfsblock *self)
{
    self->OutDataUpdateFinished__0937.HasMessage = false;
    self->OutMdmCommandedMaintenance__a992.HasMessage = false;
    self->OutRebootRequired__bc8e.HasMessage = false;
    self->OutMdmTriggeredReset__00d0.HasMessage = false;
    self->OutStatusReportCompleted__b457.HasMessage = false;
}

static void resetTriggers(Hilfsblock *self)
{

    self->HilfmdmMaintenanceCommanded.IsTriggered = false;
    self->HilffinishedDataUpdate.IsTriggered = false;
    self->HilfstatusUpdateCompleted.IsTriggered = false;
    self->HilfmdmRebootRequired.IsTriggered = false;
    self->HilfmdmTriggeredReset.IsTriggered = false;
}

void transition_Hilfsblock(Hilfsblock *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_Hilfsblock__root(self, &self->state);
    resetTriggers(self);
}

void new_Hilfsblock(Hilfsblock *self)
{
    make_state_Hilfsblock__root(self, &self->state);
}
