
#include "FSciIoReport.h"

// Value Conversion Functions

static FSciIoReport_D7inDetectedInputChannelState1Value map_MemLastReportedInputChannelState1_to_D7inDetectedInputChannelState1(FSciIoReport_MemLastReportedInputChannelState1Value value) {
            switch (value) {
                case FSciIoReport_MemLastReportedInputChannelState1Value__NULL__: return FSciIoReport_D7inDetectedInputChannelState1Value__NULL__;
                case FSciIoReport_MemLastReportedInputChannelState1Value__UNKNOWN__: return FSciIoReport_D7inDetectedInputChannelState1Value__UNKNOWN__;
                case FSciIoReport_MemLastReportedInputChannelState1Value__SwitchedOn: return FSciIoReport_D7inDetectedInputChannelState1Value__SwitchedOn; 
case FSciIoReport_MemLastReportedInputChannelState1Value__SwitchedOff: return FSciIoReport_D7inDetectedInputChannelState1Value__SwitchedOff; 
case FSciIoReport_MemLastReportedInputChannelState1Value__Disturbed: return FSciIoReport_D7inDetectedInputChannelState1Value__Disturbed;
                default: abort();
            }
        }
static FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value map_MemLastReportedOutputChannelState1_to_D9inMonitoredOutputChannelDisturbanceState1(FSciIoReport_MemLastReportedOutputChannelState1Value value) {
            switch (value) {
                case FSciIoReport_MemLastReportedOutputChannelState1Value__NULL__: return FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__NULL__;
                case FSciIoReport_MemLastReportedOutputChannelState1Value__UNKNOWN__: return FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__UNKNOWN__;
                case FSciIoReport_MemLastReportedOutputChannelState1Value__NotPhysicallyDisturbed: return FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed; 
case FSciIoReport_MemLastReportedOutputChannelState1Value__PhysicallyDisturbed: return FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__PhysicallyDisturbed;
                default: abort();
            }
        }
static FSciIoReport_D7inDetectedInputChannelStatenValue map_MemLastReportedInputChannelStaten_to_D7inDetectedInputChannelStaten(FSciIoReport_MemLastReportedInputChannelStatenValue value) {
            switch (value) {
                case FSciIoReport_MemLastReportedInputChannelStatenValue__NULL__: return FSciIoReport_D7inDetectedInputChannelStatenValue__NULL__;
                case FSciIoReport_MemLastReportedInputChannelStatenValue__UNKNOWN__: return FSciIoReport_D7inDetectedInputChannelStatenValue__UNKNOWN__;
                case FSciIoReport_MemLastReportedInputChannelStatenValue__SwitchedOn: return FSciIoReport_D7inDetectedInputChannelStatenValue__SwitchedOn; 
case FSciIoReport_MemLastReportedInputChannelStatenValue__SwitchedOff: return FSciIoReport_D7inDetectedInputChannelStatenValue__SwitchedOff; 
case FSciIoReport_MemLastReportedInputChannelStatenValue__Disturbed: return FSciIoReport_D7inDetectedInputChannelStatenValue__Disturbed;
                default: abort();
            }
        }
static FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue map_MemLastReportedOutputChannelStaten_to_D9inMonitoredOutputChannelDisturbanceStaten(FSciIoReport_MemLastReportedOutputChannelStatenValue value) {
            switch (value) {
                case FSciIoReport_MemLastReportedOutputChannelStatenValue__NULL__: return FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__NULL__;
                case FSciIoReport_MemLastReportedOutputChannelStatenValue__UNKNOWN__: return FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__UNKNOWN__;
                case FSciIoReport_MemLastReportedOutputChannelStatenValue__NotPhysicallyDisturbed: return FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed; 
case FSciIoReport_MemLastReportedOutputChannelStatenValue__PhysicallyDisturbed: return FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__PhysicallyDisturbed;
                default: abort();
            }
        }

// Operations
static void Cop1InitialReportStatusOutputChannelStates(FSciIoReport *self , FSciIoReport_OutputChannelState1Value OutputChannelState1, FSciIoReport_OutputChannelStatenValue OutputChannelStaten) {
            if ((OutputChannelState1 == FSciIoReport_OutputChannelState1Value__NotPhysicallyDisturbed) && (OutputChannelStaten == FSciIoReport_OutputChannelStatenValue__NotPhysicallyDisturbed)) { 

  self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 = OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed; 
self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN = OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed;
  self->OutMsgStateOfOutputChannels__c6d6.HasMessage = 1; 
self->MemLastReportedOutputChannelState1 = FSciIoReport_MemLastReportedOutputChannelState1Value__NotPhysicallyDisturbed; 
self->MemLastReportedOutputChannelStaten = FSciIoReport_MemLastReportedOutputChannelStatenValue__NotPhysicallyDisturbed; 
} else if ((OutputChannelState1 == FSciIoReport_OutputChannelState1Value__PhysicallyDisturbed) && (OutputChannelStaten == FSciIoReport_OutputChannelStatenValue__PhysicallyDisturbed)) { 

  self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 = OutputChannelDisturbanceState__bed9__PhysicallyDisturbed; 
self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN = OutputChannelDisturbanceState__bed9__PhysicallyDisturbed;
  self->OutMsgStateOfOutputChannels__c6d6.HasMessage = 1; 
self->MemLastReportedOutputChannelState1 = FSciIoReport_MemLastReportedOutputChannelState1Value__PhysicallyDisturbed; 
self->MemLastReportedOutputChannelStaten = FSciIoReport_MemLastReportedOutputChannelStatenValue__PhysicallyDisturbed; 
} else if ((OutputChannelState1 == FSciIoReport_OutputChannelState1Value__PhysicallyDisturbed) && (OutputChannelStaten == FSciIoReport_OutputChannelStatenValue__NotPhysicallyDisturbed)) { 

  self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 = OutputChannelDisturbanceState__bed9__PhysicallyDisturbed; 
self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN = OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed;
  self->OutMsgStateOfOutputChannels__c6d6.HasMessage = 1; 
self->MemLastReportedOutputChannelState1 = FSciIoReport_MemLastReportedOutputChannelState1Value__PhysicallyDisturbed; 
self->MemLastReportedOutputChannelStaten = FSciIoReport_MemLastReportedOutputChannelStatenValue__NotPhysicallyDisturbed; 
} else if ((OutputChannelState1 == FSciIoReport_OutputChannelState1Value__NotPhysicallyDisturbed) && (OutputChannelStaten == FSciIoReport_OutputChannelStatenValue__PhysicallyDisturbed)) { 

  self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 = OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed; 
self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN = OutputChannelDisturbanceState__bed9__PhysicallyDisturbed;
  self->OutMsgStateOfOutputChannels__c6d6.HasMessage = 1; 
self->MemLastReportedOutputChannelState1 = FSciIoReport_MemLastReportedOutputChannelState1Value__NotPhysicallyDisturbed; 
self->MemLastReportedOutputChannelStaten = FSciIoReport_MemLastReportedOutputChannelStatenValue__PhysicallyDisturbed; 
}
            
        }
static void Cop2InitialReportStatusInputChannelStates(FSciIoReport *self , FSciIoReport_InputChannelState1Value InputChannelState1, FSciIoReport_InputChannelStatenValue InputChannelStaten) {
            if ((InputChannelState1 == FSciIoReport_InputChannelState1Value__SwitchedOn) && (InputChannelStaten == FSciIoReport_InputChannelStatenValue__SwitchedOn)) { 

  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOn; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOn;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1; 
self->MemLastReportedInputChannelState1 = FSciIoReport_MemLastReportedInputChannelState1Value__SwitchedOn; 
self->MemLastReportedInputChannelStaten = FSciIoReport_MemLastReportedInputChannelStatenValue__SwitchedOn; 
} else if ((InputChannelState1 == FSciIoReport_InputChannelState1Value__SwitchedOff) && (InputChannelStaten == FSciIoReport_InputChannelStatenValue__SwitchedOff)) { 

  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOff; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOff;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1; 
self->MemLastReportedInputChannelState1 = FSciIoReport_MemLastReportedInputChannelState1Value__SwitchedOff; 
self->MemLastReportedInputChannelStaten = FSciIoReport_MemLastReportedInputChannelStatenValue__SwitchedOff; 
} else if ((InputChannelState1 == FSciIoReport_InputChannelState1Value__Disturbed) && (InputChannelStaten == FSciIoReport_InputChannelStatenValue__Disturbed)) { 

  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__Disturbed; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__Disturbed;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1; 
self->MemLastReportedInputChannelState1 = FSciIoReport_MemLastReportedInputChannelState1Value__Disturbed; 
self->MemLastReportedInputChannelStaten = FSciIoReport_MemLastReportedInputChannelStatenValue__Disturbed; 
} else if ((InputChannelState1 == FSciIoReport_InputChannelState1Value__SwitchedOff) && (InputChannelStaten == FSciIoReport_InputChannelStatenValue__SwitchedOn)) { 

  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOff; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOn;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1; 
self->MemLastReportedInputChannelState1 = FSciIoReport_MemLastReportedInputChannelState1Value__SwitchedOff; 
self->MemLastReportedInputChannelStaten = FSciIoReport_MemLastReportedInputChannelStatenValue__SwitchedOn; 
} else if ((InputChannelState1 == FSciIoReport_InputChannelState1Value__SwitchedOn) && (InputChannelStaten == FSciIoReport_InputChannelStatenValue__SwitchedOff)) { 

  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOn; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOff;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1; 
self->MemLastReportedInputChannelState1 = FSciIoReport_MemLastReportedInputChannelState1Value__SwitchedOn; 
self->MemLastReportedInputChannelStaten = FSciIoReport_MemLastReportedInputChannelStatenValue__SwitchedOff; 
} else if ((InputChannelState1 == FSciIoReport_InputChannelState1Value__SwitchedOff) && (InputChannelStaten == FSciIoReport_InputChannelStatenValue__Disturbed)) { 

  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOff; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__Disturbed;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1; 
self->MemLastReportedInputChannelState1 = FSciIoReport_MemLastReportedInputChannelState1Value__SwitchedOff; 
self->MemLastReportedInputChannelStaten = FSciIoReport_MemLastReportedInputChannelStatenValue__Disturbed; 
} else if ((InputChannelState1 == FSciIoReport_InputChannelState1Value__SwitchedOn) && (InputChannelStaten == FSciIoReport_InputChannelStatenValue__Disturbed)) { 

  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOn; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__Disturbed;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1; 
self->MemLastReportedInputChannelState1 = FSciIoReport_MemLastReportedInputChannelState1Value__SwitchedOn; 
self->MemLastReportedInputChannelStaten = FSciIoReport_MemLastReportedInputChannelStatenValue__Disturbed; 
} else if ((InputChannelState1 == FSciIoReport_InputChannelState1Value__Disturbed) && (InputChannelStaten == FSciIoReport_InputChannelStatenValue__SwitchedOff)) { 

  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__Disturbed; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOff;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1; 
self->MemLastReportedInputChannelState1 = FSciIoReport_MemLastReportedInputChannelState1Value__Disturbed; 
self->MemLastReportedInputChannelStaten = FSciIoReport_MemLastReportedInputChannelStatenValue__SwitchedOff; 
} else if ((InputChannelState1 == FSciIoReport_InputChannelState1Value__Disturbed) && (InputChannelStaten == FSciIoReport_InputChannelStatenValue__SwitchedOn)) { 

  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__Disturbed; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOn;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1; 
self->MemLastReportedInputChannelState1 = FSciIoReport_MemLastReportedInputChannelState1Value__Disturbed; 
self->MemLastReportedInputChannelStaten = FSciIoReport_MemLastReportedInputChannelStatenValue__SwitchedOn; 
}
            
        }






void make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(FSciIoReport *self, FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__state_struct *region) {
    LOG("[FSciIoReport] Entering state SendingInputChannelReports in region root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates");
    region->state = FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports;
    
};


void make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates(FSciIoReport *self, FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__state_struct *x) {
    memset(x, 0, sizeof(FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__state_struct));
    
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, x); return;
}





void make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports(FSciIoReport *self, FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__state_struct *region) {
    LOG("[FSciIoReport] Entering state SendingOutputChannelReports in region root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates");
    region->state = FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports;
    
};


void make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates(FSciIoReport *self, FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__state_struct *x) {
    memset(x, 0, sizeof(FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__state_struct));
    
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports(self, x); return;
}



void make_state_FSciIoReport__root__ReportingLogicalChannelStates(FSciIoReport *self, FSciIoReport__root__state_struct *region) {
    LOG("[FSciIoReport] Entering state ReportingLogicalChannelStates in region root");
    region->state = FSciIoReport__root__ReportingLogicalChannelStates;
    make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates(self, &region->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates);
make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates(self, &region->ReportingLogicalChannelStates.ReportingLogicalOutputChannelStates);
};


void make_state_FSciIoReport__root__InterfaceConnectionNotEstablished(FSciIoReport *self, FSciIoReport__root__state_struct *region) {
    LOG("[FSciIoReport] Entering state InterfaceConnectionNotEstablished in region root");
    region->state = FSciIoReport__root__InterfaceConnectionNotEstablished;
    
};


void make_state_FSciIoReport__root(FSciIoReport *self, FSciIoReport__root__state_struct *x) {
    memset(x, 0, sizeof(FSciIoReport__root__state_struct));
    
                make_state_FSciIoReport__root__InterfaceConnectionNotEstablished(self, x); return;
}



        
        

        void transition_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(FSciIoReport *self, FSciIoReport__root__state_struct *x) {
            
            if (self->Change303.IsTriggered) {
                if ((!(self->D7inDetectedInputChannelState1.Value == map_MemLastReportedInputChannelState1_to_D7inDetectedInputChannelState1(self->MemLastReportedInputChannelState1))) || (!(self->D7inDetectedInputChannelStaten.Value == map_MemLastReportedInputChannelStaten_to_D7inDetectedInputChannelStaten(self->MemLastReportedInputChannelStaten)))) {
                Cop2InitialReportStatusInputChannelStates(self, self->D7inDetectedInputChannelState1.Value, self->D7inDetectedInputChannelStaten.Value);
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates); return;
            }
            }
if (self->Change437.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__Disturbed; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOff;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates); return;
            }
            }
if (self->Change438.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__Disturbed; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOn;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates); return;
            }
            }
if (self->Change439.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__Disturbed; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__Disturbed;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates); return;
            }
            }
if (self->Change441.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOff; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOff;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates); return;
            }
            }
if (self->Change443.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOff; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__Disturbed;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates); return;
            }
            }
if (self->Change445.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOn; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__Disturbed;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates); return;
            }
            }
if (self->Change442.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOn; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOn;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates); return;
            }
            }
if (self->Change440.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOn; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOff;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates); return;
            }
            }
if (self->Change444.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfInputChannels__8132.Value.ResportedInputState1 = InputChannelState__a4d2__SwitchedOff; 
self->OutMsgStateOfInputChannels__8132.Value.ResportedInputStateN = InputChannelState__a4d2__SwitchedOn;
  self->OutMsgStateOfInputChannels__8132.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates); return;
            }
            }
        }
        

        void transition_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates(FSciIoReport *self, FSciIoReport__root__state_struct *x) {
            switch (x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates.state) {
                case FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports:
                    transition_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(self, x);
                    break;
            }
        }
        

        

        void transition_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports(FSciIoReport *self, FSciIoReport__root__state_struct *x) {
            
            if (self->Change304.IsTriggered) {
                if ((!(self->D9inMonitoredOutputChannelDisturbanceState1.Value == map_MemLastReportedOutputChannelState1_to_D9inMonitoredOutputChannelDisturbanceState1(self->MemLastReportedOutputChannelState1))) || (!(self->D9inMonitoredOutputChannelDisturbanceStaten.Value == map_MemLastReportedOutputChannelStaten_to_D9inMonitoredOutputChannelDisturbanceStaten(self->MemLastReportedOutputChannelStaten)))) {
                Cop1InitialReportStatusOutputChannelStates(self, self->D9inMonitoredOutputChannelDisturbanceState1.Value, self->D9inMonitoredOutputChannelDisturbanceStaten.Value);
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalOutputChannelStates); return;
            }
            }
if (self->Change499.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 = OutputChannelDisturbanceState__bed9__PhysicallyDisturbed; 
self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN = OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed;
  self->OutMsgStateOfOutputChannels__c6d6.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalOutputChannelStates); return;
            }
            }
if (self->Change494.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 = OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed; 
self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN = OutputChannelDisturbanceState__bed9__PhysicallyDisturbed;
  self->OutMsgStateOfOutputChannels__c6d6.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalOutputChannelStates); return;
            }
            }
if (self->Change492.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 = OutputChannelDisturbanceState__bed9__PhysicallyDisturbed; 
self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN = OutputChannelDisturbanceState__bed9__PhysicallyDisturbed;
  self->OutMsgStateOfOutputChannels__c6d6.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalOutputChannelStates); return;
            }
            }
if (self->Change497.IsTriggered) {
                if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established) {
                
  self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 = OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed; 
self->OutMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN = OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed;
  self->OutMsgStateOfOutputChannels__c6d6.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports(self, &x->ReportingLogicalChannelStates.ReportingLogicalOutputChannelStates); return;
            }
            }
        }
        

        void transition_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates(FSciIoReport *self, FSciIoReport__root__state_struct *x) {
            switch (x->ReportingLogicalChannelStates.ReportingLogicalOutputChannelStates.state) {
                case FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports:
                    transition_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports(self, x);
                    break;
            }
        }
        

        void transition_from_FSciIoReport__root__ReportingLogicalChannelStates(FSciIoReport *self, FSciIoReport__root__state_struct *x) {
            transition_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates(self, x);
transition_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates(self, x);
            if (self->Change313.IsTriggered) {
                
                make_state_FSciIoReport__root__InterfaceConnectionNotEstablished(self, x); return;
            }
        }
        
void transition_from_FSciIoReport__root__InterfaceConnectionNotEstablished(FSciIoReport *self, FSciIoReport__root__state_struct *x) {
            
            if (self->InStartStatusReport__1e4e.HasMessage) {
                Cop1InitialReportStatusOutputChannelStates(self, self->D9inMonitoredOutputChannelDisturbanceState1.Value, self->D9inMonitoredOutputChannelDisturbanceStaten.Value);
Cop2InitialReportStatusInputChannelStates(self, self->D7inDetectedInputChannelState1.Value, self->D7inDetectedInputChannelStaten.Value);

  
  self->OutStatusReportCompleted__b457.HasMessage = 1;
                make_state_FSciIoReport__root__ReportingLogicalChannelStates(self, x); return;
            }
        }
        

        void transition_from_FSciIoReport__root(FSciIoReport *self, FSciIoReport__root__state_struct *x) {
            switch (x->state) {
                case FSciIoReport__root__ReportingLogicalChannelStates:
                    transition_from_FSciIoReport__root__ReportingLogicalChannelStates(self, x);
                    break;
case FSciIoReport__root__InterfaceConnectionNotEstablished:
                    transition_from_FSciIoReport__root__InterfaceConnectionNotEstablished(self, x);
                    break;
            }
        }
        

static void evaluateChangeEvents(FSciIoReport *self) {
    self->Change303.IsTriggered = IsTriggered(MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established));
self->Change437.IsTriggered = IsTriggered(AndChange(MakeChange(self->D7inDetectedInputChannelState1.IsSignalled, self->D7inDetectedInputChannelState1.Value == FSciIoReport_D7inDetectedInputChannelState1Value__Disturbed), MakeChange(self->D7inDetectedInputChannelStaten.IsSignalled, self->D7inDetectedInputChannelStaten.Value == FSciIoReport_D7inDetectedInputChannelStatenValue__SwitchedOff)));
self->Change438.IsTriggered = IsTriggered(AndChange(MakeChange(self->D7inDetectedInputChannelState1.IsSignalled, self->D7inDetectedInputChannelState1.Value == FSciIoReport_D7inDetectedInputChannelState1Value__Disturbed), MakeChange(self->D7inDetectedInputChannelStaten.IsSignalled, self->D7inDetectedInputChannelStaten.Value == FSciIoReport_D7inDetectedInputChannelStatenValue__SwitchedOn)));
self->Change439.IsTriggered = IsTriggered(AndChange(MakeChange(self->D7inDetectedInputChannelState1.IsSignalled, self->D7inDetectedInputChannelState1.Value == FSciIoReport_D7inDetectedInputChannelState1Value__Disturbed), MakeChange(self->D7inDetectedInputChannelStaten.IsSignalled, self->D7inDetectedInputChannelStaten.Value == FSciIoReport_D7inDetectedInputChannelStatenValue__Disturbed)));
self->Change441.IsTriggered = IsTriggered(AndChange(MakeChange(self->D7inDetectedInputChannelState1.IsSignalled, self->D7inDetectedInputChannelState1.Value == FSciIoReport_D7inDetectedInputChannelState1Value__SwitchedOff), MakeChange(self->D7inDetectedInputChannelStaten.IsSignalled, self->D7inDetectedInputChannelStaten.Value == FSciIoReport_D7inDetectedInputChannelStatenValue__SwitchedOff)));
self->Change443.IsTriggered = IsTriggered(AndChange(MakeChange(self->D7inDetectedInputChannelState1.IsSignalled, self->D7inDetectedInputChannelState1.Value == FSciIoReport_D7inDetectedInputChannelState1Value__SwitchedOff), MakeChange(self->D7inDetectedInputChannelStaten.IsSignalled, self->D7inDetectedInputChannelStaten.Value == FSciIoReport_D7inDetectedInputChannelStatenValue__Disturbed)));
self->Change445.IsTriggered = IsTriggered(AndChange(MakeChange(self->D7inDetectedInputChannelState1.IsSignalled, self->D7inDetectedInputChannelState1.Value == FSciIoReport_D7inDetectedInputChannelState1Value__SwitchedOn), MakeChange(self->D7inDetectedInputChannelStaten.IsSignalled, self->D7inDetectedInputChannelStaten.Value == FSciIoReport_D7inDetectedInputChannelStatenValue__Disturbed)));
self->Change442.IsTriggered = IsTriggered(AndChange(MakeChange(self->D7inDetectedInputChannelState1.IsSignalled, self->D7inDetectedInputChannelState1.Value == FSciIoReport_D7inDetectedInputChannelState1Value__SwitchedOn), MakeChange(self->D7inDetectedInputChannelStaten.IsSignalled, self->D7inDetectedInputChannelStaten.Value == FSciIoReport_D7inDetectedInputChannelStatenValue__SwitchedOn)));
self->Change440.IsTriggered = IsTriggered(AndChange(MakeChange(self->D7inDetectedInputChannelState1.IsSignalled, self->D7inDetectedInputChannelState1.Value == FSciIoReport_D7inDetectedInputChannelState1Value__SwitchedOn), MakeChange(self->D7inDetectedInputChannelStaten.IsSignalled, self->D7inDetectedInputChannelStaten.Value == FSciIoReport_D7inDetectedInputChannelStatenValue__SwitchedOff)));
self->Change444.IsTriggered = IsTriggered(AndChange(MakeChange(self->D7inDetectedInputChannelState1.IsSignalled, self->D7inDetectedInputChannelState1.Value == FSciIoReport_D7inDetectedInputChannelState1Value__SwitchedOff), MakeChange(self->D7inDetectedInputChannelStaten.IsSignalled, self->D7inDetectedInputChannelStaten.Value == FSciIoReport_D7inDetectedInputChannelStatenValue__SwitchedOn)));
self->Change304.IsTriggered = IsTriggered(MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established));
self->Change499.IsTriggered = IsTriggered(AndChange(MakeChange(self->D9inMonitoredOutputChannelDisturbanceState1.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceState1.Value == FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__PhysicallyDisturbed), MakeChange(self->D9inMonitoredOutputChannelDisturbanceStaten.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceStaten.Value == FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed)));
self->Change494.IsTriggered = IsTriggered(AndChange(MakeChange(self->D9inMonitoredOutputChannelDisturbanceState1.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceState1.Value == FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed), MakeChange(self->D9inMonitoredOutputChannelDisturbanceStaten.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceStaten.Value == FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__PhysicallyDisturbed)));
self->Change492.IsTriggered = IsTriggered(AndChange(MakeChange(self->D9inMonitoredOutputChannelDisturbanceState1.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceState1.Value == FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__PhysicallyDisturbed), MakeChange(self->D9inMonitoredOutputChannelDisturbanceStaten.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceStaten.Value == FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__PhysicallyDisturbed)));
self->Change497.IsTriggered = IsTriggered(AndChange(MakeChange(self->D9inMonitoredOutputChannelDisturbanceState1.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceState1.Value == FSciIoReport_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed), MakeChange(self->D9inMonitoredOutputChannelDisturbanceStaten.IsSignalled, self->D9inMonitoredOutputChannelDisturbanceStaten.Value == FSciIoReport_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed)));
self->Change313.IsTriggered = IsTriggered(OrChange(OrChange(MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__ReadyForPdiNoScp), MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__ReadyForPdi)), MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Suspended)));
}

static void resetOutputs(FSciIoReport *self) {
    self->OutMsgStateOfOutputChannels__c6d6.HasMessage = false;
self->OutMsgStateOfInputChannels__8132.HasMessage = false;
self->OutStatusReportCompleted__b457.HasMessage = false;

    

    
}

static void resetTriggers(FSciIoReport *self) {
    self->InStartStatusReport__1e4e.HasMessage = false;

    

    self->D7inDetectedInputChannelState1.IsSignalled = false;
self->D9inMonitoredOutputChannelDisturbanceState1.IsSignalled = false;
self->D50inPdiConnectionState.IsSignalled = false;
self->D7inDetectedInputChannelStaten.IsSignalled = false;
self->D9inMonitoredOutputChannelDisturbanceStaten.IsSignalled = false;

    
}

void transition_FSciIoReport(FSciIoReport *self) {
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FSciIoReport__root(self, &self->state);
    resetTriggers(self);
}

void new_FSciIoReport(FSciIoReport *self) {
    make_state_FSciIoReport__root(self, &self->state);
}
