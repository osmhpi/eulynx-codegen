
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FHandleInternalFcUCommand__root__state
{
    FHandleInternalFcUCommand__root__ReceivingCommandsFromInternal
} FHandleInternalFcUCommand__root__state;

typedef struct FHandleInternalFcUCommand__root__state_struct
{
    FHandleInternalFcUCommand__root__state state;
    union {
    };
} FHandleInternalFcUCommand__root__state_struct;

/// Contained in:
/// Subsystem - Train Detection System
/// Functional requirements specification
/// Subsystem - Train Detection System - Functional Viewpoint
/// Subsystem - Train Detection System - Functional Entities
typedef struct FHandleInternalFcUCommand
{
    FHandleInternalFcUCommand__root__state_struct state;

    /// T33in_FC_U
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T33inFcU;

    // Messages -- Incoming

    // Messages -- Outgoing
    MessagePort(Message__RequestFcU__bd99) OutRequestFcU__bd99;

    // Change Events
    ChangeEvent Change1087; // T33in_FC_U

    // Timeout Events

} FHandleInternalFcUCommand;

void transition_FHandleInternalFcUCommand(FHandleInternalFcUCommand *self);
void new_FHandleInternalFcUCommand(FHandleInternalFcUCommand *x);
