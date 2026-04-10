
#include "FSciIoReceive.h"

// Value Conversion Functions



// Operations







void make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__RequiredOutputChannel1StateCanNotBeSet(FSciIoReceive *self, FSciIoReceive__root__ReceivingCommands__OutputChannelState1__state_struct *region) {
    LOG("[FSciIoReceive] Entering state RequiredOutputChannel1StateCanNotBeSet in region root__ReceivingCommands__OutputChannelState1");
    region->state = FSciIoReceive__root__ReceivingCommands__OutputChannelState1__RequiredOutputChannel1StateCanNotBeSet;
    
};


void make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1(FSciIoReceive *self, FSciIoReceive__root__ReceivingCommands__OutputChannelState1__state_struct *region) {
    LOG("[FSciIoReceive] Entering state ReceivingCommandsChannel1 in region root__ReceivingCommands__OutputChannelState1");
    region->state = FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1;
    
};


void make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1(FSciIoReceive *self, FSciIoReceive__root__ReceivingCommands__OutputChannelState1__state_struct *x) {
    memset(x, 0, sizeof(FSciIoReceive__root__ReceivingCommands__OutputChannelState1__state_struct));
    
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1(self, x); return;
}





void make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__RequiredOutputChannelNStateCanNotBeSet(FSciIoReceive *self, FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__state_struct *region) {
    LOG("[FSciIoReceive] Entering state RequiredOutputChannelNStateCanNotBeSet in region root__ReceivingCommands__OutputChannelStateN");
    region->state = FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__RequiredOutputChannelNStateCanNotBeSet;
    
};


void make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN(FSciIoReceive *self, FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__state_struct *region) {
    LOG("[FSciIoReceive] Entering state ReceivingCommandsChannelN in region root__ReceivingCommands__OutputChannelStateN");
    region->state = FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN;
    
};


void make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN(FSciIoReceive *self, FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__state_struct *x) {
    memset(x, 0, sizeof(FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__state_struct));
    
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN(self, x); return;
}



void make_state_FSciIoReceive__root__ReceivingCommands(FSciIoReceive *self, FSciIoReceive__root__state_struct *region) {
    LOG("[FSciIoReceive] Entering state ReceivingCommands in region root");
    region->state = FSciIoReceive__root__ReceivingCommands;
    make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1(self, &region->ReceivingCommands.OutputChannelState1);
make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN(self, &region->ReceivingCommands.OutputChannelStateN);
};


void make_state_FSciIoReceive__root__InterfaceConnectionClosed(FSciIoReceive *self, FSciIoReceive__root__state_struct *region) {
    LOG("[FSciIoReceive] Entering state InterfaceConnectionClosed in region root");
    region->state = FSciIoReceive__root__InterfaceConnectionClosed;
    
};


void make_state_FSciIoReceive__root(FSciIoReceive *self, FSciIoReceive__root__state_struct *x) {
    memset(x, 0, sizeof(FSciIoReceive__root__state_struct));
    self->D3outRequiredOutputChannelState1.Value = FSciIoReceive_D3outRequiredOutputChannelState1Value__Unknown;self->D3outRequiredOutputChannelState1.IsSignalled = true;
self->D3outRequiredOutputChannelStaten.Value = FSciIoReceive_D3outRequiredOutputChannelStatenValue__Unknown;self->D3outRequiredOutputChannelStaten.IsSignalled = true;
                make_state_FSciIoReceive__root__InterfaceConnectionClosed(self, x); return;
}



        
        

        void transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__RequiredOutputChannel1StateCanNotBeSet(FSciIoReceive *self, FSciIoReceive__root__state_struct *x) {
            
            if (self->Change498.IsTriggered) {
                if (!(self->D13inSwitchOffEachPhysicalOutputChannel.Value)) {
                
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1(self, &x->ReceivingCommands.OutputChannelState1); return;
            }
            }
if (self->Change543.IsTriggered) {
                if (self->D9inMonitoredOutputChannelDisturbanceState1.Value == FSciIoReceive_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed) {
                
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1(self, &x->ReceivingCommands.OutputChannelState1); return;
            }
            }
        }
        
void transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1(FSciIoReceive *self, FSciIoReceive__root__state_struct *x) {
            
            if (true) {
                self->D3outRequiredOutputChannelState1.Value = FSciIoReceive_D3outRequiredOutputChannelState1Value__Unknown;self->D3outRequiredOutputChannelState1.IsSignalled = true;
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__RequiredOutputChannel1StateCanNotBeSet(self, &x->ReceivingCommands.OutputChannelState1); return;
            }
if (self->Change104.IsTriggered) {
                self->D3outRequiredOutputChannelState1.Value = FSciIoReceive_D3outRequiredOutputChannelState1Value__Unknown;self->D3outRequiredOutputChannelState1.IsSignalled = true;
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__RequiredOutputChannel1StateCanNotBeSet(self, &x->ReceivingCommands.OutputChannelState1); return;
            }
if (self->InCdSetOutputChannels__3b5f.HasMessage) {
                if (self->InCdSetOutputChannels__3b5f.Value.CommandedOutputState1 == OutputChannelControllableState__80ea__SwitchedOff) {
                self->D3outRequiredOutputChannelState1.Value = FSciIoReceive_D3outRequiredOutputChannelState1Value__SwitchedOff;self->D3outRequiredOutputChannelState1.IsSignalled = true;
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1(self, &x->ReceivingCommands.OutputChannelState1); return;
            }
            }
if (self->InCdSetOutputChannels__3b5f.HasMessage) {
                if ((self->InCdSetOutputChannels__3b5f.Value.CommandedOutputState1 == OutputChannelControllableState__80ea__Flashing) && (self->D24inConFlashing.Value)) {
                self->D3outRequiredOutputChannelState1.Value = FSciIoReceive_D3outRequiredOutputChannelState1Value__Flashing;self->D3outRequiredOutputChannelState1.IsSignalled = true;
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1(self, &x->ReceivingCommands.OutputChannelState1); return;
            }
            }
if (self->InCdSetOutputChannels__3b5f.HasMessage) {
                if (self->InCdSetOutputChannels__3b5f.Value.CommandedOutputState1 == OutputChannelControllableState__80ea__SwitchedOn) {
                self->D3outRequiredOutputChannelState1.Value = FSciIoReceive_D3outRequiredOutputChannelState1Value__SwitchedOn;self->D3outRequiredOutputChannelState1.IsSignalled = true;
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1(self, &x->ReceivingCommands.OutputChannelState1); return;
            }
            }
        }
        

        void transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1(FSciIoReceive *self, FSciIoReceive__root__state_struct *x) {
            switch (x->ReceivingCommands.OutputChannelState1.state) {
                case FSciIoReceive__root__ReceivingCommands__OutputChannelState1__RequiredOutputChannel1StateCanNotBeSet:
                    transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__RequiredOutputChannel1StateCanNotBeSet(self, x);
                    break;
case FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1:
                    transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1(self, x);
                    break;
            }
        }
        

        

        void transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__RequiredOutputChannelNStateCanNotBeSet(FSciIoReceive *self, FSciIoReceive__root__state_struct *x) {
            
            if (self->Change493.IsTriggered) {
                if (!(self->D13inSwitchOffEachPhysicalOutputChannel.Value)) {
                
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN(self, &x->ReceivingCommands.OutputChannelStateN); return;
            }
            }
if (self->Change542.IsTriggered) {
                if (self->D9inMonitoredOutputChannelDisturbanceStaten.Value == FSciIoReceive_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed) {
                
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN(self, &x->ReceivingCommands.OutputChannelStateN); return;
            }
            }
        }
        
void transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN(FSciIoReceive *self, FSciIoReceive__root__state_struct *x) {
            
            if (true) {
                self->D3outRequiredOutputChannelStaten.Value = FSciIoReceive_D3outRequiredOutputChannelStatenValue__Unknown;self->D3outRequiredOutputChannelStaten.IsSignalled = true;
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__RequiredOutputChannelNStateCanNotBeSet(self, &x->ReceivingCommands.OutputChannelStateN); return;
            }
if (self->Change106.IsTriggered) {
                self->D3outRequiredOutputChannelStaten.Value = FSciIoReceive_D3outRequiredOutputChannelStatenValue__Unknown;self->D3outRequiredOutputChannelStaten.IsSignalled = true;
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__RequiredOutputChannelNStateCanNotBeSet(self, &x->ReceivingCommands.OutputChannelStateN); return;
            }
if (self->InCdSetOutputChannels__3b5f.HasMessage) {
                if (self->InCdSetOutputChannels__3b5f.Value.CommandedOutputStateN == OutputChannelControllableState__80ea__SwitchedOff) {
                self->D3outRequiredOutputChannelStaten.Value = FSciIoReceive_D3outRequiredOutputChannelStatenValue__SwitchedOff;self->D3outRequiredOutputChannelStaten.IsSignalled = true;
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN(self, &x->ReceivingCommands.OutputChannelStateN); return;
            }
            }
if (self->InCdSetOutputChannels__3b5f.HasMessage) {
                if ((self->InCdSetOutputChannels__3b5f.Value.CommandedOutputStateN == OutputChannelControllableState__80ea__Flashing) && (self->D24inConFlashing.Value)) {
                self->D3outRequiredOutputChannelStaten.Value = FSciIoReceive_D3outRequiredOutputChannelStatenValue__Flashing;self->D3outRequiredOutputChannelStaten.IsSignalled = true;
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN(self, &x->ReceivingCommands.OutputChannelStateN); return;
            }
            }
if (self->InCdSetOutputChannels__3b5f.HasMessage) {
                if (self->InCdSetOutputChannels__3b5f.Value.CommandedOutputStateN == OutputChannelControllableState__80ea__SwitchedOn) {
                self->D3outRequiredOutputChannelStaten.Value = FSciIoReceive_D3outRequiredOutputChannelStatenValue__SwitchedOn;self->D3outRequiredOutputChannelStaten.IsSignalled = true;
                make_state_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN(self, &x->ReceivingCommands.OutputChannelStateN); return;
            }
            }
        }
        

        void transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN(FSciIoReceive *self, FSciIoReceive__root__state_struct *x) {
            switch (x->ReceivingCommands.OutputChannelStateN.state) {
                case FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__RequiredOutputChannelNStateCanNotBeSet:
                    transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__RequiredOutputChannelNStateCanNotBeSet(self, x);
                    break;
case FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN:
                    transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN(self, x);
                    break;
            }
        }
        

        void transition_from_FSciIoReceive__root__ReceivingCommands(FSciIoReceive *self, FSciIoReceive__root__state_struct *x) {
            transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1(self, x);
transition_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN(self, x);
            if (self->Change317.IsTriggered) {
                self->D3outRequiredOutputChannelState1.Value = FSciIoReceive_D3outRequiredOutputChannelState1Value__Unknown;self->D3outRequiredOutputChannelState1.IsSignalled = true;
self->D3outRequiredOutputChannelStaten.Value = FSciIoReceive_D3outRequiredOutputChannelStatenValue__Unknown;self->D3outRequiredOutputChannelStaten.IsSignalled = true;
                make_state_FSciIoReceive__root__InterfaceConnectionClosed(self, x); return;
            }
        }
        
void transition_from_FSciIoReceive__root__InterfaceConnectionClosed(FSciIoReceive *self, FSciIoReceive__root__state_struct *x) {
            
            if (self->Change305.IsTriggered) {
                
                make_state_FSciIoReceive__root__ReceivingCommands(self, x); return;
            }
        }
        

        void transition_from_FSciIoReceive__root(FSciIoReceive *self, FSciIoReceive__root__state_struct *x) {
            switch (x->state) {
                case FSciIoReceive__root__ReceivingCommands:
                    transition_from_FSciIoReceive__root__ReceivingCommands(self, x);
                    break;
case FSciIoReceive__root__InterfaceConnectionClosed:
                    transition_from_FSciIoReceive__root__InterfaceConnectionClosed(self, x);
                    break;
            }
        }
        

static void evaluateChangeEvents(FSciIoReceive *self) {
    self->Change498.IsTriggered = IsTriggered(MakeChange(self->D9inMonitoredOutputChannelDisturbanceState1.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceState1.Value == FSciIoReceive_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed));
self->Change543.IsTriggered = IsTriggered(NegateChange(MakeChange(self->D13inSwitchOffEachPhysicalOutputChannel.IsSignalled, self->D13inSwitchOffEachPhysicalOutputChannel.Value)));
self->Change104.IsTriggered = IsTriggered(OrChange(MakeChange(self->D13inSwitchOffEachPhysicalOutputChannel.IsSignalled, self->D13inSwitchOffEachPhysicalOutputChannel.Value), MakeChange(self->D9inMonitoredOutputChannelDisturbanceState1.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceState1.Value == FSciIoReceive_D9inMonitoredOutputChannelDisturbanceState1Value__PhysicallyDisturbed)));
self->Change493.IsTriggered = IsTriggered(MakeChange(self->D9inMonitoredOutputChannelDisturbanceStaten.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceStaten.Value == FSciIoReceive_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed));
self->Change542.IsTriggered = IsTriggered(NegateChange(MakeChange(self->D13inSwitchOffEachPhysicalOutputChannel.IsSignalled, self->D13inSwitchOffEachPhysicalOutputChannel.Value)));
self->Change106.IsTriggered = IsTriggered(OrChange(MakeChange(self->D13inSwitchOffEachPhysicalOutputChannel.IsSignalled, self->D13inSwitchOffEachPhysicalOutputChannel.Value), MakeChange(self->D9inMonitoredOutputChannelDisturbanceStaten.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceStaten.Value == FSciIoReceive_D9inMonitoredOutputChannelDisturbanceStatenValue__PhysicallyDisturbed)));
self->Change317.IsTriggered = IsTriggered(OrChange(OrChange(MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciIoReceive_D50inPdiConnectionStateValue__ReadyForPdiNoScp), MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciIoReceive_D50inPdiConnectionStateValue__ReadyForPdi)), MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciIoReceive_D50inPdiConnectionStateValue__Suspended)));
self->Change305.IsTriggered = IsTriggered(MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciIoReceive_D50inPdiConnectionStateValue__Established));
}

static void resetOutputs(FSciIoReceive *self) {
    

    

    self->D3outRequiredOutputChannelState1.IsSignalled = false;
self->D3outRequiredOutputChannelStaten.IsSignalled = false;
}

static void resetTriggers(FSciIoReceive *self) {
    self->InCdSetOutputChannels__3b5f.HasMessage = false;

    

    self->D50inPdiConnectionState.IsSignalled = false;
self->D9inMonitoredOutputChannelDisturbanceStaten.IsSignalled = false;
self->D9inMonitoredOutputChannelDisturbanceState1.IsSignalled = false;
self->D13inSwitchOffEachPhysicalOutputChannel.IsSignalled = false;
self->D24inConFlashing.IsSignalled = false;

    
}

void transition_FSciIoReceive(FSciIoReceive *self) {
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FSciIoReceive__root(self, &self->state);
    resetTriggers(self);
}

void new_FSciIoReceive(FSciIoReceive *self) {
    make_state_FSciIoReceive__root(self, &self->state);
}
