
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FPerformFcPOrFcPA_D19outProcessStateValue {
            FPerformFcPOrFcPA_D19outProcessStateValue__NULL__,
            FPerformFcPOrFcPA_D19outProcessStateValue__WaitingForSweepingTrain,
FPerformFcPOrFcPA_D19outProcessStateValue__SweepingTrainDetected,
FPerformFcPOrFcPA_D19outProcessStateValue__WaitingForAnAcknowledgment,
FPerformFcPOrFcPA_D19outProcessStateValue__Waiting,
            FPerformFcPOrFcPA_D19outProcessStateValue__UNKNOWN__
        } FPerformFcPOrFcPA_D19outProcessStateValue;
typedef enum FPerformFcPOrFcPA_MemLastCommandValue {
            FPerformFcPOrFcPA_MemLastCommandValue__NULL__,
            FPerformFcPOrFcPA_MemLastCommandValue__FcP,
FPerformFcPOrFcPA_MemLastCommandValue__FcPA,
            FPerformFcPOrFcPA_MemLastCommandValue__UNKNOWN__
        } FPerformFcPOrFcPA_MemLastCommandValue;






typedef enum FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__state {
        FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__WaiitingForTMin,
FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__TMimExpired
} FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__state;



typedef struct FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__state_struct {
    FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__state state;
    union {
        
    };
} FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__state_struct;




typedef enum FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__state {
        FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Incoming,
FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Outgoing
} FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__state;



typedef struct FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__state_struct {
    FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__state state;
    union {
        
    };
} FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__state_struct;


typedef enum FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state {
        FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForSweepingTrain,
FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected,
FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForAcknowledgement,
FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SuccessfulSweeping
} FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state;


typedef struct FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__state_struct {
        FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__state_struct MonitorTMin;
FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__state_struct MonitorLastCountingAction;
} FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__state_struct;


typedef struct FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state_struct {
    FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state state;
    union {
        FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__state_struct SweepingTrainDetected;
    };
} FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state_struct;


typedef enum FPerformFcPOrFcPA__root__state {
        FPerformFcPOrFcPA__root__PerformFcPOrFcPA,
FPerformFcPOrFcPA__root__Waiting,
FPerformFcPOrFcPA__root__Failed
} FPerformFcPOrFcPA__root__state;


typedef struct FPerformFcPOrFcPA__root__PerformFcPOrFcPA__state_struct {
        FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state_struct root;
} FPerformFcPOrFcPA__root__PerformFcPOrFcPA__state_struct;


typedef struct FPerformFcPOrFcPA__root__state_struct {
    FPerformFcPOrFcPA__root__state state;
    union {
        FPerformFcPOrFcPA__root__PerformFcPOrFcPA__state_struct PerformFcPOrFcPA;
    };
} FPerformFcPOrFcPA__root__state_struct;


/// Contained in:
/// Subsystem - Train Detection System 
/// Functional requirements specification 
/// Subsystem - Train Detection System - Functional Viewpoint 
/// Subsystem - Train Detection System - Functional Entities
typedef struct FPerformFcPOrFcPA {
    FPerformFcPOrFcPA__root__state_struct state;

    /// T88in_In_Not_Permitted_Wheel
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T88inInNotPermittedWheel;
        
/// T42in_In_Permitted_Wheel
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T42inInPermittedWheel;
        
/// T44in_Out_Permitted_Wheel
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T44inOutPermittedWheel;
        
/// T39in_Undefined_Pattern
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T39inUndefinedPattern;
        
/// D30in_Con_t_Max_FC_P_or_FC_P_A
            /// Trigger: False, DataPort: True, In: True, Out: False, External: True
            DataPort(int, ) D30inConTMaxFcPOrFcPA;
            
/// D31in_Con_t_Min_FC_P_or_FC_P_A
            /// Trigger: False, DataPort: True, In: True, Out: False, External: True
            DataPort(int, ) D31inConTMinFcPOrFcPA;
            
/// T40in_Sweeping_Successful
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T40inSweepingSuccessful;
        
/// d18out_Perform_FC_P_or_FC_A
            /// Trigger: False, DataPort: True, In: False, Out: True, External: False
            DataPort(bool, ) D18outPerformFcPOrFcA;
            


/// d19out_Process_State
            /// Trigger: False, DataPort: True, In: False, Out: True, External: False
            DataPort(FPerformFcPOrFcPA_D19outProcessStateValue, ) D19outProcessState;
            
/// T43in_Out_Not_Permitted_Wheel
        /// Trigger: True, DataPort: False, In: True, Out: False, External: True
        PulsedIn T43inOutNotPermittedWheel;
        


/// D32in_Critical_Failure_TVPS
            /// Trigger: False, DataPort: True, In: True, Out: False, External: True
            DataPort(bool, ) D32inCriticalFailureTvps;
            
/// Mem_Last_Command
            /// Trigger: False, DataPort: False, In: False, Out: False, External: False
            FPerformFcPOrFcPA_MemLastCommandValue MemLastCommand;
            

    // Messages -- Incoming
    MessagePort(Message__ExecuteVisualSweepingConfirmation__251f) InExecuteVisualSweepingConfirmation__251f;
MessagePort(Message__ConfirmAcknowledgement__3cca) InConfirmAcknowledgement__3cca;
MessagePort(Message__ExecuteCancel__045b) InExecuteCancel__045b;
MessagePort(Message__ExecuteFcP__c2bd) InExecuteFcP__c2bd;
MessagePort(Message__ExecuteFcPA__f496) InExecuteFcPA__f496;
    // Messages -- Outgoing
    MessagePort(Message__ReasonFcPFailed__bfdd) OutReasonFcPFailed__bfdd;
MessagePort(Message__ReasonFcPAFailed__668a) OutReasonFcPAFailed__668a;
MessagePort(Message__ChangeTrigger__e05e) OutChangeTrigger__e05e;
MessagePort(Message__ExecuteFc__ffe5) OutExecuteFc__ffe5;

    // Change Events
    ChangeEvent Change1157; // T44in_Out_Permitted_Wheel
ChangeEvent Change1158; // T44in_Out_Permitted_Wheel
ChangeEvent Change1148; // T40in_Sweeping_Successful
ChangeEvent Change1152; // T42in_In_Permitted_Wheel
ChangeEvent Change1153; // T42in_In_Permitted_Wheel
ChangeEvent Change1156; // T44in_Out_Permitted_Wheel
ChangeEvent Change1154; // T42in_In_Permitted_Wheel OR T44in_Out_Permitted_Wheel
ChangeEvent Change231; // D32in_Critical_Failure_TVPS
ChangeEvent Change1113; // T39in_Undefined_Pattern
ChangeEvent Change1267; // T88in_In_Not_Permitted_Wheel OR T43in_Out_Not_Permitted_Wheel

    // Timeout Events
    TimeoutEvent Time26;
TimeoutEvent Time25;

} FPerformFcPOrFcPA;

void transition_FPerformFcPOrFcPA(FPerformFcPOrFcPA *self);
void new_FPerformFcPOrFcPA(FPerformFcPOrFcPA *x);
