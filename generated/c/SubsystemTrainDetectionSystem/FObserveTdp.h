
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveTdp_D53outReportTdpPassingStatusValue {
            FObserveTdp_D53outReportTdpPassingStatusValue__NULL__,
            FObserveTdp_D53outReportTdpPassingStatusValue__Undefined,
FObserveTdp_D53outReportTdpPassingStatusValue__NotPassed,
FObserveTdp_D53outReportTdpPassingStatusValue__Passed,
FObserveTdp_D53outReportTdpPassingStatusValue__TdpDisturbed,
            FObserveTdp_D53outReportTdpPassingStatusValue__UNKNOWN__
        } FObserveTdp_D53outReportTdpPassingStatusValue;
typedef enum FObserveTdp_D51outEstEfesStateValue {
            FObserveTdp_D51outEstEfesStateValue__NULL__,
            FObserveTdp_D51outEstEfesStateValue__Initialising,
FObserveTdp_D51outEstEfesStateValue__Booting,
FObserveTdp_D51outEstEfesStateValue__NoOperatingVoltage,
FObserveTdp_D51outEstEfesStateValue__FallbackMode,
            FObserveTdp_D51outEstEfesStateValue__UNKNOWN__
        } FObserveTdp_D51outEstEfesStateValue;
typedef enum FObserveTdp_D54outReportTdpDirectionValue {
            FObserveTdp_D54outReportTdpDirectionValue__NULL__,
            FObserveTdp_D54outReportTdpDirectionValue__Undefined,
FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection,
FObserveTdp_D54outReportTdpDirectionValue__AgainstReferenceDirection,
FObserveTdp_D54outReportTdpDirectionValue__ReferenceDirection,
            FObserveTdp_D54outReportTdpDirectionValue__UNKNOWN__
        } FObserveTdp_D54outReportTdpDirectionValue;








typedef enum FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed,
FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection,
FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection,
FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__OperationallyDisturbed,
FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__WaitingDelayOfNotificationOfUndefinedPattern
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state;



typedef struct FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state_struct {
    FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state state;
    union {
        
    };
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state_struct;


typedef enum FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__state {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection,
FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__TechnicallyDisturbed
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__state;


typedef struct FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__state_struct {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state_struct root;
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__state_struct;


typedef struct FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__state_struct {
    FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__state state;
    union {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__state_struct MonitoringTdpWithDirection;
    };
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__state_struct;





typedef enum FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__NotPassed,
FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed,
FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__OperationallyDisturbed,
FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__WaitingDelayOfNotificationOfUndefinedPattern
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state;



typedef struct FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state_struct {
    FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state state;
    union {
        
    };
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state_struct;


typedef enum FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__state {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection,
FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__TechnicallyDisturbed
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__state;


typedef struct FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__state_struct {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state_struct root;
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__state_struct;


typedef struct FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__state_struct {
    FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__state state;
    union {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__state_struct MonitoringTdpWithoutDirection;
    };
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__state_struct;


typedef enum FObserveTdp__root__NotFailed__root__Operational__root__state {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection,
FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection
} FObserveTdp__root__NotFailed__root__Operational__root__state;


typedef struct FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__state_struct {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__state_struct root;
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__state_struct;


typedef struct FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__state_struct {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__state_struct root;
} FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__state_struct;


typedef struct FObserveTdp__root__NotFailed__root__Operational__root__state_struct {
    FObserveTdp__root__NotFailed__root__Operational__root__state state;
    union {
        FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__state_struct TdpWithDirection;
FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__state_struct TdpWithoutDirection;
    };
} FObserveTdp__root__NotFailed__root__Operational__root__state_struct;


typedef enum FObserveTdp__root__NotFailed__root__state {
        FObserveTdp__root__NotFailed__root__WaitingForFinishedBooting,
FObserveTdp__root__NotFailed__root__Operational
} FObserveTdp__root__NotFailed__root__state;


typedef struct FObserveTdp__root__NotFailed__root__Operational__state_struct {
        FObserveTdp__root__NotFailed__root__Operational__root__state_struct root;
} FObserveTdp__root__NotFailed__root__Operational__state_struct;


typedef struct FObserveTdp__root__NotFailed__root__state_struct {
    FObserveTdp__root__NotFailed__root__state state;
    union {
        FObserveTdp__root__NotFailed__root__Operational__state_struct Operational;
    };
} FObserveTdp__root__NotFailed__root__state_struct;


typedef enum FObserveTdp__root__state {
        FObserveTdp__root__NotFailed,
FObserveTdp__root__FallbackMode
} FObserveTdp__root__state;


typedef struct FObserveTdp__root__NotFailed__state_struct {
        FObserveTdp__root__NotFailed__root__state_struct root;
} FObserveTdp__root__NotFailed__state_struct;


typedef struct FObserveTdp__root__state_struct {
    FObserveTdp__root__state state;
    union {
        FObserveTdp__root__NotFailed__state_struct NotFailed;
    };
} FObserveTdp__root__state_struct;


/// Contained in:
/// Subsystem - Train Detection System 
/// Functional requirements specification 
/// Subsystem - Train Detection System - Functional Viewpoint 
/// Subsystem - Train Detection System - Functional Entities
typedef struct FObserveTdp {
    FObserveTdp__root__state_struct state;

    /// T59in_Passing_In_Reference_Direction
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T59inPassingInReferenceDirection;
        
/// T60in_Passing_Against_Reference_Direction
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T60inPassingAgainstReferenceDirection;
        
/// D63in_Critical_Failure_TDP
            /// Trigger: False, DataPort: True, In: True, Out: False, External: True
            DataPort(bool, ) D63inCriticalFailureTdp;
            
/// D55in_Con_t_TDP_Delay
            /// Trigger: False, DataPort: True, In: True, Out: False, External: True
            DataPort(int, ) D55inConTTdpDelay;
            
/// d53out_Report_TDP_Passing_Status
            /// Trigger: False, DataPort: True, In: False, Out: True, External: False
            DataPort(FObserveTdp_D53outReportTdpPassingStatusValue, ) D53outReportTdpPassingStatus;
            
/// d51out_EST_EfeS_State
            /// Trigger: False, DataPort: True, In: False, Out: True, External: False
            DataPort(FObserveTdp_D51outEstEfesStateValue, ) D51outEstEfesState;
            
/// D56in_Con_TDP_Without_Direction
            /// Trigger: False, DataPort: True, In: True, Out: False, External: True
            DataPort(bool, ) D56inConTdpWithoutDirection;
            
/// T62in_Receiving_An_Undefined_Pattern
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T62inReceivingAnUndefinedPattern;
        
/// d54out_Report_TDP_Direction
            /// Trigger: False, DataPort: True, In: False, Out: True, External: False
            DataPort(FObserveTdp_D54outReportTdpDirectionValue, ) D54outReportTdpDirection;
            
/// T61in_Passing_Without_Direction
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T61inPassingWithoutDirection;
        
/// D58_Con_t_TDP_Undefined_Delay
            /// Trigger: False, DataPort: True, In: False, Out: False, External: True
            DataPort(int, ) D58ConTTdpUndefinedDelay;
            

    // Messages -- Incoming
    
    // Messages -- Outgoing
    

    // Change Events
    ChangeEvent Change1195; // T59in_Passing_In_Reference_Direction
ChangeEvent Change1229; // T60in_Passing_Against_Reference_Direction
ChangeEvent Change1238; // T62in_Receiving_An_Undefined_Pattern
ChangeEvent Change1197; // T59in_Passing_In_Reference_Direction
ChangeEvent Change1232; // T60in_Passing_Against_Reference_Direction or T62in_Receiving_An_Undefined_Pattern
ChangeEvent Change1198; // T59in_Passing_In_Reference_Direction or T62in_Receiving_An_Undefined_Pattern
ChangeEvent Change1230; // T60in_Passing_Against_Reference_Direction
ChangeEvent Change1196; // T59in_Passing_In_Reference_Direction
ChangeEvent Change1231; // T60in_Passing_Against_Reference_Direction
ChangeEvent Change1194; // T59in_Passing_In_Reference_Direction
ChangeEvent Change1228; // T60in_Passing_Against_Reference_Direction
ChangeEvent Change425; // D63in_Critical_Failure_TDP
ChangeEvent Change426; // D63in_Critical_Failure_TDP = FALSE
ChangeEvent Change1234; // T61in_Passing_Without_Direction
ChangeEvent Change1239; // T62in_Receiving_An_Undefined_Pattern
ChangeEvent Change1236; // T61in_Passing_Without_Direction or T62in_Receiving_An_Undefined_Pattern
ChangeEvent Change1233; // T61in_Passing_Without_Direction
ChangeEvent Change1235; // T61in_Passing_Without_Direction
ChangeEvent Change424; // D63in_Critical_Failure_TDP
ChangeEvent Change427; // D63in_Critical_Failure_TDP = FALSE
ChangeEvent Change401; // d51out_EST_EfeS_State = "INITIALISING"
ChangeEvent Change390; // d51out_EST_EfeS_State = "BOOTING" OR d51out_EST_EfeS_State = "NO_OPERATING_VOLTAGE"
ChangeEvent Change398; // d51out_EST_EfeS_State = "FALLBACK_MODE"
ChangeEvent Change385; // d51out_EST_EfeS_State = "BOOTING"

    // Timeout Events
    TimeoutEvent Time38;
TimeoutEvent Time39;
TimeoutEvent Time41;
TimeoutEvent Time37;
TimeoutEvent Time42;

} FObserveTdp;

void transition_FObserveTdp(FObserveTdp *self);
void new_FObserveTdp(FObserveTdp *x);
