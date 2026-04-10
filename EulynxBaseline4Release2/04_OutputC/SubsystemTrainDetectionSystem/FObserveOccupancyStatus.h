
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveOccupancyStatus_D9outOccupancyStatusValue {
  FObserveOccupancyStatus_D9outOccupancyStatusValue__NULL__,
  FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableIn,
  FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableOut,
  FObserveOccupancyStatus_D9outOccupancyStatusValue__Vacant,
  FObserveOccupancyStatus_D9outOccupancyStatusValue__OccupiedIn,
  FObserveOccupancyStatus_D9outOccupancyStatusValue__OccupiedOut,
  FObserveOccupancyStatus_D9outOccupancyStatusValue__TechnicalDisturbed,
  FObserveOccupancyStatus_D9outOccupancyStatusValue__UNKNOWN__
} FObserveOccupancyStatus_D9outOccupancyStatusValue;
typedef enum FObserveOccupancyStatus_D51outEstEfesStateValue {
  FObserveOccupancyStatus_D51outEstEfesStateValue__NULL__,
  FObserveOccupancyStatus_D51outEstEfesStateValue__Booting,
  FObserveOccupancyStatus_D51outEstEfesStateValue__NoOperatingVoltage,
  FObserveOccupancyStatus_D51outEstEfesStateValue__FallbackMode,
  FObserveOccupancyStatus_D51outEstEfesStateValue__Initialising,
  FObserveOccupancyStatus_D51outEstEfesStateValue__UNKNOWN__
} FObserveOccupancyStatus_D51outEstEfesStateValue;

typedef enum FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state {
  FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming,
  FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing,
  FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant,
  FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming,
  FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing,
  FObserveOccupancyStatus__root__ObserveTvpsStatus__root__WaitingForNotificationOfAvailability
} FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state;

typedef struct
    FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct {
  FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state state;
  union {};
} FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct;

typedef enum FObserveOccupancyStatus__root__state {
  FObserveOccupancyStatus__root__ObserveTvpsStatus,
  FObserveOccupancyStatus__root__FallbackMode,
  FObserveOccupancyStatus__root__WaitingForFinishBooting,
  FObserveOccupancyStatus__root__TechnicalDisturbance
} FObserveOccupancyStatus__root__state;

typedef struct FObserveOccupancyStatus__root__ObserveTvpsStatus__state_struct {
  FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct root;
} FObserveOccupancyStatus__root__ObserveTvpsStatus__state_struct;

typedef struct FObserveOccupancyStatus__root__state_struct {
  FObserveOccupancyStatus__root__state state;
  union {
    FObserveOccupancyStatus__root__ObserveTvpsStatus__state_struct
        ObserveTvpsStatus;
  };
} FObserveOccupancyStatus__root__state_struct;

/// Contained in:
/// Subsystem Train Detection System
/// Functional requirements specification
/// Subsystem Train Detection System - Functional Viewpoint
/// Subsystem Train Detection System - Functional Entities
typedef struct FObserveOccupancyStatus {
  FObserveOccupancyStatus__root__state_struct state;

  /// D26in_Con_Variant_A_is_used
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D26inConVariantAIsUsed;

  /// d9out_Occupancy_Status
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(FObserveOccupancyStatus_D9outOccupancyStatusValue, )
      D9outOccupancyStatus;

  /// T37in_Wheel_In
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T37inWheelIn;

  /// T38in_Wheel_Out
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T38inWheelOut;

  /// T39in_Undefined_Pattern
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T39inUndefinedPattern;

  /// D32in_Critical_Failure_TVPS
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D32inCriticalFailureTvps;

  /// d51out_EST_EfeS_State
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(FObserveOccupancyStatus_D51outEstEfesStateValue, )
      D51outEstEfesState;

  /// d10out_Fillinglevel
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(int, ) D10outFillinglevel;

  /// d16out_Last_Wheel_Out
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(bool, ) D16outLastWheelOut;

  /// d14n_Running_Timer
  /// Trigger: False, DataPort: True, In: False, Out: False, External: False
  DataPort(bool, ) D14nRunningTimer;

  /// D28in_Con_t_Delay_Of_Notification_Of_Availability
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(int, ) D28inConTDelayOfNotificationOfAvailability;

  /// Mem_EnteredAxles
  /// Trigger: False, DataPort: False, In: False, Out: False, External: False
  int MemEnteredaxles;

  /// Mem_ExitedAxles
  /// Trigger: False, DataPort: False, In: False, Out: False, External: False
  int MemExitedaxles;

  /// Mem_Difference
  /// Trigger: False, DataPort: False, In: False, Out: False, External: False
  int MemDifference;

  // Messages -- Incoming
  MessagePort(Message__ExecuteDrfc__4da5) InExecuteDrfc__4da5;
  MessagePort(Message__ExecuteFc__ffe5) InExecuteFc__ffe5;
  // Messages -- Outgoing
  MessagePort(Message__ChangeTrigger__e05e) OutChangeTrigger__e05e;

  // Change Events
  ChangeEvent Change1116; // T38in_Wheel_Out
  ChangeEvent Change1101; // T37in_Wheel_In
  ChangeEvent Change1110; // T37in_Wheel_In OR T39in_Undefined_Pattern
  ChangeEvent Change1112; // T38in_Wheel_Out
  ChangeEvent Change1104; // T37in_Wheel_In
  ChangeEvent Change1111; // T38in_Wheel_Out
  ChangeEvent Change1121; // T39in_Undefined_Pattern
  ChangeEvent Change1114; // T38in_Wheel_Out
  ChangeEvent Change1120; // T39in_Undefined_Pattern
  ChangeEvent Change1105; // T37in_Wheel_In
  ChangeEvent Change542;  // Mem_Difference = 0
  ChangeEvent Change543;  // Mem_Difference = 0
  ChangeEvent Change1106; // T37in_Wheel_In
  ChangeEvent Change1119; // T39in_Undefined_Pattern
  ChangeEvent Change1117; // T38in_Wheel_Out
  ChangeEvent Change552;  // NOT d14n_Running_Timer
  ChangeEvent Change1102; // T37in_Wheel_In
  ChangeEvent Change1115; // T38in_Wheel_Out
  ChangeEvent Change1118; // T39in_Undefined_Pattern
  ChangeEvent Change257;  // D32in_Critical_Failure_TVPS
  ChangeEvent Change411;  // d51out_EST_EfeS_State = "BOOTING" OR
                          // d51out_EST_EfeS_State = "NO_OPERATING_VOLTAGE"
  ChangeEvent Change418;  // d51out_EST_EfeS_State = "FALLBACK_MODE"
  ChangeEvent Change1103; // T37in_Wheel_In
  ChangeEvent Change1113; // T38in_Wheel_Out
  ChangeEvent Change405;  // d51out_EST_EfeS_State = "BOOTING"
  ChangeEvent Change424;  // d51out_EST_EfeS_State = "INITIALISING"
  ChangeEvent Change416;  // d51out_EST_EfeS_State = "FALLBACK_MODE"
  ChangeEvent Change569;  // NOT D32in_Critical_Failure_TVPS

  // Timeout Events

} FObserveOccupancyStatus;

void transition_FObserveOccupancyStatus(FObserveOccupancyStatus *self);
void new_FObserveOccupancyStatus(FObserveOccupancyStatus *x);
