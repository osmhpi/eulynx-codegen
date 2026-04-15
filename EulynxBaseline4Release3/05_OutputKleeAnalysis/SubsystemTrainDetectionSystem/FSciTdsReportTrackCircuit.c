
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FSciTdsReportTrackCircuit.h"

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomOk(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change270.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomNok(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change273.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__WithoutPom(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    switch (x->ReportingOccupancyStatus.root.Vacant.root.state)
    {
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomOk:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomOk(
            ctr, self, x);
        break;
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomNok:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__PomNok(
            ctr, self, x);
        break;
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__WithoutPom:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root__WithoutPom(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomNok(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change274.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomOk(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change271.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__WithoutPom(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    switch (x->ReportingOccupancyStatus.root.Occupied.root.state)
    {
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomNok:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomNok(
            ctr, self, x);
        break;
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomOk:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__PomOk(
            ctr, self, x);
        break;
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__WithoutPom:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root__WithoutPom(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomOk(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change272.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomNok(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change275.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__WithoutPom(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    switch (x->ReportingOccupancyStatus.root.Disturbed.root.state)
    {
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomOk:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomOk(
            ctr, self, x);
        break;
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomNok:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__PomNok(
            ctr, self, x);
        break;
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__WithoutPom:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root__WithoutPom(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Waiting(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InStartStatusReport__1e4e.HasMessage)
    {

        if (self->D45inReportedTvpsOccupancyStatus.Value ==
            FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateOccupied)
        {
            (*ctr)++;
        }
        if (self->D45inReportedTvpsOccupancyStatus.Value ==
            FSciTdsReportTrackCircuit_D45inReportedTvpsOccupancyStatusValue__TvpsIsInStateVacant)
        {
            (*ctr)++;
        }
        else
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change265.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change267.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied__root(&tmp, self,
                                                                                                           x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change268.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change269.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed__root(&tmp, self,
                                                                                                            x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change266.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change264.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    switch (x->ReportingOccupancyStatus.root.state)
    {
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Waiting:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Waiting(ctr, self, x);
        break;
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Vacant(ctr, self, x);
        break;
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Occupied(ctr, self, x);
        break;
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root__Disturbed(ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus(
    int *ctr, FSciTdsReportTrackCircuit *self, FSciTdsReportTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change310.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTrackCircuit__root(int *ctr, FSciTdsReportTrackCircuit *self,
                                                            FSciTdsReportTrackCircuit__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus:
        count_transitions_from_FSciTdsReportTrackCircuit__root__ReportingOccupancyStatus(ctr, self, x);
        break;
    }
}

int count_transitions_FSciTdsReportTrackCircuit(FSciTdsReportTrackCircuit *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciTdsReportTrackCircuit__root(&ctr, self, &self->state);
    return ctr;
}