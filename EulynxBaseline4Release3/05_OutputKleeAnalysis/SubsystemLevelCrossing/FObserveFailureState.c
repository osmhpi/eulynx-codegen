
#include "../../04_OutputC/SubsystemLevelCrossing/FObserveFailureState.h"

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change575.IsTriggered)
    {
        if (self->D69inConLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change415.IsTriggered)
    {
        if (self->D69inConLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change576.IsTriggered)
    {
        if (self->D69inConLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change417.IsTriggered)
    {
        if (self->D69inConLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    switch (x->ObserveFailureStates.LcFailureState.state)
    {
    case FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected:
        count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected(
            ctr, self, x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected:
        count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected(
            ctr, self, x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected:
        count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected(
            ctr, self, x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected:
        count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change435.IsTriggered)
    {
        if (self->D67inConLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change434.IsTriggered)
    {
        if (self->D67inConLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change436.IsTriggered)
    {
        if (self->D67inConLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change433.IsTriggered)
    {
        if (self->D67inConLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    switch (x->ObserveFailureStates.LcpfFailureState.state)
    {
    case FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected:
        count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected(
            ctr, self, x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected:
        count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected(
            ctr, self, x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected:
        count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected(
            ctr, self, x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected:
        count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change350.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root__WaitingForBooting(int *ctr, FObserveFailureState *self,
                                                                          FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change332.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root(int *ctr, FObserveFailureState *self,
                                                       FObserveFailureState__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveFailureState__root__ObserveFailureStates:
        count_transitions_from_FObserveFailureState__root__ObserveFailureStates(ctr, self, x);
        break;
    case FObserveFailureState__root__WaitingForBooting:
        count_transitions_from_FObserveFailureState__root__WaitingForBooting(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveFailureState(FObserveFailureState *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveFailureState__root(&ctr, self, &self->state);
    return ctr;
}