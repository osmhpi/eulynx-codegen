
#include "../../04_OutputC/SubsystemPoint/FObserveDegradedPointPosition.h"

void count_transitions_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation(
    int *ctr, FObserveDegradedPointPosition *self, FObserveDegradedPointPosition__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change375.IsTriggered)
    {
        self->D4outObservedDegradedPointPosition.Value =
            FObserveDegradedPointPosition_D4outObservedDegradedPointPositionValue__Undefined;
        self->D4outObservedDegradedPointPosition.IsSignalled = true;
        if ((!(self->D8inConPm2NonCrucialActivation.Value)) && (!(self->D9inConPm2nNonCrucialActivation.Value)))
        {
            (*ctr)++;
        }
        if (((self->D10inPm1CrucialPosition.Value ==
              FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Left) &&
             ((self->D10inPm1nCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm1nCrucialPositionValue__Left) ||
              (!(self->D7inConPm1nCrucialActivation.Value)))) &&
            (((self->D10inPm2nNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue__NoEndPosition) ||
              (self->D10inPm2nNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue__Trailed)) ||
             ((self->D10inPm2NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue__NoEndPosition) ||
              (self->D10inPm2NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue__Trailed))))
        {
            (*ctr)++;
        }
        if (((self->D10inPm1CrucialPosition.Value ==
              FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Right) &&
             ((self->D10inPm1nCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm1nCrucialPositionValue__Right) ||
              (!(self->D7inConPm1nCrucialActivation.Value)))) &&
            (((self->D10inPm2nNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue__NoEndPosition) ||
              (self->D10inPm2nNonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm2nNonCrucialPositionValue__Trailed)) ||
             ((self->D10inPm2NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue__NoEndPosition) ||
              (self->D10inPm2NonCrucialPosition.Value ==
               FObserveDegradedPointPosition_D10inPm2NonCrucialPositionValue__Trailed))))
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

    if (self->Change8.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change25.IsTriggered)
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

    if (self->Change24.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change27.IsTriggered)
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
    if (self->Change26.IsTriggered)
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
    if (self->Change384.IsTriggered)
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