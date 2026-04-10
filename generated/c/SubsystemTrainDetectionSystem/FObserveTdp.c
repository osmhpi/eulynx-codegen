
#include "FObserveTdp.h"

// Value Conversion Functions



// Operations
static void Cop1Init(FObserveTdp *self ) {
            self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Undefined;self->D53outReportTdpPassingStatus.IsSignalled = true; 
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__Undefined;self->D54outReportTdpDirection.IsSignalled = true;
            
        }









void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state NotPassed in region root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state PassedAgainstReferenceDirection in region root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state PassedInReferenceDirection in region root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__OperationallyDisturbed(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state OperationallyDisturbed in region root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__OperationallyDisturbed;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state WaitingDelayOfNotificationOfUndefinedPattern in region root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__WaitingDelayOfNotificationOfUndefinedPattern;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state_struct *x) {
    memset(x, 0, sizeof(FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__state_struct));
    self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__NotPassed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed(self, x); return;
}



void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state MonitoringTdpWithDirection in region root__NotFailed__root__Operational__root__TdpWithDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection;
    make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root(self, &region->MonitoringTdpWithDirection.root);
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__TechnicallyDisturbed(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state TechnicallyDisturbed in region root__NotFailed__root__Operational__root__TdpWithDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__TechnicallyDisturbed;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__state_struct *x) {
    memset(x, 0, sizeof(FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__state_struct));
    
                    if (self->D63inCriticalFailureTdp.Value) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__TdpDisturbed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__TechnicallyDisturbed(self, x); return;
            }
else {
                
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection(self, x); return;
            }
}






void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__NotPassed(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state NotPassed in region root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__NotPassed;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state Passed in region root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__OperationallyDisturbed(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state OperationallyDisturbed in region root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__OperationallyDisturbed;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state WaitingDelayOfNotificationOfUndefinedPattern in region root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__WaitingDelayOfNotificationOfUndefinedPattern;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state_struct *x) {
    memset(x, 0, sizeof(FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__state_struct));
    self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__NotPassed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__NotPassed(self, x); return;
}



void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state MonitoringTdpWithoutDirection in region root__NotFailed__root__Operational__root__TdpWithoutDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection;
    make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root(self, &region->MonitoringTdpWithoutDirection.root);
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__TechnicallyDisturbed(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state TechnicallyDisturbed in region root__NotFailed__root__Operational__root__TdpWithoutDirection__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__TechnicallyDisturbed;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__state_struct *x) {
    memset(x, 0, sizeof(FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__state_struct));
    
                    if (self->D63inCriticalFailureTdp.Value) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__TdpDisturbed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__TechnicallyDisturbed(self, x); return;
            }
else {
                
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection(self, x); return;
            }
}



void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state TdpWithDirection in region root__NotFailed__root__Operational__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection;
    make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root(self, &region->TdpWithDirection.root);
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state TdpWithoutDirection in region root__NotFailed__root__Operational__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection;
    make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root(self, &region->TdpWithoutDirection.root);
};


void make_state_FObserveTdp__root__NotFailed__root__Operational__root(FObserveTdp *self, FObserveTdp__root__NotFailed__root__Operational__root__state_struct *x) {
    memset(x, 0, sizeof(FObserveTdp__root__NotFailed__root__Operational__root__state_struct));
    
                    if (self->D56inConTdpWithoutDirection.Value == true) {
                
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection(self, x); return;
            }
else {
                
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection(self, x); return;
            }
}



void make_state_FObserveTdp__root__NotFailed__root__WaitingForFinishedBooting(FObserveTdp *self, FObserveTdp__root__NotFailed__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state WaitingForFinishedBooting in region root__NotFailed__root");
    region->state = FObserveTdp__root__NotFailed__root__WaitingForFinishedBooting;
    
};


void make_state_FObserveTdp__root__NotFailed__root__Operational(FObserveTdp *self, FObserveTdp__root__NotFailed__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state Operational in region root__NotFailed__root");
    region->state = FObserveTdp__root__NotFailed__root__Operational;
    make_state_FObserveTdp__root__NotFailed__root__Operational__root(self, &region->Operational.root);
};


void make_state_FObserveTdp__root__NotFailed__root(FObserveTdp *self, FObserveTdp__root__NotFailed__root__state_struct *x) {
    memset(x, 0, sizeof(FObserveTdp__root__NotFailed__root__state_struct));
    
                make_state_FObserveTdp__root__NotFailed__root__WaitingForFinishedBooting(self, x); return;
}



void make_state_FObserveTdp__root__NotFailed(FObserveTdp *self, FObserveTdp__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state NotFailed in region root");
    region->state = FObserveTdp__root__NotFailed;
    make_state_FObserveTdp__root__NotFailed__root(self, &region->NotFailed.root);
};


void make_state_FObserveTdp__root__FallbackMode(FObserveTdp *self, FObserveTdp__root__state_struct *region) {
    LOG("[FObserveTdp] Entering state FallbackMode in region root");
    region->state = FObserveTdp__root__FallbackMode;
    
};


void make_state_FObserveTdp__root(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
    memset(x, 0, sizeof(FObserveTdp__root__state_struct));
    Cop1Init(self);
                make_state_FObserveTdp__root__NotFailed(self, x); return;
}



        
        
        
        
        

        void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Change1195.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__ReferenceDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
if (self->Change1229.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__AgainstReferenceDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
if (self->Change1238.IsTriggered) {
                
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
        }
        
void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Time38.IsTimeoutExpired) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__NotPassed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
if (self->Change1197.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__ReferenceDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
if (self->Change1232.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__AgainstReferenceDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
        }
        
void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Time39.IsTimeoutExpired) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__NotPassed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
if (self->Change1198.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__ReferenceDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
if (self->Change1230.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__AgainstReferenceDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
        }
        
void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__OperationallyDisturbed(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Change1196.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__ReferenceDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
if (self->Change1231.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__AgainstReferenceDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
        }
        
void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Time41.IsTimeoutExpired) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__TdpDisturbed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__OperationallyDisturbed(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
if (self->Change1194.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__ReferenceDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
if (self->Change1228.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__AgainstReferenceDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root); return;
            }
        }
        

        void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            switch (x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root.state) {
                case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed(self, x);
                    break;
case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection(self, x);
                    break;
case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection(self, x);
                    break;
case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__OperationallyDisturbed:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__OperationallyDisturbed(self, x);
                    break;
case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__WaitingDelayOfNotificationOfUndefinedPattern:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(self, x);
                    break;
            }
        }
        

        void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root(self, x);
            if (self->Change425.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__TdpDisturbed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__TechnicallyDisturbed(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root); return;
            }
        }
        
void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__TechnicallyDisturbed(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Change426.IsTriggered) {
                
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection(self, &x->NotFailed.root.Operational.root.TdpWithDirection.root); return;
            }
        }
        

        void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            switch (x->NotFailed.root.Operational.root.TdpWithDirection.root.state) {
                case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection(self, x);
                    break;
case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__TechnicallyDisturbed:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__TechnicallyDisturbed(self, x);
                    break;
            }
        }
        

        
        

        void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__NotPassed(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Change1234.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed(self, &x->NotFailed.root.Operational.root.TdpWithoutDirection.root.MonitoringTdpWithoutDirection.root); return;
            }
if (self->Change1239.IsTriggered) {
                
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(self, &x->NotFailed.root.Operational.root.TdpWithoutDirection.root.MonitoringTdpWithoutDirection.root); return;
            }
        }
        
void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Time37.IsTimeoutExpired) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__NotPassed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__NotPassed(self, &x->NotFailed.root.Operational.root.TdpWithoutDirection.root.MonitoringTdpWithoutDirection.root); return;
            }
if (self->Change1236.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed(self, &x->NotFailed.root.Operational.root.TdpWithoutDirection.root.MonitoringTdpWithoutDirection.root); return;
            }
        }
        
void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__OperationallyDisturbed(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Change1233.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed(self, &x->NotFailed.root.Operational.root.TdpWithoutDirection.root.MonitoringTdpWithoutDirection.root); return;
            }
        }
        
void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Time42.IsTimeoutExpired) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__TdpDisturbed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__OperationallyDisturbed(self, &x->NotFailed.root.Operational.root.TdpWithoutDirection.root.MonitoringTdpWithoutDirection.root); return;
            }
if (self->Change1235.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__Passed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed(self, &x->NotFailed.root.Operational.root.TdpWithoutDirection.root.MonitoringTdpWithoutDirection.root); return;
            }
        }
        

        void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            switch (x->NotFailed.root.Operational.root.TdpWithoutDirection.root.MonitoringTdpWithoutDirection.root.state) {
                case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__NotPassed:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__NotPassed(self, x);
                    break;
case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed(self, x);
                    break;
case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__OperationallyDisturbed:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__OperationallyDisturbed(self, x);
                    break;
case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__WaitingDelayOfNotificationOfUndefinedPattern:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(self, x);
                    break;
            }
        }
        

        void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root(self, x);
            if (self->Change424.IsTriggered) {
                self->D53outReportTdpPassingStatus.Value = FObserveTdp_D53outReportTdpPassingStatusValue__TdpDisturbed;self->D53outReportTdpPassingStatus.IsSignalled = true;
self->D54outReportTdpDirection.Value = FObserveTdp_D54outReportTdpDirectionValue__WithoutIndicatedDirection;self->D54outReportTdpDirection.IsSignalled = true;
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__TechnicallyDisturbed(self, &x->NotFailed.root.Operational.root.TdpWithoutDirection.root); return;
            }
        }
        
void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__TechnicallyDisturbed(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Change427.IsTriggered) {
                
                make_state_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection(self, &x->NotFailed.root.Operational.root.TdpWithoutDirection.root); return;
            }
        }
        

        void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            switch (x->NotFailed.root.Operational.root.TdpWithoutDirection.root.state) {
                case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection(self, x);
                    break;
case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__TechnicallyDisturbed:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__TechnicallyDisturbed(self, x);
                    break;
            }
        }
        

        void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root(self, x);
            
        }
        
void transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root(self, x);
            
        }
        

        void transition_from_FObserveTdp__root__NotFailed__root__Operational__root(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            switch (x->NotFailed.root.Operational.root.state) {
                case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection(self, x);
                    break;
case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection(self, x);
                    break;
            }
        }
        

        void transition_from_FObserveTdp__root__NotFailed__root__WaitingForFinishedBooting(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Change401.IsTriggered) {
                
                make_state_FObserveTdp__root__NotFailed__root__Operational(self, &x->NotFailed.root); return;
            }
        }
        
void transition_from_FObserveTdp__root__NotFailed__root__Operational(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            transition_from_FObserveTdp__root__NotFailed__root__Operational__root(self, x);
            if (self->Change390.IsTriggered) {
                Cop1Init(self);
                make_state_FObserveTdp__root__NotFailed(self, x); return;
            }
        }
        

        void transition_from_FObserveTdp__root__NotFailed__root(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            switch (x->NotFailed.root.state) {
                case FObserveTdp__root__NotFailed__root__WaitingForFinishedBooting:
                    transition_from_FObserveTdp__root__NotFailed__root__WaitingForFinishedBooting(self, x);
                    break;
case FObserveTdp__root__NotFailed__root__Operational:
                    transition_from_FObserveTdp__root__NotFailed__root__Operational(self, x);
                    break;
            }
        }
        

        void transition_from_FObserveTdp__root__NotFailed(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            transition_from_FObserveTdp__root__NotFailed__root(self, x);
            if (self->Change398.IsTriggered) {
                
                make_state_FObserveTdp__root__FallbackMode(self, x); return;
            }
        }
        
void transition_from_FObserveTdp__root__FallbackMode(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            
            if (self->Change385.IsTriggered) {
                Cop1Init(self);
                make_state_FObserveTdp__root__NotFailed(self, x); return;
            }
        }
        

        void transition_from_FObserveTdp__root(FObserveTdp *self, FObserveTdp__root__state_struct *x) {
            switch (x->state) {
                case FObserveTdp__root__NotFailed:
                    transition_from_FObserveTdp__root__NotFailed(self, x);
                    break;
case FObserveTdp__root__FallbackMode:
                    transition_from_FObserveTdp__root__FallbackMode(self, x);
                    break;
            }
        }
        

static void evaluateChangeEvents(FObserveTdp *self) {
    self->Change1195.IsTriggered = self->T59inPassingInReferenceDirection.IsTriggered;
self->Change1229.IsTriggered = self->T60inPassingAgainstReferenceDirection.IsTriggered;
self->Change1238.IsTriggered = self->T62inReceivingAnUndefinedPattern.IsTriggered;
self->Change1197.IsTriggered = self->T59inPassingInReferenceDirection.IsTriggered;
self->Change1232.IsTriggered = IsTriggered(OrChange(MakeChange(self->T60inPassingAgainstReferenceDirection.IsTriggered, self->T60inPassingAgainstReferenceDirection.IsTriggered), MakeChange(self->T62inReceivingAnUndefinedPattern.IsTriggered, self->T62inReceivingAnUndefinedPattern.IsTriggered)));
self->Change1198.IsTriggered = IsTriggered(OrChange(MakeChange(self->T59inPassingInReferenceDirection.IsTriggered, self->T59inPassingInReferenceDirection.IsTriggered), MakeChange(self->T62inReceivingAnUndefinedPattern.IsTriggered, self->T62inReceivingAnUndefinedPattern.IsTriggered)));
self->Change1230.IsTriggered = self->T60inPassingAgainstReferenceDirection.IsTriggered;
self->Change1196.IsTriggered = self->T59inPassingInReferenceDirection.IsTriggered;
self->Change1231.IsTriggered = self->T60inPassingAgainstReferenceDirection.IsTriggered;
self->Change1194.IsTriggered = self->T59inPassingInReferenceDirection.IsTriggered;
self->Change1228.IsTriggered = self->T60inPassingAgainstReferenceDirection.IsTriggered;
self->Change425.IsTriggered = IsTriggered(MakeChange(self->D63inCriticalFailureTdp.IsSignalled, self->D63inCriticalFailureTdp.Value));
self->Change426.IsTriggered = IsTriggered(MakeChange(self->D63inCriticalFailureTdp.IsSignalled, self->D63inCriticalFailureTdp.Value == false));
self->Change1234.IsTriggered = self->T61inPassingWithoutDirection.IsTriggered;
self->Change1239.IsTriggered = self->T62inReceivingAnUndefinedPattern.IsTriggered;
self->Change1236.IsTriggered = IsTriggered(OrChange(MakeChange(self->T61inPassingWithoutDirection.IsTriggered, self->T61inPassingWithoutDirection.IsTriggered), MakeChange(self->T62inReceivingAnUndefinedPattern.IsTriggered, self->T62inReceivingAnUndefinedPattern.IsTriggered)));
self->Change1233.IsTriggered = self->T61inPassingWithoutDirection.IsTriggered;
self->Change1235.IsTriggered = self->T61inPassingWithoutDirection.IsTriggered;
self->Change424.IsTriggered = IsTriggered(MakeChange(self->D63inCriticalFailureTdp.IsSignalled, self->D63inCriticalFailureTdp.Value));
self->Change427.IsTriggered = IsTriggered(MakeChange(self->D63inCriticalFailureTdp.IsSignalled, self->D63inCriticalFailureTdp.Value == false));
self->Change401.IsTriggered = IsTriggered(MakeChange(self->D51outEstEfesState.IsSignalled, self->D51outEstEfesState.Value == FObserveTdp_D51outEstEfesStateValue__Initialising));
self->Change390.IsTriggered = IsTriggered(OrChange(MakeChange(self->D51outEstEfesState.IsSignalled, self->D51outEstEfesState.Value == FObserveTdp_D51outEstEfesStateValue__Booting), MakeChange(self->D51outEstEfesState.IsSignalled, self->D51outEstEfesState.Value == FObserveTdp_D51outEstEfesStateValue__NoOperatingVoltage)));
self->Change398.IsTriggered = IsTriggered(MakeChange(self->D51outEstEfesState.IsSignalled, self->D51outEstEfesState.Value == FObserveTdp_D51outEstEfesStateValue__FallbackMode));
self->Change385.IsTriggered = IsTriggered(MakeChange(self->D51outEstEfesState.IsSignalled, self->D51outEstEfesState.Value == FObserveTdp_D51outEstEfesStateValue__Booting));
}

static void resetOutputs(FObserveTdp *self) {
    

    

    self->D53outReportTdpPassingStatus.IsSignalled = false;
self->D51outEstEfesState.IsSignalled = false;
self->D54outReportTdpDirection.IsSignalled = false;
}

static void resetTriggers(FObserveTdp *self) {
    

    self->T59inPassingInReferenceDirection.IsTriggered = false;
self->T60inPassingAgainstReferenceDirection.IsTriggered = false;
self->T62inReceivingAnUndefinedPattern.IsTriggered = false;
self->T61inPassingWithoutDirection.IsTriggered = false;

    self->D63inCriticalFailureTdp.IsSignalled = false;
self->D55inConTTdpDelay.IsSignalled = false;
self->D56inConTdpWithoutDirection.IsSignalled = false;

    self->Time38.IsTimeoutExpired = false;
self->Time39.IsTimeoutExpired = false;
self->Time41.IsTimeoutExpired = false;
self->Time37.IsTimeoutExpired = false;
self->Time42.IsTimeoutExpired = false;
}

void transition_FObserveTdp(FObserveTdp *self) {
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FObserveTdp__root(self, &self->state);
    resetTriggers(self);
}

void new_FObserveTdp(FObserveTdp *self) {
    make_state_FObserveTdp__root(self, &self->state);
}
