
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciLsCommandExpl_D9PdiConnectionStateValue
{
    SSciLsCommandExpl_D9PdiConnectionStateValue__NULL__,
    SSciLsCommandExpl_D9PdiConnectionStateValue__Established,
    SSciLsCommandExpl_D9PdiConnectionStateValue__UNKNOWN__
} SSciLsCommandExpl_D9PdiConnectionStateValue;
typedef enum SSciLsCommandExpl_D23inSignalAspectValue
{
    SSciLsCommandExpl_D23inSignalAspectValue__NULL__,
    SSciLsCommandExpl_D23inSignalAspectValue__SignalAspect2,
    SSciLsCommandExpl_D23inSignalAspectValue__MostRestrictAspect,
    SSciLsCommandExpl_D23inSignalAspectValue__SignalAspect1,
    SSciLsCommandExpl_D23inSignalAspectValue__UNKNOWN__
} SSciLsCommandExpl_D23inSignalAspectValue;
typedef enum SSciLsCommandExpl_D25inLuminosityValue
{
    SSciLsCommandExpl_D25inLuminosityValue__NULL__,
    SSciLsCommandExpl_D25inLuminosityValue__Night,
    SSciLsCommandExpl_D25inLuminosityValue__Day,
    SSciLsCommandExpl_D25inLuminosityValue__UNKNOWN__
} SSciLsCommandExpl_D25inLuminosityValue;

typedef enum SSciLsCommandExpl__root__state
{
    SSciLsCommandExpl__root__SendingCommands
} SSciLsCommandExpl__root__state;

typedef struct SSciLsCommandExpl__root__state_struct
{
    SSciLsCommandExpl__root__state state;
    union {
    };
} SSciLsCommandExpl__root__state_struct;

/// Contained in:
/// Subsystem Light Signal
typedef struct SSciLsCommandExpl
{
    SSciLsCommandExpl__root__state_struct state;

    /// d9_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: False, Out: False, External: False
    DataPort(SSciLsCommandExpl_D9PdiConnectionStateValue, ) D9PdiConnectionState;

    /// d24in_Intentionally_Dark
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D24inIntentionallyDark;

    /// d23in_Signal_Aspect
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(SSciLsCommandExpl_D23inSignalAspectValue, ) D23inSignalAspect;

    /// d25in_Luminosity
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(SSciLsCommandExpl_D25inLuminosityValue, ) D25inLuminosity;

    /// t23in_Signal_Aspect
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T23inSignalAspect;

    /// t25in_Luminosity
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T25inLuminosity;

    /// T5_Signal_Aspect
    /// Trigger: True, DataPort: False, In: False, Out: False, External: True
    PulsedIn T5SignalAspect;

    /// T6_Luminosity
    /// Trigger: True, DataPort: False, In: False, Out: False, External: True
    PulsedIn T6Luminosity;

    // Messages -- Incoming

    // Messages -- Outgoing
    MessagePort(Message__CdIndicateSignalAspect__e570) OutCdIndicateSignalAspect__e570;
    MessagePort(Message__CdSetLuminosity__4570) OutCdSetLuminosity__4570;

    // Change Events
    ChangeEvent Change1003; // t23in_Signal_Aspect
    ChangeEvent Change1007; // t23in_Signal_Aspect
    ChangeEvent Change1008; // t23in_Signal_Aspect
    ChangeEvent Change1015; // t25in_Luminosity
    ChangeEvent Change1017; // t25in_Luminosity

    // Timeout Events

} SSciLsCommandExpl;

void transition_SSciLsCommandExpl(SSciLsCommandExpl *self);
void new_SSciLsCommandExpl(SSciLsCommandExpl *x);
