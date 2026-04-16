
#include "../../04_OutputC/SubsystemTrainDetectionSystem/SSciTdsReceiveTrackCircuit.h"

void count_transitions_from_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(
    int *ctr, SSciTdsReceiveTrackCircuit *self, SSciTdsReceiveTrackCircuit__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Vacant) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Nok))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Occupied) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Ok))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Occupied) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Nok))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Disturbed) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Ok))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Disturbed) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Nok))
        {
            (*ctr)++;
        }
    }
    if (self->InMsgTvpsOccupancyStatus__b4e1.HasMessage)
    {
        if ((self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedOccupancyStatus == OccupancyStatus__65fa__Vacant) &&
            (self->InMsgTvpsOccupancyStatus__b4e1.Value.ReportedpomStatus == PomStatus__d74a__Ok))
        {
            (*ctr)++;
        }
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_SSciTdsReceiveTrackCircuit__root(int *ctr, SSciTdsReceiveTrackCircuit *self,
                                                             SSciTdsReceiveTrackCircuit__root__state_struct *x)
{
    switch (x->state)
    {
    case SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus:
        count_transitions_from_SSciTdsReceiveTrackCircuit__root__RepoprtingOccupancyStatus(ctr, self, x);
        break;
    }
}

int count_transitions_SSciTdsReceiveTrackCircuit(SSciTdsReceiveTrackCircuit *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_SSciTdsReceiveTrackCircuit__root(&ctr, self, &self->state);
    return ctr;
}