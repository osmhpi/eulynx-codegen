
#include "../../04_OutputC/GenericRequirementsForSci/SSciEfesPrim.h"

void count_transitions_from_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(
    int *ctr, SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgPdiVersionCheck__9827.HasMessage)
    {
        self->MemPdiVersionResult = map_Result_to_MemPdiVersionResult(self->InMsgPdiVersionCheck__9827.Value.Result);
        memcpy(self->MemChecksumData, self->InMsgPdiVersionCheck__9827.Value.ChecksumData,
               sizeof(self->MemChecksumData));
        if (self->MemPdiVersionResult == SSciEfesPrim_MemPdiVersionResultValue__Match)
        {

            if (!(memcmp(self->MemChecksumData, self->D4inConChecksumData.Value, sizeof(self->MemChecksumData)) == 0))
            {
                (*ctr)++;
            }
            if (memcmp(self->MemChecksumData, self->D4inConChecksumData.Value, sizeof(self->MemChecksumData)) == 0)
            {
                (*ctr)++;
            }
        }
        if (self->MemPdiVersionResult == SSciEfesPrim_MemPdiVersionResultValue__NotMatch)
        {

            if (self->D39inConLastPdiVersion.Value == false)
            {
                (*ctr)++;
            }
            if (self->D39inConLastPdiVersion.Value == true)
            {
                (*ctr)++;
            }
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForInitialisation(
    int *ctr, SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x)
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

void count_transitions_from_SSciEfesPrim__root__Active__root__Establishing__root__ReceivingStatus(
    int *ctr, SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x)
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

void count_transitions_from_SSciEfesPrim__root__Active__root__Establishing__root__OtherVersionRequired(
    int *ctr, SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1168.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciEfesPrim__root__Active__root__Establishing__root(int *ctr, SSciEfesPrim *self,
                                                                                 SSciEfesPrim__root__state_struct *x)
{
    switch (x->Active.root.Establishing.root.state)
    {
    case SSciEfesPrim__root__Active__root__Establishing__root__WaitingForVersionCheck:
        count_transitions_from_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(ctr, self,
                                                                                                            x);
        break;
    case SSciEfesPrim__root__Active__root__Establishing__root__WaitingForInitialisation:
        count_transitions_from_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForInitialisation(ctr, self,
                                                                                                              x);
        break;
    case SSciEfesPrim__root__Active__root__Establishing__root__ReceivingStatus:
        count_transitions_from_SSciEfesPrim__root__Active__root__Establishing__root__ReceivingStatus(ctr, self, x);
        break;
    case SSciEfesPrim__root__Active__root__Establishing__root__OtherVersionRequired:
        count_transitions_from_SSciEfesPrim__root__Active__root__Establishing__root__OtherVersionRequired(ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciEfesPrim__root__Active__root__Establishing(int *ctr, SSciEfesPrim *self,
                                                                           SSciEfesPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_SSciEfesPrim__root__Active__root__Establishing__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Time22.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciEfesPrim__root__Active__root__Established(int *ctr, SSciEfesPrim *self,
                                                                          SSciEfesPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciEfesPrim__root__Active__root(int *ctr, SSciEfesPrim *self,
                                                             SSciEfesPrim__root__state_struct *x)
{
    switch (x->Active.root.state)
    {
    case SSciEfesPrim__root__Active__root__Establishing:
        count_transitions_from_SSciEfesPrim__root__Active__root__Establishing(ctr, self, x);
        break;
    case SSciEfesPrim__root__Active__root__Established:
        count_transitions_from_SSciEfesPrim__root__Active__root__Established(ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciEfesPrim__root__RequestedNoScp(int *ctr, SSciEfesPrim *self,
                                                               SSciEfesPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1171.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1217.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciEfesPrim__root__ImpermissibleNoScp(int *ctr, SSciEfesPrim *self,
                                                                   SSciEfesPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1163.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1219.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciEfesPrim__root__Impermissible(int *ctr, SSciEfesPrim *self,
                                                              SSciEfesPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change742.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1162.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciEfesPrim__root__Disconnected(int *ctr, SSciEfesPrim *self,
                                                             SSciEfesPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change736.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1174.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciEfesPrim__root__DisconnectedNoScp(int *ctr, SSciEfesPrim *self,
                                                                  SSciEfesPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1173.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1223.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciEfesPrim__root__Active(int *ctr, SSciEfesPrim *self,
                                                       SSciEfesPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_SSciEfesPrim__root__Active__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->InMsgPdiNotAvailable__b83e.HasMessage)
    {
        (*ctr)++;
    }
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
    if (self->Change737.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change978.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change987.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change997.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1155.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1170.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciEfesPrim__root__Suspended(int *ctr, SSciEfesPrim *self,
                                                          SSciEfesPrim__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgPdiAvailable__af0a.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change744.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1172.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciEfesPrim__root(int *ctr, SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciEfesPrim__root__RequestedNoScp:
        count_transitions_from_SSciEfesPrim__root__RequestedNoScp(ctr, self, x);
        break;
    case SSciEfesPrim__root__ImpermissibleNoScp:
        count_transitions_from_SSciEfesPrim__root__ImpermissibleNoScp(ctr, self, x);
        break;
    case SSciEfesPrim__root__Impermissible:
        count_transitions_from_SSciEfesPrim__root__Impermissible(ctr, self, x);
        break;
    case SSciEfesPrim__root__Disconnected:
        count_transitions_from_SSciEfesPrim__root__Disconnected(ctr, self, x);
        break;
    case SSciEfesPrim__root__DisconnectedNoScp:
        count_transitions_from_SSciEfesPrim__root__DisconnectedNoScp(ctr, self, x);
        break;
    case SSciEfesPrim__root__Active:
        count_transitions_from_SSciEfesPrim__root__Active(ctr, self, x);
        break;
    case SSciEfesPrim__root__Suspended:
        count_transitions_from_SSciEfesPrim__root__Suspended(ctr, self, x);
        break;
    }
}

int count_transitions_SSciEfesPrim(SSciEfesPrim *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciEfesPrim__root(&ctr, self, &self->state);
    return ctr;
}