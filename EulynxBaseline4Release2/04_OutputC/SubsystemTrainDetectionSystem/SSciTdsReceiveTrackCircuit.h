
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue {
  SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__NULL__,
  SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateVacant,
  SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateOccupied,
  SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateDisturbed,
  SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__UNKNOWN__
} SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue;
typedef enum SSciTdsReceiveTrackCircuit_D66outPomStatusValue {
  SSciTdsReceiveTrackCircuit_D66outPomStatusValue__NULL__,
  SSciTdsReceiveTrackCircuit_D66outPomStatusValue__Nok,
  SSciTdsReceiveTrackCircuit_D66outPomStatusValue__Ok,
  SSciTdsReceiveTrackCircuit_D66outPomStatusValue__UNKNOWN__
} SSciTdsReceiveTrackCircuit_D66outPomStatusValue;
typedef enum SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue {
  SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__NULL__,
  SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__NotApplicable,
  SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__Technical,
  SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__UNKNOWN__
} SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue;

typedef enum SSciTdsReceiveTrackCircuit__root__state {
  SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus
} SSciTdsReceiveTrackCircuit__root__state;

typedef struct SSciTdsReceiveTrackCircuit__root__state_struct {
  SSciTdsReceiveTrackCircuit__root__state state;
  union {};
} SSciTdsReceiveTrackCircuit__root__state_struct;

/// Contained in:
/// Subsystem Train Detection System
/// Functional requirements specification
/// Subsystem Train Detection System - Interfaces
/// SCI-TDS (Subsystem – Electronic Interlocking)
/// SCI-TDS - Functional Viewpoint
/// SCI-TDS - Functional Entities
typedef struct SSciTdsReceiveTrackCircuit {
  SSciTdsReceiveTrackCircuit__root__state_struct state;

  /// d66out_Ability_To_Be_Forced_To_Clear
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(bool, ) D66outAbilityToBeForcedToClear;

  /// d66out_TVPS_Occupancy_Status
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue, )
      D66outTvpsOccupancyStatus;

  /// d66out_POM_Status
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciTdsReceiveTrackCircuit_D66outPomStatusValue, ) D66outPomStatus;

  /// d66out_Disturbance_Status
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue, )
      D66outDisturbanceStatus;

  /// t66out_TVPS_Occupancy_Status
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T66outTvpsOccupancyStatus;

  // Messages -- Incoming
  MessagePort(Message__MsgTvpsOccupancyStatus__b4e1)
      InMsgTvpsOccupancyStatus__b4e1;
  // Messages -- Outgoing

  // Change Events

  // Timeout Events

} SSciTdsReceiveTrackCircuit;

void transition_SSciTdsReceiveTrackCircuit(SSciTdsReceiveTrackCircuit *self);
void new_SSciTdsReceiveTrackCircuit(SSciTdsReceiveTrackCircuit *x);
