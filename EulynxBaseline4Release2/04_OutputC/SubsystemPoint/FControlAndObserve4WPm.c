
#include "FControlAndObserve4WPm.h"

// Value Conversion Functions

// Operations

void make_state_FControlAndObserve4WPm__root__Operating__root__Detection(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__root__state_struct *region) {
  LOG("[FControlAndObserve4WPm] Entering state Detection in region "
      "root__Operating__root");
  region->state = FControlAndObserve4WPm__root__Operating__root__Detection;
};

void make_state_FControlAndObserve4WPm__root__Operating__root__MovingRightPm(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__root__state_struct *region) {
  LOG("[FControlAndObserve4WPm] Entering state MovingRightPm in region "
      "root__Operating__root");
  region->state = FControlAndObserve4WPm__root__Operating__root__MovingRightPm;
};

void make_state_FControlAndObserve4WPm__root__Operating__root__MovingLeftPm(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__root__state_struct *region) {
  LOG("[FControlAndObserve4WPm] Entering state MovingLeftPm in region "
      "root__Operating__root");
  region->state = FControlAndObserve4WPm__root__Operating__root__MovingLeftPm;
};

void make_state_FControlAndObserve4WPm__root__Operating__root(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__root__state_struct *x) {
  memset(x, 0,
         sizeof(FControlAndObserve4WPm__root__Operating__root__state_struct));
  self->D25outDetectionVoltage.Value = true;
  self->D24outDriveVoltageRight.Value = false;
  self->D23outDriveVoltageLeft.Value = false;
  make_state_FControlAndObserve4WPm__root__Operating__root__Detection(self, x);
  return;
}

void make_state_FControlAndObserve4WPm__root__Operating(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__state_struct *region) {
  LOG("[FControlAndObserve4WPm] Entering state Operating in region root");
  region->state = FControlAndObserve4WPm__root__Operating;
  make_state_FControlAndObserve4WPm__root__Operating__root(
      self, &region->Operating.root);
};

void make_state_FControlAndObserve4WPm__root__WaitingForInitialising(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__state_struct *region) {
  LOG("[FControlAndObserve4WPm] Entering state WaitingForInitialising in "
      "region root");
  region->state = FControlAndObserve4WPm__root__WaitingForInitialising;
};

void make_state_FControlAndObserve4WPm__root(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__state_struct *x) {
  memset(x, 0, sizeof(FControlAndObserve4WPm__root__state_struct));

  make_state_FControlAndObserve4WPm__root__WaitingForInitialising(self, x);
  return;
}

void transition_from_FControlAndObserve4WPm__root__Operating__root__Detection(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__state_struct *x) {

  if (self->Change61.IsTriggered) {
    if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value)) {
      self->D25outDetectionVoltage.Value = false;
      self->D24outDriveVoltageRight.Value = false;
      self->D23outDriveVoltageLeft.Value = true;
      self->D10outPmPosition.Value =
          FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
      self->D10outPmPosition.IsSignalled = true;
      make_state_FControlAndObserve4WPm__root__Operating__root__MovingLeftPm(
          self, &x->Operating.root);
      return;
    }
  }
  if (self->Change67.IsTriggered) {
    if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value)) {
      self->D25outDetectionVoltage.Value = false;
      self->D24outDriveVoltageRight.Value = true;
      self->D23outDriveVoltageLeft.Value = false;
      self->D10outPmPosition.Value =
          FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
      self->D10outPmPosition.IsSignalled = true;
      make_state_FControlAndObserve4WPm__root__Operating__root__MovingRightPm(
          self, &x->Operating.root);
      return;
    }
  }
  if (self->Change201.IsTriggered) {
    self->D10outPmPosition.Value =
        FControlAndObserve4WPm_D10outPmPositionValue__Left;
    self->D10outPmPosition.IsSignalled = true;
    make_state_FControlAndObserve4WPm__root__Operating__root__Detection(
        self, &x->Operating.root);
    return;
  }
  if (self->Change202.IsTriggered) {
    self->D10outPmPosition.Value =
        FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
    self->D10outPmPosition.IsSignalled = true;
    make_state_FControlAndObserve4WPm__root__Operating__root__Detection(
        self, &x->Operating.root);
    return;
  }
  if (self->Change203.IsTriggered) {
    self->D10outPmPosition.Value =
        FControlAndObserve4WPm_D10outPmPositionValue__Right;
    self->D10outPmPosition.IsSignalled = true;
    make_state_FControlAndObserve4WPm__root__Operating__root__Detection(
        self, &x->Operating.root);
    return;
  }
  if (self->Change204.IsTriggered) {
    self->D10outPmPosition.Value =
        FControlAndObserve4WPm_D10outPmPositionValue__UnintendedPosition;
    self->D10outPmPosition.IsSignalled = true;
    make_state_FControlAndObserve4WPm__root__Operating__root__Detection(
        self, &x->Operating.root);
    return;
  }
}

void transition_from_FControlAndObserve4WPm__root__Operating__root__MovingRightPm(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__state_struct *x) {

  if (self->Change63.IsTriggered) {
    if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value)) {
      self->D25outDetectionVoltage.Value = false;
      self->D24outDriveVoltageRight.Value = false;
      self->D23outDriveVoltageLeft.Value = true;
      self->D10outPmPosition.Value =
          FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
      self->D10outPmPosition.IsSignalled = true;
      make_state_FControlAndObserve4WPm__root__Operating__root__MovingLeftPm(
          self, &x->Operating.root);
      return;
    }
  }
  if (self->Change72.IsTriggered) {
    self->D25outDetectionVoltage.Value = true;
    self->D24outDriveVoltageRight.Value = false;
    self->D23outDriveVoltageLeft.Value = false;
    make_state_FControlAndObserve4WPm__root__Operating__root__Detection(
        self, &x->Operating.root);
    return;
  }
  if (self->Change78.IsTriggered) {
    self->D25outDetectionVoltage.Value = true;
    self->D24outDriveVoltageRight.Value = false;
    self->D23outDriveVoltageLeft.Value = false;
    make_state_FControlAndObserve4WPm__root__Operating__root__Detection(
        self, &x->Operating.root);
    return;
  }
}

void transition_from_FControlAndObserve4WPm__root__Operating__root__MovingLeftPm(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__state_struct *x) {

  if (self->Change66.IsTriggered) {
    self->D25outDetectionVoltage.Value = true;
    self->D24outDriveVoltageRight.Value = false;
    self->D23outDriveVoltageLeft.Value = false;
    make_state_FControlAndObserve4WPm__root__Operating__root__Detection(
        self, &x->Operating.root);
    return;
  }
  if (self->Change68.IsTriggered) {
    if ((self->D20inConDriveCapability.Value) && (self->D45inConActive.Value)) {
      self->D25outDetectionVoltage.Value = false;
      self->D24outDriveVoltageRight.Value = true;
      self->D23outDriveVoltageLeft.Value = false;
      self->D10outPmPosition.Value =
          FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
      self->D10outPmPosition.IsSignalled = true;
      make_state_FControlAndObserve4WPm__root__Operating__root__MovingRightPm(
          self, &x->Operating.root);
      return;
    }
  }
  if (self->Change74.IsTriggered) {
    self->D25outDetectionVoltage.Value = true;
    self->D24outDriveVoltageRight.Value = false;
    self->D23outDriveVoltageLeft.Value = false;
    make_state_FControlAndObserve4WPm__root__Operating__root__Detection(
        self, &x->Operating.root);
    return;
  }
}

void transition_from_FControlAndObserve4WPm__root__Operating__root(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__state_struct *x) {
  switch (x->Operating.root.state) {
  case FControlAndObserve4WPm__root__Operating__root__Detection:
    transition_from_FControlAndObserve4WPm__root__Operating__root__Detection(
        self, x);
    break;
  case FControlAndObserve4WPm__root__Operating__root__MovingRightPm:
    transition_from_FControlAndObserve4WPm__root__Operating__root__MovingRightPm(
        self, x);
    break;
  case FControlAndObserve4WPm__root__Operating__root__MovingLeftPm:
    transition_from_FControlAndObserve4WPm__root__Operating__root__MovingLeftPm(
        self, x);
    break;
  }
}

void transition_from_FControlAndObserve4WPm__root__Operating(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__state_struct *x) {
  transition_from_FControlAndObserve4WPm__root__Operating__root(self, x);
  if (self->Change354.IsTriggered) {
    self->D24outDriveVoltageRight.Value = false;
    self->D23outDriveVoltageLeft.Value = false;
    make_state_FControlAndObserve4WPm__root__Operating(self, x);
    return;
  }
  if (self->Change392.IsTriggered) {
    self->D24outDriveVoltageRight.Value = false;
    self->D23outDriveVoltageLeft.Value = false;
    make_state_FControlAndObserve4WPm__root__WaitingForInitialising(self, x);
    return;
  }
  if (self->Change200.IsTriggered) {
    self->D19outAbilityToMovePm.Value =
        FControlAndObserve4WPm_D19outAbilityToMovePmValue__Able;
    self->D19outAbilityToMovePm.IsSignalled = true;
    make_state_FControlAndObserve4WPm__root__Operating(self, x);
    return;
  }
  if (self->Change565.IsTriggered) {
    self->D19outAbilityToMovePm.Value =
        FControlAndObserve4WPm_D19outAbilityToMovePmValue__Unable;
    self->D19outAbilityToMovePm.IsSignalled = true;
    make_state_FControlAndObserve4WPm__root__Operating(self, x);
    return;
  }
}

void transition_from_FControlAndObserve4WPm__root__WaitingForInitialising(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__state_struct *x) {

  if (self->Change353.IsTriggered) {
    if (self->D45inConActive.Value) {

      if ((self->D20inConDriveCapability.Value) &&
          (!(self->D26inDriveVoltageAvailable.Value))) {
        self->D19outAbilityToMovePm.Value =
            FControlAndObserve4WPm_D19outAbilityToMovePmValue__Unable;
        self->D19outAbilityToMovePm.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating(self, x);
        return;
      }
      if (!(self->D20inConDriveCapability.Value)) {
        self->D19outAbilityToMovePm.Value =
            FControlAndObserve4WPm_D19outAbilityToMovePmValue__NotUsed;
        self->D19outAbilityToMovePm.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating(self, x);
        return;
      }
      if ((self->D20inConDriveCapability.Value) &&
          (self->D26inDriveVoltageAvailable.Value)) {
        self->D19outAbilityToMovePm.Value =
            FControlAndObserve4WPm_D19outAbilityToMovePmValue__Able;
        self->D19outAbilityToMovePm.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating(self, x);
        return;
      }
    }
  }
}

void transition_from_FControlAndObserve4WPm__root(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__state_struct *x) {
  switch (x->state) {
  case FControlAndObserve4WPm__root__Operating:
    transition_from_FControlAndObserve4WPm__root__Operating(self, x);
    break;
  case FControlAndObserve4WPm__root__WaitingForInitialising:
    transition_from_FControlAndObserve4WPm__root__WaitingForInitialising(self,
                                                                         x);
    break;
  }
}

static void evaluateChangeEvents(FControlAndObserve4WPm *self) {
  self->Change61.IsTriggered = IsTriggered(MakeChange(
      self->D12inRequiredPmPosition.IsSignalled,
      self->D12inRequiredPmPosition.Value ==
          FControlAndObserve4WPm_D12inRequiredPmPositionValue__Left));
  self->Change67.IsTriggered = IsTriggered(MakeChange(
      self->D12inRequiredPmPosition.IsSignalled,
      self->D12inRequiredPmPosition.Value ==
          FControlAndObserve4WPm_D12inRequiredPmPositionValue__Right));
  self->Change201.IsTriggered = IsTriggered(MakeChange(
      self->D27in4WPmPosition.IsSignalled,
      self->D27in4WPmPosition.Value ==
          FControlAndObserve4WPm_D27in4WPmPositionValue__LeftDetected));
  self->Change202.IsTriggered = IsTriggered(MakeChange(
      self->D27in4WPmPosition.IsSignalled,
      self->D27in4WPmPosition.Value ==
          FControlAndObserve4WPm_D27in4WPmPositionValue__NoEndPosition));
  self->Change203.IsTriggered = IsTriggered(MakeChange(
      self->D27in4WPmPosition.IsSignalled,
      self->D27in4WPmPosition.Value ==
          FControlAndObserve4WPm_D27in4WPmPositionValue__RightDetected));
  self->Change204.IsTriggered = IsTriggered(MakeChange(
      self->D27in4WPmPosition.IsSignalled,
      self->D27in4WPmPosition.Value ==
          FControlAndObserve4WPm_D27in4WPmPositionValue__UnintendedPosition));
  self->Change63.IsTriggered = IsTriggered(MakeChange(
      self->D12inRequiredPmPosition.IsSignalled,
      self->D12inRequiredPmPosition.Value ==
          FControlAndObserve4WPm_D12inRequiredPmPositionValue__Left));
  self->Change72.IsTriggered = IsTriggered(MakeChange(
      self->D12inRequiredPmPosition.IsSignalled,
      self->D12inRequiredPmPosition.Value ==
          FControlAndObserve4WPm_D12inRequiredPmPositionValue__RightReached));
  self->Change78.IsTriggered = IsTriggered(MakeChange(
      self->D12inRequiredPmPosition.IsSignalled,
      self->D12inRequiredPmPosition.Value ==
          FControlAndObserve4WPm_D12inRequiredPmPositionValue__Uncommanded));
  self->Change66.IsTriggered = IsTriggered(MakeChange(
      self->D12inRequiredPmPosition.IsSignalled,
      self->D12inRequiredPmPosition.Value ==
          FControlAndObserve4WPm_D12inRequiredPmPositionValue__LeftReached));
  self->Change68.IsTriggered = IsTriggered(MakeChange(
      self->D12inRequiredPmPosition.IsSignalled,
      self->D12inRequiredPmPosition.Value ==
          FControlAndObserve4WPm_D12inRequiredPmPositionValue__Right));
  self->Change74.IsTriggered = IsTriggered(MakeChange(
      self->D12inRequiredPmPosition.IsSignalled,
      self->D12inRequiredPmPosition.Value ==
          FControlAndObserve4WPm_D12inRequiredPmPositionValue__Uncommanded));
  self->Change354.IsTriggered = IsTriggered(
      MakeChange(self->D51inEstEfesState.IsSignalled,
                 self->D51inEstEfesState.Value ==
                     FControlAndObserve4WPm_D51inEstEfesStateValue__Booting));
  self->Change392.IsTriggered = IsTriggered(OrChange(
      MakeChange(
          self->D51inEstEfesState.IsSignalled,
          self->D51inEstEfesState.Value ==
              FControlAndObserve4WPm_D51inEstEfesStateValue__NoOperatingVoltage),
      MakeChange(
          self->D51inEstEfesState.IsSignalled,
          self->D51inEstEfesState.Value ==
              FControlAndObserve4WPm_D51inEstEfesStateValue__FallbackMode)));
  self->Change200.IsTriggered =
      IsTriggered(MakeChange(self->D26inDriveVoltageAvailable.IsSignalled,
                             self->D26inDriveVoltageAvailable.Value));
  self->Change565.IsTriggered = IsTriggered(
      NegateChange(MakeChange(self->D26inDriveVoltageAvailable.IsSignalled,
                              self->D26inDriveVoltageAvailable.Value)));
  self->Change353.IsTriggered = IsTriggered(
      MakeChange(self->D51inEstEfesState.IsSignalled,
                 self->D51inEstEfesState.Value ==
                     FControlAndObserve4WPm_D51inEstEfesStateValue__Booting));
}

static void resetOutputs(FControlAndObserve4WPm *self) {

  self->D24outDriveVoltageRight.IsSignalled = false;
  self->D23outDriveVoltageLeft.IsSignalled = false;
  self->D10outPmPosition.IsSignalled = false;
  self->D19outAbilityToMovePm.IsSignalled = false;
  self->D25outDetectionVoltage.IsSignalled = false;
}

static void resetTriggers(FControlAndObserve4WPm *self) {

  self->D20inConDriveCapability.IsSignalled = false;
  self->D27in4WPmPosition.IsSignalled = false;
  self->D51inEstEfesState.IsSignalled = false;
  self->D12inRequiredPmPosition.IsSignalled = false;
  self->D45inConActive.IsSignalled = false;
  self->D26inDriveVoltageAvailable.IsSignalled = false;
}

void transition_FControlAndObserve4WPm(FControlAndObserve4WPm *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_FControlAndObserve4WPm__root(self, &self->state);
  resetTriggers(self);
}

void new_FControlAndObserve4WPm(FControlAndObserve4WPm *self) {
  make_state_FControlAndObserve4WPm__root(self, &self->state);
}
