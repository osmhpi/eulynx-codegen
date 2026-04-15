
#include "../../04_OutputC/SubsystemGenericIo/FMonitorOutputChannelDisturbanceState.h"

void count_transitions_from_FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed(
    int *ctr, FMonitorOutputChannelDisturbanceState *self, FMonitorOutputChannelDisturbanceState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (true)
    {
        (*ctr)++;
    }
    if (true)
    {
        (*ctr)++;
    }
    if (self->Change262.IsTriggered)
    {
        if ((self->D8inConMonitored.Value) &&
            (self->D4inConChannelType.Value == FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Single))
        {
            (*ctr)++;
        }
    }
    if (self->Change263.IsTriggered)
    {
        if ((self->D8inConMonitored.Value) &&
            ((self->D4inConChannelType.Value ==
              FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Antivalent) ||
             (self->D4inConChannelType.Value ==
              FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Equivalent)))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed(
    int *ctr, FMonitorOutputChannelDisturbanceState *self, FMonitorOutputChannelDisturbanceState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change568.IsTriggered)
    {
        if (self->D4inConChannelType.Value == FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Single)
        {
            (*ctr)++;
        }
    }
    if (self->Change569.IsTriggered)
    {
        if ((self->D4inConChannelType.Value ==
             FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Antivalent) ||
            (self->D4inConChannelType.Value ==
             FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Equivalent))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorOutputChannelDisturbanceState__root(
    int *ctr, FMonitorOutputChannelDisturbanceState *self, FMonitorOutputChannelDisturbanceState__root__state_struct *x)
{
    switch (x->state)
    {
    case FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed:
        count_transitions_from_FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed(ctr, self, x);
        break;
    case FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed:
        count_transitions_from_FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed(ctr, self, x);
        break;
    }
}

int count_transitions_FMonitorOutputChannelDisturbanceState(FMonitorOutputChannelDisturbanceState *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FMonitorOutputChannelDisturbanceState__root(&ctr, self, &self->state);
    return ctr;
}