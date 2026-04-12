
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciLsReceive_D50inPdiConnectionStateValue
{
    FSciLsReceive_D50inPdiConnectionStateValue__NULL__,
    FSciLsReceive_D50inPdiConnectionStateValue__NotReadyForPdiNoScp,
    FSciLsReceive_D50inPdiConnectionStateValue__ReadyForPdiNoScp,
    FSciLsReceive_D50inPdiConnectionStateValue__NotReadyForPdi,
    FSciLsReceive_D50inPdiConnectionStateValue__ReadyForPdi,
    FSciLsReceive_D50inPdiConnectionStateValue__Suspended,
    FSciLsReceive_D50inPdiConnectionStateValue__UNKNOWN__
} FSciLsReceive_D50inPdiConnectionStateValue;
typedef enum FSciLsReceive_D2outRequiredSignalAspectValue
{
    FSciLsReceive_D2outRequiredSignalAspectValue__NULL__,
    FSciLsReceive_D2outRequiredSignalAspectValue__Unknown,
    FSciLsReceive_D2outRequiredSignalAspectValue__SignalAspect2,
    FSciLsReceive_D2outRequiredSignalAspectValue__MostRestrictAspect,
    FSciLsReceive_D2outRequiredSignalAspectValue__SignalAspect1,
    FSciLsReceive_D2outRequiredSignalAspectValue__UNKNOWN__
} FSciLsReceive_D2outRequiredSignalAspectValue;
typedef enum FSciLsReceive_D11outRequiredLuminosityValue
{
    FSciLsReceive_D11outRequiredLuminosityValue__NULL__,
    FSciLsReceive_D11outRequiredLuminosityValue__Unknown,
    FSciLsReceive_D11outRequiredLuminosityValue__Day,
    FSciLsReceive_D11outRequiredLuminosityValue__Night,
    FSciLsReceive_D11outRequiredLuminosityValue__UNKNOWN__
} FSciLsReceive_D11outRequiredLuminosityValue;

typedef enum FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__state
{
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects
} FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__state;

typedef struct FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__state_struct
{
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__state state;
    union {
    };
} FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__state_struct;

typedef enum FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__state
{
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark
} FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__state;

typedef struct FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__state_struct
{
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__state state;
    union {
    };
} FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__state_struct;

typedef enum FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__state
{
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity
} FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__state;

typedef struct FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__state_struct
{
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__state state;
    union {
    };
} FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__state_struct;

typedef enum FSciLsReceive__root__state
{
    FSciLsReceive__root__ReceivingLightSignalCommands
} FSciLsReceive__root__state;

typedef struct FSciLsReceive__root__ReceivingLightSignalCommands__state_struct
{
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__state_struct ReceivingSignalAspect;
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__state_struct
        ReceivingIntentionallyDark;
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__state_struct ReceivingLuminosity;
} FSciLsReceive__root__ReceivingLightSignalCommands__state_struct;

typedef struct FSciLsReceive__root__state_struct
{
    FSciLsReceive__root__state state;
    union {
        FSciLsReceive__root__ReceivingLightSignalCommands__state_struct ReceivingLightSignalCommands;
    };
} FSciLsReceive__root__state_struct;

/// Contained in:
/// Subsystem Light Signal
/// Functional requirements specification
/// Subsystem Light Signal - Interfaces
/// SCI-LS (Subsystem - Electronic Interlocking)
/// SCI-LS - Functional Viewpoint
/// SCI-LS - Functional Entities
typedef struct FSciLsReceive
{
    FSciLsReceive__root__state_struct state;

    /// d50in_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciLsReceive_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;

    /// d2out_Required_Signal_Aspect
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FSciLsReceive_D2outRequiredSignalAspectValue, ) D2outRequiredSignalAspect;

    /// d3out_Required_Intentionally_Dark
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D3outRequiredIntentionallyDark;

    /// D4in_Con_Intentionally_Dark
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D4inConIntentionallyDark;

    /// d11out_Required_Luminosity
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FSciLsReceive_D11outRequiredLuminosityValue, ) D11outRequiredLuminosity;

    /// D13in_Luminosity_Day_Fault
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D13inLuminosityDayFault;

    /// D14in_Luminosity_Night_Fault
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D14inLuminosityNightFault;

    /// D4in_Fault_Lamps_Aspect_1
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D4inFaultLampsAspect1;

    /// D5in_Fault_Lamps_Aspect_2
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D5inFaultLampsAspect2;

    /// D6in_Fault_Lamps_Most_Restrict
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D6inFaultLampsMostRestrict;

    // Messages -- Incoming
    MessagePort(Message__CdIndicateSignalAspect__e570) InCdIndicateSignalAspect__e570;
    MessagePort(Message__CdSetLuminosity__4570) InCdSetLuminosity__4570;
    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change311; // D4in_Fault_Lamps_Aspect_1 OR D5in_Fault_Lamps_Aspect_2 OR D6in_Fault_Lamps_Most_Restrict
    ChangeEvent Change581; // NOT D4in_Fault_Lamps_Aspect_1
    ChangeEvent Change584; // NOT D5in_Fault_Lamps_Aspect_2
    ChangeEvent Change587; // NOT D6in_Fault_Lamps_Most_Restrict
    ChangeEvent Change86;  // D13in_Luminosity_Day_Fault OR D14in_Luminosity_Night_Fault
    ChangeEvent Change547; // NOT D13in_Luminosity_Day_Fault
    ChangeEvent Change550; // NOT D14in_Luminosity_Night_Fault
    ChangeEvent Change332; // d50in_PDI_Connection_State = "NOT_READY_FOR_PDI_NO_SCP" OR d50in_PDI_Connection_State =
                           // "READY_FOR_PDI_NO_SCP" OR d50in_PDI_Connection_State = "NOT_READY_FOR_PDI" OR
                           // d50in_PDI_Connection_State = "READY_FOR_PDI" OR d50in_PDI_Connection_State = "SUSPENDED"

    // Timeout Events

} FSciLsReceive;

void transition_FSciLsReceive(FSciLsReceive *self);
void new_FSciLsReceive(FSciLsReceive *x);
