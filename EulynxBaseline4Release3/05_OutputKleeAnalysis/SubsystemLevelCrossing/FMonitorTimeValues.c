
#include "../../04_OutputC/SubsystemLevelCrossing/FMonitorTimeValues.h"

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change155.IsTriggered)
    {
        if (self->D63inConUseClosureTime.Value == true)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeIsRunning(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time33.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change244.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeExpired(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change243.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    switch (x->MonitorTimeValues.MonitorClosureTime.state)
    {
    case FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle(ctr, self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeIsRunning:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeIsRunning(
            ctr, self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeExpired:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeExpired(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Idle(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change324.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__WaitingForDelay(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time40.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change326.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__DelayReached(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change376.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change321.IsTriggered)
    {
        if ((!(self->D1inReceiveLcState.Value == FMonitorTimeValues_D1inReceiveLcStateValue__Isolated)) &&
            (self->D64inConUsePdiConLossDeactivationDelay.Value == true))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    switch (x->MonitorTimeValues.PdiConLossDelay.state)
    {
    case FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Idle:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Idle(ctr, self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__WaitingForDelay:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__WaitingForDelay(ctr, self,
                                                                                                             x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__DelayReached:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__DelayReached(ctr, self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting(ctr, self, x);
        break;
    }
}

void count_transitions_from_FMonitorTimeValues__root__WaitingForFinishBooting(int *ctr, FMonitorTimeValues *self,
                                                                              FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__Fallbackmode(int *ctr, FMonitorTimeValues *self,
                                                                   FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__TechnicalDisturbance(int *ctr, FMonitorTimeValues *self,
                                                                           FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues(int *ctr, FMonitorTimeValues *self,
                                                                        FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root(int *ctr, FMonitorTimeValues *self,
                                                     FMonitorTimeValues__root__state_struct *x)
{
    switch (x->state)
    {
    case FMonitorTimeValues__root__WaitingForFinishBooting:
        count_transitions_from_FMonitorTimeValues__root__WaitingForFinishBooting(ctr, self, x);
        break;
    case FMonitorTimeValues__root__Fallbackmode:
        count_transitions_from_FMonitorTimeValues__root__Fallbackmode(ctr, self, x);
        break;
    case FMonitorTimeValues__root__TechnicalDisturbance:
        count_transitions_from_FMonitorTimeValues__root__TechnicalDisturbance(ctr, self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues(ctr, self, x);
        break;
    }
}

int count_transitions_FMonitorTimeValues(FMonitorTimeValues *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FMonitorTimeValues__root(&ctr, self, &self->state);
    return ctr;
}