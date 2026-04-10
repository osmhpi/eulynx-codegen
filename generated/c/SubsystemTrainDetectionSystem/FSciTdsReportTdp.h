
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciTdsReportTdp_D50inPdiConnectionStateValue {
  FSciTdsReportTdp_D50inPdiConnectionStateValue__NULL__,
  FSciTdsReportTdp_D50inPdiConnectionStateValue__ReadyForPdiNoScp,
  FSciTdsReportTdp_D50inPdiConnectionStateValue__ReadyForPdi,
  FSciTdsReportTdp_D50inPdiConnectionStateValue__Suspended,
  FSciTdsReportTdp_D50inPdiConnectionStateValue__UNKNOWN__
} FSciTdsReportTdp_D50inPdiConnectionStateValue;
typedef enum FSciTdsReportTdp_D53inReportedTdpStatusValue {
  FSciTdsReportTdp_D53inReportedTdpStatusValue__NULL__,
  FSciTdsReportTdp_D53inReportedTdpStatusValue__Passed,
  FSciTdsReportTdp_D53inReportedTdpStatusValue__TdpDisturbed,
  FSciTdsReportTdp_D53inReportedTdpStatusValue__NotPassed,
  FSciTdsReportTdp_D53inReportedTdpStatusValue__UNKNOWN__
} FSciTdsReportTdp_D53inReportedTdpStatusValue;
typedef enum FSciTdsReportTdp_D54intReportedTdpDirectionValue {
  FSciTdsReportTdp_D54intReportedTdpDirectionValue__NULL__,
  FSciTdsReportTdp_D54intReportedTdpDirectionValue__AgainstReferenceDirection,
  FSciTdsReportTdp_D54intReportedTdpDirectionValue__ReferenceDirection,
  FSciTdsReportTdp_D54intReportedTdpDirectionValue__UNKNOWN__
} FSciTdsReportTdp_D54intReportedTdpDirectionValue;

typedef enum FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__state {
  FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__InRefenceDirection,
  FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__AgainstRefenceDirection,
  FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__WithoutDirection
} FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__state;

typedef struct
    FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__state_struct {
  FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__state state;
  union {};
} FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__state_struct;

typedef enum FSciTdsReportTdp__root__ReportingTdpStatus__root__state {
  FSciTdsReportTdp__root__ReportingTdpStatus__root__Waiting,
  FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed,
  FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed,
  FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed
} FSciTdsReportTdp__root__ReportingTdpStatus__root__state;

typedef struct
    FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__state_struct {
  FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__state_struct
      root;
} FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__state_struct;

typedef struct FSciTdsReportTdp__root__ReportingTdpStatus__root__state_struct {
  FSciTdsReportTdp__root__ReportingTdpStatus__root__state state;
  union {
    FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__state_struct
        Passed;
  };
} FSciTdsReportTdp__root__ReportingTdpStatus__root__state_struct;

typedef enum FSciTdsReportTdp__root__state {
  FSciTdsReportTdp__root__ReportingTdpStatus
} FSciTdsReportTdp__root__state;

typedef struct FSciTdsReportTdp__root__ReportingTdpStatus__state_struct {
  FSciTdsReportTdp__root__ReportingTdpStatus__root__state_struct root;
} FSciTdsReportTdp__root__ReportingTdpStatus__state_struct;

typedef struct FSciTdsReportTdp__root__state_struct {
  FSciTdsReportTdp__root__state state;
  union {
    FSciTdsReportTdp__root__ReportingTdpStatus__state_struct ReportingTdpStatus;
  };
} FSciTdsReportTdp__root__state_struct;

/// Contained in:
/// Subsystem - Train Detection System
/// Functional requirements specification
/// Subsystem - Train Detection System - Interfaces
/// SCI-TDS (Subsystem – Electronic Interlocking)
/// SCI-TDS - Functional Viewpoint
/// SCI-TDS - Functional Entities
typedef struct FSciTdsReportTdp {
  FSciTdsReportTdp__root__state_struct state;

  /// d50in_PDI_Connection_State
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciTdsReportTdp_D50inPdiConnectionStateValue, )
      D50inPdiConnectionState;

  /// d53in_Reported_TDP_Status
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciTdsReportTdp_D53inReportedTdpStatusValue, )
      D53inReportedTdpStatus;

  /// d54int_Reported_TDP_Direction
  /// Trigger: False, DataPort: True, In: False, Out: False, External: False
  DataPort(FSciTdsReportTdp_D54intReportedTdpDirectionValue, )
      D54intReportedTdpDirection;

  // Messages -- Incoming
  MessagePort(Message__StartStatusReport__1e4e) InStartStatusReport__1e4e;
  // Messages -- Outgoing
  MessagePort(Message__MsgTdpStatus__b6d9) OutMsgTdpStatus__b6d9;

  // Change Events
  ChangeEvent Change412; // d54int_Reported_TDP_Direction = "against reference
                         // direction"
  ChangeEvent
      Change413; // d54int_Reported_TDP_Direction = "reference direction"
  ChangeEvent Change408; // d53in_Reported_TDP_Status = "passed"
  ChangeEvent Change410; // d53in_Reported_TDP_Status = "TDP disturbed"
  ChangeEvent Change406; // d53in_Reported_TDP_Status = "not passed"
  ChangeEvent Change409; // d53in_Reported_TDP_Status = "TDP disturbed"
  ChangeEvent Change405; // d53in_Reported_TDP_Status = "not passed"
  ChangeEvent Change407; // d53in_Reported_TDP_Status = "passed"
  ChangeEvent
      Change314; // d50in_PDI_Connection_State = "READY_FOR_PDI_NO_SCP"OR
                 // d50in_PDI_Connection_State = "READY_FOR_PDI"OR
                 // d50in_PDI_Connection_State = "SUSPENDED"

  // Timeout Events

} FSciTdsReportTdp;

void transition_FSciTdsReportTdp(FSciTdsReportTdp *self);
void new_FSciTdsReportTdp(FSciTdsReportTdp *x);
