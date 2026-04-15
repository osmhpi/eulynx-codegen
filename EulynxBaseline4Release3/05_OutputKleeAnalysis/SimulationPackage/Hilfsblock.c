
#include "../../04_OutputC/SimulationPackage/Hilfsblock.h"

void count_transitions_from_Hilfsblock__root__AtomicState(int *ctr, Hilfsblock *self, Hilfsblock__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change517.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change518.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change519.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change520.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change521.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_Hilfsblock__root(int *ctr, Hilfsblock *self, Hilfsblock__root__state_struct *x)
{
    switch (x->state)
    {
    case Hilfsblock__root__AtomicState:
        count_transitions_from_Hilfsblock__root__AtomicState(ctr, self, x);
        break;
    }
}

int count_transitions_Hilfsblock(Hilfsblock *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_Hilfsblock__root(&ctr, self, &self->state);
    return ctr;
}