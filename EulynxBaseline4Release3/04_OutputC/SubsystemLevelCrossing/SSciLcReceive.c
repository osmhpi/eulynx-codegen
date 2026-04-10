
#include "SSciLcReceive.h"

// Value Conversion Functions

// Operations
static void Cop2GetMonitoringStatus(
    SSciLcReceive *self,
    ChangendMonitoringStatus__6c2c ParameterChangedMonitoringParameters,
    TimeOverrunState__b8ce ParameterTimeOverrun) {
  if (ParameterChangedMonitoringParameters ==
      ChangendMonitoringStatus__6c2c__MonitoringParameterSet1) {
    self->D62outMsgLcMonitoringStatusChangedMonitoringParameter.Value =
        SSciLcReceive_D62outMsgLcMonitoringStatusChangedMonitoringParameterValue__MonitoringParameterSet1;
    self->D62outMsgLcMonitoringStatusChangedMonitoringParameter.IsSignalled =
        true;
  } else if (ParameterChangedMonitoringParameters ==
             ChangendMonitoringStatus__6c2c__MonitoringParameterSet2) {
    self->D62outMsgLcMonitoringStatusChangedMonitoringParameter.Value =
        SSciLcReceive_D62outMsgLcMonitoringStatusChangedMonitoringParameterValue__MonitoringParameterSet2;
    self->D62outMsgLcMonitoringStatusChangedMonitoringParameter.IsSignalled =
        true;
  }
  if (ParameterTimeOverrun ==
      TimeOverrunState__b8ce__ClosureTimeOverrunOccured) {
    self->D61outMsgLcMonitoringStatusClosureTime.Value =
        SSciLcReceive_D61outMsgLcMonitoringStatusClosureTimeValue__ClosureTimeOverrunOccurred;
    self->D61outMsgLcMonitoringStatusClosureTime.IsSignalled = true;
  } else if (ParameterTimeOverrun ==
             TimeOverrunState__b8ce__NoClosureTimeOverrun) {
    self->D61outMsgLcMonitoringStatusClosureTime.Value =
        SSciLcReceive_D61outMsgLcMonitoringStatusClosureTimeValue__NoClosureTimeOverrun;
    self->D61outMsgLcMonitoringStatusClosureTime.IsSignalled = true;
  }
}
static void Cop3GetFailureState(
    SSciLcReceive *self,
    NonCriticalFailureStatusState__b376 ParameterNonCriticalFailure,
    CriticalFailureStatusState__f095 ParameterCriticalFailure) {
  if (ParameterCriticalFailure ==
      CriticalFailureStatusState__f095__ACriticalFailureIsPresent) {
    self->D72outMsgLcFailureStatusCritical.Value =
        SSciLcReceive_D72outMsgLcFailureStatusCriticalValue__ACriticalFailureIsPresent;
    self->D72outMsgLcFailureStatusCritical.IsSignalled = true;
  } else if (ParameterCriticalFailure ==
             CriticalFailureStatusState__f095__NoCriticalFailureIsPresent) {
    self->D72outMsgLcFailureStatusCritical.Value =
        SSciLcReceive_D72outMsgLcFailureStatusCriticalValue__NoCriticalFailureIsPresent;
    self->D72outMsgLcFailureStatusCritical.IsSignalled = true;
  }
  if (ParameterNonCriticalFailure ==
      NonCriticalFailureStatusState__b376__ANonCriticalFailureIsPresent) {
    self->D71outMsgLcFailureStatusNonCritical.Value =
        SSciLcReceive_D71outMsgLcFailureStatusNonCriticalValue__ANonCriticalFailureIsPresent;
    self->D71outMsgLcFailureStatusNonCritical.IsSignalled = true;
  } else if (
      ParameterNonCriticalFailure ==
      NonCriticalFailureStatusState__b376__NoNonCriticalFailureIsPresent) {
    self->D71outMsgLcFailureStatusNonCritical.Value =
        SSciLcReceive_D71outMsgLcFailureStatusNonCriticalValue__NoNonCriticalFailureIsPresent;
    self->D71outMsgLcFailureStatusNonCritical.IsSignalled = true;
  }
}

void make_state_SSciLcReceive__root__ReceivingLcReports(
    SSciLcReceive *self, SSciLcReceive__root__state_struct *region) {
  LOG("[SSciLcReceive] Entering state ReceivingLcReports in region root");
  region->state = SSciLcReceive__root__ReceivingLcReports;
};

void make_state_SSciLcReceive__root(SSciLcReceive *self,
                                    SSciLcReceive__root__state_struct *x) {
  memset(x, 0, sizeof(SSciLcReceive__root__state_struct));

  make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
  return;
}

void transition_from_SSciLcReceive__root__ReceivingLcReports(
    SSciLcReceive *self, SSciLcReceive__root__state_struct *x) {

  if (self->InMsgDetectionElementStatus__aa8b.HasMessage) {
    if (self->InMsgDetectionElementStatus__aa8b.Value
            .ReportedDetectionElementStatusState ==
        DetectionElementStatusState__4b10__DetectionElementIsFailed) {
      self->D18outMsgDetectionElementStatus.Value =
          SSciLcReceive_D18outMsgDetectionElementStatusValue__Failed;
      self->D18outMsgDetectionElementStatus.IsSignalled = true;
      self->T18outMsgDetectionElementStatus.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgDetectionElementStatus__aa8b.HasMessage) {
    if (self->InMsgDetectionElementStatus__aa8b.Value
            .ReportedDetectionElementStatusState ==
        DetectionElementStatusState__4b10__DetectionElementIsOccupied) {
      self->D18outMsgDetectionElementStatus.Value =
          SSciLcReceive_D18outMsgDetectionElementStatusValue__Occupied;
      self->D18outMsgDetectionElementStatus.IsSignalled = true;
      self->T18outMsgDetectionElementStatus.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgDetectionElementStatus__aa8b.HasMessage) {
    if (self->InMsgDetectionElementStatus__aa8b.Value
            .ReportedDetectionElementStatusState ==
        DetectionElementStatusState__4b10__DetectionElementIsVacant) {
      self->D18outMsgDetectionElementStatus.Value =
          SSciLcReceive_D18outMsgDetectionElementStatusValue__Vacant;
      self->D18outMsgDetectionElementStatus.IsSignalled = true;
      self->T18outMsgDetectionElementStatus.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgLcFailureStatus__5440.HasMessage) {
    Cop3GetFailureState(
        self,
        self->InMsgLcFailureStatus__5440.Value.ReportedNonCriticalFailureState,
        self->InMsgLcFailureStatus__5440.Value.ReportedCriticalFailureState);
    self->T7outMsgLcFailureStatus.Trigger = true;
    make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
    return;
  }
  if (self->InMsgLcFunctionalStatus__ab8c.HasMessage) {
    if (self->InMsgLcFunctionalStatus__ab8c.Value
            .ReportedActivationlStatusState ==
        FunctionalStatusState__5d12__IsolatedLC) {
      self->D5outMsgLcFunctionalStatus.Value =
          SSciLcReceive_D5outMsgLcFunctionalStatusValue__IsolatedLc;
      self->D5outMsgLcFunctionalStatus.IsSignalled = true;
      self->T5outMsgLcFunctionalStatus.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgLcFunctionalStatus__ab8c.HasMessage) {
    if (self->InMsgLcFunctionalStatus__ab8c.Value
            .ReportedActivationlStatusState ==
        FunctionalStatusState__5d12__PreActivated) {
      self->D5outMsgLcFunctionalStatus.Value =
          SSciLcReceive_D5outMsgLcFunctionalStatusValue__PreActivated;
      self->D5outMsgLcFunctionalStatus.IsSignalled = true;
      self->T5outMsgLcFunctionalStatus.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgLcFunctionalStatus__ab8c.HasMessage) {
    if (self->InMsgLcFunctionalStatus__ab8c.Value
            .ReportedActivationlStatusState ==
        FunctionalStatusState__5d12__ActivatedAndProtected) {
      self->D5outMsgLcFunctionalStatus.Value =
          SSciLcReceive_D5outMsgLcFunctionalStatusValue__ActivatedAndProtected;
      self->D5outMsgLcFunctionalStatus.IsSignalled = true;
      self->T5outMsgLcFunctionalStatus.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgLcFunctionalStatus__ab8c.HasMessage) {
    if (self->InMsgLcFunctionalStatus__ab8c.Value
            .ReportedActivationlStatusState ==
        FunctionalStatusState__5d12__ActivatedAndUnprotected) {
      self->D5outMsgLcFunctionalStatus.Value =
          SSciLcReceive_D5outMsgLcFunctionalStatusValue__ActivatedAndUnprotected;
      self->D5outMsgLcFunctionalStatus.IsSignalled = true;
      self->T5outMsgLcFunctionalStatus.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgLcFunctionalStatus__ab8c.HasMessage) {
    if (self->InMsgLcFunctionalStatus__ab8c.Value
            .ReportedActivationlStatusState ==
        FunctionalStatusState__5d12__DeactivatingAndUnprotected) {
      self->D5outMsgLcFunctionalStatus.Value =
          SSciLcReceive_D5outMsgLcFunctionalStatusValue__DeactivatingAndUnprotected;
      self->D5outMsgLcFunctionalStatus.IsSignalled = true;
      self->T5outMsgLcFunctionalStatus.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgLcFunctionalStatus__ab8c.HasMessage) {
    if (self->InMsgLcFunctionalStatus__ab8c.Value
            .ReportedActivationlStatusState ==
        FunctionalStatusState__5d12__DeactivatedAndIdle) {
      self->D5outMsgLcFunctionalStatus.Value =
          SSciLcReceive_D5outMsgLcFunctionalStatusValue__DeactivatedAndIdle;
      self->D5outMsgLcFunctionalStatus.IsSignalled = true;
      self->T5outMsgLcFunctionalStatus.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgLcMonitoringStatus__1d45.HasMessage) {
    Cop2GetMonitoringStatus(
        self,
        self->InMsgLcMonitoringStatus__1d45.Value
            .ReportedChangedMonitoringParameter,
        self->InMsgLcMonitoringStatus__1d45.Value.ReportedTimeOverrunState);
    self->T6outMsgLcMonitoringStatus.Trigger = true;
    make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
    return;
  }
  if (self->InMsgLocalOperationHandover__0594.HasMessage) {
    if (self->InMsgLocalOperationHandover__0594.Value
            .ReportedLocalOperationHandoverState ==
        LocalOperationHandoverState__ee05__ReturnHandoverFromLocalOperator) {
      self->D9outMsgLocalOperationHandover.Value =
          SSciLcReceive_D9outMsgLocalOperationHandoverValue__ReturnHandoverFromLocalOperator;
      self->D9outMsgLocalOperationHandover.IsSignalled = true;
      self->T9outMsgLocalOperationHandover.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgLocalOperationHandover__0594.HasMessage) {
    if (self->InMsgLocalOperationHandover__0594.Value
            .ReportedLocalOperationHandoverState ==
        LocalOperationHandoverState__ee05__AllowHandovertoLocalOperator) {
      self->D9outMsgLocalOperationHandover.Value =
          SSciLcReceive_D9outMsgLocalOperationHandoverValue__AllowHandoverToLocalOperator;
      self->D9outMsgLocalOperationHandover.IsSignalled = true;
      self->T9outMsgLocalOperationHandover.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgLocalRequest__daeb.HasMessage) {
    if (self->InMsgLocalRequest__daeb.Value.ReportedLocalRequestState ==
        LocalRequestState__d488__LocalRequestToActivateTheLevelCrossing) {
      self->D8outMsgLocalRequest.Value =
          SSciLcReceive_D8outMsgLocalRequestValue__LocalRequestToActivateTheLevelCrossing;
      self->D8outMsgLocalRequest.IsSignalled = true;
      self->T8outMsgLocalRequest.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgLocalRequest__daeb.HasMessage) {
    if (self->InMsgLocalRequest__daeb.Value.ReportedLocalRequestState ==
        LocalRequestState__d488__LocalRequestToDeactivateTheLevelCrossing) {
      self->D8outMsgLocalRequest.Value =
          SSciLcReceive_D8outMsgLocalRequestValue__LocalRequestToDeactivateTheLevelCrossing;
      self->D8outMsgLocalRequest.IsSignalled = true;
      self->T8outMsgLocalRequest.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgObstacleDetectionStatus__734d.HasMessage) {
    if (self->InMsgObstacleDetectionStatus__734d.Value
            .ReportedObstacleDetectionStatusState ==
        ObstacleDetectionStatusState__5aa0__ObstacleInTheConflictArea) {
      self->D91outMsgObstacleDetectionStatus.Value =
          SSciLcReceive_D91outMsgObstacleDetectionStatusValue__ObstacleDetectedInTheConflictArea;
      self->D91outMsgObstacleDetectionStatus.IsSignalled = true;
      self->T91outMsgObstacleDetectionStatus.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
  if (self->InMsgObstacleDetectionStatus__734d.HasMessage) {
    if (self->InMsgObstacleDetectionStatus__734d.Value
            .ReportedObstacleDetectionStatusState ==
        ObstacleDetectionStatusState__5aa0__NoObstacleInTheConflictArea) {
      self->D91outMsgObstacleDetectionStatus.Value =
          SSciLcReceive_D91outMsgObstacleDetectionStatusValue__NoObstacleInTheConflictArea;
      self->D91outMsgObstacleDetectionStatus.IsSignalled = true;
      self->T91outMsgObstacleDetectionStatus.Trigger = true;
      make_state_SSciLcReceive__root__ReceivingLcReports(self, x);
      return;
    }
  }
}

void transition_from_SSciLcReceive__root(SSciLcReceive *self,
                                         SSciLcReceive__root__state_struct *x) {
  switch (x->state) {
  case SSciLcReceive__root__ReceivingLcReports:
    transition_from_SSciLcReceive__root__ReceivingLcReports(self, x);
    break;
  }
}

static void evaluateChangeEvents(SSciLcReceive *self) {}

static void resetOutputs(SSciLcReceive *self) {

  self->T5outMsgLcFunctionalStatus.Trigger = false;
  self->T91outMsgObstacleDetectionStatus.Trigger = false;
  self->T7outMsgLcFailureStatus.Trigger = false;
  self->T18outMsgDetectionElementStatus.Trigger = false;
  self->T9outMsgLocalOperationHandover.Trigger = false;
  self->T6outMsgLcMonitoringStatus.Trigger = false;
  self->T8outMsgLocalRequest.Trigger = false;

  self->D5outMsgLcFunctionalStatus.IsSignalled = false;
  self->D91outMsgObstacleDetectionStatus.IsSignalled = false;
  self->D72outMsgLcFailureStatusCritical.IsSignalled = false;
  self->D18outMsgDetectionElementStatus.IsSignalled = false;
  self->D9outMsgLocalOperationHandover.IsSignalled = false;
  self->D61outMsgLcMonitoringStatusClosureTime.IsSignalled = false;
  self->D8outMsgLocalRequest.IsSignalled = false;
  self->D71outMsgLcFailureStatusNonCritical.IsSignalled = false;
  self->D62outMsgLcMonitoringStatusChangedMonitoringParameter.IsSignalled =
      false;
}

static void resetTriggers(SSciLcReceive *self) {
  self->InMsgDetectionElementStatus__aa8b.HasMessage = false;
  self->InMsgLcFailureStatus__5440.HasMessage = false;
  self->InMsgLcFunctionalStatus__ab8c.HasMessage = false;
  self->InMsgLcMonitoringStatus__1d45.HasMessage = false;
  self->InMsgLocalOperationHandover__0594.HasMessage = false;
  self->InMsgLocalRequest__daeb.HasMessage = false;
  self->InMsgObstacleDetectionStatus__734d.HasMessage = false;

  self->D50inPdiConnectionState.IsSignalled = false;
}

void transition_SSciLcReceive(SSciLcReceive *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_SSciLcReceive__root(self, &self->state);
  resetTriggers(self);
}

void new_SSciLcReceive(SSciLcReceive *self) {
  make_state_SSciLcReceive__root(self, &self->state);
}
