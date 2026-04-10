
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciAdjSec_D50outPdiConnectionStateValue
{
    SSciAdjSec_D50outPdiConnectionStateValue__NULL__,
    SSciAdjSec_D50outPdiConnectionStateValue__RequestedNoScp,
    SSciAdjSec_D50outPdiConnectionStateValue__ReadyForPdi,
    SSciAdjSec_D50outPdiConnectionStateValue__ReadyForInitialisation,
    SSciAdjSec_D50outPdiConnectionStateValue__SendingSecStatus,
    SSciAdjSec_D50outPdiConnectionStateValue__VersionUnequal,
    SSciAdjSec_D50outPdiConnectionStateValue__ReceivingPrimStatus,
    SSciAdjSec_D50outPdiConnectionStateValue__CheckingPrimStatus,
    SSciAdjSec_D50outPdiConnectionStateValue__Established,
    SSciAdjSec_D50outPdiConnectionStateValue__UNKNOWN__
} SSciAdjSec_D50outPdiConnectionStateValue;
typedef enum SSciAdjSec_D60PdiCloseReasonValue
{
    SSciAdjSec_D60PdiCloseReasonValue__NULL__,
    SSciAdjSec_D60PdiCloseReasonValue__PdiTimeout,
    SSciAdjSec_D60PdiCloseReasonValue__PrimFormalTelegramError,
    SSciAdjSec_D60PdiCloseReasonValue__PrimProtocolError,
    SSciAdjSec_D60PdiCloseReasonValue__PdiOtherVersionRequired,
    SSciAdjSec_D60PdiCloseReasonValue__PdiChecksumMismatch,
    SSciAdjSec_D60PdiCloseReasonValue__PrimContentTelegramError,
    SSciAdjSec_D60PdiCloseReasonValue__SecProtocolError,
    SSciAdjSec_D60PdiCloseReasonValue__SecFormalTelegramError,
    SSciAdjSec_D60PdiCloseReasonValue__SecContentTelegramError,
    SSciAdjSec_D60PdiCloseReasonValue__UNKNOWN__
} SSciAdjSec_D60PdiCloseReasonValue;

typedef enum SSciAdjSec__root__Active__root__Establishing__root__state
{
    SSciAdjSec__root__Active__root__Establishing__root__ReadyForInitialisation,
    SSciAdjSec__root__Active__root__Establishing__root__SendingSecStatus,
    SSciAdjSec__root__Active__root__Establishing__root__VersionUnequal,
    SSciAdjSec__root__Active__root__Establishing__root__ReceivingPrimStatus,
    SSciAdjSec__root__Active__root__Establishing__root__CheckingPrimStatus
} SSciAdjSec__root__Active__root__Establishing__root__state;

typedef struct SSciAdjSec__root__Active__root__Establishing__root__state_struct
{
    SSciAdjSec__root__Active__root__Establishing__root__state state;
    union {
    };
} SSciAdjSec__root__Active__root__Establishing__root__state_struct;

typedef enum SSciAdjSec__root__Active__root__state
{
    SSciAdjSec__root__Active__root__Establishing,
    SSciAdjSec__root__Active__root__Established
} SSciAdjSec__root__Active__root__state;

typedef struct SSciAdjSec__root__Active__root__Establishing__state_struct
{
    SSciAdjSec__root__Active__root__Establishing__root__state_struct root;
} SSciAdjSec__root__Active__root__Establishing__state_struct;

typedef struct SSciAdjSec__root__Active__root__state_struct
{
    SSciAdjSec__root__Active__root__state state;
    union {
        SSciAdjSec__root__Active__root__Establishing__state_struct Establishing;
    };
} SSciAdjSec__root__Active__root__state_struct;

typedef enum SSciAdjSec__root__state
{
    SSciAdjSec__root__RequestedNoScp,
    SSciAdjSec__root__ReadyForPdi,
    SSciAdjSec__root__Active
} SSciAdjSec__root__state;

typedef struct SSciAdjSec__root__Active__state_struct
{
    SSciAdjSec__root__Active__root__state_struct root;
} SSciAdjSec__root__Active__state_struct;

typedef struct SSciAdjSec__root__state_struct
{
    SSciAdjSec__root__state state;
    union {
        SSciAdjSec__root__Active__state_struct Active;
    };
} SSciAdjSec__root__state_struct;

/// Contained in:
/// Generic requirements for SCI
/// Adjacent systems interfaces
/// Interface between Subsystem - Electronic Interlocking and AdjS (SCI-XX AdjS)
/// SCI-XX AdjS - Functional Viewpoint
/// SCI-XX AdjS - Functional Entities
typedef struct SSciAdjSec
{
    SSciAdjSec__root__state_struct state;

    /// T5in_SCP_Connection_Established
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T5inScpConnectionEstablished;

    /// T10in_SCP_Connection_Terminated
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T10inScpConnectionTerminated;

    /// t25in_Prim_Status_Report_Complete
    /// Trigger: True, DataPort: False, In: True, Out: False, External: False
    PulsedIn T25inPrimStatusReportComplete;

    /// D3in_Con_PDI_Version
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(char, ) D3inConPdiVersion;

    /// D4in_Con_Checksum_Data
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(char, [16]) D4inConChecksumData;

    /// T11out_PDI_Connection_Established
    /// Trigger: True, DataPort: False, In: False, Out: True, External: True
    PulsedOut T11outPdiConnectionEstablished;

    /// D50out_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(SSciAdjSec_D50outPdiConnectionStateValue, ) D50outPdiConnectionState;

    /// T22in_Content_Telegram_Error
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T22inContentTelegramError;

    /// T20in_Protocol_Error
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T20inProtocolError;

    /// T21in_Formal_Telegram_Error
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T21inFormalTelegramError;

    /// T17out_PDI_Connection_Closed
    /// Trigger: True, DataPort: False, In: False, Out: True, External: True
    PulsedOut T17outPdiConnectionClosed;

    /// t27out_Check_Prim_Status
    /// Trigger: True, DataPort: False, In: False, Out: True, External: False
    PulsedOut T27outCheckPrimStatus;

    /// d60_PDI_Close_Reason
    /// Trigger: False, DataPort: True, In: False, Out: False, External: False
    DataPort(SSciAdjSec_D60PdiCloseReasonValue, ) D60PdiCloseReason;

    /// Mem_PDI_Version
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    char MemPdiVersion;

    // Messages -- Incoming
    MessagePort(Message__CdInitialisationRequest__8d96) InCdInitialisationRequest__8d96;
    MessagePort(Message__SecStatusReportCompleted__339c) InSecStatusReportCompleted__339c;
    MessagePort(Message__MsgStatusReportCompleted__c465) InMsgStatusReportCompleted__c465;
    MessagePort(Message__CdPdiVersionCheck__ffab) InCdPdiVersionCheck__ffab;
    MessagePort(Message__CdClosePdi__8a06) InCdClosePdi__8a06;
    // Messages -- Outgoing
    MessagePort(Message__StartSecStatusReport__2c19) OutStartSecStatusReport__2c19;
    MessagePort(Message__MsgStatusReportCompleted__c465) OutMsgStatusReportCompleted__c465;
    MessagePort(Message__PdiConnectionEstablished__019d) OutPdiConnectionEstablished__019d;
    MessagePort(Message__PdiConnectionClosed__7975) OutPdiConnectionClosed__7975;
    MessagePort(Message__MsgStartInitialisation__43d2) OutMsgStartInitialisation__43d2;
    MessagePort(Message__MsgInitialisationCompleted__75d9) OutMsgInitialisationCompleted__75d9;
    MessagePort(Message__MsgPdiVersionCheck__9827) OutMsgPdiVersionCheck__9827;
    MessagePort(Message__EstablishingPdiConnection__41d4) OutEstablishingPdiConnection__41d4;
    MessagePort(Message__MsgResetPdi__59f4) OutMsgResetPdi__59f4;

    // Change Events
    ChangeEvent Change1025; // t25in_Prim_Status_Report_Complete
    ChangeEvent Change1228; // T5in_SCP_Connection_Established
    ChangeEvent Change753;  // T10in_SCP_Connection_Terminated
    ChangeEvent Change745;  // T10in_SCP_Connection_Terminated
    ChangeEvent Change983;  // T20in_Protocol_Error
    ChangeEvent Change992;  // T21in_Formal_Telegram_Error
    ChangeEvent Change1004; // T22in_Content_Telegram_Error

    // Timeout Events

} SSciAdjSec;

void transition_SSciAdjSec(SSciAdjSec *self);
void new_SSciAdjSec(SSciAdjSec *x);
