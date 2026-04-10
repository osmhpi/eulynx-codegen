
#include "FSciTdsReportTdp.h"

// Value Conversion Functions



// Operations








void make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__InRefenceDirection(FSciTdsReportTdp *self, FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__state_struct *region) {
    LOG("[FSciTdsReportTdp] Entering state InRefenceDirection in region root__ReportingTdpStatus__root__Passed__root");
    region->state = FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__InRefenceDirection;
    
};


void make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__AgainstRefenceDirection(FSciTdsReportTdp *self, FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__state_struct *region) {
    LOG("[FSciTdsReportTdp] Entering state AgainstRefenceDirection in region root__ReportingTdpStatus__root__Passed__root");
    region->state = FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__AgainstRefenceDirection;
    
};


void make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__WithoutDirection(FSciTdsReportTdp *self, FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__state_struct *region) {
    LOG("[FSciTdsReportTdp] Entering state WithoutDirection in region root__ReportingTdpStatus__root__Passed__root");
    region->state = FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__WithoutDirection;
    
};


void make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root(FSciTdsReportTdp *self, FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__state_struct *x) {
    memset(x, 0, sizeof(FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__state_struct));
    
                    if (self->D54intReportedTdpDirection.Value == FSciTdsReportTdp_D54intReportedTdpDirectionValue__AgainstReferenceDirection) {
                
  self->OutMsgTdpStatus__b6d9.Value.ReportedStateOfPassing = StateOfPassing__616f__Passed; 
self->OutMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing = DirectionOfPassing__a7c9__AgainstRefernceDirection;
  self->OutMsgTdpStatus__b6d9.HasMessage = 1;
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__AgainstRefenceDirection(self, x); return;
            }
if (self->D54intReportedTdpDirection.Value == FSciTdsReportTdp_D54intReportedTdpDirectionValue__ReferenceDirection) {
                
  self->OutMsgTdpStatus__b6d9.Value.ReportedStateOfPassing = StateOfPassing__616f__Passed; 
self->OutMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing = DirectionOfPassing__a7c9__ReferenceDirection;
  self->OutMsgTdpStatus__b6d9.HasMessage = 1;
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__InRefenceDirection(self, x); return;
            }
else {
                
  self->OutMsgTdpStatus__b6d9.Value.ReportedStateOfPassing = StateOfPassing__616f__Passed; 
self->OutMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing = DirectionOfPassing__a7c9__WithoutIndicatedDirection;
  self->OutMsgTdpStatus__b6d9.HasMessage = 1;
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__WithoutDirection(self, x); return;
            }
}



void make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Waiting(FSciTdsReportTdp *self, FSciTdsReportTdp__root__ReportingTdpStatus__root__state_struct *region) {
    LOG("[FSciTdsReportTdp] Entering state Waiting in region root__ReportingTdpStatus__root");
    region->state = FSciTdsReportTdp__root__ReportingTdpStatus__root__Waiting;
    
};


void make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed(FSciTdsReportTdp *self, FSciTdsReportTdp__root__ReportingTdpStatus__root__state_struct *region) {
    LOG("[FSciTdsReportTdp] Entering state NotPassed in region root__ReportingTdpStatus__root");
    region->state = FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed;
    
};


void make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed(FSciTdsReportTdp *self, FSciTdsReportTdp__root__ReportingTdpStatus__root__state_struct *region) {
    LOG("[FSciTdsReportTdp] Entering state Passed in region root__ReportingTdpStatus__root");
    region->state = FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed;
    make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root(self, &region->Passed.root);
};


void make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed(FSciTdsReportTdp *self, FSciTdsReportTdp__root__ReportingTdpStatus__root__state_struct *region) {
    LOG("[FSciTdsReportTdp] Entering state Disturbed in region root__ReportingTdpStatus__root");
    region->state = FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed;
    
};


void make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root(FSciTdsReportTdp *self, FSciTdsReportTdp__root__ReportingTdpStatus__root__state_struct *x) {
    memset(x, 0, sizeof(FSciTdsReportTdp__root__ReportingTdpStatus__root__state_struct));
    
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Waiting(self, x); return;
}



void make_state_FSciTdsReportTdp__root__ReportingTdpStatus(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *region) {
    LOG("[FSciTdsReportTdp] Entering state ReportingTdpStatus in region root");
    region->state = FSciTdsReportTdp__root__ReportingTdpStatus;
    make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root(self, &region->ReportingTdpStatus.root);
};


void make_state_FSciTdsReportTdp__root(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
    memset(x, 0, sizeof(FSciTdsReportTdp__root__state_struct));
    
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus(self, x); return;
}



        
        
        

        void transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__InRefenceDirection(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
            
            if (self->Change412.IsTriggered) {
                
  self->OutMsgTdpStatus__b6d9.Value.ReportedStateOfPassing = StateOfPassing__616f__Passed; 
self->OutMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing = DirectionOfPassing__a7c9__AgainstRefernceDirection;
  self->OutMsgTdpStatus__b6d9.HasMessage = 1;
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__AgainstRefenceDirection(self, &x->ReportingTdpStatus.root.Passed.root); return;
            }
        }
        
void transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__AgainstRefenceDirection(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
            
            if (self->Change413.IsTriggered) {
                
  self->OutMsgTdpStatus__b6d9.Value.ReportedStateOfPassing = StateOfPassing__616f__Passed; 
self->OutMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing = DirectionOfPassing__a7c9__ReferenceDirection;
  self->OutMsgTdpStatus__b6d9.HasMessage = 1;
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__InRefenceDirection(self, &x->ReportingTdpStatus.root.Passed.root); return;
            }
        }
        
void transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__WithoutDirection(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
            
            
        }
        

        void transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
            switch (x->ReportingTdpStatus.root.Passed.root.state) {
                case FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__InRefenceDirection:
                    transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__InRefenceDirection(self, x);
                    break;
case FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__AgainstRefenceDirection:
                    transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__AgainstRefenceDirection(self, x);
                    break;
case FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__WithoutDirection:
                    transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__WithoutDirection(self, x);
                    break;
            }
        }
        

        void transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Waiting(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
            
            if (self->InStartStatusReport__1e4e.HasMessage) {
                
                    if (self->D53inReportedTdpStatus.Value == FSciTdsReportTdp_D53inReportedTdpStatusValue__NotPassed) {
                
  self->OutMsgTdpStatus__b6d9.Value.ReportedStateOfPassing = StateOfPassing__616f__NotPassed; 
self->OutMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing = DirectionOfPassing__a7c9__WithoutIndicatedDirection;
  self->OutMsgTdpStatus__b6d9.HasMessage = 1;
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed(self, &x->ReportingTdpStatus.root); return;
            }
if (self->D53inReportedTdpStatus.Value == FSciTdsReportTdp_D53inReportedTdpStatusValue__Passed) {
                
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed(self, &x->ReportingTdpStatus.root); return;
            }
else {
                
  self->OutMsgTdpStatus__b6d9.Value.ReportedStateOfPassing = StateOfPassing__616f__Disturbed; 
self->OutMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing = DirectionOfPassing__a7c9__WithoutIndicatedDirection;
  self->OutMsgTdpStatus__b6d9.HasMessage = 1;
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed(self, &x->ReportingTdpStatus.root); return;
            }
            }
        }
        
void transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
            
            if (self->Change408.IsTriggered) {
                
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed(self, &x->ReportingTdpStatus.root); return;
            }
if (self->Change410.IsTriggered) {
                
  self->OutMsgTdpStatus__b6d9.Value.ReportedStateOfPassing = StateOfPassing__616f__Disturbed; 
self->OutMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing = DirectionOfPassing__a7c9__WithoutIndicatedDirection;
  self->OutMsgTdpStatus__b6d9.HasMessage = 1;
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed(self, &x->ReportingTdpStatus.root); return;
            }
        }
        
void transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
            transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root(self, x);
            if (self->Change406.IsTriggered) {
                
  self->OutMsgTdpStatus__b6d9.Value.ReportedStateOfPassing = StateOfPassing__616f__NotPassed; 
self->OutMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing = DirectionOfPassing__a7c9__WithoutIndicatedDirection;
  self->OutMsgTdpStatus__b6d9.HasMessage = 1;
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed(self, &x->ReportingTdpStatus.root); return;
            }
if (self->Change409.IsTriggered) {
                
  self->OutMsgTdpStatus__b6d9.Value.ReportedStateOfPassing = StateOfPassing__616f__Disturbed; 
self->OutMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing = DirectionOfPassing__a7c9__WithoutIndicatedDirection;
  self->OutMsgTdpStatus__b6d9.HasMessage = 1;
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed(self, &x->ReportingTdpStatus.root); return;
            }
        }
        
void transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
            
            if (self->Change405.IsTriggered) {
                
  self->OutMsgTdpStatus__b6d9.Value.ReportedStateOfPassing = StateOfPassing__616f__NotPassed; 
self->OutMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing = DirectionOfPassing__a7c9__WithoutIndicatedDirection;
  self->OutMsgTdpStatus__b6d9.HasMessage = 1;
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed(self, &x->ReportingTdpStatus.root); return;
            }
if (self->Change407.IsTriggered) {
                
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed(self, &x->ReportingTdpStatus.root); return;
            }
        }
        

        void transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
            switch (x->ReportingTdpStatus.root.state) {
                case FSciTdsReportTdp__root__ReportingTdpStatus__root__Waiting:
                    transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Waiting(self, x);
                    break;
case FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed:
                    transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed(self, x);
                    break;
case FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed:
                    transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed(self, x);
                    break;
case FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed:
                    transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed(self, x);
                    break;
            }
        }
        

        void transition_from_FSciTdsReportTdp__root__ReportingTdpStatus(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
            transition_from_FSciTdsReportTdp__root__ReportingTdpStatus__root(self, x);
            if (self->Change314.IsTriggered) {
                
                make_state_FSciTdsReportTdp__root__ReportingTdpStatus(self, x); return;
            }
        }
        

        void transition_from_FSciTdsReportTdp__root(FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x) {
            switch (x->state) {
                case FSciTdsReportTdp__root__ReportingTdpStatus:
                    transition_from_FSciTdsReportTdp__root__ReportingTdpStatus(self, x);
                    break;
            }
        }
        

static void evaluateChangeEvents(FSciTdsReportTdp *self) {
    self->Change412.IsTriggered = IsTriggered(MakeChange(self->D54intReportedTdpDirection.IsSignalled, self->D54intReportedTdpDirection.Value == FSciTdsReportTdp_D54intReportedTdpDirectionValue__AgainstReferenceDirection));
self->Change413.IsTriggered = IsTriggered(MakeChange(self->D54intReportedTdpDirection.IsSignalled, self->D54intReportedTdpDirection.Value == FSciTdsReportTdp_D54intReportedTdpDirectionValue__ReferenceDirection));
self->Change408.IsTriggered = IsTriggered(MakeChange(self->D53inReportedTdpStatus.IsSignalled, self->D53inReportedTdpStatus.Value == FSciTdsReportTdp_D53inReportedTdpStatusValue__Passed));
self->Change410.IsTriggered = IsTriggered(MakeChange(self->D53inReportedTdpStatus.IsSignalled, self->D53inReportedTdpStatus.Value == FSciTdsReportTdp_D53inReportedTdpStatusValue__TdpDisturbed));
self->Change406.IsTriggered = IsTriggered(MakeChange(self->D53inReportedTdpStatus.IsSignalled, self->D53inReportedTdpStatus.Value == FSciTdsReportTdp_D53inReportedTdpStatusValue__NotPassed));
self->Change409.IsTriggered = IsTriggered(MakeChange(self->D53inReportedTdpStatus.IsSignalled, self->D53inReportedTdpStatus.Value == FSciTdsReportTdp_D53inReportedTdpStatusValue__TdpDisturbed));
self->Change405.IsTriggered = IsTriggered(MakeChange(self->D53inReportedTdpStatus.IsSignalled, self->D53inReportedTdpStatus.Value == FSciTdsReportTdp_D53inReportedTdpStatusValue__NotPassed));
self->Change407.IsTriggered = IsTriggered(MakeChange(self->D53inReportedTdpStatus.IsSignalled, self->D53inReportedTdpStatus.Value == FSciTdsReportTdp_D53inReportedTdpStatusValue__Passed));
self->Change314.IsTriggered = IsTriggered(OrChange(OrChange(MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciTdsReportTdp_D50inPdiConnectionStateValue__ReadyForPdiNoScp), MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciTdsReportTdp_D50inPdiConnectionStateValue__ReadyForPdi)), MakeChange(self->D50inPdiConnectionState.IsSignalled, self->D50inPdiConnectionState.Value == FSciTdsReportTdp_D50inPdiConnectionStateValue__Suspended)));
}

static void resetOutputs(FSciTdsReportTdp *self) {
    self->OutMsgTdpStatus__b6d9.HasMessage = false;

    

    
}

static void resetTriggers(FSciTdsReportTdp *self) {
    self->InStartStatusReport__1e4e.HasMessage = false;

    

    self->D50inPdiConnectionState.IsSignalled = false;
self->D53inReportedTdpStatus.IsSignalled = false;

    
}

void transition_FSciTdsReportTdp(FSciTdsReportTdp *self) {
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FSciTdsReportTdp__root(self, &self->state);
    resetTriggers(self);
}

void new_FSciTdsReportTdp(FSciTdsReportTdp *self) {
    make_state_FSciTdsReportTdp__root(self, &self->state);
}
