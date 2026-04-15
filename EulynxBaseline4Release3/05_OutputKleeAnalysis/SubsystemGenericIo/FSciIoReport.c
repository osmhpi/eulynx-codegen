
#include "../../04_OutputC/SubsystemGenericIo/FSciIoReport.h"

void count_transitions_from_FSciIoReport__root__ReportingLogicalChannelStates__ReportingLogicalInputChannelStates__SendingInputChannelReports(
    int *ctr, FSciIoReport *self, FSciIoReport__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change303.IsTriggered)
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
    if (self->Change437.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change438.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change439.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change441.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change443.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change445.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change442.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change440.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change444.IsTriggered)
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

    if (self->Change304.IsTriggered)
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
    if (self->Change499.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change494.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change492.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciIoReport_D50inPdiConnectionStateValue__Established)
        {
            (*ctr)++;
        }
    }
    if (self->Change497.IsTriggered)
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
    if (self->Change313.IsTriggered)
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