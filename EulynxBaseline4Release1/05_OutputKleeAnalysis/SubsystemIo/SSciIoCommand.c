
#include "../../04_OutputC/SubsystemIo/SSciIoCommand.h"

void count_transitions_from_SSciIoCommand__root__SendingOutputChannelCommand(int *ctr, SSciIoCommand *self,
                                                                             SSciIoCommand__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1088.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOff) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOff)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1086.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOff) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOn)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1082.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOff) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__Flashing)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1084.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOn) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOn)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1083.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOn) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOff)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1089.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOn) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__Flashing)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1085.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__Flashing) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__Flashing)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1087.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__Flashing) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOn)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1081.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__Flashing) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOff)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciIoCommand__root(int *ctr, SSciIoCommand *self, SSciIoCommand__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciIoCommand__root__SendingOutputChannelCommand:
        count_transitions_from_SSciIoCommand__root__SendingOutputChannelCommand(ctr, self, x);
        break;
    }
}

int count_transitions_SSciIoCommand(SSciIoCommand *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciIoCommand__root(&ctr, self, &self->state);
    return ctr;
}