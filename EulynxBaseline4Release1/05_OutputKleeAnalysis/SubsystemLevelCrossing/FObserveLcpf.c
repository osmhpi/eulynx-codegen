
#include "../../04_OutputC/SubsystemLevelCrossing/FObserveLcpf.h"

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change220.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change228.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Protected(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change216.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change231.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Idle(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change230.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change232.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    switch (x->ObserveLcpf.ObserveLcpfProtectionState.state)
    {
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Unprotected(ctr, self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Protected:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Protected(ctr, self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Idle:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState__Idle(ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__NoObstacleInConflictArea(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change226.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__ObstacleInConflictArea(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change225.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__Waiting(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change224.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change227.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    switch (x->ObserveLcpf.ObserveLcpfObstacleDetectionState.state)
    {
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__NoObstacleInConflictArea:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__NoObstacleInConflictArea(
            ctr, self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__ObstacleInConflictArea:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__ObstacleInConflictArea(
            ctr, self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__Waiting:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState__Waiting(ctr, self,
                                                                                                           x);
        break;
    }
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__NoFailureDetected(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change214.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__FailureDetected(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change223.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__Waiting(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change222.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    switch (x->ObserveLcpf.ObserveLcpfFailureState.state)
    {
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__NoFailureDetected:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__NoFailureDetected(ctr, self,
                                                                                                           x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__FailureDetected:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__FailureDetected(ctr, self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__Waiting:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState__Waiting(ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet2(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change213.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet1(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change221.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus(
    int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    switch (x->ObserveLcpf.ObserveMonitoringStatus.state)
    {
    case FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet2:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet2(
            ctr, self, x);
        break;
    case FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet1:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus__MonitoringParameterSet1(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveLcpf__root__ObserveLcpf(int *ctr, FObserveLcpf *self,
                                                            FObserveLcpf__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfProtectionState(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfObstacleDetectionState(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveLcpfFailureState(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FObserveLcpf__root__ObserveLcpf__ObserveMonitoringStatus(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveLcpf__root(int *ctr, FObserveLcpf *self, FObserveLcpf__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveLcpf__root__ObserveLcpf:
        count_transitions_from_FObserveLcpf__root__ObserveLcpf(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveLcpf(FObserveLcpf *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveLcpf__root(&ctr, self, &self->state);
    return ctr;
}