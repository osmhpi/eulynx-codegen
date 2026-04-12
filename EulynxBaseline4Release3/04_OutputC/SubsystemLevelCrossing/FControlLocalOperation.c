
#include "FControlLocalOperation.h"

// Value Conversion Functions

// Operations

void make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__Waiting(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state_struct *region)
{
    LOG("[FControlLocalOperation] Entering state Waiting in region "
        "root__ControlLocalOperation__CommandHandoverToLocalOperation");
    region->state = FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__Waiting;
};

void make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state_struct *region)
{
    LOG("[FControlLocalOperation] Entering state HandoverInitiated in region "
        "root__ControlLocalOperation__CommandHandoverToLocalOperation");
    region->state =
        FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated;
};

void make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state_struct *region)
{
    LOG("[FControlLocalOperation] Entering state HandoverEstablished in region "
        "root__ControlLocalOperation__CommandHandoverToLocalOperation");
    region->state =
        FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished;
};

void make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state_struct *region)
{
    LOG("[FControlLocalOperation] Entering state NoHandover in region "
        "root__ControlLocalOperation__CommandHandoverToLocalOperation");
    region->state = FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover;
};

void make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state_struct *x)
{
    memset(x, 0,
           sizeof(FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__state_struct));

    make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__Waiting(self, x);
    return;
}

void make_state_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Allow(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__state_struct
        *region)
{
    LOG("[FControlLocalOperation] Entering state Allow in region "
        "root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator");
    region->state =
        FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Allow;
};

void make_state_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Return(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__state_struct
        *region)
{
    LOG("[FControlLocalOperation] Entering state Return in region "
        "root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator");
    region->state =
        FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Return;
};

void make_state_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Waiting(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__state_struct
        *region)
{
    LOG("[FControlLocalOperation] Entering state Waiting in region "
        "root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator");
    region->state =
        FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Waiting;
};

void make_state_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__state_struct *x)
{
    memset(
        x, 0,
        sizeof(
            FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__state_struct));

    make_state_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Waiting(
        self, x);
    return;
}

void make_state_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__Waiting(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__state_struct *region)
{
    LOG("[FControlLocalOperation] Entering state Waiting in region "
        "root__ControlLocalOperation__RequestByLocalOperator");
    region->state = FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__Waiting;
};

void make_state_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToActivate(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__state_struct *region)
{
    LOG("[FControlLocalOperation] Entering state RequestToActivate in region "
        "root__ControlLocalOperation__RequestByLocalOperator");
    region->state = FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToActivate;
};

void make_state_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToDeactivate(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__state_struct *region)
{
    LOG("[FControlLocalOperation] Entering state RequestToDeactivate in region "
        "root__ControlLocalOperation__RequestByLocalOperator");
    region->state = FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToDeactivate;
};

void make_state_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator(
    FControlLocalOperation *self,
    FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__state_struct *x)
{
    memset(x, 0, sizeof(FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__state_struct));

    make_state_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__Waiting(self, x);
    return;
}

void make_state_FControlLocalOperation__root__ControlLocalOperation(FControlLocalOperation *self,
                                                                    FControlLocalOperation__root__state_struct *region)
{
    LOG("[FControlLocalOperation] Entering state ControlLocalOperation in region root");
    region->state = FControlLocalOperation__root__ControlLocalOperation;
    make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation(
        self, &region->ControlLocalOperation.CommandHandoverToLocalOperation);
    make_state_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator(
        self, &region->ControlLocalOperation.ReceiveInputForLocalOperationByLocalOperator);
    make_state_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator(
        self, &region->ControlLocalOperation.RequestByLocalOperator);
};

void make_state_FControlLocalOperation__root(FControlLocalOperation *self,
                                             FControlLocalOperation__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlLocalOperation__root__state_struct));

    make_state_FControlLocalOperation__root__ControlLocalOperation(self, x);
    return;
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__Waiting(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{

    if (self->Change475.IsTriggered)
    {
        self->D80outHandoverToLocalOperationState.Value =
            FControlLocalOperation_D80outHandoverToLocalOperationStateValue__HandoverToLocalOperatorEstablished;
        self->D80outHandoverToLocalOperationState.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished(
            self, &x->ControlLocalOperation.CommandHandoverToLocalOperation);
        return;
    }
    if (self->Change478.IsTriggered)
    {
        self->D80outHandoverToLocalOperationState.Value =
            FControlLocalOperation_D80outHandoverToLocalOperationStateValue__HandoverToLocalOperatorInitiated;
        self->D80outHandoverToLocalOperationState.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated(
            self, &x->ControlLocalOperation.CommandHandoverToLocalOperation);
        return;
    }
    if (self->Change481.IsTriggered)
    {
        self->D80outHandoverToLocalOperationState.Value =
            FControlLocalOperation_D80outHandoverToLocalOperationStateValue__NoHandoverToLocalOperator;
        self->D80outHandoverToLocalOperationState.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover(
            self, &x->ControlLocalOperation.CommandHandoverToLocalOperation);
        return;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{

    if (self->Change477.IsTriggered)
    {
        self->D80outHandoverToLocalOperationState.Value =
            FControlLocalOperation_D80outHandoverToLocalOperationStateValue__HandoverToLocalOperatorEstablished;
        self->D80outHandoverToLocalOperationState.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished(
            self, &x->ControlLocalOperation.CommandHandoverToLocalOperation);
        return;
    }
    if (self->Change483.IsTriggered)
    {
        self->D80outHandoverToLocalOperationState.Value =
            FControlLocalOperation_D80outHandoverToLocalOperationStateValue__NoHandoverToLocalOperator;
        self->D80outHandoverToLocalOperationState.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover(
            self, &x->ControlLocalOperation.CommandHandoverToLocalOperation);
        return;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{

    if (self->Change482.IsTriggered)
    {
        self->D80outHandoverToLocalOperationState.Value =
            FControlLocalOperation_D80outHandoverToLocalOperationStateValue__NoHandoverToLocalOperator;
        self->D80outHandoverToLocalOperationState.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover(
            self, &x->ControlLocalOperation.CommandHandoverToLocalOperation);
        return;
    }
    if (self->Change480.IsTriggered)
    {
        self->D80outHandoverToLocalOperationState.Value =
            FControlLocalOperation_D80outHandoverToLocalOperationStateValue__HandoverToLocalOperatorInitiated;
        self->D80outHandoverToLocalOperationState.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated(
            self, &x->ControlLocalOperation.CommandHandoverToLocalOperation);
        return;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{

    if (self->Change479.IsTriggered)
    {
        self->D80outHandoverToLocalOperationState.Value =
            FControlLocalOperation_D80outHandoverToLocalOperationStateValue__HandoverToLocalOperatorInitiated;
        self->D80outHandoverToLocalOperationState.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated(
            self, &x->ControlLocalOperation.CommandHandoverToLocalOperation);
        return;
    }
    if (self->Change476.IsTriggered)
    {
        self->D80outHandoverToLocalOperationState.Value =
            FControlLocalOperation_D80outHandoverToLocalOperationStateValue__HandoverToLocalOperatorEstablished;
        self->D80outHandoverToLocalOperationState.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished(
            self, &x->ControlLocalOperation.CommandHandoverToLocalOperation);
        return;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    switch (x->ControlLocalOperation.CommandHandoverToLocalOperation.state)
    {
    case FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__Waiting:
        transition_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__Waiting(
            self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated:
        transition_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverInitiated(
            self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished:
        transition_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__HandoverEstablished(
            self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover:
        transition_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation__NoHandover(
            self, x);
        break;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Allow(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{

    if (self->Change468.IsTriggered)
    {
        self->D81outLocalOperationHandover.Value =
            FControlLocalOperation_D81outLocalOperationHandoverValue__ReturnHandoverFromLocalOperator;
        self->D81outLocalOperationHandover.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Return(
            self, &x->ControlLocalOperation.ReceiveInputForLocalOperationByLocalOperator);
        return;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Return(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{

    if (self->Change465.IsTriggered)
    {
        self->D81outLocalOperationHandover.Value =
            FControlLocalOperation_D81outLocalOperationHandoverValue__AllowHandoverToLocalOperator;
        self->D81outLocalOperationHandover.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Allow(
            self, &x->ControlLocalOperation.ReceiveInputForLocalOperationByLocalOperator);
        return;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Waiting(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{

    if (self->Change463.IsTriggered)
    {
        self->D81outLocalOperationHandover.Value =
            FControlLocalOperation_D81outLocalOperationHandoverValue__AllowHandoverToLocalOperator;
        self->D81outLocalOperationHandover.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Allow(
            self, &x->ControlLocalOperation.ReceiveInputForLocalOperationByLocalOperator);
        return;
    }
    if (self->Change466.IsTriggered)
    {
        self->D81outLocalOperationHandover.Value =
            FControlLocalOperation_D81outLocalOperationHandoverValue__ReturnHandoverFromLocalOperator;
        self->D81outLocalOperationHandover.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Return(
            self, &x->ControlLocalOperation.ReceiveInputForLocalOperationByLocalOperator);
        return;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    switch (x->ControlLocalOperation.ReceiveInputForLocalOperationByLocalOperator.state)
    {
    case FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Allow:
        transition_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Allow(
            self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Return:
        transition_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Return(
            self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Waiting:
        transition_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator__Waiting(
            self, x);
        break;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__Waiting(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{

    if (self->Change471.IsTriggered)
    {
        self->D82outLocalOperationHandover.Value =
            FControlLocalOperation_D82outLocalOperationHandoverValue__RequestToActivateTheLevelCrossing;
        self->D82outLocalOperationHandover.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToActivate(
            self, &x->ControlLocalOperation.RequestByLocalOperator);
        return;
    }
    if (self->Change473.IsTriggered)
    {
        self->D82outLocalOperationHandover.Value =
            FControlLocalOperation_D82outLocalOperationHandoverValue__RequestToDeactivateTheLevelCrossing;
        self->D82outLocalOperationHandover.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToDeactivate(
            self, &x->ControlLocalOperation.RequestByLocalOperator);
        return;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToActivate(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{

    if (self->Change474.IsTriggered)
    {
        self->D82outLocalOperationHandover.Value =
            FControlLocalOperation_D82outLocalOperationHandoverValue__RequestToDeactivateTheLevelCrossing;
        self->D82outLocalOperationHandover.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToDeactivate(
            self, &x->ControlLocalOperation.RequestByLocalOperator);
        return;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToDeactivate(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{

    if (self->Change472.IsTriggered)
    {
        self->D82outLocalOperationHandover.Value =
            FControlLocalOperation_D82outLocalOperationHandoverValue__RequestToActivateTheLevelCrossing;
        self->D82outLocalOperationHandover.IsSignalled = true;
        make_state_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToActivate(
            self, &x->ControlLocalOperation.RequestByLocalOperator);
        return;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator(
    FControlLocalOperation *self, FControlLocalOperation__root__state_struct *x)
{
    switch (x->ControlLocalOperation.RequestByLocalOperator.state)
    {
    case FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__Waiting:
        transition_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__Waiting(self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToActivate:
        transition_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToActivate(
            self, x);
        break;
    case FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToDeactivate:
        transition_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator__RequestToDeactivate(
            self, x);
        break;
    }
}

void transition_from_FControlLocalOperation__root__ControlLocalOperation(FControlLocalOperation *self,
                                                                         FControlLocalOperation__root__state_struct *x)
{
    transition_from_FControlLocalOperation__root__ControlLocalOperation__CommandHandoverToLocalOperation(self, x);
    transition_from_FControlLocalOperation__root__ControlLocalOperation__ReceiveInputForLocalOperationByLocalOperator(
        self, x);
    transition_from_FControlLocalOperation__root__ControlLocalOperation__RequestByLocalOperator(self, x);
}

void transition_from_FControlLocalOperation__root(FControlLocalOperation *self,
                                                  FControlLocalOperation__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlLocalOperation__root__ControlLocalOperation:
        transition_from_FControlLocalOperation__root__ControlLocalOperation(self, x);
        break;
    }
}

static void evaluateChangeEvents(FControlLocalOperation *self)
{
    self->Change475.IsTriggered =
        IsTriggered(MakeChange(self->D8inHandoverToLocalOperatorState.IsSignalled,
                               self->D8inHandoverToLocalOperatorState.Value ==
                                   FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__Established));
    self->Change478.IsTriggered =
        IsTriggered(MakeChange(self->D8inHandoverToLocalOperatorState.IsSignalled,
                               self->D8inHandoverToLocalOperatorState.Value ==
                                   FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__Initiated));
    self->Change481.IsTriggered =
        IsTriggered(MakeChange(self->D8inHandoverToLocalOperatorState.IsSignalled,
                               self->D8inHandoverToLocalOperatorState.Value ==
                                   FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__NoHandover));
    self->Change477.IsTriggered =
        IsTriggered(MakeChange(self->D8inHandoverToLocalOperatorState.IsSignalled,
                               self->D8inHandoverToLocalOperatorState.Value ==
                                   FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__Established));
    self->Change483.IsTriggered =
        IsTriggered(MakeChange(self->D8inHandoverToLocalOperatorState.IsSignalled,
                               self->D8inHandoverToLocalOperatorState.Value ==
                                   FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__NoHandover));
    self->Change482.IsTriggered =
        IsTriggered(MakeChange(self->D8inHandoverToLocalOperatorState.IsSignalled,
                               self->D8inHandoverToLocalOperatorState.Value ==
                                   FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__NoHandover));
    self->Change480.IsTriggered =
        IsTriggered(MakeChange(self->D8inHandoverToLocalOperatorState.IsSignalled,
                               self->D8inHandoverToLocalOperatorState.Value ==
                                   FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__Initiated));
    self->Change479.IsTriggered =
        IsTriggered(MakeChange(self->D8inHandoverToLocalOperatorState.IsSignalled,
                               self->D8inHandoverToLocalOperatorState.Value ==
                                   FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__Initiated));
    self->Change476.IsTriggered =
        IsTriggered(MakeChange(self->D8inHandoverToLocalOperatorState.IsSignalled,
                               self->D8inHandoverToLocalOperatorState.Value ==
                                   FControlLocalOperation_D8inHandoverToLocalOperatorStateValue__Established));
    self->Change468.IsTriggered = IsTriggered(
        MakeChange(self->D81inLocalOperationHandover.IsSignalled,
                   self->D81inLocalOperationHandover.Value ==
                       FControlLocalOperation_D81inLocalOperationHandoverValue__ReturnHandoverFromLocalOperator));
    self->Change465.IsTriggered = IsTriggered(
        MakeChange(self->D81inLocalOperationHandover.IsSignalled,
                   self->D81inLocalOperationHandover.Value ==
                       FControlLocalOperation_D81inLocalOperationHandoverValue__AllowHandoverToLocalOperator));
    self->Change463.IsTriggered = IsTriggered(
        MakeChange(self->D81inLocalOperationHandover.IsSignalled,
                   self->D81inLocalOperationHandover.Value ==
                       FControlLocalOperation_D81inLocalOperationHandoverValue__AllowHandoverToLocalOperator));
    self->Change466.IsTriggered = IsTriggered(
        MakeChange(self->D81inLocalOperationHandover.IsSignalled,
                   self->D81inLocalOperationHandover.Value ==
                       FControlLocalOperation_D81inLocalOperationHandoverValue__ReturnHandoverFromLocalOperator));
    self->Change471.IsTriggered = IsTriggered(
        MakeChange(self->D82inRequestByLocalOperator.IsSignalled,
                   self->D82inRequestByLocalOperator.Value ==
                       FControlLocalOperation_D82inRequestByLocalOperatorValue__RequestToActivateTheLevelCrossing));
    self->Change473.IsTriggered = IsTriggered(
        MakeChange(self->D82inRequestByLocalOperator.IsSignalled,
                   self->D82inRequestByLocalOperator.Value ==
                       FControlLocalOperation_D82inRequestByLocalOperatorValue__RequestToDeactivateTheLevelCrossing));
    self->Change474.IsTriggered = IsTriggered(
        MakeChange(self->D82inRequestByLocalOperator.IsSignalled,
                   self->D82inRequestByLocalOperator.Value ==
                       FControlLocalOperation_D82inRequestByLocalOperatorValue__RequestToDeactivateTheLevelCrossing));
    self->Change472.IsTriggered = IsTriggered(
        MakeChange(self->D82inRequestByLocalOperator.IsSignalled,
                   self->D82inRequestByLocalOperator.Value ==
                       FControlLocalOperation_D82inRequestByLocalOperatorValue__RequestToActivateTheLevelCrossing));
}

static void resetOutputs(FControlLocalOperation *self)
{

    self->D80outHandoverToLocalOperationState.IsSignalled = false;
    self->D81outLocalOperationHandover.IsSignalled = false;
    self->D82outLocalOperationHandover.IsSignalled = false;
}

static void resetTriggers(FControlLocalOperation *self)
{

    self->D8inHandoverToLocalOperatorState.IsSignalled = false;
    self->D81inLocalOperationHandover.IsSignalled = false;
    self->D82inRequestByLocalOperator.IsSignalled = false;
    self->D83inConUseLocalOperation.IsSignalled = false;
}

void transition_FControlLocalOperation(FControlLocalOperation *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FControlLocalOperation__root(self, &self->state);
    resetTriggers(self);
}

void new_FControlLocalOperation(FControlLocalOperation *self)
{
    make_state_FControlLocalOperation__root(self, &self->state);
}
