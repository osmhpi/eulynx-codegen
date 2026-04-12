
#include "FMonitorReportStatus.h"

// Value Conversion Functions

// Operations

void make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__Waiting(
    FMonitorReportStatus *self,
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__state_struct
        *region)
{
    LOG("[FMonitorReportStatus] Entering state Waiting in region "
        "root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter");
    region->state =
        FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__Waiting;
};

void make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter(
    FMonitorReportStatus *self,
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__state_struct
        *x)
{
    memset(
        x, 0,
        sizeof(
            FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__state_struct));

    make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__Waiting(
        self, x);
    return;
}

void make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__Waiting(
    FMonitorReportStatus *self,
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__state_struct
        *region)
{
    LOG("[FMonitorReportStatus] Entering state Waiting in region "
        "root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits");
    region->state =
        FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__Waiting;
};

void make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits(
    FMonitorReportStatus *self,
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__state_struct
        *x)
{
    memset(
        x, 0,
        sizeof(
            FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__state_struct));

    make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__Waiting(
        self, x);
    return;
}

void make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__Waiting(
    FMonitorReportStatus *self,
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__state_struct *region)
{
    LOG("[FMonitorReportStatus] Entering state Waiting in region "
        "root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp");
    region->state = FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__Waiting;
};

void make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp(
    FMonitorReportStatus *self,
    FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__state_struct *x)
{
    memset(
        x, 0,
        sizeof(FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__state_struct));

    make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__Waiting(self, x);
    return;
}

void make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForReportStatus(
    FMonitorReportStatus *self, FMonitorReportStatus__root__MonitoringReportStatus__root__state_struct *region)
{
    LOG("[FMonitorReportStatus] Entering state WaitingForReportStatus in region root__MonitoringReportStatus__root");
    region->state = FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForReportStatus;
};

void make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports(
    FMonitorReportStatus *self, FMonitorReportStatus__root__MonitoringReportStatus__root__state_struct *region)
{
    LOG("[FMonitorReportStatus] Entering state WaitingForStatusReports in region root__MonitoringReportStatus__root");
    region->state = FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports;
    make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter(
        self, &region->WaitingForStatusReports.TvpsStatusAxleCounter);
    make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits(
        self, &region->WaitingForStatusReports.TvpsStatusTrackCircuits);
    make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp(
        self, &region->WaitingForStatusReports.Tdp);
};

void make_state_FMonitorReportStatus__root__MonitoringReportStatus__root(
    FMonitorReportStatus *self, FMonitorReportStatus__root__MonitoringReportStatus__root__state_struct *x)
{
    memset(x, 0, sizeof(FMonitorReportStatus__root__MonitoringReportStatus__root__state_struct));

    make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForReportStatus(self, x);
    return;
}

void make_state_FMonitorReportStatus__root__MonitoringReportStatus(FMonitorReportStatus *self,
                                                                   FMonitorReportStatus__root__state_struct *region)
{
    LOG("[FMonitorReportStatus] Entering state MonitoringReportStatus in region root");
    region->state = FMonitorReportStatus__root__MonitoringReportStatus;
    make_state_FMonitorReportStatus__root__MonitoringReportStatus__root(self, &region->MonitoringReportStatus.root);
};

void make_state_FMonitorReportStatus__root(FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    memset(x, 0, sizeof(FMonitorReportStatus__root__state_struct));

    make_state_FMonitorReportStatus__root__MonitoringReportStatus(self, x);
    return;
}

void transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__Waiting(
    FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{

    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {

        make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__Join0(self,
                                                                                   &x->MonitoringReportStatus.root);
        return;
    }
}

void transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter(
    FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    switch (x->MonitoringReportStatus.root.WaitingForStatusReports.TvpsStatusAxleCounter.state)
    {
    case FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__Waiting:
        transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter__Waiting(
            self, x);
        break;
    }
}

void transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__Waiting(
    FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{

    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {

        make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__Join0(self,
                                                                                   &x->MonitoringReportStatus.root);
        return;
    }
}

void transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits(
    FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    switch (x->MonitoringReportStatus.root.WaitingForStatusReports.TvpsStatusTrackCircuits.state)
    {
    case FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__Waiting:
        transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits__Waiting(
            self, x);
        break;
    }
}

void transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__Waiting(
    FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{

    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {

        make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__Join0(self,
                                                                                   &x->MonitoringReportStatus.root);
        return;
    }
}

void transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp(
    FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    switch (x->MonitoringReportStatus.root.WaitingForStatusReports.Tdp.state)
    {
    case FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__Waiting:
        transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp__Waiting(
            self, x);
        break;
    }
}

void transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForReportStatus(
    FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{

    if (self->InStartStatusReport__1e4e.HasMessage)
    {

        make_state_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports(
            self, &x->MonitoringReportStatus.root);
        return;
    }
}

void transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports(
    FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusAxleCounter(
        self, x);
    transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__TvpsStatusTrackCircuits(
        self, x);
    transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports__Tdp(self, x);
}

void transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root(
    FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    switch (x->MonitoringReportStatus.root.state)
    {
    case FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForReportStatus:
        transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForReportStatus(self, x);
        break;
    case FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports:
        transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root__WaitingForStatusReports(self, x);
        break;
    }
}

void transition_from_FMonitorReportStatus__root__MonitoringReportStatus(FMonitorReportStatus *self,
                                                                        FMonitorReportStatus__root__state_struct *x)
{
    transition_from_FMonitorReportStatus__root__MonitoringReportStatus__root(self, x);
}

void transition_from_FMonitorReportStatus__root(FMonitorReportStatus *self, FMonitorReportStatus__root__state_struct *x)
{
    switch (x->state)
    {
    case FMonitorReportStatus__root__MonitoringReportStatus:
        transition_from_FMonitorReportStatus__root__MonitoringReportStatus(self, x);
        break;
    }
}

static void evaluateChangeEvents(FMonitorReportStatus *self)
{
}

static void resetOutputs(FMonitorReportStatus *self)
{
    self->OutStatusReportCompleted__b457.HasMessage = false;
}

static void resetTriggers(FMonitorReportStatus *self)
{
    self->InMsgTvpsOccupancyStatus__b4e1.HasMessage = false;
    self->InMsgTdpStatus__b6d9.HasMessage = false;
    self->InStartStatusReport__1e4e.HasMessage = false;
}

void transition_FMonitorReportStatus(FMonitorReportStatus *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FMonitorReportStatus__root(self, &self->state);
    resetTriggers(self);
}

void new_FMonitorReportStatus(FMonitorReportStatus *self)
{
    make_state_FMonitorReportStatus__root(self, &self->state);
}
