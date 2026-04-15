
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FHandleInternalFcUCommand.h"

void count_transitions_from_FHandleInternalFcUCommand__root__ReceivingCommandsFromInternal(
    int *ctr, FHandleInternalFcUCommand *self, FHandleInternalFcUCommand__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1087.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FHandleInternalFcUCommand__root(int *ctr, FHandleInternalFcUCommand *self,
                                                            FHandleInternalFcUCommand__root__state_struct *x)
{
    switch (x->state)
    {
    case FHandleInternalFcUCommand__root__ReceivingCommandsFromInternal:
        count_transitions_from_FHandleInternalFcUCommand__root__ReceivingCommandsFromInternal(ctr, self, x);
        break;
    }
}

int count_transitions_FHandleInternalFcUCommand(FHandleInternalFcUCommand *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FHandleInternalFcUCommand__root(&ctr, self, &self->state);
    return ctr;
}