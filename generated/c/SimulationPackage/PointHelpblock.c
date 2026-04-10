
#include "PointHelpblock.h"

// Value Conversion Functions



// Operations






void make_state_PointHelpblock__root__AtomicState(PointHelpblock *self, PointHelpblock__root__state_struct *region) {
    LOG("[PointHelpblock] Entering state AtomicState in region root");
    region->state = PointHelpblock__root__AtomicState;
    
};


void make_state_PointHelpblock__root(PointHelpblock *self, PointHelpblock__root__state_struct *x) {
    memset(x, 0, sizeof(PointHelpblock__root__state_struct));
    self->DoutConstantTrue.Value = true;
                make_state_PointHelpblock__root__AtomicState(self, x); return;
}



        

        void transition_from_PointHelpblock__root__AtomicState(PointHelpblock *self, PointHelpblock__root__state_struct *x) {
            
            
        }
        

        void transition_from_PointHelpblock__root(PointHelpblock *self, PointHelpblock__root__state_struct *x) {
            switch (x->state) {
                case PointHelpblock__root__AtomicState:
                    transition_from_PointHelpblock__root__AtomicState(self, x);
                    break;
            }
        }
        

static void evaluateChangeEvents(PointHelpblock *self) {
    
}

static void resetOutputs(PointHelpblock *self) {
    

    

    
}

static void resetTriggers(PointHelpblock *self) {
    

    

    

    
}

void transition_PointHelpblock(PointHelpblock *self) {
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_PointHelpblock__root(self, &self->state);
    resetTriggers(self);
}

void new_PointHelpblock(PointHelpblock *self) {
    make_state_PointHelpblock__root(self, &self->state);
}
