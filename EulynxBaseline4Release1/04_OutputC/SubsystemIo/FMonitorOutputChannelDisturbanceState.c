
#include "FMonitorOutputChannelDisturbanceState.h"

// Value Conversion Functions

// Operations

void make_state_FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed(
    FMonitorOutputChannelDisturbanceState *self, FMonitorOutputChannelDisturbanceState__root__state_struct *region)
{
    LOG("[FMonitorOutputChannelDisturbanceState] Entering state NotPhysicallyDisturbed in region root");
    region->state = FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed;
};

void make_state_FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed(
    FMonitorOutputChannelDisturbanceState *self, FMonitorOutputChannelDisturbanceState__root__state_struct *region)
{
    LOG("[FMonitorOutputChannelDisturbanceState] Entering state PhysicallyDisturbed in region root");
    region->state = FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed;
};

void make_state_FMonitorOutputChannelDisturbanceState__root(
    FMonitorOutputChannelDisturbanceState *self, FMonitorOutputChannelDisturbanceState__root__state_struct *x)
{
    memset(x, 0, sizeof(FMonitorOutputChannelDisturbanceState__root__state_struct));
    self->D9outMonitoredDisturbanceState.Value =
        FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue__NotPhysicallyDisturbed;
    self->D9outMonitoredDisturbanceState.IsSignalled = true;
    make_state_FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed(self, x);
    return;
}

void transition_from_FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed(
    FMonitorOutputChannelDisturbanceState *self, FMonitorOutputChannelDisturbanceState__root__state_struct *x)
{

    if (true)
    {
        self->D9outMonitoredDisturbanceState.Value =
            FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue__PhysicallyDisturbed;
        self->D9outMonitoredDisturbanceState.IsSignalled = true;
        make_state_FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed(self, x);
        return;
    }
    if (true)
    {
        self->D9outMonitoredDisturbanceState.Value =
            FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue__PhysicallyDisturbed;
        self->D9outMonitoredDisturbanceState.IsSignalled = true;
        make_state_FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed(self, x);
        return;
    }
    if (self->Change279.IsTriggered)
    {
        if ((self->D8inConMonitored.Value) &&
            (self->D4inConChannelType.Value == FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Single))
        {
            self->D9outMonitoredDisturbanceState.Value =
                FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue__PhysicallyDisturbed;
            self->D9outMonitoredDisturbanceState.IsSignalled = true;
            make_state_FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed(self, x);
            return;
        }
    }
    if (self->Change280.IsTriggered)
    {
        if ((self->D8inConMonitored.Value) &&
            ((self->D4inConChannelType.Value ==
              FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Antivalent) ||
             (self->D4inConChannelType.Value ==
              FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Equivalent)))
        {
            self->D9outMonitoredDisturbanceState.Value =
                FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue__PhysicallyDisturbed;
            self->D9outMonitoredDisturbanceState.IsSignalled = true;
            make_state_FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed(self, x);
            return;
        }
    }
}

void transition_from_FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed(
    FMonitorOutputChannelDisturbanceState *self, FMonitorOutputChannelDisturbanceState__root__state_struct *x)
{

    if (self->Change575.IsTriggered)
    {
        if (self->D4inConChannelType.Value == FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Single)
        {
            self->D9outMonitoredDisturbanceState.Value =
                FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue__NotPhysicallyDisturbed;
            self->D9outMonitoredDisturbanceState.IsSignalled = true;
            make_state_FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed(self, x);
            return;
        }
    }
    if (self->Change576.IsTriggered)
    {
        if ((self->D4inConChannelType.Value ==
             FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Antivalent) ||
            (self->D4inConChannelType.Value ==
             FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Equivalent))
        {
            self->D9outMonitoredDisturbanceState.Value =
                FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue__NotPhysicallyDisturbed;
            self->D9outMonitoredDisturbanceState.IsSignalled = true;
            make_state_FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed(self, x);
            return;
        }
    }
}

void transition_from_FMonitorOutputChannelDisturbanceState__root(
    FMonitorOutputChannelDisturbanceState *self, FMonitorOutputChannelDisturbanceState__root__state_struct *x)
{
    switch (x->state)
    {
    case FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed:
        transition_from_FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed(self, x);
        break;
    case FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed:
        transition_from_FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed(self, x);
        break;
    }
}

static void evaluateChangeEvents(FMonitorOutputChannelDisturbanceState *self)
{
    self->Change279.IsTriggered =
        IsTriggered(MakeChange(self->D41inDisturbanceRoc.IsSignalled, self->D41inDisturbanceRoc.Value));
    self->Change280.IsTriggered =
        IsTriggered(OrChange(MakeChange(self->D41inDisturbanceRoc.IsSignalled, self->D41inDisturbanceRoc.Value),
                             MakeChange(self->D42inDisturbanceVoc.IsSignalled, self->D42inDisturbanceVoc.Value)));
    self->Change575.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D41inDisturbanceRoc.IsSignalled, self->D41inDisturbanceRoc.Value)));
    self->Change576.IsTriggered = IsTriggered(
        AndChange(NegateChange(MakeChange(self->D41inDisturbanceRoc.IsSignalled, self->D41inDisturbanceRoc.Value)),
                  NegateChange(MakeChange(self->D42inDisturbanceVoc.IsSignalled, self->D42inDisturbanceVoc.Value))));
}

static void resetOutputs(FMonitorOutputChannelDisturbanceState *self)
{

    self->D9outMonitoredDisturbanceState.IsSignalled = false;
}

static void resetTriggers(FMonitorOutputChannelDisturbanceState *self)
{

    self->D41inDisturbanceRoc.IsSignalled = false;
    self->D42inDisturbanceVoc.IsSignalled = false;
    self->D8inConMonitored.IsSignalled = false;
    self->D4inConChannelType.IsSignalled = false;
}

void transition_FMonitorOutputChannelDisturbanceState(FMonitorOutputChannelDisturbanceState *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FMonitorOutputChannelDisturbanceState__root(self, &self->state);
    resetTriggers(self);
}

void new_FMonitorOutputChannelDisturbanceState(FMonitorOutputChannelDisturbanceState *self)
{
    make_state_FMonitorOutputChannelDisturbanceState__root(self, &self->state);
}
