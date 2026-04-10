
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciLcReceive_D5outMsgLcFunctionalStatusValue {
  SSciLcReceive_D5outMsgLcFunctionalStatusValue__NULL__,
  SSciLcReceive_D5outMsgLcFunctionalStatusValue__IsolatedLc,
  SSciLcReceive_D5outMsgLcFunctionalStatusValue__PreActivated,
  SSciLcReceive_D5outMsgLcFunctionalStatusValue__ActivatedAndProtected,
  SSciLcReceive_D5outMsgLcFunctionalStatusValue__ActivatedAndUnprotected,
  SSciLcReceive_D5outMsgLcFunctionalStatusValue__DeactivatedAndUnprotected,
  SSciLcReceive_D5outMsgLcFunctionalStatusValue__UNKNOWN__
} SSciLcReceive_D5outMsgLcFunctionalStatusValue;
typedef enum SSciLcReceive_D91outMsgObstacleDetectionStatusValue {
  SSciLcReceive_D91outMsgObstacleDetectionStatusValue__NULL__,
  SSciLcReceive_D91outMsgObstacleDetectionStatusValue__ObstacleDetectedInTheConflictArea,
  SSciLcReceive_D91outMsgObstacleDetectionStatusValue__NoObstacleInTheConflictArea,
  SSciLcReceive_D91outMsgObstacleDetectionStatusValue__UNKNOWN__
} SSciLcReceive_D91outMsgObstacleDetectionStatusValue;
typedef enum SSciLcReceive_D72outMsgLcFailureStatusCriticalValue {
  SSciLcReceive_D72outMsgLcFailureStatusCriticalValue__NULL__,
  SSciLcReceive_D72outMsgLcFailureStatusCriticalValue__ACriticalFailureIsPresent,
  SSciLcReceive_D72outMsgLcFailureStatusCriticalValue__NoCriticalFailureIsPresent,
  SSciLcReceive_D72outMsgLcFailureStatusCriticalValue__UNKNOWN__
} SSciLcReceive_D72outMsgLcFailureStatusCriticalValue;
typedef enum SSciLcReceive_D18outMsgDetectionElementStatusValue {
  SSciLcReceive_D18outMsgDetectionElementStatusValue__NULL__,
  SSciLcReceive_D18outMsgDetectionElementStatusValue__Failed,
  SSciLcReceive_D18outMsgDetectionElementStatusValue__Occupied,
  SSciLcReceive_D18outMsgDetectionElementStatusValue__Vacant,
  SSciLcReceive_D18outMsgDetectionElementStatusValue__UNKNOWN__
} SSciLcReceive_D18outMsgDetectionElementStatusValue;
typedef enum SSciLcReceive_D9outMsgLocalOperationHandoverValue {
  SSciLcReceive_D9outMsgLocalOperationHandoverValue__NULL__,
  SSciLcReceive_D9outMsgLocalOperationHandoverValue__AllowHandoverToLocalOperator,
  SSciLcReceive_D9outMsgLocalOperationHandoverValue__ReturnHandoverFromLocalOperator,
  SSciLcReceive_D9outMsgLocalOperationHandoverValue__UNKNOWN__
} SSciLcReceive_D9outMsgLocalOperationHandoverValue;
typedef enum SSciLcReceive_D61outMsgLcMonitoringStatusClosureTimerValue {
  SSciLcReceive_D61outMsgLcMonitoringStatusClosureTimerValue__NULL__,
  SSciLcReceive_D61outMsgLcMonitoringStatusClosureTimerValue__ClosureTimerOverrunOccurred,
  SSciLcReceive_D61outMsgLcMonitoringStatusClosureTimerValue__NoClosureTimerOverrun,
  SSciLcReceive_D61outMsgLcMonitoringStatusClosureTimerValue__UNKNOWN__
} SSciLcReceive_D61outMsgLcMonitoringStatusClosureTimerValue;
typedef enum SSciLcReceive_D8outMsgLocalRequestValue {
  SSciLcReceive_D8outMsgLocalRequestValue__NULL__,
  SSciLcReceive_D8outMsgLocalRequestValue__LocalRequestToActivateTheLevelCrossing,
  SSciLcReceive_D8outMsgLocalRequestValue__LocalRequestToDeactivateTheLevelCrossing,
  SSciLcReceive_D8outMsgLocalRequestValue__UNKNOWN__
} SSciLcReceive_D8outMsgLocalRequestValue;
typedef enum SSciLcReceive_D71outMsgLcFailureStatusNonCriticalValue {
  SSciLcReceive_D71outMsgLcFailureStatusNonCriticalValue__NULL__,
  SSciLcReceive_D71outMsgLcFailureStatusNonCriticalValue__ANonCriticalFailureIsPresent,
  SSciLcReceive_D71outMsgLcFailureStatusNonCriticalValue__NoNonCriticalFailureIsPresent,
  SSciLcReceive_D71outMsgLcFailureStatusNonCriticalValue__UNKNOWN__
} SSciLcReceive_D71outMsgLcFailureStatusNonCriticalValue;
typedef enum SSciLcReceive_D62outMsgLcMonitoringStatusChangedMonitoringParameterValue {
  SSciLcReceive_D62outMsgLcMonitoringStatusChangedMonitoringParameterValue__NULL__,
  SSciLcReceive_D62outMsgLcMonitoringStatusChangedMonitoringParameterValue__MonitoringParameterSet1,
  SSciLcReceive_D62outMsgLcMonitoringStatusChangedMonitoringParameterValue__MonitoringParameterSet2,
  SSciLcReceive_D62outMsgLcMonitoringStatusChangedMonitoringParameterValue__UNKNOWN__
} SSciLcReceive_D62outMsgLcMonitoringStatusChangedMonitoringParameterValue;

typedef enum SSciLcReceive__root__state {
  SSciLcReceive__root__ReceivingLcReports
} SSciLcReceive__root__state;

typedef struct SSciLcReceive__root__state_struct {
  SSciLcReceive__root__state state;
  union {};
} SSciLcReceive__root__state_struct;

/// Contained in:
/// Subsystem Level Crossing
/// Functional requirements specification
/// Subsystem Level Crossing - Interfaces
/// SCI-LC (Subsystem -  Electronic Interlocking)
/// SCI-LC - Functional Viewpoint
/// SCI-LC - Functional Entities
typedef struct SSciLcReceive {
  SSciLcReceive__root__state_struct state;

  /// d5out_Msg_LC_Functional_Status
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciLcReceive_D5outMsgLcFunctionalStatusValue, )
      D5outMsgLcFunctionalStatus;

  /// t5out_Msg_LC_Functional_Status
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T5outMsgLcFunctionalStatus;

  /// t91out_Msg_Obstacle_Detection_Status
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T91outMsgObstacleDetectionStatus;

  /// d91out_Msg_Obstacle_Detection_Status
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciLcReceive_D91outMsgObstacleDetectionStatusValue, )
      D91outMsgObstacleDetectionStatus;

  /// t7out_Msg_LC_Failure_Status
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T7outMsgLcFailureStatus;

  /// d72out_Msg_LC_Failure_Status_Critical
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciLcReceive_D72outMsgLcFailureStatusCriticalValue, )
      D72outMsgLcFailureStatusCritical;

  /// t18out_Msg_Detection_Element_Status
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T18outMsgDetectionElementStatus;

  /// d18out_Msg_Detection_Element_Status
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciLcReceive_D18outMsgDetectionElementStatusValue, )
      D18outMsgDetectionElementStatus;

  /// t9out_Msg_Local_Operation_Handover
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T9outMsgLocalOperationHandover;

  /// d9out_Msg_Local_Operation_Handover
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciLcReceive_D9outMsgLocalOperationHandoverValue, )
      D9outMsgLocalOperationHandover;

  /// d61out_Msg_LC_Monitoring_Status_Closure_timer
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciLcReceive_D61outMsgLcMonitoringStatusClosureTimerValue, )
      D61outMsgLcMonitoringStatusClosureTimer;

  /// t6out_Msg_LC_Monitoring_Status
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T6outMsgLcMonitoringStatus;

  /// d8out_Msg_Local_Request
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciLcReceive_D8outMsgLocalRequestValue, ) D8outMsgLocalRequest;

  /// t8out_Msg_Local_Request
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T8outMsgLocalRequest;

  /// d50in_PDI_Connection_State
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(void *, ) D50inPdiConnectionState;

  /// d71out_Msg_LC_Failure_Status_Non_Critical
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciLcReceive_D71outMsgLcFailureStatusNonCriticalValue, )
      D71outMsgLcFailureStatusNonCritical;

  /// d62out_Msg_LC_Monitoring_Status_Changed_Monitoring_Parameter
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(
      SSciLcReceive_D62outMsgLcMonitoringStatusChangedMonitoringParameterValue, )
      D62outMsgLcMonitoringStatusChangedMonitoringParameter;

  // Messages -- Incoming
  MessagePort(Message__MsgDetectionElementStatus__aa8b)
      InMsgDetectionElementStatus__aa8b;
  MessagePort(Message__MsgLcFailureStatus__5440) InMsgLcFailureStatus__5440;
  MessagePort(Message__MsgLcFunctionalStatus__ab8c)
      InMsgLcFunctionalStatus__ab8c;
  MessagePort(Message__MsgLcMonitoringStatus__1d45)
      InMsgLcMonitoringStatus__1d45;
  MessagePort(Message__MsgLocalOperationHandover__0594)
      InMsgLocalOperationHandover__0594;
  MessagePort(Message__MsgLocalRequest__daeb) InMsgLocalRequest__daeb;
  MessagePort(Message__MsgObstacleDetectionStatus__734d)
      InMsgObstacleDetectionStatus__734d;
  // Messages -- Outgoing

  // Change Events

  // Timeout Events

} SSciLcReceive;

void transition_SSciLcReceive(SSciLcReceive *self);
void new_SSciLcReceive(SSciLcReceive *x);
