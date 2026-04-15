
#include "../../04_OutputC/SubsystemLightSignal/FControlSignalAspect.h"

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__ControllingSignalAspect__root__SignalAspect2(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change184.IsTriggered)
    {
        if (self->D6inFaultLampsMostRestrict.Value)
        {
            (*ctr)++;
        }
    }
    if (self->Change186.IsTriggered)
    {
        if (!(self->D6inFaultLampsMostRestrict.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change190.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D6inFaultLampsMostRestrict.Value))) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change191.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (self->D6inFaultLampsMostRestrict.Value)) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change194.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change259.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change565.IsTriggered)
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

    if (self->Change189.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change196.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change188.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D5inFaultLampsAspect2.Value))) &&
            (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change428.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change260.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change566.IsTriggered)
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

    if (self->Change193.IsTriggered)
    {
        if (!(self->D4inFaultLampsAspect1.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change195.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change192.IsTriggered)
    {
        if (((self->D4inFaultLampsAspect1.Value) && (!(self->D5inFaultLampsAspect2.Value))) &&
            (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change577.IsTriggered)
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

    if (self->Change187.IsTriggered)
    {
        if (self->D6inFaultLampsMostRestrict.Value)
        {
            (*ctr)++;
        }
    }
    if (self->Change185.IsTriggered)
    {
        if (!(self->D6inFaultLampsMostRestrict.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change198.IsTriggered)
    {
        if ((self->D5inFaultLampsAspect2.Value) && (self->D6inFaultLampsMostRestrict.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change199.IsTriggered)
    {
        if ((self->D5inFaultLampsAspect2.Value) && (!(self->D6inFaultLampsMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change197.IsTriggered)
    {
        if (!(self->D5inFaultLampsAspect2.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change287.IsTriggered)
    {
        if ((!(self->D6inFaultLampsMostRestrict.Value)) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change285.IsTriggered)
    {
        if ((self->D6inFaultLampsMostRestrict.Value) &&
            ((self->D5inFaultLampsAspect2.Value) || (self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change286.IsTriggered)
    {
        if ((!(self->D5inFaultLampsAspect2.Value)) && (!(self->D10inConDowngradeMostRestrict.Value)))
        {
            (*ctr)++;
        }
    }
    if (self->Change261.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change567.IsTriggered)
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
    if (self->Change514.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspectLuminosityFailure(
    int *ctr, FControlSignalAspect *self, FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change513.IsTriggered)
    {
        (*ctr)++;
    }
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
    case FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspectLuminosityFailure:
        count_transitions_from_FControlSignalAspect__root__OperatingVoltage__root__SetNoSignalAspectLuminosityFailure(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FControlSignalAspect__root__NationalAspect(int *ctr, FControlSignalAspect *self,
                                                                       FControlSignalAspect__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change335.IsTriggered)
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
    if (self->Change337.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change368.IsTriggered)
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