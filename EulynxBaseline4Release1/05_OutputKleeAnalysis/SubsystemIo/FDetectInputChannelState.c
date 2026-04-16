
#include "../../04_OutputC/SubsystemIo/FDetectInputChannelState.h"

void count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change2.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change42.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change49.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Time33.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change3.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change44.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change60.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Time37.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time57.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change41.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change52.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change59.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change54.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change58.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    switch (x->DetectingAntivalentInputChannelPhysicalStateChange.root.state)
    {
    case FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn:
        count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            ctr, self, x);
        break;
    case FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff:
        count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            ctr, self, x);
        break;
    case FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__OperationlDisturbed:
        count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
            ctr, self, x);
        break;
    case FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed:
        count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change4.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change43.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change50.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Time32.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change5.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change46.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change61.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Time36.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time56.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change45.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change53.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change62.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change51.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change57.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    switch (x->DetectingEquivalentInputChannelPhysicalStateChange.root.state)
    {
    case FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn:
        count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            ctr, self, x);
        break;
    case FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff:
        count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            ctr, self, x);
        break;
    case FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__OperationlDisturbed:
        count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
            ctr, self, x);
        break;
    case FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed:
        count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change39.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change48.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Time31.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change40.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change56.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Time38.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change47.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change55.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    switch (x->DetectingSingleInputChannelPhysicalStateChange.root.state)
    {
    case FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn:
        count_transitions_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn(
            ctr, self, x);
        break;
    case FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff:
        count_transitions_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff(
            ctr, self, x);
        break;
    case FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed:
        count_transitions_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FDetectInputChannelState__root__ChannelConfiguration(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (true)
    {
        (*ctr)++;
    }
    if (true)
    {
        (*ctr)++;
    }
    if (true)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange(
    int *ctr, FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FDetectInputChannelState__root(int *ctr, FDetectInputChannelState *self,
                                                           FDetectInputChannelState__root__state_struct *x)
{
    switch (x->state)
    {
    case FDetectInputChannelState__root__ChannelConfiguration:
        count_transitions_from_FDetectInputChannelState__root__ChannelConfiguration(ctr, self, x);
        break;
    case FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange:
        count_transitions_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange(
            ctr, self, x);
        break;
    case FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange:
        count_transitions_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange(
            ctr, self, x);
        break;
    case FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange:
        count_transitions_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange(ctr, self,
                                                                                                              x);
        break;
    }
}

int count_transitions_FDetectInputChannelState(FDetectInputChannelState *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FDetectInputChannelState__root(&ctr, self, &self->state);
    return ctr;
}