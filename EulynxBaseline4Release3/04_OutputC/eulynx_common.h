
#pragma once
#include <stdbool.h>
#include <string.h>
// For abort()
#include <stdlib.h>
// For fprintf()
#include <stdio.h>

#define MessagePort(X)                                                         \
  struct {                                                                     \
    bool HasMessage;                                                           \
    X Value;                                                                   \
  }
#define DataPort(X, Y)                                                         \
  struct {                                                                     \
    bool IsSignalled;                                                          \
    X Value Y;                                                                 \
  }

typedef struct PulsedIn {
  bool IsTriggered;
} PulsedIn;

typedef struct PulsedOut {
  bool Trigger;
} PulsedOut;

typedef struct ChangeOp {
  bool T;
  bool V;
} ChangeOp;

static inline ChangeOp AndChange(ChangeOp lhs, ChangeOp rhs) {
  ChangeOp result = {.T = lhs.T || rhs.T, .V = lhs.V && rhs.V};
  return result;
}

static inline ChangeOp OrChange(ChangeOp lhs, ChangeOp rhs) {
  ChangeOp result = {.T = lhs.V && lhs.T || rhs.V && rhs.T,
                     .V = lhs.V || rhs.V};
  return result;
}

static inline ChangeOp NegateChange(ChangeOp c) {
  ChangeOp result = {.T = c.T, .V = !c.V};
  return result;
}

static inline ChangeOp MakeChange(bool t, bool v) {
  ChangeOp result = {.T = t, .V = v};
  return result;
}

static inline bool IsTriggered(ChangeOp op) { return op.T && op.V; }

typedef struct ChangeEvent {
  int IsTriggered;
} ChangeEvent;

typedef struct TimeoutEvent {
  int IsTimeoutExpired;
} TimeoutEvent;

// Enumerations
/// CloseReason
/// UML Identifier: _91bc5244-d0e5-400e-97d6-a58fee012f92
typedef enum CloseReason__91bc {
  /// NormalClose
  CloseReason__91bc__NormalClose,

  /// OtherVersionRequired
  CloseReason__91bc__OtherVersionRequired,

  /// Timeout
  CloseReason__91bc__Timeout,

  /// ProtocolError
  CloseReason__91bc__ProtocolError,

  /// FormalTelegramError
  CloseReason__91bc__FormalTelegramError,

  /// ContentTelegramError
  CloseReason__91bc__ContentTelegramError,

  /// ChecksumMismatch
  CloseReason__91bc__ChecksumMismatch
} CloseReason__91bc;

/// ResetReason
/// UML Identifier: _44e34330-fd9d-40cf-8e47-c92e60f22d50
typedef enum ResetReason__44e3 {
  /// ProtocolError
  ResetReason__44e3__ProtocolError,

  /// FormalTelegramError
  ResetReason__44e3__FormalTelegramError,

  /// ContentTelegramError
  ResetReason__44e3__ContentTelegramError
} ResetReason__44e3;

/// Line_Direction_Control_Information
/// UML Identifier: _531ba801-8472-4e66-8ae6-34d00ee97342
typedef enum LineDirectionControlInformation__531b {
  /// exitHandover
  LineDirectionControlInformation__531b__Exithandover,

  /// exitRequest
  LineDirectionControlInformation__531b__Exitrequest,

  /// exitRequestRejected
  LineDirectionControlInformation__531b__Exitrequestrejected,

  /// exit
  LineDirectionControlInformation__531b__Exit,

  /// entry
  LineDirectionControlInformation__531b__Entry
} LineDirectionControlInformation__531b;

/// LineDirectionState
/// UML Identifier: _288d9e39-ab0c-4125-b1f3-0880a60f1dfe
typedef enum LineDirectionState__288d {
  /// Entry
  LineDirectionState__288d__Entry,

  /// Exit
  LineDirectionState__288d__Exit
} LineDirectionState__288d;

/// Access Restriction Type values
/// UML Identifier: _ec2544c1-eab5-4fa7-9916-f1e75631adea
typedef enum AccessRestrictionTypeValues__ec25 {
  /// no access
  AccessRestrictionTypeValues__ec25__NoAccess,

  /// work track
  AccessRestrictionTypeValues__ec25__WorkTrack,

  /// track out of service
  AccessRestrictionTypeValues__ec25__TrackOutOfService,

  /// emergency train
  AccessRestrictionTypeValues__ec25__EmergencyTrain,

  /// secondary vehicle
  AccessRestrictionTypeValues__ec25__SecondaryVehicle,

  /// work team
  AccessRestrictionTypeValues__ec25__WorkTeam,

  /// level crossing in degraded operation
  AccessRestrictionTypeValues__ec25__LevelCrossingInDegradedOperation,

  /// clearance check required
  AccessRestrictionTypeValues__ec25__ClearanceCheckRequired,

  /// section check required
  AccessRestrictionTypeValues__ec25__SectionCheckRequired,

  /// no electric trains
  AccessRestrictionTypeValues__ec25__NoElectricTrains,

  /// extraordinary transport
  AccessRestrictionTypeValues__ec25__ExtraordinaryTransport,

  /// catenary off / pantograph down
  AccessRestrictionTypeValues__ec25__CatenaryOffOrPantographDown,

  /// written order required
  AccessRestrictionTypeValues__ec25__WrittenOrderRequired,

  /// manual route condition
  AccessRestrictionTypeValues__ec25__ManualRouteCondition,

  /// do not use opposite direction
  AccessRestrictionTypeValues__ec25__DoNotUseOppositeDirection,

  /// use opposite direction
  AccessRestrictionTypeValues__ec25__UseOppositeDirection,

  /// no LX remote supervision
  AccessRestrictionTypeValues__ec25__NoLxRemoteSupervision,

  /// LX remote supervision timeout
  AccessRestrictionTypeValues__ec25__LxRemoteSupervisionTimeout,

  /// not applicable
  AccessRestrictionTypeValues__ec25__NotApplicable
} AccessRestrictionTypeValues__ec25;

/// Activation Status values
/// UML Identifier: _c64a3397-40ff-4502-a855-51b816616034
typedef enum ActivationStatusValues__c64a {
  /// not active
  ActivationStatusValues__c64a__NotActive,

  /// active
  ActivationStatusValues__c64a__Active
} ActivationStatusValues__c64a;

/// Dynamic or Static Target Speed values
/// UML Identifier: _d34afb03-584c-4e22-bf56-0e3ea40b0aa1
typedef enum DynamicOrStaticTargetSpeedValues__d34a {
  /// dynamic
  DynamicOrStaticTargetSpeedValues__d34a__Dynamic,

  /// static
  DynamicOrStaticTargetSpeedValues__d34a__Static,

  /// not applicable
  DynamicOrStaticTargetSpeedValues__d34a__NotApplicable
} DynamicOrStaticTargetSpeedValues__d34a;

/// Flank Protection Request values
/// UML Identifier: _d52c928a-1e1e-44ae-9f80-ae58b43e47f6
typedef enum FlankProtectionRequestValues__d52c {
  /// provision
  FlankProtectionRequestValues__d52c__Provision,

  /// cancellation
  FlankProtectionRequestValues__d52c__Cancellation
} FlankProtectionRequestValues__d52c;

/// Flank Protection Status values
/// UML Identifier: _6fea58ff-9dd0-4350-8080-1fff8abf940c
typedef enum FlankProtectionStatusValues__6fea {
  /// provided
  FlankProtectionStatusValues__6fea__Provided,

  /// not provided
  FlankProtectionStatusValues__6fea__NotProvided
} FlankProtectionStatusValues__6fea;

/// Level Crossing Monitoring values
/// UML Identifier: _9e1720d5-b17b-40f8-a0eb-f01a9a8bb8bd
typedef enum LevelCrossingMonitoringValues__9e17 {
  /// present
  LevelCrossingMonitoringValues__9e17__Present,

  /// not present
  LevelCrossingMonitoringValues__9e17__NotPresent,

  /// present up to next block indicator
  LevelCrossingMonitoringValues__9e17__PresentUpToNextBlockIndicator,

  /// not applicable
  LevelCrossingMonitoringValues__9e17__NotApplicable
} LevelCrossingMonitoringValues__9e17;

/// Line Direction Control Information
/// UML Identifier: _30e7601a-e9c8-44f3-955a-05c0d7e53219
typedef enum LineDirectionControlInformation__30e7 {
  /// no direction
  LineDirectionControlInformation__30e7__NoDirection,

  /// entry
  LineDirectionControlInformation__30e7__Entry,

  /// exit
  LineDirectionControlInformation__30e7__Exit,

  /// direction request
  LineDirectionControlInformation__30e7__DirectionRequest,

  /// direction handover
  LineDirectionControlInformation__30e7__DirectionHandover,

  /// direction handover aborted
  LineDirectionControlInformation__30e7__DirectionHandoverAborted,

  /// disable line block direction
  LineDirectionControlInformation__30e7__DisableLineBlockDirection,

  /// enable line block direction
  LineDirectionControlInformation__30e7__EnableLineBlockDirection
} LineDirectionControlInformation__30e7;

/// Line Direction Status
/// UML Identifier: _28852db9-7210-43af-a124-3c6cb48757d7
typedef enum LineDirectionStatus__2885 {
  /// released
  LineDirectionStatus__2885__Released,

  /// locked
  LineDirectionStatus__2885__Locked,

  /// line block direction disabled
  LineDirectionStatus__2885__LineBlockDirectionDisabled,

  /// not applicable
  LineDirectionStatus__2885__NotApplicable
} LineDirectionStatus__2885;

/// Line Status values
/// UML Identifier: _594d00a4-0927-4166-a2b8-15844d565e50
typedef enum LineStatusValues__594d {
  /// vacant
  LineStatusValues__594d__Vacant,

  /// occupied
  LineStatusValues__594d__Occupied,

  /// request for line block reset
  LineStatusValues__594d__RequestForLineBlockReset,

  /// rejected
  LineStatusValues__594d__Rejected
} LineStatusValues__594d;

/// Pretest Response values
/// UML Identifier: _3b4f71e8-08e5-45de-9dd7-98192ca184ab
typedef enum PretestResponseValues__3b4f {
  /// possible and vacant
  PretestResponseValues__3b4f__PossibleAndVacant,

  /// possible and occupied
  PretestResponseValues__3b4f__PossibleAndOccupied,

  /// queue
  PretestResponseValues__3b4f__Queue,

  /// rejected
  PretestResponseValues__3b4f__Rejected
} PretestResponseValues__3b4f;

/// Route Monitoring values
/// UML Identifier: _f524894c-2ac5-4300-81e6-98ddc05d28d7
typedef enum RouteMonitoringValues__f524 {
  /// present
  RouteMonitoringValues__f524__Present,

  /// not present
  RouteMonitoringValues__f524__NotPresent,

  /// present up to next block indicator
  RouteMonitoringValues__f524__PresentUpToNextBlockIndicator,

  /// shunting conditions present
  RouteMonitoringValues__f524__ShuntingConditionsPresent
} RouteMonitoringValues__f524;

/// Route Occupancy Monitoring values
/// UML Identifier: _f70738b0-4892-422a-b8a0-0666729465d4
typedef enum RouteOccupancyMonitoringValues__f707 {
  /// occupation
  RouteOccupancyMonitoringValues__f707__Occupation,

  /// no occupation
  RouteOccupancyMonitoringValues__f707__NoOccupation,

  /// not applicable
  RouteOccupancyMonitoringValues__f707__NotApplicable
} RouteOccupancyMonitoringValues__f707;

/// Route Release Inhibition Status values
/// UML Identifier: _2795b6be-91a4-400f-b7d9-8a2e71e9463a
typedef enum RouteReleaseInhibitionStatusValues__2795 {
  /// deactivated
  RouteReleaseInhibitionStatusValues__2795__Deactivated,

  /// activated
  RouteReleaseInhibitionStatusValues__2795__Activated
} RouteReleaseInhibitionStatusValues__2795;

/// Route Status values
/// UML Identifier: _075813cd-6a66-45af-8028-2cdfb498eb4b
typedef enum RouteStatusValues__0758 {
  /// initiated
  RouteStatusValues__0758__Initiated,

  /// locked
  RouteStatusValues__0758__Locked,

  /// no route
  RouteStatusValues__0758__NoRoute
} RouteStatusValues__0758;

/// Route Type values
/// UML Identifier: _760fdca9-0a63-464d-a99b-5028e30b0cc5
typedef enum RouteTypeValues__760f {
  /// main route
  RouteTypeValues__760f__MainRoute,

  /// shunting route
  RouteTypeValues__760f__ShuntingRoute,

  /// on-sight route
  RouteTypeValues__760f__OnSightRoute,

  /// SR train route
  RouteTypeValues__760f__SrTrainRoute,

  /// special train route
  RouteTypeValues__760f__SpecialTrainRoute,

  /// temporary shunting area
  RouteTypeValues__760f__TemporaryShuntingArea
} RouteTypeValues__760f;

/// Signal Intentionally Dark values
/// UML Identifier: _d7ce737a-5b9f-4d44-8490-f24b89510fba
typedef enum SignalIntentionallyDarkValues__d7ce {
  /// not set to dark
  SignalIntentionallyDarkValues__d7ce__NotSetToDark,

  /// intentionally set to dark
  SignalIntentionallyDarkValues__d7ce__IntentionallySetToDark,

  /// not applicable
  SignalIntentionallyDarkValues__d7ce__NotApplicable
} SignalIntentionallyDarkValues__d7ce;

/// Train Operated Route Release Status values
/// UML Identifier: _e1362479-3265-4990-a7b7-9894e3e25763
typedef enum TrainOperatedRouteReleaseStatusValues__e136 {
  /// correct occupancy sequence
  TrainOperatedRouteReleaseStatusValues__e136__CorrectOccupancySequence,

  /// released by train
  TrainOperatedRouteReleaseStatusValues__e136__ReleasedByTrain,

  /// not in a correct occupancy sequence and not released by train
  TrainOperatedRouteReleaseStatusValues__e136__NotInACorrectOccupancySequenceAndNotReleasedByTrain
} TrainOperatedRouteReleaseStatusValues__e136;

/// TVPS Fouling Status values
/// UML Identifier: _a63c5289-2e16-40c6-ad2b-d54b7342b8a8
typedef enum TvpsFoulingStatusValues__a63c {
  /// fouling
  TvpsFoulingStatusValues__a63c__Fouling,

  /// not fouling
  TvpsFoulingStatusValues__a63c__NotFouling,

  /// not applicable
  TvpsFoulingStatusValues__a63c__NotApplicable
} TvpsFoulingStatusValues__a63c;

/// TVPS Occupancy Status values
/// UML Identifier: _0ef905a6-35b5-48cc-91aa-7b3fb7a40da7
typedef enum TvpsOccupancyStatusValues__0ef9 {
  /// vacant
  TvpsOccupancyStatusValues__0ef9__Vacant,

  /// occupied
  TvpsOccupancyStatusValues__0ef9__Occupied,

  /// disturbed
  TvpsOccupancyStatusValues__0ef9__Disturbed
} TvpsOccupancyStatusValues__0ef9;

/// InputChannelState
/// UML Identifier: _a4d29c6c-1e57-4135-9300-f813c2d2fd35
typedef enum InputChannelState__a4d2 {
  /// Switched_On
  InputChannelState__a4d2__SwitchedOn,

  /// Switched_Off
  InputChannelState__a4d2__SwitchedOff,

  /// Disturbed
  InputChannelState__a4d2__Disturbed
} InputChannelState__a4d2;

/// OutputChannelControllableState
/// UML Identifier: _80eafaa2-cee3-4420-8092-dca0457ca080
typedef enum OutputChannelControllableState__80ea {
  /// Switched_On
  OutputChannelControllableState__80ea__SwitchedOn,

  /// Switched_Off
  OutputChannelControllableState__80ea__SwitchedOff,

  /// Flashing
  OutputChannelControllableState__80ea__Flashing
} OutputChannelControllableState__80ea;

/// OutputChannelDisturbanceState
/// UML Identifier: _bed935e7-e6e3-423f-93d3-c9be053ea32d
typedef enum OutputChannelDisturbanceState__bed9 {
  /// Not_Physically_Disturbed
  OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed,

  /// Physically_Disturbed
  OutputChannelDisturbanceState__bed9__PhysicallyDisturbed
} OutputChannelDisturbanceState__bed9;

/// ActivationControlableState
/// UML Identifier: _41409318-c96e-40be-80c9-7f1e630cab04
typedef enum ActivationControlableState__4140 {
  /// Activation
  ActivationControlableState__4140__Activation,

  /// Pre-activation
  ActivationControlableState__4140__PreActivation
} ActivationControlableState__4140;

/// ChangendMonitoringStatus
/// UML Identifier: _6c2c99e7-ac6b-49d6-b0a0-a1e4b7bda934
typedef enum ChangendMonitoringStatus__6c2c {
  /// MonitoringParameterSet1
  ChangendMonitoringStatus__6c2c__MonitoringParameterSet1,

  /// MonitoringParameterSet2
  ChangendMonitoringStatus__6c2c__MonitoringParameterSet2
} ChangendMonitoringStatus__6c2c;

/// CriticalFailureStatusState
/// UML Identifier: _f095bcde-58e3-455d-87a8-3a174437c0ac
typedef enum CriticalFailureStatusState__f095 {
  /// ACriticalFailureIsPresent
  CriticalFailureStatusState__f095__ACriticalFailureIsPresent,

  /// NoCriticalFailureIsPresent
  CriticalFailureStatusState__f095__NoCriticalFailureIsPresent
} CriticalFailureStatusState__f095;

/// DeactivationControlableState
/// UML Identifier: _514fe2f0-1ff4-4623-9ad0-9a9eeb8fc6ed
typedef enum DeactivationControlableState__514f {
  /// Deactivation
  DeactivationControlableState__514f__Deactivation
} DeactivationControlableState__514f;

/// DetectionElementStatusState
/// UML Identifier: _4b10205c-fb36-4e8c-9a3d-49455b2aa79e
typedef enum DetectionElementStatusState__4b10 {
  /// DetectionElementIsVacant
  DetectionElementStatusState__4b10__DetectionElementIsVacant,

  /// DetectionElementIsOccupied
  DetectionElementStatusState__4b10__DetectionElementIsOccupied,

  /// DetectionElementIsFailed
  DetectionElementStatusState__4b10__DetectionElementIsFailed
} DetectionElementStatusState__4b10;

/// FunctionalStatusState
/// UML Identifier: _5d1236aa-fb61-4290-bb17-b77dff20c1ff
typedef enum FunctionalStatusState__5d12 {
  /// DeactivatingAndUnprotected
  FunctionalStatusState__5d12__DeactivatingAndUnprotected,

  /// ActivatedAndUnprotected
  FunctionalStatusState__5d12__ActivatedAndUnprotected,

  /// ActivatedAndProtected
  FunctionalStatusState__5d12__ActivatedAndProtected,

  /// PreActivated
  FunctionalStatusState__5d12__PreActivated,

  /// IsolatedLC
  FunctionalStatusState__5d12__IsolatedLC,

  /// DeactivatedAndIdle
  FunctionalStatusState__5d12__DeactivatedAndIdle
} FunctionalStatusState__5d12;

/// IsolateLevelCrossingControlableState
/// UML Identifier: _55c125aa-604f-478f-af31-060b754c70d0
typedef enum IsolateLevelCrossingControlableState__55c1 {
  /// EnableIsolationOfTheLevelCrossing
  IsolateLevelCrossingControlableState__55c1__EnableIsolationOfTheLevelCrossing,

  /// DisableIsolationOfTheLevelCrossing
  IsolateLevelCrossingControlableState__55c1__DisableIsolationOfTheLevelCrossing
} IsolateLevelCrossingControlableState__55c1;

/// LocalOperationHandoverControlableState
/// UML Identifier: _916468ff-6cb8-4489-b104-cb25d128c7b2
typedef enum LocalOperationHandoverControlableState__9164 {
  /// NoHandOverToLocalOperator
  LocalOperationHandoverControlableState__9164__NoHandOverToLocalOperator,

  /// HandoverToLocalOperatorInitiated
  LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorInitiated,

  /// HandoverToLocalOperatorEstablished
  LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorEstablished
} LocalOperationHandoverControlableState__9164;

/// LocalOperationHandoverState
/// UML Identifier: _ee05f142-9328-4224-ba2e-4a0add7153b6
typedef enum LocalOperationHandoverState__ee05 {
  /// AllowHandovertoLocalOperator
  LocalOperationHandoverState__ee05__AllowHandovertoLocalOperator,

  /// ReturnHandoverFromLocalOperator
  LocalOperationHandoverState__ee05__ReturnHandoverFromLocalOperator
} LocalOperationHandoverState__ee05;

/// LocalRequestState
/// UML Identifier: _d488613d-b0ff-4186-9f5a-5f0396a41590
typedef enum LocalRequestState__d488 {
  /// LocalRequestToActivateTheLevelCrossing
  LocalRequestState__d488__LocalRequestToActivateTheLevelCrossing,

  /// LocalRequestToDeactivateTheLevelCrossing
  LocalRequestState__d488__LocalRequestToDeactivateTheLevelCrossing
} LocalRequestState__d488;

/// NonCriticalFailureStatusState
/// UML Identifier: _b376aec7-a402-4bb3-bfb4-e28864dce44e
typedef enum NonCriticalFailureStatusState__b376 {
  /// ANonCriticalFailureIsPresent
  NonCriticalFailureStatusState__b376__ANonCriticalFailureIsPresent,

  /// NoNonCriticalFailureIsPresent
  NonCriticalFailureStatusState__b376__NoNonCriticalFailureIsPresent
} NonCriticalFailureStatusState__b376;

/// ObstacleDetectionStatusState
/// UML Identifier: _5aa0e263-63f0-421c-97a4-8d87029e64c3
typedef enum ObstacleDetectionStatusState__5aa0 {
  /// NoObstacleInTheConflictArea
  ObstacleDetectionStatusState__5aa0__NoObstacleInTheConflictArea,

  /// ObstacleInTheConflictArea
  ObstacleDetectionStatusState__5aa0__ObstacleInTheConflictArea
} ObstacleDetectionStatusState__5aa0;

/// TimeOverrunState
/// UML Identifier: _b8ce00d3-8208-40c6-a818-f6593fb18da9
typedef enum TimeOverrunState__b8ce {
  /// NoClosureTimeOverrun
  TimeOverrunState__b8ce__NoClosureTimeOverrun,

  /// ClosureTimeOverrunOccured
  TimeOverrunState__b8ce__ClosureTimeOverrunOccured,

  /// TimeOverrunIsNotApplicable
  TimeOverrunState__b8ce__TimeOverrunIsNotApplicable
} TimeOverrunState__b8ce;

/// LuminosityState
/// UML Identifier: _20ae90ab-5759-4ff1-b0b9-c40936528e12
typedef enum LuminosityState__20ae {
  /// Day
  LuminosityState__20ae__Day,

  /// Night
  LuminosityState__20ae__Night
} LuminosityState__20ae;

/// SignalAspectControlableState
/// UML Identifier: _0dcc1660-59e7-40a1-a22a-c0fa25669ad3
typedef enum SignalAspectControlableState__0dcc {
  /// Signal_Aspect_1
  SignalAspectControlableState__0dcc__SignalAspect1,

  /// Signal_Aspect_2
  SignalAspectControlableState__0dcc__SignalAspect2,

  /// Most_Restrict_Aspect
  SignalAspectControlableState__0dcc__MostRestrictAspect
} SignalAspectControlableState__0dcc;

/// SignalAspectState
/// UML Identifier: _f56634ed-6021-48dd-aba1-fb9de4765b25
typedef enum SignalAspectState__f566 {
  /// Signal_Aspect_1
  SignalAspectState__f566__SignalAspect1,

  /// Signal_Aspect_2
  SignalAspectState__f566__SignalAspect2,

  /// Most_Restrict_Aspect
  SignalAspectState__f566__MostRestrictAspect,

  /// No_Signal_Aspect
  SignalAspectState__f566__NoSignalAspect
} SignalAspectState__f566;

/// AbilityToMoveState
/// UML Identifier: _ed0fe45d-45dc-475b-a454-501457c57f29
typedef enum AbilityToMoveState__ed0f {
  /// AbleToMove
  AbilityToMoveState__ed0f__AbleToMove,

  /// UnableToMove
  AbilityToMoveState__ed0f__UnableToMove
} AbilityToMoveState__ed0f;

/// PointPositionControlableState
/// UML Identifier: _14bc2c76-891f-4559-9e92-a7e0a8da8d57
typedef enum PointPositionControlableState__14bc {
  /// Left
  PointPositionControlableState__14bc__Left,

  /// Right
  PointPositionControlableState__14bc__Right
} PointPositionControlableState__14bc;

/// PointPositionDegradedState
/// UML Identifier: _422e0a2f-77f5-4036-9f49-2130f426c8f5
typedef enum PointPositionDegradedState__422e {
  /// DegradedLeft
  PointPositionDegradedState__422e__DegradedLeft,

  /// DegradedRight
  PointPositionDegradedState__422e__DegradedRight,

  /// NotDegraded
  PointPositionDegradedState__422e__NotDegraded,

  /// NotApplicable
  PointPositionDegradedState__422e__NotApplicable
} PointPositionDegradedState__422e;

/// PointPositionState
/// UML Identifier: _2e6f9294-3b7a-4a9b-a726-ccefd9ef22b0
typedef enum PointPositionState__2e6f {
  /// Left
  PointPositionState__2e6f__Left,

  /// Right
  PointPositionState__2e6f__Right,

  /// NoEndPosition
  PointPositionState__2e6f__NoEndPosition,

  /// UnintendedPosition
  PointPositionState__2e6f__UnintendedPosition
} PointPositionState__2e6f;

/// AbilityToBeForcedToClear
/// UML Identifier: _8b12218c-3bf0-4b00-bd80-ef672a20aab8
typedef enum AbilityToBeForcedToClear__8b12 {
  /// NotAble
  AbilityToBeForcedToClear__8b12__NotAble,

  /// Able
  AbilityToBeForcedToClear__8b12__Able
} AbilityToBeForcedToClear__8b12;

/// ChangeTrigger
/// UML Identifier: _de2dfc56-2189-4dc9-bc36-df7095d5c261
typedef enum ChangeTrigger__de2d {
  /// PassingDetected
  ChangeTrigger__de2d__PassingDetected,

  /// CommandFromEIL
  ChangeTrigger__de2d__CommandFromEIL,

  /// CommandFromMaintainer
  ChangeTrigger__de2d__CommandFromMaintainer,

  /// TechnicalFailure
  ChangeTrigger__de2d__TechnicalFailure,

  /// InitialSectionState
  ChangeTrigger__de2d__InitialSectionState,

  /// InternalTrigger
  ChangeTrigger__de2d__InternalTrigger,

  /// NotApplicable
  ChangeTrigger__de2d__NotApplicable
} ChangeTrigger__de2d;

/// DirectionOfPassing
/// UML Identifier: _a7c922c8-6d33-4511-9aec-2daacff67272
typedef enum DirectionOfPassing__a7c9 {
  /// ReferenceDirection
  DirectionOfPassing__a7c9__ReferenceDirection,

  /// AgainstRefernceDirection
  DirectionOfPassing__a7c9__AgainstRefernceDirection,

  /// WithoutIndicatedDirection
  DirectionOfPassing__a7c9__WithoutIndicatedDirection
} DirectionOfPassing__a7c9;

/// DisturbanceStatus
/// UML Identifier: _fd6578a2-eb46-410d-b7d7-e75cd394242c
typedef enum DisturbanceStatus__fd65 {
  /// Operational
  DisturbanceStatus__fd65__Operational,

  /// Technical
  DisturbanceStatus__fd65__Technical,

  /// NotApplicable
  DisturbanceStatus__fd65__NotApplicable
} DisturbanceStatus__fd65;

/// ModeOfFC
/// UML Identifier: _fc54cfa3-9aeb-4266-982b-e978940f3ff1
typedef enum ModeOfFC__fc54 {
  /// FC_U
  ModeOfFC__fc54__FcU,

  /// FC_C
  ModeOfFC__fc54__FcC,

  /// FC_P_A
  ModeOfFC__fc54__FcPA,

  /// FC_P
  ModeOfFC__fc54__FcP,

  /// AcknowledgmentAfterFC_P_A_Command
  ModeOfFC__fc54__AcknowledgmentafterfcPACommand
} ModeOfFC__fc54;

/// OccupancyStatus
/// UML Identifier: _65fa6d7b-8ca8-4f77-bc41-e29774dd5724
typedef enum OccupancyStatus__65fa {
  /// Vacant
  OccupancyStatus__65fa__Vacant,

  /// Occupied
  OccupancyStatus__65fa__Occupied,

  /// Disturbed
  OccupancyStatus__65fa__Disturbed,

  /// WaitingForASweepingTrain
  OccupancyStatus__65fa__WaitingForASweepingTrain,

  /// WaitingForAnAcknowledgment
  OccupancyStatus__65fa__WaitingForAnAcknowledgment,

  /// SweepingTrainDetected
  OccupancyStatus__65fa__SweepingTrainDetected
} OccupancyStatus__65fa;

/// POM_Status
/// UML Identifier: _d74ae5ad-36a9-49bb-acd9-7606bb23b798
typedef enum PomStatus__d74a {
  /// OK
  PomStatus__d74a__Ok,

  /// NOK
  PomStatus__d74a__Nok,

  /// NotApplicable
  PomStatus__d74a__NotApplicable
} PomStatus__d74a;

/// ReasonForFailure
/// UML Identifier: _b02d7797-6781-4ec7-a366-e1aaebc480e8
typedef enum ReasonForFailure__b02d {
  /// IncorrectCount
  ReasonForFailure__b02d__IncorrectCount,

  /// Timeout_t_Max
  ReasonForFailure__b02d__TimeoutTMax,

  /// NotPermittedPassing
  ReasonForFailure__b02d__NotPermittedPassing,

  /// OutgoingWheelBefore_t_Min
  ReasonForFailure__b02d__OutgoingwheelbeforeTMin,

  /// ProcessCanceled
  ReasonForFailure__b02d__ProcessCanceled
} ReasonForFailure__b02d;

/// ReasonForRejection
/// UML Identifier: _abec9aa1-21d1-4c2d-bc25-bd484ae3c5da
typedef enum ReasonForRejection__abec {
  /// Operational
  ReasonForRejection__abec__Operational,

  /// Technical
  ReasonForRejection__abec__Technical
} ReasonForRejection__abec;

/// StateOfPassing
/// UML Identifier: _616f4dcb-cde8-49b0-aab7-c4cfdb3000d3
typedef enum StateOfPassing__616f {
  /// NotPassed
  StateOfPassing__616f__NotPassed,

  /// Passed
  StateOfPassing__616f__Passed,

  /// Disturbed
  StateOfPassing__616f__Disturbed
} StateOfPassing__616f;

/// SourceOfCommand
/// UML Identifier: _d5a99903-ca2c-45e2-827c-a3c9955e07f3
typedef enum SourceOfCommand__d5a9 {
  /// EIL
  SourceOfCommand__d5a9__Eil,

  /// Maintainer
  SourceOfCommand__d5a9__Maintainer,

  /// Internal
  SourceOfCommand__d5a9__Internal
} SourceOfCommand__d5a9;

// Message Types

/// Cd_Block_LX
/// UML Identifier: _6cce953e-731e-4e73-9433-a28d2dc247d7
typedef struct Message__CdBlockLx__6cce {

} Message__CdBlockLx__6cce;

/// Cd_Control_Activation_Point
/// UML Identifier: _042b08a2-cc7e-4fe7-98fb-abdbc93f73d1
typedef struct Message__CdControlActivationPoint__042b {

} Message__CdControlActivationPoint__042b;

/// Cd_Crossing_Clear
/// UML Identifier: _2c74c5f8-cdba-4800-8592-dd8821f1f81a
typedef struct Message__CdCrossingClear__2c74 {

} Message__CdCrossingClear__2c74;

/// Cd_LX_Activation
/// UML Identifier: _d7a19835-150f-4b7e-91db-110ba0827c59
typedef struct Message__CdLxActivation__d7a1 {

} Message__CdLxActivation__d7a1;

/// Cd_LX_Deactivation
/// UML Identifier: _b2e7b4c3-3a48-451b-9ab0-4cbdf6ba3a4c
typedef struct Message__CdLxDeactivation__b2e7 {

} Message__CdLxDeactivation__b2e7;

/// Cd_Track_Related_Activation
/// UML Identifier: _61f014b3-4412-4374-a238-97339140c2ac
typedef struct Message__CdTrackRelatedActivation__61f0 {

} Message__CdTrackRelatedActivation__61f0;

/// Cd_Track_Related_Deactivation
/// UML Identifier: _2f77e4ad-7fb4-407f-91be-aac83a07979a
typedef struct Message__CdTrackRelatedDeactivation__2f77 {

} Message__CdTrackRelatedDeactivation__2f77;

/// Cd_Track_Related_Isolation
/// UML Identifier: _a7c384c4-ad99-4d16-a7eb-5aa7d7946106
typedef struct Message__CdTrackRelatedIsolation__a7c3 {

} Message__CdTrackRelatedIsolation__a7c3;

/// Cd_Track_Related_Prolong_Activation
/// UML Identifier: _9f46808f-15df-4778-89fd-d042b435cdf6
typedef struct Message__CdTrackRelatedProlongActivation__9f46 {

} Message__CdTrackRelatedProlongActivation__9f46;

/// Msg_Detection_Element_Status
/// UML Identifier: _d44d2e54-6f35-4f9b-9ce9-feebc0dc67f7
typedef struct Message__MsgDetectionElementStatus__d44d {

} Message__MsgDetectionElementStatus__d44d;

/// Msg_LX_Command_Admissibility
/// UML Identifier: _393073fc-809c-4d77-9e51-87808750f3c0
typedef struct Message__MsgLxCommandAdmissibility__3930 {

} Message__MsgLxCommandAdmissibility__3930;

/// Msg_LX_Failure_Status
/// UML Identifier: _d13db7e0-b266-4bd5-b999-bc000350f3da
typedef struct Message__MsgLxFailureStatus__d13d {

} Message__MsgLxFailureStatus__d13d;

/// Msg_LX_Functional_Status
/// UML Identifier: _18c6cff9-aa58-4fc3-b3d1-e47d9d794dff
typedef struct Message__MsgLxFunctionalStatus__18c6 {

} Message__MsgLxFunctionalStatus__18c6;

/// Msg_LX_Monitoring_Status
/// UML Identifier: _d6cb8054-ae8a-47a5-9500-f7fa0e5b0b58
typedef struct Message__MsgLxMonitoringStatus__d6cb {

} Message__MsgLxMonitoringStatus__d6cb;

/// Msg_Obstacle_Detection_Status
/// UML Identifier: _b7d32524-56eb-466a-9af3-9fc19e4143a5
typedef struct Message__MsgObstacleDetectionStatus__b7d3 {

} Message__MsgObstacleDetectionStatus__b7d3;

/// Msg_Status_Of_Activation_Point
/// UML Identifier: _de8b31ef-857b-42b6-ac03-757d8b4d3115
typedef struct Message__MsgStatusOfActivationPoint__de8b {

} Message__MsgStatusOfActivationPoint__de8b;

/// Msg_Track_Related_Command_Admissibility
/// UML Identifier: _3f18eac5-79a7-4b9e-adcf-50ee287099d9
typedef struct Message__MsgTrackRelatedCommandAdmissibility__3f18 {

} Message__MsgTrackRelatedCommandAdmissibility__3f18;

/// Msg_Track_Related_Failure_Status
/// UML Identifier: _83d4c4dc-2276-45e6-854b-33b66586bef6
typedef struct Message__MsgTrackRelatedFailureStatus__83d4 {

} Message__MsgTrackRelatedFailureStatus__83d4;

/// Msg_Track_Related_Functional_Status
/// UML Identifier: _4feb59b8-41ed-448b-be15-5608b56ba205
typedef struct Message__MsgTrackRelatedFunctionalStatus__4feb {

} Message__MsgTrackRelatedFunctionalStatus__4feb;

/// Msg_Track_Related_Monitoring_Status
/// UML Identifier: _27ceb17c-a26b-4506-a592-1a96480edfba
typedef struct Message__MsgTrackRelatedMonitoringStatus__27ce {

} Message__MsgTrackRelatedMonitoringStatus__27ce;

/// Establishing_PDI_Connection
/// UML Identifier: _41d4ef83-fbf3-4eac-a2f8-cdcbebbaef70
typedef struct Message__EstablishingPdiConnection__41d4 {

} Message__EstablishingPdiConnection__41d4;

/// PDI_Connection_Closed
/// UML Identifier: _7975140f-f420-445d-b3c4-e0d96a9bc2ad
typedef struct Message__PdiConnectionClosed__7975 {

} Message__PdiConnectionClosed__7975;

/// PDI_Connection_Established
/// UML Identifier: _019db850-1233-47c6-83b5-f164bf0bad3e
typedef struct Message__PdiConnectionEstablished__019d {

} Message__PdiConnectionEstablished__019d;

/// Prim_Status_Report_Completed
/// UML Identifier: _80d8f189-fa6a-4db3-8959-b6512a22dfdb
typedef struct Message__PrimStatusReportCompleted__80d8 {

} Message__PrimStatusReportCompleted__80d8;

/// Sec_Status_Report_Completed
/// UML Identifier: _339c5222-f08c-4525-a996-565296e4185a
typedef struct Message__SecStatusReportCompleted__339c {

} Message__SecStatusReportCompleted__339c;

/// Start_Prim_Status_Report
/// UML Identifier: _a91c4d72-3495-4cea-9e79-a786b3d89c76
typedef struct Message__StartPrimStatusReport__a91c {

} Message__StartPrimStatusReport__a91c;

/// Start_Sec_Status_Report
/// UML Identifier: _2c198fec-78ce-482b-86aa-173a159bf51f
typedef struct Message__StartSecStatusReport__2c19 {

} Message__StartSecStatusReport__2c19;

/// Start_Status_Report
/// UML Identifier: _1e4ea2a0-1465-4c1a-af7e-2fb5fab8bb47
typedef struct Message__StartStatusReport__1e4e {

} Message__StartStatusReport__1e4e;

/// Status_Report_Completed
/// UML Identifier: _b457fc19-ab60-4795-b1d9-72d745b4e721
typedef struct Message__StatusReportCompleted__b457 {

} Message__StatusReportCompleted__b457;

/// Cd_Close_PDI
/// UML Identifier: _8a06f369-7e07-4a25-a713-b731c808b2c4
typedef struct Message__CdClosePdi__8a06 {
  CloseReason__91bc RequestedCloseReason;
} Message__CdClosePdi__8a06;

/// Cd_Initialisation_Request
/// UML Identifier: _8d96e6cf-5511-4450-aeb0-86dbede3f6e2
typedef struct Message__CdInitialisationRequest__8d96 {

} Message__CdInitialisationRequest__8d96;

/// Cd_PDI_Version_Check
/// UML Identifier: _ffab9839-b01c-4c4b-8d8a-c59ad8f2ca05
typedef struct Message__CdPdiVersionCheck__ffab {
  char PdiVersion;
} Message__CdPdiVersionCheck__ffab;

/// Cd_Release_PDI_for_Maintenance
/// UML Identifier: _3e43cdab-a35d-4ef9-b090-a453a6873278
typedef struct Message__CdReleasePdiForMaintenance__3e43 {

} Message__CdReleasePdiForMaintenance__3e43;

/// Msg_Initialisation_Completed
/// UML Identifier: _75d93039-5486-4c1e-9d35-9a6158c91822
typedef struct Message__MsgInitialisationCompleted__75d9 {

} Message__MsgInitialisationCompleted__75d9;

/// Msg_PDI_Available
/// UML Identifier: _af0ad5d1-8890-45db-8b0d-e0d28adf54ba
typedef struct Message__MsgPdiAvailable__af0a {

} Message__MsgPdiAvailable__af0a;

/// Msg_PDI_Not_Available
/// UML Identifier: _b83e8378-4f8a-4dbd-acd7-1ea862a10b1e
typedef struct Message__MsgPdiNotAvailable__b83e {

} Message__MsgPdiNotAvailable__b83e;

typedef enum MsgPdiVersionCheck__9827_ResultValue {
  MsgPdiVersionCheck__9827_ResultValue__NULL__,
  MsgPdiVersionCheck__9827_ResultValue__Match,
  MsgPdiVersionCheck__9827_ResultValue__NotMatch,
  MsgPdiVersionCheck__9827_ResultValue__UNKNOWN__
} MsgPdiVersionCheck__9827_ResultValue;

/// Msg_PDI_Version_Check
/// UML Identifier: _98271aba-44ee-4a93-bb41-b93b4051d9ea
typedef struct Message__MsgPdiVersionCheck__9827 {
  MsgPdiVersionCheck__9827_ResultValue Result;
  char ChecksumData[16];
  char PDIVersion;
} Message__MsgPdiVersionCheck__9827;

/// Msg_Reset_PDI
/// UML Identifier: _59f44418-b2ea-4434-a5dc-da0f853a262b
typedef struct Message__MsgResetPdi__59f4 {
  ResetReason__44e3 ReportedResetReason;
} Message__MsgResetPdi__59f4;

/// Msg_Start_Initialisation
/// UML Identifier: _43d2568f-f9e5-4e3f-b652-23542d4d1205
typedef struct Message__MsgStartInitialisation__43d2 {

} Message__MsgStartInitialisation__43d2;

/// Msg_Status_Report_Completed
/// UML Identifier: _c465a7a2-8d11-4059-956f-5c6cde24c0e6
typedef struct Message__MsgStatusReportCompleted__c465 {

} Message__MsgStatusReportCompleted__c465;

/// Cd_Manage_A_By-pass_Area
/// UML Identifier: _8996ef21-16eb-4540-8e24-9e0d717e772d
typedef struct Message__CdManageAByPassArea__8996 {

} Message__CdManageAByPassArea__8996;

/// Cd_Manage_A_Local_Shunting_Area
/// UML Identifier: _90971c6e-443c-4547-99d6-9d4b3a083696
typedef struct Message__CdManageALocalShuntingArea__9097 {

} Message__CdManageALocalShuntingArea__9097;

/// Cd_Manage_A_Working_Area
/// UML Identifier: _f8d881e9-f291-4e41-a1e1-14c4fef15b03
typedef struct Message__CdManageAWorkingArea__f8d8 {

} Message__CdManageAWorkingArea__f8d8;

/// Cd_Manage_An_Emergency_Stop_Area
/// UML Identifier: _b0b3b703-8340-4d23-af94-eb180ae5a73d
typedef struct Message__CdManageAnEmergencyStopArea__b0b3 {

} Message__CdManageAnEmergencyStopArea__b0b3;

/// Cd_Manage_An_Overhead_Line_(OHL)_Groupset
/// UML Identifier: _72d71a0e-d212-4bca-9779-713896a26b29
typedef struct Message__CdManageAnOverheadLineOhlGroupset__72d7 {

} Message__CdManageAnOverheadLineOhlGroupset__72d7;

/// Cd_Manage_Automatic_Route_Setting_For_An_Area
/// UML Identifier: _942b932c-8888-4cad-b098-8a9498baf3ff
typedef struct Message__CdManageAutomaticRouteSettingForAnArea__942b {

} Message__CdManageAutomaticRouteSettingForAnArea__942b;

/// Msg_Automatic_Route_Setting_Area_Status
/// UML Identifier: _03406c0c-ef0b-4f82-898f-061a3dd23870
typedef struct Message__MsgAutomaticRouteSettingAreaStatus__0340 {

} Message__MsgAutomaticRouteSettingAreaStatus__0340;

/// Msg_By-pass_Area_Status
/// UML Identifier: _26e62b0f-48ba-4300-bdcb-0b4cb6478517
typedef struct Message__MsgByPassAreaStatus__26e6 {

} Message__MsgByPassAreaStatus__26e6;

/// Msg_Emergency_Stop_Area_Status
/// UML Identifier: _574b1aef-db88-44ab-a98e-7e3ac0f80fad
typedef struct Message__MsgEmergencyStopAreaStatus__574b {

} Message__MsgEmergencyStopAreaStatus__574b;

/// Msg_Emergency_Stop_Message_Response
/// UML Identifier: _d93a9324-3da4-4ba2-8853-5d80f856b966
typedef struct Message__MsgEmergencyStopMessageResponse__d93a {

} Message__MsgEmergencyStopMessageResponse__d93a;

/// Msg_Local_Shunting_Area_Status
/// UML Identifier: _96831279-1515-4ae6-8806-e4f08312be22
typedef struct Message__MsgLocalShuntingAreaStatus__9683 {

} Message__MsgLocalShuntingAreaStatus__9683;

/// Msg_Request_Luminosity_Change
/// UML Identifier: _1646e236-acae-4aed-97c1-3ff49653c256
typedef struct Message__MsgRequestLuminosityChange__1646 {

} Message__MsgRequestLuminosityChange__1646;

/// Msg_Signal_Area_Status
/// UML Identifier: _9824a168-be1b-4697-aaa9-817b653b2b70
typedef struct Message__MsgSignalAreaStatus__9824 {

} Message__MsgSignalAreaStatus__9824;

/// Msg_Signal_Luminosity_Group_Status
/// UML Identifier: _63aff8ea-ef22-4b08-b406-abca2d0ddd01
typedef struct Message__MsgSignalLuminosityGroupStatus__63af {

} Message__MsgSignalLuminosityGroupStatus__63af;

/// Msg_Working_Area_Status
/// UML Identifier: _34c6bd68-a710-49af-bf68-3f98b34d8101
typedef struct Message__MsgWorkingAreaStatus__34c6 {

} Message__MsgWorkingAreaStatus__34c6;

/// Cd_Release_For_Normal_Operation
/// UML Identifier: _b651b2a7-63d2-41cf-acc3-d91147a66622
typedef struct Message__CdReleaseForNormalOperation__b651 {

} Message__CdReleaseForNormalOperation__b651;

/// Cd_Reset_The_Release_Safety_Command
/// UML Identifier: _945c4ac2-33ba-40ee-b229-08d78ce4356b
typedef struct Message__CdResetTheReleaseSafetyCommand__945c {

} Message__CdResetTheReleaseSafetyCommand__945c;

/// Cd_Set_Interlocking_Time_and_Date
/// UML Identifier: _50c67ee6-24a9-458e-8a5d-85c28dc24198
typedef struct Message__CdSetInterlockingTimeAndDate__50c6 {

} Message__CdSetInterlockingTimeAndDate__50c6;

/// Cd_Abort_Command
/// UML Identifier: _4b93a6e6-bdf1-4e57-89f8-fc217aed2b82
typedef struct Message__CdAbortCommand__4b93 {

} Message__CdAbortCommand__4b93;

/// Cd_Confirmation_Of_A_Command_With_Safety_Codes
/// UML Identifier: _e9a260f9-95e7-4a67-bfaa-9e88a8547964
typedef struct Message__CdConfirmationOfACommandWithSafetyCodes__e9a2 {

} Message__CdConfirmationOfACommandWithSafetyCodes__e9a2;

/// Msg_Command_Accepted
/// UML Identifier: _3564536e-8abf-404c-a099-5fd869531e19
typedef struct Message__MsgCommandAccepted__3564 {

} Message__MsgCommandAccepted__3564;

/// Msg_Command_Rejected
/// UML Identifier: _0bc105ef-9c63-4ebc-a598-a9cd24060cc2
typedef struct Message__MsgCommandRejected__0bc1 {

} Message__MsgCommandRejected__0bc1;

/// Msg_Request_Confirmation_Of_Command
/// UML Identifier: _fe932712-bd46-40b7-bcfc-6c70bdbfba80
typedef struct Message__MsgRequestConfirmationOfCommand__fe93 {

} Message__MsgRequestConfirmationOfCommand__fe93;

/// Msg_Request_Confirmation_Of_Command_With_Safety_Codes
/// UML Identifier: _e6a42170-f7d3-4a9e-820d-9826cb89c0fe
typedef struct Message__MsgRequestConfirmationOfCommandWithSafetyCodes__e6a4 {

} Message__MsgRequestConfirmationOfCommandWithSafetyCodes__e6a4;

/// Cd_Authorise_SH_Mode_For_Train
/// UML Identifier: _58bf91b9-e875-460b-abaf-fef06e9607c2
typedef struct Message__CdAuthoriseShModeForTrain__58bf {

} Message__CdAuthoriseShModeForTrain__58bf;

/// Cd_Enter_Event_Text
/// UML Identifier: _5bf784ad-916d-4829-8645-e1867b5b9aea
typedef struct Message__CdEnterEventText__5bf7 {

} Message__CdEnterEventText__5bf7;

/// Cd_Operational_Reversing
/// UML Identifier: _8b9a542d-725b-4b4a-98f1-8211bf3616ca
typedef struct Message__CdOperationalReversing__8b9a {

} Message__CdOperationalReversing__8b9a;

/// Cd_Release_Movement_Authority
/// UML Identifier: _359fedb0-6452-459b-b97f-bd4c7643e011
typedef struct Message__CdReleaseMovementAuthority__359f {

} Message__CdReleaseMovementAuthority__359f;

/// Cd_Remove_Emergency_Stop_For_The_Train
/// UML Identifier: _212142a2-218d-457c-900a-3f132fd9567b
typedef struct Message__CdRemoveEmergencyStopForTheTrain__2121 {

} Message__CdRemoveEmergencyStopForTheTrain__2121;

/// Msg_Train_Data_Report
/// UML Identifier: _d615ea82-0c3c-4f9c-95b9-9bb5f22c1041
typedef struct Message__MsgTrainDataReport__d615 {

} Message__MsgTrainDataReport__d615;

/// Msg_Train_Position_Speed_And_Status_Report
/// UML Identifier: _15a81926-6fa3-49ee-a347-cfe43efeee6b
typedef struct Message__MsgTrainPositionSpeedAndStatusReport__15a8 {

} Message__MsgTrainPositionSpeedAndStatusReport__15a8;

/// Msg_Train_Request
/// UML Identifier: _4b54f4e9-21e0-4d39-8a4f-adef5996e62c
typedef struct Message__MsgTrainRequest__4b54 {

} Message__MsgTrainRequest__4b54;

/// Cd_Acknowledge_Alarm_Or_Alert
/// UML Identifier: _01ab6818-b39e-4e9a-a378-0d031cdd3930
typedef struct Message__CdAcknowledgeAlarmOrAlert__01ab {

} Message__CdAcknowledgeAlarmOrAlert__01ab;

/// Cd_Apply_EC_Route_Blocking
/// UML Identifier: _5af77a3f-1f76-4a07-9734-35bd5f1a8be7
typedef struct Message__CdApplyEcRouteBlocking__5af7 {

} Message__CdApplyEcRouteBlocking__5af7;

/// Cd_Cancel_Residual_Route
/// UML Identifier: _f54c4c11-3f3d-45b8-9ca8-490982dbd11f
typedef struct Message__CdCancelResidualRoute__f54c {

} Message__CdCancelResidualRoute__f54c;

/// Cd_Display_All_Reminders_And_Blocking_Set_On_A_Route_Element_Or_On_A_Route
/// UML Identifier: _6b81d8fe-d595-4f25-9f2b-a55b015a2b1f
typedef struct
    Message__CdDisplayAllRemindersAndBlockingSetOnARouteElementOrOnARoute__6b81 {

} Message__CdDisplayAllRemindersAndBlockingSetOnARouteElementOrOnARoute__6b81;

/// Cd_Manage_field_element_PDI_connection
/// UML Identifier: _04345adc-c312-45ea-af98-793ea34bcb14
typedef struct Message__CdManageFieldElementPdiConnection__0434 {

} Message__CdManageFieldElementPdiConnection__0434;

/// Cd_Remove_EC_Route_Blocking
/// UML Identifier: _17f8b56d-0675-47e5-b7b0-0455e00c7a53
typedef struct Message__CdRemoveEcRouteBlocking__17f8 {

} Message__CdRemoveEcRouteBlocking__17f8;

/// Msg_EC_Blocking_Text
/// UML Identifier: _c644b5aa-b4f0-4c5e-8051-6ef9842caa55
typedef struct Message__MsgEcBlockingText__c644 {

} Message__MsgEcBlockingText__c644;

/// Msg_Field_element_PDI_connection_status
/// UML Identifier: _1cdd7acd-536d-46e5-8543-1aa291bc1839
typedef struct Message__MsgFieldElementPdiConnectionStatus__1cdd {

} Message__MsgFieldElementPdiConnectionStatus__1cdd;

/// Msg_Raise_Alarm_Or_Alert_Or_Event
/// UML Identifier: _6cd591e3-a917-4fc9-b2da-480dc2ad8486
typedef struct Message__MsgRaiseAlarmOrAlertOrEvent__6cd5 {

} Message__MsgRaiseAlarmOrAlertOrEvent__6cd5;

/// Msg_Released_Status
/// UML Identifier: _f91cc1b1-b63e-4647-b3f7-1703d23da4ce
typedef struct Message__MsgReleasedStatus__f91c {

} Message__MsgReleasedStatus__f91c;

/// Cd_Manual_Deletion_Of_Train_Data
/// UML Identifier: _8df4c73a-1417-4eda-a74e-89c6600f3230
typedef struct Message__CdManualDeletionOfTrainData__8df4 {

} Message__CdManualDeletionOfTrainData__8df4;

/// Cd_Update_Train_Running_Number
/// UML Identifier: _ee04769f-1043-47bd-a766-4f9344ae0495
typedef struct Message__CdUpdateTrainRunningNumber__ee04 {

} Message__CdUpdateTrainRunningNumber__ee04;

/// Msg_Train_Definition_Deleted
/// UML Identifier: _3e50b6df-83ce-4723-bd99-db3cb0128bea
typedef struct Message__MsgTrainDefinitionDeleted__3e50 {

} Message__MsgTrainDefinitionDeleted__3e50;

/// Cd_Generic_Latches_/_Bit_States
/// UML Identifier: _2ec11dc2-b092-4d27-ba46-228e73c35664
typedef struct Message__CdGenericLatchesBitStates__2ec1 {

} Message__CdGenericLatchesBitStates__2ec1;

/// Cd_Manage_A_Level_Crossing
/// UML Identifier: _0099f530-1973-4f73-afde-6daf80499ce5
typedef struct Message__CdManageALevelCrossing__0099 {

} Message__CdManageALevelCrossing__0099;

/// Cd_Manage_A_Line_Block_Between_Signalling_Areas
/// UML Identifier: _dc287b1f-c8f0-44da-baf8-655322ceaff5
typedef struct Message__CdManageALineBlockBetweenSignallingAreas__dc28 {

} Message__CdManageALineBlockBetweenSignallingAreas__dc28;

/// Cd_Manage_A_Point_Heater
/// UML Identifier: _2eac303c-edf6-4d9d-a73f-e149d1a871ec
typedef struct Message__CdManageAPointHeater__2eac {

} Message__CdManageAPointHeater__2eac;

/// Cd_Manage_A_Powered_Moveable_Element
/// UML Identifier: _a86b11ed-7f42-4d14-baff-9e2c66bbc133
typedef struct Message__CdManageAPoweredMoveableElement__a86b {

} Message__CdManageAPoweredMoveableElement__a86b;

/// Cd_Manage_A_Static_Lockable_Device
/// UML Identifier: _4124146e-a918-451a-8e2f-fc060e80ed34
typedef struct Message__CdManageAStaticLockableDevice__4124 {

} Message__CdManageAStaticLockableDevice__4124;

/// Cd_Manage_A_Track_Section
/// UML Identifier: _f2a9bf84-f6bd-44b5-b37e-1b9f7486aa3c
typedef struct Message__CdManageATrackSection__f2a9 {

} Message__CdManageATrackSection__f2a9;

/// Cd_Manage_A_TVP_Section
/// UML Identifier: _d206f306-54b2-4837-82b7-74e2c8b80d21
typedef struct Message__CdManageATvpSection__d206 {

} Message__CdManageATvpSection__d206;

/// Cd_Manage_An_Auxiliary_Object
/// UML Identifier: _28147e4a-7067-4f58-93c9-dd42f780191b
typedef struct Message__CdManageAnAuxiliaryObject__2814 {

} Message__CdManageAnAuxiliaryObject__2814;

/// Cd_Operate_A_Level_Crossing
/// UML Identifier: _b44b0ec2-0eac-4400-b2ec-a499e2f9035f
typedef struct Message__CdOperateALevelCrossing__b44b {

} Message__CdOperateALevelCrossing__b44b;

/// Cd_Operate_A_Moveable_Lockable_Device
/// UML Identifier: _65e3633e-eb28-42e5-8e51-b136dd6e0ac3
typedef struct Message__CdOperateAMoveableLockableDevice__65e3 {

} Message__CdOperateAMoveableLockableDevice__65e3;

/// Cd_Operate_A_Powered_Moveable_Element
/// UML Identifier: _ff6e796d-dbae-46e9-bd9e-0c3a8b591a6c
typedef struct Message__CdOperateAPoweredMoveableElement__ff6e {

} Message__CdOperateAPoweredMoveableElement__ff6e;

/// Cd_Set_Predefined_Obstruction
/// UML Identifier: _81e588a3-83c3-482c-be04-773acb60ae85
typedef struct Message__CdSetPredefinedObstruction__81e5 {

} Message__CdSetPredefinedObstruction__81e5;

/// Msg_Auxiliary_Object_Status
/// UML Identifier: _3d48856e-cf90-42df-897b-ac9b71b78c8d
typedef struct Message__MsgAuxiliaryObjectStatus__3d48 {

} Message__MsgAuxiliaryObjectStatus__3d48;

/// Msg_Diamond_Crossing_Status
/// UML Identifier: _64358f4f-a3ff-4146-a715-10cf17a6f0f9
typedef struct Message__MsgDiamondCrossingStatus__6435 {

} Message__MsgDiamondCrossingStatus__6435;

/// Msg_Generic_Latches_/_Bit_States
/// UML Identifier: _878b76bb-8b53-40ac-911c-9b746a613bc8
typedef struct Message__MsgGenericLatchesBitStates__878b {

} Message__MsgGenericLatchesBitStates__878b;

/// Msg_Indicator_Status
/// UML Identifier: _98e26dfc-df09-4684-9850-e71f79fd23a7
typedef struct Message__MsgIndicatorStatus__98e2 {

} Message__MsgIndicatorStatus__98e2;

/// Msg_Level_Crossing_Status
/// UML Identifier: _d4f8f886-f37b-471b-88e3-8dd94980c4c9
typedef struct Message__MsgLevelCrossingStatus__d4f8 {

} Message__MsgLevelCrossingStatus__d4f8;

/// Msg_Line_Block_Status
/// UML Identifier: _a08d4896-1498-477f-84bd-1d622766affa
typedef struct Message__MsgLineBlockStatus__a08d {

} Message__MsgLineBlockStatus__a08d;

/// Msg_Moveable_Lockable_Device_Status
/// UML Identifier: _23bd3384-f7f8-4171-819d-0faba971395d
typedef struct Message__MsgMoveableLockableDeviceStatus__23bd {

} Message__MsgMoveableLockableDeviceStatus__23bd;

/// Msg_Point_Heater_Status
/// UML Identifier: _d5b9649f-af70-49db-8e93-0c95240b015b
typedef struct Message__MsgPointHeaterStatus__d5b9 {

} Message__MsgPointHeaterStatus__d5b9;

/// Msg_Powered_Moveable_Element_Status
/// UML Identifier: _74d25b31-f2ea-45fa-83b3-98ed5d3a7fca
typedef struct Message__MsgPoweredMoveableElementStatus__74d2 {

} Message__MsgPoweredMoveableElementStatus__74d2;

/// Msg_Predefined_Obstruction_Status
/// UML Identifier: _405fd816-632f-4c1c-8542-2a6fad19f1a9
typedef struct Message__MsgPredefinedObstructionStatus__405f {

} Message__MsgPredefinedObstructionStatus__405f;

/// Msg_Static_Lockable_Device_Status
/// UML Identifier: _e2985cad-a642-426f-95c8-806fb86872e2
typedef struct Message__MsgStaticLockableDeviceStatus__e298 {

} Message__MsgStaticLockableDeviceStatus__e298;

/// Msg_Track_Section_Status
/// UML Identifier: _9b7ca0d6-b971-41dc-bec9-607a409ca79f
typedef struct Message__MsgTrackSectionStatus__9b7c {

} Message__MsgTrackSectionStatus__9b7c;

/// Msg_TVP_Section_Status
/// UML Identifier: _c10b53c8-d297-4c5b-a828-870dc7156b55
typedef struct Message__MsgTvpSectionStatus__c10b {

} Message__MsgTvpSectionStatus__c10b;

/// Cd_Barrier_Stop
/// UML Identifier: _dc9a4d6d-4ab0-4e22-a537-a90a66094d35
typedef struct Message__CdBarrierStop__dc9a {

} Message__CdBarrierStop__dc9a;

/// Cd_Set_A_Signal_/_Signalling_Point_/_Area_To_Stop_Aspect
/// UML Identifier: _1bad0f39-2dd8-4c17-8cdb-9665e730a1ea
typedef struct Message__CdSetASignalSignallingPointAreaToStopAspect__1bad {

} Message__CdSetASignalSignallingPointAreaToStopAspect__1bad;

/// Cd_Unconditional_Emergency_Stop_For_A_Train
/// UML Identifier: _9272ac0e-91f5-4e37-b191-553c8fe8abb1
typedef struct Message__CdUnconditionalEmergencyStopForATrain__9272 {

} Message__CdUnconditionalEmergencyStopForATrain__9272;

/// Cd_Manage_Local_Or_Remote_Control
/// UML Identifier: _1ba798a4-eae6-4874-a323-81cb5280ca4e
typedef struct Message__CdManageLocalOrRemoteControl__1ba7 {

} Message__CdManageLocalOrRemoteControl__1ba7;

/// Msg_Local_Or_Remote_Control
/// UML Identifier: _13d4b757-8f84-48f8-8fea-7fbb289a32e5
typedef struct Message__MsgLocalOrRemoteControl__13d4 {

} Message__MsgLocalOrRemoteControl__13d4;

/// Cd_Apply_TW_Safe_Sys_Protec
/// UML Identifier: _2b5ea764-d34f-479e-abc7-2decd20c2699
typedef struct Message__CdApplyTwSafeSysProtec__2b5e {

} Message__CdApplyTwSafeSysProtec__2b5e;

/// Cd_Cancel_A_Route
/// UML Identifier: _741c832d-06bd-469d-916f-4ab844357fc7
typedef struct Message__CdCancelARoute__741c {

} Message__CdCancelARoute__741c;

/// Cd_Cancel_Or_Extend_An_Overlap
/// UML Identifier: _215c5e1c-45d5-456f-af76-1c9b33a40e1c
typedef struct Message__CdCancelOrExtendAnOverlap__215c {

} Message__CdCancelOrExtendAnOverlap__215c;

/// Cd_Cancel_Route_With_Co-operative_Shortening_Of_Movement_Authority
/// UML Identifier: _1ae6cda1-bdea-46f5-b757-4d4d369fb90f
typedef struct
    Message__CdCancelRouteWithCoOperativeShorteningOfMovementAuthority__1ae6 {

} Message__CdCancelRouteWithCoOperativeShorteningOfMovementAuthority__1ae6;

/// Cd_Set_A_Route
/// UML Identifier: _7c351aff-8424-434d-984f-d78a9a13a82d
typedef struct Message__CdSetARoute__7c35 {

} Message__CdSetARoute__7c35;

/// Msg_Co-operative_Shortening_Status
/// UML Identifier: _3a6463df-bc30-4e66-b195-c82bdec5be71
typedef struct Message__MsgCoOperativeShorteningStatus__3a64 {

} Message__MsgCoOperativeShorteningStatus__3a64;

/// Msg_Route_Status
/// UML Identifier: _15d7b415-b97a-4be5-ad22-6388f48ecf6b
typedef struct Message__MsgRouteStatus__15d7 {

} Message__MsgRouteStatus__15d7;

/// Msg_Sub-Route_Status
/// UML Identifier: _0ebcab74-9b85-4cb4-974a-ca21c48c04f5
typedef struct Message__MsgSubRouteStatus__0ebc {

} Message__MsgSubRouteStatus__0ebc;

/// Cd_Abort_Safe_Screen
/// UML Identifier: _b82ca3eb-c4e5-4336-ba10-a29d1fc07f15
typedef struct Message__CdAbortSafeScreen__b82c {

} Message__CdAbortSafeScreen__b82c;

/// Cd_Failed_Safe_Screen
/// UML Identifier: _35ef5483-6905-4e76-acc6-dd4603461ca2
typedef struct Message__CdFailedSafeScreen__35ef {

} Message__CdFailedSafeScreen__35ef;

/// Cd_Safe_Screen_Update_Checksum (Encrypted)
/// UML Identifier: _2158aaac-db37-4dfc-b3a2-33b5011eb1d1
typedef struct Message__CdSafeScreenUpdateChecksumEncrypted__2158 {

} Message__CdSafeScreenUpdateChecksumEncrypted__2158;

/// Cd_Safe_Screen_Update_Checksum (Unencrypted)
/// UML Identifier: _5d49c769-d88d-4e9c-b278-6779f2bb2495
typedef struct Message__CdSafeScreenUpdateChecksumUnencrypted__5d49 {

} Message__CdSafeScreenUpdateChecksumUnencrypted__5d49;

/// Msg_Failed_Safe_Screen
/// UML Identifier: _b3f8094d-1c46-4199-b3c1-4fc62d93198e
typedef struct Message__MsgFailedSafeScreen__b3f8 {

} Message__MsgFailedSafeScreen__b3f8;

/// Msg_Safe_Screen_Update_Process_Completed
/// UML Identifier: _e29573d2-e5f2-4f7e-82ce-b37fb09f62b9
typedef struct Message__MsgSafeScreenUpdateProcessCompleted__e295 {

} Message__MsgSafeScreenUpdateProcessCompleted__e295;

/// Msg_Safe_Screen_Update_Process_Initiated
/// UML Identifier: _b4321ee9-5e10-4461-8cb5-ca13e994bad1
typedef struct Message__MsgSafeScreenUpdateProcessInitiated__b432 {

} Message__MsgSafeScreenUpdateProcessInitiated__b432;

/// Cd_Manage_A_Signal_/_Signalling_Point_/_Area
/// UML Identifier: _db235025-fd8c-4ce4-b5de-a9cda9bcf5ef
typedef struct Message__CdManageASignalSignallingPointArea__db23 {

} Message__CdManageASignalSignallingPointArea__db23;

/// Cd_Manage_Overrun_Detection
/// UML Identifier: _6deb2b82-ee7d-40c2-a9bd-6a93d4e738e6
typedef struct Message__CdManageOverrunDetection__6deb {

} Message__CdManageOverrunDetection__6deb;

/// Msg_Overrun_Alarm
/// UML Identifier: _d6cafa9b-50ff-49be-888e-2b520388253d
typedef struct Message__MsgOverrunAlarm__d6ca {

} Message__MsgOverrunAlarm__d6ca;

/// Msg_Signal_Status
/// UML Identifier: _f9f68e74-4414-459b-a5fe-b638eb94c620
typedef struct Message__MsgSignalStatus__f9f6 {

} Message__MsgSignalStatus__f9f6;

/// Cd_Request_Update_Of_All_Statuses
/// UML Identifier: _31a8482d-95cd-44a7-9ee6-560f911580b9
typedef struct Message__CdRequestUpdateOfAllStatuses__31a8 {

} Message__CdRequestUpdateOfAllStatuses__31a8;

/// Cd_Update_The_Disturbance_And_Fault_Reports
/// UML Identifier: _a2f884f7-aa0e-4136-abfc-741bc96afa76
typedef struct Message__CdUpdateTheDisturbanceAndFaultReports__a2f8 {

} Message__CdUpdateTheDisturbanceAndFaultReports__a2f8;

/// Msg_Update_Of_All_Statuses_Completed
/// UML Identifier: _3788e6b0-dcb7-4465-82ad-43479c0df544
typedef struct Message__MsgUpdateOfAllStatusesCompleted__3788 {

} Message__MsgUpdateOfAllStatusesCompleted__3788;

/// Msg_Update_Of_All_Statuses_Started
/// UML Identifier: _632df45e-a0f7-4986-91e1-051fa04a8937
typedef struct Message__MsgUpdateOfAllStatusesStarted__632d {

} Message__MsgUpdateOfAllStatusesStarted__632d;

/// Msg_Update_The_Disturbance_And_Fault_Reports_Completed
/// UML Identifier: _079a0c25-ecc9-46c8-8b45-f281ffe58f2d
typedef struct Message__MsgUpdateTheDisturbanceAndFaultReportsCompleted__079a {

} Message__MsgUpdateTheDisturbanceAndFaultReportsCompleted__079a;

/// Msg_Update_The_Disturbance_And_Fault_Reports_Started
/// UML Identifier: _59d7b66f-982e-4f18-a238-4395fdf2f825
typedef struct Message__MsgUpdateTheDisturbanceAndFaultReportsStarted__59d7 {

} Message__MsgUpdateTheDisturbanceAndFaultReportsStarted__59d7;

/// Cd_Define_A_Temporary_Speed_Restriction
/// UML Identifier: _6f74310e-b743-4f0f-8907-514380fee3d0
typedef struct Message__CdDefineATemporarySpeedRestriction__6f74 {

} Message__CdDefineATemporarySpeedRestriction__6f74;

/// Cd_Manage_A_Temporary_Speed_Restriction
/// UML Identifier: _87f336a0-752c-49e0-b217-41fe7c620bee
typedef struct Message__CdManageATemporarySpeedRestriction__87f3 {

} Message__CdManageATemporarySpeedRestriction__87f3;

/// Cd_Status_Request_For_All_TSR_Within_A_Defined_Area
/// UML Identifier: _f7eea5bb-4cfc-4283-8275-d8e170af7224
typedef struct Message__CdStatusRequestForAllTsrWithinADefinedArea__f7ee {

} Message__CdStatusRequestForAllTsrWithinADefinedArea__f7ee;

/// Cd_Update_A_Temporary_Speed_Restriction
/// UML Identifier: _6e520f9f-8bbd-4214-b189-808411066044
typedef struct Message__CdUpdateATemporarySpeedRestriction__6e52 {

} Message__CdUpdateATemporarySpeedRestriction__6e52;

/// Msg_Request_To_Activate_TSR
/// UML Identifier: _0ebcaf1f-ba20-45d2-8938-055b85633535
typedef struct Message__MsgRequestToActivateTsr__0ebc {

} Message__MsgRequestToActivateTsr__0ebc;

/// Msg_TSR_Status_Report
/// UML Identifier: _72a97d51-9c02-4e85-a2d4-942869c17587
typedef struct Message__MsgTsrStatusReport__72a9 {

} Message__MsgTsrStatusReport__72a9;

/// Msg_Line_Direction_Control
/// UML Identifier: _3a6f0710-e930-4cce-b59f-ccd2c506d741
typedef struct Message__MsgLineDirectionControl__3a6f {
  LineDirectionControlInformation__531b ControlInformation;
} Message__MsgLineDirectionControl__3a6f;

/// Cd_XX
/// UML Identifier: _6a0f044b-f916-491c-8e6e-1f93f7e1e709
typedef struct Message__CdXx__6a0f {
  void *Type;
  void *Information;
} Message__CdXx__6a0f;

/// Cd_Abort_Route_Cancellation_Request
/// UML Identifier: _582f16cb-4b87-484b-a35a-7d61a02fee01
typedef struct Message__CdAbortRouteCancellationRequest__582f {

} Message__CdAbortRouteCancellationRequest__582f;

/// Cd_Access_Restriction_Request
/// UML Identifier: _439e671d-1caa-4ffc-88b7-5503b7b391d6
typedef struct Message__CdAccessRestrictionRequest__439e {
  void *BoundaryId;
  AccessRestrictionTypeValues__ec25 AccessRestrictionType;
} Message__CdAccessRestrictionRequest__439e;

/// Cd_Flank_Protection_Request
/// UML Identifier: _0b4ffc5c-1f23-4bc3-9807-c7035aa818b4
typedef struct Message__CdFlankProtectionRequest__0b4f {
  void *BoundaryId;
  FlankProtectionRequestValues__d52c FlankProtectionRequest;
} Message__CdFlankProtectionRequest__0b4f;

/// Cd_Route_Cancellation_Request
/// UML Identifier: _47be37fb-7b58-4b60-b147-9dcbabd33424
typedef struct Message__CdRouteCancellationRequest__47be {
  void *BoundaryId;
  void *RouteId;
} Message__CdRouteCancellationRequest__47be;

/// Cd_Route_Pretest_Request
/// UML Identifier: _66ce5c6f-6df6-45f8-9b0f-3d143bd43f97
typedef struct Message__CdRoutePretestRequest__66ce {
  void *BoundaryId;
  void *RouteId;
  RouteTypeValues__760f RouteType;
} Message__CdRoutePretestRequest__66ce;

/// Cd_Route_Release_Inhibition_Activation_Request
/// UML Identifier: _b1aa7801-633a-41f8-946a-141c9fb3c123
typedef struct Message__CdRouteReleaseInhibitionActivationRequest__b1aa {
  void *BoundaryId;
} Message__CdRouteReleaseInhibitionActivationRequest__b1aa;

/// Cd_Route_Request
/// UML Identifier: _497ff0ef-0869-4736-9f6a-94c6449daf80
typedef struct Message__CdRouteRequest__497f {
  void *BoundaryId;
  void *RouteId;
  RouteTypeValues__760f RouteType;
} Message__CdRouteRequest__497f;

/// Msg_Access_Restriction_Status
/// UML Identifier: _0bb86f2e-b0fe-4b9a-a69a-cda30997cf27
typedef struct Message__MsgAccessRestrictionStatus__0bb8 {
  void *BoundaryId;
  ActivationStatusValues__c64a AccessRestrictionActivationStatus;
  AccessRestrictionTypeValues__ec25 AccessRestrictionType;
} Message__MsgAccessRestrictionStatus__0bb8;

/// Msg_Activation_Zone_Status
/// UML Identifier: _f1bda046-bf95-487b-b8a1-217ab0e8ef76
typedef struct Message__MsgActivationZoneStatus__f1bd {
  void *BoundaryId;
  void *ActivationZoneId;
  ActivationStatusValues__c64a ActivationZoneStatus;
} Message__MsgActivationZoneStatus__f1bd;

/// Msg_Approach_Zone_Status
/// UML Identifier: _4533568c-9702-4ae4-8d6e-0070cf437ee1
typedef struct Message__MsgApproachZoneStatus__4533 {
  void *BoundaryId;
  void *ApproachZoneId;
  ActivationStatusValues__c64a ApproachZoneStatus;
} Message__MsgApproachZoneStatus__4533;

/// Msg_Flank_Protection_Status
/// UML Identifier: _60487a06-2f09-43eb-b6df-792d30a833c0
typedef struct Message__MsgFlankProtectionStatus__6048 {
  void *BoundaryId;
  FlankProtectionStatusValues__6fea FlankProtectionStatus;
} Message__MsgFlankProtectionStatus__6048;

/// Msg_Line_Direction_Control
/// UML Identifier: _1c8c06a2-447d-4935-922b-94de6be6da2b
typedef struct Message__MsgLineDirectionControl__1c8c {
  void *BoundaryId;
  LineDirectionControlInformation__30e7 LineDirectionControlInformation;
  LineDirectionStatus__2885 LineDirectionStatus;
} Message__MsgLineDirectionControl__1c8c;

/// Msg_Line_Status
/// UML Identifier: _aef2006f-b5f9-432a-abc8-5a0bb7980b85
typedef struct Message__MsgLineStatus__aef2 {
  void *BoundaryId;
  LineStatusValues__594d LineStatus;
} Message__MsgLineStatus__aef2;

/// Msg_Opposite_Main_Signal_Status
/// UML Identifier: _757c334e-356d-4244-a578-ed921bf8c29e
typedef struct Message__MsgOppositeMainSignalStatus__757c {
  void *BoundaryId;
} Message__MsgOppositeMainSignalStatus__757c;

/// Msg_Route_Monitoring_Status
/// UML Identifier: _ecdbee09-bfaf-410f-a098-c5a225df27e4
typedef struct Message__MsgRouteMonitoringStatus__ecdb {
  void *BoundaryId;
  void *RouteId;
  void *OverlapId;
  RouteTypeValues__760f RouteType;
  RouteMonitoringValues__f524 RouteMonitoring;
  RouteOccupancyMonitoringValues__f707 OccupancyMonitoring;
  LevelCrossingMonitoringValues__9e17 LevelCrossingMonitoring;
  int EntranceSpeed;
  int TargetSpeed;
  DynamicOrStaticTargetSpeedValues__d34a DynamicOrStaticTargetSpeed;
} Message__MsgRouteMonitoringStatus__ecdb;

/// Msg_Route_Pretest_Status
/// UML Identifier: _3463e14d-ce71-4cb8-857c-334b08c456cf
typedef struct Message__MsgRoutePretestStatus__3463 {
  void *BoundaryId;
  void *RouteId;
  RouteTypeValues__760f RouteType;
  RouteStatusValues__0758 RouteStatus;
  PretestResponseValues__3b4f PretestResponse;
} Message__MsgRoutePretestStatus__3463;

/// Msg_Route_Release_Inhibition_Status
/// UML Identifier: _cf647570-4c79-4878-a882-236ceefeb1f7
typedef struct Message__MsgRouteReleaseInhibitionStatus__cf64 {
  void *BoundaryId;
  RouteReleaseInhibitionStatusValues__2795 RouteReleaseInhibitionStatus;
} Message__MsgRouteReleaseInhibitionStatus__cf64;

/// Msg_Route_Status
/// UML Identifier: _66eee5b8-2567-4e50-970a-387b466c02a8
typedef struct Message__MsgRouteStatus__66ee {
  void *BoundaryId;
  void *RouteId;
  RouteTypeValues__760f RouteType;
  RouteStatusValues__0758 RouteStatus;
} Message__MsgRouteStatus__66ee;

/// Msg_Signal_Status
/// UML Identifier: _cc56038c-331e-4a94-831f-6a1c8d0920a6
typedef struct Message__MsgSignalStatus__cc56 {
  void *BoundaryId;
  void *AspectLampCombinations;
  void *AspectExtensionLampCombinations;
  void *SpeedIndicator;
  void *SpeedIndicatorAnnouncement;
  void *DirectionIndicator;
  void *DirectionIndicatorAnnouncement;
  SignalIntentionallyDarkValues__d7ce IntentionallyDark;
} Message__MsgSignalStatus__cc56;

/// Msg_TDP_Status
/// UML Identifier: _01c6122f-024c-4ca7-9eb4-14c9139c8841
typedef struct Message__MsgTdpStatus__01c6 {

} Message__MsgTdpStatus__01c6;

/// Msg_Train_Operated_Route_Release_Status
/// UML Identifier: _1b070f95-177a-4dcc-8c7c-48dbd94b5232
typedef struct Message__MsgTrainOperatedRouteReleaseStatus__1b07 {
  void *BoundaryId;
  TrainOperatedRouteReleaseStatusValues__e136 TrainOperatedRouteReleaseStatus;
} Message__MsgTrainOperatedRouteReleaseStatus__1b07;

/// Msg_TVPS_Status
/// UML Identifier: _821b8b1b-6b27-4d76-810a-7fe31785f153
typedef struct Message__MsgTvpsStatus__821b {
  void *BoundaryId;
  TvpsOccupancyStatusValues__0ef9 OccupancyStatus;
  TvpsFoulingStatusValues__a63c FoulingStatus;
} Message__MsgTvpsStatus__821b;

/// Internal_Cd_Abort_Route_Cancellation_Request
/// UML Identifier: _de33f676-d856-4f7a-b843-df9aa9578ecd
typedef struct Message__InternalCdAbortRouteCancellationRequest__de33 {

} Message__InternalCdAbortRouteCancellationRequest__de33;

/// Internal_Cd_Access_Restriction_Request
/// UML Identifier: _40fd6455-ed9f-4e32-b6fd-0e2a105a979c
typedef struct Message__InternalCdAccessRestrictionRequest__40fd {
  void *BoundaryId;
  AccessRestrictionTypeValues__ec25 AccessRestrictionType;
} Message__InternalCdAccessRestrictionRequest__40fd;

/// Internal_Cd_Flank_Protection_Request
/// UML Identifier: _dd7ac899-8ae1-4a8e-8f14-46aaa9c531aa
typedef struct Message__InternalCdFlankProtectionRequest__dd7a {
  void *BoundaryId;
  FlankProtectionRequestValues__d52c FlankProtectionRequest;
} Message__InternalCdFlankProtectionRequest__dd7a;

/// Internal_Cd_Route_Cancellation_Request
/// UML Identifier: _9ffd057a-45be-49f9-96c1-ea8a09e5e77b
typedef struct Message__InternalCdRouteCancellationRequest__9ffd {
  void *BoundaryId;
  void *RouteId;
} Message__InternalCdRouteCancellationRequest__9ffd;

/// Internal_Cd_Route_Pretest_Request
/// UML Identifier: _eb17a1a0-b76c-4cfc-a558-eb70b7c9f619
typedef struct Message__InternalCdRoutePretestRequest__eb17 {
  void *BoundaryId;
  void *RouteId;
  RouteTypeValues__760f RouteType;
} Message__InternalCdRoutePretestRequest__eb17;

/// Internal_Cd_Route_Release_Inhibition_Activation_Request
/// UML Identifier: _3e1ee2bf-1293-47ed-93a5-4e33a584e640
typedef struct
    Message__InternalCdRouteReleaseInhibitionActivationRequest__3e1e {
  void *BoundaryId;
} Message__InternalCdRouteReleaseInhibitionActivationRequest__3e1e;

/// Internal_Cd_Route_Request
/// UML Identifier: _e83a1dad-4546-47b3-8494-7f5badfe2eb5
typedef struct Message__InternalCdRouteRequest__e83a {
  void *BoundaryId;
  void *RouteId;
  RouteTypeValues__760f RouteType;
} Message__InternalCdRouteRequest__e83a;

/// Internal_Msg_Access_Restriction_Status
/// UML Identifier: _be736f8c-1c25-4809-9cff-c59b19d398d3
typedef struct Message__InternalMsgAccessRestrictionStatus__be73 {
  void *BoundaryId;
  ActivationStatusValues__c64a AccessRestrictionActivationStatus;
  AccessRestrictionTypeValues__ec25 AccessRestrictionType;
} Message__InternalMsgAccessRestrictionStatus__be73;

/// Internal_Msg_Activation_Zone_Status
/// UML Identifier: _a71bb896-bcc1-4640-a65a-0dc0ebb7c752
typedef struct Message__InternalMsgActivationZoneStatus__a71b {
  void *BoundaryId;
  void *ActivationZoneId;
  ActivationStatusValues__c64a ActivationZoneStatus;
} Message__InternalMsgActivationZoneStatus__a71b;

/// Internal_Msg_Approach_Zone_Status
/// UML Identifier: _a8cf9e8b-2a24-433f-87df-04fba9566cbe
typedef struct Message__InternalMsgApproachZoneStatus__a8cf {
  void *BoundaryId;
  void *ApproachZoneId;
  ActivationStatusValues__c64a ApproachZoneStatus;
} Message__InternalMsgApproachZoneStatus__a8cf;

/// Internal_Msg_Flank_Protection_Status
/// UML Identifier: _dae3099e-9b6a-4c5a-9605-9adc2a55d279
typedef struct Message__InternalMsgFlankProtectionStatus__dae3 {
  void *BoundaryId;
  FlankProtectionStatusValues__6fea FlankProtectionStatus;
} Message__InternalMsgFlankProtectionStatus__dae3;

/// Internal_Msg_Line_Direction_Control
/// UML Identifier: _bf5bf9d9-12fe-4e29-aac9-a02af2a6f22d
typedef struct Message__InternalMsgLineDirectionControl__bf5b {
  void *BoundaryId;
  LineDirectionControlInformation__30e7 LineDirectionControlInformation;
  LineDirectionStatus__2885 LineDirectionStatus;
} Message__InternalMsgLineDirectionControl__bf5b;

/// Internal_Msg_Line_Status
/// UML Identifier: _21e01dfa-a47f-448f-bf94-bc763ec005e9
typedef struct Message__InternalMsgLineStatus__21e0 {
  void *BoundaryId;
  LineStatusValues__594d LineStatus;
} Message__InternalMsgLineStatus__21e0;

/// Internal_Msg_Opposite_Main_Signal_Status
/// UML Identifier: _c64cdae8-c763-4203-b278-a67d3a0335ea
typedef struct Message__InternalMsgOppositeMainSignalStatus__c64c {
  void *BoundaryId;
} Message__InternalMsgOppositeMainSignalStatus__c64c;

/// Internal_Msg_Route_Monitoring_Status
/// UML Identifier: _c7a6d905-b63f-4030-8d52-c0bb628beb58
typedef struct Message__InternalMsgRouteMonitoringStatus__c7a6 {
  void *BoundaryId;
  void *RouteId;
  void *OverlapId;
  RouteTypeValues__760f RouteType;
  RouteMonitoringValues__f524 RouteMonitoring;
  RouteOccupancyMonitoringValues__f707 OccupancyMonitoring;
  LevelCrossingMonitoringValues__9e17 LevelCrossingMonitoring;
  int EntranceSpeed;
  int TargetSpeed;
  DynamicOrStaticTargetSpeedValues__d34a DynamicOrStaticTargetSpeed;
} Message__InternalMsgRouteMonitoringStatus__c7a6;

/// Internal_Msg_Route_Pretest_Status
/// UML Identifier: _e074a94a-fc34-4179-9668-caacbe377c74
typedef struct Message__InternalMsgRoutePretestStatus__e074 {
  void *BoundaryId;
  void *RouteId;
  RouteTypeValues__760f RouteType;
  RouteStatusValues__0758 RouteStatus;
  PretestResponseValues__3b4f PretestResponse;
} Message__InternalMsgRoutePretestStatus__e074;

/// Internal_Msg_Route_Release_Inhibition_Status
/// UML Identifier: _1a5859c4-4e63-4a1b-8d29-71523fb8f3bb
typedef struct Message__InternalMsgRouteReleaseInhibitionStatus__1a58 {
  void *BoundaryId;
  RouteReleaseInhibitionStatusValues__2795 RouteReleaseInhibitionStatus;
} Message__InternalMsgRouteReleaseInhibitionStatus__1a58;

/// Internal_Msg_Route_Status
/// UML Identifier: _9f046ae0-4da4-4dcf-970d-8d94eef13ab8
typedef struct Message__InternalMsgRouteStatus__9f04 {
  void *BoundaryId;
  void *RouteId;
  RouteTypeValues__760f RouteType;
  RouteStatusValues__0758 RouteStatus;
} Message__InternalMsgRouteStatus__9f04;

/// Internal_Msg_Signal_Status
/// UML Identifier: _f4bd9f32-2287-4d8f-9ac0-4af14ab0d69a
typedef struct Message__InternalMsgSignalStatus__f4bd {
  void *BoundaryId;
  void *AspectLampCombinations;
  void *AspectExtensionLampCombinations;
  void *SpeedIndicator;
  void *SpeedIndicatorAnnouncement;
  void *DirectionIndicator;
  void *DirectionIndicatorAnnouncement;
  SignalIntentionallyDarkValues__d7ce IntentionallyDark;
} Message__InternalMsgSignalStatus__f4bd;

/// Internal_Msg_TDP_Status
/// UML Identifier: _f254118f-df39-4d78-b200-5b9590e96e13
typedef struct Message__InternalMsgTdpStatus__f254 {

} Message__InternalMsgTdpStatus__f254;

/// Internal_Msg_Train_Operated_Route_Release_Status
/// UML Identifier: _7cd8a97b-8862-4553-8688-c75a655ac664
typedef struct Message__InternalMsgTrainOperatedRouteReleaseStatus__7cd8 {
  void *BoundaryId;
  TrainOperatedRouteReleaseStatusValues__e136 TrainOperatedRouteReleaseStatus;
} Message__InternalMsgTrainOperatedRouteReleaseStatus__7cd8;

/// Internal_Msg_TVPS_Status
/// UML Identifier: _7cb25494-eb89-4681-9241-e01a36a952c4
typedef struct Message__InternalMsgTvpsStatus__7cb2 {
  void *BoundaryId;
  TvpsOccupancyStatusValues__0ef9 OccupancyStatus;
  TvpsFoulingStatusValues__a63c FoulingStatus;
} Message__InternalMsgTvpsStatus__7cb2;

/// Cd_Msg_XX
/// UML Identifier: _909a5ceb-94fe-4d5f-9108-3cbea7827075
typedef struct Message__CdMsgXx__909a {
  void *Type;
  void *Information;
} Message__CdMsgXx__909a;

/// Signal1
/// UML Identifier: _c0051843-4563-4769-974b-92b7720799b6
typedef struct Message__Signal1__c005 {

} Message__Signal1__c005;

/// Cd_IO_Element_Control
/// UML Identifier: _60235288-60a1-448b-94ae-c7a1cd1dbc4f
typedef struct Message__CdIoElementControl__6023 {

} Message__CdIoElementControl__6023;

/// Cd_LX_Control
/// UML Identifier: _707f667a-c4d6-4cab-9549-0ee20f0d4984
typedef struct Message__CdLxControl__707f {

} Message__CdLxControl__707f;

/// Cd_Preset_Signal_BG
/// UML Identifier: _ff60d1b4-ea9e-4568-ad2d-d3a48520ac22
typedef struct Message__CdPresetSignalBg__ff60 {

} Message__CdPresetSignalBg__ff60;

/// Cd_Route_Cancelling
/// UML Identifier: _d08eaa87-a5f2-4c26-b3cb-0cda944e1947
typedef struct Message__CdRouteCancelling__d08e {

} Message__CdRouteCancelling__d08e;

/// Cd_Route_Control
/// UML Identifier: _503fa18d-aafb-4775-99da-0fe83bbc54d5
typedef struct Message__CdRouteControl__503f {

} Message__CdRouteControl__503f;

/// Cd_Signal_Cancelling
/// UML Identifier: _49989abe-7048-46b9-9762-b11cff79d6f2
typedef struct Message__CdSignalCancelling__4998 {

} Message__CdSignalCancelling__4998;

/// Cd_Signal_Control
/// UML Identifier: _b42442c1-c1d6-4f3d-92ec-c7150b1ff786
typedef struct Message__CdSignalControl__b424 {

} Message__CdSignalControl__b424;

/// Cd_Signal_Overlap_Control
/// UML Identifier: _a29ac37d-6f9c-4893-9c08-40ebacb774be
typedef struct Message__CdSignalOverlapControl__a29a {

} Message__CdSignalOverlapControl__a29a;

/// Msg_BG_Status
/// UML Identifier: _49886304-c2af-4d1d-8926-02f13a976e58
typedef struct Message__MsgBgStatus__4988 {

} Message__MsgBgStatus__4988;

/// Msg_ESA_Status
/// UML Identifier: _c2dd8931-715a-4e80-95d8-91424864a9a5
typedef struct Message__MsgEsaStatus__c2dd {

} Message__MsgEsaStatus__c2dd;

/// Msg_Flank_Protection_Status
/// UML Identifier: _2c725904-3091-4977-ab3d-29da5aed539c
typedef struct Message__MsgFlankProtectionStatus__2c72 {

} Message__MsgFlankProtectionStatus__2c72;

/// Msg_Group_Failure
/// UML Identifier: _c827a1ca-1b5a-411c-8e92-180c725f62f7
typedef struct Message__MsgGroupFailure__c827 {

} Message__MsgGroupFailure__c827;

/// Msg_IO_Element_Status
/// UML Identifier: _eb3ae8a2-38f6-4cc3-b0ca-b3613b82d7c7
typedef struct Message__MsgIoElementStatus__eb3a {

} Message__MsgIoElementStatus__eb3a;

/// Msg_LSA_Status
/// UML Identifier: _2006d620-dfcd-4ccb-bb79-cb0f30baf41b
typedef struct Message__MsgLsaStatus__2006 {

} Message__MsgLsaStatus__2006;

/// Msg_LX_Status
/// UML Identifier: _70ba5c2a-c293-4662-b8ff-4d7742cd6acc
typedef struct Message__MsgLxStatus__70ba {

} Message__MsgLxStatus__70ba;

/// Msg_Point_Status
/// UML Identifier: _137783e0-15e2-4d57-9f13-e0079aa65717
typedef struct Message__MsgPointStatus__1377 {

} Message__MsgPointStatus__1377;

/// Msg_Preset_Signal_BG_Reply
/// UML Identifier: _62bf301d-0e11-4208-9ed1-6f98841d8141
typedef struct Message__MsgPresetSignalBgReply__62bf {

} Message__MsgPresetSignalBgReply__62bf;

/// Msg_Route_Cancelling_Reply
/// UML Identifier: _76b1864f-b540-4fe0-983a-e2c8e2212230
typedef struct Message__MsgRouteCancellingReply__76b1 {

} Message__MsgRouteCancellingReply__76b1;

/// Msg_Route_Occupation
/// UML Identifier: _0c9fd8d8-061c-4a39-8187-e08d75b29dd5
typedef struct Message__MsgRouteOccupation__0c9f {

} Message__MsgRouteOccupation__0c9f;

/// Msg_Route_Status
/// UML Identifier: _856c9a8a-2ffb-4e41-a440-7c5b8701217b
typedef struct Message__MsgRouteStatus__856c {

} Message__MsgRouteStatus__856c;

/// Msg_Signal_Cancelling_Reply
/// UML Identifier: _dbb22460-76d1-43b6-ab8f-86d0b05b0913
typedef struct Message__MsgSignalCancellingReply__dbb2 {

} Message__MsgSignalCancellingReply__dbb2;

/// Msg_Signal_Occupation
/// UML Identifier: _2fd888c9-32fa-4f74-bdea-e5e7650dd11a
typedef struct Message__MsgSignalOccupation__2fd8 {

} Message__MsgSignalOccupation__2fd8;

/// Msg_Signal_Status
/// UML Identifier: _d0ee8cf8-8b85-403d-b21a-831ebe378ea7
typedef struct Message__MsgSignalStatus__d0ee {

} Message__MsgSignalStatus__d0ee;

/// Msg_Train_Data
/// UML Identifier: _95a65d03-3d97-432d-9d3b-2ddeea3b33bc
typedef struct Message__MsgTrainData__95a6 {

} Message__MsgTrainData__95a6;

/// Msg_TVP_Section_Status
/// UML Identifier: _3c7fcaf5-9732-471c-b941-2d52b962e492
typedef struct Message__MsgTvpSectionStatus__3c7f {

} Message__MsgTvpSectionStatus__3c7f;

/// Msg_WA_Status
/// UML Identifier: _47d2f44e-fae4-4e1f-a509-0c72e34df316
typedef struct Message__MsgWaStatus__47d2 {

} Message__MsgWaStatus__47d2;

/// Cd_Set_Output_Channels
/// UML Identifier: _3b5f9c91-e433-4819-b6be-fcfd61aa7b85
typedef struct Message__CdSetOutputChannels__3b5f {
  OutputChannelControllableState__80ea CommandedOutputState1;
  OutputChannelControllableState__80ea CommandedOutputStateN;
} Message__CdSetOutputChannels__3b5f;

/// Msg_State_Of_Input_Channels
/// UML Identifier: _8132b637-4502-4b32-8f97-04ca45189c3a
typedef struct Message__MsgStateOfInputChannels__8132 {
  InputChannelState__a4d2 ResportedInputState1;
  InputChannelState__a4d2 ResportedInputStateN;
} Message__MsgStateOfInputChannels__8132;

/// Msg_State_Of_Output_Channels
/// UML Identifier: _c6d654fc-43ff-4d98-a5ce-d779077ce857
typedef struct Message__MsgStateOfOutputChannels__c6d6 {
  OutputChannelDisturbanceState__bed9 ResportedDisturbanceState1;
  OutputChannelDisturbanceState__bed9 ResportedDisturbanceStateN;
} Message__MsgStateOfOutputChannels__c6d6;

/// Cd_Activation
/// UML Identifier: _3513c0ba-d34e-42d5-abfc-09866dc5549b
typedef struct Message__CdActivation__3513 {
  ActivationControlableState__4140 CommandedActivationState;
} Message__CdActivation__3513;

/// Cd_Deactivation
/// UML Identifier: _48b565d4-e1ab-40e1-84d8-638793c8e396
typedef struct Message__CdDeactivation__48b5 {
  DeactivationControlableState__514f CommandedDeactivationState;
} Message__CdDeactivation__48b5;

/// Cd_Isolate_LC
/// UML Identifier: _add904da-ec89-464a-93ae-cb54f5e3d2f3
typedef struct Message__CdIsolateLc__add9 {
  IsolateLevelCrossingControlableState__55c1 CommandedIsolateState;
} Message__CdIsolateLc__add9;

/// Cd_Local_Operation_Handover
/// UML Identifier: _2b725991-bf02-4cab-ae45-ec14ac1b4010
typedef struct Message__CdLocalOperationHandover__2b72 {
  LocalOperationHandoverControlableState__9164 CommandedHandoverState;
} Message__CdLocalOperationHandover__2b72;

/// Msg_Detection_Element_Status
/// UML Identifier: _aa8ba199-589b-4c57-a30e-23f84fd3f859
typedef struct Message__MsgDetectionElementStatus__aa8b {
  DetectionElementStatusState__4b10 ReportedDetectionElementStatusState;
} Message__MsgDetectionElementStatus__aa8b;

/// Msg_LC_Failure_Status
/// UML Identifier: _5440725f-5f89-463d-88c2-cff91d260e45
typedef struct Message__MsgLcFailureStatus__5440 {
  NonCriticalFailureStatusState__b376 ReportedNonCriticalFailureState;
  CriticalFailureStatusState__f095 ReportedCriticalFailureState;
} Message__MsgLcFailureStatus__5440;

/// Msg_LC_Functional_Status
/// UML Identifier: _ab8c67b9-e9c9-4549-9ac7-0627bddca4af
typedef struct Message__MsgLcFunctionalStatus__ab8c {
  FunctionalStatusState__5d12 ReportedActivationlStatusState;
} Message__MsgLcFunctionalStatus__ab8c;

/// Msg_LC_Monitoring_Status
/// UML Identifier: _1d451154-23ca-4ba2-a275-dd977451df8f
typedef struct Message__MsgLcMonitoringStatus__1d45 {
  TimeOverrunState__b8ce ReportedTimeOverrunState;
  ChangendMonitoringStatus__6c2c ReportedChangedMonitoringParameter;
} Message__MsgLcMonitoringStatus__1d45;

/// Msg_Local_Operation_Handover
/// UML Identifier: _0594e445-4f73-4600-b6fa-6ea8eb085fe1
typedef struct Message__MsgLocalOperationHandover__0594 {
  LocalOperationHandoverState__ee05 ReportedLocalOperationHandoverState;
} Message__MsgLocalOperationHandover__0594;

/// Msg_Local_Request
/// UML Identifier: _daeb7b23-f630-4410-94e2-51148cbe0e46
typedef struct Message__MsgLocalRequest__daeb {
  LocalRequestState__d488 ReportedLocalRequestState;
} Message__MsgLocalRequest__daeb;

/// Msg_Obstacle_Detection_Status
/// UML Identifier: _734db8d7-5cda-478b-8ce9-8b51929db8a0
typedef struct Message__MsgObstacleDetectionStatus__734d {
  ObstacleDetectionStatusState__5aa0 ReportedObstacleDetectionStatusState;
} Message__MsgObstacleDetectionStatus__734d;

/// Cd_Indicate_Signal_Aspect
/// UML Identifier: _e57027d2-fc80-42b8-84d4-bd112a17f041
typedef struct Message__CdIndicateSignalAspect__e570 {
  SignalAspectControlableState__0dcc CommandedSignalAspectState;
  bool CommandedDarkState;
} Message__CdIndicateSignalAspect__e570;

/// Cd_Set_Luminosity
/// UML Identifier: _457085b3-1992-444c-bb8a-0190de7ee36a
typedef struct Message__CdSetLuminosity__4570 {
  LuminosityState__20ae CommandedLuminosityState;
} Message__CdSetLuminosity__4570;

/// Msg_Indicated_Signal_Aspect
/// UML Identifier: _e1299b18-fef4-4c6a-894e-63a188778481
typedef struct Message__MsgIndicatedSignalAspect__e129 {
  SignalAspectState__f566 ReportedSignalAspectState;
  bool ReportedDarkState;
} Message__MsgIndicatedSignalAspect__e129;

/// Msg_Set_Luminosity
/// UML Identifier: _c2b47bb3-0345-44f5-b510-c48be693142f
typedef struct Message__MsgSetLuminosity__c2b4 {
  LuminosityState__20ae ReportedLuminosityState;
} Message__MsgSetLuminosity__c2b4;

/// Cd_Move_Point
/// UML Identifier: _342e4e67-6e20-495c-8078-f4b65d014046
typedef struct Message__CdMovePoint__342e {
  PointPositionControlableState__14bc CommandedPointPositionState;
} Message__CdMovePoint__342e;

/// Msg_Ability_To_Move_Point
/// UML Identifier: _1f1b661e-1c9a-40c5-a7a3-4a1656382d30
typedef struct Message__MsgAbilityToMovePoint__1f1b {
  AbilityToMoveState__ed0f ReportedAbilityToMoveState;
} Message__MsgAbilityToMovePoint__1f1b;

/// Msg_Movement_Failed
/// UML Identifier: _ff4fd851-2588-468e-af3a-f65c9f4b695f
typedef struct Message__MsgMovementFailed__ff4f {

} Message__MsgMovementFailed__ff4f;

/// Msg_Point_Position
/// UML Identifier: _27c171fe-43d8-4daa-a90f-227432d733ab
typedef struct Message__MsgPointPosition__27c1 {
  PointPositionState__2e6f ReportedPointPositionState;
  PointPositionDegradedState__422e ReportedDegradedPointPosition;
} Message__MsgPointPosition__27c1;

/// Cd_Cancel
/// UML Identifier: _6acf8bb8-a3cf-48f4-9b6a-f6c98c12480a
typedef struct Message__CdCancel__6acf {

} Message__CdCancel__6acf;

/// Cd_DRFC
/// UML Identifier: _15c72a1d-fdab-414e-a1cd-63bc15c7cac3
typedef struct Message__CdDrfc__15c7 {

} Message__CdDrfc__15c7;

/// Cd_FC
/// UML Identifier: _ec572f37-b79f-4068-be24-d3eb80835a9d
typedef struct Message__CdFc__ec57 {
  ModeOfFC__fc54 CommandedModeOfFC;
} Message__CdFc__ec57;

/// Cd_Update_Filling_Level
/// UML Identifier: _d24dbc0f-b2ad-4141-9b1e-49e6a90aea78
typedef struct Message__CdUpdateFillingLevel__d24d {

} Message__CdUpdateFillingLevel__d24d;

/// Msg_Command_Rejected
/// UML Identifier: _8d0bdab7-aa7c-4e10-b66b-9c0d523f5809
typedef struct Message__MsgCommandRejected__8d0b {
  ReasonForRejection__abec ReportedReasonForRejection;
} Message__MsgCommandRejected__8d0b;

/// Msg_TDP_Status
/// UML Identifier: _b6d93f3b-74a3-4efd-aee0-f4e78300123d
typedef struct Message__MsgTdpStatus__b6d9 {
  StateOfPassing__616f ReportedStateOfPassing;
  DirectionOfPassing__a7c9 ReportedDirectionOfPassing;
} Message__MsgTdpStatus__b6d9;

/// Msg_TVPS_FC_P_A_failed
/// UML Identifier: _3c6194b6-5c51-4f34-8e65-6455b0b27b8d
typedef struct Message__MsgTvpsFcPAFailed__3c61 {
  ReasonForFailure__b02d ReportedReasonForFailure;
} Message__MsgTvpsFcPAFailed__3c61;

/// Msg_TVPS_FC_P_failed
/// UML Identifier: _811b4b77-eeb6-4f88-a072-16c4db414782
typedef struct Message__MsgTvpsFcPFailed__811b {
  ReasonForFailure__b02d ReportedReasonForFailure;
} Message__MsgTvpsFcPFailed__811b;

/// Msg_TVPS_Occupancy_Status
/// UML Identifier: _b4e1a796-0ae4-4fd2-a860-0549bc61db69
typedef struct Message__MsgTvpsOccupancyStatus__b4e1 {
  OccupancyStatus__65fa ReportedOccupancyStatus;
  AbilityToBeForcedToClear__8b12 ReportedAbilityToBeForcedToClear;
  PomStatus__d74a ReportedpomStatus;
  int FillingLevel;
  DisturbanceStatus__fd65 ReportedDisturbanceStatus;
  ChangeTrigger__de2d ReportedChangeTrigger;
} Message__MsgTvpsOccupancyStatus__b4e1;

/// Change_Trigger
/// UML Identifier: _e05eb385-2786-4931-97c1-59bf13ce7b6a
typedef struct Message__ChangeTrigger__e05e {
  ChangeTrigger__de2d ReportedChangeTrigger;
} Message__ChangeTrigger__e05e;

/// Confirm_Acknowledgement
/// UML Identifier: _3cca6017-6dc6-4146-8698-fb63f7155403
typedef struct Message__ConfirmAcknowledgement__3cca {

} Message__ConfirmAcknowledgement__3cca;

/// Execute_Cancel
/// UML Identifier: _045b3b5f-d4ac-4f78-8b41-4e8829d96a69
typedef struct Message__ExecuteCancel__045b {

} Message__ExecuteCancel__045b;

/// Execute_DRFC
/// UML Identifier: _4da595c8-87f7-46b9-b691-96d6f211c7b7
typedef struct Message__ExecuteDrfc__4da5 {

} Message__ExecuteDrfc__4da5;

/// Execute_FC
/// UML Identifier: _ffe5b51d-ee4b-4bd8-b0b9-a1569d87561c
typedef struct Message__ExecuteFc__ffe5 {

} Message__ExecuteFc__ffe5;

/// Execute_FC_P
/// UML Identifier: _c2bdf4b7-c8e5-479e-8219-b709b1cb9588
typedef struct Message__ExecuteFcP__c2bd {

} Message__ExecuteFcP__c2bd;

/// Execute_FC_P_A
/// UML Identifier: _f496bcb5-6e3e-4326-b276-33ea813effa2
typedef struct Message__ExecuteFcPA__f496 {

} Message__ExecuteFcPA__f496;

/// Execute_UFL
/// UML Identifier: _f8ea58d0-533c-44ed-9dc4-878fc6e2e03b
typedef struct Message__ExecuteUfl__f8ea {

} Message__ExecuteUfl__f8ea;

/// Execute_Visual_Sweeping_Confirmation
/// UML Identifier: _251f7306-bf23-419e-bfe1-c726b50e7a4b
typedef struct Message__ExecuteVisualSweepingConfirmation__251f {

} Message__ExecuteVisualSweepingConfirmation__251f;

/// Reason_FC_P_A_failed
/// UML Identifier: _668aa211-f914-4622-8da8-e4b62af04e3f
typedef struct Message__ReasonFcPAFailed__668a {
  ReasonForFailure__b02d ReportedReasonForFailure;
} Message__ReasonFcPAFailed__668a;

/// Reason_FC_P_failed
/// UML Identifier: _bfddaed9-182c-422d-bfaa-3aaff37a5092
typedef struct Message__ReasonFcPFailed__bfdd {
  ReasonForFailure__b02d ReportedReasonForFailure;
} Message__ReasonFcPFailed__bfdd;

/// Report_Command_Rejected
/// UML Identifier: _fa56c8b2-a785-4aa9-9343-6ea6df8acb9a
typedef struct Message__ReportCommandRejected__fa56 {
  ReasonForRejection__abec ReportedReasonForRejection;
} Message__ReportCommandRejected__fa56;

/// Request_Acknowledgement
/// UML Identifier: _28425986-558e-4066-af61-967104bc8a9e
typedef struct Message__RequestAcknowledgement__2842 {

} Message__RequestAcknowledgement__2842;

/// Request_Cancel
/// UML Identifier: _7d24c433-807d-47b6-94f9-c38b778c319d
typedef struct Message__RequestCancel__7d24 {

} Message__RequestCancel__7d24;

/// Request_DRFC
/// UML Identifier: _a48b8729-1089-40dd-8f88-f208e1ce434b
typedef struct Message__RequestDrfc__a48b {
  SourceOfCommand__d5a9 ReportedSource;
} Message__RequestDrfc__a48b;

/// Request_FC_C
/// UML Identifier: _f9025b6c-0897-4701-b29a-7ffecef1b11a
typedef struct Message__RequestFcC__f902 {
  SourceOfCommand__d5a9 ReportedSource;
} Message__RequestFcC__f902;

/// Request_FC_P
/// UML Identifier: _e8be8c50-7622-40d2-b8cc-952e7ef8a554
typedef struct Message__RequestFcP__e8be {

} Message__RequestFcP__e8be;

/// Request_FC_P_A
/// UML Identifier: _edba05d0-23de-45e4-b4e1-12b3bab2f106
typedef struct Message__RequestFcPA__edba {

} Message__RequestFcPA__edba;

/// Request_FC_U
/// UML Identifier: _bd99b808-2934-45ee-965e-1395f2d775d4
typedef struct Message__RequestFcU__bd99 {
  SourceOfCommand__d5a9 ReportedSource;
} Message__RequestFcU__bd99;

/// Request_UFL
/// UML Identifier: _f416e4f1-dbf6-4e18-8127-b4d631cb7bf6
typedef struct Message__RequestUfl__f416 {

} Message__RequestUfl__f416;

/// Request_Visual_Sweeping_Confirmation
/// UML Identifier: _23330e0e-50ce-458e-93f3-b9c56d5cd8b1
typedef struct Message__RequestVisualSweepingConfirmation__2333 {

} Message__RequestVisualSweepingConfirmation__2333;

/// Data_Update_Finished
/// UML Identifier: _0937d145-a58e-4ddd-886d-cb12fe5fd0eb
typedef struct Message__DataUpdateFinished__0937 {

} Message__DataUpdateFinished__0937;

/// Data_Update_Stop
/// UML Identifier: _cf0d7c83-4544-472f-ab79-b5b3ac3f1c19
typedef struct Message__DataUpdateStop__cf0d {

} Message__DataUpdateStop__cf0d;

/// EST_Ready_For_Maintenance
/// UML Identifier: _dd9a0c5d-58f3-4355-8a11-22d041169de2
typedef struct Message__EstReadyForMaintenance__dd9a {

} Message__EstReadyForMaintenance__dd9a;

/// MDM_Commanded_Maintenance
/// UML Identifier: _a9926753-601e-4061-81e7-39f4d179e28f
typedef struct Message__MdmCommandedMaintenance__a992 {

} Message__MdmCommandedMaintenance__a992;

/// MDM_Triggered_Reset
/// UML Identifier: _00d06ee8-baf4-4b23-9d5a-05d4708efcf0
typedef struct Message__MdmTriggeredReset__00d0 {

} Message__MdmTriggeredReset__00d0;

/// NotReady_For_PDI_Connection
/// UML Identifier: _0b73073d-dcf9-458f-9a7f-c51766c5590c
typedef struct Message__NotreadyForPdiConnection__0b73 {

} Message__NotreadyForPdiConnection__0b73;

/// PDI_Connection_Closed
/// UML Identifier: _d803971d-349b-416b-954b-4a23407817d3
typedef struct Message__PdiConnectionClosed__d803 {

} Message__PdiConnectionClosed__d803;

/// PDI_Connection_Established
/// UML Identifier: _4cbf9fcc-c130-4977-9da7-78ce482af7e0
typedef struct Message__PdiConnectionEstablished__4cbf {

} Message__PdiConnectionEstablished__4cbf;

/// PDI_Connection_Started
/// UML Identifier: _f9c3330c-5b9a-46fc-b4d3-866c48edbe02
typedef struct Message__PdiConnectionStarted__f9c3 {

} Message__PdiConnectionStarted__f9c3;

/// PDI_Released_For_Maintenance
/// UML Identifier: _3f7ce166-2108-410d-8016-aa06ec1f935e
typedef struct Message__PdiReleasedForMaintenance__3f7c {

} Message__PdiReleasedForMaintenance__3f7c;

/// Ready_For_PDI_Connection
/// UML Identifier: _6bd30c55-f317-47f1-8b1e-1b6becf9e5a8
typedef struct Message__ReadyForPdiConnection__6bd3 {

} Message__ReadyForPdiConnection__6bd3;

/// Reboot_Required
/// UML Identifier: _bc8e2ca2-2c25-4585-ba3b-ec695bccfc35
typedef struct Message__RebootRequired__bc8e {

} Message__RebootRequired__bc8e;

// Logging
#define LOG(...)                                                               \
  fprintf(stderr, __VA_ARGS__);                                                \
  fprintf(stderr, "\n")
