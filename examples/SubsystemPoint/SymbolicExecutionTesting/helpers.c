#include "helpers.h"

void apply_inputs(system_inputs_t *inputs, FSciEfesSec *fSciEfesSec, FSciPReport *fSciPReport, FSciPReceive *fSciPReceive, FObserveDegradedPointPosition *fObserveDegradedPointPosition, FObserveOverallPointPosition *fObserveOverallPointPosition, FObserveAbilityToMove *fObserveAbilityToMove, FControlAndObserve4WPm *fControlAndObserve4WPm, FObserveMovementFailed *fObserveMovementFailed, FControlPoint *fControlPoint, FEstEfes *fEstEfes)
{
    // FSciEfesSec
    fSciEfesSec->T20inProtocolError = inputs->T20inProtocolError;
    fSciEfesSec->T21inFormalTelegramError = inputs->T21inFormalTelegramError;
    fSciEfesSec->T22inContentTelegramError = inputs->T22inContentTelegramError;
    fSciEfesSec->T5inScpConnectionEstablished = inputs->T5inScpConnectionEstablished;
    fSciEfesSec->T10inScpConnectionTerminated = inputs->T10inScpConnectionTerminated;

    fSciEfesSec->InCdInitialisationRequest__8d96.HasMessage = inputs->InCdInitialisationRequest__8d96.HasMessage;
    fSciEfesSec->InCdInitialisationRequest__8d96.Value = inputs->InCdInitialisationRequest__8d96.Value;
    fSciEfesSec->InStatusReportCompleted__b457.HasMessage = inputs->InStatusReportCompleted__b457.HasMessage;
    fSciEfesSec->InStatusReportCompleted__b457.Value = inputs->InStatusReportCompleted__b457.Value;
    fSciEfesSec->InCdPdiVersionCheck__ffab.HasMessage = inputs->InCdPdiVersionCheck__ffab.HasMessage;
    fSciEfesSec->InCdPdiVersionCheck__ffab.Value = inputs->InCdPdiVersionCheck__ffab.Value;
    fSciEfesSec->InReadyForPdiConnection__6bd3.HasMessage = inputs->InReadyForPdiConnection__6bd3.HasMessage;
    fSciEfesSec->InReadyForPdiConnection__6bd3.Value = inputs->InReadyForPdiConnection__6bd3.Value;
    fSciEfesSec->InNotreadyForPdiConnection__0b73.HasMessage = inputs->InNotreadyForPdiConnection__0b73.HasMessage;
    fSciEfesSec->InNotreadyForPdiConnection__0b73.Value = inputs->InNotreadyForPdiConnection__0b73.Value;
    fSciEfesSec->InCdClosePdi__8a06.HasMessage = inputs->InCdClosePdi__8a06.HasMessage;
    fSciEfesSec->InCdClosePdi__8a06.Value = inputs->InCdClosePdi__8a06.Value;
    fSciEfesSec->InCdReleasePdiForMaintenance__3e43.HasMessage = inputs->InCdReleasePdiForMaintenance__3e43.HasMessage;
    fSciEfesSec->InCdReleasePdiForMaintenance__3e43.Value = inputs->InCdReleasePdiForMaintenance__3e43.Value;

    // FSciPReport
    // no inputs.

    // FSciPReceive
    fSciPReceive->InCdMovePoint__342e.HasMessage = inputs->InCdMovePoint__342e.HasMessage;
    fSciPReceive->InCdMovePoint__342e.Value = inputs->InCdMovePoint__342e.Value;

    // FObserveDegradedPointPosition
    // fObserveDegradedPointPosition.D10inPm1CrucialPosition.Value = inputs->D10inPm1CrucialPosition.Value;
    // fObserveDegradedPointPosition.D10inPm1CrucialPosition.IsSignalled = inputs->D10inPm1CrucialPosition.IsSignalled;
    // fObserveDegradedPointPosition.D10inPmiCrucialPosition.Value = inputs->D10inPm1CrucialPosition.Value;
    // fObserveDegradedPointPosition.D10inPmiCrucialPosition.IsSignalled = inputs->D10inPm1CrucialPosition.IsSignalled;
    // fObserveDegradedPointPosition.D10inPm1NonCrucialPosition.Value = inputs->D10inPm1CrucialPosition.Value;
    // fObserveDegradedPointPosition.D10inPm1NonCrucialPosition.IsSignalled = inputs->D10inPm1CrucialPosition.IsSignalled;
    // fObserveDegradedPointPosition.D10inPmkNonCrucialPosition.Value = inputs->D10inPm1CrucialPosition.Value;
    // fObserveDegradedPointPosition.D10inPmkNonCrucialPosition.IsSignalled = inputs->D10inPm1CrucialPosition.IsSignalled;

    // FObserveOverallPointPosition
    // DataPort(FObserveOverallPointPosition_D10inPm1CrucialPositionValue, ) D10inPm1CrucialPosition;
    // DataPort(FObserveOverallPointPosition_D10inPmiCrucialPositionValue, ) D10inPmiCrucialPosition;
    // DataPort(FObserveOverallPointPosition_D10inPm1NonCrucialPositionValue, ) D10inPm1NonCrucialPosition;
    // DataPort(FObserveOverallPointPosition_D10inPmkNonCrucialPositionValue, ) D10inPmkNonCrucialPosition;

    // FObserveAbilityToMove
    // DataPort(FObserveAbilityToMove_D19inAbilityToMovePm1nCrucialValue, ) D19inAbilityToMovePm1nCrucial;
    // DataPort(FObserveAbilityToMove_D19inAbilityToMovePm1CrucialValue, ) D19inAbilityToMovePm1Crucial;
    // DataPort(FObserveAbilityToMove_D19inAbilityToMovePm2NonCrucialValue, ) D19inAbilityToMovePm2NonCrucial;
    // DataPort(FObserveAbilityToMove_D19inAbilityToMovePm2nNonCrucialValue, ) D19inAbilityToMovePm2nNonCrucial;
    // DataPort(bool, ) D33inInternalTriggerAbilityToMovePointAvailable;

    // FControlAndObserve4WPm
    fControlAndObserve4WPm->D27in4WPmPosition.Value = inputs->D27in4WPmPosition.Value;
    fControlAndObserve4WPm->D27in4WPmPosition.IsSignalled = inputs->D27in4WPmPosition.IsSignalled;
    // DataPort(bool, ) D26inInternalTriggerAbilityToMovePmAvailable;

    // FObserveMovementFailed
    // nothing

    // FControlPoint
    // nothing

    // FEstEfes
    fEstEfes->T1inPowerOnDetected = inputs->T1inPowerOnDetected;
    fEstEfes->T2inPowerOffDetected = inputs->T2inPowerOffDetected;
    fEstEfes->T3inReset = inputs->T3inReset;
    fEstEfes->T4inBooted = inputs->T4inBooted;
    fEstEfes->T5inSilNotFulfilled = inputs->T5inSilNotFulfilled;
    fEstEfes->T7inInvalidOrMissingBasicData = inputs->T7inInvalidOrMissingBasicData;
}
