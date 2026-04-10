
#include "FHandleInternalFcUCommand.h"

// Value Conversion Functions



// Operations






void make_state_FHandleInternalFcUCommand__root__ReceivingCommandsFromInternal(FHandleInternalFcUCommand *self, FHandleInternalFcUCommand__root__state_struct *region) {
    LOG("[FHandleInternalFcUCommand] Entering state ReceivingCommandsFromInternal in region root");
    region->state = FHandleInternalFcUCommand__root__ReceivingCommandsFromInternal;
    
};


void make_state_FHandleInternalFcUCommand__root(FHandleInternalFcUCommand *self, FHandleInternalFcUCommand__root__state_struct *x) {
    memset(x, 0, sizeof(FHandleInternalFcUCommand__root__state_struct));
    
                make_state_FHandleInternalFcUCommand__root__ReceivingCommandsFromInternal(self, x); return;
}



        

        void transition_from_FHandleInternalFcUCommand__root__ReceivingCommandsFromInternal(FHandleInternalFcUCommand *self, FHandleInternalFcUCommand__root__state_struct *x) {
            
            if (self->Change1087.IsTriggered) {
                
  self->OutRequestFcU__bd99.Value.ReportedSource = SourceOfCommand__d5a9__Internal;
  self->OutRequestFcU__bd99.HasMessage = 1;
                make_state_FHandleInternalFcUCommand__root__ReceivingCommandsFromInternal(self, x); return;
            }
        }
        

        void transition_from_FHandleInternalFcUCommand__root(FHandleInternalFcUCommand *self, FHandleInternalFcUCommand__root__state_struct *x) {
            switch (x->state) {
                case FHandleInternalFcUCommand__root__ReceivingCommandsFromInternal:
                    transition_from_FHandleInternalFcUCommand__root__ReceivingCommandsFromInternal(self, x);
                    break;
            }
        }
        

static void evaluateChangeEvents(FHandleInternalFcUCommand *self) {
    self->Change1087.IsTriggered = self->T33inFcU.IsTriggered;
}

static void resetOutputs(FHandleInternalFcUCommand *self) {
    self->OutRequestFcU__bd99.HasMessage = false;

    

    
}

static void resetTriggers(FHandleInternalFcUCommand *self) {
    

    self->T33inFcU.IsTriggered = false;

    

    
}

void transition_FHandleInternalFcUCommand(FHandleInternalFcUCommand *self) {
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FHandleInternalFcUCommand__root(self, &self->state);
    resetTriggers(self);
}

void new_FHandleInternalFcUCommand(FHandleInternalFcUCommand *self) {
    make_state_FHandleInternalFcUCommand__root(self, &self->state);
}
