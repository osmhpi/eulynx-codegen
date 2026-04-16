
#include "FSciPReport.h"

// Value Conversion Functions

static FSciPReport_D5inObservedPointPositionValue map_MemLastReportedPointPosition_to_D5inObservedPointPosition(
    FSciPReport_MemLastReportedPointPositionValue value)
{
    switch (value)
    {
    case FSciPReport_MemLastReportedPointPositionValue__NULL__:
        return FSciPReport_D5inObservedPointPositionValue__NULL__;
    case FSciPReport_MemLastReportedPointPositionValue__UNKNOWN__:
        return FSciPReport_D5inObservedPointPositionValue__UNKNOWN__;
    case FSciPReport_MemLastReportedPointPositionValue__Left:
        return FSciPReport_D5inObservedPointPositionValue__Left;
    case FSciPReport_MemLastReportedPointPositionValue__Right:
        return FSciPReport_D5inObservedPointPositionValue__Right;
    case FSciPReport_MemLastReportedPointPositionValue__NoEndPosition:
        return FSciPReport_D5inObservedPointPositionValue__NoEndPosition;
    case FSciPReport_MemLastReportedPointPositionValue__Trailed:
        return FSciPReport_D5inObservedPointPositionValue__Trailed;
    default:
        abort();
    }
}
static FSciPReport_D4inObservedDegradedPointPositionValue
map_MemLastReportedDegradedPointPosition_to_D4inObservedDegradedPointPosition(
    FSciPReport_MemLastReportedDegradedPointPositionValue value)
{
    switch (value)
    {
    case FSciPReport_MemLastReportedDegradedPointPositionValue__NULL__:
        return FSciPReport_D4inObservedDegradedPointPositionValue__NULL__;
    case FSciPReport_MemLastReportedDegradedPointPositionValue__UNKNOWN__:
        return FSciPReport_D4inObservedDegradedPointPositionValue__UNKNOWN__;
    case FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedLeft:
        return FSciPReport_D4inObservedDegradedPointPositionValue__DegradedLeft;
    case FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedRight:
        return FSciPReport_D4inObservedDegradedPointPositionValue__DegradedRight;
    case FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedDenied:
        return FSciPReport_D4inObservedDegradedPointPositionValue__DegradedDenied;
    default:
        abort();
    }
}
static FSciPReport_MemLastReportedPointPositionValue map_D5inObservedPointPosition_to_MemLastReportedPointPosition(
    FSciPReport_D5inObservedPointPositionValue value)
{
    switch (value)
    {
    case FSciPReport_D5inObservedPointPositionValue__NULL__:
        return FSciPReport_MemLastReportedPointPositionValue__NULL__;
    case FSciPReport_D5inObservedPointPositionValue__UNKNOWN__:
        return FSciPReport_MemLastReportedPointPositionValue__UNKNOWN__;
    case FSciPReport_D5inObservedPointPositionValue__Left:
        return FSciPReport_MemLastReportedPointPositionValue__Left;
    case FSciPReport_D5inObservedPointPositionValue__Right:
        return FSciPReport_MemLastReportedPointPositionValue__Right;
    case FSciPReport_D5inObservedPointPositionValue__NoEndPosition:
        return FSciPReport_MemLastReportedPointPositionValue__NoEndPosition;
    case FSciPReport_D5inObservedPointPositionValue__Trailed:
        return FSciPReport_MemLastReportedPointPositionValue__Trailed;
    default:
        abort();
    }
}
static FSciPReport_MemLastReportedDegradedPointPositionValue
map_D4inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
    FSciPReport_D4inObservedDegradedPointPositionValue value)
{
    switch (value)
    {
    case FSciPReport_D4inObservedDegradedPointPositionValue__NULL__:
        return FSciPReport_MemLastReportedDegradedPointPositionValue__NULL__;
    case FSciPReport_D4inObservedDegradedPointPositionValue__UNKNOWN__:
        return FSciPReport_MemLastReportedDegradedPointPositionValue__UNKNOWN__;
    case FSciPReport_D4inObservedDegradedPointPositionValue__DegradedLeft:
        return FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedLeft;
    case FSciPReport_D4inObservedDegradedPointPositionValue__DegradedRight:
        return FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedRight;
    case FSciPReport_D4inObservedDegradedPointPositionValue__DegradedDenied:
        return FSciPReport_MemLastReportedDegradedPointPositionValue__DegradedDenied;
    default:
        abort();
    }
}

// Operations
static PointPositionState__2e6f Cop1PointPosition(FSciPReport *self)
{
    if (self->D5inObservedPointPosition.Value == FSciPReport_D5inObservedPointPositionValue__Left)
    {
        return PointPositionState__2e6f__Left;
    }
    else if (self->D5inObservedPointPosition.Value == FSciPReport_D5inObservedPointPositionValue__Right)
    {
        return PointPositionState__2e6f__Right;
    }
    else if (self->D5inObservedPointPosition.Value == FSciPReport_D5inObservedPointPositionValue__NoEndPosition)
    {
        return PointPositionState__2e6f__NoEndPosition;
    }
    else if (self->D5inObservedPointPosition.Value == FSciPReport_D5inObservedPointPositionValue__Trailed)
    {
        return PointPositionState__2e6f__Trailed;
    }
    abort();
}
static PointPositionDegradedState__422e Cop2DegradedPointPosition(FSciPReport *self)
{
    if (self->D4inObservedDegradedPointPosition.Value ==
        FSciPReport_D4inObservedDegradedPointPositionValue__DegradedLeft)
    {
        return PointPositionDegradedState__422e__DegradedLeft;
    }
    else if (self->D4inObservedDegradedPointPosition.Value ==
             FSciPReport_D4inObservedDegradedPointPositionValue__DegradedRight)
    {
        return PointPositionDegradedState__422e__DegradedRight;
    }
    else if (self->D4inObservedDegradedPointPosition.Value ==
             FSciPReport_D4inObservedDegradedPointPositionValue__DegradedDenied)
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
    if (self->D6inObservedAbilityToMove.Value == FSciPReport_D6inObservedAbilityToMoveValue__AbleToMove)
    {
        return AbilityToMoveState__ed0f__AbleToMove;
    }
    else if (self->D6inObservedAbilityToMove.Value == FSciPReport_D6inObservedAbilityToMoveValue__UnableToMove)
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

void make_state_FSciPReport__root__ReportingOverallPointStates(FSciPReport *self,
                                                               FSciPReport__root__state_struct *region)
{
    LOG("[FSciPReport] Entering state ReportingOverallPointStates in region root");
    region->state = FSciPReport__root__ReportingOverallPointStates;
    make_state_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove(
        self, &region->ReportingOverallPointStates.ReportingAbilityToMove);
    make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition(
        self, &region->ReportingOverallPointStates.ReportingMsgPointPosition);
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

    if (self->Change458.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgAbilityToMovePoint__1f1b.Value.ReportedAbilityToMoveState =
                AbilityToMoveState__ed0f__AbleToMove;
            self->OutMsgAbilityToMovePoint__1f1b.HasMessage = 1;
            make_state_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove__MsgAbilityToMove(
                self, &x->ReportingOverallPointStates.ReportingAbilityToMove);
            return;
        }
    }
    if (self->Change459.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
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

    if (self->Change6.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgPointPosition__27c1.Value.ReportedPointPositionState = Cop1PointPosition(self);
            self->OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition = Cop2DegradedPointPosition(self);
            self->OutMsgPointPosition__27c1.HasMessage = 1;
            self->MemLastReportedPointPosition =
                map_D5inObservedPointPosition_to_MemLastReportedPointPosition(self->D5inObservedPointPosition.Value);
            self->MemLastReportedDegradedPointPosition =
                map_D4inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
                    self->D4inObservedDegradedPointPosition.Value);
            make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition(
                self, &x->ReportingOverallPointStates.ReportingMsgPointPosition);
            return;
        }
    }
    if (self->Change7.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgPointPosition__27c1.Value.ReportedPointPositionState = Cop1PointPosition(self);
            self->OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition = Cop2DegradedPointPosition(self);
            self->OutMsgPointPosition__27c1.HasMessage = 1;
            self->MemLastReportedPointPosition =
                map_D5inObservedPointPosition_to_MemLastReportedPointPosition(self->D5inObservedPointPosition.Value);
            self->MemLastReportedDegradedPointPosition =
                map_D4inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
                    self->D4inObservedDegradedPointPosition.Value);
            make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition(
                self, &x->ReportingOverallPointStates.ReportingMsgPointPosition);
            return;
        }
    }
}

void transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__Waiting(
    FSciPReport *self, FSciPReport__root__state_struct *x)
{

    if (self->Change308.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgPointPosition__27c1.Value.ReportedPointPositionState = Cop1PointPosition(self);
            self->OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition = Cop2DegradedPointPosition(self);
            self->OutMsgPointPosition__27c1.HasMessage = 1;
            self->MemLastReportedPointPosition =
                map_D5inObservedPointPosition_to_MemLastReportedPointPosition(self->D5inObservedPointPosition.Value);
            self->MemLastReportedDegradedPointPosition =
                map_D4inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
                    self->D4inObservedDegradedPointPosition.Value);
            make_state_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition__MsgOverallPointPosition(
                self, &x->ReportingOverallPointStates.ReportingMsgPointPosition);
            return;
        }
    }
    if (self->Change427.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value == FSciPReport_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgPointPosition__27c1.Value.ReportedPointPositionState = Cop1PointPosition(self);
            self->OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition = Cop2DegradedPointPosition(self);
            self->OutMsgPointPosition__27c1.HasMessage = 1;
            self->MemLastReportedPointPosition =
                map_D5inObservedPointPosition_to_MemLastReportedPointPosition(self->D5inObservedPointPosition.Value);
            self->MemLastReportedDegradedPointPosition =
                map_D4inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
                    self->D4inObservedDegradedPointPosition.Value);
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

void transition_from_FSciPReport__root__ReportingOverallPointStates(FSciPReport *self,
                                                                    FSciPReport__root__state_struct *x)
{
    transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingAbilityToMove(self, x);
    transition_from_FSciPReport__root__ReportingOverallPointStates__ReportingMsgPointPosition(self, x);
    if (self->Change331.IsTriggered)
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

        self->OutMsgAbilityToMovePoint__1f1b.Value.ReportedAbilityToMoveState = Cop3AbilityToMove(self);
        self->OutMsgAbilityToMovePoint__1f1b.HasMessage = 1;
        self->MemLastReportedPointPosition =
            map_D5inObservedPointPosition_to_MemLastReportedPointPosition(self->D5inObservedPointPosition.Value);
        self->MemLastReportedDegradedPointPosition =
            map_D4inObservedDegradedPointPosition_to_MemLastReportedDegradedPointPosition(
                self->D4inObservedDegradedPointPosition.Value);

        self->OutStatusReportCompleted__b457.HasMessage = 1;
        make_state_FSciPReport__root__ReportingOverallPointStates(self, x);
        return;
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
    self->Change458.IsTriggered = IsTriggered(
        MakeChange(self->D6inObservedAbilityToMove.IsSignalled,
                   self->D6inObservedAbilityToMove.Value == FSciPReport_D6inObservedAbilityToMoveValue__AbleToMove));
    self->Change459.IsTriggered = IsTriggered(
        MakeChange(self->D6inObservedAbilityToMove.IsSignalled,
                   self->D6inObservedAbilityToMove.Value == FSciPReport_D6inObservedAbilityToMoveValue__UnableToMove));
    self->Change6.IsTriggered =
        IsTriggered(MakeChange(self->D4inObservedDegradedPointPosition.IsSignalled,
                               !(self->D4inObservedDegradedPointPosition.Value ==
                                 map_MemLastReportedDegradedPointPosition_to_D4inObservedDegradedPointPosition(
                                     self->MemLastReportedDegradedPointPosition))));
    self->Change7.IsTriggered = IsTriggered(MakeChange(
        self->D5inObservedPointPosition.IsSignalled,
        !(self->D5inObservedPointPosition.Value ==
          map_MemLastReportedPointPosition_to_D5inObservedPointPosition(self->MemLastReportedPointPosition))));
    self->Change308.IsTriggered =
        IsTriggered(MakeChange(self->D4inObservedDegradedPointPosition.IsSignalled,
                               !(self->D4inObservedDegradedPointPosition.Value ==
                                 map_MemLastReportedDegradedPointPosition_to_D4inObservedDegradedPointPosition(
                                     self->MemLastReportedDegradedPointPosition))));
    self->Change427.IsTriggered = IsTriggered(MakeChange(
        self->D5inObservedPointPosition.IsSignalled,
        !(self->D5inObservedPointPosition.Value ==
          map_MemLastReportedPointPosition_to_D5inObservedPointPosition(self->MemLastReportedPointPosition))));
    self->Change331.IsTriggered = IsTriggered(OrChange(
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
}

static void resetTriggers(FSciPReport *self)
{
    self->InStartStatusReport__1e4e.HasMessage = false;

    self->D50inPdiConnectionState.IsSignalled = false;
    self->D5inObservedPointPosition.IsSignalled = false;
    self->D6inObservedAbilityToMove.IsSignalled = false;
    self->D4inObservedDegradedPointPosition.IsSignalled = false;
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
