
#include "SSciIoReceive.h"

// Value Conversion Functions

// Operations

void make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
    SSciIoReceive *self,
    SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__state_struct *region)
{
    LOG("[SSciIoReceive] Entering state ReceivingInputChannelReports in region "
        "root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates");
    region->state =
        SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports;
};

void make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates(
    SSciIoReceive *self,
    SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__state_struct *x)
{
    memset(
        x, 0,
        sizeof(SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__state_struct));
    self->D71outReportedInputChannelState1.Value = SSciIoReceive_D71outReportedInputChannelState1Value__Unknown;
    self->D71outReportedInputChannelState1.IsSignalled = true;
    self->D72outReportedInputChannelStaten.Value = SSciIoReceive_D72outReportedInputChannelStatenValue__Unknown;
    self->D72outReportedInputChannelStaten.IsSignalled = true;
    make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
        self, x);
    return;
}

void make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports(
    SSciIoReceive *self,
    SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__state_struct *region)
{
    LOG("[SSciIoReceive] Entering state ReceivingOutputChannelReports in region "
        "root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates");
    region->state =
        SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports;
};

void make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates(
    SSciIoReceive *self,
    SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__state_struct *x)
{
    memset(
        x, 0,
        sizeof(SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__state_struct));
    self->D91outReportedOutputChannelDisturbanceState1.Value =
        SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value__Unknown;
    self->D91outReportedOutputChannelDisturbanceState1.IsSignalled = true;
    self->D92outReportedOutputChannelDisturbanceStaten.Value =
        SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue__Unknown;
    self->D92outReportedOutputChannelDisturbanceStaten.IsSignalled = true;
    make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports(
        self, x);
    return;
}

void make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates(SSciIoReceive *self,
                                                                          SSciIoReceive__root__state_struct *region)
{
    LOG("[SSciIoReceive] Entering state ReceivingInputAndOutputChannelStates in region root");
    region->state = SSciIoReceive__root__ReceivingInputAndOutputChannelStates;
    make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates(
        self, &region->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates);
    make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates(
        self, &region->ReceivingInputAndOutputChannelStates.ReceivingOutputChannelStates);
};

void make_state_SSciIoReceive__root(SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciIoReceive__root__state_struct));

    make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates(self, x);
    return;
}

void transition_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
    SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{

    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__SwitchedOn) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOn))
        {
            self->D71outReportedInputChannelState1.Value =
                SSciIoReceive_D71outReportedInputChannelState1Value__SwitchedOn;
            self->D71outReportedInputChannelState1.IsSignalled = true;
            self->D72outReportedInputChannelStaten.Value =
                SSciIoReceive_D72outReportedInputChannelStatenValue__SwitchedOn;
            self->D72outReportedInputChannelStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates);
            return;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 ==
             InputChannelState__a4d2__SwitchedOff) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOff))
        {
            self->D71outReportedInputChannelState1.Value =
                SSciIoReceive_D71outReportedInputChannelState1Value__SwitchedOff;
            self->D71outReportedInputChannelState1.IsSignalled = true;
            self->D72outReportedInputChannelStaten.Value =
                SSciIoReceive_D72outReportedInputChannelStatenValue__SwitchedOff;
            self->D72outReportedInputChannelStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates);
            return;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__Disturbed) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__Disturbed))
        {
            self->D71outReportedInputChannelState1.Value =
                SSciIoReceive_D71outReportedInputChannelState1Value__Disturbed;
            self->D71outReportedInputChannelState1.IsSignalled = true;
            self->D72outReportedInputChannelStaten.Value =
                SSciIoReceive_D72outReportedInputChannelStatenValue__Disturbed;
            self->D72outReportedInputChannelStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates);
            return;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 ==
             InputChannelState__a4d2__SwitchedOff) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOn))
        {
            self->D71outReportedInputChannelState1.Value =
                SSciIoReceive_D71outReportedInputChannelState1Value__SwitchedOff;
            self->D71outReportedInputChannelState1.IsSignalled = true;
            self->D72outReportedInputChannelStaten.Value =
                SSciIoReceive_D72outReportedInputChannelStatenValue__SwitchedOn;
            self->D72outReportedInputChannelStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates);
            return;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__SwitchedOn) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOff))
        {
            self->D71outReportedInputChannelState1.Value =
                SSciIoReceive_D71outReportedInputChannelState1Value__SwitchedOn;
            self->D71outReportedInputChannelState1.IsSignalled = true;
            self->D72outReportedInputChannelStaten.Value =
                SSciIoReceive_D72outReportedInputChannelStatenValue__SwitchedOff;
            self->D72outReportedInputChannelStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates);
            return;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 ==
             InputChannelState__a4d2__SwitchedOff) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__Disturbed))
        {
            self->D71outReportedInputChannelState1.Value =
                SSciIoReceive_D71outReportedInputChannelState1Value__SwitchedOff;
            self->D71outReportedInputChannelState1.IsSignalled = true;
            self->D72outReportedInputChannelStaten.Value =
                SSciIoReceive_D72outReportedInputChannelStatenValue__Disturbed;
            self->D72outReportedInputChannelStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates);
            return;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__SwitchedOn) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__Disturbed))
        {
            self->D71outReportedInputChannelState1.Value =
                SSciIoReceive_D71outReportedInputChannelState1Value__SwitchedOn;
            self->D71outReportedInputChannelState1.IsSignalled = true;
            self->D72outReportedInputChannelStaten.Value =
                SSciIoReceive_D72outReportedInputChannelStatenValue__Disturbed;
            self->D72outReportedInputChannelStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates);
            return;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__Disturbed) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOff))
        {
            self->D71outReportedInputChannelState1.Value =
                SSciIoReceive_D71outReportedInputChannelState1Value__Disturbed;
            self->D71outReportedInputChannelState1.IsSignalled = true;
            self->D72outReportedInputChannelStaten.Value =
                SSciIoReceive_D72outReportedInputChannelStatenValue__SwitchedOff;
            self->D72outReportedInputChannelStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates);
            return;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__Disturbed) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOn))
        {
            self->D71outReportedInputChannelState1.Value =
                SSciIoReceive_D71outReportedInputChannelState1Value__Disturbed;
            self->D71outReportedInputChannelState1.IsSignalled = true;
            self->D72outReportedInputChannelStaten.Value =
                SSciIoReceive_D72outReportedInputChannelStatenValue__SwitchedOn;
            self->D72outReportedInputChannelStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates);
            return;
        }
    }
}

void transition_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates(
    SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{
    switch (x->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates.state)
    {
    case SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports:
        transition_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
            self, x);
        break;
    }
}

void transition_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports(
    SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{

    if (self->InMsgStateOfOutputChannels__c6d6.HasMessage)
    {
        if ((self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 ==
             OutputChannelDisturbanceState__bed9__PhysicallyDisturbed) &&
            (self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN ==
             OutputChannelDisturbanceState__bed9__PhysicallyDisturbed))
        {
            self->D91outReportedOutputChannelDisturbanceState1.Value =
                SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value__PhysicallyDisturbed;
            self->D91outReportedOutputChannelDisturbanceState1.IsSignalled = true;
            self->D92outReportedOutputChannelDisturbanceStaten.Value =
                SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue__PhysicallyDisturbed;
            self->D92outReportedOutputChannelDisturbanceStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingOutputChannelStates);
            return;
        }
    }
    if (self->InMsgStateOfOutputChannels__c6d6.HasMessage)
    {
        if ((self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 ==
             OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed) &&
            (self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN ==
             OutputChannelDisturbanceState__bed9__PhysicallyDisturbed))
        {
            self->D91outReportedOutputChannelDisturbanceState1.Value =
                SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed;
            self->D91outReportedOutputChannelDisturbanceState1.IsSignalled = true;
            self->D92outReportedOutputChannelDisturbanceStaten.Value =
                SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue__PhysicallyDisturbed;
            self->D92outReportedOutputChannelDisturbanceStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingOutputChannelStates);
            return;
        }
    }
    if (self->InMsgStateOfOutputChannels__c6d6.HasMessage)
    {
        if ((self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 ==
             OutputChannelDisturbanceState__bed9__PhysicallyDisturbed) &&
            (self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN ==
             OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed))
        {
            self->D91outReportedOutputChannelDisturbanceState1.Value =
                SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value__PhysicallyDisturbed;
            self->D91outReportedOutputChannelDisturbanceState1.IsSignalled = true;
            self->D92outReportedOutputChannelDisturbanceStaten.Value =
                SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed;
            self->D92outReportedOutputChannelDisturbanceStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingOutputChannelStates);
            return;
        }
    }
    if (self->InMsgStateOfOutputChannels__c6d6.HasMessage)
    {
        if ((self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 ==
             OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed) &&
            (self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN ==
             OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed))
        {
            self->D91outReportedOutputChannelDisturbanceState1.Value =
                SSciIoReceive_D91outReportedOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed;
            self->D91outReportedOutputChannelDisturbanceState1.IsSignalled = true;
            self->D92outReportedOutputChannelDisturbanceStaten.Value =
                SSciIoReceive_D92outReportedOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed;
            self->D92outReportedOutputChannelDisturbanceStaten.IsSignalled = true;
            make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports(
                self, &x->ReceivingInputAndOutputChannelStates.ReceivingOutputChannelStates);
            return;
        }
    }
}

void transition_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates(
    SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{
    switch (x->ReceivingInputAndOutputChannelStates.ReceivingOutputChannelStates.state)
    {
    case SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports:
        transition_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports(
            self, x);
        break;
    }
}

void transition_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates(SSciIoReceive *self,
                                                                               SSciIoReceive__root__state_struct *x)
{
    transition_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates(self, x);
    transition_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates(self, x);
    if (self->Change323.IsTriggered)
    {

        make_state_SSciIoReceive__root__ReceivingInputAndOutputChannelStates(self, x);
        return;
    }
}

void transition_from_SSciIoReceive__root(SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciIoReceive__root__ReceivingInputAndOutputChannelStates:
        transition_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciIoReceive *self)
{
    self->Change323.IsTriggered = IsTriggered(OrChange(
        OrChange(
            OrChange(MakeChange(self->D50inPdiConnectionState.IsSignalled,
                                self->D50inPdiConnectionState.Value ==
                                    SSciIoReceive_D50inPdiConnectionStateValue__Disconnected),
                     MakeChange(self->D50inPdiConnectionState.IsSignalled,
                                self->D50inPdiConnectionState.Value ==
                                    SSciIoReceive_D50inPdiConnectionStateValue__Impermissible)),
            MakeChange(self->D50inPdiConnectionState.IsSignalled,
                       self->D50inPdiConnectionState.Value == SSciIoReceive_D50inPdiConnectionStateValue__Suspended)),
        MakeChange(self->D50inPdiConnectionState.IsSignalled,
                   self->D50inPdiConnectionState.Value == SSciIoReceive_D50inPdiConnectionStateValue__RequestedNoScp)));
}

static void resetOutputs(SSciIoReceive *self)
{

    self->D71outReportedInputChannelState1.IsSignalled = false;
    self->D91outReportedOutputChannelDisturbanceState1.IsSignalled = false;
    self->D72outReportedInputChannelStaten.IsSignalled = false;
    self->D92outReportedOutputChannelDisturbanceStaten.IsSignalled = false;
}

static void resetTriggers(SSciIoReceive *self)
{
    self->InMsgStateOfInputChannels__8132.HasMessage = false;
    self->InMsgStateOfOutputChannels__c6d6.HasMessage = false;

    self->D50inPdiConnectionState.IsSignalled = false;
}

void transition_SSciIoReceive(SSciIoReceive *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciIoReceive__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciIoReceive(SSciIoReceive *self)
{
    make_state_SSciIoReceive__root(self, &self->state);
}
