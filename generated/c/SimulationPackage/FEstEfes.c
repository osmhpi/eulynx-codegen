
#include "FEstEfes.h"

// Value Conversion Functions



// Operations
static void Cop1Init(FEstEfes *self ) {
            self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__Unknown;self->D52outEstEfesInitSubstate.IsSignalled = true;
            
        }







void make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate(FEstEfes *self, FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state_struct *region) {
    LOG("[FEstEfes] Entering state WaitingForDataUpdate in region root__OperatingVoltageSupplied__root__Initialising__root");
    region->state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate;
    
};


void make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdi(FEstEfes *self, FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state_struct *region) {
    LOG("[FEstEfes] Entering state WaitingForPdi in region root__OperatingVoltageSupplied__root__Initialising__root");
    region->state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdi;
    
};


void make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance(FEstEfes *self, FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state_struct *region) {
    LOG("[FEstEfes] Entering state WaitingForPdiOrMaintenance in region root__OperatingVoltageSupplied__root__Initialising__root");
    region->state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance;
    
};


void make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout(FEstEfes *self, FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state_struct *region) {
    LOG("[FEstEfes] Entering state WaitingForNoMaintenanceTimeout in region root__OperatingVoltageSupplied__root__Initialising__root");
    region->state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout;
    
};


void make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root(FEstEfes *self, FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state_struct *x) {
    memset(x, 0, sizeof(FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__state_struct));
    
                    if (self->D20inConMdmUsed.Value) {
                
  
  self->OutEstReadyForMaintenance__dd9a.HasMessage = 1;

  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;
self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForDataUpdate;self->D52outEstEfesInitSubstate.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate(self, x); return;
            }
if (!(self->D20inConMdmUsed.Value)) {
                
  
  self->OutReadyForPdiConnection__6bd3.HasMessage = 1;
self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForPdiOrMaintenance;self->D52outEstEfesInitSubstate.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance(self, x); return;
            }
}



void make_state_FEstEfes__root__OperatingVoltageSupplied__root__Booting(FEstEfes *self, FEstEfes__root__OperatingVoltageSupplied__root__state_struct *region) {
    LOG("[FEstEfes] Entering state Booting in region root__OperatingVoltageSupplied__root");
    region->state = FEstEfes__root__OperatingVoltageSupplied__root__Booting;
    
};


void make_state_FEstEfes__root__OperatingVoltageSupplied__root__Operational(FEstEfes *self, FEstEfes__root__OperatingVoltageSupplied__root__state_struct *region) {
    LOG("[FEstEfes] Entering state Operational in region root__OperatingVoltageSupplied__root");
    region->state = FEstEfes__root__OperatingVoltageSupplied__root__Operational;
    
};


void make_state_FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode(FEstEfes *self, FEstEfes__root__OperatingVoltageSupplied__root__state_struct *region) {
    LOG("[FEstEfes] Entering state FallbackMode in region root__OperatingVoltageSupplied__root");
    region->state = FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode;
    
};


void make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising(FEstEfes *self, FEstEfes__root__OperatingVoltageSupplied__root__state_struct *region) {
    LOG("[FEstEfes] Entering state Initialising in region root__OperatingVoltageSupplied__root");
    region->state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising;
    make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root(self, &region->Initialising.root);
};


void make_state_FEstEfes__root__OperatingVoltageSupplied__root(FEstEfes *self, FEstEfes__root__OperatingVoltageSupplied__root__state_struct *x) {
    memset(x, 0, sizeof(FEstEfes__root__OperatingVoltageSupplied__root__state_struct));
    self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__Booting;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Booting(self, x); return;
}



void make_state_FEstEfes__root__NoOperatingVoltage(FEstEfes *self, FEstEfes__root__state_struct *region) {
    LOG("[FEstEfes] Entering state NoOperatingVoltage in region root");
    region->state = FEstEfes__root__NoOperatingVoltage;
    
};


void make_state_FEstEfes__root__OperatingVoltageSupplied(FEstEfes *self, FEstEfes__root__state_struct *region) {
    LOG("[FEstEfes] Entering state OperatingVoltageSupplied in region root");
    region->state = FEstEfes__root__OperatingVoltageSupplied;
    make_state_FEstEfes__root__OperatingVoltageSupplied__root(self, &region->OperatingVoltageSupplied.root);
};


void make_state_FEstEfes__root(FEstEfes *self, FEstEfes__root__state_struct *x) {
    memset(x, 0, sizeof(FEstEfes__root__state_struct));
    Cop1Init(self);
self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__NoOperatingVoltage;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__NoOperatingVoltage(self, x); return;
}



        
        
        

        void transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate(FEstEfes *self, FEstEfes__root__state_struct *x) {
            
            if (self->InDataUpdateFinished__0937.HasMessage) {
                
  
  self->OutReadyForPdiConnection__6bd3.HasMessage = 1;
self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForPdiOrMaintenance;self->D52outEstEfesInitSubstate.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance(self, &x->OperatingVoltageSupplied.root.Initialising.root); return;
            }
        }
        
void transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdi(FEstEfes *self, FEstEfes__root__state_struct *x) {
            
            if (self->InPdiConnectionClosed__d803.HasMessage) {
                self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForPdiOrMaintenance;self->D52outEstEfesInitSubstate.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance(self, &x->OperatingVoltageSupplied.root.Initialising.root); return;
            }
if (self->InPdiConnectionEstablished__4cbf.HasMessage) {
                self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__Operational;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Operational(self, &x->OperatingVoltageSupplied.root); return;
            }
if (self->InPdiReleasedForMaintenance__3f7c.HasMessage) {
                if (!(self->D20inConMdmUsed.Value)) {
                self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForNoMaintenanceTimeout;self->D52outEstEfesInitSubstate.IsSignalled = true;

  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout(self, &x->OperatingVoltageSupplied.root.Initialising.root); return;
            }
            }
if (self->InPdiReleasedForMaintenance__3f7c.HasMessage) {
                if (self->D20inConMdmUsed.Value) {
                
  
  self->OutEstReadyForMaintenance__dd9a.HasMessage = 1;

  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;
self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForDataUpdate;self->D52outEstEfesInitSubstate.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate(self, &x->OperatingVoltageSupplied.root.Initialising.root); return;
            }
            }
        }
        
void transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance(FEstEfes *self, FEstEfes__root__state_struct *x) {
            
            if (self->InMdmCommandedMaintenance__a992.HasMessage) {
                if (self->D20inConMdmUsed.Value) {
                
  
  self->OutEstReadyForMaintenance__dd9a.HasMessage = 1;

  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;
self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForDataUpdate;self->D52outEstEfesInitSubstate.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate(self, &x->OperatingVoltageSupplied.root.Initialising.root); return;
            }
            }
if (self->InPdiConnectionStarted__f9c3.HasMessage) {
                self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForPdi;self->D52outEstEfesInitSubstate.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdi(self, &x->OperatingVoltageSupplied.root.Initialising.root); return;
            }
        }
        
void transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout(FEstEfes *self, FEstEfes__root__state_struct *x) {
            
            if (self->Time13.IsTimeoutExpired) {
                
  
  self->OutReadyForPdiConnection__6bd3.HasMessage = 1;
self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForPdiOrMaintenance;self->D52outEstEfesInitSubstate.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance(self, &x->OperatingVoltageSupplied.root.Initialising.root); return;
            }
        }
        

        void transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root(FEstEfes *self, FEstEfes__root__state_struct *x) {
            switch (x->OperatingVoltageSupplied.root.Initialising.root.state) {
                case FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate:
                    transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate(self, x);
                    break;
case FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdi:
                    transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdi(self, x);
                    break;
case FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance:
                    transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance(self, x);
                    break;
case FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout:
                    transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout(self, x);
                    break;
            }
        }
        

        void transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Booting(FEstEfes *self, FEstEfes__root__state_struct *x) {
            
            if (self->Change1191.IsTriggered) {
                self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__Initialising;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising(self, &x->OperatingVoltageSupplied.root); return;
            }
if (self->Change1226.IsTriggered) {
                self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__FallbackMode;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode(self, &x->OperatingVoltageSupplied.root); return;
            }
if (self->Change1266.IsTriggered) {
                self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__FallbackMode;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode(self, &x->OperatingVoltageSupplied.root); return;
            }
        }
        
void transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Operational(FEstEfes *self, FEstEfes__root__state_struct *x) {
            
            if (self->InPdiConnectionClosed__d803.HasMessage) {
                self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForPdiOrMaintenance;self->D52outEstEfesInitSubstate.IsSignalled = true;
                        x->OperatingVoltageSupplied.root.state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising;
                        make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance(self, &x->OperatingVoltageSupplied.root.Initialising.root); return;
            }
if (self->InPdiReleasedForMaintenance__3f7c.HasMessage) {
                if (self->D20inConMdmUsed.Value) {
                
  
  self->OutEstReadyForMaintenance__dd9a.HasMessage = 1;

  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;
self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForDataUpdate;self->D52outEstEfesInitSubstate.IsSignalled = true;
                        x->OperatingVoltageSupplied.root.state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising;
                        make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate(self, &x->OperatingVoltageSupplied.root.Initialising.root); return;
            }
            }
if (self->InPdiReleasedForMaintenance__3f7c.HasMessage) {
                if (!(self->D20inConMdmUsed.Value)) {
                self->D52outEstEfesInitSubstate.Value = FEstEfes_D52outEstEfesInitSubstateValue__WaitingForNoMaintenanceTimeout;self->D52outEstEfesInitSubstate.IsSignalled = true;

  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;
                        x->OperatingVoltageSupplied.root.state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising;
                        make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout(self, &x->OperatingVoltageSupplied.root.Initialising.root); return;
            }
            }
if (self->Change1143.IsTriggered) {
                
  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;
self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__Booting;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Booting(self, &x->OperatingVoltageSupplied.root); return;
            }
if (self->Change1224.IsTriggered) {
                
  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;
self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__FallbackMode;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode(self, &x->OperatingVoltageSupplied.root); return;
            }
        }
        
void transition_from_FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode(FEstEfes *self, FEstEfes__root__state_struct *x) {
            
            if (self->InMdmTriggeredReset__00d0.HasMessage) {
                self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__Booting;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Booting(self, &x->OperatingVoltageSupplied.root); return;
            }
if (self->Change1144.IsTriggered) {
                self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__Booting;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Booting(self, &x->OperatingVoltageSupplied.root); return;
            }
        }
        
void transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising(FEstEfes *self, FEstEfes__root__state_struct *x) {
            transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root(self, x);
            if (self->InRebootRequired__bc8e.HasMessage) {
                if (self->D20inConMdmUsed.Value) {
                
  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;
self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__Booting;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Booting(self, &x->OperatingVoltageSupplied.root); return;
            }
            }
if (self->Change1145.IsTriggered) {
                
  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;

  
  self->OutDataUpdateStop__cf0d.HasMessage = 1;
self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__Booting;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__Booting(self, &x->OperatingVoltageSupplied.root); return;
            }
if (self->Change1225.IsTriggered) {
                
  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;

  
  self->OutDataUpdateStop__cf0d.HasMessage = 1;
self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__FallbackMode;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode(self, &x->OperatingVoltageSupplied.root); return;
            }
        }
        

        void transition_from_FEstEfes__root__OperatingVoltageSupplied__root(FEstEfes *self, FEstEfes__root__state_struct *x) {
            switch (x->OperatingVoltageSupplied.root.state) {
                case FEstEfes__root__OperatingVoltageSupplied__root__Booting:
                    transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Booting(self, x);
                    break;
case FEstEfes__root__OperatingVoltageSupplied__root__Operational:
                    transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Operational(self, x);
                    break;
case FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode:
                    transition_from_FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode(self, x);
                    break;
case FEstEfes__root__OperatingVoltageSupplied__root__Initialising:
                    transition_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising(self, x);
                    break;
            }
        }
        

        void transition_from_FEstEfes__root__NoOperatingVoltage(FEstEfes *self, FEstEfes__root__state_struct *x) {
            
            if (self->Change869.IsTriggered) {
                
                make_state_FEstEfes__root__OperatingVoltageSupplied(self, x); return;
            }
        }
        
void transition_from_FEstEfes__root__OperatingVoltageSupplied(FEstEfes *self, FEstEfes__root__state_struct *x) {
            transition_from_FEstEfes__root__OperatingVoltageSupplied__root(self, x);
            if (self->Change1060.IsTriggered) {
                
  
  self->OutNotreadyForPdiConnection__0b73.HasMessage = 1;

  
  self->OutDataUpdateStop__cf0d.HasMessage = 1;
self->D51outEstEfesState.Value = FEstEfes_D51outEstEfesStateValue__NoOperatingVoltage;self->D51outEstEfesState.IsSignalled = true;
                make_state_FEstEfes__root__NoOperatingVoltage(self, x); return;
            }
        }
        

        void transition_from_FEstEfes__root(FEstEfes *self, FEstEfes__root__state_struct *x) {
            switch (x->state) {
                case FEstEfes__root__NoOperatingVoltage:
                    transition_from_FEstEfes__root__NoOperatingVoltage(self, x);
                    break;
case FEstEfes__root__OperatingVoltageSupplied:
                    transition_from_FEstEfes__root__OperatingVoltageSupplied(self, x);
                    break;
            }
        }
        

static void evaluateChangeEvents(FEstEfes *self) {
    self->Change1191.IsTriggered = self->T4inBooted.IsTriggered;
self->Change1226.IsTriggered = self->T5inSilNotFulfilled.IsTriggered;
self->Change1266.IsTriggered = self->T7inInvalidOrMissingBasicData.IsTriggered;
self->Change1143.IsTriggered = self->T3inReset.IsTriggered;
self->Change1224.IsTriggered = self->T5inSilNotFulfilled.IsTriggered;
self->Change1144.IsTriggered = self->T3inReset.IsTriggered;
self->Change1145.IsTriggered = self->T3inReset.IsTriggered;
self->Change1225.IsTriggered = self->T5inSilNotFulfilled.IsTriggered;
self->Change869.IsTriggered = self->T1inPowerOnDetected.IsTriggered;
self->Change1060.IsTriggered = self->T2inPowerOffDetected.IsTriggered;
}

static void resetOutputs(FEstEfes *self) {
    self->OutEstReadyForMaintenance__dd9a.HasMessage = false;
self->OutNotreadyForPdiConnection__0b73.HasMessage = false;
self->OutReadyForPdiConnection__6bd3.HasMessage = false;
self->OutDataUpdateStop__cf0d.HasMessage = false;

    

    self->D51outEstEfesState.IsSignalled = false;
self->D52outEstEfesInitSubstate.IsSignalled = false;
}

static void resetTriggers(FEstEfes *self) {
    self->InDataUpdateFinished__0937.HasMessage = false;
self->InPdiConnectionClosed__d803.HasMessage = false;
self->InPdiConnectionEstablished__4cbf.HasMessage = false;
self->InPdiReleasedForMaintenance__3f7c.HasMessage = false;
self->InMdmCommandedMaintenance__a992.HasMessage = false;
self->InPdiConnectionStarted__f9c3.HasMessage = false;
self->InMdmTriggeredReset__00d0.HasMessage = false;
self->InRebootRequired__bc8e.HasMessage = false;

    self->T1inPowerOnDetected.IsTriggered = false;
self->T2inPowerOffDetected.IsTriggered = false;
self->T3inReset.IsTriggered = false;
self->T4inBooted.IsTriggered = false;
self->T5inSilNotFulfilled.IsTriggered = false;
self->T7inInvalidOrMissingBasicData.IsTriggered = false;

    self->D20inConMdmUsed.IsSignalled = false;
self->D21inConTmaxNoMaintenance.IsSignalled = false;

    self->Time13.IsTimeoutExpired = false;
}

void transition_FEstEfes(FEstEfes *self) {
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FEstEfes__root(self, &self->state);
    resetTriggers(self);
}

void new_FEstEfes(FEstEfes *self) {
    make_state_FEstEfes__root(self, &self->state);
}
