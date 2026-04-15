
#include "FObserveOccupancyStatus.h"

// Value Conversion Functions

// Operations
static void Cop2ReportCtInitial(FObserveOccupancyStatus *self)
{

    self->OutChangeTrigger__e05e.Value.ReportedChangeTrigger = ChangeTrigger__de2d__InitialSectionState;
    self->OutChangeTrigger__e05e.HasMessage = 1;
}
static void Cop3ReportCtPassing(FObserveOccupancyStatus *self)
{

    self->OutChangeTrigger__e05e.Value.ReportedChangeTrigger = ChangeTrigger__de2d__PassingDetected;
    self->OutChangeTrigger__e05e.HasMessage = 1;
}
static void Cop4ResetCount(FObserveOccupancyStatus *self)
{
    self->MemEnteredaxles = 0;
    self->MemExitedaxles = 0;
    self->MemDifference = 0;
}

void make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct *region)
{
    LOG("[FObserveOccupancyStatus] Entering state UnreliableIncoming in region root__ObserveTvpsStatus__root");
    region->state = FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming;
};

void make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct *region)
{
    LOG("[FObserveOccupancyStatus] Entering state UnreliableOutgoing in region root__ObserveTvpsStatus__root");
    region->state = FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing;
};

void make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct *region)
{
    LOG("[FObserveOccupancyStatus] Entering state Vacant in region root__ObserveTvpsStatus__root");
    region->state = FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant;
};

void make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct *region)
{
    LOG("[FObserveOccupancyStatus] Entering state OccupiedIncoming in region root__ObserveTvpsStatus__root");
    region->state = FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming;
};

void make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct *region)
{
    LOG("[FObserveOccupancyStatus] Entering state OccupiedOutgoing in region root__ObserveTvpsStatus__root");
    region->state = FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing;
};

void make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__WaitingForNotificationOfAvailability(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct *region)
{
    LOG("[FObserveOccupancyStatus] Entering state WaitingForNotificationOfAvailability in region "
        "root__ObserveTvpsStatus__root");
    region->state = FObserveOccupancyStatus__root__ObserveTvpsStatus__root__WaitingForNotificationOfAvailability;
};

void make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveOccupancyStatus__root__ObserveTvpsStatus__root__state_struct));

    if (self->D26inConVariantAIsUsed.Value)
    {
        Cop2ReportCtInitial(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableOut;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing(self, x);
        return;
    }
    else
    {
        Cop2ReportCtInitial(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableIn;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(self, x);
        return;
    }
}

void make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus(FObserveOccupancyStatus *self,
                                                                 FObserveOccupancyStatus__root__state_struct *region)
{
    LOG("[FObserveOccupancyStatus] Entering state ObserveTvpsStatus in region root");
    region->state = FObserveOccupancyStatus__root__ObserveTvpsStatus;
    make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root(self, &region->ObserveTvpsStatus.root);
};

void make_state_FObserveOccupancyStatus__root__FallbackMode(FObserveOccupancyStatus *self,
                                                            FObserveOccupancyStatus__root__state_struct *region)
{
    LOG("[FObserveOccupancyStatus] Entering state FallbackMode in region root");
    region->state = FObserveOccupancyStatus__root__FallbackMode;
};

void make_state_FObserveOccupancyStatus__root__WaitingForFinishBooting(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *region)
{
    LOG("[FObserveOccupancyStatus] Entering state WaitingForFinishBooting in region root");
    region->state = FObserveOccupancyStatus__root__WaitingForFinishBooting;
};

void make_state_FObserveOccupancyStatus__root__TechnicalDisturbance(FObserveOccupancyStatus *self,
                                                                    FObserveOccupancyStatus__root__state_struct *region)
{
    LOG("[FObserveOccupancyStatus] Entering state TechnicalDisturbance in region root");
    region->state = FObserveOccupancyStatus__root__TechnicalDisturbance;
};

void make_state_FObserveOccupancyStatus__root(FObserveOccupancyStatus *self,
                                              FObserveOccupancyStatus__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveOccupancyStatus__root__state_struct));

    make_state_FObserveOccupancyStatus__root__WaitingForFinishBooting(self, x);
    return;
}

void transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{

    if (self->InExecuteDrfc__4da5.HasMessage)
    {
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableOut;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing(
            self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->InExecuteFc__ffe5.HasMessage)
    {
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__Vacant;
        self->D9outOccupancyStatus.IsSignalled = true;
        self->MemDifference = 0;
        self->MemEnteredaxles = 0;
        self->MemExitedaxles = 0;
        self->D16outLastWheelOut.Value = false;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant(self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1110.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableOut;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing(
            self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1098.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(
            self, &x->ObserveTvpsStatus.root);
        return;
    }
}

void transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{

    if (self->InExecuteFc__ffe5.HasMessage)
    {
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__Vacant;
        self->D9outOccupancyStatus.IsSignalled = true;
        self->MemDifference = 0;
        self->MemEnteredaxles = 0;
        self->MemExitedaxles = 0;
        self->D16outLastWheelOut.Value = false;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant(self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1103.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableIn;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(
            self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1106.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing(
            self, &x->ObserveTvpsStatus.root);
        return;
    }
}

void transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{

    if (self->Change1094.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__OccupiedIn;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming(self,
                                                                                            &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1104.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableOut;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing(
            self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1115.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableIn;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(
            self, &x->ObserveTvpsStatus.root);
        return;
    }
}

void transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{

    if (self->InExecuteDrfc__4da5.HasMessage)
    {
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__OccupiedOut;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing(self,
                                                                                            &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->InExecuteFc__ffe5.HasMessage)
    {
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__Vacant;
        self->D9outOccupancyStatus.IsSignalled = true;
        self->MemDifference = 0;
        self->MemEnteredaxles = 0;
        self->MemExitedaxles = 0;
        self->D16outLastWheelOut.Value = false;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant(self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1107.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__OccupiedOut;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing(self,
                                                                                            &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1114.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableIn;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(
            self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1099.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming(self,
                                                                                            &x->ObserveTvpsStatus.root);
        return;
    }
}

void transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{

    if (self->InExecuteFc__ffe5.HasMessage)
    {
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__Vacant;
        self->D9outOccupancyStatus.IsSignalled = true;
        self->MemDifference = 0;
        self->MemEnteredaxles = 0;
        self->MemExitedaxles = 0;
        self->D16outLastWheelOut.Value = false;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant(self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change536.IsTriggered)
    {
        if (self->D28inConTDelayOfNotificationOfAvailability.Value != 0)
        {
            self->D16outLastWheelOut.Value = true;
            make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__WaitingForNotificationOfAvailability(
                self, &x->ObserveTvpsStatus.root);
            return;
        }
    }
    if (self->Change534.IsTriggered)
    {
        if (self->D28inConTDelayOfNotificationOfAvailability.Value == 0)
        {
            self->D16outLastWheelOut.Value = true;
            self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__Vacant;
            self->D9outOccupancyStatus.IsSignalled = true;
            self->MemDifference = 0;
            self->MemEnteredaxles = 0;
            self->MemExitedaxles = 0;
            self->D16outLastWheelOut.Value = false;
            make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant(self, &x->ObserveTvpsStatus.root);
            return;
        }
    }
    if (self->Change1095.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__OccupiedIn;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming(self,
                                                                                            &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1111.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableIn;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(
            self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1109.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing(self,
                                                                                            &x->ObserveTvpsStatus.root);
        return;
    }
}

void transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__WaitingForNotificationOfAvailability(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{

    if (self->Change546.IsTriggered)
    {
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__Vacant;
        self->D9outOccupancyStatus.IsSignalled = true;
        self->MemDifference = 0;
        self->MemEnteredaxles = 0;
        self->MemExitedaxles = 0;
        self->D16outLastWheelOut.Value = false;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant(self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1096.IsTriggered)
    {
        self->D16outLastWheelOut.Value = false;
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__OccupiedIn;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming(self,
                                                                                            &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1108.IsTriggered)
    {
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableOut;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing(
            self, &x->ObserveTvpsStatus.root);
        return;
    }
    if (self->Change1112.IsTriggered)
    {
        self->D16outLastWheelOut.Value = false;
        Cop3ReportCtPassing(self);
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__UnreliableIn;
        self->D9outOccupancyStatus.IsSignalled = true;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(
            self, &x->ObserveTvpsStatus.root);
        return;
    }
}

void transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{
    switch (x->ObserveTvpsStatus.root.state)
    {
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming:
        transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableIncoming(self, x);
        break;
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing:
        transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__UnreliableOutgoing(self, x);
        break;
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant:
        transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__Vacant(self, x);
        break;
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming:
        transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedIncoming(self, x);
        break;
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing:
        transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__OccupiedOutgoing(self, x);
        break;
    case FObserveOccupancyStatus__root__ObserveTvpsStatus__root__WaitingForNotificationOfAvailability:
        transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root__WaitingForNotificationOfAvailability(
            self, x);
        break;
    }
}

void transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus(FObserveOccupancyStatus *self,
                                                                      FObserveOccupancyStatus__root__state_struct *x)
{
    transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus__root(self, x);
    if (self->Change235.IsTriggered)
    {
        self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__TechnicalDisturbed;
        self->D9outOccupancyStatus.IsSignalled = true;

        self->OutChangeTrigger__e05e.Value.ReportedChangeTrigger = ChangeTrigger__de2d__TechnicalFailure;
        self->OutChangeTrigger__e05e.HasMessage = 1;
        make_state_FObserveOccupancyStatus__root__TechnicalDisturbance(self, x);
        return;
    }
    if (self->Change389.IsTriggered)
    {

        make_state_FObserveOccupancyStatus__root__WaitingForFinishBooting(self, x);
        return;
    }
    if (self->Change397.IsTriggered)
    {

        make_state_FObserveOccupancyStatus__root__FallbackMode(self, x);
        return;
    }
    if (self->Change1097.IsTriggered)
    {
        self->MemEnteredaxles = self->MemEnteredaxles + 1;
        self->MemDifference = self->MemEnteredaxles;
        self->D10outFillinglevel.Value = self->MemDifference;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus(self, x);
        return;
    }
    if (self->Change1105.IsTriggered)
    {
        self->MemExitedaxles = self->MemExitedaxles + 1;
        self->MemDifference = self->MemEnteredaxles;
        self->D10outFillinglevel.Value = self->MemDifference;
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus(self, x);
        return;
    }
}

void transition_from_FObserveOccupancyStatus__root__FallbackMode(FObserveOccupancyStatus *self,
                                                                 FObserveOccupancyStatus__root__state_struct *x)
{

    if (self->Change382.IsTriggered)
    {

        make_state_FObserveOccupancyStatus__root__WaitingForFinishBooting(self, x);
        return;
    }
}

void transition_from_FObserveOccupancyStatus__root__WaitingForFinishBooting(
    FObserveOccupancyStatus *self, FObserveOccupancyStatus__root__state_struct *x)
{

    if (self->Change404.IsTriggered)
    {

        if (self->D32inCriticalFailureTvps.Value)
        {
            self->D9outOccupancyStatus.Value = FObserveOccupancyStatus_D9outOccupancyStatusValue__TechnicalDisturbed;
            self->D9outOccupancyStatus.IsSignalled = true;

            self->OutChangeTrigger__e05e.Value.ReportedChangeTrigger = ChangeTrigger__de2d__TechnicalFailure;
            self->OutChangeTrigger__e05e.HasMessage = 1;
            make_state_FObserveOccupancyStatus__root__TechnicalDisturbance(self, x);
            return;
        }
        else
        {
            Cop4ResetCount(self);
            make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus(self, x);
            return;
        }
    }
}

void transition_from_FObserveOccupancyStatus__root__TechnicalDisturbance(FObserveOccupancyStatus *self,
                                                                         FObserveOccupancyStatus__root__state_struct *x)
{

    if (self->Change394.IsTriggered)
    {

        make_state_FObserveOccupancyStatus__root__FallbackMode(self, x);
        return;
    }
    if (self->Change560.IsTriggered)
    {
        Cop4ResetCount(self);
        make_state_FObserveOccupancyStatus__root__ObserveTvpsStatus(self, x);
        return;
    }
}

void transition_from_FObserveOccupancyStatus__root(FObserveOccupancyStatus *self,
                                                   FObserveOccupancyStatus__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveOccupancyStatus__root__ObserveTvpsStatus:
        transition_from_FObserveOccupancyStatus__root__ObserveTvpsStatus(self, x);
        break;
    case FObserveOccupancyStatus__root__FallbackMode:
        transition_from_FObserveOccupancyStatus__root__FallbackMode(self, x);
        break;
    case FObserveOccupancyStatus__root__WaitingForFinishBooting:
        transition_from_FObserveOccupancyStatus__root__WaitingForFinishBooting(self, x);
        break;
    case FObserveOccupancyStatus__root__TechnicalDisturbance:
        transition_from_FObserveOccupancyStatus__root__TechnicalDisturbance(self, x);
        break;
    }
}

static void evaluateChangeEvents(FObserveOccupancyStatus *self)
{
    self->Change1110.IsTriggered = self->T38inWheelOut.IsTriggered;
    self->Change1098.IsTriggered = self->T37inWheelIn.IsTriggered;
    self->Change1103.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->T37inWheelIn.IsTriggered, self->T37inWheelIn.IsTriggered),
                 MakeChange(self->T39inUndefinedPattern.IsTriggered, self->T39inUndefinedPattern.IsTriggered)));
    self->Change1106.IsTriggered = self->T38inWheelOut.IsTriggered;
    self->Change1094.IsTriggered = self->T37inWheelIn.IsTriggered;
    self->Change1104.IsTriggered = self->T38inWheelOut.IsTriggered;
    self->Change1115.IsTriggered = self->T39inUndefinedPattern.IsTriggered;
    self->Change1107.IsTriggered = self->T38inWheelOut.IsTriggered;
    self->Change1114.IsTriggered = self->T39inUndefinedPattern.IsTriggered;
    self->Change1099.IsTriggered = self->T37inWheelIn.IsTriggered;
    self->Change536.IsTriggered = IsTriggered(MakeChange(self->MemDifference.IsSignalled, self->MemDifference == 0));
    self->Change534.IsTriggered = IsTriggered(MakeChange(self->MemDifference.IsSignalled, self->MemDifference == 0));
    self->Change1095.IsTriggered = self->T37inWheelIn.IsTriggered;
    self->Change1111.IsTriggered = self->T39inUndefinedPattern.IsTriggered;
    self->Change1109.IsTriggered = self->T38inWheelOut.IsTriggered;
    self->Change546.IsTriggered =
        IsTriggered(NegateChange(MakeChange(self->D14inMonitoringTime.IsSignalled, self->D14inMonitoringTime.Value)));
    self->Change1096.IsTriggered = self->T37inWheelIn.IsTriggered;
    self->Change1108.IsTriggered = self->T38inWheelOut.IsTriggered;
    self->Change1112.IsTriggered = self->T39inUndefinedPattern.IsTriggered;
    self->Change235.IsTriggered =
        IsTriggered(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value));
    self->Change389.IsTriggered = IsTriggered(
        OrChange(MakeChange(self->D51outEstEfesState.IsSignalled,
                            self->D51outEstEfesState.Value == FObserveOccupancyStatus_D51outEstEfesStateValue__Booting),
                 MakeChange(self->D51outEstEfesState.IsSignalled,
                            self->D51outEstEfesState.Value ==
                                FObserveOccupancyStatus_D51outEstEfesStateValue__NoOperatingVoltage)));
    self->Change397.IsTriggered = IsTriggered(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveOccupancyStatus_D51outEstEfesStateValue__FallbackMode));
    self->Change1097.IsTriggered = self->T37inWheelIn.IsTriggered;
    self->Change1105.IsTriggered = self->T38inWheelOut.IsTriggered;
    self->Change382.IsTriggered = IsTriggered(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveOccupancyStatus_D51outEstEfesStateValue__Booting));
    self->Change404.IsTriggered = IsTriggered(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveOccupancyStatus_D51outEstEfesStateValue__Initialising));
    self->Change394.IsTriggered = IsTriggered(
        MakeChange(self->D51outEstEfesState.IsSignalled,
                   self->D51outEstEfesState.Value == FObserveOccupancyStatus_D51outEstEfesStateValue__FallbackMode));
    self->Change560.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D32inCriticalFailureTvps.IsSignalled, self->D32inCriticalFailureTvps.Value)));
}

static void resetOutputs(FObserveOccupancyStatus *self)
{
    self->OutChangeTrigger__e05e.HasMessage = false;

    self->D9outOccupancyStatus.IsSignalled = false;
    self->D51outEstEfesState.IsSignalled = false;
    self->D10outFillinglevel.IsSignalled = false;
    self->D16outLastWheelOut.IsSignalled = false;
}

static void resetTriggers(FObserveOccupancyStatus *self)
{
    self->InExecuteDrfc__4da5.HasMessage = false;
    self->InExecuteFc__ffe5.HasMessage = false;

    self->T37inWheelIn.IsTriggered = false;
    self->T38inWheelOut.IsTriggered = false;
    self->T39inUndefinedPattern.IsTriggered = false;

    self->D26inConVariantAIsUsed.IsSignalled = false;
    self->D32inCriticalFailureTvps.IsSignalled = false;
    self->D14inMonitoringTime.IsSignalled = false;
    self->D28inConTDelayOfNotificationOfAvailability.IsSignalled = false;
}

void transition_FObserveOccupancyStatus(FObserveOccupancyStatus *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FObserveOccupancyStatus__root(self, &self->state);
    resetTriggers(self);
}

void new_FObserveOccupancyStatus(FObserveOccupancyStatus *self)
{
    make_state_FObserveOccupancyStatus__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemTrainDetectionSystem/FObserveOccupancyStatus.c"
#endif
