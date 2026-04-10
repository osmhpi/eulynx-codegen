
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FTds6MaintainerCommandsAndMessages_D35inModeOfFcValue {
  FTds6MaintainerCommandsAndMessages_D35inModeOfFcValue__NULL__,
  FTds6MaintainerCommandsAndMessages_D35inModeOfFcValue__FcU,
  FTds6MaintainerCommandsAndMessages_D35inModeOfFcValue__FcC,
  FTds6MaintainerCommandsAndMessages_D35inModeOfFcValue__UNKNOWN__
} FTds6MaintainerCommandsAndMessages_D35inModeOfFcValue;
typedef enum FTds6MaintainerCommandsAndMessages_D36outCommandRejectedValue {
  FTds6MaintainerCommandsAndMessages_D36outCommandRejectedValue__NULL__,
  FTds6MaintainerCommandsAndMessages_D36outCommandRejectedValue__Operational,
  FTds6MaintainerCommandsAndMessages_D36outCommandRejectedValue__Technical,
  FTds6MaintainerCommandsAndMessages_D36outCommandRejectedValue__UNKNOWN__
} FTds6MaintainerCommandsAndMessages_D36outCommandRejectedValue;

typedef enum FTds6MaintainerCommandsAndMessages__root__state {
  FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages
} FTds6MaintainerCommandsAndMessages__root__state;

typedef struct FTds6MaintainerCommandsAndMessages__root__state_struct {
  FTds6MaintainerCommandsAndMessages__root__state state;
  union {};
} FTds6MaintainerCommandsAndMessages__root__state_struct;

/// Contained in:
/// Subsystem Train Detection System
/// Functional requirements specification
/// Subsystem Train Detection System - Functional Viewpoint
/// Subsystem Train Detection System - Functional Entities
typedef struct FTds6MaintainerCommandsAndMessages {
  FTds6MaintainerCommandsAndMessages__root__state_struct state;

  /// T35in_FC
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T35inFc;

  /// D35in_Mode_Of_FC
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(FTds6MaintainerCommandsAndMessages_D35inModeOfFcValue, )
      D35inModeOfFc;

  /// T34in_DRFC
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T34inDrfc;

  /// D36out_Command_Rejected
  /// Trigger: False, DataPort: True, In: False, Out: True, External: True
  DataPort(FTds6MaintainerCommandsAndMessages_D36outCommandRejectedValue, )
      D36outCommandRejected;

  /// T36out_Command_Rejected
  /// Trigger: True, DataPort: False, In: False, Out: True, External: True
  PulsedOut T36outCommandRejected;

  /// T41in_Visual_Sweeping_Confirmed
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T41inVisualSweepingConfirmed;

  // Messages -- Incoming
  MessagePort(Message__ReportCommandRejected__fa56)
      InReportCommandRejected__fa56;
  // Messages -- Outgoing
  MessagePort(Message__RequestDrfc__a48b) OutRequestDrfc__a48b;
  MessagePort(Message__RequestFcU__bd99) OutRequestFcU__bd99;
  MessagePort(Message__RequestFcC__f902) OutRequestFcC__f902;
  MessagePort(Message__RequestVisualSweepingConfirmation__2333)
      OutRequestVisualSweepingConfirmation__2333;

  // Change Events
  ChangeEvent Change1096; // T34in_DRFC
  ChangeEvent Change1097; // T35in_FC
  ChangeEvent Change1098; // T35in_FC
  ChangeEvent Change1158; // T41in_Visual_Sweeping_Confirmed

  // Timeout Events

} FTds6MaintainerCommandsAndMessages;

void transition_FTds6MaintainerCommandsAndMessages(
    FTds6MaintainerCommandsAndMessages *self);
void new_FTds6MaintainerCommandsAndMessages(
    FTds6MaintainerCommandsAndMessages *x);
