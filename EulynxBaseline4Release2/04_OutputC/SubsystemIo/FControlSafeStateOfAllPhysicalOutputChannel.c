
#include "FControlSafeStateOfAllPhysicalOutputChannel.h"

// Value Conversion Functions

// Operations

void make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel(
    FControlSafeStateOfAllPhysicalOutputChannel *self,
    FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct *region)
{
    LOG("[FControlSafeStateOfAllPhysicalOutputChannel] Entering state "
        "NotSwitchedOffAllPhysicalOutputChannel in region root");
    region->state = FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel;
};

void make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel(
    FControlSafeStateOfAllPhysicalOutputChannel *self,
    FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct *region)
{
    LOG("[FControlSafeStateOfAllPhysicalOutputChannel] Entering state "
        "SwitchedOffAllPhysicalOutputChannel in region root");
    region->state = FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel;
};

void make_state_FControlSafeStateOfAllPhysicalOutputChannel__root(
    FControlSafeStateOfAllPhysicalOutputChannel *self,
    FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct));
    self->D13outSwitchOffEachPhysicalOuputChannel.Value = false;
    make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel(self, x);
    return;
}

void transition_from_FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel(
    FControlSafeStateOfAllPhysicalOutputChannel *self,
    FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct *x)
{

    if (self->Change357.IsTriggered)
    {
        self->D13outSwitchOffEachPhysicalOuputChannel.Value = true;
        make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel(self, x);
        return;
    }
    if (self->Change371.IsTriggered)
    {
        self->D13outSwitchOffEachPhysicalOuputChannel.Value = true;
        make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel(self, x);
        return;
    }
    if (self->Change382.IsTriggered)
    {
        self->D13outSwitchOffEachPhysicalOuputChannel.Value = true;
        make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel(self, x);
        return;
    }
    if (self->Change387.IsTriggered)
    {
        self->D13outSwitchOffEachPhysicalOuputChannel.Value = true;
        make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel(self, x);
        return;
    }
    if (self->Change498.IsTriggered)
    {
        if ((self->D600inConDisturbanceSwitchOffAll.Value) &&
            (self->D51inEstEfesState.Value ==
             FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Operational))
        {
            self->D13outSwitchOffEachPhysicalOuputChannel.Value = true;
            make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel(self, x);
            return;
        }
    }
    if (self->Change506.IsTriggered)
    {
        if ((self->D600inConDisturbanceSwitchOffAll.Value) &&
            (self->D51inEstEfesState.Value ==
             FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Operational))
        {
            self->D13outSwitchOffEachPhysicalOuputChannel.Value = true;
            make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel(self, x);
            return;
        }
    }
}

void transition_from_FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel(
    FControlSafeStateOfAllPhysicalOutputChannel *self,
    FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct *x)
{

    if (self->Change400.IsTriggered)
    {
        if (((self->D600inConDisturbanceSwitchOffAll.Value) &&
             (self->D9inMonitoredOutputChannelDisturbanceState1.Value ==
              FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed)) &&
            (self->D9inMonitoredOutputChannelDisturbanceStaten.Value ==
             FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed))
        {
            self->D13outSwitchOffEachPhysicalOuputChannel.Value = false;
            make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel(self,
                                                                                                                 x);
            return;
        }
    }
    if (self->Change396.IsTriggered)
    {
        if (!(self->D600inConDisturbanceSwitchOffAll.Value))
        {
            self->D13outSwitchOffEachPhysicalOuputChannel.Value = false;
            make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel(self,
                                                                                                                 x);
            return;
        }
    }
    if (self->Change501.IsTriggered)
    {
        if ((self->D600inConDisturbanceSwitchOffAll.Value) &&
            (self->D51inEstEfesState.Value ==
             FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Operational))
        {
            self->D13outSwitchOffEachPhysicalOuputChannel.Value = false;
            make_state_FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel(self,
                                                                                                                 x);
            return;
        }
    }
}

void transition_from_FControlSafeStateOfAllPhysicalOutputChannel__root(
    FControlSafeStateOfAllPhysicalOutputChannel *self,
    FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel:
        transition_from_FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel(self,
                                                                                                                  x);
        break;
    case FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel:
        transition_from_FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel(self, x);
        break;
    }
}

static void evaluateChangeEvents(FControlSafeStateOfAllPhysicalOutputChannel *self)
{
    self->Change357.IsTriggered = IsTriggered(MakeChange(
        self->D51inEstEfesState.IsSignalled,
        self->D51inEstEfesState.Value == FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Booting));
    self->Change371.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value ==
                                   FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__FallbackMode));
    self->Change382.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value ==
                                   FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Initialising));
    self->Change387.IsTriggered = IsTriggered(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value ==
                       FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__NoOperatingVoltage));
    self->Change498.IsTriggered = IsTriggered(MakeChange(
        self->D9inMonitoredOutputChannelDisturbanceStaten.IsSignalled,
        self->D9inMonitoredOutputChannelDisturbanceStaten.Value ==
            FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceStatenValue__PhysicallyDisturbed));
    self->Change506.IsTriggered = IsTriggered(MakeChange(
        self->D9inMonitoredOutputChannelDisturbanceState1.IsSignalled,
        self->D9inMonitoredOutputChannelDisturbanceState1.Value ==
            FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceState1Value__PhysicallyDisturbed));
    self->Change400.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value ==
                                   FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Operational));
    self->Change396.IsTriggered =
        IsTriggered(MakeChange(self->D51inEstEfesState.IsSignalled,
                               self->D51inEstEfesState.Value ==
                                   FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Operational));
    self->Change501.IsTriggered = IsTriggered(AndChange(
        MakeChange(
            self->D9inMonitoredOutputChannelDisturbanceState1.IsSignalled,
            self->D9inMonitoredOutputChannelDisturbanceState1.Value ==
                FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed),
        MakeChange(
            self->D9inMonitoredOutputChannelDisturbanceStaten.IsSignalled,
            self->D9inMonitoredOutputChannelDisturbanceStaten.Value ==
                FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed)));
}

static void resetOutputs(FControlSafeStateOfAllPhysicalOutputChannel *self)
{

    self->D13outSwitchOffEachPhysicalOuputChannel.IsSignalled = false;
}

static void resetTriggers(FControlSafeStateOfAllPhysicalOutputChannel *self)
{

    self->D9inMonitoredOutputChannelDisturbanceStaten.IsSignalled = false;
    self->D600inConDisturbanceSwitchOffAll.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
    self->D9inMonitoredOutputChannelDisturbanceState1.IsSignalled = false;
}

void transition_FControlSafeStateOfAllPhysicalOutputChannel(FControlSafeStateOfAllPhysicalOutputChannel *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FControlSafeStateOfAllPhysicalOutputChannel__root(self, &self->state);
    resetTriggers(self);
}

void new_FControlSafeStateOfAllPhysicalOutputChannel(FControlSafeStateOfAllPhysicalOutputChannel *self)
{
    make_state_FControlSafeStateOfAllPhysicalOutputChannel__root(self, &self->state);
}
