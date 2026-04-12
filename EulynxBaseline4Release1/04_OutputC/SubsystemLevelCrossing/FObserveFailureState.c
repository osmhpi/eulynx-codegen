
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
    LOG("[FObserveFailureState] Entering state NoCriticalFailureDetected in region "
        "root__ObserveFailureStates__LcFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state NonCriticalFailureDetected in region "
        "root__ObserveFailureStates__LcFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state NoNonCriticalFailureDetected in region "
        "root__ObserveFailureStates__LcFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__Waiting(
    FObserveFailureState *self, FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state Waiting in region root__ObserveFailureStates__LcFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcFailureState__Waiting;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState(
    FObserveFailureState *self, FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct *x)
{
    memset(x, 0, sizeof(FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct));

    make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__Waiting(self, x);
    return;
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
    LOG("[FObserveFailureState] Entering state NoCriticalFailureDetected in region "
        "root__ObserveFailureStates__LcpfFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected(
    FObserveFailureState *self,
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state NonCriticalFailureDetected in region "
        "root__ObserveFailureStates__LcpfFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected(
    FObserveFailureState *self,
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state NoNonCriticalFailureDetected in region "
        "root__ObserveFailureStates__LcpfFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__Waiting(
    FObserveFailureState *self,
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state Waiting in region root__ObserveFailureStates__LcpfFailureState");
    region->state = FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__Waiting;
};

void make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState(
    FObserveFailureState *self, FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct *x)
{
    memset(x, 0, sizeof(FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct));

    make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__Waiting(self, x);
    return;
}

void make_state_FObserveFailureState__root__ObserveFailureStates(FObserveFailureState *self,
                                                                 FObserveFailureState__root__state_struct *region)
{
    LOG("[FObserveFailureState] Entering state ObserveFailureStates in region root");
    region->state = FObserveFailureState__root__ObserveFailureStates;
    make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState(
        self, &region->ObserveFailureStates.LcFailureState);
    make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState(
        self, &region->ObserveFailureStates.LcpfFailureState);
};

void make_state_FObserveFailureState__root(FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveFailureState__root__state_struct));

    make_state_FObserveFailureState__root__ObserveFailureStates(self, x);
    return;
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change584.IsTriggered)
    {
        if (self->D69inLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            self->D61outMsgLcFailureStatus.Value =
                FObserveFailureState_D61outMsgLcFailureStatusValue__NoCriticalFailurePresent;
            self->D61outMsgLcFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change432.IsTriggered)
    {
        if (self->D69inLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            self->D61outMsgLcFailureStatus.Value =
                FObserveFailureState_D61outMsgLcFailureStatusValue__ACriticalFailureIsPresent;
            self->D61outMsgLcFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected(
                self, &x->ObserveFailureStates.LcFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change585.IsTriggered)
    {
        if (self->D69inLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            self->D61outMsgLcFailureStatus.Value =
                FObserveFailureState_D61outMsgLcFailureStatusValue__NoNonCriticalFailurePresent;
            self->D61outMsgLcFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change430.IsTriggered)
    {
        if (self->D69inLcFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            self->D61outMsgLcFailureStatus.Value =
                FObserveFailureState_D61outMsgLcFailureStatusValue__ANonCriticalFailureIsPresent;
            self->D61outMsgLcFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__Waiting(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change447.IsTriggered)
    {
        self->D61outMsgLcFailureStatus.Value =
            FObserveFailureState_D61outMsgLcFailureStatusValue__NoCriticalFailurePresent;
        self->D61outMsgLcFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected(
            self, &x->ObserveFailureStates.LcFailureState);
        return;
    }
    if (self->Change448.IsTriggered)
    {
        self->D61outMsgLcFailureStatus.Value =
            FObserveFailureState_D61outMsgLcFailureStatusValue__NoNonCriticalFailurePresent;
        self->D61outMsgLcFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected(
            self, &x->ObserveFailureStates.LcFailureState);
        return;
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
    case FObserveFailureState__root__ObserveFailureStates__LcFailureState__Waiting:
        transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState__Waiting(self, x);
        break;
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change453.IsTriggered)
    {
        if (self->D67inLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            self->D62outMsgLcpfFailureStatus.Value =
                FObserveFailureState_D62outMsgLcpfFailureStatusValue__NoCriticalFailurePresent;
            self->D62outMsgLcpfFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcpfFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change450.IsTriggered)
    {
        if (self->D67inLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport)
        {
            self->D62outMsgLcpfFailureStatus.Value =
                FObserveFailureState_D62outMsgLcpfFailureStatusValue__ACriticalFailureIsPresent;
            self->D62outMsgLcpfFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected(
                self, &x->ObserveFailureStates.LcpfFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change452.IsTriggered)
    {
        if (self->D67inLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            self->D62outMsgLcpfFailureStatus.Value =
                FObserveFailureState_D62outMsgLcpfFailureStatusValue__NoNonCriticalFailurePresent;
            self->D62outMsgLcpfFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcpfFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change451.IsTriggered)
    {
        if (self->D67inLcpfFailureStatusAfterPresentFailure.Value ==
            FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport)
        {
            self->D62outMsgLcpfFailureStatus.Value =
                FObserveFailureState_D62outMsgLcpfFailureStatusValue__ANonCriticalFailureIsPresent;
            self->D62outMsgLcpfFailureStatus.IsSignalled = true;
            make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected(
                self, &x->ObserveFailureStates.LcpfFailureState);
            return;
        }
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__Waiting(
    FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{

    if (self->Change446.IsTriggered)
    {
        self->D62outMsgLcpfFailureStatus.Value =
            FObserveFailureState_D62outMsgLcpfFailureStatusValue__NoNonCriticalFailurePresent;
        self->D62outMsgLcpfFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected(
            self, &x->ObserveFailureStates.LcpfFailureState);
        return;
    }
    if (self->Change445.IsTriggered)
    {
        self->D62outMsgLcpfFailureStatus.Value =
            FObserveFailureState_D62outMsgLcpfFailureStatusValue__NoCriticalFailurePresent;
        self->D62outMsgLcpfFailureStatus.IsSignalled = true;
        make_state_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected(
            self, &x->ObserveFailureStates.LcpfFailureState);
        return;
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
    case FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__Waiting:
        transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__Waiting(self, x);
        break;
    }
}

void transition_from_FObserveFailureState__root__ObserveFailureStates(FObserveFailureState *self,
                                                                      FObserveFailureState__root__state_struct *x)
{
    transition_from_FObserveFailureState__root__ObserveFailureStates__LcFailureState(self, x);
    transition_from_FObserveFailureState__root__ObserveFailureStates__LcpfFailureState(self, x);
}

void transition_from_FObserveFailureState__root(FObserveFailureState *self, FObserveFailureState__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveFailureState__root__ObserveFailureStates:
        transition_from_FObserveFailureState__root__ObserveFailureStates(self, x);
        break;
    }
}

static void evaluateChangeEvents(FObserveFailureState *self)
{
    self->Change584.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D60inLcFailure.IsSignalled, self->D60inLcFailure.Value)));
    self->Change432.IsTriggered = IsTriggered(MakeChange(self->D60inLcFailure.IsSignalled, self->D60inLcFailure.Value));
    self->Change585.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D60inLcFailure.IsSignalled, self->D60inLcFailure.Value)));
    self->Change430.IsTriggered = IsTriggered(MakeChange(self->D60inLcFailure.IsSignalled, self->D60inLcFailure.Value));
    self->Change447.IsTriggered = IsTriggered(
        MakeChange(self->D69inLcFailureStatusAfterPresentFailure.IsSignalled,
                   self->D69inLcFailureStatusAfterPresentFailure.Value ==
                       FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__CriticalFailureReport));
    self->Change448.IsTriggered = IsTriggered(
        MakeChange(self->D69inLcFailureStatusAfterPresentFailure.IsSignalled,
                   self->D69inLcFailureStatusAfterPresentFailure.Value ==
                       FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport));
    self->Change453.IsTriggered = IsTriggered(MakeChange(
        self->D6inLcpfFailureState.IsSignalled,
        self->D6inLcpfFailureState.Value == FObserveFailureState_D6inLcpfFailureStateValue__NoFailurePresent));
    self->Change450.IsTriggered = IsTriggered(
        MakeChange(self->D6inLcpfFailureState.IsSignalled,
                   self->D6inLcpfFailureState.Value == FObserveFailureState_D6inLcpfFailureStateValue__FailurePresent));
    self->Change452.IsTriggered = IsTriggered(MakeChange(
        self->D6inLcpfFailureState.IsSignalled,
        self->D6inLcpfFailureState.Value == FObserveFailureState_D6inLcpfFailureStateValue__NoFailurePresent));
    self->Change451.IsTriggered = IsTriggered(
        MakeChange(self->D6inLcpfFailureState.IsSignalled,
                   self->D6inLcpfFailureState.Value == FObserveFailureState_D6inLcpfFailureStateValue__FailurePresent));
    self->Change446.IsTriggered = IsTriggered(
        MakeChange(self->D67inLcpfFailureStatusAfterPresentFailure.IsSignalled,
                   self->D67inLcpfFailureStatusAfterPresentFailure.Value ==
                       FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport));
    self->Change445.IsTriggered = IsTriggered(
        MakeChange(self->D67inLcpfFailureStatusAfterPresentFailure.IsSignalled,
                   self->D67inLcpfFailureStatusAfterPresentFailure.Value ==
                       FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport));
}

static void resetOutputs(FObserveFailureState *self)
{

    self->D61outMsgLcFailureStatus.IsSignalled = false;
    self->D62outMsgLcpfFailureStatus.IsSignalled = false;
}

static void resetTriggers(FObserveFailureState *self)
{

    self->D6inLcpfFailureState.IsSignalled = false;
    self->D69inLcFailureStatusAfterPresentFailure.IsSignalled = false;
    self->D67inLcpfFailureStatusAfterPresentFailure.IsSignalled = false;
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
