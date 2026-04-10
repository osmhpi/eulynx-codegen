
#include "SSciLsCommand.h"

// Value Conversion Functions

// Operations

void make_state_SSciLsCommand__root__SendingCommands(
    SSciLsCommand *self, SSciLsCommand__root__state_struct *region) {
  LOG("[SSciLsCommand] Entering state SendingCommands in region root");
  region->state = SSciLsCommand__root__SendingCommands;
};

void make_state_SSciLsCommand__root(SSciLsCommand *self,
                                    SSciLsCommand__root__state_struct *x) {
  memset(x, 0, sizeof(SSciLsCommand__root__state_struct));

  make_state_SSciLsCommand__root__SendingCommands(self, x);
  return;
}

void transition_from_SSciLsCommand__root__SendingCommands(
    SSciLsCommand *self, SSciLsCommand__root__state_struct *x) {

  if (self->Change1012.IsTriggered) {
    if ((self->D23inSignalAspect.Value ==
         SSciLsCommand_D23inSignalAspectValue__SignalAspect2) &&
        (self->D9PdiConnectionState.Value ==
         SSciLsCommand_D9PdiConnectionStateValue__Established)) {

      self->OutCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState =
          SignalAspectControlableState__0dcc__SignalAspect2;
      self->OutCdIndicateSignalAspect__e570.Value.CommandedDarkState =
          self->D24inIntentionallyDark.Value;
      self->OutCdIndicateSignalAspect__e570.HasMessage = 1;
      make_state_SSciLsCommand__root__SendingCommands(self, x);
      return;
    }
  }
  if (self->Change1013.IsTriggered) {
    if ((self->D23inSignalAspect.Value ==
         SSciLsCommand_D23inSignalAspectValue__MostRestrictAspect) &&
        (self->D9PdiConnectionState.Value ==
         SSciLsCommand_D9PdiConnectionStateValue__Established)) {

      self->OutCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState =
          SignalAspectControlableState__0dcc__MostRestrictAspect;
      self->OutCdIndicateSignalAspect__e570.Value.CommandedDarkState =
          self->D24inIntentionallyDark.Value;
      self->OutCdIndicateSignalAspect__e570.HasMessage = 1;
      make_state_SSciLsCommand__root__SendingCommands(self, x);
      return;
    }
  }
  if (self->Change1011.IsTriggered) {
    if ((self->D23inSignalAspect.Value ==
         SSciLsCommand_D23inSignalAspectValue__SignalAspect1) &&
        (self->D9PdiConnectionState.Value ==
         SSciLsCommand_D9PdiConnectionStateValue__Established)) {

      self->OutCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState =
          SignalAspectControlableState__0dcc__SignalAspect1;
      self->OutCdIndicateSignalAspect__e570.Value.CommandedDarkState =
          self->D24inIntentionallyDark.Value;
      self->OutCdIndicateSignalAspect__e570.HasMessage = 1;
      make_state_SSciLsCommand__root__SendingCommands(self, x);
      return;
    }
  }
  if (self->Change1024.IsTriggered) {
    if ((self->D25inLuminosity.Value ==
         SSciLsCommand_D25inLuminosityValue__Night) &&
        (self->D9PdiConnectionState.Value ==
         SSciLsCommand_D9PdiConnectionStateValue__Established)) {

      self->OutCdSetLuminosity__4570.Value.CommandedLuminosityState =
          LuminosityState__20ae__Night;
      self->OutCdSetLuminosity__4570.HasMessage = 1;
      make_state_SSciLsCommand__root__SendingCommands(self, x);
      return;
    }
  }
  if (self->Change1022.IsTriggered) {
    if ((self->D25inLuminosity.Value ==
         SSciLsCommand_D25inLuminosityValue__Day) &&
        (self->D9PdiConnectionState.Value ==
         SSciLsCommand_D9PdiConnectionStateValue__Established)) {

      self->OutCdSetLuminosity__4570.Value.CommandedLuminosityState =
          LuminosityState__20ae__Day;
      self->OutCdSetLuminosity__4570.HasMessage = 1;
      make_state_SSciLsCommand__root__SendingCommands(self, x);
      return;
    }
  }
}

void transition_from_SSciLsCommand__root(SSciLsCommand *self,
                                         SSciLsCommand__root__state_struct *x) {
  switch (x->state) {
  case SSciLsCommand__root__SendingCommands:
    transition_from_SSciLsCommand__root__SendingCommands(self, x);
    break;
  }
}

static void evaluateChangeEvents(SSciLsCommand *self) {
  self->Change1012.IsTriggered = self->T23inSignalAspect.IsTriggered;
  self->Change1013.IsTriggered = self->T23inSignalAspect.IsTriggered;
  self->Change1011.IsTriggered = self->T23inSignalAspect.IsTriggered;
  self->Change1024.IsTriggered = self->T25inLuminosity.IsTriggered;
  self->Change1022.IsTriggered = self->T25inLuminosity.IsTriggered;
}

static void resetOutputs(SSciLsCommand *self) {
  self->OutCdIndicateSignalAspect__e570.HasMessage = false;
  self->OutCdSetLuminosity__4570.HasMessage = false;
}

static void resetTriggers(SSciLsCommand *self) {

  self->T23inSignalAspect.IsTriggered = false;
  self->T25inLuminosity.IsTriggered = false;

  self->D24inIntentionallyDark.IsSignalled = false;
  self->D23inSignalAspect.IsSignalled = false;
  self->D25inLuminosity.IsSignalled = false;
}

void transition_SSciLsCommand(SSciLsCommand *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_SSciLsCommand__root(self, &self->state);
  resetTriggers(self);
}

void new_SSciLsCommand(SSciLsCommand *self) {
  make_state_SSciLsCommand__root(self, &self->state);
}
