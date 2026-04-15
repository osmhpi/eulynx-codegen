
#include "../../04_OutputC/SubsystemLevelCrossing/SSciLcReceive.h"

void count_transitions_from_SSciLcReceive__root__ReceivingLcReports(int *ctr, SSciLcReceive *self,
                                                                    SSciLcReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgDetectionElementStatus__aa8b.HasMessage)
    {
        if (self->InMsgDetectionElementStatus__aa8b.Value.ReportedDetectionElementStatusState ==
            DetectionElementStatusState__4b10__DetectionElementIsFailed)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgDetectionElementStatus__aa8b.HasMessage)
    {
        if (self->InMsgDetectionElementStatus__aa8b.Value.ReportedDetectionElementStatusState ==
            DetectionElementStatusState__4b10__DetectionElementIsOccupied)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgDetectionElementStatus__aa8b.HasMessage)
    {
        if (self->InMsgDetectionElementStatus__aa8b.Value.ReportedDetectionElementStatusState ==
            DetectionElementStatusState__4b10__DetectionElementIsVacant)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgLcFailureStatus__5440.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InMsgLcFunctionalStatus__ab8c.HasMessage)
    {
        if (self->InMsgLcFunctionalStatus__ab8c.Value.ReportedActivationlStatusState ==
            FunctionalStatusState__5d12__IsolatedLC)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgLcFunctionalStatus__ab8c.HasMessage)
    {
        if (self->InMsgLcFunctionalStatus__ab8c.Value.ReportedActivationlStatusState ==
            FunctionalStatusState__5d12__PreActivated)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgLcFunctionalStatus__ab8c.HasMessage)
    {
        if (self->InMsgLcFunctionalStatus__ab8c.Value.ReportedActivationlStatusState ==
            FunctionalStatusState__5d12__ActivatedAndProtected)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgLcFunctionalStatus__ab8c.HasMessage)
    {
        if (self->InMsgLcFunctionalStatus__ab8c.Value.ReportedActivationlStatusState ==
            FunctionalStatusState__5d12__ActivatedAndUnprotected)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgLcFunctionalStatus__ab8c.HasMessage)
    {
        if (self->InMsgLcFunctionalStatus__ab8c.Value.ReportedActivationlStatusState ==
            FunctionalStatusState__5d12__DeactivatingAndUnprotected)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgLcFunctionalStatus__ab8c.HasMessage)
    {
        if (self->InMsgLcFunctionalStatus__ab8c.Value.ReportedActivationlStatusState ==
            FunctionalStatusState__5d12__DeactivatedAndIdle)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgLcMonitoringStatus__1d45.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InMsgLocalOperationHandover__0594.HasMessage)
    {
        if (self->InMsgLocalOperationHandover__0594.Value.ReportedLocalOperationHandoverState ==
            LocalOperationHandoverState__ee05__ReturnHandoverFromLocalOperator)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgLocalOperationHandover__0594.HasMessage)
    {
        if (self->InMsgLocalOperationHandover__0594.Value.ReportedLocalOperationHandoverState ==
            LocalOperationHandoverState__ee05__AllowHandovertoLocalOperator)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgLocalRequest__daeb.HasMessage)
    {
        if (self->InMsgLocalRequest__daeb.Value.ReportedLocalRequestState ==
            LocalRequestState__d488__LocalRequestToActivateTheLevelCrossing)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgLocalRequest__daeb.HasMessage)
    {
        if (self->InMsgLocalRequest__daeb.Value.ReportedLocalRequestState ==
            LocalRequestState__d488__LocalRequestToDeactivateTheLevelCrossing)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgObstacleDetectionStatus__734d.HasMessage)
    {
        if (self->InMsgObstacleDetectionStatus__734d.Value.ReportedObstacleDetectionStatusState ==
            ObstacleDetectionStatusState__5aa0__ObstacleInTheConflictArea)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgObstacleDetectionStatus__734d.HasMessage)
    {
        if (self->InMsgObstacleDetectionStatus__734d.Value.ReportedObstacleDetectionStatusState ==
            ObstacleDetectionStatusState__5aa0__NoObstacleInTheConflictArea)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciLcReceive__root(int *ctr, SSciLcReceive *self, SSciLcReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciLcReceive__root__ReceivingLcReports:
        count_transitions_from_SSciLcReceive__root__ReceivingLcReports(ctr, self, x);
        break;
    }
}

int count_transitions_SSciLcReceive(SSciLcReceive *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciLcReceive__root(&ctr, self, &self->state);
    return ctr;
}