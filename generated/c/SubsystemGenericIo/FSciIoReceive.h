
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FSciIoReceive_D3outRequiredOutputChannelState1Value {
            FSciIoReceive_D3outRequiredOutputChannelState1Value__NULL__,
            FSciIoReceive_D3outRequiredOutputChannelState1Value__Unknown,
FSciIoReceive_D3outRequiredOutputChannelState1Value__SwitchedOff,
FSciIoReceive_D3outRequiredOutputChannelState1Value__Flashing,
FSciIoReceive_D3outRequiredOutputChannelState1Value__SwitchedOn,
            FSciIoReceive_D3outRequiredOutputChannelState1Value__UNKNOWN__
        } FSciIoReceive_D3outRequiredOutputChannelState1Value;
typedef enum FSciIoReceive_D50inPdiConnectionStateValue {
            FSciIoReceive_D50inPdiConnectionStateValue__NULL__,
            FSciIoReceive_D50inPdiConnectionStateValue__ReadyForPdiNoScp,
FSciIoReceive_D50inPdiConnectionStateValue__ReadyForPdi,
FSciIoReceive_D50inPdiConnectionStateValue__Suspended,
FSciIoReceive_D50inPdiConnectionStateValue__Established,
            FSciIoReceive_D50inPdiConnectionStateValue__UNKNOWN__
        } FSciIoReceive_D50inPdiConnectionStateValue;
typedef enum FSciIoReceive_D3outRequiredOutputChannelStatenValue {
            FSciIoReceive_D3outRequiredOutputChannelStatenValue__NULL__,
            FSciIoReceive_D3outRequiredOutputChannelStatenValue__Unknown,
FSciIoReceive_D3outRequiredOutputChannelStatenValue__SwitchedOff,
FSciIoReceive_D3outRequiredOutputChannelStatenValue__Flashing,
FSciIoReceive_D3outRequiredOutputChannelStatenValue__SwitchedOn,
            FSciIoReceive_D3outRequiredOutputChannelStatenValue__UNKNOWN__
        } FSciIoReceive_D3outRequiredOutputChannelStatenValue;
typedef enum FSciIoReceive_D9inMonitoredOutputChannelDisturbanceStatenValue {
            FSciIoReceive_D9inMonitoredOutputChannelDisturbanceStatenValue__NULL__,
            FSciIoReceive_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed,
FSciIoReceive_D9inMonitoredOutputChannelDisturbanceStatenValue__PhysicallyDisturbed,
            FSciIoReceive_D9inMonitoredOutputChannelDisturbanceStatenValue__UNKNOWN__
        } FSciIoReceive_D9inMonitoredOutputChannelDisturbanceStatenValue;
typedef enum FSciIoReceive_D9inMonitoredOutputChannelDisturbanceState1Value {
            FSciIoReceive_D9inMonitoredOutputChannelDisturbanceState1Value__NULL__,
            FSciIoReceive_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed,
FSciIoReceive_D9inMonitoredOutputChannelDisturbanceState1Value__PhysicallyDisturbed,
            FSciIoReceive_D9inMonitoredOutputChannelDisturbanceState1Value__UNKNOWN__
        } FSciIoReceive_D9inMonitoredOutputChannelDisturbanceState1Value;





typedef enum FSciIoReceive__root__ReceivingCommands__OutputChannelState1__state {
        FSciIoReceive__root__ReceivingCommands__OutputChannelState1__RequiredOutputChannel1StateCanNotBeSet,
FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1
} FSciIoReceive__root__ReceivingCommands__OutputChannelState1__state;



typedef struct FSciIoReceive__root__ReceivingCommands__OutputChannelState1__state_struct {
    FSciIoReceive__root__ReceivingCommands__OutputChannelState1__state state;
    union {
        
    };
} FSciIoReceive__root__ReceivingCommands__OutputChannelState1__state_struct;




typedef enum FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__state {
        FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__RequiredOutputChannelNStateCanNotBeSet,
FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN
} FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__state;



typedef struct FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__state_struct {
    FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__state state;
    union {
        
    };
} FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__state_struct;


typedef enum FSciIoReceive__root__state {
        FSciIoReceive__root__ReceivingCommands,
FSciIoReceive__root__InterfaceConnectionClosed
} FSciIoReceive__root__state;


typedef struct FSciIoReceive__root__ReceivingCommands__state_struct {
        FSciIoReceive__root__ReceivingCommands__OutputChannelState1__state_struct OutputChannelState1;
FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__state_struct OutputChannelStateN;
} FSciIoReceive__root__ReceivingCommands__state_struct;


typedef struct FSciIoReceive__root__state_struct {
    FSciIoReceive__root__state state;
    union {
        FSciIoReceive__root__ReceivingCommands__state_struct ReceivingCommands;
    };
} FSciIoReceive__root__state_struct;


/// Contained in:
/// Subsystem - Generic IO 
/// Functional requirements specification 
/// Subsystem - Generic IO - Interfaces 
/// SCI-IO (Subsystem - Electronic Interlocking) 
/// SCI-IO - Functional Viewpoint 
/// SCI-IO - Functional Entities
typedef struct FSciIoReceive {
    FSciIoReceive__root__state_struct state;

    /// d3out_Required_Output_Channel_State1
            /// Trigger: False, DataPort: True, In: False, Out: True, External: False
            DataPort(FSciIoReceive_D3outRequiredOutputChannelState1Value, ) D3outRequiredOutputChannelState1;
            
/// d50in_PDI_Connection_State
            /// Trigger: False, DataPort: True, In: True, Out: False, External: False
            DataPort(FSciIoReceive_D50inPdiConnectionStateValue, ) D50inPdiConnectionState;
            

/// d3out_Required_Output_Channel_StateN
            /// Trigger: False, DataPort: True, In: False, Out: True, External: False
            DataPort(FSciIoReceive_D3outRequiredOutputChannelStatenValue, ) D3outRequiredOutputChannelStaten;
            
/// d9in_Monitored_Output_Channel_Disturbance_StateN
            /// Trigger: False, DataPort: True, In: True, Out: False, External: False
            DataPort(FSciIoReceive_D9inMonitoredOutputChannelDisturbanceStatenValue, ) D9inMonitoredOutputChannelDisturbanceStaten;
            
/// d9in_Monitored_Output_Channel_Disturbance_State1
            /// Trigger: False, DataPort: True, In: True, Out: False, External: False
            DataPort(FSciIoReceive_D9inMonitoredOutputChannelDisturbanceState1Value, ) D9inMonitoredOutputChannelDisturbanceState1;
            
/// d13in_Switch_Off_Each_Physical_Output_Channel
            /// Trigger: False, DataPort: True, In: True, Out: False, External: False
            DataPort(bool, ) D13inSwitchOffEachPhysicalOutputChannel;
            
/// D24in_Con_Flashing
            /// Trigger: False, DataPort: True, In: True, Out: False, External: True
            DataPort(bool, ) D24inConFlashing;
            

    // Messages -- Incoming
    MessagePort(Message__CdSetOutputChannels__3b5f) InCdSetOutputChannels__3b5f;
    // Messages -- Outgoing
    

    // Change Events
    ChangeEvent Change498; // d9in_Monitored_Output_Channel_Disturbance_State1 = "Not_Physically_Disturbed"
ChangeEvent Change543; // Not d13in_Switch_Off_Each_Physical_Output_Channel
ChangeEvent Change104; // d13in_Switch_Off_Each_Physical_Output_Channel OR d9in_Monitored_Output_Channel_Disturbance_State1 = "Physically_Disturbed"
ChangeEvent Change493; // d9in_Monitored_Output_Channel_Disturbance_StateN = "Not_Physically_Disturbed"
ChangeEvent Change542; // Not d13in_Switch_Off_Each_Physical_Output_Channel
ChangeEvent Change106; // d13in_Switch_Off_Each_Physical_Output_Channel OR d9in_Monitored_Output_Channel_Disturbance_StateN = "Physically_Disturbed"
ChangeEvent Change317; // d50in_PDI_Connection_State = "READY_FOR_PDI_NO_SCP"OR d50in_PDI_Connection_State = "READY_FOR_PDI"OR d50in_PDI_Connection_State = "SUSPENDED"
ChangeEvent Change305; // d50in_PDI_Connection_State = "ESTABLISHED" 

    // Timeout Events
    

} FSciIoReceive;

void transition_FSciIoReceive(FSciIoReceive *self);
void new_FSciIoReceive(FSciIoReceive *x);
