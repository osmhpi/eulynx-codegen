
#include "../../04_OutputC/GenericRequirementsForSci/FSciEfesSec.h"

void count_transitions_from_FSciEfesSec__root__Active__root__Establishing__root__ReadyForInitialisation(
    int *ctr, FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
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

void count_transitions_from_FSciEfesSec__root__Active__root__Establishing__root__SendingStatus(
    int *ctr, FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InStatusReportCompleted__b457.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciEfesSec__root__Active__root__Establishing__root__VersionUnequal(
    int *ctr, FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciEfesSec__root__Active__root__Establishing__root(int *ctr, FSciEfesSec *self,
                                                                                FSciEfesSec__root__state_struct *x)
{
    switch (x->Active.root.Establishing.root.state)
    {
    case FSciEfesSec__root__Active__root__Establishing__root__ReadyForInitialisation:
        count_transitions_from_FSciEfesSec__root__Active__root__Establishing__root__ReadyForInitialisation(ctr, self,
                                                                                                           x);
        break;
    case FSciEfesSec__root__Active__root__Establishing__root__SendingStatus:
        count_transitions_from_FSciEfesSec__root__Active__root__Establishing__root__SendingStatus(ctr, self, x);
        break;
    case FSciEfesSec__root__Active__root__Establishing__root__VersionUnequal:
        count_transitions_from_FSciEfesSec__root__Active__root__Establishing__root__VersionUnequal(ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciEfesSec__root__Active__root__Establishing(int *ctr, FSciEfesSec *self,
                                                                          FSciEfesSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciEfesSec__root__Active__root__Establishing__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciEfesSec__root__Active__root__Established(int *ctr, FSciEfesSec *self,
                                                                         FSciEfesSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciEfesSec__root__Active__root(int *ctr, FSciEfesSec *self,
                                                            FSciEfesSec__root__state_struct *x)
{
    switch (x->Active.root.state)
    {
    case FSciEfesSec__root__Active__root__Establishing:
        count_transitions_from_FSciEfesSec__root__Active__root__Establishing(ctr, self, x);
        break;
    case FSciEfesSec__root__Active__root__Established:
        count_transitions_from_FSciEfesSec__root__Active__root__Established(ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciEfesSec__root__NotReadyForPdi(int *ctr, FSciEfesSec *self,
                                                              FSciEfesSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdPdiVersionCheck__ffab.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InReadyForPdiConnection__6bd3.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change745.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciEfesSec__root__Suspended(int *ctr, FSciEfesSec *self,
                                                         FSciEfesSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InReadyForPdiConnection__6bd3.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change746.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciEfesSec__root__ReadyForPdi(int *ctr, FSciEfesSec *self,
                                                           FSciEfesSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdPdiVersionCheck__ffab.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InNotreadyForPdiConnection__0b73.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change747.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciEfesSec__root__Active(int *ctr, FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciEfesSec__root__Active__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__OtherVersionRequired)
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
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__FormalTelegramError)
        {
            (*ctr)++;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__NormalClose)
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
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__Timeout)
        {
            (*ctr)++;
        }
    }
    if (self->InCdReleasePdiForMaintenance__3e43.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InNotreadyForPdiConnection__0b73.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change743.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change977.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change984.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change999.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciEfesSec__root__NotReadyForPdiNoScp(int *ctr, FSciEfesSec *self,
                                                                   FSciEfesSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InReadyForPdiConnection__6bd3.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change1222.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciEfesSec__root__ReadyForPdiNoScp(int *ctr, FSciEfesSec *self,
                                                                FSciEfesSec__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InNotreadyForPdiConnection__0b73.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change1221.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciEfesSec__root(int *ctr, FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciEfesSec__root__NotReadyForPdi:
        count_transitions_from_FSciEfesSec__root__NotReadyForPdi(ctr, self, x);
        break;
    case FSciEfesSec__root__Suspended:
        count_transitions_from_FSciEfesSec__root__Suspended(ctr, self, x);
        break;
    case FSciEfesSec__root__ReadyForPdi:
        count_transitions_from_FSciEfesSec__root__ReadyForPdi(ctr, self, x);
        break;
    case FSciEfesSec__root__Active:
        count_transitions_from_FSciEfesSec__root__Active(ctr, self, x);
        break;
    case FSciEfesSec__root__NotReadyForPdiNoScp:
        count_transitions_from_FSciEfesSec__root__NotReadyForPdiNoScp(ctr, self, x);
        break;
    case FSciEfesSec__root__ReadyForPdiNoScp:
        count_transitions_from_FSciEfesSec__root__ReadyForPdiNoScp(ctr, self, x);
        break;
    }
}

int count_transitions_FSciEfesSec(FSciEfesSec *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciEfesSec__root(&ctr, self, &self->state);
    return ctr;
}