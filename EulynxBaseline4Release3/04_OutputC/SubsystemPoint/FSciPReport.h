
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciPReport_D11inObservedAbilityToMoveValue
{
    FSciPReport_D11inObservedAbilityToMoveValue__NULL__,
    FSciPReport_D11inObservedAbilityToMoveValue__AbleToMove,
    FSciPReport_D11inObservedAbilityToMoveValue__UnableToMove,
    FSciPReport_D11inObservedAbilityToMoveValue__UNKNOWN__
} FSciPReport_D11inObservedAbilityToMoveValue;
typedef enum FSciPReport_D14inObservedPointPositionValue
{
    FSciPReport_D14inObservedPointPositionValue__NULL__,
    FSciPReport_D14inObservedPointPositionValue__Left,
    FSciPReport_D14inObservedPointPositionValue__Right,
    FSciPReport_D14inObservedPointPositionValue__NoEndPosition,
    FSciPReport_D14inObservedPointPositionValue__UnintendedPosition,
    FSciPReport_D14inObservedPointPositionValue__UNKNOWN__
} FSciPReport_D14inObservedPointPositionValue;
typedef enum FSciPReport_D17inObservedDegradedPointPositionValue
{
    FSciPReport_D17inObservedDegradedPointPositionValue__NULL__,
    FSciPReport_D17inObservedDegradedPointPositionValue__DegradedLeft,
    FSciPReport_D17inObservedDegradedPointPositionValue__DegradedRight,
    FSciPReport_D17inObservedDegradedPointPositionValue__DegradedDenied,
    FSciPReport_D17inObservedDegradedPointPositionValue__UNKNOWN__
} FSciPReport_D17inObservedDegradedPointPositionValue;
typedef enum FSciPReport_D50inPdiConnectionStateValue
{
    FSciPReport_D50inPdiConnectionStateValue__NULL__,
    FSciPReport_D50inPdiConnectionStateValue__Established,
    FSciPReport_D50inPdiConnectionStateValue__ReadyForPdiNoScp,
    FSciPReport_D50inPdiConnectionStateValue__ReadyForPdi,
    FSciPReport_D50inPdiConnectionStateValue__Suspended,
    FSciPReport_D50inPdiConnectionStateValue__UNKNOWN__
} FSciPReport_D50inPdiConnectionStateValue;
typedef enum FSciPReport_MemLastReportedPointPositionValue
{
    FSciPReport_MemLastReportedPointPositionValue__NULL__,
    FSciPReport_MemLastReportedPointPositionValue__Left,
    FSciPReport_MemLastReportedPointPositionValue__Right,
    FSciPReport_MemLastReportedPointPositionValue__NoEndPosition,
    FSciPReport_MemLastReportedPointPositionValue__UnintendedPosition,
    FSciPReport_MemLastReportedPointPositionValue__UNKNOWN__
} FSciPReport_MemLastReportedPointPositionValue;
typedef enum FSciPReport_MemLastReportedDegradedPointPositionValue
{
    FSciPReport_MemLastReportedDegradedPointPositionValue__NULL__,
    FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedLeft,
    FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedRight,
    FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedDenied,
    FSciPReport_MemLastReportedDegradedPointPositionValue__UNKNOWN__
} FSciPReport_MemLastReportedDegradedPointPositionValue;

typedef enum FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__state
{
    FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove
} FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__state;

typedef struct FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__state_struct
{
    FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__state state;
    union {
    };
} FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__state_struct;

typedef enum FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__state
{
    FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition,
    FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__Waiting
} FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__state;

typedef struct FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__state_struct
{
    FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__state state;
    union {
    };
} FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__state_struct;

typedef enum FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__state
{
    FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__MsgMovementFailed
} FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__state;

typedef struct FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__state_struct
{
    FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__state state;
    union {
    };
} FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__state_struct;

typedef enum FSciPReport__root__state
{
    FSciPReport__root__ReportingOverallPointStates,
    FSciPReport__root__InterfaceConnectionNotEstablished
} FSciPReport__root__state;

typedef struct FSciPReport__root__ReportingOverallPointStates__state_struct
{
    FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__state_struct ReportingAbilityToMove;
    FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__state_struct ReportingMsgPointPosition;
    FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__state_struct ReportingMovementFailed;
} FSciPReport__root__ReportingOverallPointStates__state_struct;

typedef struct FSciPReport__root__state_struct
{
    FSciPReport__root__state state;
    union {
        FSciPReport__root__ReportingOverallPointStates__state_struct ReportingOverallPointStates;
    };
} FSciPReport__root__state_struct;

/// Contained in:
/// Subsystem - Point
/// Functional requirements specification
/// Subsystem - Point - Interfaces
/// SCI-P (Subsystem -  Electronic Interlocking)
/// SCI-P - Functional Viewpoint
/// SCI-P - Functional Entities
typedef struct FSciPReport
{
    FSciPReport__root__state_struct state;

    /// d11in_Observed_Ability_To_Move
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPReport_D11inObservedAbilityToMoveValue, ) D11inObservedAbilityToMove;

    /// d13in_Observed_Movement_Failed
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D13inObservedMovementFailed;

    /// d14in_Observed_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPReport_D14inObservedPointPositionValue, ) D14inObservedPointPosition;

    /// D15in_Con_Observe_Ability_To_Move
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D15inConObserveAbilityToMove;

    /// d17in_Observed_Degraded_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPReport_D17inObservedDegradedPointPositionValue, ) D17inObservedDegradedPointPosition;

    /// d50in_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPReport_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;

    /// Mem_Last_Reported_Point_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FSciPReport_MemLastReportedPointPositionValue MemLastReportedPointPosition;

    /// Mem_Last_Reported_Degraded_Point_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FSciPReport_MemLastReportedDegradedPointPositionValue MemLastReportedDegradedPointPosition;

    // Messages -- Incoming
    MessagePort(Message__StartStatusReport__1e4e) InStartStatusReport__1e4e;
    // Messages -- Outgoing
    MessagePort(Message__StatusReportCompleted__b457) OutStatusReportCompleted__b457;
    MessagePort(Message__MsgPointPosition__27c1) OutMsgPointPosition__27c1;
    MessagePort(Message__MsgAbilityToMovePoint__1f1b) OutMsgAbilityToMovePoint__1f1b;
    MessagePort(Message__MsgMovementFailed__ff4f) OutMsgMovementFailed__ff4f;

    // Change Events
    ChangeEvent Change40;  // d11in_Observed_Ability_To_Move = "ABLE_TO_MOVE"
    ChangeEvent Change43;  // d11in_Observed_Ability_To_Move = "UNABLE_TO_MOVE"
    ChangeEvent Change8;   // (d14in_Observed_Point_Position <>
                           // Mem_Last_Reported_Point_Position)
    ChangeEvent Change11;  // (d17in_Observed_Degraded_Point_Position <>
                           // Mem_Last_Reported_Degraded_Point_Position)
    ChangeEvent Change7;   // (d14in_Observed_Point_Position <>
                           // Mem_Last_Reported_Point_Position) OR
                           // (d17in_Observed_Degraded_Point_Position <>
                           // Mem_Last_Reported_Degraded_Point_Position)
    ChangeEvent Change95;  // d13in_Observed_Movement_Failed
    ChangeEvent Change316; // d50in_PDI_Connection_State = "READY_FOR_PDI_NO_SCP"OR
                           // d50in_PDI_Connection_State = "READY_FOR_PDI"OR
                           // d50in_PDI_Connection_State = "SUSPENDED"

    // Timeout Events

} FSciPReport;

void transition_FSciPReport(FSciPReport *self);
void new_FSciPReport(FSciPReport *x);
