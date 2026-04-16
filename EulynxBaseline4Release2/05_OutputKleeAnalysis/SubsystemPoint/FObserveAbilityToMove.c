
#include "../../04_OutputC/SubsystemPoint/FObserveAbilityToMove.h"

void count_transitions_from_FObserveAbilityToMove__root__WaitingForInitialising(
    int *ctr, FObserveAbilityToMove *self, FObserveAbilityToMove__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change381.IsTriggered)
    {

        if ((((((self->D29inAbilityToMovePm1Crucial.Value ==
                 FObserveAbilityToMove_D29inAbilityToMovePm1CrucialValue__Able) &&
                (((self->D30inAbilityToMovePm1nCrucial.Value ==
                   FObserveAbilityToMove_D30inAbilityToMovePm1nCrucialValue__Able) ||
                  (self->D30inAbilityToMovePm1nCrucial.Value ==
                   FObserveAbilityToMove_D30inAbilityToMovePm1nCrucialValue__NotUsed)) ||
                 (!(self->D26inConPm1nCrucialActivation.Value)))) &&
               (((self->D32inAbilityToMovePm2nNonCrucial.Value ==
                  FObserveAbilityToMove_D32inAbilityToMovePm2nNonCrucialValue__Able) ||
                 (self->D32inAbilityToMovePm2nNonCrucial.Value ==
                  FObserveAbilityToMove_D32inAbilityToMovePm2nNonCrucialValue__NotUsed)) ||
                (!(self->D28inConPm2nNonCrucialActivation.Value)))) &&
              (((self->D31inAbilityToMovePm2NonCrucial.Value ==
                 FObserveAbilityToMove_D31inAbilityToMovePm2NonCrucialValue__Able) ||
                (self->D31inAbilityToMovePm2NonCrucial.Value ==
                 FObserveAbilityToMove_D31inAbilityToMovePm2NonCrucialValue__NotUsed)) ||
               (!(self->D27inConPm2NonCrucialActivation.Value)))) &&
             (self->D33inInternalTriggerAbilityToMovePointAvailable.Value)) &&
            (self->D15inConObserveAbilityToMove.Value))
        {
            (*ctr)++;
        }
        if (!(self->D15inConObserveAbilityToMove.Value))
        {
            (*ctr)++;
        }
        if ((((((self->D29inAbilityToMovePm1Crucial.Value ==
                 FObserveAbilityToMove_D29inAbilityToMovePm1CrucialValue__Unable) ||
                (self->D30inAbilityToMovePm1nCrucial.Value ==
                 FObserveAbilityToMove_D30inAbilityToMovePm1nCrucialValue__Unable)) ||
               (self->D31inAbilityToMovePm2NonCrucial.Value ==
                FObserveAbilityToMove_D31inAbilityToMovePm2NonCrucialValue__Unable)) ||
              (self->D32inAbilityToMovePm2nNonCrucial.Value ==
               FObserveAbilityToMove_D32inAbilityToMovePm2nNonCrucialValue__Unable)) ||
             (!(self->D33inInternalTriggerAbilityToMovePointAvailable.Value))) &&
            (self->D15inConObserveAbilityToMove.Value))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveAbilityToMove__root__AbleToMove(int *ctr, FObserveAbilityToMove *self,
                                                                    FObserveAbilityToMove__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change209.IsTriggered)
    {
        if (self->D15inConObserveAbilityToMove.Value)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveAbilityToMove__root__UnableToMove(int *ctr, FObserveAbilityToMove *self,
                                                                      FObserveAbilityToMove__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change208.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveAbilityToMove__root(int *ctr, FObserveAbilityToMove *self,
                                                        FObserveAbilityToMove__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveAbilityToMove__root__WaitingForInitialising:
        count_transitions_from_FObserveAbilityToMove__root__WaitingForInitialising(ctr, self, x);
        break;
    case FObserveAbilityToMove__root__AbleToMove:
        count_transitions_from_FObserveAbilityToMove__root__AbleToMove(ctr, self, x);
        break;
    case FObserveAbilityToMove__root__UnableToMove:
        count_transitions_from_FObserveAbilityToMove__root__UnableToMove(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveAbilityToMove(FObserveAbilityToMove *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveAbilityToMove__root(&ctr, self, &self->state);
    return ctr;
}