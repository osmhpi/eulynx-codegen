
#include "FObserveAbilityToMove.h"

// Value Conversion Functions

// Operations

void make_state_FObserveAbilityToMove__root__WaitingForInitialising(FObserveAbilityToMove *self,
                                                                    FObserveAbilityToMove__root__state_struct *region)
{
    LOG("[FObserveAbilityToMove] Entering state WaitingForInitialising in region "
        "root");
    region->state = FObserveAbilityToMove__root__WaitingForInitialising;
};

void make_state_FObserveAbilityToMove__root__AbleToMove(FObserveAbilityToMove *self,
                                                        FObserveAbilityToMove__root__state_struct *region)
{
    LOG("[FObserveAbilityToMove] Entering state AbleToMove in region root");
    region->state = FObserveAbilityToMove__root__AbleToMove;
};

void make_state_FObserveAbilityToMove__root__UnableToMove(FObserveAbilityToMove *self,
                                                          FObserveAbilityToMove__root__state_struct *region)
{
    LOG("[FObserveAbilityToMove] Entering state UnableToMove in region root");
    region->state = FObserveAbilityToMove__root__UnableToMove;
};

void make_state_FObserveAbilityToMove__root(FObserveAbilityToMove *self, FObserveAbilityToMove__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveAbilityToMove__root__state_struct));

    make_state_FObserveAbilityToMove__root__WaitingForInitialising(self, x);
    return;
}

void transition_from_FObserveAbilityToMove__root__WaitingForInitialising(FObserveAbilityToMove *self,
                                                                         FObserveAbilityToMove__root__state_struct *x)
{

    if (self->Change356.IsTriggered)
    {

        if ((((((self->D19inAbilityToMovePm1Crucial.Value ==
                 FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue__Able) &&
                (((self->D19inAbilityToMovePm1nCrucial.Value ==
                   FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue__Able) ||
                  (self->D19inAbilityToMovePm1nCrucial.Value ==
                   FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue__NotUsed)) ||
                 (!(self->D26inConPmiCrucialActivation.Value)))) &&
               (((self->D19inAbilityToMovePm2nNonCrucial.Value ==
                  FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue__Able) ||
                 (self->D19inAbilityToMovePm2nNonCrucial.Value ==
                  FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue__NotUsed)) ||
                (!(self->D28inConPmkNonCrucialActivation.Value)))) &&
              (((self->D19inAbilityToMovePm2NonCrucial.Value ==
                 FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue__Able) ||
                (self->D19inAbilityToMovePm2NonCrucial.Value ==
                 FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue__NotUsed)) ||
               (!(self->D27inConPm1NonCrucialActivation.Value)))) &&
             (self->D33inInternalTriggerAbilityToMovePointAvailable.Value)) &&
            (self->D15inConObserveAbilityToMove.Value))
        {
            self->D11outObservedAbilityToMove.Value =
                FObserveAbilityToMove_D11outObservedAbilityToMoveValue__AbleToMove;
            self->D11outObservedAbilityToMove.IsSignalled = true;
            make_state_FObserveAbilityToMove__root__AbleToMove(self, x);
            return;
        }
        if (!(self->D15inConObserveAbilityToMove.Value))
        {
            self->D11outObservedAbilityToMove.Value =
                FObserveAbilityToMove_D11outObservedAbilityToMoveValue__AbleToMove;
            self->D11outObservedAbilityToMove.IsSignalled = true;
            make_state_FObserveAbilityToMove__root__AbleToMove(self, x);
            return;
        }
        if ((((((self->D19inAbilityToMovePm1Crucial.Value ==
                 FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue__Unable) ||
                (self->D19inAbilityToMovePm1nCrucial.Value ==
                 FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue__Unable)) ||
               (self->D19inAbilityToMovePm2NonCrucial.Value ==
                FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue__Unable)) ||
              (self->D19inAbilityToMovePm2nNonCrucial.Value ==
               FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue__Unable)) ||
             (!(self->D33inInternalTriggerAbilityToMovePointAvailable.Value))) &&
            (self->D15inConObserveAbilityToMove.Value))
        {
            self->D11outObservedAbilityToMove.Value =
                FObserveAbilityToMove_D11outObservedAbilityToMoveValue__UnableToMove;
            self->D11outObservedAbilityToMove.IsSignalled = true;
            make_state_FObserveAbilityToMove__root__UnableToMove(self, x);
            return;
        }
    }
}

void transition_from_FObserveAbilityToMove__root__AbleToMove(FObserveAbilityToMove *self,
                                                             FObserveAbilityToMove__root__state_struct *x)
{

    if (self->Change131.IsTriggered)
    {
        if (self->D15inConObserveAbilityToMove.Value)
        {
            self->D11outObservedAbilityToMove.Value =
                FObserveAbilityToMove_D11outObservedAbilityToMoveValue__UnableToMove;
            self->D11outObservedAbilityToMove.IsSignalled = true;
            make_state_FObserveAbilityToMove__root__UnableToMove(self, x);
            return;
        }
    }
}

void transition_from_FObserveAbilityToMove__root__UnableToMove(FObserveAbilityToMove *self,
                                                               FObserveAbilityToMove__root__state_struct *x)
{

    if (self->Change130.IsTriggered)
    {
        self->D11outObservedAbilityToMove.Value = FObserveAbilityToMove_D11outObservedAbilityToMoveValue__AbleToMove;
        self->D11outObservedAbilityToMove.IsSignalled = true;
        make_state_FObserveAbilityToMove__root__AbleToMove(self, x);
        return;
    }
}

void transition_from_FObserveAbilityToMove__root(FObserveAbilityToMove *self,
                                                 FObserveAbilityToMove__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveAbilityToMove__root__WaitingForInitialising:
        transition_from_FObserveAbilityToMove__root__WaitingForInitialising(self, x);
        break;
    case FObserveAbilityToMove__root__AbleToMove:
        transition_from_FObserveAbilityToMove__root__AbleToMove(self, x);
        break;
    case FObserveAbilityToMove__root__UnableToMove:
        transition_from_FObserveAbilityToMove__root__UnableToMove(self, x);
        break;
    }
}

static void evaluateChangeEvents(FObserveAbilityToMove *self)
{
    self->Change356.IsTriggered = IsTriggered(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FObserveAbilityToMove_D51inEstEfesStateValue__Initialising));
    self->Change131.IsTriggered = IsTriggered(OrChange(
        OrChange(OrChange(OrChange(MakeChange(self->D19inAbilityToMovePm1Crucial.IsSignalled,
                                              self->D19inAbilityToMovePm1Crucial.Value ==
                                                  FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue__Unable),
                                   MakeChange(self->D19inAbilityToMovePm1nCrucial.IsSignalled,
                                              self->D19inAbilityToMovePm1nCrucial.Value ==
                                                  FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue__Unable)),
                          MakeChange(self->D19inAbilityToMovePm2NonCrucial.IsSignalled,
                                     self->D19inAbilityToMovePm2NonCrucial.Value ==
                                         FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue__Unable)),
                 MakeChange(self->D19inAbilityToMovePm2nNonCrucial.IsSignalled,
                            self->D19inAbilityToMovePm2nNonCrucial.Value ==
                                FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue__Unable)),
        NegateChange(MakeChange(self->D33inInternalTriggerAbilityToMovePointAvailable.IsSignalled,
                                self->D33inInternalTriggerAbilityToMovePointAvailable.Value))));
    self->Change130.IsTriggered = IsTriggered(AndChange(
        AndChange(
            AndChange(
                AndChange(
                    MakeChange(self->D19inAbilityToMovePm1Crucial.IsSignalled,
                               self->D19inAbilityToMovePm1Crucial.Value ==
                                   FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue__Able),
                    OrChange(
                        OrChange(MakeChange(self->D19inAbilityToMovePm1nCrucial.IsSignalled,
                                            self->D19inAbilityToMovePm1nCrucial.Value ==
                                                FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue__Able),
                                 MakeChange(self->D19inAbilityToMovePm1nCrucial.IsSignalled,
                                            self->D19inAbilityToMovePm1nCrucial.Value ==
                                                FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue__NotUsed)),
                        NegateChange(MakeChange(self->D26inConPmiCrucialActivation.IsSignalled,
                                                self->D26inConPmiCrucialActivation.Value)))),
                OrChange(OrChange(MakeChange(self->D19inAbilityToMovePm2nNonCrucial.IsSignalled,
                                             self->D19inAbilityToMovePm2nNonCrucial.Value ==
                                                 FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue__Able),
                                  MakeChange(self->D19inAbilityToMovePm2nNonCrucial.IsSignalled,
                                             self->D19inAbilityToMovePm2nNonCrucial.Value ==
                                                 FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue__NotUsed)),
                         NegateChange(MakeChange(self->D28inConPmkNonCrucialActivation.IsSignalled,
                                                 self->D28inConPmkNonCrucialActivation.Value)))),
            OrChange(OrChange(MakeChange(self->D19inAbilityToMovePm2NonCrucial.IsSignalled,
                                         self->D19inAbilityToMovePm2NonCrucial.Value ==
                                             FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue__Able),
                              MakeChange(self->D19inAbilityToMovePm2NonCrucial.IsSignalled,
                                         self->D19inAbilityToMovePm2NonCrucial.Value ==
                                             FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue__NotUsed)),
                     NegateChange(MakeChange(self->D27inConPm1NonCrucialActivation.IsSignalled,
                                             self->D27inConPm1NonCrucialActivation.Value)))),
        MakeChange(self->D33inInternalTriggerAbilityToMovePointAvailable.IsSignalled,
                   self->D33inInternalTriggerAbilityToMovePointAvailable.Value)));
}

static void resetOutputs(FObserveAbilityToMove *self)
{

    self->D11outObservedAbilityToMove.IsSignalled = false;
}

static void resetTriggers(FObserveAbilityToMove *self)
{

    self->D19inAbilityToMovePm1nCrucial.IsSignalled = false;
    self->D19inAbilityToMovePm1Crucial.IsSignalled = false;
    self->D19inAbilityToMovePm2NonCrucial.IsSignalled = false;
    self->D19inAbilityToMovePm2nNonCrucial.IsSignalled = false;
    self->D33inInternalTriggerAbilityToMovePointAvailable.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
    self->D26inConPmiCrucialActivation.IsSignalled = false;
    self->D27inConPm1NonCrucialActivation.IsSignalled = false;
    self->D28inConPmkNonCrucialActivation.IsSignalled = false;
    self->D15inConObserveAbilityToMove.IsSignalled = false;
}

void transition_FObserveAbilityToMove(FObserveAbilityToMove *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FObserveAbilityToMove__root(self, &self->state);
    resetTriggers(self);
}

void new_FObserveAbilityToMove(FObserveAbilityToMove *self)
{
    make_state_FObserveAbilityToMove__root(self, &self->state);
}
