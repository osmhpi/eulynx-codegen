
#include "FSciPRecieveAndReportTimeout.h"

// Value Conversion Functions

// Operations

void make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft(
    FSciPRecieveAndReportTimeout *self,
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state_struct
        *region)
{
    LOG("[FSciPRecieveAndReportTimeout] Entering state CommandedLeft in region "
        "root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand");
    region->state =
        FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft;
};

void make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
    FSciPRecieveAndReportTimeout *self,
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state_struct
        *region)
{
    LOG("[FSciPRecieveAndReportTimeout] Entering state Uncommanded in region "
        "root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand");
    region->state =
        FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded;
};

void make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight(
    FSciPRecieveAndReportTimeout *self,
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state_struct
        *region)
{
    LOG("[FSciPRecieveAndReportTimeout] Entering state CommandedRight in region "
        "root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand");
    region->state =
        FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight;
};

void make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Waiting(
    FSciPRecieveAndReportTimeout *self,
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state_struct
        *region)
{
    LOG("[FSciPRecieveAndReportTimeout] Entering state Waiting in region "
        "root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand");
    region->state =
        FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Waiting;
};

void make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand(
    FSciPRecieveAndReportTimeout *self,
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state_struct *x)
{
    memset(
        x, 0,
        sizeof(
            FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__state_struct));
    self->D34outPm1ConActive.Value = true;
    self->D44outPm1ConDriveCapability.Value = true;
    self->D2outRequiredPointPosition.Value = FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Initial;
    self->D2outRequiredPointPosition.IsSignalled = true;
    make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Waiting(
        self, x);
    return;
}

void make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout(
    FSciPRecieveAndReportTimeout *self,
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__state_struct
        *region)
{
    LOG("[FSciPRecieveAndReportTimeout] Entering state ReportingPointTimeout in region "
        "root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout");
    region->state =
        FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout;
};

void make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout(
    FSciPRecieveAndReportTimeout *self,
    FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__state_struct *x)
{
    memset(
        x, 0,
        sizeof(
            FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__state_struct));

    make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout(
        self, x);
    return;
}

void make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout(
    FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *region)
{
    LOG("[FSciPRecieveAndReportTimeout] Entering state RecievingCommandsAndReportingTimeout in region root");
    region->state = FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout;
    make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand(
        self, &region->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
    make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout(
        self, &region->RecievingCommandsAndReportingTimeout.ReportingPointTimeout);
};

void make_state_FSciPRecieveAndReportTimeout__root(FSciPRecieveAndReportTimeout *self,
                                                   FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    memset(x, 0, sizeof(FSciPRecieveAndReportTimeout__root__state_struct));

    make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout(self, x);
    return;
}

void transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft(
    FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{

    if (true)
    {
        self->D2outRequiredPointPosition.Value =
            FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Uncommanded;
        self->D2outRequiredPointPosition.IsSignalled = true;
        make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
            self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
        return;
    }
    if (self->Time20.IsTimeoutExpired)
    {

        self->OutMsgTimeout__ff4f.HasMessage = 1;
        self->D41outMsgTimeout.Value = true;
        self->D2outRequiredPointPosition.Value =
            FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Uncommanded;
        self->D2outRequiredPointPosition.IsSignalled = true;
        make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
            self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
        return;
    }
    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Right) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            self->D2outRequiredPointPosition.Value =
                FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Right;
            self->D2outRequiredPointPosition.IsSignalled = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight(
                self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
            return;
        }
    }
    if (self->Change251.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {
            self->D2outRequiredPointPosition.Value =
                FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Uncommanded;
            self->D2outRequiredPointPosition.IsSignalled = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
                self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
            return;
        }
    }
    if (self->Change428.IsTriggered)
    {
        self->D2outRequiredPointPosition.Value =
            FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Uncommanded;
        self->D2outRequiredPointPosition.IsSignalled = true;
        make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
            self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
        return;
    }
}

void transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
    FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{

    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Left) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            self->D2outRequiredPointPosition.Value = FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Left;
            self->D2outRequiredPointPosition.IsSignalled = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft(
                self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
            return;
        }
    }
    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Right) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            self->D2outRequiredPointPosition.Value =
                FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Right;
            self->D2outRequiredPointPosition.IsSignalled = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight(
                self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
            return;
        }
    }
}

void transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight(
    FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{

    if (true)
    {
        self->D2outRequiredPointPosition.Value =
            FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Uncommanded;
        self->D2outRequiredPointPosition.IsSignalled = true;
        make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
            self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
        return;
    }
    if (self->Time19.IsTimeoutExpired)
    {

        self->OutMsgTimeout__ff4f.HasMessage = 1;
        self->D41outMsgTimeout.Value = true;
        self->D2outRequiredPointPosition.Value =
            FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Uncommanded;
        self->D2outRequiredPointPosition.IsSignalled = true;
        make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
            self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
        return;
    }
    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Left) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            self->D2outRequiredPointPosition.Value = FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Left;
            self->D2outRequiredPointPosition.IsSignalled = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft(
                self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
            return;
        }
    }
    if (self->Change250.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {
            self->D2outRequiredPointPosition.Value =
                FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Uncommanded;
            self->D2outRequiredPointPosition.IsSignalled = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
                self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
            return;
        }
    }
    if (self->Change429.IsTriggered)
    {
        self->D2outRequiredPointPosition.Value =
            FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Uncommanded;
        self->D2outRequiredPointPosition.IsSignalled = true;
        make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
            self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
        return;
    }
}

void transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Waiting(
    FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{

    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Left) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            self->D2outRequiredPointPosition.Value = FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Left;
            self->D2outRequiredPointPosition.IsSignalled = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft(
                self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
            return;
        }
    }
    if (self->InCdMovePoint__342e.HasMessage)
    {
        if ((self->InCdMovePoint__342e.Value.CommandedPointPositionState ==
             PointPositionControlableState__14bc__Right) &&
            (self->D50inPdiConnectionState.Value ==
             FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established))
        {
            self->D2outRequiredPointPosition.Value =
                FSciPRecieveAndReportTimeout_D2outRequiredPointPositionValue__Right;
            self->D2outRequiredPointPosition.IsSignalled = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight(
                self, &x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand);
            return;
        }
    }
}

void transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand(
    FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    switch (x->RecievingCommandsAndReportingTimeout.RecievingMoveCommand.state)
    {
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft:
        transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedLeft(
            self, x);
        break;
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded:
        transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Uncommanded(
            self, x);
        break;
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight:
        transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__CommandedRight(
            self, x);
        break;
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Waiting:
        transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand__Waiting(
            self, x);
        break;
    }
}

void transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout(
    FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{

    if (self->Change275.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgTimeout__ff4f.HasMessage = 1;
            self->D41outMsgTimeout.Value = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout(
                self, &x->RecievingCommandsAndReportingTimeout.ReportingPointTimeout);
            return;
        }
    }
    if (self->Change276.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgTimeout__ff4f.HasMessage = 1;
            self->D41outMsgTimeout.Value = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout(
                self, &x->RecievingCommandsAndReportingTimeout.ReportingPointTimeout);
            return;
        }
    }
    if (self->Change277.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgTimeout__ff4f.HasMessage = 1;
            self->D41outMsgTimeout.Value = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout(
                self, &x->RecievingCommandsAndReportingTimeout.ReportingPointTimeout);
            return;
        }
    }
    if (self->Change278.IsTriggered)
    {
        if (self->D50inPdiConnectionState.Value ==
            FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Established)
        {

            self->OutMsgTimeout__ff4f.HasMessage = 1;
            self->D41outMsgTimeout.Value = true;
            make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout(
                self, &x->RecievingCommandsAndReportingTimeout.ReportingPointTimeout);
            return;
        }
    }
}

void transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout(
    FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    switch (x->RecievingCommandsAndReportingTimeout.ReportingPointTimeout.state)
    {
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout:
        transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout__ReportingPointTimeout(
            self, x);
        break;
    }
}

void transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout(
    FSciPRecieveAndReportTimeout *self, FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__RecievingMoveCommand(self,
                                                                                                                   x);
    transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout__ReportingPointTimeout(
        self, x);
    if (self->Change328.IsTriggered)
    {

        make_state_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout(self, x);
        return;
    }
}

void transition_from_FSciPRecieveAndReportTimeout__root(FSciPRecieveAndReportTimeout *self,
                                                        FSciPRecieveAndReportTimeout__root__state_struct *x)
{
    switch (x->state)
    {
    case FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout:
        transition_from_FSciPRecieveAndReportTimeout__root__RecievingCommandsAndReportingTimeout(self, x);
        break;
    }
}

static void evaluateChangeEvents(FSciPRecieveAndReportTimeout *self)
{
    self->Change251.IsTriggered = IsTriggered(AndChange(
        AndChange(
            AndChange(MakeChange(self->D35inPm1DriveStop.IsSignalled, self->D35inPm1DriveStop.Value),
                      OrChange(MakeChange(self->D35inPm1nDriveStop.IsSignalled, self->D35inPm1nDriveStop.Value),
                               NegateChange(MakeChange(self->D36inPm1nActivation.IsSignalled,
                                                       self->D36inPm1nActivation.Value)))),
            OrChange(MakeChange(self->D35inPm2DriveStop.IsSignalled, self->D35inPm2DriveStop.Value),
                     NegateChange(MakeChange(self->D37inPm2Activation.IsSignalled, self->D37inPm2Activation.Value)))),
        OrChange(MakeChange(self->D35inPm2nDriveStop.IsSignalled, self->D35inPm2nDriveStop.Value),
                 NegateChange(MakeChange(self->D38inPm2nActivation.IsSignalled, self->D38inPm2nActivation.Value)))));
    self->Change428.IsTriggered = IsTriggered(MakeChange(
        self->D5inObservedPointPosition.IsSignalled,
        self->D5inObservedPointPosition.Value == FSciPRecieveAndReportTimeout_D5inObservedPointPositionValue__Left));
    self->Change250.IsTriggered = IsTriggered(AndChange(
        AndChange(
            AndChange(MakeChange(self->D35inPm1DriveStop.IsSignalled, self->D35inPm1DriveStop.Value),
                      OrChange(MakeChange(self->D35inPm1nDriveStop.IsSignalled, self->D35inPm1nDriveStop.Value),
                               NegateChange(MakeChange(self->D36inPm1nActivation.IsSignalled,
                                                       self->D36inPm1nActivation.Value)))),
            OrChange(MakeChange(self->D35inPm2DriveStop.IsSignalled, self->D35inPm2DriveStop.Value),
                     NegateChange(MakeChange(self->D37inPm2Activation.IsSignalled, self->D37inPm2Activation.Value)))),
        OrChange(MakeChange(self->D35inPm2nDriveStop.IsSignalled, self->D35inPm2nDriveStop.Value),
                 NegateChange(MakeChange(self->D38inPm2nActivation.IsSignalled, self->D38inPm2nActivation.Value)))));
    self->Change429.IsTriggered = IsTriggered(MakeChange(
        self->D5inObservedPointPosition.IsSignalled,
        self->D5inObservedPointPosition.Value == FSciPRecieveAndReportTimeout_D5inObservedPointPositionValue__Right));
    self->Change275.IsTriggered =
        IsTriggered(MakeChange(self->D40inPm1MsgPmTimeout.IsSignalled, self->D40inPm1MsgPmTimeout.Value));
    self->Change276.IsTriggered =
        IsTriggered(MakeChange(self->D40inPm1nMsgPmTimeout.IsSignalled, self->D40inPm1nMsgPmTimeout.Value));
    self->Change277.IsTriggered =
        IsTriggered(MakeChange(self->D40inPm2MsgPmTimeout.IsSignalled, self->D40inPm2MsgPmTimeout.Value));
    self->Change278.IsTriggered =
        IsTriggered(MakeChange(self->D40inPm2nMsgPmTimeout.IsSignalled, self->D40inPm2nMsgPmTimeout.Value));
    self->Change328.IsTriggered = IsTriggered(OrChange(
        OrChange(
            OrChange(
                OrChange(MakeChange(self->D50inPdiConnectionState.IsSignalled,
                                    self->D50inPdiConnectionState.Value ==
                                        FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__NotReadyForPdiNoScp),
                         MakeChange(self->D50inPdiConnectionState.IsSignalled,
                                    self->D50inPdiConnectionState.Value ==
                                        FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__ReadyForPdiNoScp)),
                MakeChange(self->D50inPdiConnectionState.IsSignalled,
                           self->D50inPdiConnectionState.Value ==
                               FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__NotReadyForPdi)),
            MakeChange(self->D50inPdiConnectionState.IsSignalled,
                       self->D50inPdiConnectionState.Value ==
                           FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__ReadyForPdi)),
        MakeChange(self->D50inPdiConnectionState.IsSignalled,
                   self->D50inPdiConnectionState.Value ==
                       FSciPRecieveAndReportTimeout_D50inPdiConnectionStateValue__Suspended)));
}

static void resetOutputs(FSciPRecieveAndReportTimeout *self)
{
    self->OutMsgTimeout__ff4f.HasMessage = false;

    self->D2outRequiredPointPosition.IsSignalled = false;
    self->D34outPm1ConActive.IsSignalled = false;
    self->D44outPm1ConDriveCapability.IsSignalled = false;
    self->D41outMsgTimeout.IsSignalled = false;
}

static void resetTriggers(FSciPRecieveAndReportTimeout *self)
{
    self->InCdMovePoint__342e.HasMessage = false;

    self->D50inPdiConnectionState.IsSignalled = false;
    self->D5inObservedPointPosition.IsSignalled = false;
    self->D35inPm1DriveStop.IsSignalled = false;
    self->D35inPm1nDriveStop.IsSignalled = false;
    self->D35inPm2DriveStop.IsSignalled = false;
    self->D35inPm2nDriveStop.IsSignalled = false;
    self->D36inPm1nActivation.IsSignalled = false;
    self->D37inPm2Activation.IsSignalled = false;
    self->D38inPm2nActivation.IsSignalled = false;
    self->D28inConTmaxPointOperation.IsSignalled = false;
    self->D40inPm1MsgPmTimeout.IsSignalled = false;
    self->D40inPm1nMsgPmTimeout.IsSignalled = false;
    self->D40inPm2MsgPmTimeout.IsSignalled = false;
    self->D40inPm2nMsgPmTimeout.IsSignalled = false;

    self->Time20.IsTimeoutExpired = false;
    self->Time19.IsTimeoutExpired = false;
}

void transition_FSciPRecieveAndReportTimeout(FSciPRecieveAndReportTimeout *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FSciPRecieveAndReportTimeout__root(self, &self->state);
    resetTriggers(self);
}

void new_FSciPRecieveAndReportTimeout(FSciPRecieveAndReportTimeout *self)
{
    make_state_FSciPRecieveAndReportTimeout__root(self, &self->state);
}
