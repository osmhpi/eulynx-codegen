
#include "SSciIoCommand.h"

// Value Conversion Functions

// Operations

void make_state_SSciIoCommand__root__SendingOutputChannelCommand(SSciIoCommand *self,
                                                                 SSciIoCommand__root__state_struct *region)
{
    LOG("[SSciIoCommand] Entering state SendingOutputChannelCommand in region root");
    region->state = SSciIoCommand__root__SendingOutputChannelCommand;
};

void make_state_SSciIoCommand__root(SSciIoCommand *self, SSciIoCommand__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciIoCommand__root__state_struct));

    make_state_SSciIoCommand__root__SendingOutputChannelCommand(self, x);
    return;
}

void transition_from_SSciIoCommand__root__SendingOutputChannelCommand(SSciIoCommand *self,
                                                                      SSciIoCommand__root__state_struct *x)
{

    if (self->Change1084.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOff) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOff)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputState1 =
                OutputChannelControllableState__80ea__SwitchedOff;
            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputStateN =
                OutputChannelControllableState__80ea__SwitchedOff;
            self->OutCdSetOutputChannels__3b5f.HasMessage = 1;
            make_state_SSciIoCommand__root__SendingOutputChannelCommand(self, x);
            return;
        }
    }
    if (self->Change1083.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOff) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOn)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputState1 =
                OutputChannelControllableState__80ea__SwitchedOff;
            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputStateN =
                OutputChannelControllableState__80ea__SwitchedOn;
            self->OutCdSetOutputChannels__3b5f.HasMessage = 1;
            make_state_SSciIoCommand__root__SendingOutputChannelCommand(self, x);
            return;
        }
    }
    if (self->Change1082.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOff) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__Flashing)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputState1 =
                OutputChannelControllableState__80ea__SwitchedOff;
            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputStateN =
                OutputChannelControllableState__80ea__Flashing;
            self->OutCdSetOutputChannels__3b5f.HasMessage = 1;
            make_state_SSciIoCommand__root__SendingOutputChannelCommand(self, x);
            return;
        }
    }
    if (self->Change1081.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOn) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOn)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputState1 =
                OutputChannelControllableState__80ea__SwitchedOn;
            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputStateN =
                OutputChannelControllableState__80ea__SwitchedOn;
            self->OutCdSetOutputChannels__3b5f.HasMessage = 1;
            make_state_SSciIoCommand__root__SendingOutputChannelCommand(self, x);
            return;
        }
    }
    if (self->Change1078.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOn) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOff)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputState1 =
                OutputChannelControllableState__80ea__SwitchedOn;
            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputStateN =
                OutputChannelControllableState__80ea__SwitchedOff;
            self->OutCdSetOutputChannels__3b5f.HasMessage = 1;
            make_state_SSciIoCommand__root__SendingOutputChannelCommand(self, x);
            return;
        }
    }
    if (self->Change1077.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__SwitchedOn) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__Flashing)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputState1 =
                OutputChannelControllableState__80ea__SwitchedOn;
            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputStateN =
                OutputChannelControllableState__80ea__Flashing;
            self->OutCdSetOutputChannels__3b5f.HasMessage = 1;
            make_state_SSciIoCommand__root__SendingOutputChannelCommand(self, x);
            return;
        }
    }
    if (self->Change1076.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__Flashing) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__Flashing)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputState1 =
                OutputChannelControllableState__80ea__Flashing;
            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputStateN =
                OutputChannelControllableState__80ea__Flashing;
            self->OutCdSetOutputChannels__3b5f.HasMessage = 1;
            make_state_SSciIoCommand__root__SendingOutputChannelCommand(self, x);
            return;
        }
    }
    if (self->Change1079.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__Flashing) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOn)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputState1 =
                OutputChannelControllableState__80ea__Flashing;
            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputStateN =
                OutputChannelControllableState__80ea__SwitchedOn;
            self->OutCdSetOutputChannels__3b5f.HasMessage = 1;
            make_state_SSciIoCommand__root__SendingOutputChannelCommand(self, x);
            return;
        }
    }
    if (self->Change1080.IsTriggered)
    {
        if (((self->D31inRequiredChannelState1.Value == SSciIoCommand_D31inRequiredChannelState1Value__Flashing) &&
             (self->D32inRequiredChannelStaten.Value == SSciIoCommand_D32inRequiredChannelStatenValue__SwitchedOff)) &&
            (self->D50inPdiConnectionState.Value == SSciIoCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputState1 =
                OutputChannelControllableState__80ea__Flashing;
            self->OutCdSetOutputChannels__3b5f.Value.CommandedOutputStateN =
                OutputChannelControllableState__80ea__SwitchedOff;
            self->OutCdSetOutputChannels__3b5f.HasMessage = 1;
            make_state_SSciIoCommand__root__SendingOutputChannelCommand(self, x);
            return;
        }
    }
}

void transition_from_SSciIoCommand__root(SSciIoCommand *self, SSciIoCommand__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciIoCommand__root__SendingOutputChannelCommand:
        transition_from_SSciIoCommand__root__SendingOutputChannelCommand(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciIoCommand *self)
{
    self->Change1084.IsTriggered = self->T30inNewOutputChannelStateRequired.IsTriggered;
    self->Change1083.IsTriggered = self->T30inNewOutputChannelStateRequired.IsTriggered;
    self->Change1082.IsTriggered = self->T30inNewOutputChannelStateRequired.IsTriggered;
    self->Change1081.IsTriggered = self->T30inNewOutputChannelStateRequired.IsTriggered;
    self->Change1078.IsTriggered = self->T30inNewOutputChannelStateRequired.IsTriggered;
    self->Change1077.IsTriggered = self->T30inNewOutputChannelStateRequired.IsTriggered;
    self->Change1076.IsTriggered = self->T30inNewOutputChannelStateRequired.IsTriggered;
    self->Change1079.IsTriggered = self->T30inNewOutputChannelStateRequired.IsTriggered;
    self->Change1080.IsTriggered = self->T30inNewOutputChannelStateRequired.IsTriggered;
}

static void resetOutputs(SSciIoCommand *self)
{
    self->OutCdSetOutputChannels__3b5f.HasMessage = false;
}

static void resetTriggers(SSciIoCommand *self)
{

    self->T30inNewOutputChannelStateRequired.IsTriggered = false;

    self->D31inRequiredChannelState1.IsSignalled = false;
    self->D50inPdiConnectionState.IsSignalled = false;
    self->D32inRequiredChannelStaten.IsSignalled = false;
}

void transition_SSciIoCommand(SSciIoCommand *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciIoCommand__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciIoCommand(SSciIoCommand *self)
{
    make_state_SSciIoCommand__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemGenericIo/SSciIoCommand.c"
#endif
