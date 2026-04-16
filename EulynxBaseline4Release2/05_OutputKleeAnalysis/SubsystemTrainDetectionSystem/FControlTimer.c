
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FControlTimer.h"

void count_transitions_from_FControlTimer__root__ObserveTimer__root__NoTimer(int *ctr, FControlTimer *self,
                                                                             FControlTimer__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change492.IsTriggered)
    {
        if (self->D28inConTDelayOfNotificationOfAvailability.Value != 0)
        {
            (*ctr)++;
        }
    }
    if (self->Change1109.IsTriggered)
    {
        if ((!(self->D8inLastWheelOut.Value)) && (self->D29inConTInhibitionTimer.Value != 0))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer(
    int *ctr, FControlTimer *self, FControlTimer__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time20.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change493.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1107.IsTriggered)
    {
        if (!(self->D8inLastWheelOut.Value))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlTimer__root__ObserveTimer__root__NotificationOfAvailabilityRunningTimer(
    int *ctr, FControlTimer *self, FControlTimer__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time19.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change1108.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlTimer__root__ObserveTimer__root(int *ctr, FControlTimer *self,
                                                                    FControlTimer__root__state_struct *x)
{
    switch (x->ObserveTimer.root.state)
    {
    case FControlTimer__root__ObserveTimer__root__NoTimer:
        count_transitions_from_FControlTimer__root__ObserveTimer__root__NoTimer(ctr, self, x);
        break;
    case FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer:
        count_transitions_from_FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer(ctr, self, x);
        break;
    case FControlTimer__root__ObserveTimer__root__NotificationOfAvailabilityRunningTimer:
        count_transitions_from_FControlTimer__root__ObserveTimer__root__NotificationOfAvailabilityRunningTimer(ctr,
                                                                                                               self, x);
        break;
    }
}

void count_transitions_from_FControlTimer__root__ObserveTimer(int *ctr, FControlTimer *self,
                                                              FControlTimer__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FControlTimer__root__ObserveTimer__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change255.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change410.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change415.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlTimer__root__WaitingForFinishBooting(int *ctr, FControlTimer *self,
                                                                         FControlTimer__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change422.IsTriggered)
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

void count_transitions_from_FControlTimer__root__FallbackMode(int *ctr, FControlTimer *self,
                                                              FControlTimer__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change407.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlTimer__root__TechnicalDisturbance(int *ctr, FControlTimer *self,
                                                                      FControlTimer__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change413.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change568.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlTimer__root(int *ctr, FControlTimer *self, FControlTimer__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlTimer__root__ObserveTimer:
        count_transitions_from_FControlTimer__root__ObserveTimer(ctr, self, x);
        break;
    case FControlTimer__root__WaitingForFinishBooting:
        count_transitions_from_FControlTimer__root__WaitingForFinishBooting(ctr, self, x);
        break;
    case FControlTimer__root__FallbackMode:
        count_transitions_from_FControlTimer__root__FallbackMode(ctr, self, x);
        break;
    case FControlTimer__root__TechnicalDisturbance:
        count_transitions_from_FControlTimer__root__TechnicalDisturbance(ctr, self, x);
        break;
    }
}

int count_transitions_FControlTimer(FControlTimer *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FControlTimer__root(&ctr, self, &self->state);
    return ctr;
}