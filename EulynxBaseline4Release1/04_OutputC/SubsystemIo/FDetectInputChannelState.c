
#include "FDetectInputChannelState.h"

// Value Conversion Functions

// Operations

void make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state SwitchedOn in region "
        "root__DetectingAntivalentInputChannelPhysicalStateChange__root");
    region->state =
        FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn;
};

void make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state SwitchedOff in region "
        "root__DetectingAntivalentInputChannelPhysicalStateChange__root");
    region->state =
        FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff;
};

void make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state OperationlDisturbed in region "
        "root__DetectingAntivalentInputChannelPhysicalStateChange__root");
    region->state =
        FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__OperationlDisturbed;
};

void make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state Disturbed in region "
        "root__DetectingAntivalentInputChannelPhysicalStateChange__root");
    region->state = FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed;
};

void make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state_struct *x)
{
    memset(
        x, 0,
        sizeof(FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state_struct));

    if (((self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off) &&
         (self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off)) ||
        ((self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On) &&
         (self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On)))
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, x);
        return;
    }
    if ((self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Disturbed) ||
        (self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Disturbed))
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, x);
        return;
    }
    if ((self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off) &&
        (self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On))
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOff;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff;
        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            self, x);
        return;
    }
    if ((self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On) &&
        (self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off))
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOn;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn;
        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            self, x);
        return;
    }
}

void make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state SwitchedOn in region "
        "root__DetectingEquivalentInputChannelPhysicalStateChange__root");
    region->state =
        FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn;
};

void make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state SwitchedOff in region "
        "root__DetectingEquivalentInputChannelPhysicalStateChange__root");
    region->state =
        FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff;
};

void make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state OperationlDisturbed in region "
        "root__DetectingEquivalentInputChannelPhysicalStateChange__root");
    region->state =
        FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__OperationlDisturbed;
};

void make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state Disturbed in region "
        "root__DetectingEquivalentInputChannelPhysicalStateChange__root");
    region->state = FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed;
};

void make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state_struct *x)
{
    memset(
        x, 0,
        sizeof(FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state_struct));

    if ((self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Disturbed) ||
        (self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Disturbed))
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, x);
        return;
    }
    if (((self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off) &&
         (self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On)) ||
        ((self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On) &&
         (self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off)))
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, x);
        return;
    }
    if ((self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off) &&
        (self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off))
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOff;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff;
        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            self, x);
        return;
    }
    if ((self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On) &&
        (self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On))
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOn;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn;
        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            self, x);
        return;
    }
}

void make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state SwitchedOn in region "
        "root__DetectingSingleInputChannelPhysicalStateChange__root");
    region->state = FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn;
};

void make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state SwitchedOff in region "
        "root__DetectingSingleInputChannelPhysicalStateChange__root");
    region->state = FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff;
};

void make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state Disturbed in region "
        "root__DetectingSingleInputChannelPhysicalStateChange__root");
    region->state = FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed;
};

void make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root(
    FDetectInputChannelState *self,
    FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__state_struct *x)
{
    memset(x, 0,
           sizeof(FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__state_struct));

    if (self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Disturbed)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed(self,
                                                                                                                   x);
        return;
    }
    if (self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOff;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff;
        make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff(
            self, x);
        return;
    }
    if (self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOn;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn;
        make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn(
            self, x);
        return;
    }
}

void make_state_FDetectInputChannelState__root__ChannelConfiguration(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state ChannelConfiguration in region root");
    region->state = FDetectInputChannelState__root__ChannelConfiguration;
};

void make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state DetectingAntivalentInputChannelPhysicalStateChange in region root");
    region->state = FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange;
    make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root(
        self, &region->DetectingAntivalentInputChannelPhysicalStateChange.root);
};

void make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state DetectingEquivalentInputChannelPhysicalStateChange in region root");
    region->state = FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange;
    make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root(
        self, &region->DetectingEquivalentInputChannelPhysicalStateChange.root);
};

void make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *region)
{
    LOG("[FDetectInputChannelState] Entering state DetectingSingleInputChannelPhysicalStateChange in region root");
    region->state = FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange;
    make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root(
        self, &region->DetectingSingleInputChannelPhysicalStateChange.root);
};

void make_state_FDetectInputChannelState__root(FDetectInputChannelState *self,
                                               FDetectInputChannelState__root__state_struct *x)
{
    memset(x, 0, sizeof(FDetectInputChannelState__root__state_struct));

    make_state_FDetectInputChannelState__root__ChannelConfiguration(self, x);
    return;
}

void transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (self->Change2.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change42.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change49.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Time33.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff)
        {
            self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOn;
            self->D7outDetectedChannelState.IsSignalled = true;
            self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn;
            make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn(
                self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
            return;
        }
    }
}

void transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (self->Change3.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change44.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change60.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Time37.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn)
        {
            self->D7outDetectedChannelState.Value =
                FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOff;
            self->D7outDetectedChannelState.IsSignalled = true;
            self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff;
            make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff(
                self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
            return;
        }
    }
}

void transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (self->Time57.IsTimeoutExpired)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change41.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change52.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change59.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
}

void transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (self->Change54.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOff;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff;
        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change58.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOn;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn;
        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            self, &x->DetectingAntivalentInputChannelPhysicalStateChange.root);
        return;
    }
}

void transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    switch (x->DetectingAntivalentInputChannelPhysicalStateChange.root.state)
    {
    case FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn:
        transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            self, x);
        break;
    case FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff:
        transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            self, x);
        break;
    case FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__OperationlDisturbed:
        transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
            self, x);
        break;
    case FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed:
        transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, x);
        break;
    }
}

void transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (self->Change4.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change43.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change50.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Time32.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff)
        {
            self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOn;
            self->D7outDetectedChannelState.IsSignalled = true;
            self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn;
            make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn(
                self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
            return;
        }
    }
}

void transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (self->Change5.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change46.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change61.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Time36.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn)
        {
            self->D7outDetectedChannelState.Value =
                FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOff;
            self->D7outDetectedChannelState.IsSignalled = true;
            self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff;
            make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff(
                self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
            return;
        }
    }
}

void transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (self->Time56.IsTimeoutExpired)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change45.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change53.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change62.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
}

void transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (self->Change51.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOff;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff;
        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change57.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOn;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn;
        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            self, &x->DetectingEquivalentInputChannelPhysicalStateChange.root);
        return;
    }
}

void transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    switch (x->DetectingEquivalentInputChannelPhysicalStateChange.root.state)
    {
    case FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn:
        transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn(
            self, x);
        break;
    case FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff:
        transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff(
            self, x);
        break;
    case FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__OperationlDisturbed:
        transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__OperationlDisturbed(
            self, x);
        break;
    case FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed:
        transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed(
            self, x);
        break;
    }
}

void transition_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (self->Change39.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed(
            self, &x->DetectingSingleInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change48.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff(
            self, &x->DetectingSingleInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Time31.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff)
        {
            self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOn;
            self->D7outDetectedChannelState.IsSignalled = true;
            self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn;
            make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn(
                self, &x->DetectingSingleInputChannelPhysicalStateChange.root);
            return;
        }
    }
}

void transition_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (self->Change40.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed;
        make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed(
            self, &x->DetectingSingleInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change56.IsTriggered)
    {

        make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn(
            self, &x->DetectingSingleInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Time38.IsTimeoutExpired)
    {
        if (self->MemLastDetectedChannelState == FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn)
        {
            self->D7outDetectedChannelState.Value =
                FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOff;
            self->D7outDetectedChannelState.IsSignalled = true;
            self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff;
            make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff(
                self, &x->DetectingSingleInputChannelPhysicalStateChange.root);
            return;
        }
    }
}

void transition_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (self->Change47.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOff;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff;
        make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff(
            self, &x->DetectingSingleInputChannelPhysicalStateChange.root);
        return;
    }
    if (self->Change55.IsTriggered)
    {
        self->D7outDetectedChannelState.Value = FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOn;
        self->D7outDetectedChannelState.IsSignalled = true;
        self->MemLastDetectedChannelState = FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn;
        make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn(
            self, &x->DetectingSingleInputChannelPhysicalStateChange.root);
        return;
    }
}

void transition_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    switch (x->DetectingSingleInputChannelPhysicalStateChange.root.state)
    {
    case FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn:
        transition_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn(
            self, x);
        break;
    case FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff:
        transition_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff(
            self, x);
        break;
    case FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed:
        transition_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed(
            self, x);
        break;
    }
}

void transition_from_FDetectInputChannelState__root__ChannelConfiguration(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{

    if (true)
    {

        make_state_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange(self, x);
        return;
    }
    if (true)
    {

        make_state_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange(self, x);
        return;
    }
    if (true)
    {

        make_state_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange(self, x);
        return;
    }
}

void transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root(self, x);
}

void transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root(self, x);
}

void transition_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange(
    FDetectInputChannelState *self, FDetectInputChannelState__root__state_struct *x)
{
    transition_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root(self, x);
}

void transition_from_FDetectInputChannelState__root(FDetectInputChannelState *self,
                                                    FDetectInputChannelState__root__state_struct *x)
{
    switch (x->state)
    {
    case FDetectInputChannelState__root__ChannelConfiguration:
        transition_from_FDetectInputChannelState__root__ChannelConfiguration(self, x);
        break;
    case FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange:
        transition_from_FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange(self, x);
        break;
    case FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange:
        transition_from_FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange(self, x);
        break;
    case FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange:
        transition_from_FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange(self, x);
        break;
    }
}

static void evaluateChangeEvents(FDetectInputChannelState *self)
{
    self->Change2.IsTriggered = IsTriggered(
        OrChange(AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                                      self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off),
                           MakeChange(self->D22inStateVic.IsSignalled,
                                      self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off)),
                 AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                                      self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On),
                           MakeChange(self->D22inStateVic.IsSignalled,
                                      self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On))));
    self->Change42.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D11inStateRic.IsSignalled,
                            self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Disturbed),
                 MakeChange(self->D22inStateVic.IsSignalled,
                            self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Disturbed)));
    self->Change49.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On)));
    self->Change3.IsTriggered = IsTriggered(
        OrChange(AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                                      self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off),
                           MakeChange(self->D22inStateVic.IsSignalled,
                                      self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off)),
                 AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                                      self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On),
                           MakeChange(self->D22inStateVic.IsSignalled,
                                      self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On))));
    self->Change44.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D11inStateRic.IsSignalled,
                            self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Disturbed),
                 MakeChange(self->D22inStateVic.IsSignalled,
                            self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Disturbed)));
    self->Change60.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off)));
    self->Change41.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D11inStateRic.IsSignalled,
                            self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Disturbed),
                 MakeChange(self->D22inStateVic.IsSignalled,
                            self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Disturbed)));
    self->Change52.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On)));
    self->Change59.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off)));
    self->Change54.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On)));
    self->Change58.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off)));
    self->Change4.IsTriggered = IsTriggered(
        OrChange(AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                                      self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off),
                           MakeChange(self->D22inStateVic.IsSignalled,
                                      self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On)),
                 AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                                      self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On),
                           MakeChange(self->D22inStateVic.IsSignalled,
                                      self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off))));
    self->Change43.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D11inStateRic.IsSignalled,
                            self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Disturbed),
                 MakeChange(self->D22inStateVic.IsSignalled,
                            self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Disturbed)));
    self->Change50.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off)));
    self->Change5.IsTriggered = IsTriggered(
        OrChange(AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                                      self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off),
                           MakeChange(self->D22inStateVic.IsSignalled,
                                      self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On)),
                 AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                                      self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On),
                           MakeChange(self->D22inStateVic.IsSignalled,
                                      self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off))));
    self->Change46.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D11inStateRic.IsSignalled,
                            self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Disturbed),
                 MakeChange(self->D22inStateVic.IsSignalled,
                            self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Disturbed)));
    self->Change61.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On)));
    self->Change45.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D11inStateRic.IsSignalled,
                            self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Disturbed),
                 MakeChange(self->D22inStateVic.IsSignalled,
                            self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Disturbed)));
    self->Change53.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off)));
    self->Change62.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On)));
    self->Change51.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__Off)));
    self->Change57.IsTriggered = IsTriggered(
        AndChange(MakeChange(self->D11inStateRic.IsSignalled,
                             self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On),
                  MakeChange(self->D22inStateVic.IsSignalled,
                             self->D22inStateVic.Value == FDetectInputChannelState_D22inStateVicValue__On)));
    self->Change39.IsTriggered =
        IsTriggered(MakeChange(self->D11inStateRic.IsSignalled,
                               self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Disturbed));
    self->Change48.IsTriggered =
        IsTriggered(MakeChange(self->D11inStateRic.IsSignalled,
                               self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off));
    self->Change40.IsTriggered =
        IsTriggered(MakeChange(self->D11inStateRic.IsSignalled,
                               self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Disturbed));
    self->Change56.IsTriggered = IsTriggered(MakeChange(
        self->D11inStateRic.IsSignalled, self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On));
    self->Change47.IsTriggered =
        IsTriggered(MakeChange(self->D11inStateRic.IsSignalled,
                               self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__Off));
    self->Change55.IsTriggered = IsTriggered(MakeChange(
        self->D11inStateRic.IsSignalled, self->D11inStateRic.Value == FDetectInputChannelState_D11inStateRicValue__On));
}

static void resetOutputs(FDetectInputChannelState *self)
{

    self->D7outDetectedChannelState.IsSignalled = false;
}

static void resetTriggers(FDetectInputChannelState *self)
{

    self->D11inStateRic.IsSignalled = false;
    self->D22inStateVic.IsSignalled = false;
    self->D4inConChannelType.IsSignalled = false;
    self->D6inConTmaxSwitchingPeriod.IsSignalled = false;
    self->D44inConTMessageDelayTimeOn.IsSignalled = false;
    self->D55inConTMessageDelayTimeOff.IsSignalled = false;

    self->Time33.IsTimeoutExpired = false;
    self->Time37.IsTimeoutExpired = false;
    self->Time57.IsTimeoutExpired = false;
    self->Time32.IsTimeoutExpired = false;
    self->Time36.IsTimeoutExpired = false;
    self->Time56.IsTimeoutExpired = false;
    self->Time31.IsTimeoutExpired = false;
    self->Time38.IsTimeoutExpired = false;
}

void transition_FDetectInputChannelState(FDetectInputChannelState *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FDetectInputChannelState__root(self, &self->state);
    resetTriggers(self);
}

void new_FDetectInputChannelState(FDetectInputChannelState *self)
{
    make_state_FDetectInputChannelState__root(self, &self->state);
}
