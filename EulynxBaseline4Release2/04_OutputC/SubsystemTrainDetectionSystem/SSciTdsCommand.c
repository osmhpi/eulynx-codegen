
#include "SSciTdsCommand.h"

// Value Conversion Functions

// Operations

void make_state_SSciTdsCommand__root__SendingCommands(SSciTdsCommand *self, SSciTdsCommand__root__state_struct *region)
{
    LOG("[SSciTdsCommand] Entering state SendingCommands in region root");
    region->state = SSciTdsCommand__root__SendingCommands;
};

void make_state_SSciTdsCommand__root(SSciTdsCommand *self, SSciTdsCommand__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciTdsCommand__root__state_struct));

    make_state_SSciTdsCommand__root__SendingCommands(self, x);
    return;
}

void transition_from_SSciTdsCommand__root__SendingCommands(SSciTdsCommand *self, SSciTdsCommand__root__state_struct *x)
{

    if (self->Change1259.IsTriggered)
    {
        if ((self->D70inModeOfFc.Value == SSciTdsCommand_D70inModeOfFcValue__FcU) &&
            (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established))
        {

            self->OutCdFc__ec57.Value.CommandedModeOfFC = ModeOfFC__fc54__FcU;
            self->OutCdFc__ec57.HasMessage = 1;
            make_state_SSciTdsCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1260.IsTriggered)
    {
        if ((self->D70inModeOfFc.Value == SSciTdsCommand_D70inModeOfFcValue__FcP) &&
            (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established))
        {

            self->OutCdFc__ec57.Value.CommandedModeOfFC = ModeOfFC__fc54__FcP;
            self->OutCdFc__ec57.HasMessage = 1;
            make_state_SSciTdsCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1258.IsTriggered)
    {
        if ((self->D70inModeOfFc.Value == SSciTdsCommand_D70inModeOfFcValue__FcPA) &&
            (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established))
        {

            self->OutCdFc__ec57.Value.CommandedModeOfFC = ModeOfFC__fc54__FcPA;
            self->OutCdFc__ec57.HasMessage = 1;
            make_state_SSciTdsCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1257.IsTriggered)
    {
        if ((self->D70inModeOfFc.Value == SSciTdsCommand_D70inModeOfFcValue__AcknowledgementAfterFcPACommand) &&
            (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established))
        {

            self->OutCdFc__ec57.Value.CommandedModeOfFC = ModeOfFC__fc54__AcknowledgmentafterfcPACommand;
            self->OutCdFc__ec57.HasMessage = 1;
            make_state_SSciTdsCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1256.IsTriggered)
    {
        if ((self->D70inModeOfFc.Value == SSciTdsCommand_D70inModeOfFcValue__FcC) &&
            (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established))
        {

            self->OutCdFc__ec57.Value.CommandedModeOfFC = ModeOfFC__fc54__FcC;
            self->OutCdFc__ec57.HasMessage = 1;
            make_state_SSciTdsCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1261.IsTriggered)
    {
        if (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established)
        {

            self->OutCdUpdateFillingLevel__d24d.HasMessage = 1;
            make_state_SSciTdsCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1262.IsTriggered)
    {
        if (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established)
        {

            self->OutCdCancel__6acf.HasMessage = 1;
            make_state_SSciTdsCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1263.IsTriggered)
    {
        if (self->D50PdiConnectionState.Value == SSciTdsCommand_D50PdiConnectionStateValue__Established)
        {

            self->OutCdDrfc__15c7.HasMessage = 1;
            make_state_SSciTdsCommand__root__SendingCommands(self, x);
            return;
        }
    }
}

void transition_from_SSciTdsCommand__root(SSciTdsCommand *self, SSciTdsCommand__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciTdsCommand__root__SendingCommands:
        transition_from_SSciTdsCommand__root__SendingCommands(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciTdsCommand *self)
{
    self->Change1259.IsTriggered = self->T70inFc.IsTriggered;
    self->Change1260.IsTriggered = self->T70inFc.IsTriggered;
    self->Change1258.IsTriggered = self->T70inFc.IsTriggered;
    self->Change1257.IsTriggered = self->T70inFc.IsTriggered;
    self->Change1256.IsTriggered = self->T70inFc.IsTriggered;
    self->Change1261.IsTriggered = self->T72inUpdateFillingLevel.IsTriggered;
    self->Change1262.IsTriggered = self->T73inCancel.IsTriggered;
    self->Change1263.IsTriggered = self->T74inDrfc.IsTriggered;
}

static void resetOutputs(SSciTdsCommand *self)
{
    self->OutCdFc__ec57.HasMessage = false;
    self->OutCdUpdateFillingLevel__d24d.HasMessage = false;
    self->OutCdCancel__6acf.HasMessage = false;
    self->OutCdDrfc__15c7.HasMessage = false;
}

static void resetTriggers(SSciTdsCommand *self)
{

    self->T70inFc.IsTriggered = false;
    self->T72inUpdateFillingLevel.IsTriggered = false;
    self->T73inCancel.IsTriggered = false;
    self->T74inDrfc.IsTriggered = false;

    self->D70inModeOfFc.IsSignalled = false;
}

void transition_SSciTdsCommand(SSciTdsCommand *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciTdsCommand__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciTdsCommand(SSciTdsCommand *self)
{
    make_state_SSciTdsCommand__root(self, &self->state);
}
