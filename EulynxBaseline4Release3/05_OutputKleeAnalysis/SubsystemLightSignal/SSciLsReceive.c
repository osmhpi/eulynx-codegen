
#include "../../04_OutputC/SubsystemLightSignal/SSciLsReceive.h"

void count_transitions_from_SSciLsReceive__root__ReceivingLightSignalReports(int *ctr, SSciLsReceive *self,
                                                                             SSciLsReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__SignalAspect1) &&
            (!(self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState)))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__SignalAspect1) &&
            (self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__SignalAspect2) &&
            (!(self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState)))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__SignalAspect2) &&
            (self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__MostRestrictAspect) &&
            (!(self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState)))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__MostRestrictAspect) &&
            (self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if (self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
            SignalAspectState__f566__NoSignalAspect)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgSetLuminosity__c2b4.HasMessage)
    {
        if (self->InMsgSetLuminosity__c2b4.Value.ReportedLuminosityState == LuminosityState__20ae__Night)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgSetLuminosity__c2b4.HasMessage)
    {
        if (self->InMsgSetLuminosity__c2b4.Value.ReportedLuminosityState == LuminosityState__20ae__Day)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciLsReceive__root(int *ctr, SSciLsReceive *self, SSciLsReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciLsReceive__root__ReceivingLightSignalReports:
        count_transitions_from_SSciLsReceive__root__ReceivingLightSignalReports(ctr, self, x);
        break;
    }
}

int count_transitions_SSciLsReceive(SSciLsReceive *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciLsReceive__root(&ctr, self, &self->state);
    return ctr;
}