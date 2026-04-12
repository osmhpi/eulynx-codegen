
#include "FObserveLuminosity.h"

// Value Conversion Functions

// Operations

void make_state_FObserveLuminosity__root__ObservingLuminosity__root__Day(
    FObserveLuminosity *self, FObserveLuminosity__root__ObservingLuminosity__root__state_struct *region)
{
    LOG("[FObserveLuminosity] Entering state Day in region root__ObservingLuminosity__root");
    region->state = FObserveLuminosity__root__ObservingLuminosity__root__Day;
};

void make_state_FObserveLuminosity__root__ObservingLuminosity__root__Night(
    FObserveLuminosity *self, FObserveLuminosity__root__ObservingLuminosity__root__state_struct *region)
{
    LOG("[FObserveLuminosity] Entering state Night in region root__ObservingLuminosity__root");
    region->state = FObserveLuminosity__root__ObservingLuminosity__root__Night;
};

void make_state_FObserveLuminosity__root__ObservingLuminosity__root__Waiting(
    FObserveLuminosity *self, FObserveLuminosity__root__ObservingLuminosity__root__state_struct *region)
{
    LOG("[FObserveLuminosity] Entering state Waiting in region root__ObservingLuminosity__root");
    region->state = FObserveLuminosity__root__ObservingLuminosity__root__Waiting;
};

void make_state_FObserveLuminosity__root__ObservingLuminosity__root(
    FObserveLuminosity *self, FObserveLuminosity__root__ObservingLuminosity__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveLuminosity__root__ObservingLuminosity__root__state_struct));

    make_state_FObserveLuminosity__root__ObservingLuminosity__root__Waiting(self, x);
    return;
}

void make_state_FObserveLuminosity__root__NoOperatingVoltage(FObserveLuminosity *self,
                                                             FObserveLuminosity__root__state_struct *region)
{
    LOG("[FObserveLuminosity] Entering state NoOperatingVoltage in region root");
    region->state = FObserveLuminosity__root__NoOperatingVoltage;
};

void make_state_FObserveLuminosity__root__ObservingLuminosity(FObserveLuminosity *self,
                                                              FObserveLuminosity__root__state_struct *region)
{
    LOG("[FObserveLuminosity] Entering state ObservingLuminosity in region root");
    region->state = FObserveLuminosity__root__ObservingLuminosity;
    make_state_FObserveLuminosity__root__ObservingLuminosity__root(self, &region->ObservingLuminosity.root);
};

void make_state_FObserveLuminosity__root(FObserveLuminosity *self, FObserveLuminosity__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveLuminosity__root__state_struct));

    make_state_FObserveLuminosity__root__NoOperatingVoltage(self, x);
    return;
}

void transition_from_FObserveLuminosity__root__ObservingLuminosity__root__Day(FObserveLuminosity *self,
                                                                              FObserveLuminosity__root__state_struct *x)
{

    if (self->Change85.IsTriggered)
    {
        self->D21outObservedLuminosity.Value = FObserveLuminosity_D21outObservedLuminosityValue__Night;
        self->D21outObservedLuminosity.IsSignalled = true;
        make_state_FObserveLuminosity__root__ObservingLuminosity__root__Night(self, &x->ObservingLuminosity.root);
        return;
    }
    if (self->Change172.IsTriggered)
    {
        self->D21outObservedLuminosity.Value = FObserveLuminosity_D21outObservedLuminosityValue__Night;
        self->D21outObservedLuminosity.IsSignalled = true;
        make_state_FObserveLuminosity__root__ObservingLuminosity__root__Night(self, &x->ObservingLuminosity.root);
        return;
    }
}

void transition_from_FObserveLuminosity__root__ObservingLuminosity__root__Night(
    FObserveLuminosity *self, FObserveLuminosity__root__state_struct *x)
{

    if (self->Change84.IsTriggered)
    {
        self->D21outObservedLuminosity.Value = FObserveLuminosity_D21outObservedLuminosityValue__Day;
        self->D21outObservedLuminosity.IsSignalled = true;
        make_state_FObserveLuminosity__root__ObservingLuminosity__root__Day(self, &x->ObservingLuminosity.root);
        return;
    }
    if (self->Change171.IsTriggered)
    {
        self->D21outObservedLuminosity.Value = FObserveLuminosity_D21outObservedLuminosityValue__Day;
        self->D21outObservedLuminosity.IsSignalled = true;
        make_state_FObserveLuminosity__root__ObservingLuminosity__root__Day(self, &x->ObservingLuminosity.root);
        return;
    }
}

void transition_from_FObserveLuminosity__root__ObservingLuminosity__root__Waiting(
    FObserveLuminosity *self, FObserveLuminosity__root__state_struct *x)
{

    if (self->Change170.IsTriggered)
    {
        self->D21outObservedLuminosity.Value = FObserveLuminosity_D21outObservedLuminosityValue__Day;
        self->D21outObservedLuminosity.IsSignalled = true;
        make_state_FObserveLuminosity__root__ObservingLuminosity__root__Day(self, &x->ObservingLuminosity.root);
        return;
    }
    if (self->Change173.IsTriggered)
    {
        self->D21outObservedLuminosity.Value = FObserveLuminosity_D21outObservedLuminosityValue__Night;
        self->D21outObservedLuminosity.IsSignalled = true;
        make_state_FObserveLuminosity__root__ObservingLuminosity__root__Night(self, &x->ObservingLuminosity.root);
        return;
    }
}

void transition_from_FObserveLuminosity__root__ObservingLuminosity__root(FObserveLuminosity *self,
                                                                         FObserveLuminosity__root__state_struct *x)
{
    switch (x->ObservingLuminosity.root.state)
    {
    case FObserveLuminosity__root__ObservingLuminosity__root__Day:
        transition_from_FObserveLuminosity__root__ObservingLuminosity__root__Day(self, x);
        break;
    case FObserveLuminosity__root__ObservingLuminosity__root__Night:
        transition_from_FObserveLuminosity__root__ObservingLuminosity__root__Night(self, x);
        break;
    case FObserveLuminosity__root__ObservingLuminosity__root__Waiting:
        transition_from_FObserveLuminosity__root__ObservingLuminosity__root__Waiting(self, x);
        break;
    }
}

void transition_from_FObserveLuminosity__root__NoOperatingVoltage(FObserveLuminosity *self,
                                                                  FObserveLuminosity__root__state_struct *x)
{

    if (self->Change345.IsTriggered)
    {

        make_state_FObserveLuminosity__root__ObservingLuminosity(self, x);
        return;
    }
}

void transition_from_FObserveLuminosity__root__ObservingLuminosity(FObserveLuminosity *self,
                                                                   FObserveLuminosity__root__state_struct *x)
{
    transition_from_FObserveLuminosity__root__ObservingLuminosity__root(self, x);
    if (self->Change353.IsTriggered)
    {

        make_state_FObserveLuminosity__root__ObservingLuminosity(self, x);
        return;
    }
    if (self->Change381.IsTriggered)
    {

        make_state_FObserveLuminosity__root__NoOperatingVoltage(self, x);
        return;
    }
}

void transition_from_FObserveLuminosity__root(FObserveLuminosity *self, FObserveLuminosity__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveLuminosity__root__NoOperatingVoltage:
        transition_from_FObserveLuminosity__root__NoOperatingVoltage(self, x);
        break;
    case FObserveLuminosity__root__ObservingLuminosity:
        transition_from_FObserveLuminosity__root__ObservingLuminosity(self, x);
        break;
    }
}

static void evaluateChangeEvents(FObserveLuminosity *self)
{
    self->Change85.IsTriggered = IsTriggered(
        MakeChange(self->D15inRespondedLuminosity.IsSignalled,
                   self->D15inRespondedLuminosity.Value == FObserveLuminosity_D15inRespondedLuminosityValue__Night));
    self->Change172.IsTriggered = IsTriggered(
        MakeChange(self->D22inSensedLuminosity.IsSignalled,
                   self->D22inSensedLuminosity.Value == FObserveLuminosity_D22inSensedLuminosityValue__Night));
    self->Change84.IsTriggered = IsTriggered(
        MakeChange(self->D15inRespondedLuminosity.IsSignalled,
                   self->D15inRespondedLuminosity.Value == FObserveLuminosity_D15inRespondedLuminosityValue__Day));
    self->Change171.IsTriggered = IsTriggered(
        MakeChange(self->D22inSensedLuminosity.IsSignalled,
                   self->D22inSensedLuminosity.Value == FObserveLuminosity_D22inSensedLuminosityValue__Day));
    self->Change170.IsTriggered = IsTriggered(
        MakeChange(self->D22inSensedLuminosity.IsSignalled,
                   self->D22inSensedLuminosity.Value == FObserveLuminosity_D22inSensedLuminosityValue__Day));
    self->Change173.IsTriggered = IsTriggered(
        MakeChange(self->D22inSensedLuminosity.IsSignalled,
                   self->D22inSensedLuminosity.Value == FObserveLuminosity_D22inSensedLuminosityValue__Night));
    self->Change345.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value == FObserveLuminosity_D51inEstEfesStateValue__Booting));
    self->Change353.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value == FObserveLuminosity_D51inEstEfesStateValue__Booting),
                 MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value == FObserveLuminosity_D51inEstEfesStateValue__Initialising)));
    self->Change381.IsTriggered = IsTriggered(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FObserveLuminosity_D51inEstEfesStateValue__NoOperatingVoltage));
}

static void resetOutputs(FObserveLuminosity *self)
{

    self->D21outObservedLuminosity.IsSignalled = false;
}

static void resetTriggers(FObserveLuminosity *self)
{

    self->D22inSensedLuminosity.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
    self->D15inRespondedLuminosity.IsSignalled = false;
}

void transition_FObserveLuminosity(FObserveLuminosity *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FObserveLuminosity__root(self, &self->state);
    resetTriggers(self);
}

void new_FObserveLuminosity(FObserveLuminosity *self)
{
    make_state_FObserveLuminosity__root(self, &self->state);
}
