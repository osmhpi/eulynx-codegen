#include "../point.h"

#include <stdio.h>
#include <assert.h>

#include <klee/klee.h>

#include "helpers.h"

static SubsystemPoint point;

int main() {
    // Configuration
    bool D15inConObserveAbilityToMove = false;

    point.fSciEfesSec.D3inConPdiVersion.Value = 1;
    memset(&point.fSciEfesSec.D4inConChecksumData, 0, sizeof(point.fSciEfesSec.D4inConChecksumData));

    point.fSciPReport.D15inConObserveAbilityToMove.Value = D15inConObserveAbilityToMove;

    point.fControlPoint.D18inConUseRedrive.Value = false;

    // point.fObserveMovementFailed.D20inConTmaxPmOperation.Value = 10;

    point.fControlAndObserve4WPm.D20inConDriveCapability.Value = true;
    point.fControlAndObserve4WPm.D45inConActive.Value = true;

    // point.fObserveDegradedPointPosition.D26inConPmiCrucialActivation
    // point.fObserveDegradedPointPosition.D27inConPm1NonCrucialActivation
    // point.fObserveDegradedPointPosition.D28inConPmkNonCrucialActivation
    // point.fObserveOverallPointPosition.D26inConPmiCrucialActivation
    // point.fObserveOverallPointPosition.D27inConPm1NonCrucialActivation
    // point.fObserveOverallPointPosition.D28inConPmkNonCrucialActivation
    // point.fObserveOverallPointPosition.D29inConUseUnintendedPosition

    point.fObserveAbilityToMove.D15inConObserveAbilityToMove.Value = D15inConObserveAbilityToMove;
    // point.fObserveAbilityToMove.D26inConPmiCrucialActivation
    // point.fObserveAbilityToMove.D27inConPm1NonCrucialActivation
    // point.fObserveAbilityToMove.D28inConPmkNonCrucialActivation
    // point.fObserveAbilityToMove.D28inConPmkNonCrucialActivation

    new_FSciEfesSec(&point.fSciEfesSec);
    new_FSciPReport(&point.fSciPReport);
    new_FSciPReceive(&point.fSciPReceive);
    new_FObserveDegradedPointPosition(&point.fObserveDegradedPointPosition);
    new_FObserveOverallPointPosition(&point.fObserveOverallPointPosition);
    new_FObserveAbilityToMove(&point.fObserveAbilityToMove);
    new_FControlAndObserve4WPm(&point.fControlAndObserve4WPm);
    new_FObserveMovementFailed(&point.fObserveMovementFailed);
    new_FControlPoint(&point.fControlPoint);
    new_FEstEfes(&point.fEstEfes);

    // Boot.
    cycle(&point);

    // Provide operating voltage
    point.fEstEfes.T1inPowerOnDetected.IsTriggered = true;
    cycle(&point);

    // Complete boot
    point.fEstEfes.T4inBooted.IsTriggered = true;
    cycle(&point);

    // Declare ready to accept connections.
    point.fSciEfesSec.InReadyForPdiConnection__6bd3.HasMessage = true;
    cycle(&point);
    assert(point.fSciEfesSec.D50outPdiConnectionState.Value == FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdiNoScp);

    // Signal RaSTA connection established.
    point.fSciEfesSec.T5inScpConnectionEstablished.IsTriggered = true;
    cycle(&point);
    assert(point.fSciEfesSec.D50outPdiConnectionState.Value == FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi);

    // Perform initialization sequence.

    // 1. Send version check message
    point.fSciEfesSec.InCdPdiVersionCheck__ffab.HasMessage = true;
    point.fSciEfesSec.InCdPdiVersionCheck__ffab.Value.PdiVersion = 1;
    cycle(&point);
    // Expect version check message
    assert(point.fSciEfesSec.OutMsgPdiVersionCheck__9827.HasMessage);
    assert(point.fSciEfesSec.OutMsgPdiVersionCheck__9827.Value.Result == MsgPdiVersionCheck__9827_ResultValue__Match);
    assert(point.fSciEfesSec.OutMsgPdiVersionCheck__9827.Value.PDIVersion == 1);

    // 2. Respond to version check message
    point.fSciEfesSec.InCdInitialisationRequest__8d96.HasMessage = true;
    cycle(&point);
    // Expect start initialization message
    assert(point.fSciEfesSec.OutMsgStartInitialisation__43d2.HasMessage);

    cycle(&point);
    // Expect point position message
    assert(point.fSciPReport.OutMsgPointPosition__27c1.HasMessage);
    assert(point.fSciPReport.OutMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__NoEndPosition);
    assert(point.fSciPReport.OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition == PointPositionDegradedState__422e__NotApplicable);

    cycle(&point);
    // Expect end initialization message
    assert(point.fSciEfesSec.OutMsgInitialisationCompleted__75d9.HasMessage);
    // Expect supervise point position
    assert(point.fControlAndObserve4WPm.D25outDetectionVoltage.Value == true);
    assert(point.fControlAndObserve4WPm.D24outDriveVoltageRight.Value == false);
    assert(point.fControlAndObserve4WPm.D23outDriveVoltageLeft.Value == false);

    // Ensure system is in a stable state (no further transitions expected).
    LOG("NO TRANSITIONS EXPECTED");
    cycle(&point);

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
    apply_inputs(&inputs1, &point);
    cycle(&point);
    pointPositionReported |= point.fSciPReport.OutMsgPointPosition__27c1.HasMessage;

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
    apply_inputs(&inputs2, &point);
    cycle(&point);
    pointPositionReported |= point.fSciPReport.OutMsgPointPosition__27c1.HasMessage;

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
    apply_inputs(&inputs3, &point);
    cycle(&point);
    pointPositionReported |= point.fSciPReport.OutMsgPointPosition__27c1.HasMessage;

    assert(pointPositionReported == true);

    return 0;
}
