
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciTdsReceiveTvps_D75outOccupancyStatusValue {
  SSciTdsReceiveTvps_D75outOccupancyStatusValue__NULL__,
  SSciTdsReceiveTvps_D75outOccupancyStatusValue__Vacant,
  SSciTdsReceiveTvps_D75outOccupancyStatusValue__Occupied,
  SSciTdsReceiveTvps_D75outOccupancyStatusValue__Disturbed,
  SSciTdsReceiveTvps_D75outOccupancyStatusValue__WaitingForSweepingTrain,
  SSciTdsReceiveTvps_D75outOccupancyStatusValue__SweepingTrainDetected,
  SSciTdsReceiveTvps_D75outOccupancyStatusValue__WaitingForAcknowledgement,
  SSciTdsReceiveTvps_D75outOccupancyStatusValue__UNKNOWN__
} SSciTdsReceiveTvps_D75outOccupancyStatusValue;
typedef enum SSciTdsReceiveTvps_D75outReasonForFailureValue {
  SSciTdsReceiveTvps_D75outReasonForFailureValue__NULL__,
  SSciTdsReceiveTvps_D75outReasonForFailureValue__Operational,
  SSciTdsReceiveTvps_D75outReasonForFailureValue__Technical,
  SSciTdsReceiveTvps_D75outReasonForFailureValue__NotApplicable,
  SSciTdsReceiveTvps_D75outReasonForFailureValue__UNKNOWN__
} SSciTdsReceiveTvps_D75outReasonForFailureValue;
typedef enum SSciTdsReceiveTvps_D75outChangeTriggerValue {
  SSciTdsReceiveTvps_D75outChangeTriggerValue__NULL__,
  SSciTdsReceiveTvps_D75outChangeTriggerValue__CommandFromEil,
  SSciTdsReceiveTvps_D75outChangeTriggerValue__PassingDetected,
  SSciTdsReceiveTvps_D75outChangeTriggerValue__CommandFromMaintainer,
  SSciTdsReceiveTvps_D75outChangeTriggerValue__TechnicalFailure,
  SSciTdsReceiveTvps_D75outChangeTriggerValue__InitialSectionState,
  SSciTdsReceiveTvps_D75outChangeTriggerValue__InternalTrigger,
  SSciTdsReceiveTvps_D75outChangeTriggerValue__UNKNOWN__
} SSciTdsReceiveTvps_D75outChangeTriggerValue;
typedef enum SSciTdsReceiveTvps_D82outFcPFailedValue {
  SSciTdsReceiveTvps_D82outFcPFailedValue__NULL__,
  SSciTdsReceiveTvps_D82outFcPFailedValue__IncorrectCount,
  SSciTdsReceiveTvps_D82outFcPFailedValue__TimeoutTMax,
  SSciTdsReceiveTvps_D82outFcPFailedValue__NotPermittedPassing,
  SSciTdsReceiveTvps_D82outFcPFailedValue__OutgoingWheelBeforeTMin,
  SSciTdsReceiveTvps_D82outFcPFailedValue__ProcessCanceled,
  SSciTdsReceiveTvps_D82outFcPFailedValue__UNKNOWN__
} SSciTdsReceiveTvps_D82outFcPFailedValue;
typedef enum SSciTdsReceiveTvps_D83outFcPAFailedValue {
  SSciTdsReceiveTvps_D83outFcPAFailedValue__NULL__,
  SSciTdsReceiveTvps_D83outFcPAFailedValue__IncorrectCount,
  SSciTdsReceiveTvps_D83outFcPAFailedValue__TimeoutTMax,
  SSciTdsReceiveTvps_D83outFcPAFailedValue__NotPermittedPassing,
  SSciTdsReceiveTvps_D83outFcPAFailedValue__OutgoingWheelBeforeTMin,
  SSciTdsReceiveTvps_D83outFcPAFailedValue__ProcessCanceled,
  SSciTdsReceiveTvps_D83outFcPAFailedValue__UNKNOWN__
} SSciTdsReceiveTvps_D83outFcPAFailedValue;
typedef enum SSciTdsReceiveTvps_D84outCommandRejectedValue {
  SSciTdsReceiveTvps_D84outCommandRejectedValue__NULL__,
  SSciTdsReceiveTvps_D84outCommandRejectedValue__Operational,
  SSciTdsReceiveTvps_D84outCommandRejectedValue__Technical,
  SSciTdsReceiveTvps_D84outCommandRejectedValue__UNKNOWN__
} SSciTdsReceiveTvps_D84outCommandRejectedValue;

typedef enum SSciTdsReceiveTvps__root__state {
  SSciTdsReceiveTvps__root__ReceivingTvpsReports
} SSciTdsReceiveTvps__root__state;

typedef struct SSciTdsReceiveTvps__root__state_struct {
  SSciTdsReceiveTvps__root__state state;
  union {};
} SSciTdsReceiveTvps__root__state_struct;

/// Contained in:
/// Subsystem - Train Detection System
/// Functional requirements specification
/// Subsystem - Train Detection System - Interfaces
/// SCI-TDS (Subsystem – Electronic Interlocking)
/// SCI-TDS - Functional Viewpoint
/// SCI-TDS - Functional Entities
typedef struct SSciTdsReceiveTvps {
  SSciTdsReceiveTvps__root__state_struct state;

  /// d75out_Occupancy_Status
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciTdsReceiveTvps_D75outOccupancyStatusValue, )
      D75outOccupancyStatus;

  /// d75out_Ability_To_Be_Forced_To_Clear
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(bool, ) D75outAbilityToBeForcedToClear;

  /// d75out_Fillinglevel
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(int, ) D75outFillinglevel;

  /// d75out_Reason_For_Failure
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciTdsReceiveTvps_D75outReasonForFailureValue, )
      D75outReasonForFailure;

  /// d75out_Change_Trigger
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciTdsReceiveTvps_D75outChangeTriggerValue, ) D75outChangeTrigger;

  /// d82out_FC_P_failed
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciTdsReceiveTvps_D82outFcPFailedValue, ) D82outFcPFailed;

  /// d83out_FC_P_A_failed
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciTdsReceiveTvps_D83outFcPAFailedValue, ) D83outFcPAFailed;

  /// d84out_Command_Rejected
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciTdsReceiveTvps_D84outCommandRejectedValue, )
      D84outCommandRejected;

  /// t75out_TVPS_Occupancy_Status
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T75outTvpsOccupancyStatus;

  /// t84out_Command_Rejected
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T84outCommandRejected;

  /// t82out_FC_P_failed
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T82outFcPFailed;

  /// t83out_FC_P_A_failed
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T83outFcPAFailed;

  // Messages -- Incoming
  MessagePort(Message__MsgCommandRejected__8d0b) InMsgCommandRejected__8d0b;
  MessagePort(Message__MsgTvpsFcPAFailed__3c61) InMsgTvpsFcPAFailed__3c61;
  MessagePort(Message__MsgTvpsFcPFailed__811b) InMsgTvpsFcPFailed__811b;
  MessagePort(Message__MsgTvpsOccupancyStatus__b4e1)
      InMsgTvpsOccupancyStatus__b4e1;
  // Messages -- Outgoing

  // Change Events

  // Timeout Events

} SSciTdsReceiveTvps;

void transition_SSciTdsReceiveTvps(SSciTdsReceiveTvps *self);
void new_SSciTdsReceiveTvps(SSciTdsReceiveTvps *x);
