
#include "../../04_OutputC/SubsystemLightSignal/FControlSignalAspect.h"

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change193.IsTriggered)
    {
        if (self->D6inFaultLampsMostRestrict.Value)
        {
            (*ctr)++;
        }
    }
    if (self->Change195.IsTriggered)
    {
        if (!(self->D6inFaultLampsMostRestrict.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change201.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D6inFaultLampsMostRestrict.Value))) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change200.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (self->D6inFaultLampsMostRestrict.Value)) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change202.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change274.IsTriggered)
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

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__MostRestrictiveAspect(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change197.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change204.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change199.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D5inFaultLampsAspect2.Value))) &&
            (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change449.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change273.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change572.IsTriggered)
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

    if (self->Change198.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change206.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change203.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D5inFaultLampsAspect2.Value))) &&
            (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change586.IsTriggered)
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

    if (self->Change196.IsTriggered)
    {
        if (self->D6inFaultLampsMostRestrict.Value)
        {
            (*ctr)++;
        }
    }
    if (self->Change194.IsTriggered)
    {
        if (!(self->D6inFaultLampsMostRestrict.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change208.IsTriggered)
    {
        if ((self->D5inFaultLampsAspect2.Value) && (self->D6inFaultLampsMostRestrict.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change205.IsTriggered)
    {
        if ((self->D5inFaultLampsAspect2.Value) && (!(self->D6inFaultLampsMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change207.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change306.IsTriggered)
    {
        if ((!(self->D6inFaultLampsMostRestrict.Value)) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change304.IsTriggered)
    {
        if ((self->D6inFaultLampsMostRestrict.Value) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change305.IsTriggered)
    {
        if ((!(self->D5inFaultLampsAspect2.Value)) && (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change272.IsTriggered)
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
    if (self->Change524.IsTriggered)
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

    if (self->Change344.IsTriggered)
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
    if (self->Change352.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change386.IsTriggered)
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