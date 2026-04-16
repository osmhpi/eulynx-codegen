
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FTds6MaintainerCommandsAndMessages.h"

void count_transitions_from_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(
    int *ctr, FTds6MaintainerCommandsAndMessages *self, FTds6MaintainerCommandsAndMessages__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InReportCommandRejected__fa56.HasMessage)
    {
        if (self->InReportCommandRejected__fa56.Value.ReportedReasonForRejection ==
            ReasonForRejection__abec__Operational)
        {
            (*ctr)++;
        }
    }
    if (self->InReportCommandRejected__fa56.HasMessage)
    {
        if (self->InReportCommandRejected__fa56.Value.ReportedReasonForRejection == ReasonForRejection__abec__Technical)
        {
            (*ctr)++;
        }
    }
    if (self->Change1096.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1097.IsTriggered)
    {
        if (self->D35inModeOfFc.Value == FTds6MaintainerCommandsAndMessages_D35inModeOfFcValue__FcU)
        {
            (*ctr)++;
        }
    }
    if (self->Change1098.IsTriggered)
    {
        if (self->D35inModeOfFc.Value == FTds6MaintainerCommandsAndMessages_D35inModeOfFcValue__FcC)
        {
            (*ctr)++;
        }
    }
    if (self->Change1158.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FTds6MaintainerCommandsAndMessages__root(
    int *ctr, FTds6MaintainerCommandsAndMessages *self, FTds6MaintainerCommandsAndMessages__root__state_struct *x)
{
    switch (x->state)
    {
    case FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages:
        count_transitions_from_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(ctr, self,
                                                                                                            x);
        break;
    }
}

int count_transitions_FTds6MaintainerCommandsAndMessages(FTds6MaintainerCommandsAndMessages *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FTds6MaintainerCommandsAndMessages__root(&ctr, self, &self->state);
    return ctr;
}