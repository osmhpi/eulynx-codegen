
#include "FSciPReport.h"

// Value Conversion Functions

static FSciPReport_D14inObservedPointPositionValue map_MemLastReportedPointPosition_to_D14inObservedPointPosition(
    FSciPReport_MemLastReportedPointPositionValue value)
{
    switch (value)
    {
    case FSciPReport_MemLastReportedPointPositionValue__NULL__:
        return FSciPReport_D14inObservedPointPositionValue__NULL__;
    case FSciPReport_MemLastReportedPointPositionValue__UNKNOWN__:
        return FSciPReport_D14inObservedPointPositionValue__UNKNOWN__;
    case FSciPReport_MemLastReportedPointPositionValue__Left:
        return FSciPReport_D14inObservedPointPositionValue__Left;
    case FSciPReport_MemLastReportedPointPositionValue__Right:
        return FSciPReport_D14inObservedPointPositionValue__Right;
    case FSciPReport_MemLastReportedPointPositionValue__NoEndPosition:
        return FSciPReport_D14inObservedPointPositionValue__NoEndPosition;
    case FSciPReport_MemLastReportedPointPositionValue__UnintendedPosition:
        return FSciPReport_D14inObservedPointPositionValue__UnintendedPosition;
    default:
        abort();
    }
}
static FSciPReport_D17inObservedDegradedPointPositionValue
map_MemLastReportedDegradedPointPosition_to_D17inObservedDegradedPointPosition(
    FSciPReport_MemLastReportedDegradedPointPositionValue value)
{
    switch (value)
    {
    case FSciPReport_MemLastReportedDegradedPointPositionValue__NULL__:
        return FSciPReport_D17inObservedDegradedPointPositionValue__NULL__;
    case FSciPReport_MemLastReportedDegradedPointPositionValue__UNKNOWN__:
        return FSciPReport_D17inObservedDegradedPointPositionValue__UNKNOWN__;
    case FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedLeft:
        return FSciPReport_D17inObservedDegradedPointPositionValue__DegradedLeft;
    case FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedRight:
        return FSciPReport_D17inObservedDegradedPointPositionValue__DegradedRight;
    case FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedDenied:
        return FSciPReport_D17inObservedDegradedPointPositionValue__DegradedDenied;
    default:
        abort();
    }
}
static FSciPReport_MemLastReportedPointPositionValue map_D14inObservedPointPosition_to_MemLastReportedPointPosition(
    FSciPReport_D14inObservedPointPositionValue value)
{
    switch (value)
    {
    case FSciPReport_D14inObservedPointPositionValue__NULL__:
        return FSciPReport_MemLastReportedPointPositionValue__NULL__;
    case FSciPReport_D14inObservedPointPositionValue__UNKNOWN__:
        return FSciPReport_MemLastReportedPointPositionValue__UNKNOWN__;
    case FSciPReport_D14inObservedPointPositionValue__Left:
        return FSciPReport_MemLastReportedPointPositionValue__Left;
    case FSciPReport_D14inObservedPointPositionValue__Right:
        return FSciPReport_MemLastReportedPointPositionValue__Right;
    case FSciPReport_D14inObservedPointPositionValue__NoEndPosition:
        return FSciPReport_MemLastReportedPointPositionValue__NoEndPosition;
    case FSciPReport_D14inObservedPointPositionValue__UnintendedPosition:
        return FSciPReport_MemLastReportedPointPositionValue__UnintendedPosition;
    default:
        abort();
    }
}
static FSciPReport_MemLastReportedDegradedPointPositionValue
map_D17inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
    FSciPReport_D17inObservedDegradedPointPositionValue value)
{
    switch (value)
    {
    case FSciPReport_D17inObservedDegradedPointPositionValue__NULL__:
        return FSciPReport_MemLastReportedDegradedPointPositionValue__NULL__;
    case FSciPReport_D17inObservedDegradedPointPositionValue__UNKNOWN__:
        return FSciPReport_MemLastReportedDegradedPointPositionValue__UNKNOWN__;
    case FSciPReport_D17inObservedDegradedPointPositionValue__DegradedLeft:
        return FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedLeft;
    case FSciPReport_D17inObservedDegradedPointPositionValue__DegradedRight:
        return FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedRight;
    case FSciPReport_D17inObservedDegradedPointPositionValue__DegradedDenied:
        return FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedDenied;
    default:
        abort();
    }
}

// Operations
static PointPositionState__2e6f Cop1PointPosition(FSciPReport *self)
{
    if (self->D14inObservedPointPosition.Value == FSciPReport_D14inObservedPointPositionValue__Left)
    {
        return PointPositionState__2e6f__Left;
    }
    else if (self->D14inObservedPointPosition.Value == FSciPReport_D14inObservedPointPositionValue__Right)
    {
        return PointPositionState__2e6f__Right;
    }
    else if (self->D14inObservedPointPosition.Value == FSciPReport_D14inObservedPointPositionValue__NoEndPosition)
    {
        return PointPositionState__2e6f__NoEndPosition;
    }
    else if (self->D14inObservedPointPosition.Value == FSciPReport_D14inObservedPointPositionValue__UnintendedPosition)
    {
        return PointPositionState__2e6f__UnintendedPosition;
    }
    abort();
}
static PointPositionDegradedState__422e Cop2DegradedPointPosition(FSciPReport *self)
{
    if (self->D17inObservedDegradedPointPosition.Value ==
        FSciPReport_D17inObservedDegradedPointPositionValue__DegradedLeft)
    {
        return PointPositionDegradedState__422e__DegradedLeft;
    }
    else if (self->D17inObservedDegradedPointPosition.Value ==
             FSciPReport_D17inObservedDegradedPointPositionValue__DegradedRight)
    {
        return PointPositionDegradedState__422e__DegradedRight;
    }
    else if (self->D17inObservedDegradedPointPosition.Value ==
             FSciPReport_D17inObservedDegradedPointPositionValue__DegradedDenied)
    {
        return PointPositionDegradedState__422e__NotApplicable;
    }
    else
    {
        return PointPositionDegradedState__422e__NotDegraded;
    }
    abort();
}
static AbilityToMoveState__ed0f Cop3AbilityToMove(FSciPReport *self)
{
    if (self->D11inObservedAbilityToMove.Value == FSciPReport_D11inObservedAbilityToMoveValue__AbleToMove)
    {
        return AbilityToMoveState__ed0f__AbleToMove;
    }
    else if (self->D11inObservedAbilityToMove.Value == FSciPReport_D11inObservedAbilityToMoveValue__UnableToMove)
    {
        return AbilityToMoveState__ed0f__UnableToMove;
    }
    abort();
}

void make_state_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove(
    FSciPReport *self, FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__state_struct *region)
{
    LOG("[FSciPReport] Entering state MsgAbilityToMove in region "
        "root__ReportingOverallPointStates__ReportingAbilityToMove");
    region->state = FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove;
};

void make_state_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove(
    FSciPReport *self, FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__state_struct *x)
{
    memset(x, 0, sizeof(FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__state_struct));

    make_state_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove(self, x);
    return;
}

void make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition(
    FSciPReport *self, FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__state_struct *region)
{
    LOG("[FSciPReport] Entering state MsgOverallPointPosition in region "
        "root__ReportingOverallPointStates__ReportingMsgPointPosition");
    region->state = FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition;
};

void make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__Waiting(
    FSciPReport *self, FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__state_struct *region)
{
    LOG("[FSciPReport] Entering state Waiting in region root__ReportingOverallPointStates__ReportingMsgPointPosition");
    region->state = FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__Waiting;
};

void make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition(
    FSciPReport *self, FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__state_struct *x)
{
    memset(x, 0, sizeof(FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__state_struct));

    make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__Waiting(self, x);
    return;
}

void make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__MsgMovementFailed(
    FSciPReport *self, FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__state_struct *region)
{
    LOG("[FSciPReport] Entering state MsgMovementFailed in region "
        "root__ReportingOverallPointStates__ReportingMovementFailed");
    region->state = FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__MsgMovementFailed;
};

void make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed(
    FSciPReport *self, FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__state_struct *x)
{
    memset(x, 0, sizeof(FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__state_struct));

    make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__MsgMovementFailed(self, x);
    return;
}

void make_state_FSciPReport__root__ReportingOverallPointStates(FSciPReport *self,
                                                               FSciPReport__root__state_struct *region)
{
    LOG("[FSciPReport] Entering state ReportingOverallPointStates in region root");
    region->state = FSciPReport__root__ReportingOverallPointStates;
    make_state_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove(
        self, &region->ReportingOverallPointStates.ReportingAbilityToMove);
    make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition(
        self, &region->ReportingOverallPointStates.ReportingMsgPointPosition);
    make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed(
        self, &region->ReportingOverallPointStates.ReportingMovementFailed);
};

void make_state_FSciPReport__root__InterfaceConnectionNotEstablished(FSciPReport *self,
                                                                     FSciPReport__root__state_struct *region)
{
    LOG("[FSciPReport] Entering state InterfaceConnectionNotEstablished in region root");
    region->state = FSciPReport__root__InterfaceConnectionNotEstablished;
};

void make_state_FSciPReport__root(FSciPReport *self, FSciPReport__root__state_struct *x)
{
    memset(x, 0, sizeof(FSciPReport__root__state_struct));

    make_state_FSciPReport__root__InterfaceConnectionNotEstablished(self, x);
    return;
}

void transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove(
    FSciPReport *self, FSciPReport__root__state_struct *x)
{

    if (self->Change32.IsTriggered)
    {
        if ((self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established) &&
            (self->D15inConObserveAbilityToMove.Value))
        {

            self->OutMsgAbilityToMovePoint__1f1b.Value.ReportedAbilityToMoveState =
                AbilityToMoveState__ed0f__AbleToMove;
            self->OutMsgAbilityToMovePoint__1f1b.HasMessage = 1;
            make_state_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove(
                self, &x->ReportingOverallPointStates.ReportingAbilityToMove);
            return;
        }
    }
    if (self->Change34.IsTriggered)
    {
        if ((self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established) &&
            (self->D15inConObserveAbilityToMove.Value))
        {

            self->OutMsgAbilityToMovePoint__1f1b.Value.ReportedAbilityToMoveState =
                AbilityToMoveState__ed0f__UnableToMove;
            self->OutMsgAbilityToMovePoint__1f1b.HasMessage = 1;
            make_state_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove(
                self, &x->ReportingOverallPointStates.ReportingAbilityToMove);
            return;
        }
    }
}

void transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove(
    FSciPReport *self, FSciPReport__root__state_struct *x)
{
    switch (x->ReportingOverallPointStates.ReportingAbilityToMove.state)
    {
    case FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove:
        transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove(self,
                                                                                                                 x);
        break;
    }
}

void transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition(
    FSciPReport *self, FSciPReport__root__state_struct *x)
{

    if (self->Change7.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgPointPosition__27c1.Value.ReportedPointPositionState = Cop1PointPosition(self);
            self->OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition = Cop2DegradedPointPosition(self);
            self->OutMsgPointPosition__27c1.HasMessage = 1;
            self->MemLastReportedPointPosition =
                map_D14inObservedPointPosition_to_MemLastReportedPointPosition(self->D14inObservedPointPosition.Value);
            self->MemLastReportedDegradedPointPosition =
                map_D17inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
                    self->D17inObservedDegradedPointPosition.Value);
            make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition(
                self, &x->ReportingOverallPointStates.ReportingMsgPointPosition);
            return;
        }
    }
    if (self->Change11.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgPointPosition__27c1.Value.ReportedPointPositionState = Cop1PointPosition(self);
            self->OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition = Cop2DegradedPointPosition(self);
            self->OutMsgPointPosition__27c1.HasMessage = 1;
            self->MemLastReportedPointPosition =
                map_D14inObservedPointPosition_to_MemLastReportedPointPosition(self->D14inObservedPointPosition.Value);
            self->MemLastReportedDegradedPointPosition =
                map_D17inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
                    self->D17inObservedDegradedPointPosition.Value);
            make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition(
                self, &x->ReportingOverallPointStates.ReportingMsgPointPosition);
            return;
        }
    }
}

void transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__Waiting(
    FSciPReport *self, FSciPReport__root__state_struct *x)
{

    if (self->Change8.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgPointPosition__27c1.Value.ReportedPointPositionState = Cop1PointPosition(self);
            self->OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition = Cop2DegradedPointPosition(self);
            self->OutMsgPointPosition__27c1.HasMessage = 1;
            self->MemLastReportedPointPosition =
                map_D14inObservedPointPosition_to_MemLastReportedPointPosition(self->D14inObservedPointPosition.Value);
            self->MemLastReportedDegradedPointPosition =
                map_D17inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
                    self->D17inObservedDegradedPointPosition.Value);
            make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition(
                self, &x->ReportingOverallPointStates.ReportingMsgPointPosition);
            return;
        }
    }
}

void transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition(
    FSciPReport *self, FSciPReport__root__state_struct *x)
{
    switch (x->ReportingOverallPointStates.ReportingMsgPointPosition.state)
    {
    case FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition:
        transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition(
            self, x);
        break;
    case FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__Waiting:
        transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__Waiting(self, x);
        break;
    }
}

void transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__MsgMovementFailed(
    FSciPReport *self, FSciPReport__root__state_struct *x)
{

    if (self->Change87.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgMovementFailed__ff4f.HasMessage = 1;
            make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__MsgMovementFailed(
                self, &x->ReportingOverallPointStates.ReportingMovementFailed);
            return;
        }
    }
}

void transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed(
    FSciPReport *self, FSciPReport__root__state_struct *x)
{
    switch (x->ReportingOverallPointStates.ReportingMovementFailed.state)
    {
    case FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__MsgMovementFailed:
        transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed__MsgMovementFailed(self,
                                                                                                                   x);
        break;
    }
}

void transition_from_FSciPReport__root__ReportingOverallPointStates(FSciPReport *self,
                                                                    FSciPReport__root__state_struct *x)
{
    transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove(self, x);
    transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition(self, x);
    transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMovementFailed(self, x);
    if (self->Change328.IsTriggered)
    {

        make_state_FSciPReport__root__InterfaceConnectionNotEstablished(self, x);
        return;
    }
}

void transition_from_FSciPReport__root__InterfaceConnectionNotEstablished(FSciPReport *self,
                                                                          FSciPReport__root__state_struct *x)
{

    if (self->InStartStatusReport__1e4e.HasMessage)
    {

        self->OutMsgPointPosition__27c1.Value.ReportedPointPositionState = Cop1PointPosition(self);
        self->OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition = Cop2DegradedPointPosition(self);
        self->OutMsgPointPosition__27c1.HasMessage = 1;
        self->MemLastReportedPointPosition =
            map_D14inObservedPointPosition_to_MemLastReportedPointPosition(self->D14inObservedPointPosition.Value);
        self->MemLastReportedDegradedPointPosition =
            map_D17inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
                self->D17inObservedDegradedPointPosition.Value);
        if (!(self->D15inConObserveAbilityToMove.Value))
        {

            self->OutStatusReportCompleted__b457.HasMessage = 1;
            make_state_FSciPReport__root__ReportingOverallPointStates(self, x);
            return;
        }
        if (self->D15inConObserveAbilityToMove.Value)
        {

            self->OutMsgAbilityToMovePoint__1f1b.Value.ReportedAbilityToMoveState = Cop3AbilityToMove(self);
            self->OutMsgAbilityToMovePoint__1f1b.HasMessage = 1;

            self->OutStatusReportCompleted__b457.HasMessage = 1;
            make_state_FSciPReport__root__ReportingOverallPointStates(self, x);
            return;
        }
    }
}

void transition_from_FSciPReport__root(FSciPReport *self, FSciPReport__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciPReport__root__ReportingOverallPointStates:
        transition_from_FSciPReport__root__ReportingOverallPointStates(self, x);
        break;
    case FSciPReport__root__InterfaceConnectionNotEstablished:
        transition_from_FSciPReport__root__InterfaceConnectionNotEstablished(self, x);
        break;
    }
}

static void evaluateChangeEvents(FSciPReport *self)
{
    self->Change32.IsTriggered = IsTriggered(
        MakeChange(self->D11inObservedAbilityToMove.IsSignalled,
                   self->D11inObservedAbilityToMove.Value == FSciPReport_D11inObservedAbilityToMoveValue__AbleToMove));
    self->Change34.IsTriggered = IsTriggered(MakeChange(self->D11inObservedAbilityToMove.IsSignalled,
                                                        self->D11inObservedAbilityToMove.Value ==
                                                            FSciPReport_D11inObservedAbilityToMoveValue__UnableToMove));
    self->Change7.IsTriggered = IsTriggered(MakeChange(
        self->D14inObservedPointPosition.IsSignalled,
        !(self->D14inObservedPointPosition.Value ==
          map_MemLastReportedPointPosition_to_D14inObservedPointPosition(self->MemLastReportedPointPosition))));
    self->Change11.IsTriggered =
        IsTriggered(MakeChange(self->D17inObservedDegradedPointPosition.IsSignalled,
                               !(self->D17inObservedDegradedPointPosition.Value ==
                                 map_MemLastReportedDegradedPointPosition_to_D17inObservedDegradedPointPosition(
                                     self->MemLastReportedDegradedPointPosition))));
    self->Change8.IsTriggered = IsTriggered(OrChange(
        MakeChange(
            self->D14inObservedPointPosition.IsSignalled,
            !(self->D14inObservedPointPosition.Value ==
              map_MemLastReportedPointPosition_to_D14inObservedPointPosition(self->MemLastReportedPointPosition))),
        MakeChange(self->D17inObservedDegradedPointPosition.IsSignalled,
                   !(self->D17inObservedDegradedPointPosition.Value ==
                     map_MemLastReportedDegradedPointPosition_to_D17inObservedDegradedPointPosition(
                         self->MemLastReportedDegradedPointPosition)))));
    self->Change87.IsTriggered =
        IsTriggered(MakeChange(self->D13inObservedMovementFailed.IsSignalled, self->D13inObservedMovementFailed.Value));
    self->Change328.IsTriggered = IsTriggered(OrChange(
        OrChange(
            OrChange(OrChange(MakeChange(self->D50inPdiConnectionState.IsSignalled,
                                         self->D50inPdiConnectionState.Value ==
                                             FSciPReport_D50inPdiConnectionStateValue__NotReadyForPdiNoScp),
                              MakeChange(self->D50inPdiConnectionState.IsSignalled,
                                         self->D50inPdiConnectionState.Value ==
                                             FSciPReport_D50inPdiConnectionStateValue__ReadyForPdiNoScp)),
                     MakeChange(self->D50inPdiConnectionState.IsSignalled,
                                self->D50inPdiConnectionState.Value ==
                                    FSciPReport_D50inPdiConnectionStateValue__NotReadyForPdi)),
            MakeChange(self->D50inPdiConnectionState.IsSignalled,
                       self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__ReadyForPdi)),
        MakeChange(self->D50inPdiConnectionState.IsSignalled,
                   self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Suspended)));
}

static void resetOutputs(FSciPReport *self)
{
    self->OutStatusReportCompleted__b457.HasMessage = false;
    self->OutMsgPointPosition__27c1.HasMessage = false;
    self->OutMsgAbilityToMovePoint__1f1b.HasMessage = false;
    self->OutMsgMovementFailed__ff4f.HasMessage = false;
}

static void resetTriggers(FSciPReport *self)
{
    self->InStartStatusReport__1e4e.HasMessage = false;

    self->D11inObservedAbilityToMove.IsSignalled = false;
    self->D13inObservedMovementFailed.IsSignalled = false;
    self->D14inObservedPointPosition.IsSignalled = false;
    self->D15inConObserveAbilityToMove.IsSignalled = false;
    self->D17inObservedDegradedPointPosition.IsSignalled = false;
    self->D50inPdiConnectionState.IsSignalled = false;
}

void transition_FSciPReport(FSciPReport *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FSciPReport__root(self, &self->state);
    resetTriggers(self);
}

void new_FSciPReport(FSciPReport *self)
{
    make_state_FSciPReport__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemPoint/FSciPReport.c"
#endif
