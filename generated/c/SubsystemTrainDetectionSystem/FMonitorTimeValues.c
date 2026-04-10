
#include "FMonitorTimeValues.h"

// Value Conversion Functions



// Operations







void make_state_FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring(FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__root__state_struct *region) {
    LOG("[FMonitorTimeValues] Entering state NoMonitoring in region root__MonitorTimeValues__root");
    region->state = FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring;
    
};


void make_state_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime(FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__root__state_struct *region) {
    LOG("[FMonitorTimeValues] Entering state MonitorInhibitionTime in region root__MonitorTimeValues__root");
    region->state = FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime;
    
};


void make_state_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorNotificationOfAvailability(FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__root__state_struct *region) {
    LOG("[FMonitorTimeValues] Entering state MonitorNotificationOfAvailability in region root__MonitorTimeValues__root");
    region->state = FMonitorTimeValues__root__MonitorTimeValues__root__MonitorNotificationOfAvailability;
    
};


void make_state_FMonitorTimeValues__root__MonitorTimeValues__root(FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__root__state_struct *x) {
    memset(x, 0, sizeof(FMonitorTimeValues__root__MonitorTimeValues__root__state_struct));
    
                make_state_FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring(self, x); return;
}



void make_state_FMonitorTimeValues__root__MonitorTimeValues(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *region) {
    LOG("[FMonitorTimeValues] Entering state MonitorTimeValues in region root");
    region->state = FMonitorTimeValues__root__MonitorTimeValues;
    make_state_FMonitorTimeValues__root__MonitorTimeValues__root(self, &region->MonitorTimeValues.root);
};


void make_state_FMonitorTimeValues__root__WaitingForFinishBooting(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *region) {
    LOG("[FMonitorTimeValues] Entering state WaitingForFinishBooting in region root");
    region->state = FMonitorTimeValues__root__WaitingForFinishBooting;
    
};


void make_state_FMonitorTimeValues__root__FallbackMode(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *region) {
    LOG("[FMonitorTimeValues] Entering state FallbackMode in region root");
    region->state = FMonitorTimeValues__root__FallbackMode;
    
};


void make_state_FMonitorTimeValues__root__TechnicalDisturbance(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *region) {
    LOG("[FMonitorTimeValues] Entering state TechnicalDisturbance in region root");
    region->state = FMonitorTimeValues__root__TechnicalDisturbance;
    
};


void make_state_FMonitorTimeValues__root(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x) {
    memset(x, 0, sizeof(FMonitorTimeValues__root__state_struct));
    
                make_state_FMonitorTimeValues__root__WaitingForFinishBooting(self, x); return;
}



        
        

        void transition_from_FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x) {
            
            if (self->Change120.IsTriggered) {
                if (self->D28inConTDelayOfNotificationOfAvailability.Value != 0) {
                self->D14outMonitoringTime.Value = true;
                make_state_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorNotificationOfAvailability(self, &x->MonitorTimeValues.root); return;
            }
            }
if (self->Change1102.IsTriggered) {
                if ((!(self->D16inLastWheelOut.Value)) && (self->D29inConTInhibitionTime.Value != 0)) {
                self->D14outMonitoringTime.Value = true;
                make_state_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime(self, &x->MonitorTimeValues.root); return;
            }
            }
        }
        
void transition_from_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x) {
            
            if (self->Time20.IsTimeoutExpired) {
                self->D14outMonitoringTime.Value = false;
                make_state_FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring(self, &x->MonitorTimeValues.root); return;
            }
if (self->Change119.IsTriggered) {
                
                make_state_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorNotificationOfAvailability(self, &x->MonitorTimeValues.root); return;
            }
if (self->Change1100.IsTriggered) {
                if (!(self->D16inLastWheelOut.Value)) {
                
                make_state_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime(self, &x->MonitorTimeValues.root); return;
            }
            }
        }
        
void transition_from_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorNotificationOfAvailability(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x) {
            
            if (self->Time19.IsTimeoutExpired) {
                self->D14outMonitoringTime.Value = false;
                make_state_FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring(self, &x->MonitorTimeValues.root); return;
            }
if (self->Change1101.IsTriggered) {
                
                make_state_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime(self, &x->MonitorTimeValues.root); return;
            }
        }
        

        void transition_from_FMonitorTimeValues__root__MonitorTimeValues__root(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x) {
            switch (x->MonitorTimeValues.root.state) {
                case FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring:
                    transition_from_FMonitorTimeValues__root__MonitorTimeValues__root__NoMonitoring(self, x);
                    break;
case FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime:
                    transition_from_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorInhibitionTime(self, x);
                    break;
case FMonitorTimeValues__root__MonitorTimeValues__root__MonitorNotificationOfAvailability:
                    transition_from_FMonitorTimeValues__root__MonitorTimeValues__root__MonitorNotificationOfAvailability(self, x);
                    break;
            }
        }
        

        void transition_from_FMonitorTimeValues__root__MonitorTimeValues(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x) {
            transition_from_FMonitorTimeValues__root__MonitorTimeValues__root(self, x);
            if (self->Change233.IsTriggered) {
                self->D14outMonitoringTime.Value = false;
                make_state_FMonitorTimeValues__root__TechnicalDisturbance(self, x); return;
            }
if (self->Change391.IsTriggered) {
                self->D14outMonitoringTime.Value = false;
                make_state_FMonitorTimeValues__root__WaitingForFinishBooting(self, x); return;
            }
if (self->Change392.IsTriggered) {
                self->D14outMonitoringTime.Value = false;
                make_state_FMonitorTimeValues__root__FallbackMode(self, x); return;
            }
        }
        
void transition_from_FMonitorTimeValues__root__WaitingForFinishBooting(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x) {
            
            if (self->Change402.IsTriggered) {
                
                    if (self->D32inCriticalFailureTvps.Value) {
                
                make_state_FMonitorTimeValues__root__TechnicalDisturbance(self, x); return;
            }
else {
                
                make_state_FMonitorTimeValues__root__MonitorTimeValues(self, x); return;
            }
            }
        }
        
void transition_from_FMonitorTimeValues__root__FallbackMode(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x) {
            
            if (self->Change386.IsTriggered) {
                
                make_state_FMonitorTimeValues__root__WaitingForFinishBooting(self, x); return;
            }
        }
        
void transition_from_FMonitorTimeValues__root__TechnicalDisturbance(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x) {
            
            if (self->Change396.IsTriggered) {
                
                make_state_FMonitorTimeValues__root__FallbackMode(self, x); return;
            }
if (self->Change562.IsTriggered) {
                
                make_state_FMonitorTimeValues__root__MonitorTimeValues(self, x); return;
            }
        }
        

        void transition_from_FMonitorTimeValues__root(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x) {
            switch (x->state) {
                case FMonitorTimeValues__root__MonitorTimeValues:
                    transition_from_FMonitorTimeValues__root__MonitorTimeValues(self, x);
                    break;
case FMonitorTimeValues__root__WaitingForFinishBooting:
                    transition_from_FMonitorTimeValues__root__WaitingForFinishBooting(self, x);
                    break;
case FMonitorTimeValues__root__FallbackMode:
                    transition_from_FMonitorTimeValues__root__FallbackMode(self, x);
                    break;
case FMonitorTimeValues__root__TechnicalDisturbance:
                    transition_from_FMonitorTimeValues__root__TechnicalDisturbance(self, x);
                    break;
            }
        }
        

static void evaluateChangeEvents(FMonitorTimeValues *self) {
    self->Change120.IsTriggered = IsTriggered(MakeChange(self->D16inLastWheelOut.IsSignalled, self->D16inLastWheelOut.Value));
self->Change1102.IsTriggered = IsTriggered(OrChange(OrChange(MakeChange(self->T37inWheelIn.IsTriggered, self->T37inWheelIn.IsTriggered), MakeChange(self->T38inWheelOut.IsTriggered, self->T38inWheelOut.IsTriggered)), MakeChange(self->T39inUndefinedPattern.IsTriggered, self->T39inUndefinedPattern.IsTriggered)));
self->Change119.IsTriggered = IsTriggered(MakeChange(self->D16inLastWheelOut.IsSignalled, self->D16inLastWheelOut.Value));
self->Change1100.IsTriggered = IsTriggered(OrChange(OrChange(MakeChange(self->T37inWheelIn.IsTriggered, self->T37inWheelIn.IsTriggered), MakeChange(self->T38inWheelOut.IsTriggered, self->T38inWheelOut.IsTriggered)), MakeChange(self->T39inUndefinedPattern.IsTriggered, self->T39inUndefinedPattern.IsTriggered)));
self->Change1101.IsTriggered = IsTriggered(OrChange(OrChange(MakeChange(self->T37inWheelIn.IsTriggered, self->T37inWheelIn.IsTriggered), MakeChange(self->T38inWheelOut.IsTriggered, self->T38inWheelOut.IsTriggered)), MakeChange(self->T39inUndefinedPattern.IsTriggered, self->T39inUndefinedPattern.IsTriggered)));
self->Change233.IsTriggered = IsTriggered(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value));
self->Change391.IsTriggered = IsTriggered(OrChange(MakeChange(self->D51outEstEfesState.IsSignalled, self->D51outEstEfesState.Value == FMonitorTimeValues_D51outEstEfesStateValue__Booting), MakeChange(self->D51outEstEfesState.IsSignalled, self->D51outEstEfesState.Value == FMonitorTimeValues_D51outEstEfesStateValue__NoOperatingVoltage)));
self->Change392.IsTriggered = IsTriggered(MakeChange(self->D51outEstEfesState.IsSignalled, self->D51outEstEfesState.Value == FMonitorTimeValues_D51outEstEfesStateValue__FallbackMode));
self->Change402.IsTriggered = IsTriggered(MakeChange(self->D51outEstEfesState.IsSignalled, self->D51outEstEfesState.Value == FMonitorTimeValues_D51outEstEfesStateValue__Initialising));
self->Change386.IsTriggered = IsTriggered(MakeChange(self->D51outEstEfesState.IsSignalled, self->D51outEstEfesState.Value == FMonitorTimeValues_D51outEstEfesStateValue__Booting));
self->Change396.IsTriggered = IsTriggered(MakeChange(self->D51outEstEfesState.IsSignalled, self->D51outEstEfesState.Value == FMonitorTimeValues_D51outEstEfesStateValue__FallbackMode));
self->Change562.IsTriggered = IsTriggered(NegateChange(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value)));
}

static void resetOutputs(FMonitorTimeValues *self) {
    

    

    self->D51outEstEfesState.IsSignalled = false;
self->D14outMonitoringTime.IsSignalled = false;
}

static void resetTriggers(FMonitorTimeValues *self) {
    

    self->T37inWheelIn.IsTriggered = false;
self->T38inWheelOut.IsTriggered = false;
self->T39inUndefinedPattern.IsTriggered = false;

    self->D28inConTDelayOfNotificationOfAvailability.IsSignalled = false;
self->D29inConTInhibitionTime.IsSignalled = false;
self->D32inCriticalFailureTvps.IsSignalled = false;
self->D16inLastWheelOut.IsSignalled = false;

    self->Time20.IsTimeoutExpired = false;
self->Time19.IsTimeoutExpired = false;
}

void transition_FMonitorTimeValues(FMonitorTimeValues *self) {
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FMonitorTimeValues__root(self, &self->state);
    resetTriggers(self);
}

void new_FMonitorTimeValues(FMonitorTimeValues *self) {
    make_state_FMonitorTimeValues__root(self, &self->state);
}
