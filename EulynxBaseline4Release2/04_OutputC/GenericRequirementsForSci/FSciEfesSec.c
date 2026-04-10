
#include "FSciEfesSec.h"

// Value Conversion Functions

// Operations
static void Cop1Init(FSciEfesSec *self)
{
    self->MemPdiVersion = self->D3inConPdiVersion.Value;
}

void make_state_FSciEfesSec__root__Active__root__Establishing__root__ReadyForInitialisation(
    FSciEfesSec *self, FSciEfesSec__root__Active__root__Establishing__root__state_struct *region)
{
    LOG("[FSciEfesSec] Entering state ReadyForInitialisation in region "
        "root__Active__root__Establishing__root");
    region->state = FSciEfesSec__root__Active__root__Establishing__root__ReadyForInitialisation;
};

void make_state_FSciEfesSec__root__Active__root__Establishing__root__SendingStatus(
    FSciEfesSec *self, FSciEfesSec__root__Active__root__Establishing__root__state_struct *region)
{
    LOG("[FSciEfesSec] Entering state SendingStatus in region "
        "root__Active__root__Establishing__root");
    region->state = FSciEfesSec__root__Active__root__Establishing__root__SendingStatus;
};

void make_state_FSciEfesSec__root__Active__root__Establishing__root__VersionUnequal(
    FSciEfesSec *self, FSciEfesSec__root__Active__root__Establishing__root__state_struct *region)
{
    LOG("[FSciEfesSec] Entering state VersionUnequal in region "
        "root__Active__root__Establishing__root");
    region->state = FSciEfesSec__root__Active__root__Establishing__root__VersionUnequal;
};

void make_state_FSciEfesSec__root__Active__root__Establishing__root(
    FSciEfesSec *self, FSciEfesSec__root__Active__root__Establishing__root__state_struct *x)
{
    memset(x, 0, sizeof(FSciEfesSec__root__Active__root__Establishing__root__state_struct));

    if (self->MemPdiVersion == self->D3inConPdiVersion.Value)
    {

        self->OutMsgPdiVersionCheck__9827.Value.Result = MsgPdiVersionCheck__9827_ResultValue__Match;
        memcpy(self->OutMsgPdiVersionCheck__9827.Value.ChecksumData, self->D4inConChecksumData.Value,
               sizeof(self->OutMsgPdiVersionCheck__9827.Value.ChecksumData));
        self->OutMsgPdiVersionCheck__9827.Value.PDIVersion = self->D3inConPdiVersion.Value;
        self->OutMsgPdiVersionCheck__9827.HasMessage = 1;
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForInitialisation;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__Active__root__Establishing__root__ReadyForInitialisation(self, x);
        return;
    }
    if (!(self->MemPdiVersion == self->D3inConPdiVersion.Value))
    {

        self->OutMsgPdiVersionCheck__9827.Value.Result = MsgPdiVersionCheck__9827_ResultValue__NotMatch;
        memcpy(self->OutMsgPdiVersionCheck__9827.Value.ChecksumData, self->D4inConChecksumData.Value,
               sizeof(self->OutMsgPdiVersionCheck__9827.Value.ChecksumData));
        self->OutMsgPdiVersionCheck__9827.Value.PDIVersion = self->D3inConPdiVersion.Value;
        self->OutMsgPdiVersionCheck__9827.HasMessage = 1;
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__VersionUnequal;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__Active__root__Establishing__root__VersionUnequal(self, x);
        return;
    }
}

void make_state_FSciEfesSec__root__Active__root__Establishing(FSciEfesSec *self,
                                                              FSciEfesSec__root__Active__root__state_struct *region)
{
    LOG("[FSciEfesSec] Entering state Establishing in region root__Active__root");
    region->state = FSciEfesSec__root__Active__root__Establishing;
    make_state_FSciEfesSec__root__Active__root__Establishing__root(self, &region->Establishing.root);
};

void make_state_FSciEfesSec__root__Active__root__Established(FSciEfesSec *self,
                                                             FSciEfesSec__root__Active__root__state_struct *region)
{
    LOG("[FSciEfesSec] Entering state Established in region root__Active__root");
    region->state = FSciEfesSec__root__Active__root__Established;
};

void make_state_FSciEfesSec__root__Active__root(FSciEfesSec *self, FSciEfesSec__root__Active__root__state_struct *x)
{
    memset(x, 0, sizeof(FSciEfesSec__root__Active__root__state_struct));

    make_state_FSciEfesSec__root__Active__root__Establishing(self, x);
    return;
}

void make_state_FSciEfesSec__root__NotReadyForPdi(FSciEfesSec *self, FSciEfesSec__root__state_struct *region)
{
    LOG("[FSciEfesSec] Entering state NotReadyForPdi in region root");
    region->state = FSciEfesSec__root__NotReadyForPdi;
};

void make_state_FSciEfesSec__root__Suspended(FSciEfesSec *self, FSciEfesSec__root__state_struct *region)
{
    LOG("[FSciEfesSec] Entering state Suspended in region root");
    region->state = FSciEfesSec__root__Suspended;
};

void make_state_FSciEfesSec__root__ReadyForPdi(FSciEfesSec *self, FSciEfesSec__root__state_struct *region)
{
    LOG("[FSciEfesSec] Entering state ReadyForPdi in region root");
    region->state = FSciEfesSec__root__ReadyForPdi;
};

void make_state_FSciEfesSec__root__Active(FSciEfesSec *self, FSciEfesSec__root__state_struct *region)
{
    LOG("[FSciEfesSec] Entering state Active in region root");
    region->state = FSciEfesSec__root__Active;
    make_state_FSciEfesSec__root__Active__root(self, &region->Active.root);
};

void make_state_FSciEfesSec__root__NotReadyForPdiNoScp(FSciEfesSec *self, FSciEfesSec__root__state_struct *region)
{
    LOG("[FSciEfesSec] Entering state NotReadyForPdiNoScp in region root");
    region->state = FSciEfesSec__root__NotReadyForPdiNoScp;
};

void make_state_FSciEfesSec__root__ReadyForPdiNoScp(FSciEfesSec *self, FSciEfesSec__root__state_struct *region)
{
    LOG("[FSciEfesSec] Entering state ReadyForPdiNoScp in region root");
    region->state = FSciEfesSec__root__ReadyForPdiNoScp;
};

void make_state_FSciEfesSec__root(FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{
    memset(x, 0, sizeof(FSciEfesSec__root__state_struct));
    Cop1Init(self);
    self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdiNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_FSciEfesSec__root__NotReadyForPdiNoScp(self, x);
    return;
}

void transition_from_FSciEfesSec__root__Active__root__Establishing__root__ReadyForInitialisation(
    FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{

    if (self->InCdInitialisationRequest__8d96.HasMessage)
    {

        self->OutMsgStartInitialisation__43d2.HasMessage = 1;
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__SendingStatus;
        self->D50outPdiConnectionState.IsSignalled = true;

        self->OutStartStatusReport__1e4e.HasMessage = 1;
        make_state_FSciEfesSec__root__Active__root__Establishing__root__SendingStatus(
            self, &x->Active.root.Establishing.root);
        return;
    }
}

void transition_from_FSciEfesSec__root__Active__root__Establishing__root__SendingStatus(
    FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{

    if (self->InStatusReportCompleted__b457.HasMessage)
    {

        self->OutMsgInitialisationCompleted__75d9.HasMessage = 1;
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__Established;
        self->D50outPdiConnectionState.IsSignalled = true;

        self->OutPdiConnectionEstablished__4cbf.HasMessage = 1;
        make_state_FSciEfesSec__root__Active__root__Established(self, &x->Active.root);
        return;
    }
}

void transition_from_FSciEfesSec__root__Active__root__Establishing__root__VersionUnequal(
    FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{
}

void transition_from_FSciEfesSec__root__Active__root__Establishing__root(FSciEfesSec *self,
                                                                         FSciEfesSec__root__state_struct *x)
{
    switch (x->Active.root.Establishing.root.state)
    {
    case FSciEfesSec__root__Active__root__Establishing__root__ReadyForInitialisation:
        transition_from_FSciEfesSec__root__Active__root__Establishing__root__ReadyForInitialisation(self, x);
        break;
    case FSciEfesSec__root__Active__root__Establishing__root__SendingStatus:
        transition_from_FSciEfesSec__root__Active__root__Establishing__root__SendingStatus(self, x);
        break;
    case FSciEfesSec__root__Active__root__Establishing__root__VersionUnequal:
        transition_from_FSciEfesSec__root__Active__root__Establishing__root__VersionUnequal(self, x);
        break;
    }
}

void transition_from_FSciEfesSec__root__Active__root__Establishing(FSciEfesSec *self,
                                                                   FSciEfesSec__root__state_struct *x)
{
    transition_from_FSciEfesSec__root__Active__root__Establishing__root(self, x);
}

void transition_from_FSciEfesSec__root__Active__root__Established(FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{
}

void transition_from_FSciEfesSec__root__Active__root(FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{
    switch (x->Active.root.state)
    {
    case FSciEfesSec__root__Active__root__Establishing:
        transition_from_FSciEfesSec__root__Active__root__Establishing(self, x);
        break;
    case FSciEfesSec__root__Active__root__Established:
        transition_from_FSciEfesSec__root__Active__root__Established(self, x);
        break;
    }
}

void transition_from_FSciEfesSec__root__NotReadyForPdi(FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{

    if (self->InCdPdiVersionCheck__ffab.HasMessage)
    {

        self->OutMsgPdiNotAvailable__b83e.HasMessage = 1;
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__Suspended;
        self->D50outPdiConnectionState.IsSignalled = true;

        self->OutPdiReleasedForMaintenance__3f7c.HasMessage = 1;
        make_state_FSciEfesSec__root__Suspended(self, x);
        return;
    }
    if (self->InReadyForPdiConnection__6bd3.HasMessage)
    {
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__ReadyForPdi(self, x);
        return;
    }
    if (self->Change749.IsTriggered)
    {
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdiNoScp;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__NotReadyForPdiNoScp(self, x);
        return;
    }
}

void transition_from_FSciEfesSec__root__Suspended(FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{

    if (self->InReadyForPdiConnection__6bd3.HasMessage)
    {

        self->OutMsgPdiAvailable__af0a.HasMessage = 1;
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__ReadyForPdi(self, x);
        return;
    }
    if (self->Change746.IsTriggered)
    {
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdiNoScp;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__NotReadyForPdiNoScp(self, x);
        return;
    }
}

void transition_from_FSciEfesSec__root__ReadyForPdi(FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{

    if (self->InCdPdiVersionCheck__ffab.HasMessage)
    {
        self->MemPdiVersion = self->InCdPdiVersionCheck__ffab.Value.PdiVersion;

        self->OutPdiConnectionStarted__f9c3.HasMessage = 1;
        make_state_FSciEfesSec__root__Active(self, x);
        return;
    }
    if (self->InNotreadyForPdiConnection__0b73.HasMessage)
    {
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__NotReadyForPdi(self, x);
        return;
    }
    if (self->Change750.IsTriggered)
    {
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdiNoScp;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__ReadyForPdiNoScp(self, x);
        return;
    }
}

void transition_from_FSciEfesSec__root__Active(FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{
    transition_from_FSciEfesSec__root__Active__root(self, x);
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__OtherVersionRequired)
        {

            self->OutPdiConnectionClosed__d803.HasMessage = 1;
            self->D60outPdiCloseReason.Value = FSciEfesSec_D60outPdiCloseReasonValue__PdiOtherVersionRequired;
            self->D60outPdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_FSciEfesSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__ContentTelegramError)
        {

            self->OutPdiConnectionClosed__d803.HasMessage = 1;
            self->D60outPdiCloseReason.Value = FSciEfesSec_D60outPdiCloseReasonValue__EilContentTelegramError;
            self->D60outPdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_FSciEfesSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__FormalTelegramError)
        {

            self->OutPdiConnectionClosed__d803.HasMessage = 1;
            self->D60outPdiCloseReason.Value = FSciEfesSec_D60outPdiCloseReasonValue__EilFormalTelegramError;
            self->D60outPdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_FSciEfesSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__NormalClose)
        {

            self->OutPdiConnectionClosed__d803.HasMessage = 1;
            self->D60outPdiCloseReason.Value = FSciEfesSec_D60outPdiCloseReasonValue__PdiNormalClose;
            self->D60outPdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_FSciEfesSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__ProtocolError)
        {

            self->OutPdiConnectionClosed__d803.HasMessage = 1;
            self->D60outPdiCloseReason.Value = FSciEfesSec_D60outPdiCloseReasonValue__EilProtocolError;
            self->D60outPdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_FSciEfesSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->InCdClosePdi__8a06.HasMessage)
    {
        if (self->InCdClosePdi__8a06.Value.RequestedCloseReason == CloseReason__91bc__Timeout)
        {

            self->OutPdiConnectionClosed__d803.HasMessage = 1;
            self->D60outPdiCloseReason.Value = FSciEfesSec_D60outPdiCloseReasonValue__PdiTimeout;
            self->D60outPdiCloseReason.IsSignalled = true;
            self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
            self->D50outPdiConnectionState.IsSignalled = true;
            make_state_FSciEfesSec__root__ReadyForPdi(self, x);
            return;
        }
    }
    if (self->InCdReleasePdiForMaintenance__3e43.HasMessage)
    {
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__Suspended;
        self->D50outPdiConnectionState.IsSignalled = true;

        self->OutPdiReleasedForMaintenance__3f7c.HasMessage = 1;
        make_state_FSciEfesSec__root__Suspended(self, x);
        return;
    }
    if (self->InNotreadyForPdiConnection__0b73.HasMessage)
    {

        self->OutMsgPdiNotAvailable__b83e.HasMessage = 1;
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__Suspended;
        self->D50outPdiConnectionState.IsSignalled = true;

        self->OutPdiReleasedForMaintenance__3f7c.HasMessage = 1;
        make_state_FSciEfesSec__root__Suspended(self, x);
        return;
    }
    if (self->Change747.IsTriggered)
    {

        self->OutPdiConnectionClosed__d803.HasMessage = 1;
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdiNoScp;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__ReadyForPdiNoScp(self, x);
        return;
    }
    if (self->Change985.IsTriggered)
    {

        self->OutMsgResetPdi__59f4.Value.ReportedResetReason = ResetReason__44e3__ProtocolError;
        self->OutMsgResetPdi__59f4.HasMessage = 1;

        self->OutPdiConnectionClosed__d803.HasMessage = 1;
        self->D60outPdiCloseReason.Value = FSciEfesSec_D60outPdiCloseReasonValue__EfesProtocolError;
        self->D60outPdiCloseReason.IsSignalled = true;
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__ReadyForPdi(self, x);
        return;
    }
    if (self->Change991.IsTriggered)
    {

        self->OutMsgResetPdi__59f4.Value.ReportedResetReason = ResetReason__44e3__FormalTelegramError;
        self->OutMsgResetPdi__59f4.HasMessage = 1;

        self->OutPdiConnectionClosed__d803.HasMessage = 1;
        self->D60outPdiCloseReason.Value = FSciEfesSec_D60outPdiCloseReasonValue__EfesFormalTelegramError;
        self->D60outPdiCloseReason.IsSignalled = true;
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__ReadyForPdi(self, x);
        return;
    }
    if (self->Change1007.IsTriggered)
    {

        self->OutMsgResetPdi__59f4.Value.ReportedResetReason = ResetReason__44e3__ContentTelegramError;
        self->OutMsgResetPdi__59f4.HasMessage = 1;

        self->OutPdiConnectionClosed__d803.HasMessage = 1;
        self->D60outPdiCloseReason.Value = FSciEfesSec_D60outPdiCloseReasonValue__EfesContentTelegramError;
        self->D60outPdiCloseReason.IsSignalled = true;
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__ReadyForPdi(self, x);
        return;
    }
}

void transition_from_FSciEfesSec__root__NotReadyForPdiNoScp(FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{

    if (self->InReadyForPdiConnection__6bd3.HasMessage)
    {
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdiNoScp;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__ReadyForPdiNoScp(self, x);
        return;
    }
    if (self->Change1227.IsTriggered)
    {
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__NotReadyForPdi(self, x);
        return;
    }
}

void transition_from_FSciEfesSec__root__ReadyForPdiNoScp(FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{

    if (self->InNotreadyForPdiConnection__0b73.HasMessage)
    {
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdiNoScp;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__NotReadyForPdiNoScp(self, x);
        return;
    }
    if (self->Change1225.IsTriggered)
    {
        self->D50outPdiConnectionState.Value = FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_FSciEfesSec__root__ReadyForPdi(self, x);
        return;
    }
}

void transition_from_FSciEfesSec__root(FSciEfesSec *self, FSciEfesSec__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciEfesSec__root__NotReadyForPdi:
        transition_from_FSciEfesSec__root__NotReadyForPdi(self, x);
        break;
    case FSciEfesSec__root__Suspended:
        transition_from_FSciEfesSec__root__Suspended(self, x);
        break;
    case FSciEfesSec__root__ReadyForPdi:
        transition_from_FSciEfesSec__root__ReadyForPdi(self, x);
        break;
    case FSciEfesSec__root__Active:
        transition_from_FSciEfesSec__root__Active(self, x);
        break;
    case FSciEfesSec__root__NotReadyForPdiNoScp:
        transition_from_FSciEfesSec__root__NotReadyForPdiNoScp(self, x);
        break;
    case FSciEfesSec__root__ReadyForPdiNoScp:
        transition_from_FSciEfesSec__root__ReadyForPdiNoScp(self, x);
        break;
    }
}

static void evaluateChangeEvents(FSciEfesSec *self)
{
    self->Change749.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
    self->Change746.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
    self->Change750.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
    self->Change747.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
    self->Change985.IsTriggered = self->T20inProtocolError.IsTriggered;
    self->Change991.IsTriggered = self->T21inFormalTelegramError.IsTriggered;
    self->Change1007.IsTriggered = self->T22inContentTelegramError.IsTriggered;
    self->Change1227.IsTriggered = self->T5inScpConnectionEstablished.IsTriggered;
    self->Change1225.IsTriggered = self->T5inScpConnectionEstablished.IsTriggered;
}

static void resetOutputs(FSciEfesSec *self)
{
    self->OutPdiReleasedForMaintenance__3f7c.HasMessage = false;
    self->OutStartStatusReport__1e4e.HasMessage = false;
    self->OutPdiConnectionEstablished__4cbf.HasMessage = false;
    self->OutMsgStartInitialisation__43d2.HasMessage = false;
    self->OutMsgInitialisationCompleted__75d9.HasMessage = false;
    self->OutMsgPdiVersionCheck__9827.HasMessage = false;
    self->OutMsgPdiNotAvailable__b83e.HasMessage = false;
    self->OutMsgPdiAvailable__af0a.HasMessage = false;
    self->OutPdiConnectionStarted__f9c3.HasMessage = false;
    self->OutPdiConnectionClosed__d803.HasMessage = false;
    self->OutMsgResetPdi__59f4.HasMessage = false;

    self->T12outTerminateScpConnection.Trigger = false;

    self->D50outPdiConnectionState.IsSignalled = false;
    self->D60outPdiCloseReason.IsSignalled = false;
}

static void resetTriggers(FSciEfesSec *self)
{
    self->InCdInitialisationRequest__8d96.HasMessage = false;
    self->InStatusReportCompleted__b457.HasMessage = false;
    self->InCdPdiVersionCheck__ffab.HasMessage = false;
    self->InReadyForPdiConnection__6bd3.HasMessage = false;
    self->InNotreadyForPdiConnection__0b73.HasMessage = false;
    self->InCdClosePdi__8a06.HasMessage = false;
    self->InCdReleasePdiForMaintenance__3e43.HasMessage = false;

    self->T20inProtocolError.IsTriggered = false;
    self->T21inFormalTelegramError.IsTriggered = false;
    self->T22inContentTelegramError.IsTriggered = false;
    self->T5inScpConnectionEstablished.IsTriggered = false;
    self->T10inScpConnectionTerminated.IsTriggered = false;

    self->D3inConPdiVersion.IsSignalled = false;
    self->D4inConChecksumData.IsSignalled = false;
}

void transition_FSciEfesSec(FSciEfesSec *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FSciEfesSec__root(self, &self->state);
    resetTriggers(self);
}

void new_FSciEfesSec(FSciEfesSec *self)
{
    make_state_FSciEfesSec__root(self, &self->state);
}
