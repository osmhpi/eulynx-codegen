
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciIoReceive_D71outReportedInputChannelState1Value
{
    SSciIoReceive_D71outReportedInputChannelState1Value__NULL__,
    SSciIoReceive_D71outReportedInputChannelState1Value__Unknown,
    SSciIoReceive_D71outReportedInputChannelState1Value__SwitchedOn,
    SSciIoReceive_D71outReportedInputChannelState1Value__SwitchedOff,
    SSciIoReceive_D71outReportedInputChannelState1Value__Disturbed,
    SSciIoReceive_D71outReportedInputChannelState1Value__UNKNOWN__
} SSciIoReceive_D71outReportedInputChannelState1Value;
typedef enum SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value
{
    SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value__NULL__,
    SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value__Unknown,
    SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value__PhysicallyDisturbed,
    SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed,
    SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value__UNKNOWN__
} SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value;
typedef enum SSciIoReceive_D50inPdiConnectionStateValue
{
    SSciIoReceive_D50inPdiConnectionStateValue__NULL__,
    SSciIoReceive_D50inPdiConnectionStateValue__Disconnected,
    SSciIoReceive_D50inPdiConnectionStateValue__Impermissible,
    SSciIoReceive_D50inPdiConnectionStateValue__Suspended,
    SSciIoReceive_D50inPdiConnectionStateValue__RequestedNoScp,
    SSciIoReceive_D50inPdiConnectionStateValue__UNKNOWN__
} SSciIoReceive_D50inPdiConnectionStateValue;
typedef enum SSciIoReceive_D72outReportedInputChannelStatenValue
{
    SSciIoReceive_D72outReportedInputChannelStatenValue__NULL__,
    SSciIoReceive_D72outReportedInputChannelStatenValue__Unknown,
    SSciIoReceive_D72outReportedInputChannelStatenValue__SwitchedOn,
    SSciIoReceive_D72outReportedInputChannelStatenValue__SwitchedOff,
    SSciIoReceive_D72outReportedInputChannelStatenValue__Disturbed,
    SSciIoReceive_D72outReportedInputChannelStatenValue__UNKNOWN__
} SSciIoReceive_D72outReportedInputChannelStatenValue;
typedef enum SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue
{
    SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue__NULL__,
    SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue__Unknown,
    SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue__PhysicallyDisturbed,
    SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed,
    SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue__UNKNOWN__
} SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue;

typedef enum SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__state
{
    SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports
} SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__state;

typedef struct SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__state_struct
{
    SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__state state;
    union {
    };
} SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__state_struct;

typedef enum SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__state
{
    SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports
} SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__state;

typedef struct SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__state_struct
{
    SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__state state;
    union {
    };
} SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__state_struct;

typedef enum SSciIoReceive__root__state
{
    SSciIoReceive__root__ReceivingInputAndOutputChannelStates
} SSciIoReceive__root__state;

typedef struct SSciIoReceive__root__ReceivingInputAndOutputChannelStates__state_struct
{
    SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__state_struct
        ReceivingInputChannelStates;
    SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__state_struct
        ReceivingOutputChannelStates;
} SSciIoReceive__root__ReceivingInputAndOutputChannelStates__state_struct;

typedef struct SSciIoReceive__root__state_struct
{
    SSciIoReceive__root__state state;
    union {
        SSciIoReceive__root__ReceivingInputAndOutputChannelStates__state_struct ReceivingInputAndOutputChannelStates;
    };
} SSciIoReceive__root__state_struct;

/// Contained in:
/// Subsystem - Generic IO
/// Functional requirements specification
/// Subsystem - Generic IO - Interfaces
/// SCI-IO (Subsystem - Electronic Interlocking)
/// SCI-IO - Functional Viewpoint
/// SCI-IO - Functional Entities
typedef struct SSciIoReceive
{
    SSciIoReceive__root__state_struct state;

    /// d71out_Reported_Input_Channel_State1
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(SSciIoReceive_D71outReportedInputChannelState1Value, ) D71outReportedInputChannelState1;

    /// d91out_Reported_Output_Channel_Disturbance_State1
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value, )
        D91outReportedOutputChannelDisturbanceState1;

    /// d50in_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(SSciIoReceive_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;

    /// d72out_Reported_Input_Channel_StateN
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(SSciIoReceive_D72outReportedInputChannelStatenValue, ) D72outReportedInputChannelStaten;

    /// d92out_Reported_Output_Channel_Disturbance_StateN
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue, )
        D92outReportedOutputChannelDisturbanceStaten;

    // Messages -- Incoming
    MessagePort(Message__MsgStateOfInputChannels__8132) InMsgStateOfInputChannels__8132;
    MessagePort(Message__MsgStateOfOutputChannels__c6d6) InMsgStateOfOutputChannels__c6d6;
    // Messages -- Outgoing

    // Change Events
    ChangeEvent
        Change297; // d50in_PDI_Connection_State = "DISCONNECTED"OR d50in_PDI_Connection_State = "IMPERMISSIBLE"OR
                   // d50in_PDI_Connection_State = "SUSPENDED"OR d50in_PDI_Connection_State = "REQUESTED_NO_SCP"

    // Timeout Events

} SSciIoReceive;

void transition_SSciIoReceive(SSciIoReceive *self);
void new_SSciIoReceive(SSciIoReceive *x);
