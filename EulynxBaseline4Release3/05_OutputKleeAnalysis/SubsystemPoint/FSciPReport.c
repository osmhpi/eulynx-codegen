
#include "../../04_OutputC/SubsystemPoint/FSciPReport.h"

void count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove(
    int *ctr, FSciPReport *self, FSciPReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change40.IsTriggered)
    {
        if ((self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established) &&
            (self->D15inConObserveAbilityToMove.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change43.IsTriggered)
    {
        if ((self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established) &&
            (self->D15inConObserveAbilityToMove.Value))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove(
    int *ctr, FSciPReport *self, FSciPReport__root__state_struct *x)
{
    switch (x->ReportingOverallPointStates.ReportingAbilityToMove.state)
    {
    case FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove:
        count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition(
    int *ctr, FSciPReport *self, FSciPReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change8.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change11.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__Waiting(
    int *ctr, FSciPReport *self, FSciPReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change7.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition(
    int *ctr, FSciPReport *self, FSciPReport__root__state_struct *x)
{
    switch (x->ReportingOverallPointStates.ReportingMsgPointPosition.state)
    {
    case FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition:
        count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition(
            ctr, self, x);
        break;
    case FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__Waiting:
        count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__Waiting(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__MsgMovementFailed(
    int *ctr, FSciPReport *self, FSciPReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change95.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed(
    int *ctr, FSciPReport *self, FSciPReport__root__state_struct *x)
{
    switch (x->ReportingOverallPointStates.ReportingMovementFailed.state)
    {
    case FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__MsgMovementFailed:
        count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__MsgMovementFailed(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciPReport__root__ReportingOverallPointStates(int *ctr, FSciPReport *self,
                                                                           FSciPReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change316.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPReport__root__InterfaceConnectionNotEstablished(int *ctr, FSciPReport *self,
                                                                                 FSciPReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InStartStatusReport__1e4e.HasMessage)
    {

        self->OutMsgPointPosition__27c1.Value.ReportedPointPositionState = Cop1PointPosition(self);
        self->OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition = Cop2DegradedPointPosition(self);
        self->OutMsgPointPosition__27c1.HasMessage = 1;
        self->MemLastReportedPointPosition =
            map_D14inObservedPointPosition_to_MemLastReportedPointPosition(self->D14inObservedPointPosition.Value);
        self->MemLastReportedDegradedPointPosition =
            map_D17inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
                self->D17inObservedDegradedPointPosition.Value);
        if (!(self->D15inConObserveAbilityToMove.Value))
        {
            (*ctr)++;
        }
        if (self->D15inConObserveAbilityToMove.Value)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPReport__root(int *ctr, FSciPReport *self, FSciPReport__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciPReport__root__ReportingOverallPointStates:
        count_transitions_from_FSciPReport__root__ReportingOverallPointStates(ctr, self, x);
        break;
    case FSciPReport__root__InterfaceConnectionNotEstablished:
        count_transitions_from_FSciPReport__root__InterfaceConnectionNotEstablished(ctr, self, x);
        break;
    }
}

int count_transitions_FSciPReport(FSciPReport *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciPReport__root(&ctr, self, &self->state);
    return ctr;
}