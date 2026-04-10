
#include "SSciAdjPrim.h"

// Value Conversion Functions

// Operations
static void Cop1Init(SSciAdjPrim *self) {
  self->MemPdiVersionCheckResult =
      SSciAdjPrim_MemPdiVersionCheckResultValue__Unknown;
  memcpy(self->MemPdiVersionChecksumdata, self->D4inConChecksumData.Value,
         sizeof(self->MemPdiVersionChecksumdata));
}

void make_state_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(
    SSciAdjPrim *self,
    SSciAdjPrim__root__Active__root__Establishing__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state WaitingForVersionCheck in region "
      "root__Active__root__Establishing__root");
  region->state =
      SSciAdjPrim__root__Active__root__Establishing__root__WaitingForVersionCheck;
};

void make_state_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitialisation(
    SSciAdjPrim *self,
    SSciAdjPrim__root__Active__root__Establishing__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state WaitingForInitialisation in region "
      "root__Active__root__Establishing__root");
  region->state =
      SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitialisation;
};

void make_state_SSciAdjPrim__root__Active__root__Establishing__root__ReceivingSecStatus(
    SSciAdjPrim *self,
    SSciAdjPrim__root__Active__root__Establishing__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state ReceivingSecStatus in region "
      "root__Active__root__Establishing__root");
  region->state =
      SSciAdjPrim__root__Active__root__Establishing__root__ReceivingSecStatus;
};

void make_state_SSciAdjPrim__root__Active__root__Establishing__root__CheckingSecStatus(
    SSciAdjPrim *self,
    SSciAdjPrim__root__Active__root__Establishing__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state CheckingSecStatus in region "
      "root__Active__root__Establishing__root");
  region->state =
      SSciAdjPrim__root__Active__root__Establishing__root__CheckingSecStatus;
};

void make_state_SSciAdjPrim__root__Active__root__Establishing__root__SendingPrimStatus(
    SSciAdjPrim *self,
    SSciAdjPrim__root__Active__root__Establishing__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state SendingPrimStatus in region "
      "root__Active__root__Establishing__root");
  region->state =
      SSciAdjPrim__root__Active__root__Establishing__root__SendingPrimStatus;
};

void make_state_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitCompletion(
    SSciAdjPrim *self,
    SSciAdjPrim__root__Active__root__Establishing__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state WaitingForInitCompletion in region "
      "root__Active__root__Establishing__root");
  region->state =
      SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitCompletion;
};

void make_state_SSciAdjPrim__root__Active__root__Establishing__root(
    SSciAdjPrim *self,
    SSciAdjPrim__root__Active__root__Establishing__root__state_struct *x) {
  memset(
      x, 0,
      sizeof(
          SSciAdjPrim__root__Active__root__Establishing__root__state_struct));

  self->OutEstablishingPdiConnection__41d4.HasMessage = 1;

  self->OutCdPdiVersionCheck__ffab.Value.PdiVersion =
      self->D3inConPdiVersion.Value;
  self->OutCdPdiVersionCheck__ffab.HasMessage = 1;
  self->D50outPdiConnectionState.Value =
      SSciAdjPrim_D50outPdiConnectionStateValue__WaitingForVersionCheck;
  self->D50outPdiConnectionState.IsSignalled = true;
  make_state_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(
      self, x);
  return;
}

void make_state_SSciAdjPrim__root__Active__root__Establishing(
    SSciAdjPrim *self, SSciAdjPrim__root__Active__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state Establishing in region root__Active__root");
  region->state = SSciAdjPrim__root__Active__root__Establishing;
  make_state_SSciAdjPrim__root__Active__root__Establishing__root(
      self, &region->Establishing.root);
};

void make_state_SSciAdjPrim__root__Active__root__Established(
    SSciAdjPrim *self, SSciAdjPrim__root__Active__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state Established in region root__Active__root");
  region->state = SSciAdjPrim__root__Active__root__Established;
};

void make_state_SSciAdjPrim__root__Active__root(
    SSciAdjPrim *self, SSciAdjPrim__root__Active__root__state_struct *x) {
  memset(x, 0, sizeof(SSciAdjPrim__root__Active__root__state_struct));

  make_state_SSciAdjPrim__root__Active__root__Establishing(self, x);
  return;
}

void make_state_SSciAdjPrim__root__RequestedNoScp(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state RequestedNoScp in region root");
  region->state = SSciAdjPrim__root__RequestedNoScp;
};

void make_state_SSciAdjPrim__root__ImpermissibleNoScp(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state ImpermissibleNoScp in region root");
  region->state = SSciAdjPrim__root__ImpermissibleNoScp;
};

void make_state_SSciAdjPrim__root__Impermissible(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state Impermissible in region root");
  region->state = SSciAdjPrim__root__Impermissible;
};

void make_state_SSciAdjPrim__root__Active(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *region) {
  LOG("[SSciAdjPrim] Entering state Active in region root");
  region->state = SSciAdjPrim__root__Active;
  make_state_SSciAdjPrim__root__Active__root(self, &region->Active.root);
};

void make_state_SSciAdjPrim__root(SSciAdjPrim *self,
                                  SSciAdjPrim__root__state_struct *x) {
  memset(x, 0, sizeof(SSciAdjPrim__root__state_struct));
  Cop1Init(self);
  self->D50outPdiConnectionState.Value =
      SSciAdjPrim_D50outPdiConnectionStateValue__RequestedNoScp;
  self->D50outPdiConnectionState.IsSignalled = true;
  self->T6outEstablishScpConnection.Trigger = true;
  make_state_SSciAdjPrim__root__RequestedNoScp(self, x);
  return;
}

void transition_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {

  if (self->InMsgPdiVersionCheck__9827.HasMessage) {
    if ((self->InMsgPdiVersionCheck__9827.Value.Result ==
         MsgPdiVersionCheck__9827_ResultValue__Match) &&
        (memcmp(self->InMsgPdiVersionCheck__9827.Value.ChecksumData,
                self->D4inConChecksumData.Value,
                sizeof(self->InMsgPdiVersionCheck__9827.Value.ChecksumData)) ==
         0)) {

      self->OutCdInitialisationRequest__8d96.HasMessage = 1;
      self->D50outPdiConnectionState.Value =
          SSciAdjPrim_D50outPdiConnectionStateValue__WaitingForInitialisation;
      self->D50outPdiConnectionState.IsSignalled = true;
      make_state_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitialisation(
          self, &x->Active.root.Establishing.root);
      return;
    }
  }
  if (self->InMsgPdiVersionCheck__9827.HasMessage) {
    if ((self->InMsgPdiVersionCheck__9827.Value.Result ==
         MsgPdiVersionCheck__9827_ResultValue__Match) &&
        (!(memcmp(
               self->InMsgPdiVersionCheck__9827.Value.ChecksumData,
               self->D4inConChecksumData.Value,
               sizeof(self->InMsgPdiVersionCheck__9827.Value.ChecksumData)) ==
           0))) {
      self->D60outPdiCloseReason.Value =
          SSciAdjPrim_D60outPdiCloseReasonValue__PdiChecksumMismatch;
      self->D60outPdiCloseReason.IsSignalled = true;

      self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
          CloseReason__91bc__ChecksumMismatch;
      self->OutCdClosePdi__8a06.HasMessage = 1;
      self->D50outPdiConnectionState.Value =
          SSciAdjPrim_D50outPdiConnectionStateValue__Impermissible;
      self->D50outPdiConnectionState.IsSignalled = true;
      make_state_SSciAdjPrim__root__Impermissible(self, x);
      return;
    }
  }
  if (self->InMsgPdiVersionCheck__9827.HasMessage) {
    if (self->InMsgPdiVersionCheck__9827.Value.Result ==
        MsgPdiVersionCheck__9827_ResultValue__NotMatch) {
      self->D60outPdiCloseReason.Value =
          SSciAdjPrim_D60outPdiCloseReasonValue__PdiOtherVersionRequired;
      self->D60outPdiCloseReason.IsSignalled = true;

      self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
          CloseReason__91bc__OtherVersionRequired;
      self->OutCdClosePdi__8a06.HasMessage = 1;
      self->D50outPdiConnectionState.Value =
          SSciAdjPrim_D50outPdiConnectionStateValue__Impermissible;
      self->D50outPdiConnectionState.IsSignalled = true;
      make_state_SSciAdjPrim__root__Impermissible(self, x);
      return;
    }
  }
}

void transition_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitialisation(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {

  if (self->InMsgStartInitialisation__43d2.HasMessage) {
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__ReceivingSecStatus;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciAdjPrim__root__Active__root__Establishing__root__ReceivingSecStatus(
        self, &x->Active.root.Establishing.root);
    return;
  }
}

void transition_from_SSciAdjPrim__root__Active__root__Establishing__root__ReceivingSecStatus(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {

  if (self->InMsgStatusReportCompleted__c465.HasMessage) {
    self->T27outCheckSecStatus.Trigger = true;
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__CheckingSecStatus;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciAdjPrim__root__Active__root__Establishing__root__CheckingSecStatus(
        self, &x->Active.root.Establishing.root);
    return;
  }
}

void transition_from_SSciAdjPrim__root__Active__root__Establishing__root__CheckingSecStatus(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {

  if (self->Change1019.IsTriggered) {

    self->OutStartPrimStatusReport__a91c.HasMessage = 1;
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__SendingPrimStatus;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciAdjPrim__root__Active__root__Establishing__root__SendingPrimStatus(
        self, &x->Active.root.Establishing.root);
    return;
  }
}

void transition_from_SSciAdjPrim__root__Active__root__Establishing__root__SendingPrimStatus(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {

  if (self->InPrimStatusReportCompleted__80d8.HasMessage) {

    self->OutMsgStatusReportCompleted__c465.HasMessage = 1;
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__WaitingForInitCompletion;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitCompletion(
        self, &x->Active.root.Establishing.root);
    return;
  }
}

void transition_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitCompletion(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {

  if (self->InMsgInitialisationCompleted__75d9.HasMessage) {
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__Established;
    self->D50outPdiConnectionState.IsSignalled = true;

    self->OutPdiConnectionEstablished__019d.HasMessage = 1;
    make_state_SSciAdjPrim__root__Active__root__Established(self,
                                                            &x->Active.root);
    return;
  }
}

void transition_from_SSciAdjPrim__root__Active__root__Establishing__root(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {
  switch (x->Active.root.Establishing.root.state) {
  case SSciAdjPrim__root__Active__root__Establishing__root__WaitingForVersionCheck:
    transition_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(
        self, x);
    break;
  case SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitialisation:
    transition_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitialisation(
        self, x);
    break;
  case SSciAdjPrim__root__Active__root__Establishing__root__ReceivingSecStatus:
    transition_from_SSciAdjPrim__root__Active__root__Establishing__root__ReceivingSecStatus(
        self, x);
    break;
  case SSciAdjPrim__root__Active__root__Establishing__root__CheckingSecStatus:
    transition_from_SSciAdjPrim__root__Active__root__Establishing__root__CheckingSecStatus(
        self, x);
    break;
  case SSciAdjPrim__root__Active__root__Establishing__root__SendingPrimStatus:
    transition_from_SSciAdjPrim__root__Active__root__Establishing__root__SendingPrimStatus(
        self, x);
    break;
  case SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitCompletion:
    transition_from_SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitCompletion(
        self, x);
    break;
  }
}

void transition_from_SSciAdjPrim__root__Active__root__Establishing(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {
  transition_from_SSciAdjPrim__root__Active__root__Establishing__root(self, x);
  if (self->Time23.IsTimeoutExpired) {

    self->OutPdiConnectionClosed__7975.HasMessage = 1;

    self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
        CloseReason__91bc__Timeout;
    self->OutCdClosePdi__8a06.HasMessage = 1;
    self->D60outPdiCloseReason.Value =
        SSciAdjPrim_D60outPdiCloseReasonValue__PdiTimeout;
    self->D60outPdiCloseReason.IsSignalled = true;
    make_state_SSciAdjPrim__root__Active__root__Establishing(self,
                                                             &x->Active.root);
    return;
  }
}

void transition_from_SSciAdjPrim__root__Active__root__Established(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {}

void transition_from_SSciAdjPrim__root__Active__root(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {
  switch (x->Active.root.state) {
  case SSciAdjPrim__root__Active__root__Establishing:
    transition_from_SSciAdjPrim__root__Active__root__Establishing(self, x);
    break;
  case SSciAdjPrim__root__Active__root__Established:
    transition_from_SSciAdjPrim__root__Active__root__Established(self, x);
    break;
  }
}

void transition_from_SSciAdjPrim__root__RequestedNoScp(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {

  if (self->Change1220.IsTriggered) {

    make_state_SSciAdjPrim__root__Active(self, x);
    return;
  }
}

void transition_from_SSciAdjPrim__root__ImpermissibleNoScp(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {

  if (self->Change1164.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__RequestedNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    self->T6outEstablishScpConnection.Trigger = true;
    make_state_SSciAdjPrim__root__RequestedNoScp(self, x);
    return;
  }
  if (self->Change1216.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__Impermissible;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciAdjPrim__root__Impermissible(self, x);
    return;
  }
}

void transition_from_SSciAdjPrim__root__Impermissible(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {

  if (self->Change738.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__ImpermissibleNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciAdjPrim__root__ImpermissibleNoScp(self, x);
    return;
  }
  if (self->Change1165.IsTriggered) {

    make_state_SSciAdjPrim__root__Active(self, x);
    return;
  }
}

void transition_from_SSciAdjPrim__root__Active(
    SSciAdjPrim *self, SSciAdjPrim__root__state_struct *x) {
  transition_from_SSciAdjPrim__root__Active__root(self, x);
  if (self->InMsgResetPdi__59f4.HasMessage) {
    if (self->InMsgResetPdi__59f4.Value.ReportedResetReason ==
        ResetReason__44e3__ProtocolError) {
      self->D60outPdiCloseReason.Value =
          SSciAdjPrim_D60outPdiCloseReasonValue__SecProtocolError;
      self->D60outPdiCloseReason.IsSignalled = true;
      self->D50outPdiConnectionState.Value =
          SSciAdjPrim_D50outPdiConnectionStateValue__Impermissible;
      self->D50outPdiConnectionState.IsSignalled = true;
      make_state_SSciAdjPrim__root__Impermissible(self, x);
      return;
    }
  }
  if (self->InMsgResetPdi__59f4.HasMessage) {
    if (self->InMsgResetPdi__59f4.Value.ReportedResetReason ==
        ResetReason__44e3__ContentTelegramError) {
      self->D60outPdiCloseReason.Value =
          SSciAdjPrim_D60outPdiCloseReasonValue__SecContentTelegramError;
      self->D60outPdiCloseReason.IsSignalled = true;
      self->D50outPdiConnectionState.Value =
          SSciAdjPrim_D50outPdiConnectionStateValue__Impermissible;
      self->D50outPdiConnectionState.IsSignalled = true;
      make_state_SSciAdjPrim__root__Impermissible(self, x);
      return;
    }
  }
  if (self->InMsgResetPdi__59f4.HasMessage) {
    if (self->InMsgResetPdi__59f4.Value.ReportedResetReason ==
        ResetReason__44e3__FormalTelegramError) {
      self->D60outPdiCloseReason.Value =
          SSciAdjPrim_D60outPdiCloseReasonValue__SecFormalTelegramError;
      self->D60outPdiCloseReason.IsSignalled = true;
      self->D50outPdiConnectionState.Value =
          SSciAdjPrim_D50outPdiConnectionStateValue__Impermissible;
      self->D50outPdiConnectionState.IsSignalled = true;
      make_state_SSciAdjPrim__root__Impermissible(self, x);
      return;
    }
  }
  if (self->Change741.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__RequestedNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    self->T6outEstablishScpConnection.Trigger = true;
    make_state_SSciAdjPrim__root__RequestedNoScp(self, x);
    return;
  }
  if (self->Change979.IsTriggered) {
    self->D60outPdiCloseReason.Value =
        SSciAdjPrim_D60outPdiCloseReasonValue__PrimProtocolError;
    self->D60outPdiCloseReason.IsSignalled = true;

    self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
        CloseReason__91bc__ProtocolError;
    self->OutCdClosePdi__8a06.HasMessage = 1;
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__Impermissible;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciAdjPrim__root__Impermissible(self, x);
    return;
  }
  if (self->Change986.IsTriggered) {
    self->D60outPdiCloseReason.Value =
        SSciAdjPrim_D60outPdiCloseReasonValue__PrimFormalTelegramError;
    self->D60outPdiCloseReason.IsSignalled = true;

    self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
        CloseReason__91bc__FormalTelegramError;
    self->OutCdClosePdi__8a06.HasMessage = 1;
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__Impermissible;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciAdjPrim__root__Impermissible(self, x);
    return;
  }
  if (self->Change1000.IsTriggered) {
    self->D60outPdiCloseReason.Value =
        SSciAdjPrim_D60outPdiCloseReasonValue__PrimContentTelegramError;
    self->D60outPdiCloseReason.IsSignalled = true;

    self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
        CloseReason__91bc__ContentTelegramError;
    self->OutCdClosePdi__8a06.HasMessage = 1;
    self->D50outPdiConnectionState.Value =
        SSciAdjPrim_D50outPdiConnectionStateValue__Impermissible;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciAdjPrim__root__Impermissible(self, x);
    return;
  }
}

void transition_from_SSciAdjPrim__root(SSciAdjPrim *self,
                                       SSciAdjPrim__root__state_struct *x) {
  switch (x->state) {
  case SSciAdjPrim__root__RequestedNoScp:
    transition_from_SSciAdjPrim__root__RequestedNoScp(self, x);
    break;
  case SSciAdjPrim__root__ImpermissibleNoScp:
    transition_from_SSciAdjPrim__root__ImpermissibleNoScp(self, x);
    break;
  case SSciAdjPrim__root__Impermissible:
    transition_from_SSciAdjPrim__root__Impermissible(self, x);
    break;
  case SSciAdjPrim__root__Active:
    transition_from_SSciAdjPrim__root__Active(self, x);
    break;
  }
}

static void evaluateChangeEvents(SSciAdjPrim *self) {
  self->Change1019.IsTriggered = self->T25inSecStatusReportComplete.IsTriggered;
  self->Change1220.IsTriggered = self->T5inScpConnectionEstablished.IsTriggered;
  self->Change1164.IsTriggered = self->T45inResetSevereError.IsTriggered;
  self->Change1216.IsTriggered = self->T5inScpConnectionEstablished.IsTriggered;
  self->Change738.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
  self->Change1165.IsTriggered = self->T45inResetSevereError.IsTriggered;
  self->Change741.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
  self->Change979.IsTriggered = self->T20inProtocolError.IsTriggered;
  self->Change986.IsTriggered = self->T21inFormalTelegramError.IsTriggered;
  self->Change1000.IsTriggered = self->T22inContentTelegramError.IsTriggered;
}

static void resetOutputs(SSciAdjPrim *self) {
  self->OutStartPrimStatusReport__a91c.HasMessage = false;
  self->OutMsgStatusReportCompleted__c465.HasMessage = false;
  self->OutPdiConnectionEstablished__019d.HasMessage = false;
  self->OutPdiConnectionClosed__7975.HasMessage = false;
  self->OutEstablishingPdiConnection__41d4.HasMessage = false;
  self->OutCdPdiVersionCheck__ffab.HasMessage = false;
  self->OutCdInitialisationRequest__8d96.HasMessage = false;
  self->OutCdClosePdi__8a06.HasMessage = false;

  self->T6outEstablishScpConnection.Trigger = false;
  self->T27outCheckSecStatus.Trigger = false;

  self->D50outPdiConnectionState.IsSignalled = false;
  self->D60outPdiCloseReason.IsSignalled = false;
}

static void resetTriggers(SSciAdjPrim *self) {
  self->InMsgPdiVersionCheck__9827.HasMessage = false;
  self->InMsgStartInitialisation__43d2.HasMessage = false;
  self->InMsgStatusReportCompleted__c465.HasMessage = false;
  self->InPrimStatusReportCompleted__80d8.HasMessage = false;
  self->InMsgInitialisationCompleted__75d9.HasMessage = false;
  self->InMsgResetPdi__59f4.HasMessage = false;

  self->T5inScpConnectionEstablished.IsTriggered = false;
  self->T10inScpConnectionTerminated.IsTriggered = false;
  self->T22inContentTelegramError.IsTriggered = false;
  self->T20inProtocolError.IsTriggered = false;
  self->T21inFormalTelegramError.IsTriggered = false;
  self->T45inResetSevereError.IsTriggered = false;
  self->T25inSecStatusReportComplete.IsTriggered = false;

  self->D4inConChecksumData.IsSignalled = false;
  self->D2inConTmaxPdiConnection.IsSignalled = false;
  self->D3inConPdiVersion.IsSignalled = false;

  self->Time23.IsTimeoutExpired = false;
}

void transition_SSciAdjPrim(SSciAdjPrim *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_SSciAdjPrim__root(self, &self->state);
  resetTriggers(self);
}

void new_SSciAdjPrim(SSciAdjPrim *self) {
  make_state_SSciAdjPrim__root(self, &self->state);
}
