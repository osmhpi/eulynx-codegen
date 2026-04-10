
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue {
  FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__NULL__,
  FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__Vacant,
  FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__OccupiedOut,
  FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableOut,
  FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableIn,
  FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UNKNOWN__
} FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue;
typedef enum FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue {
  FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__NULL__,
  FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__Booting,
  FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__NoOperatingVoltage,
  FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__FallbackMode,
  FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__Initialising,
  FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__UNKNOWN__
} FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue;

typedef enum FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__state {
  FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear,
  FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear
} FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__state;

typedef struct
    FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__state_struct {
  FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__state
      state;
  union {};
} FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__state_struct;

typedef enum FObserveAbilityToBeForcedToClear__root__state {
  FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear,
  FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting,
  FObserveAbilityToBeForcedToClear__root__FallbackMode,
  FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance
} FObserveAbilityToBeForcedToClear__root__state;

typedef struct
    FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__state_struct {
  FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__state_struct
      root;
} FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__state_struct;

typedef struct FObserveAbilityToBeForcedToClear__root__state_struct {
  FObserveAbilityToBeForcedToClear__root__state state;
  union {
    FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__state_struct
        ObserveAbilityToBeForcedToClear;
  };
} FObserveAbilityToBeForcedToClear__root__state_struct;

/// Contained in:
/// Subsystem - Train Detection System
/// Functional requirements specification
/// Subsystem - Train Detection System - Functional Viewpoint
/// Subsystem - Train Detection System - Functional Entities
typedef struct FObserveAbilityToBeForcedToClear {
  FObserveAbilityToBeForcedToClear__root__state_struct state;

  /// d13out_Able_To_Be_Forced_To_Clear
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(bool, ) D13outAbleToBeForcedToClear;

  /// d14n_Monitoring_Time
  /// Trigger: False, DataPort: True, In: False, Out: False, External: False
  DataPort(bool, ) D14nMonitoringTime;

  /// D26in_Con_Variant_A_is_used
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D26inConVariantAIsUsed;

  /// d9in_Occupancy_Status
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue, )
      D9inOccupancyStatus;

  /// D32in_Critical_Failure_TVPS
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D32inCriticalFailureTvps;

  /// d51out_EST_EfeS_State
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue, )
      D51outEstEfesState;

  /// d18in_Perform_FC_P_Or_FC_P_A
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(bool, ) D18inPerformFcPOrFcPA;

  // Messages -- Incoming

  // Messages -- Outgoing

  // Change Events
  ChangeEvent Change118; // d14n_Monitoring_Time
  ChangeEvent Change128; // d18in_Perform_FC_P_Or_FC_P_A
  ChangeEvent Change508; // d9in_Occupancy_Status = "vacant"
  ChangeEvent Change502; // d9in_Occupancy_Status = "occupied out"
  ChangeEvent Change505; // d9in_Occupancy_Status = "unreliable out"
  ChangeEvent Change549; // NOT d14n_Monitoring_Time
  ChangeEvent Change547; // NOT d14n_Monitoring_Time
  ChangeEvent Change548; // NOT d14n_Monitoring_Time
  ChangeEvent Change552; // NOT d18in_Perform_FC_P_Or_FC_P_A
  ChangeEvent Change550; // NOT d18in_Perform_FC_P_Or_FC_P_A
  ChangeEvent Change553; // NOT d18in_Perform_FC_P_Or_FC_P_A
  ChangeEvent Change234; // D32in_Critical_Failure_TVPS
  ChangeEvent Change388; // d51out_EST_EfeS_State = "BOOTING" OR
                         // d51out_EST_EfeS_State = "NO_OPERATING_VOLTAGE"
  ChangeEvent Change393; // d51out_EST_EfeS_State = "FALLBACK_MODE"
  ChangeEvent Change403; // d51out_EST_EfeS_State = "INITIALISING"
  ChangeEvent Change384; // d51out_EST_EfeS_State = "BOOTING"
  ChangeEvent Change399; // d51out_EST_EfeS_State = "FALLBACK_MODE"
  ChangeEvent Change561; // NOT D32in_Critical_Failure_TVPS

  // Timeout Events

} FObserveAbilityToBeForcedToClear;

void transition_FObserveAbilityToBeForcedToClear(
    FObserveAbilityToBeForcedToClear *self);
void new_FObserveAbilityToBeForcedToClear(FObserveAbilityToBeForcedToClear *x);
