
#include "../../04_OutputC/SubsystemPoint/SSciPCommand.h"

void count_transitions_from_SSciPCommand__root__SendingCommands(int *ctr, SSciPCommand *self,
                                                                SSciPCommand__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change874.IsTriggered)
    {
        if ((self->D2inMovePoint.Value == SSciPCommand_D2inMovePointValue__Right) &&
            (self->D50inPdiConnectionState.Value == SSciPCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change875.IsTriggered)
    {
        if ((self->D2inMovePoint.Value == SSciPCommand_D2inMovePointValue__Left) &&
            (self->D50inPdiConnectionState.Value == SSciPCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciPCommand__root(int *ctr, SSciPCommand *self, SSciPCommand__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciPCommand__root__SendingCommands:
        count_transitions_from_SSciPCommand__root__SendingCommands(ctr, self, x);
        break;
    }
}

int count_transitions_SSciPCommand(SSciPCommand *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciPCommand__root(&ctr, self, &self->state);
    return ctr;
}