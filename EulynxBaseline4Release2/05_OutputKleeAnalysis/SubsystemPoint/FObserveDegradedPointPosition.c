
#include "../../04_OutputC/SubsystemPoint/FObserveDegradedPointPosition.h"

void count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation(
    int *ctr, FObserveDegradedPointPosition *self, FObserveDegradedPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change376.IsTriggered)
    {
        self->D30outObservedDegradedPointPosition.Value =
            FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__Undefined;
        self->D30outObservedDegradedPointPosition.IsSignalled = true;
        if ((!(self->D27inConPm2NonCrucialActivation.Value)) && (!(self->D28inConPm2nNonCrucialActivation.Value)))
        {
            (*ctr)++;
        }
        if (((self->D22inPm1CrucialPosition.Value ==
              FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Left) &&
             ((self->D23inPm1nCrucialPosition.Value ==
               FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__Left) ||
              (!(self->D26inConPm1nCrucialActivation.Value)))) &&
            (((self->D25inPm2nNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NoEndPosition) ||
              (self->D25inPm2nNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UnintendedPosition)) ||
             ((self->D24inPm2NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NoEndPosition) ||
              (self->D24inPm2NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition))))
        {
            (*ctr)++;
        }
        if (((self->D22inPm1CrucialPosition.Value ==
              FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Right) &&
             ((self->D23inPm1nCrucialPosition.Value ==
               FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__Right) ||
              (!(self->D26inConPm1nCrucialActivation.Value)))) &&
            (((self->D25inPm2nNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NoEndPosition) ||
              (self->D25inPm2nNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UnintendedPosition)) ||
             ((self->D24inPm2NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NoEndPosition) ||
              (self->D24inPm2NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition))))
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

    if (self->Change9.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change186.IsTriggered)
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

    if (self->Change187.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change188.IsTriggered)
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

    if (self->Change10.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change189.IsTriggered)
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
    if (self->Change391.IsTriggered)
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