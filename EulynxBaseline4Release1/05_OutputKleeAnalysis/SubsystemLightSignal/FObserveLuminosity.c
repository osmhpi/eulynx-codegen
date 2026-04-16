
#include "../../04_OutputC/SubsystemLightSignal/FObserveLuminosity.h"

void count_transitions_from_FObserveLuminosity__root__ObservingLuminosity__root__Day(
    int *ctr, FObserveLuminosity *self, FObserveLuminosity__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change85.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change172.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLuminosity__root__ObservingLuminosity__root__Night(
    int *ctr, FObserveLuminosity *self, FObserveLuminosity__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change84.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change171.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLuminosity__root__ObservingLuminosity__root__Waiting(
    int *ctr, FObserveLuminosity *self, FObserveLuminosity__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change170.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change173.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLuminosity__root__ObservingLuminosity__root(
    int *ctr, FObserveLuminosity *self, FObserveLuminosity__root__state_struct *x)
{
    switch (x->ObservingLuminosity.root.state)
    {
    case FObserveLuminosity__root__ObservingLuminosity__root__Day:
        count_transitions_from_FObserveLuminosity__root__ObservingLuminosity__root__Day(ctr, self, x);
        break;
    case FObserveLuminosity__root__ObservingLuminosity__root__Night:
        count_transitions_from_FObserveLuminosity__root__ObservingLuminosity__root__Night(ctr, self, x);
        break;
    case FObserveLuminosity__root__ObservingLuminosity__root__Waiting:
        count_transitions_from_FObserveLuminosity__root__ObservingLuminosity__root__Waiting(ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveLuminosity__root__NoOperatingVoltage(int *ctr, FObserveLuminosity *self,
                                                                         FObserveLuminosity__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change345.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLuminosity__root__ObservingLuminosity(int *ctr, FObserveLuminosity *self,
                                                                          FObserveLuminosity__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveLuminosity__root__ObservingLuminosity__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change353.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change381.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLuminosity__root(int *ctr, FObserveLuminosity *self,
                                                     FObserveLuminosity__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveLuminosity__root__NoOperatingVoltage:
        count_transitions_from_FObserveLuminosity__root__NoOperatingVoltage(ctr, self, x);
        break;
    case FObserveLuminosity__root__ObservingLuminosity:
        count_transitions_from_FObserveLuminosity__root__ObservingLuminosity(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveLuminosity(FObserveLuminosity *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveLuminosity__root(&ctr, self, &self->state);
    return ctr;
}