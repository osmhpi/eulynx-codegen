
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciPReport_D50inPdiConnectionStateValue
{
    FSciPReport_D50inPdiConnectionStateValue__NULL__,
    FSciPReport_D50inPdiConnectionStateValue__Established,
    FSciPReport_D50inPdiConnectionStateValue__NotReadyForPdiNoScp,
    FSciPReport_D50inPdiConnectionStateValue__ReadyForPdiNoScp,
    FSciPReport_D50inPdiConnectionStateValue__NotReadyForPdi,
    FSciPReport_D50inPdiConnectionStateValue__ReadyForPdi,
    FSciPReport_D50inPdiConnectionStateValue__Suspended,
    FSciPReport_D50inPdiConnectionStateValue__UNKNOWN__
} FSciPReport_D50inPdiConnectionStateValue;
typedef enum FSciPReport_D5inObservedPointPositionValue
{
    FSciPReport_D5inObservedPointPositionValue__NULL__,
    FSciPReport_D5inObservedPointPositionValue__Left,
    FSciPReport_D5inObservedPointPositionValue__Right,
    FSciPReport_D5inObservedPointPositionValue__NoEndPosition,
    FSciPReport_D5inObservedPointPositionValue__Trailed,
    FSciPReport_D5inObservedPointPositionValue__UNKNOWN__
} FSciPReport_D5inObservedPointPositionValue;
typedef enum FSciPReport_D6inObservedAbilityToMoveValue
{
    FSciPReport_D6inObservedAbilityToMoveValue__NULL__,
    FSciPReport_D6inObservedAbilityToMoveValue__AbleToMove,
    FSciPReport_D6inObservedAbilityToMoveValue__UnableToMove,
    FSciPReport_D6inObservedAbilityToMoveValue__UNKNOWN__
} FSciPReport_D6inObservedAbilityToMoveValue;
typedef enum FSciPReport_D4inObservedDegradedPointPositionValue
{
    FSciPReport_D4inObservedDegradedPointPositionValue__NULL__,
    FSciPReport_D4inObservedDegradedPointPositionValue__DegradedLeft,
    FSciPReport_D4inObservedDegradedPointPositionValue__DegradedRight,
    FSciPReport_D4inObservedDegradedPointPositionValue__DegradedDenied,
    FSciPReport_D4inObservedDegradedPointPositionValue__UNKNOWN__
} FSciPReport_D4inObservedDegradedPointPositionValue;
typedef enum FSciPReport_MemLastReportedPointPositionValue
{
    FSciPReport_MemLastReportedPointPositionValue__NULL__,
    FSciPReport_MemLastReportedPointPositionValue__Left,
    FSciPReport_MemLastReportedPointPositionValue__Right,
    FSciPReport_MemLastReportedPointPositionValue__NoEndPosition,
    FSciPReport_MemLastReportedPointPositionValue__Trailed,
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

typedef enum FSciPReport__root__state
{
    FSciPReport__root__ReportingOverallPointStates,
    FSciPReport__root__InterfaceConnectionNotEstablished
} FSciPReport__root__state;

typedef struct FSciPReport__root__ReportingOverallPointStates__state_struct
{
    FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__state_struct ReportingAbilityToMove;
    FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__state_struct ReportingMsgPointPosition;
} FSciPReport__root__ReportingOverallPointStates__state_struct;

typedef struct FSciPReport__root__state_struct
{
    FSciPReport__root__state state;
    union {
        FSciPReport__root__ReportingOverallPointStates__state_struct ReportingOverallPointStates;
    };
} FSciPReport__root__state_struct;

/// Contained in:
/// Subsystem Point
/// Functional requirements specification
/// Subsystem Point - Interfaces
/// SCI-P (Subsystem -  Electronic Interlocking)
/// SCI-P - Functional Viewpoint
/// SCI-P - Functional Entities
typedef struct FSciPReport
{
    FSciPReport__root__state_struct state;

    /// d50in_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPReport_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;

    /// d5in_Observed_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPReport_D5inObservedPointPositionValue, ) D5inObservedPointPosition;

    /// d6in_Observed_Ability_To_Move
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPReport_D6inObservedAbilityToMoveValue, ) D6inObservedAbilityToMove;

    /// d4in_Observed_Degraded_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPReport_D4inObservedDegradedPointPositionValue, ) D4inObservedDegradedPointPosition;

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

    // Change Events
    ChangeEvent Change458; // d6in_Observed_Ability_To_Move = "ABLE_TO_MOVE"
    ChangeEvent Change459; // d6in_Observed_Ability_To_Move = "UNABLE_TO_MOVE"
    ChangeEvent Change6;   // (d4in_Observed_Degraded_Point_Position <> Mem_Last_Reported_Degraded_Point_Position)
    ChangeEvent Change7;   // (d5in_Observed_Point_Position <> Mem_Last_Reported_Point_Position)
    ChangeEvent Change308; // d4in_Observed_Degraded_Point_Position <> Mem_Last_Reported_Degraded_Point_Position
    ChangeEvent Change427; // d5in_Observed_Point_Position <> Mem_Last_Reported_Point_Position
    ChangeEvent Change331; // d50in_PDI_Connection_State = "NOT_READY_FOR_PDI_NO_SCP" OR d50in_PDI_Connection_State =
                           // "READY_FOR_PDI_NO_SCP" OR d50in_PDI_Connection_State = "NOT_READY_FOR_PDI" OR
                           // d50in_PDI_Connection_State = "READY_FOR_PDI" OR d50in_PDI_Connection_State = "SUSPENDED"

    // Timeout Events

} FSciPReport;

void transition_FSciPReport(FSciPReport *self);
void new_FSciPReport(FSciPReport *x);
