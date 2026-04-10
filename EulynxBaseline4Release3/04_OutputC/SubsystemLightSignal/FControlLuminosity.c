
#include "FControlLuminosity.h"

// Value Conversion Functions

// Operations

void make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night(
    FControlLuminosity *self,
    FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__state_struct *region)
{
    LOG("[FControlLuminosity] Entering state Night in region "
        "root__OperatingVoltage__root__ControllingLuminosity__root");
    region->state = FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night;
};

void make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day(
    FControlLuminosity *self,
    FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__state_struct *region)
{
    LOG("[FControlLuminosity] Entering state Day in region "
        "root__OperatingVoltage__root__ControllingLuminosity__root");
    region->state = FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day;
};

void make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined(
    FControlLuminosity *self,
    FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__state_struct *region)
{
    LOG("[FControlLuminosity] Entering state Undefined in region "
        "root__OperatingVoltage__root__ControllingLuminosity__root");
    region->state = FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined;
};

void make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root(
    FControlLuminosity *self,
    FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__state_struct));

    if (((self->D12inConLuminosity.Value == true) && (!(self->D13inLuminosityDayFault.Value))) ||
        ((((self->D14inLuminosityNightFault.Value) && (self->D12inConLuminosity.Value == false)) &&
          (!(self->D13inLuminosityDayFault.Value))) &&
         (!(self->D16inLuminositySetUnchangeable.Value))))
    {
        self->D9outSetLuminosity.Value = FControlLuminosity_D9outSetLuminosityValue__Day;
        self->D9outSetLuminosity.IsSignalled = true;
        make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day(self, x);
        return;
    }
    if (((self->D12inConLuminosity.Value == false) && (!(self->D14inLuminosityNightFault.Value))) ||
        ((((self->D13inLuminosityDayFault.Value) && (self->D12inConLuminosity.Value == true)) &&
          (!(self->D14inLuminosityNightFault.Value))) &&
         (!(self->D16inLuminositySetUnchangeable.Value))))
    {
        self->D9outSetLuminosity.Value = FControlLuminosity_D9outSetLuminosityValue__Night;
        self->D9outSetLuminosity.IsSignalled = true;
        make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night(self, x);
        return;
    }
    else
    {
        self->T5outSilNotFulfilled.Trigger = true;
        self->D9outSetLuminosity.Value = FControlLuminosity_D9outSetLuminosityValue__Undefined;
        self->D9outSetLuminosity.IsSignalled = true;
        make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined(self, x);
        return;
    }
}

void make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity(
    FControlLuminosity *self, FControlLuminosity__root__OperatingVoltage__root__state_struct *region)
{
    LOG("[FControlLuminosity] Entering state ControllingLuminosity in region "
        "root__OperatingVoltage__root");
    region->state = FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity;
    make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root(
        self, &region->ControllingLuminosity.root);
};

void make_state_FControlLuminosity__root__OperatingVoltage__root(
    FControlLuminosity *self, FControlLuminosity__root__OperatingVoltage__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlLuminosity__root__OperatingVoltage__root__state_struct));

    make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity(self, x);
    return;
}

void make_state_FControlLuminosity__root__NoOperatingVoltage(FControlLuminosity *self,
                                                             FControlLuminosity__root__state_struct *region)
{
    LOG("[FControlLuminosity] Entering state NoOperatingVoltage in region root");
    region->state = FControlLuminosity__root__NoOperatingVoltage;
};

void make_state_FControlLuminosity__root__OperatingVoltage(FControlLuminosity *self,
                                                           FControlLuminosity__root__state_struct *region)
{
    LOG("[FControlLuminosity] Entering state OperatingVoltage in region root");
    region->state = FControlLuminosity__root__OperatingVoltage;
    make_state_FControlLuminosity__root__OperatingVoltage__root(self, &region->OperatingVoltage.root);
};

void make_state_FControlLuminosity__root(FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlLuminosity__root__state_struct));

    make_state_FControlLuminosity__root__NoOperatingVoltage(self, x);
    return;
}

void transition_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night(
    FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{

    if (self->Change109.IsTriggered)
    {
        if ((!(self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Operational)) &&
            ((self->D16inLuminositySetUnchangeable.Value) || (self->D13inLuminosityDayFault.Value)))
        {
            self->T5outSilNotFulfilled.Trigger = true;
            self->D9outSetLuminosity.Value = FControlLuminosity_D9outSetLuminosityValue__Undefined;
            self->D9outSetLuminosity.IsSignalled = true;
            make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined(
                self, &x->OperatingVoltage.root.ControllingLuminosity.root);
            return;
        }
    }
    if (self->Change110.IsTriggered)
    {
        if ((self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Operational) &&
            ((self->D16inLuminositySetUnchangeable.Value) || (self->D13inLuminosityDayFault.Value)))
        {
            self->D9outSetLuminosity.Value = FControlLuminosity_D9outSetLuminosityValue__Undefined;
            self->D9outSetLuminosity.IsSignalled = true;
            make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined(
                self, &x->OperatingVoltage.root.ControllingLuminosity.root);
            return;
        }
    }
    if (self->Change111.IsTriggered)
    {
        if ((!(self->D13inLuminosityDayFault.Value)) && (!(self->D16inLuminositySetUnchangeable.Value)))
        {
            self->D9outSetLuminosity.Value = FControlLuminosity_D9outSetLuminosityValue__Day;
            self->D9outSetLuminosity.IsSignalled = true;
            make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day(
                self, &x->OperatingVoltage.root.ControllingLuminosity.root);
            return;
        }
    }
}

void transition_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day(
    FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{

    if (self->Change91.IsTriggered)
    {
        if ((!(self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Operational)) &&
            ((self->D16inLuminositySetUnchangeable.Value) || (self->D14inLuminosityNightFault.Value)))
        {
            self->T5outSilNotFulfilled.Trigger = true;
            self->D9outSetLuminosity.Value = FControlLuminosity_D9outSetLuminosityValue__Undefined;
            self->D9outSetLuminosity.IsSignalled = true;
            make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined(
                self, &x->OperatingVoltage.root.ControllingLuminosity.root);
            return;
        }
    }
    if (self->Change92.IsTriggered)
    {
        if ((self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Operational) &&
            ((self->D16inLuminositySetUnchangeable.Value) || (self->D14inLuminosityNightFault.Value)))
        {
            self->D9outSetLuminosity.Value = FControlLuminosity_D9outSetLuminosityValue__Undefined;
            self->D9outSetLuminosity.IsSignalled = true;
            make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined(
                self, &x->OperatingVoltage.root.ControllingLuminosity.root);
            return;
        }
    }
    if (self->Change93.IsTriggered)
    {
        if ((!(self->D14inLuminosityNightFault.Value)) && (!(self->D16inLuminositySetUnchangeable.Value)))
        {
            self->D9outSetLuminosity.Value = FControlLuminosity_D9outSetLuminosityValue__Night;
            self->D9outSetLuminosity.IsSignalled = true;
            make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night(
                self, &x->OperatingVoltage.root.ControllingLuminosity.root);
            return;
        }
    }
}

void transition_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined(
    FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{

    if (self->Change540.IsTriggered)
    {
        if ((self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Operational) &&
            ((!(self->D16inLuminositySetUnchangeable.Value)) ||
             ((self->D16inLuminositySetUnchangeable.Value) &&
              ((self->D11inRequiredLuminosity.Value == FControlLuminosity_D11inRequiredLuminosityValue__Day) ||
               (self->D12inConLuminosity.Value)))))
        {
            self->D9outSetLuminosity.Value = FControlLuminosity_D9outSetLuminosityValue__Day;
            self->D9outSetLuminosity.IsSignalled = true;
            make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day(
                self, &x->OperatingVoltage.root.ControllingLuminosity.root);
            return;
        }
    }
    if (self->Change545.IsTriggered)
    {
        if ((self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Operational) &&
            ((!(self->D16inLuminositySetUnchangeable.Value)) ||
             ((self->D16inLuminositySetUnchangeable.Value) &&
              ((self->D11inRequiredLuminosity.Value == FControlLuminosity_D11inRequiredLuminosityValue__Night) ||
               (!(self->D12inConLuminosity.Value))))))
        {
            self->D9outSetLuminosity.Value = FControlLuminosity_D9outSetLuminosityValue__Night;
            self->D9outSetLuminosity.IsSignalled = true;
            make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night(
                self, &x->OperatingVoltage.root.ControllingLuminosity.root);
            return;
        }
    }
}

void transition_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root(
    FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{
    switch (x->OperatingVoltage.root.ControllingLuminosity.root.state)
    {
    case FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night:
        transition_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night(self, x);
        break;
    case FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day:
        transition_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day(self, x);
        break;
    case FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined:
        transition_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined(self,
                                                                                                                 x);
        break;
    }
}

void transition_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity(
    FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{
    transition_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root(self, x);
    if (self->Change342.IsTriggered)
    {

        make_state_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity(self,
                                                                                           &x->OperatingVoltage.root);
        return;
    }
}

void transition_from_FControlLuminosity__root__OperatingVoltage__root(FControlLuminosity *self,
                                                                      FControlLuminosity__root__state_struct *x)
{
    switch (x->OperatingVoltage.root.state)
    {
    case FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity:
        transition_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity(self, x);
        break;
    }
}

void transition_from_FControlLuminosity__root__NoOperatingVoltage(FControlLuminosity *self,
                                                                  FControlLuminosity__root__state_struct *x)
{

    if (self->Change333.IsTriggered)
    {

        make_state_FControlLuminosity__root__OperatingVoltage(self, x);
        return;
    }
}

void transition_from_FControlLuminosity__root__OperatingVoltage(FControlLuminosity *self,
                                                                FControlLuminosity__root__state_struct *x)
{
    transition_from_FControlLuminosity__root__OperatingVoltage__root(self, x);
    if (self->Change363.IsTriggered)
    {

        make_state_FControlLuminosity__root__NoOperatingVoltage(self, x);
        return;
    }
}

void transition_from_FControlLuminosity__root(FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlLuminosity__root__NoOperatingVoltage:
        transition_from_FControlLuminosity__root__NoOperatingVoltage(self, x);
        break;
    case FControlLuminosity__root__OperatingVoltage:
        transition_from_FControlLuminosity__root__OperatingVoltage(self, x);
        break;
    }
}

static void evaluateChangeEvents(FControlLuminosity *self)
{
    self->Change109.IsTriggered =
        IsTriggered(MakeChange(self->D14inLuminosityNightFault.IsSignalled, self->D14inLuminosityNightFault.Value));
    self->Change110.IsTriggered =
        IsTriggered(MakeChange(self->D14inLuminosityNightFault.IsSignalled, self->D14inLuminosityNightFault.Value));
    self->Change111.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D14inLuminosityNightFault.IsSignalled, self->D14inLuminosityNightFault.Value),
        MakeChange(self->D11inRequiredLuminosity.IsSignalled,
                   self->D11inRequiredLuminosity.Value == FControlLuminosity_D11inRequiredLuminosityValue__Day)));
    self->Change91.IsTriggered =
        IsTriggered(MakeChange(self->D13inLuminosityDayFault.IsSignalled, self->D13inLuminosityDayFault.Value));
    self->Change92.IsTriggered =
        IsTriggered(MakeChange(self->D13inLuminosityDayFault.IsSignalled, self->D13inLuminosityDayFault.Value));
    self->Change93.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D13inLuminosityDayFault.IsSignalled, self->D13inLuminosityDayFault.Value),
        MakeChange(self->D11inRequiredLuminosity.IsSignalled,
                   self->D11inRequiredLuminosity.Value == FControlLuminosity_D11inRequiredLuminosityValue__Night)));
    self->Change540.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D13inLuminosityDayFault.IsSignalled, self->D13inLuminosityDayFault.Value)));
    self->Change545.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D14inLuminosityNightFault.IsSignalled, self->D14inLuminosityNightFault.Value)));
    self->Change342.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Booting),
                 MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Initialising)));
    self->Change333.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Booting));
    self->Change363.IsTriggered = IsTriggered(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__NoOperatingVoltage));
}

static void resetOutputs(FControlLuminosity *self)
{

    self->T5outSilNotFulfilled.Trigger = false;

    self->D9outSetLuminosity.IsSignalled = false;
}

static void resetTriggers(FControlLuminosity *self)
{

    self->D12inConLuminosity.IsSignalled = false;
    self->D13inLuminosityDayFault.IsSignalled = false;
    self->D14inLuminosityNightFault.IsSignalled = false;
    self->D16inLuminositySetUnchangeable.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
    self->D11inRequiredLuminosity.IsSignalled = false;
}

void transition_FControlLuminosity(FControlLuminosity *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FControlLuminosity__root(self, &self->state);
    resetTriggers(self);
}

void new_FControlLuminosity(FControlLuminosity *self)
{
    make_state_FControlLuminosity__root(self, &self->state);
}
