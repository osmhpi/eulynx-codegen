
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FObserveOccupancyStatus.h"

void count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(
    int *ctr, FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InExecuteDrfc__4da5.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InExecuteFc__ffe5.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change1116.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1101.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing(
    int *ctr, FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InExecuteFc__ffe5.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change1110.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1112.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant(
    int *ctr, FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1104.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1111.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1121.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming(
    int *ctr, FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InExecuteDrfc__4da5.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InExecuteFc__ffe5.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change1114.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1120.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1105.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing(
    int *ctr, FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InExecuteFc__ffe5.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change542.IsTriggered)
    {
        if (self->D28inConTDelayOfNotificationOfAvailability.Value != 0)
        {
            (*ctr)++;
        }
    }
    if (self->Change543.IsTriggered)
    {
        if (self->D28inConTDelayOfNotificationOfAvailability.Value == 0)
        {
            (*ctr)++;
        }
    }
    if (self->Change1106.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1119.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1117.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__WaitingForNotificationOfAvailability(
    int *ctr, FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change552.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1102.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1115.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1118.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root(
    int *ctr, FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{
    switch (x->ObserveTvpsStatus.root.state)
    {
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming:
        count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(ctr, self, x);
        break;
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing:
        count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing(ctr, self, x);
        break;
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant:
        count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant(ctr, self, x);
        break;
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming:
        count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming(ctr, self, x);
        break;
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing:
        count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing(ctr, self, x);
        break;
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__WaitingForNotificationOfAvailability:
        count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__WaitingForNotificationOfAvailability(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus(
    int *ctr, FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change257.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change411.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change418.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1103.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1113.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOccupancyStatus__root__FallbackMode(int *ctr, FObserveOccupancyStatus *self,
                                                                        FObserveOccupancyStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change405.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOccupancyStatus__root__WaitingForFinishBooting(
    int *ctr, FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change424.IsTriggered)
    {

        if (self->D32inCriticalFailureTvps.Value)
        {
            (*ctr)++;
        }
        else
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOccupancyStatus__root__TechnicalDisturbance(
    int *ctr, FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change416.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change569.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOccupancyStatus__root(int *ctr, FObserveOccupancyStatus *self,
                                                          FObserveOccupancyStatus__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveOccupancyStatus__root__ObserveTvpsStatus:
        count_transitions_from_FObserveOccupancyStatus__root__ObserveTvpsStatus(ctr, self, x);
        break;
    case FObserveOccupancyStatus__root__FallbackMode:
        count_transitions_from_FObserveOccupancyStatus__root__FallbackMode(ctr, self, x);
        break;
    case FObserveOccupancyStatus__root__WaitingForFinishBooting:
        count_transitions_from_FObserveOccupancyStatus__root__WaitingForFinishBooting(ctr, self, x);
        break;
    case FObserveOccupancyStatus__root__TechnicalDisturbance:
        count_transitions_from_FObserveOccupancyStatus__root__TechnicalDisturbance(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveOccupancyStatus(FObserveOccupancyStatus *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveOccupancyStatus__root(&ctr, self, &self->state);
    return ctr;
}