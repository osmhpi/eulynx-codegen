
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciPCommandAndRecieve_D30inMovePointValue
{
    SSciPCommandAndRecieve_D30inMovePointValue__NULL__,
    SSciPCommandAndRecieve_D30inMovePointValue__Right,
    SSciPCommandAndRecieve_D30inMovePointValue__Left,
    SSciPCommandAndRecieve_D30inMovePointValue__UNKNOWN__
} SSciPCommandAndRecieve_D30inMovePointValue;
typedef enum SSciPCommandAndRecieve_D32outPointPositionValue
{
    SSciPCommandAndRecieve_D32outPointPositionValue__NULL__,
    SSciPCommandAndRecieve_D32outPointPositionValue__LeftAndNotApplicable,
    SSciPCommandAndRecieve_D32outPointPositionValue__LeftAndNotDegraded,
    SSciPCommandAndRecieve_D32outPointPositionValue__RightAndNotApplicable,
    SSciPCommandAndRecieve_D32outPointPositionValue__RightAndNotDegraded,
    SSciPCommandAndRecieve_D32outPointPositionValue__NoEndPositionAndDegradedLeft,
    SSciPCommandAndRecieve_D32outPointPositionValue__NoEndPositionAndDegradedRight,
    SSciPCommandAndRecieve_D32outPointPositionValue__NoEndPositionAndNotDegraded,
    SSciPCommandAndRecieve_D32outPointPositionValue__NoEndPositionAndNotApplicable,
    SSciPCommandAndRecieve_D32outPointPositionValue__TrailedAndDegradedLeft,
    SSciPCommandAndRecieve_D32outPointPositionValue__TrailedAndDegradedRight,
    SSciPCommandAndRecieve_D32outPointPositionValue__TrailedAndNotDegraded,
    SSciPCommandAndRecieve_D32outPointPositionValue__TrailedAndNotApplicable,
    SSciPCommandAndRecieve_D32outPointPositionValue__UNKNOWN__
} SSciPCommandAndRecieve_D32outPointPositionValue;
typedef enum SSciPCommandAndRecieve_D50inPdiConnectionStateValue
{
    SSciPCommandAndRecieve_D50inPdiConnectionStateValue__NULL__,
    SSciPCommandAndRecieve_D50inPdiConnectionStateValue__Established,
    SSciPCommandAndRecieve_D50inPdiConnectionStateValue__UNKNOWN__
} SSciPCommandAndRecieve_D50inPdiConnectionStateValue;
typedef enum SSciPCommandAndRecieve_D33outAbilityToMoveValue
{
    SSciPCommandAndRecieve_D33outAbilityToMoveValue__NULL__,
    SSciPCommandAndRecieve_D33outAbilityToMoveValue__UnableToMove,
    SSciPCommandAndRecieve_D33outAbilityToMoveValue__AbleToMove,
    SSciPCommandAndRecieve_D33outAbilityToMoveValue__UNKNOWN__
} SSciPCommandAndRecieve_D33outAbilityToMoveValue;

typedef enum SSciPCommandAndRecieve__root__Operating__PointPositionControlling__state
{
    SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands
} SSciPCommandAndRecieve__root__Operating__PointPositionControlling__state;

typedef struct SSciPCommandAndRecieve__root__Operating__PointPositionControlling__state_struct
{
    SSciPCommandAndRecieve__root__Operating__PointPositionControlling__state state;
    union {
    };
} SSciPCommandAndRecieve__root__Operating__PointPositionControlling__state_struct;

typedef enum SSciPCommandAndRecieve__root__Operating__PointPositionObserving__state
{
    SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport
} SSciPCommandAndRecieve__root__Operating__PointPositionObserving__state;

typedef struct SSciPCommandAndRecieve__root__Operating__PointPositionObserving__state_struct
{
    SSciPCommandAndRecieve__root__Operating__PointPositionObserving__state state;
    union {
    };
} SSciPCommandAndRecieve__root__Operating__PointPositionObserving__state_struct;

typedef enum SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__state
{
    SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport
} SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__state;

typedef struct SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__state_struct
{
    SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__state state;
    union {
    };
} SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__state_struct;

typedef enum SSciPCommandAndRecieve__root__Operating__TimeOutObserving__state
{
    SSciPCommandAndRecieve__root__Operating__TimeOutObserving__RecieveTimeOutReport
} SSciPCommandAndRecieve__root__Operating__TimeOutObserving__state;

typedef struct SSciPCommandAndRecieve__root__Operating__TimeOutObserving__state_struct
{
    SSciPCommandAndRecieve__root__Operating__TimeOutObserving__state state;
    union {
    };
} SSciPCommandAndRecieve__root__Operating__TimeOutObserving__state_struct;

typedef enum SSciPCommandAndRecieve__root__state
{
    SSciPCommandAndRecieve__root__Operating
} SSciPCommandAndRecieve__root__state;

typedef struct SSciPCommandAndRecieve__root__Operating__state_struct
{
    SSciPCommandAndRecieve__root__Operating__PointPositionControlling__state_struct PointPositionControlling;
    SSciPCommandAndRecieve__root__Operating__PointPositionObserving__state_struct PointPositionObserving;
    SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__state_struct AbilityToMoveObserving;
    SSciPCommandAndRecieve__root__Operating__TimeOutObserving__state_struct TimeOutObserving;
} SSciPCommandAndRecieve__root__Operating__state_struct;

typedef struct SSciPCommandAndRecieve__root__state_struct
{
    SSciPCommandAndRecieve__root__state state;
    union {
        SSciPCommandAndRecieve__root__Operating__state_struct Operating;
    };
} SSciPCommandAndRecieve__root__state_struct;

/// Contained in:
/// Subsystem Point
/// Functional requirements specification
/// Subsystem Point - Interfaces
/// SCI-P (Subsystem -  Electronic Interlocking)
/// SCI-P - Functional Viewpoint
/// SCI-P - Functional Entities
typedef struct SSciPCommandAndRecieve
{
    SSciPCommandAndRecieve__root__state_struct state;

    /// d30in_Move_Point
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(SSciPCommandAndRecieve_D30inMovePointValue, ) D30inMovePoint;

    /// t31out_Timeout
    /// Trigger: True, DataPort: False, In: False, Out: True, External: False
    PulsedOut T31outTimeout;

    /// d32out_Point_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(SSciPCommandAndRecieve_D32outPointPositionValue, ) D32outPointPosition;

    /// d50in_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(SSciPCommandAndRecieve_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;

    /// d33out_Ability_To_Move
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(SSciPCommandAndRecieve_D33outAbilityToMoveValue, ) D33outAbilityToMove;

    /// t30in_Move_Point
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T30inMovePoint;

    /// t32out_Point_Position
    /// Trigger: True, DataPort: False, In: False, Out: True, External: False
    PulsedOut T32outPointPosition;

    /// t33out_Ability_To_Move
    /// Trigger: True, DataPort: False, In: False, Out: True, External: False
    PulsedOut T33outAbilityToMove;

    // Messages -- Incoming
    MessagePort(Message__MsgPointPosition__27c1) InMsgPointPosition__27c1;
    MessagePort(Message__MsgAbilityToMovePoint__1f1b) InMsgAbilityToMovePoint__1f1b;
    MessagePort(Message__MsgTimeout__ff4f) InMsgTimeout__ff4f;
    // Messages -- Outgoing
    MessagePort(Message__CdMovePoint__342e) OutCdMovePoint__342e;

    // Change Events
    ChangeEvent Change1079; // t30in_Move_Point
    ChangeEvent Change1080; // t30in_Move_Point

    // Timeout Events

} SSciPCommandAndRecieve;

void transition_SSciPCommandAndRecieve(SSciPCommandAndRecieve *self);
void new_SSciPCommandAndRecieve(SSciPCommandAndRecieve *x);
