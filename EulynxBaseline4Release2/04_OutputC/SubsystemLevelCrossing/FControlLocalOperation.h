
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FControlLocalOperation_D8inHandoverToLocalOperatorStateValue
{
    FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__NULL__,
    FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__Established,
    FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__Initiated,
    FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__NoHandover,
    FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__UNKNOWN__
} FControlLocalOperation_D8inHandoverToLocalOperatorStateValue;
typedef enum FControlLocalOperation_D80outHandoverToLocalOperationStateValue
{
    FControlLocalOperation_D80outHandoverToLocalOperationStateValue__NULL__,
    FControlLocalOperation_D80outHandoverToLocalOperationStateValue__HandoverToLocalOperatorInitiated,
    FControlLocalOperation_D80outHandoverToLocalOperationStateValue__HandoverToLocalOperatorEstablished,
    FControlLocalOperation_D80outHandoverToLocalOperationStateValue__NoHandoverToLocalOperator,
    FControlLocalOperation_D80outHandoverToLocalOperationStateValue__UNKNOWN__
} FControlLocalOperation_D80outHandoverToLocalOperationStateValue;
typedef enum FControlLocalOperation_D81outLocalOperationHandoverValue
{
    FControlLocalOperation_D81outLocalOperationHandoverValue__NULL__,
    FControlLocalOperation_D81outLocalOperationHandoverValue__AllowHandoverToLocalOperator,
    FControlLocalOperation_D81outLocalOperationHandoverValue__ReturnHandoverFromLocalOperator,
    FControlLocalOperation_D81outLocalOperationHandoverValue__UNKNOWN__
} FControlLocalOperation_D81outLocalOperationHandoverValue;
typedef enum FControlLocalOperation_D81inLocalOperationHandoverValue
{
    FControlLocalOperation_D81inLocalOperationHandoverValue__NULL__,
    FControlLocalOperation_D81inLocalOperationHandoverValue__ReturnHandoverFromLocalOperator,
    FControlLocalOperation_D81inLocalOperationHandoverValue__AllowHandoverToLocalOperator,
    FControlLocalOperation_D81inLocalOperationHandoverValue__UNKNOWN__
} FControlLocalOperation_D81inLocalOperationHandoverValue;
typedef enum FControlLocalOperation_D82inRequestByLocalOperatorValue
{
    FControlLocalOperation_D82inRequestByLocalOperatorValue__NULL__,
    FControlLocalOperation_D82inRequestByLocalOperatorValue__RequestToActivateTheLevelCrossing,
    FControlLocalOperation_D82inRequestByLocalOperatorValue__RequestToDeactivateTheLevelCrossing,
    FControlLocalOperation_D82inRequestByLocalOperatorValue__UNKNOWN__
} FControlLocalOperation_D82inRequestByLocalOperatorValue;
typedef enum FControlLocalOperation_D82outLocalOperationHandoverValue
{
    FControlLocalOperation_D82outLocalOperationHandoverValue__NULL__,
    FControlLocalOperation_D82outLocalOperationHandoverValue__RequestToActivateTheLevelCrossing,
    FControlLocalOperation_D82outLocalOperationHandoverValue__RequestToDeactivateTheLevelCrossing,
    FControlLocalOperation_D82outLocalOperationHandoverValue__UNKNOWN__
} FControlLocalOperation_D82outLocalOperationHandoverValue;

typedef enum FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state
{
    FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__Waiting,
    FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated,
    FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished,
    FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover
} FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state;

typedef struct FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state_struct
{
    FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state state;
    union {
    };
} FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state_struct;

typedef enum FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__state
{
    FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Allow,
    FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Return,
    FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Waiting
} FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__state;

typedef struct
    FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__state_struct
{
    FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__state state;
    union {
    };
} FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__state_struct;

typedef enum FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__state
{
    FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__Waiting,
    FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToActivate,
    FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToDeactivate
} FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__state;

typedef struct FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__state_struct
{
    FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__state state;
    union {
    };
} FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__state_struct;

typedef enum FControlLocalOperation__root__state
{
    FControlLocalOperation__root__ControlLocalOperation
} FControlLocalOperation__root__state;

typedef struct FControlLocalOperation__root__ControlLocalOperation__state_struct
{
    FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state_struct
        CommandHandoverToLocalOperation;
    FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__state_struct
        ReceiveInputForLocalOperationByLocalOperator;
    FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__state_struct RequestByLocalOperator;
} FControlLocalOperation__root__ControlLocalOperation__state_struct;

typedef struct FControlLocalOperation__root__state_struct
{
    FControlLocalOperation__root__state state;
    union {
        FControlLocalOperation__root__ControlLocalOperation__state_struct ControlLocalOperation;
    };
} FControlLocalOperation__root__state_struct;

/// Contained in:
/// Subsystem Level Crossing
/// Functional requirements specification
/// Subsystem Level Crossing - Functional Viewpoint
/// Subsystem Level Crossing - Functional Entities
typedef struct FControlLocalOperation
{
    FControlLocalOperation__root__state_struct state;

    /// d8in_Handover_To_Local_Operator_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlLocalOperation_D8inHandoverToLocalOperatorStateValue, ) D8inHandoverToLocalOperatorState;

    /// D80out_Handover_To_local_Operation_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(FControlLocalOperation_D80outHandoverToLocalOperationStateValue, ) D80outHandoverToLocalOperationState;

    /// d81out_Local_Operation_Handover
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FControlLocalOperation_D81outLocalOperationHandoverValue, ) D81outLocalOperationHandover;

    /// D81in_Local_Operation_Handover
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FControlLocalOperation_D81inLocalOperationHandoverValue, ) D81inLocalOperationHandover;

    /// D82in_Request_by_Local_Operator
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FControlLocalOperation_D82inRequestByLocalOperatorValue, ) D82inRequestByLocalOperator;

    /// d82out_Local_Operation_Handover
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FControlLocalOperation_D82outLocalOperationHandoverValue, ) D82outLocalOperationHandover;

    /// D83in_Con_Use_Local_Operation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D83inConUseLocalOperation;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change484; // d8in_Handover_To_Local_Operator_State = "Established" And D83in_Con_Use_Local_Operation
    ChangeEvent Change486; // d8in_Handover_To_Local_Operator_State = "Initiated" And D83in_Con_Use_Local_Operation
    ChangeEvent Change490; // d8in_Handover_To_Local_Operator_State = "No Handover" And D83in_Con_Use_Local_Operation
    ChangeEvent Change483; // d8in_Handover_To_Local_Operator_State = "Established" And D83in_Con_Use_Local_Operation
    ChangeEvent Change489; // d8in_Handover_To_Local_Operator_State = "No Handover" And D83in_Con_Use_Local_Operation
    ChangeEvent Change491; // d8in_Handover_To_Local_Operator_State = "No Handover" And D83in_Con_Use_Local_Operation
    ChangeEvent Change487; // d8in_Handover_To_Local_Operator_State = "Initiated" And D83in_Con_Use_Local_Operation
    ChangeEvent Change488; // d8in_Handover_To_Local_Operator_State = "Initiated" And D83in_Con_Use_Local_Operation
    ChangeEvent Change485; // d8in_Handover_To_Local_Operator_State = "Established" And D83in_Con_Use_Local_Operation
    ChangeEvent Change474; // D81in_Local_Operation_Handover = "Return handover from local operator" And
                           // D83in_Con_Use_Local_Operation
    ChangeEvent Change473; // D81in_Local_Operation_Handover = "Allow handover to local operator" And
                           // D83in_Con_Use_Local_Operation
    ChangeEvent Change472; // D81in_Local_Operation_Handover = "Allow handover to local operator" And
                           // D83in_Con_Use_Local_Operation
    ChangeEvent Change476; // D81in_Local_Operation_Handover = "Return handover from local operator" And
                           // D83in_Con_Use_Local_Operation
    ChangeEvent Change479; // D82in_Request_by_Local_Operator = "Request to activate the level Crossing" And
                           // D83in_Con_Use_Local_Operation
    ChangeEvent Change482; // D82in_Request_by_Local_Operator = "Request to deactivate the level Crossing" And
                           // D83in_Con_Use_Local_Operation
    ChangeEvent Change481; // D82in_Request_by_Local_Operator = "Request to deactivate the level Crossing" And
                           // D83in_Con_Use_Local_Operation
    ChangeEvent Change480; // D82in_Request_by_Local_Operator = "Request to activate the level Crossing" And
                           // D83in_Con_Use_Local_Operation

    // Timeout Events

} FControlLocalOperation;

void transition_FControlLocalOperation(FControlLocalOperation *self);
void new_FControlLocalOperation(FControlLocalOperation *x);
