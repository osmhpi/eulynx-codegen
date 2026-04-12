
#include "FObserveAbilityToBeForcedToClear.h"

// Value Conversion Functions

// Operations

void make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
    FObserveAbilityToBeForcedToClear *self,
    FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__state_struct *region)
{
    LOG("[FObserveAbilityToBeForcedToClear] Entering state AbleToBeForcedToClear in region "
        "root__ObserveAbilityToBeForcedToClear__root");
    region->state =
        FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear;
};

void make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear(
    FObserveAbilityToBeForcedToClear *self,
    FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__state_struct *region)
{
    LOG("[FObserveAbilityToBeForcedToClear] Entering state NotAbleToBeForcedToClear in region "
        "root__ObserveAbilityToBeForcedToClear__root");
    region->state =
        FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear;
};

void make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root(
    FObserveAbilityToBeForcedToClear *self,
    FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__state_struct));

    if (self->D26inConVariantAIsUsed.Value)
    {
        self->D13outAbleToBeForcedToClear.Value = true;
        make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
            self, x);
        return;
    }
    else
    {
        self->D13outAbleToBeForcedToClear.Value = false;
        make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear(
            self, x);
        return;
    }
}

void make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *region)
{
    LOG("[FObserveAbilityToBeForcedToClear] Entering state ObserveAbilityToBeForcedToClear in region root");
    region->state = FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear;
    make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root(
        self, &region->ObserveAbilityToBeForcedToClear.root);
};

void make_state_FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *region)
{
    LOG("[FObserveAbilityToBeForcedToClear] Entering state WaitingForFinishBooting in region root");
    region->state = FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting;
};

void make_state_FObserveAbilityToBeForcedToClear__root__FallbackMode(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *region)
{
    LOG("[FObserveAbilityToBeForcedToClear] Entering state FallbackMode in region root");
    region->state = FObserveAbilityToBeForcedToClear__root__FallbackMode;
};

void make_state_FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *region)
{
    LOG("[FObserveAbilityToBeForcedToClear] Entering state TechnicalDisturbance in region root");
    region->state = FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance;
};

void make_state_FObserveAbilityToBeForcedToClear__root(FObserveAbilityToBeForcedToClear *self,
                                                       FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveAbilityToBeForcedToClear__root__state_struct));

    make_state_FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting(self, x);
    return;
}

void transition_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{

    if (self->Change110.IsTriggered)
    {
        self->D13outAbleToBeForcedToClear.Value = false;
        make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear(
            self, &x->ObserveAbilityToBeForcedToClear.root);
        return;
    }
    if (self->Change133.IsTriggered)
    {
        self->D13outAbleToBeForcedToClear.Value = false;
        make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear(
            self, &x->ObserveAbilityToBeForcedToClear.root);
        return;
    }
    if (self->Change515.IsTriggered)
    {
        self->D13outAbleToBeForcedToClear.Value = false;
        make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear(
            self, &x->ObserveAbilityToBeForcedToClear.root);
        return;
    }
}

void transition_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{

    if (self->Change509.IsTriggered)
    {
        if ((!(self->D14nRunningTimer.Value)) && (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            self->D13outAbleToBeForcedToClear.Value = true;
            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
                self, &x->ObserveAbilityToBeForcedToClear.root);
            return;
        }
    }
    if (self->Change512.IsTriggered)
    {
        if ((!(self->D14nRunningTimer.Value)) && (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            self->D13outAbleToBeForcedToClear.Value = true;
            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
                self, &x->ObserveAbilityToBeForcedToClear.root);
            return;
        }
    }
    if (self->Change554.IsTriggered)
    {
        if ((self->D9inOccupancyStatus.Value ==
             FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__OccupiedOut) &&
            (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            self->D13outAbleToBeForcedToClear.Value = true;
            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
                self, &x->ObserveAbilityToBeForcedToClear.root);
            return;
        }
    }
    if (self->Change551.IsTriggered)
    {
        if (((self->D9inOccupancyStatus.Value ==
              FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableIn) &&
             (self->D26inConVariantAIsUsed.Value)) &&
            (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            self->D13outAbleToBeForcedToClear.Value = true;
            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
                self, &x->ObserveAbilityToBeForcedToClear.root);
            return;
        }
    }
    if (self->Change553.IsTriggered)
    {
        if ((self->D9inOccupancyStatus.Value ==
             FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableOut) &&
            (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            self->D13outAbleToBeForcedToClear.Value = true;
            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
                self, &x->ObserveAbilityToBeForcedToClear.root);
            return;
        }
    }
    if (self->Change558.IsTriggered)
    {
        if (((!(self->D14nRunningTimer.Value)) &&
             (self->D9inOccupancyStatus.Value ==
              FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableIn)) &&
            (self->D26inConVariantAIsUsed.Value))
        {
            self->D13outAbleToBeForcedToClear.Value = true;
            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
                self, &x->ObserveAbilityToBeForcedToClear.root);
            return;
        }
    }
    if (self->Change555.IsTriggered)
    {
        if ((self->D9inOccupancyStatus.Value ==
             FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableOut) &&
            (!(self->D14nRunningTimer.Value)))
        {
            self->D13outAbleToBeForcedToClear.Value = true;
            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
                self, &x->ObserveAbilityToBeForcedToClear.root);
            return;
        }
    }
    if (self->Change557.IsTriggered)
    {
        if ((!(self->D14nRunningTimer.Value)) &&
            (self->D9inOccupancyStatus.Value == FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__OccupiedOut))
        {
            self->D13outAbleToBeForcedToClear.Value = true;
            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
                self, &x->ObserveAbilityToBeForcedToClear.root);
            return;
        }
    }
}

void transition_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    switch (x->ObserveAbilityToBeForcedToClear.root.state)
    {
    case FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear:
        transition_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
            self, x);
        break;
    case FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear:
        transition_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear(
            self, x);
        break;
    }
}

void transition_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    transition_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root(self, x);
    if (self->Change256.IsTriggered)
    {
        self->D13outAbleToBeForcedToClear.Value = false;
        make_state_FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance(self, x);
        return;
    }
    if (self->Change412.IsTriggered)
    {

        make_state_FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting(self, x);
        return;
    }
    if (self->Change414.IsTriggered)
    {

        make_state_FObserveAbilityToBeForcedToClear__root__FallbackMode(self, x);
        return;
    }
}

void transition_from_FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{

    if (self->Change426.IsTriggered)
    {

        if (self->D32inCriticalFailureTvps.Value)
        {
            self->D13outAbleToBeForcedToClear.Value = false;
            make_state_FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance(self, x);
            return;
        }
        else
        {

            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear(self, x);
            return;
        }
    }
}

void transition_from_FObserveAbilityToBeForcedToClear__root__FallbackMode(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{

    if (self->Change406.IsTriggered)
    {

        make_state_FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting(self, x);
        return;
    }
}

void transition_from_FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{

    if (self->Change417.IsTriggered)
    {

        make_state_FObserveAbilityToBeForcedToClear__root__FallbackMode(self, x);
        return;
    }
    if (self->Change570.IsTriggered)
    {

        make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear(self, x);
        return;
    }
}

void transition_from_FObserveAbilityToBeForcedToClear__root(FObserveAbilityToBeForcedToClear *self,
                                                            FObserveAbilityToBeForcedToClear__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear:
        transition_from_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear(self, x);
        break;
    case FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting:
        transition_from_FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting(self, x);
        break;
    case FObserveAbilityToBeForcedToClear__root__FallbackMode:
        transition_from_FObserveAbilityToBeForcedToClear__root__FallbackMode(self, x);
        break;
    case FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance:
        transition_from_FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance(self, x);
        break;
    }
}

static void evaluateChangeEvents(FObserveAbilityToBeForcedToClear *self)
{
    self->Change110.IsTriggered =
        IsTriggered(MakeChange(self->D14nRunningTimer.IsSignalled, self->D14nRunningTimer.Value));
    self->Change133.IsTriggered =
        IsTriggered(MakeChange(self->D18inPerformFcPOrFcPA.IsSignalled, self->D18inPerformFcPOrFcPA.Value));
    self->Change515.IsTriggered = IsTriggered(MakeChange(
        self->D9inOccupancyStatus.IsSignalled,
        self->D9inOccupancyStatus.Value == FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__Vacant));
    self->Change509.IsTriggered = IsTriggered(MakeChange(
        self->D9inOccupancyStatus.IsSignalled,
        self->D9inOccupancyStatus.Value == FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__OccupiedOut));
    self->Change512.IsTriggered = IsTriggered(MakeChange(
        self->D9inOccupancyStatus.IsSignalled,
        self->D9inOccupancyStatus.Value == FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableOut));
    self->Change554.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D14nRunningTimer.IsSignalled, self->D14nRunningTimer.Value)));
    self->Change551.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D14nRunningTimer.IsSignalled, self->D14nRunningTimer.Value)));
    self->Change553.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D14nRunningTimer.IsSignalled, self->D14nRunningTimer.Value)));
    self->Change558.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D18inPerformFcPOrFcPA.IsSignalled, self->D18inPerformFcPOrFcPA.Value)));
    self->Change555.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D18inPerformFcPOrFcPA.IsSignalled, self->D18inPerformFcPOrFcPA.Value)));
    self->Change557.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D18inPerformFcPOrFcPA.IsSignalled, self->D18inPerformFcPOrFcPA.Value)));
    self->Change256.IsTriggered =
        IsTriggered(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value));
    self->Change412.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__Booting),
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value ==
                       FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__NoOperatingVoltage)));
    self->Change414.IsTriggered = IsTriggered(MakeChange(
        self->D51outEstEfesState.IsSignalled,
        self->D51outEstEfesState.Value == FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__FallbackMode));
    self->Change426.IsTriggered = IsTriggered(MakeChange(
        self->D51outEstEfesState.IsSignalled,
        self->D51outEstEfesState.Value == FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__Initialising));
    self->Change406.IsTriggered = IsTriggered(MakeChange(
        self->D51outEstEfesState.IsSignalled,
        self->D51outEstEfesState.Value == FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__Booting));
    self->Change417.IsTriggered = IsTriggered(MakeChange(
        self->D51outEstEfesState.IsSignalled,
        self->D51outEstEfesState.Value == FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__FallbackMode));
    self->Change570.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value)));
}

static void resetOutputs(FObserveAbilityToBeForcedToClear *self)
{

    self->D13outAbleToBeForcedToClear.IsSignalled = false;
    self->D51outEstEfesState.IsSignalled = false;
}

static void resetTriggers(FObserveAbilityToBeForcedToClear *self)
{

    self->D26inConVariantAIsUsed.IsSignalled = false;
    self->D9inOccupancyStatus.IsSignalled = false;
    self->D32inCriticalFailureTvps.IsSignalled = false;
    self->D18inPerformFcPOrFcPA.IsSignalled = false;
}

void transition_FObserveAbilityToBeForcedToClear(FObserveAbilityToBeForcedToClear *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FObserveAbilityToBeForcedToClear__root(self, &self->state);
    resetTriggers(self);
}

void new_FObserveAbilityToBeForcedToClear(FObserveAbilityToBeForcedToClear *self)
{
    make_state_FObserveAbilityToBeForcedToClear__root(self, &self->state);
}
