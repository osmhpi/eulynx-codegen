
#include "FObserveDegradedPointPosition.h"

// Value Conversion Functions

static FObserveDegradedPointPosition_D10inPm1CrucialPositionValue
map_D10inPmiCrucialPosition_to_D10inPm1CrucialPosition(
    FObserveDegradedPointPosition_D10inPmiCrucialPositionValue value) {
  switch (value) {
  case FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__NULL__:
    return FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__NULL__;
  case FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__UNKNOWN__:
    return FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__UNKNOWN__;
  case FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__Left:
    return FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Left;
  case FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__Right:
    return FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Right;
  case FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__NoEndPosition:
    return FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__NoEndPosition;
  case FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__UnintendedPosition:
    return FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__UnintendedPosition;
  default:
    abort();
  }
}
static FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue
map_D10inPm1CrucialPosition_to_D10inPm1NonCrucialPosition(
    FObserveDegradedPointPosition_D10inPm1CrucialPositionValue value) {
  switch (value) {
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__NULL__:
    return FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NULL__;
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__UNKNOWN__:
    return FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UNKNOWN__;
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Left:
    return FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__Left;
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Right:
    return FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__Right;
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__NoEndPosition:
    return FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NoEndPosition;
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__UnintendedPosition:
    return FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition;
  default:
    abort();
  }
}
static FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue
map_D10inPm1CrucialPosition_to_D10inPmkNonCrucialPosition(
    FObserveDegradedPointPosition_D10inPm1CrucialPositionValue value) {
  switch (value) {
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__NULL__:
    return FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NULL__;
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__UNKNOWN__:
    return FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UNKNOWN__;
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Left:
    return FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__Left;
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Right:
    return FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__Right;
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__NoEndPosition:
    return FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NoEndPosition;
  case FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__UnintendedPosition:
    return FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition;
  default:
    abort();
  }
}

// Operations

void make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct
        *region) {
  LOG("[FObserveDegradedPointPosition] Entering state WaitingForInitialisation "
      "in region root__ObserveDegradedPointPosition__root");
  region->state =
      FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation;
};

void make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct
        *region) {
  LOG("[FObserveDegradedPointPosition] Entering state DegradedRight in region "
      "root__ObserveDegradedPointPosition__root");
  region->state =
      FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight;
};

void make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct
        *region) {
  LOG("[FObserveDegradedPointPosition] Entering state NotDegraded in region "
      "root__ObserveDegradedPointPosition__root");
  region->state =
      FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded;
};

void make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct
        *region) {
  LOG("[FObserveDegradedPointPosition] Entering state DegradedLeft in region "
      "root__ObserveDegradedPointPosition__root");
  region->state =
      FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft;
};

void make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct
        *region) {
  LOG("[FObserveDegradedPointPosition] Entering state DegradedDenied in region "
      "root__ObserveDegradedPointPosition__root");
  region->state =
      FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied;
};

void make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct
        *x) {
  memset(
      x, 0,
      sizeof(
          FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__state_struct));

  make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation(
      self, x);
  return;
}

void make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *region) {
  LOG("[FObserveDegradedPointPosition] Entering state "
      "ObserveDegradedPointPosition in region root");
  region->state =
      FObserveDegradedPointPosition__root__ObserveDegradedPointPosition;
  make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root(
      self, &region->ObserveDegradedPointPosition.root);
};

void make_state_FObserveDegradedPointPosition__root(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {
  memset(x, 0, sizeof(FObserveDegradedPointPosition__root__state_struct));

  make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition(
      self, x);
  return;
}

void transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {

  if (self->Change360.IsTriggered) {
    self->D17outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__Undefined;
    self->D17outObservedDegradedPointPosition.IsSignalled = true;
    if ((!(self->D27inConPm1NonCrucialActivation.Value)) &&
        (!(self->D28inConPmkNonCrucialActivation.Value))) {
      self->D17outObservedDegradedPointPosition.Value =
          FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedDenied;
      self->D17outObservedDegradedPointPosition.IsSignalled = true;
      make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied(
          self, &x->ObserveDegradedPointPosition.root);
      return;
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
           FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition)))) {
      self->D17outObservedDegradedPointPosition.Value =
          FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedLeft;
      self->D17outObservedDegradedPointPosition.IsSignalled = true;
      make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
          self, &x->ObserveDegradedPointPosition.root);
      return;
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
           FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition)))) {
      self->D17outObservedDegradedPointPosition.Value =
          FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedRight;
      self->D17outObservedDegradedPointPosition.IsSignalled = true;
      make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight(
          self, &x->ObserveDegradedPointPosition.root);
      return;
    } else {
      self->D17outObservedDegradedPointPosition.Value =
          FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__NotDegraded;
      self->D17outObservedDegradedPointPosition.IsSignalled = true;
      make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
          self, &x->ObserveDegradedPointPosition.root);
      return;
    }
  }
}

void transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {

  if (self->Change10.IsTriggered) {
    self->D17outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__NotDegraded;
    self->D17outObservedDegradedPointPosition.IsSignalled = true;
    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
        self, &x->ObserveDegradedPointPosition.root);
    return;
  }
  if (self->Change26.IsTriggered) {
    self->D17outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedLeft;
    self->D17outObservedDegradedPointPosition.IsSignalled = true;
    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
        self, &x->ObserveDegradedPointPosition.root);
    return;
  }
}

void transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {

  if (self->Change27.IsTriggered) {
    self->D17outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedLeft;
    self->D17outObservedDegradedPointPosition.IsSignalled = true;
    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
        self, &x->ObserveDegradedPointPosition.root);
    return;
  }
  if (self->Change28.IsTriggered) {
    self->D17outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedRight;
    self->D17outObservedDegradedPointPosition.IsSignalled = true;
    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight(
        self, &x->ObserveDegradedPointPosition.root);
    return;
  }
}

void transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {

  if (self->Change9.IsTriggered) {
    self->D17outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__NotDegraded;
    self->D17outObservedDegradedPointPosition.IsSignalled = true;
    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
        self, &x->ObserveDegradedPointPosition.root);
    return;
  }
  if (self->Change29.IsTriggered) {
    self->D17outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedRight;
    self->D17outObservedDegradedPointPosition.IsSignalled = true;
    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight(
        self, &x->ObserveDegradedPointPosition.root);
    return;
  }
}

void transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {}

void transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {
  switch (x->ObserveDegradedPointPosition.root.state) {
  case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation:
    transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__WaitingForInitialisation(
        self, x);
    break;
  case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight:
    transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight(
        self, x);
    break;
  case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded:
    transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
        self, x);
    break;
  case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft:
    transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
        self, x);
    break;
  case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied:
    transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied(
        self, x);
    break;
  }
}

void transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {
  transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root(
      self, x);
  if (self->Change374.IsTriggered) {

    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition(
        self, x);
    return;
  }
}

void transition_from_FObserveDegradedPointPosition__root(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {
  switch (x->state) {
  case FObserveDegradedPointPosition__root__ObserveDegradedPointPosition:
    transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition(
        self, x);
    break;
  }
}

static void evaluateChangeEvents(FObserveDegradedPointPosition *self) {
  self->Change360.IsTriggered = IsTriggered(MakeChange(
      self->D51inEstEfesState.IsSignalled,
      self->D51inEstEfesState.Value ==
          FObserveDegradedPointPosition_D51inEstEfesStateValue__Initialising));
  self->Change10.IsTriggered = IsTriggered(OrChange(
      OrChange(
          OrChange(
              OrChange(
                  MakeChange(
                      self->D14inObservedPointPosition.IsSignalled,
                      self->D14inObservedPointPosition.Value ==
                          FObserveDegradedPointPosition_D14inObservedPointPositionValue__Left),
                  MakeChange(
                      self->D14inObservedPointPosition.IsSignalled,
                      self->D14inObservedPointPosition.Value ==
                          FObserveDegradedPointPosition_D14inObservedPointPositionValue__Right)),
              AndChange(
                  MakeChange(
                      self->D10inPm1CrucialPosition.IsSignalled ||
                          self->D10inPmiCrucialPosition.IsSignalled,
                      !(self->D10inPm1CrucialPosition.Value ==
                        map_D10inPmiCrucialPosition_to_D10inPm1CrucialPosition(
                            self->D10inPmiCrucialPosition.Value))),
                  MakeChange(self->D26inConPmiCrucialActivation.IsSignalled,
                             self->D26inConPmiCrucialActivation.Value))),
          AndChange(
              AndChange(
                  AndChange(
                      MakeChange(
                          self->D10inPm1NonCrucialPosition.IsSignalled ||
                              self->D10inPm1CrucialPosition.IsSignalled,
                          !(self->D10inPm1NonCrucialPosition.Value ==
                            map_D10inPm1CrucialPosition_to_D10inPm1NonCrucialPosition(
                                self->D10inPm1CrucialPosition.Value))),
                      MakeChange(
                          self->D10inPm1NonCrucialPosition.IsSignalled,
                          !(self->D10inPm1NonCrucialPosition.Value ==
                            FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition))),
                  MakeChange(
                      self->D10inPm1NonCrucialPosition.IsSignalled,
                      !(self->D10inPm1NonCrucialPosition.Value ==
                        FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NoEndPosition))),
              MakeChange(self->D27inConPm1NonCrucialActivation.IsSignalled,
                         self->D27inConPm1NonCrucialActivation.Value))),
      AndChange(
          AndChange(
              AndChange(
                  MakeChange(
                      self->D10inPmkNonCrucialPosition.IsSignalled ||
                          self->D10inPm1CrucialPosition.IsSignalled,
                      !(self->D10inPmkNonCrucialPosition.Value ==
                        map_D10inPm1CrucialPosition_to_D10inPmkNonCrucialPosition(
                            self->D10inPm1CrucialPosition.Value))),
                  MakeChange(
                      self->D10inPmkNonCrucialPosition.IsSignalled,
                      !(self->D10inPmkNonCrucialPosition.Value ==
                        FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition))),
              MakeChange(
                  self->D10inPmkNonCrucialPosition.IsSignalled,
                  !(self->D10inPmkNonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NoEndPosition))),
          MakeChange(self->D28inConPmkNonCrucialActivation.IsSignalled,
                     self->D28inConPmkNonCrucialActivation.Value))));
  self->Change26.IsTriggered = IsTriggered(AndChange(
      AndChange(
          MakeChange(
              self->D10inPm1CrucialPosition.IsSignalled,
              self->D10inPm1CrucialPosition.Value ==
                  FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Left),
          OrChange(
              MakeChange(
                  self->D10inPmiCrucialPosition.IsSignalled,
                  self->D10inPmiCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__Left),
              NegateChange(
                  MakeChange(self->D26inConPmiCrucialActivation.IsSignalled,
                             self->D26inConPmiCrucialActivation.Value)))),
      OrChange(
          OrChange(
              MakeChange(
                  self->D10inPmkNonCrucialPosition.IsSignalled,
                  self->D10inPmkNonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NoEndPosition),
              MakeChange(
                  self->D10inPmkNonCrucialPosition.IsSignalled,
                  self->D10inPmkNonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition)),
          OrChange(
              MakeChange(
                  self->D10inPm1NonCrucialPosition.IsSignalled,
                  self->D10inPm1NonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NoEndPosition),
              MakeChange(
                  self->D10inPm1NonCrucialPosition.IsSignalled,
                  self->D10inPm1NonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition)))));
  self->Change27.IsTriggered = IsTriggered(AndChange(
      AndChange(
          MakeChange(
              self->D10inPm1CrucialPosition.IsSignalled,
              self->D10inPm1CrucialPosition.Value ==
                  FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Left),
          OrChange(
              MakeChange(
                  self->D10inPmiCrucialPosition.IsSignalled,
                  self->D10inPmiCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__Left),
              NegateChange(
                  MakeChange(self->D26inConPmiCrucialActivation.IsSignalled,
                             self->D26inConPmiCrucialActivation.Value)))),
      OrChange(
          AndChange(
              OrChange(
                  MakeChange(
                      self->D10inPmkNonCrucialPosition.IsSignalled,
                      self->D10inPmkNonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NoEndPosition),
                  MakeChange(
                      self->D10inPmkNonCrucialPosition.IsSignalled,
                      self->D10inPmkNonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition)),
              MakeChange(
                  self->D10inPm1NonCrucialPosition.IsSignalled,
                  !(self->D10inPm1NonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__Right))),
          AndChange(
              OrChange(
                  MakeChange(
                      self->D10inPm1NonCrucialPosition.IsSignalled,
                      self->D10inPm1NonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NoEndPosition),
                  MakeChange(
                      self->D10inPm1NonCrucialPosition.IsSignalled,
                      self->D10inPm1NonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition)),
              MakeChange(
                  self->D10inPmkNonCrucialPosition.IsSignalled,
                  !(self->D10inPmkNonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__Right))))));
  self->Change28.IsTriggered = IsTriggered(AndChange(
      AndChange(
          MakeChange(
              self->D10inPm1CrucialPosition.IsSignalled,
              self->D10inPm1CrucialPosition.Value ==
                  FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Right),
          OrChange(
              MakeChange(
                  self->D10inPmiCrucialPosition.IsSignalled,
                  self->D10inPmiCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__Right),
              NegateChange(
                  MakeChange(self->D26inConPmiCrucialActivation.IsSignalled,
                             self->D26inConPmiCrucialActivation.Value)))),
      OrChange(
          AndChange(
              OrChange(
                  MakeChange(
                      self->D10inPmkNonCrucialPosition.IsSignalled,
                      self->D10inPmkNonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NoEndPosition),
                  MakeChange(
                      self->D10inPmkNonCrucialPosition.IsSignalled,
                      self->D10inPmkNonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition)),
              MakeChange(
                  self->D10inPm1NonCrucialPosition.IsSignalled,
                  !(self->D10inPm1NonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__Left))),
          AndChange(
              OrChange(
                  MakeChange(
                      self->D10inPm1NonCrucialPosition.IsSignalled,
                      self->D10inPm1NonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NoEndPosition),
                  MakeChange(
                      self->D10inPm1NonCrucialPosition.IsSignalled,
                      self->D10inPm1NonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition)),
              MakeChange(
                  self->D10inPmkNonCrucialPosition.IsSignalled,
                  !(self->D10inPmkNonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__Left))))));
  self->Change9.IsTriggered = IsTriggered(OrChange(
      OrChange(
          OrChange(
              OrChange(
                  MakeChange(
                      self->D14inObservedPointPosition.IsSignalled,
                      self->D14inObservedPointPosition.Value ==
                          FObserveDegradedPointPosition_D14inObservedPointPositionValue__Left),
                  MakeChange(
                      self->D14inObservedPointPosition.IsSignalled,
                      self->D14inObservedPointPosition.Value ==
                          FObserveDegradedPointPosition_D14inObservedPointPositionValue__Right)),
              AndChange(
                  MakeChange(
                      self->D10inPm1CrucialPosition.IsSignalled ||
                          self->D10inPmiCrucialPosition.IsSignalled,
                      !(self->D10inPm1CrucialPosition.Value ==
                        map_D10inPmiCrucialPosition_to_D10inPm1CrucialPosition(
                            self->D10inPmiCrucialPosition.Value))),
                  MakeChange(self->D26inConPmiCrucialActivation.IsSignalled,
                             self->D26inConPmiCrucialActivation.Value))),
          AndChange(
              AndChange(
                  AndChange(
                      MakeChange(
                          self->D10inPm1NonCrucialPosition.IsSignalled ||
                              self->D10inPm1CrucialPosition.IsSignalled,
                          !(self->D10inPm1NonCrucialPosition.Value ==
                            map_D10inPm1CrucialPosition_to_D10inPm1NonCrucialPosition(
                                self->D10inPm1CrucialPosition.Value))),
                      MakeChange(
                          self->D10inPm1NonCrucialPosition.IsSignalled,
                          !(self->D10inPm1NonCrucialPosition.Value ==
                            FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition))),
                  MakeChange(
                      self->D10inPm1NonCrucialPosition.IsSignalled,
                      !(self->D10inPm1NonCrucialPosition.Value ==
                        FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NoEndPosition))),
              MakeChange(self->D27inConPm1NonCrucialActivation.IsSignalled,
                         self->D27inConPm1NonCrucialActivation.Value))),
      AndChange(
          AndChange(
              AndChange(
                  MakeChange(
                      self->D10inPmkNonCrucialPosition.IsSignalled ||
                          self->D10inPm1CrucialPosition.IsSignalled,
                      !(self->D10inPmkNonCrucialPosition.Value ==
                        map_D10inPm1CrucialPosition_to_D10inPmkNonCrucialPosition(
                            self->D10inPm1CrucialPosition.Value))),
                  MakeChange(
                      self->D10inPmkNonCrucialPosition.IsSignalled,
                      !(self->D10inPmkNonCrucialPosition.Value ==
                        FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition))),
              MakeChange(
                  self->D10inPmkNonCrucialPosition.IsSignalled,
                  !(self->D10inPmkNonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NoEndPosition))),
          MakeChange(self->D28inConPmkNonCrucialActivation.IsSignalled,
                     self->D28inConPmkNonCrucialActivation.Value))));
  self->Change29.IsTriggered = IsTriggered(AndChange(
      AndChange(
          MakeChange(
              self->D10inPm1CrucialPosition.IsSignalled,
              self->D10inPm1CrucialPosition.Value ==
                  FObserveDegradedPointPosition_D10inPm1CrucialPositionValue__Right),
          OrChange(
              MakeChange(
                  self->D10inPmiCrucialPosition.IsSignalled,
                  self->D10inPmiCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPmiCrucialPositionValue__Right),
              NegateChange(
                  MakeChange(self->D26inConPmiCrucialActivation.IsSignalled,
                             self->D26inConPmiCrucialActivation.Value)))),
      OrChange(
          OrChange(
              MakeChange(
                  self->D10inPmkNonCrucialPosition.IsSignalled,
                  self->D10inPmkNonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__NoEndPosition),
              MakeChange(
                  self->D10inPmkNonCrucialPosition.IsSignalled,
                  self->D10inPmkNonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue__UnintendedPosition)),
          OrChange(
              MakeChange(
                  self->D10inPm1NonCrucialPosition.IsSignalled,
                  self->D10inPm1NonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__NoEndPosition),
              MakeChange(
                  self->D10inPm1NonCrucialPosition.IsSignalled,
                  self->D10inPm1NonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue__UnintendedPosition)))));
  self->Change374.IsTriggered = IsTriggered(OrChange(
      OrChange(
          MakeChange(
              self->D51inEstEfesState.IsSignalled,
              self->D51inEstEfesState.Value ==
                  FObserveDegradedPointPosition_D51inEstEfesStateValue__NoOperatingVoltage),
          MakeChange(
              self->D51inEstEfesState.IsSignalled,
              self->D51inEstEfesState.Value ==
                  FObserveDegradedPointPosition_D51inEstEfesStateValue__Booting)),
      MakeChange(
          self->D51inEstEfesState.IsSignalled,
          self->D51inEstEfesState.Value ==
              FObserveDegradedPointPosition_D51inEstEfesStateValue__FallbackMode)));
}

static void resetOutputs(FObserveDegradedPointPosition *self) {

  self->D17outObservedDegradedPointPosition.IsSignalled = false;
}

static void resetTriggers(FObserveDegradedPointPosition *self) {

  self->D10inPm1CrucialPosition.IsSignalled = false;
  self->D10inPmiCrucialPosition.IsSignalled = false;
  self->D10inPm1NonCrucialPosition.IsSignalled = false;
  self->D10inPmkNonCrucialPosition.IsSignalled = false;
  self->D51inEstEfesState.IsSignalled = false;
  self->D26inConPmiCrucialActivation.IsSignalled = false;
  self->D27inConPm1NonCrucialActivation.IsSignalled = false;
  self->D28inConPmkNonCrucialActivation.IsSignalled = false;
  self->D14inObservedPointPosition.IsSignalled = false;
}

void transition_FObserveDegradedPointPosition(
    FObserveDegradedPointPosition *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_FObserveDegradedPointPosition__root(self, &self->state);
  resetTriggers(self);
}

void new_FObserveDegradedPointPosition(FObserveDegradedPointPosition *self) {
  make_state_FObserveDegradedPointPosition__root(self, &self->state);
}
