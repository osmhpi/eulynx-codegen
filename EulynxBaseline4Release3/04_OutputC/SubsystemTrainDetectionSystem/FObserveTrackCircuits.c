
#include "FObserveTrackCircuits.h"

// Value Conversion Functions

// Operations
static void Cop1Init(FObserveTrackCircuits *self)
{
    self->D46outReportAbilityToBeForcedToClear.Value = false;
    self->D45outReportTvpsOccupancyStatus.Value = FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__Undefined;
    self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
    self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__Undefined;
    self->D47outReportPomStatus.IsSignalled = true;
}

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomOk(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PomOk in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomOk;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomNok(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PomNok in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomNok;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__WithoutPom(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state WithoutPom in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__WithoutPom;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__state_struct
        *x)
{
    memset(
        x, 0,
        sizeof(
            FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__state_struct));

    if ((self->D49inPowerMonitoringFailure.Value) && (self->D50inConPomUsed.Value))
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomNok(
            self, x);
        return;
    }
    if ((!(self->D49inPowerMonitoringFailure.Value)) && (self->D50inConPomUsed.Value))
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomOk(
            self, x);
        return;
    }
    else
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__NotApplicable;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__WithoutPom(
            self, x);
        return;
    }
}

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomNok(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PomNok in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomNok;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomOk(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PomOk in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomOk;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__WithoutPom(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state WithoutPom in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__WithoutPom;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__state_struct
        *x)
{
    memset(
        x, 0,
        sizeof(
            FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__state_struct));

    if ((self->D49inPowerMonitoringFailure.Value) && (self->D50inConPomUsed.Value))
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateVacant;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomNok(
            self, x);
        return;
    }
    if ((!(self->D49inPowerMonitoringFailure.Value)) && (self->D50inConPomUsed.Value))
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateVacant;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomOk(
            self, x);
        return;
    }
    else
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateVacant;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__NotApplicable;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__WithoutPom(
            self, x);
        return;
    }
}

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state_struct *region)
{
    LOG("[FObserveTrackCircuits] Entering state Occupied in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied;
    make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root(
        self, &region->Occupied.root);
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state_struct *region)
{
    LOG("[FObserveTrackCircuits] Entering state Vacant in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root");
    region->state = FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant;
    make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root(
        self, &region->Vacant.root);
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state_struct *x)
{
    memset(
        x, 0,
        sizeof(
            FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state_struct));

    if (self->D48inOccupancyDetected.Value)
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied(
            self, x);
        return;
    }
    else
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant(
            self, x);
        return;
    }
}

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomNok(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PomNok in region "
        "root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomNok;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomOk(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PomOk in region "
        "root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomOk;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__WithoutPom(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state WithoutPom in region "
        "root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__WithoutPom;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state_struct
        *x)
{
    memset(
        x, 0,
        sizeof(
            FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state_struct));

    if ((self->D49inPowerMonitoringFailure.Value) && (self->D50inConPomUsed.Value))
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomNok(
            self, x);
        return;
    }
    if ((!(self->D49inPowerMonitoringFailure.Value)) && (self->D50inConPomUsed.Value))
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomOk(
            self, x);
        return;
    }
    else
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__NotApplicable;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__WithoutPom(
            self, x);
        return;
    }
}

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__state_struct *region)
{
    LOG("[FObserveTrackCircuits] Entering state Observing in region "
        "root__ReportOccupancyStatus__root__Operating__root");
    region->state = FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing;
    make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root(
        self, &region->Observing.root);
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__state_struct *region)
{
    LOG("[FObserveTrackCircuits] Entering state TechnicallyDisturbed in region "
        "root__ReportOccupancyStatus__root__Operating__root");
    region->state = FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed;
    make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root(
        self, &region->TechnicallyDisturbed.root);
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__state_struct));

    if (self->D32inCriticalFailureTvps.Value)
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed(self,
                                                                                                                   x);
        return;
    }
    else
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing(self, x);
        return;
    }
}

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__ReportOccupancyStatus__root__state_struct *region)
{
    LOG("[FObserveTrackCircuits] Entering state WaitingForFinishedBooting in region root__ReportOccupancyStatus__root");
    region->state = FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__ReportOccupancyStatus__root__state_struct *region)
{
    LOG("[FObserveTrackCircuits] Entering state Operating in region root__ReportOccupancyStatus__root");
    region->state = FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating;
    make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root(self, &region->Operating.root);
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__ReportOccupancyStatus__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveTrackCircuits__root__ReportOccupancyStatus__root__state_struct));

    make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting(self, x);
    return;
}

void make_state_FObserveTrackCircuits__root__FallbackMode(FObserveTrackCircuits *self,
                                                          FObserveTrackCircuits__root__state_struct *region)
{
    LOG("[FObserveTrackCircuits] Entering state FallbackMode in region root");
    region->state = FObserveTrackCircuits__root__FallbackMode;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus(FObserveTrackCircuits *self,
                                                                   FObserveTrackCircuits__root__state_struct *region)
{
    LOG("[FObserveTrackCircuits] Entering state ReportOccupancyStatus in region root");
    region->state = FObserveTrackCircuits__root__ReportOccupancyStatus;
    make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root(self, &region->ReportOccupancyStatus.root);
};

void make_state_FObserveTrackCircuits__root(FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveTrackCircuits__root__state_struct));
    Cop1Init(self);
    make_state_FObserveTrackCircuits__root__ReportOccupancyStatus(self, x);
    return;
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomOk(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change278.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomNok(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root.Occupied.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomNok(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change572.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomOk(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root.Occupied.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__WithoutPom(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.Occupied.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomOk:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomOk(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomNok:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomNok(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__WithoutPom:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__WithoutPom(
            self, x);
        break;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomNok(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change570.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateVacant;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomOk(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root.Vacant.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomOk(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change279.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateVacant;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomNok(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root.Vacant.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__WithoutPom(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.Vacant.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomNok:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomNok(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomOk:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomOk(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__WithoutPom:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__WithoutPom(
            self, x);
        break;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root(
        self, x);
    if (self->Change276.IsTriggered)
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root(
        self, x);
    if (self->Change277.IsTriggered)
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant(
            self, x);
        break;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomNok(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change571.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomOk(
            self, &x->ReportOccupancyStatus.root.Operating.root.TechnicallyDisturbed.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomOk(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change280.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomNok(
            self, &x->ReportOccupancyStatus.root.Operating.root.TechnicallyDisturbed.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__WithoutPom(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.TechnicallyDisturbed.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomNok:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomNok(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomOk:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomOk(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__WithoutPom:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__WithoutPom(
            self, x);
        break;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root(self, x);
    if (self->Change232.IsTriggered)
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed(
            self, &x->ReportOccupancyStatus.root.Operating.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root(
        self, x);
    if (self->Change236.IsTriggered)
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing(
            self, &x->ReportOccupancyStatus.root.Operating.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing(self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed(
            self, x);
        break;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change400.IsTriggered)
    {
        self->D46outReportAbilityToBeForcedToClear.Value = false;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating(self,
                                                                                       &x->ReportOccupancyStatus.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root(self, x);
    if (self->Change387.IsTriggered)
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting(
            self, &x->ReportOccupancyStatus.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting(self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating(self, x);
        break;
    }
}

void transition_from_FObserveTrackCircuits__root__FallbackMode(FObserveTrackCircuits *self,
                                                               FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change383.IsTriggered)
    {
        Cop1Init(self);
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus(self, x);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus(FObserveTrackCircuits *self,
                                                                        FObserveTrackCircuits__root__state_struct *x)
{
    transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root(self, x);
    if (self->Change395.IsTriggered)
    {

        make_state_FObserveTrackCircuits__root__FallbackMode(self, x);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root(FObserveTrackCircuits *self,
                                                 FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveTrackCircuits__root__FallbackMode:
        transition_from_FObserveTrackCircuits__root__FallbackMode(self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus(self, x);
        break;
    }
}

static void evaluateChangeEvents(FObserveTrackCircuits *self)
{
    self->Change278.IsTriggered =
        IsTriggered(MakeChange(self->D49inPowerMonitoringFailure.IsSignalled, self->D49inPowerMonitoringFailure.Value));
    self->Change572.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D49inPowerMonitoringFailure.IsSignalled, self->D49inPowerMonitoringFailure.Value)));
    self->Change570.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D49inPowerMonitoringFailure.IsSignalled, self->D49inPowerMonitoringFailure.Value)));
    self->Change279.IsTriggered =
        IsTriggered(MakeChange(self->D49inPowerMonitoringFailure.IsSignalled, self->D49inPowerMonitoringFailure.Value));
    self->Change276.IsTriggered =
        IsTriggered(MakeChange(self->D48inOccupancyDetected.IsSignalled, self->D48inOccupancyDetected.Value == false));
    self->Change277.IsTriggered =
        IsTriggered(MakeChange(self->D48inOccupancyDetected.IsSignalled, self->D48inOccupancyDetected.Value == true));
    self->Change571.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D49inPowerMonitoringFailure.IsSignalled, self->D49inPowerMonitoringFailure.Value)));
    self->Change280.IsTriggered =
        IsTriggered(MakeChange(self->D49inPowerMonitoringFailure.IsSignalled, self->D49inPowerMonitoringFailure.Value));
    self->Change232.IsTriggered =
        IsTriggered(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value));
    self->Change236.IsTriggered = IsTriggered(
        MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value == false));
    self->Change400.IsTriggered = IsTriggered(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveTrackCircuits_D51outEstEfesStateValue__Initialising));
    self->Change387.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D51outEstEfesState.IsSignalled,
                            self->D51outEstEfesState.Value == FObserveTrackCircuits_D51outEstEfesStateValue__Booting),
                 MakeChange(self->D51outEstEfesState.IsSignalled,
                            self->D51outEstEfesState.Value ==
                                FObserveTrackCircuits_D51outEstEfesStateValue__NoOperatingVoltage)));
    self->Change383.IsTriggered = IsTriggered(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveTrackCircuits_D51outEstEfesStateValue__Booting));
    self->Change395.IsTriggered = IsTriggered(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveTrackCircuits_D51outEstEfesStateValue__FallbackMode));
}

static void resetOutputs(FObserveTrackCircuits *self)
{

    self->D45outReportTvpsOccupancyStatus.IsSignalled = false;
    self->D46outReportAbilityToBeForcedToClear.IsSignalled = false;
    self->D51outEstEfesState.IsSignalled = false;
    self->D47outReportPomStatus.IsSignalled = false;
}

static void resetTriggers(FObserveTrackCircuits *self)
{

    self->D32inCriticalFailureTvps.IsSignalled = false;
    self->D48inOccupancyDetected.IsSignalled = false;
    self->D49inPowerMonitoringFailure.IsSignalled = false;
    self->D50inConPomUsed.IsSignalled = false;
}

void transition_FObserveTrackCircuits(FObserveTrackCircuits *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FObserveTrackCircuits__root(self, &self->state);
    resetTriggers(self);
}

void new_FObserveTrackCircuits(FObserveTrackCircuits *self)
{
    make_state_FObserveTrackCircuits__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemTrainDetectionSystem/FObserveTrackCircuits.c"
#endif
