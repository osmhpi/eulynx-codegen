
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FSciTdsReceive.h"

void count_transitions_from_FSciTdsReceive__root__ReceivingCommands(int *ctr, FSciTdsReceive *self,
                                                                    FSciTdsReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdCancel__6acf.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InCdDrfc__15c7.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InCdFc__ec57.HasMessage)
    {
        if (self->InCdFc__ec57.Value.CommandedModeOfFC == ModeOfFC__fc54__FcPA)
        {
            (*ctr)++;
        }
    }
    if (self->InCdFc__ec57.HasMessage)
    {
        if (self->InCdFc__ec57.Value.CommandedModeOfFC == ModeOfFC__fc54__AcknowledgmentafterfcPACommand)
        {
            (*ctr)++;
        }
    }
    if (self->InCdFc__ec57.HasMessage)
    {
        if (self->InCdFc__ec57.Value.CommandedModeOfFC == ModeOfFC__fc54__FcP)
        {
            (*ctr)++;
        }
    }
    if (self->InCdFc__ec57.HasMessage)
    {
        if (self->InCdFc__ec57.Value.CommandedModeOfFC == ModeOfFC__fc54__FcU)
        {
            (*ctr)++;
        }
    }
    if (self->InCdFc__ec57.HasMessage)
    {
        if (self->InCdFc__ec57.Value.CommandedModeOfFC == ModeOfFC__fc54__FcC)
        {
            (*ctr)++;
        }
    }
    if (self->InCdUpdateFillingLevel__d24d.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReceive__root(int *ctr, FSciTdsReceive *self, FSciTdsReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciTdsReceive__root__ReceivingCommands:
        count_transitions_from_FSciTdsReceive__root__ReceivingCommands(ctr, self, x);
        break;
    }
}

int count_transitions_FSciTdsReceive(FSciTdsReceive *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciTdsReceive__root(&ctr, self, &self->state);
    return ctr;
}