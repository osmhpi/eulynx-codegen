
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveAbilityToMove_D30inAbilityToMovePm1nCrucialValue {
  FObserveAbilityToMove_D30inAbilityToMovePm1nCrucialValue__NULL__,
  FObserveAbilityToMove_D30inAbilityToMovePm1nCrucialValue__Unable,
  FObserveAbilityToMove_D30inAbilityToMovePm1nCrucialValue__Able,
  FObserveAbilityToMove_D30inAbilityToMovePm1nCrucialValue__NotUsed,
  FObserveAbilityToMove_D30inAbilityToMovePm1nCrucialValue__UNKNOWN__
} FObserveAbilityToMove_D30inAbilityToMovePm1nCrucialValue;
typedef enum FObserveAbilityToMove_D29inAbilityToMovePm1CrucialValue {
  FObserveAbilityToMove_D29inAbilityToMovePm1CrucialValue__NULL__,
  FObserveAbilityToMove_D29inAbilityToMovePm1CrucialValue__Unable,
  FObserveAbilityToMove_D29inAbilityToMovePm1CrucialValue__Able,
  FObserveAbilityToMove_D29inAbilityToMovePm1CrucialValue__UNKNOWN__
} FObserveAbilityToMove_D29inAbilityToMovePm1CrucialValue;
typedef enum FObserveAbilityToMove_D11outObservedAbilityToMoveValue {
  FObserveAbilityToMove_D11outObservedAbilityToMoveValue__NULL__,
  FObserveAbilityToMove_D11outObservedAbilityToMoveValue__AbleToMove,
  FObserveAbilityToMove_D11outObservedAbilityToMoveValue__UnableToMove,
  FObserveAbilityToMove_D11outObservedAbilityToMoveValue__UNKNOWN__
} FObserveAbilityToMove_D11outObservedAbilityToMoveValue;
typedef enum FObserveAbilityToMove_D32inAbilityToMovePm2nNonCrucialValue {
  FObserveAbilityToMove_D32inAbilityToMovePm2nNonCrucialValue__NULL__,
  FObserveAbilityToMove_D32inAbilityToMovePm2nNonCrucialValue__Unable,
  FObserveAbilityToMove_D32inAbilityToMovePm2nNonCrucialValue__Able,
  FObserveAbilityToMove_D32inAbilityToMovePm2nNonCrucialValue__NotUsed,
  FObserveAbilityToMove_D32inAbilityToMovePm2nNonCrucialValue__UNKNOWN__
} FObserveAbilityToMove_D32inAbilityToMovePm2nNonCrucialValue;
typedef enum FObserveAbilityToMove_D31inAbilityToMovePm2NonCrucialValue {
  FObserveAbilityToMove_D31inAbilityToMovePm2NonCrucialValue__NULL__,
  FObserveAbilityToMove_D31inAbilityToMovePm2NonCrucialValue__Unable,
  FObserveAbilityToMove_D31inAbilityToMovePm2NonCrucialValue__Able,
  FObserveAbilityToMove_D31inAbilityToMovePm2NonCrucialValue__NotUsed,
  FObserveAbilityToMove_D31inAbilityToMovePm2NonCrucialValue__UNKNOWN__
} FObserveAbilityToMove_D31inAbilityToMovePm2NonCrucialValue;
typedef enum FObserveAbilityToMove_D51inEstEfesStateValue {
  FObserveAbilityToMove_D51inEstEfesStateValue__NULL__,
  FObserveAbilityToMove_D51inEstEfesStateValue__Initialising,
  FObserveAbilityToMove_D51inEstEfesStateValue__UNKNOWN__
} FObserveAbilityToMove_D51inEstEfesStateValue;

typedef enum FObserveAbilityToMove__root__state {
  FObserveAbilityToMove__root__WaitingForInitialising,
  FObserveAbilityToMove__root__AbleToMove,
  FObserveAbilityToMove__root__UnableToMove
} FObserveAbilityToMove__root__state;

typedef struct FObserveAbilityToMove__root__state_struct {
  FObserveAbilityToMove__root__state state;
  union {};
} FObserveAbilityToMove__root__state_struct;

/// Contained in:
/// Subsystem Point
/// Functional requirements specification
/// Subsystem Point - Functional Viewpoint
/// Subsystem Point - Functional Entities
typedef struct FObserveAbilityToMove {
  FObserveAbilityToMove__root__state_struct state;

  /// D30in_Ability_To_Move_PM1n_Crucial
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(FObserveAbilityToMove_D30inAbilityToMovePm1nCrucialValue, )
      D30inAbilityToMovePm1nCrucial;

  /// D29in_Ability_To_Move_PM1_Crucial
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(FObserveAbilityToMove_D29inAbilityToMovePm1CrucialValue, )
      D29inAbilityToMovePm1Crucial;

  /// d11out_Observed_Ability_To_Move
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(FObserveAbilityToMove_D11outObservedAbilityToMoveValue, )
      D11outObservedAbilityToMove;

  /// D33in_Internal_Trigger_Ability_To_Move_Point_Available
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D33inInternalTriggerAbilityToMovePointAvailable;

  /// D32in_Ability_To_Move_PM2n_Non_Crucial
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(FObserveAbilityToMove_D32inAbilityToMovePm2nNonCrucialValue, )
      D32inAbilityToMovePm2nNonCrucial;

  /// D31in_Ability_To_Move_PM2_Non_Crucial
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(FObserveAbilityToMove_D31inAbilityToMovePm2NonCrucialValue, )
      D31inAbilityToMovePm2NonCrucial;

  /// d51in_EST_EfeS_State
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FObserveAbilityToMove_D51inEstEfesStateValue, ) D51inEstEfesState;

  /// D26in_Con_PM1n_Crucial_Activation
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D26inConPm1nCrucialActivation;

  /// D27in_Con_PM2_Non_Crucial_Activation
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D27inConPm2NonCrucialActivation;

  /// D28in_Con_PM2n_Non_Crucial_Activation
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D28inConPm2nNonCrucialActivation;

  /// D15in_Con_Observe_Ability_To_Move
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D15inConObserveAbilityToMove;

  // Messages -- Incoming

  // Messages -- Outgoing

  // Change Events
  ChangeEvent Change381; // d51in_EST_EfeS_State = "INITIALISING"
  ChangeEvent
      Change209; // D29in_Ability_To_Move_PM1_Crucial = "UNABLE" OR
                 // D30in_Ability_To_Move_PM1n_Crucial = "UNABLE" OR
                 // D31in_Ability_To_Move_PM2_Non_Crucial = "UNABLE" OR
                 // D32in_Ability_To_Move_PM2n_Non_Crucial = "UNABLE" OR NOT
                 // D33in_Internal_Trigger_Ability_To_Move_Point_Available
  ChangeEvent
      Change208; // D29in_Ability_To_Move_PM1_Crucial = "ABLE"  AND
                 // (D30in_Ability_To_Move_PM1n_Crucial = "ABLE" OR
                 // D30in_Ability_To_Move_PM1n_Crucial = "NOT_USED" OR NOT
                 // D26in_Con_PM1n_Crucial_Activation) AND
                 // (D32in_Ability_To_Move_PM2n_Non_Crucial = "ABLE" OR
                 // D32in_Ability_To_Move_PM2n_Non_Crucial = "NOT_USED" OR NOT
                 // D28in_Con_PM2n_Non_Crucial_Activation) AND
                 // (D31in_Ability_To_Move_PM2_Non_Crucial = "ABLE" OR
                 // D31in_Ability_To_Move_PM2_Non_Crucial = "NOT_USED" OR NOT
                 // D27in_Con_PM2_Non_Crucial_Activation) AND
                 // D33in_Internal_Trigger_Ability_To_Move_Point_Available

  // Timeout Events

} FObserveAbilityToMove;

void transition_FObserveAbilityToMove(FObserveAbilityToMove *self);
void new_FObserveAbilityToMove(FObserveAbilityToMove *x);
