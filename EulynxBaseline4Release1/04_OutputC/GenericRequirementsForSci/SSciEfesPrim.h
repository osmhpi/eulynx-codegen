
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciEfesPrim_D50outPdiConnectionStateValue
{
    SSciEfesPrim_D50outPdiConnectionStateValue__NULL__,
    SSciEfesPrim_D50outPdiConnectionStateValue__RequestedNoScp,
    SSciEfesPrim_D50outPdiConnectionStateValue__ImpermissibleNoScp,
    SSciEfesPrim_D50outPdiConnectionStateValue__Impermissible,
    SSciEfesPrim_D50outPdiConnectionStateValue__Disconnected,
    SSciEfesPrim_D50outPdiConnectionStateValue__DisconnectedNoScp,
    SSciEfesPrim_D50outPdiConnectionStateValue__WaitingForVersionCheck,
    SSciEfesPrim_D50outPdiConnectionStateValue__WaitingForInitialisation,
    SSciEfesPrim_D50outPdiConnectionStateValue__ReceivingStatus,
    SSciEfesPrim_D50outPdiConnectionStateValue__OtherVersionRequired,
    SSciEfesPrim_D50outPdiConnectionStateValue__Established,
    SSciEfesPrim_D50outPdiConnectionStateValue__Suspended,
    SSciEfesPrim_D50outPdiConnectionStateValue__UNKNOWN__
} SSciEfesPrim_D50outPdiConnectionStateValue;
typedef enum SSciEfesPrim_D60outPdiCloseReasonValue
{
    SSciEfesPrim_D60outPdiCloseReasonValue__NULL__,
    SSciEfesPrim_D60outPdiCloseReasonValue__NoError,
    SSciEfesPrim_D60outPdiCloseReasonValue__PdiOtherVersionRequired,
    SSciEfesPrim_D60outPdiCloseReasonValue__PdiTimeout,
    SSciEfesPrim_D60outPdiCloseReasonValue__EfesProtocolError,
    SSciEfesPrim_D60outPdiCloseReasonValue__EfesContentTelegramError,
    SSciEfesPrim_D60outPdiCloseReasonValue__EfesFormalTelegramError,
    SSciEfesPrim_D60outPdiCloseReasonValue__EilProtocolError,
    SSciEfesPrim_D60outPdiCloseReasonValue__EilFormalTelegramError,
    SSciEfesPrim_D60outPdiCloseReasonValue__EilContentTelegramError,
    SSciEfesPrim_D60outPdiCloseReasonValue__PdiNormalClose,
    SSciEfesPrim_D60outPdiCloseReasonValue__UNKNOWN__
} SSciEfesPrim_D60outPdiCloseReasonValue;
typedef enum SSciEfesPrim_MemPdiVersionResultValue
{
    SSciEfesPrim_MemPdiVersionResultValue__NULL__,
    SSciEfesPrim_MemPdiVersionResultValue__Unknown,
    SSciEfesPrim_MemPdiVersionResultValue__Match,
    SSciEfesPrim_MemPdiVersionResultValue__NotMatch,
    SSciEfesPrim_MemPdiVersionResultValue__UNKNOWN__
} SSciEfesPrim_MemPdiVersionResultValue;

typedef enum SSciEfesPrim__root__Active__root__Establishing__root__state
{
    SSciEfesPrim__root__Active__root__Establishing__root__WaitingForVersionCheck,
    SSciEfesPrim__root__Active__root__Establishing__root__WaitingForInitialisation,
    SSciEfesPrim__root__Active__root__Establishing__root__ReceivingStatus,
    SSciEfesPrim__root__Active__root__Establishing__root__OtherVersionRequired
} SSciEfesPrim__root__Active__root__Establishing__root__state;

typedef struct SSciEfesPrim__root__Active__root__Establishing__root__state_struct
{
    SSciEfesPrim__root__Active__root__Establishing__root__state state;
    union {
    };
} SSciEfesPrim__root__Active__root__Establishing__root__state_struct;

typedef enum SSciEfesPrim__root__Active__root__state
{
    SSciEfesPrim__root__Active__root__Establishing,
    SSciEfesPrim__root__Active__root__Established
} SSciEfesPrim__root__Active__root__state;

typedef struct SSciEfesPrim__root__Active__root__Establishing__state_struct
{
    SSciEfesPrim__root__Active__root__Establishing__root__state_struct root;
} SSciEfesPrim__root__Active__root__Establishing__state_struct;

typedef struct SSciEfesPrim__root__Active__root__state_struct
{
    SSciEfesPrim__root__Active__root__state state;
    union {
        SSciEfesPrim__root__Active__root__Establishing__state_struct Establishing;
    };
} SSciEfesPrim__root__Active__root__state_struct;

typedef enum SSciEfesPrim__root__state
{
    SSciEfesPrim__root__RequestedNoScp,
    SSciEfesPrim__root__ImpermissibleNoScp,
    SSciEfesPrim__root__Impermissible,
    SSciEfesPrim__root__Disconnected,
    SSciEfesPrim__root__DisconnectedNoScp,
    SSciEfesPrim__root__Active,
    SSciEfesPrim__root__Suspended
} SSciEfesPrim__root__state;

typedef struct SSciEfesPrim__root__Active__state_struct
{
    SSciEfesPrim__root__Active__root__state_struct root;
} SSciEfesPrim__root__Active__state_struct;

typedef struct SSciEfesPrim__root__state_struct
{
    SSciEfesPrim__root__state state;
    union {
        SSciEfesPrim__root__Active__state_struct Active;
    };
} SSciEfesPrim__root__state_struct;

/// Contained in:
/// Generic requirements for SCI
/// Field element interfaces
/// Interface between Subsystem - Electronic Interlocking and EfeS (SCI-XX EfeS)
/// SCI-XX EfeS - Functional Viewpoint
/// SCI-XX EfeS - Functional Entities
typedef struct SSciEfesPrim
{
    SSciEfesPrim__root__state_struct state;

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

    /// T5in_SCP_Connection_Established
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T5inScpConnectionEstablished;

    /// T10in_SCP_Connection_Terminated
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T10inScpConnectionTerminated;

    /// T12out_Terminate_SCP_Connection
    /// Trigger: True, DataPort: False, In: False, Out: True, External: True
    PulsedOut T12outTerminateScpConnection;

    /// d50out_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(SSciEfesPrim_D50outPdiConnectionStateValue, ) D50outPdiConnectionState;

    /// D2in_Con_tmax_PDI_Connection
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D2inConTmaxPdiConnection;

    /// T6out_Establish_SCP_Connection
    /// Trigger: True, DataPort: False, In: False, Out: True, External: True
    PulsedOut T6outEstablishScpConnection;

    /// T48in_Disable_Or_Disconnect_PDI_EfeS
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T48inDisableOrDisconnectPdiEfes;

    /// T49in_Enable_Or_Connect_PDI_EfeS
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T49inEnableOrConnectPdiEfes;

    /// T45in_Reset_Severe_Error
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T45inResetSevereError;

    /// T47in_Con_Other_PDI_Version_Available
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T47inConOtherPdiVersionAvailable;

    /// D39in_Con_Last_PDI_Version
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D39inConLastPdiVersion;

    /// T46out_Con_Other_PDI_Version_Request
    /// Trigger: True, DataPort: False, In: False, Out: True, External: True
    PulsedOut T46outConOtherPdiVersionRequest;

    /// T44in_Initiate_Maintenance
    /// Trigger: True, DataPort: False, In: True, Out: False, External: True
    PulsedIn T44inInitiateMaintenance;

    /// d60out_PDI_Close_Reason
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(SSciEfesPrim_D60outPdiCloseReasonValue, ) D60outPdiCloseReason;

    /// Mem_PDI_Version_Result
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    SSciEfesPrim_MemPdiVersionResultValue MemPdiVersionResult;

    /// Mem_Checksum_Data
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    char MemChecksumData[16];

    // Messages -- Incoming
    MessagePort(Message__MsgPdiVersionCheck__9827) InMsgPdiVersionCheck__9827;
    MessagePort(Message__MsgStartInitialisation__43d2) InMsgStartInitialisation__43d2;
    MessagePort(Message__MsgInitialisationCompleted__75d9) InMsgInitialisationCompleted__75d9;
    MessagePort(Message__MsgPdiNotAvailable__b83e) InMsgPdiNotAvailable__b83e;
    MessagePort(Message__MsgResetPdi__59f4) InMsgResetPdi__59f4;
    MessagePort(Message__MsgPdiAvailable__af0a) InMsgPdiAvailable__af0a;
    // Messages -- Outgoing
    MessagePort(Message__CdPdiVersionCheck__ffab) OutCdPdiVersionCheck__ffab;
    MessagePort(Message__CdReleasePdiForMaintenance__3e43) OutCdReleasePdiForMaintenance__3e43;
    MessagePort(Message__CdInitialisationRequest__8d96) OutCdInitialisationRequest__8d96;
    MessagePort(Message__CdClosePdi__8a06) OutCdClosePdi__8a06;

    // Change Events
    ChangeEvent Change1175; // T47in_Con_Other_PDI_Version_Available
    ChangeEvent Change1178; // T48in_Disable_Or_Disconnect_PDI_EfeS
    ChangeEvent Change1225; // T5in_SCP_Connection_Established
    ChangeEvent Change1172; // T45in_Reset_Severe_Error
    ChangeEvent Change1223; // T5in_SCP_Connection_Established
    ChangeEvent Change743;  // T10in_SCP_Connection_Terminated
    ChangeEvent Change1171; // T45in_Reset_Severe_Error
    ChangeEvent Change745;  // T10in_SCP_Connection_Terminated
    ChangeEvent Change1180; // T49in_Enable_Or_Connect_PDI_EfeS
    ChangeEvent Change1181; // T49in_Enable_Or_Connect_PDI_EfeS
    ChangeEvent Change1227; // T5in_SCP_Connection_Established
    ChangeEvent Change749;  // T10in_SCP_Connection_Terminated
    ChangeEvent Change980;  // T20in_Protocol_Error
    ChangeEvent Change987;  // T21in_Formal_Telegram_Error
    ChangeEvent Change999;  // T22in_Content_Telegram_Error
    ChangeEvent Change1162; // T44in_Initiate_Maintenance
    ChangeEvent Change1179; // T48in_Disable_Or_Disconnect_PDI_EfeS
    ChangeEvent Change742;  // T10in_SCP_Connection_Terminated
    ChangeEvent Change1177; // T48in_Disable_Or_Disconnect_PDI_EfeS

    // Timeout Events
    TimeoutEvent Time24;

} SSciEfesPrim;

void transition_SSciEfesPrim(SSciEfesPrim *self);
void new_SSciEfesPrim(SSciEfesPrim *x);
