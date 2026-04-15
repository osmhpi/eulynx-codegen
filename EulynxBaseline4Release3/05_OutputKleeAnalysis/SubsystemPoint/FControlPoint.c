
#include "../../04_OutputC/SubsystemPoint/FControlPoint.h"

void count_transitions_from_FControlPoint__root__Operating__root__MovingLeft(int *ctr, FControlPoint *self,
                                                                             FControlPoint__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change36.IsTriggered)
    {
        if (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove)
        {
            (*ctr)++;
        }
    }
    if (self->Change37.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change41.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change97.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change114.IsTriggered)
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

void count_transitions_from_FControlPoint__root__Operating__root__MovingRight(int *ctr, FControlPoint *self,
                                                                              FControlPoint__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change34.IsTriggered)
    {
        if (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove)
        {
            (*ctr)++;
        }
    }
    if (self->Change38.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change42.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change96.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change115.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change117.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlPoint__root__Operating__root__Stopped(int *ctr, FControlPoint *self,
                                                                          FControlPoint__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change33.IsTriggered)
    {
        if ((!(self->D10inRequiredPointPosition.Value ==
               map_D14inObservedPointPosition_to_D10inRequiredPointPosition(self->D14inObservedPointPosition.Value))) &&
            (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove))
        {
            (*ctr)++;
        }
    }
    if (self->Change35.IsTriggered)
    {
        if ((!(self->D10inRequiredPointPosition.Value ==
               map_D14inObservedPointPosition_to_D10inRequiredPointPosition(self->D14inObservedPointPosition.Value))) &&
            (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove))
        {
            (*ctr)++;
        }
    }
    if (self->Change113.IsTriggered)
    {
        if (((self->MemLastRequiredPointPosition == FControlPoint_MemLastRequiredPointPositionValue__Right) &&
             (self->D18inConUseRedrive.Value)) &&
            (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove))
        {
            (*ctr)++;
        }
    }
    if (self->Change112.IsTriggered)
    {
        if (((self->MemLastRequiredPointPosition == FControlPoint_MemLastRequiredPointPositionValue__Left) &&
             (self->D18inConUseRedrive.Value)) &&
            (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlPoint__root__Operating__root__Waiting(int *ctr, FControlPoint *self,
                                                                          FControlPoint__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change359.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlPoint__root__Operating__root(int *ctr, FControlPoint *self,
                                                                 FControlPoint__root__state_struct *x)
{
    switch (x->Operating.root.state)
    {
    case FControlPoint__root__Operating__root__MovingLeft:
        count_transitions_from_FControlPoint__root__Operating__root__MovingLeft(ctr, self, x);
        break;
    case FControlPoint__root__Operating__root__MovingRight:
        count_transitions_from_FControlPoint__root__Operating__root__MovingRight(ctr, self, x);
        break;
    case FControlPoint__root__Operating__root__Stopped:
        count_transitions_from_FControlPoint__root__Operating__root__Stopped(ctr, self, x);
        break;
    case FControlPoint__root__Operating__root__Waiting:
        count_transitions_from_FControlPoint__root__Operating__root__Waiting(ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlPoint__root__Operating(int *ctr, FControlPoint *self,
                                                           FControlPoint__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FControlPoint__root__Operating__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change371.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlPoint__root(int *ctr, FControlPoint *self, FControlPoint__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlPoint__root__Operating:
        count_transitions_from_FControlPoint__root__Operating(ctr, self, x);
        break;
    }
}

int count_transitions_FControlPoint(FControlPoint *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FControlPoint__root(&ctr, self, &self->state);
    return ctr;
}