
#pragma once
#include "../eulynx_common.h"

// Value Types






typedef enum FSciTdsReceive__root__state {
        FSciTdsReceive__root__ReceivingCommands
} FSciTdsReceive__root__state;



typedef struct FSciTdsReceive__root__state_struct {
    FSciTdsReceive__root__state state;
    union {
        
    };
} FSciTdsReceive__root__state_struct;


/// Contained in:
/// Subsystem - Train Detection System 
/// Functional requirements specification 
/// Subsystem - Train Detection System - Interfaces 
/// SCI-TDS (Subsystem – Electronic Interlocking) 
/// SCI-TDS - Functional Viewpoint 
/// SCI-TDS - Functional Entities
typedef struct FSciTdsReceive {
    FSciTdsReceive__root__state_struct state;

    


    // Messages -- Incoming
    MessagePort(Message__CdCancel__6acf) InCdCancel__6acf;
MessagePort(Message__CdDrfc__15c7) InCdDrfc__15c7;
MessagePort(Message__CdFc__ec57) InCdFc__ec57;
MessagePort(Message__CdUpdateFillingLevel__d24d) InCdUpdateFillingLevel__d24d;
    // Messages -- Outgoing
    MessagePort(Message__RequestCancel__7d24) OutRequestCancel__7d24;
MessagePort(Message__RequestDrfc__a48b) OutRequestDrfc__a48b;
MessagePort(Message__RequestFcPA__edba) OutRequestFcPA__edba;
MessagePort(Message__RequestAcknowledgement__2842) OutRequestAcknowledgement__2842;
MessagePort(Message__RequestFcP__e8be) OutRequestFcP__e8be;
MessagePort(Message__RequestFcU__bd99) OutRequestFcU__bd99;
MessagePort(Message__RequestFcC__f902) OutRequestFcC__f902;
MessagePort(Message__RequestUfl__f416) OutRequestUfl__f416;

    // Change Events
    

    // Timeout Events
    

} FSciTdsReceive;

void transition_FSciTdsReceive(FSciTdsReceive *self);
void new_FSciTdsReceive(FSciTdsReceive *x);
