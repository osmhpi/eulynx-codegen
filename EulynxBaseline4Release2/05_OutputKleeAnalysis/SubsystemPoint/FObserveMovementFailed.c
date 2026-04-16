
#include "../../04_OutputC/SubsystemPoint/FObserveMovementFailed.h"

void count_transitions_from_FObserveMovementFailed__root__ObserveMovementFailure__root__Idle(
    int *ctr, FObserveMovementFailed *self, FObserveMovementFailed__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change65.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure(
    int *ctr, FObserveMovementFailed *self, FObserveMovementFailed__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change60.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change69.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change73.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Time12.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change997.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveMovementFailed__root__ObserveMovementFailure__root(
    int *ctr, FObserveMovementFailed *self, FObserveMovementFailed__root__state_struct *x)
{
    switch (x->ObserveMovementFailure.root.state)
    {
    case FObserveMovementFailed__root__ObserveMovementFailure__root__Idle:
        count_transitions_from_FObserveMovementFailed__root__ObserveMovementFailure__root__Idle(ctr, self, x);
        break;
    case FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure:
        count_transitions_from_FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveMovementFailed__root__ObserveMovementFailure(
    int *ctr, FObserveMovementFailed *self, FObserveMovementFailed__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveMovementFailed__root__ObserveMovementFailure__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveMovementFailed__root(int *ctr, FObserveMovementFailed *self,
                                                         FObserveMovementFailed__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveMovementFailed__root__ObserveMovementFailure:
        count_transitions_from_FObserveMovementFailed__root__ObserveMovementFailure(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveMovementFailed(FObserveMovementFailed *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveMovementFailed__root(&ctr, self, &self->state);
    return ctr;
}