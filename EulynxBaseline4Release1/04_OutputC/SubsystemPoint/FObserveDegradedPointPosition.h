
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveDegradedPointPosition_D10inPm1CrucialPositionValue
{
    FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__NULL__,
    FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Left,
    FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Right,
    FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__NoEndPosition,
    FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Trailed,
    FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D10inPm1CrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D10inPm1nCrucialPositionValue
{
    FObserveDegradedPointPosition_D10inPm1nCrucialPositionValue__NULL__,
    FObserveDegradedPointPosition_D10inPm1nCrucialPositionValue__Left,
    FObserveDegradedPointPosition_D10inPm1nCrucialPositionValue__Right,
    FObserveDegradedPointPosition_D10inPm1nCrucialPositionValue__NoEndPosition,
    FObserveDegradedPointPosition_D10inPm1nCrucialPositionValue__Trailed,
    FObserveDegradedPointPosition_D10inPm1nCrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D10inPm1nCrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D51inEstEfesStateValue
{
    FObserveDegradedPointPosition_D51inEstEfesStateValue__NULL__,
    FObserveDegradedPointPosition_D51inEstEfesStateValue__Initialising,
    FObserveDegradedPointPosition_D51inEstEfesStateValue__NoOperatingVoltage,
    FObserveDegradedPointPosition_D51inEstEfesStateValue__Booting,
    FObserveDegradedPointPosition_D51inEstEfesStateValue__FallbackMode,
    FObserveDegradedPointPosition_D51inEstEfesStateValue__UNKNOWN__
} FObserveDegradedPointPosition_D51inEstEfesStateValue;
typedef enum FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue
{
    FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue__NULL__,
    FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue__NoEndPosition,
    FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue__Trailed,
    FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue__Right,
    FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue__Left,
    FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D4outObservedDegradedPointPositionValue
{
    FObserveDegradedPointPosition_D4outObservedDegradedPointPositionValue__NULL__,
    FObserveDegradedPointPosition_D4outObservedDegradedPointPositionValue__DegradedRight,
    FObserveDegradedPointPosition_D4outObservedDegradedPointPositionValue__NotDegraded,
    FObserveDegradedPointPosition_D4outObservedDegradedPointPositionValue__DegradedLeft,
    FObserveDegradedPointPosition_D4outObservedDegradedPointPositionValue__DegradedDenied,
    FObserveDegradedPointPosition_D4outObservedDegradedPointPositionValue__Undefined,
    FObserveDegradedPointPosition_D4outObservedDegradedPointPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D4outObservedDegradedPointPositionValue;
typedef enum FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue
{
    FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue__NULL__,
    FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue__NoEndPosition,
    FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue__Trailed,
    FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue__Right,
    FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue__Left,
    FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D5inObservedPointPositionValue
{
    FObserveDegradedPointPosition_D5inObservedPointPositionValue__NULL__,
    FObserveDegradedPointPosition_D5inObservedPointPositionValue__Left,
    FObserveDegradedPointPosition_D5inObservedPointPositionValue__Right,
    FObserveDegradedPointPosition_D5inObservedPointPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D5inObservedPointPositionValue;

typedef enum FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state
{
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation,
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight,
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded,
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft,
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied
} FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state;

typedef struct FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct
{
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state state;
    union {
    };
} FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct;

typedef enum FObserveDegradedPointPosition__root__state
{
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition
} FObserveDegradedPointPosition__root__state;

typedef struct FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__state_struct
{
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct root;
} FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__state_struct;

typedef struct FObserveDegradedPointPosition__root__state_struct
{
    FObserveDegradedPointPosition__root__state state;
    union {
        FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__state_struct ObserveDegradedPointPosition;
    };
} FObserveDegradedPointPosition__root__state_struct;

/// Contained in:
/// Subsystem Point
/// Functional requirements specification
/// Subsystem Point - Functional Viewpoint
/// Subsystem Point - Functional Entities
typedef struct FObserveDegradedPointPosition
{
    FObserveDegradedPointPosition__root__state_struct state;

    /// D10in_PM1_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveDegradedPointPosition_D10inPm1CrucialPositionValue, ) D10inPm1CrucialPosition;

    /// D10in_PM1n_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveDegradedPointPosition_D10inPm1nCrucialPositionValue, ) D10inPm1nCrucialPosition;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveDegradedPointPosition_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// D8in_Con_PM2_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D8inConPm2NonCrucialActivation;

    /// D10in_PM2n_Non_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue, ) D10inPm2nNonCrucialPosition;

    /// d4out_Observed_Degraded_Point_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveDegradedPointPosition_D4outObservedDegradedPointPositionValue, )
        D4outObservedDegradedPointPosition;

    /// D10in_PM2_Non_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue, ) D10inPm2NonCrucialPosition;

    /// D9in_Con_PM2n_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D9inConPm2nNonCrucialActivation;

    /// D7in_Con_PM1n_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D7inConPm1nCrucialActivation;

    /// d5in_Observed_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveDegradedPointPosition_D5inObservedPointPositionValue, ) D5inObservedPointPosition;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change375; // d51in_EST_EfeS_State = "INITIALISING"
    ChangeEvent
        Change8; // (d5in_Observed_Point_Position = "LEFT" OR d5in_Observed_Point_Position = "RIGHT") OR
                 // ((D10in_PM1_Crucial_Position <> D10in_PM1n_Crucial_Position) AND D7in_Con_PM1n_Crucial_Activation)
                 // OR ((D10in_PM2_Non_Crucial_Position <> D10in_PM1_Crucial_Position AND D10in_PM2_Non_Crucial_Position
                 // <> "TRAILED" AND D10in_PM2_Non_Crucial_Position <> "NO_END_POSITION")AND
                 // D8in_Con_PM2_Non_Crucial_Activation) OR ((D10in_PM2n_Non_Crucial_Position <>
                 // D10in_PM1_Crucial_Position AND D10in_PM2n_Non_Crucial_Position <> "TRAILED" AND
                 // D10in_PM2n_Non_Crucial_Position <> "NO_END_POSITION")AND D9in_Con_PM2n_Non_Crucial_Activation)
    ChangeEvent Change25; // D10in_PM1_Crucial_Position = "LEFT" AND (D10in_PM1n_Crucial_Position = "LEFT" OR NOT
                          // D7in_Con_PM1n_Crucial_Activation) AND ((D10in_PM2n_Non_Crucial_Position = "NO_END_POSITION"
                          // OR D10in_PM2n_Non_Crucial_Position = "TRAILED") OR (D10in_PM2_Non_Crucial_Position =
                          // "NO_END_POSITION" OR D10in_PM2_Non_Crucial_Position = "TRAILED"))
    ChangeEvent
        Change24; // D10in_PM1_Crucial_Position = "LEFT" AND (D10in_PM1n_Crucial_Position = "LEFT" OR NOT
                  // D7in_Con_PM1n_Crucial_Activation) AND ((((D10in_PM2n_Non_Crucial_Position = "NO_END_POSITION" OR
                  // D10in_PM2n_Non_Crucial_Position = "TRAILED") AND D10in_PM2_Non_Crucial_Position <> "RIGHT")) OR
                  // (((D10in_PM2_Non_Crucial_Position = "NO_END_POSITION" OR D10in_PM2_Non_Crucial_Position =
                  // "TRAILED") AND D10in_PM2n_Non_Crucial_Position <> "RIGHT")))
    ChangeEvent
        Change27; // D10in_PM1_Crucial_Position = "RIGHT" AND (D10in_PM1n_Crucial_Position = "RIGHT" OR NOT
                  // D7in_Con_PM1n_Crucial_Activation) AND ((((D10in_PM2n_Non_Crucial_Position = "NO_END_POSITION" OR
                  // D10in_PM2n_Non_Crucial_Position = "TRAILED") AND D10in_PM2_Non_Crucial_Position <> "LEFT")) OR
                  // (((D10in_PM2_Non_Crucial_Position = "NO_END_POSITION" OR D10in_PM2_Non_Crucial_Position =
                  // "TRAILED") AND D10in_PM2n_Non_Crucial_Position <> "LEFT")))
    ChangeEvent
        Change9; // (d5in_Observed_Point_Position = "LEFT" OR d5in_Observed_Point_Position = "RIGHT") OR
                 // ((D10in_PM1_Crucial_Position <> D10in_PM1n_Crucial_Position) AND D7in_Con_PM1n_Crucial_Activation)
                 // OR ((D10in_PM2_Non_Crucial_Position <> D10in_PM1_Crucial_Position AND D10in_PM2_Non_Crucial_Position
                 // <> "TRAILED" AND D10in_PM2_Non_Crucial_Position <> "NO_END_POSITION")AND
                 // D8in_Con_PM2_Non_Crucial_Activation) OR((D10in_PM2n_Non_Crucial_Position <>
                 // D10in_PM1_Crucial_Position AND D10in_PM2n_Non_Crucial_Position <> "TRAILED" AND
                 // D10in_PM2n_Non_Crucial_Position <> "NO_END_POSITION")AND D9in_Con_PM2n_Non_Crucial_Activation)
    ChangeEvent Change26; // D10in_PM1_Crucial_Position = "RIGHT" AND (D10in_PM1n_Crucial_Position = "RIGHT" OR NOT
                          // D7in_Con_PM1n_Crucial_Activation) AND ((D10in_PM2n_Non_Crucial_Position = "NO_END_POSITION"
                          // OR D10in_PM2n_Non_Crucial_Position = "TRAILED") OR (D10in_PM2_Non_Crucial_Position =
                          // "NO_END_POSITION" OR D10in_PM2_Non_Crucial_Position = "TRAILED"))
    ChangeEvent Change384; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR d51in_EST_EfeS_State = "BOOTING" OR
                           // d51in_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events

} FObserveDegradedPointPosition;

void transition_FObserveDegradedPointPosition(FObserveDegradedPointPosition *self);
void new_FObserveDegradedPointPosition(FObserveDegradedPointPosition *x);
