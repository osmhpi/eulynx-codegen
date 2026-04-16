
#include "../../04_OutputC/SubsystemPoint/FControlPoint.h"

void count_transitions_from_FControlPoint__root__Operating__root__MovingLeft(int *ctr, FControlPoint *self,
                                                                             FControlPoint__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change28.IsTriggered)
    {
        if (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove)
        {
            (*ctr)++;
        }
    }
    if (self->Change30.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change33.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change89.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change107.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change108.IsTriggered)
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

    if (self->Change26.IsTriggered)
    {
        if (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove)
        {
            (*ctr)++;
        }
    }
    if (self->Change29.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change35.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change88.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change106.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change109.IsTriggered)
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

    if (self->Change25.IsTriggered)
    {
        if ((!(self->D10inRequiredPointPosition.Value ==
               map_D14inObservedPointPosition_to_D10inRequiredPointPosition(self->D14inObservedPointPosition.Value))) &&
            (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove))
        {
            (*ctr)++;
        }
    }
    if (self->Change27.IsTriggered)
    {
        if ((!(self->D10inRequiredPointPosition.Value ==
               map_D14inObservedPointPosition_to_D10inRequiredPointPosition(self->D14inObservedPointPosition.Value))) &&
            (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove))
        {
            (*ctr)++;
        }
    }
    if (self->Change105.IsTriggered)
    {
        if (((self->MemLastRequiredPointPosition == FControlPoint_MemLastRequiredPointPositionValue__Right) &&
             (self->D18inConUseRedrive.Value)) &&
            (self->D11inObservedAbilityToMove.Value == FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove))
        {
            (*ctr)++;
        }
    }
    if (self->Change104.IsTriggered)
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

    if (self->Change380.IsTriggered)
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
    if (self->Change390.IsTriggered)
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