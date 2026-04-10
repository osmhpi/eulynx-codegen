
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FControlLuminosity_D9outSetLuminosityValue
{
    FControlLuminosity_D9outSetLuminosityValue__NULL__,
    FControlLuminosity_D9outSetLuminosityValue__Night,
    FControlLuminosity_D9outSetLuminosityValue__Day,
    FControlLuminosity_D9outSetLuminosityValue__Undefined,
    FControlLuminosity_D9outSetLuminosityValue__UNKNOWN__
} FControlLuminosity_D9outSetLuminosityValue;
typedef enum FControlLuminosity_D51inEstEfesStateValue
{
    FControlLuminosity_D51inEstEfesStateValue__NULL__,
    FControlLuminosity_D51inEstEfesStateValue__Operational,
    FControlLuminosity_D51inEstEfesStateValue__Booting,
    FControlLuminosity_D51inEstEfesStateValue__Initialising,
    FControlLuminosity_D51inEstEfesStateValue__NoOperatingVoltage,
    FControlLuminosity_D51inEstEfesStateValue__UNKNOWN__
} FControlLuminosity_D51inEstEfesStateValue;
typedef enum FControlLuminosity_D11inRequiredLuminosityValue
{
    FControlLuminosity_D11inRequiredLuminosityValue__NULL__,
    FControlLuminosity_D11inRequiredLuminosityValue__Day,
    FControlLuminosity_D11inRequiredLuminosityValue__Night,
    FControlLuminosity_D11inRequiredLuminosityValue__UNKNOWN__
} FControlLuminosity_D11inRequiredLuminosityValue;

typedef enum FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__state
{
    FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night,
    FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day,
    FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined
} FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__state;

typedef struct FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__state_struct
{
    FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__state state;
    union {
    };
} FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__state_struct;

typedef enum FControlLuminosity__root__OperatingVoltage__root__state
{
    FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity
} FControlLuminosity__root__OperatingVoltage__root__state;

typedef struct FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__state_struct
{
    FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__state_struct root;
} FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__state_struct;

typedef struct FControlLuminosity__root__OperatingVoltage__root__state_struct
{
    FControlLuminosity__root__OperatingVoltage__root__state state;
    union {
        FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__state_struct ControllingLuminosity;
    };
} FControlLuminosity__root__OperatingVoltage__root__state_struct;

typedef enum FControlLuminosity__root__state
{
    FControlLuminosity__root__NoOperatingVoltage,
    FControlLuminosity__root__OperatingVoltage
} FControlLuminosity__root__state;

typedef struct FControlLuminosity__root__OperatingVoltage__state_struct
{
    FControlLuminosity__root__OperatingVoltage__root__state_struct root;
} FControlLuminosity__root__OperatingVoltage__state_struct;

typedef struct FControlLuminosity__root__state_struct
{
    FControlLuminosity__root__state state;
    union {
        FControlLuminosity__root__OperatingVoltage__state_struct OperatingVoltage;
    };
} FControlLuminosity__root__state_struct;

/// Contained in:
/// Subsystem - Light Signal
/// Functional requirements specification
/// Subsystem - Light Signal - Functional Viewpoint
/// Subsystem - Light Signal - Functional Entities
typedef struct FControlLuminosity
{
    FControlLuminosity__root__state_struct state;

    /// D12in_Con_Luminosity
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D12inConLuminosity;

    /// D13in_Luminosity_Day_Fault
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D13inLuminosityDayFault;

    /// D14in_Luminosity_Night_Fault
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D14inLuminosityNightFault;

    /// T5out_SIL_Not_Fulfilled
    /// Trigger: True, DataPort: False, In: False, Out: True, External: True
    PulsedOut T5outSilNotFulfilled;

    /// D16in_Luminosity_Set_Unchangeable
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D16inLuminositySetUnchangeable;

    /// D9out_Set_Luminosity
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(FControlLuminosity_D9outSetLuminosityValue, ) D9outSetLuminosity;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlLuminosity_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// d11in_Required_Luminosity
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlLuminosity_D11inRequiredLuminosityValue, ) D11inRequiredLuminosity;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change109; // D14in_Luminosity_Night_Fault
    ChangeEvent Change110; // D14in_Luminosity_Night_Fault
    ChangeEvent Change111; // D14in_Luminosity_Night_Fault OR
                           // d11in_Required_Luminosity = "Day"
    ChangeEvent Change91;  // D13in_Luminosity_Day_Fault
    ChangeEvent Change92;  // D13in_Luminosity_Day_Fault
    ChangeEvent Change93;  // D13in_Luminosity_Day_Fault OR
                           // d11in_Required_Luminosity = "Night"
    ChangeEvent Change540; // NOT D13in_Luminosity_Day_Fault
    ChangeEvent Change545; // NOT D14in_Luminosity_Night_Fault
    ChangeEvent Change342; // d51in_EST_EfeS_State = "BOOTING" OR
                           // d51in_EST_EfeS_State = "INITIALISING"
    ChangeEvent Change333; // d51in_EST_EfeS_State = "BOOTING"
    ChangeEvent Change363; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE"

    // Timeout Events

} FControlLuminosity;

void transition_FControlLuminosity(FControlLuminosity *self);
void new_FControlLuminosity(FControlLuminosity *x);
