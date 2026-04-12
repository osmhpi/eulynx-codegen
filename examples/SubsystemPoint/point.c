#include "point.h"

#include <stdio.h>
#include <assert.h>

static FSciEfesSec fSciEfesSec;
static FSciPReport fSciPReport;
static FSciPReceive fSciPReceive;
static FObserveDegradedPointPosition fObserveDegradedPointPosition;
static FObserveOverallPointPosition fObserveOverallPointPosition;
static FObserveAbilityToMove fObserveAbilityToMove;
static FControlAndObserve4WPm fControlAndObserve4WPm;
static FObserveMovementFailed fObserveMovementFailed;
static FControlPoint fControlPoint;
static FEstEfes fEstEfes;

int main() {
    // Configuration
    bool D15inConObserveAbilityToMove = false;

    fSciEfesSec.D3inConPdiVersion.Value = 1;
    memset(&fSciEfesSec.D4inConChecksumData, 0, sizeof(fSciEfesSec.D4inConChecksumData));

    fSciPReport.D15inConObserveAbilityToMove.Value = D15inConObserveAbilityToMove;

    fControlPoint.D18inConUseRedrive.Value = false;

    // fObserveMovementFailed.D20inConTmaxPmOperation.Value = 10;

    fControlAndObserve4WPm.D20inConDriveCapability.Value = true;
    fControlAndObserve4WPm.D45inConActive.Value = true;

    // fObserveDegradedPointPosition.D26inConPmiCrucialActivation
    // fObserveDegradedPointPosition.D27inConPm1NonCrucialActivation
    // fObserveDegradedPointPosition.D28inConPmkNonCrucialActivation
    // fObserveOverallPointPosition.D26inConPmiCrucialActivation
    // fObserveOverallPointPosition.D27inConPm1NonCrucialActivation
    // fObserveOverallPointPosition.D28inConPmkNonCrucialActivation
    // fObserveOverallPointPosition.D29inConUseUnintendedPosition

    fObserveAbilityToMove.D15inConObserveAbilityToMove.Value = D15inConObserveAbilityToMove;
    // fObserveAbilityToMove.D26inConPmiCrucialActivation
    // fObserveAbilityToMove.D27inConPm1NonCrucialActivation
    // fObserveAbilityToMove.D28inConPmkNonCrucialActivation
    // fObserveAbilityToMove.D28inConPmkNonCrucialActivation

    new_FSciEfesSec(&fSciEfesSec);
    new_FSciPReport(&fSciPReport);
    new_FSciPReceive(&fSciPReceive);
    new_FObserveDegradedPointPosition(&fObserveDegradedPointPosition);
    new_FObserveOverallPointPosition(&fObserveOverallPointPosition);
    new_FObserveAbilityToMove(&fObserveAbilityToMove);
    new_FControlAndObserve4WPm(&fControlAndObserve4WPm);
    new_FObserveMovementFailed(&fObserveMovementFailed);
    new_FControlPoint(&fControlPoint);
    new_FEstEfes(&fEstEfes);

    // Boot.
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);

    // Provide operating voltage
    fEstEfes.T1inPowerOnDetected.IsTriggered = true;
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);

    // Complete boot
    fEstEfes.T4inBooted.IsTriggered = true;
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);

    // Declare ready to accept connections.
    fSciEfesSec.InReadyForPdiConnection__6bd3.HasMessage = true;
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    assert(fSciEfesSec.D50outPdiConnectionState.Value == FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdiNoScp);

    // Signal RaSTA connection established.
    fSciEfesSec.T5inScpConnectionEstablished.IsTriggered = true;
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    assert(fSciEfesSec.D50outPdiConnectionState.Value == FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi);

    // Perform initialization sequence.

    // 1. Send version check message
    fSciEfesSec.InCdPdiVersionCheck__ffab.HasMessage = true;
    fSciEfesSec.InCdPdiVersionCheck__ffab.Value.PdiVersion = 1;
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    // Expect version check message
    assert(fSciEfesSec.OutMsgPdiVersionCheck__9827.HasMessage);
    assert(fSciEfesSec.OutMsgPdiVersionCheck__9827.Value.Result == MsgPdiVersionCheck__9827_ResultValue__Match);
    assert(fSciEfesSec.OutMsgPdiVersionCheck__9827.Value.PDIVersion == 1);

    // 2. Respond to version check message
    fSciEfesSec.InCdInitialisationRequest__8d96.HasMessage = true;
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    // Expect start initialization message
    assert(fSciEfesSec.OutMsgStartInitialisation__43d2.HasMessage);

    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    // Expect point position message
    assert(fSciPReport.OutMsgPointPosition__27c1.HasMessage);
    assert(fSciPReport.OutMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__NoEndPosition);
    assert(fSciPReport.OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition == PointPositionDegradedState__422e__NotApplicable);

    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    // Expect end initialization message
    assert(fSciEfesSec.OutMsgInitialisationCompleted__75d9.HasMessage);
    // Expect supervise point position
    assert(fControlAndObserve4WPm.D25outDetectionVoltage.Value == true);
    assert(fControlAndObserve4WPm.D24outDriveVoltageRight.Value == false);
    assert(fControlAndObserve4WPm.D23outDriveVoltageLeft.Value == false);

    // Trigger a point movement to the right
    fControlAndObserve4WPm.D27in4WPmPosition.IsSignalled = true;
    fControlAndObserve4WPm.D27in4WPmPosition.Value = FControlAndObserve4WPm_D27in4WPmPositionValue__RightDetected;
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);

    // Expect point position message
    assert(fSciPReport.OutMsgPointPosition__27c1.HasMessage);
    assert(fSciPReport.OutMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__Right);
    assert(fSciPReport.OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition == PointPositionDegradedState__422e__NotApplicable);

/*
    // Command a point movement to the left
    fSciPReceive.InCdMovePoint__342e.Value.CommandedPointPositionState = PointPositionControlableState__14bc__Left;
    fSciPReceive.InCdMovePoint__342e.HasMessage = true;
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);

    assert(fControlAndObserve4WPm.D23outDriveVoltageLeft.Value == true);

    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    // Expect point position message
    assert(fSciPReport.OutMsgPointPosition__27c1.HasMessage);
    assert(fSciPReport.OutMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__NoEndPosition);
    assert(fSciPReport.OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition == PointPositionDegradedState__422e__NotApplicable);
*/

    // Ensure system is in a stable state (no further transitions expected).
    LOG("NO TRANSITIONS EXPECTED");
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);

    LOG("Done.");

    return 0;
}
