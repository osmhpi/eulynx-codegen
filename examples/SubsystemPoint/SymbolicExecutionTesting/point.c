#include "../point.h"

#include <stdio.h>
#include <assert.h>

#include <klee/klee.h>

#include "helpers.h"

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

    // Ensure system is in a stable state (no further transitions expected).
    LOG("NO TRANSITIONS EXPECTED");
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);

    LOG("Done.");

    bool pointPositionReported = false;

    system_inputs_t inputs1;
    klee_make_symbolic(&inputs1, sizeof(inputs1), "inputs1");
    // klee_assume(inputs1.InCdMovePoint__342e.HasMessage == false);
    klee_assume(inputs1.InCdClosePdi__8a06.HasMessage == false);
    klee_assume(inputs1.InCdReleasePdiForMaintenance__3e43.HasMessage == false);
    klee_assume(inputs1.D27in4WPmPosition.IsSignalled == true);
    klee_assume(inputs1.D27in4WPmPosition.Value == FControlAndObserve4WPm_D27in4WPmPositionValue__RightDetected);
    klee_assume(inputs1.T20inProtocolError.IsTriggered == false);
    klee_assume(inputs1.T21inFormalTelegramError.IsTriggered == false);
    klee_assume(inputs1.T22inContentTelegramError.IsTriggered == false);
    // klee_assume(inputs1.T5inScpConnectionEstablished.IsTriggered == false);
    klee_assume(inputs1.T10inScpConnectionTerminated.IsTriggered == false);

    // klee_assume(inputs1.InCdInitialisationRequest__8d96.HasMessage == false);
    // klee_assume(inputs1.InStatusReportCompleted__b457.HasMessage == false);
    // klee_assume(inputs1.InCdPdiVersionCheck__ffab.HasMessage == false);
    // klee_assume(inputs1.InReadyForPdiConnection__6bd3.HasMessage == false);
    klee_assume(inputs1.InNotreadyForPdiConnection__0b73.HasMessage == false);

    // klee_assume(inputs1.D27in4WPmPosition.IsSignalled == false);
    // klee_assume(inputs1.T1inPowerOnDetected.IsTriggered == false);
    // klee_assume(inputs1.T2inPowerOffDetected.IsTriggered == false);
    // klee_assume(inputs1.T3inReset.IsTriggered == false);
    // klee_assume(inputs1.T4inBooted.IsTriggered == false);
    // klee_assume(inputs1.T5inSilNotFulfilled.IsTriggered == false);
    // klee_assume(inputs1.T7inInvalidOrMissingBasicData.IsTriggered == false);
    apply_inputs(&inputs1, &fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    pointPositionReported |= fSciPReport.OutMsgPointPosition__27c1.HasMessage;

    system_inputs_t inputs2;
    klee_make_symbolic(&inputs2, sizeof(inputs2), "inputs2");
    // klee_assume(inputs2.InCdMovePoint__342e.HasMessage == false);
    klee_assume(inputs2.InCdClosePdi__8a06.HasMessage == false);
    klee_assume(inputs2.InCdReleasePdiForMaintenance__3e43.HasMessage == false);
    klee_assume(inputs2.T20inProtocolError.IsTriggered == false);
    klee_assume(inputs2.T21inFormalTelegramError.IsTriggered == false);
    klee_assume(inputs2.T22inContentTelegramError.IsTriggered == false);
    // klee_assume(inputs2.T5inScpConnectionEstablished.IsTriggered == false);
    klee_assume(inputs2.T10inScpConnectionTerminated.IsTriggered == false);

    // klee_assume(inputs2.InCdInitialisationRequest__8d96.HasMessage == false);
    // klee_assume(inputs2.InStatusReportCompleted__b457.HasMessage == false);
    // klee_assume(inputs2.InCdPdiVersionCheck__ffab.HasMessage == false);
    // klee_assume(inputs2.InReadyForPdiConnection__6bd3.HasMessage == false);
    klee_assume(inputs2.InNotreadyForPdiConnection__0b73.HasMessage == false);

    // klee_assume(inputs2.D27in4WPmPosition.IsSignalled == false);
    // klee_assume(inputs2.T1inPowerOnDetected.IsTriggered == false);
    // klee_assume(inputs2.T2inPowerOffDetected.IsTriggered == false);
    // klee_assume(inputs2.T3inReset.IsTriggered == false);
    // klee_assume(inputs2.T4inBooted.IsTriggered == false);
    // klee_assume(inputs2.T5inSilNotFulfilled.IsTriggered == false);
    // klee_assume(inputs2.T7inInvalidOrMissingBasicData.IsTriggered == false);
    apply_inputs(&inputs2, &fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    pointPositionReported |= fSciPReport.OutMsgPointPosition__27c1.HasMessage;

    system_inputs_t inputs3;
    klee_make_symbolic(&inputs3, sizeof(inputs3), "inputs3");
    // klee_assume(inputs3.InCdMovePoint__342e.HasMessage == false);
    klee_assume(inputs3.InCdClosePdi__8a06.HasMessage == false);
    klee_assume(inputs3.InCdReleasePdiForMaintenance__3e43.HasMessage == false);
    klee_assume(inputs3.T20inProtocolError.IsTriggered == false);
    klee_assume(inputs3.T21inFormalTelegramError.IsTriggered == false);
    klee_assume(inputs3.T22inContentTelegramError.IsTriggered == false);
    // klee_assume(inputs3.T5inScpConnectionEstablished.IsTriggered == false);
    klee_assume(inputs3.T10inScpConnectionTerminated.IsTriggered == false);

    // klee_assume(inputs3.InCdInitialisationRequest__8d96.HasMessage == false);
    // klee_assume(inputs3.InStatusReportCompleted__b457.HasMessage == false);
    // klee_assume(inputs3.InCdPdiVersionCheck__ffab.HasMessage == false);
    // klee_assume(inputs3.InReadyForPdiConnection__6bd3.HasMessage == false);
    klee_assume(inputs3.InNotreadyForPdiConnection__0b73.HasMessage == false);

    // klee_assume(inputs3.D27in4WPmPosition.IsSignalled == false);
    // klee_assume(inputs3.T1inPowerOnDetected.IsTriggered == false);
    // klee_assume(inputs3.T2inPowerOffDetected.IsTriggered == false);
    // klee_assume(inputs3.T3inReset.IsTriggered == false);
    // klee_assume(inputs3.T4inBooted.IsTriggered == false);
    // klee_assume(inputs3.T5inSilNotFulfilled.IsTriggered == false);
    // klee_assume(inputs3.T7inInvalidOrMissingBasicData.IsTriggered == false);
    apply_inputs(&inputs3, &fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    cycle(&fSciEfesSec, &fSciPReport, &fSciPReceive, &fObserveDegradedPointPosition, &fObserveOverallPointPosition, &fObserveAbilityToMove, &fControlAndObserve4WPm, &fObserveMovementFailed, &fControlPoint, &fEstEfes);
    pointPositionReported |= fSciPReport.OutMsgPointPosition__27c1.HasMessage;

    assert(pointPositionReported == true);

    return 0;
}
