
#include "../../04_OutputC/SubsystemLevelCrossing/FObserveDetectionElement.h"

void count_transitions_from_FObserveDetectionElement__root__Waiting(int *ctr, FObserveDetectionElement *self,
                                                                    FObserveDetectionElement__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change13.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change12.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change14.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveDetectionElement__root__Occupied(int *ctr, FObserveDetectionElement *self,
                                                                     FObserveDetectionElement__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change18.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change19.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveDetectionElement__root__Vacant(int *ctr, FObserveDetectionElement *self,
                                                                   FObserveDetectionElement__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change16.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change15.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveDetectionElement__root__TechnicalFailure(
    int *ctr, FObserveDetectionElement *self, FObserveDetectionElement__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change20.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change17.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveDetectionElement__root(int *ctr, FObserveDetectionElement *self,
                                                           FObserveDetectionElement__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveDetectionElement__root__Waiting:
        count_transitions_from_FObserveDetectionElement__root__Waiting(ctr, self, x);
        break;
    case FObserveDetectionElement__root__Occupied:
        count_transitions_from_FObserveDetectionElement__root__Occupied(ctr, self, x);
        break;
    case FObserveDetectionElement__root__Vacant:
        count_transitions_from_FObserveDetectionElement__root__Vacant(ctr, self, x);
        break;
    case FObserveDetectionElement__root__TechnicalFailure:
        count_transitions_from_FObserveDetectionElement__root__TechnicalFailure(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveDetectionElement(FObserveDetectionElement *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveDetectionElement__root(&ctr, self, &self->state);
    return ctr;
}