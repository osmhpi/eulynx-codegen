
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
typedef enum FObserveOverallPointPosition_D10inPm1CrucialPositionValue
{
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Left,
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Right,
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D10inPm1CrucialPositionValue;
typedef enum FObserveOverallPointPosition_D10inPmiCrucialPositionValue
{
    FObserveOverallPointPosition_D10inPmiCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D10inPmiCrucialPositionValue__Left,
    FObserveOverallPointPosition_D10inPmiCrucialPositionValue__Right,
    FObserveOverallPointPosition_D10inPmiCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_D10inPmiCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D10inPmiCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D10inPmiCrucialPositionValue;
typedef enum FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue
{
    FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__Left,
    FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__Right,
    FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue;
typedef enum FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue
{
    FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__Left,
    FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__Right,
    FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue;
typedef enum FObserveOverallPointPosition_D51inEstEfesStateValue
{
    FObserveOverallPointPosition_D51inEstEfesStateValue__NULL__,
    FObserveOverallPointPosition_D51inEstEfesStateValue__NoOperatingVoltage,
    FObserveOverallPointPosition_D51inEstEfesStateValue__Booting,
    FObserveOverallPointPosition_D51inEstEfesStateValue__FallbackMode,
    FObserveOverallPointPosition_D51inEstEfesStateValue__UNKNOWN__
} FObserveOverallPointPosition_D51inEstEfesStateValue;
typedef enum FObserveOverallPointPosition_MemPm1CrucialPositionValue
{
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_MemPm1CrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPm1CrucialPositionValue;
typedef enum FObserveOverallPointPosition_MemPmiCrucialPositionValue
{
    FObserveOverallPointPosition_MemPmiCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPmiCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPmiCrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPmiCrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPmiCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_MemPmiCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPmiCrucialPositionValue;
typedef enum FObserveOverallPointPosition_MemPm1NonCrucialPositionValue
{
    FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPm1NonCrucialPositionValue;
typedef enum FObserveOverallPointPosition_MemPmkNonCrucialPositionValue
{
    FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__NULL__,
    FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__Undefined,
    FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__Left,
    FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__Right,
    FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__UnintendedPosition,
    FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__UNKNOWN__
} FObserveOverallPointPosition_MemPmkNonCrucialPositionValue;

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
/// Subsystem - Point
/// Functional requirements specification
/// Subsystem - Point - Functional Viewpoint
/// Subsystem - Point - Functional Entities
typedef struct FObserveOverallPointPosition
{
    FObserveOverallPointPosition__root__state_struct state;

    /// d14out_Observed_Point_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveOverallPointPosition_D14outObservedPointPositionValue, ) D14outObservedPointPosition;

    /// D10in_PM1_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D10inPm1CrucialPositionValue, ) D10inPm1CrucialPosition;

    /// D10in_PMi_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D10inPmiCrucialPositionValue, ) D10inPmiCrucialPosition;

    /// D10in_PM1_Non_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue, ) D10inPm1NonCrucialPosition;

    /// D10in_PMk_Non_Crucial_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue, ) D10inPmkNonCrucialPosition;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveOverallPointPosition_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// D26in_Con_PMi_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D26inConPmiCrucialActivation;

    /// D27in_Con_PM1_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D27inConPm1NonCrucialActivation;

    /// D28in_Con_PMk_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D28inConPmkNonCrucialActivation;

    /// D29in_Con_Use_Unintended_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D29inConUseUnintendedPosition;

    /// Mem_PM1_Crucial_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FObserveOverallPointPosition_MemPm1CrucialPositionValue MemPm1CrucialPosition;

    /// Mem_PMi_Crucial_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FObserveOverallPointPosition_MemPmiCrucialPositionValue MemPmiCrucialPosition;

    /// Mem_PM1_Non_Crucial_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FObserveOverallPointPosition_MemPm1NonCrucialPositionValue MemPm1NonCrucialPosition;

    /// Mem_PMk_Non_Crucial_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FObserveOverallPointPosition_MemPmkNonCrucialPositionValue MemPmkNonCrucialPosition;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change25;  // D10in_PM1_Crucial_Position <> Mem_PM1_Crucial_Position
    ChangeEvent Change30;  // D10in_PM1_Non_Crucial_Position <> Mem_PM1_Non_Crucial_Position
    ChangeEvent Change31;  // D10in_PMi_Crucial_Position <> Mem_PMi_Crucial_Position
    ChangeEvent Change32;  // D10in_PMk_Non_Crucial_Position <> Mem_PMk_Non_Crucial_Position
    ChangeEvent Change369; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR d51in_EST_EfeS_State = "BOOTING" OR
                           // d51in_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events

} FObserveOverallPointPosition;

void transition_FObserveOverallPointPosition(FObserveOverallPointPosition *self);
void transition_FObserveOverallPointPosition(FObserveOverallPointPosition *self);
void new_FObserveOverallPointPosition(FObserveOverallPointPosition *x);
