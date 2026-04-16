
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveSignalAspect_D19outObservedSignalAspectValue
{
    FObserveSignalAspect_D19outObservedSignalAspectValue__NULL__,
    FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect2,
    FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect,
    FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect,
    FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect1,
    FObserveSignalAspect_D19outObservedSignalAspectValue__UNKNOWN__
} FObserveSignalAspect_D19outObservedSignalAspectValue;
typedef enum FObserveSignalAspect_D7inSensedSignalAspectValue
{
    FObserveSignalAspect_D7inSensedSignalAspectValue__NULL__,
    FObserveSignalAspect_D7inSensedSignalAspectValue__MostRestrictAspect,
    FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLampFailure,
    FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLuminosityFailure,
    FObserveSignalAspect_D7inSensedSignalAspectValue__SignalAspect1,
    FObserveSignalAspect_D7inSensedSignalAspectValue__SignalAspect2,
    FObserveSignalAspect_D7inSensedSignalAspectValue__UNKNOWN__
} FObserveSignalAspect_D7inSensedSignalAspectValue;
typedef enum FObserveSignalAspect_D51inEstEfesStateValue
{
    FObserveSignalAspect_D51inEstEfesStateValue__NULL__,
    FObserveSignalAspect_D51inEstEfesStateValue__Booting,
    FObserveSignalAspect_D51inEstEfesStateValue__Initialising,
    FObserveSignalAspect_D51inEstEfesStateValue__NoOperatingVoltage,
    FObserveSignalAspect_D51inEstEfesStateValue__FallbackMode,
    FObserveSignalAspect_D51inEstEfesStateValue__UNKNOWN__
} FObserveSignalAspect_D51inEstEfesStateValue;

typedef enum FObserveSignalAspect__root__ObservingSignalAspect__root__state
{
    FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2,
    FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect,
    FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting,
    FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect,
    FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1
} FObserveSignalAspect__root__ObservingSignalAspect__root__state;

typedef struct FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct
{
    FObserveSignalAspect__root__ObservingSignalAspect__root__state state;
    union {
    };
} FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct;

typedef enum FObserveSignalAspect__root__state
{
    FObserveSignalAspect__root__NationalAspect,
    FObserveSignalAspect__root__ObservingSignalAspect
} FObserveSignalAspect__root__state;

typedef struct FObserveSignalAspect__root__ObservingSignalAspect__state_struct
{
    FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct root;
} FObserveSignalAspect__root__ObservingSignalAspect__state_struct;

typedef struct FObserveSignalAspect__root__state_struct
{
    FObserveSignalAspect__root__state state;
    union {
        FObserveSignalAspect__root__ObservingSignalAspect__state_struct ObservingSignalAspect;
    };
} FObserveSignalAspect__root__state_struct;

/// Contained in:
/// Subsystem - Light Signal
/// Functional requirements specification
/// Subsystem - Light Signal - Functional Viewpoint
/// Subsystem - Light Signal - Functional Entities
typedef struct FObserveSignalAspect
{
    FObserveSignalAspect__root__state_struct state;

    /// d19out_Observed_Signal_Aspect
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveSignalAspect_D19outObservedSignalAspectValue, ) D19outObservedSignalAspect;

    /// d20out_Observed_Intentionally_Dark
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D20outObservedIntentionallyDark;

    /// D8in_Sensed_Intentionally_Dark
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D8inSensedIntentionallyDark;

    /// D7in_Sensed_Signal_Aspect
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveSignalAspect_D7inSensedSignalAspectValue, ) D7inSensedSignalAspect;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveSignalAspect_D51inEstEfesStateValue, ) D51inEstEfesState;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change450; // D7in_Sensed_Signal_Aspect = "Most Restrict Aspect"
    ChangeEvent Change454; // D7in_Sensed_Signal_Aspect = "No Signal Aspect - lamp failure" OR D7in_Sensed_Signal_Aspect
                           // = "No Signal Aspect - luminosity failure"
    ChangeEvent Change459; // D7in_Sensed_Signal_Aspect = "Signal Aspect 1"
    ChangeEvent Change486; // D8in_Sensed_Intentionally_Dark
    ChangeEvent Change580; // NOT D8in_Sensed_Intentionally_Dark
    ChangeEvent Change452; // D7in_Sensed_Signal_Aspect = "Most Restrict Aspect"
    ChangeEvent Change457; // D7in_Sensed_Signal_Aspect = "Signal Aspect 1"
    ChangeEvent Change462; // D7in_Sensed_Signal_Aspect = "Signal Aspect 2"
    ChangeEvent Change451; // D7in_Sensed_Signal_Aspect = "Most Restrict Aspect"
    ChangeEvent Change455; // D7in_Sensed_Signal_Aspect = "No Signal Aspect - lamp failure" OR D7in_Sensed_Signal_Aspect
                           // = "No Signal Aspect - luminosity failure"
    ChangeEvent Change453; // D7in_Sensed_Signal_Aspect = "No Signal Aspect - lamp failure" OR D7in_Sensed_Signal_Aspect
                           // = "No Signal Aspect - luminosity failure"
    ChangeEvent Change458; // D7in_Sensed_Signal_Aspect = "Signal Aspect 1"
    ChangeEvent Change460; // D7in_Sensed_Signal_Aspect = "Signal Aspect 2"
    ChangeEvent Change485; // D8in_Sensed_Intentionally_Dark
    ChangeEvent Change579; // NOT D8in_Sensed_Intentionally_Dark
    ChangeEvent Change449; // D7in_Sensed_Signal_Aspect = "Most Restrict Aspect"
    ChangeEvent Change456; // D7in_Sensed_Signal_Aspect = "No Signal Aspect - lamp failure" OR D7in_Sensed_Signal_Aspect
                           // = "No Signal Aspect - luminosity failure"
    ChangeEvent Change461; // D7in_Sensed_Signal_Aspect = "Signal Aspect 2"
    ChangeEvent Change484; // D8in_Sensed_Intentionally_Dark
    ChangeEvent Change581; // NOT D8in_Sensed_Intentionally_Dark
    ChangeEvent Change331; // d51in_EST_EfeS_State = "BOOTING"
    ChangeEvent Change338; // d51in_EST_EfeS_State = "BOOTING" ORd51in_EST_EfeS_State = "INITIALISING"
    ChangeEvent Change373; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR d51in_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events

} FObserveSignalAspect;

void transition_FObserveSignalAspect(FObserveSignalAspect *self);
void new_FObserveSignalAspect(FObserveSignalAspect *x);
