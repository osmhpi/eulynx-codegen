
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FEstEfes_D51outEstEfesStateValue {
  FEstEfes_D51outEstEfesStateValue__NULL__,
  FEstEfes_D51outEstEfesStateValue__NoOperatingVoltage,
  FEstEfes_D51outEstEfesStateValue__Booting,
  FEstEfes_D51outEstEfesStateValue__Operational,
  FEstEfes_D51outEstEfesStateValue__FallbackMode,
  FEstEfes_D51outEstEfesStateValue__Initialising,
  FEstEfes_D51outEstEfesStateValue__UNKNOWN__
} FEstEfes_D51outEstEfesStateValue;
typedef enum FEstEfes_D52outEstEfesInitSubstateValue {
  FEstEfes_D52outEstEfesInitSubstateValue__NULL__,
  FEstEfes_D52outEstEfesInitSubstateValue__Unknown,
  FEstEfes_D52outEstEfesInitSubstateValue__WaitingForDataUpdate,
  FEstEfes_D52outEstEfesInitSubstateValue__WaitingForPdi,
  FEstEfes_D52outEstEfesInitSubstateValue__WaitingForPdiOrMaintenance,
  FEstEfes_D52outEstEfesInitSubstateValue__WaitingForNoMaintenanceTimeout,
  FEstEfes_D52outEstEfesInitSubstateValue__UNKNOWN__
} FEstEfes_D52outEstEfesInitSubstateValue;

typedef enum FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state {
  FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate,
  FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdi,
  FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance,
  FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout
} FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state;

typedef struct
    FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state_struct {
  FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state
      state;
  union {};
} FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state_struct;

typedef enum FEstEfes__root__OperatingVoltageSupplied__root__state {
  FEstEfes__root__OperatingVoltageSupplied__root__Booting,
  FEstEfes__root__OperatingVoltageSupplied__root__Operational,
  FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode,
  FEstEfes__root__OperatingVoltageSupplied__root__Initialising
} FEstEfes__root__OperatingVoltageSupplied__root__state;

typedef struct
    FEstEfes__root__OperatingVoltageSupplied__root__Initialising__state_struct {
  FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state_struct
      root;
} FEstEfes__root__OperatingVoltageSupplied__root__Initialising__state_struct;

typedef struct FEstEfes__root__OperatingVoltageSupplied__root__state_struct {
  FEstEfes__root__OperatingVoltageSupplied__root__state state;
  union {
    FEstEfes__root__OperatingVoltageSupplied__root__Initialising__state_struct
        Initialising;
  };
} FEstEfes__root__OperatingVoltageSupplied__root__state_struct;

typedef enum FEstEfes__root__state {
  FEstEfes__root__NoOperatingVoltage,
  FEstEfes__root__OperatingVoltageSupplied
} FEstEfes__root__state;

typedef struct FEstEfes__root__OperatingVoltageSupplied__state_struct {
  FEstEfes__root__OperatingVoltageSupplied__root__state_struct root;
} FEstEfes__root__OperatingVoltageSupplied__state_struct;

typedef struct FEstEfes__root__state_struct {
  FEstEfes__root__state state;
  union {
    FEstEfes__root__OperatingVoltageSupplied__state_struct
        OperatingVoltageSupplied;
  };
} FEstEfes__root__state_struct;

/// Contained in:
/// Simulation_Package
typedef struct FEstEfes {
  FEstEfes__root__state_struct state;

  /// T1in_Power_On_Detected
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T1inPowerOnDetected;

  /// T2in_Power_Off_Detected
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T2inPowerOffDetected;

  /// T3in_Reset
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T3inReset;

  /// T4in_Booted
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T4inBooted;

  /// T5in_SIL_Not_Fulfilled
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T5inSilNotFulfilled;

  /// T7in_Invalid_Or_Missing_Basic_Data
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T7inInvalidOrMissingBasicData;

  /// d51out_EST_EfeS_State
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(FEstEfes_D51outEstEfesStateValue, ) D51outEstEfesState;

  /// D20in_Con_MDM_Used
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D20inConMdmUsed;

  /// d52out_EST_EfeS_init_SubState
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(FEstEfes_D52outEstEfesInitSubstateValue, ) D52outEstEfesInitSubstate;

  /// D21in_Con_tmax_No_Maintenance
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(int, ) D21inConTmaxNoMaintenance;

  // Messages -- Incoming
  MessagePort(Message__DataUpdateFinished__0937) InDataUpdateFinished__0937;
  MessagePort(Message__PdiConnectionClosed__d803) InPdiConnectionClosed__d803;
  MessagePort(Message__PdiConnectionEstablished__4cbf)
      InPdiConnectionEstablished__4cbf;
  MessagePort(Message__PdiReleasedForMaintenance__3f7c)
      InPdiReleasedForMaintenance__3f7c;
  MessagePort(Message__MdmCommandedMaintenance__a992)
      InMdmCommandedMaintenance__a992;
  MessagePort(Message__PdiConnectionStarted__f9c3) InPdiConnectionStarted__f9c3;
  MessagePort(Message__MdmTriggeredReset__00d0) InMdmTriggeredReset__00d0;
  MessagePort(Message__RebootRequired__bc8e) InRebootRequired__bc8e;
  // Messages -- Outgoing
  MessagePort(Message__EstReadyForMaintenance__dd9a)
      OutEstReadyForMaintenance__dd9a;
  MessagePort(Message__NotreadyForPdiConnection__0b73)
      OutNotreadyForPdiConnection__0b73;
  MessagePort(Message__ReadyForPdiConnection__6bd3)
      OutReadyForPdiConnection__6bd3;
  MessagePort(Message__DataUpdateStop__cf0d) OutDataUpdateStop__cf0d;

  // Change Events
  ChangeEvent Change1191; // T4in_Booted
  ChangeEvent Change1226; // T5in_SIL_Not_Fulfilled
  ChangeEvent Change1266; // T7in_Invalid_Or_Missing_Basic_Data
  ChangeEvent Change1143; // T3in_Reset
  ChangeEvent Change1224; // T5in_SIL_Not_Fulfilled
  ChangeEvent Change1144; // T3in_Reset
  ChangeEvent Change1145; // T3in_Reset
  ChangeEvent Change1225; // T5in_SIL_Not_Fulfilled
  ChangeEvent Change869;  // T1in_Power_On_Detected
  ChangeEvent Change1060; // T2in_Power_Off_Detected

  // Timeout Events
  TimeoutEvent Time13;

} FEstEfes;

void transition_FEstEfes(FEstEfes *self);
void new_FEstEfes(FEstEfes *x);
