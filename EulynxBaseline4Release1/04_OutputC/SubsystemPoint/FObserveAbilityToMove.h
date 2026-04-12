
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue
{
    FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue__NULL__,
    FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue__Unable,
    FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue__Able,
    FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue__NotUsed,
    FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue__UNKNOWN__
} FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue;
typedef enum FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue
{
    FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue__NULL__,
    FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue__Unable,
    FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue__Able,
    FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue__UNKNOWN__
} FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue;
typedef enum FObserveAbilityToMove_D6outObservedAbilityToMovePointValue
{
    FObserveAbilityToMove_D6outObservedAbilityToMovePointValue__NULL__,
    FObserveAbilityToMove_D6outObservedAbilityToMovePointValue__AbleToMove,
    FObserveAbilityToMove_D6outObservedAbilityToMovePointValue__UnableToMove,
    FObserveAbilityToMove_D6outObservedAbilityToMovePointValue__UNKNOWN__
} FObserveAbilityToMove_D6outObservedAbilityToMovePointValue;
typedef enum FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue
{
    FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue__NULL__,
    FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue__Unable,
    FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue__Able,
    FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue__NotUsed,
    FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue__UNKNOWN__
} FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue;
typedef enum FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue
{
    FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue__NULL__,
    FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue__Unable,
    FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue__Able,
    FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue__NotUsed,
    FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue__UNKNOWN__
} FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue;
typedef enum FObserveAbilityToMove_D51inEstEfesStateValue
{
    FObserveAbilityToMove_D51inEstEfesStateValue__NULL__,
    FObserveAbilityToMove_D51inEstEfesStateValue__Initialising,
    FObserveAbilityToMove_D51inEstEfesStateValue__UNKNOWN__
} FObserveAbilityToMove_D51inEstEfesStateValue;

typedef enum FObserveAbilityToMove__root__state
{
    FObserveAbilityToMove__root__WaitingForInitialising,
    FObserveAbilityToMove__root__AbleToMove,
    FObserveAbilityToMove__root__UnableToMove
} FObserveAbilityToMove__root__state;

typedef struct FObserveAbilityToMove__root__state_struct
{
    FObserveAbilityToMove__root__state state;
    union {
    };
} FObserveAbilityToMove__root__state_struct;

/// Contained in:
/// Subsystem Point
/// Functional requirements specification
/// Subsystem Point - Functional Viewpoint
/// Subsystem Point - Functional Entities
typedef struct FObserveAbilityToMove
{
    FObserveAbilityToMove__root__state_struct state;

    /// D19in_Ability_To_Move_PM1n_Crucial
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue, ) D19inAbilityToMovePm1nCrucial;

    /// D19in_Ability_To_Move_PM1_Crucial
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue, ) D19inAbilityToMovePm1Crucial;

    /// d6out_Observed_Ability_To_Move_Point
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveAbilityToMove_D6outObservedAbilityToMovePointValue, ) D6outObservedAbilityToMovePoint;

    /// D18in_Internal_Trigger_Ability_To_Move_Point_Available
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D18inInternalTriggerAbilityToMovePointAvailable;

    /// D19in_Ability_To_Move_PM2n_Non_Crucial
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue, ) D19inAbilityToMovePm2nNonCrucial;

    /// D19in_Ability_To_Move_PM2_Non_Crucial
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue, ) D19inAbilityToMovePm2NonCrucial;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveAbilityToMove_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// D46in_Con_PM1n_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D46inConPm1nCrucialActivation;

    /// D47in_Con_PM2_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D47inConPm2NonCrucialActivation;

    /// D48in_Con_PM2n_Non_Crucial_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D48inConPm2nNonCrucialActivation;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change374; // d51in_EST_EfeS_State = "INITIALISING"
    ChangeEvent
        Change113; // D19in_Ability_To_Move_PM1_Crucial = "UNABLE" OR D19in_Ability_To_Move_PM1n_Crucial = "UNABLE" OR
                   // D19in_Ability_To_Move_PM2_Non_Crucial = "UNABLE" OR D19in_Ability_To_Move_PM2n_Non_Crucial =
                   // "UNABLE" OR NOT D18in_Internal_Trigger_Ability_To_Move_Point_Available
    ChangeEvent
        Change112; // D19in_Ability_To_Move_PM1_Crucial = "ABLE"  AND (D19in_Ability_To_Move_PM1n_Crucial = "ABLE" OR
                   // D19in_Ability_To_Move_PM1n_Crucial = "NOT_USED" OR NOT D46in_Con_PM1n_Crucial_Activation) AND
                   // (D19in_Ability_To_Move_PM2n_Non_Crucial = "ABLE" OR D19in_Ability_To_Move_PM2n_Non_Crucial =
                   // "NOT_USED" OR NOT D48in_Con_PM2n_Non_Crucial_Activation) AND
                   // (D19in_Ability_To_Move_PM2_Non_Crucial = "ABLE" OR D19in_Ability_To_Move_PM2_Non_Crucial =
                   // "NOT_USED" OR NOT D47in_Con_PM2_Non_Crucial_Activation) AND
                   // D18in_Internal_Trigger_Ability_To_Move_Point_Available

    // Timeout Events

} FObserveAbilityToMove;

void transition_FObserveAbilityToMove(FObserveAbilityToMove *self);
void new_FObserveAbilityToMove(FObserveAbilityToMove *x);
