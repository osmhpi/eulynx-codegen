
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

    if (self->D7inSensedSignalAspect.Value == FObserveSignalAspect_D7inSensedSignalAspectValue__MostRestrictAspect)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D8inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(self, x);
        return;
    }
    if ((self->D7inSensedSignalAspect.Value ==
         FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLampFailure) ||
        (self->D7inSensedSignalAspect.Value ==
         FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLuminosityFailure))
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(self, x);
        return;
    }
    else
    {

        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting(self, x);
        return;
    }
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

    if (self->Change450.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D8inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change454.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change459.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect1;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D8inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change486.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change580.IsTriggered)
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

    if (self->Change452.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D8inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change457.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect1;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D8inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change462.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect2;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D8inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root__Waiting(
    FObserveSignalAspect *self, FObserveSignalAspect__root__state_struct *x)
{

    if (self->Change451.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D8inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change455.IsTriggered)
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

    if (self->Change453.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change458.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect1;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D8inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change460.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect2;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D8inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change485.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change579.IsTriggered)
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

    if (self->Change449.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value =
            FObserveSignalAspect_D19outObservedSignalAspectValue__MostRestrictAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D8inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__MostRestrictAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change456.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__NoSignalAspect;
        self->D19outObservedSignalAspect.IsSignalled = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__NoSignalAspect(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change461.IsTriggered)
    {
        self->D19outObservedSignalAspect.Value = FObserveSignalAspect_D19outObservedSignalAspectValue__SignalAspect2;
        self->D19outObservedSignalAspect.IsSignalled = true;
        self->D20outObservedIntentionallyDark.Value = self->D8inSensedIntentionallyDark.Value;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect2(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change484.IsTriggered)
    {
        self->D20outObservedIntentionallyDark.Value = true;
        make_state_FObserveSignalAspect__root__ObservingSignalAspect__root__SignalAspect1(
            self, &x->ObservingSignalAspect.root);
        return;
    }
    if (self->Change581.IsTriggered)
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

    if (self->Change331.IsTriggered)
    {

        make_state_FObserveSignalAspect__root__ObservingSignalAspect(self, x);
        return;
    }
}

void transition_from_FObserveSignalAspect__root__ObservingSignalAspect(FObserveSignalAspect *self,
                                                                       FObserveSignalAspect__root__state_struct *x)
{
    transition_from_FObserveSignalAspect__root__ObservingSignalAspect__root(self, x);
    if (self->Change338.IsTriggered)
    {

        make_state_FObserveSignalAspect__root__ObservingSignalAspect(self, x);
        return;
    }
    if (self->Change373.IsTriggered)
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
    self->Change450.IsTriggered = IsTriggered(MakeChange(
        self->D7inSensedSignalAspect.IsSignalled,
        self->D7inSensedSignalAspect.Value == FObserveSignalAspect_D7inSensedSignalAspectValue__MostRestrictAspect));
    self->Change454.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D7inSensedSignalAspect.IsSignalled,
                            self->D7inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D7inSensedSignalAspect.IsSignalled,
                            self->D7inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLuminosityFailure)));
    self->Change459.IsTriggered = IsTriggered(MakeChange(
        self->D7inSensedSignalAspect.IsSignalled,
        self->D7inSensedSignalAspect.Value == FObserveSignalAspect_D7inSensedSignalAspectValue__SignalAspect1));
    self->Change486.IsTriggered =
        IsTriggered(MakeChange(self->D8inSensedIntentionallyDark.IsSignalled, self->D8inSensedIntentionallyDark.Value));
    self->Change580.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D8inSensedIntentionallyDark.IsSignalled, self->D8inSensedIntentionallyDark.Value)));
    self->Change452.IsTriggered = IsTriggered(MakeChange(
        self->D7inSensedSignalAspect.IsSignalled,
        self->D7inSensedSignalAspect.Value == FObserveSignalAspect_D7inSensedSignalAspectValue__MostRestrictAspect));
    self->Change457.IsTriggered = IsTriggered(MakeChange(
        self->D7inSensedSignalAspect.IsSignalled,
        self->D7inSensedSignalAspect.Value == FObserveSignalAspect_D7inSensedSignalAspectValue__SignalAspect1));
    self->Change462.IsTriggered = IsTriggered(MakeChange(
        self->D7inSensedSignalAspect.IsSignalled,
        self->D7inSensedSignalAspect.Value == FObserveSignalAspect_D7inSensedSignalAspectValue__SignalAspect2));
    self->Change451.IsTriggered = IsTriggered(MakeChange(
        self->D7inSensedSignalAspect.IsSignalled,
        self->D7inSensedSignalAspect.Value == FObserveSignalAspect_D7inSensedSignalAspectValue__MostRestrictAspect));
    self->Change455.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D7inSensedSignalAspect.IsSignalled,
                            self->D7inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D7inSensedSignalAspect.IsSignalled,
                            self->D7inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLuminosityFailure)));
    self->Change453.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D7inSensedSignalAspect.IsSignalled,
                            self->D7inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D7inSensedSignalAspect.IsSignalled,
                            self->D7inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLuminosityFailure)));
    self->Change458.IsTriggered = IsTriggered(MakeChange(
        self->D7inSensedSignalAspect.IsSignalled,
        self->D7inSensedSignalAspect.Value == FObserveSignalAspect_D7inSensedSignalAspectValue__SignalAspect1));
    self->Change460.IsTriggered = IsTriggered(MakeChange(
        self->D7inSensedSignalAspect.IsSignalled,
        self->D7inSensedSignalAspect.Value == FObserveSignalAspect_D7inSensedSignalAspectValue__SignalAspect2));
    self->Change485.IsTriggered =
        IsTriggered(MakeChange(self->D8inSensedIntentionallyDark.IsSignalled, self->D8inSensedIntentionallyDark.Value));
    self->Change579.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D8inSensedIntentionallyDark.IsSignalled, self->D8inSensedIntentionallyDark.Value)));
    self->Change449.IsTriggered = IsTriggered(MakeChange(
        self->D7inSensedSignalAspect.IsSignalled,
        self->D7inSensedSignalAspect.Value == FObserveSignalAspect_D7inSensedSignalAspectValue__MostRestrictAspect));
    self->Change456.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D7inSensedSignalAspect.IsSignalled,
                            self->D7inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLampFailure),
                 MakeChange(self->D7inSensedSignalAspect.IsSignalled,
                            self->D7inSensedSignalAspect.Value ==
                                FObserveSignalAspect_D7inSensedSignalAspectValue__NoSignalAspectLuminosityFailure)));
    self->Change461.IsTriggered = IsTriggered(MakeChange(
        self->D7inSensedSignalAspect.IsSignalled,
        self->D7inSensedSignalAspect.Value == FObserveSignalAspect_D7inSensedSignalAspectValue__SignalAspect2));
    self->Change484.IsTriggered =
        IsTriggered(MakeChange(self->D8inSensedIntentionallyDark.IsSignalled, self->D8inSensedIntentionallyDark.Value));
    self->Change581.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D8inSensedIntentionallyDark.IsSignalled, self->D8inSensedIntentionallyDark.Value)));
    self->Change331.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value == FObserveSignalAspect_D51inEstEfesStateValue__Booting));
    self->Change338.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FObserveSignalAspect_D51inEstEfesStateValue__Booting),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FObserveSignalAspect_D51inEstEfesStateValue__Initialising)));
    self->Change373.IsTriggered = IsTriggered(OrChange(
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

    self->D8inSensedIntentionallyDark.IsSignalled = false;
    self->D7inSensedSignalAspect.IsSignalled = false;
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
