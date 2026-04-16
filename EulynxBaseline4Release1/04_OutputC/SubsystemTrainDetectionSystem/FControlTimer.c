
#include "FControlTimer.h"

// Value Conversion Functions

// Operations

void make_state_FControlTimer__root__ObserveTimer__root__NoTimer(
    FControlTimer *self, FControlTimer__root__ObserveTimer__root__state_struct *region)
{
    LOG("[FControlTimer] Entering state NoTimer in region root__ObserveTimer__root");
    region->state = FControlTimer__root__ObserveTimer__root__NoTimer;
};

void make_state_FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer(
    FControlTimer *self, FControlTimer__root__ObserveTimer__root__state_struct *region)
{
    LOG("[FControlTimer] Entering state InhibitionRunningTimer in region root__ObserveTimer__root");
    region->state = FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer;
};

void make_state_FControlTimer__root__ObserveTimer__root__NotificationOfAvailabilityRunningTimer(
    FControlTimer *self, FControlTimer__root__ObserveTimer__root__state_struct *region)
{
    LOG("[FControlTimer] Entering state NotificationOfAvailabilityRunningTimer in region root__ObserveTimer__root");
    region->state = FControlTimer__root__ObserveTimer__root__NotificationOfAvailabilityRunningTimer;
};

void make_state_FControlTimer__root__ObserveTimer__root(FControlTimer *self,
                                                        FControlTimer__root__ObserveTimer__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlTimer__root__ObserveTimer__root__state_struct));

    make_state_FControlTimer__root__ObserveTimer__root__NoTimer(self, x);
    return;
}

void make_state_FControlTimer__root__ObserveTimer(FControlTimer *self, FControlTimer__root__state_struct *region)
{
    LOG("[FControlTimer] Entering state ObserveTimer in region root");
    region->state = FControlTimer__root__ObserveTimer;
    make_state_FControlTimer__root__ObserveTimer__root(self, &region->ObserveTimer.root);
};

void make_state_FControlTimer__root__WaitingForFinishBooting(FControlTimer *self,
                                                             FControlTimer__root__state_struct *region)
{
    LOG("[FControlTimer] Entering state WaitingForFinishBooting in region root");
    region->state = FControlTimer__root__WaitingForFinishBooting;
};

void make_state_FControlTimer__root__FallbackMode(FControlTimer *self, FControlTimer__root__state_struct *region)
{
    LOG("[FControlTimer] Entering state FallbackMode in region root");
    region->state = FControlTimer__root__FallbackMode;
};

void make_state_FControlTimer__root__TechnicalDisturbance(FControlTimer *self,
                                                          FControlTimer__root__state_struct *region)
{
    LOG("[FControlTimer] Entering state TechnicalDisturbance in region root");
    region->state = FControlTimer__root__TechnicalDisturbance;
};

void make_state_FControlTimer__root(FControlTimer *self, FControlTimer__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlTimer__root__state_struct));

    make_state_FControlTimer__root__WaitingForFinishBooting(self, x);
    return;
}

void transition_from_FControlTimer__root__ObserveTimer__root__NoTimer(FControlTimer *self,
                                                                      FControlTimer__root__state_struct *x)
{

    if (self->Change495.IsTriggered)
    {
        if (self->D28inConTDelayOfNotificationOfAvailability.Value != 0)
        {
            self->D14outRunningTimer.Value = true;
            make_state_FControlTimer__root__ObserveTimer__root__NotificationOfAvailabilityRunningTimer(
                self, &x->ObserveTimer.root);
            return;
        }
    }
    if (self->Change1109.IsTriggered)
    {
        if ((!(self->D8inLastWheelOut.Value)) && (self->D29inConTInhibitionTimer.Value != 0))
        {
            self->D14outRunningTimer.Value = true;
            make_state_FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer(self, &x->ObserveTimer.root);
            return;
        }
    }
}

void transition_from_FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer(
    FControlTimer *self, FControlTimer__root__state_struct *x)
{

    if (self->Time21.IsTimeoutExpired)
    {
        self->D14outRunningTimer.Value = false;
        make_state_FControlTimer__root__ObserveTimer__root__NoTimer(self, &x->ObserveTimer.root);
        return;
    }
    if (self->Change496.IsTriggered)
    {

        make_state_FControlTimer__root__ObserveTimer__root__NotificationOfAvailabilityRunningTimer(
            self, &x->ObserveTimer.root);
        return;
    }
    if (self->Change1107.IsTriggered)
    {
        if (!(self->D8inLastWheelOut.Value))
        {

            make_state_FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer(self, &x->ObserveTimer.root);
            return;
        }
    }
}

void transition_from_FControlTimer__root__ObserveTimer__root__NotificationOfAvailabilityRunningTimer(
    FControlTimer *self, FControlTimer__root__state_struct *x)
{

    if (self->Time18.IsTimeoutExpired)
    {
        self->D14outRunningTimer.Value = false;
        make_state_FControlTimer__root__ObserveTimer__root__NoTimer(self, &x->ObserveTimer.root);
        return;
    }
    if (self->Change1108.IsTriggered)
    {

        make_state_FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer(self, &x->ObserveTimer.root);
        return;
    }
}

void transition_from_FControlTimer__root__ObserveTimer__root(FControlTimer *self, FControlTimer__root__state_struct *x)
{
    switch (x->ObserveTimer.root.state)
    {
    case FControlTimer__root__ObserveTimer__root__NoTimer:
        transition_from_FControlTimer__root__ObserveTimer__root__NoTimer(self, x);
        break;
    case FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer:
        transition_from_FControlTimer__root__ObserveTimer__root__InhibitionRunningTimer(self, x);
        break;
    case FControlTimer__root__ObserveTimer__root__NotificationOfAvailabilityRunningTimer:
        transition_from_FControlTimer__root__ObserveTimer__root__NotificationOfAvailabilityRunningTimer(self, x);
        break;
    }
}

void transition_from_FControlTimer__root__ObserveTimer(FControlTimer *self, FControlTimer__root__state_struct *x)
{
    transition_from_FControlTimer__root__ObserveTimer__root(self, x);
    if (self->Change246.IsTriggered)
    {
        self->D14outRunningTimer.Value = false;
        make_state_FControlTimer__root__TechnicalDisturbance(self, x);
        return;
    }
    if (self->Change404.IsTriggered)
    {
        self->D14outRunningTimer.Value = false;
        make_state_FControlTimer__root__WaitingForFinishBooting(self, x);
        return;
    }
    if (self->Change408.IsTriggered)
    {
        self->D14outRunningTimer.Value = false;
        make_state_FControlTimer__root__FallbackMode(self, x);
        return;
    }
}

void transition_from_FControlTimer__root__WaitingForFinishBooting(FControlTimer *self,
                                                                  FControlTimer__root__state_struct *x)
{

    if (self->Change418.IsTriggered)
    {

        if (self->D32inCriticalFailureTvps.Value)
        {

            make_state_FControlTimer__root__TechnicalDisturbance(self, x);
            return;
        }
        else
        {

            make_state_FControlTimer__root__ObserveTimer(self, x);
            return;
        }
    }
}

void transition_from_FControlTimer__root__FallbackMode(FControlTimer *self, FControlTimer__root__state_struct *x)
{

    if (self->Change399.IsTriggered)
    {

        make_state_FControlTimer__root__WaitingForFinishBooting(self, x);
        return;
    }
}

void transition_from_FControlTimer__root__TechnicalDisturbance(FControlTimer *self,
                                                               FControlTimer__root__state_struct *x)
{

    if (self->Change409.IsTriggered)
    {

        make_state_FControlTimer__root__FallbackMode(self, x);
        return;
    }
    if (self->Change571.IsTriggered)
    {

        make_state_FControlTimer__root__ObserveTimer(self, x);
        return;
    }
}

void transition_from_FControlTimer__root(FControlTimer *self, FControlTimer__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlTimer__root__ObserveTimer:
        transition_from_FControlTimer__root__ObserveTimer(self, x);
        break;
    case FControlTimer__root__WaitingForFinishBooting:
        transition_from_FControlTimer__root__WaitingForFinishBooting(self, x);
        break;
    case FControlTimer__root__FallbackMode:
        transition_from_FControlTimer__root__FallbackMode(self, x);
        break;
    case FControlTimer__root__TechnicalDisturbance:
        transition_from_FControlTimer__root__TechnicalDisturbance(self, x);
        break;
    }
}

static void evaluateChangeEvents(FControlTimer *self)
{
    self->Change495.IsTriggered =
        IsTriggered(MakeChange(self->D8inLastWheelOut.IsSignalled, self->D8inLastWheelOut.Value));
    self->Change1109.IsTriggered = IsTriggered(
        OrChange(OrChange(MakeChange(self->T37inWheelIn.IsTriggered, self->T37inWheelIn.IsTriggered),
                          MakeChange(self->T38inWheelOut.IsTriggered, self->T38inWheelOut.IsTriggered)),
                 MakeChange(self->T39inUndefinedPattern.IsTriggered, self->T39inUndefinedPattern.IsTriggered)));
    self->Change496.IsTriggered =
        IsTriggered(MakeChange(self->D8inLastWheelOut.IsSignalled, self->D8inLastWheelOut.Value));
    self->Change1107.IsTriggered = IsTriggered(
        OrChange(OrChange(MakeChange(self->T37inWheelIn.IsTriggered, self->T37inWheelIn.IsTriggered),
                          MakeChange(self->T38inWheelOut.IsTriggered, self->T38inWheelOut.IsTriggered)),
                 MakeChange(self->T39inUndefinedPattern.IsTriggered, self->T39inUndefinedPattern.IsTriggered)));
    self->Change1108.IsTriggered = IsTriggered(
        OrChange(OrChange(MakeChange(self->T37inWheelIn.IsTriggered, self->T37inWheelIn.IsTriggered),
                          MakeChange(self->T38inWheelOut.IsTriggered, self->T38inWheelOut.IsTriggered)),
                 MakeChange(self->T39inUndefinedPattern.IsTriggered, self->T39inUndefinedPattern.IsTriggered)));
    self->Change246.IsTriggered =
        IsTriggered(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value));
    self->Change404.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FControlTimer_D51outEstEfesStateValue__Booting),
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FControlTimer_D51outEstEfesStateValue__NoOperatingVoltage)));
    self->Change408.IsTriggered =
        IsTriggered(MakeChange(self->D51outEstEfesState.IsSignalled,
                               self->D51outEstEfesState.Value == FControlTimer_D51outEstEfesStateValue__FallbackMode));
    self->Change418.IsTriggered =
        IsTriggered(MakeChange(self->D51outEstEfesState.IsSignalled,
                               self->D51outEstEfesState.Value == FControlTimer_D51outEstEfesStateValue__Initialising));
    self->Change399.IsTriggered =
        IsTriggered(MakeChange(self->D51outEstEfesState.IsSignalled,
                               self->D51outEstEfesState.Value == FControlTimer_D51outEstEfesStateValue__Booting));
    self->Change409.IsTriggered =
        IsTriggered(MakeChange(self->D51outEstEfesState.IsSignalled,
                               self->D51outEstEfesState.Value == FControlTimer_D51outEstEfesStateValue__FallbackMode));
    self->Change571.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value)));
}

static void resetOutputs(FControlTimer *self)
{

    self->D51outEstEfesState.IsSignalled = false;
    self->D14outRunningTimer.IsSignalled = false;
}

static void resetTriggers(FControlTimer *self)
{

    self->T37inWheelIn.IsTriggered = false;
    self->T38inWheelOut.IsTriggered = false;
    self->T39inUndefinedPattern.IsTriggered = false;

    self->D28inConTDelayOfNotificationOfAvailability.IsSignalled = false;
    self->D29inConTInhibitionTimer.IsSignalled = false;
    self->D32inCriticalFailureTvps.IsSignalled = false;
    self->D8inLastWheelOut.IsSignalled = false;

    self->Time21.IsTimeoutExpired = false;
    self->Time18.IsTimeoutExpired = false;
}

void transition_FControlTimer(FControlTimer *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FControlTimer__root(self, &self->state);
    resetTriggers(self);
}

void new_FControlTimer(FControlTimer *self)
{
    make_state_FControlTimer__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemTrainDetectionSystem/FControlTimer.c"
#endif
