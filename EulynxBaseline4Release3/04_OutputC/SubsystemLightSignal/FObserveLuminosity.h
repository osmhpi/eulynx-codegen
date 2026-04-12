
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveLuminosity_D21outObservedLuminosityValue
{
    FObserveLuminosity_D21outObservedLuminosityValue__NULL__,
    FObserveLuminosity_D21outObservedLuminosityValue__Day,
    FObserveLuminosity_D21outObservedLuminosityValue__Night,
    FObserveLuminosity_D21outObservedLuminosityValue__UNKNOWN__
} FObserveLuminosity_D21outObservedLuminosityValue;
typedef enum FObserveLuminosity_D9inSensedLuminosityValue
{
    FObserveLuminosity_D9inSensedLuminosityValue__NULL__,
    FObserveLuminosity_D9inSensedLuminosityValue__Night,
    FObserveLuminosity_D9inSensedLuminosityValue__Day,
    FObserveLuminosity_D9inSensedLuminosityValue__UNKNOWN__
} FObserveLuminosity_D9inSensedLuminosityValue;
typedef enum FObserveLuminosity_D51inEstEfesStateValue
{
    FObserveLuminosity_D51inEstEfesStateValue__NULL__,
    FObserveLuminosity_D51inEstEfesStateValue__Booting,
    FObserveLuminosity_D51inEstEfesStateValue__Initialising,
    FObserveLuminosity_D51inEstEfesStateValue__NoOperatingVoltage,
    FObserveLuminosity_D51inEstEfesStateValue__UNKNOWN__
} FObserveLuminosity_D51inEstEfesStateValue;

typedef enum FObserveLuminosity__root__ObservingLuminosity__root__state
{
    FObserveLuminosity__root__ObservingLuminosity__root__Day,
    FObserveLuminosity__root__ObservingLuminosity__root__Night,
    FObserveLuminosity__root__ObservingLuminosity__root__Waiting
} FObserveLuminosity__root__ObservingLuminosity__root__state;

typedef struct FObserveLuminosity__root__ObservingLuminosity__root__state_struct
{
    FObserveLuminosity__root__ObservingLuminosity__root__state state;
    union {
    };
} FObserveLuminosity__root__ObservingLuminosity__root__state_struct;

typedef enum FObserveLuminosity__root__state
{
    FObserveLuminosity__root__NoOperatingVoltage,
    FObserveLuminosity__root__ObservingLuminosity
} FObserveLuminosity__root__state;

typedef struct FObserveLuminosity__root__ObservingLuminosity__state_struct
{
    FObserveLuminosity__root__ObservingLuminosity__root__state_struct root;
} FObserveLuminosity__root__ObservingLuminosity__state_struct;

typedef struct FObserveLuminosity__root__state_struct
{
    FObserveLuminosity__root__state state;
    union {
        FObserveLuminosity__root__ObservingLuminosity__state_struct ObservingLuminosity;
    };
} FObserveLuminosity__root__state_struct;

/// Contained in:
/// Subsystem - Light Signal
/// Functional requirements specification
/// Subsystem - Light Signal - Functional Viewpoint
/// Subsystem - Light Signal - Functional Entities
typedef struct FObserveLuminosity
{
    FObserveLuminosity__root__state_struct state;

    /// d21out_Observed_Luminosity
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveLuminosity_D21outObservedLuminosityValue, ) D21outObservedLuminosity;

    /// D9in_Sensed_Luminosity
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveLuminosity_D9inSensedLuminosityValue, ) D9inSensedLuminosity;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveLuminosity_D51inEstEfesStateValue, ) D51inEstEfesState;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change512; // D9in_Sensed_Luminosity = "Night"
    ChangeEvent Change509; // D9in_Sensed_Luminosity = "Day"
    ChangeEvent Change510; // D9in_Sensed_Luminosity = "Day"
    ChangeEvent Change511; // D9in_Sensed_Luminosity = "Night"
    ChangeEvent Change327; // d51in_EST_EfeS_State = "BOOTING"
    ChangeEvent Change339; // d51in_EST_EfeS_State = "BOOTING" ORd51in_EST_EfeS_State = "INITIALISING"
    ChangeEvent Change366; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE"

    // Timeout Events

} FObserveLuminosity;

void transition_FObserveLuminosity(FObserveLuminosity *self);
void new_FObserveLuminosity(FObserveLuminosity *x);
