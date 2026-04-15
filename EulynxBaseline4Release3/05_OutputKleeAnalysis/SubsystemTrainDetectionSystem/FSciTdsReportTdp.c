
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FSciTdsReportTdp.h"

void count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__InRefenceDirection(
    int *ctr, FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change412.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__AgainstRefenceDirection(
    int *ctr, FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change413.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__WithoutDirection(
    int *ctr, FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root(
    int *ctr, FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x)
{
    switch (x->ReportingTdpStatus.root.Passed.root.state)
    {
    case FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__InRefenceDirection:
        count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__InRefenceDirection(
            ctr, self, x);
        break;
    case FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__AgainstRefenceDirection:
        count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__AgainstRefenceDirection(
            ctr, self, x);
        break;
    case FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__WithoutDirection:
        count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root__WithoutDirection(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Waiting(
    int *ctr, FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InStartStatusReport__1e4e.HasMessage)
    {

        if (self->D53inReportedTdpStatus.Value == FSciTdsReportTdp_D53inReportedTdpStatusValue__NotPassed)
        {
            (*ctr)++;
        }
        if (self->D53inReportedTdpStatus.Value == FSciTdsReportTdp_D53inReportedTdpStatusValue__Passed)
        {
            (*ctr)++;
        }
        else
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed(
    int *ctr, FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change408.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change410.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed(
    int *ctr, FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change406.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change409.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed(
    int *ctr, FSciTdsReportTdp *self, FSciTdsReportTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change405.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change407.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root(int *ctr, FSciTdsReportTdp *self,
                                                                             FSciTdsReportTdp__root__state_struct *x)
{
    switch (x->ReportingTdpStatus.root.state)
    {
    case FSciTdsReportTdp__root__ReportingTdpStatus__root__Waiting:
        count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Waiting(ctr, self, x);
        break;
    case FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed:
        count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__NotPassed(ctr, self, x);
        break;
    case FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed:
        count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Passed(ctr, self, x);
        break;
    case FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed:
        count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root__Disturbed(ctr, self, x);
        break;
    }
}

void count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus(int *ctr, FSciTdsReportTdp *self,
                                                                       FSciTdsReportTdp__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change314.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FSciTdsReportTdp__root(int *ctr, FSciTdsReportTdp *self,
                                                   FSciTdsReportTdp__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciTdsReportTdp__root__ReportingTdpStatus:
        count_transitions_from_FSciTdsReportTdp__root__ReportingTdpStatus(ctr, self, x);
        break;
    }
}

int count_transitions_FSciTdsReportTdp(FSciTdsReportTdp *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FSciTdsReportTdp__root(&ctr, self, &self->state);
    return ctr;
}