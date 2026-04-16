
#include "../../04_OutputC/SubsystemPoint/FSciPReceive.h"

void count_transitions_from_FSciPReceive__root__ReceivingCommands(int *ctr, FSciPReceive *self,
                                                                  FSciPReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change31.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change75.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change331.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Left) &&
            (self->D50inPdiConnectionState.Value == FSciPReceive_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Right) &&
            (self->D50inPdiConnectionState.Value == FSciPReceive_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPReceive__root(int *ctr, FSciPReceive *self, FSciPReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciPReceive__root__ReceivingCommands:
        count_transitions_from_FSciPReceive__root__ReceivingCommands(ctr, self, x);
        break;
    }
}

int count_transitions_FSciPReceive(FSciPReceive *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciPReceive__root(&ctr, self, &self->state);
    return ctr;
}