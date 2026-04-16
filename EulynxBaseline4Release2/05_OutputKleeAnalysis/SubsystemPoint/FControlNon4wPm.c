
#include "../../04_OutputC/SubsystemPoint/FControlNon4wPm.h"

void count_transitions_from_FControlNon4wPm__root__Operating__root__MovingLeft(int *ctr, FControlNon4wPm *self,
                                                                               FControlNon4wPm__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change70.IsTriggered)
    {
        if ((!(self->D12inRequiredPmPosition.Value ==
               map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value))) ||
            ((self->D12inRequiredPmPosition.Value ==
              map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value)) &&
             (self->D37inConCommonDrive.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change76.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change80.IsTriggered)
    {
        if (!(self->D37inConCommonDrive.Value))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlNon4wPm__root__Operating__root__MovingRight(int *ctr, FControlNon4wPm *self,
                                                                                FControlNon4wPm__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change62.IsTriggered)
    {
        if ((!(self->D12inRequiredPmPosition.Value ==
               map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value))) ||
            ((self->D12inRequiredPmPosition.Value ==
              map_D35inPmPosition_to_D12inRequiredPmPosition(self->D35inPmPosition.Value)) &&
             (self->D37inConCommonDrive.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change77.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change79.IsTriggered)
    {
        if (!(self->D37inConCommonDrive.Value))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlNon4wPm__root__Operating__root__Stopped(int *ctr, FControlNon4wPm *self,
                                                                            FControlNon4wPm__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change64.IsTriggered)
    {
        if ((self->D40inConActive.Value) && (self->D36inConDriveCapability.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change71.IsTriggered)
    {
        if ((self->D40inConActive.Value) && (self->D36inConDriveCapability.Value))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlNon4wPm__root__Operating__root__Waiting(int *ctr, FControlNon4wPm *self,
                                                                            FControlNon4wPm__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change379.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlNon4wPm__root__Operating__root(int *ctr, FControlNon4wPm *self,
                                                                   FControlNon4wPm__root__state_struct *x)
{
    switch (x->Operating.root.state)
    {
    case FControlNon4wPm__root__Operating__root__MovingLeft:
        count_transitions_from_FControlNon4wPm__root__Operating__root__MovingLeft(ctr, self, x);
        break;
    case FControlNon4wPm__root__Operating__root__MovingRight:
        count_transitions_from_FControlNon4wPm__root__Operating__root__MovingRight(ctr, self, x);
        break;
    case FControlNon4wPm__root__Operating__root__Stopped:
        count_transitions_from_FControlNon4wPm__root__Operating__root__Stopped(ctr, self, x);
        break;
    case FControlNon4wPm__root__Operating__root__Waiting:
        count_transitions_from_FControlNon4wPm__root__Operating__root__Waiting(ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlNon4wPm__root__Operating(int *ctr, FControlNon4wPm *self,
                                                             FControlNon4wPm__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FControlNon4wPm__root__Operating__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change394.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlNon4wPm__root(int *ctr, FControlNon4wPm *self,
                                                  FControlNon4wPm__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlNon4wPm__root__Operating:
        count_transitions_from_FControlNon4wPm__root__Operating(ctr, self, x);
        break;
    }
}

int count_transitions_FControlNon4wPm(FControlNon4wPm *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FControlNon4wPm__root(&ctr, self, &self->state);
    return ctr;
}