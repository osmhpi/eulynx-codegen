
#include "../../04_OutputC/SubsystemLevelCrossing/SSciLcCommand.h"

void count_transitions_from_SSciLcCommand__root__SendingCommands(int *ctr, SSciLcCommand *self,
                                                                 SSciLcCommand__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change870.IsTriggered)
    {
        if (((self->D1inCdActivation.Value == SSciLcCommand_D1inCdActivationValue__PreActivation) &&
             (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established)) &&
            (self->D65inConUsePreActivation.Value == true))
        {
            (*ctr)++;
        }
    }
    if (self->Change871.IsTriggered)
    {
        if ((self->D1inCdActivation.Value == SSciLcCommand_D1inCdActivationValue__Activation) &&
            (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1066.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change1148.IsTriggered)
    {
        if ((self->D3inCdLocalOperationHandover.Value ==
             SSciLcCommand_D3inCdLocalOperationHandoverValue__HandoverToLocalOperatorInitiated) &&
            (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1146.IsTriggered)
    {
        if ((self->D3inCdLocalOperationHandover.Value ==
             SSciLcCommand_D3inCdLocalOperationHandoverValue__HandoverToLocalOperatorEstablished) &&
            (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1147.IsTriggered)
    {
        if ((self->D3inCdLocalOperationHandover.Value ==
             SSciLcCommand_D3inCdLocalOperationHandoverValue__NoHandoverToLocalOperator) &&
            (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1199.IsTriggered)
    {
        if (((self->D4inCdIsolateLc.Value == SSciLcCommand_D4inCdIsolateLcValue__IsolateLcDisable) &&
             (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established)) &&
            (self->D67inConUseIsolation.Value == true))
        {
            (*ctr)++;
        }
    }
    if (self->Change1200.IsTriggered)
    {
        if (((self->D4inCdIsolateLc.Value == SSciLcCommand_D4inCdIsolateLcValue__IsolateLcEnable) &&
             (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established)) &&
            (self->D67inConUseIsolation.Value == true))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciLcCommand__root(int *ctr, SSciLcCommand *self, SSciLcCommand__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciLcCommand__root__SendingCommands:
        count_transitions_from_SSciLcCommand__root__SendingCommands(ctr, self, x);
        break;
    }
}

int count_transitions_SSciLcCommand(SSciLcCommand *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciLcCommand__root(&ctr, self, &self->state);
    return ctr;
}