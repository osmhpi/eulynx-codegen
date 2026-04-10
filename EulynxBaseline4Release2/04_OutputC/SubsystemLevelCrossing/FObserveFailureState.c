
#include "FObserveFailureState.h"

// Value Conversion Functions

// Operations

void make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state CriticalFailureDetected in region "
        "root__ObserveFailureStates__LcFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state NoCriticalFailureDetected in "
        "region root__ObserveFailureStates__LcFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state NonCriticalFailureDetected in "
        "region root__ObserveFailureStates__LcFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state NoNonCriticalFailureDetected in "
        "region root__ObserveFailureStates__LcFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState(
    FObserveFailureState *self, FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct *x)
{
    memset(x, 0, sizeof(FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct));

    if ((self->D60inLcFailure.Value) &&
        (self->D69inConLcFailureStatusAfterPresentFailure.Value ==
         FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__CriticalFailureReport))
    {
        self->D61outLcFailureStatus.Value = FObserveFailureState_D61outLcFailureStatusValue__ACriticalFailureIsPresent;
        self->D61outLcFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected(self, x);
        return;
    }
    if ((self->D69inConLcFailureStatusAfterPresentFailure.Value ==
         FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__CriticalFailureReport) &&
        (!(self->D60inLcFailure.Value)))
    {
        self->D61outLcFailureStatus.Value = FObserveFailureState_D61outLcFailureStatusValue__NoCriticalFailurePresent;
        self->D61outLcFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected(self, x);
        return;
    }
    if ((self->D60inLcFailure.Value) &&
        (self->D69inConLcFailureStatusAfterPresentFailure.Value ==
         FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport))
    {
        self->D61outLcFailureStatus.Value =
            FObserveFailureState_D61outLcFailureStatusValue__ANonCriticalFailureIsPresent;
        self->D61outLcFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected(self,
                                                                                                                x);
        return;
    }
    else
    {
        self->D61outLcFailureStatus.Value =
            FObserveFailureState_D61outLcFailureStatusValue__NoNonCriticalFailurePresent;
        self->D61outLcFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected(self,
                                                                                                                  x);
        return;
    }
}

void make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected(
    FObserveFailureState *self,
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state CriticalFailureDetected in region "
        "root__ObserveFailureStates__LcpfFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected(
    FObserveFailureState *self,
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state NoCriticalFailureDetected in "
        "region root__ObserveFailureStates__LcpfFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected(
    FObserveFailureState *self,
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state NonCriticalFailureDetected in "
        "region root__ObserveFailureStates__LcpfFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected(
    FObserveFailureState *self,
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state NoNonCriticalFailureDetected in "
        "region root__ObserveFailureStates__LcpfFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState(
    FObserveFailureState *self, FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct *x)
{
    memset(x, 0, sizeof(FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct));

    if ((self->D74inLcpfFailureState.Value == FObserveFailureState_D74inLcpfFailureStateValue__FailurePresent) &&
        (self->D67inConLcpfFailureStatusAfterPresentFailure.Value ==
         FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport))
    {
        self->D62outLcpfFailureStatus.Value =
            FObserveFailureState_D62outLcpfFailureStatusValue__ACriticalFailureIsPresent;
        self->D62outLcpfFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected(self, x);
        return;
    }
    if ((self->D74inLcpfFailureState.Value == FObserveFailureState_D74inLcpfFailureStateValue__NoFailurePresent) &&
        (self->D67inConLcpfFailureStatusAfterPresentFailure.Value ==
         FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport))
    {
        self->D62outLcpfFailureStatus.Value =
            FObserveFailureState_D62outLcpfFailureStatusValue__NoCriticalFailurePresent;
        self->D62outLcpfFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected(self,
                                                                                                                 x);
        return;
    }
    if ((self->D74inLcpfFailureState.Value == FObserveFailureState_D74inLcpfFailureStateValue__FailurePresent) &&
        (self->D67inConLcpfFailureStatusAfterPresentFailure.Value ==
         FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport))
    {
        self->D62outLcpfFailureStatus.Value =
            FObserveFailureState_D62outLcpfFailureStatusValue__ANonCriticalFailureIsPresent;
        self->D62outLcpfFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected(self,
                                                                                                                  x);
        return;
    }
    else
    {
        self->D62outLcpfFailureStatus.Value =
            FObserveFailureState_D62outLcpfFailureStatusValue__NoNonCriticalFailurePresent;
        self->D62outLcpfFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected(
            self, x);
        return;
    }
}

void make_state_FObserveFailureState__root__ObserveFailureStates(FObserveFailureState *self,
                                                                 FObserveFailureState__root__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state ObserveFailureStates in region "
        "root");
    region->state = FObserveFailureState__root__ObserveFailureStates;
    make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState(
        self, &region->ObserveFailureStates.LcFailureState);
    make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState(
        self, &region->ObserveFailureStates.LcpfFailureState);
};

void make_state_FObserveFailureState__root__WaitingForBooting(FObserveFailureState *self,
                                                              FObserveFailureState__root__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state WaitingForBooting in region root");
    region->state = FObserveFailureState__root__WaitingForBooting;
};

void make_state_FObserveFailureState__root(FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveFailureState__root__state_struct));

    make_state_FObserveFailureState__root__WaitingForBooting(self, x);
    return;
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change585.IsTriggered)
    {
        if (self->D69inConLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            self->D61outLcFailureStatus.Value =
                FObserveFailureState_D61outLcFailureStatusValue__NoCriticalFailurePresent;
            self->D61outLcFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change437.IsTriggered)
    {
        if (self->D69inConLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            self->D61outLcFailureStatus.Value =
                FObserveFailureState_D61outLcFailureStatusValue__ACriticalFailureIsPresent;
            self->D61outLcFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected(
                self, &x->ObserveFailureStates.LcFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change586.IsTriggered)
    {
        if (self->D69inConLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            self->D61outLcFailureStatus.Value =
                FObserveFailureState_D61outLcFailureStatusValue__NoNonCriticalFailurePresent;
            self->D61outLcFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change439.IsTriggered)
    {
        if (self->D69inConLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            self->D61outLcFailureStatus.Value =
                FObserveFailureState_D61outLcFailureStatusValue__ANonCriticalFailureIsPresent;
            self->D61outLcFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    switch (x->ObserveFailureStates.LcFailureState.state)
    {
    case FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected:
        transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected(self,
                                                                                                                  x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected:
        transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected(
            self, x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected:
        transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected(
            self, x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected:
        transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected(
            self, x);
        break;
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change458.IsTriggered)
    {
        if (self->D67inConLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            self->D62outLcpfFailureStatus.Value =
                FObserveFailureState_D62outLcpfFailureStatusValue__NoCriticalFailurePresent;
            self->D62outLcpfFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcpfFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change456.IsTriggered)
    {
        if (self->D67inConLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            self->D62outLcpfFailureStatus.Value =
                FObserveFailureState_D62outLcpfFailureStatusValue__ACriticalFailureIsPresent;
            self->D62outLcpfFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected(
                self, &x->ObserveFailureStates.LcpfFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change457.IsTriggered)
    {
        if (self->D67inConLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            self->D62outLcpfFailureStatus.Value =
                FObserveFailureState_D62outLcpfFailureStatusValue__NoNonCriticalFailurePresent;
            self->D62outLcpfFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcpfFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change455.IsTriggered)
    {
        if (self->D67inConLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            self->D62outLcpfFailureStatus.Value =
                FObserveFailureState_D62outLcpfFailureStatusValue__ANonCriticalFailureIsPresent;
            self->D62outLcpfFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcpfFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    switch (x->ObserveFailureStates.LcpfFailureState.state)
    {
    case FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected:
        transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected(
            self, x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected:
        transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected(
            self, x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected:
        transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected(
            self, x);
        break;
    case FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected:
        transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected(
            self, x);
        break;
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates(FObserveFailureState *self,
                                                                      FObserveFailureState__root__state_struct *x)
{
    transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState(self, x);
    transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState(self, x);
    if (self->Change420.IsTriggered)
    {

        make_state_FObserveFailureState__root__WaitingForBooting(self, x);
        return;
    }
}

void transition_from_FObserveFailureState__root__WaitingForBooting(FObserveFailureState *self,
                                                                   FObserveFailureState__root__state_struct *x)
{

    if (self->Change402.IsTriggered)
    {

        make_state_FObserveFailureState__root__ObserveFailureStates(self, x);
        return;
    }
}

void transition_from_FObserveFailureState__root(FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveFailureState__root__ObserveFailureStates:
        transition_from_FObserveFailureState__root__ObserveFailureStates(self, x);
        break;
    case FObserveFailureState__root__WaitingForBooting:
        transition_from_FObserveFailureState__root__WaitingForBooting(self, x);
        break;
    }
}

static void evaluateChangeEvents(FObserveFailureState *self)
{
    self->Change585.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D60inLcFailure.IsSignalled, self->D60inLcFailure.Value)));
    self->Change437.IsTriggered = IsTriggered(MakeChange(self->D60inLcFailure.IsSignalled, self->D60inLcFailure.Value));
    self->Change586.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D60inLcFailure.IsSignalled, self->D60inLcFailure.Value)));
    self->Change439.IsTriggered = IsTriggered(MakeChange(self->D60inLcFailure.IsSignalled, self->D60inLcFailure.Value));
    self->Change458.IsTriggered = IsTriggered(MakeChange(
        self->D74inLcpfFailureState.IsSignalled,
        self->D74inLcpfFailureState.Value == FObserveFailureState_D74inLcpfFailureStateValue__NoFailurePresent));
    self->Change456.IsTriggered = IsTriggered(MakeChange(
        self->D74inLcpfFailureState.IsSignalled,
        self->D74inLcpfFailureState.Value == FObserveFailureState_D74inLcpfFailureStateValue__FailurePresent));
    self->Change457.IsTriggered = IsTriggered(MakeChange(
        self->D74inLcpfFailureState.IsSignalled,
        self->D74inLcpfFailureState.Value == FObserveFailureState_D74inLcpfFailureStateValue__NoFailurePresent));
    self->Change455.IsTriggered = IsTriggered(MakeChange(
        self->D74inLcpfFailureState.IsSignalled,
        self->D74inLcpfFailureState.Value == FObserveFailureState_D74inLcpfFailureStateValue__FailurePresent));
    self->Change420.IsTriggered = IsTriggered(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveFailureState_D51outEstEfesStateValue__FallbackMode));
    self->Change402.IsTriggered = IsTriggered(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveFailureState_D51outEstEfesStateValue__Booting));
}

static void resetOutputs(FObserveFailureState *self)
{

    self->D61outLcFailureStatus.IsSignalled = false;
    self->D62outLcpfFailureStatus.IsSignalled = false;
    self->D51outEstEfesState.IsSignalled = false;
}

static void resetTriggers(FObserveFailureState *self)
{

    self->D74inLcpfFailureState.IsSignalled = false;
    self->D69inConLcFailureStatusAfterPresentFailure.IsSignalled = false;
    self->D67inConLcpfFailureStatusAfterPresentFailure.IsSignalled = false;
    self->D60inLcFailure.IsSignalled = false;
}

void transition_FObserveFailureState(FObserveFailureState *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FObserveFailureState__root(self, &self->state);
    resetTriggers(self);
}

void new_FObserveFailureState(FObserveFailureState *self)
{
    make_state_FObserveFailureState__root(self, &self->state);
}
