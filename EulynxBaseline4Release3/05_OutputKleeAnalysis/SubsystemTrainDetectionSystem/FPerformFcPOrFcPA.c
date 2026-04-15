
#include "../../04_OutputC/SubsystemTrainDetectionSystem/FPerformFcPOrFcPA.h"

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__WaiitingForTMin(
    int *ctr, FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Time26.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (self->Change1157.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__TMimExpired(
    int *ctr, FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin(
    int *ctr, FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    switch (x->PerformFcPOrFcPA.root.SweepingTrainDetected.MonitorTMin.state)
    {
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__WaiitingForTMin:
        count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__WaiitingForTMin(
            ctr, self, x);
        break;
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__TMimExpired:
        count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin__TMimExpired(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Incoming(
    int *ctr, FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1158.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Outgoing(
    int *ctr, FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->Change1148.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1152.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction(
    int *ctr, FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    switch (x->PerformFcPOrFcPA.root.SweepingTrainDetected.MonitorLastCountingAction.state)
    {
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Incoming:
        count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Incoming(
            ctr, self, x);
        break;
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Outgoing:
        count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction__Outgoing(
            ctr, self, x);
        break;
    }
}

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForSweepingTrain(
    int *ctr, FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InExecuteVisualSweepingConfirmation__251f.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change1153.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1156.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected(
    int *ctr, FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorTMin(&tmp,
                                                                                                               self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    tmp = 0;
    count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected__MonitorLastCountingAction(
        &tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->Time25.IsTimeoutExpired)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForAcknowledgement(
    int *ctr, FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InConfirmAcknowledgement__3cca.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change1154.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SuccessfulSweeping(
    int *ctr, FPerformFcPOrFcPA *self, FPerformFcPOrFcPA__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (true)
    {
        (*ctr)++;
    }
    if (true)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root(int *ctr, FPerformFcPOrFcPA *self,
                                                                            FPerformFcPOrFcPA__root__state_struct *x)
{
    switch (x->PerformFcPOrFcPA.root.state)
    {
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForSweepingTrain:
        count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForSweepingTrain(ctr, self, x);
        break;
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected:
        count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SweepingTrainDetected(ctr, self, x);
        break;
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForAcknowledgement:
        count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__WaitingForAcknowledgement(ctr, self, x);
        break;
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SuccessfulSweeping:
        count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root__SuccessfulSweeping(ctr, self, x);
        break;
    }
}

void count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA(int *ctr, FPerformFcPOrFcPA *self,
                                                                      FPerformFcPOrFcPA__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;
    tmp = 0;
    count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA__root(&tmp, self, x);
    if (tmp > maxSubregionTransitions)
        maxSubregionTransitions = tmp;
    if (self->InExecuteCancel__045b.HasMessage)
    {
        (*ctr)++;
    }
    if (self->Change231.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1113.IsTriggered)
    {
        (*ctr)++;
    }
    if (self->Change1267.IsTriggered)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FPerformFcPOrFcPA__root__Waiting(int *ctr, FPerformFcPOrFcPA *self,
                                                             FPerformFcPOrFcPA__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (self->InExecuteFcP__c2bd.HasMessage)
    {
        (*ctr)++;
    }
    if (self->InExecuteFcPA__f496.HasMessage)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FPerformFcPOrFcPA__root__Failed(int *ctr, FPerformFcPOrFcPA *self,
                                                            FPerformFcPOrFcPA__root__state_struct *x)
{
    int maxSubregionTransitions = 0;
    int tmp;

    if (true)
    {
        (*ctr)++;
    }
    if (*ctr < maxSubregionTransitions)
        *ctr = maxSubregionTransitions;
}

void count_transitions_from_FPerformFcPOrFcPA__root(int *ctr, FPerformFcPOrFcPA *self,
                                                    FPerformFcPOrFcPA__root__state_struct *x)
{
    switch (x->state)
    {
    case FPerformFcPOrFcPA__root__PerformFcPOrFcPA:
        count_transitions_from_FPerformFcPOrFcPA__root__PerformFcPOrFcPA(ctr, self, x);
        break;
    case FPerformFcPOrFcPA__root__Waiting:
        count_transitions_from_FPerformFcPOrFcPA__root__Waiting(ctr, self, x);
        break;
    case FPerformFcPOrFcPA__root__Failed:
        count_transitions_from_FPerformFcPOrFcPA__root__Failed(ctr, self, x);
        break;
    }
}

int count_transitions_FPerformFcPOrFcPA(FPerformFcPOrFcPA *self)
{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_FPerformFcPOrFcPA__root(&ctr, self, &self->state);
    return ctr;
}