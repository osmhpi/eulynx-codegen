
#include "FObserveOverallPointPosition.h"

// Value Conversion Functions

static FObserveOverallPointPosition_D10inPm1CrucialPositionValue map_MemPm1CrucialPosition_to_D10inPm1CrucialPosition(
    FObserveOverallPointPosition_MemPm1CrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_MemPm1CrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_MemPm1CrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_MemPm1CrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Undefined;
    case FObserveOverallPointPosition_MemPm1CrucialPositionValue__Left:
        return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Left;
    case FObserveOverallPointPosition_MemPm1CrucialPositionValue__Right:
        return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Right;
    case FObserveOverallPointPosition_MemPm1CrucialPositionValue__UnintendedPosition:
        return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__UnintendedPosition;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_D10inPmiCrucialPositionValue map_MemPmiCrucialPosition_to_D10inPmiCrucialPosition(
    FObserveOverallPointPosition_MemPmiCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_MemPmiCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_D10inPmiCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_MemPmiCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_D10inPmiCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_MemPmiCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_D10inPmiCrucialPositionValue__Undefined;
    case FObserveOverallPointPosition_MemPmiCrucialPositionValue__Left:
        return FObserveOverallPointPosition_D10inPmiCrucialPositionValue__Left;
    case FObserveOverallPointPosition_MemPmiCrucialPositionValue__Right:
        return FObserveOverallPointPosition_D10inPmiCrucialPositionValue__Right;
    case FObserveOverallPointPosition_MemPmiCrucialPositionValue__UnintendedPosition:
        return FObserveOverallPointPosition_D10inPmiCrucialPositionValue__UnintendedPosition;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue
map_MemPm1NonCrucialPosition_to_D10inPm1NonCrucialPosition(
    FObserveOverallPointPosition_MemPm1NonCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__Undefined;
    case FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__Left:
        return FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__Left;
    case FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__Right:
        return FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__Right;
    case FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__UnintendedPosition:
        return FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue
map_MemPmkNonCrucialPosition_to_D10inPmkNonCrucialPosition(
    FObserveOverallPointPosition_MemPmkNonCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__Undefined;
    case FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__Left:
        return FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__Left;
    case FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__Right:
        return FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__Right;
    case FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__UnintendedPosition:
        return FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_MemPm1CrucialPositionValue map_D10inPm1CrucialPosition_to_MemPm1CrucialPosition(
    FObserveOverallPointPosition_D10inPm1CrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_D10inPm1CrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_MemPm1CrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_D10inPm1CrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_MemPm1CrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Left:
        return FObserveOverallPointPosition_MemPm1CrucialPositionValue__Left;
    case FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Right:
        return FObserveOverallPointPosition_MemPm1CrucialPositionValue__Right;
    case FObserveOverallPointPosition_D10inPm1CrucialPositionValue__UnintendedPosition:
        return FObserveOverallPointPosition_MemPm1CrucialPositionValue__UnintendedPosition;
    case FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_MemPm1CrucialPositionValue__Undefined;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_MemPmiCrucialPositionValue map_D10inPmiCrucialPosition_to_MemPmiCrucialPosition(
    FObserveOverallPointPosition_D10inPmiCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_D10inPmiCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_MemPmiCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_D10inPmiCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_MemPmiCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_D10inPmiCrucialPositionValue__Left:
        return FObserveOverallPointPosition_MemPmiCrucialPositionValue__Left;
    case FObserveOverallPointPosition_D10inPmiCrucialPositionValue__Right:
        return FObserveOverallPointPosition_MemPmiCrucialPositionValue__Right;
    case FObserveOverallPointPosition_D10inPmiCrucialPositionValue__UnintendedPosition:
        return FObserveOverallPointPosition_MemPmiCrucialPositionValue__UnintendedPosition;
    case FObserveOverallPointPosition_D10inPmiCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_MemPmiCrucialPositionValue__Undefined;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_MemPm1NonCrucialPositionValue
map_D10inPm1NonCrucialPosition_to_MemPm1NonCrucialPosition(
    FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__Left:
        return FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__Left;
    case FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__Right:
        return FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__Right;
    case FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition:
        return FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__UnintendedPosition;
    case FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__Undefined;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_MemPmkNonCrucialPositionValue
map_D10inPmkNonCrucialPosition_to_MemPmkNonCrucialPosition(
    FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__Left:
        return FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__Left;
    case FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__Right:
        return FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__Right;
    case FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition:
        return FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__UnintendedPosition;
    case FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__Undefined;
    default:
        abort();
    }
}

// Operations
static void Cop1MemPmPosition(FObserveOverallPointPosition *self)
{
    if (self->D26inConPmiCrucialActivation.Value)
    {
        self->MemPmiCrucialPosition =
            map_D10inPmiCrucialPosition_to_MemPmiCrucialPosition(self->D10inPmiCrucialPosition.Value);
    }
    if (self->D27inConPm1NonCrucialActivation.Value)
    {
        self->MemPm1NonCrucialPosition =
            map_D10inPm1NonCrucialPosition_to_MemPm1NonCrucialPosition(self->D10inPm1NonCrucialPosition.Value);
    }
    if (self->D28inConPmkNonCrucialActivation.Value)
    {
        self->MemPmkNonCrucialPosition =
            map_D10inPmkNonCrucialPosition_to_MemPmkNonCrucialPosition(self->D10inPmkNonCrucialPosition.Value);
    }
}

void make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left(
    FObserveOverallPointPosition *self,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct *region)
{
    LOG("[FObserveOverallPointPosition] Entering state Left in region "
        "root__ObserveOverallPointPosition__root");
    region->state = FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left;
};

void make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right(
    FObserveOverallPointPosition *self,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct *region)
{
    LOG("[FObserveOverallPointPosition] Entering state Right in region "
        "root__ObserveOverallPointPosition__root");
    region->state = FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right;
};

void make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__NoEndPosition(
    FObserveOverallPointPosition *self,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct *region)
{
    LOG("[FObserveOverallPointPosition] Entering state NoEndPosition in region "
        "root__ObserveOverallPointPosition__root");
    region->state = FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__NoEndPosition;
};

void make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__UnintendedPosition(
    FObserveOverallPointPosition *self,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct *region)
{
    LOG("[FObserveOverallPointPosition] Entering state UnintendedPosition in "
        "region root__ObserveOverallPointPosition__root");
    region->state = FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__UnintendedPosition;
};

void make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root(
    FObserveOverallPointPosition *self,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct));

    if ((((self->D10inPm1CrucialPosition.Value == FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Left) &&
          ((self->D10inPmiCrucialPosition.Value == FObserveOverallPointPosition_D10inPmiCrucialPositionValue__Left) ||
           (!(self->D26inConPmiCrucialActivation.Value)))) &&
         ((self->D10inPm1NonCrucialPosition.Value ==
           FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__Left) ||
          (!(self->D27inConPm1NonCrucialActivation.Value)))) &&
        ((self->D10inPmkNonCrucialPosition.Value ==
          FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__Left) ||
         (!(self->D28inConPmkNonCrucialActivation.Value))))
    {
        self->D14outObservedPointPosition.Value = FObserveOverallPointPosition_D14outObservedPointPositionValue__Left;
        self->D14outObservedPointPosition.IsSignalled = true;
        self->MemPm1CrucialPosition =
            map_D10inPm1CrucialPosition_to_MemPm1CrucialPosition(self->D10inPm1CrucialPosition.Value);
        Cop1MemPmPosition(self);
        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left(self, x);
        return;
    }
    if ((((self->D10inPm1CrucialPosition.Value == FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Right) &&
          ((self->D10inPmiCrucialPosition.Value == FObserveOverallPointPosition_D10inPmiCrucialPositionValue__Right) ||
           (!(self->D26inConPmiCrucialActivation.Value)))) &&
         ((self->D10inPm1NonCrucialPosition.Value ==
           FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__Right) ||
          (!(self->D27inConPm1NonCrucialActivation.Value)))) &&
        ((self->D10inPmkNonCrucialPosition.Value ==
          FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__Right) ||
         (!(self->D28inConPmkNonCrucialActivation.Value))))
    {
        self->D14outObservedPointPosition.Value = FObserveOverallPointPosition_D14outObservedPointPositionValue__Right;
        self->D14outObservedPointPosition.IsSignalled = true;
        self->MemPm1CrucialPosition =
            map_D10inPm1CrucialPosition_to_MemPm1CrucialPosition(self->D10inPm1CrucialPosition.Value);
        Cop1MemPmPosition(self);
        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right(self, x);
        return;
    }
    if (((((self->D10inPm1CrucialPosition.Value ==
            FObserveOverallPointPosition_D10inPm1CrucialPositionValue__UnintendedPosition) ||
           (self->D10inPmiCrucialPosition.Value ==
            FObserveOverallPointPosition_D10inPmiCrucialPositionValue__UnintendedPosition)) ||
          (self->D10inPm1NonCrucialPosition.Value ==
           FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition)) ||
         (self->D10inPmkNonCrucialPosition.Value ==
          FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition)) &&
        (self->D29inConUseUnintendedPosition.Value))
    {
        self->D14outObservedPointPosition.Value =
            FObserveOverallPointPosition_D14outObservedPointPositionValue__UnintendedPosition;
        self->D14outObservedPointPosition.IsSignalled = true;
        self->MemPm1CrucialPosition =
            map_D10inPm1CrucialPosition_to_MemPm1CrucialPosition(self->D10inPm1CrucialPosition.Value);
        Cop1MemPmPosition(self);
        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__UnintendedPosition(self, x);
        return;
    }
    else
    {
        self->D14outObservedPointPosition.Value =
            FObserveOverallPointPosition_D14outObservedPointPositionValue__NoEndPosition;
        self->D14outObservedPointPosition.IsSignalled = true;
        self->MemPm1CrucialPosition =
            map_D10inPm1CrucialPosition_to_MemPm1CrucialPosition(self->D10inPm1CrucialPosition.Value);
        Cop1MemPmPosition(self);
        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__NoEndPosition(self, x);
        return;
    }
}

void make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition(
    FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *region)
{
    LOG("[FObserveOverallPointPosition] Entering state "
        "ObserveOverallPointPosition in region root");
    region->state = FObserveOverallPointPosition__root__ObserveOverallPointPosition;
    make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root(
        self, &region->ObserveOverallPointPosition.root);
};

void make_state_FObserveOverallPointPosition__root(FObserveOverallPointPosition *self,
                                                   FObserveOverallPointPosition__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveOverallPointPosition__root__state_struct));
    self->MemPm1CrucialPosition = FObserveOverallPointPosition_MemPm1CrucialPositionValue__Undefined;
    self->MemPmiCrucialPosition = FObserveOverallPointPosition_MemPmiCrucialPositionValue__Undefined;
    self->MemPm1NonCrucialPosition = FObserveOverallPointPosition_MemPm1NonCrucialPositionValue__Undefined;
    self->MemPmkNonCrucialPosition = FObserveOverallPointPosition_MemPmkNonCrucialPositionValue__Undefined;
    make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition(self, x);
    return;
}

void transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left(
    FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
}

void transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right(
    FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
}

void transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__NoEndPosition(
    FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
}

void transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__UnintendedPosition(
    FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
}

void transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root(
    FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
    switch (x->ObserveOverallPointPosition.root.state)
    {
    case FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left:
        transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left(self, x);
        break;
    case FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right:
        transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right(self, x);
        break;
    case FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__NoEndPosition:
        transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__NoEndPosition(self, x);
        break;
    case FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__UnintendedPosition:
        transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__UnintendedPosition(self,
                                                                                                                  x);
        break;
    }
}

void transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition(
    FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
    transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root(self, x);
    if (self->Change25.IsTriggered)
    {

        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition(self, x);
        return;
    }
    if (self->Change30.IsTriggered)
    {

        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition(self, x);
        return;
    }
    if (self->Change31.IsTriggered)
    {

        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition(self, x);
        return;
    }
    if (self->Change32.IsTriggered)
    {

        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition(self, x);
        return;
    }
    if (self->Change369.IsTriggered)
    {

        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition(self, x);
        return;
    }
}

void transition_from_FObserveOverallPointPosition__root(FObserveOverallPointPosition *self,
                                                        FObserveOverallPointPosition__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveOverallPointPosition__root__ObserveOverallPointPosition:
        transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition(self, x);
        break;
    }
}

static void evaluateChangeEvents(FObserveOverallPointPosition *self)
{
    self->Change25.IsTriggered =
        IsTriggered(MakeChange(self->D10inPm1CrucialPosition.IsSignalled,
                               !(self->D10inPm1CrucialPosition.Value ==
                                 map_MemPm1CrucialPosition_to_D10inPm1CrucialPosition(self->MemPm1CrucialPosition))));
    self->Change30.IsTriggered = IsTriggered(
        MakeChange(self->D10inPm1NonCrucialPosition.IsSignalled,
                   !(self->D10inPm1NonCrucialPosition.Value ==
                     map_MemPm1NonCrucialPosition_to_D10inPm1NonCrucialPosition(self->MemPm1NonCrucialPosition))));
    self->Change31.IsTriggered =
        IsTriggered(MakeChange(self->D10inPmiCrucialPosition.IsSignalled,
                               !(self->D10inPmiCrucialPosition.Value ==
                                 map_MemPmiCrucialPosition_to_D10inPmiCrucialPosition(self->MemPmiCrucialPosition))));
    self->Change32.IsTriggered = IsTriggered(
        MakeChange(self->D10inPmkNonCrucialPosition.IsSignalled,
                   !(self->D10inPmkNonCrucialPosition.Value ==
                     map_MemPmkNonCrucialPosition_to_D10inPmkNonCrucialPosition(self->MemPmkNonCrucialPosition))));
    self->Change369.IsTriggered = IsTriggered(
        OrChange(OrChange(MakeChange(self->D51inEstEfesState.IsSignalled,
                                     self->D51inEstEfesState.Value ==
                                         FObserveOverallPointPosition_D51inEstEfesStateValue__NoOperatingVoltage),
                          MakeChange(self->D51inEstEfesState.IsSignalled,
                                     self->D51inEstEfesState.Value ==
                                         FObserveOverallPointPosition_D51inEstEfesStateValue__Booting)),
                 MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value ==
                                FObserveOverallPointPosition_D51inEstEfesStateValue__FallbackMode)));
}

static void resetOutputs(FObserveOverallPointPosition *self)
{

    self->D14outObservedPointPosition.IsSignalled = false;
}

static void resetTriggers(FObserveOverallPointPosition *self)
{

    self->D10inPm1CrucialPosition.IsSignalled = false;
    self->D10inPmiCrucialPosition.IsSignalled = false;
    self->D10inPm1NonCrucialPosition.IsSignalled = false;
    self->D10inPmkNonCrucialPosition.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
    self->D26inConPmiCrucialActivation.IsSignalled = false;
    self->D27inConPm1NonCrucialActivation.IsSignalled = false;
    self->D28inConPmkNonCrucialActivation.IsSignalled = false;
    self->D29inConUseUnintendedPosition.IsSignalled = false;
}

void transition_FObserveOverallPointPosition(FObserveOverallPointPosition *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FObserveOverallPointPosition__root(self, &self->state);
    resetTriggers(self);
}

void new_FObserveOverallPointPosition(FObserveOverallPointPosition *self)
{
    make_state_FObserveOverallPointPosition__root(self, &self->state);
}
