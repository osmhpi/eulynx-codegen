
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

    if (self->Change210.IsTriggered)
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
    if (self->Change211.IsTriggered)
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
    if (self->Change214.IsTriggered)
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
    if (self->Change217.IsTriggered)
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
    if (self->Change219.IsTriggered)
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
    if (self->Change283.IsTriggered)
    {
        self->D8outSetIntentionallyDark.Value = true;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
    if (self->Change573.IsTriggered)
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

    if (self->Change215.IsTriggered)
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
    if (self->Change225.IsTriggered)
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
    if (self->Change216.IsTriggered)
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
    if (self->Change450.IsTriggered)
    {
        self->D7outSetSignalAspect.Value = FControlSignalAspect_D7outSetSignalAspectValue__NoSignalAspectLampFailure;
        self->D7outSetSignalAspect.IsSignalled = true;
        self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__NoSignalAspectLampFailure;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
    if (self->Change282.IsTriggered)
    {
        self->D8outSetIntentionallyDark.Value = true;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
    if (self->Change575.IsTriggered)
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

    if (self->Change220.IsTriggered)
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
    if (self->Change224.IsTriggered)
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
    if (self->Change218.IsTriggered)
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
    if (self->Change588.IsTriggered)
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

    if (self->Change212.IsTriggered)
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
    if (self->Change213.IsTriggered)
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
    if (self->Change223.IsTriggered)
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
    if (self->Change221.IsTriggered)
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
    if (self->Change222.IsTriggered)
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
    if (self->Change308.IsTriggered)
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
    if (self->Change310.IsTriggered)
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
    if (self->Change309.IsTriggered)
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
    if (self->Change284.IsTriggered)
    {
        self->D8outSetIntentionallyDark.Value = true;
        make_state_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1(
            self, &x->OperatingVoltage.root.ControllingSignalAspect.root);
        return;
    }
    if (self->Change574.IsTriggered)
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
    if (self->Change521.IsTriggered)
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

    if (self->Change350.IsTriggered)
    {

        make_state_FControlSignalAspect__root__OperatingVoltage(self, x);
        return;
    }
}

void transition_from_FControlSignalAspect__root__OperatingVoltage(FControlSignalAspect *self,
                                                                  FControlSignalAspect__root__state_struct *x)
{
    transition_from_FControlSignalAspect__root__OperatingVoltage__root(self, x);
    if (self->Change359.IsTriggered)
    {
        self->MemSetAspect = FControlSignalAspect_MemSetAspectValue__;
        make_state_FControlSignalAspect__root__OperatingVoltage(self, x);
        return;
    }
    if (self->Change388.IsTriggered)
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
    self->Change210.IsTriggered =
        IsTriggered(OrChange(MakeChange(self->D2inRequiredSignalAspect.IsSignalled,
                                        self->D2inRequiredSignalAspect.Value ==
                                            FControlSignalAspect_D2inRequiredSignalAspectValue__MostRestrictAspect),
                             MakeChange(self->D5inFaultLampsAspect2.IsSignalled, self->D5inFaultLampsAspect2.Value)));
    self->Change211.IsTriggered =
        IsTriggered(OrChange(MakeChange(self->D2inRequiredSignalAspect.IsSignalled,
                                        self->D2inRequiredSignalAspect.Value ==
                                            FControlSignalAspect_D2inRequiredSignalAspectValue__MostRestrictAspect),
                             MakeChange(self->D5inFaultLampsAspect2.IsSignalled, self->D5inFaultLampsAspect2.Value)));
    self->Change214.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change217.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change219.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change283.IsTriggered = IsTriggered(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value));
    self->Change573.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value)));
    self->Change215.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change225.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2));
    self->Change216.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change450.IsTriggered =
        IsTriggered(MakeChange(self->D6inFaultLampsMostRestrict.IsSignalled, self->D6inFaultLampsMostRestrict.Value));
    self->Change282.IsTriggered = IsTriggered(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value));
    self->Change575.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value)));
    self->Change220.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change224.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2));
    self->Change218.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect1));
    self->Change588.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D6inFaultLampsMostRestrict.IsSignalled, self->D6inFaultLampsMostRestrict.Value)));
    self->Change212.IsTriggered =
        IsTriggered(MakeChange(self->D2inRequiredSignalAspect.IsSignalled,
                               self->D2inRequiredSignalAspect.Value ==
                                   FControlSignalAspect_D2inRequiredSignalAspectValue__MostRestrictAspect));
    self->Change213.IsTriggered =
        IsTriggered(MakeChange(self->D2inRequiredSignalAspect.IsSignalled,
                               self->D2inRequiredSignalAspect.Value ==
                                   FControlSignalAspect_D2inRequiredSignalAspectValue__MostRestrictAspect));
    self->Change223.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2));
    self->Change221.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2));
    self->Change222.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredSignalAspect.IsSignalled,
        self->D2inRequiredSignalAspect.Value == FControlSignalAspect_D2inRequiredSignalAspectValue__SignalAspect2));
    self->Change308.IsTriggered =
        IsTriggered(MakeChange(self->D4inFaultLampsAspect1.IsSignalled, self->D4inFaultLampsAspect1.Value));
    self->Change310.IsTriggered =
        IsTriggered(MakeChange(self->D4inFaultLampsAspect1.IsSignalled, self->D4inFaultLampsAspect1.Value));
    self->Change309.IsTriggered =
        IsTriggered(MakeChange(self->D4inFaultLampsAspect1.IsSignalled, self->D4inFaultLampsAspect1.Value));
    self->Change284.IsTriggered = IsTriggered(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value));
    self->Change574.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D3inRequiredIntentionallyDark.IsSignalled, self->D3inRequiredIntentionallyDark.Value)));
    self->Change521.IsTriggered = IsTriggered(
        MakeChange(self->D9inSetLuminosity.IsSignalled,
                   self->D9inSetLuminosity.Value == FControlSignalAspect_D9inSetLuminosityValue__Undefined));
    self->Change350.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value == FControlSignalAspect_D51inEstEfesStateValue__Booting));
    self->Change359.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlSignalAspect_D51inEstEfesStateValue__Booting),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlSignalAspect_D51inEstEfesStateValue__Initialising)));
    self->Change388.IsTriggered = IsTriggered(OrChange(
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
