
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciEfesSec_D50outPdiConnectionStateValue
{
    FSciEfesSec_D50outPdiConnectionStateValue__NULL__,
    FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdi,
    FSciEfesSec_D50outPdiConnectionStateValue__Suspended,
    FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi,
    FSciEfesSec_D50outPdiConnectionStateValue__ReadyForInitialisation,
    FSciEfesSec_D50outPdiConnectionStateValue__SendingStatus,
    FSciEfesSec_D50outPdiConnectionStateValue__VersionUnequal,
    FSciEfesSec_D50outPdiConnectionStateValue__Established,
    FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdiNoScp,
    FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdiNoScp,
    FSciEfesSec_D50outPdiConnectionStateValue__UNKNOWN__
} FSciEfesSec_D50outPdiConnectionStateValue;
typedef enum FSciEfesSec_D60outPdiCloseReasonValue
{
    FSciEfesSec_D60outPdiCloseReasonValue__NULL__,
    FSciEfesSec_D60outPdiCloseReasonValue__PdiOtherVersionRequired,
    FSciEfesSec_D60outPdiCloseReasonValue__EilContentTelegramError,
    FSciEfesSec_D60outPdiCloseReasonValue__EilFormalTelegramError,
    FSciEfesSec_D60outPdiCloseReasonValue__PdiNormalClose,
    FSciEfesSec_D60outPdiCloseReasonValue__EilProtocolError,
    FSciEfesSec_D60outPdiCloseReasonValue__PdiTimeout,
    FSciEfesSec_D60outPdiCloseReasonValue__EfesProtocolError,
    FSciEfesSec_D60outPdiCloseReasonValue__EfesFormalTelegramError,
    FSciEfesSec_D60outPdiCloseReasonValue__EfesContentTelegramError,
    FSciEfesSec_D60outPdiCloseReasonValue__UNKNOWN__
} FSciEfesSec_D60outPdiCloseReasonValue;

typedef enum FSciEfesSec__root__Active__root__Establishing__root__state
{
    FSciEfesSec__root__Active__root__Establishing__root__ReadyForInitialisation,
    FSciEfesSec__root__Active__root__Establishing__root__SendingStatus,
    FSciEfesSec__root__Active__root__Establishing__root__VersionUnequal
} FSciEfesSec__root__Active__root__Establishing__root__state;

typedef struct FSciEfesSec__root__Active__root__Establishing__root__state_struct
{
    FSciEfesSec__root__Active__root__Establishing__root__state state;
    union {
    };
} FSciEfesSec__root__Active__root__Establishing__root__state_struct;

typedef enum FSciEfesSec__root__Active__root__state
{
    FSciEfesSec__root__Active__root__Establishing,
    FSciEfesSec__root__Active__root__Established
} FSciEfesSec__root__Active__root__state;

typedef struct FSciEfesSec__root__Active__root__Establishing__state_struct
{
    FSciEfesSec__root__Active__root__Establishing__root__state_struct root;
} FSciEfesSec__root__Active__root__Establishing__state_struct;

typedef struct FSciEfesSec__root__Active__root__state_struct
{
    FSciEfesSec__root__Active__root__state state;
    union {
        FSciEfesSec__root__Active__root__Establishing__state_struct Establishing;
    };
} FSciEfesSec__root__Active__root__state_struct;

typedef enum FSciEfesSec__root__state
{
    FSciEfesSec__root__NotReadyForPdi,
    FSciEfesSec__root__Suspended,
    FSciEfesSec__root__ReadyForPdi,
    FSciEfesSec__root__Active,
    FSciEfesSec__root__NotReadyForPdiNoScp,
    FSciEfesSec__root__ReadyForPdiNoScp
} FSciEfesSec__root__state;

typedef struct FSciEfesSec__root__Active__state_struct
{
    FSciEfesSec__root__Active__root__state_struct root;
} FSciEfesSec__root__Active__state_struct;

typedef struct FSciEfesSec__root__state_struct
{
    FSciEfesSec__root__state state;
    union {
        FSciEfesSec__root__Active__state_struct Active;
    };
} FSciEfesSec__root__state_struct;

/// Contained in:
/// Generic requirements for SCI
/// Field element interfaces
/// Interface between Subsystem - Electronic Interlocking and EfeS (SCI-XX EfeS)
/// SCI-XX EfeS - Functional Viewpoint
/// SCI-XX EfeS - Functional Entities
typedef struct FSciEfesSec
{
    FSciEfesSec__root__state_struct state;

    /// D3in_Con_PDI_Version
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(char, ) D3inConPdiVersion;

    /// D4in_Con_Checksum_Data
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(char, [16]) D4inConChecksumData;

    /// T20in_Protocol_Error
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T20inProtocolError;

    /// T21in_Formal_Telegram_Error
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T21inFormalTelegramError;

    /// T22in_Content_Telegram_Error
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T22inContentTelegramError;

    /// d50out_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FSciEfesSec_D50outPdiConnectionStateValue, ) D50outPdiConnectionState;

    /// T5in_SCP_Connection_Established
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T5inScpConnectionEstablished;

    /// T10in_SCP_Connection_Terminated
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T10inScpConnectionTerminated;

    /// T12out_Terminate_SCP_Connection
    /// Trigger: True, DataPort: False, In: False, Out: True, External: True
    PulsedOut T12outTerminateScpConnection;

    /// d60out_PDI_Close_Reason
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FSciEfesSec_D60outPdiCloseReasonValue, ) D60outPdiCloseReason;

    /// Mem_PDI_Version
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    char MemPdiVersion;

    // Messages -- Incoming
    MessagePort(Message__CdInitialisationRequest__8d96) InCdInitialisationRequest__8d96;
    MessagePort(Message__StatusReportCompleted__b457) InStatusReportCompleted__b457;
    MessagePort(Message__CdPdiVersionCheck__ffab) InCdPdiVersionCheck__ffab;
    MessagePort(Message__ReadyForPdiConnection__6bd3) InReadyForPdiConnection__6bd3;
    MessagePort(Message__NotreadyForPdiConnection__0b73) InNotreadyForPdiConnection__0b73;
    MessagePort(Message__CdClosePdi__8a06) InCdClosePdi__8a06;
    MessagePort(Message__CdReleasePdiForMaintenance__3e43) InCdReleasePdiForMaintenance__3e43;
    // Messages -- Outgoing
    MessagePort(Message__PdiReleasedForMaintenance__3f7c) OutPdiReleasedForMaintenance__3f7c;
    MessagePort(Message__StartStatusReport__1e4e) OutStartStatusReport__1e4e;
    MessagePort(Message__PdiConnectionEstablished__4cbf) OutPdiConnectionEstablished__4cbf;
    MessagePort(Message__MsgStartInitialisation__43d2) OutMsgStartInitialisation__43d2;
    MessagePort(Message__MsgInitialisationCompleted__75d9) OutMsgInitialisationCompleted__75d9;
    MessagePort(Message__MsgPdiVersionCheck__9827) OutMsgPdiVersionCheck__9827;
    MessagePort(Message__MsgPdiNotAvailable__b83e) OutMsgPdiNotAvailable__b83e;
    MessagePort(Message__MsgPdiAvailable__af0a) OutMsgPdiAvailable__af0a;
    MessagePort(Message__PdiConnectionStarted__f9c3) OutPdiConnectionStarted__f9c3;
    MessagePort(Message__PdiConnectionClosed__d803) OutPdiConnectionClosed__d803;
    MessagePort(Message__MsgResetPdi__59f4) OutMsgResetPdi__59f4;

    // Change Events
    ChangeEvent Change745;  // T10in_SCP_Connection_Terminated
    ChangeEvent Change746;  // T10in_SCP_Connection_Terminated
    ChangeEvent Change747;  // T10in_SCP_Connection_Terminated
    ChangeEvent Change743;  // T10in_SCP_Connection_Terminated
    ChangeEvent Change977;  // T20in_Protocol_Error
    ChangeEvent Change984;  // T21in_Formal_Telegram_Error
    ChangeEvent Change999;  // T22in_Content_Telegram_Error
    ChangeEvent Change1222; // T5in_SCP_Connection_Established
    ChangeEvent Change1221; // T5in_SCP_Connection_Established

    // Timeout Events

} FSciEfesSec;

void transition_FSciEfesSec(FSciEfesSec *self);
void transition_FSciEfesSec(FSciEfesSec *self);
void new_FSciEfesSec(FSciEfesSec *x);
