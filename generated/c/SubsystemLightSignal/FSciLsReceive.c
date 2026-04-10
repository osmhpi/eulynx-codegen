
#include "FSciLsReceive.h"

// Value Conversion Functions

// Operations

void make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
    FSciLsReceive *self,
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__state_struct
        *region) {
  LOG("[FSciLsReceive] Entering state ReceivingSignalAspects in region "
      "root__ReceivingLightSignalCommands__ReceivingSignalAspect");
  region->state =
      FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects;
};

void make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect(
    FSciLsReceive *self,
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__state_struct
        *x) {
  memset(
      x, 0,
      sizeof(
          FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__state_struct));
  self->D2outRequiredSignalAspect.Value =
      FSciLsReceive_D2outRequiredSignalAspectValue__Unknown;
  self->D2outRequiredSignalAspect.IsSignalled = true;
  make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
      self, x);
  return;
}

void make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark(
    FSciLsReceive *self,
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__state_struct
        *region) {
  LOG("[FSciLsReceive] Entering state ReceivingIntentionallyDark in region "
      "root__ReceivingLightSignalCommands__ReceivingIntentionallyDark");
  region->state =
      FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark;
};

void make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark(
    FSciLsReceive *self,
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__state_struct
        *x) {
  memset(
      x, 0,
      sizeof(
          FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__state_struct));
  self->D3outRequiredIntentionallyDark.Value = false;
  make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark(
      self, x);
  return;
}

void make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity(
    FSciLsReceive *self,
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__state_struct
        *region) {
  LOG("[FSciLsReceive] Entering state ReceivingLuminosity in region "
      "root__ReceivingLightSignalCommands__ReceivingLuminosity");
  region->state =
      FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity;
};

void make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity(
    FSciLsReceive *self,
    FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__state_struct
        *x) {
  memset(
      x, 0,
      sizeof(
          FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__state_struct));
  self->D11outRequiredLuminosity.Value =
      FSciLsReceive_D11outRequiredLuminosityValue__Unknown;
  self->D11outRequiredLuminosity.IsSignalled = true;
  make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity(
      self, x);
  return;
}

void make_state_FSciLsReceive__root__ReceivingLightSignalCommands(
    FSciLsReceive *self, FSciLsReceive__root__state_struct *region) {
  LOG("[FSciLsReceive] Entering state ReceivingLightSignalCommands in region "
      "root");
  region->state = FSciLsReceive__root__ReceivingLightSignalCommands;
  make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect(
      self, &region->ReceivingLightSignalCommands.ReceivingSignalAspect);
  make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark(
      self, &region->ReceivingLightSignalCommands.ReceivingIntentionallyDark);
  make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity(
      self, &region->ReceivingLightSignalCommands.ReceivingLuminosity);
};

void make_state_FSciLsReceive__root(FSciLsReceive *self,
                                    FSciLsReceive__root__state_struct *x) {
  memset(x, 0, sizeof(FSciLsReceive__root__state_struct));

  make_state_FSciLsReceive__root__ReceivingLightSignalCommands(self, x);
  return;
}

void transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
    FSciLsReceive *self, FSciLsReceive__root__state_struct *x) {

  if (self->Change288.IsTriggered) {
    self->D2outRequiredSignalAspect.Value =
        FSciLsReceive_D2outRequiredSignalAspectValue__Unknown;
    self->D2outRequiredSignalAspect.IsSignalled = true;
    make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
        self, &x->ReceivingLightSignalCommands.ReceivingSignalAspect);
    return;
  }
  if (self->Change573.IsTriggered) {
    self->D2outRequiredSignalAspect.Value =
        FSciLsReceive_D2outRequiredSignalAspectValue__Unknown;
    self->D2outRequiredSignalAspect.IsSignalled = true;
    make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
        self, &x->ReceivingLightSignalCommands.ReceivingSignalAspect);
    return;
  }
  if (self->Change574.IsTriggered) {
    self->D2outRequiredSignalAspect.Value =
        FSciLsReceive_D2outRequiredSignalAspectValue__Unknown;
    self->D2outRequiredSignalAspect.IsSignalled = true;
    make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
        self, &x->ReceivingLightSignalCommands.ReceivingSignalAspect);
    return;
  }
  if (self->Change578.IsTriggered) {
    self->D2outRequiredSignalAspect.Value =
        FSciLsReceive_D2outRequiredSignalAspectValue__Unknown;
    self->D2outRequiredSignalAspect.IsSignalled = true;
    make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
        self, &x->ReceivingLightSignalCommands.ReceivingSignalAspect);
    return;
  }
  if (self->InCdIndicateSignalAspect__e570.HasMessage) {
    if (self->InCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState ==
        SignalAspectControlableState__0dcc__SignalAspect2) {
      self->D2outRequiredSignalAspect.Value =
          FSciLsReceive_D2outRequiredSignalAspectValue__SignalAspect2;
      self->D2outRequiredSignalAspect.IsSignalled = true;
      make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
          self, &x->ReceivingLightSignalCommands.ReceivingSignalAspect);
      return;
    }
  }
  if (self->InCdIndicateSignalAspect__e570.HasMessage) {
    if (self->InCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState ==
        SignalAspectControlableState__0dcc__MostRestrictAspect) {
      self->D2outRequiredSignalAspect.Value =
          FSciLsReceive_D2outRequiredSignalAspectValue__MostRestrictAspect;
      self->D2outRequiredSignalAspect.IsSignalled = true;
      make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
          self, &x->ReceivingLightSignalCommands.ReceivingSignalAspect);
      return;
    }
  }
  if (self->InCdIndicateSignalAspect__e570.HasMessage) {
    if (self->InCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState ==
        SignalAspectControlableState__0dcc__SignalAspect1) {
      self->D2outRequiredSignalAspect.Value =
          FSciLsReceive_D2outRequiredSignalAspectValue__SignalAspect1;
      self->D2outRequiredSignalAspect.IsSignalled = true;
      make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
          self, &x->ReceivingLightSignalCommands.ReceivingSignalAspect);
      return;
    }
  }
}

void transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect(
    FSciLsReceive *self, FSciLsReceive__root__state_struct *x) {
  switch (x->ReceivingLightSignalCommands.ReceivingSignalAspect.state) {
  case FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects:
    transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
        self, x);
    break;
  }
}

void transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark(
    FSciLsReceive *self, FSciLsReceive__root__state_struct *x) {

  if (self->InCdIndicateSignalAspect__e570.HasMessage) {
    if ((self->InCdIndicateSignalAspect__e570.Value.CommandedDarkState ==
         true) &&
        (self->D4inConIntentionallyDark.Value)) {
      self->D3outRequiredIntentionallyDark.Value = true;
      make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark(
          self, &x->ReceivingLightSignalCommands.ReceivingIntentionallyDark);
      return;
    }
  }
  if (self->InCdIndicateSignalAspect__e570.HasMessage) {
    if (self->InCdIndicateSignalAspect__e570.Value.CommandedDarkState ==
        false) {
      self->D3outRequiredIntentionallyDark.Value = false;
      make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark(
          self, &x->ReceivingLightSignalCommands.ReceivingIntentionallyDark);
      return;
    }
  }
}

void transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark(
    FSciLsReceive *self, FSciLsReceive__root__state_struct *x) {
  switch (x->ReceivingLightSignalCommands.ReceivingIntentionallyDark.state) {
  case FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark:
    transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark(
        self, x);
    break;
  }
}

void transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity(
    FSciLsReceive *self, FSciLsReceive__root__state_struct *x) {

  if (self->Change94.IsTriggered) {
    self->D11outRequiredLuminosity.Value =
        FSciLsReceive_D11outRequiredLuminosityValue__Unknown;
    self->D11outRequiredLuminosity.IsSignalled = true;
    make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity(
        self, &x->ReceivingLightSignalCommands.ReceivingLuminosity);
    return;
  }
  if (self->Change541.IsTriggered) {
    self->D11outRequiredLuminosity.Value =
        FSciLsReceive_D11outRequiredLuminosityValue__Unknown;
    self->D11outRequiredLuminosity.IsSignalled = true;
    make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity(
        self, &x->ReceivingLightSignalCommands.ReceivingLuminosity);
    return;
  }
  if (self->Change544.IsTriggered) {
    self->D11outRequiredLuminosity.Value =
        FSciLsReceive_D11outRequiredLuminosityValue__Unknown;
    self->D11outRequiredLuminosity.IsSignalled = true;
    make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity(
        self, &x->ReceivingLightSignalCommands.ReceivingLuminosity);
    return;
  }
  if (self->InCdSetLuminosity__4570.HasMessage) {
    if (self->InCdSetLuminosity__4570.Value.CommandedLuminosityState ==
        LuminosityState__20ae__Day) {
      self->D11outRequiredLuminosity.Value =
          FSciLsReceive_D11outRequiredLuminosityValue__Day;
      self->D11outRequiredLuminosity.IsSignalled = true;
      make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity(
          self, &x->ReceivingLightSignalCommands.ReceivingLuminosity);
      return;
    }
  }
  if (self->InCdSetLuminosity__4570.HasMessage) {
    if (self->InCdSetLuminosity__4570.Value.CommandedLuminosityState ==
        LuminosityState__20ae__Night) {
      self->D11outRequiredLuminosity.Value =
          FSciLsReceive_D11outRequiredLuminosityValue__Night;
      self->D11outRequiredLuminosity.IsSignalled = true;
      make_state_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity(
          self, &x->ReceivingLightSignalCommands.ReceivingLuminosity);
      return;
    }
  }
}

void transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity(
    FSciLsReceive *self, FSciLsReceive__root__state_struct *x) {
  switch (x->ReceivingLightSignalCommands.ReceivingLuminosity.state) {
  case FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity:
    transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity(
        self, x);
    break;
  }
}

void transition_from_FSciLsReceive__root__ReceivingLightSignalCommands(
    FSciLsReceive *self, FSciLsReceive__root__state_struct *x) {
  transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect(
      self, x);
  transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark(
      self, x);
  transition_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity(
      self, x);
  if (self->Change311.IsTriggered) {

    make_state_FSciLsReceive__root__ReceivingLightSignalCommands(self, x);
    return;
  }
}

void transition_from_FSciLsReceive__root(FSciLsReceive *self,
                                         FSciLsReceive__root__state_struct *x) {
  switch (x->state) {
  case FSciLsReceive__root__ReceivingLightSignalCommands:
    transition_from_FSciLsReceive__root__ReceivingLightSignalCommands(self, x);
    break;
  }
}

static void evaluateChangeEvents(FSciLsReceive *self) {
  self->Change288.IsTriggered = IsTriggered(
      OrChange(OrChange(MakeChange(self->D4inFaultLampsAspect1.IsSignalled,
                                   self->D4inFaultLampsAspect1.Value),
                        MakeChange(self->D5inFaultLampsAspect2.IsSignalled,
                                   self->D5inFaultLampsAspect2.Value)),
               MakeChange(self->D6inFaultLampsMostRestrict.IsSignalled,
                          self->D6inFaultLampsMostRestrict.Value)));
  self->Change573.IsTriggered = IsTriggered(
      NegateChange(MakeChange(self->D4inFaultLampsAspect1.IsSignalled,
                              self->D4inFaultLampsAspect1.Value)));
  self->Change574.IsTriggered = IsTriggered(
      NegateChange(MakeChange(self->D5inFaultLampsAspect2.IsSignalled,
                              self->D5inFaultLampsAspect2.Value)));
  self->Change578.IsTriggered = IsTriggered(
      NegateChange(MakeChange(self->D6inFaultLampsMostRestrict.IsSignalled,
                              self->D6inFaultLampsMostRestrict.Value)));
  self->Change94.IsTriggered = IsTriggered(
      OrChange(MakeChange(self->D13inLuminosityDayFault.IsSignalled,
                          self->D13inLuminosityDayFault.Value),
               MakeChange(self->D14inLuminosityNightFault.IsSignalled,
                          self->D14inLuminosityNightFault.Value)));
  self->Change541.IsTriggered = IsTriggered(
      NegateChange(MakeChange(self->D13inLuminosityDayFault.IsSignalled,
                              self->D13inLuminosityDayFault.Value)));
  self->Change544.IsTriggered = IsTriggered(
      NegateChange(MakeChange(self->D14inLuminosityNightFault.IsSignalled,
                              self->D14inLuminosityNightFault.Value)));
  self->Change311.IsTriggered = IsTriggered(OrChange(
      OrChange(
          MakeChange(
              self->D50inPdiConnectionState.IsSignalled,
              self->D50inPdiConnectionState.Value ==
                  FSciLsReceive_D50inPdiConnectionStateValue__ReadyForPdiNoScp),
          MakeChange(
              self->D50inPdiConnectionState.IsSignalled,
              self->D50inPdiConnectionState.Value ==
                  FSciLsReceive_D50inPdiConnectionStateValue__ReadyForPdi)),
      MakeChange(self->D50inPdiConnectionState.IsSignalled,
                 self->D50inPdiConnectionState.Value ==
                     FSciLsReceive_D50inPdiConnectionStateValue__Suspended)));
}

static void resetOutputs(FSciLsReceive *self) {

  self->D2outRequiredSignalAspect.IsSignalled = false;
  self->D3outRequiredIntentionallyDark.IsSignalled = false;
  self->D11outRequiredLuminosity.IsSignalled = false;
}

static void resetTriggers(FSciLsReceive *self) {
  self->InCdIndicateSignalAspect__e570.HasMessage = false;
  self->InCdSetLuminosity__4570.HasMessage = false;

  self->D50inPdiConnectionState.IsSignalled = false;
  self->D4inConIntentionallyDark.IsSignalled = false;
  self->D13inLuminosityDayFault.IsSignalled = false;
  self->D14inLuminosityNightFault.IsSignalled = false;
  self->D4inFaultLampsAspect1.IsSignalled = false;
  self->D5inFaultLampsAspect2.IsSignalled = false;
  self->D6inFaultLampsMostRestrict.IsSignalled = false;
}

void transition_FSciLsReceive(FSciLsReceive *self) {
  resetOutputs(self);
  evaluateChangeEvents(self);
  transition_from_FSciLsReceive__root(self, &self->state);
  resetTriggers(self);
}

void new_FSciLsReceive(FSciLsReceive *self) {
  make_state_FSciLsReceive__root(self, &self->state);
}
