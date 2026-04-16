
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
    case FObserveOverallPointPosition_MemPm1CrucialPositionValue__Trailed:
        return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Trailed;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_D10inPm1nCrucialPositionValue
map_MemPm1nCrucialPosition_to_D10inPm1nCrucialPosition(FObserveOverallPointPosition_MemPm1nCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_MemPm1nCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_MemPm1nCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Undefined;
    case FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Left:
        return FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Left;
    case FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Right:
        return FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Right;
    case FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Trailed:
        return FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Trailed;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue
map_MemPm2nNonCrucialPosition_to_D10inPm2nNonCrucialPosition(
    FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Undefined;
    case FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Left:
        return FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Left;
    case FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Right:
        return FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Right;
    case FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Trailed:
        return FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Trailed;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue
map_MemPm2NonCrucialPosition_to_D10inPm2NonCrucialPosition(
    FObserveOverallPointPosition_MemPm2NonCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Undefined;
    case FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Left:
        return FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Left;
    case FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Right:
        return FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Right;
    case FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Trailed:
        return FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Trailed;
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
    case FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Trailed:
        return FObserveOverallPointPosition_MemPm1CrucialPositionValue__Trailed;
    case FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_MemPm1CrucialPositionValue__Undefined;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_MemPm1nCrucialPositionValue map_D10inPm1nCrucialPosition_to_MemPm1nCrucialPosition(
    FObserveOverallPointPosition_D10inPm1nCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_MemPm1nCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_MemPm1nCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Left:
        return FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Left;
    case FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Right:
        return FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Right;
    case FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Trailed:
        return FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Trailed;
    case FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Undefined;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_MemPm2NonCrucialPositionValue
map_D10inPm2NonCrucialPosition_to_MemPm2NonCrucialPosition(
    FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Left:
        return FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Left;
    case FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Right:
        return FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Right;
    case FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Trailed:
        return FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Trailed;
    case FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Undefined;
    default:
        abort();
    }
}
static FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue
map_D10inPm2nNonCrucialPosition_to_MemPm2nNonCrucialPosition(
    FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue value)
{
    switch (value)
    {
    case FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__NULL__:
        return FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__NULL__;
    case FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__UNKNOWN__:
        return FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__UNKNOWN__;
    case FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Left:
        return FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Left;
    case FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Right:
        return FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Right;
    case FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Trailed:
        return FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Trailed;
    case FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Undefined:
        return FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Undefined;
    default:
        abort();
    }
}

// Operations
static void Cop1MemPmPosition(FObserveOverallPointPosition *self)
{
    if (self->D11inConPm1nCrucialActivation.Value)
    {
        self->MemPm1nCrucialPosition =
            map_D10inPm1nCrucialPosition_to_MemPm1nCrucialPosition(self->D10inPm1nCrucialPosition.Value);
    }
    if (self->D12inConPm2NonCrucialActivation.Value)
    {
        self->MemPm2NonCrucialPosition =
            map_D10inPm2NonCrucialPosition_to_MemPm2NonCrucialPosition(self->D10inPm2NonCrucialPosition.Value);
    }
    if (self->D13inConPm2nNonCrucialActivation.Value)
    {
        self->MemPm2nNonCrucialPosition =
            map_D10inPm2nNonCrucialPosition_to_MemPm2nNonCrucialPosition(self->D10inPm2nNonCrucialPosition.Value);
    }
}

void make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left(
    FObserveOverallPointPosition *self,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct *region)
{
    LOG("[FObserveOverallPointPosition] Entering state Left in region root__ObserveOverallPointPosition__root");
    region->state = FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left;
};

void make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right(
    FObserveOverallPointPosition *self,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct *region)
{
    LOG("[FObserveOverallPointPosition] Entering state Right in region root__ObserveOverallPointPosition__root");
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

void make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Trailed(
    FObserveOverallPointPosition *self,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct *region)
{
    LOG("[FObserveOverallPointPosition] Entering state Trailed in region root__ObserveOverallPointPosition__root");
    region->state = FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Trailed;
};

void make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root(
    FObserveOverallPointPosition *self,
    FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__state_struct));

    if ((((self->D10inPm1CrucialPosition.Value == FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Left) &&
          ((self->D10inPm1nCrucialPosition.Value == FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Left) ||
           (!(self->D11inConPm1nCrucialActivation.Value)))) &&
         ((self->D10inPm2NonCrucialPosition.Value ==
           FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Left) ||
          (!(self->D12inConPm2NonCrucialActivation.Value)))) &&
        ((self->D10inPm2nNonCrucialPosition.Value ==
          FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Left) ||
         (!(self->D13inConPm2nNonCrucialActivation.Value))))
    {
        self->D5outObservedPointPosition.Value = FObserveOverallPointPosition_D5outObservedPointPositionValue__Left;
        self->D5outObservedPointPosition.IsSignalled = true;
        self->D41outObservedPointEndPosition.Value =
            FObserveOverallPointPosition_D41outObservedPointEndPositionValue__Left;
        self->D41outObservedPointEndPosition.IsSignalled = true;
        self->MemPm1CrucialPosition =
            map_D10inPm1CrucialPosition_to_MemPm1CrucialPosition(self->D10inPm1CrucialPosition.Value);
        Cop1MemPmPosition(self);
        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Left(self, x);
        return;
    }
    if ((((self->D10inPm1CrucialPosition.Value == FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Right) &&
          ((self->D10inPm1nCrucialPosition.Value ==
            FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Right) ||
           (!(self->D11inConPm1nCrucialActivation.Value)))) &&
         ((self->D10inPm2NonCrucialPosition.Value ==
           FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Right) ||
          (!(self->D12inConPm2NonCrucialActivation.Value)))) &&
        ((self->D10inPm2nNonCrucialPosition.Value ==
          FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Right) ||
         (!(self->D13inConPm2nNonCrucialActivation.Value))))
    {
        self->D5outObservedPointPosition.Value = FObserveOverallPointPosition_D5outObservedPointPositionValue__Right;
        self->D5outObservedPointPosition.IsSignalled = true;
        self->D41outObservedPointEndPosition.Value =
            FObserveOverallPointPosition_D41outObservedPointEndPositionValue__Right;
        self->D41outObservedPointEndPosition.IsSignalled = true;
        self->MemPm1CrucialPosition =
            map_D10inPm1CrucialPosition_to_MemPm1CrucialPosition(self->D10inPm1CrucialPosition.Value);
        Cop1MemPmPosition(self);
        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Right(self, x);
        return;
    }
    if (((((self->D10inPm1CrucialPosition.Value ==
            FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Trailed) ||
           (self->D10inPm1nCrucialPosition.Value ==
            FObserveOverallPointPosition_D10inPm1nCrucialPositionValue__Trailed)) ||
          (self->D10inPm2NonCrucialPosition.Value ==
           FObserveOverallPointPosition_D10inPm2NonCrucialPositionValue__Trailed)) ||
         (self->D10inPm2nNonCrucialPosition.Value ==
          FObserveOverallPointPosition_D10inPm2nNonCrucialPositionValue__Trailed)) &&
        (self->D14inConUseTrailing.Value))
    {
        self->D5outObservedPointPosition.Value = FObserveOverallPointPosition_D5outObservedPointPositionValue__Trailed;
        self->D5outObservedPointPosition.IsSignalled = true;
        self->MemPm1CrucialPosition =
            map_D10inPm1CrucialPosition_to_MemPm1CrucialPosition(self->D10inPm1CrucialPosition.Value);
        Cop1MemPmPosition(self);
        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Trailed(self, x);
        return;
    }
    else
    {
        self->D5outObservedPointPosition.Value =
            FObserveOverallPointPosition_D5outObservedPointPositionValue__NoEndPosition;
        self->D5outObservedPointPosition.IsSignalled = true;
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
    LOG("[FObserveOverallPointPosition] Entering state ObserveOverallPointPosition in region root");
    region->state = FObserveOverallPointPosition__root__ObserveOverallPointPosition;
    make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root(
        self, &region->ObserveOverallPointPosition.root);
};

void make_state_FObserveOverallPointPosition__root(FObserveOverallPointPosition *self,
                                                   FObserveOverallPointPosition__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveOverallPointPosition__root__state_struct));
    self->MemPm1CrucialPosition = FObserveOverallPointPosition_MemPm1CrucialPositionValue__Undefined;
    self->MemPm1nCrucialPosition = FObserveOverallPointPosition_MemPm1nCrucialPositionValue__Undefined;
    self->MemPm2NonCrucialPosition = FObserveOverallPointPosition_MemPm2NonCrucialPositionValue__Undefined;
    self->MemPm2nNonCrucialPosition = FObserveOverallPointPosition_MemPm2nNonCrucialPositionValue__Undefined;
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

void transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Trailed(
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
    case FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Trailed:
        transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root__Trailed(self, x);
        break;
    }
}

void transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition(
    FObserveOverallPointPosition *self, FObserveOverallPointPosition__root__state_struct *x)
{
    transition_from_FObserveOverallPointPosition__root__ObserveOverallPointPosition__root(self, x);
    if (self->Change23.IsTriggered)
    {

        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition(self, x);
        return;
    }
    if (self->Change28.IsTriggered)
    {

        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition(self, x);
        return;
    }
    if (self->Change29.IsTriggered)
    {

        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition(self, x);
        return;
    }
    if (self->Change30.IsTriggered)
    {

        make_state_FObserveOverallPointPosition__root__ObserveOverallPointPosition(self, x);
        return;
    }
    if (self->Change388.IsTriggered)
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
    self->Change23.IsTriggered =
        IsTriggered(MakeChange(self->D10inPm1CrucialPosition.IsSignalled,
                               !(self->D10inPm1CrucialPosition.Value ==
                                 map_MemPm1CrucialPosition_to_D10inPm1CrucialPosition(self->MemPm1CrucialPosition))));
    self->Change28.IsTriggered = IsTriggered(
        MakeChange(self->D10inPm1nCrucialPosition.IsSignalled,
                   !(self->D10inPm1nCrucialPosition.Value ==
                     map_MemPm1nCrucialPosition_to_D10inPm1nCrucialPosition(self->MemPm1nCrucialPosition))));
    self->Change29.IsTriggered = IsTriggered(
        MakeChange(self->D10inPm2NonCrucialPosition.IsSignalled,
                   !(self->D10inPm2NonCrucialPosition.Value ==
                     map_MemPm2NonCrucialPosition_to_D10inPm2NonCrucialPosition(self->MemPm2NonCrucialPosition))));
    self->Change30.IsTriggered = IsTriggered(
        MakeChange(self->D10inPm2nNonCrucialPosition.IsSignalled,
                   !(self->D10inPm2nNonCrucialPosition.Value ==
                     map_MemPm2nNonCrucialPosition_to_D10inPm2nNonCrucialPosition(self->MemPm2nNonCrucialPosition))));
    self->Change388.IsTriggered = IsTriggered(
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

    self->D5outObservedPointPosition.IsSignalled = false;
    self->D41outObservedPointEndPosition.IsSignalled = false;
}

static void resetTriggers(FObserveOverallPointPosition *self)
{

    self->D10inPm1CrucialPosition.IsSignalled = false;
    self->D10inPm1nCrucialPosition.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
    self->D11inConPm1nCrucialActivation.IsSignalled = false;
    self->D10inPm2nNonCrucialPosition.IsSignalled = false;
    self->D10inPm2NonCrucialPosition.IsSignalled = false;
    self->D14inConUseTrailing.IsSignalled = false;
    self->D12inConPm2NonCrucialActivation.IsSignalled = false;
    self->D13inConPm2nNonCrucialActivation.IsSignalled = false;
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

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemPoint/FObserveOverallPointPosition.c"
#endif
