#include "point.h"

// fSciEfesSec->D50outPdiConnectionState -> fSciPReport->D50inPdiConnectionState
// fObserveAbilityToMove->D11outObservedAbilityToMove -> fSciPReport->D11inObservedAbilityToMove
// fObserveMovementFailed->D13outObservedMovementFailed -> fSciPReport->D13inObservedMovementFailed
// fObserveOverallPointPosition->D14outObservedPointPosition -> fSciPReport->D14inObservedPointPosition
// fObserveDegradedPointPosition->D17outObservedDegradedPointPosition -> fSciPReport->D17inObservedDegradedPointPosition
// fSciEfesSec->OutStartStatusReport__1e4e -> fSciPReport->InStartStatusReport__1e4e.Value

FSciPReport_D11inObservedAbilityToMoveValue map_FObserveAbilityToMove_D11outObservedAbilityToMove_to_FSciPReport_D11inObservedAbilityToMoveValue(FObserveAbilityToMove_D11outObservedAbilityToMoveValue value)
{
    switch (value) {
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__NULL__:
            return FSciPReport_D11inObservedAbilityToMoveValue__NULL__;
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__AbleToMove:
            return FSciPReport_D11inObservedAbilityToMoveValue__AbleToMove;
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__UnableToMove:
            return FSciPReport_D11inObservedAbilityToMoveValue__UnableToMove;
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__UNKNOWN__:
            return FSciPReport_D11inObservedAbilityToMoveValue__UNKNOWN__;
    }
}

FSciPReport_D14inObservedPointPositionValue map_FObserveOverallPointPosition_D14outObservedPointPosition_to_FSciPReport_D14inObservedPointPositionValue(FObserveOverallPointPosition_D14outObservedPointPositionValue value)
{
    switch (value) {
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__NULL__:
            return FSciPReport_D14inObservedPointPositionValue__NULL__;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__Left:
            return FSciPReport_D14inObservedPointPositionValue__Left;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__NoEndPosition:
            return FSciPReport_D14inObservedPointPositionValue__NoEndPosition;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__Right:
            return FSciPReport_D14inObservedPointPositionValue__Right;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__UnintendedPosition:
            return FSciPReport_D14inObservedPointPositionValue__UnintendedPosition;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__UNKNOWN__:
            return FSciPReport_D14inObservedPointPositionValue__UNKNOWN__;
    }
}

FSciPReport_D17inObservedDegradedPointPositionValue map_FObserveDegradedPointPosition_D17outObservedDegradedPointPosition_to_FSciPReport_D17inObservedDegradedPointPositionValue(FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue value)
{
    switch (value) {
        case FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__NULL__:
            return FSciPReport_D17inObservedDegradedPointPositionValue__NULL__;
        case FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedRight:
            return FSciPReport_D17inObservedDegradedPointPositionValue__DegradedRight;
        case FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__NotDegraded:
            return FSciPReport_D17inObservedDegradedPointPositionValue__UNKNOWN__;
        case FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedLeft:
            return FSciPReport_D17inObservedDegradedPointPositionValue__DegradedLeft;
        case FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__DegradedDenied:
            return FSciPReport_D17inObservedDegradedPointPositionValue__DegradedDenied;
        case FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__Undefined:
            return FSciPReport_D17inObservedDegradedPointPositionValue__UNKNOWN__;
        case FObserveDegradedPointPosition_D17outObservedDegradedPointPositionValue__UNKNOWN__:
            return FSciPReport_D17inObservedDegradedPointPositionValue__UNKNOWN__;
    }
}

FSciPReport_D50inPdiConnectionStateValue map_FSciEfesSec_D50outPdiConnectionState_to_FSciPReport_D50inPdiConnectionStateValue(FSciEfesSec_D50outPdiConnectionStateValue value)
{
    switch (value) {
        case FSciEfesSec_D50outPdiConnectionStateValue__NULL__:
            return FSciPReport_D50inPdiConnectionStateValue__NULL__;
        case FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdi:
            return FSciPReport_D50inPdiConnectionStateValue__UNKNOWN__;
        case FSciEfesSec_D50outPdiConnectionStateValue__Suspended:
            return FSciPReport_D50inPdiConnectionStateValue__Suspended;
        case FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi:
            return FSciPReport_D50inPdiConnectionStateValue__ReadyForPdi;
        case FSciEfesSec_D50outPdiConnectionStateValue__ReadyForInitialisation:
            return FSciPReport_D50inPdiConnectionStateValue__UNKNOWN__;
        case FSciEfesSec_D50outPdiConnectionStateValue__SendingStatus:
            return FSciPReport_D50inPdiConnectionStateValue__UNKNOWN__;
        case FSciEfesSec_D50outPdiConnectionStateValue__VersionUnequal:
            return FSciPReport_D50inPdiConnectionStateValue__UNKNOWN__;
        case FSciEfesSec_D50outPdiConnectionStateValue__Established:
            return FSciPReport_D50inPdiConnectionStateValue__Established;
        case FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdiNoScp:
            return FSciPReport_D50inPdiConnectionStateValue__UNKNOWN__;
        case FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdiNoScp:
            return FSciPReport_D50inPdiConnectionStateValue__ReadyForPdiNoScp;
        case FSciEfesSec_D50outPdiConnectionStateValue__UNKNOWN__:
            return FSciPReport_D50inPdiConnectionStateValue__UNKNOWN__;
    }
}

// fSciEfesSec->D50outPdiConnectionState -> fSciPReceive->D50inPdiConnectionState
// fObserveAbilityToMove->D11outObservedAbilityToMove -> fSciPReceive->D11inObservedAbilityToMove
// fControlPoint->D12outRequiredPmPosition -> fSciPReceive->D12inRequiredPmPosition

FSciPReceive_D11inObservedAbilityToMoveValue map_FObserveAbilityToMove_D11outObservedAbilityToMove_to_FSciPReceive_D11inObservedAbilityToMoveValue(FObserveAbilityToMove_D11outObservedAbilityToMoveValue value)
{
    switch (value) {
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__NULL__:
            return FSciPReceive_D11inObservedAbilityToMoveValue__NULL__;
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__AbleToMove:
            return FSciPReceive_D11inObservedAbilityToMoveValue__AbleToMove;
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__UnableToMove:
            return FSciPReceive_D11inObservedAbilityToMoveValue__UNKNOWN__;
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__UNKNOWN__:
            return FSciPReceive_D11inObservedAbilityToMoveValue__UNKNOWN__;
    }
}

FSciPReceive_D12inRequiredPmPositionValue map_FControlPoint_D12outRequiredPmPosition_to_FSciPReceive_D12inRequiredPmPositionValue(FControlPoint_D12outRequiredPmPositionValue value)
{
    switch (value) {
        case FControlPoint_D12outRequiredPmPositionValue__NULL__:
            return FSciPReceive_D12inRequiredPmPositionValue__NULL__;
        case FControlPoint_D12outRequiredPmPositionValue__Uncommanded:
            return FSciPReceive_D12inRequiredPmPositionValue__Uncommanded;
        case FControlPoint_D12outRequiredPmPositionValue__Left:
            return FSciPReceive_D12inRequiredPmPositionValue__UNKNOWN__;
        case FControlPoint_D12outRequiredPmPositionValue__Right:
            return FSciPReceive_D12inRequiredPmPositionValue__UNKNOWN__;
        case FControlPoint_D12outRequiredPmPositionValue__UNKNOWN__:
            return FSciPReceive_D12inRequiredPmPositionValue__UNKNOWN__;
    }
}

FSciPReceive_D50inPdiConnectionStateValue map_FSciEfesSec_D50outPdiConnectionState_to_FSciPReceive_D50inPdiConnectionStateValue(FSciEfesSec_D50outPdiConnectionStateValue value)
{
    switch (value) {
        case FSciEfesSec_D50outPdiConnectionStateValue__NULL__:
            return FSciPReceive_D50inPdiConnectionStateValue__NULL__;
        case FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdi:
            return FSciPReceive_D50inPdiConnectionStateValue__NotReadyForPdi;
        case FSciEfesSec_D50outPdiConnectionStateValue__Suspended:
            return FSciPReceive_D50inPdiConnectionStateValue__Suspended;
        case FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi:
            return FSciPReceive_D50inPdiConnectionStateValue__UNKNOWN__;
        case FSciEfesSec_D50outPdiConnectionStateValue__ReadyForInitialisation:
            return FSciPReceive_D50inPdiConnectionStateValue__UNKNOWN__;
        case FSciEfesSec_D50outPdiConnectionStateValue__SendingStatus:
            return FSciPReceive_D50inPdiConnectionStateValue__UNKNOWN__;
        case FSciEfesSec_D50outPdiConnectionStateValue__VersionUnequal:
            return FSciPReceive_D50inPdiConnectionStateValue__UNKNOWN__;
        case FSciEfesSec_D50outPdiConnectionStateValue__Established:
            return FSciPReceive_D50inPdiConnectionStateValue__Established;
        case FSciEfesSec_D50outPdiConnectionStateValue__NotReadyForPdiNoScp:
            return FSciPReceive_D50inPdiConnectionStateValue__NotReadyForPdiNoScp;
        case FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdiNoScp:
            return FSciPReceive_D50inPdiConnectionStateValue__UNKNOWN__;
        case FSciEfesSec_D50outPdiConnectionStateValue__UNKNOWN__:
            return FSciPReceive_D50inPdiConnectionStateValue__UNKNOWN__;
    }
}

// fSciPReceive->D10outRequiredPointPosition -> fControlPoint->D10inRequiredPointPosition
// fObserveAbilityToMove->D11outObservedAbilityToMove -> fControlPoint->D11inObservedAbilityToMove
// fObserveMovementFailed->D13outObservedMovementFailed -> fControlPoint->D13inObservedMovementFailed
// fObserveOverallPointPosition->D14outObservedPointPosition -> fControlPoint->D14inObservedPointPosition
// fEstEfes->D51outEstEfesState -> fControlPoint->D51inEstEfesState

FControlPoint_D10inRequiredPointPositionValue map_FSciPReceive_D10outRequiredPointPosition_to_FControlPoint_D10inRequiredPointPositionValue(FSciPReceive_D10outRequiredPointPositionValue value)
{
    switch (value) {
        case FSciPReceive_D10outRequiredPointPositionValue__NULL__:
            return FControlPoint_D10inRequiredPointPositionValue__NULL__;
        case FSciPReceive_D10outRequiredPointPositionValue__Uncommanded:
            return FControlPoint_D10inRequiredPointPositionValue__Uncommanded;
        case FSciPReceive_D10outRequiredPointPositionValue__Left:
            return FControlPoint_D10inRequiredPointPositionValue__Left;
        case FSciPReceive_D10outRequiredPointPositionValue__Right:
            return FControlPoint_D10inRequiredPointPositionValue__Right;
        case FSciPReceive_D10outRequiredPointPositionValue__UNKNOWN__:
            return FControlPoint_D10inRequiredPointPositionValue__UNKNOWN__;
    }
}

FControlPoint_D11inObservedAbilityToMoveValue map_FObserveAbilityToMove_D11outObservedAbilityToMove_to_FControlPoint_D11inObservedAbilityToMoveValue(FObserveAbilityToMove_D11outObservedAbilityToMoveValue value)
{
    switch (value) {
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__NULL__:
            return FControlPoint_D11inObservedAbilityToMoveValue__NULL__;
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__AbleToMove:
            return FControlPoint_D11inObservedAbilityToMoveValue__AbleToMove;
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__UnableToMove:
            return FControlPoint_D11inObservedAbilityToMoveValue__UnableToMove;
        case FObserveAbilityToMove_D11outObservedAbilityToMoveValue__UNKNOWN__:
            return FControlPoint_D11inObservedAbilityToMoveValue__UNKNOWN__;
    }
}

FControlPoint_D14inObservedPointPositionValue map_FObserveOverallPointPosition_D14outObservedPointPosition_to_FControlPoint_D14inObservedPointPositionValue(FObserveOverallPointPosition_D14outObservedPointPositionValue value)
{
    switch (value) {
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__NULL__:
            return FControlPoint_D14inObservedPointPositionValue__NULL__;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__Left:
            return FControlPoint_D14inObservedPointPositionValue__Left;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__NoEndPosition:
            return FControlPoint_D14inObservedPointPositionValue__UNKNOWN__;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__Right:
            return FControlPoint_D14inObservedPointPositionValue__Right;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__UnintendedPosition:
            return FControlPoint_D14inObservedPointPositionValue__UNKNOWN__;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__UNKNOWN__:
            return FControlPoint_D14inObservedPointPositionValue__UNKNOWN__;
    }
}

FControlPoint_D51inEstEfesStateValue map_FEstEfes_D51outEstEfesState_to_FControlPoint_D51inEstEfesStateValue(FEstEfes_D51outEstEfesStateValue value)
{
    switch (value) {
        case FEstEfes_D51outEstEfesStateValue__NULL__:
            return FControlPoint_D51inEstEfesStateValue__NULL__;
        case FEstEfes_D51outEstEfesStateValue__Initialising:
            return FControlPoint_D51inEstEfesStateValue__Initialising;
        case FEstEfes_D51outEstEfesStateValue__NoOperatingVoltage:
            return FControlPoint_D51inEstEfesStateValue__NoOperatingVoltage;
        case FEstEfes_D51outEstEfesStateValue__Booting:
            return FControlPoint_D51inEstEfesStateValue__Booting;
        case FEstEfes_D51outEstEfesStateValue__Operational:
            return FControlPoint_D51inEstEfesStateValue__UNKNOWN__;
        case FEstEfes_D51outEstEfesStateValue__FallbackMode:
            return FControlPoint_D51inEstEfesStateValue__FallbackMode;
        case FEstEfes_D51outEstEfesStateValue__UNKNOWN__:
            return FControlPoint_D51inEstEfesStateValue__UNKNOWN__;
    }
}

// fControlPoint->D12outRequiredPmPosition -> fObserveMovementFailed->D12inRequiredPmPosition
FObserveMovementFailed_D12inRequiredPmPositionValue map_FControlPoint_D12outRequiredPmPosition_to_FObserveMovementFailed_D12inRequiredPmPositionValue(FControlPoint_D12outRequiredPmPositionValue value)
{
    switch (value) {
        case FControlPoint_D12outRequiredPmPositionValue__NULL__:
            return FObserveMovementFailed_D12inRequiredPmPositionValue__NULL__;
        case FControlPoint_D12outRequiredPmPositionValue__Uncommanded:
            return FObserveMovementFailed_D12inRequiredPmPositionValue__Uncommanded;
        case FControlPoint_D12outRequiredPmPositionValue__Left:
            return FObserveMovementFailed_D12inRequiredPmPositionValue__Left;
        case FControlPoint_D12outRequiredPmPositionValue__Right:
            return FObserveMovementFailed_D12inRequiredPmPositionValue__Right;
        case FControlPoint_D12outRequiredPmPositionValue__UNKNOWN__:
            return FObserveMovementFailed_D12inRequiredPmPositionValue__UNKNOWN__;
    }
}

// fControlPoint->D12outRequiredPmPosition -> fControlAndObserve4WPm->D12inRequiredPmPosition
// fEstEfes->D51outEstEfesState -> fControlAndObserve4WPm->D51inEstEfesState
FControlAndObserve4WPm_D12inRequiredPmPositionValue map_FControlPoint_D12outRequiredPmPosition_to_FControlAndObserve4WPm_D12inRequiredPmPositionValue(FControlPoint_D12outRequiredPmPositionValue value)
{
    switch (value) {
        case FControlPoint_D12outRequiredPmPositionValue__NULL__:
            return FControlAndObserve4WPm_D12inRequiredPmPositionValue__NULL__;
        case FControlPoint_D12outRequiredPmPositionValue__Uncommanded:
            return FControlAndObserve4WPm_D12inRequiredPmPositionValue__Uncommanded;
        case FControlPoint_D12outRequiredPmPositionValue__Left:
            return FControlAndObserve4WPm_D12inRequiredPmPositionValue__Left;
        case FControlPoint_D12outRequiredPmPositionValue__Right:
            return FControlAndObserve4WPm_D12inRequiredPmPositionValue__Right;
        case FControlPoint_D12outRequiredPmPositionValue__UNKNOWN__:
            return FControlAndObserve4WPm_D12inRequiredPmPositionValue__UNKNOWN__;
    }
}

FControlAndObserve4WPm_D51inEstEfesStateValue map_FEstEfes_D51outEstEfesState_to_FControlAndObserve4WPm_D51inEstEfesStateValue(FEstEfes_D51outEstEfesStateValue value)
{
    switch (value) {
        case FEstEfes_D51outEstEfesStateValue__NULL__:
            return FControlAndObserve4WPm_D51inEstEfesStateValue__NULL__;
        case FEstEfes_D51outEstEfesStateValue__Initialising:
            return FControlAndObserve4WPm_D51inEstEfesStateValue__UNKNOWN__;
        case FEstEfes_D51outEstEfesStateValue__NoOperatingVoltage:
            return FControlAndObserve4WPm_D51inEstEfesStateValue__NoOperatingVoltage;
        case FEstEfes_D51outEstEfesStateValue__Booting:
            return FControlAndObserve4WPm_D51inEstEfesStateValue__Booting;
        case FEstEfes_D51outEstEfesStateValue__Operational:
            return FControlAndObserve4WPm_D51inEstEfesStateValue__UNKNOWN__;
        case FEstEfes_D51outEstEfesStateValue__FallbackMode:
            return FControlAndObserve4WPm_D51inEstEfesStateValue__FallbackMode;
        case FEstEfes_D51outEstEfesStateValue__UNKNOWN__:
            return FControlAndObserve4WPm_D51inEstEfesStateValue__UNKNOWN__;
    }
}

// fObserveOverallPointPosition->D14outObservedPointPosition -> fObserveDegradedPointPosition->D14inObservedPointPosition
// fEstEfes->D51outEstEfesState -> fObserveDegradedPointPosition->D51inEstEfesState
FObserveDegradedPointPosition_D14inObservedPointPositionValue map_FObserveOverallPointPosition_D14outObservedPointPosition_to_FObserveDegradedPointPosition_D14inObservedPointPositionValue(FObserveOverallPointPosition_D14outObservedPointPositionValue value)
{
    switch (value) {
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__NULL__:
            return FObserveDegradedPointPosition_D14inObservedPointPositionValue__NULL__;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__Left:
            return FObserveDegradedPointPosition_D14inObservedPointPositionValue__Left;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__NoEndPosition:
            return FObserveDegradedPointPosition_D14inObservedPointPositionValue__UNKNOWN__;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__Right:
            return FObserveDegradedPointPosition_D14inObservedPointPositionValue__Right;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__UnintendedPosition:
            return FObserveDegradedPointPosition_D14inObservedPointPositionValue__UNKNOWN__;
        case FObserveOverallPointPosition_D14outObservedPointPositionValue__UNKNOWN__:
            return FObserveDegradedPointPosition_D14inObservedPointPositionValue__UNKNOWN__;
    }
}

FObserveDegradedPointPosition_D51inEstEfesStateValue map_FEstEfes_D51outEstEfesState_to_FObserveDegradedPointPosition_D51inEstEfesStateValue(FEstEfes_D51outEstEfesStateValue value)
{
    switch (value) {
        case FEstEfes_D51outEstEfesStateValue__NULL__:
            return FObserveDegradedPointPosition_D51inEstEfesStateValue__NULL__;
        case FEstEfes_D51outEstEfesStateValue__Initialising:
            return FObserveDegradedPointPosition_D51inEstEfesStateValue__Initialising;
        case FEstEfes_D51outEstEfesStateValue__NoOperatingVoltage:
            return FObserveDegradedPointPosition_D51inEstEfesStateValue__NoOperatingVoltage;
        case FEstEfes_D51outEstEfesStateValue__Booting:
            return FObserveDegradedPointPosition_D51inEstEfesStateValue__Booting;
        case FEstEfes_D51outEstEfesStateValue__Operational:
            return FObserveDegradedPointPosition_D51inEstEfesStateValue__UNKNOWN__;
        case FEstEfes_D51outEstEfesStateValue__FallbackMode:
            return FObserveDegradedPointPosition_D51inEstEfesStateValue__FallbackMode;
        case FEstEfes_D51outEstEfesStateValue__UNKNOWN__:
            return FObserveDegradedPointPosition_D51inEstEfesStateValue__UNKNOWN__;
    }
}

// fEstEfes->D51outEstEfesState -> fObserveOverallPointPosition->D51inEstEfesState
// fControlAndObserve4WPm->D10outPmPosition -> fObserveOverallPointPosition->D10inPmPosition
FObserveOverallPointPosition_D51inEstEfesStateValue map_FEstEfes_D51outEstEfesState_to_FObserveOverallPointPosition_D51inEstEfesStateValue(FEstEfes_D51outEstEfesStateValue value)
{
    switch (value) {
        case FEstEfes_D51outEstEfesStateValue__NULL__:
            return FObserveOverallPointPosition_D51inEstEfesStateValue__NULL__;
        case FEstEfes_D51outEstEfesStateValue__Initialising:
            return FObserveOverallPointPosition_D51inEstEfesStateValue__UNKNOWN__;
        case FEstEfes_D51outEstEfesStateValue__NoOperatingVoltage:
            return FObserveOverallPointPosition_D51inEstEfesStateValue__NoOperatingVoltage;
        case FEstEfes_D51outEstEfesStateValue__Booting:
            return FObserveOverallPointPosition_D51inEstEfesStateValue__Booting;
        case FEstEfes_D51outEstEfesStateValue__Operational:
            return FObserveOverallPointPosition_D51inEstEfesStateValue__UNKNOWN__;
        case FEstEfes_D51outEstEfesStateValue__FallbackMode:
            return FObserveOverallPointPosition_D51inEstEfesStateValue__FallbackMode;
        case FEstEfes_D51outEstEfesStateValue__UNKNOWN__:
            return FObserveOverallPointPosition_D51inEstEfesStateValue__UNKNOWN__;
    }
}

FObserveOverallPointPosition_D10inPm1CrucialPositionValue map_FControlAndObserve4WPm_D10outPmPositionValue_to_FObserveOverallPointPosition_D10inPm1CrucialPositionValue(FControlAndObserve4WPm_D10outPmPositionValue value)
{
    switch (value) {
        case FControlAndObserve4WPm_D10outPmPositionValue__NULL__:
            return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__NULL__;
        case FControlAndObserve4WPm_D10outPmPositionValue__Left:
            return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Left;
        case FControlAndObserve4WPm_D10outPmPositionValue__Right:
            return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Right;
        case FControlAndObserve4WPm_D10outPmPositionValue__UnintendedPosition:
            return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__UnintendedPosition;
        case FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition:
            // return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__Undefined;
            return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__UNKNOWN__;
        case FControlAndObserve4WPm_D10outPmPositionValue__UNKNOWN__:
            return FObserveOverallPointPosition_D10inPm1CrucialPositionValue__UNKNOWN__;
    }
}

// fEstEfes->D51outEstEfesState -> fObserveAbilityToMove->D51inEstEfesState
FObserveAbilityToMove_D51inEstEfesStateValue map_FEstEfes_D51outEstEfesState_to_FObserveAbilityToMove_D51inEstEfesStateValue(FEstEfes_D51outEstEfesStateValue value)
{
    switch (value) {
        case FEstEfes_D51outEstEfesStateValue__NULL__:
            return FObserveAbilityToMove_D51inEstEfesStateValue__NULL__;
        case FEstEfes_D51outEstEfesStateValue__Initialising:
            return FObserveAbilityToMove_D51inEstEfesStateValue__Initialising;
        case FEstEfes_D51outEstEfesStateValue__NoOperatingVoltage:
            return FObserveAbilityToMove_D51inEstEfesStateValue__UNKNOWN__;
        case FEstEfes_D51outEstEfesStateValue__Booting:
            return FObserveAbilityToMove_D51inEstEfesStateValue__UNKNOWN__;
        case FEstEfes_D51outEstEfesStateValue__Operational:
            return FObserveAbilityToMove_D51inEstEfesStateValue__UNKNOWN__;
        case FEstEfes_D51outEstEfesStateValue__FallbackMode:
            return FObserveAbilityToMove_D51inEstEfesStateValue__UNKNOWN__;
        case FEstEfes_D51outEstEfesStateValue__UNKNOWN__:
            return FObserveAbilityToMove_D51inEstEfesStateValue__UNKNOWN__;
    }
}

void propagate(SubsystemPoint *point)
{
    point->fEstEfes.InPdiConnectionStarted__f9c3.HasMessage = point->fSciEfesSec.OutPdiConnectionStarted__f9c3.HasMessage;
    point->fEstEfes.InPdiConnectionStarted__f9c3.Value = point->fSciEfesSec.OutPdiConnectionStarted__f9c3.Value;
    point->fEstEfes.InPdiConnectionEstablished__4cbf.HasMessage = point->fSciEfesSec.OutPdiConnectionEstablished__4cbf.HasMessage;
    point->fEstEfes.InPdiConnectionEstablished__4cbf.Value = point->fSciEfesSec.OutPdiConnectionEstablished__4cbf.Value;
    point->fEstEfes.InPdiConnectionClosed__d803.HasMessage = point->fSciEfesSec.OutPdiConnectionClosed__d803.HasMessage;
    point->fEstEfes.InPdiConnectionClosed__d803.Value = point->fSciEfesSec.OutPdiConnectionClosed__d803.Value;
    point->fEstEfes.InPdiReleasedForMaintenance__3f7c.HasMessage = point->fSciEfesSec.OutPdiReleasedForMaintenance__3f7c.HasMessage;
    point->fEstEfes.InPdiReleasedForMaintenance__3f7c.Value = point->fSciEfesSec.OutPdiReleasedForMaintenance__3f7c.Value;

    point->fSciEfesSec.InStatusReportCompleted__b457.HasMessage = point->fSciPReport.OutStatusReportCompleted__b457.HasMessage;
    point->fSciEfesSec.InStatusReportCompleted__b457.Value = point->fSciPReport.OutStatusReportCompleted__b457.Value;

    point->fSciPReport.InStartStatusReport__1e4e.HasMessage = point->fSciEfesSec.OutStartStatusReport__1e4e.HasMessage;
    point->fSciPReport.InStartStatusReport__1e4e.Value = point->fSciEfesSec.OutStartStatusReport__1e4e.Value;
    point->fSciPReport.D11inObservedAbilityToMove.Value = map_FObserveAbilityToMove_D11outObservedAbilityToMove_to_FSciPReport_D11inObservedAbilityToMoveValue(point->fObserveAbilityToMove.D11outObservedAbilityToMove.Value);
    point->fSciPReport.D11inObservedAbilityToMove.IsSignalled = point->fObserveAbilityToMove.D11outObservedAbilityToMove.IsSignalled;
    point->fSciPReport.D13inObservedMovementFailed.Value = point->fObserveMovementFailed.D13outObservedMovementFailed.Value;
    point->fSciPReport.D13inObservedMovementFailed.IsSignalled = point->fObserveMovementFailed.D13outObservedMovementFailed.IsSignalled;
    point->fSciPReport.D14inObservedPointPosition.Value = map_FObserveOverallPointPosition_D14outObservedPointPosition_to_FSciPReport_D14inObservedPointPositionValue(point->fObserveOverallPointPosition.D14outObservedPointPosition.Value);
    point->fSciPReport.D14inObservedPointPosition.IsSignalled = point->fObserveOverallPointPosition.D14outObservedPointPosition.IsSignalled;
    point->fSciPReport.D17inObservedDegradedPointPosition.Value = map_FObserveDegradedPointPosition_D17outObservedDegradedPointPosition_to_FSciPReport_D17inObservedDegradedPointPositionValue(point->fObserveDegradedPointPosition.D17outObservedDegradedPointPosition.Value);
    point->fSciPReport.D17inObservedDegradedPointPosition.IsSignalled = point->fObserveDegradedPointPosition.D17outObservedDegradedPointPosition.IsSignalled;
    point->fSciPReport.D50inPdiConnectionState.Value = map_FSciEfesSec_D50outPdiConnectionState_to_FSciPReport_D50inPdiConnectionStateValue(point->fSciEfesSec.D50outPdiConnectionState.Value);
    point->fSciPReport.D50inPdiConnectionState.IsSignalled = point->fSciEfesSec.D50outPdiConnectionState.IsSignalled;

    point->fSciPReceive.D11inObservedAbilityToMove.Value = map_FObserveAbilityToMove_D11outObservedAbilityToMove_to_FSciPReceive_D11inObservedAbilityToMoveValue(point->fObserveAbilityToMove.D11outObservedAbilityToMove.Value);
    point->fSciPReceive.D11inObservedAbilityToMove.IsSignalled = point->fObserveAbilityToMove.D11outObservedAbilityToMove.IsSignalled;
    point->fSciPReceive.D12inRequiredPmPosition.Value = map_FControlPoint_D12outRequiredPmPosition_to_FSciPReceive_D12inRequiredPmPositionValue(point->fControlPoint.D12outRequiredPmPosition.Value);
    point->fSciPReceive.D12inRequiredPmPosition.IsSignalled = point->fControlPoint.D12outRequiredPmPosition.IsSignalled;
    point->fSciPReceive.D50inPdiConnectionState.Value = map_FSciEfesSec_D50outPdiConnectionState_to_FSciPReceive_D50inPdiConnectionStateValue(point->fSciEfesSec.D50outPdiConnectionState.Value);
    point->fSciPReceive.D50inPdiConnectionState.IsSignalled = point->fSciEfesSec.D50outPdiConnectionState.IsSignalled;

    point->fControlPoint.D10inRequiredPointPosition.Value = map_FSciPReceive_D10outRequiredPointPosition_to_FControlPoint_D10inRequiredPointPositionValue(point->fSciPReceive.D10outRequiredPointPosition.Value);
    point->fControlPoint.D10inRequiredPointPosition.IsSignalled = point->fSciPReceive.D10outRequiredPointPosition.IsSignalled;
    point->fControlPoint.D11inObservedAbilityToMove.Value = map_FObserveAbilityToMove_D11outObservedAbilityToMove_to_FControlPoint_D11inObservedAbilityToMoveValue(point->fObserveAbilityToMove.D11outObservedAbilityToMove.Value);
    point->fControlPoint.D11inObservedAbilityToMove.IsSignalled = point->fObserveAbilityToMove.D11outObservedAbilityToMove.IsSignalled;
    point->fControlPoint.D13inObservedMovementFailed.Value = point->fObserveMovementFailed.D13outObservedMovementFailed.Value;
    point->fControlPoint.D13inObservedMovementFailed.IsSignalled = point->fObserveMovementFailed.D13outObservedMovementFailed.IsSignalled;
    point->fControlPoint.D14inObservedPointPosition.Value = map_FObserveOverallPointPosition_D14outObservedPointPosition_to_FControlPoint_D14inObservedPointPositionValue(point->fObserveOverallPointPosition.D14outObservedPointPosition.Value);
    point->fControlPoint.D14inObservedPointPosition.IsSignalled = point->fObserveOverallPointPosition.D14outObservedPointPosition.IsSignalled;
    point->fControlPoint.D51inEstEfesState.Value = map_FEstEfes_D51outEstEfesState_to_FControlPoint_D51inEstEfesStateValue(point->fEstEfes.D51outEstEfesState.Value);
    point->fControlPoint.D51inEstEfesState.IsSignalled = point->fEstEfes.D51outEstEfesState.IsSignalled;

    point->fObserveMovementFailed.D12inRequiredPmPosition.Value = map_FControlPoint_D12outRequiredPmPosition_to_FObserveMovementFailed_D12inRequiredPmPositionValue(point->fControlPoint.D12outRequiredPmPosition.Value);
    point->fObserveMovementFailed.D12inRequiredPmPosition.IsSignalled = point->fControlPoint.D12outRequiredPmPosition.IsSignalled;

    // point->fControlAndObserve4WPm.D26inInternalTriggerAbilityToMovePmAvailable
    // point->fControlAndObserve4WPm.D27in4WPmPosition
    point->fControlAndObserve4WPm.D12inRequiredPmPosition.Value = map_FControlPoint_D12outRequiredPmPosition_to_FControlAndObserve4WPm_D12inRequiredPmPositionValue(point->fControlPoint.D12outRequiredPmPosition.Value);
    point->fControlAndObserve4WPm.D12inRequiredPmPosition.IsSignalled = point->fControlPoint.D12outRequiredPmPosition.IsSignalled;
    point->fControlAndObserve4WPm.D51inEstEfesState.Value = map_FEstEfes_D51outEstEfesState_to_FControlAndObserve4WPm_D51inEstEfesStateValue(point->fEstEfes.D51outEstEfesState.Value);
    point->fControlAndObserve4WPm.D51inEstEfesState.IsSignalled = point->fEstEfes.D51outEstEfesState.IsSignalled;

    // point->fControlAndObserve4WPm.D10outPmPosition
    // point->fObserveDegradedPointPosition.D10inPm1CrucialPosition
    // point->fObserveDegradedPointPosition.D10inPmiCrucialPosition
    // point->fObserveDegradedPointPosition.D10inPm1NonCrucialPosition
    // point->fObserveDegradedPointPosition.D10inPmkNonCrucialPosition
    point->fObserveDegradedPointPosition.D14inObservedPointPosition.Value = map_FObserveOverallPointPosition_D14outObservedPointPosition_to_FObserveDegradedPointPosition_D14inObservedPointPositionValue(point->fObserveOverallPointPosition.D14outObservedPointPosition.Value);
    point->fObserveDegradedPointPosition.D14inObservedPointPosition.IsSignalled = point->fObserveOverallPointPosition.D14outObservedPointPosition.IsSignalled;
    point->fObserveDegradedPointPosition.D51inEstEfesState.Value = map_FEstEfes_D51outEstEfesState_to_FObserveDegradedPointPosition_D51inEstEfesStateValue(point->fEstEfes.D51outEstEfesState.Value);
    point->fObserveDegradedPointPosition.D51inEstEfesState.IsSignalled = point->fEstEfes.D51outEstEfesState.IsSignalled;

    // point->fControlAndObserve4WPm.D10outPmPosition
    // point->fObserveOverallPointPosition.D10inPm1CrucialPosition
    // point->fObserveOverallPointPosition.D10inPm1NonCrucialPosition
    // point->fObserveOverallPointPosition.D10inPmiCrucialPosition
    // point->fObserveOverallPointPosition.D10inPmkNonCrucialPosition
    point->fObserveOverallPointPosition.D10inPm1CrucialPosition.Value = map_FControlAndObserve4WPm_D10outPmPositionValue_to_FObserveOverallPointPosition_D10inPm1CrucialPositionValue(point->fControlAndObserve4WPm.D10outPmPosition.Value);
    point->fObserveOverallPointPosition.D10inPm1CrucialPosition.IsSignalled = point->fControlAndObserve4WPm.D10outPmPosition.IsSignalled;
    point->fObserveOverallPointPosition.D51inEstEfesState.Value = map_FEstEfes_D51outEstEfesState_to_FObserveOverallPointPosition_D51inEstEfesStateValue(point->fEstEfes.D51outEstEfesState.Value);
    point->fObserveOverallPointPosition.D51inEstEfesState.IsSignalled = point->fEstEfes.D51outEstEfesState.IsSignalled;

    // point->fObserveAbilityToMove.D19inAbilityToMovePm1Crucial
    // point->fObserveAbilityToMove.D19inAbilityToMovePm1nCrucial
    // point->fObserveAbilityToMove.D19inAbilityToMovePm2nNonCrucial
    // point->fObserveAbilityToMove.D19inAbilityToMovePm2NonCrucial
    // point->fObserveAbilityToMove.D33inInternalTriggerAbilityToMovePointAvailable
    point->fObserveAbilityToMove.D51inEstEfesState.Value = map_FEstEfes_D51outEstEfesState_to_FObserveAbilityToMove_D51inEstEfesStateValue(point->fEstEfes.D51outEstEfesState.Value);
    point->fObserveAbilityToMove.D51inEstEfesState.IsSignalled = point->fEstEfes.D51outEstEfesState.IsSignalled;
}

void cycle(SubsystemPoint *point)
{
    // Map the SySim model execution semantics.
    // Data is propagated between state machines only at the end of a cycle.

    transition_FSciEfesSec(&point->fSciEfesSec);
    transition_FSciPReport(&point->fSciPReport);
    transition_FSciPReceive(&point->fSciPReceive);
    transition_FObserveDegradedPointPosition(&point->fObserveDegradedPointPosition);
    transition_FObserveOverallPointPosition(&point->fObserveOverallPointPosition);
    transition_FObserveAbilityToMove(&point->fObserveAbilityToMove);
    transition_FControlAndObserve4WPm(&point->fControlAndObserve4WPm);
    transition_FObserveMovementFailed(&point->fObserveMovementFailed);
    transition_FControlPoint(&point->fControlPoint);
    transition_FEstEfes(&point->fEstEfes);

    propagate(point);

    LOG("===END OF CYCLE===");
}
