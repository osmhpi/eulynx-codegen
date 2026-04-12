
#include "SSciTdsReceiveTrackCircuit.h"

// Value Conversion Functions

// Operations

void make_state_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(
    SSciTdsReceiveTrackCircuit *self, SSciTdsReceiveTrackCircuit__root__state_struct *region)
{
    LOG("[SSciTdsReceiveTrackCircuit] Entering state RepoprtingOccupancyStatus in region root");
    region->state = SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus;
};

void make_state_SSciTdsReceiveTrackCircuit__root(SSciTdsReceiveTrackCircuit *self,
                                                 SSciTdsReceiveTrackCircuit__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciTdsReceiveTrackCircuit__root__state_struct));

    make_state_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(self, x);
    return;
}

void transition_from_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(
    SSciTdsReceiveTrackCircuit *self, SSciTdsReceiveTrackCircuit__root__state_struct *x)
{

    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Vacant) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Ok))
        {
            self->D66outAbilityToBeForcedToClear.Value = false;
            self->D66outTvpsOccupancyStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateVacant;
            self->D66outTvpsOccupancyStatus.IsSignalled = true;
            self->D66outPomStatus.Value = SSciTdsReceiveTrackCircuit_D66outPomStatusValue__Ok;
            self->D66outPomStatus.IsSignalled = true;
            self->D66outDisturbanceStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__NotApplicable;
            self->D66outDisturbanceStatus.IsSignalled = true;
            self->T66outTvpsOccupancyStatus.Trigger = true;
            make_state_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(self, x);
            return;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Vacant) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Nok))
        {
            self->D66outAbilityToBeForcedToClear.Value = false;
            self->D66outTvpsOccupancyStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateVacant;
            self->D66outTvpsOccupancyStatus.IsSignalled = true;
            self->D66outPomStatus.Value = SSciTdsReceiveTrackCircuit_D66outPomStatusValue__Nok;
            self->D66outPomStatus.IsSignalled = true;
            self->D66outDisturbanceStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__NotApplicable;
            self->D66outDisturbanceStatus.IsSignalled = true;
            self->T66outTvpsOccupancyStatus.Trigger = true;
            make_state_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(self, x);
            return;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Occupied) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Ok))
        {
            self->D66outAbilityToBeForcedToClear.Value = false;
            self->D66outTvpsOccupancyStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
            self->D66outTvpsOccupancyStatus.IsSignalled = true;
            self->D66outPomStatus.Value = SSciTdsReceiveTrackCircuit_D66outPomStatusValue__Ok;
            self->D66outPomStatus.IsSignalled = true;
            self->D66outDisturbanceStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__NotApplicable;
            self->D66outDisturbanceStatus.IsSignalled = true;
            self->T66outTvpsOccupancyStatus.Trigger = true;
            make_state_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(self, x);
            return;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Occupied) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Nok))
        {
            self->D66outAbilityToBeForcedToClear.Value = false;
            self->D66outTvpsOccupancyStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
            self->D66outTvpsOccupancyStatus.IsSignalled = true;
            self->D66outPomStatus.Value = SSciTdsReceiveTrackCircuit_D66outPomStatusValue__Nok;
            self->D66outPomStatus.IsSignalled = true;
            self->D66outDisturbanceStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__NotApplicable;
            self->D66outDisturbanceStatus.IsSignalled = true;
            self->T66outTvpsOccupancyStatus.Trigger = true;
            make_state_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(self, x);
            return;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Disturbed) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Ok))
        {
            self->D66outAbilityToBeForcedToClear.Value = false;
            self->D66outTvpsOccupancyStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
            self->D66outTvpsOccupancyStatus.IsSignalled = true;
            self->D66outPomStatus.Value = SSciTdsReceiveTrackCircuit_D66outPomStatusValue__Ok;
            self->D66outPomStatus.IsSignalled = true;
            self->D66outDisturbanceStatus.Value = SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__Technical;
            self->D66outDisturbanceStatus.IsSignalled = true;
            self->T66outTvpsOccupancyStatus.Trigger = true;
            make_state_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(self, x);
            return;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Disturbed) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Nok))
        {
            self->D66outAbilityToBeForcedToClear.Value = false;
            self->D66outTvpsOccupancyStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
            self->D66outTvpsOccupancyStatus.IsSignalled = true;
            self->D66outPomStatus.Value = SSciTdsReceiveTrackCircuit_D66outPomStatusValue__Nok;
            self->D66outPomStatus.IsSignalled = true;
            self->D66outDisturbanceStatus.Value = SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__Technical;
            self->D66outDisturbanceStatus.IsSignalled = true;
            self->T66outTvpsOccupancyStatus.Trigger = true;
            make_state_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(self, x);
            return;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Vacant) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__NotApplicable))
        {
            self->D66outAbilityToBeForcedToClear.Value = false;
            self->D66outTvpsOccupancyStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateVacant;
            self->D66outTvpsOccupancyStatus.IsSignalled = true;
            self->D66outPomStatus.Value = SSciTdsReceiveTrackCircuit_D66outPomStatusValue__NotApplicable;
            self->D66outPomStatus.IsSignalled = true;
            self->D66outDisturbanceStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__NotApplicable;
            self->D66outDisturbanceStatus.IsSignalled = true;
            self->T66outTvpsOccupancyStatus.Trigger = true;
            make_state_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(self, x);
            return;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Occupied) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__NotApplicable))
        {
            self->D66outAbilityToBeForcedToClear.Value = false;
            self->D66outTvpsOccupancyStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateOccupied;
            self->D66outTvpsOccupancyStatus.IsSignalled = true;
            self->D66outPomStatus.Value = SSciTdsReceiveTrackCircuit_D66outPomStatusValue__NotApplicable;
            self->D66outPomStatus.IsSignalled = true;
            self->D66outDisturbanceStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__NotApplicable;
            self->D66outDisturbanceStatus.IsSignalled = true;
            self->T66outTvpsOccupancyStatus.Trigger = true;
            make_state_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(self, x);
            return;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Disturbed) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__NotApplicable))
        {
            self->D66outAbilityToBeForcedToClear.Value = false;
            self->D66outTvpsOccupancyStatus.Value =
                SSciTdsReceiveTrackCircuit_D66outTvpsOccupancyStatusValue__TvpsIsInStateDisturbed;
            self->D66outTvpsOccupancyStatus.IsSignalled = true;
            self->D66outPomStatus.Value = SSciTdsReceiveTrackCircuit_D66outPomStatusValue__NotApplicable;
            self->D66outPomStatus.IsSignalled = true;
            self->D66outDisturbanceStatus.Value = SSciTdsReceiveTrackCircuit_D66outDisturbanceStatusValue__Technical;
            self->D66outDisturbanceStatus.IsSignalled = true;
            self->T66outTvpsOccupancyStatus.Trigger = true;
            make_state_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(self, x);
            return;
        }
    }
}

void transition_from_SSciTdsReceiveTrackCircuit__root(SSciTdsReceiveTrackCircuit *self,
                                                      SSciTdsReceiveTrackCircuit__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus:
        transition_from_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciTdsReceiveTrackCircuit *self)
{
}

static void resetOutputs(SSciTdsReceiveTrackCircuit *self)
{

    self->T66outTvpsOccupancyStatus.Trigger = false;

    self->D66outAbilityToBeForcedToClear.IsSignalled = false;
    self->D66outTvpsOccupancyStatus.IsSignalled = false;
    self->D66outPomStatus.IsSignalled = false;
    self->D66outDisturbanceStatus.IsSignalled = false;
}

static void resetTriggers(SSciTdsReceiveTrackCircuit *self)
{
    self->InMsgTvpsOccupancyStatus__b4e1.HasMessage = false;
}

void transition_SSciTdsReceiveTrackCircuit(SSciTdsReceiveTrackCircuit *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciTdsReceiveTrackCircuit__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciTdsReceiveTrackCircuit(SSciTdsReceiveTrackCircuit *self)
{
    make_state_SSciTdsReceiveTrackCircuit__root(self, &self->state);
}
