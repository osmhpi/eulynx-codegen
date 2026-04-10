
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum SSciPCommand_D2inMovePointValue {
            SSciPCommand_D2inMovePointValue__NULL__,
            SSciPCommand_D2inMovePointValue__Right,
SSciPCommand_D2inMovePointValue__Left,
            SSciPCommand_D2inMovePointValue__UNKNOWN__
        } SSciPCommand_D2inMovePointValue;
typedef enum SSciPCommand_D50inPdiConnectionStateValue {
            SSciPCommand_D50inPdiConnectionStateValue__NULL__,
            SSciPCommand_D50inPdiConnectionStateValue__Established,
            SSciPCommand_D50inPdiConnectionStateValue__UNKNOWN__
        } SSciPCommand_D50inPdiConnectionStateValue;




typedef enum SSciPCommand__root__state {
        SSciPCommand__root__SendingCommands
} SSciPCommand__root__state;



typedef struct SSciPCommand__root__state_struct {
    SSciPCommand__root__state state;
    union {
        
    };
} SSciPCommand__root__state_struct;


/// Contained in:
/// Subsystem - Point 
/// Functional requirements specification 
/// Subsystem - Point - Interfaces 
/// SCI-P (Subsystem -  Electronic Interlocking) 
/// SCI-P - Functional Viewpoint 
/// SCI-P - Functional Entities
typedef struct SSciPCommand {
    SSciPCommand__root__state_struct state;

    /// d2in_Move_Point
            /// Trigger: False, DataPort: True, In: True, Out: False, External: False
            DataPort(SSciPCommand_D2inMovePointValue, ) D2inMovePoint;
            
/// t1in_Move_Point
        /// Trigger: True, DataPort: False, In: True, Out: False, External: False
        PulsedIn T1inMovePoint;
        
/// d50in_PDI_Connection_State
            /// Trigger: False, DataPort: True, In: True, Out: False, External: False
            DataPort(SSciPCommand_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;
            


    // Messages -- Incoming
    
    // Messages -- Outgoing
    MessagePort(Message__CdMovePoint__342e) OutCdMovePoint__342e;

    // Change Events
    ChangeEvent Change867; // t1in_Move_Point
ChangeEvent Change868; // t1in_Move_Point

    // Timeout Events
    

} SSciPCommand;

void transition_SSciPCommand(SSciPCommand *self);
void new_SSciPCommand(SSciPCommand *x);
