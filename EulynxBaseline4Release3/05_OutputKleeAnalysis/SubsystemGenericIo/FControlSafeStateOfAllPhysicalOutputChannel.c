
#include "../../04_OutputC/SubsystemGenericIo/FControlSafeStateOfAllPhysicalOutputChannel.h"

void count_transitions_from_FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel(
    int *ctr, FControlSafeStateOfAllPhysicalOutputChannel *self,
    FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change336.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change348.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change362.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change367.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change496.IsTriggered)
    {
        if ((self->D600inConDisturbanceSwitchOffAll.Value) &&
            (self->D51inEstEfesState.Value ==
             FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Operational))
        {
            (*ctr)++;
        }
    }
    if (self->Change491.IsTriggered)
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

    if (self->Change381.IsTriggered)
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
    if (self->Change378.IsTriggered)
    {
        if (!(self->D600inConDisturbanceSwitchOffAll.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change495.IsTriggered)
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