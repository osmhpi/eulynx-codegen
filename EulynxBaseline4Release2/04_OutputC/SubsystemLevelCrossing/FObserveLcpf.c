
#include "FObserveLcpf.h"

// Value Conversion Functions

// Operations

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state Unprotected in region root__ObserveLcpf__ObserveLcpfProtectionState");
    region->state = FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected;
};

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Protected(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state Protected in region root__ObserveLcpf__ObserveLcpfProtectionState");
    region->state = FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Protected;
};

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Idle(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state Idle in region root__ObserveLcpf__ObserveLcpfProtectionState");
    region->state = FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Idle;
};

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__state_struct *x)
{
    memset(x, 0, sizeof(FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__state_struct));
    self->D3outLcpfProtectionState.Value = FObserveLcpf_D3outLcpfProtectionStateValue__Unprotected;
    self->D3outLcpfProtectionState.IsSignalled = true;
    make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected(self, x);
    return;
}

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__NoObstacleInConflictArea(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state NoObstacleInConflictArea in region "
        "root__ObserveLcpf__ObserveLcpfObstacleDetectionState");
    region->state = FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__NoObstacleInConflictArea;
};

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__ObstacleInConflictArea(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state ObstacleInConflictArea in region "
        "root__ObserveLcpf__ObserveLcpfObstacleDetectionState");
    region->state = FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__ObstacleInConflictArea;
};

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__Waiting(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state Waiting in region root__ObserveLcpf__ObserveLcpfObstacleDetectionState");
    region->state = FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__Waiting;
};

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__state_struct *x)
{
    memset(x, 0, sizeof(FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__state_struct));

    make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__Waiting(self, x);
    return;
}

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__NoFailureDetected(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state NoFailureDetected in region root__ObserveLcpf__ObserveLcpfFailureState");
    region->state = FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__NoFailureDetected;
};

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__FailureDetected(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state FailureDetected in region root__ObserveLcpf__ObserveLcpfFailureState");
    region->state = FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__FailureDetected;
};

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__Waiting(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state Waiting in region root__ObserveLcpf__ObserveLcpfFailureState");
    region->state = FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__Waiting;
};

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__state_struct *x)
{
    memset(x, 0, sizeof(FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__state_struct));

    make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__Waiting(self, x);
    return;
}

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet2(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state MonitoringParameterSet2 in region root__ObserveLcpf__ObserveMonitoringStatus");
    region->state = FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet2;
};

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet1(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state MonitoringParameterSet1 in region root__ObserveLcpf__ObserveMonitoringStatus");
    region->state = FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet1;
};

void make_state_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus(
    FObserveLcpf *self, FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__state_struct *x)
{
    memset(x, 0, sizeof(FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__state_struct));
    self->D9outChangedMonitoringState.Value = FObserveLcpf_D9outChangedMonitoringStateValue__MonitoringParameterSet1;
    self->D9outChangedMonitoringState.IsSignalled = true;
    make_state_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet1(self, x);
    return;
}

void make_state_FObserveLcpf__root__ObserveLcpf(FObserveLcpf *self, FObserveLcpf__root__state_struct *region)
{
    LOG("[FObserveLcpf] Entering state ObserveLcpf in region root");
    region->state = FObserveLcpf__root__ObserveLcpf;
    make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState(
        self, &region->ObserveLcpf.ObserveLcpfProtectionState);
    make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState(
        self, &region->ObserveLcpf.ObserveLcpfObstacleDetectionState);
    make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState(self,
                                                                        &region->ObserveLcpf.ObserveLcpfFailureState);
    make_state_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus(self,
                                                                        &region->ObserveLcpf.ObserveMonitoringStatus);
};

void make_state_FObserveLcpf__root(FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    memset(x, 0, sizeof(FObserveLcpf__root__state_struct));

    make_state_FObserveLcpf__root__ObserveLcpf(self, x);
    return;
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{

    if (self->Change230.IsTriggered)
    {
        self->D3outLcpfProtectionState.Value = FObserveLcpf_D3outLcpfProtectionStateValue__Idle;
        self->D3outLcpfProtectionState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Idle(
            self, &x->ObserveLcpf.ObserveLcpfProtectionState);
        return;
    }
    if (self->Change233.IsTriggered)
    {
        self->D3outLcpfProtectionState.Value = FObserveLcpf_D3outLcpfProtectionStateValue__Protected;
        self->D3outLcpfProtectionState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Protected(
            self, &x->ObserveLcpf.ObserveLcpfProtectionState);
        return;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Protected(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{

    if (self->Change231.IsTriggered)
    {
        self->D3outLcpfProtectionState.Value = FObserveLcpf_D3outLcpfProtectionStateValue__Idle;
        self->D3outLcpfProtectionState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Idle(
            self, &x->ObserveLcpf.ObserveLcpfProtectionState);
        return;
    }
    if (self->Change237.IsTriggered)
    {
        self->D3outLcpfProtectionState.Value = FObserveLcpf_D3outLcpfProtectionStateValue__Unprotected;
        self->D3outLcpfProtectionState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected(
            self, &x->ObserveLcpf.ObserveLcpfProtectionState);
        return;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Idle(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{

    if (self->Change232.IsTriggered)
    {
        self->D3outLcpfProtectionState.Value = FObserveLcpf_D3outLcpfProtectionStateValue__Protected;
        self->D3outLcpfProtectionState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Protected(
            self, &x->ObserveLcpf.ObserveLcpfProtectionState);
        return;
    }
    if (self->Change235.IsTriggered)
    {
        self->D3outLcpfProtectionState.Value = FObserveLcpf_D3outLcpfProtectionStateValue__Unprotected;
        self->D3outLcpfProtectionState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected(
            self, &x->ObserveLcpf.ObserveLcpfProtectionState);
        return;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState(FObserveLcpf *self,
                                                                                 FObserveLcpf__root__state_struct *x)
{
    switch (x->ObserveLcpf.ObserveLcpfProtectionState.state)
    {
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected:
        transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected(self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Protected:
        transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Protected(self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Idle:
        transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Idle(self, x);
        break;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__NoObstacleInConflictArea(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{

    if (self->Change249.IsTriggered)
    {
        self->D4outObstacleDetectionStatus.Value =
            FObserveLcpf_D4outObstacleDetectionStatusValue__ObstacleDetectedInTheConflictArea;
        self->D4outObstacleDetectionStatus.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__ObstacleInConflictArea(
            self, &x->ObserveLcpf.ObserveLcpfObstacleDetectionState);
        return;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__ObstacleInConflictArea(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{

    if (self->Change566.IsTriggered)
    {
        self->D4outObstacleDetectionStatus.Value =
            FObserveLcpf_D4outObstacleDetectionStatusValue__NoObstacleInTheConflictArea;
        self->D4outObstacleDetectionStatus.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__NoObstacleInConflictArea(
            self, &x->ObserveLcpf.ObserveLcpfObstacleDetectionState);
        return;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__Waiting(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{

    if (self->Change248.IsTriggered)
    {
        self->D4outObstacleDetectionStatus.Value =
            FObserveLcpf_D4outObstacleDetectionStatusValue__ObstacleDetectedInTheConflictArea;
        self->D4outObstacleDetectionStatus.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__ObstacleInConflictArea(
            self, &x->ObserveLcpf.ObserveLcpfObstacleDetectionState);
        return;
    }
    if (self->Change567.IsTriggered)
    {
        if (self->D109inConUseObstacleDetection.Value)
        {
            self->D4outObstacleDetectionStatus.Value =
                FObserveLcpf_D4outObstacleDetectionStatusValue__NoObstacleInTheConflictArea;
            self->D4outObstacleDetectionStatus.IsSignalled = true;
            make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__NoObstacleInConflictArea(
                self, &x->ObserveLcpf.ObserveLcpfObstacleDetectionState);
            return;
        }
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    switch (x->ObserveLcpf.ObserveLcpfObstacleDetectionState.state)
    {
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__NoObstacleInConflictArea:
        transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__NoObstacleInConflictArea(
            self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__ObstacleInConflictArea:
        transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__ObstacleInConflictArea(self,
                                                                                                                   x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__Waiting:
        transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__Waiting(self, x);
        break;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__NoFailureDetected(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{

    if (self->Change260.IsTriggered)
    {
        self->D74outLcpfFailureState.Value = FObserveLcpf_D74outLcpfFailureStateValue__FailurePresent;
        self->D74outLcpfFailureState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__FailureDetected(
            self, &x->ObserveLcpf.ObserveLcpfFailureState);
        return;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__FailureDetected(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{

    if (self->Change571.IsTriggered)
    {
        self->D74outLcpfFailureState.Value = FObserveLcpf_D74outLcpfFailureStateValue__NoFailurePresent;
        self->D74outLcpfFailureState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__NoFailureDetected(
            self, &x->ObserveLcpf.ObserveLcpfFailureState);
        return;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__Waiting(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{

    if (self->Change1.IsTriggered)
    {
        self->D74outLcpfFailureState.Value = FObserveLcpf_D74outLcpfFailureStateValue__FailurePresent;
        self->D74outLcpfFailureState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__FailureDetected(
            self, &x->ObserveLcpf.ObserveLcpfFailureState);
        return;
    }
    if (self->Change572.IsTriggered)
    {
        self->D74outLcpfFailureState.Value = FObserveLcpf_D74outLcpfFailureStateValue__NoFailurePresent;
        self->D74outLcpfFailureState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__NoFailureDetected(
            self, &x->ObserveLcpf.ObserveLcpfFailureState);
        return;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState(FObserveLcpf *self,
                                                                              FObserveLcpf__root__state_struct *x)
{
    switch (x->ObserveLcpf.ObserveLcpfFailureState.state)
    {
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__NoFailureDetected:
        transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__NoFailureDetected(self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__FailureDetected:
        transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__FailureDetected(self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__Waiting:
        transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__Waiting(self, x);
        break;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet2(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{

    if (self->Change2.IsTriggered)
    {
        self->D9outChangedMonitoringState.Value =
            FObserveLcpf_D9outChangedMonitoringStateValue__MonitoringParameterSet1;
        self->D9outChangedMonitoringState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet1(
            self, &x->ObserveLcpf.ObserveMonitoringStatus);
        return;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet1(
    FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{

    if (self->Change261.IsTriggered)
    {
        self->D9outChangedMonitoringState.Value =
            FObserveLcpf_D9outChangedMonitoringStateValue__MonitoringParameterSet2;
        self->D9outChangedMonitoringState.IsSignalled = true;
        make_state_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet2(
            self, &x->ObserveLcpf.ObserveMonitoringStatus);
        return;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus(FObserveLcpf *self,
                                                                              FObserveLcpf__root__state_struct *x)
{
    switch (x->ObserveLcpf.ObserveMonitoringStatus.state)
    {
    case FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet2:
        transition_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet2(self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet1:
        transition_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet1(self, x);
        break;
    }
}

void transition_from_FObserveLcpf__root__ObserveLcpf(FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState(self, x);
    transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState(self, x);
    transition_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState(self, x);
    transition_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus(self, x);
}

void transition_from_FObserveLcpf__root(FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveLcpf__root__ObserveLcpf:
        transition_from_FObserveLcpf__root__ObserveLcpf(self, x);
        break;
    }
}

static void evaluateChangeEvents(FObserveLcpf *self)
{
    self->Change230.IsTriggered = IsTriggered(
        MakeChange(self->D30inLcpfProtectionState.IsSignalled,
                   self->D30inLcpfProtectionState.Value == FObserveLcpf_D30inLcpfProtectionStateValue__Idle));
    self->Change233.IsTriggered = IsTriggered(
        MakeChange(self->D30inLcpfProtectionState.IsSignalled,
                   self->D30inLcpfProtectionState.Value == FObserveLcpf_D30inLcpfProtectionStateValue__Protected));
    self->Change231.IsTriggered = IsTriggered(
        MakeChange(self->D30inLcpfProtectionState.IsSignalled,
                   self->D30inLcpfProtectionState.Value == FObserveLcpf_D30inLcpfProtectionStateValue__Idle));
    self->Change237.IsTriggered = IsTriggered(
        MakeChange(self->D30inLcpfProtectionState.IsSignalled,
                   self->D30inLcpfProtectionState.Value == FObserveLcpf_D30inLcpfProtectionStateValue__Unprotected));
    self->Change232.IsTriggered = IsTriggered(
        MakeChange(self->D30inLcpfProtectionState.IsSignalled,
                   self->D30inLcpfProtectionState.Value == FObserveLcpf_D30inLcpfProtectionStateValue__Protected));
    self->Change235.IsTriggered = IsTriggered(
        MakeChange(self->D30inLcpfProtectionState.IsSignalled,
                   self->D30inLcpfProtectionState.Value == FObserveLcpf_D30inLcpfProtectionStateValue__Unprotected));
    self->Change249.IsTriggered =
        IsTriggered(MakeChange(self->D31inObstacleDetectionState.IsSignalled, self->D31inObstacleDetectionState.Value));
    self->Change566.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D31inObstacleDetectionState.IsSignalled, self->D31inObstacleDetectionState.Value)));
    self->Change248.IsTriggered =
        IsTriggered(MakeChange(self->D31inObstacleDetectionState.IsSignalled, self->D31inObstacleDetectionState.Value));
    self->Change567.IsTriggered = IsTriggered(NegateChange(
        MakeChange(self->D31inObstacleDetectionState.IsSignalled, self->D31inObstacleDetectionState.Value)));
    self->Change260.IsTriggered =
        IsTriggered(MakeChange(self->D32inLcpfFailureState.IsSignalled, self->D32inLcpfFailureState.Value));
    self->Change571.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D32inLcpfFailureState.IsSignalled, self->D32inLcpfFailureState.Value)));
    self->Change1.IsTriggered =
        IsTriggered(MakeChange(self->D32inLcpfFailureState.IsSignalled, self->D32inLcpfFailureState.Value));
    self->Change572.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D32inLcpfFailureState.IsSignalled, self->D32inLcpfFailureState.Value)));
    self->Change2.IsTriggered = IsTriggered(MakeChange(
        self->D33inMonitoringState.IsSignalled,
        self->D33inMonitoringState.Value == FObserveLcpf_D33inMonitoringStateValue__MonitoringParameterSet1));
    self->Change261.IsTriggered = IsTriggered(MakeChange(
        self->D33inMonitoringState.IsSignalled,
        self->D33inMonitoringState.Value == FObserveLcpf_D33inMonitoringStateValue__MonitoringParameterSet2));
}

static void resetOutputs(FObserveLcpf *self)
{

    self->D4outObstacleDetectionStatus.IsSignalled = false;
    self->D3outLcpfProtectionState.IsSignalled = false;
    self->D74outLcpfFailureState.IsSignalled = false;
    self->D9outChangedMonitoringState.IsSignalled = false;
}

static void resetTriggers(FObserveLcpf *self)
{

    self->D30inLcpfProtectionState.IsSignalled = false;
    self->D109inConUseObstacleDetection.IsSignalled = false;
    self->D31inObstacleDetectionState.IsSignalled = false;
    self->D32inLcpfFailureState.IsSignalled = false;
    self->D33inMonitoringState.IsSignalled = false;
}

void transition_FObserveLcpf(FObserveLcpf *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FObserveLcpf__root(self, &self->state);
    resetTriggers(self);
}

void new_FObserveLcpf(FObserveLcpf *self)
{
    make_state_FObserveLcpf__root(self, &self->state);
}
