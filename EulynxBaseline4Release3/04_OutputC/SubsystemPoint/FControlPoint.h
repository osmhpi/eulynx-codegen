
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FControlPoint_D10inRequiredPointPositionValue
{
    FControlPoint_D10inRequiredPointPositionValue__NULL__,
    FControlPoint_D10inRequiredPointPositionValue__Right,
    FControlPoint_D10inRequiredPointPositionValue__Uncommanded,
    FControlPoint_D10inRequiredPointPositionValue__Left,
    FControlPoint_D10inRequiredPointPositionValue__UNKNOWN__
} FControlPoint_D10inRequiredPointPositionValue;
typedef enum FControlPoint_D12outRequiredPmPositionValue
{
    FControlPoint_D12outRequiredPmPositionValue__NULL__,
    FControlPoint_D12outRequiredPmPositionValue__Uncommanded,
    FControlPoint_D12outRequiredPmPositionValue__Left,
    FControlPoint_D12outRequiredPmPositionValue__Right,
    FControlPoint_D12outRequiredPmPositionValue__UNKNOWN__
} FControlPoint_D12outRequiredPmPositionValue;
typedef enum FControlPoint_D51inEstEfesStateValue
{
    FControlPoint_D51inEstEfesStateValue__NULL__,
    FControlPoint_D51inEstEfesStateValue__Initialising,
    FControlPoint_D51inEstEfesStateValue__NoOperatingVoltage,
    FControlPoint_D51inEstEfesStateValue__Booting,
    FControlPoint_D51inEstEfesStateValue__FallbackMode,
    FControlPoint_D51inEstEfesStateValue__UNKNOWN__
} FControlPoint_D51inEstEfesStateValue;
typedef enum FControlPoint_D14inObservedPointPositionValue
{
    FControlPoint_D14inObservedPointPositionValue__NULL__,
    FControlPoint_D14inObservedPointPositionValue__Right,
    FControlPoint_D14inObservedPointPositionValue__Uncommanded,
    FControlPoint_D14inObservedPointPositionValue__Left,
    FControlPoint_D14inObservedPointPositionValue__UNKNOWN__
} FControlPoint_D14inObservedPointPositionValue;
typedef enum FControlPoint_D11inObservedAbilityToMoveValue
{
    FControlPoint_D11inObservedAbilityToMoveValue__NULL__,
    FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove,
    FControlPoint_D11inObservedAbilityToMoveValue__UnableToMove,
    FControlPoint_D11inObservedAbilityToMoveValue__UNKNOWN__
} FControlPoint_D11inObservedAbilityToMoveValue;
typedef enum FControlPoint_MemLastRequiredPointPositionValue
{
    FControlPoint_MemLastRequiredPointPositionValue__NULL__,
    FControlPoint_MemLastRequiredPointPositionValue__Uncommanded,
    FControlPoint_MemLastRequiredPointPositionValue__Left,
    FControlPoint_MemLastRequiredPointPositionValue__Right,
    FControlPoint_MemLastRequiredPointPositionValue__UNKNOWN__
} FControlPoint_MemLastRequiredPointPositionValue;

typedef enum FControlPoint__root__Operating__root__state
{
    FControlPoint__root__Operating__root__MovingLeft,
    FControlPoint__root__Operating__root__MovingRight,
    FControlPoint__root__Operating__root__Stopped,
    FControlPoint__root__Operating__root__Waiting
} FControlPoint__root__Operating__root__state;

typedef struct FControlPoint__root__Operating__root__state_struct
{
    FControlPoint__root__Operating__root__state state;
    union {
    };
} FControlPoint__root__Operating__root__state_struct;

typedef enum FControlPoint__root__state
{
    FControlPoint__root__Operating
} FControlPoint__root__state;

typedef struct FControlPoint__root__Operating__state_struct
{
    FControlPoint__root__Operating__root__state_struct root;
} FControlPoint__root__Operating__state_struct;

typedef struct FControlPoint__root__state_struct
{
    FControlPoint__root__state state;
    union {
        FControlPoint__root__Operating__state_struct Operating;
    };
} FControlPoint__root__state_struct;

/// Contained in:
/// Subsystem - Point
/// Functional requirements specification
/// Subsystem - Point - Functional Viewpoint
/// Subsystem - Point - Functional Entities
typedef struct FControlPoint
{
    FControlPoint__root__state_struct state;

    /// d10in_Required_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlPoint_D10inRequiredPointPositionValue, ) D10inRequiredPointPosition;

    /// d12out_Required_PM_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FControlPoint_D12outRequiredPmPositionValue, ) D12outRequiredPmPosition;

    /// D18in_Con_Use_Redrive
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D18inConUseRedrive;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlPoint_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// d14in_Observed_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlPoint_D14inObservedPointPositionValue, ) D14inObservedPointPosition;

    /// d11in_Observed_Ability_To_Move
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlPoint_D11inObservedAbilityToMoveValue, ) D11inObservedAbilityToMove;

    /// d13in_Observed_Movement_Failed
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D13inObservedMovementFailed;

    /// Mem_Last_Required_Point_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FControlPoint_MemLastRequiredPointPositionValue MemLastRequiredPointPosition;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change36;  // d10in_Required_Point_Position = "RIGHT" AND (d10in_Required_Point_Position <>
                           // d14in_Observed_Point_Position)
    ChangeEvent Change37;  // d10in_Required_Point_Position = "UNCOMMANDED"
    ChangeEvent Change41;  // d11in_Observed_Ability_To_Move = "UNABLE_TO_MOVE"
    ChangeEvent Change97;  // d13in_Observed_Movement_Failed
    ChangeEvent Change114; // d14in_Observed_Point_Position = d10in_Required_Point_Position
    ChangeEvent Change116; // d14in_Observed_Point_Position = Mem_Last_Required_Point_Position
    ChangeEvent Change34;  // d10in_Required_Point_Position = "LEFT" AND (d10in_Required_Point_Position <>
                           // d14in_Observed_Point_Position)
    ChangeEvent Change38;  // d10in_Required_Point_Position = "UNCOMMANDED"
    ChangeEvent Change42;  // d11in_Observed_Ability_To_Move = "UNABLE_TO_MOVE"
    ChangeEvent Change96;  // d13in_Observed_Movement_Failed
    ChangeEvent Change115; // d14in_Observed_Point_Position = d10in_Required_Point_Position
    ChangeEvent Change117; // d14in_Observed_Point_Position = Mem_Last_Required_Point_Position
    ChangeEvent Change33;  // d10in_Required_Point_Position = "LEFT"
    ChangeEvent Change35;  // d10in_Required_Point_Position = "RIGHT"
    ChangeEvent Change113; // d14in_Observed_Point_Position <> Mem_Last_Required_Point_Position
    ChangeEvent Change112; // d14in_Observed_Point_Position <> Mem_Last_Required_Point_Position
    ChangeEvent Change359; // d51in_EST_EfeS_State = "INITIALISING"
    ChangeEvent Change371; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR d51in_EST_EfeS_State = "BOOTING" OR
                           // d51in_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events

} FControlPoint;

void transition_FControlPoint(FControlPoint *self);
void transition_FControlPoint(FControlPoint *self);
void new_FControlPoint(FControlPoint *x);
