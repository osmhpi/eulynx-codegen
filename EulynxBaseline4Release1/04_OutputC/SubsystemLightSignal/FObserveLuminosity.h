
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
typedef enum FObserveLuminosity_D22inSensedLuminosityValue
{
    FObserveLuminosity_D22inSensedLuminosityValue__NULL__,
    FObserveLuminosity_D22inSensedLuminosityValue__Night,
    FObserveLuminosity_D22inSensedLuminosityValue__Day,
    FObserveLuminosity_D22inSensedLuminosityValue__UNKNOWN__
} FObserveLuminosity_D22inSensedLuminosityValue;
typedef enum FObserveLuminosity_D51inEstEfesStateValue
{
    FObserveLuminosity_D51inEstEfesStateValue__NULL__,
    FObserveLuminosity_D51inEstEfesStateValue__Booting,
    FObserveLuminosity_D51inEstEfesStateValue__Initialising,
    FObserveLuminosity_D51inEstEfesStateValue__NoOperatingVoltage,
    FObserveLuminosity_D51inEstEfesStateValue__UNKNOWN__
} FObserveLuminosity_D51inEstEfesStateValue;
typedef enum FObserveLuminosity_D15inRespondedLuminosityValue
{
    FObserveLuminosity_D15inRespondedLuminosityValue__NULL__,
    FObserveLuminosity_D15inRespondedLuminosityValue__Night,
    FObserveLuminosity_D15inRespondedLuminosityValue__Day,
    FObserveLuminosity_D15inRespondedLuminosityValue__UNKNOWN__
} FObserveLuminosity_D15inRespondedLuminosityValue;

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
/// Subsystem Light Signal
/// Functional requirements specification
/// Subsystem Light Signal - Functional Viewpoint
/// Subsystem Light Signal - Functional Entities
typedef struct FObserveLuminosity
{
    FObserveLuminosity__root__state_struct state;

    /// d21out_Observed_Luminosity
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveLuminosity_D21outObservedLuminosityValue, ) D21outObservedLuminosity;

    /// D22in_Sensed_Luminosity
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveLuminosity_D22inSensedLuminosityValue, ) D22inSensedLuminosity;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveLuminosity_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// d15in_Responded_Luminosity
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveLuminosity_D15inRespondedLuminosityValue, ) D15inRespondedLuminosity;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change85;  // d15in_Responded_Luminosity = "Night"
    ChangeEvent Change172; // D22in_Sensed_Luminosity = "Night"
    ChangeEvent Change84;  // d15in_Responded_Luminosity = "Day"
    ChangeEvent Change171; // D22in_Sensed_Luminosity = "Day"
    ChangeEvent Change170; // D22in_Sensed_Luminosity = "Day"
    ChangeEvent Change173; // D22in_Sensed_Luminosity = "Night"
    ChangeEvent Change345; // d51in_EST_EfeS_State = "BOOTING"
    ChangeEvent Change353; // d51in_EST_EfeS_State = "BOOTING" ORd51in_EST_EfeS_State = "INITIALISING"
    ChangeEvent Change381; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE"

    // Timeout Events

} FObserveLuminosity;

void transition_FObserveLuminosity(FObserveLuminosity *self);
void new_FObserveLuminosity(FObserveLuminosity *x);
