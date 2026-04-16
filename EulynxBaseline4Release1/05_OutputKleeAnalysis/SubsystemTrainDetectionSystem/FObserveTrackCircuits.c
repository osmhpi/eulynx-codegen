
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FObserveTrackCircuits.h"

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomNok(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change579.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomOk(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change297.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root.Vacant.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomNok:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomNok(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomOk:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomOk(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomOk(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change298.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomNok(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change577.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root.Occupied.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomOk:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomOk(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomNok:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomNok(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change296.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change295.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.Observing.root.PowerSupplyIsOk.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change316.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsNok(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change582.IsTriggered)
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
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsNok:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsNok(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change578.IsTriggered)
    {
        if (!(self->D50inFailureOfThePowerSupply.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change581.IsTriggered)
    {
        if (!(self->D49inFailureOfThePom.Value))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change299.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change315.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root(
    int *ctr, FObserveTrackCircuits *self, FObserveTrackCircuits__root__state_struct *x)
{
    switch (x->ReportOccupancyStatus.root.Operating.root.TechnicallyDisturbed.root.state)
    {
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok(
            ctr, self, x);
        break;
    case FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk:
        count_transitions_from_FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk(
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
    if (self->Change247.IsTriggered)
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
    if (self->Change249.IsTriggered)
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

    if (self->Change416.IsTriggered)
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
    if (self->Change405.IsTriggered)
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

    if (self->Change400.IsTriggered)
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
    if (self->Change406.IsTriggered)
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