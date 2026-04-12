
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciLsCommand_D9PdiConnectionStateValue
{
    SSciLsCommand_D9PdiConnectionStateValue__NULL__,
    SSciLsCommand_D9PdiConnectionStateValue__Established,
    SSciLsCommand_D9PdiConnectionStateValue__UNKNOWN__
} SSciLsCommand_D9PdiConnectionStateValue;
typedef enum SSciLsCommand_D23inSignalAspectValue
{
    SSciLsCommand_D23inSignalAspectValue__NULL__,
    SSciLsCommand_D23inSignalAspectValue__SignalAspect2,
    SSciLsCommand_D23inSignalAspectValue__MostRestrictAspect,
    SSciLsCommand_D23inSignalAspectValue__SignalAspect1,
    SSciLsCommand_D23inSignalAspectValue__UNKNOWN__
} SSciLsCommand_D23inSignalAspectValue;
typedef enum SSciLsCommand_D25inLuminosityValue
{
    SSciLsCommand_D25inLuminosityValue__NULL__,
    SSciLsCommand_D25inLuminosityValue__Night,
    SSciLsCommand_D25inLuminosityValue__Day,
    SSciLsCommand_D25inLuminosityValue__UNKNOWN__
} SSciLsCommand_D25inLuminosityValue;

typedef enum SSciLsCommand__root__state
{
    SSciLsCommand__root__SendingCommands
} SSciLsCommand__root__state;

typedef struct SSciLsCommand__root__state_struct
{
    SSciLsCommand__root__state state;
    union {
    };
} SSciLsCommand__root__state_struct;

/// Contained in:
/// Subsystem Light Signal
/// Functional requirements specification
/// Subsystem Light Signal - Interfaces
/// SCI-LS (Subsystem - Electronic Interlocking)
/// SCI-LS - Functional Viewpoint
/// SCI-LS - Functional Entities
typedef struct SSciLsCommand
{
    SSciLsCommand__root__state_struct state;

    /// d9_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: False, Out: False, External: False
    DataPort(SSciLsCommand_D9PdiConnectionStateValue, ) D9PdiConnectionState;

    /// d24in_Intentionally_Dark
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D24inIntentionallyDark;

    /// d23in_Signal_Aspect
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(SSciLsCommand_D23inSignalAspectValue, ) D23inSignalAspect;

    /// d25in_Luminosity
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(SSciLsCommand_D25inLuminosityValue, ) D25inLuminosity;

    /// t23in_Signal_Aspect
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T23inSignalAspect;

    /// t25in_Luminosity
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T25inLuminosity;

    // Messages -- Incoming

    // Messages -- Outgoing
    MessagePort(Message__CdIndicateSignalAspect__e570) OutCdIndicateSignalAspect__e570;
    MessagePort(Message__CdSetLuminosity__4570) OutCdSetLuminosity__4570;

    // Change Events
    ChangeEvent Change1006; // t23in_Signal_Aspect
    ChangeEvent Change1004; // t23in_Signal_Aspect
    ChangeEvent Change1005; // t23in_Signal_Aspect
    ChangeEvent Change1016; // t25in_Luminosity
    ChangeEvent Change1018; // t25in_Luminosity

    // Timeout Events

} SSciLsCommand;

void transition_SSciLsCommand(SSciLsCommand *self);
void new_SSciLsCommand(SSciLsCommand *x);
