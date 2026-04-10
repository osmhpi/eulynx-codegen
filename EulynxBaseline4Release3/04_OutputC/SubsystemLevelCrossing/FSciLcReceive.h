
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciLcReceive_D1outReceiveLcStateValue {
  FSciLcReceive_D1outReceiveLcStateValue__NULL__,
  FSciLcReceive_D1outReceiveLcStateValue__Activated,
  FSciLcReceive_D1outReceiveLcStateValue__Deactivated,
  FSciLcReceive_D1outReceiveLcStateValue__Isolated,
  FSciLcReceive_D1outReceiveLcStateValue__PreActivated,
  FSciLcReceive_D1outReceiveLcStateValue__UNKNOWN__
} FSciLcReceive_D1outReceiveLcStateValue;
typedef enum FSciLcReceive_D8outHandoverToLocalOperatorStateValue {
  FSciLcReceive_D8outHandoverToLocalOperatorStateValue__NULL__,
  FSciLcReceive_D8outHandoverToLocalOperatorStateValue__NoHandover,
  FSciLcReceive_D8outHandoverToLocalOperatorStateValue__Initiated,
  FSciLcReceive_D8outHandoverToLocalOperatorStateValue__Established,
  FSciLcReceive_D8outHandoverToLocalOperatorStateValue__UNKNOWN__
} FSciLcReceive_D8outHandoverToLocalOperatorStateValue;
typedef enum FSciLcReceive_D53inTimeExpiredValue {
  FSciLcReceive_D53inTimeExpiredValue__NULL__,
  FSciLcReceive_D53inTimeExpiredValue__DelayExpired,
  FSciLcReceive_D53inTimeExpiredValue__UNKNOWN__
} FSciLcReceive_D53inTimeExpiredValue;
typedef enum FSciLcReceive_D51inEstEfesStateValue {
  FSciLcReceive_D51inEstEfesStateValue__NULL__,
  FSciLcReceive_D51inEstEfesStateValue__Initialising,
  FSciLcReceive_D51inEstEfesStateValue__Booting,
  FSciLcReceive_D51inEstEfesStateValue__FallbackMode,
  FSciLcReceive_D51inEstEfesStateValue__NoOperatingVoltage,
  FSciLcReceive_D51inEstEfesStateValue__Operational,
  FSciLcReceive_D51inEstEfesStateValue__UNKNOWN__
} FSciLcReceive_D51inEstEfesStateValue;

typedef enum FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state {
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated,
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated,
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Isolated,
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__PreActivated
} FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state;

typedef struct
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state_struct {
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state
      state;
  union {};
} FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state_struct;

typedef enum FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state {
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__Waiting,
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator,
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated,
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished
} FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state;

typedef struct
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state_struct {
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state
      state;
  union {};
} FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state_struct;

typedef enum FSciLcReceive__root__state {
  FSciLcReceive__root__ReceivingLevelCrossingCommands,
  FSciLcReceive__root__NationalSpecificState,
  FSciLcReceive__root__Waiting
} FSciLcReceive__root__state;

typedef struct
    FSciLcReceive__root__ReceivingLevelCrossingCommands__state_struct {
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state_struct
      ReceivingActivationState;
  FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state_struct
      ReceiveLocalOperationHandover;
} FSciLcReceive__root__ReceivingLevelCrossingCommands__state_struct;

typedef struct FSciLcReceive__root__state_struct {
  FSciLcReceive__root__state state;
  union {
    FSciLcReceive__root__ReceivingLevelCrossingCommands__state_struct
        ReceivingLevelCrossingCommands;
  };
} FSciLcReceive__root__state_struct;

/// Contained in:
/// Subsystem - Level Crossing
/// Functional requirements specification
/// Subsystem - Level Crossing - Interfaces
/// SCI-LC (Subsystem -  Electronic Interlocking)
/// SCI-LC - Functional Viewpoint
/// SCI-LC - Functional Entities
typedef struct FSciLcReceive {
  FSciLcReceive__root__state_struct state;

  /// d1out_Receive_LC_State
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(FSciLcReceive_D1outReceiveLcStateValue, ) D1outReceiveLcState;

  /// d8out_Handover_To_Local_Operator_State
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(FSciLcReceive_D8outHandoverToLocalOperatorStateValue, )
      D8outHandoverToLocalOperatorState;

  /// d53in_Time_Expired
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciLcReceive_D53inTimeExpiredValue, ) D53inTimeExpired;

  /// T31out_Activate_LCPF
  /// Trigger: True, DataPort: False, In: False, Out: True, External: True
  PulsedOut T31outActivateLcpf;

  /// T33out_Pre_Activate_LCPF
  /// Trigger: True, DataPort: False, In: False, Out: True, External: True
  PulsedOut T33outPreActivateLcpf;

  /// T34out_National_Specific_State_LCPF
  /// Trigger: True, DataPort: False, In: False, Out: True, External: True
  PulsedOut T34outNationalSpecificStateLcpf;

  /// T32out_Deactivate_LCPF
  /// Trigger: True, DataPort: False, In: False, Out: True, External: True
  PulsedOut T32outDeactivateLcpf;

  /// d51in_EST_EfeS_State
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciLcReceive_D51inEstEfesStateValue, ) D51inEstEfesState;

  /// D55in_Con_Inital_Activate_LCPF
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D55inConInitalActivateLcpf;

  // Messages -- Incoming
  MessagePort(Message__CdDeactivation__48b5) InCdDeactivation__48b5;
  MessagePort(Message__CdActivation__3513) InCdActivation__3513;
  MessagePort(Message__CdIsolateLc__add9) InCdIsolateLc__add9;
  MessagePort(Message__CdLocalOperationHandover__2b72)
      InCdLocalOperationHandover__2b72;
  // Messages -- Outgoing

  // Change Events
  ChangeEvent Change411; // d53in_Time_Expired = "Delay Expired"
  ChangeEvent Change322; // d51in_EST_EfeS_State  = "INITIALISING" AND
                         // D55in_Con_Inital_Activate_LCPF = TRUE
  ChangeEvent Change323; // d51in_EST_EfeS_State  = "INITIALISING" AND
                         // D55in_Con_Inital_Activate_LCPF = TRUE
  ChangeEvent Change320; // d51in_EST_EfeS_State  = "BOOTING"
  ChangeEvent Change355; // d51in_EST_EfeS_State = "FALLBACK_MODE" OR
                         // d51in_EST_EfeS_State  = "NO_OPERATING_VOLTAGE"
  ChangeEvent Change325; // d51in_EST_EfeS_State  = "OPERATIONAL" OR
                         // d51in_EST_EfeS_State  = "BOOTING" OR
                         // d51in_EST_EfeS_State  = "INITIALISING"
  ChangeEvent Change319; // d51in_EST_EfeS_State  = "BOOTING"

  // Timeout Events

} FSciLcReceive;

void transition_FSciLcReceive(FSciLcReceive *self);
void new_FSciLcReceive(FSciLcReceive *x);
