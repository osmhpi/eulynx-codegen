
#include "FObserveSignalAspect.h"

// Value Conversion Functions

// Operations

void make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
    FObserveSignalAspect *self, FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state SignalAspect2 in region "
        "root__ObservingSignalAspect__root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2;
};

void make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
    FObserveSignalAspect *self, FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state NoSignalAspect in region "
        "root__ObservingSignalAspect__root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect;
};

void make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting(
    FObserveSignalAspect *self, FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state Waiting in region "
        "root__ObservingSignalAspect__root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting;
};

void make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
    FObserveSignalAspect *self, FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state MostRestrictAspect in region "
        "root__ObservingSignalAspect__root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect;
};

void make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
    FObserveSignalAspect *self, FObserveSignalAspect__root__ObservingSignalAspect__root__state_struct *region)
{
    LOG("[FObserveSignalAspect] Entering state SignalAspect1 in region "
        "root__ObservingSignalAspect__root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1;
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
    LOG("[FObserveSignalAspect] Entering state ObservingSignalAspect in region "
        "root");
    region->state = FObserveSignalAspect__root__ObservingSignalAspect;
    make_state_FObserveSignalAspect__root__ObservingSignalAspect__root(self, &region->ObservingSignalAspect.root);
};

void make_state_FObserveSignalAspect__root(FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveSignalAspect__root__state_struct));

    make_state_FObserveSignalAspect__root__NationalAspect(self, x);
    return;
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
    FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{

    if (self->Change115.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change119.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change120.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect1;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change134.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change560.IsTriggered)
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

    if (self->Change113.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change122.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect1;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change123.IsTriggered)
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

    if (self->Change112.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change116.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
    FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{

    if (self->Change118.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change121.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect1;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change125.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect2;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change135.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change559.IsTriggered)
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

    if (self->Change114.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change117.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change124.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect2;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D18inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change136.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change561.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = false;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root(
    FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{
    switch (x->ObservingSignalAspect.root.state)
    {
    case FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2:
        transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect:
        transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting:
        transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting(self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect:
        transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(self, x);
        break;
    case FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1:
        transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(self, x);
        break;
    }
}

void transition_from_FObserveSignalAspect__root__NationalAspect(FObserveSignalAspect *self,
                                                                FObserveSignalAspect__root__state_struct *x)
{

    if (self->Change349.IsTriggered)
    {

        make_state_FObserveSignalAspect__root__ObservingSignalAspect(self, x);
        return;
    }
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect(FObserveSignalAspect *self,
                                                                       FObserveSignalAspect__root__state_struct *x)
{
    transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root(self, x);
    if (self->Change358.IsTriggered)
    {

        make_state_FObserveSignalAspect__root__ObservingSignalAspect(self, x);
        return;
    }
    if (self->Change393.IsTriggered)
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
    self->Change115.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__MostRestrictAspect));
    self->Change119.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspect)));
    self->Change120.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect1));
    self->Change134.IsTriggered = IsTriggered(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value));
    self->Change560.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value)));
    self->Change113.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__MostRestrictAspect));
    self->Change122.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect1));
    self->Change123.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect2));
    self->Change112.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__MostRestrictAspect));
    self->Change116.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspect)));
    self->Change118.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspect)));
    self->Change121.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect1));
    self->Change125.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect2));
    self->Change135.IsTriggered = IsTriggered(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value));
    self->Change559.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value)));
    self->Change114.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__MostRestrictAspect));
    self->Change117.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D17inSensedSignalAspect.IsSignalled,
                            self->D17inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D17inSensedSignalAspectValue__NoSignalAspect)));
    self->Change124.IsTriggered = IsTriggered(MakeChange(
        self->D17inSensedSignalAspect.IsSignalled,
        self->D17inSensedSignalAspect.Value == FObserveSignalAspect_D17inSensedSignalAspectValue__SignalAspect2));
    self->Change136.IsTriggered = IsTriggered(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value));
    self->Change561.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D18inSensedIntentionallyDark.IsSignalled, self->D18inSensedIntentionallyDark.Value)));
    self->Change349.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value == FObserveSignalAspect_D51inEstEfesStateValue__Booting));
    self->Change358.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FObserveSignalAspect_D51inEstEfesStateValue__Booting),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FObserveSignalAspect_D51inEstEfesStateValue__Initialising)));
    self->Change393.IsTriggered = IsTriggered(OrChange(
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
