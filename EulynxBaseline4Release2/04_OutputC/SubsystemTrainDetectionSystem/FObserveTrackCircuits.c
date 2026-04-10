
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

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomNok(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PomNok in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__"
        "PowerSupplyIsOk__root__Vacant__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomNok;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomOk(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PomOk in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__"
        "PowerSupplyIsOk__root__Vacant__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomOk;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__state_struct
        *x)
{
    memset(
        x, 0,
        sizeof(
            FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__state_struct));

    if (!(self->D49inFailureOfThePom.Value))
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateVacant;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomOk(
            self, x);
        return;
    }
    else
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateVacant;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomNok(
            self, x);
        return;
    }
}

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomOk(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PomOk in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__"
        "PowerSupplyIsOk__root__Occupied__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomOk;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomNok(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PomNok in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__"
        "PowerSupplyIsOk__root__Occupied__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomNok;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__state_struct
        *x)
{
    memset(
        x, 0,
        sizeof(
            FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__state_struct));

    if (!(self->D49inFailureOfThePom.Value))
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomOk(
            self, x);
        return;
    }
    else
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomNok(
            self, x);
        return;
    }
}

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state Vacant in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__"
        "PowerSupplyIsOk__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant;
    make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root(
        self, &region->Vacant.root);
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state Occupied in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root__"
        "PowerSupplyIsOk__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied;
    make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root(
        self, &region->Occupied.root);
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__state_struct
        *x)
{
    memset(
        x, 0,
        sizeof(
            FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__state_struct));

    if (self->D48inOccupancyDetected.Value)
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied(
            self, x);
        return;
    }
    else
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant(
            self, x);
        return;
    }
}

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state_struct *region)
{
    LOG("[FObserveTrackCircuits] Entering state PowerSupplyIsOk in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk;
    make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root(
        self, &region->PowerSupplyIsOk.root);
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsNok(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state_struct *region)
{
    LOG("[FObserveTrackCircuits] Entering state PowerSupplyIsNok in region "
        "root__ReportOccupancyStatus__root__Operating__root__Observing__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsNok;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state_struct *x)
{
    memset(
        x, 0,
        sizeof(
            FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state_struct));

    if (self->D50inFailureOfThePowerSupply.Value)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsNok(
            self, x);
        return;
    }
    else
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk(
            self, x);
        return;
    }
}

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PowerSupplyIsNok in region "
        "root__ReportOccupancyStatus__root__Operating__root__"
        "TechnicallyDisturbed__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk(
    FObserveTrackCircuits *self,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state_struct
        *region)
{
    LOG("[FObserveTrackCircuits] Entering state PowerSupplyIsOk in region "
        "root__ReportOccupancyStatus__root__Operating__root__"
        "TechnicallyDisturbed__root");
    region->state =
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk;
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

    if ((!(self->D50inFailureOfThePowerSupply.Value)) && (!(self->D49inFailureOfThePom.Value)))
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk(
            self, x);
        return;
    }
    else
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok(
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
    LOG("[FObserveTrackCircuits] Entering state WaitingForFinishedBooting in "
        "region root__ReportOccupancyStatus__root");
    region->state = FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting;
};

void make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__ReportOccupancyStatus__root__state_struct *region)
{
    LOG("[FObserveTrackCircuits] Entering state Operating in region "
        "root__ReportOccupancyStatus__root");
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
    LOG("[FObserveTrackCircuits] Entering state ReportOccupancyStatus in region "
        "root");
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

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomNok(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change579.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateVacant;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomOk(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root.Vacant.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomOk(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change303.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateVacant;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomNok(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root.Vacant.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root.Vacant.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomNok:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomNok(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomOk:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomOk(
            self, x);
        break;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomOk(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change302.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomNok(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root.Occupied.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomNok(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change578.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomOk(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root.Occupied.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root.Occupied.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomOk:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomOk(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomNok:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomNok(
            self, x);
        break;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root(
        self, x);
    if (self->Change300.IsTriggered)
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root(
        self, x);
    if (self->Change299.IsTriggered)
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied(
            self, x);
        break;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root(
        self, x);
    if (self->Change319.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsNok(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsNok(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change582.IsTriggered)
    {

        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk(
            self, &x->ReportOccupancyStatus.root.Operating.root.Observing.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsNok:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsNok(
            self, x);
        break;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change580.IsTriggered)
    {
        if (!(self->D50inFailureOfThePowerSupply.Value))
        {
            self->D45outReportTvpsOccupancyStatus.Value =
                FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
            self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
            self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
            self->D47outReportPomStatus.IsSignalled = true;
            make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk(
                self, &x->ReportOccupancyStatus.root.Operating.root.TechnicallyDisturbed.root);
            return;
        }
    }
    if (self->Change583.IsTriggered)
    {
        if (!(self->D49inFailureOfThePom.Value))
        {
            self->D45outReportTvpsOccupancyStatus.Value =
                FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
            self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
            self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk;
            self->D47outReportPomStatus.IsSignalled = true;
            make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk(
                self, &x->ReportOccupancyStatus.root.Operating.root.TechnicallyDisturbed.root);
            return;
        }
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{

    if (self->Change301.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok(
            self, &x->ReportOccupancyStatus.root.Operating.root.TechnicallyDisturbed.root);
        return;
    }
    if (self->Change318.IsTriggered)
    {
        self->D45outReportTvpsOccupancyStatus.Value =
            FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
        self->D45outReportTvpsOccupancyStatus.IsSignalled = true;
        self->D47outReportPomStatus.Value = FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok;
        self->D47outReportPomStatus.IsSignalled = true;
        make_state_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok(
            self, &x->ReportOccupancyStatus.root.Operating.root.TechnicallyDisturbed.root);
        return;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.TechnicallyDisturbed.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok(
            self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk:
        transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk(
            self, x);
        break;
    }
}

void transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing(
    FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    transition_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root(self, x);
    if (self->Change254.IsTriggered)
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
    if (self->Change259.IsTriggered)
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

    if (self->Change423.IsTriggered)
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
    if (self->Change409.IsTriggered)
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

    if (self->Change404.IsTriggered)
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
    if (self->Change419.IsTriggered)
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
    self->Change579.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D49inFailureOfThePom.IsSignalled, self->D49inFailureOfThePom.Value)));
    self->Change303.IsTriggered =
        IsTriggered(MakeChange(self->D49inFailureOfThePom.IsSignalled, self->D49inFailureOfThePom.Value));
    self->Change302.IsTriggered =
        IsTriggered(MakeChange(self->D49inFailureOfThePom.IsSignalled, self->D49inFailureOfThePom.Value));
    self->Change578.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D49inFailureOfThePom.IsSignalled, self->D49inFailureOfThePom.Value)));
    self->Change300.IsTriggered =
        IsTriggered(MakeChange(self->D48inOccupancyDetected.IsSignalled, self->D48inOccupancyDetected.Value == true));
    self->Change299.IsTriggered =
        IsTriggered(MakeChange(self->D48inOccupancyDetected.IsSignalled, self->D48inOccupancyDetected.Value == false));
    self->Change319.IsTriggered = IsTriggered(
        MakeChange(self->D50inFailureOfThePowerSupply.IsSignalled, self->D50inFailureOfThePowerSupply.Value));
    self->Change582.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D50inFailureOfThePowerSupply.IsSignalled, self->D50inFailureOfThePowerSupply.Value)));
    self->Change580.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D49inFailureOfThePom.IsSignalled, self->D49inFailureOfThePom.Value)));
    self->Change583.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D50inFailureOfThePowerSupply.IsSignalled, self->D50inFailureOfThePowerSupply.Value)));
    self->Change301.IsTriggered =
        IsTriggered(MakeChange(self->D49inFailureOfThePom.IsSignalled, self->D49inFailureOfThePom.Value));
    self->Change318.IsTriggered = IsTriggered(
        MakeChange(self->D50inFailureOfThePowerSupply.IsSignalled, self->D50inFailureOfThePowerSupply.Value));
    self->Change254.IsTriggered =
        IsTriggered(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value));
    self->Change259.IsTriggered = IsTriggered(
        MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value == false));
    self->Change423.IsTriggered = IsTriggered(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveTrackCircuits_D51outEstEfesStateValue__Initialising));
    self->Change409.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D51outEstEfesState.IsSignalled,
                            self->D51outEstEfesState.Value == FObserveTrackCircuits_D51outEstEfesStateValue__Booting),
                 MakeChange(self->D51outEstEfesState.IsSignalled,
                            self->D51outEstEfesState.Value ==
                                FObserveTrackCircuits_D51outEstEfesStateValue__NoOperatingVoltage)));
    self->Change404.IsTriggered = IsTriggered(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveTrackCircuits_D51outEstEfesStateValue__Booting));
    self->Change419.IsTriggered = IsTriggered(
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
    self->D49inFailureOfThePom.IsSignalled = false;
    self->D50inFailureOfThePowerSupply.IsSignalled = false;
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
