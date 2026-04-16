
#include "../../04_OutputC/SubsystemLightSignal/FControlSignalAspect.h"

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change210.IsTriggered)
    {
        if (self->D6inFaultLampsMostRestrict.Value)
        {
            (*ctr)++;
        }
    }
    if (self->Change211.IsTriggered)
    {
        if (!(self->D6inFaultLampsMostRestrict.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change214.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D6inFaultLampsMostRestrict.Value))) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change217.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (self->D6inFaultLampsMostRestrict.Value)) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change219.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change283.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change573.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change215.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change225.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change216.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D5inFaultLampsAspect2.Value))) &&
            (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change450.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change282.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change575.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change220.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change224.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change218.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D5inFaultLampsAspect2.Value))) &&
            (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change588.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change212.IsTriggered)
    {
        if (self->D6inFaultLampsMostRestrict.Value)
        {
            (*ctr)++;
        }
    }
    if (self->Change213.IsTriggered)
    {
        if (!(self->D6inFaultLampsMostRestrict.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change223.IsTriggered)
    {
        if ((self->D5inFaultLampsAspect2.Value) && (self->D6inFaultLampsMostRestrict.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change221.IsTriggered)
    {
        if ((self->D5inFaultLampsAspect2.Value) && (!(self->D6inFaultLampsMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change222.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change308.IsTriggered)
    {
        if ((!(self->D6inFaultLampsMostRestrict.Value)) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change310.IsTriggered)
    {
        if ((self->D6inFaultLampsMostRestrict.Value) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change309.IsTriggered)
    {
        if ((!(self->D5inFaultLampsAspect2.Value)) && (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change284.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change574.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    switch (x->OperatingVoltage.root.ControllingSignalAspect.root.state)
    {
    case FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2:
        count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
            ctr, self, x);
        break;
    case FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect:
        count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
            ctr, self, x);
        break;
    case FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure:
        count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__NoSignalAspectLampFailure(
            ctr, self, x);
        break;
    case FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1:
        count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect1(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root(&tmp, self,
                                                                                                             x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change521.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspect(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    switch (x->OperatingVoltage.root.state)
    {
    case FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect:
        count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect(ctr, self,
                                                                                                           x);
        break;
    case FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspect:
        count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspect(ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlSignalAspect__root__NationalAspect(int *ctr, FControlSignalAspect *self,
                                                                       FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change350.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage(int *ctr, FControlSignalAspect *self,
                                                                         FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change359.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change388.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlSignalAspect__root(int *ctr, FControlSignalAspect *self,
                                                       FControlSignalAspect__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlSignalAspect__root__NationalAspect:
        count_transitions_from_FControlSignalAspect__root__NationalAspect(ctr, self, x);
        break;
    case FControlSignalAspect__root__OperatingVoltage:
        count_transitions_from_FControlSignalAspect__root__OperatingVoltage(ctr, self, x);
        break;
    }
}

int count_transitions_FControlSignalAspect(FControlSignalAspect *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FControlSignalAspect__root(&ctr, self, &self->state);
    return ctr;
}