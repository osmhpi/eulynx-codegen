
#include "FTds6MaintainerCommandsAndMessages.h"

// Value Conversion Functions

// Operations

void make_state_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(
    FTds6MaintainerCommandsAndMessages *self, FTds6MaintainerCommandsAndMessages__root__state_struct *region)
{
    LOG("[FTds6MaintainerCommandsAndMessages] Entering state ReceivingCommandsAndReportMessages in region root");
    region->state = FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages;
};

void make_state_FTds6MaintainerCommandsAndMessages__root(FTds6MaintainerCommandsAndMessages *self,
                                                         FTds6MaintainerCommandsAndMessages__root__state_struct *x)
{
    memset(x, 0, sizeof(FTds6MaintainerCommandsAndMessages__root__state_struct));

    make_state_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(self, x);
    return;
}

void transition_from_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(
    FTds6MaintainerCommandsAndMessages *self, FTds6MaintainerCommandsAndMessages__root__state_struct *x)
{

    if (self->InReportCommandRejected__fa56.HasMessage)
    {
        if (self->InReportCommandRejected__fa56.Value.ReportedReasonForRejection ==
            ReasonForRejection__abec__Operational)
        {
            self->D36outCommandRejected.Value =
                FTds6MaintainerCommandsAndMessages_D36outCommandRejectedValue__Operational;
            self->D36outCommandRejected.IsSignalled = true;
            self->T36outCommandRejected.Trigger = true;
            make_state_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(self, x);
            return;
        }
    }
    if (self->InReportCommandRejected__fa56.HasMessage)
    {
        if (self->InReportCommandRejected__fa56.Value.ReportedReasonForRejection == ReasonForRejection__abec__Technical)
        {
            self->D36outCommandRejected.Value =
                FTds6MaintainerCommandsAndMessages_D36outCommandRejectedValue__Technical;
            self->D36outCommandRejected.IsSignalled = true;
            self->T36outCommandRejected.Trigger = true;
            make_state_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(self, x);
            return;
        }
    }
    if (self->Change1089.IsTriggered)
    {

        self->OutRequestDrfc__a48b.Value.ReportedSource = SourceOfCommand__d5a9__Maintainer;
        self->OutRequestDrfc__a48b.HasMessage = 1;
        make_state_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(self, x);
        return;
    }
    if (self->Change1091.IsTriggered)
    {
        if (self->D35inModeOfFc.Value == FTds6MaintainerCommandsAndMessages_D35inModeOfFcValue__FcU)
        {

            self->OutRequestFcU__bd99.Value.ReportedSource = SourceOfCommand__d5a9__Maintainer;
            self->OutRequestFcU__bd99.HasMessage = 1;
            make_state_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(self, x);
            return;
        }
    }
    if (self->Change1090.IsTriggered)
    {
        if (self->D35inModeOfFc.Value == FTds6MaintainerCommandsAndMessages_D35inModeOfFcValue__FcC)
        {

            self->OutRequestFcC__f902.Value.ReportedSource = SourceOfCommand__d5a9__Maintainer;
            self->OutRequestFcC__f902.HasMessage = 1;
            make_state_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(self, x);
            return;
        }
    }
    if (self->Change1151.IsTriggered)
    {

        self->OutRequestVisualSweepingConfirmation__2333.HasMessage = 1;
        make_state_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(self, x);
        return;
    }
}

void transition_from_FTds6MaintainerCommandsAndMessages__root(FTds6MaintainerCommandsAndMessages *self,
                                                              FTds6MaintainerCommandsAndMessages__root__state_struct *x)
{
    switch (x->state)
    {
    case FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages:
        transition_from_FTds6MaintainerCommandsAndMessages__root__ReceivingCommandsAndReportMessages(self, x);
        break;
    }
}

static void evaluateChangeEvents(FTds6MaintainerCommandsAndMessages *self)
{
    self->Change1089.IsTriggered = self->T34inDrfc.IsTriggered;
    self->Change1091.IsTriggered = self->T35inFc.IsTriggered;
    self->Change1090.IsTriggered = self->T35inFc.IsTriggered;
    self->Change1151.IsTriggered = self->T41inVisualSweepingConfirmed.IsTriggered;
}

static void resetOutputs(FTds6MaintainerCommandsAndMessages *self)
{
    self->OutRequestDrfc__a48b.HasMessage = false;
    self->OutRequestFcU__bd99.HasMessage = false;
    self->OutRequestFcC__f902.HasMessage = false;
    self->OutRequestVisualSweepingConfirmation__2333.HasMessage = false;

    self->T36outCommandRejected.Trigger = false;

    self->D36outCommandRejected.IsSignalled = false;
}

static void resetTriggers(FTds6MaintainerCommandsAndMessages *self)
{
    self->InReportCommandRejected__fa56.HasMessage = false;

    self->T35inFc.IsTriggered = false;
    self->T34inDrfc.IsTriggered = false;
    self->T41inVisualSweepingConfirmed.IsTriggered = false;

    self->D35inModeOfFc.IsSignalled = false;
}

void transition_FTds6MaintainerCommandsAndMessages(FTds6MaintainerCommandsAndMessages *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FTds6MaintainerCommandsAndMessages__root(self, &self->state);
    resetTriggers(self);
}

void new_FTds6MaintainerCommandsAndMessages(FTds6MaintainerCommandsAndMessages *self)
{
    make_state_FTds6MaintainerCommandsAndMessages__root(self, &self->state);
}
