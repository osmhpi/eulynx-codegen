
#include "../../04_OutputC/GenericRequirementsForSci/SSciAdjPrim.h"

void count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(
    int *ctr, SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgPdiVersionCheck__9827.HasMessage)
    {
        if ((self->InMsgPdiVersionCheck__9827.Value.Result == MsgPdiVersionCheck__9827_ResultValue__Match) &&
            (memcmp(self->InMsgPdiVersionCheck__9827.Value.ChecksumData, self->D4inConChecksumData.Value,
                    sizeof(self->InMsgPdiVersionCheck__9827.Value.ChecksumData)) == 0))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPdiVersionCheck__9827.HasMessage)
    {
        if ((self->InMsgPdiVersionCheck__9827.Value.Result == MsgPdiVersionCheck__9827_ResultValue__Match) &&
            (!(memcmp(self->InMsgPdiVersionCheck__9827.Value.ChecksumData, self->D4inConChecksumData.Value,
                      sizeof(self->InMsgPdiVersionCheck__9827.Value.ChecksumData)) == 0)))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPdiVersionCheck__9827.HasMessage)
    {
        if (self->InMsgPdiVersionCheck__9827.Value.Result == MsgPdiVersionCheck__9827_ResultValue__NotMatch)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitialisation(
    int *ctr, SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgStartInitialisation__43d2.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__ReceivingSecStatus(
    int *ctr, SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgStatusReportCompleted__c465.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__CheckingSecStatus(
    int *ctr, SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1019.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__SendingPrimStatus(
    int *ctr, SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InPrimStatusReportCompleted__80d8.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitCompletion(
    int *ctr, SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgInitialisationCompleted__75d9.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root(int *ctr, SSciAdjPrim *self,
                                                                                SSciAdjPrim__root__state_struct *x)
{
    switch (x->Active.root.Establishing.root.state)
    {
    case SSciAdjPrim__root__Active__root__Establishing__root__WaitingForVersionCheck:
        count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(ctr, self,
                                                                                                           x);
        break;
    case SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitialisation:
        count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitialisation(ctr, self,
                                                                                                             x);
        break;
    case SSciAdjPrim__root__Active__root__Establishing__root__ReceivingSecStatus:
        count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__ReceivingSecStatus(ctr, self, x);
        break;
    case SSciAdjPrim__root__Active__root__Establishing__root__CheckingSecStatus:
        count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__CheckingSecStatus(ctr, self, x);
        break;
    case SSciAdjPrim__root__Active__root__Establishing__root__SendingPrimStatus:
        count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__SendingPrimStatus(ctr, self, x);
        break;
    case SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitCompletion:
        count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitCompletion(ctr, self,
                                                                                                             x);
        break;
    }
}

void count_transitions_from_SSciAdjPrim__root__Active__root__Establishing(int *ctr, SSciAdjPrim *self,
                                                                          SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_SSciAdjPrim__root__Active__root__Establishing__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Time23.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root__Active__root__Established(int *ctr, SSciAdjPrim *self,
                                                                         SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root__Active__root(int *ctr, SSciAdjPrim *self,
                                                            SSciAdjPrim__root__state_struct *x)
{
    switch (x->Active.root.state)
    {
    case SSciAdjPrim__root__Active__root__Establishing:
        count_transitions_from_SSciAdjPrim__root__Active__root__Establishing(ctr, self, x);
        break;
    case SSciAdjPrim__root__Active__root__Established:
        count_transitions_from_SSciAdjPrim__root__Active__root__Established(ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciAdjPrim__root__RequestedNoScp(int *ctr, SSciAdjPrim *self,
                                                              SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1220.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root__ImpermissibleNoScp(int *ctr, SSciAdjPrim *self,
                                                                  SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1164.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1216.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root__Impermissible(int *ctr, SSciAdjPrim *self,
                                                             SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change738.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1165.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root__Active(int *ctr, SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_SSciAdjPrim__root__Active__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->InMsgResetPdi__59f4.HasMessage)
    {
        if (self->InMsgResetPdi__59f4.Value.ReportedResetReason == ResetReason__44e3__ProtocolError)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgResetPdi__59f4.HasMessage)
    {
        if (self->InMsgResetPdi__59f4.Value.ReportedResetReason == ResetReason__44e3__ContentTelegramError)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgResetPdi__59f4.HasMessage)
    {
        if (self->InMsgResetPdi__59f4.Value.ReportedResetReason == ResetReason__44e3__FormalTelegramError)
        {
            (*ctr)++;
        }
    }
    if (self->Change741.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change979.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change986.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1000.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjPrim__root(int *ctr, SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciAdjPrim__root__RequestedNoScp:
        count_transitions_from_SSciAdjPrim__root__RequestedNoScp(ctr, self, x);
        break;
    case SSciAdjPrim__root__ImpermissibleNoScp:
        count_transitions_from_SSciAdjPrim__root__ImpermissibleNoScp(ctr, self, x);
        break;
    case SSciAdjPrim__root__Impermissible:
        count_transitions_from_SSciAdjPrim__root__Impermissible(ctr, self, x);
        break;
    case SSciAdjPrim__root__Active:
        count_transitions_from_SSciAdjPrim__root__Active(ctr, self, x);
        break;
    }
}

int count_transitions_SSciAdjPrim(SSciAdjPrim *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciAdjPrim__root(&ctr, self, &self->state);
    return ctr;
}