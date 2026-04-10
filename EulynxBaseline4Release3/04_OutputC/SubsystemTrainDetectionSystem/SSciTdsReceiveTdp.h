
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciTdsReceiveTdp_D64outTdpStatusValue {
  SSciTdsReceiveTdp_D64outTdpStatusValue__NULL__,
  SSciTdsReceiveTdp_D64outTdpStatusValue__Passed,
  SSciTdsReceiveTdp_D64outTdpStatusValue__Disturbed,
  SSciTdsReceiveTdp_D64outTdpStatusValue__NotPassed,
  SSciTdsReceiveTdp_D64outTdpStatusValue__UNKNOWN__
} SSciTdsReceiveTdp_D64outTdpStatusValue;
typedef enum SSciTdsReceiveTdp_D64outTdpDirectionValue {
  SSciTdsReceiveTdp_D64outTdpDirectionValue__NULL__,
  SSciTdsReceiveTdp_D64outTdpDirectionValue__ReferenceDirection,
  SSciTdsReceiveTdp_D64outTdpDirectionValue__AgainstReferenceDirection,
  SSciTdsReceiveTdp_D64outTdpDirectionValue__WithoutIndicatedDirection,
  SSciTdsReceiveTdp_D64outTdpDirectionValue__UNKNOWN__
} SSciTdsReceiveTdp_D64outTdpDirectionValue;

typedef enum SSciTdsReceiveTdp__root__state {
  SSciTdsReceiveTdp__root__ReceivingTdpReports
} SSciTdsReceiveTdp__root__state;

typedef struct SSciTdsReceiveTdp__root__state_struct {
  SSciTdsReceiveTdp__root__state state;
  union {};
} SSciTdsReceiveTdp__root__state_struct;

/// Contained in:
/// Subsystem - Train Detection System
/// Functional requirements specification
/// Subsystem - Train Detection System - Interfaces
/// SCI-TDS (Subsystem – Electronic Interlocking)
/// SCI-TDS - Functional Viewpoint
/// SCI-TDS - Functional Entities
typedef struct SSciTdsReceiveTdp {
  SSciTdsReceiveTdp__root__state_struct state;

  /// d64out_TDP_Status
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciTdsReceiveTdp_D64outTdpStatusValue, ) D64outTdpStatus;

  /// d64out_TDP_Direction
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciTdsReceiveTdp_D64outTdpDirectionValue, ) D64outTdpDirection;

  /// t64out_TDP_Status
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T64outTdpStatus;

  // Messages -- Incoming
  MessagePort(Message__MsgTdpStatus__b6d9) InMsgTdpStatus__b6d9;
  // Messages -- Outgoing

  // Change Events

  // Timeout Events

} SSciTdsReceiveTdp;

void transition_SSciTdsReceiveTdp(SSciTdsReceiveTdp *self);
void new_SSciTdsReceiveTdp(SSciTdsReceiveTdp *x);
