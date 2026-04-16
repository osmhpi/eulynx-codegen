
#include "FControlAndObserve4WPm.h"

// Value Conversion Functions

// Operations

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__NoEndPosition(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state NoEndPosition in region "
        "root__Operating__DriveAndDetection__DetectionRight__root");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__NoEndPosition;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Trailed(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state Trailed in region "
        "root__Operating__DriveAndDetection__DetectionRight__root");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Trailed;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Initialising(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state Initialising in region "
        "root__Operating__DriveAndDetection__DetectionRight__root");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Initialising;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Right(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state Right in region "
        "root__Operating__DriveAndDetection__DetectionRight__root");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Right;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state_struct *x)
{
    memset(x, 0,
           sizeof(FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state_struct));
    self->D25outDetectionVoltage.Value = true;
    make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Initialising(self, x);
    return;
}

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Left(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state Left in region "
        "root__Operating__DriveAndDetection__DetectionLeft__root");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Left;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__NoEndPosition(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state NoEndPosition in region "
        "root__Operating__DriveAndDetection__DetectionLeft__root");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__NoEndPosition;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Trailed(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state Trailed in region "
        "root__Operating__DriveAndDetection__DetectionLeft__root");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Trailed;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Initialising(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state Initialising in region "
        "root__Operating__DriveAndDetection__DetectionLeft__root");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Initialising;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root(
    FControlAndObserve4WPm *self,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state_struct));
    self->D25outDetectionVoltage.Value = true;
    make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Initialising(self, x);
    return;
}

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__DriveAndDetection__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state DetectionRight in region root__Operating__DriveAndDetection");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight;
    make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root(
        self, &region->DetectionRight.root);
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__DriveAndDetection__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state DetectionLeft in region root__Operating__DriveAndDetection");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft;
    make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root(
        self, &region->DetectionLeft.root);
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__InitialisingWithoutTarget(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__DriveAndDetection__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state InitialisingWithoutTarget in region "
        "root__Operating__DriveAndDetection");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__InitialisingWithoutTarget;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__Waiting(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__DriveAndDetection__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state Waiting in region root__Operating__DriveAndDetection");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__Waiting;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingRightPm(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__DriveAndDetection__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state MovingRightPm in region root__Operating__DriveAndDetection");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingRightPm;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingLeftPm(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__DriveAndDetection__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state MovingLeftPm in region root__Operating__DriveAndDetection");
    region->state = FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingLeftPm;
};

void make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__DriveAndDetection__state_struct *x)
{
    memset(x, 0, sizeof(FControlAndObserve4WPm__root__Operating__DriveAndDetection__state_struct));

    make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__Waiting(self, x);
    return;
}

void make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__NotUsed(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state NotUsed in region root__Operating__CheckAbleToMove");
    region->state = FControlAndObserve4WPm__root__Operating__CheckAbleToMove__NotUsed;
};

void make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Able(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state Able in region root__Operating__CheckAbleToMove");
    region->state = FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Able;
};

void make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Waiting(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state Waiting in region root__Operating__CheckAbleToMove");
    region->state = FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Waiting;
};

void make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Unable(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state Unable in region root__Operating__CheckAbleToMove");
    region->state = FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Unable;
};

void make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state_struct *x)
{
    memset(x, 0, sizeof(FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state_struct));

    make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Waiting(self, x);
    return;
}

void make_state_FControlAndObserve4WPm__root__Operating(FControlAndObserve4WPm *self,
                                                        FControlAndObserve4WPm__root__state_struct *region)
{
    LOG("[FControlAndObserve4WPm] Entering state Operating in region root");
    region->state = FControlAndObserve4WPm__root__Operating;
    make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection(self, &region->Operating.DriveAndDetection);
    make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove(self, &region->Operating.CheckAbleToMove);
};

void make_state_FControlAndObserve4WPm__root(FControlAndObserve4WPm *self,
                                             FControlAndObserve4WPm__root__state_struct *x)
{
    memset(x, 0, sizeof(FControlAndObserve4WPm__root__state_struct));

    make_state_FControlAndObserve4WPm__root__Operating(self, x);
    return;
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__NoEndPosition(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Right;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Right(
            self, &x->Operating.DriveAndDetection.DetectionRight.root);
        return;
    }
    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Trailed;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Trailed(
            self, &x->Operating.DriveAndDetection.DetectionRight.root);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Trailed(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__NoEndPosition(
            self, &x->Operating.DriveAndDetection.DetectionRight.root);
        return;
    }
    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Right;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Right(
            self, &x->Operating.DriveAndDetection.DetectionRight.root);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Initialising(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__NoEndPosition(
            self, &x->Operating.DriveAndDetection.DetectionRight.root);
        return;
    }
    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Right;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Right(
            self, &x->Operating.DriveAndDetection.DetectionRight.root);
        return;
    }
    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Trailed;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Trailed(
            self, &x->Operating.DriveAndDetection.DetectionRight.root);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Right(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__NoEndPosition(
            self, &x->Operating.DriveAndDetection.DetectionRight.root);
        return;
    }
    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Trailed;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Trailed(
            self, &x->Operating.DriveAndDetection.DetectionRight.root);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
    switch (x->Operating.DriveAndDetection.DetectionRight.root.state)
    {
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__NoEndPosition:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__NoEndPosition(
            self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Trailed:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Trailed(self,
                                                                                                                  x);
        break;
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Initialising:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Initialising(
            self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Right:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Right(self,
                                                                                                                x);
        break;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Left(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__NoEndPosition(
            self, &x->Operating.DriveAndDetection.DetectionLeft.root);
        return;
    }
    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Trailed;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Trailed(
            self, &x->Operating.DriveAndDetection.DetectionLeft.root);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__NoEndPosition(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Left;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Left(
            self, &x->Operating.DriveAndDetection.DetectionLeft.root);
        return;
    }
    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Trailed;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Trailed(
            self, &x->Operating.DriveAndDetection.DetectionLeft.root);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Trailed(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Left;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Left(
            self, &x->Operating.DriveAndDetection.DetectionLeft.root);
        return;
    }
    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__NoEndPosition(
            self, &x->Operating.DriveAndDetection.DetectionLeft.root);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Initialising(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Left;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Left(
            self, &x->Operating.DriveAndDetection.DetectionLeft.root);
        return;
    }
    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__NoEndPosition(
            self, &x->Operating.DriveAndDetection.DetectionLeft.root);
        return;
    }
    if (true)
    {
        self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__Trailed;
        self->D10outPmPosition.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Trailed(
            self, &x->Operating.DriveAndDetection.DetectionLeft.root);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
    switch (x->Operating.DriveAndDetection.DetectionLeft.root.state)
    {
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Left:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Left(self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__NoEndPosition:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__NoEndPosition(
            self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Trailed:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Trailed(self,
                                                                                                                 x);
        break;
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Initialising:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Initialising(
            self, x);
        break;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
    transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root(self, x);
    if (self->Change162.IsTriggered)
    {
        if (self->D20inConDriveCapability.Value)
        {
            self->D25outDetectionVoltage.Value = false;
            self->D23outDriveVoltageLeft.Value = true;
            self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
            self->D10outPmPosition.IsSignalled = true;
            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingLeftPm(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
    if (self->Change169.IsTriggered)
    {
        if (self->D20inConDriveCapability.Value)
        {
            self->D25outDetectionVoltage.Value = false;
            self->D24outDriveVoltageRight.Value = true;
            self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
            self->D10outPmPosition.IsSignalled = true;
            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingRightPm(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
    if (self->Change181.IsTriggered)
    {
        if ((!(self->D20inConDriveCapability.Value)) ||
            (self->D6inObservedAbilityToMovePoint.Value ==
             FControlAndObserve4WPm_D6inObservedAbilityToMovePointValue__UnableToMove))
        {

            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
    transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root(self, x);
    if (self->Change160.IsTriggered)
    {
        if (self->D20inConDriveCapability.Value)
        {
            self->D25outDetectionVoltage.Value = false;
            self->D23outDriveVoltageLeft.Value = true;
            self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
            self->D10outPmPosition.IsSignalled = true;
            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingLeftPm(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
    if (self->Change166.IsTriggered)
    {
        if (self->D20inConDriveCapability.Value)
        {
            self->D25outDetectionVoltage.Value = false;
            self->D24outDriveVoltageRight.Value = true;
            self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
            self->D10outPmPosition.IsSignalled = true;
            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingRightPm(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
    if (self->Change187.IsTriggered)
    {
        if ((!(self->D20inConDriveCapability.Value)) ||
            (self->D6inObservedAbilityToMovePoint.Value ==
             FControlAndObserve4WPm_D6inObservedAbilityToMovePointValue__UnableToMove))
        {

            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__InitialisingWithoutTarget(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (self->Change161.IsTriggered)
    {
        if (self->D20inConDriveCapability.Value)
        {
            self->D25outDetectionVoltage.Value = false;
            self->D23outDriveVoltageLeft.Value = true;
            self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
            self->D10outPmPosition.IsSignalled = true;
            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingLeftPm(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
    if (self->Change168.IsTriggered)
    {
        if (self->D20inConDriveCapability.Value)
        {
            self->D25outDetectionVoltage.Value = false;
            self->D24outDriveVoltageRight.Value = true;
            self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
            self->D10outPmPosition.IsSignalled = true;
            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingRightPm(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
    if (self->Change182.IsTriggered)
    {
        if ((!(self->D20inConDriveCapability.Value)) ||
            (self->D6inObservedAbilityToMovePoint.Value ==
             FControlAndObserve4WPm_D6inObservedAbilityToMovePointValue__UnableToMove))
        {

            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
    if (self->Change186.IsTriggered)
    {
        if ((!(self->D20inConDriveCapability.Value)) ||
            (self->D6inObservedAbilityToMovePoint.Value ==
             FControlAndObserve4WPm_D6inObservedAbilityToMovePointValue__UnableToMove))
        {

            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__Waiting(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (self->Change377.IsTriggered)
    {

        if (self->D35inLastTargetPosition.Value == FControlAndObserve4WPm_D35inLastTargetPositionValue__Left)
        {

            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft(
                self, &x->Operating.DriveAndDetection);
            return;
        }
        if (self->D35inLastTargetPosition.Value == FControlAndObserve4WPm_D35inLastTargetPositionValue__Right)
        {

            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight(
                self, &x->Operating.DriveAndDetection);
            return;
        }
        else
        {
            self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
            self->D10outPmPosition.IsSignalled = true;
            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__InitialisingWithoutTarget(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingRightPm(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (true)
    {
        self->D24outDriveVoltageRight.Value = false;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight(
            self, &x->Operating.DriveAndDetection);
        return;
    }
    if (self->Change163.IsTriggered)
    {
        if (self->D20inConDriveCapability.Value)
        {
            self->D24outDriveVoltageRight.Value = false;
            self->D25outDetectionVoltage.Value = false;
            self->D23outDriveVoltageLeft.Value = true;
            self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
            self->D10outPmPosition.IsSignalled = true;
            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingLeftPm(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
    if (self->Change282.IsTriggered)
    {
        self->D24outDriveVoltageRight.Value = false;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft(
            self, &x->Operating.DriveAndDetection);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingLeftPm(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (true)
    {
        self->D23outDriveVoltageLeft.Value = false;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft(
            self, &x->Operating.DriveAndDetection);
        return;
    }
    if (self->Change167.IsTriggered)
    {
        if (self->D20inConDriveCapability.Value)
        {
            self->D23outDriveVoltageLeft.Value = false;
            self->D25outDetectionVoltage.Value = false;
            self->D24outDriveVoltageRight.Value = true;
            self->D10outPmPosition.Value = FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition;
            self->D10outPmPosition.IsSignalled = true;
            make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingRightPm(
                self, &x->Operating.DriveAndDetection);
            return;
        }
    }
    if (self->Change281.IsTriggered)
    {
        self->D23outDriveVoltageLeft.Value = false;
        make_state_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight(
            self, &x->Operating.DriveAndDetection);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
    switch (x->Operating.DriveAndDetection.state)
    {
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight(self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft(self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__InitialisingWithoutTarget:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__InitialisingWithoutTarget(self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__Waiting:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__Waiting(self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingRightPm:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingRightPm(self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingLeftPm:
        transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingLeftPm(self, x);
        break;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__NotUsed(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
}

void transition_from_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Able(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (self->Change568.IsTriggered)
    {
        self->D19outAbilityToMovePm.Value = FControlAndObserve4WPm_D19outAbilityToMovePmValue__Unable;
        self->D19outAbilityToMovePm.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Unable(self,
                                                                                    &x->Operating.CheckAbleToMove);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Waiting(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (self->Change348.IsTriggered)
    {
        if (self->D45inConActive.Value)
        {

            if ((self->D20inConDriveCapability.Value) && (self->D26inDriveVoltageAvailable.Value))
            {
                self->D19outAbilityToMovePm.Value = FControlAndObserve4WPm_D19outAbilityToMovePmValue__Able;
                self->D19outAbilityToMovePm.IsSignalled = true;
                make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Able(
                    self, &x->Operating.CheckAbleToMove);
                return;
            }
            if (!(self->D20inConDriveCapability.Value))
            {
                self->D19outAbilityToMovePm.Value = FControlAndObserve4WPm_D19outAbilityToMovePmValue__NotUsed;
                self->D19outAbilityToMovePm.IsSignalled = true;
                make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__NotUsed(
                    self, &x->Operating.CheckAbleToMove);
                return;
            }
            if ((self->D20inConDriveCapability.Value) && (!(self->D26inDriveVoltageAvailable.Value)))
            {
                self->D19outAbilityToMovePm.Value = FControlAndObserve4WPm_D19outAbilityToMovePmValue__Unable;
                self->D19outAbilityToMovePm.IsSignalled = true;
                make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Unable(
                    self, &x->Operating.CheckAbleToMove);
                return;
            }
        }
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Unable(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{

    if (self->Change177.IsTriggered)
    {
        self->D19outAbilityToMovePm.Value = FControlAndObserve4WPm_D19outAbilityToMovePmValue__Able;
        self->D19outAbilityToMovePm.IsSignalled = true;
        make_state_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Able(self, &x->Operating.CheckAbleToMove);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating__CheckAbleToMove(
    FControlAndObserve4WPm *self, FControlAndObserve4WPm__root__state_struct *x)
{
    switch (x->Operating.CheckAbleToMove.state)
    {
    case FControlAndObserve4WPm__root__Operating__CheckAbleToMove__NotUsed:
        transition_from_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__NotUsed(self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Able:
        transition_from_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Able(self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Waiting:
        transition_from_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Waiting(self, x);
        break;
    case FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Unable:
        transition_from_FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Unable(self, x);
        break;
    }
}

void transition_from_FControlAndObserve4WPm__root__Operating(FControlAndObserve4WPm *self,
                                                             FControlAndObserve4WPm__root__state_struct *x)
{
    transition_from_FControlAndObserve4WPm__root__Operating__DriveAndDetection(self, x);
    transition_from_FControlAndObserve4WPm__root__Operating__CheckAbleToMove(self, x);
    if (self->Change383.IsTriggered)
    {

        make_state_FControlAndObserve4WPm__root__Operating(self, x);
        return;
    }
}

void transition_from_FControlAndObserve4WPm__root(FControlAndObserve4WPm *self,
                                                  FControlAndObserve4WPm__root__state_struct *x)
{
    switch (x->state)
    {
    case FControlAndObserve4WPm__root__Operating:
        transition_from_FControlAndObserve4WPm__root__Operating(self, x);
        break;
    }
}

static void evaluateChangeEvents(FControlAndObserve4WPm *self)
{
    self->Change162.IsTriggered =
        IsTriggered(MakeChange(self->D21inMoveLeftPm.IsSignalled, self->D21inMoveLeftPm.Value));
    self->Change169.IsTriggered =
        IsTriggered(MakeChange(self->D22inMoveRightPm.IsSignalled, self->D22inMoveRightPm.Value));
    self->Change181.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredPointPosition.IsSignalled,
        self->D2inRequiredPointPosition.Value == FControlAndObserve4WPm_D2inRequiredPointPositionValue__Left));
    self->Change160.IsTriggered =
        IsTriggered(MakeChange(self->D21inMoveLeftPm.IsSignalled, self->D21inMoveLeftPm.Value));
    self->Change166.IsTriggered =
        IsTriggered(MakeChange(self->D22inMoveRightPm.IsSignalled, self->D22inMoveRightPm.Value));
    self->Change187.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredPointPosition.IsSignalled,
        self->D2inRequiredPointPosition.Value == FControlAndObserve4WPm_D2inRequiredPointPositionValue__Right));
    self->Change161.IsTriggered =
        IsTriggered(MakeChange(self->D21inMoveLeftPm.IsSignalled, self->D21inMoveLeftPm.Value));
    self->Change168.IsTriggered =
        IsTriggered(MakeChange(self->D22inMoveRightPm.IsSignalled, self->D22inMoveRightPm.Value));
    self->Change182.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredPointPosition.IsSignalled,
        self->D2inRequiredPointPosition.Value == FControlAndObserve4WPm_D2inRequiredPointPositionValue__Left));
    self->Change186.IsTriggered = IsTriggered(MakeChange(
        self->D2inRequiredPointPosition.IsSignalled,
        self->D2inRequiredPointPosition.Value == FControlAndObserve4WPm_D2inRequiredPointPositionValue__Right));
    self->Change377.IsTriggered = IsTriggered(AndChange(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlAndObserve4WPm_D51inEstEfesStateValue__Initialising),
        MakeChange(self->D45inConActive.IsSignalled, self->D45inConActive.Value)));
    self->Change163.IsTriggered =
        IsTriggered(MakeChange(self->D21inMoveLeftPm.IsSignalled, self->D21inMoveLeftPm.Value));
    self->Change282.IsTriggered =
        IsTriggered(MakeChange(self->D41inMsgTimeout.IsSignalled, self->D41inMsgTimeout.Value));
    self->Change167.IsTriggered =
        IsTriggered(MakeChange(self->D22inMoveRightPm.IsSignalled, self->D22inMoveRightPm.Value));
    self->Change281.IsTriggered =
        IsTriggered(MakeChange(self->D41inMsgTimeout.IsSignalled, self->D41inMsgTimeout.Value));
    self->Change568.IsTriggered = IsTriggered(
        NegateChange(MakeChange(self->D26inDriveVoltageAvailable.IsSignalled, self->D26inDriveVoltageAvailable.Value)));
    self->Change348.IsTriggered = IsTriggered(
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlAndObserve4WPm_D51inEstEfesStateValue__Booting));
    self->Change177.IsTriggered =
        IsTriggered(MakeChange(self->D26inDriveVoltageAvailable.IsSignalled, self->D26inDriveVoltageAvailable.Value));
    self->Change383.IsTriggered = IsTriggered(OrChange(
        OrChange(MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value ==
                                FControlAndObserve4WPm_D51inEstEfesStateValue__NoOperatingVoltage),
                 MakeChange(self->D51inEstEfesState.IsSignalled,
                            self->D51inEstEfesState.Value == FControlAndObserve4WPm_D51inEstEfesStateValue__Booting)),
        MakeChange(self->D51inEstEfesState.IsSignalled,
                   self->D51inEstEfesState.Value == FControlAndObserve4WPm_D51inEstEfesStateValue__FallbackMode)));
}

static void resetOutputs(FControlAndObserve4WPm *self)
{

    self->D10outPmPosition.IsSignalled = false;
    self->D19outAbilityToMovePm.IsSignalled = false;
    self->D24outDriveVoltageRight.IsSignalled = false;
    self->D23outDriveVoltageLeft.IsSignalled = false;
    self->D25outDetectionVoltage.IsSignalled = false;
}

static void resetTriggers(FControlAndObserve4WPm *self)
{

    self->D21inMoveLeftPm.IsSignalled = false;
    self->D22inMoveRightPm.IsSignalled = false;
    self->D26inDriveVoltageAvailable.IsSignalled = false;
    self->D20inConDriveCapability.IsSignalled = false;
    self->D27in4WPattern.IsSignalled = false;
    self->D51inEstEfesState.IsSignalled = false;
    self->D35inLastTargetPosition.IsSignalled = false;
    self->D2inRequiredPointPosition.IsSignalled = false;
    self->D45inConActive.IsSignalled = false;
    self->D6inObservedAbilityToMovePoint.IsSignalled = false;
    self->D41inMsgTimeout.IsSignalled = false;
}

void transition_FControlAndObserve4WPm(FControlAndObserve4WPm *self)
{
    resetOutputs(self);
    evaluateChangeEvents(self);
    transition_from_FControlAndObserve4WPm__root(self, &self->state);
    resetTriggers(self);
}

void new_FControlAndObserve4WPm(FControlAndObserve4WPm *self)
{
    make_state_FControlAndObserve4WPm__root(self, &self->state);
}

#ifdef KLEE_ENABLED
#include "../../05_OutputKleeAnalysis/SubsystemPoint/FControlAndObserve4WPm.c"
#endif
