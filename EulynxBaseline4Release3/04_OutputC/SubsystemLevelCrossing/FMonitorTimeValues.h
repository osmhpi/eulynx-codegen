
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FMonitorTimeValues_D53outTimeExpiredValue
{
    FMonitorTimeValues_D53outTimeExpiredValue__NULL__,
    FMonitorTimeValues_D53outTimeExpiredValue__DelayExpired,
    FMonitorTimeValues_D53outTimeExpiredValue__DelayNotExpired,
    FMonitorTimeValues_D53outTimeExpiredValue__UNKNOWN__
} FMonitorTimeValues_D53outTimeExpiredValue;
typedef enum FMonitorTimeValues_D1inReceiveLcStateValue
{
    FMonitorTimeValues_D1inReceiveLcStateValue__NULL__,
    FMonitorTimeValues_D1inReceiveLcStateValue__Activated,
    FMonitorTimeValues_D1inReceiveLcStateValue__Isolated,
    FMonitorTimeValues_D1inReceiveLcStateValue__UNKNOWN__
} FMonitorTimeValues_D1inReceiveLcStateValue;
typedef enum FMonitorTimeValues_D3inLcpfProtectionStateValue
{
    FMonitorTimeValues_D3inLcpfProtectionStateValue__NULL__,
    FMonitorTimeValues_D3inLcpfProtectionStateValue__Idle,
    FMonitorTimeValues_D3inLcpfProtectionStateValue__UNKNOWN__
} FMonitorTimeValues_D3inLcpfProtectionStateValue;
typedef enum FMonitorTimeValues_D68inConFailureStatusAfterClosureTimeOverrunValue
{
    FMonitorTimeValues_D68inConFailureStatusAfterClosureTimeOverrunValue__NULL__,
    FMonitorTimeValues_D68inConFailureStatusAfterClosureTimeOverrunValue__NonCriticalFailureReport,
    FMonitorTimeValues_D68inConFailureStatusAfterClosureTimeOverrunValue__CriticalFailureReport,
    FMonitorTimeValues_D68inConFailureStatusAfterClosureTimeOverrunValue__UNKNOWN__
} FMonitorTimeValues_D68inConFailureStatusAfterClosureTimeOverrunValue;
typedef enum FMonitorTimeValues_D6outLcMonitoringStatusValue
{
    FMonitorTimeValues_D6outLcMonitoringStatusValue__NULL__,
    FMonitorTimeValues_D6outLcMonitoringStatusValue__NoClosureTimeOverrun,
    FMonitorTimeValues_D6outLcMonitoringStatusValue__ClosureTimeOverrunOccurred,
    FMonitorTimeValues_D6outLcMonitoringStatusValue__UNKNOWN__
} FMonitorTimeValues_D6outLcMonitoringStatusValue;
typedef enum FMonitorTimeValues_D75outLcFailureStatusValue
{
    FMonitorTimeValues_D75outLcFailureStatusValue__NULL__,
    FMonitorTimeValues_D75outLcFailureStatusValue__ANonCriticalFailureIsPresent,
    FMonitorTimeValues_D75outLcFailureStatusValue__ACriticalFailureIsPresent,
    FMonitorTimeValues_D75outLcFailureStatusValue__NoNonCriticalFailurePresent,
    FMonitorTimeValues_D75outLcFailureStatusValue__NoCriticalFailurePresent,
    FMonitorTimeValues_D75outLcFailureStatusValue__UNKNOWN__
} FMonitorTimeValues_D75outLcFailureStatusValue;
typedef enum FMonitorTimeValues_D51inEstEfesStateValue
{
    FMonitorTimeValues_D51inEstEfesStateValue__NULL__,
    FMonitorTimeValues_D51inEstEfesStateValue__FallbackMode,
    FMonitorTimeValues_D51inEstEfesStateValue__Operational,
    FMonitorTimeValues_D51inEstEfesStateValue__Booting,
    FMonitorTimeValues_D51inEstEfesStateValue__NoOperatingVoltage,
    FMonitorTimeValues_D51inEstEfesStateValue__Initialising,
    FMonitorTimeValues_D51inEstEfesStateValue__UNKNOWN__
} FMonitorTimeValues_D51inEstEfesStateValue;

typedef enum FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__state
{
    FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle,
    FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeIsRunning,
    FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeExpired
} FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__state;

typedef struct FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__state_struct
{
    FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__state state;
    union {
    };
} FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__state_struct;

typedef enum FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state
{
    FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Idle,
    FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__WaitingForDelay,
    FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__DelayReached,
    FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting
} FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state;

typedef struct FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state_struct
{
    FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state state;
    union {
    };
} FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state_struct;

typedef enum FMonitorTimeValues__root__state
{
    FMonitorTimeValues__root__WaitingForFinishBooting,
    FMonitorTimeValues__root__Fallbackmode,
    FMonitorTimeValues__root__TechnicalDisturbance,
    FMonitorTimeValues__root__MonitorTimeValues
} FMonitorTimeValues__root__state;

typedef struct FMonitorTimeValues__root__MonitorTimeValues__state_struct
{
    FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__state_struct MonitorClosureTime;
    FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state_struct PdiConLossDelay;
} FMonitorTimeValues__root__MonitorTimeValues__state_struct;

typedef struct FMonitorTimeValues__root__state_struct
{
    FMonitorTimeValues__root__state state;
    union {
        FMonitorTimeValues__root__MonitorTimeValues__state_struct MonitorTimeValues;
    };
} FMonitorTimeValues__root__state_struct;

/// Contained in:
/// Subsystem - Level Crossing
/// Functional requirements specification
/// Subsystem - Level Crossing - Functional Viewpoint
/// Subsystem - Level Crossing - Functional Entities
typedef struct FMonitorTimeValues
{
    FMonitorTimeValues__root__state_struct state;

    /// D64in_Con_Use_PDI_Con_Loss_Deactivation_Delay
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D64inConUsePdiConLossDeactivationDelay;

    /// D63in_Con_Use_Closure_Time
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D63inConUseClosureTime;

    /// D54in_Con_tmax_Closure_Time
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D54inConTmaxClosureTime;

    /// D56in_Con_t_PDI_Con_Loss_Deactivation_Delay
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D56inConTPdiConLossDeactivationDelay;

    /// d53out_Time_Expired
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FMonitorTimeValues_D53outTimeExpiredValue, ) D53outTimeExpired;

    /// d1in_Receive_LC_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FMonitorTimeValues_D1inReceiveLcStateValue, ) D1inReceiveLcState;

    /// d3in_LCPF_Protection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FMonitorTimeValues_D3inLcpfProtectionStateValue, ) D3inLcpfProtectionState;

    /// D68in_Con_Failure_Status_After_Closure_Time_Overrun
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FMonitorTimeValues_D68inConFailureStatusAfterClosureTimeOverrunValue, )
        D68inConFailureStatusAfterClosureTimeOverrun;

    /// d6out_LC_Monitoring_Status
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FMonitorTimeValues_D6outLcMonitoringStatusValue, ) D6outLcMonitoringStatus;

    /// d75out_LC_Failure_Status
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FMonitorTimeValues_D75outLcFailureStatusValue, ) D75outLcFailureStatus;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FMonitorTimeValues_D51inEstEfesStateValue, ) D51inEstEfesState;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change155; // d1in_Receive_LC_State = "Activated"
    ChangeEvent Change244; // d3in_LCPF_Protection_State = "Idle" OR
                           // d51in_EST_EfeS_State  = "FALLBACK_MODE"
    ChangeEvent Change243; // d3in_LCPF_Protection_State = "Idle" OR
                           // d51in_EST_EfeS_State  = "FALLBACK_MODE"
    ChangeEvent Change324; // d51in_EST_EfeS_State  = "OPERATIONAL"
    ChangeEvent Change326; // d51in_EST_EfeS_State  = "OPERATIONAL" OR
                           // d51in_EST_EfeS_State  = "BOOTING" OR
                           // d51in_EST_EfeS_State  = "NO_OPERATING_VOLTAGE"
    ChangeEvent Change376; // d51in_EST_EfeS_State = "OPERATIONAL"
    ChangeEvent Change321; // d51in_EST_EfeS_State  = "INITIALISING"

    // Timeout Events
    TimeoutEvent Time33;
    TimeoutEvent Time40;

} FMonitorTimeValues;

void transition_FMonitorTimeValues(FMonitorTimeValues *self);
void new_FMonitorTimeValues(FMonitorTimeValues *x);
