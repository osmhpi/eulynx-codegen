
#include "../../04_OutputC/SubsystemTrainDetectionSystem/SSciTdsCommand.h"

void count_transitions_from_SSciTdsCommand__root__SendingCommands(int *ctr, SSciTdsCommand *self,
                                                                  SSciTdsCommand__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1255.IsTriggered)
    {
        if ((self->D70inModeOfFc.Value == SSciTdsCommand_D70inModeOfFcValue__FcU) &&
            (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1256.IsTriggered)
    {
        if ((self->D70inModeOfFc.Value == SSciTdsCommand_D70inModeOfFcValue__FcP) &&
            (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1254.IsTriggered)
    {
        if ((self->D70inModeOfFc.Value == SSciTdsCommand_D70inModeOfFcValue__FcPA) &&
            (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1258.IsTriggered)
    {
        if ((self->D70inModeOfFc.Value == SSciTdsCommand_D70inModeOfFcValue__AcknowledgementAfterFcPACommand) &&
            (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1257.IsTriggered)
    {
        if ((self->D70inModeOfFc.Value == SSciTdsCommand_D70inModeOfFcValue__FcC) &&
            (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1259.IsTriggered)
    {
        if (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change1260.IsTriggered)
    {
        if (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change1261.IsTriggered)
    {
        if (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciTdsCommand__root(int *ctr, SSciTdsCommand *self, SSciTdsCommand__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciTdsCommand__root__SendingCommands:
        count_transitions_from_SSciTdsCommand__root__SendingCommands(ctr, self, x);
        break;
    }
}

int count_transitions_SSciTdsCommand(SSciTdsCommand *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciTdsCommand__root(&ctr, self, &self->state);
    return ctr;
}