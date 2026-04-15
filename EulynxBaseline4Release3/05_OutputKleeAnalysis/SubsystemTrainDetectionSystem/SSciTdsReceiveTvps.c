
#include "../../04_OutputC/SubsystemTrainDetectionSystem/SSciTdsReceiveTvps.h"

void count_transitions_from_SSciTdsReceiveTvps__root__ReceivingTvpsReports(int *ctr, SSciTdsReceiveTvps *self,
                                                                           SSciTdsReceiveTvps__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgCommandRejected__8d0b.HasMessage)
    {
        if (self->InMsgCommandRejected__8d0b.Value.ReportedReasonForRejection == ReasonForRejection__abec__Operational)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgCommandRejected__8d0b.HasMessage)
    {
        if (self->InMsgCommandRejected__8d0b.Value.ReportedReasonForRejection == ReasonForRejection__abec__Technical)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgTvpsFcPAFailed__3c61.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InMsgTvpsFcPFailed__811b.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciTdsReceiveTvps__root(int *ctr, SSciTdsReceiveTvps *self,
                                                     SSciTdsReceiveTvps__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciTdsReceiveTvps__root__ReceivingTvpsReports:
        count_transitions_from_SSciTdsReceiveTvps__root__ReceivingTvpsReports(ctr, self, x);
        break;
    }
}

int count_transitions_SSciTdsReceiveTvps(SSciTdsReceiveTvps *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciTdsReceiveTvps__root(&ctr, self, &self->state);
    return ctr;
}