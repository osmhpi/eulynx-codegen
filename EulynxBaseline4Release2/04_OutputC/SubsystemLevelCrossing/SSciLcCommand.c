
#include "SSciLcCommand.h"

// Value Conversion Functions

// Operations

void make_state_SSciLcCommand__root__SendingCommands(SSciLcCommand *self, SSciLcCommand__root__state_struct *region)
{
    LOG("[SSciLcCommand] Entering state SendingCommands in region root");
    region->state = SSciLcCommand__root__SendingCommands;
};

void make_state_SSciLcCommand__root(SSciLcCommand *self, SSciLcCommand__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciLcCommand__root__state_struct));

    make_state_SSciLcCommand__root__SendingCommands(self, x);
    return;
}

void transition_from_SSciLcCommand__root__SendingCommands(SSciLcCommand *self, SSciLcCommand__root__state_struct *x)
{

    if (self->Change870.IsTriggered)
    {
        if (((self->D1inCdActivation.Value == SSciLcCommand_D1inCdActivationValue__PreActivation) &&
             (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established)) &&
            (self->D65inConUsePreActivation.Value == true))
        {

            self->OutCdActivation__3513.Value.CommandedActivationState =
                ActivationControlableState__4140__PreActivation;
            self->OutCdActivation__3513.HasMessage = 1;
            make_state_SSciLcCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change871.IsTriggered)
    {
        if ((self->D1inCdActivation.Value == SSciLcCommand_D1inCdActivationValue__Activation) &&
            (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdActivation__3513.Value.CommandedActivationState = ActivationControlableState__4140__Activation;
            self->OutCdActivation__3513.HasMessage = 1;
            make_state_SSciLcCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1066.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established)
        {

            self->OutCdDeactivation__48b5.Value.CommandedDeactivationState =
                DeactivationControlableState__514f__Deactivation;
            self->OutCdDeactivation__48b5.HasMessage = 1;
            make_state_SSciLcCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1148.IsTriggered)
    {
        if ((self->D3inCdLocalOperationHandover.Value ==
             SSciLcCommand_D3inCdLocalOperationHandoverValue__HandoverToLocalOperatorInitiated) &&
            (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdLocalOperationHandover__2b72.Value.CommandedHandoverState =
                LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorInitiated;
            self->OutCdLocalOperationHandover__2b72.HasMessage = 1;
            make_state_SSciLcCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1146.IsTriggered)
    {
        if ((self->D3inCdLocalOperationHandover.Value ==
             SSciLcCommand_D3inCdLocalOperationHandoverValue__HandoverToLocalOperatorEstablished) &&
            (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdLocalOperationHandover__2b72.Value.CommandedHandoverState =
                LocalOperationHandoverControlableState__9164__HandoverToLocalOperatorEstablished;
            self->OutCdLocalOperationHandover__2b72.HasMessage = 1;
            make_state_SSciLcCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1147.IsTriggered)
    {
        if ((self->D3inCdLocalOperationHandover.Value ==
             SSciLcCommand_D3inCdLocalOperationHandoverValue__NoHandoverToLocalOperator) &&
            (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established))
        {

            self->OutCdLocalOperationHandover__2b72.Value.CommandedHandoverState =
                LocalOperationHandoverControlableState__9164__NoHandOverToLocalOperator;
            self->OutCdLocalOperationHandover__2b72.HasMessage = 1;
            make_state_SSciLcCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1199.IsTriggered)
    {
        if (((self->D4inCdIsolateLc.Value == SSciLcCommand_D4inCdIsolateLcValue__IsolateLcDisable) &&
             (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established)) &&
            (self->D67inConUseIsolation.Value == true))
        {

            self->OutCdIsolateLc__add9.Value.CommandedIsolateState =
                IsolateLevelCrossingControlableState__55c1__DisableIsolationOfTheLevelCrossing;
            self->OutCdIsolateLc__add9.HasMessage = 1;
            make_state_SSciLcCommand__root__SendingCommands(self, x);
            return;
        }
    }
    if (self->Change1200.IsTriggered)
    {
        if (((self->D4inCdIsolateLc.Value == SSciLcCommand_D4inCdIsolateLcValue__IsolateLcEnable) &&
             (self->D50inPdiConnectionState.Value == SSciLcCommand_D50inPdiConnectionStateValue__Established)) &&
            (self->D67inConUseIsolation.Value == true))
        {

            self->OutCdIsolateLc__add9.Value.CommandedIsolateState =
                IsolateLevelCrossingControlableState__55c1__EnableIsolationOfTheLevelCrossing;
            self->OutCdIsolateLc__add9.HasMessage = 1;
            make_state_SSciLcCommand__root__SendingCommands(self, x);
            return;
        }
    }
}

void transition_from_SSciLcCommand__root(SSciLcCommand *self, SSciLcCommand__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciLcCommand__root__SendingCommands:
        transition_from_SSciLcCommand__root__SendingCommands(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciLcCommand *self)
{
    self->Change870.IsTriggered = self->T1inCdActivation.IsTriggered;
    self->Change871.IsTriggered = self->T1inCdActivation.IsTriggered;
    self->Change1066.IsTriggered = self->T2inCdDeactivation.IsTriggered;
    self->Change1148.IsTriggered = self->T3inCdLocalOperationHandover.IsTriggered;
    self->Change1146.IsTriggered = self->T3inCdLocalOperationHandover.IsTriggered;
    self->Change1147.IsTriggered = self->T3inCdLocalOperationHandover.IsTriggered;
    self->Change1199.IsTriggered = self->T4inCdIsolateLc.IsTriggered;
    self->Change1200.IsTriggered = self->T4inCdIsolateLc.IsTriggered;
}

static void resetOutputs(SSciLcCommand *self)
{
    self->OutCdActivation__3513.HasMessage = false;
    self->OutCdDeactivation__48b5.HasMessage = false;
    self->OutCdLocalOperationHandover__2b72.HasMessage = false;
    self->OutCdIsolateLc__add9.HasMessage = false;
}

static void resetTriggers(SSciLcCommand *self)
{

    self->T1inCdActivation.IsTriggered = false;
    self->T2inCdDeactivation.IsTriggered = false;
    self->T4inCdIsolateLc.IsTriggered = false;
    self->T3inCdLocalOperationHandover.IsTriggered = false;

    self->D1inCdActivation.IsSignalled = false;
    self->D4inCdIsolateLc.IsSignalled = false;
    self->D3inCdLocalOperationHandover.IsSignalled = false;
    self->D50inPdiConnectionState.IsSignalled = false;
    self->D65inConUsePreActivation.IsSignalled = false;
    self->D67inConUseIsolation.IsSignalled = false;
    self->D84inConUseLocalOperation.IsSignalled = false;
}

void transition_SSciLcCommand(SSciLcCommand *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciLcCommand__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciLcCommand(SSciLcCommand *self)
{
    make_state_SSciLcCommand__root(self, &self->state);
}
