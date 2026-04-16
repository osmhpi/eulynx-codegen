
#include "../../04_OutputC/SubsystemLightSignal/FObserveSignalAspect.h"

void count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
    int *ctr, FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change115.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change119.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change120.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change134.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change560.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
    int *ctr, FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change113.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change122.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change123.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting(
    int *ctr, FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change112.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change116.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
    int *ctr, FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change118.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change121.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change125.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change135.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change559.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
    int *ctr, FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change114.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change117.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change124.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change136.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change561.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root(
    int *ctr, FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    switch (x->ObservingSignalAspect.root.state)
    {
    case FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2:
        count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(ctr, self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect:
        count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(ctr, self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting:
        count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting(ctr, self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect:
        count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(ctr, self,
                                                                                                           x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1:
        count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveSignalAspect__root__NationalAspect(int *ctr, FObserveSignalAspect *self,
                                                                       FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change349.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect(
    int *ctr, FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change358.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change393.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveSignalAspect__root(int *ctr, FObserveSignalAspect *self,
                                                       FObserveSignalAspect__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveSignalAspect__root__NationalAspect:
        count_transitions_from_FObserveSignalAspect__root__NationalAspect(ctr, self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect:
        count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveSignalAspect(FObserveSignalAspect *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveSignalAspect__root(&ctr, self, &self->state);
    return ctr;
}