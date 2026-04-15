
#include "FPerformFcPOrFcPA.h"

// Value Conversion Functions

// Operations
static void Cop2ReportIncorrectCount(FPerformFcPOrFcPA *self)
{
    if (self->MemLastCommand == FPerformFcPOrFcPA_MemLastCommandValue__FcP)
    {

        self->OutReasonFcPFailed__bfdd.Value.ReportedReasonForFailure = ReasonForFailure__b02d__IncorrectCount;
        self->OutReasonFcPFailed__bfdd.HasMessage = 1;
    }
    else if (self->MemLastCommand == FPerformFcPOrFcPA_MemLastCommandValue__FcPA)
    {

        self->OutReasonFcPAFailed__668a.Value.ReportedReasonForFailure = ReasonForFailure__b02d__IncorrectCount;
        self->OutReasonFcPAFailed__668a.HasMessage = 1;
    }
}
static void Cop3ReportTimeoutTMax(FPerformFcPOrFcPA *self)
{
    if (self->MemLastCommand == FPerformFcPOrFcPA_MemLastCommandValue__FcP)
    {

        self->OutReasonFcPFailed__bfdd.Value.ReportedReasonForFailure = ReasonForFailure__b02d__TimeoutTMax;
        self->OutReasonFcPFailed__bfdd.HasMessage = 1;
    }
    else if (self->MemLastCommand == FPerformFcPOrFcPA_MemLastCommandValue__FcPA)
    {

        self->OutReasonFcPAFailed__668a.Value.ReportedReasonForFailure = ReasonForFailure__b02d__TimeoutTMax;
        self->OutReasonFcPAFailed__668a.HasMessage = 1;
    }
}
static void Cop4ReportNotPermittedPassing(FPerformFcPOrFcPA *self)
{
    if (self->MemLastCommand == FPerformFcPOrFcPA_MemLastCommandValue__FcP)
    {

        self->OutReasonFcPFailed__bfdd.Value.ReportedReasonForFailure = ReasonForFailure__b02d__NotPermittedPassing;
        self->OutReasonFcPFailed__bfdd.HasMessage = 1;
    }
    else if (self->MemLastCommand == FPerformFcPOrFcPA_MemLastCommandValue__FcPA)
    {

        self->OutReasonFcPAFailed__668a.Value.ReportedReasonForFailure = ReasonForFailure__b02d__NotPermittedPassing;
        self->OutReasonFcPAFailed__668a.HasMessage = 1;
    }
}
static void Cop5ReportOutgoingWheelBeforeTMin(FPerformFcPOrFcPA *self)
{
    if (self->MemLastCommand == FPerformFcPOrFcPA_MemLastCommandValue__FcP)
    {

        self->OutReasonFcPFailed__bfdd.Value.ReportedReasonForFailure = ReasonForFailure__b02d__OutgoingwheelbeforeTMin;
        self->OutReasonFcPFailed__bfdd.HasMessage = 1;
    }
    else if (self->MemLastCommand == FPerformFcPOrFcPA_MemLastCommandValue__FcPA)
    {

        self->OutReasonFcPAFailed__668a.Value.ReportedReasonForFailure =
            ReasonForFailure__b02d__OutgoingwheelbeforeTMin;
        self->OutReasonFcPAFailed__668a.HasMessage = 1;
    }
}
static void Cop6ReportProcessCanceled(FPerformFcPOrFcPA *self)
{
    if (self->MemLastCommand == FPerformFcPOrFcPA_MemLastCommandValue__FcP)
    {

        self->OutReasonFcPFailed__bfdd.Value.ReportedReasonForFailure = ReasonForFailure__b02d__ProcessCanceled;
        self->OutReasonFcPFailed__bfdd.HasMessage = 1;
    }
    else if (self->MemLastCommand == FPerformFcPOrFcPA_MemLastCommandValue__FcPA)
    {

        self->OutReasonFcPAFailed__668a.Value.ReportedReasonForFailure = ReasonForFailure__b02d__ProcessCanceled;
        self->OutReasonFcPAFailed__668a.HasMessage = 1;
    }
}

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__WaiitingForTMin(
    FPerformFcPOrFcPA *self,
    FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__state_struct *region)
{
    LOG("[FPerformFcPOrFcPA] Entering state WaiitingForTMin in region "
        "root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin");
    region->state =
        FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__WaiitingForTMin;
};

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__TMimExpired(
    FPerformFcPOrFcPA *self,
    FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__state_struct *region)
{
    LOG("[FPerformFcPOrFcPA] Entering state TMimExpired in region "
        "root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin");
    region->state = FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__TMimExpired;
};

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin(
    FPerformFcPOrFcPA *self,
    FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__state_struct *x)
{
    memset(x, 0,
           sizeof(FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__state_struct));

    make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__WaiitingForTMin(
        self, x);
    return;
}

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Incoming(
    FPerformFcPOrFcPA *self,
    FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__state_struct
        *region)
{
    LOG("[FPerformFcPOrFcPA] Entering state Incoming in region "
        "root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction");
    region->state =
        FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Incoming;
};

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Outgoing(
    FPerformFcPOrFcPA *self,
    FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__state_struct
        *region)
{
    LOG("[FPerformFcPOrFcPA] Entering state Outgoing in region "
        "root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction");
    region->state =
        FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Outgoing;
};

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction(
    FPerformFcPOrFcPA *self,
    FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__state_struct *x)
{
    memset(
        x, 0,
        sizeof(
            FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__state_struct));

    make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Outgoing(
        self, x);
    return;
}

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForSweepingTrain(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state_struct *region)
{
    LOG("[FPerformFcPOrFcPA] Entering state WaitingForSweepingTrain in region root__PerformFcPOrFcPA__root");
    region->state = FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForSweepingTrain;
};

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state_struct *region)
{
    LOG("[FPerformFcPOrFcPA] Entering state SweepingTrainDetected in region root__PerformFcPOrFcPA__root");
    region->state = FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected;
    make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin(
        self, &region->SweepingTrainDetected.MonitorTMin);
    make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction(
        self, &region->SweepingTrainDetected.MonitorLastCountingAction);
};

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForAcknowledgement(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state_struct *region)
{
    LOG("[FPerformFcPOrFcPA] Entering state WaitingForAcknowledgement in region root__PerformFcPOrFcPA__root");
    region->state = FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForAcknowledgement;
};

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SuccessfulSweeping(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state_struct *region)
{
    LOG("[FPerformFcPOrFcPA] Entering state SuccessfulSweeping in region root__PerformFcPOrFcPA__root");
    region->state = FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SuccessfulSweeping;
};

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state_struct *x)
{
    memset(x, 0, sizeof(FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__state_struct));
    self->D19outProcessState.Value = FPerformFcPOrFcPA_D19outProcessStateValue__WaitingForSweepingTrain;
    self->D19outProcessState.IsSignalled = true;
    make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForSweepingTrain(self, x);
    return;
}

void make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA(FPerformFcPOrFcPA *self,
                                                          FPerformFcPOrFcPA__root__state_struct *region)
{
    LOG("[FPerformFcPOrFcPA] Entering state PerformFcPOrFcPA in region root");
    region->state = FPerformFcPOrFcPA__root__PerformFcPOrFcPA;
    make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root(self, &region->PerformFcPOrFcPA.root);
};

void make_state_FPerformFcPOrFcPA__root__Waiting(FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *region)
{
    LOG("[FPerformFcPOrFcPA] Entering state Waiting in region root");
    region->state = FPerformFcPOrFcPA__root__Waiting;
};

void make_state_FPerformFcPOrFcPA__root__Failed(FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *region)
{
    LOG("[FPerformFcPOrFcPA] Entering state Failed in region root");
    region->state = FPerformFcPOrFcPA__root__Failed;
};

void make_state_FPerformFcPOrFcPA__root(FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    memset(x, 0, sizeof(FPerformFcPOrFcPA__root__state_struct));
    self->D19outProcessState.Value = FPerformFcPOrFcPA_D19outProcessStateValue__Waiting;
    self->D19outProcessState.IsSignalled = true;
    make_state_FPerformFcPOrFcPA__root__Waiting(self, x);
    return;
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__WaiitingForTMin(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{

    if (self->Time26.IsTimeoutExpired)
    {

        make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__TMimExpired(
            self, &x->PerformFcPOrFcPA.root.SweepingTrainDetected.MonitorTMin);
        return;
    }
    if (self->Change1157.IsTriggered)
    {
        Cop5ReportOutgoingWheelBeforeTMin(self);
        make_state_FPerformFcPOrFcPA__root__Failed(self, x);
        return;
    }
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__TMimExpired(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    switch (x->PerformFcPOrFcPA.root.SweepingTrainDetected.MonitorTMin.state)
    {
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__WaiitingForTMin:
        transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__WaiitingForTMin(
            self, x);
        break;
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__TMimExpired:
        transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__TMimExpired(
            self, x);
        break;
    }
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Incoming(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{

    if (self->Change1158.IsTriggered)
    {

        make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Outgoing(
            self, &x->PerformFcPOrFcPA.root.SweepingTrainDetected.MonitorLastCountingAction);
        return;
    }
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Outgoing(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{

    if (self->Change1148.IsTriggered)
    {

        self->OutChangeTrigger__e05e.Value.ReportedChangeTrigger = ChangeTrigger__de2d__InternalTrigger;
        self->OutChangeTrigger__e05e.HasMessage = 1;
        make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SuccessfulSweeping(self, &x->PerformFcPOrFcPA.root);
        return;
    }
    if (self->Change1152.IsTriggered)
    {

        make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Incoming(
            self, &x->PerformFcPOrFcPA.root.SweepingTrainDetected.MonitorLastCountingAction);
        return;
    }
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    switch (x->PerformFcPOrFcPA.root.SweepingTrainDetected.MonitorLastCountingAction.state)
    {
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Incoming:
        transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Incoming(
            self, x);
        break;
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Outgoing:
        transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Outgoing(
            self, x);
        break;
    }
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForSweepingTrain(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{

    if (self->InExecuteVisualSweepingConfirmation__251f.HasMessage)
    {

        self->OutChangeTrigger__e05e.Value.ReportedChangeTrigger = ChangeTrigger__de2d__CommandFromMaintainer;
        self->OutChangeTrigger__e05e.HasMessage = 1;
        make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SuccessfulSweeping(self, &x->PerformFcPOrFcPA.root);
        return;
    }
    if (self->Change1153.IsTriggered)
    {
        self->D19outProcessState.Value = FPerformFcPOrFcPA_D19outProcessStateValue__SweepingTrainDetected;
        self->D19outProcessState.IsSignalled = true;
        make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected(self,
                                                                                          &x->PerformFcPOrFcPA.root);
        return;
    }
    if (self->Change1156.IsTriggered)
    {
        Cop2ReportIncorrectCount(self);
        make_state_FPerformFcPOrFcPA__root__Failed(self, x);
        return;
    }
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin(self, x);
    transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction(
        self, x);
    if (self->Time25.IsTimeoutExpired)
    {
        Cop3ReportTimeoutTMax(self);

        self->OutChangeTrigger__e05e.Value.ReportedChangeTrigger = ChangeTrigger__de2d__InternalTrigger;
        self->OutChangeTrigger__e05e.HasMessage = 1;
        make_state_FPerformFcPOrFcPA__root__Failed(self, x);
        return;
    }
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForAcknowledgement(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{

    if (self->InConfirmAcknowledgement__3cca.HasMessage)
    {

        self->OutExecuteFc__ffe5.HasMessage = 1;
        self->D19outProcessState.Value = FPerformFcPOrFcPA_D19outProcessStateValue__Waiting;
        self->D19outProcessState.IsSignalled = true;
        make_state_FPerformFcPOrFcPA__root__Waiting(self, x);
        return;
    }
    if (self->Change1154.IsTriggered)
    {
        Cop2ReportIncorrectCount(self);
        make_state_FPerformFcPOrFcPA__root__Failed(self, x);
        return;
    }
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SuccessfulSweeping(
    FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{

    if (true)
    {

        self->OutExecuteFc__ffe5.HasMessage = 1;
        self->D19outProcessState.Value = FPerformFcPOrFcPA_D19outProcessStateValue__Waiting;
        self->D19outProcessState.IsSignalled = true;
        make_state_FPerformFcPOrFcPA__root__Waiting(self, x);
        return;
    }
    if (true)
    {
        self->D19outProcessState.Value = FPerformFcPOrFcPA_D19outProcessStateValue__WaitingForAnAcknowledgment;
        self->D19outProcessState.IsSignalled = true;
        make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForAcknowledgement(
            self, &x->PerformFcPOrFcPA.root);
        return;
    }
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root(FPerformFcPOrFcPA *self,
                                                                     FPerformFcPOrFcPA__root__state_struct *x)
{
    switch (x->PerformFcPOrFcPA.root.state)
    {
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForSweepingTrain:
        transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForSweepingTrain(self, x);
        break;
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected:
        transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected(self, x);
        break;
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForAcknowledgement:
        transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForAcknowledgement(self, x);
        break;
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SuccessfulSweeping:
        transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SuccessfulSweeping(self, x);
        break;
    }
}

void transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA(FPerformFcPOrFcPA *self,
                                                               FPerformFcPOrFcPA__root__state_struct *x)
{
    transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root(self, x);
    if (self->InExecuteCancel__045b.HasMessage)
    {
        self->D18outPerformFcPOrFcA.Value = false;
        Cop6ReportProcessCanceled(self);
        make_state_FPerformFcPOrFcPA__root__Failed(self, x);
        return;
    }
    if (self->Change231.IsTriggered)
    {
        self->D18outPerformFcPOrFcA.Value = false;
        self->D19outProcessState.Value = FPerformFcPOrFcPA_D19outProcessStateValue__Waiting;
        self->D19outProcessState.IsSignalled = true;
        make_state_FPerformFcPOrFcPA__root__Waiting(self, x);
        return;
    }
    if (self->Change1113.IsTriggered)
    {
        self->D18outPerformFcPOrFcA.Value = false;
        Cop2ReportIncorrectCount(self);
        make_state_FPerformFcPOrFcPA__root__Failed(self, x);
        return;
    }
    if (self->Change1267.IsTriggered)
    {
        self->D18outPerformFcPOrFcA.Value = false;
        Cop4ReportNotPermittedPassing(self);
        make_state_FPerformFcPOrFcPA__root__Failed(self, x);
        return;
    }
}

void transition_from_FPerformFcPOrFcPA__root__Waiting(FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{

    if (self->InExecuteFcP__c2bd.HasMessage)
    {
        self->MemLastCommand = FPerformFcPOrFcPA_MemLastCommandValue__FcP;
        self->D18outPerformFcPOrFcA.Value = true;
        make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA(self, x);
        return;
    }
    if (self->InExecuteFcPA__f496.HasMessage)
    {
        self->MemLastCommand = FPerformFcPOrFcPA_MemLastCommandValue__FcPA;
        self->D18outPerformFcPOrFcA.Value = true;
        make_state_FPerformFcPOrFcPA__root__PerformFcPOrFcPA(self, x);
        return;
    }
}

void transition_from_FPerformFcPOrFcPA__root__Failed(FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{

    if (true)
    {
        self->D19outProcessState.Value = FPerformFcPOrFcPA_D19outProcessStateValue__Waiting;
        self->D19outProcessState.IsSignalled = true;
        make_state_FPerformFcPOrFcPA__root__Waiting(self, x);
        return;
    }
}

void transition_from_FPerformFcPOrFcPA__root(FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    switch (x->state)
    {
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA:
        transition_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA(self, x);
        break;
    case FPerformFcPOrFcPA__root__Waiting:
        transition_from_FPerformFcPOrFcPA__root__Waiting(self, x);
        break;
    case FPerformFcPOrFcPA__root__Failed:
        transition_from_FPerformFcPOrFcPA__root__Failed(self, x);
        break;
    }
}

static void evaluateChangeEvents(FPerformFcPOrFcPA *self)
{
    self->Change1157.IsTriggered = self->T44inOutPermittedWheel.IsTriggered;
    self->Change1158.IsTriggered = self->T44inOutPermittedWheel.IsTriggered;
    self->Change1148.IsTriggered = self->T40inSweepingSuccessful.IsTriggered;
    self->Change1152.IsTriggered = self->T42inInPermittedWheel.IsTriggered;
    self->Change1153.IsTriggered = self->T42inInPermittedWheel.IsTriggered;
    self->Change1156.IsTriggered = self->T44inOutPermittedWheel.IsTriggered;
    self->Change1154.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->T42inInPermittedWheel.IsTriggered, self->T42inInPermittedWheel.IsTriggered),
                 MakeChange(self->T44inOutPermittedWheel.IsTriggered, self->T44inOutPermittedWheel.IsTriggered)));
    self->Change231.IsTriggered =
        IsTriggered(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value));
    self->Change1113.IsTriggered = self->T39inUndefinedPattern.IsTriggered;
    self->Change1267.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->T88inInNotPermittedWheel.IsTriggered, self->T88inInNotPermittedWheel.IsTriggered),
                 MakeChange(self->T43inOutNotPermittedWheel.IsTriggered, self->T43inOutNotPermittedWheel.IsTriggered)));
}

static void resetOutputs(FPerformFcPOrFcPA *self)
{
    self->OutReasonFcPFailed__bfdd.HasMessage = false;
    self->OutReasonFcPAFailed__668a.HasMessage = false;
    self->OutChangeTrigger__e05e.HasMessage = false;
    self->OutExecuteFc__ffe5.HasMessage = false;

    self->D18outPerformFcPOrFcA.IsSignalled = false;
    self->D19outProcessState.IsSignalled = false;
}

static void resetTriggers(FPerformFcPOrFcPA *self)
{
    self->InExecuteVisualSweepingConfirmation__251f.HasMessage = false;
    self->InConfirmAcknowledgement__3cca.HasMessage = false;
    self->InExecuteCancel__045b.HasMessage = false;
    self->InExecuteFcP__c2bd.HasMessage = false;
    self->InExecuteFcPA__f496.HasMessage = false;

    self->T88inInNotPermittedWheel.IsTriggered = false;
    self->T42inInPermittedWheel.IsTriggered = false;
    self->T44inOutPermittedWheel.IsTriggered = false;
    self->T39inUndefinedPattern.IsTriggered = false;
    self->T40inSweepingSuccessful.IsTriggered = false;
    self->T43inOutNotPermittedWheel.IsTriggered = false;

    self->D30inConTMaxFcPOrFcPA.IsSignalled = false;
    self->D31inConTMinFcPOrFcPA.IsSignalled = false;
    self->D32inCriticalFailureTvps.IsSignalled = false;

    self->Time26.IsTimeoutExpired = false;
    self->Time25.IsTimeoutExpired = false;
}

void transition_FPerformFcPOrFcPA(FPerformFcPOrFcPA *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FPerformFcPOrFcPA__root(self, &self->state);
    resetTriggers(self);
}

void new_FPerformFcPOrFcPA(FPerformFcPOrFcPA *self)
{
    make_state_FPerformFcPOrFcPA__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemTrainDetectionSystem/FPerformFcPOrFcPA.c"
#endif
