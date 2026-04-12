
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FControlSignalAspect_D2inRequiredSignalAspectValue
{
    FControlSignalAspect_D2inRequiredSignalAspectValue__NULL__,
    FControlSignalAspect_D2inRequiredSignalAspectValue__MostRestrictAspect,
    FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1,
    FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2,
    FControlSignalAspect_D2inRequiredSignalAspectValue__UNKNOWN__
} FControlSignalAspect_D2inRequiredSignalAspectValue;
typedef enum FControlSignalAspect_D7outSetSignalAspectValue
{
    FControlSignalAspect_D7outSetSignalAspectValue__NULL__,
    FControlSignalAspect_D7outSetSignalAspectValue__NationalAspect,
    FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect2,
    FControlSignalAspect_D7outSetSignalAspectValue__MostRestrictAspect,
    FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspectLampFailure,
    FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect1,
    FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspect,
    FControlSignalAspect_D7outSetSignalAspectValue__UNKNOWN__
} FControlSignalAspect_D7outSetSignalAspectValue;
typedef enum FControlSignalAspect_D9inSetLuminosityValue
{
    FControlSignalAspect_D9inSetLuminosityValue__NULL__,
    FControlSignalAspect_D9inSetLuminosityValue__Undefined,
    FControlSignalAspect_D9inSetLuminosityValue__UNKNOWN__
} FControlSignalAspect_D9inSetLuminosityValue;
typedef enum FControlSignalAspect_D51inEstEfesStateValue
{
    FControlSignalAspect_D51inEstEfesStateValue__NULL__,
    FControlSignalAspect_D51inEstEfesStateValue__Booting,
    FControlSignalAspect_D51inEstEfesStateValue__Initialising,
    FControlSignalAspect_D51inEstEfesStateValue__NoOperatingVoltage,
    FControlSignalAspect_D51inEstEfesStateValue__FallbackMode,
    FControlSignalAspect_D51inEstEfesStateValue__UNKNOWN__
} FControlSignalAspect_D51inEstEfesStateValue;
typedef enum FControlSignalAspect_MemSetAspectValue
{
    FControlSignalAspect_MemSetAspectValue__NULL__,
    FControlSignalAspect_MemSetAspectValue__,
    FControlSignalAspect_MemSetAspectValue__SignalAspect2,
    FControlSignalAspect_MemSetAspectValue__MostRestrictAspect,
    FControlSignalAspect_MemSetAspectValue__NoSignalAspectLampFailure,
    FControlSignalAspect_MemSetAspectValue__SignalAspect1,
    FControlSignalAspect_MemSetAspectValue__UNKNOWN__
} FControlSignalAspect_MemSetAspectValue;

typedef enum FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state
{
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2,
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect,
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure,
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1
} FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state;

typedef struct FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct
{
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state state;
    union {
    };
} FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct;

typedef enum FControlSignalAspect__root__OperatingVoltage__root__state
{
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect,
    FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspect
} FControlSignalAspect__root__OperatingVoltage__root__state;

typedef struct FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__state_struct
{
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct root;
} FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__state_struct;

typedef struct FControlSignalAspect__root__OperatingVoltage__root__state_struct
{
    FControlSignalAspect__root__OperatingVoltage__root__state state;
    union {
        FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__state_struct
            ControllingSignalAspect;
    };
} FControlSignalAspect__root__OperatingVoltage__root__state_struct;

typedef enum FControlSignalAspect__root__state
{
    FControlSignalAspect__root__NationalAspect,
    FControlSignalAspect__root__OperatingVoltage
} FControlSignalAspect__root__state;

typedef struct FControlSignalAspect__root__OperatingVoltage__state_struct
{
    FControlSignalAspect__root__OperatingVoltage__root__state_struct root;
} FControlSignalAspect__root__OperatingVoltage__state_struct;

typedef struct FControlSignalAspect__root__state_struct
{
    FControlSignalAspect__root__state state;
    union {
        FControlSignalAspect__root__OperatingVoltage__state_struct OperatingVoltage;
    };
} FControlSignalAspect__root__state_struct;

/// Contained in:
/// Subsystem Light Signal
/// Functional requirements specification
/// Subsystem Light Signal - Functional Viewpoint
/// Subsystem Light Signal - Functional Entities
typedef struct FControlSignalAspect
{
    FControlSignalAspect__root__state_struct state;

    /// d3in_Required_Intentionally_Dark
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D3inRequiredIntentionallyDark;

    /// d2in_Required_Signal_Aspect
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlSignalAspect_D2inRequiredSignalAspectValue, ) D2inRequiredSignalAspect;

    /// D4in_Fault_Lamps_Aspect_1
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D4inFaultLampsAspect1;

    /// D5in_Fault_Lamps_Aspect_2
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D5inFaultLampsAspect2;

    /// D6in_Fault_Lamps_Most_Restrict
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D6inFaultLampsMostRestrict;

    /// D7out_Set_Signal_Aspect
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(FControlSignalAspect_D7outSetSignalAspectValue, ) D7outSetSignalAspect;

    /// D8out_Set_Intentionally_Dark
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(bool, ) D8outSetIntentionallyDark;

    /// d9in_Set_Luminosity
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlSignalAspect_D9inSetLuminosityValue, ) D9inSetLuminosity;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlSignalAspect_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// D10in_Con_Downgrade_Most_Restrict
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D10inConDowngradeMostRestrict;

    /// Mem_Set_Aspect
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FControlSignalAspect_MemSetAspectValue MemSetAspect;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change193; // d2in_Required_Signal_Aspect = "Most Restrict Aspect" OR D5in_Fault_Lamps_Aspect_2
    ChangeEvent Change195; // d2in_Required_Signal_Aspect = "Most Restrict Aspect" OR D5in_Fault_Lamps_Aspect_2
    ChangeEvent Change201; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
    ChangeEvent Change200; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
    ChangeEvent Change202; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
    ChangeEvent Change274; // d3in_Required_Intentionally_Dark
    ChangeEvent Change574; // NOT d3in_Required_Intentionally_Dark
    ChangeEvent Change197; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
    ChangeEvent Change204; // d2in_Required_Signal_Aspect = "Signal Aspect 2"
    ChangeEvent Change199; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
    ChangeEvent Change449; // D6in_Fault_Lamps_Most_Restrict
    ChangeEvent Change273; // d3in_Required_Intentionally_Dark
    ChangeEvent Change572; // NOT d3in_Required_Intentionally_Dark
    ChangeEvent Change198; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
    ChangeEvent Change206; // d2in_Required_Signal_Aspect = "Signal Aspect 2"
    ChangeEvent Change203; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
    ChangeEvent Change586; // NOT D6in_Fault_Lamps_Most_Restrict
    ChangeEvent Change196; // d2in_Required_Signal_Aspect = "Most Restrict Aspect"
    ChangeEvent Change194; // d2in_Required_Signal_Aspect = "Most Restrict Aspect"
    ChangeEvent Change208; // d2in_Required_Signal_Aspect = "Signal Aspect 2"
    ChangeEvent Change205; // d2in_Required_Signal_Aspect = "Signal Aspect 2"
    ChangeEvent Change207; // d2in_Required_Signal_Aspect = "Signal Aspect 2"
    ChangeEvent Change306; // D4in_Fault_Lamps_Aspect_1
    ChangeEvent Change304; // D4in_Fault_Lamps_Aspect_1
    ChangeEvent Change305; // D4in_Fault_Lamps_Aspect_1
    ChangeEvent Change272; // d3in_Required_Intentionally_Dark
    ChangeEvent Change573; // NOT d3in_Required_Intentionally_Dark
    ChangeEvent Change524; // d9in_Set_Luminosity = "Undefined"
    ChangeEvent Change344; // d51in_EST_EfeS_State = "BOOTING"
    ChangeEvent Change352; // d51in_EST_EfeS_State = "BOOTING" ORd51in_EST_EfeS_State = "INITIALISING"
    ChangeEvent Change386; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR d51in_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events

} FControlSignalAspect;

void transition_FControlSignalAspect(FControlSignalAspect *self);
void new_FControlSignalAspect(FControlSignalAspect *x);
