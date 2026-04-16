
#include "../../04_OutputC/SubsystemIo/FControlSafeStateOfAllPhysicalOutputChannel.h"

void count_transitions_from_FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel(
    int *ctr, FControlSafeStateOfAllPhysicalOutputChannel *self,
    FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change357.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change371.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change382.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change387.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change498.IsTriggered)
    {
        if ((self->D600inConDisturbanceSwitchOffAll.Value) &&
            (self->D51inEstEfesState.Value ==
             FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Operational))
        {
            (*ctr)++;
        }
    }
    if (self->Change506.IsTriggered)
    {
        if ((self->D600inConDisturbanceSwitchOffAll.Value) &&
            (self->D51inEstEfesState.Value ==
             FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Operational))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel(
    int *ctr, FControlSafeStateOfAllPhysicalOutputChannel *self,
    FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change400.IsTriggered)
    {
        if (((self->D600inConDisturbanceSwitchOffAll.Value) &&
             (self->D9inMonitoredOutputChannelDisturbanceState1.Value ==
              FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed)) &&
            (self->D9inMonitoredOutputChannelDisturbanceStaten.Value ==
             FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed))
        {
            (*ctr)++;
        }
    }
    if (self->Change396.IsTriggered)
    {
        if (!(self->D600inConDisturbanceSwitchOffAll.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change501.IsTriggered)
    {
        if ((self->D600inConDisturbanceSwitchOffAll.Value) &&
            (self->D51inEstEfesState.Value ==
             FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Operational))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlSafeStateOfAllPhysicalOutputChannel__root(
    int *ctr, FControlSafeStateOfAllPhysicalOutputChannel *self,
    FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel:
        count_transitions_from_FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel(
            ctr, self, x);
        break;
    case FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel:
        count_transitions_from_FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel(
            ctr, self, x);
        break;
    }
}

int count_transitions_FControlSafeStateOfAllPhysicalOutputChannel(FControlSafeStateOfAllPhysicalOutputChannel *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FControlSafeStateOfAllPhysicalOutputChannel__root(&ctr, self, &self->state);
    return ctr;
}