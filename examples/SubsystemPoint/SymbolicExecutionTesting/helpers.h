#pragma once

#include "../point.h"

typedef struct system_inputs {
    // FSciEfesSec
    PulsedIn T20inProtocolError;
    PulsedIn T21inFormalTelegramError;
    PulsedIn T22inContentTelegramError;
    PulsedIn T5inScpConnectionEstablished;
    PulsedIn T10inScpConnectionTerminated;

    MessagePort(Message__CdInitialisationRequest__8d96) InCdInitialisationRequest__8d96;
    MessagePort(Message__StatusReportCompleted__b457) InStatusReportCompleted__b457;
    MessagePort(Message__CdPdiVersionCheck__ffab) InCdPdiVersionCheck__ffab;
    MessagePort(Message__ReadyForPdiConnection__6bd3) InReadyForPdiConnection__6bd3;
    MessagePort(Message__NotreadyForPdiConnection__0b73) InNotreadyForPdiConnection__0b73;
    MessagePort(Message__CdClosePdi__8a06) InCdClosePdi__8a06;
    MessagePort(Message__CdReleasePdiForMaintenance__3e43) InCdReleasePdiForMaintenance__3e43;

    // FSciPReport
    // no inputs.

    // FSciPReceive
    MessagePort(Message__CdMovePoint__342e) InCdMovePoint__342e;

    // FObserveDegradedPointPosition
    // DataPort(FObserveDegradedPointPosition_D10inPm1CrucialPositionValue, ) D10inPm1CrucialPosition;
    // DataPort(FObserveDegradedPointPosition_D10inPmiCrucialPositionValue, ) D10inPmiCrucialPosition;
    // DataPort(FObserveDegradedPointPosition_D10inPm1NonCrucialPositionValue, ) D10inPm1NonCrucialPosition;
    // DataPort(FObserveDegradedPointPosition_D10inPmkNonCrucialPositionValue, ) D10inPmkNonCrucialPosition;

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
    DataPort(FControlAndObserve4WPm_D27in4WPmPositionValue, ) D27in4WPmPosition;
    // DataPort(bool, ) D26inInternalTriggerAbilityToMovePmAvailable;

    // FObserveMovementFailed
    // nothing

    // FControlPoint
    // nothing

    // FEstEfes
    PulsedIn T1inPowerOnDetected;
    PulsedIn T2inPowerOffDetected;
    PulsedIn T3inReset;
    PulsedIn T4inBooted;
    PulsedIn T5inSilNotFulfilled;
    PulsedIn T7inInvalidOrMissingBasicData;
} system_inputs_t;

void apply_inputs(system_inputs_t* inputs, FSciEfesSec *fSciEfesSec, FSciPReport *fSciPReport, FSciPReceive *fSciPReceive, FObserveDegradedPointPosition *fObserveDegradedPointPosition, FObserveOverallPointPosition *fObserveOverallPointPosition, FObserveAbilityToMove *fObserveAbilityToMove, FControlAndObserve4WPm *fControlAndObserve4WPm, FObserveMovementFailed *fObserveMovementFailed, FControlPoint *fControlPoint, FEstEfes *fEstEfes);
