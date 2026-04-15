
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FMonitorReportStatus.h"

void count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__Waiting(
    int *ctr, FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter(
    int *ctr, FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    switch (x->MonitoringReportStatus.root.WaitingForStatusReports.TvpsStatusAxleCounter.state)
    {
    case FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__Waiting:
        count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__Waiting(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__Waiting(
    int *ctr, FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits(
    int *ctr, FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    switch (x->MonitoringReportStatus.root.WaitingForStatusReports.TvpsStatusTrackCircuits.state)
    {
    case FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__Waiting:
        count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__Waiting(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__Waiting(
    int *ctr, FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp(
    int *ctr, FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    switch (x->MonitoringReportStatus.root.WaitingForStatusReports.Tdp.state)
    {
    case FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__Waiting:
        count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__Waiting(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForReportStatus(
    int *ctr, FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
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

void count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports(
    int *ctr, FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root(
    int *ctr, FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    switch (x->MonitoringReportStatus.root.state)
    {
    case FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForReportStatus:
        count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForReportStatus(
            ctr, self, x);
        break;
    case FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports:
        count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus(
    int *ctr, FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FMonitorReportStatus__root(int *ctr, FMonitorReportStatus *self,
                                                       FMonitorReportStatus__root__state_struct *x)
{
    switch (x->state)
    {
    case FMonitorReportStatus__root__MonitoringReportStatus:
        count_transitions_from_FMonitorReportStatus__root__MonitoringReportStatus(ctr, self, x);
        break;
    }
}

int count_transitions_FMonitorReportStatus(FMonitorReportStatus *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FMonitorReportStatus__root(&ctr, self, &self->state);
    return ctr;
}