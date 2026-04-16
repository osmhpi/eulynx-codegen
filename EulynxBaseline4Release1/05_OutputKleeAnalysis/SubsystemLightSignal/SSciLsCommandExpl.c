
#include "../../04_OutputC/SubsystemLightSignal/SSciLsCommandExpl.h"

void count_transitions_from_SSciLsCommandExpl__root__SendingCommands(int *ctr, SSciLsCommandExpl *self,
                                                                     SSciLsCommandExpl__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1003.IsTriggered)
    {
        if ((self->D23inSignalAspect.Value == SSciLsCommandExpl_D23inSignalAspectValue__SignalAspect2) &&
            (self->D9PdiConnectionState.Value == SSciLsCommandExpl_D9PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1007.IsTriggered)
    {
        if ((self->D23inSignalAspect.Value == SSciLsCommandExpl_D23inSignalAspectValue__MostRestrictAspect) &&
            (self->D9PdiConnectionState.Value == SSciLsCommandExpl_D9PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1008.IsTriggered)
    {
        if ((self->D23inSignalAspect.Value == SSciLsCommandExpl_D23inSignalAspectValue__SignalAspect1) &&
            (self->D9PdiConnectionState.Value == SSciLsCommandExpl_D9PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1015.IsTriggered)
    {
        if ((self->D25inLuminosity.Value == SSciLsCommandExpl_D25inLuminosityValue__Night) &&
            (self->D9PdiConnectionState.Value == SSciLsCommandExpl_D9PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1017.IsTriggered)
    {
        if ((self->D25inLuminosity.Value == SSciLsCommandExpl_D25inLuminosityValue__Day) &&
            (self->D9PdiConnectionState.Value == SSciLsCommandExpl_D9PdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciLsCommandExpl__root(int *ctr, SSciLsCommandExpl *self,
                                                    SSciLsCommandExpl__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciLsCommandExpl__root__SendingCommands:
        count_transitions_from_SSciLsCommandExpl__root__SendingCommands(ctr, self, x);
        break;
    }
}

int count_transitions_SSciLsCommandExpl(SSciLsCommandExpl *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciLsCommandExpl__root(&ctr, self, &self->state);
    return ctr;
}