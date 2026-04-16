
#include "SSciPCommandAndRecieve.h"

// Value Conversion Functions

// Operations

void make_state_SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands(
    SSciPCommandAndRecieve *self,
    SSciPCommandAndRecieve__root__Operating__PointPositionControlling__state_struct *region)
{
    LOG("[SSciPCommandAndRecieve] Entering state SendingCommands in region root__Operating__PointPositionControlling");
    region->state = SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands;
};

void make_state_SSciPCommandAndRecieve__root__Operating__PointPositionControlling(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__Operating__PointPositionControlling__state_struct *x)
{
    memset(x, 0, sizeof(SSciPCommandAndRecieve__root__Operating__PointPositionControlling__state_struct));

    make_state_SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands(self, x);
    return;
}

void make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__Operating__PointPositionObserving__state_struct *region)
{
    LOG("[SSciPCommandAndRecieve] Entering state RecieveOverallPointPositionAndDegradedPointPositionReport in region "
        "root__Operating__PointPositionObserving");
    region->state =
        SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport;
};

void make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__Operating__PointPositionObserving__state_struct *x)
{
    memset(x, 0, sizeof(SSciPCommandAndRecieve__root__Operating__PointPositionObserving__state_struct));

    make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
        self, x);
    return;
}

void make_state_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__state_struct *region)
{
    LOG("[SSciPCommandAndRecieve] Entering state RecieveAbilityToMoveReport in region "
        "root__Operating__AbilityToMoveObserving");
    region->state = SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport;
};

void make_state_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__state_struct *x)
{
    memset(x, 0, sizeof(SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__state_struct));

    make_state_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport(self, x);
    return;
}

void make_state_SSciPCommandAndRecieve__root__Operating__TimeOutObserving__RecieveTimeOutReport(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__Operating__TimeOutObserving__state_struct *region)
{
    LOG("[SSciPCommandAndRecieve] Entering state RecieveTimeOutReport in region root__Operating__TimeOutObserving");
    region->state = SSciPCommandAndRecieve__root__Operating__TimeOutObserving__RecieveTimeOutReport;
};

void make_state_SSciPCommandAndRecieve__root__Operating__TimeOutObserving(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__Operating__TimeOutObserving__state_struct *x)
{
    memset(x, 0, sizeof(SSciPCommandAndRecieve__root__Operating__TimeOutObserving__state_struct));

    make_state_SSciPCommandAndRecieve__root__Operating__TimeOutObserving__RecieveTimeOutReport(self, x);
    return;
}

void make_state_SSciPCommandAndRecieve__root__Operating(SSciPCommandAndRecieve *self,
                                                        SSciPCommandAndRecieve__root__state_struct *region)
{
    LOG("[SSciPCommandAndRecieve] Entering state Operating in region root");
    region->state = SSciPCommandAndRecieve__root__Operating;
    make_state_SSciPCommandAndRecieve__root__Operating__PointPositionControlling(
        self, &region->Operating.PointPositionControlling);
    make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving(
        self, &region->Operating.PointPositionObserving);
    make_state_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving(
        self, &region->Operating.AbilityToMoveObserving);
    make_state_SSciPCommandAndRecieve__root__Operating__TimeOutObserving(self, &region->Operating.TimeOutObserving);
};

void make_state_SSciPCommandAndRecieve__root(SSciPCommandAndRecieve *self,
                                             SSciPCommandAndRecieve__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciPCommandAndRecieve__root__state_struct));

    make_state_SSciPCommandAndRecieve__root__Operating(self, x);
    return;
}

void transition_from_SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{

    if (self->Change1079.IsTriggered)
    {
        if ((self->D30inMovePoint.Value == SSciPCommandAndRecieve_D30inMovePointValue__Right) &&
            (self->D50inPdiConnectionState.Value == SSciPCommandAndRecieve_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdMovePoint__342e.Value.CommandedPointPositionState = PointPositionControlableState__14bc__Right;
            self->OutCdMovePoint__342e.HasMessage = 1;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands(
                self, &x->Operating.PointPositionControlling);
            return;
        }
    }
    if (self->Change1080.IsTriggered)
    {
        if ((self->D30inMovePoint.Value == SSciPCommandAndRecieve_D30inMovePointValue__Left) &&
            (self->D50inPdiConnectionState.Value == SSciPCommandAndRecieve_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdMovePoint__342e.Value.CommandedPointPositionState = PointPositionControlableState__14bc__Left;
            self->OutCdMovePoint__342e.HasMessage = 1;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands(
                self, &x->Operating.PointPositionControlling);
            return;
        }
    }
}

void transition_from_SSciPCommandAndRecieve__root__Operating__PointPositionControlling(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    switch (x->Operating.PointPositionControlling.state)
    {
    case SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands:
        transition_from_SSciPCommandAndRecieve__root__Operating__PointPositionControlling__SendingCommands(self, x);
        break;
    }
}

void transition_from_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{

    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Left) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotApplicable))
        {
            self->D32outPointPosition.Value = SSciPCommandAndRecieve_D32outPointPositionValue__LeftAndNotApplicable;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
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
            self->D32outPointPosition.Value = SSciPCommandAndRecieve_D32outPointPositionValue__LeftAndNotDegraded;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
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
            self->D32outPointPosition.Value = SSciPCommandAndRecieve_D32outPointPositionValue__RightAndNotApplicable;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
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
            self->D32outPointPosition.Value = SSciPCommandAndRecieve_D32outPointPositionValue__RightAndNotDegraded;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
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
            self->D32outPointPosition.Value =
                SSciPCommandAndRecieve_D32outPointPositionValue__NoEndPositionAndDegradedLeft;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
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
            self->D32outPointPosition.Value =
                SSciPCommandAndRecieve_D32outPointPositionValue__NoEndPositionAndDegradedRight;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
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
            self->D32outPointPosition.Value =
                SSciPCommandAndRecieve_D32outPointPositionValue__NoEndPositionAndNotDegraded;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
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
            self->D32outPointPosition.Value =
                SSciPCommandAndRecieve_D32outPointPositionValue__NoEndPositionAndNotApplicable;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Trailed) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedLeft))
        {
            self->D32outPointPosition.Value = SSciPCommandAndRecieve_D32outPointPositionValue__TrailedAndDegradedLeft;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Trailed) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__DegradedRight))
        {
            self->D32outPointPosition.Value = SSciPCommandAndRecieve_D32outPointPositionValue__TrailedAndDegradedRight;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Trailed) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotDegraded))
        {
            self->D32outPointPosition.Value = SSciPCommandAndRecieve_D32outPointPositionValue__TrailedAndNotDegraded;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
    if (self->InMsgPointPosition__27c1.HasMessage)
    {
        if ((self->InMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Trailed) &&
            (self->InMsgPointPosition__27c1.Value.ReportedDegradedPointPosition ==
             PointPositionDegradedState__422e__NotApplicable))
        {
            self->D32outPointPosition.Value = SSciPCommandAndRecieve_D32outPointPositionValue__TrailedAndNotApplicable;
            self->D32outPointPosition.IsSignalled = true;
            self->T32outPointPosition.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
                self, &x->Operating.PointPositionObserving);
            return;
        }
    }
}

void transition_from_SSciPCommandAndRecieve__root__Operating__PointPositionObserving(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    switch (x->Operating.PointPositionObserving.state)
    {
    case SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport:
        transition_from_SSciPCommandAndRecieve__root__Operating__PointPositionObserving__RecieveOverallPointPositionAndDegradedPointPositionReport(
            self, x);
        break;
    }
}

void transition_from_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{

    if (self->InMsgAbilityToMovePoint__1f1b.HasMessage)
    {
        if (self->InMsgAbilityToMovePoint__1f1b.Value.ReportedAbilityToMoveState ==
            AbilityToMoveState__ed0f__UnableToMove)
        {
            self->D33outAbilityToMove.Value = SSciPCommandAndRecieve_D33outAbilityToMoveValue__UnableToMove;
            self->D33outAbilityToMove.IsSignalled = true;
            self->T33outAbilityToMove.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport(
                self, &x->Operating.AbilityToMoveObserving);
            return;
        }
    }
    if (self->InMsgAbilityToMovePoint__1f1b.HasMessage)
    {
        if (self->InMsgAbilityToMovePoint__1f1b.Value.ReportedAbilityToMoveState ==
            AbilityToMoveState__ed0f__AbleToMove)
        {
            self->D33outAbilityToMove.Value = SSciPCommandAndRecieve_D33outAbilityToMoveValue__AbleToMove;
            self->D33outAbilityToMove.IsSignalled = true;
            self->T33outAbilityToMove.Trigger = true;
            make_state_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport(
                self, &x->Operating.AbilityToMoveObserving);
            return;
        }
    }
}

void transition_from_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    switch (x->Operating.AbilityToMoveObserving.state)
    {
    case SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport:
        transition_from_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving__RecieveAbilityToMoveReport(
            self, x);
        break;
    }
}

void transition_from_SSciPCommandAndRecieve__root__Operating__TimeOutObserving__RecieveTimeOutReport(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{

    if (self->InMsgTimeout__ff4f.HasMessage)
    {
        self->T31outTimeout.Trigger = true;
        make_state_SSciPCommandAndRecieve__root__Operating__TimeOutObserving__RecieveTimeOutReport(
            self, &x->Operating.TimeOutObserving);
        return;
    }
}

void transition_from_SSciPCommandAndRecieve__root__Operating__TimeOutObserving(
    SSciPCommandAndRecieve *self, SSciPCommandAndRecieve__root__state_struct *x)
{
    switch (x->Operating.TimeOutObserving.state)
    {
    case SSciPCommandAndRecieve__root__Operating__TimeOutObserving__RecieveTimeOutReport:
        transition_from_SSciPCommandAndRecieve__root__Operating__TimeOutObserving__RecieveTimeOutReport(self, x);
        break;
    }
}

void transition_from_SSciPCommandAndRecieve__root__Operating(SSciPCommandAndRecieve *self,
                                                             SSciPCommandAndRecieve__root__state_struct *x)
{
    transition_from_SSciPCommandAndRecieve__root__Operating__PointPositionControlling(self, x);
    transition_from_SSciPCommandAndRecieve__root__Operating__PointPositionObserving(self, x);
    transition_from_SSciPCommandAndRecieve__root__Operating__AbilityToMoveObserving(self, x);
    transition_from_SSciPCommandAndRecieve__root__Operating__TimeOutObserving(self, x);
}

void transition_from_SSciPCommandAndRecieve__root(SSciPCommandAndRecieve *self,
                                                  SSciPCommandAndRecieve__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciPCommandAndRecieve__root__Operating:
        transition_from_SSciPCommandAndRecieve__root__Operating(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciPCommandAndRecieve *self)
{
    self->Change1079.IsTriggered = self->T30inMovePoint.IsTriggered;
    self->Change1080.IsTriggered = self->T30inMovePoint.IsTriggered;
}

static void resetOutputs(SSciPCommandAndRecieve *self)
{
    self->OutCdMovePoint__342e.HasMessage = false;

    self->T31outTimeout.Trigger = false;
    self->T32outPointPosition.Trigger = false;
    self->T33outAbilityToMove.Trigger = false;

    self->D32outPointPosition.IsSignalled = false;
    self->D33outAbilityToMove.IsSignalled = false;
}

static void resetTriggers(SSciPCommandAndRecieve *self)
{
    self->InMsgPointPosition__27c1.HasMessage = false;
    self->InMsgAbilityToMovePoint__1f1b.HasMessage = false;
    self->InMsgTimeout__ff4f.HasMessage = false;

    self->T30inMovePoint.IsTriggered = false;

    self->D30inMovePoint.IsSignalled = false;
    self->D50inPdiConnectionState.IsSignalled = false;
}

void transition_SSciPCommandAndRecieve(SSciPCommandAndRecieve *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciPCommandAndRecieve__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciPCommandAndRecieve(SSciPCommandAndRecieve *self)
{
    make_state_SSciPCommandAndRecieve__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemPoint/SSciPCommandAndRecieve.c"
#endif
