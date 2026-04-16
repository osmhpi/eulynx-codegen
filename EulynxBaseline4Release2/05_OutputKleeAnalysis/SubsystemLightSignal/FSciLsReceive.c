
#include "../../04_OutputC/SubsystemLightSignal/FSciLsReceive.h"

void count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
    int *ctr, FSciLsReceive *self, FSciLsReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change311.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change581.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change584.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change587.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->InCdIndicateSignalAspect__e570.HasMessage)
    {
        if (self->InCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState ==
            SignalAspectControlableState__0dcc__SignalAspect2)
        {
            (*ctr)++;
        }
    }
    if (self->InCdIndicateSignalAspect__e570.HasMessage)
    {
        if (self->InCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState ==
            SignalAspectControlableState__0dcc__MostRestrictAspect)
        {
            (*ctr)++;
        }
    }
    if (self->InCdIndicateSignalAspect__e570.HasMessage)
    {
        if (self->InCdIndicateSignalAspect__e570.Value.CommandedSignalAspectState ==
            SignalAspectControlableState__0dcc__SignalAspect1)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect(
    int *ctr, FSciLsReceive *self, FSciLsReceive__root__state_struct *x)
{
    switch (x->ReceivingLightSignalCommands.ReceivingSignalAspect.state)
    {
    case FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects:
        count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect__ReceivingSignalAspects(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark(
    int *ctr, FSciLsReceive *self, FSciLsReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InCdIndicateSignalAspect__e570.HasMessage)
    {
        if ((self->InCdIndicateSignalAspect__e570.Value.CommandedDarkState == true) &&
            (self->D4inConIntentionallyDark.Value))
        {
            (*ctr)++;
        }
    }
    if (self->InCdIndicateSignalAspect__e570.HasMessage)
    {
        if (self->InCdIndicateSignalAspect__e570.Value.CommandedDarkState == false)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark(
    int *ctr, FSciLsReceive *self, FSciLsReceive__root__state_struct *x)
{
    switch (x->ReceivingLightSignalCommands.ReceivingIntentionallyDark.state)
    {
    case FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark:
        count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark__ReceivingIntentionallyDark(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity(
    int *ctr, FSciLsReceive *self, FSciLsReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change86.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change547.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change550.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->InCdSetLuminosity__4570.HasMessage)
    {
        if (self->InCdSetLuminosity__4570.Value.CommandedLuminosityState == LuminosityState__20ae__Day)
        {
            (*ctr)++;
        }
    }
    if (self->InCdSetLuminosity__4570.HasMessage)
    {
        if (self->InCdSetLuminosity__4570.Value.CommandedLuminosityState == LuminosityState__20ae__Night)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity(
    int *ctr, FSciLsReceive *self, FSciLsReceive__root__state_struct *x)
{
    switch (x->ReceivingLightSignalCommands.ReceivingLuminosity.state)
    {
    case FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity:
        count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity__ReceivingLuminosity(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands(int *ctr, FSciLsReceive *self,
                                                                              FSciLsReceive__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingSignalAspect(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingIntentionallyDark(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands__ReceivingLuminosity(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change332.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciLsReceive__root(int *ctr, FSciLsReceive *self, FSciLsReceive__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciLsReceive__root__ReceivingLightSignalCommands:
        count_transitions_from_FSciLsReceive__root__ReceivingLightSignalCommands(ctr, self, x);
        break;
    }
}

int count_transitions_FSciLsReceive(FSciLsReceive *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciLsReceive__root(&ctr, self, &self->state);
    return ctr;
}