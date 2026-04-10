
#include "SSciTdsReceiveTvps.h"

// Value Conversion Functions

// Operations
static void Cop2GetOccupancyStatusInformation(
    SSciTdsReceiveTvps *self, OccupancyStatus__65fa ParameterOccupancyStatus,
    AbilityToBeForcedToClear__8b12 ParameterAbilityToBeForcedToClear,
    DisturbanceStatus__fd65 ParameterDisturbanceStatus,
    ChangeTrigger__de2d ParameterChangeTrigger) {
  if (ParameterOccupancyStatus == OccupancyStatus__65fa__Vacant) {
    self->D75outOccupancyStatus.Value =
        SSciTdsReceiveTvps_D75outOccupancyStatusValue__Vacant;
    self->D75outOccupancyStatus.IsSignalled = true;
  } else if (ParameterOccupancyStatus == OccupancyStatus__65fa__Occupied) {
    self->D75outOccupancyStatus.Value =
        SSciTdsReceiveTvps_D75outOccupancyStatusValue__Occupied;
    self->D75outOccupancyStatus.IsSignalled = true;
  } else if (ParameterOccupancyStatus == OccupancyStatus__65fa__Disturbed) {
    self->D75outOccupancyStatus.Value =
        SSciTdsReceiveTvps_D75outOccupancyStatusValue__Disturbed;
    self->D75outOccupancyStatus.IsSignalled = true;
  } else if (ParameterOccupancyStatus ==
             OccupancyStatus__65fa__WaitingForASweepingTrain) {
    self->D75outOccupancyStatus.Value =
        SSciTdsReceiveTvps_D75outOccupancyStatusValue__WaitingForSweepingTrain;
    self->D75outOccupancyStatus.IsSignalled = true;
  } else if (ParameterOccupancyStatus ==
             OccupancyStatus__65fa__SweepingTrainDetected) {
    self->D75outOccupancyStatus.Value =
        SSciTdsReceiveTvps_D75outOccupancyStatusValue__SweepingTrainDetected;
    self->D75outOccupancyStatus.IsSignalled = true;
  } else if (ParameterOccupancyStatus ==
             OccupancyStatus__65fa__WaitingForAnAcknowledgment) {
    self->D75outOccupancyStatus.Value =
        SSciTdsReceiveTvps_D75outOccupancyStatusValue__WaitingForAcknowledgement;
    self->D75outOccupancyStatus.IsSignalled = true;
  }
  if (ParameterAbilityToBeForcedToClear ==
      AbilityToBeForcedToClear__8b12__Able) {
    self->D75outAbilityToBeForcedToClear.Value = true;
  } else if (ParameterAbilityToBeForcedToClear ==
             AbilityToBeForcedToClear__8b12__NotAble) {
    self->D75outAbilityToBeForcedToClear.Value = false;
  }
  if (ParameterChangeTrigger == ChangeTrigger__de2d__CommandFromEIL) {
    self->D75outChangeTrigger.Value =
        SSciTdsReceiveTvps_D75outChangeTriggerValue__CommandFromEil;
    self->D75outChangeTrigger.IsSignalled = true;
  } else if (ParameterChangeTrigger == ChangeTrigger__de2d__PassingDetected) {
    self->D75outChangeTrigger.Value =
        SSciTdsReceiveTvps_D75outChangeTriggerValue__PassingDetected;
    self->D75outChangeTrigger.IsSignalled = true;
  } else if (ParameterChangeTrigger ==
             ChangeTrigger__de2d__CommandFromMaintainer) {
    self->D75outChangeTrigger.Value =
        SSciTdsReceiveTvps_D75outChangeTriggerValue__CommandFromMaintainer;
    self->D75outChangeTrigger.IsSignalled = true;
  } else if (ParameterChangeTrigger == ChangeTrigger__de2d__TechnicalFailure) {
    self->D75outChangeTrigger.Value =
        SSciTdsReceiveTvps_D75outChangeTriggerValue__TechnicalFailure;
    self->D75outChangeTrigger.IsSignalled = true;
  } else if (ParameterChangeTrigger ==
             ChangeTrigger__de2d__InitialSectionState) {
    self->D75outChangeTrigger.Value =
        SSciTdsReceiveTvps_D75outChangeTriggerValue__InitialSectionState;
    self->D75outChangeTrigger.IsSignalled = true;
  } else if (ParameterChangeTrigger == ChangeTrigger__de2d__InternalTrigger) {
    self->D75outChangeTrigger.Value =
        SSciTdsReceiveTvps_D75outChangeTriggerValue__InternalTrigger;
    self->D75outChangeTrigger.IsSignalled = true;
  }
  if (ParameterDisturbanceStatus == DisturbanceStatus__fd65__Operational) {
    self->D75outReasonForFailure.Value =
        SSciTdsReceiveTvps_D75outReasonForFailureValue__Operational;
    self->D75outReasonForFailure.IsSignalled = true;
  } else if (ParameterDisturbanceStatus == DisturbanceStatus__fd65__Technical) {
    self->D75outReasonForFailure.Value =
        SSciTdsReceiveTvps_D75outReasonForFailureValue__Technical;
    self->D75outReasonForFailure.IsSignalled = true;
  } else if (ParameterDisturbanceStatus ==
             DisturbanceStatus__fd65__NotApplicable) {
    self->D75outReasonForFailure.Value =
        SSciTdsReceiveTvps_D75outReasonForFailureValue__NotApplicable;
    self->D75outReasonForFailure.IsSignalled = true;
  }
}
static void
Cop3GetReasonForFailureFcP(SSciTdsReceiveTvps *self,
                           ReasonForFailure__b02d ParameterReasonForFailure) {
  if (ParameterReasonForFailure == ReasonForFailure__b02d__IncorrectCount) {
    self->D82outFcPFailed.Value =
        SSciTdsReceiveTvps_D82outFcPFailedValue__IncorrectCount;
    self->D82outFcPFailed.IsSignalled = true;
  } else if (ParameterReasonForFailure == ReasonForFailure__b02d__TimeoutTMax) {
    self->D82outFcPFailed.Value =
        SSciTdsReceiveTvps_D82outFcPFailedValue__TimeoutTMax;
    self->D82outFcPFailed.IsSignalled = true;
  } else if (ParameterReasonForFailure ==
             ReasonForFailure__b02d__NotPermittedPassing) {
    self->D82outFcPFailed.Value =
        SSciTdsReceiveTvps_D82outFcPFailedValue__NotPermittedPassing;
    self->D82outFcPFailed.IsSignalled = true;
  } else if (ParameterReasonForFailure ==
             ReasonForFailure__b02d__OutgoingwheelbeforeTMin) {
    self->D82outFcPFailed.Value =
        SSciTdsReceiveTvps_D82outFcPFailedValue__OutgoingWheelBeforeTMin;
    self->D82outFcPFailed.IsSignalled = true;
  } else if (ParameterReasonForFailure ==
             ReasonForFailure__b02d__ProcessCanceled) {
    self->D82outFcPFailed.Value =
        SSciTdsReceiveTvps_D82outFcPFailedValue__ProcessCanceled;
    self->D82outFcPFailed.IsSignalled = true;
  }
}
static void
Cop4GetReasonForFailureFcPA(SSciTdsReceiveTvps *self,
                            ReasonForFailure__b02d ParameterReasonForFailure) {
  if (ParameterReasonForFailure == ReasonForFailure__b02d__IncorrectCount) {
    self->D83outFcPAFailed.Value =
        SSciTdsReceiveTvps_D83outFcPAFailedValue__IncorrectCount;
    self->D83outFcPAFailed.IsSignalled = true;
  } else if (ParameterReasonForFailure == ReasonForFailure__b02d__TimeoutTMax) {
    self->D83outFcPAFailed.Value =
        SSciTdsReceiveTvps_D83outFcPAFailedValue__TimeoutTMax;
    self->D83outFcPAFailed.IsSignalled = true;
  } else if (ParameterReasonForFailure ==
             ReasonForFailure__b02d__NotPermittedPassing) {
    self->D83outFcPAFailed.Value =
        SSciTdsReceiveTvps_D83outFcPAFailedValue__NotPermittedPassing;
    self->D83outFcPAFailed.IsSignalled = true;
  } else if (ParameterReasonForFailure ==
             ReasonForFailure__b02d__OutgoingwheelbeforeTMin) {
    self->D83outFcPAFailed.Value =
        SSciTdsReceiveTvps_D83outFcPAFailedValue__OutgoingWheelBeforeTMin;
    self->D83outFcPAFailed.IsSignalled = true;
  } else if (ParameterReasonForFailure ==
             ReasonForFailure__b02d__ProcessCanceled) {
    self->D83outFcPAFailed.Value =
        SSciTdsReceiveTvps_D83outFcPAFailedValue__ProcessCanceled;
    self->D83outFcPAFailed.IsSignalled = true;
  }
}

void make_state_SSciTdsReceiveTvps__root__ReceivingTvpsReports(
    SSciTdsReceiveTvps *self, SSciTdsReceiveTvps__root__state_struct *region) {
  LOG("[SSciTdsReceiveTvps] Entering state ReceivingTvpsReports in region "
      "root");
  region->state = SSciTdsReceiveTvps__root__ReceivingTvpsReports;
};

void make_state_SSciTdsReceiveTvps__root(
    SSciTdsReceiveTvps *self, SSciTdsReceiveTvps__root__state_struct *x) {
  memset(x, 0, sizeof(SSciTdsReceiveTvps__root__state_struct));

  make_state_SSciTdsReceiveTvps__root__ReceivingTvpsReports(self, x);
  return;
}

void transition_from_SSciTdsReceiveTvps__root__ReceivingTvpsReports(
    SSciTdsReceiveTvps *self, SSciTdsReceiveTvps__root__state_struct *x) {

  if (self->InMsgCommandRejected__8d0b.HasMessage) {
    if (self->InMsgCommandRejected__8d0b.Value.ReportedReasonForRejection ==
        ReasonForRejection__abec__Operational) {
      self->D84outCommandRejected.Value =
          SSciTdsReceiveTvps_D84outCommandRejectedValue__Operational;
      self->D84outCommandRejected.IsSignalled = true;
      self->T84outCommandRejected.Trigger = true;
      make_state_SSciTdsReceiveTvps__root__ReceivingTvpsReports(self, x);
      return;
    }
  }
  if (self->InMsgCommandRejected__8d0b.HasMessage) {
    if (self->InMsgCommandRejected__8d0b.Value.ReportedReasonForRejection ==
        ReasonForRejection__abec__Technical) {
      self->D84outCommandRejected.Value =
          SSciTdsReceiveTvps_D84outCommandRejectedValue__Technical;
      self->D84outCommandRejected.IsSignalled = true;
      self->T84outCommandRejected.Trigger = true;
      make_state_SSciTdsReceiveTvps__root__ReceivingTvpsReports(self, x);
      return;
    }
  }
  if (self->InMsgTvpsFcPAFailed__3c61.HasMessage) {
    Cop4GetReasonForFailureFcPA(
        self, self->InMsgTvpsFcPAFailed__3c61.Value.ReportedReasonForFailure);
    self->T83outFcPAFailed.Trigger = true;
    make_state_SSciTdsReceiveTvps__root__ReceivingTvpsReports(self, x);
    return;
  }
  if (self->InMsgTvpsFcPFailed__811b.HasMessage) {
    Cop3GetReasonForFailureFcP(
        self, self->InMsgTvpsFcPFailed__811b.Value.ReportedReasonForFailure);
    self->T82outFcPFailed.Trigger = true;
    make_state_SSciTdsReceiveTvps__root__ReceivingTvpsReports(self, x);
    return;
  }
  if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage) {
    Cop2GetOccupancyStatusInformation(
        self,
        self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus,
        self->InMsgTvpsOccupancyStatus__b4e1.Value
            .ReportedAbilityToBeForcedToClear,
        self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus,
        self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger);
    self->D75outFillinglevel.Value =
        self->InMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel;
    self->T75outTvpsOccupancyStatus.Trigger = true;
    make_state_SSciTdsReceiveTvps__root__ReceivingTvpsReports(self, x);
    return;
  }
}

void transition_from_SSciTdsReceiveTvps__root(
    SSciTdsReceiveTvps *self, SSciTdsReceiveTvps__root__state_struct *x) {
  switch (x->state) {
  case SSciTdsReceiveTvps__root__ReceivingTvpsReports:
    transition_from_SSciTdsReceiveTvps__root__ReceivingTvpsReports(self, x);
    break;
  }
}

static void evaluateChangeEvents(SSciTdsReceiveTvps *self) {}

static void resetOutputs(SSciTdsReceiveTvps *self) {

  self->T75outTvpsOccupancyStatus.Trigger = false;
  self->T84outCommandRejected.Trigger = false;
  self->T82outFcPFailed.Trigger = false;
  self->T83outFcPAFailed.Trigger = false;

  self->D75outOccupancyStatus.IsSignalled = false;
  self->D75outAbilityToBeForcedToClear.IsSignalled = false;
  self->D75outFillinglevel.IsSignalled = false;
  self->D75outReasonForFailure.IsSignalled = false;
  self->D75outChangeTrigger.IsSignalled = false;
  self->D82outFcPFailed.IsSignalled = false;
  self->D83outFcPAFailed.IsSignalled = false;
  self->D84outCommandRejected.IsSignalled = false;
}

static void resetTriggers(SSciTdsReceiveTvps *self) {
  self->InMsgCommandRejected__8d0b.HasMessage = false;
  self->InMsgTvpsFcPAFailed__3c61.HasMessage = false;
  self->InMsgTvpsFcPFailed__811b.HasMessage = false;
  self->InMsgTvpsOccupancyStatus__b4e1.HasMessage = false;
}

void transition_SSciTdsReceiveTvps(SSciTdsReceiveTvps *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_SSciTdsReceiveTvps__root(self, &self->state);
  resetTriggers(self);
}

void new_SSciTdsReceiveTvps(SSciTdsReceiveTvps *self) {
  make_state_SSciTdsReceiveTvps__root(self, &self->state);
}
