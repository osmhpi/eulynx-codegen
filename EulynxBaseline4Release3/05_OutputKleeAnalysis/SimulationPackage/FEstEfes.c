
#include "../../04_OutputC/SimulationPackage/FEstEfes.h"

void count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate(
    int *ctr, FEstEfes *self, FEstEfes__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InDataUpdateFinished__0937.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdi(
    int *ctr, FEstEfes *self, FEstEfes__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InPdiConnectionClosed__d803.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InPdiConnectionEstablished__4cbf.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InPdiReleasedForMaintenance__3f7c.HasMessage)
    {
        if (!(self->D20inConMdmUsed.Value))
        {
            (*ctr)++;
        }
    }
    if (self->InPdiReleasedForMaintenance__3f7c.HasMessage)
    {
        if (self->D20inConMdmUsed.Value)
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance(
    int *ctr, FEstEfes *self, FEstEfes__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMdmCommandedMaintenance__a992.HasMessage)
    {
        if (self->D20inConMdmUsed.Value)
        {
            (*ctr)++;
        }
    }
    if (self->InPdiConnectionStarted__f9c3.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout(
    int *ctr, FEstEfes *self, FEstEfes__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time13.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root(
    int *ctr, FEstEfes *self, FEstEfes__root__state_struct *x)
{
    switch (x->OperatingVoltageSupplied.root.Initialising.root.state)
    {
    case FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate:
        count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate(
            ctr, self, x);
        break;
    case FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdi:
        count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdi(
            ctr, self, x);
        break;
    case FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance:
        count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance(
            ctr, self, x);
        break;
    case FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout:
        count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Booting(int *ctr, FEstEfes *self,
                                                                                    FEstEfes__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1191.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1226.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1266.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Operational(int *ctr, FEstEfes *self,
                                                                                        FEstEfes__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InPdiConnectionClosed__d803.HasMessage)
    {

        x->OperatingVoltageSupplied.root.state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising;
        make_state_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance(
            self, &x->OperatingVoltageSupplied.root.Initialising.root);
        return;
    }
    if (self->InPdiReleasedForMaintenance__3f7c.HasMessage)
    {
        if (self->D20inConMdmUsed.Value)
        {

            x->OperatingVoltageSupplied.root.state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising;
            (*ctr)++;
        }
    }
    if (self->InPdiReleasedForMaintenance__3f7c.HasMessage)
    {
        if (!(self->D20inConMdmUsed.Value))
        {

            x->OperatingVoltageSupplied.root.state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising;
            (*ctr)++;
        }
    }
    if (self->Change1143.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1224.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode(
    int *ctr, FEstEfes *self, FEstEfes__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMdmTriggeredReset__00d0.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change1144.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising(
    int *ctr, FEstEfes *self, FEstEfes__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->InRebootRequired__bc8e.HasMessage)
    {
        if (self->D20inConMdmUsed.Value)
        {
            (*ctr)++;
        }
    }
    if (self->Change1145.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1225.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root(int *ctr, FEstEfes *self,
                                                                           FEstEfes__root__state_struct *x)
{
    switch (x->OperatingVoltageSupplied.root.state)
    {
    case FEstEfes__root__OperatingVoltageSupplied__root__Booting:
        count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Booting(ctr, self, x);
        break;
    case FEstEfes__root__OperatingVoltageSupplied__root__Operational:
        count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Operational(ctr, self, x);
        break;
    case FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode:
        count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__FallbackMode(ctr, self, x);
        break;
    case FEstEfes__root__OperatingVoltageSupplied__root__Initialising:
        count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root__Initialising(ctr, self, x);
        break;
    }
}

void count_transitions_from_FEstEfes__root__NoOperatingVoltage(int *ctr, FEstEfes *self,
                                                               FEstEfes__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change869.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FEstEfes__root__OperatingVoltageSupplied(int *ctr, FEstEfes *self,
                                                                     FEstEfes__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FEstEfes__root__OperatingVoltageSupplied__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Change1060.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FEstEfes__root(int *ctr, FEstEfes *self, FEstEfes__root__state_struct *x)
{
    switch (x->state)
    {
    case FEstEfes__root__NoOperatingVoltage:
        count_transitions_from_FEstEfes__root__NoOperatingVoltage(ctr, self, x);
        break;
    case FEstEfes__root__OperatingVoltageSupplied:
        count_transitions_from_FEstEfes__root__OperatingVoltageSupplied(ctr, self, x);
        break;
    }
}

int count_transitions_FEstEfes(FEstEfes *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FEstEfes__root(&ctr, self, &self->state);
    return ctr;
}