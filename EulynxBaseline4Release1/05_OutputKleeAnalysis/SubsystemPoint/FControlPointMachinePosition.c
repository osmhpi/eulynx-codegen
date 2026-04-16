
#include "../../04_OutputC/SubsystemPoint/FControlPointMachinePosition.h"

void count_transitions_from_FControlPointMachinePosition__root__Operating__root__MovingLeft(
    int *ctr, FControlPointMachinePosition *self, FControlPointMachinePosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time28.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change34.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change188.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change189.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change192.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change460.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlPointMachinePosition__root__Operating__root__MovingRight(
    int *ctr, FControlPointMachinePosition *self, FControlPointMachinePosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time29.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change33.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change184.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change190.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change191.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change461.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlPointMachinePosition__root__Operating__root__Stopped(
    int *ctr, FControlPointMachinePosition *self, FControlPointMachinePosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change31.IsTriggered)
    {
        if (((((self->D41inObservedPointEndPosition.Value ==
                FControlPointMachinePosition_D41inObservedPointEndPositionValue__Right) &&
               (self->MemLastCommandedPointPosition ==
                FControlPointMachinePosition_MemLastCommandedPointPositionValue__Right)) &&
              (self->D29inConUseRedrive.Value)) &&
             (self->D6inObservedAbilityToMovePoint.Value ==
              FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__AbleToMove)) &&
            (self->D51inEstEfesState.Value == FControlPointMachinePosition_D51inEstEfesStateValue__Operational))
        {
            (*ctr)++;
        }
    }
    if (self->Change32.IsTriggered)
    {
        if (((((self->D41inObservedPointEndPosition.Value ==
                FControlPointMachinePosition_D41inObservedPointEndPositionValue__Left) &&
               (self->MemLastCommandedPointPosition ==
                FControlPointMachinePosition_MemLastCommandedPointPositionValue__Left)) &&
              (self->D29inConUseRedrive.Value)) &&
             (self->D6inObservedAbilityToMovePoint.Value ==
              FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__AbleToMove)) &&
            (self->D51inEstEfesState.Value == FControlPointMachinePosition_D51inEstEfesStateValue__Operational))
        {
            (*ctr)++;
        }
    }
    if (self->Change183.IsTriggered)
    {
        self->D35outDriveStop.Value = false;
        self->MemLastCommandedPointPosition = FControlPointMachinePosition_MemLastCommandedPointPositionValue__Left;
        if ((!(self->D2inRequiredPointPosition.Value ==
               map_D10inPmPosition_to_D2inRequiredPointPosition(self->D10inPmPosition.Value))) &&
            (self->D6inObservedAbilityToMovePoint.Value ==
             FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__AbleToMove))
        {
            (*ctr)++;
        }
        else
        {
            (*ctr)++;
        }
    }
    if (self->Change185.IsTriggered)
    {
        self->D35outDriveStop.Value = false;
        self->MemLastCommandedPointPosition = FControlPointMachinePosition_MemLastCommandedPointPositionValue__Right;
        if ((!(self->D2inRequiredPointPosition.Value ==
               map_D10inPmPosition_to_D2inRequiredPointPosition(self->D10inPmPosition.Value))) &&
            (self->D6inObservedAbilityToMovePoint.Value ==
             FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__AbleToMove))
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

void count_transitions_from_FControlPointMachinePosition__root__Operating__root__Waiting(
    int *ctr, FControlPointMachinePosition *self, FControlPointMachinePosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change373.IsTriggered)
    {
        if ((self->D34inConActive.Value) && (self->D44inConDriveCapability.Value))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlPointMachinePosition__root__Operating__root(
    int *ctr, FControlPointMachinePosition *self, FControlPointMachinePosition__root__state_struct *x)
{
    switch (x->Operating.root.state)
    {
    case FControlPointMachinePosition__root__Operating__root__MovingLeft:
        count_transitions_from_FControlPointMachinePosition__root__Operating__root__MovingLeft(ctr, self, x);
        break;
    case FControlPointMachinePosition__root__Operating__root__MovingRight:
        count_transitions_from_FControlPointMachinePosition__root__Operating__root__MovingRight(ctr, self, x);
        break;
    case FControlPointMachinePosition__root__Operating__root__Stopped:
        count_transitions_from_FControlPointMachinePosition__root__Operating__root__Stopped(ctr, self, x);
        break;
    case FControlPointMachinePosition__root__Operating__root__Waiting:
        count_transitions_from_FControlPointMachinePosition__root__Operating__root__Waiting(ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlPointMachinePosition__root__Operating(
    int *ctr, FControlPointMachinePosition *self, FControlPointMachinePosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FControlPointMachinePosition__root__Operating__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change387.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlPointMachinePosition__root(int *ctr, FControlPointMachinePosition *self,
                                                               FControlPointMachinePosition__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlPointMachinePosition__root__Operating:
        count_transitions_from_FControlPointMachinePosition__root__Operating(ctr, self, x);
        break;
    }
}

int count_transitions_FControlPointMachinePosition(FControlPointMachinePosition *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FControlPointMachinePosition__root(&ctr, self, &self->state);
    return ctr;
}