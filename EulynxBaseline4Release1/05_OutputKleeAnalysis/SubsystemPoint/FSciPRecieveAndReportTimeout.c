
#include "../../04_OutputC/SubsystemPoint/FSciPRecieveAndReportTimeout.h"

void count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft(
    int *ctr, FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (true)
    {
        (*ctr)++;
    }
    if (self->Time20.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Right) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change251.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change428.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
    int *ctr, FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Left) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Right) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight(
    int *ctr, FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (true)
    {
        (*ctr)++;
    }
    if (self->Time19.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Left) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change250.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change429.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Waiting(
    int *ctr, FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Left) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Right) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand(
    int *ctr, FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    switch (x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand.state)
    {
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft:
        count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft(
            ctr, self, x);
        break;
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded:
        count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
            ctr, self, x);
        break;
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight:
        count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight(
            ctr, self, x);
        break;
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Waiting:
        count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Waiting(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout(
    int *ctr, FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change275.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change276.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change277.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change278.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout(
    int *ctr, FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    switch (x->RecievingCommandsAndReportingTimeout.ReportingPointTimeout.state)
    {
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout:
        count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout(
    int *ctr, FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change328.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciPRecieveAndReportTimeout__root(int *ctr, FSciPRecieveAndReportTimeout *self,
                                                               FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout:
        count_transitions_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout(ctr, self, x);
        break;
    }
}

int count_transitions_FSciPRecieveAndReportTimeout(FSciPRecieveAndReportTimeout *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciPRecieveAndReportTimeout__root(&ctr, self, &self->state);
    return ctr;
}