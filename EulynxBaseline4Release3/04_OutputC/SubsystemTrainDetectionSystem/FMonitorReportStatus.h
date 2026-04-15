
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__state
{
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__Waiting
} FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__state;

typedef struct
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__state_struct
{
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__state
        state;
    union {
    };
} FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__state_struct;

typedef enum FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__state
{
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__Waiting
} FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__state;

typedef struct
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__state_struct
{
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__state
        state;
    union {
    };
} FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__state_struct;

typedef enum FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__state
{
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__Waiting
} FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__state;

typedef struct FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__state_struct
{
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__state state;
    union {
    };
} FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__state_struct;

typedef enum FMonitorReportStatus__root__MonitoringReportStatus__root__state
{
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForReportStatus,
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports
} FMonitorReportStatus__root__MonitoringReportStatus__root__state;

typedef struct FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__state_struct
{
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__state_struct
        TvpsStatusAxleCounter;
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__state_struct
        TvpsStatusTrackCircuits;
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__state_struct Tdp;
} FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__state_struct;

typedef struct FMonitorReportStatus__root__MonitoringReportStatus__root__state_struct
{
    FMonitorReportStatus__root__MonitoringReportStatus__root__state state;
    union {
        FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__state_struct
            WaitingForStatusReports;
    };
} FMonitorReportStatus__root__MonitoringReportStatus__root__state_struct;

typedef enum FMonitorReportStatus__root__state
{
    FMonitorReportStatus__root__MonitoringReportStatus
} FMonitorReportStatus__root__state;

typedef struct FMonitorReportStatus__root__MonitoringReportStatus__state_struct
{
    FMonitorReportStatus__root__MonitoringReportStatus__root__state_struct root;
} FMonitorReportStatus__root__MonitoringReportStatus__state_struct;

typedef struct FMonitorReportStatus__root__state_struct
{
    FMonitorReportStatus__root__state state;
    union {
        FMonitorReportStatus__root__MonitoringReportStatus__state_struct MonitoringReportStatus;
    };
} FMonitorReportStatus__root__state_struct;

/// Contained in:
/// Subsystem - Train Detection System
/// Functional requirements specification
/// Subsystem - Train Detection System - Functional Viewpoint
/// Subsystem - Train Detection System - Functional Entities
typedef struct FMonitorReportStatus
{
    FMonitorReportStatus__root__state_struct state;

    // Messages -- Incoming
    MessagePort(Message__MsgTvpsOccupancyStatus__b4e1) InMsgTvpsOccupancyStatus__b4e1;
    MessagePort(Message__MsgTdpStatus__b6d9) InMsgTdpStatus__b6d9;
    MessagePort(Message__StartStatusReport__1e4e) InStartStatusReport__1e4e;
    // Messages -- Outgoing
    MessagePort(Message__StatusReportCompleted__b457) OutStatusReportCompleted__b457;

    // Change Events

    // Timeout Events

} FMonitorReportStatus;

void transition_FMonitorReportStatus(FMonitorReportStatus *self);
void transition_FMonitorReportStatus(FMonitorReportStatus *self);
void new_FMonitorReportStatus(FMonitorReportStatus *x);
