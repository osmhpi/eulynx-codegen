
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue {
  FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue__NULL__,
  FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue__NotReadyForPdiNoScp,
  FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue__ReadyForPdiNoScp,
  FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue__NotReadyForPdi,
  FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue__ReadyForPdi,
  FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue__Suspended,
  FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue__UNKNOWN__
} FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue;
typedef enum FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue {
  FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__NULL__,
  FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateOccupied,
  FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateDisturbed,
  FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateVacant,
  FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__UNKNOWN__
} FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue;
typedef enum FSciTdsReportTrackCircuit_D47inReportPomStatusValue {
  FSciTdsReportTrackCircuit_D47inReportPomStatusValue__NULL__,
  FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyOk,
  FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyNok,
  FSciTdsReportTrackCircuit_D47inReportPomStatusValue__UNKNOWN__
} FSciTdsReportTrackCircuit_D47inReportPomStatusValue;

typedef enum FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__state {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomOk,
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomNok
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__state;

typedef struct
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__state_struct {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__state
      state;
  union {};
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__state_struct;

typedef enum FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__state {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomNok,
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomOk
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__state;

typedef struct
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__state_struct {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__state
      state;
  union {};
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__state_struct;

typedef enum FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__state {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomOk,
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomNok
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__state;

typedef struct
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__state_struct {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__state
      state;
  union {};
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__state_struct;

typedef enum FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Waiting,
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant,
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied,
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state;

typedef struct
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__state_struct {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__state_struct
      root;
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__state_struct;

typedef struct
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__state_struct {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__state_struct
      root;
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__state_struct;

typedef struct
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__state_struct {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__state_struct
      root;
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__state_struct;

typedef struct
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state_struct {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state state;
  union {
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__state_struct
        Vacant;
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__state_struct
        Occupied;
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__state_struct
        Disturbed;
  };
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state_struct;

typedef enum FSciTdsReportTrackCircuit__root__state {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus
} FSciTdsReportTrackCircuit__root__state;

typedef struct
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__state_struct {
  FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state_struct
      root;
} FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__state_struct;

typedef struct FSciTdsReportTrackCircuit__root__state_struct {
  FSciTdsReportTrackCircuit__root__state state;
  union {
    FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__state_struct
        ReportingOccupancyStatus;
  };
} FSciTdsReportTrackCircuit__root__state_struct;

/// Contained in:
/// Subsystem Train Detection System
/// Functional requirements specification
/// Subsystem Train Detection System - Interfaces
/// SCI-TDS (Subsystem – Electronic Interlocking)
/// SCI-TDS - Functional Viewpoint
/// SCI-TDS - Functional Entities
typedef struct FSciTdsReportTrackCircuit {
  FSciTdsReportTrackCircuit__root__state_struct state;

  /// d50in_PDI_Connection_State
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue, )
      D50inPdiConnectionState;

  /// d46in_Reported_Ability_To_Be_Forced_To_Clear
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(bool, ) D46inReportedAbilityToBeForcedToClear;

  /// d45in_Reported_TVPS_Occupancy_Status
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue, )
      D45inReportedTvpsOccupancyStatus;

  /// d47in_Report_POM_Status
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciTdsReportTrackCircuit_D47inReportPomStatusValue, )
      D47inReportPomStatus;

  // Messages -- Incoming
  MessagePort(Message__StartStatusReport__1e4e) InStartStatusReport__1e4e;
  // Messages -- Outgoing
  MessagePort(Message__MsgTvpsOccupancyStatus__b4e1)
      OutMsgTvpsOccupancyStatus__b4e1;

  // Change Events
  ChangeEvent Change294; // d47in_Report_POM_Status = "Power supply NOK"
  ChangeEvent Change298; // d47in_Report_POM_Status = "Power supply OK"
  ChangeEvent Change296; // d47in_Report_POM_Status = "Power supply OK"
  ChangeEvent Change293; // d47in_Report_POM_Status = "Power supply NOK"
  ChangeEvent Change295; // d47in_Report_POM_Status = "Power supply NOK"
  ChangeEvent Change297; // d47in_Report_POM_Status = "Power supply OK"
  ChangeEvent Change288; // d45in_Reported_TVPS_Occupancy_Status = "TVPS is in
                         // state occupied"
  ChangeEvent Change289; // d45in_Reported_TVPS_Occupancy_Status = "TVPS is in
                         // state disturbed"
  ChangeEvent Change287; // d45in_Reported_TVPS_Occupancy_Status = "TVPS is in
                         // state disturbed"
  ChangeEvent Change292; // d45in_Reported_TVPS_Occupancy_Status = "TVPS is in
                         // state vacant"
  ChangeEvent Change291; // d45in_Reported_TVPS_Occupancy_Status = "TVPS is in
                         // state occupied"
  ChangeEvent Change290; // d45in_Reported_TVPS_Occupancy_Status = "TVPS is in
                         // state vacant"
  ChangeEvent
      Change335; // d50in_PDI_Connection_State = "NOT_READY_FOR_PDI_NO_SCP" OR
                 // d50in_PDI_Connection_State = "READY_FOR_PDI_NO_SCP" OR
                 // d50in_PDI_Connection_State = "NOT_READY_FOR_PDI" OR
                 // d50in_PDI_Connection_State = "READY_FOR_PDI" OR
                 // d50in_PDI_Connection_State = "SUSPENDED"

  // Timeout Events

} FSciTdsReportTrackCircuit;

void transition_FSciTdsReportTrackCircuit(FSciTdsReportTrackCircuit *self);
void new_FSciTdsReportTrackCircuit(FSciTdsReportTrackCircuit *x);
