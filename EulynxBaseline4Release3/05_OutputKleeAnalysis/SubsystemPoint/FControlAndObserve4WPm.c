
#include "../../04_OutputC/SubsystemPoint/FControlAndObserve4WPm.h"

void count_transitions_from_FControlAndObserve4WPm__root__Operating__root__Detection(
    int *ctr, FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change71.IsTriggered)
    {
        if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change77.IsTriggered)
    {
        if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change177.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change178.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change179.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change180.IsTriggered)
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

    if (self->Change68.IsTriggered)
    {
        if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change80.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change84.IsTriggered)
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

    if (self->Change74.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change76.IsTriggered)
    {
        if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change81.IsTriggered)
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
    if (self->Change328.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change372.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change176.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change557.IsTriggered)
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

    if (self->Change329.IsTriggered)
    {
        if (self->D45inConActive.Value)
        {

            if ((self->D20inConDriveCapability.Value) && (!(self->D26inInternalTriggerAbilityToMovePmAvailable.Value)))
            {
                (*ctr)++;
            }
            if (!(self->D20inConDriveCapability.Value))
            {
                (*ctr)++;
            }
            if ((self->D20inConDriveCapability.Value) && (self->D26inInternalTriggerAbilityToMovePmAvailable.Value))
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