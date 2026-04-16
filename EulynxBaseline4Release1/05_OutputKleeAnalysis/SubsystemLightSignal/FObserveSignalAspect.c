
#include "../../04_OutputC/SubsystemLightSignal/FObserveSignalAspect.h"

void count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
    int *ctr, FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change93.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change97.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change100.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change110.IsTriggered)
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

void count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
    int *ctr, FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change87.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change91.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change99.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change109.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change563.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
    int *ctr, FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change89.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change92.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change96.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change111.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change564.IsTriggered)
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

    if (self->Change90.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change95.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change98.IsTriggered)
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

    if (self->Change88.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change94.IsTriggered)
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
    case FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect:
        count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(ctr, self,
                                                                                                           x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1:
        count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(ctr, self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2:
        count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(ctr, self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect:
        count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(ctr, self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting:
        count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting(ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveSignalAspect__root__NationalAspect(int *ctr, FObserveSignalAspect *self,
                                                                       FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change346.IsTriggered)
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
    if (self->Change354.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change385.IsTriggered)
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