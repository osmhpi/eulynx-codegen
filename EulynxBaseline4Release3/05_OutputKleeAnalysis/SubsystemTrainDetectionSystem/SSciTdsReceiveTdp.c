
#include "../../04_OutputC/SubsystemTrainDetectionSystem/SSciTdsReceiveTdp.h"

void count_transitions_from_SSciTdsReceiveTdp__root__ReceivingTdpReports(int *ctr, SSciTdsReceiveTdp *self,
                                                                         SSciTdsReceiveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {
        if ((self->InMsgTdpStatus__b6d9.Value.ReportedStateOfPassing == StateOfPassing__616f__Passed) &&
            (self->InMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing ==
             DirectionOfPassing__a7c9__ReferenceDirection))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {
        if ((self->InMsgTdpStatus__b6d9.Value.ReportedStateOfPassing == StateOfPassing__616f__Passed) &&
            (self->InMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing ==
             DirectionOfPassing__a7c9__AgainstRefernceDirection))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {
        if ((self->InMsgTdpStatus__b6d9.Value.ReportedStateOfPassing == StateOfPassing__616f__Passed) &&
            (self->InMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing ==
             DirectionOfPassing__a7c9__WithoutIndicatedDirection))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {
        if (self->InMsgTdpStatus__b6d9.Value.ReportedStateOfPassing == StateOfPassing__616f__Disturbed)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {
        if (self->InMsgTdpStatus__b6d9.Value.ReportedStateOfPassing == StateOfPassing__616f__NotPassed)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciTdsReceiveTdp__root(int *ctr, SSciTdsReceiveTdp *self,
                                                    SSciTdsReceiveTdp__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciTdsReceiveTdp__root__ReceivingTdpReports:
        count_transitions_from_SSciTdsReceiveTdp__root__ReceivingTdpReports(ctr, self, x);
        break;
    }
}

int count_transitions_SSciTdsReceiveTdp(SSciTdsReceiveTdp *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciTdsReceiveTdp__root(&ctr, self, &self->state);
    return ctr;
}