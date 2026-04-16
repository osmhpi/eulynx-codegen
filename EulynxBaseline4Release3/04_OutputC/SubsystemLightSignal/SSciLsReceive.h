
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciLsReceive_D26outSignalAspectValue
{
    SSciLsReceive_D26outSignalAspectValue__NULL__,
    SSciLsReceive_D26outSignalAspectValue__SignalAspect1,
    SSciLsReceive_D26outSignalAspectValue__SignalAspect2,
    SSciLsReceive_D26outSignalAspectValue__MostRestrictAspect,
    SSciLsReceive_D26outSignalAspectValue__NoSignalAspect,
    SSciLsReceive_D26outSignalAspectValue__UNKNOWN__
} SSciLsReceive_D26outSignalAspectValue;
typedef enum SSciLsReceive_D28outLuminosityValue
{
    SSciLsReceive_D28outLuminosityValue__NULL__,
    SSciLsReceive_D28outLuminosityValue__Night,
    SSciLsReceive_D28outLuminosityValue__Day,
    SSciLsReceive_D28outLuminosityValue__UNKNOWN__
} SSciLsReceive_D28outLuminosityValue;

typedef enum SSciLsReceive__root__state
{
    SSciLsReceive__root__ReceivingLightSignalReports
} SSciLsReceive__root__state;

typedef struct SSciLsReceive__root__state_struct
{
    SSciLsReceive__root__state state;
    union {
    };
} SSciLsReceive__root__state_struct;

/// Contained in:
/// Subsystem - Light Signal
/// Functional requirements specification
/// Subsystem - Light Signal - Interfaces
/// SCI-LS (Subsystem - Electronic Interlocking)
/// SCI-LS - Functional Viewpoint
/// SCI-LS - Functional Entities
typedef struct SSciLsReceive
{
    SSciLsReceive__root__state_struct state;

    /// d9_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: False, Out: False, External: False
    DataPort(void *, ) D9PdiConnectionState;

    /// d26out_Signal_Aspect
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(SSciLsReceive_D26outSignalAspectValue, ) D26outSignalAspect;

    /// d27out_Intentionally_Dark
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D27outIntentionallyDark;

    /// d28out_Luminosity
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(SSciLsReceive_D28outLuminosityValue, ) D28outLuminosity;

    // Messages -- Incoming
    MessagePort(Message__MsgIndicatedSignalAspect__e129) InMsgIndicatedSignalAspect__e129;
    MessagePort(Message__MsgSetLuminosity__c2b4) InMsgSetLuminosity__c2b4;
    // Messages -- Outgoing

    // Change Events

    // Timeout Events

} SSciLsReceive;

void transition_SSciLsReceive(SSciLsReceive *self);
void new_SSciLsReceive(SSciLsReceive *x);
