
#include "FObserveDegradedPointPosition.h"

// Value Conversion Functions

static FObserveDegradedPointPosition_D22inPm1CrucialPositionValue
map_D23inPm1nCrucialPosition_to_D22inPm1CrucialPosition(
    FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue value) {
  switch (value) {
  case FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__NULL__:
    return FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__NULL__;
  case FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__UNKNOWN__:
    return FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__UNKNOWN__;
  case FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__Left:
    return FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Left;
  case FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__Right:
    return FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Right;
  case FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__NoEndPosition:
    return FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__NoEndPosition;
  case FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__UnintendedPosition:
    return FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__UnintendedPosition;
  default:
    abort();
  }
}
static FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue
map_D22inPm1CrucialPosition_to_D24inPm2NonCrucialPosition(
    FObserveDegradedPointPosition_D22inPm1CrucialPositionValue value) {
  switch (value) {
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__NULL__:
    return FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NULL__;
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__UNKNOWN__:
    return FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UNKNOWN__;
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Left:
    return FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__Left;
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Right:
    return FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__Right;
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__NoEndPosition:
    return FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NoEndPosition;
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__UnintendedPosition:
    return FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition;
  default:
    abort();
  }
}
static FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue
map_D22inPm1CrucialPosition_to_D25inPm2nNonCrucialPosition(
    FObserveDegradedPointPosition_D22inPm1CrucialPositionValue value) {
  switch (value) {
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__NULL__:
    return FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NULL__;
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__UNKNOWN__:
    return FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UNKNOWN__;
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Left:
    return FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__Left;
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Right:
    return FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__Right;
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__NoEndPosition:
    return FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NoEndPosition;
  case FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__UnintendedPosition:
    return FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UnintendedPosition;
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

  if (self->Change376.IsTriggered) {
    self->D30outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__Undefined;
    self->D30outObservedDegradedPointPosition.IsSignalled = true;
    if ((!(self->D27inConPm2NonCrucialActivation.Value)) &&
        (!(self->D28inConPm2nNonCrucialActivation.Value))) {
      self->D30outObservedDegradedPointPosition.Value =
          FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__DegradedDenied;
      self->D30outObservedDegradedPointPosition.IsSignalled = true;
      make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedDenied(
          self, &x->ObserveDegradedPointPosition.root);
      return;
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
           FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition)))) {
      self->D30outObservedDegradedPointPosition.Value =
          FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__DegradedLeft;
      self->D30outObservedDegradedPointPosition.IsSignalled = true;
      make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
          self, &x->ObserveDegradedPointPosition.root);
      return;
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
           FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition)))) {
      self->D30outObservedDegradedPointPosition.Value =
          FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__DegradedRight;
      self->D30outObservedDegradedPointPosition.IsSignalled = true;
      make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight(
          self, &x->ObserveDegradedPointPosition.root);
      return;
    } else {
      self->D30outObservedDegradedPointPosition.Value =
          FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__NotDegraded;
      self->D30outObservedDegradedPointPosition.IsSignalled = true;
      make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
          self, &x->ObserveDegradedPointPosition.root);
      return;
    }
  }
}

void transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {

  if (self->Change9.IsTriggered) {
    self->D30outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__NotDegraded;
    self->D30outObservedDegradedPointPosition.IsSignalled = true;
    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
        self, &x->ObserveDegradedPointPosition.root);
    return;
  }
  if (self->Change186.IsTriggered) {
    self->D30outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__DegradedLeft;
    self->D30outObservedDegradedPointPosition.IsSignalled = true;
    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
        self, &x->ObserveDegradedPointPosition.root);
    return;
  }
}

void transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {

  if (self->Change187.IsTriggered) {
    self->D30outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__DegradedLeft;
    self->D30outObservedDegradedPointPosition.IsSignalled = true;
    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
        self, &x->ObserveDegradedPointPosition.root);
    return;
  }
  if (self->Change188.IsTriggered) {
    self->D30outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__DegradedRight;
    self->D30outObservedDegradedPointPosition.IsSignalled = true;
    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedRight(
        self, &x->ObserveDegradedPointPosition.root);
    return;
  }
}

void transition_from_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__DegradedLeft(
    FObserveDegradedPointPosition *self,
    FObserveDegradedPointPosition__root__state_struct *x) {

  if (self->Change10.IsTriggered) {
    self->D30outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__NotDegraded;
    self->D30outObservedDegradedPointPosition.IsSignalled = true;
    make_state_FObserveDegradedPointPosition__root__ObserveDegradedPointPosition__root__NotDegraded(
        self, &x->ObserveDegradedPointPosition.root);
    return;
  }
  if (self->Change189.IsTriggered) {
    self->D30outObservedDegradedPointPosition.Value =
        FObserveDegradedPointPosition_D30outObservedDegradedPointPositionValue__DegradedRight;
    self->D30outObservedDegradedPointPosition.IsSignalled = true;
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
  if (self->Change391.IsTriggered) {

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
  self->Change376.IsTriggered = IsTriggered(MakeChange(
      self->D51inEstEfesState.IsSignalled,
      self->D51inEstEfesState.Value ==
          FObserveDegradedPointPosition_D51inEstEfesStateValue__Initialising));
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
                      self->D22inPm1CrucialPosition.IsSignalled ||
                          self->D23inPm1nCrucialPosition.IsSignalled,
                      !(self->D22inPm1CrucialPosition.Value ==
                        map_D23inPm1nCrucialPosition_to_D22inPm1CrucialPosition(
                            self->D23inPm1nCrucialPosition.Value))),
                  MakeChange(self->D26inConPm1nCrucialActivation.IsSignalled,
                             self->D26inConPm1nCrucialActivation.Value))),
          AndChange(
              AndChange(
                  AndChange(
                      MakeChange(
                          self->D24inPm2NonCrucialPosition.IsSignalled ||
                              self->D22inPm1CrucialPosition.IsSignalled,
                          !(self->D24inPm2NonCrucialPosition.Value ==
                            map_D22inPm1CrucialPosition_to_D24inPm2NonCrucialPosition(
                                self->D22inPm1CrucialPosition.Value))),
                      MakeChange(
                          self->D24inPm2NonCrucialPosition.IsSignalled,
                          !(self->D24inPm2NonCrucialPosition.Value ==
                            FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition))),
                  MakeChange(
                      self->D24inPm2NonCrucialPosition.IsSignalled,
                      !(self->D24inPm2NonCrucialPosition.Value ==
                        FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NoEndPosition))),
              MakeChange(self->D27inConPm2NonCrucialActivation.IsSignalled,
                         self->D27inConPm2NonCrucialActivation.Value))),
      AndChange(
          AndChange(
              AndChange(
                  MakeChange(
                      self->D25inPm2nNonCrucialPosition
                              .IsSignalled ||
                          self->D22inPm1CrucialPosition
                              .IsSignalled,
                      !(self->D25inPm2nNonCrucialPosition.Value ==
                        map_D22inPm1CrucialPosition_to_D25inPm2nNonCrucialPosition(
                            self->D22inPm1CrucialPosition.Value))),
                  MakeChange(
                      self->D25inPm2nNonCrucialPosition.IsSignalled,
                      !(self->D25inPm2nNonCrucialPosition.Value ==
                        FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UnintendedPosition))),
              MakeChange(
                  self->D25inPm2nNonCrucialPosition.IsSignalled,
                  !(self->D25inPm2nNonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NoEndPosition))),
          MakeChange(self->D28inConPm2nNonCrucialActivation.IsSignalled,
                     self->D28inConPm2nNonCrucialActivation.Value))));
  self->Change186.IsTriggered = IsTriggered(AndChange(
      AndChange(
          MakeChange(
              self->D22inPm1CrucialPosition.IsSignalled,
              self->D22inPm1CrucialPosition.Value ==
                  FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Left),
          OrChange(
              MakeChange(
                  self->D23inPm1nCrucialPosition.IsSignalled,
                  self->D23inPm1nCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__Left),
              NegateChange(
                  MakeChange(self->D26inConPm1nCrucialActivation.IsSignalled,
                             self->D26inConPm1nCrucialActivation.Value)))),
      OrChange(
          OrChange(
              MakeChange(
                  self->D25inPm2nNonCrucialPosition.IsSignalled,
                  self->D25inPm2nNonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NoEndPosition),
              MakeChange(
                  self->D25inPm2nNonCrucialPosition.IsSignalled,
                  self->D25inPm2nNonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UnintendedPosition)),
          OrChange(
              MakeChange(
                  self->D24inPm2NonCrucialPosition.IsSignalled,
                  self->D24inPm2NonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NoEndPosition),
              MakeChange(
                  self->D24inPm2NonCrucialPosition.IsSignalled,
                  self->D24inPm2NonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition)))));
  self->Change187.IsTriggered = IsTriggered(AndChange(
      AndChange(
          MakeChange(
              self->D22inPm1CrucialPosition.IsSignalled,
              self->D22inPm1CrucialPosition.Value ==
                  FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Left),
          OrChange(
              MakeChange(
                  self->D23inPm1nCrucialPosition.IsSignalled,
                  self->D23inPm1nCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__Left),
              NegateChange(
                  MakeChange(self->D26inConPm1nCrucialActivation.IsSignalled,
                             self->D26inConPm1nCrucialActivation.Value)))),
      OrChange(
          AndChange(
              OrChange(
                  MakeChange(
                      self->D25inPm2nNonCrucialPosition.IsSignalled,
                      self->D25inPm2nNonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NoEndPosition),
                  MakeChange(
                      self->D25inPm2nNonCrucialPosition.IsSignalled,
                      self->D25inPm2nNonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UnintendedPosition)),
              MakeChange(
                  self->D24inPm2NonCrucialPosition.IsSignalled,
                  !(self->D24inPm2NonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__Right))),
          AndChange(
              OrChange(
                  MakeChange(
                      self->D24inPm2NonCrucialPosition.IsSignalled,
                      self->D24inPm2NonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NoEndPosition),
                  MakeChange(
                      self->D24inPm2NonCrucialPosition.IsSignalled,
                      self->D24inPm2NonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition)),
              MakeChange(
                  self->D25inPm2nNonCrucialPosition.IsSignalled,
                  !(self->D25inPm2nNonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__Right))))));
  self->Change188.IsTriggered = IsTriggered(AndChange(
      AndChange(
          MakeChange(
              self->D22inPm1CrucialPosition.IsSignalled,
              self->D22inPm1CrucialPosition.Value ==
                  FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Right),
          OrChange(
              MakeChange(
                  self->D23inPm1nCrucialPosition.IsSignalled,
                  self->D23inPm1nCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__Right),
              NegateChange(
                  MakeChange(self->D26inConPm1nCrucialActivation.IsSignalled,
                             self->D26inConPm1nCrucialActivation.Value)))),
      OrChange(
          AndChange(
              OrChange(
                  MakeChange(
                      self->D25inPm2nNonCrucialPosition.IsSignalled,
                      self->D25inPm2nNonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NoEndPosition),
                  MakeChange(
                      self->D25inPm2nNonCrucialPosition.IsSignalled,
                      self->D25inPm2nNonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UnintendedPosition)),
              MakeChange(
                  self->D24inPm2NonCrucialPosition.IsSignalled,
                  !(self->D24inPm2NonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__Left))),
          AndChange(
              OrChange(
                  MakeChange(
                      self->D24inPm2NonCrucialPosition.IsSignalled,
                      self->D24inPm2NonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NoEndPosition),
                  MakeChange(
                      self->D24inPm2NonCrucialPosition.IsSignalled,
                      self->D24inPm2NonCrucialPosition.Value ==
                          FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition)),
              MakeChange(
                  self->D25inPm2nNonCrucialPosition.IsSignalled,
                  !(self->D25inPm2nNonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__Left))))));
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
                      self->D22inPm1CrucialPosition.IsSignalled ||
                          self->D23inPm1nCrucialPosition.IsSignalled,
                      !(self->D22inPm1CrucialPosition.Value ==
                        map_D23inPm1nCrucialPosition_to_D22inPm1CrucialPosition(
                            self->D23inPm1nCrucialPosition.Value))),
                  MakeChange(self->D26inConPm1nCrucialActivation.IsSignalled,
                             self->D26inConPm1nCrucialActivation.Value))),
          AndChange(
              AndChange(
                  AndChange(
                      MakeChange(
                          self->D24inPm2NonCrucialPosition.IsSignalled ||
                              self->D22inPm1CrucialPosition.IsSignalled,
                          !(self->D24inPm2NonCrucialPosition.Value ==
                            map_D22inPm1CrucialPosition_to_D24inPm2NonCrucialPosition(
                                self->D22inPm1CrucialPosition.Value))),
                      MakeChange(
                          self->D24inPm2NonCrucialPosition.IsSignalled,
                          !(self->D24inPm2NonCrucialPosition.Value ==
                            FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition))),
                  MakeChange(
                      self->D24inPm2NonCrucialPosition.IsSignalled,
                      !(self->D24inPm2NonCrucialPosition.Value ==
                        FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NoEndPosition))),
              MakeChange(self->D27inConPm2NonCrucialActivation.IsSignalled,
                         self->D27inConPm2NonCrucialActivation.Value))),
      AndChange(
          AndChange(
              AndChange(
                  MakeChange(
                      self->D25inPm2nNonCrucialPosition
                              .IsSignalled ||
                          self->D22inPm1CrucialPosition
                              .IsSignalled,
                      !(self->D25inPm2nNonCrucialPosition.Value ==
                        map_D22inPm1CrucialPosition_to_D25inPm2nNonCrucialPosition(
                            self->D22inPm1CrucialPosition.Value))),
                  MakeChange(
                      self->D25inPm2nNonCrucialPosition.IsSignalled,
                      !(self->D25inPm2nNonCrucialPosition.Value ==
                        FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UnintendedPosition))),
              MakeChange(
                  self->D25inPm2nNonCrucialPosition.IsSignalled,
                  !(self->D25inPm2nNonCrucialPosition.Value ==
                    FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NoEndPosition))),
          MakeChange(self->D28inConPm2nNonCrucialActivation.IsSignalled,
                     self->D28inConPm2nNonCrucialActivation.Value))));
  self->Change189.IsTriggered = IsTriggered(AndChange(
      AndChange(
          MakeChange(
              self->D22inPm1CrucialPosition.IsSignalled,
              self->D22inPm1CrucialPosition.Value ==
                  FObserveDegradedPointPosition_D22inPm1CrucialPositionValue__Right),
          OrChange(
              MakeChange(
                  self->D23inPm1nCrucialPosition.IsSignalled,
                  self->D23inPm1nCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D23inPm1nCrucialPositionValue__Right),
              NegateChange(
                  MakeChange(self->D26inConPm1nCrucialActivation.IsSignalled,
                             self->D26inConPm1nCrucialActivation.Value)))),
      OrChange(
          OrChange(
              MakeChange(
                  self->D25inPm2nNonCrucialPosition.IsSignalled,
                  self->D25inPm2nNonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__NoEndPosition),
              MakeChange(
                  self->D25inPm2nNonCrucialPosition.IsSignalled,
                  self->D25inPm2nNonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D25inPm2nNonCrucialPositionValue__UnintendedPosition)),
          OrChange(
              MakeChange(
                  self->D24inPm2NonCrucialPosition.IsSignalled,
                  self->D24inPm2NonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__NoEndPosition),
              MakeChange(
                  self->D24inPm2NonCrucialPosition.IsSignalled,
                  self->D24inPm2NonCrucialPosition.Value ==
                      FObserveDegradedPointPosition_D24inPm2NonCrucialPositionValue__UnintendedPosition)))));
  self->Change391.IsTriggered = IsTriggered(OrChange(
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

  self->D30outObservedDegradedPointPosition.IsSignalled = false;
}

static void resetTriggers(FObserveDegradedPointPosition *self) {

  self->D22inPm1CrucialPosition.IsSignalled = false;
  self->D23inPm1nCrucialPosition.IsSignalled = false;
  self->D24inPm2NonCrucialPosition.IsSignalled = false;
  self->D25inPm2nNonCrucialPosition.IsSignalled = false;
  self->D51inEstEfesState.IsSignalled = false;
  self->D26inConPm1nCrucialActivation.IsSignalled = false;
  self->D27inConPm2NonCrucialActivation.IsSignalled = false;
  self->D28inConPm2nNonCrucialActivation.IsSignalled = false;
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
