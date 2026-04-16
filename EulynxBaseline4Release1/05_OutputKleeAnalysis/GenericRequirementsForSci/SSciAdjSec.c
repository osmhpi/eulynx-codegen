
#include "../../04_OutputC/GenericRequirementsForSci/SSciAdjSec.h"

void count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root__ReadyForInitialisation(
    int *ctr, SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdInitialisationRequest__8d96.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root__SendingSecStatus(
    int *ctr, SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InSecStatusReportCompleted__339c.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root__VersionUnequal(
    int *ctr, SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root__ReceivingPrimStatus(
    int *ctr, SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
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

void count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root__CheckingPrimStatus(
    int *ctr, SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
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

void count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root(int *ctr, SSciAdjSec *self,
                                                                               SSciAdjSec__root__state_struct *x)
{
    switch (x->Active.root.Establishing.root.state)
    {
    case SSciAdjSec__root__Active__root__Establishing__root__ReadyForInitialisation:
        count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root__ReadyForInitialisation(ctr, self, x);
        break;
    case SSciAdjSec__root__Active__root__Establishing__root__SendingSecStatus:
        count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root__SendingSecStatus(ctr, self, x);
        break;
    case SSciAdjSec__root__Active__root__Establishing__root__VersionUnequal:
        count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root__VersionUnequal(ctr, self, x);
        break;
    case SSciAdjSec__root__Active__root__Establishing__root__ReceivingPrimStatus:
        count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root__ReceivingPrimStatus(ctr, self, x);
        break;
    case SSciAdjSec__root__Active__root__Establishing__root__CheckingPrimStatus:
        count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root__CheckingPrimStatus(ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciAdjSec__root__Active__root__Establishing(int *ctr, SSciAdjSec *self,
                                                                         SSciAdjSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_SSciAdjSec__root__Active__root__Establishing__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjSec__root__Active__root__Established(int *ctr, SSciAdjSec *self,
                                                                        SSciAdjSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjSec__root__Active__root(int *ctr, SSciAdjSec *self,
                                                           SSciAdjSec__root__state_struct *x)
{
    switch (x->Active.root.state)
    {
    case SSciAdjSec__root__Active__root__Establishing:
        count_transitions_from_SSciAdjSec__root__Active__root__Establishing(ctr, self, x);
        break;
    case SSciAdjSec__root__Active__root__Established:
        count_transitions_from_SSciAdjSec__root__Active__root__Established(ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciAdjSec__root__RequestedNoScp(int *ctr, SSciAdjSec *self,
                                                             SSciAdjSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1224.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjSec__root__ReadyForPdi(int *ctr, SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdPdiVersionCheck__ffab.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change744.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciAdjSec__root__Active(int *ctr, SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_SSciAdjSec__root__Active__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__Timeout)
        {
            (*ctr)++;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__FormalTelegramError)
        {
            (*ctr)++;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__ProtocolError)
        {
            (*ctr)++;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__OtherVersionRequired)
        {
            (*ctr)++;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__ChecksumMismatch)
        {
            (*ctr)++;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__ContentTelegramError)
        {
            (*ctr)++;
        }
    }
    if (self->Change747.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change977.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change988.IsTriggered)
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

void count_transitions_from_SSciAdjSec__root(int *ctr, SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciAdjSec__root__RequestedNoScp:
        count_transitions_from_SSciAdjSec__root__RequestedNoScp(ctr, self, x);
        break;
    case SSciAdjSec__root__ReadyForPdi:
        count_transitions_from_SSciAdjSec__root__ReadyForPdi(ctr, self, x);
        break;
    case SSciAdjSec__root__Active:
        count_transitions_from_SSciAdjSec__root__Active(ctr, self, x);
        break;
    }
}

int count_transitions_SSciAdjSec(SSciAdjSec *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciAdjSec__root(&ctr, self, &self->state);
    return ctr;
}