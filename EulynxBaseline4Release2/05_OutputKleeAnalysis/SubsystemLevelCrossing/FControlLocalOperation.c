
#include "../../04_OutputC/SubsystemLevelCrossing/FControlLocalOperation.h"

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__Waiting(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change484.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change486.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change490.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change483.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change489.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change491.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change487.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change488.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change485.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    switch (x->ControlLocalOperation.CommandHandoverToLocalOperation.state)
    {
    case FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__Waiting:
        count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__Waiting(
            ctr, self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated:
        count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated(
            ctr, self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished:
        count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished(
            ctr, self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover:
        count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Allow(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change474.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Return(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change473.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Waiting(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change472.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change476.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    switch (x->ControlLocalOperation.ReceiveInputForLocalOperationByLocalOperator.state)
    {
    case FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Allow:
        count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Allow(
            ctr, self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Return:
        count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Return(
            ctr, self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Waiting:
        count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Waiting(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__Waiting(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change479.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change482.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToActivate(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change481.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToDeactivate(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change480.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    switch (x->ControlLocalOperation.RequestByLocalOperator.state)
    {
    case FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__Waiting:
        count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__Waiting(
            ctr, self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToActivate:
        count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToActivate(
            ctr, self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToDeactivate:
        count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToDeactivate(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlLocalOperation__root__ControlLocalOperation(
    int *ctr, FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLocalOperation__root(int *ctr, FControlLocalOperation *self,
                                                         FControlLocalOperation__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlLocalOperation__root__ControlLocalOperation:
        count_transitions_from_FControlLocalOperation__root__ControlLocalOperation(ctr, self, x);
        break;
    }
}

int count_transitions_FControlLocalOperation(FControlLocalOperation *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FControlLocalOperation__root(&ctr, self, &self->state);
    return ctr;
}