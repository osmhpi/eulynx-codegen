
#include "FSciLcReceive.h"

// Value Conversion Functions

// Operations

void make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated(
    FSciLcReceive *self,
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state_struct
        *region) {
  LOG("[FSciLcReceive] Entering state Activated in region "
      "root__ReceivingLevelCrossingCommands__ReceivingActivationState");
  region->state =
      FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated;
};

void make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated(
    FSciLcReceive *self,
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state_struct
        *region) {
  LOG("[FSciLcReceive] Entering state Deactivated in region "
      "root__ReceivingLevelCrossingCommands__ReceivingActivationState");
  region->state =
      FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated;
};

void make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__PreActivated(
    FSciLcReceive *self,
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state_struct
        *region) {
  LOG("[FSciLcReceive] Entering state PreActivated in region "
      "root__ReceivingLevelCrossingCommands__ReceivingActivationState");
  region->state =
      FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__PreActivated;
};

void make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Isolated(
    FSciLcReceive *self,
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state_struct
        *region) {
  LOG("[FSciLcReceive] Entering state Isolated in region "
      "root__ReceivingLevelCrossingCommands__ReceivingActivationState");
  region->state =
      FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Isolated;
};

void make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState(
    FSciLcReceive *self,
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state_struct
        *x) {
  memset(
      x, 0,
      sizeof(
          FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__state_struct));
  self->D1outReceiveLcState.Value =
      FSciLcReceive_D1outReceiveLcStateValue__Activated;
  self->D1outReceiveLcState.IsSignalled = true;
  self->T31outActivateLcpf.Trigger = true;
  make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated(
      self, x);
  return;
}

void make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__Waiting(
    FSciLcReceive *self,
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state_struct
        *region) {
  LOG("[FSciLcReceive] Entering state Waiting in region "
      "root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover");
  region->state =
      FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__Waiting;
};

void make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator(
    FSciLcReceive *self,
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state_struct
        *region) {
  LOG("[FSciLcReceive] Entering state NoHandoverToLocalOperator in region "
      "root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover");
  region->state =
      FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator;
};

void make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated(
    FSciLcReceive *self,
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state_struct
        *region) {
  LOG("[FSciLcReceive] Entering state HandoverToLocalOperatorInitiated in "
      "region "
      "root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover");
  region->state =
      FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated;
};

void make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished(
    FSciLcReceive *self,
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state_struct
        *region) {
  LOG("[FSciLcReceive] Entering state HandoverToLocalOperatorEstablished in "
      "region "
      "root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover");
  region->state =
      FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished;
};

void make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover(
    FSciLcReceive *self,
    FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state_struct
        *x) {
  memset(
      x, 0,
      sizeof(
          FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__state_struct));

  make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__Waiting(
      self, x);
  return;
}

void make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *region) {
  LOG("[FSciLcReceive] Entering state ReceivingLevelCrossingCommands in region "
      "root");
  region->state = FSciLcReceive__root__ReceivingLevelCrossingCommands;
  make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState(
      self, &region->ReceivingLevelCrossingCommands.ReceivingActivationState);
  make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover(
      self,
      &region->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover);
};

void make_state_FSciLcReceive__root__FallbackMode(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *region) {
  LOG("[FSciLcReceive] Entering state FallbackMode in region root");
  region->state = FSciLcReceive__root__FallbackMode;
};

void make_state_FSciLcReceive__root__Waiting(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *region) {
  LOG("[FSciLcReceive] Entering state Waiting in region root");
  region->state = FSciLcReceive__root__Waiting;
};

void make_state_FSciLcReceive__root(FSciLcReceive *self,
                                    FSciLcReceive__root__state_struct *x) {
  memset(x, 0, sizeof(FSciLcReceive__root__state_struct));

  make_state_FSciLcReceive__root__Waiting(self, x);
  return;
}

void transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {

  if (self->InCdDeactivation__48b5.HasMessage) {
    if (self->InCdDeactivation__48b5.Value.CommandedDeactivationState ==
        DeactivationControlableState__514f__Deactivation) {
      self->T32outDeactivateLcpf.Trigger = true;
      self->D1outReceiveLcState.Value =
          FSciLcReceive_D1outReceiveLcStateValue__Deactivated;
      self->D1outReceiveLcState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated(
          self, &x->ReceivingLevelCrossingCommands.ReceivingActivationState);
      return;
    }
  }
  if (self->Change433.IsTriggered) {
    self->T32outDeactivateLcpf.Trigger = true;
    self->D1outReceiveLcState.Value =
        FSciLcReceive_D1outReceiveLcStateValue__Deactivated;
    self->D1outReceiveLcState.IsSignalled = true;
    make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated(
        self, &x->ReceivingLevelCrossingCommands.ReceivingActivationState);
    return;
  }
}

void transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {

  if (self->InCdActivation__3513.HasMessage) {
    if (self->InCdActivation__3513.Value.CommandedActivationState ==
        ActivationControlableState__4140__Activation) {
      self->D1outReceiveLcState.Value =
          FSciLcReceive_D1outReceiveLcStateValue__Activated;
      self->D1outReceiveLcState.IsSignalled = true;
      self->T31outActivateLcpf.Trigger = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated(
          self, &x->ReceivingLevelCrossingCommands.ReceivingActivationState);
      return;
    }
  }
  if (self->InCdActivation__3513.HasMessage) {
    if (self->InCdActivation__3513.Value.CommandedActivationState ==
        ActivationControlableState__4140__PreActivation) {
      self->D1outReceiveLcState.Value =
          FSciLcReceive_D1outReceiveLcStateValue__PreActivated;
      self->D1outReceiveLcState.IsSignalled = true;
      self->T33outPreActivateLcpf.Trigger = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__PreActivated(
          self, &x->ReceivingLevelCrossingCommands.ReceivingActivationState);
      return;
    }
  }
  if (self->InCdIsolateLc__add9.HasMessage) {
    if (self->InCdIsolateLc__add9.Value.CommandedIsolateState ==
        IsolateLevelCrossingControlableState__55c1__EnableIsolationOfTheLevelCrossing) {
      self->D1outReceiveLcState.Value =
          FSciLcReceive_D1outReceiveLcStateValue__Isolated;
      self->D1outReceiveLcState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Isolated(
          self, &x->ReceivingLevelCrossingCommands.ReceivingActivationState);
      return;
    }
  }
  if (self->Change342.IsTriggered) {
    self->D1outReceiveLcState.Value =
        FSciLcReceive_D1outReceiveLcStateValue__Activated;
    self->D1outReceiveLcState.IsSignalled = true;
    self->T31outActivateLcpf.Trigger = true;
    make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated(
        self, &x->ReceivingLevelCrossingCommands.ReceivingActivationState);
    return;
  }
}

void transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__PreActivated(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {

  if (self->InCdActivation__3513.HasMessage) {
    if (self->InCdActivation__3513.Value.CommandedActivationState ==
        ActivationControlableState__4140__Activation) {
      self->D1outReceiveLcState.Value =
          FSciLcReceive_D1outReceiveLcStateValue__Activated;
      self->D1outReceiveLcState.IsSignalled = true;
      self->T31outActivateLcpf.Trigger = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated(
          self, &x->ReceivingLevelCrossingCommands.ReceivingActivationState);
      return;
    }
  }
  if (self->InCdDeactivation__48b5.HasMessage) {
    if (self->InCdDeactivation__48b5.Value.CommandedDeactivationState ==
        DeactivationControlableState__514f__Deactivation) {
      self->T32outDeactivateLcpf.Trigger = true;
      self->D1outReceiveLcState.Value =
          FSciLcReceive_D1outReceiveLcStateValue__Deactivated;
      self->D1outReceiveLcState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated(
          self, &x->ReceivingLevelCrossingCommands.ReceivingActivationState);
      return;
    }
  }
  if (self->Change344.IsTriggered) {
    self->D1outReceiveLcState.Value =
        FSciLcReceive_D1outReceiveLcStateValue__Activated;
    self->D1outReceiveLcState.IsSignalled = true;
    self->T31outActivateLcpf.Trigger = true;
    make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated(
        self, &x->ReceivingLevelCrossingCommands.ReceivingActivationState);
    return;
  }
}

void transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Isolated(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {

  if (self->InCdIsolateLc__add9.HasMessage) {
    if (self->InCdIsolateLc__add9.Value.CommandedIsolateState ==
        IsolateLevelCrossingControlableState__55c1__DisableIsolationOfTheLevelCrossing) {
      self->D1outReceiveLcState.Value =
          FSciLcReceive_D1outReceiveLcStateValue__Deactivated;
      self->D1outReceiveLcState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated(
          self, &x->ReceivingLevelCrossingCommands.ReceivingActivationState);
      return;
    }
  }
}

void transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {
  switch (x->ReceivingLevelCrossingCommands.ReceivingActivationState.state) {
  case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated:
    transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Activated(
        self, x);
    break;
  case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated:
    transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Deactivated(
        self, x);
    break;
  case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__PreActivated:
    transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__PreActivated(
        self, x);
    break;
  case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Isolated:
    transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState__Isolated(
        self, x);
    break;
  }
}

void transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__Waiting(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {

  if (self->InCdLocalOperationHandover__2b72.HasMessage) {
    if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
        LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorEstablished) {
      self->D8outHandoverToLocalOperatorState.Value =
          FSciLcReceive_D8outHandoverToLocalOperatorStateValue__Established;
      self->D8outHandoverToLocalOperatorState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished(
          self,
          &x->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover);
      return;
    }
  }
  if (self->InCdLocalOperationHandover__2b72.HasMessage) {
    if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
        LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorInitiated) {
      self->D8outHandoverToLocalOperatorState.Value =
          FSciLcReceive_D8outHandoverToLocalOperatorStateValue__Initiated;
      self->D8outHandoverToLocalOperatorState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated(
          self,
          &x->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover);
      return;
    }
  }
  if (self->InCdLocalOperationHandover__2b72.HasMessage) {
    if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
        LocalOperationHandoverControlableState__9164__NoHandOverToLocalOperator) {
      self->D8outHandoverToLocalOperatorState.Value =
          FSciLcReceive_D8outHandoverToLocalOperatorStateValue__NoHandover;
      self->D8outHandoverToLocalOperatorState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator(
          self,
          &x->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover);
      return;
    }
  }
}

void transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {

  if (self->InCdLocalOperationHandover__2b72.HasMessage) {
    if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
        LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorInitiated) {
      self->D8outHandoverToLocalOperatorState.Value =
          FSciLcReceive_D8outHandoverToLocalOperatorStateValue__Initiated;
      self->D8outHandoverToLocalOperatorState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated(
          self,
          &x->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover);
      return;
    }
  }
  if (self->InCdLocalOperationHandover__2b72.HasMessage) {
    if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
        LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorEstablished) {
      self->D8outHandoverToLocalOperatorState.Value =
          FSciLcReceive_D8outHandoverToLocalOperatorStateValue__Established;
      self->D8outHandoverToLocalOperatorState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished(
          self,
          &x->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover);
      return;
    }
  }
}

void transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {

  if (self->InCdLocalOperationHandover__2b72.HasMessage) {
    if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
        LocalOperationHandoverControlableState__9164__NoHandOverToLocalOperator) {
      self->D8outHandoverToLocalOperatorState.Value =
          FSciLcReceive_D8outHandoverToLocalOperatorStateValue__NoHandover;
      self->D8outHandoverToLocalOperatorState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator(
          self,
          &x->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover);
      return;
    }
  }
  if (self->InCdLocalOperationHandover__2b72.HasMessage) {
    if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
        LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorEstablished) {
      self->D8outHandoverToLocalOperatorState.Value =
          FSciLcReceive_D8outHandoverToLocalOperatorStateValue__Established;
      self->D8outHandoverToLocalOperatorState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished(
          self,
          &x->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover);
      return;
    }
  }
}

void transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {

  if (self->InCdLocalOperationHandover__2b72.HasMessage) {
    if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
        LocalOperationHandoverControlableState__9164__NoHandOverToLocalOperator) {
      self->D8outHandoverToLocalOperatorState.Value =
          FSciLcReceive_D8outHandoverToLocalOperatorStateValue__NoHandover;
      self->D8outHandoverToLocalOperatorState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator(
          self,
          &x->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover);
      return;
    }
  }
  if (self->InCdLocalOperationHandover__2b72.HasMessage) {
    if (self->InCdLocalOperationHandover__2b72.Value.CommandedHandoverState ==
        LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorInitiated) {
      self->D8outHandoverToLocalOperatorState.Value =
          FSciLcReceive_D8outHandoverToLocalOperatorStateValue__Initiated;
      self->D8outHandoverToLocalOperatorState.IsSignalled = true;
      make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated(
          self,
          &x->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover);
      return;
    }
  }
}

void transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {
  switch (
      x->ReceivingLevelCrossingCommands.ReceiveLocalOperationHandover.state) {
  case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__Waiting:
    transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__Waiting(
        self, x);
    break;
  case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator:
    transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__NoHandoverToLocalOperator(
        self, x);
    break;
  case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated:
    transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorInitiated(
        self, x);
    break;
  case FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished:
    transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover__HandoverToLocalOperatorEstablished(
        self, x);
    break;
  }
}

void transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {
  transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceivingActivationState(
      self, x);
  transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands__ReceiveLocalOperationHandover(
      self, x);
  if (self->Change340.IsTriggered) {

    make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands(self, x);
    return;
  }
  if (self->Change345.IsTriggered) {

    make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands(self, x);
    return;
  }
  if (self->Change368.IsTriggered) {
    self->T34outNationalSpecificStateLcpf.Trigger = true;
    make_state_FSciLcReceive__root__FallbackMode(self, x);
    return;
  }
}

void transition_from_FSciLcReceive__root__FallbackMode(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {

  if (self->Change347.IsTriggered) {

    make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands(self, x);
    return;
  }
}

void transition_from_FSciLcReceive__root__Waiting(
    FSciLcReceive *self, FSciLcReceive__root__state_struct *x) {

  if (self->Change341.IsTriggered) {

    make_state_FSciLcReceive__root__ReceivingLevelCrossingCommands(self, x);
    return;
  }
}

void transition_from_FSciLcReceive__root(FSciLcReceive *self,
                                         FSciLcReceive__root__state_struct *x) {
  switch (x->state) {
  case FSciLcReceive__root__ReceivingLevelCrossingCommands:
    transition_from_FSciLcReceive__root__ReceivingLevelCrossingCommands(self,
                                                                        x);
    break;
  case FSciLcReceive__root__FallbackMode:
    transition_from_FSciLcReceive__root__FallbackMode(self, x);
    break;
  case FSciLcReceive__root__Waiting:
    transition_from_FSciLcReceive__root__Waiting(self, x);
    break;
  }
}

static void evaluateChangeEvents(FSciLcReceive *self) {
  self->Change433.IsTriggered = IsTriggered(
      MakeChange(self->D53inTimerExpired.IsSignalled,
                 self->D53inTimerExpired.Value ==
                     FSciLcReceive_D53inTimerExpiredValue__TimerExpired));
  self->Change342.IsTriggered = IsTriggered(
      MakeChange(self->D51inEstEfesState.IsSignalled,
                 self->D51inEstEfesState.Value ==
                     FSciLcReceive_D51inEstEfesStateValue__Initialising));
  self->Change344.IsTriggered = IsTriggered(
      MakeChange(self->D51inEstEfesState.IsSignalled,
                 self->D51inEstEfesState.Value ==
                     FSciLcReceive_D51inEstEfesStateValue__Initialising));
  self->Change340.IsTriggered = IsTriggered(
      MakeChange(self->D51inEstEfesState.IsSignalled,
                 self->D51inEstEfesState.Value ==
                     FSciLcReceive_D51inEstEfesStateValue__Booting));
  self->Change345.IsTriggered = IsTriggered(
      MakeChange(self->D51inEstEfesState.IsSignalled,
                 self->D51inEstEfesState.Value ==
                     FSciLcReceive_D51inEstEfesStateValue__NoOperatingVoltage));
  self->Change368.IsTriggered = IsTriggered(
      MakeChange(self->D51inEstEfesState.IsSignalled,
                 self->D51inEstEfesState.Value ==
                     FSciLcReceive_D51inEstEfesStateValue__FallbackMode));
  self->Change347.IsTriggered = IsTriggered(OrChange(
      OrChange(
          OrChange(
              MakeChange(self->D51inEstEfesState.IsSignalled,
                         self->D51inEstEfesState.Value ==
                             FSciLcReceive_D51inEstEfesStateValue__Operational),
              MakeChange(self->D51inEstEfesState.IsSignalled,
                         self->D51inEstEfesState.Value ==
                             FSciLcReceive_D51inEstEfesStateValue__Booting)),
          MakeChange(
              self->D51inEstEfesState.IsSignalled,
              self->D51inEstEfesState.Value ==
                  FSciLcReceive_D51inEstEfesStateValue__NoOperatingVoltage)),
      MakeChange(self->D51inEstEfesState.IsSignalled,
                 self->D51inEstEfesState.Value ==
                     FSciLcReceive_D51inEstEfesStateValue__Initialising)));
  self->Change341.IsTriggered = IsTriggered(
      MakeChange(self->D51inEstEfesState.IsSignalled,
                 self->D51inEstEfesState.Value ==
                     FSciLcReceive_D51inEstEfesStateValue__Booting));
}

static void resetOutputs(FSciLcReceive *self) {

  self->T31outActivateLcpf.Trigger = false;
  self->T33outPreActivateLcpf.Trigger = false;
  self->T34outNationalSpecificStateLcpf.Trigger = false;
  self->T32outDeactivateLcpf.Trigger = false;

  self->D1outReceiveLcState.IsSignalled = false;
  self->D8outHandoverToLocalOperatorState.IsSignalled = false;
}

static void resetTriggers(FSciLcReceive *self) {
  self->InCdDeactivation__48b5.HasMessage = false;
  self->InCdActivation__3513.HasMessage = false;
  self->InCdIsolateLc__add9.HasMessage = false;
  self->InCdLocalOperationHandover__2b72.HasMessage = false;

  self->D53inTimerExpired.IsSignalled = false;
  self->D51inEstEfesState.IsSignalled = false;
}

void transition_FSciLcReceive(FSciLcReceive *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_FSciLcReceive__root(self, &self->state);
  resetTriggers(self);
}

void new_FSciLcReceive(FSciLcReceive *self) {
  make_state_FSciLcReceive__root(self, &self->state);
}
