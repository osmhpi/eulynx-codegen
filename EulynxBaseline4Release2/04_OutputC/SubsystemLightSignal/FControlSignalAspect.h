
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FControlSignalAspect_D2inRequiredSignalAspectValue {
  FControlSignalAspect_D2inRequiredSignalAspectValue__NULL__,
  FControlSignalAspect_D2inRequiredSignalAspectValue__MostRestrictAspect,
  FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1,
  FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2,
  FControlSignalAspect_D2inRequiredSignalAspectValue__UNKNOWN__
} FControlSignalAspect_D2inRequiredSignalAspectValue;
typedef enum FControlSignalAspect_D7outSetSignalAspectValue {
  FControlSignalAspect_D7outSetSignalAspectValue__NULL__,
  FControlSignalAspect_D7outSetSignalAspectValue__NationalAspect,
  FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect2,
  FControlSignalAspect_D7outSetSignalAspectValue__MostRestrictAspect,
  FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspectLampFailure,
  FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect1,
  FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspect,
  FControlSignalAspect_D7outSetSignalAspectValue__UNKNOWN__
} FControlSignalAspect_D7outSetSignalAspectValue;
typedef enum FControlSignalAspect_D9inSetLuminosityValue {
  FControlSignalAspect_D9inSetLuminosityValue__NULL__,
  FControlSignalAspect_D9inSetLuminosityValue__Undefined,
  FControlSignalAspect_D9inSetLuminosityValue__UNKNOWN__
} FControlSignalAspect_D9inSetLuminosityValue;
typedef enum FControlSignalAspect_D51inEstEfesStateValue {
  FControlSignalAspect_D51inEstEfesStateValue__NULL__,
  FControlSignalAspect_D51inEstEfesStateValue__Booting,
  FControlSignalAspect_D51inEstEfesStateValue__Initialising,
  FControlSignalAspect_D51inEstEfesStateValue__NoOperatingVoltage,
  FControlSignalAspect_D51inEstEfesStateValue__FallbackMode,
  FControlSignalAspect_D51inEstEfesStateValue__UNKNOWN__
} FControlSignalAspect_D51inEstEfesStateValue;
typedef enum FControlSignalAspect_MemSetAspectValue {
  FControlSignalAspect_MemSetAspectValue__NULL__,
  FControlSignalAspect_MemSetAspectValue__,
  FControlSignalAspect_MemSetAspectValue__SignalAspect2,
  FControlSignalAspect_MemSetAspectValue__MostRestrictAspect,
  FControlSignalAspect_MemSetAspectValue__NoSignalAspectLampFailure,
  FControlSignalAspect_MemSetAspectValue__SignalAspect1,
  FControlSignalAspect_MemSetAspectValue__UNKNOWN__
} FControlSignalAspect_MemSetAspectValue;

typedef enum FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state {
  FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2,
  FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect,
  FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure,
  FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1
} FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state;

typedef struct
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct {
  FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state
      state;
  union {};
} FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct;

typedef enum FControlSignalAspect__root__OperatingVoltage__root__state {
  FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect,
  FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspect
} FControlSignalAspect__root__OperatingVoltage__root__state;

typedef struct
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__state_struct {
  FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct
      root;
} FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__state_struct;

typedef struct
    FControlSignalAspect__root__OperatingVoltage__root__state_struct {
  FControlSignalAspect__root__OperatingVoltage__root__state state;
  union {
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__state_struct
        ControllingSignalAspect;
  };
} FControlSignalAspect__root__OperatingVoltage__root__state_struct;

typedef enum FControlSignalAspect__root__state {
  FControlSignalAspect__root__NationalAspect,
  FControlSignalAspect__root__OperatingVoltage
} FControlSignalAspect__root__state;

typedef struct FControlSignalAspect__root__OperatingVoltage__state_struct {
  FControlSignalAspect__root__OperatingVoltage__root__state_struct root;
} FControlSignalAspect__root__OperatingVoltage__state_struct;

typedef struct FControlSignalAspect__root__state_struct {
  FControlSignalAspect__root__state state;
  union {
    FControlSignalAspect__root__OperatingVoltage__state_struct OperatingVoltage;
  };
} FControlSignalAspect__root__state_struct;

/// Contained in:
/// Subsystem Light Signal
/// Functional requirements specification
/// Subsystem Light Signal - Functional Viewpoint
/// Subsystem Light Signal - Functional Entities
typedef struct FControlSignalAspect {
  FControlSignalAspect__root__state_struct state;

  /// d3in_Required_Intentionally_Dark
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(bool, ) D3inRequiredIntentionallyDark;

  /// d2in_Required_Signal_Aspect
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FControlSignalAspect_D2inRequiredSignalAspectValue, )
      D2inRequiredSignalAspect;

  /// D4in_Fault_Lamps_Aspect_1
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D4inFaultLampsAspect1;

  /// D5in_Fault_Lamps_Aspect_2
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D5inFaultLampsAspect2;

  /// D6in_Fault_Lamps_Most_Restrict
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D6inFaultLampsMostRestrict;

  /// D7out_Set_Signal_Aspect
  /// Trigger: False, DataPort: True, In: False, Out: True, External: True
  DataPort(FControlSignalAspect_D7outSetSignalAspectValue, )
      D7outSetSignalAspect;

  /// D8out_Set_Intentionally_Dark
  /// Trigger: False, DataPort: True, In: False, Out: True, External: True
  DataPort(bool, ) D8outSetIntentionallyDark;

  /// d9in_Set_Luminosity
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FControlSignalAspect_D9inSetLuminosityValue, ) D9inSetLuminosity;

  /// d51in_EST_EfeS_State
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FControlSignalAspect_D51inEstEfesStateValue, ) D51inEstEfesState;

  /// D10in_Con_Downgrade_Most_Restrict
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D10inConDowngradeMostRestrict;

  /// Mem_Set_Aspect
  /// Trigger: False, DataPort: False, In: False, Out: False, External: False
  FControlSignalAspect_MemSetAspectValue MemSetAspect;

  // Messages -- Incoming

  // Messages -- Outgoing

  // Change Events
  ChangeEvent Change210; // d2in_Required_Signal_Aspect = "Most Restrict Aspect"
                         // OR D5in_Fault_Lamps_Aspect_2
  ChangeEvent Change211; // d2in_Required_Signal_Aspect = "Most Restrict Aspect"
                         // OR D5in_Fault_Lamps_Aspect_2
  ChangeEvent Change214; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
  ChangeEvent Change217; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
  ChangeEvent Change219; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
  ChangeEvent Change283; // d3in_Required_Intentionally_Dark
  ChangeEvent Change573; // NOT d3in_Required_Intentionally_Dark
  ChangeEvent Change215; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
  ChangeEvent Change225; // d2in_Required_Signal_Aspect = "Signal Aspect 2"
  ChangeEvent Change216; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
  ChangeEvent Change450; // D6in_Fault_Lamps_Most_Restrict
  ChangeEvent Change282; // d3in_Required_Intentionally_Dark
  ChangeEvent Change575; // NOT d3in_Required_Intentionally_Dark
  ChangeEvent Change220; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
  ChangeEvent Change224; // d2in_Required_Signal_Aspect = "Signal Aspect 2"
  ChangeEvent Change218; // d2in_Required_Signal_Aspect = "Signal Aspect 1"
  ChangeEvent Change588; // NOT D6in_Fault_Lamps_Most_Restrict
  ChangeEvent Change212; // d2in_Required_Signal_Aspect = "Most Restrict Aspect"
  ChangeEvent Change213; // d2in_Required_Signal_Aspect = "Most Restrict Aspect"
  ChangeEvent Change223; // d2in_Required_Signal_Aspect = "Signal Aspect 2"
  ChangeEvent Change221; // d2in_Required_Signal_Aspect = "Signal Aspect 2"
  ChangeEvent Change222; // d2in_Required_Signal_Aspect = "Signal Aspect 2"
  ChangeEvent Change308; // D4in_Fault_Lamps_Aspect_1
  ChangeEvent Change310; // D4in_Fault_Lamps_Aspect_1
  ChangeEvent Change309; // D4in_Fault_Lamps_Aspect_1
  ChangeEvent Change284; // d3in_Required_Intentionally_Dark
  ChangeEvent Change574; // NOT d3in_Required_Intentionally_Dark
  ChangeEvent Change521; // d9in_Set_Luminosity = "Undefined"
  ChangeEvent Change350; // d51in_EST_EfeS_State = "BOOTING"
  ChangeEvent Change359; // d51in_EST_EfeS_State = "BOOTING"
                         // ORd51in_EST_EfeS_State = "INITIALISING"
  ChangeEvent Change388; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR
                         // d51in_EST_EfeS_State = "FALLBACK_MODE"

  // Timeout Events

} FControlSignalAspect;

void transition_FControlSignalAspect(FControlSignalAspect *self);
void new_FControlSignalAspect(FControlSignalAspect *x);
