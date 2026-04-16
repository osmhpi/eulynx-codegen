
#include "../../04_OutputC/SubsystemIo/SSciIoReceive.h"

void count_transitions_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
    int *ctr, SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__SwitchedOn) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOn))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 ==
             InputChannelState__a4d2__SwitchedOff) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOff))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__Disturbed) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__Disturbed))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 ==
             InputChannelState__a4d2__SwitchedOff) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOn))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__SwitchedOn) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOff))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 ==
             InputChannelState__a4d2__SwitchedOff) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__Disturbed))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__SwitchedOn) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__Disturbed))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__Disturbed) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOff))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgStateOfInputChannels__8132.HasMessage)
    {
        if ((self->InMsgStateOfInputChannels__8132.Value.ResportedInputState1 == InputChannelState__a4d2__Disturbed) &&
            (self->InMsgStateOfInputChannels__8132.Value.ResportedInputStateN == InputChannelState__a4d2__SwitchedOn))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates(
    int *ctr, SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{
    switch (x->ReceivingInputAndOutputChannelStates.ReceivingInputChannelStates.state)
    {
    case SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports:
        count_transitions_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates__ReceivingInputChannelReports(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports(
    int *ctr, SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgStateOfOutputChannels__c6d6.HasMessage)
    {
        if ((self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 ==
             OutputChannelDisturbanceState__bed9__PhysicallyDisturbed) &&
            (self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN ==
             OutputChannelDisturbanceState__bed9__PhysicallyDisturbed))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgStateOfOutputChannels__c6d6.HasMessage)
    {
        if ((self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 ==
             OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed) &&
            (self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN ==
             OutputChannelDisturbanceState__bed9__PhysicallyDisturbed))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgStateOfOutputChannels__c6d6.HasMessage)
    {
        if ((self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 ==
             OutputChannelDisturbanceState__bed9__PhysicallyDisturbed) &&
            (self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN ==
             OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgStateOfOutputChannels__c6d6.HasMessage)
    {
        if ((self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceState1 ==
             OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed) &&
            (self->InMsgStateOfOutputChannels__c6d6.Value.ResportedDisturbanceStateN ==
             OutputChannelDisturbanceState__bed9__NotPhysicallyDisturbed))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates(
    int *ctr, SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{
    switch (x->ReceivingInputAndOutputChannelStates.ReceivingOutputChannelStates.state)
    {
    case SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports:
        count_transitions_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates__ReceivingOutputChannelReports(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates(
    int *ctr, SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingInputChannelStates(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates__ReceivingOutputChannelStates(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change320.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciIoReceive__root(int *ctr, SSciIoReceive *self, SSciIoReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciIoReceive__root__ReceivingInputAndOutputChannelStates:
        count_transitions_from_SSciIoReceive__root__ReceivingInputAndOutputChannelStates(ctr, self, x);
        break;
    }
}

int count_transitions_SSciIoReceive(SSciIoReceive *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciIoReceive__root(&ctr, self, &self->state);
    return ctr;
}