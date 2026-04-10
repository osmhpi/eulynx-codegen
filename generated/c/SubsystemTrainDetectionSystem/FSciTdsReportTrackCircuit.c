
#include "FSciTdsReportTrackCircuit.h"

// Value Conversion Functions



// Operations








void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomOk(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state PomOk in region root__ReportingOccupancyStatus__root__Vacant__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomOk;
    
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomNok(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state PomNok in region root__ReportingOccupancyStatus__root__Vacant__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomNok;
    
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__WithoutPom(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state WithoutPom in region root__ReportingOccupancyStatus__root__Vacant__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__WithoutPom;
    
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__state_struct *x) {
    memset(x, 0, sizeof(FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__state_struct));
    
                    if (self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyNok) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Vacant; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Nok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__NotApplicable;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomNok(self, x); return;
            }
if (self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyOk) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Vacant; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Ok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__NotApplicable;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomOk(self, x); return;
            }
else {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Vacant; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__NotApplicable;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__WithoutPom(self, x); return;
            }
}





void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomNok(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state PomNok in region root__ReportingOccupancyStatus__root__Occupied__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomNok;
    
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomOk(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state PomOk in region root__ReportingOccupancyStatus__root__Occupied__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomOk;
    
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__WithoutPom(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state WithoutPom in region root__ReportingOccupancyStatus__root__Occupied__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__WithoutPom;
    
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__state_struct *x) {
    memset(x, 0, sizeof(FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__state_struct));
    
                    if (self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyNok) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Occupied; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Nok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__NotApplicable;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomNok(self, x); return;
            }
if (self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyOk) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Occupied; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Ok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__NotApplicable;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomOk(self, x); return;
            }
else {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Occupied; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__NotApplicable;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__WithoutPom(self, x); return;
            }
}





void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomOk(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state PomOk in region root__ReportingOccupancyStatus__root__Disturbed__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomOk;
    
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomNok(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state PomNok in region root__ReportingOccupancyStatus__root__Disturbed__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomNok;
    
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__WithoutPom(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state WithoutPom in region root__ReportingOccupancyStatus__root__Disturbed__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__WithoutPom;
    
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__state_struct *x) {
    memset(x, 0, sizeof(FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__state_struct));
    
                    if (self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyNok) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Disturbed; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Nok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__TechnicalFailure;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomNok(self, x); return;
            }
if (self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyOk) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Disturbed; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Ok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__TechnicalFailure;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomOk(self, x); return;
            }
else {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Disturbed; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__TechnicalFailure;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__WithoutPom(self, x); return;
            }
}



void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Waiting(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state Waiting in region root__ReportingOccupancyStatus__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Waiting;
    
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state Vacant in region root__ReportingOccupancyStatus__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant;
    make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root(self, &region->Vacant.root);
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state Occupied in region root__ReportingOccupancyStatus__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied;
    make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root(self, &region->Occupied.root);
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state Disturbed in region root__ReportingOccupancyStatus__root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed;
    make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root(self, &region->Disturbed.root);
};


void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state_struct *x) {
    memset(x, 0, sizeof(FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__state_struct));
    
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Waiting(self, x); return;
}



void make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *region) {
    LOG("[FSciTdsReportTrackCircuit] Entering state ReportingOccupancyStatus in region root");
    region->state = FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus;
    make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root(self, &region->ReportingOccupancyStatus.root);
};


void make_state_FSciTdsReportTrackCircuit__root(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
    memset(x, 0, sizeof(FSciTdsReportTrackCircuit__root__state_struct));
    
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus(self, x); return;
}



        
        
        

        void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomOk(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            
            if (self->Change270.IsTriggered) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Vacant; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Nok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__NotApplicable;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomNok(self, &x->ReportingOccupancyStatus.root.Vacant.root); return;
            }
        }
        
void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomNok(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            
            if (self->Change273.IsTriggered) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Vacant; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Ok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__NotApplicable;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomOk(self, &x->ReportingOccupancyStatus.root.Vacant.root); return;
            }
        }
        
void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__WithoutPom(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            
            
        }
        

        void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            switch (x->ReportingOccupancyStatus.root.Vacant.root.state) {
                case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomOk:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomOk(self, x);
                    break;
case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomNok:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomNok(self, x);
                    break;
case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__WithoutPom:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__WithoutPom(self, x);
                    break;
            }
        }
        

        

        void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomNok(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            
            if (self->Change274.IsTriggered) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Occupied; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Ok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__NotApplicable;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomOk(self, &x->ReportingOccupancyStatus.root.Occupied.root); return;
            }
        }
        
void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomOk(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            
            if (self->Change271.IsTriggered) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Occupied; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Nok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__NotApplicable;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomNok(self, &x->ReportingOccupancyStatus.root.Occupied.root); return;
            }
        }
        
void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__WithoutPom(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            
            
        }
        

        void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            switch (x->ReportingOccupancyStatus.root.Occupied.root.state) {
                case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomNok:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomNok(self, x);
                    break;
case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomOk:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomOk(self, x);
                    break;
case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__WithoutPom:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__WithoutPom(self, x);
                    break;
            }
        }
        

        

        void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomOk(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            
            if (self->Change272.IsTriggered) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Disturbed; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Nok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__TechnicalFailure;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomNok(self, &x->ReportingOccupancyStatus.root.Disturbed.root); return;
            }
        }
        
void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomNok(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            
            if (self->Change275.IsTriggered) {
                
  self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus = OccupancyStatus__65fa__Disturbed; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedAbilityToBeForcedToClear = AbilityToBeForcedToClear__8b12__NotAble; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus = PomStatus__d74a__Ok; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.FillingLevel = 0; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedDisturbanceStatus = DisturbanceStatus__fd65__NotApplicable; 
self->OutMsgTvpsOccupancyStatus__b4e1.Value.ReportedChangeTrigger = ChangeTrigger__de2d__TechnicalFailure;
  self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = 1;
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomOk(self, &x->ReportingOccupancyStatus.root.Disturbed.root); return;
            }
        }
        
void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__WithoutPom(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            
            
        }
        

        void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            switch (x->ReportingOccupancyStatus.root.Disturbed.root.state) {
                case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomOk:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomOk(self, x);
                    break;
case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomNok:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomNok(self, x);
                    break;
case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__WithoutPom:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__WithoutPom(self, x);
                    break;
            }
        }
        

        void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Waiting(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            
            if (self->InStartStatusReport__1e4e.HasMessage) {
                
                    if (self->D45inReportedTvpsOccupancyStatus.Value == FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateOccupied) {
                
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied(self, &x->ReportingOccupancyStatus.root); return;
            }
if (self->D45inReportedTvpsOccupancyStatus.Value == FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateVacant) {
                
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant(self, &x->ReportingOccupancyStatus.root); return;
            }
else {
                
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed(self, &x->ReportingOccupancyStatus.root); return;
            }
            }
        }
        
void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root(self, x);
            if (self->Change265.IsTriggered) {
                
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied(self, &x->ReportingOccupancyStatus.root); return;
            }
if (self->Change267.IsTriggered) {
                
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed(self, &x->ReportingOccupancyStatus.root); return;
            }
        }
        
void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root(self, x);
            if (self->Change268.IsTriggered) {
                
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed(self, &x->ReportingOccupancyStatus.root); return;
            }
if (self->Change269.IsTriggered) {
                
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant(self, &x->ReportingOccupancyStatus.root); return;
            }
        }
        
void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root(self, x);
            if (self->Change266.IsTriggered) {
                
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied(self, &x->ReportingOccupancyStatus.root); return;
            }
if (self->Change264.IsTriggered) {
                
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant(self, &x->ReportingOccupancyStatus.root); return;
            }
        }
        

        void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            switch (x->ReportingOccupancyStatus.root.state) {
                case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Waiting:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Waiting(self, x);
                    break;
case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant(self, x);
                    break;
case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied(self, x);
                    break;
case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed(self, x);
                    break;
            }
        }
        

        void transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root(self, x);
            if (self->Change310.IsTriggered) {
                
                make_state_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus(self, x); return;
            }
        }
        

        void transition_from_FSciTdsReportTrackCircuit__root(FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x) {
            switch (x->state) {
                case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus:
                    transition_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus(self, x);
                    break;
            }
        }
        

static void evaluateChangeEvents(FSciTdsReportTrackCircuit *self) {
    self->Change270.IsTriggered = IsTriggered(MakeChange(self->D47inReportPomStatus.IsSignalled, self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyNok));
self->Change273.IsTriggered = IsTriggered(MakeChange(self->D47inReportPomStatus.IsSignalled, self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyOk));
self->Change274.IsTriggered = IsTriggered(MakeChange(self->D47inReportPomStatus.IsSignalled, self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyOk));
self->Change271.IsTriggered = IsTriggered(MakeChange(self->D47inReportPomStatus.IsSignalled, self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyNok));
self->Change272.IsTriggered = IsTriggered(MakeChange(self->D47inReportPomStatus.IsSignalled, self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyNok));
self->Change275.IsTriggered = IsTriggered(MakeChange(self->D47inReportPomStatus.IsSignalled, self->D47inReportPomStatus.Value == FSciTdsReportTrackCircuit_D47inReportPomStatusValue__PowerSupplyOk));
self->Change265.IsTriggered = IsTriggered(MakeChange(self->D45inReportedTvpsOccupancyStatus.IsSignalled, self->D45inReportedTvpsOccupancyStatus.Value == FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateOccupied));
self->Change267.IsTriggered = IsTriggered(MakeChange(self->D45inReportedTvpsOccupancyStatus.IsSignalled, self->D45inReportedTvpsOccupancyStatus.Value == FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateDisturbed));
self->Change268.IsTriggered = IsTriggered(MakeChange(self->D45inReportedTvpsOccupancyStatus.IsSignalled, self->D45inReportedTvpsOccupancyStatus.Value == FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateDisturbed));
self->Change269.IsTriggered = IsTriggered(MakeChange(self->D45inReportedTvpsOccupancyStatus.IsSignalled, self->D45inReportedTvpsOccupancyStatus.Value == FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateVacant));
self->Change266.IsTriggered = IsTriggered(MakeChange(self->D45inReportedTvpsOccupancyStatus.IsSignalled, self->D45inReportedTvpsOccupancyStatus.Value == FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateOccupied));
self->Change264.IsTriggered = IsTriggered(MakeChange(self->D45inReportedTvpsOccupancyStatus.IsSignalled, self->D45inReportedTvpsOccupancyStatus.Value == FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateVacant));
self->Change310.IsTriggered = IsTriggered(OrChange(OrChange(MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue__ReadyForPdiNoScp), MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue__ReadyForPdi)), MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciTdsReportTrackCircuit_D50inPdiConnectionStateValue__Suspended)));
}

static void resetOutputs(FSciTdsReportTrackCircuit *self) {
    self->OutMsgTvpsOccupancyStatus__b4e1.HasMessage = false;

    

    
}

static void resetTriggers(FSciTdsReportTrackCircuit *self) {
    self->InStartStatusReport__1e4e.HasMessage = false;

    

    self->D50inPdiConnectionState.IsSignalled = false;
self->D46inReportedAbilityToBeForcedToClear.IsSignalled = false;
self->D45inReportedTvpsOccupancyStatus.IsSignalled = false;
self->D47inReportPomStatus.IsSignalled = false;

    
}

void transition_FSciTdsReportTrackCircuit(FSciTdsReportTrackCircuit *self) {
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FSciTdsReportTrackCircuit__root(self, &self->state);
    resetTriggers(self);
}

void new_FSciTdsReportTrackCircuit(FSciTdsReportTrackCircuit *self) {
    make_state_FSciTdsReportTrackCircuit__root(self, &self->state);
}
