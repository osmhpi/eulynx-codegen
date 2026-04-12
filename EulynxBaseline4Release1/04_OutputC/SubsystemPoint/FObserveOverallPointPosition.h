
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveOverallPointPosition_D5outObservedPointPositionValue
{
    FObserveOverallPointPosition_D5outObservedPointPositionValue__NULL__,
    FObserveOverallPointPosition_D5outObservedPointPositionValue__Left,
    FObserveOverallPointPosition_D5outObservedPointPositionValue__NoEndPosition,
    FObserveOverallPointPosition_D5outObservedPointPositionValue__Right,
    FObserveOverallPointPosition_D5outObservedPointPositionValue__Trailed,
    FObserveOverallPointPosition_D5outObservedPointPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D5outObservedPointPositionValue;
typedef enum FObserveOverallPointPosition_D10inPm1CrucialPositionValue
{
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Left,
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Right,
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Trailed,
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D10inPm1CrucialPositionValue;
typedef enum FObserveOverallPointPosition_D10inPm1nCrucialPositionValue
{
    FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Left,
    FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Right,
    FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Trailed,
    FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D10inPm1nCrucialPositionValue;
typedef enum FObserveOverallPointPosition_D51inEstEfesStateValue
{
    FObserveOverallPointPosition_D51inEstEfesStateValue__NULL__,
    FObserveOverallPointPosition_D51inEstEfesStateValue__NoOperatingVoltage,
    FObserveOverallPointPosition_D51inEstEfesStateValue__Booting,
    FObserveOverallPointPosition_D51inEstEfesStateValue__FallbackMode,
    FObserveOverallPointPosition_D51inEstEfesStateValue__UNKNOWN__
} FObserveOverallPointPosition_D51inEstEfesStateValue;
typedef enum FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue
{
    FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Left,
    FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Right,
    FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Trailed,
    FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue;
typedef enum FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue
{
    FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Left,
    FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Right,
    FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Trailed,
    FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue;
typedef enum FObserveOverallPointPosition_D41outObservedPointEndPositionValue
{
    FObserveOverallPointPosition_D41outObservedPointEndPositionValue__NULL__,
    FObserveOverallPointPosition_D41outObservedPointEndPositionValue__Left,
    FObserveOverallPointPosition_D41outObservedPointEndPositionValue__Right,
    FObserveOverallPointPosition_D41outObservedPointEndPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D41outObservedPointEndPositionValue;
typedef enum FObserveOverallPointPosition_MemPm1CrucialPositionValue
{
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__Trailed,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPm1CrucialPositionValue;
typedef enum FObserveOverallPointPosition_MemPm1nCrucialPositionValue
{
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Trailed,
    FObserveOverallPointPosition_MemPm1nCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPm1nCrucialPositionValue;
typedef enum FObserveOverallPointPosition_MemPm2NonCrucialPositionValue
{
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Trailed,
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPm2NonCrucialPositionValue;
typedef enum FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue
{
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Trailed,
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue;

typedef enum FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state
{
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__NoEndPosition,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Trailed
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

    /// d5out_Observed_Point_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveOverallPointPosition_D5outObservedPointPositionValue, ) D5outObservedPointPosition;

    /// D10in_PM1_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D10inPm1CrucialPositionValue, ) D10inPm1CrucialPosition;

    /// D10in_PM1n_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D10inPm1nCrucialPositionValue, ) D10inPm1nCrucialPosition;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveOverallPointPosition_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// D11in_Con_PM1n_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D11inConPm1nCrucialActivation;

    /// D10in_PM2n_Non_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue, ) D10inPm2nNonCrucialPosition;

    /// D10in_PM2_Non_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue, ) D10inPm2NonCrucialPosition;

    /// D14in_Con_Use_Trailing
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D14inConUseTrailing;

    /// D12in_Con_PM2_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D12inConPm2NonCrucialActivation;

    /// D13in_Con_PM2n_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D13inConPm2nNonCrucialActivation;

    /// d41out_Observed_Point_End_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveOverallPointPosition_D41outObservedPointEndPositionValue, ) D41outObservedPointEndPosition;

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
    ChangeEvent Change23;  // D10in_PM1_Crucial_Position <> Mem_PM1_Crucial_Position
    ChangeEvent Change28;  // D10in_PM1n_Crucial_Position <> Mem_PM1n_Crucial_Position
    ChangeEvent Change29;  // D10in_PM2_Non_Crucial_Position <> Mem_PM2_Non_Crucial_Position
    ChangeEvent Change30;  // D10in_PM2n_Non_Crucial_Position <> Mem_PM2n_Non_Crucial_Position
    ChangeEvent Change388; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR d51in_EST_EfeS_State = "BOOTING" OR
                           // d51in_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events

} FObserveOverallPointPosition;

void transition_FObserveOverallPointPosition(FObserveOverallPointPosition *self);
void new_FObserveOverallPointPosition(FObserveOverallPointPosition *x);
