
#include "../../04_OutputC/SubsystemLightSignal/FObserveSignalAspect.h"

void count_transitions_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
    int *ctr, FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change450.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change454.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change459.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change486.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change580.IsTriggered)
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

    if (self->Change452.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change457.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change462.IsTriggered)
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

    if (self->Change451.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change455.IsTriggered)
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

    if (self->Change453.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change458.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change460.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change485.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change579.IsTriggered)
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

    if (self->Change449.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change456.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change461.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change484.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change581.IsTriggered)
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

    if (self->Change331.IsTriggered)
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
    if (self->Change338.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change373.IsTriggered)
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