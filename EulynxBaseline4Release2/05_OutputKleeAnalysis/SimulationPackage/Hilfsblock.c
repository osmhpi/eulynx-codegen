
#include "../../04_OutputC/SimulationPackage/Hilfsblock.h"

void count_transitions_from_Hilfsblock__root__AtomicState(int *ctr, Hilfsblock *self, Hilfsblock__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change524.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change525.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change526.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change527.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change528.IsTriggered)
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