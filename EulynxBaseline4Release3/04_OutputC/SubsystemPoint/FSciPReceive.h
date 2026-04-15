
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciPReceive_D10outRequiredPointPositionValue
{
    FSciPReceive_D10outRequiredPointPositionValue__NULL__,
    FSciPReceive_D10outRequiredPointPositionValue__Uncommanded,
    FSciPReceive_D10outRequiredPointPositionValue__Left,
    FSciPReceive_D10outRequiredPointPositionValue__Right,
    FSciPReceive_D10outRequiredPointPositionValue__UNKNOWN__
} FSciPReceive_D10outRequiredPointPositionValue;
typedef enum FSciPReceive_D50inPdiConnectionStateValue
{
    FSciPReceive_D50inPdiConnectionStateValue__NULL__,
    FSciPReceive_D50inPdiConnectionStateValue__NotReadyForPdiNoScp,
    FSciPReceive_D50inPdiConnectionStateValue__NotReadyForPdi,
    FSciPReceive_D50inPdiConnectionStateValue__Suspended,
    FSciPReceive_D50inPdiConnectionStateValue__Established,
    FSciPReceive_D50inPdiConnectionStateValue__UNKNOWN__
} FSciPReceive_D50inPdiConnectionStateValue;
typedef enum FSciPReceive_D12inRequiredPmPositionValue
{
    FSciPReceive_D12inRequiredPmPositionValue__NULL__,
    FSciPReceive_D12inRequiredPmPositionValue__Uncommanded,
    FSciPReceive_D12inRequiredPmPositionValue__UNKNOWN__
} FSciPReceive_D12inRequiredPmPositionValue;
typedef enum FSciPReceive_D11inObservedAbilityToMoveValue
{
    FSciPReceive_D11inObservedAbilityToMoveValue__NULL__,
    FSciPReceive_D11inObservedAbilityToMoveValue__AbleToMove,
    FSciPReceive_D11inObservedAbilityToMoveValue__UNKNOWN__
} FSciPReceive_D11inObservedAbilityToMoveValue;

typedef enum FSciPReceive__root__state
{
    FSciPReceive__root__ReceivingCommands
} FSciPReceive__root__state;

typedef struct FSciPReceive__root__state_struct
{
    FSciPReceive__root__state state;
    union {
    };
} FSciPReceive__root__state_struct;

/// Contained in:
/// Subsystem - Point
/// Functional requirements specification
/// Subsystem - Point - Interfaces
/// SCI-P (Subsystem -  Electronic Interlocking)
/// SCI-P - Functional Viewpoint
/// SCI-P - Functional Entities
typedef struct FSciPReceive
{
    FSciPReceive__root__state_struct state;

    /// d10out_Required_Point_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FSciPReceive_D10outRequiredPointPositionValue, ) D10outRequiredPointPosition;

    /// d50in_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPReceive_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;

    /// d12in_Required_PM_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPReceive_D12inRequiredPmPositionValue, ) D12inRequiredPmPosition;

    /// d11in_Observed_Ability_To_Move
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciPReceive_D11inObservedAbilityToMoveValue, ) D11inObservedAbilityToMove;

    // Messages -- Incoming
    MessagePort(Message__CdMovePoint__342e) InCdMovePoint__342e;
    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change39;  // d11in_Observed_Ability_To_Move = "ABLE_TO_MOVE"
    ChangeEvent Change83;  // d12in_Required_PM_Position = "UNCOMMANDED"
    ChangeEvent Change306; // d50in_PDI_Connection_State = "NOT_READY_FOR_PDI_NO_SCP" OR d50in_PDI_Connection_State =
                           // "NOT_READY_FOR_PDI" OR d50in_PDI_Connection_State = "SUSPENDED"

    // Timeout Events

} FSciPReceive;

void transition_FSciPReceive(FSciPReceive *self);
void transition_FSciPReceive(FSciPReceive *self);
void new_FSciPReceive(FSciPReceive *x);
