
#include "../../04_OutputC/SubsystemLightSignal/SSciLsCommand.h"

void count_transitions_from_SSciLsCommand__root__SendingCommands(int *ctr, SSciLsCommand *self,
                                                                 SSciLsCommand__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1006.IsTriggered)
    {
        if ((self->D23inSignalAspect.Value == SSciLsCommand_D23inSignalAspectValue__SignalAspect2) &&
            (self->D9PdiConnectionState.Value == SSciLsCommand_D9PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1004.IsTriggered)
    {
        if ((self->D23inSignalAspect.Value == SSciLsCommand_D23inSignalAspectValue__MostRestrictAspect) &&
            (self->D9PdiConnectionState.Value == SSciLsCommand_D9PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1005.IsTriggered)
    {
        if ((self->D23inSignalAspect.Value == SSciLsCommand_D23inSignalAspectValue__SignalAspect1) &&
            (self->D9PdiConnectionState.Value == SSciLsCommand_D9PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1016.IsTriggered)
    {
        if ((self->D25inLuminosity.Value == SSciLsCommand_D25inLuminosityValue__Night) &&
            (self->D9PdiConnectionState.Value == SSciLsCommand_D9PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1018.IsTriggered)
    {
        if ((self->D25inLuminosity.Value == SSciLsCommand_D25inLuminosityValue__Day) &&
            (self->D9PdiConnectionState.Value == SSciLsCommand_D9PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciLsCommand__root(int *ctr, SSciLsCommand *self, SSciLsCommand__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciLsCommand__root__SendingCommands:
        count_transitions_from_SSciLsCommand__root__SendingCommands(ctr, self, x);
        break;
    }
}

int count_transitions_SSciLsCommand(SSciLsCommand *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciLsCommand__root(&ctr, self, &self->state);
    return ctr;
}