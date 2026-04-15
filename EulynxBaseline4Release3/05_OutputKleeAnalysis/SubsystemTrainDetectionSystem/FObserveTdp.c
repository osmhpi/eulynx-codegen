
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FObserveTdp.h"

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1195.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1229.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1238.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time38.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change1197.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1232.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time39.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change1198.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1230.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__OperationallyDisturbed(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1196.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1231.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time41.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change1194.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1228.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    switch (x->NotFailed.root.Operational.root.TdpWithDirection.root.MonitoringTdpWithDirection.root.state)
    {
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__NotPassed(
            ctr, self, x);
        break;
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedAgainstReferenceDirection(
            ctr, self, x);
        break;
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__PassedInReferenceDirection(
            ctr, self, x);
        break;
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__OperationallyDisturbed:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__OperationallyDisturbed(
            ctr, self, x);
        break;
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__WaitingDelayOfNotificationOfUndefinedPattern:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change425.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__TechnicallyDisturbed(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change426.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    switch (x->NotFailed.root.Operational.root.TdpWithDirection.root.state)
    {
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__MonitoringTdpWithDirection(
            ctr, self, x);
        break;
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__TechnicallyDisturbed:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root__TechnicallyDisturbed(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__NotPassed(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1234.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1239.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time37.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change1236.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__OperationallyDisturbed(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1233.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time42.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change1235.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    switch (x->NotFailed.root.Operational.root.TdpWithoutDirection.root.MonitoringTdpWithoutDirection.root.state)
    {
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__NotPassed:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__NotPassed(
            ctr, self, x);
        break;
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__Passed(
            ctr, self, x);
        break;
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__OperationallyDisturbed:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__OperationallyDisturbed(
            ctr, self, x);
        break;
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__WaitingDelayOfNotificationOfUndefinedPattern:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root__WaitingDelayOfNotificationOfUndefinedPattern(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection__root(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change424.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__TechnicallyDisturbed(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change427.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    switch (x->NotFailed.root.Operational.root.TdpWithoutDirection.root.state)
    {
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__MonitoringTdpWithoutDirection(
            ctr, self, x);
        break;
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__TechnicallyDisturbed:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root__TechnicallyDisturbed(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection__root(&tmp, self,
                                                                                                            x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root(int *ctr, FObserveTdp *self,
                                                                                  FObserveTdp__root__state_struct *x)
{
    switch (x->NotFailed.root.Operational.root.state)
    {
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithDirection(ctr, self, x);
        break;
    case FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root__TdpWithoutDirection(ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__WaitingForFinishedBooting(
    int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change401.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root__Operational(int *ctr, FObserveTdp *self,
                                                                            FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTdp__root__NotFailed__root__Operational__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change390.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__NotFailed__root(int *ctr, FObserveTdp *self,
                                                               FObserveTdp__root__state_struct *x)
{
    switch (x->NotFailed.root.state)
    {
    case FObserveTdp__root__NotFailed__root__WaitingForFinishedBooting:
        count_transitions_from_FObserveTdp__root__NotFailed__root__WaitingForFinishedBooting(ctr, self, x);
        break;
    case FObserveTdp__root__NotFailed__root__Operational:
        count_transitions_from_FObserveTdp__root__NotFailed__root__Operational(ctr, self, x);
        break;
    }
}

void count_transitions_from_FObserveTdp__root__NotFailed(int *ctr, FObserveTdp *self,
                                                         FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FObserveTdp__root__NotFailed__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change398.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root__FallbackMode(int *ctr, FObserveTdp *self,
                                                            FObserveTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change385.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FObserveTdp__root(int *ctr, FObserveTdp *self, FObserveTdp__root__state_struct *x)
{
    switch (x->state)
    {
    case FObserveTdp__root__NotFailed:
        count_transitions_from_FObserveTdp__root__NotFailed(ctr, self, x);
        break;
    case FObserveTdp__root__FallbackMode:
        count_transitions_from_FObserveTdp__root__FallbackMode(ctr, self, x);
        break;
    }
}

int count_transitions_FObserveTdp(FObserveTdp *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FObserveTdp__root(&ctr, self, &self->state);
    return ctr;
}