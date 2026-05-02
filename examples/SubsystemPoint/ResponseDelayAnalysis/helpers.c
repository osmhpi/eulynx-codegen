#include "helpers.h"

void apply_inputs(system_inputs_t *inputs, SubsystemPoint *point)
{
    // FSciEfesSec
    point->fSciEfesSec.T20inProtocolError = inputs->T20inProtocolError;
    point->fSciEfesSec.T21inFormalTelegramError = inputs->T21inFormalTelegramError;
    point->fSciEfesSec.T22inContentTelegramError = inputs->T22inContentTelegramError;
    point->fSciEfesSec.T5inScpConnectionEstablished = inputs->T5inScpConnectionEstablished;
    point->fSciEfesSec.T10inScpConnectionTerminated = inputs->T10inScpConnectionTerminated;

    point->fSciEfesSec.InCdInitialisationRequest__8d96.HasMessage = inputs->InCdInitialisationRequest__8d96.HasMessage;
    point->fSciEfesSec.InCdInitialisationRequest__8d96.Value = inputs->InCdInitialisationRequest__8d96.Value;
    point->fSciEfesSec.InStatusReportCompleted__b457.HasMessage = inputs->InStatusReportCompleted__b457.HasMessage;
    point->fSciEfesSec.InStatusReportCompleted__b457.Value = inputs->InStatusReportCompleted__b457.Value;
    point->fSciEfesSec.InCdPdiVersionCheck__ffab.HasMessage = inputs->InCdPdiVersionCheck__ffab.HasMessage;
    point->fSciEfesSec.InCdPdiVersionCheck__ffab.Value = inputs->InCdPdiVersionCheck__ffab.Value;
    point->fSciEfesSec.InReadyForPdiConnection__6bd3.HasMessage = inputs->InReadyForPdiConnection__6bd3.HasMessage;
    point->fSciEfesSec.InReadyForPdiConnection__6bd3.Value = inputs->InReadyForPdiConnection__6bd3.Value;
    point->fSciEfesSec.InNotreadyForPdiConnection__0b73.HasMessage = inputs->InNotreadyForPdiConnection__0b73.HasMessage;
    point->fSciEfesSec.InNotreadyForPdiConnection__0b73.Value = inputs->InNotreadyForPdiConnection__0b73.Value;
    point->fSciEfesSec.InCdClosePdi__8a06.HasMessage = inputs->InCdClosePdi__8a06.HasMessage;
    point->fSciEfesSec.InCdClosePdi__8a06.Value = inputs->InCdClosePdi__8a06.Value;
    point->fSciEfesSec.InCdReleasePdiForMaintenance__3e43.HasMessage = inputs->InCdReleasePdiForMaintenance__3e43.HasMessage;
    point->fSciEfesSec.InCdReleasePdiForMaintenance__3e43.Value = inputs->InCdReleasePdiForMaintenance__3e43.Value;

    // FSciPReport
    // no inputs.

    // FSciPReceive
    point->fSciPReceive.InCdMovePoint__342e.HasMessage = inputs->InCdMovePoint__342e.HasMessage;
    point->fSciPReceive.InCdMovePoint__342e.Value = inputs->InCdMovePoint__342e.Value;

    // FObserveDegradedPointPosition
    // point->fObserveDegradedPointPosition.D10inPm1CrucialPosition.Value = inputs->D10inPm1CrucialPosition.Value;
    // point->fObserveDegradedPointPosition.D10inPm1CrucialPosition.IsSignalled = inputs->D10inPm1CrucialPosition.IsSignalled;
    // point->fObserveDegradedPointPosition.D10inPmiCrucialPosition.Value = inputs->D10inPm1CrucialPosition.Value;
    // point->fObserveDegradedPointPosition.D10inPmiCrucialPosition.IsSignalled = inputs->D10inPm1CrucialPosition.IsSignalled;
    // point->fObserveDegradedPointPosition.D10inPm1NonCrucialPosition.Value = inputs->D10inPm1CrucialPosition.Value;
    // point->fObserveDegradedPointPosition.D10inPm1NonCrucialPosition.IsSignalled = inputs->D10inPm1CrucialPosition.IsSignalled;
    // point->fObserveDegradedPointPosition.D10inPmkNonCrucialPosition.Value = inputs->D10inPm1CrucialPosition.Value;
    // point->fObserveDegradedPointPosition.D10inPmkNonCrucialPosition.IsSignalled = inputs->D10inPm1CrucialPosition.IsSignalled;

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
    point->fControlAndObserve4WPm.D27in4WPmPosition.Value = inputs->D27in4WPmPosition.Value;
    point->fControlAndObserve4WPm.D27in4WPmPosition.IsSignalled = inputs->D27in4WPmPosition.IsSignalled;
    // DataPort(bool, ) D26inInternalTriggerAbilityToMovePmAvailable;

    // FObserveMovementFailed
    // nothing

    // FControlPoint
    // nothing

    // FEstEfes
    point->fEstEfes.T1inPowerOnDetected = inputs->T1inPowerOnDetected;
    point->fEstEfes.T2inPowerOffDetected = inputs->T2inPowerOffDetected;
    point->fEstEfes.T3inReset = inputs->T3inReset;
    point->fEstEfes.T4inBooted = inputs->T4inBooted;
    point->fEstEfes.T5inSilNotFulfilled = inputs->T5inSilNotFulfilled;
    point->fEstEfes.T7inInvalidOrMissingBasicData = inputs->T7inInvalidOrMissingBasicData;
}
