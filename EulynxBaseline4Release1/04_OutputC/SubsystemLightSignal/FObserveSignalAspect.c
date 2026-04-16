
#include "FObserveSignalAspect.h"

// Value Conversion Functions

// Operations

void make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
    FObserveSignalAspect *self, FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state MostRestrictAspect in region root__ObservingSignalAspect__root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect;
};

void make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
    FObserveSignalAspect *self, FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state SignalAspect1 in region root__ObservingSignalAspect__root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1;
};

void make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
    FObserveSignalAspect *self, FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state SignalAspect2 in region root__ObservingSignalAspect__root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2;
};

void make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
    FObserveSignalAspect *self, FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state NoSignalAspect in region root__ObservingSignalAspect__root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect;
};

void make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting(
    FObserveSignalAspect *self, FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state Waiting in region root__ObservingSignalAspect__root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting;
};

void make_state_FObserveSignalAspect__root__ObservingSignalAspect__root(
    FObserveSignalAspect *self, FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct));

    make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting(self, x);
    return;
}

void make_state_FObserveSignalAspect__root__NationalAspect(FObserveSignalAspect *self,
                                                           FObserveSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state NationalAspect in region root");
    region->state = FObserveSignalAspect__root__NationalAspect;
};

void make_state_FObserveSignalAspect__root__ObservingSignalAspect(FObserveSignalAspect *self,
                                                                  FObserveSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state ObservingSignalAspect in region root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect;
    make_state_FObserveSignalAspect__root__ObservingSignalAspect__root(self, &region->ObservingSignalAspect.root);
};

void make_state_FObserveSignalAspect__root(FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveSignalAspect__root__state_struct));

    make_state_FObserveSignalAspect__root__NationalAspect(self, x);
    return;
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
    FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{

    if (self->Change93.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change97.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect1;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change100.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect2;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change110.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change562.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = false;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
    FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{

    if (self->Change87.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change91.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change99.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect2;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change109.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change563.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = false;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
    FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{

    if (self->Change89.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change92.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change96.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect1;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change111.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change564.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = false;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
    FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{

    if (self->Change90.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change95.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect1;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change98.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect2;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting(
    FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{

    if (self->Change88.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change94.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root(
    FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    switch (x->ObservingSignalAspect.root.state)
    {
    case FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect:
        transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1:
        transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2:
        transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect:
        transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting:
        transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting(self, x);
        break;
    }
}

void transition_from_FObserveSignalAspect__root__NationalAspect(FObserveSignalAspect *self,
                                                                FObserveSignalAspect__root__state_struct *x)
{

    if (self->Change346.IsTriggered)
    {

        make_state_FObserveSignalAspect__root__ObservingSignalAspect(self, x);
        return;
    }
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect(FObserveSignalAspect *self,
                                                                       FObserveSignalAspect__root__state_struct *x)
{
    transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root(self, x);
    if (self->Change354.IsTriggered)
    {

        make_state_FObserveSignalAspect__root__ObservingSignalAspect(self, x);
        return;
    }
    if (self->Change385.IsTriggered)
    {

        make_state_FObserveSignalAspect__root__NationalAspect(self, x);
        return;
    }
}

void transition_from_FObserveSignalAspect__root(FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveSignalAspect__root__NationalAspect:
        transition_from_FObserveSignalAspect__root__NationalAspect(self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect:
        transition_from_FObserveSignalAspect__root__ObservingSignalAspect(self, x);
        break;
    }
}

static void evaluateChangeEvents(FObserveSignalAspect *self)
{
    self->Change93.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspect)));
    self->Change97.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect1));
    self->Change100.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect2));
    self->Change110.IsTriggered = IsTriggered(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value));
    self->Change562.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value)));
    self->Change87.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__MostRestrictAspect));
    self->Change91.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspect)));
    self->Change99.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect2));
    self->Change109.IsTriggered = IsTriggered(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value));
    self->Change563.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value)));
    self->Change89.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__MostRestrictAspect));
    self->Change92.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspect)));
    self->Change96.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect1));
    self->Change111.IsTriggered = IsTriggered(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value));
    self->Change564.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value)));
    self->Change90.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__MostRestrictAspect));
    self->Change95.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect1));
    self->Change98.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect2));
    self->Change88.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__MostRestrictAspect));
    self->Change94.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspect)));
    self->Change346.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value == FObserveSignalAspect_D51inEstEfesStateValue__Booting));
    self->Change354.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FObserveSignalAspect_D51inEstEfesStateValue__Booting),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FObserveSignalAspect_D51inEstEfesStateValue__Initialising)));
    self->Change385.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FObserveSignalAspect_D51inEstEfesStateValue__NoOperatingVoltage),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FObserveSignalAspect_D51inEstEfesStateValue__FallbackMode)));
}

static void resetOutputs(FObserveSignalAspect *self)
{

    self->D19outObservedSignalAspect.IsSignalled = false;
    self->D20outObservedIntentionallyDark.IsSignalled = false;
}

static void resetTriggers(FObserveSignalAspect *self)
{

    self->D18inSensedIntentionallyDark.IsSignalled = false;
    self->D17inSensedSignalAspect.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
}

void transition_FObserveSignalAspect(FObserveSignalAspect *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FObserveSignalAspect__root(self, &self->state);
    resetTriggers(self);
}

void new_FObserveSignalAspect(FObserveSignalAspect *self)
{
    make_state_FObserveSignalAspect__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemLightSignal/FObserveSignalAspect.c"
#endif
