
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveOverallPointPosition_D14outObservedPointPositionValue
{
    FObserveOverallPointPosition_D14outObservedPointPositionValue__NULL__,
    FObserveOverallPointPosition_D14outObservedPointPositionValue__Left,
    FObserveOverallPointPosition_D14outObservedPointPositionValue__NoEndPosition,
    FObserveOverallPointPosition_D14outObservedPointPositionValue__Right,
    FObserveOverallPointPosition_D14outObservedPointPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_D14outObservedPointPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D14outObservedPointPositionValue;
typedef enum FObserveOverallPointPosition_D22inPm1CrucialPositionValue
{
    FObserveOverallPointPosition_D22inPm1CrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D22inPm1CrucialPositionValue__Left,
    FObserveOverallPointPosition_D22inPm1CrucialPositionValue__Right,
    FObserveOverallPointPosition_D22inPm1CrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_D22inPm1CrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D22inPm1CrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D22inPm1CrucialPositionValue;
typedef enum FObserveOverallPointPosition_D23inPm1nCrucialPositionValue
{
    FObserveOverallPointPosition_D23inPm1nCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D23inPm1nCrucialPositionValue__Left,
    FObserveOverallPointPosition_D23inPm1nCrucialPositionValue__Right,
    FObserveOverallPointPosition_D23inPm1nCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_D23inPm1nCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D23inPm1nCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D23inPm1nCrucialPositionValue;
typedef enum FObserveOverallPointPosition_D24inPm2NonCrucialPositionValue
{
    FObserveOverallPointPosition_D24inPm2NonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D24inPm2NonCrucialPositionValue__Left,
    FObserveOverallPointPosition_D24inPm2NonCrucialPositionValue__Right,
    FObserveOverallPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_D24inPm2NonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D24inPm2NonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D24inPm2NonCrucialPositionValue;
typedef enum FObserveOverallPointPosition_D25inPm2nNonCrucialPositionValue
{
    FObserveOverallPointPosition_D25inPm2nNonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D25inPm2nNonCrucialPositionValue__Left,
    FObserveOverallPointPosition_D25inPm2nNonCrucialPositionValue__Right,
    FObserveOverallPointPosition_D25inPm2nNonCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_D25inPm2nNonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D25inPm2nNonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D25inPm2nNonCrucialPositionValue;
typedef enum FObserveOverallPointPosition_D51inEstEfesStateValue
{
    FObserveOverallPointPosition_D51inEstEfesStateValue__NULL__,
    FObserveOverallPointPosition_D51inEstEfesStateValue__NoOperatingVoltage,
    FObserveOverallPointPosition_D51inEstEfesStateValue__Booting,
    FObserveOverallPointPosition_D51inEstEfesStateValue__FallbackMode,
    FObserveOverallPointPosition_D51inEstEfesStateValue__UNKNOWN__
} FObserveOverallPointPosition_D51inEstEfesStateValue;
typedef enum FObserveOverallPointPosition_D19outObservedLastPointEndPositionValue
{
    FObserveOverallPointPosition_D19outObservedLastPointEndPositionValue__NULL__,
    FObserveOverallPointPosition_D19outObservedLastPointEndPositionValue__Left,
    FObserveOverallPointPosition_D19outObservedLastPointEndPositionValue__Right,
    FObserveOverallPointPosition_D19outObservedLastPointEndPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D19outObservedLastPointEndPositionValue;
typedef enum FObserveOverallPointPosition_MemPm1CrucialPositionValue
{
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPm1CrucialPositionValue;
typedef enum FObserveOverallPointPosition_MemPm1nCrucialPositionValue
{
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPm1nCrucialPositionValue;
typedef enum FObserveOverallPointPosition_MemPm2NonCrucialPositionValue
{
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPm2NonCrucialPositionValue;
typedef enum FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue
{
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue;

typedef enum FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state
{
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__NoEndPosition,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__UnintendedPosition
} FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state;

typedef struct FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct
{
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state state;
    union {
    };
} FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct;

typedef enum FObserveOverallPointPosition__root__state
{
    FObserveOverallPointPosition__root__ObserveOverallPointPosition
} FObserveOverallPointPosition__root__state;

typedef struct FObserveOverallPointPosition__root__ObserveOverallPointPosition__state_struct
{
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct root;
} FObserveOverallPointPosition__root__ObserveOverallPointPosition__state_struct;

typedef struct FObserveOverallPointPosition__root__state_struct
{
    FObserveOverallPointPosition__root__state state;
    union {
        FObserveOverallPointPosition__root__ObserveOverallPointPosition__state_struct ObserveOverallPointPosition;
    };
} FObserveOverallPointPosition__root__state_struct;

/// Contained in:
/// Subsystem Point
/// Functional requirements specification
/// Subsystem Point - Functional Viewpoint
/// Subsystem Point - Functional Entities
typedef struct FObserveOverallPointPosition
{
    FObserveOverallPointPosition__root__state_struct state;

    /// d14out_Observed_Point_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveOverallPointPosition_D14outObservedPointPositionValue, ) D14outObservedPointPosition;

    /// D22in_PM1_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D22inPm1CrucialPositionValue, ) D22inPm1CrucialPosition;

    /// D23in_PM1n_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D23inPm1nCrucialPositionValue, ) D23inPm1nCrucialPosition;

    /// D24in_PM2_Non_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D24inPm2NonCrucialPositionValue, ) D24inPm2NonCrucialPosition;

    /// D25in_PM2n_Non_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D25inPm2nNonCrucialPositionValue, ) D25inPm2nNonCrucialPosition;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveOverallPointPosition_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// D26in_Con_PM1n_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D26inConPm1nCrucialActivation;

    /// D27in_Con_PM2_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D27inConPm2NonCrucialActivation;

    /// D28in_Con_PM2n_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D28inConPm2nNonCrucialActivation;

    /// D29in_Con_Use_Unintended_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D29inConUseUnintendedPosition;

    /// d19out_Observed_Last_Point_End_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveOverallPointPosition_D19outObservedLastPointEndPositionValue, ) D19outObservedLastPointEndPosition;

    /// Mem_PM1_Crucial_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FObserveOverallPointPosition_MemPm1CrucialPositionValue MemPm1CrucialPosition;

    /// Mem_PM1n_Crucial_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue MemPm1nCrucialPosition;

    /// Mem_PM2_Non_Crucial_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue MemPm2NonCrucialPosition;

    /// Mem_PM2n_Non_Crucial_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue MemPm2nNonCrucialPosition;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change185; // D22in_PM1_Crucial_Position <> Mem_PM1_Crucial_Position
    ChangeEvent Change194; // D23in_PM1n_Crucial_Position <> Mem_PM1n_Crucial_Position
    ChangeEvent Change196; // D24in_PM2_Non_Crucial_Position <>
                           // Mem_PM2_Non_Crucial_Position
    ChangeEvent Change198; // D25in_PM2n_Non_Crucial_Position <>
                           // Mem_PM2n_Non_Crucial_Position
    ChangeEvent Change389; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR
                           // d51in_EST_EfeS_State = "BOOTING" OR
                           // d51in_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events

} FObserveOverallPointPosition;

void transition_FObserveOverallPointPosition(FObserveOverallPointPosition *self);
void new_FObserveOverallPointPosition(FObserveOverallPointPosition *x);
