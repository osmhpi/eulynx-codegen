
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FObserveTrackCircuits.h"

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomOk(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change278.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomNok(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change572.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__WithoutPom(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.Occupied.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomOk:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomOk(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomNok:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__PomNok(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__WithoutPom:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root__WithoutPom(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomNok(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change570.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomOk(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change279.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__WithoutPom(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.Vacant.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomNok:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomNok(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomOk:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__PomOk(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__WithoutPom:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root__WithoutPom(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change276.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change277.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Occupied(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__Vacant(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomNok(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change571.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomOk(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change280.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__WithoutPom(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.TechnicallyDisturbed.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomNok:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomNok(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomOk:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PomOk(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__WithoutPom:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__WithoutPom(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change232.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change236.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change400.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change387.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating(ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTrackCircuits__root__FallbackMode(int *ctr, FObserveTrackCircuits *self,
                                                                      FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change383.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change395.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root(int *ctr, FObserveTrackCircuits *self,
                                                        FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveTrackCircuits__root__FallbackMode:
        count_transitions_from_FObserveTrackCircuits__root__FallbackMode(ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveTrackCircuits(FObserveTrackCircuits *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveTrackCircuits__root(&ctr, self, &self->state);
    return ctr;
}