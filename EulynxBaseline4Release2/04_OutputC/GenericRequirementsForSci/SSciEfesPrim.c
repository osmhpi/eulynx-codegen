
#include "SSciEfesPrim.h"

// Value Conversion Functions

static SSciEfesPrim_MemPdiVersionResultValue
map_Result_to_MemPdiVersionResult(MsgPdiVersionCheck__9827_ResultValue value) {
  switch (value) {
  case MsgPdiVersionCheck__9827_ResultValue__NULL__:
    return SSciEfesPrim_MemPdiVersionResultValue__NULL__;
  case MsgPdiVersionCheck__9827_ResultValue__UNKNOWN__:
    return SSciEfesPrim_MemPdiVersionResultValue__UNKNOWN__;
  case MsgPdiVersionCheck__9827_ResultValue__Match:
    return SSciEfesPrim_MemPdiVersionResultValue__Match;
  case MsgPdiVersionCheck__9827_ResultValue__NotMatch:
    return SSciEfesPrim_MemPdiVersionResultValue__NotMatch;
  case MsgPdiVersionCheck__9827_ResultValue__Unknown:
    return SSciEfesPrim_MemPdiVersionResultValue__Unknown;
  default:
    abort();
  }
}

// Operations
static void Cop1Init(SSciEfesPrim *self) {
  self->D60outPdiCloseReason.Value =
      SSciEfesPrim_D60outPdiCloseReasonValue__NoError;
  self->D60outPdiCloseReason.IsSignalled = true;
  self->MemPdiVersionResult = SSciEfesPrim_MemPdiVersionResultValue__Unknown;
  memcpy(self->MemChecksumData, self->D4inConChecksumData.Value,
         sizeof(self->MemChecksumData));
}

void make_state_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(
    SSciEfesPrim *self,
    SSciEfesPrim__root__Active__root__Establishing__root__state_struct
        *region) {
  LOG("[SSciEfesPrim] Entering state WaitingForVersionCheck in region "
      "root__Active__root__Establishing__root");
  region->state =
      SSciEfesPrim__root__Active__root__Establishing__root__WaitingForVersionCheck;
};

void make_state_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForInitialisation(
    SSciEfesPrim *self,
    SSciEfesPrim__root__Active__root__Establishing__root__state_struct
        *region) {
  LOG("[SSciEfesPrim] Entering state WaitingForInitialisation in region "
      "root__Active__root__Establishing__root");
  region->state =
      SSciEfesPrim__root__Active__root__Establishing__root__WaitingForInitialisation;
};

void make_state_SSciEfesPrim__root__Active__root__Establishing__root__ReceivingStatus(
    SSciEfesPrim *self,
    SSciEfesPrim__root__Active__root__Establishing__root__state_struct
        *region) {
  LOG("[SSciEfesPrim] Entering state ReceivingStatus in region "
      "root__Active__root__Establishing__root");
  region->state =
      SSciEfesPrim__root__Active__root__Establishing__root__ReceivingStatus;
};

void make_state_SSciEfesPrim__root__Active__root__Establishing__root__OtherVersionRequired(
    SSciEfesPrim *self,
    SSciEfesPrim__root__Active__root__Establishing__root__state_struct
        *region) {
  LOG("[SSciEfesPrim] Entering state OtherVersionRequired in region "
      "root__Active__root__Establishing__root");
  region->state =
      SSciEfesPrim__root__Active__root__Establishing__root__OtherVersionRequired;
};

void make_state_SSciEfesPrim__root__Active__root__Establishing__root(
    SSciEfesPrim *self,
    SSciEfesPrim__root__Active__root__Establishing__root__state_struct *x) {
  memset(
      x, 0,
      sizeof(
          SSciEfesPrim__root__Active__root__Establishing__root__state_struct));

  self->OutCdPdiVersionCheck__ffab.Value.PdiVersion =
      self->D3inConPdiVersion.Value;
  self->OutCdPdiVersionCheck__ffab.HasMessage = 1;
  self->D50outPdiConnectionState.Value =
      SSciEfesPrim_D50outPdiConnectionStateValue__WaitingForVersionCheck;
  self->D50outPdiConnectionState.IsSignalled = true;
  make_state_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(
      self, x);
  return;
}

void make_state_SSciEfesPrim__root__Active__root__Establishing(
    SSciEfesPrim *self,
    SSciEfesPrim__root__Active__root__state_struct *region) {
  LOG("[SSciEfesPrim] Entering state Establishing in region "
      "root__Active__root");
  region->state = SSciEfesPrim__root__Active__root__Establishing;
  make_state_SSciEfesPrim__root__Active__root__Establishing__root(
      self, &region->Establishing.root);
};

void make_state_SSciEfesPrim__root__Active__root__Established(
    SSciEfesPrim *self,
    SSciEfesPrim__root__Active__root__state_struct *region) {
  LOG("[SSciEfesPrim] Entering state Established in region root__Active__root");
  region->state = SSciEfesPrim__root__Active__root__Established;
};

void make_state_SSciEfesPrim__root__Active__root(
    SSciEfesPrim *self, SSciEfesPrim__root__Active__root__state_struct *x) {
  memset(x, 0, sizeof(SSciEfesPrim__root__Active__root__state_struct));

  make_state_SSciEfesPrim__root__Active__root__Establishing(self, x);
  return;
}

void make_state_SSciEfesPrim__root__RequestedNoScp(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *region) {
  LOG("[SSciEfesPrim] Entering state RequestedNoScp in region root");
  region->state = SSciEfesPrim__root__RequestedNoScp;
};

void make_state_SSciEfesPrim__root__ImpermissibleNoScp(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *region) {
  LOG("[SSciEfesPrim] Entering state ImpermissibleNoScp in region root");
  region->state = SSciEfesPrim__root__ImpermissibleNoScp;
};

void make_state_SSciEfesPrim__root__Impermissible(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *region) {
  LOG("[SSciEfesPrim] Entering state Impermissible in region root");
  region->state = SSciEfesPrim__root__Impermissible;
};

void make_state_SSciEfesPrim__root__Disconnected(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *region) {
  LOG("[SSciEfesPrim] Entering state Disconnected in region root");
  region->state = SSciEfesPrim__root__Disconnected;
};

void make_state_SSciEfesPrim__root__DisconnectedNoScp(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *region) {
  LOG("[SSciEfesPrim] Entering state DisconnectedNoScp in region root");
  region->state = SSciEfesPrim__root__DisconnectedNoScp;
};

void make_state_SSciEfesPrim__root__Active(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *region) {
  LOG("[SSciEfesPrim] Entering state Active in region root");
  region->state = SSciEfesPrim__root__Active;
  make_state_SSciEfesPrim__root__Active__root(self, &region->Active.root);
};

void make_state_SSciEfesPrim__root__Suspended(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *region) {
  LOG("[SSciEfesPrim] Entering state Suspended in region root");
  region->state = SSciEfesPrim__root__Suspended;
};

void make_state_SSciEfesPrim__root(SSciEfesPrim *self,
                                   SSciEfesPrim__root__state_struct *x) {
  memset(x, 0, sizeof(SSciEfesPrim__root__state_struct));
  Cop1Init(self);
  self->D50outPdiConnectionState.Value =
      SSciEfesPrim_D50outPdiConnectionStateValue__DisconnectedNoScp;
  self->D50outPdiConnectionState.IsSignalled = true;
  make_state_SSciEfesPrim__root__DisconnectedNoScp(self, x);
  return;
}

void transition_from_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {

  if (self->InMsgPdiVersionCheck__9827.HasMessage) {
    self->MemPdiVersionResult = map_Result_to_MemPdiVersionResult(
        self->InMsgPdiVersionCheck__9827.Value.Result);
    memcpy(self->MemChecksumData,
           self->InMsgPdiVersionCheck__9827.Value.ChecksumData,
           sizeof(self->MemChecksumData));
    if (self->MemPdiVersionResult ==
        SSciEfesPrim_MemPdiVersionResultValue__Match) {

      if (!(memcmp(self->MemChecksumData, self->D4inConChecksumData.Value,
                   sizeof(self->MemChecksumData)) == 0)) {

        self->OutCdReleasePdiForMaintenance__3e43.HasMessage = 1;
        self->D50outPdiConnectionState.Value =
            SSciEfesPrim_D50outPdiConnectionStateValue__Suspended;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciEfesPrim__root__Suspended(self, x);
        return;
      }
      if (memcmp(self->MemChecksumData, self->D4inConChecksumData.Value,
                 sizeof(self->MemChecksumData)) == 0) {

        self->OutCdInitialisationRequest__8d96.HasMessage = 1;
        self->D50outPdiConnectionState.Value =
            SSciEfesPrim_D50outPdiConnectionStateValue__WaitingForInitialisation;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForInitialisation(
            self, &x->Active.root.Establishing.root);
        return;
      }
    }
    if (self->MemPdiVersionResult ==
        SSciEfesPrim_MemPdiVersionResultValue__NotMatch) {

      if (self->D39inConLastPdiVersion.Value == false) {
        self->T46outConOtherPdiVersionRequest.Trigger = true;

        self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
            CloseReason__91bc__OtherVersionRequired;
        self->OutCdClosePdi__8a06.HasMessage = 1;
        self->D60outPdiCloseReason.Value =
            SSciEfesPrim_D60outPdiCloseReasonValue__PdiOtherVersionRequired;
        self->D60outPdiCloseReason.IsSignalled = true;
        self->D50outPdiConnectionState.Value =
            SSciEfesPrim_D50outPdiConnectionStateValue__OtherVersionRequired;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciEfesPrim__root__Active__root__Establishing__root__OtherVersionRequired(
            self, &x->Active.root.Establishing.root);
        return;
      }
      if (self->D39inConLastPdiVersion.Value == true) {

        self->OutCdReleasePdiForMaintenance__3e43.HasMessage = 1;
        self->D50outPdiConnectionState.Value =
            SSciEfesPrim_D50outPdiConnectionStateValue__Suspended;
        self->D50outPdiConnectionState.IsSignalled = true;
        make_state_SSciEfesPrim__root__Suspended(self, x);
        return;
      }
    }
  }
}

void transition_from_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForInitialisation(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {

  if (self->InMsgStartInitialisation__43d2.HasMessage) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__ReceivingStatus;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__Active__root__Establishing__root__ReceivingStatus(
        self, &x->Active.root.Establishing.root);
    return;
  }
}

void transition_from_SSciEfesPrim__root__Active__root__Establishing__root__ReceivingStatus(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {

  if (self->InMsgInitialisationCompleted__75d9.HasMessage) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__Established;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__Active__root__Established(self,
                                                             &x->Active.root);
    return;
  }
}

void transition_from_SSciEfesPrim__root__Active__root__Establishing__root__OtherVersionRequired(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {

  if (self->Change1175.IsTriggered) {

    make_state_SSciEfesPrim__root__Active__root__Establishing(self,
                                                              &x->Active.root);
    return;
  }
}

void transition_from_SSciEfesPrim__root__Active__root__Establishing__root(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {
  switch (x->Active.root.Establishing.root.state) {
  case SSciEfesPrim__root__Active__root__Establishing__root__WaitingForVersionCheck:
    transition_from_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForVersionCheck(
        self, x);
    break;
  case SSciEfesPrim__root__Active__root__Establishing__root__WaitingForInitialisation:
    transition_from_SSciEfesPrim__root__Active__root__Establishing__root__WaitingForInitialisation(
        self, x);
    break;
  case SSciEfesPrim__root__Active__root__Establishing__root__ReceivingStatus:
    transition_from_SSciEfesPrim__root__Active__root__Establishing__root__ReceivingStatus(
        self, x);
    break;
  case SSciEfesPrim__root__Active__root__Establishing__root__OtherVersionRequired:
    transition_from_SSciEfesPrim__root__Active__root__Establishing__root__OtherVersionRequired(
        self, x);
    break;
  }
}

void transition_from_SSciEfesPrim__root__Active__root__Establishing(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {
  transition_from_SSciEfesPrim__root__Active__root__Establishing__root(self, x);
  if (self->Time23.IsTimeoutExpired) {

    self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
        CloseReason__91bc__Timeout;
    self->OutCdClosePdi__8a06.HasMessage = 1;
    self->D60outPdiCloseReason.Value =
        SSciEfesPrim_D60outPdiCloseReasonValue__PdiTimeout;
    self->D60outPdiCloseReason.IsSignalled = true;
    make_state_SSciEfesPrim__root__Active__root__Establishing(self,
                                                              &x->Active.root);
    return;
  }
}

void transition_from_SSciEfesPrim__root__Active__root__Established(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {}

void transition_from_SSciEfesPrim__root__Active__root(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {
  switch (x->Active.root.state) {
  case SSciEfesPrim__root__Active__root__Establishing:
    transition_from_SSciEfesPrim__root__Active__root__Establishing(self, x);
    break;
  case SSciEfesPrim__root__Active__root__Established:
    transition_from_SSciEfesPrim__root__Active__root__Established(self, x);
    break;
  }
}

void transition_from_SSciEfesPrim__root__RequestedNoScp(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {

  if (self->Change1179.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__DisconnectedNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__DisconnectedNoScp(self, x);
    return;
  }
  if (self->Change1226.IsTriggered) {

    make_state_SSciEfesPrim__root__Active(self, x);
    return;
  }
}

void transition_from_SSciEfesPrim__root__ImpermissibleNoScp(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {

  if (self->Change1171.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__RequestedNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    self->T6outEstablishScpConnection.Trigger = true;
    make_state_SSciEfesPrim__root__RequestedNoScp(self, x);
    return;
  }
  if (self->Change1224.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__Impermissible;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__Impermissible(self, x);
    return;
  }
}

void transition_from_SSciEfesPrim__root__Impermissible(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {

  if (self->Change751.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__ImpermissibleNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__ImpermissibleNoScp(self, x);
    return;
  }
  if (self->Change1172.IsTriggered) {

    make_state_SSciEfesPrim__root__Active(self, x);
    return;
  }
}

void transition_from_SSciEfesPrim__root__Disconnected(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {

  if (self->Change743.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__DisconnectedNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__DisconnectedNoScp(self, x);
    return;
  }
  if (self->Change1181.IsTriggered) {

    make_state_SSciEfesPrim__root__Active(self, x);
    return;
  }
}

void transition_from_SSciEfesPrim__root__DisconnectedNoScp(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {

  if (self->Change1180.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__RequestedNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    self->T6outEstablishScpConnection.Trigger = true;
    make_state_SSciEfesPrim__root__RequestedNoScp(self, x);
    return;
  }
  if (self->Change1230.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__Disconnected;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__Disconnected(self, x);
    return;
  }
}

void transition_from_SSciEfesPrim__root__Active(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {
  transition_from_SSciEfesPrim__root__Active__root(self, x);
  if (self->InMsgPdiNotAvailable__b83e.HasMessage) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__Suspended;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__Suspended(self, x);
    return;
  }
  if (self->InMsgResetPdi__59f4.HasMessage) {
    if (self->InMsgResetPdi__59f4.Value.ReportedResetReason ==
        ResetReason__44e3__ProtocolError) {
      self->D60outPdiCloseReason.Value =
          SSciEfesPrim_D60outPdiCloseReasonValue__EfesProtocolError;
      self->D60outPdiCloseReason.IsSignalled = true;
      self->D50outPdiConnectionState.Value =
          SSciEfesPrim_D50outPdiConnectionStateValue__Impermissible;
      self->D50outPdiConnectionState.IsSignalled = true;
      make_state_SSciEfesPrim__root__Impermissible(self, x);
      return;
    }
  }
  if (self->InMsgResetPdi__59f4.HasMessage) {
    if (self->InMsgResetPdi__59f4.Value.ReportedResetReason ==
        ResetReason__44e3__ContentTelegramError) {
      self->D60outPdiCloseReason.Value =
          SSciEfesPrim_D60outPdiCloseReasonValue__EfesContentTelegramError;
      self->D60outPdiCloseReason.IsSignalled = true;
      self->D50outPdiConnectionState.Value =
          SSciEfesPrim_D50outPdiConnectionStateValue__Impermissible;
      self->D50outPdiConnectionState.IsSignalled = true;
      make_state_SSciEfesPrim__root__Impermissible(self, x);
      return;
    }
  }
  if (self->InMsgResetPdi__59f4.HasMessage) {
    if (self->InMsgResetPdi__59f4.Value.ReportedResetReason ==
        ResetReason__44e3__FormalTelegramError) {
      self->D60outPdiCloseReason.Value =
          SSciEfesPrim_D60outPdiCloseReasonValue__EfesFormalTelegramError;
      self->D60outPdiCloseReason.IsSignalled = true;
      self->D50outPdiConnectionState.Value =
          SSciEfesPrim_D50outPdiConnectionStateValue__Impermissible;
      self->D50outPdiConnectionState.IsSignalled = true;
      make_state_SSciEfesPrim__root__Impermissible(self, x);
      return;
    }
  }
  if (self->Change754.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__RequestedNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    self->T6outEstablishScpConnection.Trigger = true;
    make_state_SSciEfesPrim__root__RequestedNoScp(self, x);
    return;
  }
  if (self->Change984.IsTriggered) {
    self->D60outPdiCloseReason.Value =
        SSciEfesPrim_D60outPdiCloseReasonValue__EilProtocolError;
    self->D60outPdiCloseReason.IsSignalled = true;

    self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
        CloseReason__91bc__ProtocolError;
    self->OutCdClosePdi__8a06.HasMessage = 1;
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__Impermissible;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__Impermissible(self, x);
    return;
  }
  if (self->Change993.IsTriggered) {
    self->D60outPdiCloseReason.Value =
        SSciEfesPrim_D60outPdiCloseReasonValue__EilFormalTelegramError;
    self->D60outPdiCloseReason.IsSignalled = true;

    self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
        CloseReason__91bc__FormalTelegramError;
    self->OutCdClosePdi__8a06.HasMessage = 1;
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__Impermissible;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__Impermissible(self, x);
    return;
  }
  if (self->Change1006.IsTriggered) {
    self->D60outPdiCloseReason.Value =
        SSciEfesPrim_D60outPdiCloseReasonValue__EilContentTelegramError;
    self->D60outPdiCloseReason.IsSignalled = true;

    self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
        CloseReason__91bc__ContentTelegramError;
    self->OutCdClosePdi__8a06.HasMessage = 1;
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__Impermissible;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__Impermissible(self, x);
    return;
  }
  if (self->Change1162.IsTriggered) {

    self->OutCdReleasePdiForMaintenance__3e43.HasMessage = 1;
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__Suspended;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__Suspended(self, x);
    return;
  }
  if (self->Change1178.IsTriggered) {

    self->OutCdClosePdi__8a06.Value.RequestedCloseReason =
        CloseReason__91bc__NormalClose;
    self->OutCdClosePdi__8a06.HasMessage = 1;
    self->D60outPdiCloseReason.Value =
        SSciEfesPrim_D60outPdiCloseReasonValue__PdiNormalClose;
    self->D60outPdiCloseReason.IsSignalled = true;
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__Disconnected;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__Disconnected(self, x);
    return;
  }
}

void transition_from_SSciEfesPrim__root__Suspended(
    SSciEfesPrim *self, SSciEfesPrim__root__state_struct *x) {

  if (self->InMsgPdiAvailable__af0a.HasMessage) {

    make_state_SSciEfesPrim__root__Active(self, x);
    return;
  }
  if (self->Change752.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__RequestedNoScp;
    self->D50outPdiConnectionState.IsSignalled = true;
    self->T6outEstablishScpConnection.Trigger = true;
    make_state_SSciEfesPrim__root__RequestedNoScp(self, x);
    return;
  }
  if (self->Change1177.IsTriggered) {
    self->D50outPdiConnectionState.Value =
        SSciEfesPrim_D50outPdiConnectionStateValue__Disconnected;
    self->D50outPdiConnectionState.IsSignalled = true;
    make_state_SSciEfesPrim__root__Disconnected(self, x);
    return;
  }
}

void transition_from_SSciEfesPrim__root(SSciEfesPrim *self,
                                        SSciEfesPrim__root__state_struct *x) {
  switch (x->state) {
  case SSciEfesPrim__root__RequestedNoScp:
    transition_from_SSciEfesPrim__root__RequestedNoScp(self, x);
    break;
  case SSciEfesPrim__root__ImpermissibleNoScp:
    transition_from_SSciEfesPrim__root__ImpermissibleNoScp(self, x);
    break;
  case SSciEfesPrim__root__Impermissible:
    transition_from_SSciEfesPrim__root__Impermissible(self, x);
    break;
  case SSciEfesPrim__root__Disconnected:
    transition_from_SSciEfesPrim__root__Disconnected(self, x);
    break;
  case SSciEfesPrim__root__DisconnectedNoScp:
    transition_from_SSciEfesPrim__root__DisconnectedNoScp(self, x);
    break;
  case SSciEfesPrim__root__Active:
    transition_from_SSciEfesPrim__root__Active(self, x);
    break;
  case SSciEfesPrim__root__Suspended:
    transition_from_SSciEfesPrim__root__Suspended(self, x);
    break;
  }
}

static void evaluateChangeEvents(SSciEfesPrim *self) {
  self->Change1175.IsTriggered =
      self->T47inConOtherPdiVersionAvailable.IsTriggered;
  self->Change1179.IsTriggered =
      self->T48inDisableOrDisconnectPdiEfes.IsTriggered;
  self->Change1226.IsTriggered = self->T5inScpConnectionEstablished.IsTriggered;
  self->Change1171.IsTriggered = self->T45inResetSevereError.IsTriggered;
  self->Change1224.IsTriggered = self->T5inScpConnectionEstablished.IsTriggered;
  self->Change751.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
  self->Change1172.IsTriggered = self->T45inResetSevereError.IsTriggered;
  self->Change743.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
  self->Change1181.IsTriggered = self->T49inEnableOrConnectPdiEfes.IsTriggered;
  self->Change1180.IsTriggered = self->T49inEnableOrConnectPdiEfes.IsTriggered;
  self->Change1230.IsTriggered = self->T5inScpConnectionEstablished.IsTriggered;
  self->Change754.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
  self->Change984.IsTriggered = self->T20inProtocolError.IsTriggered;
  self->Change993.IsTriggered = self->T21inFormalTelegramError.IsTriggered;
  self->Change1006.IsTriggered = self->T22inContentTelegramError.IsTriggered;
  self->Change1162.IsTriggered = self->T44inInitiateMaintenance.IsTriggered;
  self->Change1178.IsTriggered =
      self->T48inDisableOrDisconnectPdiEfes.IsTriggered;
  self->Change752.IsTriggered = self->T10inScpConnectionTerminated.IsTriggered;
  self->Change1177.IsTriggered =
      self->T48inDisableOrDisconnectPdiEfes.IsTriggered;
}

static void resetOutputs(SSciEfesPrim *self) {
  self->OutCdPdiVersionCheck__ffab.HasMessage = false;
  self->OutCdReleasePdiForMaintenance__3e43.HasMessage = false;
  self->OutCdInitialisationRequest__8d96.HasMessage = false;
  self->OutCdClosePdi__8a06.HasMessage = false;

  self->T12outTerminateScpConnection.Trigger = false;
  self->T6outEstablishScpConnection.Trigger = false;
  self->T46outConOtherPdiVersionRequest.Trigger = false;

  self->D50outPdiConnectionState.IsSignalled = false;
  self->D60outPdiCloseReason.IsSignalled = false;
}

static void resetTriggers(SSciEfesPrim *self) {
  self->InMsgPdiVersionCheck__9827.HasMessage = false;
  self->InMsgStartInitialisation__43d2.HasMessage = false;
  self->InMsgInitialisationCompleted__75d9.HasMessage = false;
  self->InMsgPdiNotAvailable__b83e.HasMessage = false;
  self->InMsgResetPdi__59f4.HasMessage = false;
  self->InMsgPdiAvailable__af0a.HasMessage = false;

  self->T20inProtocolError.IsTriggered = false;
  self->T21inFormalTelegramError.IsTriggered = false;
  self->T22inContentTelegramError.IsTriggered = false;
  self->T5inScpConnectionEstablished.IsTriggered = false;
  self->T10inScpConnectionTerminated.IsTriggered = false;
  self->T48inDisableOrDisconnectPdiEfes.IsTriggered = false;
  self->T49inEnableOrConnectPdiEfes.IsTriggered = false;
  self->T45inResetSevereError.IsTriggered = false;
  self->T47inConOtherPdiVersionAvailable.IsTriggered = false;
  self->T44inInitiateMaintenance.IsTriggered = false;

  self->D3inConPdiVersion.IsSignalled = false;
  self->D4inConChecksumData.IsSignalled = false;
  self->D2inConTmaxPdiConnection.IsSignalled = false;
  self->D39inConLastPdiVersion.IsSignalled = false;

  self->Time23.IsTimeoutExpired = false;
}

void transition_SSciEfesPrim(SSciEfesPrim *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_SSciEfesPrim__root(self, &self->state);
  resetTriggers(self);
}

void new_SSciEfesPrim(SSciEfesPrim *self) {
  make_state_SSciEfesPrim__root(self, &self->state);
}
