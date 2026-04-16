
#include "../../04_OutputC/SubsystemPoint/SSciPCommandAndRecieve.h"

void count_transitions_from_SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands(
    int *ctr, SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1079.IsTriggered)
    {
        if ((self->D30inMovePoint.Value == SSciPCommandAndRecieve_D30inMovePointValue__Right) &&
            (self->D50inPdiConnectionState.Value == SSciPCommandAndRecieve_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (self->Change1080.IsTriggered)
    {
        if ((self->D30inMovePoint.Value == SSciPCommandAndRecieve_D30inMovePointValue__Left) &&
            (self->D50inPdiConnectionState.Value == SSciPCommandAndRecieve_D50inPdiConnectionStateValue__Established))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciPCommandAndRecieve__root__Operating__PointPositionControlling(
    int *ctr, SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    switch (x->Operating.PointPositionControlling.state)
    {
    case SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands:
        count_transitions_from_SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
    int *ctr, SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Left) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotApplicable))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Left) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotDegraded))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Right) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotApplicable))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Right) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotDegraded))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__NoEndPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedLeft))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__NoEndPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedRight))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__NoEndPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotDegraded))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__NoEndPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotApplicable))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Trailed) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedLeft))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Trailed) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedRight))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Trailed) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotDegraded))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Trailed) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotApplicable))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciPCommandAndRecieve__root__Operating__PointPositionObserving(
    int *ctr, SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    switch (x->Operating.PointPositionObserving.state)
    {
    case SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport:
        count_transitions_from_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport(
    int *ctr, SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgAbilityToMovePoint__1f1b.HasMessage)
    {
        if (self->InMsgAbilityToMovePoint__1f1b.Value.ReportedAbilityToMoveState ==
            AbilityToMoveState__ed0f__UnableToMove)
        {
            (*ctr)++;
        }
    }
    if (self->InMsgAbilityToMovePoint__1f1b.HasMessage)
    {
        if (self->InMsgAbilityToMovePoint__1f1b.Value.ReportedAbilityToMoveState ==
            AbilityToMoveState__ed0f__AbleToMove)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving(
    int *ctr, SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    switch (x->Operating.AbilityToMoveObserving.state)
    {
    case SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport:
        count_transitions_from_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciPCommandAndRecieve__root__Operating__TimeOutObserving__RecieveTimeOutReport(
    int *ctr, SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgTimeout__ff4f.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciPCommandAndRecieve__root__Operating__TimeOutObserving(
    int *ctr, SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    switch (x->Operating.TimeOutObserving.state)
    {
    case SSciPCommandAndRecieve__root__Operating__TimeOutObserving__RecieveTimeOutReport:
        count_transitions_from_SSciPCommandAndRecieve__root__Operating__TimeOutObserving__RecieveTimeOutReport(ctr,
                                                                                                               self, x);
        break;
    }
}

void count_transitions_from_SSciPCommandAndRecieve__root__Operating(int *ctr, SSciPCommandAndRecieve *self,
                                                                    SSciPCommandAndRecieve__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_SSciPCommandAndRecieve__root__Operating__PointPositionControlling(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_SSciPCommandAndRecieve__root__Operating__PointPositionObserving(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_SSciPCommandAndRecieve__root__Operating__TimeOutObserving(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciPCommandAndRecieve__root(int *ctr, SSciPCommandAndRecieve *self,
                                                         SSciPCommandAndRecieve__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciPCommandAndRecieve__root__Operating:
        count_transitions_from_SSciPCommandAndRecieve__root__Operating(ctr, self, x);
        break;
    }
}

int count_transitions_SSciPCommandAndRecieve(SSciPCommandAndRecieve *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciPCommandAndRecieve__root(&ctr, self, &self->state);
    return ctr;
}