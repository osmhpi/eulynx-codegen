
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciAdjPrim_D50outPdiConnectionStateValue {
  SSciAdjPrim_D50outPdiConnectionStateValue__NULL__,
  SSciAdjPrim_D50outPdiConnectionStateValue__RequestedNoScp,
  SSciAdjPrim_D50outPdiConnectionStateValue__ImpermissibleNoScp,
  SSciAdjPrim_D50outPdiConnectionStateValue__Impermissible,
  SSciAdjPrim_D50outPdiConnectionStateValue__WaitingForVersionCheck,
  SSciAdjPrim_D50outPdiConnectionStateValue__WaitingForInitialisation,
  SSciAdjPrim_D50outPdiConnectionStateValue__ReceivingSecStatus,
  SSciAdjPrim_D50outPdiConnectionStateValue__CheckingSecStatus,
  SSciAdjPrim_D50outPdiConnectionStateValue__SendingPrimStatus,
  SSciAdjPrim_D50outPdiConnectionStateValue__WaitingForInitCompletion,
  SSciAdjPrim_D50outPdiConnectionStateValue__Established,
  SSciAdjPrim_D50outPdiConnectionStateValue__UNKNOWN__
} SSciAdjPrim_D50outPdiConnectionStateValue;
typedef enum SSciAdjPrim_D60outPdiCloseReasonValue {
  SSciAdjPrim_D60outPdiCloseReasonValue__NULL__,
  SSciAdjPrim_D60outPdiCloseReasonValue__PdiChecksumMismatch,
  SSciAdjPrim_D60outPdiCloseReasonValue__PdiOtherVersionRequired,
  SSciAdjPrim_D60outPdiCloseReasonValue__PdiTimeout,
  SSciAdjPrim_D60outPdiCloseReasonValue__SecProtocolError,
  SSciAdjPrim_D60outPdiCloseReasonValue__SecContentTelegramError,
  SSciAdjPrim_D60outPdiCloseReasonValue__SecFormalTelegramError,
  SSciAdjPrim_D60outPdiCloseReasonValue__PrimProtocolError,
  SSciAdjPrim_D60outPdiCloseReasonValue__PrimFormalTelegramError,
  SSciAdjPrim_D60outPdiCloseReasonValue__PrimContentTelegramError,
  SSciAdjPrim_D60outPdiCloseReasonValue__UNKNOWN__
} SSciAdjPrim_D60outPdiCloseReasonValue;
typedef enum SSciAdjPrim_MemPdiVersionCheckResultValue {
  SSciAdjPrim_MemPdiVersionCheckResultValue__NULL__,
  SSciAdjPrim_MemPdiVersionCheckResultValue__Unknown,
  SSciAdjPrim_MemPdiVersionCheckResultValue__UNKNOWN__
} SSciAdjPrim_MemPdiVersionCheckResultValue;

typedef enum SSciAdjPrim__root__Active__root__Establishing__root__state {
  SSciAdjPrim__root__Active__root__Establishing__root__WaitingForVersionCheck,
  SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitialisation,
  SSciAdjPrim__root__Active__root__Establishing__root__ReceivingSecStatus,
  SSciAdjPrim__root__Active__root__Establishing__root__CheckingSecStatus,
  SSciAdjPrim__root__Active__root__Establishing__root__SendingPrimStatus,
  SSciAdjPrim__root__Active__root__Establishing__root__WaitingForInitCompletion
} SSciAdjPrim__root__Active__root__Establishing__root__state;

typedef struct
    SSciAdjPrim__root__Active__root__Establishing__root__state_struct {
  SSciAdjPrim__root__Active__root__Establishing__root__state state;
  union {};
} SSciAdjPrim__root__Active__root__Establishing__root__state_struct;

typedef enum SSciAdjPrim__root__Active__root__state {
  SSciAdjPrim__root__Active__root__Establishing,
  SSciAdjPrim__root__Active__root__Established
} SSciAdjPrim__root__Active__root__state;

typedef struct SSciAdjPrim__root__Active__root__Establishing__state_struct {
  SSciAdjPrim__root__Active__root__Establishing__root__state_struct root;
} SSciAdjPrim__root__Active__root__Establishing__state_struct;

typedef struct SSciAdjPrim__root__Active__root__state_struct {
  SSciAdjPrim__root__Active__root__state state;
  union {
    SSciAdjPrim__root__Active__root__Establishing__state_struct Establishing;
  };
} SSciAdjPrim__root__Active__root__state_struct;

typedef enum SSciAdjPrim__root__state {
  SSciAdjPrim__root__RequestedNoScp,
  SSciAdjPrim__root__ImpermissibleNoScp,
  SSciAdjPrim__root__Impermissible,
  SSciAdjPrim__root__Active
} SSciAdjPrim__root__state;

typedef struct SSciAdjPrim__root__Active__state_struct {
  SSciAdjPrim__root__Active__root__state_struct root;
} SSciAdjPrim__root__Active__state_struct;

typedef struct SSciAdjPrim__root__state_struct {
  SSciAdjPrim__root__state state;
  union {
    SSciAdjPrim__root__Active__state_struct Active;
  };
} SSciAdjPrim__root__state_struct;

/// Contained in:
/// Generic requirements for SCI
/// Adjacent systems interfaces
/// Interface between Subsystem - Electronic Interlocking and AdjS (SCI-XX AdjS)
/// SCI-XX AdjS - Functional Viewpoint
/// SCI-XX AdjS - Functional Entities
typedef struct SSciAdjPrim {
  SSciAdjPrim__root__state_struct state;

  /// T5in_SCP_Connection_Established
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T5inScpConnectionEstablished;

  /// T10in_SCP_Connection_Terminated
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T10inScpConnectionTerminated;

  /// D4in_Con_Checksum_Data
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(char, [16]) D4inConChecksumData;

  /// D50out_PDI_Connection_State
  /// Trigger: False, DataPort: True, In: False, Out: True, External: True
  DataPort(SSciAdjPrim_D50outPdiConnectionStateValue, )
      D50outPdiConnectionState;

  /// T6out_Establish_SCP_Connection
  /// Trigger: True, DataPort: False, In: False, Out: True, External: True
  PulsedOut T6outEstablishScpConnection;

  /// T22in_Content_Telegram_Error
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T22inContentTelegramError;

  /// T20in_Protocol_Error
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T20inProtocolError;

  /// T21in_Formal_Telegram_Error
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T21inFormalTelegramError;

  /// D2in_Con_tmax_PDI_Connection
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(int, ) D2inConTmaxPdiConnection;

  /// D3in_Con_PDI_Version
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(char, ) D3inConPdiVersion;

  /// T45in_Reset_Severe_Error
  /// Trigger: True, DataPort: False, In: True, Out: False, External: True
  PulsedIn T45inResetSevereError;

  /// d60out_PDI_Close_Reason
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(SSciAdjPrim_D60outPdiCloseReasonValue, ) D60outPdiCloseReason;

  /// t27out_Check_Sec_Status
  /// Trigger: True, DataPort: False, In: False, Out: True, External: False
  PulsedOut T27outCheckSecStatus;

  /// t25in_Sec_Status_Report_Complete
  /// Trigger: True, DataPort: False, In: True, Out: False, External: False
  PulsedIn T25inSecStatusReportComplete;

  /// Mem_PDI_Version_Check_Result
  /// Trigger: False, DataPort: False, In: False, Out: False, External: False
  SSciAdjPrim_MemPdiVersionCheckResultValue MemPdiVersionCheckResult;

  /// Mem_PDI_Version_ChecksumData
  /// Trigger: False, DataPort: False, In: False, Out: False, External: False
  char MemPdiVersionChecksumdata[16];

  // Messages -- Incoming
  MessagePort(Message__MsgPdiVersionCheck__9827) InMsgPdiVersionCheck__9827;
  MessagePort(Message__MsgStartInitialisation__43d2)
      InMsgStartInitialisation__43d2;
  MessagePort(Message__MsgStatusReportCompleted__c465)
      InMsgStatusReportCompleted__c465;
  MessagePort(Message__PrimStatusReportCompleted__80d8)
      InPrimStatusReportCompleted__80d8;
  MessagePort(Message__MsgInitialisationCompleted__75d9)
      InMsgInitialisationCompleted__75d9;
  MessagePort(Message__MsgResetPdi__59f4) InMsgResetPdi__59f4;
  // Messages -- Outgoing
  MessagePort(Message__StartPrimStatusReport__a91c)
      OutStartPrimStatusReport__a91c;
  MessagePort(Message__MsgStatusReportCompleted__c465)
      OutMsgStatusReportCompleted__c465;
  MessagePort(Message__PdiConnectionEstablished__019d)
      OutPdiConnectionEstablished__019d;
  MessagePort(Message__PdiConnectionClosed__7975) OutPdiConnectionClosed__7975;
  MessagePort(Message__EstablishingPdiConnection__41d4)
      OutEstablishingPdiConnection__41d4;
  MessagePort(Message__CdPdiVersionCheck__ffab) OutCdPdiVersionCheck__ffab;
  MessagePort(Message__CdInitialisationRequest__8d96)
      OutCdInitialisationRequest__8d96;
  MessagePort(Message__CdClosePdi__8a06) OutCdClosePdi__8a06;

  // Change Events
  ChangeEvent Change1026; // t25in_Sec_Status_Report_Complete
  ChangeEvent Change1223; // T5in_SCP_Connection_Established
  ChangeEvent Change1170; // T45in_Reset_Severe_Error
  ChangeEvent Change1229; // T5in_SCP_Connection_Established
  ChangeEvent Change744;  // T10in_SCP_Connection_Terminated
  ChangeEvent Change1169; // T45in_Reset_Severe_Error
  ChangeEvent Change748;  // T10in_SCP_Connection_Terminated
  ChangeEvent Change986;  // T20in_Protocol_Error
  ChangeEvent Change994;  // T21in_Formal_Telegram_Error
  ChangeEvent Change1005; // T22in_Content_Telegram_Error

  // Timeout Events
  TimeoutEvent Time22;

} SSciAdjPrim;

void transition_SSciAdjPrim(SSciAdjPrim *self);
void new_SSciAdjPrim(SSciAdjPrim *x);
