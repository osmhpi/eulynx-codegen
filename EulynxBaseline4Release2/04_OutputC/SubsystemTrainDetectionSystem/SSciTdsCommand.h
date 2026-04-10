
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciTdsCommand_D70inModeOfFcValue
{
    SSciTdsCommand_D70inModeOfFcValue__NULL__,
    SSciTdsCommand_D70inModeOfFcValue__FcU,
    SSciTdsCommand_D70inModeOfFcValue__FcP,
    SSciTdsCommand_D70inModeOfFcValue__FcPA,
    SSciTdsCommand_D70inModeOfFcValue__AcknowledgementAfterFcPACommand,
    SSciTdsCommand_D70inModeOfFcValue__FcC,
    SSciTdsCommand_D70inModeOfFcValue__UNKNOWN__
} SSciTdsCommand_D70inModeOfFcValue;
typedef enum SSciTdsCommand_D50PdiConnectionStateValue
{
    SSciTdsCommand_D50PdiConnectionStateValue__NULL__,
    SSciTdsCommand_D50PdiConnectionStateValue__Established,
    SSciTdsCommand_D50PdiConnectionStateValue__UNKNOWN__
} SSciTdsCommand_D50PdiConnectionStateValue;

typedef enum SSciTdsCommand__root__state
{
    SSciTdsCommand__root__SendingCommands
} SSciTdsCommand__root__state;

typedef struct SSciTdsCommand__root__state_struct
{
    SSciTdsCommand__root__state state;
    union {
    };
} SSciTdsCommand__root__state_struct;

/// Contained in:
/// Subsystem Train Detection System
/// Functional requirements specification
/// Subsystem Train Detection System - Interfaces
/// SCI-TDS (Subsystem – Electronic Interlocking)
/// SCI-TDS - Functional Viewpoint
/// SCI-TDS - Functional Entities
typedef struct SSciTdsCommand
{
    SSciTdsCommand__root__state_struct state;

    /// t70in_FC
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T70inFc;

    /// d70in_Mode_Of_FC
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(SSciTdsCommand_D70inModeOfFcValue, ) D70inModeOfFc;

    /// t72in_Update_Filling_Level
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T72inUpdateFillingLevel;

    /// t73in_Cancel
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T73inCancel;

    /// t74in_DRFC
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T74inDrfc;

    /// d50_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: False, Out: False, External: False
    DataPort(SSciTdsCommand_D50PdiConnectionStateValue, ) D50PdiConnectionState;

    // Messages -- Incoming

    // Messages -- Outgoing
    MessagePort(Message__CdFc__ec57) OutCdFc__ec57;
    MessagePort(Message__CdUpdateFillingLevel__d24d) OutCdUpdateFillingLevel__d24d;
    MessagePort(Message__CdCancel__6acf) OutCdCancel__6acf;
    MessagePort(Message__CdDrfc__15c7) OutCdDrfc__15c7;

    // Change Events
    ChangeEvent Change1259; // t70in_FC
    ChangeEvent Change1260; // t70in_FC
    ChangeEvent Change1258; // t70in_FC
    ChangeEvent Change1257; // t70in_FC
    ChangeEvent Change1256; // t70in_FC
    ChangeEvent Change1261; // t72in_Update_Filling_Level
    ChangeEvent Change1262; // t73in_Cancel
    ChangeEvent Change1263; // t74in_DRFC

    // Timeout Events

} SSciTdsCommand;

void transition_SSciTdsCommand(SSciTdsCommand *self);
void new_SSciTdsCommand(SSciTdsCommand *x);
