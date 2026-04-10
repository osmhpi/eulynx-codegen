
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveOccupancyStatus_D9outOccupancyStatusValue {
            FObserveOccupancyStatus_D9outOccupancyStatusValue__NULL__,
            FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableIn,
FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableOut,
FObserveOccupancyStatus_D9outOccupancyStatusValue__Vacant,
FObserveOccupancyStatus_D9outOccupancyStatusValue__OccupiedIn,
FObserveOccupancyStatus_D9outOccupancyStatusValue__OccupiedOut,
FObserveOccupancyStatus_D9outOccupancyStatusValue__TechnicalDisturbed,
            FObserveOccupancyStatus_D9outOccupancyStatusValue__UNKNOWN__
        } FObserveOccupancyStatus_D9outOccupancyStatusValue;
typedef enum FObserveOccupancyStatus_D51outEstEfesStateValue {
            FObserveOccupancyStatus_D51outEstEfesStateValue__NULL__,
            FObserveOccupancyStatus_D51outEstEfesStateValue__Booting,
FObserveOccupancyStatus_D51outEstEfesStateValue__NoOperatingVoltage,
FObserveOccupancyStatus_D51outEstEfesStateValue__FallbackMode,
FObserveOccupancyStatus_D51outEstEfesStateValue__Initialising,
            FObserveOccupancyStatus_D51outEstEfesStateValue__UNKNOWN__
        } FObserveOccupancyStatus_D51outEstEfesStateValue;





typedef enum FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state {
        FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming,
FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing,
FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant,
FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming,
FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing,
FObserveOccupancyStatus__root__ObserveTvpsStatus__root__WaitingForNotificationOfAvailability
} FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state;



typedef struct FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct {
    FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state state;
    union {
        
    };
} FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct;


typedef enum FObserveOccupancyStatus__root__state {
        FObserveOccupancyStatus__root__ObserveTvpsStatus,
FObserveOccupancyStatus__root__FallbackMode,
FObserveOccupancyStatus__root__WaitingForFinishBooting,
FObserveOccupancyStatus__root__TechnicalDisturbance
} FObserveOccupancyStatus__root__state;


typedef struct FObserveOccupancyStatus__root__ObserveTvpsStatus__state_struct {
        FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct root;
} FObserveOccupancyStatus__root__ObserveTvpsStatus__state_struct;


typedef struct FObserveOccupancyStatus__root__state_struct {
    FObserveOccupancyStatus__root__state state;
    union {
        FObserveOccupancyStatus__root__ObserveTvpsStatus__state_struct ObserveTvpsStatus;
    };
} FObserveOccupancyStatus__root__state_struct;


/// Contained in:
/// Subsystem - Train Detection System 
/// Functional requirements specification 
/// Subsystem - Train Detection System - Functional Viewpoint 
/// Subsystem - Train Detection System - Functional Entities
typedef struct FObserveOccupancyStatus {
    FObserveOccupancyStatus__root__state_struct state;

    /// D26in_Con_Variant_A_is_used
            /// Trigger: False, DataPort: True, In: True, Out: False, External: True
            DataPort(bool, ) D26inConVariantAIsUsed;
            
/// d9out_Occupancy_Status
            /// Trigger: False, DataPort: True, In: False, Out: True, External: False
            DataPort(FObserveOccupancyStatus_D9outOccupancyStatusValue, ) D9outOccupancyStatus;
            
/// T37in_Wheel_In
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T37inWheelIn;
        
/// T38in_Wheel_Out
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T38inWheelOut;
        
/// T39in_Undefined_Pattern
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T39inUndefinedPattern;
        
/// D32in_Critical_Failure_TVPS
            /// Trigger: False, DataPort: True, In: True, Out: False, External: True
            DataPort(bool, ) D32inCriticalFailureTvps;
            
/// d51out_EST_EfeS_State
            /// Trigger: False, DataPort: True, In: False, Out: True, External: False
            DataPort(FObserveOccupancyStatus_D51outEstEfesStateValue, ) D51outEstEfesState;
            
/// d10out_Fillinglevel
            /// Trigger: False, DataPort: True, In: False, Out: True, External: False
            DataPort(int, ) D10outFillinglevel;
            
/// d16out_Last_Wheel_Out
            /// Trigger: False, DataPort: True, In: False, Out: True, External: False
            DataPort(bool, ) D16outLastWheelOut;
            


/// d14in_Monitoring_Time
            /// Trigger: False, DataPort: True, In: True, Out: False, External: False
            DataPort(bool, ) D14inMonitoringTime;
            

/// D28in_Con_t_Delay_Of_Notification_Of_Availability
            /// Trigger: False, DataPort: True, In: True, Out: False, External: True
            DataPort(int, ) D28inConTDelayOfNotificationOfAvailability;
            
/// Mem_EnteredAxles
            /// Trigger: False, DataPort: False, In: False, Out: False, External: False
            int MemEnteredaxles;
            
/// Mem_ExitedAxles
            /// Trigger: False, DataPort: False, In: False, Out: False, External: False
            int MemExitedaxles;
            
/// Mem_Difference
            /// Trigger: False, DataPort: False, In: False, Out: False, External: False
            int MemDifference;
            

    // Messages -- Incoming
    MessagePort(Message__ExecuteDrfc__4da5) InExecuteDrfc__4da5;
MessagePort(Message__ExecuteFc__ffe5) InExecuteFc__ffe5;
    // Messages -- Outgoing
    MessagePort(Message__ChangeTrigger__e05e) OutChangeTrigger__e05e;

    // Change Events
    ChangeEvent Change1110; // T38in_Wheel_Out
ChangeEvent Change1098; // T37in_Wheel_In
ChangeEvent Change1103; // T37in_Wheel_In OR T39in_Undefined_Pattern
ChangeEvent Change1106; // T38in_Wheel_Out
ChangeEvent Change1094; // T37in_Wheel_In
ChangeEvent Change1104; // T38in_Wheel_Out
ChangeEvent Change1115; // T39in_Undefined_Pattern
ChangeEvent Change1107; // T38in_Wheel_Out
ChangeEvent Change1114; // T39in_Undefined_Pattern
ChangeEvent Change1099; // T37in_Wheel_In
ChangeEvent Change536; // Mem_Difference = 0
ChangeEvent Change534; // Mem_Difference = 0
ChangeEvent Change1095; // T37in_Wheel_In
ChangeEvent Change1111; // T39in_Undefined_Pattern
ChangeEvent Change1109; // T38in_Wheel_Out
ChangeEvent Change546; // NOT d14in_Monitoring_Time
ChangeEvent Change1096; // T37in_Wheel_In
ChangeEvent Change1108; // T38in_Wheel_Out
ChangeEvent Change1112; // T39in_Undefined_Pattern
ChangeEvent Change235; // D32in_Critical_Failure_TVPS
ChangeEvent Change389; // d51out_EST_EfeS_State = "BOOTING" OR d51out_EST_EfeS_State = "NO_OPERATING_VOLTAGE"
ChangeEvent Change397; // d51out_EST_EfeS_State = "FALLBACK_MODE"
ChangeEvent Change1097; // T37in_Wheel_In
ChangeEvent Change1105; // T38in_Wheel_Out
ChangeEvent Change382; // d51out_EST_EfeS_State = "BOOTING"
ChangeEvent Change404; // d51out_EST_EfeS_State = "INITIALISING"
ChangeEvent Change394; // d51out_EST_EfeS_State = "FALLBACK_MODE"
ChangeEvent Change560; // NOT D32in_Critical_Failure_TVPS

    // Timeout Events
    

} FObserveOccupancyStatus;

void transition_FObserveOccupancyStatus(FObserveOccupancyStatus *self);
void new_FObserveOccupancyStatus(FObserveOccupancyStatus *x);
