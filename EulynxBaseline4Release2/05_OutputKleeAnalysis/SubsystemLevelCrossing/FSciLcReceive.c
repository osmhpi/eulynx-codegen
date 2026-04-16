
#include "../../04_OutputC/SubsystemLevelCrossing/FSciLcReceive.h"

void count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated(
    int *ctr, FSciLcReceive *self, FSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdDeactivation__48b5.HasMessage)
    {
        if (self->InCdDeactivation__48b5.Value.CommandedDeactivationState ==
            DeactivationControlableState__514f__Deactivation)
        {
            (*ctr)++;
        }
    }
    if (self->Change433.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated(
    int *ctr, FSciLcReceive *self, FSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdActivation__3513.HasMessage)
    {
        if (self->InCdActivation__3513.Value.CommandedActivationState == ActivationControlableState__4140__Activation)
        {
            (*ctr)++;
        }
    }
    if (self->InCdActivation__3513.HasMessage)
    {
        if (self->InCdActivation__3513.Value.CommandedActivationState ==
            ActivationControlableState__4140__PreActivation)
        {
            (*ctr)++;
        }
    }
    if (self->InCdIsolateLc__add9.HasMessage)
    {
        if (self->InCdIsolateLc__add9.Value.CommandedIsolateState ==
            IsolateLevelCrossingControlableState__55c1__EnableIsolationOfTheLevelCrossing)
        {
            (*ctr)++;
        }
    }
    if (self->Change342.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__PreActivated(
    int *ctr, FSciLcReceive *self, FSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdActivation__3513.HasMessage)
    {
        if (self->InCdActivation__3513.Value.CommandedActivationState == ActivationControlableState__4140__Activation)
        {
            (*ctr)++;
        }
    }
    if (self->InCdDeactivation__48b5.HasMessage)
    {
        if (self->InCdDeactivation__48b5.Value.CommandedDeactivationState ==
            DeactivationControlableState__514f__Deactivation)
        {
            (*ctr)++;
        }
    }
    if (self->Change344.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Isolated(
    int *ctr, FSciLcReceive *self, FSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdIsolateLc__add9.HasMessage)
    {
        if (self->InCdIsolateLc__add9.Value.CommandedIsolateState ==
            IsolateLevelCrossingControlableState__55c1__DisableIsolationOfTheLevelCrossing)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState(
    int *ctr, FSciLcReceive *self, FSciLcReceive__root__state_struct *x)
{
    switch (x->ReceivingLevelCrossingCommands.ReceivingActivationState.state)
    {
    case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated:
        count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated(
            ctr, self, x);
        break;
    case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated:
        count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated(
            ctr, self, x);
        break;
    case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__PreActivated:
        count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__PreActivated(
            ctr, self, x);
        break;
    case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Isolated:
        count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Isolated(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__Waiting(
    int *ctr, FSciLcReceive *self, FSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdLocalOperationHandover__2b72.HasMessage)
    {
        if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
            LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorEstablished)
        {
            (*ctr)++;
        }
    }
    if (self->InCdLocalOperationHandover__2b72.HasMessage)
    {
        if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
            LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorInitiated)
        {
            (*ctr)++;
        }
    }
    if (self->InCdLocalOperationHandover__2b72.HasMessage)
    {
        if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
            LocalOperationHandoverControlableState__9164__NoHandOverToLocalOperator)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator(
    int *ctr, FSciLcReceive *self, FSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdLocalOperationHandover__2b72.HasMessage)
    {
        if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
            LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorInitiated)
        {
            (*ctr)++;
        }
    }
    if (self->InCdLocalOperationHandover__2b72.HasMessage)
    {
        if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
            LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorEstablished)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated(
    int *ctr, FSciLcReceive *self, FSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdLocalOperationHandover__2b72.HasMessage)
    {
        if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
            LocalOperationHandoverControlableState__9164__NoHandOverToLocalOperator)
        {
            (*ctr)++;
        }
    }
    if (self->InCdLocalOperationHandover__2b72.HasMessage)
    {
        if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
            LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorEstablished)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished(
    int *ctr, FSciLcReceive *self, FSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdLocalOperationHandover__2b72.HasMessage)
    {
        if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
            LocalOperationHandoverControlableState__9164__NoHandOverToLocalOperator)
        {
            (*ctr)++;
        }
    }
    if (self->InCdLocalOperationHandover__2b72.HasMessage)
    {
        if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
            LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorInitiated)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover(
    int *ctr, FSciLcReceive *self, FSciLcReceive__root__state_struct *x)
{
    switch (x->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover.state)
    {
    case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__Waiting:
        count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__Waiting(
            ctr, self, x);
        break;
    case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator:
        count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator(
            ctr, self, x);
        break;
    case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated:
        count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated(
            ctr, self, x);
        break;
    case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished:
        count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands(int *ctr, FSciLcReceive *self,
                                                                                FSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover(&tmp,
                                                                                                              self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change340.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change345.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change368.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLcReceive__root__FallbackMode(int *ctr, FSciLcReceive *self,
                                                              FSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change347.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLcReceive__root__Waiting(int *ctr, FSciLcReceive *self,
                                                         FSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change341.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLcReceive__root(int *ctr, FSciLcReceive *self, FSciLcReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciLcReceive__root__ReceivingLevelCrossingCommands:
        count_transitions_from_FSciLcReceive__root__ReceivingLevelCrossingCommands(ctr, self, x);
        break;
    case FSciLcReceive__root__FallbackMode:
        count_transitions_from_FSciLcReceive__root__FallbackMode(ctr, self, x);
        break;
    case FSciLcReceive__root__Waiting:
        count_transitions_from_FSciLcReceive__root__Waiting(ctr, self, x);
        break;
    }
}

int count_transitions_FSciLcReceive(FSciLcReceive *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciLcReceive__root(&ctr, self, &self->state);
    return ctr;
}