
#include "../../04_OutputC/SubsystemPoint/FControlAndObserve4WPm.h"

void count_transitions_from_FControlAndObserve4WPm__root__Operating__root__Detection(
    int *ctr, FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change61.IsTriggered)
    {
        if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change67.IsTriggered)
    {
        if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change201.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change202.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change203.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change204.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlAndObserve4WPm__root__Operating__root__MovingRightPm(
    int *ctr, FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change63.IsTriggered)
    {
        if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change72.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change78.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlAndObserve4WPm__root__Operating__root__MovingLeftPm(
    int *ctr, FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change66.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change68.IsTriggered)
    {
        if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change74.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlAndObserve4WPm__root__Operating__root(int *ctr, FControlAndObserve4WPm *self,
                                                                          FControlAndObserve4WPm__root__state_struct *x)
{
    switch (x->Operating.root.state)
    {
    case FControlAndObserve4WPm__root__Operating__root__Detection:
        count_transitions_from_FControlAndObserve4WPm__root__Operating__root__Detection(ctr, self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__root__MovingRightPm:
        count_transitions_from_FControlAndObserve4WPm__root__Operating__root__MovingRightPm(ctr, self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__root__MovingLeftPm:
        count_transitions_from_FControlAndObserve4WPm__root__Operating__root__MovingLeftPm(ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlAndObserve4WPm__root__Operating(int *ctr, FControlAndObserve4WPm *self,
                                                                    FControlAndObserve4WPm__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FControlAndObserve4WPm__root__Operating__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change354.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change392.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change200.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change565.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlAndObserve4WPm__root__WaitingForInitialising(
    int *ctr, FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change353.IsTriggered)
    {
        if (self->D45inConActive.Value)
        {

            if ((self->D20inConDriveCapability.Value) && (!(self->D26inDriveVoltageAvailable.Value)))
            {
                (*ctr)++;
            }
            if (!(self->D20inConDriveCapability.Value))
            {
                (*ctr)++;
            }
            if ((self->D20inConDriveCapability.Value) && (self->D26inDriveVoltageAvailable.Value))
            {
                (*ctr)++;
            }
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlAndObserve4WPm__root(int *ctr, FControlAndObserve4WPm *self,
                                                         FControlAndObserve4WPm__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlAndObserve4WPm__root__Operating:
        count_transitions_from_FControlAndObserve4WPm__root__Operating(ctr, self, x);
        break;
    case FControlAndObserve4WPm__root__WaitingForInitialising:
        count_transitions_from_FControlAndObserve4WPm__root__WaitingForInitialising(ctr, self, x);
        break;
    }
}

int count_transitions_FControlAndObserve4WPm(FControlAndObserve4WPm *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FControlAndObserve4WPm__root(&ctr, self, &self->state);
    return ctr;
}