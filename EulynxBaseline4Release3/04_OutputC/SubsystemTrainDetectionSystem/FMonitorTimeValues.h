
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FMonitorTimeValues_D51outEstEfesStateValue
{
    FMonitorTimeValues_D51outEstEfesStateValue__NULL__,
    FMonitorTimeValues_D51outEstEfesStateValue__Booting,
    FMonitorTimeValues_D51outEstEfesStateValue__NoOperatingVoltage,
    FMonitorTimeValues_D51outEstEfesStateValue__FallbackMode,
    FMonitorTimeValues_D51outEstEfesStateValue__Initialising,
    FMonitorTimeValues_D51outEstEfesStateValue__UNKNOWN__
} FMonitorTimeValues_D51outEstEfesStateValue;

typedef enum FMonitorTimeValues__root__MonitorTimeValues__root__state
{
    FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring,
    FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime,
    FMonitorTimeValues__root__MonitorTimeValues__root__MonitorNotificationOfAvailability
} FMonitorTimeValues__root__MonitorTimeValues__root__state;

typedef struct FMonitorTimeValues__root__MonitorTimeValues__root__state_struct
{
    FMonitorTimeValues__root__MonitorTimeValues__root__state state;
    union {
    };
} FMonitorTimeValues__root__MonitorTimeValues__root__state_struct;

typedef enum FMonitorTimeValues__root__state
{
    FMonitorTimeValues__root__MonitorTimeValues,
    FMonitorTimeValues__root__WaitingForFinishBooting,
    FMonitorTimeValues__root__FallbackMode,
    FMonitorTimeValues__root__TechnicalDisturbance
} FMonitorTimeValues__root__state;

typedef struct FMonitorTimeValues__root__MonitorTimeValues__state_struct
{
    FMonitorTimeValues__root__MonitorTimeValues__root__state_struct root;
} FMonitorTimeValues__root__MonitorTimeValues__state_struct;

typedef struct FMonitorTimeValues__root__state_struct
{
    FMonitorTimeValues__root__state state;
    union {
        FMonitorTimeValues__root__MonitorTimeValues__state_struct MonitorTimeValues;
    };
} FMonitorTimeValues__root__state_struct;

/// Contained in:
/// Subsystem - Train Detection System
/// Functional requirements specification
/// Subsystem - Train Detection System - Functional Viewpoint
/// Subsystem - Train Detection System - Functional Entities
typedef struct FMonitorTimeValues
{
    FMonitorTimeValues__root__state_struct state;

    /// D28in_Con_t_Delay_Of_Notification_Of_Availability
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D28inConTDelayOfNotificationOfAvailability;

    /// D29in_Con_t_Inhibition_Time
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D29inConTInhibitionTime;

    /// D32in_Critical_Failure_TVPS
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D32inCriticalFailureTvps;

    /// d51out_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FMonitorTimeValues_D51outEstEfesStateValue, ) D51outEstEfesState;

    /// T37in_Wheel_In
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T37inWheelIn;

    /// T38in_Wheel_Out
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T38inWheelOut;

    /// T39in_Undefined_Pattern
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T39inUndefinedPattern;

    /// d16in_Last_Wheel_Out
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D16inLastWheelOut;

    /// d14out_Monitoring_Time
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D14outMonitoringTime;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change120;  // d16in_Last_Wheel_Out
    ChangeEvent Change1102; // T37in_Wheel_In OR T38in_Wheel_Out OR
                            // T39in_Undefined_Pattern
    ChangeEvent Change119;  // d16in_Last_Wheel_Out
    ChangeEvent Change1100; // T37in_Wheel_In OR T38in_Wheel_Out OR
                            // T39in_Undefined_Pattern
    ChangeEvent Change1101; // T37in_Wheel_In OR T38in_Wheel_Out OR
                            // T39in_Undefined_Pattern
    ChangeEvent Change233;  // D32in_Critical_Failure_TVPS
    ChangeEvent Change391;  // d51out_EST_EfeS_State = "BOOTING" OR
                            // d51out_EST_EfeS_State = "NO_OPERATING_VOLTAGE"
    ChangeEvent Change392;  // d51out_EST_EfeS_State = "FALLBACK_MODE"
    ChangeEvent Change402;  // d51out_EST_EfeS_State = "INITIALISING"
    ChangeEvent Change386;  // d51out_EST_EfeS_State = "BOOTING"
    ChangeEvent Change396;  // d51out_EST_EfeS_State = "FALLBACK_MODE"
    ChangeEvent Change562;  // NOT D32in_Critical_Failure_TVPS

    // Timeout Events
    TimeoutEvent Time20;
    TimeoutEvent Time19;

} FMonitorTimeValues;

void transition_FMonitorTimeValues(FMonitorTimeValues *self);
void new_FMonitorTimeValues(FMonitorTimeValues *x);
