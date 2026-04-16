
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FObserveAbilityToBeForcedToClear.h"

void count_transitions_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
    int *ctr, FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change83.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change108.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change518.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear(
    int *ctr, FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change512.IsTriggered)
    {
        if ((!(self->D14nRunningTimer.Value)) && (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change515.IsTriggered)
    {
        if ((!(self->D14nRunningTimer.Value)) && (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change557.IsTriggered)
    {
        if ((self->D9inOccupancyStatus.Value ==
             FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__OccupiedOut) &&
            (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change555.IsTriggered)
    {
        if (((self->D9inOccupancyStatus.Value ==
              FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableIn) &&
             (self->D26inConVariantAIsUsed.Value)) &&
            (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change556.IsTriggered)
    {
        if ((self->D9inOccupancyStatus.Value ==
             FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableOut) &&
            (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change561.IsTriggered)
    {
        if (((!(self->D14nRunningTimer.Value)) &&
             (self->D9inOccupancyStatus.Value ==
              FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableIn)) &&
            (self->D26inConVariantAIsUsed.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change558.IsTriggered)
    {
        if ((self->D9inOccupancyStatus.Value ==
             FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableOut) &&
            (!(self->D14nRunningTimer.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change560.IsTriggered)
    {
        if ((!(self->D14nRunningTimer.Value)) &&
            (self->D9inOccupancyStatus.Value == FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__OccupiedOut))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root(
    int *ctr, FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    switch (x->ObserveAbilityToBeForcedToClear.root.state)
    {
    case FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear:
        count_transitions_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
            ctr, self, x);
        break;
    case FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear:
        count_transitions_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear(
    int *ctr, FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change245.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change402.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change410.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting(
    int *ctr, FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change417.IsTriggered)
    {

        if (self->D32inCriticalFailureTvps.Value)
        {
            (*ctr)++;
        }
        else
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveAbilityToBeForcedToClear__root__FallbackMode(
    int *ctr, FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change396.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance(
    int *ctr, FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change407.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change570.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveAbilityToBeForcedToClear__root(
    int *ctr, FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear:
        count_transitions_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear(ctr, self, x);
        break;
    case FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting:
        count_transitions_from_FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting(ctr, self, x);
        break;
    case FObserveAbilityToBeForcedToClear__root__FallbackMode:
        count_transitions_from_FObserveAbilityToBeForcedToClear__root__FallbackMode(ctr, self, x);
        break;
    case FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance:
        count_transitions_from_FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveAbilityToBeForcedToClear(FObserveAbilityToBeForcedToClear *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveAbilityToBeForcedToClear__root(&ctr, self, &self->state);
    return ctr;
}