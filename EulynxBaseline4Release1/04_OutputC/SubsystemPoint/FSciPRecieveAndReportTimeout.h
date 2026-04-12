
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue
{
    FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__NULL__,
    FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Left,
    FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Uncommanded,
    FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Right,
    FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Initial,
    FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__UNKNOWN__
} FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue;
typedef enum FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue
{
    FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__NULL__,
    FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established,
    FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__NotReadyForPdiNoScp,
    FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__ReadyForPdiNoScp,
    FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__NotReadyForPdi,
    FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__ReadyForPdi,
    FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Suspended,
    FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__UNKNOWN__
} FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue;
typedef enum FSciPRecieveAndReportTimeout_D5inObservedPointPositionValue
{
    FSciPRecieveAndReportTimeout_D5inObservedPointPositionValue__NULL__,
    FSciPRecieveAndReportTimeout_D5inObservedPointPositionValue__Left,
    FSciPRecieveAndReportTimeout_D5inObservedPointPositionValue__Right,
    FSciPRecieveAndReportTimeout_D5inObservedPointPositionValue__UNKNOWN__
} FSciPRecieveAndReportTimeout_D5inObservedPointPositionValue;

typedef enum FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state
{
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft,
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded,
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight,
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Waiting
} FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state;

typedef struct
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state_struct
{
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state state;
    union {
    };
} FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state_struct;

typedef enum FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__state
{
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout
} FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__state;

typedef struct
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__state_struct
{
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__state state;
    union {
    };
} FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__state_struct;

typedef enum FSciPRecieveAndReportTimeout__root__state
{
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout
} FSciPRecieveAndReportTimeout__root__state;

typedef struct FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__state_struct
{
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state_struct
        RecievingMoveCommand;
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__state_struct
        ReportingPointTimeout;
} FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__state_struct;

typedef struct FSciPRecieveAndReportTimeout__root__state_struct
{
    FSciPRecieveAndReportTimeout__root__state state;
    union {
        FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__state_struct
            RecievingCommandsAndReportingTimeout;
    };
} FSciPRecieveAndReportTimeout__root__state_struct;

/// Contained in:
/// Subsystem Point
/// Functional requirements specification
/// Subsystem Point - Interfaces
/// SCI-P (Subsystem -  Electronic Interlocking)
/// SCI-P - Functional Viewpoint
/// SCI-P - Functional Entities
typedef struct FSciPRecieveAndReportTimeout
{
    FSciPRecieveAndReportTimeout__root__state_struct state;

    /// d2out_Required_Point_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue, ) D2outRequiredPointPosition;

    /// d50in_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;

    /// d5in_Observed_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPRecieveAndReportTimeout_D5inObservedPointPositionValue, ) D5inObservedPointPosition;

    /// d35in_PM1_Drive_Stop
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D35inPm1DriveStop;

    /// d35in_PM1n_Drive_Stop
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D35inPm1nDriveStop;

    /// d35in_PM2_Drive_Stop
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D35inPm2DriveStop;

    /// d35in_PM2n_Drive_Stop
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D35inPm2nDriveStop;

    /// D36in_PM1n_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D36inPm1nActivation;

    /// D37in_PM2_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D37inPm2Activation;

    /// D38in_PM2n_Activation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D38inPm2nActivation;

    /// d34out_PM1_Con_Active
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D34outPm1ConActive;

    /// d44out_PM1_Con_Drive_Capability
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D44outPm1ConDriveCapability;

    /// D28in_Con_tmax_Point_Operation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D28inConTmaxPointOperation;

    /// d40in_PM1_Msg_PM_Timeout
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D40inPm1MsgPmTimeout;

    /// d40in_PM1n_Msg_PM_Timeout
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D40inPm1nMsgPmTimeout;

    /// d40in_PM2_Msg_PM_Timeout
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D40inPm2MsgPmTimeout;

    /// d40in_PM2n_Msg_PM_Timeout
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D40inPm2nMsgPmTimeout;

    /// d41out_Msg_Timeout
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D41outMsgTimeout;

    // Messages -- Incoming
    MessagePort(Message__CdMovePoint__342e) InCdMovePoint__342e;
    // Messages -- Outgoing
    MessagePort(Message__MsgTimeout__ff4f) OutMsgTimeout__ff4f;

    // Change Events
    ChangeEvent Change251; // d35in_PM1_Drive_Stop AND (d35in_PM1n_Drive_Stop OR NOT D36in_PM1n_Activation) AND
                           // (d35in_PM2_Drive_Stop OR NOT D37in_PM2_Activation) AND (d35in_PM2n_Drive_Stop OR NOT
                           // D38in_PM2n_Activation)
    ChangeEvent Change428; // d5in_Observed_Point_Position = "LEFT"
    ChangeEvent Change250; // d35in_PM1_Drive_Stop AND (d35in_PM1n_Drive_Stop OR NOT D36in_PM1n_Activation) AND
                           // (d35in_PM2_Drive_Stop OR NOT D37in_PM2_Activation) AND (d35in_PM2n_Drive_Stop OR NOT
                           // D38in_PM2n_Activation)
    ChangeEvent Change429; // d5in_Observed_Point_Position = "RIGHT"
    ChangeEvent Change275; // d40in_PM1_Msg_PM_Timeout
    ChangeEvent Change276; // d40in_PM1n_Msg_PM_Timeout
    ChangeEvent Change277; // d40in_PM2_Msg_PM_Timeout
    ChangeEvent Change278; // d40in_PM2n_Msg_PM_Timeout
    ChangeEvent Change328; // d50in_PDI_Connection_State = "NOT_READY_FOR_PDI_NO_SCP" OR d50in_PDI_Connection_State =
                           // "READY_FOR_PDI_NO_SCP" OR d50in_PDI_Connection_State = "NOT_READY_FOR_PDI" OR
                           // d50in_PDI_Connection_State = "READY_FOR_PDI" OR d50in_PDI_Connection_State = "SUSPENDED"

    // Timeout Events
    TimeoutEvent Time20;
    TimeoutEvent Time19;

} FSciPRecieveAndReportTimeout;

void transition_FSciPRecieveAndReportTimeout(FSciPRecieveAndReportTimeout *self);
void new_FSciPRecieveAndReportTimeout(FSciPRecieveAndReportTimeout *x);
