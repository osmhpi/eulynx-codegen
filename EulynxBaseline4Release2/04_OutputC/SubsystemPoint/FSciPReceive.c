
#include "FSciPReceive.h"

// Value Conversion Functions

// Operations

void make_state_FSciPReceive__root__ReceivingCommands(
    FSciPReceive *self, FSciPReceive__root__state_struct *region) {
  LOG("[FSciPReceive] Entering state ReceivingCommands in region root");
  region->state = FSciPReceive__root__ReceivingCommands;
};

void make_state_FSciPReceive__root(FSciPReceive *self,
                                   FSciPReceive__root__state_struct *x) {
  memset(x, 0, sizeof(FSciPReceive__root__state_struct));
  self->D10outRequiredPointPosition.Value =
      FSciPReceive_D10outRequiredPointPositionValue__Uncommanded;
  self->D10outRequiredPointPosition.IsSignalled = true;
  make_state_FSciPReceive__root__ReceivingCommands(self, x);
  return;
}

void transition_from_FSciPReceive__root__ReceivingCommands(
    FSciPReceive *self, FSciPReceive__root__state_struct *x) {

  if (self->Change31.IsTriggered) {
    self->D10outRequiredPointPosition.Value =
        FSciPReceive_D10outRequiredPointPositionValue__Uncommanded;
    self->D10outRequiredPointPosition.IsSignalled = true;
    make_state_FSciPReceive__root__ReceivingCommands(self, x);
    return;
  }
  if (self->Change75.IsTriggered) {
    self->D10outRequiredPointPosition.Value =
        FSciPReceive_D10outRequiredPointPositionValue__Uncommanded;
    self->D10outRequiredPointPosition.IsSignalled = true;
    make_state_FSciPReceive__root__ReceivingCommands(self, x);
    return;
  }
  if (self->Change331.IsTriggered) {
    self->D10outRequiredPointPosition.Value =
        FSciPReceive_D10outRequiredPointPositionValue__Uncommanded;
    self->D10outRequiredPointPosition.IsSignalled = true;
    make_state_FSciPReceive__root__ReceivingCommands(self, x);
    return;
  }
  if (self->InCdMovePoint__342e.HasMessage) {
    if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
         PointPositionControlableState__14bc__Left) &&
        (self->D50inPdiConnectionState.Value ==
         FSciPReceive_D50inPdiConnectionStateValue__Established)) {
      self->D10outRequiredPointPosition.Value =
          FSciPReceive_D10outRequiredPointPositionValue__Left;
      self->D10outRequiredPointPosition.IsSignalled = true;
      make_state_FSciPReceive__root__ReceivingCommands(self, x);
      return;
    }
  }
  if (self->InCdMovePoint__342e.HasMessage) {
    if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
         PointPositionControlableState__14bc__Right) &&
        (self->D50inPdiConnectionState.Value ==
         FSciPReceive_D50inPdiConnectionStateValue__Established)) {
      self->D10outRequiredPointPosition.Value =
          FSciPReceive_D10outRequiredPointPositionValue__Right;
      self->D10outRequiredPointPosition.IsSignalled = true;
      make_state_FSciPReceive__root__ReceivingCommands(self, x);
      return;
    }
  }
}

void transition_from_FSciPReceive__root(FSciPReceive *self,
                                        FSciPReceive__root__state_struct *x) {
  switch (x->state) {
  case FSciPReceive__root__ReceivingCommands:
    transition_from_FSciPReceive__root__ReceivingCommands(self, x);
    break;
  }
}

static void evaluateChangeEvents(FSciPReceive *self) {
  self->Change31.IsTriggered = IsTriggered(
      MakeChange(self->D11inObservedAbilityToMove.IsSignalled,
                 self->D11inObservedAbilityToMove.Value ==
                     FSciPReceive_D11inObservedAbilityToMoveValue__AbleToMove));
  self->Change75.IsTriggered = IsTriggered(
      MakeChange(self->D12inRequiredPmPosition.IsSignalled,
                 self->D12inRequiredPmPosition.Value ==
                     FSciPReceive_D12inRequiredPmPositionValue__Uncommanded));
  self->Change331.IsTriggered = IsTriggered(OrChange(
      OrChange(
          MakeChange(
              self->D50inPdiConnectionState.IsSignalled,
              self->D50inPdiConnectionState.Value ==
                  FSciPReceive_D50inPdiConnectionStateValue__NotReadyForPdiNoScp),
          MakeChange(
              self->D50inPdiConnectionState.IsSignalled,
              self->D50inPdiConnectionState.Value ==
                  FSciPReceive_D50inPdiConnectionStateValue__NotReadyForPdi)),
      MakeChange(self->D50inPdiConnectionState.IsSignalled,
                 self->D50inPdiConnectionState.Value ==
                     FSciPReceive_D50inPdiConnectionStateValue__Suspended)));
}

static void resetOutputs(FSciPReceive *self) {

  self->D10outRequiredPointPosition.IsSignalled = false;
}

static void resetTriggers(FSciPReceive *self) {
  self->InCdMovePoint__342e.HasMessage = false;

  self->D50inPdiConnectionState.IsSignalled = false;
  self->D12inRequiredPmPosition.IsSignalled = false;
  self->D11inObservedAbilityToMove.IsSignalled = false;
}

void transition_FSciPReceive(FSciPReceive *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_FSciPReceive__root(self, &self->state);
  resetTriggers(self);
}

void new_FSciPReceive(FSciPReceive *self) {
  make_state_FSciPReceive__root(self, &self->state);
}
