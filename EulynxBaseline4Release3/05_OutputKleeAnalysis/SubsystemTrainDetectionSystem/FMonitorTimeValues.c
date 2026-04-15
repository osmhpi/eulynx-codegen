
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FMonitorTimeValues.h"

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change120.IsTriggered)
    {
        if (self->D28inConTDelayOfNotificationOfAvailability.Value != 0)
        {
            (*ctr)++;
        }
    }
    if (self->Change1102.IsTriggered)
    {
        if ((!(self->D16inLastWheelOut.Value)) && (self->D29inConTInhibitionTime.Value != 0))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time20.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change119.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1100.IsTriggered)
    {
        if (!(self->D16inLastWheelOut.Value))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorNotificationOfAvailability(
    int *ctr, FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time19.IsTimeoutExpired)
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

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__root(int *ctr, FMonitorTimeValues *self,
                                                                              FMonitorTimeValues__root__state_struct *x)
{
    switch (x->MonitorTimeValues.root.state)
    {
    case FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring(ctr, self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime(ctr, self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__root__MonitorNotificationOfAvailability:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorNotificationOfAvailability(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues(int *ctr, FMonitorTimeValues *self,
                                                                        FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change233.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change391.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change392.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__WaitingForFinishBooting(int *ctr, FMonitorTimeValues *self,
                                                                              FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change402.IsTriggered)
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

void count_transitions_from_FMonitorTimeValues__root__FallbackMode(int *ctr, FMonitorTimeValues *self,
                                                                   FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change386.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root__TechnicalDisturbance(int *ctr, FMonitorTimeValues *self,
                                                                           FMonitorTimeValues__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change396.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change562.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorTimeValues__root(int *ctr, FMonitorTimeValues *self,
                                                     FMonitorTimeValues__root__state_struct *x)
{
    switch (x->state)
    {
    case FMonitorTimeValues__root__MonitorTimeValues:
        count_transitions_from_FMonitorTimeValues__root__MonitorTimeValues(ctr, self, x);
        break;
    case FMonitorTimeValues__root__WaitingForFinishBooting:
        count_transitions_from_FMonitorTimeValues__root__WaitingForFinishBooting(ctr, self, x);
        break;
    case FMonitorTimeValues__root__FallbackMode:
        count_transitions_from_FMonitorTimeValues__root__FallbackMode(ctr, self, x);
        break;
    case FMonitorTimeValues__root__TechnicalDisturbance:
        count_transitions_from_FMonitorTimeValues__root__TechnicalDisturbance(ctr, self, x);
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