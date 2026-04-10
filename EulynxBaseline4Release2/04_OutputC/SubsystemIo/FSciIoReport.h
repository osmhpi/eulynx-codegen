
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciIoReport_D7inDetectedInputChannelState1Value {
  FSciIoReport_D7inDetectedInputChannelState1Value__NULL__,
  FSciIoReport_D7inDetectedInputChannelState1Value__Disturbed,
  FSciIoReport_D7inDetectedInputChannelState1Value__SwitchedOff,
  FSciIoReport_D7inDetectedInputChannelState1Value__SwitchedOn,
  FSciIoReport_D7inDetectedInputChannelState1Value__UNKNOWN__
} FSciIoReport_D7inDetectedInputChannelState1Value;
typedef enum FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value {
  FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__NULL__,
  FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__PhysicallyDisturbed,
  FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed,
  FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__UNKNOWN__
} FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value;
typedef enum FSciIoReport_D50inPdiConnectionStateValue {
  FSciIoReport_D50inPdiConnectionStateValue__NULL__,
  FSciIoReport_D50inPdiConnectionStateValue__Established,
  FSciIoReport_D50inPdiConnectionStateValue__NotReadyForPdiNoScp,
  FSciIoReport_D50inPdiConnectionStateValue__ReadyForPdiNoScp,
  FSciIoReport_D50inPdiConnectionStateValue__NotReadyForPdi,
  FSciIoReport_D50inPdiConnectionStateValue__ReadyForPdi,
  FSciIoReport_D50inPdiConnectionStateValue__Suspended,
  FSciIoReport_D50inPdiConnectionStateValue__UNKNOWN__
} FSciIoReport_D50inPdiConnectionStateValue;
typedef enum FSciIoReport_D7inDetectedInputChannelStatenValue {
  FSciIoReport_D7inDetectedInputChannelStatenValue__NULL__,
  FSciIoReport_D7inDetectedInputChannelStatenValue__SwitchedOff,
  FSciIoReport_D7inDetectedInputChannelStatenValue__SwitchedOn,
  FSciIoReport_D7inDetectedInputChannelStatenValue__Disturbed,
  FSciIoReport_D7inDetectedInputChannelStatenValue__UNKNOWN__
} FSciIoReport_D7inDetectedInputChannelStatenValue;
typedef enum FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue {
  FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__NULL__,
  FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed,
  FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__PhysicallyDisturbed,
  FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__UNKNOWN__
} FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue;
typedef enum FSciIoReport_MemLastReportedOutputChannelState1Value {
  FSciIoReport_MemLastReportedOutputChannelState1Value__NULL__,
  FSciIoReport_MemLastReportedOutputChannelState1Value__NotPhysicallyDisturbed,
  FSciIoReport_MemLastReportedOutputChannelState1Value__PhysicallyDisturbed,
  FSciIoReport_MemLastReportedOutputChannelState1Value__UNKNOWN__
} FSciIoReport_MemLastReportedOutputChannelState1Value;
typedef enum FSciIoReport_MemLastReportedOutputChannelStatenValue {
  FSciIoReport_MemLastReportedOutputChannelStatenValue__NULL__,
  FSciIoReport_MemLastReportedOutputChannelStatenValue__NotPhysicallyDisturbed,
  FSciIoReport_MemLastReportedOutputChannelStatenValue__PhysicallyDisturbed,
  FSciIoReport_MemLastReportedOutputChannelStatenValue__UNKNOWN__
} FSciIoReport_MemLastReportedOutputChannelStatenValue;
typedef enum FSciIoReport_MemLastReportedInputChannelState1Value {
  FSciIoReport_MemLastReportedInputChannelState1Value__NULL__,
  FSciIoReport_MemLastReportedInputChannelState1Value__SwitchedOn,
  FSciIoReport_MemLastReportedInputChannelState1Value__SwitchedOff,
  FSciIoReport_MemLastReportedInputChannelState1Value__Disturbed,
  FSciIoReport_MemLastReportedInputChannelState1Value__UNKNOWN__
} FSciIoReport_MemLastReportedInputChannelState1Value;
typedef enum FSciIoReport_MemLastReportedInputChannelStatenValue {
  FSciIoReport_MemLastReportedInputChannelStatenValue__NULL__,
  FSciIoReport_MemLastReportedInputChannelStatenValue__SwitchedOn,
  FSciIoReport_MemLastReportedInputChannelStatenValue__SwitchedOff,
  FSciIoReport_MemLastReportedInputChannelStatenValue__Disturbed,
  FSciIoReport_MemLastReportedInputChannelStatenValue__UNKNOWN__
} FSciIoReport_MemLastReportedInputChannelStatenValue;

typedef enum FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__state {
  FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports
} FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__state;

typedef struct
    FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__state_struct {
  FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__state
      state;
  union {};
} FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__state_struct;

typedef enum FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__state {
  FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports
} FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__state;

typedef struct
    FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__state_struct {
  FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__state
      state;
  union {};
} FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__state_struct;

typedef enum FSciIoReport__root__state {
  FSciIoReport__root__ReportingLogicalChannelStates,
  FSciIoReport__root__InterfaceConnectionNotEstablished
} FSciIoReport__root__state;

typedef struct FSciIoReport__root__ReportingLogicalChannelStates__state_struct {
  FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__state_struct
      ReportingLogicalInputChannelStates;
  FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__state_struct
      ReportingLogicalOutputChannelStates;
} FSciIoReport__root__ReportingLogicalChannelStates__state_struct;

typedef struct FSciIoReport__root__state_struct {
  FSciIoReport__root__state state;
  union {
    FSciIoReport__root__ReportingLogicalChannelStates__state_struct
        ReportingLogicalChannelStates;
  };
} FSciIoReport__root__state_struct;

/// Contained in:
/// Subsystem IO
/// Functional requirements specification
/// Subsystem Generic IO - Interfaces
/// SCI-IO (Subsystem - Electronic Interlocking)
/// SCI-IO - Functional Viewpoint
/// SCI-IO - Functional Entities
typedef struct FSciIoReport {
  FSciIoReport__root__state_struct state;

  /// d7in_Detected_Input_Channel_State1
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciIoReport_D7inDetectedInputChannelState1Value, )
      D7inDetectedInputChannelState1;

  /// d9in_Monitored_Output_Channel_Disturbance_State1
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value, )
      D9inMonitoredOutputChannelDisturbanceState1;

  /// d50in_PDI_Connection_State
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciIoReport_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;

  /// d7in_Detected_Input_Channel_StateN
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciIoReport_D7inDetectedInputChannelStatenValue, )
      D7inDetectedInputChannelStaten;

  /// d9in_Monitored_Output_Channel_Disturbance_StateN
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue, )
      D9inMonitoredOutputChannelDisturbanceStaten;

  /// Mem_Last_Reported_Output_Channel_State1
  /// Trigger: False, DataPort: False, In: False, Out: False, External: False
  FSciIoReport_MemLastReportedOutputChannelState1Value
      MemLastReportedOutputChannelState1;

  /// Mem_Last_Reported_Output_Channel_StateN
  /// Trigger: False, DataPort: False, In: False, Out: False, External: False
  FSciIoReport_MemLastReportedOutputChannelStatenValue
      MemLastReportedOutputChannelStaten;

  /// Mem_Last_Reported_Input_Channel_State1
  /// Trigger: False, DataPort: False, In: False, Out: False, External: False
  FSciIoReport_MemLastReportedInputChannelState1Value
      MemLastReportedInputChannelState1;

  /// Mem_Last_Reported_Input_Channel_StateN
  /// Trigger: False, DataPort: False, In: False, Out: False, External: False
  FSciIoReport_MemLastReportedInputChannelStatenValue
      MemLastReportedInputChannelStaten;

  // Messages -- Incoming
  MessagePort(Message__StartStatusReport__1e4e) InStartStatusReport__1e4e;
  // Messages -- Outgoing
  MessagePort(Message__MsgStateOfOutputChannels__c6d6)
      OutMsgStateOfOutputChannels__c6d6;
  MessagePort(Message__MsgStateOfInputChannels__8132)
      OutMsgStateOfInputChannels__8132;
  MessagePort(Message__StatusReportCompleted__b457)
      OutStatusReportCompleted__b457;

  // Change Events
  ChangeEvent Change325; // d50in_PDI_Connection_State = "ESTABLISHED"
  ChangeEvent Change461; // d7in_Detected_Input_Channel_State1 = "Disturbed" AND
                         // d7in_Detected_Input_Channel_StateN = "Switched_Off"
  ChangeEvent Change459; // d7in_Detected_Input_Channel_State1 = "Disturbed" AND
                         // d7in_Detected_Input_Channel_StateN = "Switched_On"
  ChangeEvent Change460; // d7in_Detected_Input_Channel_State1 = "Disturbed" AND
                         // d7in_Detected_Input_Channel_StateN = "Disturbed"
  ChangeEvent
      Change466; // d7in_Detected_Input_Channel_State1 = "Switched_Off" AND
                 // d7in_Detected_Input_Channel_StateN = "Switched_Off"
  ChangeEvent Change465; // d7in_Detected_Input_Channel_State1 = "Switched_Off"
                         // AND d7in_Detected_Input_Channel_StateN = "Disturbed"
  ChangeEvent Change463; // d7in_Detected_Input_Channel_State1 = "Switched_On"
                         // AND d7in_Detected_Input_Channel_StateN = "Disturbed"
  ChangeEvent
      Change467; // d7in_Detected_Input_Channel_State1 = "Switched_On"AND
                 // d7in_Detected_Input_Channel_StateN = "Switched_On"
  ChangeEvent
      Change464; // d7in_Detected_Input_Channel_State1 = "Switched_On" AND
                 // d7in_Detected_Input_Channel_StateN = "Switched_Off"
  ChangeEvent
      Change462; // d7in_Detected_Input_Channel_State1 = "Switched_Off" AND
                 // d7in_Detected_Input_Channel_StateN = "Switched_On"
  ChangeEvent Change326; // d50in_PDI_Connection_State = "ESTABLISHED"
  ChangeEvent Change505; // d9in_Monitored_Output_Channel_Disturbance_State1 =
                         // "Physically_Disturbed"AND
                         // d9in_Monitored_Output_Channel_Disturbance_StateN =
                         // "Not_Physically_Disturbed"
  ChangeEvent Change503; // d9in_Monitored_Output_Channel_Disturbance_State1 =
                         // "Not_Physically_Disturbed"AND
                         // d9in_Monitored_Output_Channel_Disturbance_StateN =
                         // "Physically_Disturbed"
  ChangeEvent Change499; // d9in_Monitored_Output_Channel_Disturbance_State1 =
                         // "Physically_Disturbed"AND
                         // d9in_Monitored_Output_Channel_Disturbance_StateN =
                         // "Physically_Disturbed"
  ChangeEvent Change504; // d9in_Monitored_Output_Channel_Disturbance_State1 =
                         // "Not_Physically_Disturbed"AND
                         // d9in_Monitored_Output_Channel_Disturbance_StateN =
                         // "Not_Physically_Disturbed"
  ChangeEvent
      Change334; // d50in_PDI_Connection_State = "NOT_READY_FOR_PDI_NO_SCP"OR
                 // d50in_PDI_Connection_State = "READY_FOR_PDI_NO_SCP"OR
                 // d50in_PDI_Connection_State = "NOT_READY_FOR_PDI"OR
                 // d50in_PDI_Connection_State = "READY_FOR_PDI"OR
                 // d50in_PDI_Connection_State = "SUSPENDED"

  // Timeout Events

} FSciIoReport;

void transition_FSciIoReport(FSciIoReport *self);
void new_FSciIoReport(FSciIoReport *x);
