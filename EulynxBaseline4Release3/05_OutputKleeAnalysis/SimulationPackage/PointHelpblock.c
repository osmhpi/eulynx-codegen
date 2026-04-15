
#include "../../04_OutputC/SimulationPackage/PointHelpblock.h"

void count_transitions_from_PointHelpblock__root__AtomicState(int *ctr, PointHelpblock *self,
                                                              PointHelpblock__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_PointHelpblock__root(int *ctr, PointHelpblock *self, PointHelpblock__root__state_struct *x)
{
    switch (x->state)
    {
    case PointHelpblock__root__AtomicState:
        count_transitions_from_PointHelpblock__root__AtomicState(ctr, self, x);
        break;
    }
}

int count_transitions_PointHelpblock(PointHelpblock *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_PointHelpblock__root(&ctr, self, &self->state);
    return ctr;
}