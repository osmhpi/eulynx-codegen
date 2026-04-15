
#include "../../04_OutputC/SubsystemPoint/SSciPReceive.h"

void count_transitions_from_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
    int *ctr, SSciPReceive *self, SSciPReceive__root__state_struct *x)
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
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__UnintendedPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedLeft))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__UnintendedPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedRight))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__UnintendedPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotDegraded))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__UnintendedPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotApplicable))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciPReceive__root__Operating__PointPositionObserving(int *ctr, SSciPReceive *self,
                                                                                  SSciPReceive__root__state_struct *x)
{
    switch (x->Operating.PointPositionObserving.state)
    {
    case SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport:
        count_transitions_from_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport(
    int *ctr, SSciPReceive *self, SSciPReceive__root__state_struct *x)
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

void count_transitions_from_SSciPReceive__root__Operating__AbilityToMoveObserving(int *ctr, SSciPReceive *self,
                                                                                  SSciPReceive__root__state_struct *x)
{
    switch (x->Operating.AbilityToMoveObserving.state)
    {
    case SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport:
        count_transitions_from_SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciPReceive__root__Operating__MovementFailedObserving__ReceiveMovementFailedReport(
    int *ctr, SSciPReceive *self, SSciPReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgMovementFailed__ff4f.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciPReceive__root__Operating__MovementFailedObserving(int *ctr, SSciPReceive *self,
                                                                                   SSciPReceive__root__state_struct *x)
{
    switch (x->Operating.MovementFailedObserving.state)
    {
    case SSciPReceive__root__Operating__MovementFailedObserving__ReceiveMovementFailedReport:
        count_transitions_from_SSciPReceive__root__Operating__MovementFailedObserving__ReceiveMovementFailedReport(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciPReceive__root__Operating(int *ctr, SSciPReceive *self,
                                                          SSciPReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_SSciPReceive__root__Operating__PointPositionObserving(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_SSciPReceive__root__Operating__AbilityToMoveObserving(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_SSciPReceive__root__Operating__MovementFailedObserving(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciPReceive__root(int *ctr, SSciPReceive *self, SSciPReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciPReceive__root__Operating:
        count_transitions_from_SSciPReceive__root__Operating(ctr, self, x);
        break;
    }
}

int count_transitions_SSciPReceive(SSciPReceive *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciPReceive__root(&ctr, self, &self->state);
    return ctr;
}