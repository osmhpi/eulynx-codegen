
#include "FObserveMovementFailed.h"

// Value Conversion Functions

// Operations

void make_state_FObserveMovementFailed__root__ObserveMovementFailure__root__Idle(
    FObserveMovementFailed *self,
    FObserveMovementFailed__root__ObserveMovementFailure__root__state_struct
        *region) {
  LOG("[FObserveMovementFailed] Entering state Idle in region "
      "root__ObserveMovementFailure__root");
  region->state =
      FObserveMovementFailed__root__ObserveMovementFailure__root__Idle;
};

void make_state_FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure(
    FObserveMovementFailed *self,
    FObserveMovementFailed__root__ObserveMovementFailure__root__state_struct
        *region) {
  LOG("[FObserveMovementFailed] Entering state ObservingMovementFailure in "
      "region root__ObserveMovementFailure__root");
  region->state =
      FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure;
};

void make_state_FObserveMovementFailed__root__ObserveMovementFailure__root(
    FObserveMovementFailed *self,
    FObserveMovementFailed__root__ObserveMovementFailure__root__state_struct
        *x) {
  memset(
      x, 0,
      sizeof(
          FObserveMovementFailed__root__ObserveMovementFailure__root__state_struct));
  self->D13outObservedMovementFailed.Value = false;
  make_state_FObserveMovementFailed__root__ObserveMovementFailure__root__Idle(
      self, x);
  return;
}

void make_state_FObserveMovementFailed__root__ObserveMovementFailure(
    FObserveMovementFailed *self,
    FObserveMovementFailed__root__state_struct *region) {
  LOG("[FObserveMovementFailed] Entering state ObserveMovementFailure in "
      "region root");
  region->state = FObserveMovementFailed__root__ObserveMovementFailure;
  make_state_FObserveMovementFailed__root__ObserveMovementFailure__root(
      self, &region->ObserveMovementFailure.root);
};

void make_state_FObserveMovementFailed__root(
    FObserveMovementFailed *self,
    FObserveMovementFailed__root__state_struct *x) {
  memset(x, 0, sizeof(FObserveMovementFailed__root__state_struct));

  make_state_FObserveMovementFailed__root__ObserveMovementFailure(self, x);
  return;
}

void transition_from_FObserveMovementFailed__root__ObserveMovementFailure__root__Idle(
    FObserveMovementFailed *self,
    FObserveMovementFailed__root__state_struct *x) {

  if (self->Change65.IsTriggered) {

    make_state_FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure(
        self, &x->ObserveMovementFailure.root);
    return;
  }
}

void transition_from_FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure(
    FObserveMovementFailed *self,
    FObserveMovementFailed__root__state_struct *x) {

  if (self->Change60.IsTriggered) {

    make_state_FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure(
        self, &x->ObserveMovementFailure.root);
    return;
  }
  if (self->Change69.IsTriggered) {

    make_state_FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure(
        self, &x->ObserveMovementFailure.root);
    return;
  }
  if (self->Change73.IsTriggered) {
    self->D13outObservedMovementFailed.Value = false;
    make_state_FObserveMovementFailed__root__ObserveMovementFailure__root__Idle(
        self, &x->ObserveMovementFailure.root);
    return;
  }
  if (self->Time12.IsTimeoutExpired) {
    self->D13outObservedMovementFailed.Value = true;
    make_state_FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure(
        self, &x->ObserveMovementFailure.root);
    return;
  }
  if (self->Change997.IsTriggered) {
    self->D13outObservedMovementFailed.Value = true;
    make_state_FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure(
        self, &x->ObserveMovementFailure.root);
    return;
  }
}

void transition_from_FObserveMovementFailed__root__ObserveMovementFailure__root(
    FObserveMovementFailed *self,
    FObserveMovementFailed__root__state_struct *x) {
  switch (x->ObserveMovementFailure.root.state) {
  case FObserveMovementFailed__root__ObserveMovementFailure__root__Idle:
    transition_from_FObserveMovementFailed__root__ObserveMovementFailure__root__Idle(
        self, x);
    break;
  case FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure:
    transition_from_FObserveMovementFailed__root__ObserveMovementFailure__root__ObservingMovementFailure(
        self, x);
    break;
  }
}

void transition_from_FObserveMovementFailed__root__ObserveMovementFailure(
    FObserveMovementFailed *self,
    FObserveMovementFailed__root__state_struct *x) {
  transition_from_FObserveMovementFailed__root__ObserveMovementFailure__root(
      self, x);
}

void transition_from_FObserveMovementFailed__root(
    FObserveMovementFailed *self,
    FObserveMovementFailed__root__state_struct *x) {
  switch (x->state) {
  case FObserveMovementFailed__root__ObserveMovementFailure:
    transition_from_FObserveMovementFailed__root__ObserveMovementFailure(self,
                                                                         x);
    break;
  }
}

static void evaluateChangeEvents(FObserveMovementFailed *self) {
  self->Change65.IsTriggered = IsTriggered(OrChange(
      MakeChange(self->D12inRequiredPmPosition.IsSignalled,
                 self->D12inRequiredPmPosition.Value ==
                     FObserveMovementFailed_D12inRequiredPmPositionValue__Left),
      MakeChange(
          self->D12inRequiredPmPosition.IsSignalled,
          self->D12inRequiredPmPosition.Value ==
              FObserveMovementFailed_D12inRequiredPmPositionValue__Right)));
  self->Change60.IsTriggered = IsTriggered(MakeChange(
      self->D12inRequiredPmPosition.IsSignalled,
      self->D12inRequiredPmPosition.Value ==
          FObserveMovementFailed_D12inRequiredPmPositionValue__Left));
  self->Change69.IsTriggered = IsTriggered(MakeChange(
      self->D12inRequiredPmPosition.IsSignalled,
      self->D12inRequiredPmPosition.Value ==
          FObserveMovementFailed_D12inRequiredPmPositionValue__Right));
  self->Change73.IsTriggered = IsTriggered(MakeChange(
      self->D12inRequiredPmPosition.IsSignalled,
      self->D12inRequiredPmPosition.Value ==
          FObserveMovementFailed_D12inRequiredPmPositionValue__Uncommanded));
  self->Change997.IsTriggered = self->T21inMovementFailed.IsTriggered;
}

static void resetOutputs(FObserveMovementFailed *self) {

  self->D13outObservedMovementFailed.IsSignalled = false;
}

static void resetTriggers(FObserveMovementFailed *self) {

  self->T21inMovementFailed.IsTriggered = false;

  self->D20inConTmaxPmOperation.IsSignalled = false;
  self->D12inRequiredPmPosition.IsSignalled = false;
  self->D14inObservedPointPosition.IsSignalled = false;

  self->Time12.IsTimeoutExpired = false;
}

void transition_FObserveMovementFailed(FObserveMovementFailed *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_FObserveMovementFailed__root(self, &self->state);
  resetTriggers(self);
}

void new_FObserveMovementFailed(FObserveMovementFailed *self) {
  make_state_FObserveMovementFailed__root(self, &self->state);
}
