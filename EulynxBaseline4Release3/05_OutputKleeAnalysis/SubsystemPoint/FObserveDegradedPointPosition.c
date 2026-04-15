
#include "../../04_OutputC/SubsystemPoint/FObserveDegradedPointPosition.h"

void count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation(
    int *ctr, FObserveDegradedPointPosition *self, FObserveDegradedPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change360.IsTriggered)
    {
        self->D17outObservedDegradedPointPosition.Value =
            FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__Undefined;
        self->D17outObservedDegradedPointPosition.IsSignalled = true;
        if ((!(self->D27inConPm1NonCrucialActivation.Value)) && (!(self->D28inConPmkNonCrucialActivation.Value)))
        {
            (*ctr)++;
        }
        if (((self->D10inPm1CrucialPosition.Value ==
              FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Left) &&
             ((self->D10inPmiCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__Left) ||
              (!(self->D26inConPmiCrucialActivation.Value)))) &&
            (((self->D10inPmkNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NoEndPosition) ||
              (self->D10inPmkNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition)) ||
             ((self->D10inPm1NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NoEndPosition) ||
              (self->D10inPm1NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition))))
        {
            (*ctr)++;
        }
        if (((self->D10inPm1CrucialPosition.Value ==
              FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Right) &&
             ((self->D10inPmiCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__Right) ||
              (!(self->D26inConPmiCrucialActivation.Value)))) &&
            (((self->D10inPmkNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NoEndPosition) ||
              (self->D10inPmkNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition)) ||
             ((self->D10inPm1NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NoEndPosition) ||
              (self->D10inPm1NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition))))
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

void count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight(
    int *ctr, FObserveDegradedPointPosition *self, FObserveDegradedPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change10.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change26.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
    int *ctr, FObserveDegradedPointPosition *self, FObserveDegradedPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change27.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change28.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
    int *ctr, FObserveDegradedPointPosition *self, FObserveDegradedPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change9.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change29.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied(
    int *ctr, FObserveDegradedPointPosition *self, FObserveDegradedPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root(
    int *ctr, FObserveDegradedPointPosition *self, FObserveDegradedPointPosition__root__state_struct *x)
{
    switch (x->ObserveDegradedPointPosition.root.state)
    {
    case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation:
        count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation(
            ctr, self, x);
        break;
    case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight:
        count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight(
            ctr, self, x);
        break;
    case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded:
        count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
            ctr, self, x);
        break;
    case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft:
        count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
            ctr, self, x);
        break;
    case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied:
        count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition(
    int *ctr, FObserveDegradedPointPosition *self, FObserveDegradedPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change374.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveDegradedPointPosition__root(int *ctr, FObserveDegradedPointPosition *self,
                                                                FObserveDegradedPointPosition__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition:
        count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveDegradedPointPosition(FObserveDegradedPointPosition *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveDegradedPointPosition__root(&ctr, self, &self->state);
    return ctr;
}