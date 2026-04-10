
#include "FMonitorTimeValues.h"

// Value Conversion Functions

// Operations
static void Cop2ReactOnClosureTimeOverrun(FMonitorTimeValues *self)
{
    if (self->D68inConFailureStatusAfterClosureTimeOverrun.Value ==
        FMonitorTimeValues_D68inConFailureStatusAfterClosureTimeOverrunValue__NonCriticalFailureReport)
    {
        self->D75outLcFailureStatus.Value = FMonitorTimeValues_D75outLcFailureStatusValue__ANonCriticalFailureIsPresent;
        self->D75outLcFailureStatus.IsSignalled = true;
    }
    else if (self->D68inConFailureStatusAfterClosureTimeOverrun.Value ==
             FMonitorTimeValues_D68inConFailureStatusAfterClosureTimeOverrunValue__CriticalFailureReport)
    {
        self->D75outLcFailureStatus.Value = FMonitorTimeValues_D75outLcFailureStatusValue__ACriticalFailureIsPresent;
        self->D75outLcFailureStatus.IsSignalled = true;
    }
}
static void Cop3ReactOnNoClosureTimeOverrun(FMonitorTimeValues *self)
{
    if (self->D68inConFailureStatusAfterClosureTimeOverrun.Value ==
        FMonitorTimeValues_D68inConFailureStatusAfterClosureTimeOverrunValue__NonCriticalFailureReport)
    {
        self->D75outLcFailureStatus.Value = FMonitorTimeValues_D75outLcFailureStatusValue__NoNonCriticalFailurePresent;
        self->D75outLcFailureStatus.IsSignalled = true;
    }
    else if (self->D68inConFailureStatusAfterClosureTimeOverrun.Value ==
             FMonitorTimeValues_D68inConFailureStatusAfterClosureTimeOverrunValue__CriticalFailureReport)
    {
        self->D75outLcFailureStatus.Value = FMonitorTimeValues_D75outLcFailureStatusValue__NoCriticalFailurePresent;
        self->D75outLcFailureStatus.IsSignalled = true;
    }
}

void make_state_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle(
    FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__state_struct *region)
{
    LOG("[FMonitorTimeValues] Entering state Idle in region "
        "root__MonitorTimeValues__MonitorClosureTime");
    region->state = FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle;
};

void make_state_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeIsRunning(
    FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__state_struct *region)
{
    LOG("[FMonitorTimeValues] Entering state ClosureTimeIsRunning in region "
        "root__MonitorTimeValues__MonitorClosureTime");
    region->state = FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeIsRunning;
};

void make_state_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeExpired(
    FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__state_struct *region)
{
    LOG("[FMonitorTimeValues] Entering state ClosureTimeExpired in region "
        "root__MonitorTimeValues__MonitorClosureTime");
    region->state = FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeExpired;
};

void make_state_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime(
    FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__state_struct *x)
{
    memset(x, 0, sizeof(FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__state_struct));
    self->D6outLcMonitoringStatus.Value = FMonitorTimeValues_D6outLcMonitoringStatusValue__NoClosureTimeOverrun;
    self->D6outLcMonitoringStatus.IsSignalled = true;
    Cop3ReactOnNoClosureTimeOverrun(self);
    make_state_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle(self, x);
    return;
}

void make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Idle(
    FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state_struct *region)
{
    LOG("[FMonitorTimeValues] Entering state Idle in region "
        "root__MonitorTimeValues__PdiConLossDelay");
    region->state = FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Idle;
};

void make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__WaitingForDelay(
    FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state_struct *region)
{
    LOG("[FMonitorTimeValues] Entering state WaitingForDelay in region "
        "root__MonitorTimeValues__PdiConLossDelay");
    region->state = FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__WaitingForDelay;
};

void make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__DelayReached(
    FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state_struct *region)
{
    LOG("[FMonitorTimeValues] Entering state DelayReached in region "
        "root__MonitorTimeValues__PdiConLossDelay");
    region->state = FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__DelayReached;
};

void make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting(
    FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state_struct *region)
{
    LOG("[FMonitorTimeValues] Entering state Waiting in region "
        "root__MonitorTimeValues__PdiConLossDelay");
    region->state = FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting;
};

void make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay(
    FMonitorTimeValues *self, FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state_struct *x)
{
    memset(x, 0, sizeof(FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__state_struct));

    make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Idle(self, x);
    return;
}

void make_state_FMonitorTimeValues__root__WaitingForFinishBooting(FMonitorTimeValues *self,
                                                                  FMonitorTimeValues__root__state_struct *region)
{
    LOG("[FMonitorTimeValues] Entering state WaitingForFinishBooting in region "
        "root");
    region->state = FMonitorTimeValues__root__WaitingForFinishBooting;
};

void make_state_FMonitorTimeValues__root__Fallbackmode(FMonitorTimeValues *self,
                                                       FMonitorTimeValues__root__state_struct *region)
{
    LOG("[FMonitorTimeValues] Entering state Fallbackmode in region root");
    region->state = FMonitorTimeValues__root__Fallbackmode;
};

void make_state_FMonitorTimeValues__root__TechnicalDisturbance(FMonitorTimeValues *self,
                                                               FMonitorTimeValues__root__state_struct *region)
{
    LOG("[FMonitorTimeValues] Entering state TechnicalDisturbance in region "
        "root");
    region->state = FMonitorTimeValues__root__TechnicalDisturbance;
};

void make_state_FMonitorTimeValues__root__MonitorTimeValues(FMonitorTimeValues *self,
                                                            FMonitorTimeValues__root__state_struct *region)
{
    LOG("[FMonitorTimeValues] Entering state MonitorTimeValues in region root");
    region->state = FMonitorTimeValues__root__MonitorTimeValues;
    make_state_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime(
        self, &region->MonitorTimeValues.MonitorClosureTime);
    make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay(self,
                                                                            &region->MonitorTimeValues.PdiConLossDelay);
};

void make_state_FMonitorTimeValues__root(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    memset(x, 0, sizeof(FMonitorTimeValues__root__state_struct));

    make_state_FMonitorTimeValues__root__MonitorTimeValues(self, x);
    return;
}

void transition_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle(
    FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{

    if (self->Change155.IsTriggered)
    {
        if (self->D63inConUseClosureTime.Value == true)
        {

            make_state_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeIsRunning(
                self, &x->MonitorTimeValues.MonitorClosureTime);
            return;
        }
    }
}

void transition_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeIsRunning(
    FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{

    if (self->Time33.IsTimeoutExpired)
    {
        Cop2ReactOnClosureTimeOverrun(self);
        self->D6outLcMonitoringStatus.Value =
            FMonitorTimeValues_D6outLcMonitoringStatusValue__ClosureTimeOverrunOccurred;
        self->D6outLcMonitoringStatus.IsSignalled = true;
        make_state_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeExpired(
            self, &x->MonitorTimeValues.MonitorClosureTime);
        return;
    }
    if (self->Change244.IsTriggered)
    {
        self->D6outLcMonitoringStatus.Value = FMonitorTimeValues_D6outLcMonitoringStatusValue__NoClosureTimeOverrun;
        self->D6outLcMonitoringStatus.IsSignalled = true;
        Cop3ReactOnNoClosureTimeOverrun(self);
        make_state_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle(
            self, &x->MonitorTimeValues.MonitorClosureTime);
        return;
    }
}

void transition_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeExpired(
    FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{

    if (self->Change243.IsTriggered)
    {
        self->D6outLcMonitoringStatus.Value = FMonitorTimeValues_D6outLcMonitoringStatusValue__NoClosureTimeOverrun;
        self->D6outLcMonitoringStatus.IsSignalled = true;
        Cop3ReactOnNoClosureTimeOverrun(self);
        make_state_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle(
            self, &x->MonitorTimeValues.MonitorClosureTime);
        return;
    }
}

void transition_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime(
    FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    switch (x->MonitorTimeValues.MonitorClosureTime.state)
    {
    case FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle:
        transition_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__Idle(self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeIsRunning:
        transition_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeIsRunning(self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeExpired:
        transition_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime__ClosureTimeExpired(self, x);
        break;
    }
}

void transition_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Idle(
    FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{

    if (self->Change324.IsTriggered)
    {

        make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting(
            self, &x->MonitorTimeValues.PdiConLossDelay);
        return;
    }
}

void transition_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__WaitingForDelay(
    FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{

    if (self->Time40.IsTimeoutExpired)
    {
        self->D53outTimeExpired.Value = FMonitorTimeValues_D53outTimeExpiredValue__DelayExpired;
        self->D53outTimeExpired.IsSignalled = true;
        make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__DelayReached(
            self, &x->MonitorTimeValues.PdiConLossDelay);
        return;
    }
    if (self->Change326.IsTriggered)
    {

        make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting(
            self, &x->MonitorTimeValues.PdiConLossDelay);
        return;
    }
}

void transition_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__DelayReached(
    FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{

    if (self->Change376.IsTriggered)
    {
        self->D53outTimeExpired.Value = FMonitorTimeValues_D53outTimeExpiredValue__DelayNotExpired;
        self->D53outTimeExpired.IsSignalled = true;
        make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting(
            self, &x->MonitorTimeValues.PdiConLossDelay);
        return;
    }
}

void transition_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting(
    FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{

    if (self->Change321.IsTriggered)
    {
        if ((!(self->D1inReceiveLcState.Value == FMonitorTimeValues_D1inReceiveLcStateValue__Isolated)) &&
            (self->D64inConUsePdiConLossDeactivationDelay.Value == true))
        {

            make_state_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__WaitingForDelay(
                self, &x->MonitorTimeValues.PdiConLossDelay);
            return;
        }
    }
}

void transition_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay(
    FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    switch (x->MonitorTimeValues.PdiConLossDelay.state)
    {
    case FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Idle:
        transition_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Idle(self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__WaitingForDelay:
        transition_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__WaitingForDelay(self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__DelayReached:
        transition_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__DelayReached(self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting:
        transition_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay__Waiting(self, x);
        break;
    }
}

void transition_from_FMonitorTimeValues__root__WaitingForFinishBooting(FMonitorTimeValues *self,
                                                                       FMonitorTimeValues__root__state_struct *x)
{
}

void transition_from_FMonitorTimeValues__root__Fallbackmode(FMonitorTimeValues *self,
                                                            FMonitorTimeValues__root__state_struct *x)
{
}

void transition_from_FMonitorTimeValues__root__TechnicalDisturbance(FMonitorTimeValues *self,
                                                                    FMonitorTimeValues__root__state_struct *x)
{
}

void transition_from_FMonitorTimeValues__root__MonitorTimeValues(FMonitorTimeValues *self,
                                                                 FMonitorTimeValues__root__state_struct *x)
{
    transition_from_FMonitorTimeValues__root__MonitorTimeValues__MonitorClosureTime(self, x);
    transition_from_FMonitorTimeValues__root__MonitorTimeValues__PdiConLossDelay(self, x);
}

void transition_from_FMonitorTimeValues__root(FMonitorTimeValues *self, FMonitorTimeValues__root__state_struct *x)
{
    switch (x->state)
    {
    case FMonitorTimeValues__root__WaitingForFinishBooting:
        transition_from_FMonitorTimeValues__root__WaitingForFinishBooting(self, x);
        break;
    case FMonitorTimeValues__root__Fallbackmode:
        transition_from_FMonitorTimeValues__root__Fallbackmode(self, x);
        break;
    case FMonitorTimeValues__root__TechnicalDisturbance:
        transition_from_FMonitorTimeValues__root__TechnicalDisturbance(self, x);
        break;
    case FMonitorTimeValues__root__MonitorTimeValues:
        transition_from_FMonitorTimeValues__root__MonitorTimeValues(self, x);
        break;
    }
}

static void evaluateChangeEvents(FMonitorTimeValues *self)
{
    self->Change155.IsTriggered = IsTriggered(
        MakeChange(self->D1inReceiveLcState.IsSignalled,
                   self->D1inReceiveLcState.Value == FMonitorTimeValues_D1inReceiveLcStateValue__Activated));
    self->Change244.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D3inLcpfProtectionState.IsSignalled,
                   self->D3inLcpfProtectionState.Value == FMonitorTimeValues_D3inLcpfProtectionStateValue__Idle),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FMonitorTimeValues_D51inEstEfesStateValue__FallbackMode)));
    self->Change243.IsTriggered = IsTriggered(OrChange(
        MakeChange(self->D3inLcpfProtectionState.IsSignalled,
                   self->D3inLcpfProtectionState.Value == FMonitorTimeValues_D3inLcpfProtectionStateValue__Idle),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FMonitorTimeValues_D51inEstEfesStateValue__FallbackMode)));
    self->Change324.IsTriggered = IsTriggered(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FMonitorTimeValues_D51inEstEfesStateValue__Operational));
    self->Change326.IsTriggered = IsTriggered(OrChange(
        OrChange(MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value == FMonitorTimeValues_D51inEstEfesStateValue__Operational),
                 MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value == FMonitorTimeValues_D51inEstEfesStateValue__Booting)),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FMonitorTimeValues_D51inEstEfesStateValue__NoOperatingVoltage)));
    self->Change376.IsTriggered = IsTriggered(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FMonitorTimeValues_D51inEstEfesStateValue__Operational));
    self->Change321.IsTriggered = IsTriggered(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FMonitorTimeValues_D51inEstEfesStateValue__Initialising));
}

static void resetOutputs(FMonitorTimeValues *self)
{

    self->D53outTimeExpired.IsSignalled = false;
    self->D6outLcMonitoringStatus.IsSignalled = false;
    self->D75outLcFailureStatus.IsSignalled = false;
}

static void resetTriggers(FMonitorTimeValues *self)
{

    self->D64inConUsePdiConLossDeactivationDelay.IsSignalled = false;
    self->D63inConUseClosureTime.IsSignalled = false;
    self->D54inConTmaxClosureTime.IsSignalled = false;
    self->D56inConTPdiConLossDeactivationDelay.IsSignalled = false;
    self->D1inReceiveLcState.IsSignalled = false;
    self->D3inLcpfProtectionState.IsSignalled = false;
    self->D68inConFailureStatusAfterClosureTimeOverrun.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;

    self->Time33.IsTimeoutExpired = false;
    self->Time40.IsTimeoutExpired = false;
}

void transition_FMonitorTimeValues(FMonitorTimeValues *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FMonitorTimeValues__root(self, &self->state);
    resetTriggers(self);
}

void new_FMonitorTimeValues(FMonitorTimeValues *self)
{
    make_state_FMonitorTimeValues__root(self, &self->state);
}
