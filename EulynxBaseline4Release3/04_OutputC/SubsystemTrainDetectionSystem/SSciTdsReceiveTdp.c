
#include "SSciTdsReceiveTdp.h"

// Value Conversion Functions

// Operations

void make_state_SSciTdsReceiveTdp__root__ReceivingTdpReports(SSciTdsReceiveTdp *self,
                                                             SSciTdsReceiveTdp__root__state_struct *region)
{
    LOG("[SSciTdsReceiveTdp] Entering state ReceivingTdpReports in region root");
    region->state = SSciTdsReceiveTdp__root__ReceivingTdpReports;
};

void make_state_SSciTdsReceiveTdp__root(SSciTdsReceiveTdp *self, SSciTdsReceiveTdp__root__state_struct *x)
{
    memset(x, 0, sizeof(SSciTdsReceiveTdp__root__state_struct));

    make_state_SSciTdsReceiveTdp__root__ReceivingTdpReports(self, x);
    return;
}

void transition_from_SSciTdsReceiveTdp__root__ReceivingTdpReports(SSciTdsReceiveTdp *self,
                                                                  SSciTdsReceiveTdp__root__state_struct *x)
{

    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {
        if ((self->InMsgTdpStatus__b6d9.Value.ReportedStateOfPassing == StateOfPassing__616f__Passed) &&
            (self->InMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing ==
             DirectionOfPassing__a7c9__ReferenceDirection))
        {
            self->D64outTdpStatus.Value = SSciTdsReceiveTdp_D64outTdpStatusValue__Passed;
            self->D64outTdpStatus.IsSignalled = true;
            self->D64outTdpDirection.Value = SSciTdsReceiveTdp_D64outTdpDirectionValue__ReferenceDirection;
            self->D64outTdpDirection.IsSignalled = true;
            self->T64outTdpStatus.Trigger = true;
            make_state_SSciTdsReceiveTdp__root__ReceivingTdpReports(self, x);
            return;
        }
    }
    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {
        if ((self->InMsgTdpStatus__b6d9.Value.ReportedStateOfPassing == StateOfPassing__616f__Passed) &&
            (self->InMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing ==
             DirectionOfPassing__a7c9__AgainstRefernceDirection))
        {
            self->D64outTdpStatus.Value = SSciTdsReceiveTdp_D64outTdpStatusValue__Passed;
            self->D64outTdpStatus.IsSignalled = true;
            self->D64outTdpDirection.Value = SSciTdsReceiveTdp_D64outTdpDirectionValue__AgainstReferenceDirection;
            self->D64outTdpDirection.IsSignalled = true;
            self->T64outTdpStatus.Trigger = true;
            make_state_SSciTdsReceiveTdp__root__ReceivingTdpReports(self, x);
            return;
        }
    }
    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {
        if ((self->InMsgTdpStatus__b6d9.Value.ReportedStateOfPassing == StateOfPassing__616f__Passed) &&
            (self->InMsgTdpStatus__b6d9.Value.ReportedDirectionOfPassing ==
             DirectionOfPassing__a7c9__WithoutIndicatedDirection))
        {
            self->D64outTdpStatus.Value = SSciTdsReceiveTdp_D64outTdpStatusValue__Passed;
            self->D64outTdpStatus.IsSignalled = true;
            self->D64outTdpDirection.Value = SSciTdsReceiveTdp_D64outTdpDirectionValue__WithoutIndicatedDirection;
            self->D64outTdpDirection.IsSignalled = true;
            self->T64outTdpStatus.Trigger = true;
            make_state_SSciTdsReceiveTdp__root__ReceivingTdpReports(self, x);
            return;
        }
    }
    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {
        if (self->InMsgTdpStatus__b6d9.Value.ReportedStateOfPassing == StateOfPassing__616f__Disturbed)
        {
            self->D64outTdpStatus.Value = SSciTdsReceiveTdp_D64outTdpStatusValue__Disturbed;
            self->D64outTdpStatus.IsSignalled = true;
            self->D64outTdpDirection.Value = SSciTdsReceiveTdp_D64outTdpDirectionValue__WithoutIndicatedDirection;
            self->D64outTdpDirection.IsSignalled = true;
            self->T64outTdpStatus.Trigger = true;
            make_state_SSciTdsReceiveTdp__root__ReceivingTdpReports(self, x);
            return;
        }
    }
    if (self->InMsgTdpStatus__b6d9.HasMessage)
    {
        if (self->InMsgTdpStatus__b6d9.Value.ReportedStateOfPassing == StateOfPassing__616f__NotPassed)
        {
            self->D64outTdpStatus.Value = SSciTdsReceiveTdp_D64outTdpStatusValue__NotPassed;
            self->D64outTdpStatus.IsSignalled = true;
            self->D64outTdpDirection.Value = SSciTdsReceiveTdp_D64outTdpDirectionValue__WithoutIndicatedDirection;
            self->D64outTdpDirection.IsSignalled = true;
            self->T64outTdpStatus.Trigger = true;
            make_state_SSciTdsReceiveTdp__root__ReceivingTdpReports(self, x);
            return;
        }
    }
}

void transition_from_SSciTdsReceiveTdp__root(SSciTdsReceiveTdp *self, SSciTdsReceiveTdp__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciTdsReceiveTdp__root__ReceivingTdpReports:
        transition_from_SSciTdsReceiveTdp__root__ReceivingTdpReports(self, x);
        break;
    }
}

static void evaluateChangeEvents(SSciTdsReceiveTdp *self)
{
}

static void resetOutputs(SSciTdsReceiveTdp *self)
{

    self->T64outTdpStatus.Trigger = false;

    self->D64outTdpStatus.IsSignalled = false;
    self->D64outTdpDirection.IsSignalled = false;
}

static void resetTriggers(SSciTdsReceiveTdp *self)
{
    self->InMsgTdpStatus__b6d9.HasMessage = false;
}

void transition_SSciTdsReceiveTdp(SSciTdsReceiveTdp *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_SSciTdsReceiveTdp__root(self, &self->state);
    resetTriggers(self);
}

void new_SSciTdsReceiveTdp(SSciTdsReceiveTdp *self)
{
    make_state_SSciTdsReceiveTdp__root(self, &self->state);
}
