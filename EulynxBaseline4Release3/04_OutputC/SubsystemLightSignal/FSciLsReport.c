
#include "FSciLsReport.h"

// Value Conversion Functions

// Operations
static void Cop1InitialReportStatus(FSciLsReport *self)
{
    if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__MostRestrictAspect)
    {

        self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
            SignalAspectState__f566__MostRestrictAspect;
        self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState = self->D20inObservedIntentionallyDark.Value;
        self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
    }
    else if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__NoSignalAspect)
    {

        self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
            SignalAspectState__f566__NoSignalAspect;
        self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState = self->D20inObservedIntentionallyDark.Value;
        self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
    }
    if (self->D21inObservedLuminosity.Value == FSciLsReport_D21inObservedLuminosityValue__Day)
    {

        self->OutMsgSetLuminosity__c2b4.Value.ReportedLuminosityState = LuminosityState__20ae__Day;
        self->OutMsgSetLuminosity__c2b4.HasMessage = 1;
    }
    else if (self->D21inObservedLuminosity.Value == FSciLsReport_D21inObservedLuminosityValue__Night)
    {

        self->OutMsgSetLuminosity__c2b4.Value.ReportedLuminosityState = LuminosityState__20ae__Night;
        self->OutMsgSetLuminosity__c2b4.HasMessage = 1;
    }
}

void make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
    FSciLsReport *self, FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__state_struct *region)
{
    LOG("[FSciLsReport] Entering state SendingSignalAspectReports in region "
        "root__SendingLightSignalReports__ReportingSignalAspect");
    region->state = FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports;
};

void make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect(
    FSciLsReport *self, FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__state_struct *x)
{
    memset(x, 0, sizeof(FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__state_struct));

    make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(self,
                                                                                                                x);
    return;
}

void make_state_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports(
    FSciLsReport *self, FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__state_struct *region)
{
    LOG("[FSciLsReport] Entering state SendingLuminosityReports in region "
        "root__SendingLightSignalReports__ReportingLuminosity");
    region->state = FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports;
};

void make_state_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity(
    FSciLsReport *self, FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__state_struct *x)
{
    memset(x, 0, sizeof(FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__state_struct));

    make_state_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports(self, x);
    return;
}

void make_state_FSciLsReport__root__SendingLightSignalReports(FSciLsReport *self,
                                                              FSciLsReport__root__state_struct *region)
{
    LOG("[FSciLsReport] Entering state SendingLightSignalReports in region root");
    region->state = FSciLsReport__root__SendingLightSignalReports;
    make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect(
        self, &region->SendingLightSignalReports.ReportingSignalAspect);
    make_state_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity(
        self, &region->SendingLightSignalReports.ReportingLuminosity);
};

void make_state_FSciLsReport__root__InterfaceConnectionNotEstablished(FSciLsReport *self,
                                                                      FSciLsReport__root__state_struct *region)
{
    LOG("[FSciLsReport] Entering state InterfaceConnectionNotEstablished in region root");
    region->state = FSciLsReport__root__InterfaceConnectionNotEstablished;
};

void make_state_FSciLsReport__root(FSciLsReport *self, FSciLsReport__root__state_struct *x)
{
    memset(x, 0, sizeof(FSciLsReport__root__state_struct));

    make_state_FSciLsReport__root__InterfaceConnectionNotEstablished(self, x);
    return;
}

void transition_from_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
    FSciLsReport *self, FSciLsReport__root__state_struct *x)
{

    if (self->Change132.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__MostRestrictAspect;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
    if (self->Change133.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__NoSignalAspect;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
    if (self->Change134.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__SignalAspect1;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
    if (self->Change135.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__SignalAspect2;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
    if (self->Change169.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__SignalAspect1)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__SignalAspect1;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
    if (self->Change168.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__SignalAspect2)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__SignalAspect2;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
    if (self->Change170.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__MostRestrictAspect)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__MostRestrictAspect;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
    if (self->Change301.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__NoSignalAspect)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__NoSignalAspect;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
    if (self->Change300.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__MostRestrictAspect)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__MostRestrictAspect;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
    if (self->Change554.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__SignalAspect1)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__SignalAspect1;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
    if (self->Change556.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__SignalAspect2)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__SignalAspect2;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
    if (self->Change555.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__MostRestrictAspect)
        {

            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedSignalAspectState =
                SignalAspectState__f566__MostRestrictAspect;
            self->OutMsgIndicatedSignalAspect__e129.Value.ReportedDarkState =
                self->D20inObservedIntentionallyDark.Value;
            self->OutMsgIndicatedSignalAspect__e129.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
                self, &x->SendingLightSignalReports.ReportingSignalAspect);
            return;
        }
    }
}

void transition_from_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect(
    FSciLsReport *self, FSciLsReport__root__state_struct *x)
{
    switch (x->SendingLightSignalReports.ReportingSignalAspect.state)
    {
    case FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports:
        transition_from_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
            self, x);
        break;
    }
}

void transition_from_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports(
    FSciLsReport *self, FSciLsReport__root__state_struct *x)
{

    if (self->Change171.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgSetLuminosity__c2b4.Value.ReportedLuminosityState = LuminosityState__20ae__Day;
            self->OutMsgSetLuminosity__c2b4.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports(
                self, &x->SendingLightSignalReports.ReportingLuminosity);
            return;
        }
    }
    if (self->Change172.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgSetLuminosity__c2b4.Value.ReportedLuminosityState = LuminosityState__20ae__Night;
            self->OutMsgSetLuminosity__c2b4.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports(
                self, &x->SendingLightSignalReports.ReportingLuminosity);
            return;
        }
    }
    if (self->Change302.IsTriggered)
    {
        if (self->D21inObservedLuminosity.Value == FSciLsReport_D21inObservedLuminosityValue__Night)
        {

            self->OutMsgSetLuminosity__c2b4.Value.ReportedLuminosityState = LuminosityState__20ae__Night;
            self->OutMsgSetLuminosity__c2b4.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports(
                self, &x->SendingLightSignalReports.ReportingLuminosity);
            return;
        }
    }
    if (self->Change298.IsTriggered)
    {
        if (self->D21inObservedLuminosity.Value == FSciLsReport_D21inObservedLuminosityValue__Day)
        {

            self->OutMsgSetLuminosity__c2b4.Value.ReportedLuminosityState = LuminosityState__20ae__Day;
            self->OutMsgSetLuminosity__c2b4.HasMessage = 1;
            make_state_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports(
                self, &x->SendingLightSignalReports.ReportingLuminosity);
            return;
        }
    }
}

void transition_from_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity(
    FSciLsReport *self, FSciLsReport__root__state_struct *x)
{
    switch (x->SendingLightSignalReports.ReportingLuminosity.state)
    {
    case FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports:
        transition_from_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports(
            self, x);
        break;
    }
}

void transition_from_FSciLsReport__root__SendingLightSignalReports(FSciLsReport *self,
                                                                   FSciLsReport__root__state_struct *x)
{
    transition_from_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect(self, x);
    transition_from_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity(self, x);
    if (self->Change312.IsTriggered)
    {

        make_state_FSciLsReport__root__InterfaceConnectionNotEstablished(self, x);
        return;
    }
}

void transition_from_FSciLsReport__root__InterfaceConnectionNotEstablished(FSciLsReport *self,
                                                                           FSciLsReport__root__state_struct *x)
{

    if (self->InStartStatusReport__1e4e.HasMessage)
    {
        Cop1InitialReportStatus(self);

        self->OutStatusReportCompleted__b457.HasMessage = 1;
        make_state_FSciLsReport__root__SendingLightSignalReports(self, x);
        return;
    }
}

void transition_from_FSciLsReport__root(FSciLsReport *self, FSciLsReport__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciLsReport__root__SendingLightSignalReports:
        transition_from_FSciLsReport__root__SendingLightSignalReports(self, x);
        break;
    case FSciLsReport__root__InterfaceConnectionNotEstablished:
        transition_from_FSciLsReport__root__InterfaceConnectionNotEstablished(self, x);
        break;
    }
}

static void evaluateChangeEvents(FSciLsReport *self)
{
    self->Change132.IsTriggered = IsTriggered(MakeChange(
        self->D19inObservedSignalAspect.IsSignalled,
        self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__MostRestrictAspect));
    self->Change133.IsTriggered = IsTriggered(MakeChange(
        self->D19inObservedSignalAspect.IsSignalled,
        self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__NoSignalAspect));
    self->Change134.IsTriggered = IsTriggered(MakeChange(
        self->D19inObservedSignalAspect.IsSignalled,
        self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__SignalAspect1));
    self->Change135.IsTriggered = IsTriggered(MakeChange(
        self->D19inObservedSignalAspect.IsSignalled,
        self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__SignalAspect2));
    self->Change169.IsTriggered = IsTriggered(
        MakeChange(self->D20inObservedIntentionallyDark.IsSignalled, self->D20inObservedIntentionallyDark.Value));
    self->Change168.IsTriggered = IsTriggered(
        MakeChange(self->D20inObservedIntentionallyDark.IsSignalled, self->D20inObservedIntentionallyDark.Value));
    self->Change170.IsTriggered = IsTriggered(
        MakeChange(self->D20inObservedIntentionallyDark.IsSignalled, self->D20inObservedIntentionallyDark.Value));
    self->Change301.IsTriggered = IsTriggered(
        MakeChange(self->D50inPdiConnectionState.IsSignalled,
                   self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established));
    self->Change300.IsTriggered = IsTriggered(
        MakeChange(self->D50inPdiConnectionState.IsSignalled,
                   self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established));
    self->Change554.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D20inObservedIntentionallyDark.IsSignalled, self->D20inObservedIntentionallyDark.Value)));
    self->Change556.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D20inObservedIntentionallyDark.IsSignalled, self->D20inObservedIntentionallyDark.Value)));
    self->Change555.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D20inObservedIntentionallyDark.IsSignalled, self->D20inObservedIntentionallyDark.Value)));
    self->Change171.IsTriggered =
        IsTriggered(MakeChange(self->D21inObservedLuminosity.IsSignalled,
                               self->D21inObservedLuminosity.Value == FSciLsReport_D21inObservedLuminosityValue__Day));
    self->Change172.IsTriggered = IsTriggered(
        MakeChange(self->D21inObservedLuminosity.IsSignalled,
                   self->D21inObservedLuminosity.Value == FSciLsReport_D21inObservedLuminosityValue__Night));
    self->Change302.IsTriggered = IsTriggered(
        MakeChange(self->D50inPdiConnectionState.IsSignalled,
                   self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established));
    self->Change298.IsTriggered = IsTriggered(
        MakeChange(self->D50inPdiConnectionState.IsSignalled,
                   self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established));
    self->Change312.IsTriggered = IsTriggered(OrChange(
        OrChange(
            MakeChange(self->D50inPdiConnectionState.IsSignalled,
                       self->D50inPdiConnectionState.Value ==
                           FSciLsReport_D50inPdiConnectionStateValue__ReadyForPdiNoScp),
            MakeChange(self->D50inPdiConnectionState.IsSignalled,
                       self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__ReadyForPdi)),
        MakeChange(self->D50inPdiConnectionState.IsSignalled,
                   self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Suspended)));
}

static void resetOutputs(FSciLsReport *self)
{
    self->OutMsgIndicatedSignalAspect__e129.HasMessage = false;
    self->OutMsgSetLuminosity__c2b4.HasMessage = false;
    self->OutStatusReportCompleted__b457.HasMessage = false;
}

static void resetTriggers(FSciLsReport *self)
{
    self->InStartStatusReport__1e4e.HasMessage = false;

    self->D50inPdiConnectionState.IsSignalled = false;
    self->D20inObservedIntentionallyDark.IsSignalled = false;
    self->D19inObservedSignalAspect.IsSignalled = false;
    self->D21inObservedLuminosity.IsSignalled = false;
}

void transition_FSciLsReport(FSciLsReport *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FSciLsReport__root(self, &self->state);
    resetTriggers(self);
}

void new_FSciLsReport(FSciLsReport *self)
{
    make_state_FSciLsReport__root(self, &self->state);
}
