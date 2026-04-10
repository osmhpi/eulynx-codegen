
#include "SSciLsReceive.h"

// Value Conversion Functions

// Operations

void make_state_SSciLsReceive__root__ReceivingLightSignalReports(SSciLsReceive *self,
                                                                 SSciLsReceive__root__state_struct *region)
{
    LOG("[SSciLsReceive] Entering state ReceivingLightSignalReports in region "
        "root");
    region->state = SSciLsReceive__root__ReceivingLightSignalReports;
};

void make_state_SSciLsReceive__root(SSciLsReceive *self, SSciLsReceive__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciLsReceive__root__state_struct));

    make_state_SSciLsReceive__root__ReceivingLightSignalReports(self, x);
    return;
}

void transition_from_SSciLsReceive__root__ReceivingLightSignalReports(SSciLsReceive *self,
                                                                      SSciLsReceive__root__state_struct *x)
{

    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__SignalAspect1) &&
            (!(self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState)))
        {
            self->D26outSignalAspect.Value = SSciLsReceive_D26outSignalAspectValue__SignalAspect1;
            self->D26outSignalAspect.IsSignalled = true;
            self->D27outIntentionallyDark.Value = false;
            make_state_SSciLsReceive__root__ReceivingLightSignalReports(self, x);
            return;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__SignalAspect1) &&
            (self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState))
        {
            self->D26outSignalAspect.Value = SSciLsReceive_D26outSignalAspectValue__SignalAspect1;
            self->D26outSignalAspect.IsSignalled = true;
            self->D27outIntentionallyDark.Value = true;
            make_state_SSciLsReceive__root__ReceivingLightSignalReports(self, x);
            return;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__SignalAspect2) &&
            (!(self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState)))
        {
            self->D26outSignalAspect.Value = SSciLsReceive_D26outSignalAspectValue__SignalAspect2;
            self->D26outSignalAspect.IsSignalled = true;
            self->D27outIntentionallyDark.Value = false;
            make_state_SSciLsReceive__root__ReceivingLightSignalReports(self, x);
            return;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__SignalAspect2) &&
            (self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState))
        {
            self->D26outSignalAspect.Value = SSciLsReceive_D26outSignalAspectValue__SignalAspect2;
            self->D26outSignalAspect.IsSignalled = true;
            self->D27outIntentionallyDark.Value = true;
            make_state_SSciLsReceive__root__ReceivingLightSignalReports(self, x);
            return;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__MostRestrictAspect) &&
            (!(self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState)))
        {
            self->D26outSignalAspect.Value = SSciLsReceive_D26outSignalAspectValue__MostRestrictAspect;
            self->D26outSignalAspect.IsSignalled = true;
            self->D27outIntentionallyDark.Value = false;
            make_state_SSciLsReceive__root__ReceivingLightSignalReports(self, x);
            return;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if ((self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
             SignalAspectState__f566__MostRestrictAspect) &&
            (self->InMsgIndicatedSignalAspect__e129.Value.ReportedDarkState))
        {
            self->D26outSignalAspect.Value = SSciLsReceive_D26outSignalAspectValue__MostRestrictAspect;
            self->D26outSignalAspect.IsSignalled = true;
            self->D27outIntentionallyDark.Value = true;
            make_state_SSciLsReceive__root__ReceivingLightSignalReports(self, x);
            return;
        }
    }
    if (self->InMsgIndicatedSignalAspect__e129.HasMessage)
    {
        if (self->InMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState ==
            SignalAspectState__f566__NoSignalAspect)
        {
            self->D26outSignalAspect.Value = SSciLsReceive_D26outSignalAspectValue__NoSignalAspect;
            self->D26outSignalAspect.IsSignalled = true;
            make_state_SSciLsReceive__root__ReceivingLightSignalReports(self, x);
            return;
        }
    }
    if (self->InMsgSetLuminosity__c2b4.HasMessage)
    {
        if (self->InMsgSetLuminosity__c2b4.Value.ReportedLuminosityState == LuminosityState__20ae__Night)
        {
            self->D28outLuminosity.Value = SSciLsReceive_D28outLuminosityValue__Night;
            self->D28outLuminosity.IsSignalled = true;
            make_state_SSciLsReceive__root__ReceivingLightSignalReports(self, x);
            return;
        }
    }
    if (self->InMsgSetLuminosity__c2b4.HasMessage)
    {
        if (self->InMsgSetLuminosity__c2b4.Value.ReportedLuminosityState == LuminosityState__20ae__Day)
        {
            self->D28outLuminosity.Value = SSciLsReceive_D28outLuminosityValue__Day;
            self->D28outLuminosity.IsSignalled = true;
            make_state_SSciLsReceive__root__ReceivingLightSignalReports(self, x);
            return;
        }
    }
}

void transition_from_SSciLsReceive__root(SSciLsReceive *self, SSciLsReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciLsReceive__root__ReceivingLightSignalReports:
        transition_from_SSciLsReceive__root__ReceivingLightSignalReports(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciLsReceive *self)
{
}

static void resetOutputs(SSciLsReceive *self)
{

    self->D26outSignalAspect.IsSignalled = false;
    self->D27outIntentionallyDark.IsSignalled = false;
    self->D28outLuminosity.IsSignalled = false;
}

static void resetTriggers(SSciLsReceive *self)
{
    self->InMsgIndicatedSignalAspect__e129.HasMessage = false;
    self->InMsgSetLuminosity__c2b4.HasMessage = false;
}

void transition_SSciLsReceive(SSciLsReceive *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciLsReceive__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciLsReceive(SSciLsReceive *self)
{
    make_state_SSciLsReceive__root(self, &self->state);
}
