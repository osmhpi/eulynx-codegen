
#include "../../04_OutputC/SubsystemIo/FSciIoReport.h"

void count_transitions_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(
    int *ctr, FSciIoReport *self, FSciIoReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change325.IsTriggered)
    {
        if ((!(self->D7inDetectedInputChannelState1.Value ==
               map_MemLastReportedInputChannelState1_to_D7inDetectedInputChannelState1(
                   self->MemLastReportedInputChannelState1))) ||
            (!(self->D7inDetectedInputChannelStaten.Value ==
               map_MemLastReportedInputChannelStaten_to_D7inDetectedInputChannelStaten(
                   self->MemLastReportedInputChannelStaten))))
        {
            (*ctr)++;
        }
    }
    if (self->Change461.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change459.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change460.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change466.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change465.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change463.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change467.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change464.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change462.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates(
    int *ctr, FSciIoReport *self, FSciIoReport__root__state_struct *x)
{
    switch (x->ReportingLogicalChannelStates.ReportingLogicalInputChannelStates.state)
    {
    case FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports:
        count_transitions_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports(
    int *ctr, FSciIoReport *self, FSciIoReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change326.IsTriggered)
    {
        if ((!(self->D9inMonitoredOutputChannelDisturbanceState1.Value ==
               map_MemLastReportedOutputChannelState1_to_D9inMonitoredOutputChannelDisturbanceState1(
                   self->MemLastReportedOutputChannelState1))) ||
            (!(self->D9inMonitoredOutputChannelDisturbanceStaten.Value ==
               map_MemLastReportedOutputChannelStaten_to_D9inMonitoredOutputChannelDisturbanceStaten(
                   self->MemLastReportedOutputChannelStaten))))
        {
            (*ctr)++;
        }
    }
    if (self->Change505.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change503.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change499.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change504.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates(
    int *ctr, FSciIoReport *self, FSciIoReport__root__state_struct *x)
{
    switch (x->ReportingLogicalChannelStates.ReportingLogicalOutputChannelStates.state)
    {
    case FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports:
        count_transitions_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates__SendingOutputChannelReports(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciIoReport__root__ReportingLogicalChannelStates(int *ctr, FSciIoReport *self,
                                                                              FSciIoReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalOutputChannelStates(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change334.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciIoReport__root__InterfaceConnectionNotEstablished(int *ctr, FSciIoReport *self,
                                                                                  FSciIoReport__root__state_struct *x)
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

void count_transitions_from_FSciIoReport__root(int *ctr, FSciIoReport *self, FSciIoReport__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciIoReport__root__ReportingLogicalChannelStates:
        count_transitions_from_FSciIoReport__root__ReportingLogicalChannelStates(ctr, self, x);
        break;
    case FSciIoReport__root__InterfaceConnectionNotEstablished:
        count_transitions_from_FSciIoReport__root__InterfaceConnectionNotEstablished(ctr, self, x);
        break;
    }
}

int count_transitions_FSciIoReport(FSciIoReport *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciIoReport__root(&ctr, self, &self->state);
    return ctr;
}