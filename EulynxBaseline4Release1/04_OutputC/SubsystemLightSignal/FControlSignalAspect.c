
#include "FControlSignalAspect.h"

// Value Conversion Functions

// Operations

void make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
    FControlSignalAspect *self,
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct *region)
{
    LOG("[FControlSignalAspect] Entering state SignalAspect2 in region "
        "root__OperatingVoltage__root__ControllingSignalAspect__root");
    region->state = FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2;
};

void make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
    FControlSignalAspect *self,
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct *region)
{
    LOG("[FControlSignalAspect] Entering state MostRestrictiveAspect in region "
        "root__OperatingVoltage__root__ControllingSignalAspect__root");
    region->state =
        FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect;
};

void make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
    FControlSignalAspect *self,
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct *region)
{
    LOG("[FControlSignalAspect] Entering state NoSignalAspectLampFailure in region "
        "root__OperatingVoltage__root__ControllingSignalAspect__root");
    region->state =
        FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure;
};

void make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1(
    FControlSignalAspect *self,
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct *region)
{
    LOG("[FControlSignalAspect] Entering state SignalAspect1 in region "
        "root__OperatingVoltage__root__ControllingSignalAspect__root");
    region->state = FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1;
};

void make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root(
    FControlSignalAspect *self,
    FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct *x)
{
    memset(x, 0,
           sizeof(FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__state_struct));

    if (!(self->D6inFaultLampsMostRestrict.Value))
    {
        self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__MostRestrictAspect;
        self->D7outSetSignalAspect.IsSignalled = true;
        self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
        self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__MostRestrictAspect;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
            self, x);
        return;
    }
    else
    {
        self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspectLampFailure;
        self->D7outSetSignalAspect.IsSignalled = true;
        self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__NoSignalAspectLampFailure;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
            self, x);
        return;
    }
}

void make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect(
    FControlSignalAspect *self, FControlSignalAspect__root__OperatingVoltage__root__state_struct *region)
{
    LOG("[FControlSignalAspect] Entering state ControllingSignalAspect in region root__OperatingVoltage__root");
    region->state = FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect;
    make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root(
        self, &region->ControllingSignalAspect.root);
};

void make_state_FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspect(
    FControlSignalAspect *self, FControlSignalAspect__root__OperatingVoltage__root__state_struct *region)
{
    LOG("[FControlSignalAspect] Entering state SetNoSignalAspect in region root__OperatingVoltage__root");
    region->state = FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspect;
};

void make_state_FControlSignalAspect__root__OperatingVoltage__root(
    FControlSignalAspect *self, FControlSignalAspect__root__OperatingVoltage__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlSignalAspect__root__OperatingVoltage__root__state_struct));

    make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect(self, x);
    return;
}

void make_state_FControlSignalAspect__root__NationalAspect(FControlSignalAspect *self,
                                                           FControlSignalAspect__root__state_struct *region)
{
    LOG("[FControlSignalAspect] Entering state NationalAspect in region root");
    region->state = FControlSignalAspect__root__NationalAspect;
};

void make_state_FControlSignalAspect__root__OperatingVoltage(FControlSignalAspect *self,
                                                             FControlSignalAspect__root__state_struct *region)
{
    LOG("[FControlSignalAspect] Entering state OperatingVoltage in region root");
    region->state = FControlSignalAspect__root__OperatingVoltage;
    make_state_FControlSignalAspect__root__OperatingVoltage__root(self, &region->OperatingVoltage.root);
};

void make_state_FControlSignalAspect__root(FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlSignalAspect__root__state_struct));
    self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__NationalAspect;
    self->D7outSetSignalAspect.IsSignalled = true;
    self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__;
    make_state_FControlSignalAspect__root__NationalAspect(self, x);
    return;
}

void transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
    FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{

    if (self->Change193.IsTriggered)
    {
        if (self->D6inFaultLampsMostRestrict.Value)
        {
            self->D7outSetSignalAspect.Value =
                FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspectLampFailure;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__NoSignalAspectLampFailure;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change195.IsTriggered)
    {
        if (!(self->D6inFaultLampsMostRestrict.Value))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__MostRestrictAspect;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__MostRestrictAspect;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change201.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D6inFaultLampsMostRestrict.Value))) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__MostRestrictAspect;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__MostRestrictAspect;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change200.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (self->D6inFaultLampsMostRestrict.Value)) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            self->D7outSetSignalAspect.Value =
                FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspectLampFailure;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__NoSignalAspectLampFailure;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change202.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect1;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__SignalAspect1;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change274.IsTriggered)
    {
        self->D8outSetIntentionallyDark.Value = true;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
    if (self->Change574.IsTriggered)
    {
        self->D8outSetIntentionallyDark.Value = false;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
}

void transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
    FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{

    if (self->Change197.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect1;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__SignalAspect1;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change204.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect2;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__SignalAspect2;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change199.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D5inFaultLampsAspect2.Value))) &&
            (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect2;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__SignalAspect2;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change449.IsTriggered)
    {
        self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspectLampFailure;
        self->D7outSetSignalAspect.IsSignalled = true;
        self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__NoSignalAspectLampFailure;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
    if (self->Change273.IsTriggered)
    {
        self->D8outSetIntentionallyDark.Value = true;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
    if (self->Change572.IsTriggered)
    {
        self->D8outSetIntentionallyDark.Value = false;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
}

void transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
    FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{

    if (self->Change198.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect1;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__SignalAspect1;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change206.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect2;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__SignalAspect2;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change203.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D5inFaultLampsAspect2.Value))) &&
            (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect2;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__SignalAspect2;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change586.IsTriggered)
    {
        self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__MostRestrictAspect;
        self->D7outSetSignalAspect.IsSignalled = true;
        self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
        self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__MostRestrictAspect;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
}

void transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1(
    FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{

    if (self->Change196.IsTriggered)
    {
        if (self->D6inFaultLampsMostRestrict.Value)
        {
            self->D7outSetSignalAspect.Value =
                FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspectLampFailure;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__NoSignalAspectLampFailure;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change194.IsTriggered)
    {
        if (!(self->D6inFaultLampsMostRestrict.Value))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__MostRestrictAspect;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__MostRestrictAspect;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change208.IsTriggered)
    {
        if ((self->D5inFaultLampsAspect2.Value) && (self->D6inFaultLampsMostRestrict.Value))
        {
            self->D7outSetSignalAspect.Value =
                FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspectLampFailure;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__NoSignalAspectLampFailure;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change205.IsTriggered)
    {
        if ((self->D5inFaultLampsAspect2.Value) && (!(self->D6inFaultLampsMostRestrict.Value)))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__MostRestrictAspect;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__MostRestrictAspect;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change207.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect2;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__SignalAspect2;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change306.IsTriggered)
    {
        if ((!(self->D6inFaultLampsMostRestrict.Value)) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__MostRestrictAspect;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__MostRestrictAspect;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change304.IsTriggered)
    {
        if ((self->D6inFaultLampsMostRestrict.Value) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            self->D7outSetSignalAspect.Value =
                FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspectLampFailure;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__NoSignalAspectLampFailure;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change305.IsTriggered)
    {
        if ((!(self->D5inFaultLampsAspect2.Value)) && (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__SignalAspect2;
            self->D7outSetSignalAspect.IsSignalled = true;
            self->D8outSetIntentionallyDark.Value = self->D3inRequiredIntentionallyDark.Value;
            self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__SignalAspect2;
            make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
                self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
            return;
        }
    }
    if (self->Change272.IsTriggered)
    {
        self->D8outSetIntentionallyDark.Value = true;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
    if (self->Change573.IsTriggered)
    {
        self->D8outSetIntentionallyDark.Value = false;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
}

void transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root(
    FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    switch (x->OperatingVoltage.root.ControllingSignalAspect.root.state)
    {
    case FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2:
        transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
            self, x);
        break;
    case FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect:
        transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
            self, x);
        break;
    case FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure:
        transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
            self, x);
        break;
    case FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1:
        transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1(
            self, x);
        break;
    }
}

void transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect(
    FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root(self, x);
    if (self->Change524.IsTriggered)
    {
        self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspect;
        self->D7outSetSignalAspect.IsSignalled = true;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspect(self,
                                                                                         &x->OperatingVoltage.root);
        return;
    }
}

void transition_from_FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspect(
    FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
}

void transition_from_FControlSignalAspect__root__OperatingVoltage__root(FControlSignalAspect *self,
                                                                        FControlSignalAspect__root__state_struct *x)
{
    switch (x->OperatingVoltage.root.state)
    {
    case FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect:
        transition_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect(self, x);
        break;
    case FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspect:
        transition_from_FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspect(self, x);
        break;
    }
}

void transition_from_FControlSignalAspect__root__NationalAspect(FControlSignalAspect *self,
                                                                FControlSignalAspect__root__state_struct *x)
{

    if (self->Change344.IsTriggered)
    {

        make_state_FControlSignalAspect__root__OperatingVoltage(self, x);
        return;
    }
}

void transition_from_FControlSignalAspect__root__OperatingVoltage(FControlSignalAspect *self,
                                                                  FControlSignalAspect__root__state_struct *x)
{
    transition_from_FControlSignalAspect__root__OperatingVoltage__root(self, x);
    if (self->Change352.IsTriggered)
    {
        self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__;
        make_state_FControlSignalAspect__root__OperatingVoltage(self, x);
        return;
    }
    if (self->Change386.IsTriggered)
    {
        self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__NationalAspect;
        self->D7outSetSignalAspect.IsSignalled = true;
        self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__;
        make_state_FControlSignalAspect__root__NationalAspect(self, x);
        return;
    }
}

void transition_from_FControlSignalAspect__root(FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlSignalAspect__root__NationalAspect:
        transition_from_FControlSignalAspect__root__NationalAspect(self, x);
        break;
    case FControlSignalAspect__root__OperatingVoltage:
        transition_from_FControlSignalAspect__root__OperatingVoltage(self, x);
        break;
    }
}

static void evaluateChangeEvents(FControlSignalAspect *self)
{
    self->Change193.IsTriggered =
        IsTriggered(OrChange(MakeChange(self->D2inRequiredSignalAspect.IsSignalled,
                                        self->D2inRequiredSignalAspect.Value ==
                                            FControlSignalAspect_D2inRequiredSignalAspectValue__MostRestrictAspect),
                             MakeChange(self->D5inFaultLampsAspect2.IsSignalled, self->D5inFaultLampsAspect2.Value)));
    self->Change195.IsTriggered =
        IsTriggered(OrChange(MakeChange(self->D2inRequiredSignalAspect.IsSignalled,
                                        self->D2inRequiredSignalAspect.Value ==
                                            FControlSignalAspect_D2inRequiredSignalAspectValue__MostRestrictAspect),
                             MakeChange(self->D5inFaultLampsAspect2.IsSignalled, self->D5inFaultLampsAspect2.Value)));
    self->Change201.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change200.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change202.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change274.IsTriggered = IsTriggered(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value));
    self->Change574.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value)));
    self->Change197.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change204.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2));
    self->Change199.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change449.IsTriggered =
        IsTriggered(MakeChange(self->D6inFaultLampsMostRestrict.IsSignalled, self->D6inFaultLampsMostRestrict.Value));
    self->Change273.IsTriggered = IsTriggered(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value));
    self->Change572.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value)));
    self->Change198.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change206.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2));
    self->Change203.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change586.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D6inFaultLampsMostRestrict.IsSignalled, self->D6inFaultLampsMostRestrict.Value)));
    self->Change196.IsTriggered =
        IsTriggered(MakeChange(self->D2inRequiredSignalAspect.IsSignalled,
                               self->D2inRequiredSignalAspect.Value ==
                                   FControlSignalAspect_D2inRequiredSignalAspectValue__MostRestrictAspect));
    self->Change194.IsTriggered =
        IsTriggered(MakeChange(self->D2inRequiredSignalAspect.IsSignalled,
                               self->D2inRequiredSignalAspect.Value ==
                                   FControlSignalAspect_D2inRequiredSignalAspectValue__MostRestrictAspect));
    self->Change208.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2));
    self->Change205.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2));
    self->Change207.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2));
    self->Change306.IsTriggered =
        IsTriggered(MakeChange(self->D4inFaultLampsAspect1.IsSignalled, self->D4inFaultLampsAspect1.Value));
    self->Change304.IsTriggered =
        IsTriggered(MakeChange(self->D4inFaultLampsAspect1.IsSignalled, self->D4inFaultLampsAspect1.Value));
    self->Change305.IsTriggered =
        IsTriggered(MakeChange(self->D4inFaultLampsAspect1.IsSignalled, self->D4inFaultLampsAspect1.Value));
    self->Change272.IsTriggered = IsTriggered(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value));
    self->Change573.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value)));
    self->Change524.IsTriggered = IsTriggered(
        MakeChange(self->D9inSetLuminosity.IsSignalled,
                   self->D9inSetLuminosity.Value == FControlSignalAspect_D9inSetLuminosityValue__Undefined));
    self->Change344.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value == FControlSignalAspect_D51inEstEfesStateValue__Booting));
    self->Change352.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlSignalAspect_D51inEstEfesStateValue__Booting),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlSignalAspect_D51inEstEfesStateValue__Initialising)));
    self->Change386.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlSignalAspect_D51inEstEfesStateValue__NoOperatingVoltage),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlSignalAspect_D51inEstEfesStateValue__FallbackMode)));
}

static void resetOutputs(FControlSignalAspect *self)
{

    self->D7outSetSignalAspect.IsSignalled = false;
    self->D8outSetIntentionallyDark.IsSignalled = false;
}

static void resetTriggers(FControlSignalAspect *self)
{

    self->D3inRequiredIntentionallyDark.IsSignalled = false;
    self->D2inRequiredSignalAspect.IsSignalled = false;
    self->D4inFaultLampsAspect1.IsSignalled = false;
    self->D5inFaultLampsAspect2.IsSignalled = false;
    self->D6inFaultLampsMostRestrict.IsSignalled = false;
    self->D9inSetLuminosity.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
    self->D10inConDowngradeMostRestrict.IsSignalled = false;
}

void transition_FControlSignalAspect(FControlSignalAspect *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FControlSignalAspect__root(self, &self->state);
    resetTriggers(self);
}

void new_FControlSignalAspect(FControlSignalAspect *self)
{
    make_state_FControlSignalAspect__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemLightSignal/FControlSignalAspect.c"
#endif
