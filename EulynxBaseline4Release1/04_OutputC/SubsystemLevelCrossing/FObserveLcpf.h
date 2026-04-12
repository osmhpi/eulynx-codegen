
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveLcpf_D30inStatusLcpfValue
{
    FObserveLcpf_D30inStatusLcpfValue__NULL__,
    FObserveLcpf_D30inStatusLcpfValue__Idle,
    FObserveLcpf_D30inStatusLcpfValue__Protected,
    FObserveLcpf_D30inStatusLcpfValue__Unprotected,
    FObserveLcpf_D30inStatusLcpfValue__ObstacleDetectedInTheConflictArea,
    FObserveLcpf_D30inStatusLcpfValue__NoObstacleInTheConflictArea,
    FObserveLcpf_D30inStatusLcpfValue__FailurePresent,
    FObserveLcpf_D30inStatusLcpfValue__NoFailurePresent,
    FObserveLcpf_D30inStatusLcpfValue__MonitoringParameterSet1,
    FObserveLcpf_D30inStatusLcpfValue__MonitoringParameterSet2,
    FObserveLcpf_D30inStatusLcpfValue__UNKNOWN__
} FObserveLcpf_D30inStatusLcpfValue;
typedef enum FObserveLcpf_D4outObstacleDetectionStatusValue
{
    FObserveLcpf_D4outObstacleDetectionStatusValue__NULL__,
    FObserveLcpf_D4outObstacleDetectionStatusValue__NoObstacleInTheConflictArea,
    FObserveLcpf_D4outObstacleDetectionStatusValue__ObstacleDetectedInTheConflictArea,
    FObserveLcpf_D4outObstacleDetectionStatusValue__UNKNOWN__
} FObserveLcpf_D4outObstacleDetectionStatusValue;
typedef enum FObserveLcpf_D3outLcpfProtectionStateValue
{
    FObserveLcpf_D3outLcpfProtectionStateValue__NULL__,
    FObserveLcpf_D3outLcpfProtectionStateValue__Unprotected,
    FObserveLcpf_D3outLcpfProtectionStateValue__Protected,
    FObserveLcpf_D3outLcpfProtectionStateValue__Idle,
    FObserveLcpf_D3outLcpfProtectionStateValue__UNKNOWN__
} FObserveLcpf_D3outLcpfProtectionStateValue;
typedef enum FObserveLcpf_D6outLcpfFailureStateValue
{
    FObserveLcpf_D6outLcpfFailureStateValue__NULL__,
    FObserveLcpf_D6outLcpfFailureStateValue__NoFailurePresent,
    FObserveLcpf_D6outLcpfFailureStateValue__FailurePresent,
    FObserveLcpf_D6outLcpfFailureStateValue__UNKNOWN__
} FObserveLcpf_D6outLcpfFailureStateValue;
typedef enum FObserveLcpf_D9outChangedMonitoringStateValue
{
    FObserveLcpf_D9outChangedMonitoringStateValue__NULL__,
    FObserveLcpf_D9outChangedMonitoringStateValue__MonitoringParameterSet2,
    FObserveLcpf_D9outChangedMonitoringStateValue__MonitoringParameterSet1,
    FObserveLcpf_D9outChangedMonitoringStateValue__UNKNOWN__
} FObserveLcpf_D9outChangedMonitoringStateValue;

typedef enum FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__state
{
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected,
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Protected,
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Idle
} FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__state;

typedef struct FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__state_struct
{
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__state state;
    union {
    };
} FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__state_struct;

typedef enum FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__state
{
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__NoObstacleInConflictArea,
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__ObstacleInConflictArea,
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__Waiting
} FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__state;

typedef struct FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__state_struct
{
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__state state;
    union {
    };
} FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__state_struct;

typedef enum FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__state
{
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__NoFailureDetected,
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__FailureDetected,
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__Waiting
} FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__state;

typedef struct FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__state_struct
{
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__state state;
    union {
    };
} FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__state_struct;

typedef enum FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__state
{
    FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet2,
    FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet1
} FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__state;

typedef struct FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__state_struct
{
    FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__state state;
    union {
    };
} FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__state_struct;

typedef enum FObserveLcpf__root__state
{
    FObserveLcpf__root__ObserveLcpf
} FObserveLcpf__root__state;

typedef struct FObserveLcpf__root__ObserveLcpf__state_struct
{
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__state_struct ObserveLcpfProtectionState;
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__state_struct ObserveLcpfObstacleDetectionState;
    FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__state_struct ObserveLcpfFailureState;
    FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__state_struct ObserveMonitoringStatus;
} FObserveLcpf__root__ObserveLcpf__state_struct;

typedef struct FObserveLcpf__root__state_struct
{
    FObserveLcpf__root__state state;
    union {
        FObserveLcpf__root__ObserveLcpf__state_struct ObserveLcpf;
    };
} FObserveLcpf__root__state_struct;

/// Contained in:
/// Subsystem Level Crossing
/// Functional requirements specification
/// Subsystem Level Crossing - Functional Viewpoint
/// Subsystem Level Crossing - Functional Entities
typedef struct FObserveLcpf
{
    FObserveLcpf__root__state_struct state;

    /// D30in_Status_LCPF
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveLcpf_D30inStatusLcpfValue, ) D30inStatusLcpf;

    /// d4out_Obstacle_Detection_Status
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveLcpf_D4outObstacleDetectionStatusValue, ) D4outObstacleDetectionStatus;

    /// d3out_LCPF_Protection_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveLcpf_D3outLcpfProtectionStateValue, ) D3outLcpfProtectionState;

    /// d6out_LCPF_Failure_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveLcpf_D6outLcpfFailureStateValue, ) D6outLcpfFailureState;

    /// d9out_Changed_Monitoring_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveLcpf_D9outChangedMonitoringStateValue, ) D9outChangedMonitoringState;

    /// D109in_Con_Use_Obstacle_Detection
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D109inConUseObstacleDetection;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change220; // D30in_Status_LCPF = "Idle"
    ChangeEvent Change228; // D30in_Status_LCPF = "Protected"
    ChangeEvent Change216; // D30in_Status_LCPF = "Idle"
    ChangeEvent Change231; // D30in_Status_LCPF = "Unprotected"
    ChangeEvent Change230; // D30in_Status_LCPF = "Protected"
    ChangeEvent Change232; // D30in_Status_LCPF = "Unprotected"
    ChangeEvent
        Change226; // D30in_Status_LCPF = "Obstacle detected in the conflict area" AND D109in_Con_Use_Obstacle_Detection
    ChangeEvent
        Change225; // D30in_Status_LCPF = "No obstacle in the conflict area" AND D109in_Con_Use_Obstacle_Detection
    ChangeEvent
        Change224; // D30in_Status_LCPF = "No obstacle in the conflict area" AND D109in_Con_Use_Obstacle_Detection
    ChangeEvent
        Change227; // D30in_Status_LCPF = "Obstacle detected in the conflict area" AND D109in_Con_Use_Obstacle_Detection
    ChangeEvent Change214; // D30in_Status_LCPF = "Failure present"
    ChangeEvent Change223; // D30in_Status_LCPF = "No failure present"
    ChangeEvent Change1;   //  D30in_Status_LCPF = "Failure present"
    ChangeEvent Change222; // D30in_Status_LCPF = "No failure present"
    ChangeEvent Change213; // D30in_Status_LCPF  = "Monitoring Parameter Set 1"
    ChangeEvent Change221; // D30in_Status_LCPF = "Monitoring Parameter Set 2"

    // Timeout Events

} FObserveLcpf;

void transition_FObserveLcpf(FObserveLcpf *self);
void new_FObserveLcpf(FObserveLcpf *x);
