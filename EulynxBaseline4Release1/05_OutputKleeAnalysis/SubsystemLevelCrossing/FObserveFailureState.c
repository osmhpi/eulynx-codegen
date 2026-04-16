
#include "../../04_OutputC/SubsystemLevelCrossing/FObserveFailureState.h"

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change584.IsTriggered)
    {
        if (self->D69inLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__CriticalFailureReport)
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

    if (self->Change432.IsTriggered)
    {
        if (self->D69inLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__CriticalFailureReport)
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

    if (self->Change585.IsTriggered)
    {
        if (self->D69inLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
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

    if (self->Change430.IsTriggered)
    {
        if (self->D69inLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__Waiting(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change447.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change448.IsTriggered)
    {
        (*ctr)++;
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
    case FObserveFailureState__root__ObserveFailureStates__LcFailureState__Waiting:
        count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__Waiting(ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change453.IsTriggered)
    {
        if (self->D67inLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport)
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

    if (self->Change450.IsTriggered)
    {
        if (self->D67inLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport)
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

    if (self->Change452.IsTriggered)
    {
        if (self->D67inLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
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

    if (self->Change451.IsTriggered)
    {
        if (self->D67inLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__Waiting(
    int *ctr, FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change446.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change445.IsTriggered)
    {
        (*ctr)++;
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
    case FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__Waiting:
        count_transitions_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__Waiting(ctr, self,
                                                                                                           x);
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
    }
}

int count_transitions_FObserveFailureState(FObserveFailureState *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveFailureState__root(&ctr, self, &self->state);
    return ctr;
}