
#include "../../04_OutputC/SubsystemGenericIo/FSciIoReceive.h"

void count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__RequiredOutputChannel1StateCanNotBeSet(
    int *ctr, FSciIoReceive *self, FSciIoReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change498.IsTriggered)
    {
        if (!(self->D13inSwitchOffEachPhysicalOutputChannel.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change543.IsTriggered)
    {
        if (self->D9inMonitoredOutputChannelDisturbanceState1.Value ==
            FSciIoReceive_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1(
    int *ctr, FSciIoReceive *self, FSciIoReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (true)
    {
        (*ctr)++;
    }
    if (self->Change104.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->InCdSetOutputChannels__3b5f.HasMessage)
    {
        if (self->InCdSetOutputChannels__3b5f.Value.CommandedOutputState1 ==
            OutputChannelControllableState__80ea__SwitchedOff)
        {
            (*ctr)++;
        }
    }
    if (self->InCdSetOutputChannels__3b5f.HasMessage)
    {
        if ((self->InCdSetOutputChannels__3b5f.Value.CommandedOutputState1 ==
             OutputChannelControllableState__80ea__Flashing) &&
            (self->D24inConFlashing.Value))
        {
            (*ctr)++;
        }
    }
    if (self->InCdSetOutputChannels__3b5f.HasMessage)
    {
        if (self->InCdSetOutputChannels__3b5f.Value.CommandedOutputState1 ==
            OutputChannelControllableState__80ea__SwitchedOn)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1(
    int *ctr, FSciIoReceive *self, FSciIoReceive__root__state_struct *x)
{
    switch (x->ReceivingCommands.OutputChannelState1.state)
    {
    case FSciIoReceive__root__ReceivingCommands__OutputChannelState1__RequiredOutputChannel1StateCanNotBeSet:
        count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__RequiredOutputChannel1StateCanNotBeSet(
            ctr, self, x);
        break;
    case FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1:
        count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1__ReceivingCommandsChannel1(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__RequiredOutputChannelNStateCanNotBeSet(
    int *ctr, FSciIoReceive *self, FSciIoReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change493.IsTriggered)
    {
        if (!(self->D13inSwitchOffEachPhysicalOutputChannel.Value))
        {
            (*ctr)++;
        }
    }
    if (self->Change542.IsTriggered)
    {
        if (self->D9inMonitoredOutputChannelDisturbanceStaten.Value ==
            FSciIoReceive_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN(
    int *ctr, FSciIoReceive *self, FSciIoReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (true)
    {
        (*ctr)++;
    }
    if (self->Change106.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->InCdSetOutputChannels__3b5f.HasMessage)
    {
        if (self->InCdSetOutputChannels__3b5f.Value.CommandedOutputStateN ==
            OutputChannelControllableState__80ea__SwitchedOff)
        {
            (*ctr)++;
        }
    }
    if (self->InCdSetOutputChannels__3b5f.HasMessage)
    {
        if ((self->InCdSetOutputChannels__3b5f.Value.CommandedOutputStateN ==
             OutputChannelControllableState__80ea__Flashing) &&
            (self->D24inConFlashing.Value))
        {
            (*ctr)++;
        }
    }
    if (self->InCdSetOutputChannels__3b5f.HasMessage)
    {
        if (self->InCdSetOutputChannels__3b5f.Value.CommandedOutputStateN ==
            OutputChannelControllableState__80ea__SwitchedOn)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN(
    int *ctr, FSciIoReceive *self, FSciIoReceive__root__state_struct *x)
{
    switch (x->ReceivingCommands.OutputChannelStateN.state)
    {
    case FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__RequiredOutputChannelNStateCanNotBeSet:
        count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__RequiredOutputChannelNStateCanNotBeSet(
            ctr, self, x);
        break;
    case FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN:
        count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN__ReceivingCommandsChannelN(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciIoReceive__root__ReceivingCommands(int *ctr, FSciIoReceive *self,
                                                                   FSciIoReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelState1(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FSciIoReceive__root__ReceivingCommands__OutputChannelStateN(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change317.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciIoReceive__root__InterfaceConnectionClosed(int *ctr, FSciIoReceive *self,
                                                                           FSciIoReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change305.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciIoReceive__root(int *ctr, FSciIoReceive *self, FSciIoReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciIoReceive__root__ReceivingCommands:
        count_transitions_from_FSciIoReceive__root__ReceivingCommands(ctr, self, x);
        break;
    case FSciIoReceive__root__InterfaceConnectionClosed:
        count_transitions_from_FSciIoReceive__root__InterfaceConnectionClosed(ctr, self, x);
        break;
    }
}

int count_transitions_FSciIoReceive(FSciIoReceive *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciIoReceive__root(&ctr, self, &self->state);
    return ctr;
}