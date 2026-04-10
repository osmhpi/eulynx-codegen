
#include "FSciTdsReceive.h"

// Value Conversion Functions

// Operations

void make_state_FSciTdsReceive__root__ReceivingCommands(
    FSciTdsReceive *self, FSciTdsReceive__root__state_struct *region) {
  LOG("[FSciTdsReceive] Entering state ReceivingCommands in region root");
  region->state = FSciTdsReceive__root__ReceivingCommands;
};

void make_state_FSciTdsReceive__root(FSciTdsReceive *self,
                                     FSciTdsReceive__root__state_struct *x) {
  memset(x, 0, sizeof(FSciTdsReceive__root__state_struct));

  make_state_FSciTdsReceive__root__ReceivingCommands(self, x);
  return;
}

void transition_from_FSciTdsReceive__root__ReceivingCommands(
    FSciTdsReceive *self, FSciTdsReceive__root__state_struct *x) {

  if (self->InCdCancel__6acf.HasMessage) {

    self->OutRequestCancel__7d24.HasMessage = 1;
    make_state_FSciTdsReceive__root__ReceivingCommands(self, x);
    return;
  }
  if (self->InCdDrfc__15c7.HasMessage) {

    self->OutRequestDrfc__a48b.Value.ReportedSource =
        SourceOfCommand__d5a9__Eil;
    self->OutRequestDrfc__a48b.HasMessage = 1;
    make_state_FSciTdsReceive__root__ReceivingCommands(self, x);
    return;
  }
  if (self->InCdFc__ec57.HasMessage) {
    if (self->InCdFc__ec57.Value.CommandedModeOfFC == ModeOfFC__fc54__FcPA) {

      self->OutRequestFcPA__edba.HasMessage = 1;
      make_state_FSciTdsReceive__root__ReceivingCommands(self, x);
      return;
    }
  }
  if (self->InCdFc__ec57.HasMessage) {
    if (self->InCdFc__ec57.Value.CommandedModeOfFC ==
        ModeOfFC__fc54__AcknowledgmentafterfcPACommand) {

      self->OutRequestAcknowledgement__2842.HasMessage = 1;
      make_state_FSciTdsReceive__root__ReceivingCommands(self, x);
      return;
    }
  }
  if (self->InCdFc__ec57.HasMessage) {
    if (self->InCdFc__ec57.Value.CommandedModeOfFC == ModeOfFC__fc54__FcP) {

      self->OutRequestFcP__e8be.HasMessage = 1;
      make_state_FSciTdsReceive__root__ReceivingCommands(self, x);
      return;
    }
  }
  if (self->InCdFc__ec57.HasMessage) {
    if (self->InCdFc__ec57.Value.CommandedModeOfFC == ModeOfFC__fc54__FcU) {

      self->OutRequestFcU__bd99.Value.ReportedSource =
          SourceOfCommand__d5a9__Eil;
      self->OutRequestFcU__bd99.HasMessage = 1;
      make_state_FSciTdsReceive__root__ReceivingCommands(self, x);
      return;
    }
  }
  if (self->InCdFc__ec57.HasMessage) {
    if (self->InCdFc__ec57.Value.CommandedModeOfFC == ModeOfFC__fc54__FcC) {

      self->OutRequestFcC__f902.Value.ReportedSource =
          SourceOfCommand__d5a9__Eil;
      self->OutRequestFcC__f902.HasMessage = 1;
      make_state_FSciTdsReceive__root__ReceivingCommands(self, x);
      return;
    }
  }
  if (self->InCdUpdateFillingLevel__d24d.HasMessage) {

    self->OutRequestUfl__f416.HasMessage = 1;
    make_state_FSciTdsReceive__root__ReceivingCommands(self, x);
    return;
  }
}

void transition_from_FSciTdsReceive__root(
    FSciTdsReceive *self, FSciTdsReceive__root__state_struct *x) {
  switch (x->state) {
  case FSciTdsReceive__root__ReceivingCommands:
    transition_from_FSciTdsReceive__root__ReceivingCommands(self, x);
    break;
  }
}

static void evaluateChangeEvents(FSciTdsReceive *self) {}

static void resetOutputs(FSciTdsReceive *self) {
  self->OutRequestCancel__7d24.HasMessage = false;
  self->OutRequestDrfc__a48b.HasMessage = false;
  self->OutRequestFcPA__edba.HasMessage = false;
  self->OutRequestAcknowledgement__2842.HasMessage = false;
  self->OutRequestFcP__e8be.HasMessage = false;
  self->OutRequestFcU__bd99.HasMessage = false;
  self->OutRequestFcC__f902.HasMessage = false;
  self->OutRequestUfl__f416.HasMessage = false;
}

static void resetTriggers(FSciTdsReceive *self) {
  self->InCdCancel__6acf.HasMessage = false;
  self->InCdDrfc__15c7.HasMessage = false;
  self->InCdFc__ec57.HasMessage = false;
  self->InCdUpdateFillingLevel__d24d.HasMessage = false;
}

void transition_FSciTdsReceive(FSciTdsReceive *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_FSciTdsReceive__root(self, &self->state);
  resetTriggers(self);
}

void new_FSciTdsReceive(FSciTdsReceive *self) {
  make_state_FSciTdsReceive__root(self, &self->state);
}
