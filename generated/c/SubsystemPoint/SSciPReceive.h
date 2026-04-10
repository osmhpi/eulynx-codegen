
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciPReceive_D5outPointPositionValue {
  SSciPReceive_D5outPointPositionValue__NULL__,
  SSciPReceive_D5outPointPositionValue__LeftAndNotApplicable,
  SSciPReceive_D5outPointPositionValue__LeftAndNotDegraded,
  SSciPReceive_D5outPointPositionValue__RightAndNotApplicable,
  SSciPReceive_D5outPointPositionValue__RightAndNotDegraded,
  SSciPReceive_D5outPointPositionValue__NoEndPositionAndDegradedLeft,
  SSciPReceive_D5outPointPositionValue__NoEndPositionAndDegradedRight,
  SSciPReceive_D5outPointPositionValue__NoEndPositionAndNotDegraded,
  SSciPReceive_D5outPointPositionValue__NoEndPositionAndNotApplicable,
  SSciPReceive_D5outPointPositionValue__UnintendedPositionAndDegradedLeft,
  SSciPReceive_D5outPointPositionValue__UnintendedPositionAndDegradedRight,
  SSciPReceive_D5outPointPositionValue__UnintendedPositionAndNotDegraded,
  SSciPReceive_D5outPointPositionValue__UnintendedPositionAndNotApplicable,
  SSciPReceive_D5outPointPositionValue__UNKNOWN__
} SSciPReceive_D5outPointPositionValue;
typedef enum SSciPReceive_D8outAbilityToMoveValue {
  SSciPReceive_D8outAbilityToMoveValue__NULL__,
  SSciPReceive_D8outAbilityToMoveValue__UnableToMove,
  SSciPReceive_D8outAbilityToMoveValue__AbleToMove,
  SSciPReceive_D8outAbilityToMoveValue__UNKNOWN__
} SSciPReceive_D8outAbilityToMoveValue;

typedef enum SSciPReceive__root__Operating__PointPositionObserving__state {
  SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport
} SSciPReceive__root__Operating__PointPositionObserving__state;

typedef struct
    SSciPReceive__root__Operating__PointPositionObserving__state_struct {
  SSciPReceive__root__Operating__PointPositionObserving__state state;
  union {};
} SSciPReceive__root__Operating__PointPositionObserving__state_struct;

typedef enum SSciPReceive__root__Operating__AbilityToMoveObserving__state {
  SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport
} SSciPReceive__root__Operating__AbilityToMoveObserving__state;

typedef struct
    SSciPReceive__root__Operating__AbilityToMoveObserving__state_struct {
  SSciPReceive__root__Operating__AbilityToMoveObserving__state state;
  union {};
} SSciPReceive__root__Operating__AbilityToMoveObserving__state_struct;

typedef enum SSciPReceive__root__Operating__MovementFailedObserving__state {
  SSciPReceive__root__Operating__MovementFailedObserving__ReceiveMovementFailedReport
} SSciPReceive__root__Operating__MovementFailedObserving__state;

typedef struct
    SSciPReceive__root__Operating__MovementFailedObserving__state_struct {
  SSciPReceive__root__Operating__MovementFailedObserving__state state;
  union {};
} SSciPReceive__root__Operating__MovementFailedObserving__state_struct;

typedef enum SSciPReceive__root__state {
  SSciPReceive__root__Operating
} SSciPReceive__root__state;

typedef struct SSciPReceive__root__Operating__state_struct {
  SSciPReceive__root__Operating__PointPositionObserving__state_struct
      PointPositionObserving;
  SSciPReceive__root__Operating__AbilityToMoveObserving__state_struct
      AbilityToMoveObserving;
  SSciPReceive__root__Operating__MovementFailedObserving__state_struct
      MovementFailedObserving;
} SSciPReceive__root__Operating__state_struct;

typedef struct SSciPReceive__root__state_struct {
  SSciPReceive__root__state state;
  union {
    SSciPReceive__root__Operating__state_struct Operating;
  };
} SSciPReceive__root__state_struct;

/// Contained in:
/// Subsystem - Point
/// Functional requirements specification
/// Subsystem - Point - Interfaces
/// SCI-P (Subsystem -  Electronic Interlocking)
/// SCI-P - Functional Viewpoint
/// SCI-P - Functional Entities
typedef struct SSciPReceive {
  SSciPReceive__root__state_struct state;

  /// t4out_Point_Position
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T4outPointPosition;

  /// d5out_Point_Position
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciPReceive_D5outPointPositionValue, ) D5outPointPosition;

  /// t6out_Movement_Failed
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T6outMovementFailed;

  /// t7out_Ability_To_Move
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T7outAbilityToMove;

  /// d8out_Ability_To_Move
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciPReceive_D8outAbilityToMoveValue, ) D8outAbilityToMove;

  // Messages -- Incoming
  MessagePort(Message__MsgPointPosition__27c1) InMsgPointPosition__27c1;
  MessagePort(Message__MsgAbilityToMovePoint__1f1b)
      InMsgAbilityToMovePoint__1f1b;
  MessagePort(Message__MsgMovementFailed__ff4f) InMsgMovementFailed__ff4f;
  // Messages -- Outgoing

  // Change Events

  // Timeout Events

} SSciPReceive;

void transition_SSciPReceive(SSciPReceive *self);
void new_SSciPReceive(SSciPReceive *x);
