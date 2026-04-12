
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveDegradedPointPosition_D22inPm1CrucialPositionValue
{
    FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__NULL__,
    FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Left,
    FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Right,
    FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__NoEndPosition,
    FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__UnintendedPosition,
    FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D22inPm1CrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue
{
    FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__NULL__,
    FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__Left,
    FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__Right,
    FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__NoEndPosition,
    FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__UnintendedPosition,
    FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue
{
    FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NULL__,
    FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NoEndPosition,
    FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition,
    FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__Right,
    FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__Left,
    FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue
{
    FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NULL__,
    FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NoEndPosition,
    FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UnintendedPosition,
    FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__Right,
    FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__Left,
    FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D51inEstEfesStateValue
{
    FObserveDegradedPointPosition_D51inEstEfesStateValue__NULL__,
    FObserveDegradedPointPosition_D51inEstEfesStateValue__Initialising,
    FObserveDegradedPointPosition_D51inEstEfesStateValue__NoOperatingVoltage,
    FObserveDegradedPointPosition_D51inEstEfesStateValue__Booting,
    FObserveDegradedPointPosition_D51inEstEfesStateValue__FallbackMode,
    FObserveDegradedPointPosition_D51inEstEfesStateValue__UNKNOWN__
} FObserveDegradedPointPosition_D51inEstEfesStateValue;
typedef enum FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue
{
    FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__NULL__,
    FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__DegradedRight,
    FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__NotDegraded,
    FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__DegradedLeft,
    FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__DegradedDenied,
    FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__Undefined,
    FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue;
typedef enum FObserveDegradedPointPosition_D14inObservedPointPositionValue
{
    FObserveDegradedPointPosition_D14inObservedPointPositionValue__NULL__,
    FObserveDegradedPointPosition_D14inObservedPointPositionValue__Left,
    FObserveDegradedPointPosition_D14inObservedPointPositionValue__Right,
    FObserveDegradedPointPosition_D14inObservedPointPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D14inObservedPointPositionValue;

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

    /// D22in_PM1_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveDegradedPointPosition_D22inPm1CrucialPositionValue, ) D22inPm1CrucialPosition;

    /// D23in_PM1n_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue, ) D23inPm1nCrucialPosition;

    /// D24in_PM2_Non_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue, ) D24inPm2NonCrucialPosition;

    /// D25in_PM2n_Non_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue, ) D25inPm2nNonCrucialPosition;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveDegradedPointPosition_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// D26in_Con_PM1n_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D26inConPm1nCrucialActivation;

    /// D27in_Con_PM2_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D27inConPm2NonCrucialActivation;

    /// D28in_Con_PM2n_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D28inConPm2nNonCrucialActivation;

    /// d30out_Observed_Degraded_Point_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue, )
        D30outObservedDegradedPointPosition;

    /// d14in_Observed_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveDegradedPointPosition_D14inObservedPointPositionValue, ) D14inObservedPointPosition;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change376; // d51in_EST_EfeS_State = "INITIALISING"
    ChangeEvent
        Change9; // (d14in_Observed_Point_Position = "LEFT" OR d14in_Observed_Point_Position = "RIGHT") OR
                 // ((D22in_PM1_Crucial_Position <> D23in_PM1n_Crucial_Position) AND D26in_Con_PM1n_Crucial_Activation)
                 // OR ((D24in_PM2_Non_Crucial_Position <> D22in_PM1_Crucial_Position AND D24in_PM2_Non_Crucial_Position
                 // <> "UNINTENDED_POSITION" AND D24in_PM2_Non_Crucial_Position <> "NO_END_POSITION")AND
                 // D27in_Con_PM2_Non_Crucial_Activation) OR ((D25in_PM2n_Non_Crucial_Position <>
                 // D22in_PM1_Crucial_Position AND D25in_PM2n_Non_Crucial_Position <> "UNINTENDED_POSITION" AND
                 // D25in_PM2n_Non_Crucial_Position <> "NO_END_POSITION")AND D28in_Con_PM2n_Non_Crucial_Activation)
    ChangeEvent
        Change186; // D22in_PM1_Crucial_Position = "LEFT" AND (D23in_PM1n_Crucial_Position = "LEFT" OR NOT
                   // D26in_Con_PM1n_Crucial_Activation) AND ((D25in_PM2n_Non_Crucial_Position = "NO_END_POSITION" OR
                   // D25in_PM2n_Non_Crucial_Position = "UNINTENDED_POSITION") OR (D24in_PM2_Non_Crucial_Position =
                   // "NO_END_POSITION" OR D24in_PM2_Non_Crucial_Position = "UNINTENDED_POSITION"))
    ChangeEvent Change187; // D22in_PM1_Crucial_Position = "LEFT" AND (D23in_PM1n_Crucial_Position = "LEFT" OR NOT
                           // D26in_Con_PM1n_Crucial_Activation) AND ((((D25in_PM2n_Non_Crucial_Position =
                           // "NO_END_POSITION" OR D25in_PM2n_Non_Crucial_Position = "UNINTENDED_POSITION") AND
                           // D24in_PM2_Non_Crucial_Position <> "RIGHT")) OR (((D24in_PM2_Non_Crucial_Position =
                           // "NO_END_POSITION" OR D24in_PM2_Non_Crucial_Position = "UNINTENDED_POSITION") AND
                           // D25in_PM2n_Non_Crucial_Position <> "RIGHT")))
    ChangeEvent Change188; // D22in_PM1_Crucial_Position = "RIGHT" AND (D23in_PM1n_Crucial_Position = "RIGHT" OR NOT
                           // D26in_Con_PM1n_Crucial_Activation) AND ((((D25in_PM2n_Non_Crucial_Position =
                           // "NO_END_POSITION" OR D25in_PM2n_Non_Crucial_Position = "UNINTENDED_POSITION") AND
                           // D24in_PM2_Non_Crucial_Position <> "LEFT")) OR (((D24in_PM2_Non_Crucial_Position =
                           // "NO_END_POSITION" OR D24in_PM2_Non_Crucial_Position = "UNINTENDED_POSITION") AND
                           // D25in_PM2n_Non_Crucial_Position <> "LEFT")))
    ChangeEvent
        Change10; // (d14in_Observed_Point_Position = "LEFT" OR d14in_Observed_Point_Position = "RIGHT") OR
                  // ((D22in_PM1_Crucial_Position <> D23in_PM1n_Crucial_Position) AND D26in_Con_PM1n_Crucial_Activation)
                  // OR ((D24in_PM2_Non_Crucial_Position <> D22in_PM1_Crucial_Position AND
                  // D24in_PM2_Non_Crucial_Position <> "UNINTENDED_POSITION" AND D24in_PM2_Non_Crucial_Position <>
                  // "NO_END_POSITION")AND D27in_Con_PM2_Non_Crucial_Activation) OR((D25in_PM2n_Non_Crucial_Position <>
                  // D22in_PM1_Crucial_Position AND D25in_PM2n_Non_Crucial_Position <> "UNINTENDED_POSITION" AND
                  // D25in_PM2n_Non_Crucial_Position <> "NO_END_POSITION")AND D28in_Con_PM2n_Non_Crucial_Activation)
    ChangeEvent
        Change189; // D22in_PM1_Crucial_Position = "RIGHT" AND (D23in_PM1n_Crucial_Position = "RIGHT" OR NOT
                   // D26in_Con_PM1n_Crucial_Activation) AND ((D25in_PM2n_Non_Crucial_Position = "NO_END_POSITION" OR
                   // D25in_PM2n_Non_Crucial_Position = "UNINTENDED_POSITION") OR (D24in_PM2_Non_Crucial_Position =
                   // "NO_END_POSITION" OR D24in_PM2_Non_Crucial_Position = "UNINTENDED_POSITION"))
    ChangeEvent Change391; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR d51in_EST_EfeS_State = "BOOTING" OR
                           // d51in_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events

} FObserveDegradedPointPosition;

void transition_FObserveDegradedPointPosition(FObserveDegradedPointPosition *self);
void new_FObserveDegradedPointPosition(FObserveDegradedPointPosition *x);
