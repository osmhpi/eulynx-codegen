
#include "SSciAdjSec.h"

// Value Conversion Functions

// Operations
static void Cop1Init(SSciAdjSec *self)
{
    self->MemPdiVersion = self->D3inConPdiVersion.Value;
}

void make_state_SSciAdjSec__root__Active__root__Establishing__root__ReadyForInitialisation(
    SSciAdjSec *self, SSciAdjSec__root__Active__root__Establishing__root__state_struct *region)
{
    LOG("[SSciAdjSec] Entering state ReadyForInitialisation in region root__Active__root__Establishing__root");
    region->state = SSciAdjSec__root__Active__root__Establishing__root__ReadyForInitialisation;
};

void make_state_SSciAdjSec__root__Active__root__Establishing__root__SendingSecStatus(
    SSciAdjSec *self, SSciAdjSec__root__Active__root__Establishing__root__state_struct *region)
{
    LOG("[SSciAdjSec] Entering state SendingSecStatus in region root__Active__root__Establishing__root");
    region->state = SSciAdjSec__root__Active__root__Establishing__root__SendingSecStatus;
};

void make_state_SSciAdjSec__root__Active__root__Establishing__root__VersionUnequal(
    SSciAdjSec *self, SSciAdjSec__root__Active__root__Establishing__root__state_struct *region)
{
    LOG("[SSciAdjSec] Entering state VersionUnequal in region root__Active__root__Establishing__root");
    region->state = SSciAdjSec__root__Active__root__Establishing__root__VersionUnequal;
};

void make_state_SSciAdjSec__root__Active__root__Establishing__root__ReceivingPrimStatus(
    SSciAdjSec *self, SSciAdjSec__root__Active__root__Establishing__root__state_struct *region)
{
    LOG("[SSciAdjSec] Entering state ReceivingPrimStatus in region root__Active__root__Establishing__root");
    region->state = SSciAdjSec__root__Active__root__Establishing__root__ReceivingPrimStatus;
};

void make_state_SSciAdjSec__root__Active__root__Establishing__root__CheckingPrimStatus(
    SSciAdjSec *self, SSciAdjSec__root__Active__root__Establishing__root__state_struct *region)
{
    LOG("[SSciAdjSec] Entering state CheckingPrimStatus in region root__Active__root__Establishing__root");
    region->state = SSciAdjSec__root__Active__root__Establishing__root__CheckingPrimStatus;
};

void make_state_SSciAdjSec__root__Active__root__Establishing__root(
    SSciAdjSec *self, SSciAdjSec__root__Active__root__Establishing__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciAdjSec__root__Active__root__Establishing__root__state_struct));

    if (self->MemPdiVersion == self->D3inConPdiVersion.Value)
    {

        self->OutMsgPdiVersionCheck__9827.Value.Result = MsgPdiVersionCheck__9827_ResultValue__Match;
        memcpy(self->OutMsgPdiVersionCheck__9827.Value.ChecksumData, self->D4inConChecksumData.Value,
               sizeof(self->OutMsgPdiVersionCheck__9827.Value.ChecksumData));
        self->OutMsgPdiVersionCheck__9827.Value.PDIVersion = self->D3inConPdiVersion.Value;
        self->OutMsgPdiVersionCheck__9827.HasMessage = 1;
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReadyForInitialisation;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciAdjSec__root__Active__root__Establishing__root__ReadyForInitialisation(self, x);
        return;
    }
    if (!(self->MemPdiVersion == self->D3inConPdiVersion.Value))
    {

        self->OutMsgPdiVersionCheck__9827.Value.Result = MsgPdiVersionCheck__9827_ResultValue__NotMatch;
        memcpy(self->OutMsgPdiVersionCheck__9827.Value.ChecksumData, self->D4inConChecksumData.Value,
               sizeof(self->OutMsgPdiVersionCheck__9827.Value.ChecksumData));
        self->OutMsgPdiVersionCheck__9827.Value.PDIVersion = self->D3inConPdiVersion.Value;
        self->OutMsgPdiVersionCheck__9827.HasMessage = 1;
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__VersionUnequal;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciAdjSec__root__Active__root__Establishing__root__VersionUnequal(self, x);
        return;
    }
}

void make_state_SSciAdjSec__root__Active__root__Establishing(SSciAdjSec *self,
                                                             SSciAdjSec__root__Active__root__state_struct *region)
{
    LOG("[SSciAdjSec] Entering state Establishing in region root__Active__root");
    region->state = SSciAdjSec__root__Active__root__Establishing;
    make_state_SSciAdjSec__root__Active__root__Establishing__root(self, &region->Establishing.root);
};

void make_state_SSciAdjSec__root__Active__root__Established(SSciAdjSec *self,
                                                            SSciAdjSec__root__Active__root__state_struct *region)
{
    LOG("[SSciAdjSec] Entering state Established in region root__Active__root");
    region->state = SSciAdjSec__root__Active__root__Established;
};

void make_state_SSciAdjSec__root__Active__root(SSciAdjSec *self, SSciAdjSec__root__Active__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciAdjSec__root__Active__root__state_struct));

    self->OutEstablishingPdiConnection__41d4.HasMessage = 1;
    make_state_SSciAdjSec__root__Active__root__Establishing(self, x);
    return;
}

void make_state_SSciAdjSec__root__RequestedNoScp(SSciAdjSec *self, SSciAdjSec__root__state_struct *region)
{
    LOG("[SSciAdjSec] Entering state RequestedNoScp in region root");
    region->state = SSciAdjSec__root__RequestedNoScp;
};

void make_state_SSciAdjSec__root__ReadyForPdi(SSciAdjSec *self, SSciAdjSec__root__state_struct *region)
{
    LOG("[SSciAdjSec] Entering state ReadyForPdi in region root");
    region->state = SSciAdjSec__root__ReadyForPdi;
};

void make_state_SSciAdjSec__root__Active(SSciAdjSec *self, SSciAdjSec__root__state_struct *region)
{
    LOG("[SSciAdjSec] Entering state Active in region root");
    region->state = SSciAdjSec__root__Active;
    make_state_SSciAdjSec__root__Active__root(self, &region->Active.root);
};

void make_state_SSciAdjSec__root(SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciAdjSec__root__state_struct));
    Cop1Init(self);
    self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__RequestedNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciAdjSec__root__RequestedNoScp(self, x);
    return;
}

void transition_from_SSciAdjSec__root__Active__root__Establishing__root__ReadyForInitialisation(
    SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{

    if (self->InCdInitialisationRequest__8d96.HasMessage)
    {

        self->OutMsgStartInitialisation__43d2.HasMessage = 1;
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__SendingSecStatus;
        self->D50outPdiConnectionState.IsSignalled = true;

        self->OutStartSecStatusReport__2c19.HasMessage = 1;
        make_state_SSciAdjSec__root__Active__root__Establishing__root__SendingSecStatus(
            self, &x->Active.root.Establishing.root);
        return;
    }
}

void transition_from_SSciAdjSec__root__Active__root__Establishing__root__SendingSecStatus(
    SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{

    if (self->InSecStatusReportCompleted__339c.HasMessage)
    {
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReceivingPrimStatus;
        self->D50outPdiConnectionState.IsSignalled = true;

        self->OutMsgStatusReportCompleted__c465.HasMessage = 1;
        make_state_SSciAdjSec__root__Active__root__Establishing__root__ReceivingPrimStatus(
            self, &x->Active.root.Establishing.root);
        return;
    }
}

void transition_from_SSciAdjSec__root__Active__root__Establishing__root__VersionUnequal(
    SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
}

void transition_from_SSciAdjSec__root__Active__root__Establishing__root__ReceivingPrimStatus(
    SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{

    if (self->InMsgStatusReportCompleted__c465.HasMessage)
    {
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__CheckingPrimStatus;
        self->D50outPdiConnectionState.IsSignalled = true;
        self->T27outCheckPrimStatus.Trigger = true;
        make_state_SSciAdjSec__root__Active__root__Establishing__root__CheckingPrimStatus(
            self, &x->Active.root.Establishing.root);
        return;
    }
}

void transition_from_SSciAdjSec__root__Active__root__Establishing__root__CheckingPrimStatus(
    SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{

    if (self->Change1025.IsTriggered)
    {

        self->OutMsgInitialisationCompleted__75d9.HasMessage = 1;
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__Established;
        self->D50outPdiConnectionState.IsSignalled = true;

        self->OutPdiConnectionEstablished__019d.HasMessage = 1;
        make_state_SSciAdjSec__root__Active__root__Established(self, &x->Active.root);
        return;
    }
}

void transition_from_SSciAdjSec__root__Active__root__Establishing__root(SSciAdjSec *self,
                                                                        SSciAdjSec__root__state_struct *x)
{
    switch (x->Active.root.Establishing.root.state)
    {
    case SSciAdjSec__root__Active__root__Establishing__root__ReadyForInitialisation:
        transition_from_SSciAdjSec__root__Active__root__Establishing__root__ReadyForInitialisation(self, x);
        break;
    case SSciAdjSec__root__Active__root__Establishing__root__SendingSecStatus:
        transition_from_SSciAdjSec__root__Active__root__Establishing__root__SendingSecStatus(self, x);
        break;
    case SSciAdjSec__root__Active__root__Establishing__root__VersionUnequal:
        transition_from_SSciAdjSec__root__Active__root__Establishing__root__VersionUnequal(self, x);
        break;
    case SSciAdjSec__root__Active__root__Establishing__root__ReceivingPrimStatus:
        transition_from_SSciAdjSec__root__Active__root__Establishing__root__ReceivingPrimStatus(self, x);
        break;
    case SSciAdjSec__root__Active__root__Establishing__root__CheckingPrimStatus:
        transition_from_SSciAdjSec__root__Active__root__Establishing__root__CheckingPrimStatus(self, x);
        break;
    }
}

void transition_from_SSciAdjSec__root__Active__root__Establishing(SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
    transition_from_SSciAdjSec__root__Active__root__Establishing__root(self, x);
}

void transition_from_SSciAdjSec__root__Active__root__Established(SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
}

void transition_from_SSciAdjSec__root__Active__root(SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
    switch (x->Active.root.state)
    {
    case SSciAdjSec__root__Active__root__Establishing:
        transition_from_SSciAdjSec__root__Active__root__Establishing(self, x);
        break;
    case SSciAdjSec__root__Active__root__Established:
        transition_from_SSciAdjSec__root__Active__root__Established(self, x);
        break;
    }
}

void transition_from_SSciAdjSec__root__RequestedNoScp(SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{

    if (self->Change1228.IsTriggered)
    {
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciAdjSec__root__ReadyForPdi(self, x);
        return;
    }
}

void transition_from_SSciAdjSec__root__ReadyForPdi(SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{

    if (self->InCdPdiVersionCheck__ffab.HasMessage)
    {
        self->MemPdiVersion = self->InCdPdiVersionCheck__ffab.Value.PdiVersion;
        make_state_SSciAdjSec__root__Active(self, x);
        return;
    }
    if (self->Change753.IsTriggered)
    {
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__RequestedNoScp;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciAdjSec__root__RequestedNoScp(self, x);
        return;
    }
}

void transition_from_SSciAdjSec__root__Active(SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
    transition_from_SSciAdjSec__root__Active__root(self, x);
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__Timeout)
        {
            self->D60PdiCloseReason.Value = SSciAdjSec_D60PdiCloseReasonValue__PdiTimeout;
            self->D60PdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_SSciAdjSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__FormalTelegramError)
        {
            self->D60PdiCloseReason.Value = SSciAdjSec_D60PdiCloseReasonValue__PrimFormalTelegramError;
            self->D60PdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_SSciAdjSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__ProtocolError)
        {
            self->D60PdiCloseReason.Value = SSciAdjSec_D60PdiCloseReasonValue__PrimProtocolError;
            self->D60PdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_SSciAdjSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__OtherVersionRequired)
        {
            self->D60PdiCloseReason.Value = SSciAdjSec_D60PdiCloseReasonValue__PdiOtherVersionRequired;
            self->D60PdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_SSciAdjSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__ChecksumMismatch)
        {
            self->D60PdiCloseReason.Value = SSciAdjSec_D60PdiCloseReasonValue__PdiChecksumMismatch;
            self->D60PdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_SSciAdjSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__ContentTelegramError)
        {
            self->D60PdiCloseReason.Value = SSciAdjSec_D60PdiCloseReasonValue__PrimContentTelegramError;
            self->D60PdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_SSciAdjSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->Change745.IsTriggered)
    {
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__RequestedNoScp;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciAdjSec__root__RequestedNoScp(self, x);
        return;
    }
    if (self->Change983.IsTriggered)
    {

        self->OutMsgResetPdi__59f4.Value.ReportedResetReason = ResetReason__44e3__ProtocolError;
        self->OutMsgResetPdi__59f4.HasMessage = 1;
        self->D60PdiCloseReason.Value = SSciAdjSec_D60PdiCloseReasonValue__SecProtocolError;
        self->D60PdiCloseReason.IsSignalled = true;
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciAdjSec__root__ReadyForPdi(self, x);
        return;
    }
    if (self->Change992.IsTriggered)
    {

        self->OutMsgResetPdi__59f4.Value.ReportedResetReason = ResetReason__44e3__FormalTelegramError;
        self->OutMsgResetPdi__59f4.HasMessage = 1;
        self->D60PdiCloseReason.Value = SSciAdjSec_D60PdiCloseReasonValue__SecFormalTelegramError;
        self->D60PdiCloseReason.IsSignalled = true;
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciAdjSec__root__ReadyForPdi(self, x);
        return;
    }
    if (self->Change1004.IsTriggered)
    {

        self->OutMsgResetPdi__59f4.Value.ReportedResetReason = ResetReason__44e3__ContentTelegramError;
        self->OutMsgResetPdi__59f4.HasMessage = 1;
        self->D60PdiCloseReason.Value = SSciAdjSec_D60PdiCloseReasonValue__SecContentTelegramError;
        self->D60PdiCloseReason.IsSignalled = true;
        self->D50outPdiConnectionState.Value = SSciAdjSec_D50outPdiConnectionStateValue__ReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciAdjSec__root__ReadyForPdi(self, x);
        return;
    }
}

void transition_from_SSciAdjSec__root(SSciAdjSec *self, SSciAdjSec__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciAdjSec__root__RequestedNoScp:
        transition_from_SSciAdjSec__root__RequestedNoScp(self, x);
        break;
    case SSciAdjSec__root__ReadyForPdi:
        transition_from_SSciAdjSec__root__ReadyForPdi(self, x);
        break;
    case SSciAdjSec__root__Active:
        transition_from_SSciAdjSec__root__Active(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciAdjSec *self)
{
    self->Change1025.IsTriggered = self->T25inPrimStatusReportComplete.IsTriggered;
    self->Change1228.IsTriggered = self->T5inScpConnectionEstablished.IsTriggered;
    self->Change753.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
    self->Change745.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
    self->Change983.IsTriggered = self->T20inProtocolError.IsTriggered;
    self->Change992.IsTriggered = self->T21inFormalTelegramError.IsTriggered;
    self->Change1004.IsTriggered = self->T22inContentTelegramError.IsTriggered;
}

static void resetOutputs(SSciAdjSec *self)
{
    self->OutStartSecStatusReport__2c19.HasMessage = false;
    self->OutMsgStatusReportCompleted__c465.HasMessage = false;
    self->OutPdiConnectionEstablished__019d.HasMessage = false;
    self->OutPdiConnectionClosed__7975.HasMessage = false;
    self->OutMsgStartInitialisation__43d2.HasMessage = false;
    self->OutMsgInitialisationCompleted__75d9.HasMessage = false;
    self->OutMsgPdiVersionCheck__9827.HasMessage = false;
    self->OutEstablishingPdiConnection__41d4.HasMessage = false;
    self->OutMsgResetPdi__59f4.HasMessage = false;

    self->T11outPdiConnectionEstablished.Trigger = false;
    self->T17outPdiConnectionClosed.Trigger = false;
    self->T27outCheckPrimStatus.Trigger = false;

    self->D50outPdiConnectionState.IsSignalled = false;
}

static void resetTriggers(SSciAdjSec *self)
{
    self->InCdInitialisationRequest__8d96.HasMessage = false;
    self->InSecStatusReportCompleted__339c.HasMessage = false;
    self->InMsgStatusReportCompleted__c465.HasMessage = false;
    self->InCdPdiVersionCheck__ffab.HasMessage = false;
    self->InCdClosePdi__8a06.HasMessage = false;

    self->T5inScpConnectionEstablished.IsTriggered = false;
    self->T10inScpConnectionTerminated.IsTriggered = false;
    self->T25inPrimStatusReportComplete.IsTriggered = false;
    self->T22inContentTelegramError.IsTriggered = false;
    self->T20inProtocolError.IsTriggered = false;
    self->T21inFormalTelegramError.IsTriggered = false;

    self->D3inConPdiVersion.IsSignalled = false;
    self->D4inConChecksumData.IsSignalled = false;
}

void transition_SSciAdjSec(SSciAdjSec *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciAdjSec__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciAdjSec(SSciAdjSec *self)
{
    make_state_SSciAdjSec__root(self, &self->state);
}
