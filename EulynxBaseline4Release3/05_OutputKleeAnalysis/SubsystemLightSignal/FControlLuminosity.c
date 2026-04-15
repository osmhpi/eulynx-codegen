
#include "../../04_OutputC/SubsystemLightSignal/FControlLuminosity.h"

void count_transitions_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night(
    int *ctr, FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change109.IsTriggered)
    {
        if ((!(self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Operational)) &&
            ((self->D16inLuminositySetUnchangeable.Value) || (self->D13inLuminosityDayFault.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change110.IsTriggered)
    {
        if ((self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Operational) &&
            ((self->D16inLuminositySetUnchangeable.Value) || (self->D13inLuminosityDayFault.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change111.IsTriggered)
    {
        if ((!(self->D13inLuminosityDayFault.Value)) && (!(self->D16inLuminositySetUnchangeable.Value)))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day(
    int *ctr, FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change91.IsTriggered)
    {
        if ((!(self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Operational)) &&
            ((self->D16inLuminositySetUnchangeable.Value) || (self->D14inLuminosityNightFault.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change92.IsTriggered)
    {
        if ((self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Operational) &&
            ((self->D16inLuminositySetUnchangeable.Value) || (self->D14inLuminosityNightFault.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change93.IsTriggered)
    {
        if ((!(self->D14inLuminosityNightFault.Value)) && (!(self->D16inLuminositySetUnchangeable.Value)))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined(
    int *ctr, FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change540.IsTriggered)
    {
        if ((self->D51inEstEfesState.Value == FControlLuminosity_D51inEstEfesStateValue__Operational) &&
            ((!(self->D16inLuminositySetUnchangeable.Value)) ||
             ((self->D16inLuminositySetUnchangeable.Value) &&
              ((self->D11inRequiredLuminosity.Value == FControlLuminosity_D11inRequiredLuminosityValue__Day) ||
               (self->D12inConLuminosity.Value)))))
        {
            (*ctr)++;
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
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root(
    int *ctr, FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{
    switch (x->OperatingVoltage.root.ControllingLuminosity.root.state)
    {
    case FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night:
        count_transitions_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Night(
            ctr, self, x);
        break;
    case FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day:
        count_transitions_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Day(
            ctr, self, x);
        break;
    case FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined:
        count_transitions_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root__Undefined(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity(
    int *ctr, FControlLuminosity *self, FControlLuminosity__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change342.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLuminosity__root__OperatingVoltage__root(int *ctr, FControlLuminosity *self,
                                                                             FControlLuminosity__root__state_struct *x)
{
    switch (x->OperatingVoltage.root.state)
    {
    case FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity:
        count_transitions_from_FControlLuminosity__root__OperatingVoltage__root__ControllingLuminosity(ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlLuminosity__root__NoOperatingVoltage(int *ctr, FControlLuminosity *self,
                                                                         FControlLuminosity__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change333.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLuminosity__root__OperatingVoltage(int *ctr, FControlLuminosity *self,
                                                                       FControlLuminosity__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FControlLuminosity__root__OperatingVoltage__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change363.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlLuminosity__root(int *ctr, FControlLuminosity *self,
                                                     FControlLuminosity__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlLuminosity__root__NoOperatingVoltage:
        count_transitions_from_FControlLuminosity__root__NoOperatingVoltage(ctr, self, x);
        break;
    case FControlLuminosity__root__OperatingVoltage:
        count_transitions_from_FControlLuminosity__root__OperatingVoltage(ctr, self, x);
        break;
    }
}

int count_transitions_FControlLuminosity(FControlLuminosity *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FControlLuminosity__root(&ctr, self, &self->state);
    return ctr;
}