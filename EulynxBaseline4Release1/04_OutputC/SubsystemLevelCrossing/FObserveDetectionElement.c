
#include "FObserveDetectionElement.h"

// Value Conversion Functions

// Operations

void make_state_FObserveDetectionElement__root__Waiting(FObserveDetectionElement *self,
                                                        FObserveDetectionElement__root__state_struct *region)
{
    LOG("[FObserveDetectionElement] Entering state Waiting in region root");
    region->state = FObserveDetectionElement__root__Waiting;
};

void make_state_FObserveDetectionElement__root__Occupied(FObserveDetectionElement *self,
                                                         FObserveDetectionElement__root__state_struct *region)
{
    LOG("[FObserveDetectionElement] Entering state Occupied in region root");
    region->state = FObserveDetectionElement__root__Occupied;
};

void make_state_FObserveDetectionElement__root__Vacant(FObserveDetectionElement *self,
                                                       FObserveDetectionElement__root__state_struct *region)
{
    LOG("[FObserveDetectionElement] Entering state Vacant in region root");
    region->state = FObserveDetectionElement__root__Vacant;
};

void make_state_FObserveDetectionElement__root__TechnicalFailure(FObserveDetectionElement *self,
                                                                 FObserveDetectionElement__root__state_struct *region)
{
    LOG("[FObserveDetectionElement] Entering state TechnicalFailure in region root");
    region->state = FObserveDetectionElement__root__TechnicalFailure;
};

void make_state_FObserveDetectionElement__root(FObserveDetectionElement *self,
                                               FObserveDetectionElement__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveDetectionElement__root__state_struct));

    make_state_FObserveDetectionElement__root__Waiting(self, x);
    return;
}

void transition_from_FObserveDetectionElement__root__Waiting(FObserveDetectionElement *self,
                                                             FObserveDetectionElement__root__state_struct *x)
{

    if (self->Change12.IsTriggered)
    {
        self->D7outDetectionElementStatus.Value = FObserveDetectionElement_D7outDetectionElementStatusValue__Occupied;
        self->D7outDetectionElementStatus.IsSignalled = true;
        make_state_FObserveDetectionElement__root__Occupied(self, x);
        return;
    }
    if (self->Change13.IsTriggered)
    {
        self->D7outDetectionElementStatus.Value = FObserveDetectionElement_D7outDetectionElementStatusValue__Vacant;
        self->D7outDetectionElementStatus.IsSignalled = true;
        make_state_FObserveDetectionElement__root__Vacant(self, x);
        return;
    }
    if (self->Change11.IsTriggered)
    {
        self->D7outDetectionElementStatus.Value = FObserveDetectionElement_D7outDetectionElementStatusValue__Failed;
        self->D7outDetectionElementStatus.IsSignalled = true;
        make_state_FObserveDetectionElement__root__TechnicalFailure(self, x);
        return;
    }
}

void transition_from_FObserveDetectionElement__root__Occupied(FObserveDetectionElement *self,
                                                              FObserveDetectionElement__root__state_struct *x)
{

    if (self->Change16.IsTriggered)
    {
        self->D7outDetectionElementStatus.Value = FObserveDetectionElement_D7outDetectionElementStatusValue__Vacant;
        self->D7outDetectionElementStatus.IsSignalled = true;
        make_state_FObserveDetectionElement__root__Vacant(self, x);
        return;
    }
    if (self->Change14.IsTriggered)
    {
        self->D7outDetectionElementStatus.Value = FObserveDetectionElement_D7outDetectionElementStatusValue__Failed;
        self->D7outDetectionElementStatus.IsSignalled = true;
        make_state_FObserveDetectionElement__root__TechnicalFailure(self, x);
        return;
    }
}

void transition_from_FObserveDetectionElement__root__Vacant(FObserveDetectionElement *self,
                                                            FObserveDetectionElement__root__state_struct *x)
{

    if (self->Change18.IsTriggered)
    {
        self->D7outDetectionElementStatus.Value = FObserveDetectionElement_D7outDetectionElementStatusValue__Occupied;
        self->D7outDetectionElementStatus.IsSignalled = true;
        make_state_FObserveDetectionElement__root__Occupied(self, x);
        return;
    }
    if (self->Change17.IsTriggered)
    {
        self->D7outDetectionElementStatus.Value = FObserveDetectionElement_D7outDetectionElementStatusValue__Failed;
        self->D7outDetectionElementStatus.IsSignalled = true;
        make_state_FObserveDetectionElement__root__TechnicalFailure(self, x);
        return;
    }
}

void transition_from_FObserveDetectionElement__root__TechnicalFailure(FObserveDetectionElement *self,
                                                                      FObserveDetectionElement__root__state_struct *x)
{

    if (self->Change10.IsTriggered)
    {
        self->D7outDetectionElementStatus.Value = FObserveDetectionElement_D7outDetectionElementStatusValue__Occupied;
        self->D7outDetectionElementStatus.IsSignalled = true;
        make_state_FObserveDetectionElement__root__Occupied(self, x);
        return;
    }
    if (self->Change15.IsTriggered)
    {
        self->D7outDetectionElementStatus.Value = FObserveDetectionElement_D7outDetectionElementStatusValue__Vacant;
        self->D7outDetectionElementStatus.IsSignalled = true;
        make_state_FObserveDetectionElement__root__Vacant(self, x);
        return;
    }
}

void transition_from_FObserveDetectionElement__root(FObserveDetectionElement *self,
                                                    FObserveDetectionElement__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveDetectionElement__root__Waiting:
        transition_from_FObserveDetectionElement__root__Waiting(self, x);
        break;
    case FObserveDetectionElement__root__Occupied:
        transition_from_FObserveDetectionElement__root__Occupied(self, x);
        break;
    case FObserveDetectionElement__root__Vacant:
        transition_from_FObserveDetectionElement__root__Vacant(self, x);
        break;
    case FObserveDetectionElement__root__TechnicalFailure:
        transition_from_FObserveDetectionElement__root__TechnicalFailure(self, x);
        break;
    }
}

static void evaluateChangeEvents(FObserveDetectionElement *self)
{
    self->Change12.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D108inDetectionElementStatus.IsSignalled,
                   self->D108inDetectionElementStatus.Value ==
                       FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementOccupied),
        MakeChange(self->D118inConUseDetectionElement.IsSignalled, self->D118inConUseDetectionElement.Value)));
    self->Change13.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D108inDetectionElementStatus.IsSignalled,
                   self->D108inDetectionElementStatus.Value ==
                       FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementVacant),
        MakeChange(self->D118inConUseDetectionElement.IsSignalled, self->D118inConUseDetectionElement.Value)));
    self->Change11.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D108inDetectionElementStatus.IsSignalled,
                   self->D108inDetectionElementStatus.Value ==
                       FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementFailed),
        MakeChange(self->D118inConUseDetectionElement.IsSignalled, self->D118inConUseDetectionElement.Value)));
    self->Change16.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D108inDetectionElementStatus.IsSignalled,
                   self->D108inDetectionElementStatus.Value ==
                       FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementVacant),
        MakeChange(self->D118inConUseDetectionElement.IsSignalled, self->D118inConUseDetectionElement.Value)));
    self->Change14.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D108inDetectionElementStatus.IsSignalled,
                   self->D108inDetectionElementStatus.Value ==
                       FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementFailed),
        MakeChange(self->D118inConUseDetectionElement.IsSignalled, self->D118inConUseDetectionElement.Value)));
    self->Change18.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D108inDetectionElementStatus.IsSignalled,
                   self->D108inDetectionElementStatus.Value ==
                       FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementOccupied),
        MakeChange(self->D118inConUseDetectionElement.IsSignalled, self->D118inConUseDetectionElement.Value)));
    self->Change17.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D108inDetectionElementStatus.IsSignalled,
                   self->D108inDetectionElementStatus.Value ==
                       FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementFailed),
        MakeChange(self->D118inConUseDetectionElement.IsSignalled, self->D118inConUseDetectionElement.Value)));
    self->Change10.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D108inDetectionElementStatus.IsSignalled,
                   self->D108inDetectionElementStatus.Value ==
                       FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementOccupied),
        MakeChange(self->D118inConUseDetectionElement.IsSignalled, self->D118inConUseDetectionElement.Value)));
    self->Change15.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D108inDetectionElementStatus.IsSignalled,
                   self->D108inDetectionElementStatus.Value ==
                       FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementVacant),
        MakeChange(self->D118inConUseDetectionElement.IsSignalled, self->D118inConUseDetectionElement.Value)));
}

static void resetOutputs(FObserveDetectionElement *self)
{

    self->D7outDetectionElementStatus.IsSignalled = false;
}

static void resetTriggers(FObserveDetectionElement *self)
{

    self->D118inConUseDetectionElement.IsSignalled = false;
    self->D108inDetectionElementStatus.IsSignalled = false;
}

void transition_FObserveDetectionElement(FObserveDetectionElement *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FObserveDetectionElement__root(self, &self->state);
    resetTriggers(self);
}

void new_FObserveDetectionElement(FObserveDetectionElement *self)
{
    make_state_FObserveDetectionElement__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemLevelCrossing/FObserveDetectionElement.c"
#endif
