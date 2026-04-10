
#include "SSciPReceive.h"

// Value Conversion Functions

// Operations

void make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
    SSciPReceive *self, SSciPReceive__root__Operating__PointPositionObserving__state_struct *region)
{
    LOG("[SSciPReceive] Entering state "
        "ReceiveOverallPointPositionAndDegradedPointPositionReport in region "
        "root__Operating__PointPositionObserving");
    region->state =
        SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport;
};

void make_state_SSciPReceive__root__Operating__PointPositionObserving(
    SSciPReceive *self, SSciPReceive__root__Operating__PointPositionObserving__state_struct *x)
{
    memset(x, 0, sizeof(SSciPReceive__root__Operating__PointPositionObserving__state_struct));

    make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
        self, x);
    return;
}

void make_state_SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport(
    SSciPReceive *self, SSciPReceive__root__Operating__AbilityToMoveObserving__state_struct *region)
{
    LOG("[SSciPReceive] Entering state ReceiveAbilityToMoveReport in region "
        "root__Operating__AbilityToMoveObserving");
    region->state = SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport;
};

void make_state_SSciPReceive__root__Operating__AbilityToMoveObserving(
    SSciPReceive *self, SSciPReceive__root__Operating__AbilityToMoveObserving__state_struct *x)
{
    memset(x, 0, sizeof(SSciPReceive__root__Operating__AbilityToMoveObserving__state_struct));

    make_state_SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport(self, x);
    return;
}

void make_state_SSciPReceive__root__Operating__MovementFailedObserving__ReceiveMovementFailedReport(
    SSciPReceive *self, SSciPReceive__root__Operating__MovementFailedObserving__state_struct *region)
{
    LOG("[SSciPReceive] Entering state ReceiveMovementFailedReport in region "
        "root__Operating__MovementFailedObserving");
    region->state = SSciPReceive__root__Operating__MovementFailedObserving__ReceiveMovementFailedReport;
};

void make_state_SSciPReceive__root__Operating__MovementFailedObserving(
    SSciPReceive *self, SSciPReceive__root__Operating__MovementFailedObserving__state_struct *x)
{
    memset(x, 0, sizeof(SSciPReceive__root__Operating__MovementFailedObserving__state_struct));

    make_state_SSciPReceive__root__Operating__MovementFailedObserving__ReceiveMovementFailedReport(self, x);
    return;
}

void make_state_SSciPReceive__root__Operating(SSciPReceive *self, SSciPReceive__root__state_struct *region)
{
    LOG("[SSciPReceive] Entering state Operating in region root");
    region->state = SSciPReceive__root__Operating;
    make_state_SSciPReceive__root__Operating__PointPositionObserving(self, &region->Operating.PointPositionObserving);
    make_state_SSciPReceive__root__Operating__AbilityToMoveObserving(self, &region->Operating.AbilityToMoveObserving);
    make_state_SSciPReceive__root__Operating__MovementFailedObserving(self, &region->Operating.MovementFailedObserving);
};

void make_state_SSciPReceive__root(SSciPReceive *self, SSciPReceive__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciPReceive__root__state_struct));

    make_state_SSciPReceive__root__Operating(self, x);
    return;
}

void transition_from_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
    SSciPReceive *self, SSciPReceive__root__state_struct *x)
{

    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Left) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotApplicable))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__LeftAndNotApplicable;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Left) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotDegraded))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__LeftAndNotDegraded;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Right) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotApplicable))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__RightAndNotApplicable;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Right) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotDegraded))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__RightAndNotDegraded;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__NoEndPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedLeft))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__NoEndPositionAndDegradedLeft;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__NoEndPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedRight))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__NoEndPositionAndDegradedRight;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__NoEndPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotDegraded))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__NoEndPositionAndNotDegraded;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__NoEndPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotApplicable))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__NoEndPositionAndNotApplicable;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__UnintendedPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedLeft))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__UnintendedPositionAndDegradedLeft;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__UnintendedPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedRight))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__UnintendedPositionAndDegradedRight;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__UnintendedPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotDegraded))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__UnintendedPositionAndNotDegraded;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState ==
             PointPositionState__2e6f__UnintendedPosition) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotApplicable))
        {
            self->D5outPointPosition.Value = SSciPReceive_D5outPointPositionValue__UnintendedPositionAndNotApplicable;
            self->D5outPointPosition.IsSignalled = true;
            self->T4outPointPosition.Trigger = true;
            make_state_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
}

void transition_from_SSciPReceive__root__Operating__PointPositionObserving(SSciPReceive *self,
                                                                           SSciPReceive__root__state_struct *x)
{
    switch (x->Operating.PointPositionObserving.state)
    {
    case SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport:
        transition_from_SSciPReceive__root__Operating__PointPositionObserving__ReceiveOverallPointPositionAndDegradedPointPositionReport(
            self, x);
        break;
    }
}

void transition_from_SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport(
    SSciPReceive *self, SSciPReceive__root__state_struct *x)
{

    if (self->InMsgAbilityToMovePoint__1f1b.HasMessage)
    {
        if (self->InMsgAbilityToMovePoint__1f1b.Value.ReportedAbilityToMoveState ==
            AbilityToMoveState__ed0f__UnableToMove)
        {
            self->D8outAbilityToMove.Value = SSciPReceive_D8outAbilityToMoveValue__UnableToMove;
            self->D8outAbilityToMove.IsSignalled = true;
            self->T7outAbilityToMove.Trigger = true;
            make_state_SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport(
                self, &x->Operating.AbilityToMoveObserving);
            return;
        }
    }
    if (self->InMsgAbilityToMovePoint__1f1b.HasMessage)
    {
        if (self->InMsgAbilityToMovePoint__1f1b.Value.ReportedAbilityToMoveState ==
            AbilityToMoveState__ed0f__AbleToMove)
        {
            self->D8outAbilityToMove.Value = SSciPReceive_D8outAbilityToMoveValue__AbleToMove;
            self->D8outAbilityToMove.IsSignalled = true;
            self->T7outAbilityToMove.Trigger = true;
            make_state_SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport(
                self, &x->Operating.AbilityToMoveObserving);
            return;
        }
    }
}

void transition_from_SSciPReceive__root__Operating__AbilityToMoveObserving(SSciPReceive *self,
                                                                           SSciPReceive__root__state_struct *x)
{
    switch (x->Operating.AbilityToMoveObserving.state)
    {
    case SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport:
        transition_from_SSciPReceive__root__Operating__AbilityToMoveObserving__ReceiveAbilityToMoveReport(self, x);
        break;
    }
}

void transition_from_SSciPReceive__root__Operating__MovementFailedObserving__ReceiveMovementFailedReport(
    SSciPReceive *self, SSciPReceive__root__state_struct *x)
{

    if (self->InMsgMovementFailed__ff4f.HasMessage)
    {
        self->T6outMovementFailed.Trigger = true;
        make_state_SSciPReceive__root__Operating__MovementFailedObserving__ReceiveMovementFailedReport(
            self, &x->Operating.MovementFailedObserving);
        return;
    }
}

void transition_from_SSciPReceive__root__Operating__MovementFailedObserving(SSciPReceive *self,
                                                                            SSciPReceive__root__state_struct *x)
{
    switch (x->Operating.MovementFailedObserving.state)
    {
    case SSciPReceive__root__Operating__MovementFailedObserving__ReceiveMovementFailedReport:
        transition_from_SSciPReceive__root__Operating__MovementFailedObserving__ReceiveMovementFailedReport(self, x);
        break;
    }
}

void transition_from_SSciPReceive__root__Operating(SSciPReceive *self, SSciPReceive__root__state_struct *x)
{
    transition_from_SSciPReceive__root__Operating__PointPositionObserving(self, x);
    transition_from_SSciPReceive__root__Operating__AbilityToMoveObserving(self, x);
    transition_from_SSciPReceive__root__Operating__MovementFailedObserving(self, x);
}

void transition_from_SSciPReceive__root(SSciPReceive *self, SSciPReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciPReceive__root__Operating:
        transition_from_SSciPReceive__root__Operating(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciPReceive *self)
{
}

static void resetOutputs(SSciPReceive *self)
{

    self->T4outPointPosition.Trigger = false;
    self->T6outMovementFailed.Trigger = false;
    self->T7outAbilityToMove.Trigger = false;

    self->D5outPointPosition.IsSignalled = false;
    self->D8outAbilityToMove.IsSignalled = false;
}

static void resetTriggers(SSciPReceive *self)
{
    self->InMsgPointPosition__27c1.HasMessage = false;
    self->InMsgAbilityToMovePoint__1f1b.HasMessage = false;
    self->InMsgMovementFailed__ff4f.HasMessage = false;
}

void transition_SSciPReceive(SSciPReceive *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciPReceive__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciPReceive(SSciPReceive *self)
{
    make_state_SSciPReceive__root(self, &self->state);
}
