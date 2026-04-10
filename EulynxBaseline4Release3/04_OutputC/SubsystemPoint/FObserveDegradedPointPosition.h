
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveDegradedPointPosition_D10inPm1CrucialPositionValue {
  FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__NULL__,
  FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Left,
  FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Right,
  FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__NoEndPosition,
  FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__UnintendedPosition,
  FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D10inPm1CrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D10inPmiCrucialPositionValue {
  FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__NULL__,
  FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__Left,
  FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__Right,
  FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__NoEndPosition,
  FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__UnintendedPosition,
  FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D10inPmiCrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue {
  FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NULL__,
  FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NoEndPosition,
  FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition,
  FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__Right,
  FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__Left,
  FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue {
  FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NULL__,
  FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NoEndPosition,
  FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition,
  FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__Right,
  FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__Left,
  FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue;
typedef enum FObserveDegradedPointPosition_D51inEstEfesStateValue {
  FObserveDegradedPointPosition_D51inEstEfesStateValue__NULL__,
  FObserveDegradedPointPosition_D51inEstEfesStateValue__Initialising,
  FObserveDegradedPointPosition_D51inEstEfesStateValue__NoOperatingVoltage,
  FObserveDegradedPointPosition_D51inEstEfesStateValue__Booting,
  FObserveDegradedPointPosition_D51inEstEfesStateValue__FallbackMode,
  FObserveDegradedPointPosition_D51inEstEfesStateValue__UNKNOWN__
} FObserveDegradedPointPosition_D51inEstEfesStateValue;
typedef enum FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue {
  FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__NULL__,
  FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedRight,
  FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__NotDegraded,
  FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedLeft,
  FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedDenied,
  FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__Undefined,
  FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue;
typedef enum FObserveDegradedPointPosition_D14inObservedPointPositionValue {
  FObserveDegradedPointPosition_D14inObservedPointPositionValue__NULL__,
  FObserveDegradedPointPosition_D14inObservedPointPositionValue__Left,
  FObserveDegradedPointPosition_D14inObservedPointPositionValue__Right,
  FObserveDegradedPointPosition_D14inObservedPointPositionValue__UNKNOWN__
} FObserveDegradedPointPosition_D14inObservedPointPositionValue;

typedef enum FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state {
  FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation,
  FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight,
  FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded,
  FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft,
  FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied
} FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state;

typedef struct
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct {
  FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state
      state;
  union {};
} FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct;

typedef enum FObserveDegradedPointPosition__root__state {
  FObserveDegradedPointPosition__root__ObserveDegradedPointPosition
} FObserveDegradedPointPosition__root__state;

typedef struct
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__state_struct {
  FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct
      root;
} FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__state_struct;

typedef struct FObserveDegradedPointPosition__root__state_struct {
  FObserveDegradedPointPosition__root__state state;
  union {
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__state_struct
        ObserveDegradedPointPosition;
  };
} FObserveDegradedPointPosition__root__state_struct;

/// Contained in:
/// Subsystem - Point
/// Functional requirements specification
/// Subsystem - Point - Functional Viewpoint
/// Subsystem - Point - Functional Entities
typedef struct FObserveDegradedPointPosition {
  FObserveDegradedPointPosition__root__state_struct state;

  /// D10in_PM1_Crucial_Position
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(FObserveDegradedPointPosition_D10inPm1CrucialPositionValue, )
      D10inPm1CrucialPosition;

  /// D10in_PMi_Crucial_Position
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(FObserveDegradedPointPosition_D10inPmiCrucialPositionValue, )
      D10inPmiCrucialPosition;

  /// D10in_PM1_Non_Crucial_Position
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue, )
      D10inPm1NonCrucialPosition;

  /// D10in_PMk_Non_Crucial_Position
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue, )
      D10inPmkNonCrucialPosition;

  /// d51in_EST_EfeS_State
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FObserveDegradedPointPosition_D51inEstEfesStateValue, )
      D51inEstEfesState;

  /// D26in_Con_PMi_Crucial_Activation
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D26inConPmiCrucialActivation;

  /// D27in_Con_PM1_Non_Crucial_Activation
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D27inConPm1NonCrucialActivation;

  /// D28in_Con_PMk_Non_Crucial_Activation
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D28inConPmkNonCrucialActivation;

  /// d17out_Observed_Degraded_Point_Position
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(
      FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue, )
      D17outObservedDegradedPointPosition;

  /// d14in_Observed_Point_Position
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FObserveDegradedPointPosition_D14inObservedPointPositionValue, )
      D14inObservedPointPosition;

  // Messages -- Incoming

  // Messages -- Outgoing

  // Change Events
  ChangeEvent Change360; // d51in_EST_EfeS_State = "INITIALISING"
  ChangeEvent
      Change10; // (d14in_Observed_Point_Position = "LEFT" OR
                // d14in_Observed_Point_Position = "RIGHT") OR
                // ((D10in_PM1_Crucial_Position <> D10in_PMi_Crucial_Position)
                // AND D26in_Con_PMi_Crucial_Activation) OR
                // ((D10in_PM1_Non_Crucial_Position <>
                // D10in_PM1_Crucial_Position AND D10in_PM1_Non_Crucial_Position
                // <> "UNINTENDED_POSITION" AND D10in_PM1_Non_Crucial_Position
                // <> "NO_END_POSITION")AND
                // D27in_Con_PM1_Non_Crucial_Activation) OR
                // ((D10in_PMk_Non_Crucial_Position <>
                // D10in_PM1_Crucial_Position AND D10in_PMk_Non_Crucial_Position
                // <> "UNINTENDED_POSITION" AND D10in_PMk_Non_Crucial_Position
                // <> "NO_END_POSITION")AND
                // D28in_Con_PMk_Non_Crucial_Activation)
  ChangeEvent
      Change26; // D10in_PM1_Crucial_Position = "LEFT" AND
                // (D10in_PMi_Crucial_Position = "LEFT" OR NOT
                // D26in_Con_PMi_Crucial_Activation) AND
                // ((D10in_PMk_Non_Crucial_Position = "NO_END_POSITION" OR
                // D10in_PMk_Non_Crucial_Position = "UNINTENDED_POSITION") OR
                // (D10in_PM1_Non_Crucial_Position = "NO_END_POSITION" OR
                // D10in_PM1_Non_Crucial_Position = "UNINTENDED_POSITION"))
  ChangeEvent
      Change27; // D10in_PM1_Crucial_Position = "LEFT" AND
                // (D10in_PMi_Crucial_Position = "LEFT" OR NOT
                // D26in_Con_PMi_Crucial_Activation) AND
                // ((((D10in_PMk_Non_Crucial_Position = "NO_END_POSITION" OR
                // D10in_PMk_Non_Crucial_Position = "UNINTENDED_POSITION") AND
                // D10in_PM1_Non_Crucial_Position <> "RIGHT")) OR
                // (((D10in_PM1_Non_Crucial_Position = "NO_END_POSITION" OR
                // D10in_PM1_Non_Crucial_Position = "UNINTENDED_POSITION") AND
                // D10in_PMk_Non_Crucial_Position <> "RIGHT")))
  ChangeEvent
      Change28; // D10in_PM1_Crucial_Position = "RIGHT" AND
                // (D10in_PMi_Crucial_Position = "RIGHT" OR NOT
                // D26in_Con_PMi_Crucial_Activation) AND
                // ((((D10in_PMk_Non_Crucial_Position = "NO_END_POSITION" OR
                // D10in_PMk_Non_Crucial_Position = "UNINTENDED_POSITION") AND
                // D10in_PM1_Non_Crucial_Position <> "LEFT")) OR
                // (((D10in_PM1_Non_Crucial_Position = "NO_END_POSITION" OR
                // D10in_PM1_Non_Crucial_Position = "UNINTENDED_POSITION") AND
                // D10in_PMk_Non_Crucial_Position <> "LEFT")))
  ChangeEvent
      Change9; // (d14in_Observed_Point_Position = "LEFT" OR
               // d14in_Observed_Point_Position = "RIGHT") OR
               // ((D10in_PM1_Crucial_Position <> D10in_PMi_Crucial_Position)
               // AND D26in_Con_PMi_Crucial_Activation) OR
               // ((D10in_PM1_Non_Crucial_Position <> D10in_PM1_Crucial_Position
               // AND D10in_PM1_Non_Crucial_Position <> "UNINTENDED_POSITION"
               // AND D10in_PM1_Non_Crucial_Position <> "NO_END_POSITION")AND
               // D27in_Con_PM1_Non_Crucial_Activation)
               // OR((D10in_PMk_Non_Crucial_Position <>
               // D10in_PM1_Crucial_Position AND D10in_PMk_Non_Crucial_Position
               // <> "UNINTENDED_POSITION" AND D10in_PMk_Non_Crucial_Position <>
               // "NO_END_POSITION")AND D28in_Con_PMk_Non_Crucial_Activation)
  ChangeEvent
      Change29; // D10in_PM1_Crucial_Position = "RIGHT" AND
                // (D10in_PMi_Crucial_Position = "RIGHT" OR NOT
                // D26in_Con_PMi_Crucial_Activation) AND
                // ((D10in_PMk_Non_Crucial_Position = "NO_END_POSITION" OR
                // D10in_PMk_Non_Crucial_Position = "UNINTENDED_POSITION") OR
                // (D10in_PM1_Non_Crucial_Position = "NO_END_POSITION" OR
                // D10in_PM1_Non_Crucial_Position = "UNINTENDED_POSITION"))
  ChangeEvent Change374; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR
                         // d51in_EST_EfeS_State = "BOOTING" OR
                         // d51in_EST_EfeS_State = "FALLBACK_MODE"

  // Timeout Events

} FObserveDegradedPointPosition;

void transition_FObserveDegradedPointPosition(
    FObserveDegradedPointPosition *self);
void new_FObserveDegradedPointPosition(FObserveDegradedPointPosition *x);
