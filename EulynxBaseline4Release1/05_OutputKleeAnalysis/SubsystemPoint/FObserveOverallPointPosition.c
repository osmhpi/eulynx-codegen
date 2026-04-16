
#include "../../04_OutputC/SubsystemPoint/FObserveOverallPointPosition.h"

void count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left(
    int *ctr, FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right(
    int *ctr, FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__NoEndPosition(
    int *ctr, FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Trailed(
    int *ctr, FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root(
    int *ctr, FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
    switch (x->ObserveOverallPointPosition.root.state)
    {
    case FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left:
        count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left(ctr, self,
                                                                                                           x);
        break;
    case FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right:
        count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right(ctr, self,
                                                                                                            x);
        break;
    case FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__NoEndPosition:
        count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__NoEndPosition(
            ctr, self, x);
        break;
    case FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Trailed:
        count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Trailed(ctr, self,
                                                                                                              x);
        break;
    }
}

void count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition(
    int *ctr, FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change23.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change28.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change29.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change30.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change388.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveOverallPointPosition__root(int *ctr, FObserveOverallPointPosition *self,
                                                               FObserveOverallPointPosition__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveOverallPointPosition__root__ObserveOverallPointPosition:
        count_transitions_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveOverallPointPosition(FObserveOverallPointPosition *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveOverallPointPosition__root(&ctr, self, &self->state);
    return ctr;
}