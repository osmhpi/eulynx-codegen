
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveMovementFailed_D12inRequiredPmPositionValue
{
    FObserveMovementFailed_D12inRequiredPmPositionValue__NULL__,
    FObserveMovementFailed_D12inRequiredPmPositionValue__Left,
    FObserveMovementFailed_D12inRequiredPmPositionValue__Right,
    FObserveMovementFailed_D12inRequiredPmPositionValue__Uncommanded,
    FObserveMovementFailed_D12inRequiredPmPositionValue__UNKNOWN__
} FObserveMovementFailed_D12inRequiredPmPositionValue;

typedef enum FObserveMovementFailed__root__ObserveMovementFailure__root__state
{
    FObserveMovementFailed__root__ObserveMovementFailure__root__Idle,
    FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure
} FObserveMovementFailed__root__ObserveMovementFailure__root__state;

typedef struct FObserveMovementFailed__root__ObserveMovementFailure__root__state_struct
{
    FObserveMovementFailed__root__ObserveMovementFailure__root__state state;
    union {
    };
} FObserveMovementFailed__root__ObserveMovementFailure__root__state_struct;

typedef enum FObserveMovementFailed__root__state
{
    FObserveMovementFailed__root__ObserveMovementFailure
} FObserveMovementFailed__root__state;

typedef struct FObserveMovementFailed__root__ObserveMovementFailure__state_struct
{
    FObserveMovementFailed__root__ObserveMovementFailure__root__state_struct root;
} FObserveMovementFailed__root__ObserveMovementFailure__state_struct;

typedef struct FObserveMovementFailed__root__state_struct
{
    FObserveMovementFailed__root__state state;
    union {
        FObserveMovementFailed__root__ObserveMovementFailure__state_struct ObserveMovementFailure;
    };
} FObserveMovementFailed__root__state_struct;

/// Contained in:
/// Subsystem Point
/// Functional requirements specification
/// Subsystem Point - Functional Viewpoint
/// Subsystem Point - Functional Entities
typedef struct FObserveMovementFailed
{
    FObserveMovementFailed__root__state_struct state;

    /// D20in_Con_tmax_PM_Operation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(void *, ) D20inConTmaxPmOperation;

    /// d13out_Observed_Movement_Failed
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D13outObservedMovementFailed;

    /// d12in_Required_PM_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveMovementFailed_D12inRequiredPmPositionValue, ) D12inRequiredPmPosition;

    /// d14in_Observed_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(void *, ) D14inObservedPointPosition;

    /// t21in_Movement_Failed
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T21inMovementFailed;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change65;  // d12in_Required_PM_Position = "LEFT" OR
                           // d12in_Required_PM_Position = "RIGHT"
    ChangeEvent Change60;  // d12in_Required_PM_Position = "LEFT"
    ChangeEvent Change69;  // d12in_Required_PM_Position = "RIGHT"
    ChangeEvent Change73;  // d12in_Required_PM_Position = "UNCOMMANDED"
    ChangeEvent Change997; // t21in_Movement_Failed

    // Timeout Events
    TimeoutEvent Time12;

} FObserveMovementFailed;

void transition_FObserveMovementFailed(FObserveMovementFailed *self);
void new_FObserveMovementFailed(FObserveMovementFailed *x);
