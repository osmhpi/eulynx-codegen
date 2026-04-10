
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveLcpf_D30inLcpfProtectionStateValue
{
    FObserveLcpf_D30inLcpfProtectionStateValue__NULL__,
    FObserveLcpf_D30inLcpfProtectionStateValue__Idle,
    FObserveLcpf_D30inLcpfProtectionStateValue__Protected,
    FObserveLcpf_D30inLcpfProtectionStateValue__Unprotected,
    FObserveLcpf_D30inLcpfProtectionStateValue__UNKNOWN__
} FObserveLcpf_D30inLcpfProtectionStateValue;
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
typedef enum FObserveLcpf_D74outLcpfFailureStateValue
{
    FObserveLcpf_D74outLcpfFailureStateValue__NULL__,
    FObserveLcpf_D74outLcpfFailureStateValue__NoFailurePresent,
    FObserveLcpf_D74outLcpfFailureStateValue__FailurePresent,
    FObserveLcpf_D74outLcpfFailureStateValue__UNKNOWN__
} FObserveLcpf_D74outLcpfFailureStateValue;
typedef enum FObserveLcpf_D9outChangedMonitoringStateValue
{
    FObserveLcpf_D9outChangedMonitoringStateValue__NULL__,
    FObserveLcpf_D9outChangedMonitoringStateValue__MonitoringParameterSet2,
    FObserveLcpf_D9outChangedMonitoringStateValue__MonitoringParameterSet1,
    FObserveLcpf_D9outChangedMonitoringStateValue__UNKNOWN__
} FObserveLcpf_D9outChangedMonitoringStateValue;
typedef enum FObserveLcpf_D33inMonitoringStateValue
{
    FObserveLcpf_D33inMonitoringStateValue__NULL__,
    FObserveLcpf_D33inMonitoringStateValue__MonitoringParameterSet1,
    FObserveLcpf_D33inMonitoringStateValue__MonitoringParameterSet2,
    FObserveLcpf_D33inMonitoringStateValue__UNKNOWN__
} FObserveLcpf_D33inMonitoringStateValue;

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

    /// D30in_LCPF_Protection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveLcpf_D30inLcpfProtectionStateValue, ) D30inLcpfProtectionState;

    /// d4out_Obstacle_Detection_Status
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveLcpf_D4outObstacleDetectionStatusValue, ) D4outObstacleDetectionStatus;

    /// d3out_LCPF_Protection_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveLcpf_D3outLcpfProtectionStateValue, ) D3outLcpfProtectionState;

    /// d74out_LCPF_Failure_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveLcpf_D74outLcpfFailureStateValue, ) D74outLcpfFailureState;

    /// d9out_Changed_Monitoring_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveLcpf_D9outChangedMonitoringStateValue, ) D9outChangedMonitoringState;

    /// D109in_Con_Use_Obstacle_Detection
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D109inConUseObstacleDetection;

    /// D31in_Obstacle_Detection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D31inObstacleDetectionState;

    /// D32in_LCPF_Failure_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D32inLcpfFailureState;

    /// D33in_Monitoring_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveLcpf_D33inMonitoringStateValue, ) D33inMonitoringState;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change230; // D30in_LCPF_Protection_State = "Idle"
    ChangeEvent Change233; // D30in_LCPF_Protection_State = "Protected"
    ChangeEvent Change231; // D30in_LCPF_Protection_State = "Idle"
    ChangeEvent Change237; // D30in_LCPF_Protection_State = "Unprotected"
    ChangeEvent Change232; // D30in_LCPF_Protection_State = "Protected"
    ChangeEvent Change235; // D30in_LCPF_Protection_State = "Unprotected"
    ChangeEvent Change249; // D31in_Obstacle_Detection_State
    ChangeEvent Change566; // NOT D31in_Obstacle_Detection_State
    ChangeEvent Change248; // D31in_Obstacle_Detection_State
    ChangeEvent Change567; // NOT D31in_Obstacle_Detection_State
    ChangeEvent Change260; // D32in_LCPF_Failure_State
    ChangeEvent Change571; // NOT D32in_LCPF_Failure_State
    ChangeEvent Change1;   //  D32in_LCPF_Failure_State
    ChangeEvent Change572; // NOT D32in_LCPF_Failure_State
    ChangeEvent Change2;   //  D33in_Monitoring_State = "Monitoring Parameter Set 1"
    ChangeEvent Change261; // D33in_Monitoring_State = "Monitoring Parameter Set 2"

    // Timeout Events

} FObserveLcpf;

void transition_FObserveLcpf(FObserveLcpf *self);
void new_FObserveLcpf(FObserveLcpf *x);
