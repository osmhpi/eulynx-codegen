
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciLsReport_D50inPdiConnectionStateValue
{
    FSciLsReport_D50inPdiConnectionStateValue__NULL__,
    FSciLsReport_D50inPdiConnectionStateValue__Established,
    FSciLsReport_D50inPdiConnectionStateValue__ReadyForPdiNoScp,
    FSciLsReport_D50inPdiConnectionStateValue__ReadyForPdi,
    FSciLsReport_D50inPdiConnectionStateValue__Suspended,
    FSciLsReport_D50inPdiConnectionStateValue__UNKNOWN__
} FSciLsReport_D50inPdiConnectionStateValue;
typedef enum FSciLsReport_D19inObservedSignalAspectValue
{
    FSciLsReport_D19inObservedSignalAspectValue__NULL__,
    FSciLsReport_D19inObservedSignalAspectValue__MostRestrictAspect,
    FSciLsReport_D19inObservedSignalAspectValue__NoSignalAspect,
    FSciLsReport_D19inObservedSignalAspectValue__SignalAspect1,
    FSciLsReport_D19inObservedSignalAspectValue__SignalAspect2,
    FSciLsReport_D19inObservedSignalAspectValue__UNKNOWN__
} FSciLsReport_D19inObservedSignalAspectValue;
typedef enum FSciLsReport_D21inObservedLuminosityValue
{
    FSciLsReport_D21inObservedLuminosityValue__NULL__,
    FSciLsReport_D21inObservedLuminosityValue__Day,
    FSciLsReport_D21inObservedLuminosityValue__Night,
    FSciLsReport_D21inObservedLuminosityValue__UNKNOWN__
} FSciLsReport_D21inObservedLuminosityValue;

typedef enum FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__state
{
    FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports
} FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__state;

typedef struct FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__state_struct
{
    FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__state state;
    union {
    };
} FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__state_struct;

typedef enum FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__state
{
    FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports
} FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__state;

typedef struct FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__state_struct
{
    FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__state state;
    union {
    };
} FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__state_struct;

typedef enum FSciLsReport__root__state
{
    FSciLsReport__root__SendingLightSignalReports,
    FSciLsReport__root__InterfaceConnectionNotEstablished
} FSciLsReport__root__state;

typedef struct FSciLsReport__root__SendingLightSignalReports__state_struct
{
    FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__state_struct ReportingSignalAspect;
    FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__state_struct ReportingLuminosity;
} FSciLsReport__root__SendingLightSignalReports__state_struct;

typedef struct FSciLsReport__root__state_struct
{
    FSciLsReport__root__state state;
    union {
        FSciLsReport__root__SendingLightSignalReports__state_struct SendingLightSignalReports;
    };
} FSciLsReport__root__state_struct;

/// Contained in:
/// Subsystem - Light Signal
/// Functional requirements specification
/// Subsystem - Light Signal - Interfaces
/// SCI-LS (Subsystem - Electronic Interlocking)
/// SCI-LS - Functional Viewpoint
/// SCI-LS - Functional Entities
typedef struct FSciLsReport
{
    FSciLsReport__root__state_struct state;

    /// d50in_PDI_Connection_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciLsReport_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;

    /// d20in_Observed_Intentionally_Dark
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D20inObservedIntentionallyDark;

    /// d19in_Observed_Signal_Aspect
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciLsReport_D19inObservedSignalAspectValue, ) D19inObservedSignalAspect;

    /// d21in_Observed_Luminosity
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FSciLsReport_D21inObservedLuminosityValue, ) D21inObservedLuminosity;

    // Messages -- Incoming
    MessagePort(Message__StartStatusReport__1e4e) InStartStatusReport__1e4e;
    // Messages -- Outgoing
    MessagePort(Message__MsgIndicatedSignalAspect__e129) OutMsgIndicatedSignalAspect__e129;
    MessagePort(Message__MsgSetLuminosity__c2b4) OutMsgSetLuminosity__c2b4;
    MessagePort(Message__StatusReportCompleted__b457) OutStatusReportCompleted__b457;

    // Change Events
    ChangeEvent Change132; // d19in_Observed_Signal_Aspect = "Most Restrict Aspect"
    ChangeEvent Change133; // d19in_Observed_Signal_Aspect = "No Signal Aspect"
    ChangeEvent Change134; // d19in_Observed_Signal_Aspect = "Signal Aspect 1"
    ChangeEvent Change135; // d19in_Observed_Signal_Aspect = "Signal Aspect 2"
    ChangeEvent Change169; // d20in_Observed_Intentionally_Dark
    ChangeEvent Change168; // d20in_Observed_Intentionally_Dark
    ChangeEvent Change170; // d20in_Observed_Intentionally_Dark
    ChangeEvent Change301; // d50in_PDI_Connection_State = "ESTABLISHED"
    ChangeEvent Change300; // d50in_PDI_Connection_State = "ESTABLISHED"
    ChangeEvent Change554; // NOT d20in_Observed_Intentionally_Dark
    ChangeEvent Change556; // NOT d20in_Observed_Intentionally_Dark
    ChangeEvent Change555; // NOT d20in_Observed_Intentionally_Dark
    ChangeEvent Change171; // d21in_Observed_Luminosity = "Day"
    ChangeEvent Change172; // d21in_Observed_Luminosity = "Night"
    ChangeEvent Change302; // d50in_PDI_Connection_State = "ESTABLISHED"
    ChangeEvent Change298; // d50in_PDI_Connection_State = "ESTABLISHED"
    ChangeEvent Change312; // d50in_PDI_Connection_State = "READY_FOR_PDI_NO_SCP"OR d50in_PDI_Connection_State =
                           // "READY_FOR_PDI"OR d50in_PDI_Connection_State = "SUSPENDED"

    // Timeout Events

} FSciLsReport;

void transition_FSciLsReport(FSciLsReport *self);
void new_FSciLsReport(FSciLsReport *x);
