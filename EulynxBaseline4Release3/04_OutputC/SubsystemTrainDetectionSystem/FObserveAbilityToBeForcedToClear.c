
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

    if (self->Change118.IsTriggered)
    {
        self->D13outAbleToBeForcedToClear.Value = false;
        make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear(
            self, &x->ObserveAbilityToBeForcedToClear.root);
        return;
    }
    if (self->Change128.IsTriggered)
    {
        self->D13outAbleToBeForcedToClear.Value = false;
        make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__NotAbleToBeForcedToClear(
            self, &x->ObserveAbilityToBeForcedToClear.root);
        return;
    }
    if (self->Change508.IsTriggered)
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

    if (self->Change502.IsTriggered)
    {
        if ((!(self->D14nMonitoringTime.Value)) && (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            self->D13outAbleToBeForcedToClear.Value = true;
            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
                self, &x->ObserveAbilityToBeForcedToClear.root);
            return;
        }
    }
    if (self->Change505.IsTriggered)
    {
        if ((!(self->D14nMonitoringTime.Value)) && (!(self->D18inPerformFcPOrFcPA.Value)))
        {
            self->D13outAbleToBeForcedToClear.Value = true;
            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
                self, &x->ObserveAbilityToBeForcedToClear.root);
            return;
        }
    }
    if (self->Change549.IsTriggered)
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
    if (self->Change547.IsTriggered)
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
    if (self->Change548.IsTriggered)
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
    if (self->Change552.IsTriggered)
    {
        if (((!(self->D14nMonitoringTime.Value)) &&
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
    if (self->Change550.IsTriggered)
    {
        if ((self->D9inOccupancyStatus.Value ==
             FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableOut) &&
            (!(self->D14nMonitoringTime.Value)))
        {
            self->D13outAbleToBeForcedToClear.Value = true;
            make_state_FObserveAbilityToBeForcedToClear__root__ObserveAbilityToBeForcedToClear__root__AbleToBeForcedToClear(
                self, &x->ObserveAbilityToBeForcedToClear.root);
            return;
        }
    }
    if (self->Change553.IsTriggered)
    {
        if ((!(self->D14nMonitoringTime.Value)) &&
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
    if (self->Change234.IsTriggered)
    {
        self->D13outAbleToBeForcedToClear.Value = false;
        make_state_FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance(self, x);
        return;
    }
    if (self->Change388.IsTriggered)
    {

        make_state_FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting(self, x);
        return;
    }
    if (self->Change393.IsTriggered)
    {

        make_state_FObserveAbilityToBeForcedToClear__root__FallbackMode(self, x);
        return;
    }
}

void transition_from_FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{

    if (self->Change403.IsTriggered)
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

    if (self->Change384.IsTriggered)
    {

        make_state_FObserveAbilityToBeForcedToClear__root__WaitingForFinishBooting(self, x);
        return;
    }
}

void transition_from_FObserveAbilityToBeForcedToClear__root__TechnicalDisturbance(
    FObserveAbilityToBeForcedToClear *self, FObserveAbilityToBeForcedToClear__root__state_struct *x)
{

    if (self->Change399.IsTriggered)
    {

        make_state_FObserveAbilityToBeForcedToClear__root__FallbackMode(self, x);
        return;
    }
    if (self->Change561.IsTriggered)
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
    self->Change118.IsTriggered =
        IsTriggered(MakeChange(self->D14nMonitoringTime.IsSignalled, self->D14nMonitoringTime.Value));
    self->Change128.IsTriggered =
        IsTriggered(MakeChange(self->D18inPerformFcPOrFcPA.IsSignalled, self->D18inPerformFcPOrFcPA.Value));
    self->Change508.IsTriggered = IsTriggered(MakeChange(
        self->D9inOccupancyStatus.IsSignalled,
        self->D9inOccupancyStatus.Value == FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__Vacant));
    self->Change502.IsTriggered = IsTriggered(MakeChange(
        self->D9inOccupancyStatus.IsSignalled,
        self->D9inOccupancyStatus.Value == FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__OccupiedOut));
    self->Change505.IsTriggered = IsTriggered(MakeChange(
        self->D9inOccupancyStatus.IsSignalled,
        self->D9inOccupancyStatus.Value == FObserveAbilityToBeForcedToClear_D9inOccupancyStatusValue__UnreliableOut));
    self->Change549.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D14nMonitoringTime.IsSignalled, self->D14nMonitoringTime.Value)));
    self->Change547.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D14nMonitoringTime.IsSignalled, self->D14nMonitoringTime.Value)));
    self->Change548.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D14nMonitoringTime.IsSignalled, self->D14nMonitoringTime.Value)));
    self->Change552.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D18inPerformFcPOrFcPA.IsSignalled, self->D18inPerformFcPOrFcPA.Value)));
    self->Change550.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D18inPerformFcPOrFcPA.IsSignalled, self->D18inPerformFcPOrFcPA.Value)));
    self->Change553.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D18inPerformFcPOrFcPA.IsSignalled, self->D18inPerformFcPOrFcPA.Value)));
    self->Change234.IsTriggered =
        IsTriggered(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value));
    self->Change388.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__Booting),
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value ==
                       FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__NoOperatingVoltage)));
    self->Change393.IsTriggered = IsTriggered(MakeChange(
        self->D51outEstEfesState.IsSignalled,
        self->D51outEstEfesState.Value == FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__FallbackMode));
    self->Change403.IsTriggered = IsTriggered(MakeChange(
        self->D51outEstEfesState.IsSignalled,
        self->D51outEstEfesState.Value == FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__Initialising));
    self->Change384.IsTriggered = IsTriggered(MakeChange(
        self->D51outEstEfesState.IsSignalled,
        self->D51outEstEfesState.Value == FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__Booting));
    self->Change399.IsTriggered = IsTriggered(MakeChange(
        self->D51outEstEfesState.IsSignalled,
        self->D51outEstEfesState.Value == FObserveAbilityToBeForcedToClear_D51outEstEfesStateValue__FallbackMode));
    self->Change561.IsTriggered = IsTriggered(
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
