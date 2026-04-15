
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciIoCommand_D31inRequiredChannelState1Value
{
    SSciIoCommand_D31inRequiredChannelState1Value__NULL__,
    SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOff,
    SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOn,
    SSciIoCommand_D31inRequiredChannelState1Value__Flashing,
    SSciIoCommand_D31inRequiredChannelState1Value__UNKNOWN__
} SSciIoCommand_D31inRequiredChannelState1Value;
typedef enum SSciIoCommand_D50inPdiConnectionStateValue
{
    SSciIoCommand_D50inPdiConnectionStateValue__NULL__,
    SSciIoCommand_D50inPdiConnectionStateValue__Established,
    SSciIoCommand_D50inPdiConnectionStateValue__UNKNOWN__
} SSciIoCommand_D50inPdiConnectionStateValue;
typedef enum SSciIoCommand_D32inRequiredChannelStatenValue
{
    SSciIoCommand_D32inRequiredChannelStatenValue__NULL__,
    SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOff,
    SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOn,
    SSciIoCommand_D32inRequiredChannelStatenValue__Flashing,
    SSciIoCommand_D32inRequiredChannelStatenValue__UNKNOWN__
} SSciIoCommand_D32inRequiredChannelStatenValue;

typedef enum SSciIoCommand__root__state
{
    SSciIoCommand__root__SendingOutputChannelCommand
} SSciIoCommand__root__state;

typedef struct SSciIoCommand__root__state_struct
{
    SSciIoCommand__root__state state;
    union {
    };
} SSciIoCommand__root__state_struct;

/// Contained in:
/// Subsystem - Generic IO
/// Functional requirements specification
/// Subsystem - Generic IO - Interfaces
/// SCI-IO (Subsystem - Electronic Interlocking)
/// SCI-IO - Functional Viewpoint
/// SCI-IO - Functional Entities
typedef struct SSciIoCommand
{
    SSciIoCommand__root__state_struct state;

    /// d31in_Required_Channel_State1
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(SSciIoCommand_D31inRequiredChannelState1Value, ) D31inRequiredChannelState1;

    /// d50in_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(SSciIoCommand_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;

    /// t30in_New_Output_Channel_State_Required
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T30inNewOutputChannelStateRequired;

    /// d32in_Required_Channel_StateN
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(SSciIoCommand_D32inRequiredChannelStatenValue, ) D32inRequiredChannelStaten;

    // Messages -- Incoming

    // Messages -- Outgoing
    MessagePort(Message__CdSetOutputChannels__3b5f) OutCdSetOutputChannels__3b5f;

    // Change Events
    ChangeEvent Change1084; // t30in_New_Output_Channel_State_Required
    ChangeEvent Change1083; // t30in_New_Output_Channel_State_Required
    ChangeEvent Change1082; // t30in_New_Output_Channel_State_Required
    ChangeEvent Change1081; // t30in_New_Output_Channel_State_Required
    ChangeEvent Change1078; // t30in_New_Output_Channel_State_Required
    ChangeEvent Change1077; // t30in_New_Output_Channel_State_Required
    ChangeEvent Change1076; // t30in_New_Output_Channel_State_Required
    ChangeEvent Change1079; // t30in_New_Output_Channel_State_Required
    ChangeEvent Change1080; // t30in_New_Output_Channel_State_Required

    // Timeout Events

} SSciIoCommand;

void transition_SSciIoCommand(SSciIoCommand *self);
void transition_SSciIoCommand(SSciIoCommand *self);
void new_SSciIoCommand(SSciIoCommand *x);
