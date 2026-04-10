
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FControlTimer_D51outEstEfesStateValue
{
    FControlTimer_D51outEstEfesStateValue__NULL__,
    FControlTimer_D51outEstEfesStateValue__Booting,
    FControlTimer_D51outEstEfesStateValue__NoOperatingVoltage,
    FControlTimer_D51outEstEfesStateValue__FallbackMode,
    FControlTimer_D51outEstEfesStateValue__Initialising,
    FControlTimer_D51outEstEfesStateValue__UNKNOWN__
} FControlTimer_D51outEstEfesStateValue;

typedef enum FControlTimer__root__ObserveTimer__root__state
{
    FControlTimer__root__ObserveTimer__root__NoTimer,
    FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer,
    FControlTimer__root__ObserveTimer__root__NotificationOfAvailabilityRunningTimer
} FControlTimer__root__ObserveTimer__root__state;

typedef struct FControlTimer__root__ObserveTimer__root__state_struct
{
    FControlTimer__root__ObserveTimer__root__state state;
    union {
    };
} FControlTimer__root__ObserveTimer__root__state_struct;

typedef enum FControlTimer__root__state
{
    FControlTimer__root__ObserveTimer,
    FControlTimer__root__WaitingForFinishBooting,
    FControlTimer__root__FallbackMode,
    FControlTimer__root__TechnicalDisturbance
} FControlTimer__root__state;

typedef struct FControlTimer__root__ObserveTimer__state_struct
{
    FControlTimer__root__ObserveTimer__root__state_struct root;
} FControlTimer__root__ObserveTimer__state_struct;

typedef struct FControlTimer__root__state_struct
{
    FControlTimer__root__state state;
    union {
        FControlTimer__root__ObserveTimer__state_struct ObserveTimer;
    };
} FControlTimer__root__state_struct;

/// Contained in:
/// Subsystem Train Detection System
/// Functional requirements specification
/// Subsystem Train Detection System - Functional Viewpoint
/// Subsystem Train Detection System - Functional Entities
typedef struct FControlTimer
{
    FControlTimer__root__state_struct state;

    /// D28in_Con_t_Delay_Of_Notification_Of_Availability
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D28inConTDelayOfNotificationOfAvailability;

    /// D29in_Con_t_Inhibition_Timer
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D29inConTInhibitionTimer;

    /// D32in_Critical_Failure_TVPS
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D32inCriticalFailureTvps;

    /// d51out_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FControlTimer_D51outEstEfesStateValue, ) D51outEstEfesState;

    /// T37in_Wheel_In
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T37inWheelIn;

    /// T38in_Wheel_Out
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T38inWheelOut;

    /// T39in_Undefined_Pattern
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T39inUndefinedPattern;

    /// d8in_Last_Wheel_Out
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D8inLastWheelOut;

    /// d14out_Running_Timer
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D14outRunningTimer;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change492;  // d8in_Last_Wheel_Out
    ChangeEvent Change1109; // T37in_Wheel_In OR T38in_Wheel_Out OR
                            // T39in_Undefined_Pattern
    ChangeEvent Change493;  // d8in_Last_Wheel_Out
    ChangeEvent Change1107; // T37in_Wheel_In OR T38in_Wheel_Out OR
                            // T39in_Undefined_Pattern
    ChangeEvent Change1108; // T37in_Wheel_In OR T38in_Wheel_Out OR
                            // T39in_Undefined_Pattern
    ChangeEvent Change255;  // D32in_Critical_Failure_TVPS
    ChangeEvent Change410;  // d51out_EST_EfeS_State = "BOOTING" OR
                            // d51out_EST_EfeS_State = "NO_OPERATING_VOLTAGE"
    ChangeEvent Change415;  // d51out_EST_EfeS_State = "FALLBACK_MODE"
    ChangeEvent Change422;  // d51out_EST_EfeS_State = "INITIALISING"
    ChangeEvent Change407;  // d51out_EST_EfeS_State = "BOOTING"
    ChangeEvent Change413;  // d51out_EST_EfeS_State = "FALLBACK_MODE"
    ChangeEvent Change568;  // NOT D32in_Critical_Failure_TVPS

    // Timeout Events
    TimeoutEvent Time20;
    TimeoutEvent Time19;

} FControlTimer;

void transition_FControlTimer(FControlTimer *self);
void new_FControlTimer(FControlTimer *x);
