
#include "../../04_OutputC/SubsystemLightSignal/FSciLsReport.h"

void count_transitions_from_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
    int *ctr, FSciLsReport *self, FSciLsReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change132.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change133.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change134.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change135.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change169.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__SignalAspect1)
        {
            (*ctr)++;
        }
    }
    if (self->Change168.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__SignalAspect2)
        {
            (*ctr)++;
        }
    }
    if (self->Change170.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__MostRestrictAspect)
        {
            (*ctr)++;
        }
    }
    if (self->Change301.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__NoSignalAspect)
        {
            (*ctr)++;
        }
    }
    if (self->Change300.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__MostRestrictAspect)
        {
            (*ctr)++;
        }
    }
    if (self->Change554.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__SignalAspect1)
        {
            (*ctr)++;
        }
    }
    if (self->Change556.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__SignalAspect2)
        {
            (*ctr)++;
        }
    }
    if (self->Change555.IsTriggered)
    {
        if (self->D19inObservedSignalAspect.Value == FSciLsReport_D19inObservedSignalAspectValue__MostRestrictAspect)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect(
    int *ctr, FSciLsReport *self, FSciLsReport__root__state_struct *x)
{
    switch (x->SendingLightSignalReports.ReportingSignalAspect.state)
    {
    case FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports:
        count_transitions_from_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect__SendingSignalAspectReports(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports(
    int *ctr, FSciLsReport *self, FSciLsReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change171.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change172.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciLsReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change302.IsTriggered)
    {
        if (self->D21inObservedLuminosity.Value == FSciLsReport_D21inObservedLuminosityValue__Night)
        {
            (*ctr)++;
        }
    }
    if (self->Change298.IsTriggered)
    {
        if (self->D21inObservedLuminosity.Value == FSciLsReport_D21inObservedLuminosityValue__Day)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity(
    int *ctr, FSciLsReport *self, FSciLsReport__root__state_struct *x)
{
    switch (x->SendingLightSignalReports.ReportingLuminosity.state)
    {
    case FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports:
        count_transitions_from_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity__SendingLuminosityReports(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciLsReport__root__SendingLightSignalReports(int *ctr, FSciLsReport *self,
                                                                          FSciLsReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciLsReport__root__SendingLightSignalReports__ReportingSignalAspect(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FSciLsReport__root__SendingLightSignalReports__ReportingLuminosity(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change312.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLsReport__root__InterfaceConnectionNotEstablished(int *ctr, FSciLsReport *self,
                                                                                  FSciLsReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InStartStatusReport__1e4e.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLsReport__root(int *ctr, FSciLsReport *self, FSciLsReport__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciLsReport__root__SendingLightSignalReports:
        count_transitions_from_FSciLsReport__root__SendingLightSignalReports(ctr, self, x);
        break;
    case FSciLsReport__root__InterfaceConnectionNotEstablished:
        count_transitions_from_FSciLsReport__root__InterfaceConnectionNotEstablished(ctr, self, x);
        break;
    }
}

int count_transitions_FSciLsReport(FSciLsReport *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciLsReport__root(&ctr, self, &self->state);
    return ctr;
}