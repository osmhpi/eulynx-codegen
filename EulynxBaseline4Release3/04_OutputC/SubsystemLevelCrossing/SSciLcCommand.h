
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciLcCommand_D1inCdActivationValue {
  SSciLcCommand_D1inCdActivationValue__NULL__,
  SSciLcCommand_D1inCdActivationValue__PreActivation,
  SSciLcCommand_D1inCdActivationValue__Activation,
  SSciLcCommand_D1inCdActivationValue__UNKNOWN__
} SSciLcCommand_D1inCdActivationValue;
typedef enum SSciLcCommand_D4inCdIsolateLcValue {
  SSciLcCommand_D4inCdIsolateLcValue__NULL__,
  SSciLcCommand_D4inCdIsolateLcValue__IsolateLcDisable,
  SSciLcCommand_D4inCdIsolateLcValue__IsolateLcEnable,
  SSciLcCommand_D4inCdIsolateLcValue__UNKNOWN__
} SSciLcCommand_D4inCdIsolateLcValue;
typedef enum SSciLcCommand_D3inCdLocalOperationHandoverValue {
  SSciLcCommand_D3inCdLocalOperationHandoverValue__NULL__,
  SSciLcCommand_D3inCdLocalOperationHandoverValue__HandoverToLocalOperatorInitiated,
  SSciLcCommand_D3inCdLocalOperationHandoverValue__HandoverToLocalOperatorEstablished,
  SSciLcCommand_D3inCdLocalOperationHandoverValue__NoHandoverToLocalOperator,
  SSciLcCommand_D3inCdLocalOperationHandoverValue__UNKNOWN__
} SSciLcCommand_D3inCdLocalOperationHandoverValue;
typedef enum SSciLcCommand_D50inPdiConnectionStateValue {
  SSciLcCommand_D50inPdiConnectionStateValue__NULL__,
  SSciLcCommand_D50inPdiConnectionStateValue__Established,
  SSciLcCommand_D50inPdiConnectionStateValue__UNKNOWN__
} SSciLcCommand_D50inPdiConnectionStateValue;

typedef enum SSciLcCommand__root__state {
  SSciLcCommand__root__SendingCommands
} SSciLcCommand__root__state;

typedef struct SSciLcCommand__root__state_struct {
  SSciLcCommand__root__state state;
  union {};
} SSciLcCommand__root__state_struct;

/// Contained in:
/// Subsystem - Level Crossing
/// Functional requirements specification
/// Subsystem - Level Crossing - Interfaces
/// SCI-LC (Subsystem -  Electronic Interlocking)
/// SCI-LC - Functional Viewpoint
/// SCI-LC - Functional Entities
typedef struct SSciLcCommand {
  SSciLcCommand__root__state_struct state;

  /// t1in_Cd_Activation
  /// Trigger: True, DataPort: False, In: True, Out: False, External: False
  PulsedIn T1inCdActivation;

  /// d1in_Cd_Activation
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(SSciLcCommand_D1inCdActivationValue, ) D1inCdActivation;

  /// t2in_Cd_Deactivation
  /// Trigger: True, DataPort: False, In: True, Out: False, External: False
  PulsedIn T2inCdDeactivation;

  /// t4in_Cd_Isolate_LC
  /// Trigger: True, DataPort: False, In: True, Out: False, External: False
  PulsedIn T4inCdIsolateLc;

  /// d4in_Cd_Isolate_LC
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(SSciLcCommand_D4inCdIsolateLcValue, ) D4inCdIsolateLc;

  /// t3in_Cd_Local_Operation_Handover
  /// Trigger: True, DataPort: False, In: True, Out: False, External: False
  PulsedIn T3inCdLocalOperationHandover;

  /// d3in_Cd_Local_Operation_Handover
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(SSciLcCommand_D3inCdLocalOperationHandoverValue, )
      D3inCdLocalOperationHandover;

  /// d50in_PDI_Connection_State
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(SSciLcCommand_D50inPdiConnectionStateValue, )
      D50inPdiConnectionState;

  /// D65in_Con_Use_Pre_Activation
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D65inConUsePreActivation;

  /// D67in_Con_Use_Isolation
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D67inConUseIsolation;

  // Messages -- Incoming

  // Messages -- Outgoing
  MessagePort(Message__CdActivation__3513) OutCdActivation__3513;
  MessagePort(Message__CdDeactivation__48b5) OutCdDeactivation__48b5;
  MessagePort(Message__CdLocalOperationHandover__2b72)
      OutCdLocalOperationHandover__2b72;
  MessagePort(Message__CdIsolateLc__add9) OutCdIsolateLc__add9;

  // Change Events
  ChangeEvent Change863;  // t1in_Cd_Activation
  ChangeEvent Change864;  // t1in_Cd_Activation
  ChangeEvent Change1059; // t2in_Cd_Deactivation
  ChangeEvent Change1141; // t3in_Cd_Local_Operation_Handover
  ChangeEvent Change1140; // t3in_Cd_Local_Operation_Handover
  ChangeEvent Change1139; // t3in_Cd_Local_Operation_Handover
  ChangeEvent Change1193; // t4in_Cd_Isolate_LC
  ChangeEvent Change1192; // t4in_Cd_Isolate_LC

  // Timeout Events

} SSciLcCommand;

void transition_SSciLcCommand(SSciLcCommand *self);
void new_SSciLcCommand(SSciLcCommand *x);
