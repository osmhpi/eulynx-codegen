
#include "SSciLsCommandExpl.h"

// Value Conversion Functions

// Operations

void make_state_SSciLsCommandExpl__root__SendingCommands(SSciLsCommandExpl *self,
                                                         SSciLsCommandExpl__root__state_struct *region)
{
    LOG("[SSciLsCommandExpl] Entering state SendingCommands in region root");
    region->state = SSciLsCommandExpl__root__SendingCommands;
};

void make_state_SSciLsCommandExpl__root(SSciLsCommandExpl *self, SSciLsCommandExpl__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciLsCommandExpl__root__state_struct));

    make_state_SSciLsCommandExpl__root__SendingCommands(self, x);
    return;
}

void transition_from_SSciLsCommandExpl__root__SendingCommands(SSciLsCommandExpl *self,
                                                              SSciLsCommandExpl__root__state_struct *x)
{

    if (self->Change1003.IsTriggered)
    {
        if ((self->D23inSignalAspect.Value == SSciLsCommandExpl_D23inSignalAspectValue__SignalAspect2) &&
            (self->D9PdiConnectionState.Value == SSciLsCommandExpl_D9PdiConnectionStateValue__Established))
        {

            self->OutCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState =
                SignalAspectControlableState__0dcc__SignalAspect2;
            self->OutCdIndicateSignalAspect__e570.Value.CommandedDarkState = self->D24inIntentionallyDark.Value;
            self->OutCdIndicateSignalAspect__e570.HasMessage = 1;
            make_state_SSciLsCommandExpl__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1007.IsTriggered)
    {
        if ((self->D23inSignalAspect.Value == SSciLsCommandExpl_D23inSignalAspectValue__MostRestrictAspect) &&
            (self->D9PdiConnectionState.Value == SSciLsCommandExpl_D9PdiConnectionStateValue__Established))
        {

            self->OutCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState =
                SignalAspectControlableState__0dcc__MostRestrictAspect;
            self->OutCdIndicateSignalAspect__e570.Value.CommandedDarkState = self->D24inIntentionallyDark.Value;
            self->OutCdIndicateSignalAspect__e570.HasMessage = 1;
            make_state_SSciLsCommandExpl__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1008.IsTriggered)
    {
        if ((self->D23inSignalAspect.Value == SSciLsCommandExpl_D23inSignalAspectValue__SignalAspect1) &&
            (self->D9PdiConnectionState.Value == SSciLsCommandExpl_D9PdiConnectionStateValue__Established))
        {

            self->OutCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState =
                SignalAspectControlableState__0dcc__SignalAspect1;
            self->OutCdIndicateSignalAspect__e570.Value.CommandedDarkState = self->D24inIntentionallyDark.Value;
            self->OutCdIndicateSignalAspect__e570.HasMessage = 1;
            make_state_SSciLsCommandExpl__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1015.IsTriggered)
    {
        if ((self->D25inLuminosity.Value == SSciLsCommandExpl_D25inLuminosityValue__Night) &&
            (self->D9PdiConnectionState.Value == SSciLsCommandExpl_D9PdiConnectionStateValue__Established))
        {

            self->OutCdSetLuminosity__4570.Value.CommandedLuminosityState = LuminosityState__20ae__Night;
            self->OutCdSetLuminosity__4570.HasMessage = 1;
            make_state_SSciLsCommandExpl__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1017.IsTriggered)
    {
        if ((self->D25inLuminosity.Value == SSciLsCommandExpl_D25inLuminosityValue__Day) &&
            (self->D9PdiConnectionState.Value == SSciLsCommandExpl_D9PdiConnectionStateValue__Established))
        {

            self->OutCdSetLuminosity__4570.Value.CommandedLuminosityState = LuminosityState__20ae__Day;
            self->OutCdSetLuminosity__4570.HasMessage = 1;
            make_state_SSciLsCommandExpl__root__SendingCommands(self, x);
            return;
        }
    }
}

void transition_from_SSciLsCommandExpl__root(SSciLsCommandExpl *self, SSciLsCommandExpl__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciLsCommandExpl__root__SendingCommands:
        transition_from_SSciLsCommandExpl__root__SendingCommands(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciLsCommandExpl *self)
{
    self->Change1003.IsTriggered = self->T23inSignalAspect.IsTriggered;
    self->Change1007.IsTriggered = self->T23inSignalAspect.IsTriggered;
    self->Change1008.IsTriggered = self->T23inSignalAspect.IsTriggered;
    self->Change1015.IsTriggered = self->T25inLuminosity.IsTriggered;
    self->Change1017.IsTriggered = self->T25inLuminosity.IsTriggered;
}

static void resetOutputs(SSciLsCommandExpl *self)
{
    self->OutCdIndicateSignalAspect__e570.HasMessage = false;
    self->OutCdSetLuminosity__4570.HasMessage = false;
}

static void resetTriggers(SSciLsCommandExpl *self)
{

    self->T23inSignalAspect.IsTriggered = false;
    self->T25inLuminosity.IsTriggered = false;
    self->T5SignalAspect.IsTriggered = false;
    self->T6Luminosity.IsTriggered = false;

    self->D24inIntentionallyDark.IsSignalled = false;
    self->D23inSignalAspect.IsSignalled = false;
    self->D25inLuminosity.IsSignalled = false;
}

void transition_SSciLsCommandExpl(SSciLsCommandExpl *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciLsCommandExpl__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciLsCommandExpl(SSciLsCommandExpl *self)
{
    make_state_SSciLsCommandExpl__root(self, &self->state);
}
