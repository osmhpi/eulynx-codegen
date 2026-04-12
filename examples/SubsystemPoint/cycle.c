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

void propagate(FSciEfesSec *fSciEfesSec, FSciPReport *fSciPReport, FSciPReceive *fSciPReceive, FObserveDegradedPointPosition *fObserveDegradedPointPosition, FObserveOverallPointPosition *fObserveOverallPointPosition, FObserveAbilityToMove *fObserveAbilityToMove, FControlAndObserve4WPm *fControlAndObserve4WPm, FObserveMovementFailed *fObserveMovementFailed, FControlPoint *fControlPoint, FEstEfes *fEstEfes)
{
    fEstEfes->InPdiConnectionStarted__f9c3.HasMessage = fSciEfesSec->OutPdiConnectionStarted__f9c3.HasMessage;
    fEstEfes->InPdiConnectionStarted__f9c3.Value = fSciEfesSec->OutPdiConnectionStarted__f9c3.Value;
    fEstEfes->InPdiConnectionEstablished__4cbf.HasMessage = fSciEfesSec->OutPdiConnectionEstablished__4cbf.HasMessage;
    fEstEfes->InPdiConnectionEstablished__4cbf.Value = fSciEfesSec->OutPdiConnectionEstablished__4cbf.Value;
    fEstEfes->InPdiConnectionClosed__d803.HasMessage = fSciEfesSec->OutPdiConnectionClosed__d803.HasMessage;
    fEstEfes->InPdiConnectionClosed__d803.Value = fSciEfesSec->OutPdiConnectionClosed__d803.Value;
    fEstEfes->InPdiReleasedForMaintenance__3f7c.HasMessage = fSciEfesSec->OutPdiReleasedForMaintenance__3f7c.HasMessage;
    fEstEfes->InPdiReleasedForMaintenance__3f7c.Value = fSciEfesSec->OutPdiReleasedForMaintenance__3f7c.Value;

    fSciEfesSec->InStatusReportCompleted__b457.HasMessage = fSciPReport->OutStatusReportCompleted__b457.HasMessage;
    fSciEfesSec->InStatusReportCompleted__b457.Value = fSciPReport->OutStatusReportCompleted__b457.Value;

    fSciPReport->InStartStatusReport__1e4e.HasMessage = fSciEfesSec->OutStartStatusReport__1e4e.HasMessage;
    fSciPReport->InStartStatusReport__1e4e.Value = fSciEfesSec->OutStartStatusReport__1e4e.Value;
    fSciPReport->D11inObservedAbilityToMove.Value = map_FObserveAbilityToMove_D11outObservedAbilityToMove_to_FSciPReport_D11inObservedAbilityToMoveValue(fObserveAbilityToMove->D11outObservedAbilityToMove.Value);
    fSciPReport->D11inObservedAbilityToMove.IsSignalled = fObserveAbilityToMove->D11outObservedAbilityToMove.IsSignalled;
    fSciPReport->D13inObservedMovementFailed.Value = fObserveMovementFailed->D13outObservedMovementFailed.Value;
    fSciPReport->D13inObservedMovementFailed.IsSignalled = fObserveMovementFailed->D13outObservedMovementFailed.IsSignalled;
    fSciPReport->D14inObservedPointPosition.Value = map_FObserveOverallPointPosition_D14outObservedPointPosition_to_FSciPReport_D14inObservedPointPositionValue(fObserveOverallPointPosition->D14outObservedPointPosition.Value);
    fSciPReport->D14inObservedPointPosition.IsSignalled = fObserveOverallPointPosition->D14outObservedPointPosition.IsSignalled;
    fSciPReport->D17inObservedDegradedPointPosition.Value = map_FObserveDegradedPointPosition_D17outObservedDegradedPointPosition_to_FSciPReport_D17inObservedDegradedPointPositionValue(fObserveDegradedPointPosition->D17outObservedDegradedPointPosition.Value);
    fSciPReport->D17inObservedDegradedPointPosition.IsSignalled = fObserveDegradedPointPosition->D17outObservedDegradedPointPosition.IsSignalled;
    fSciPReport->D50inPdiConnectionState.Value = map_FSciEfesSec_D50outPdiConnectionState_to_FSciPReport_D50inPdiConnectionStateValue(fSciEfesSec->D50outPdiConnectionState.Value);
    fSciPReport->D50inPdiConnectionState.IsSignalled = fSciEfesSec->D50outPdiConnectionState.IsSignalled;

    fSciPReceive->D11inObservedAbilityToMove.Value = map_FObserveAbilityToMove_D11outObservedAbilityToMove_to_FSciPReceive_D11inObservedAbilityToMoveValue(fObserveAbilityToMove->D11outObservedAbilityToMove.Value);
    fSciPReceive->D11inObservedAbilityToMove.IsSignalled = fObserveAbilityToMove->D11outObservedAbilityToMove.IsSignalled;
    fSciPReceive->D12inRequiredPmPosition.Value = map_FControlPoint_D12outRequiredPmPosition_to_FSciPReceive_D12inRequiredPmPositionValue(fControlPoint->D12outRequiredPmPosition.Value);
    fSciPReceive->D12inRequiredPmPosition.IsSignalled = fControlPoint->D12outRequiredPmPosition.IsSignalled;
    fSciPReceive->D50inPdiConnectionState.Value = map_FSciEfesSec_D50outPdiConnectionState_to_FSciPReceive_D50inPdiConnectionStateValue(fSciEfesSec->D50outPdiConnectionState.Value);
    fSciPReceive->D50inPdiConnectionState.IsSignalled = fSciEfesSec->D50outPdiConnectionState.IsSignalled;

    fControlPoint->D10inRequiredPointPosition.Value = map_FSciPReceive_D10outRequiredPointPosition_to_FControlPoint_D10inRequiredPointPositionValue(fSciPReceive->D10outRequiredPointPosition.Value);
    fControlPoint->D10inRequiredPointPosition.IsSignalled = fSciPReceive->D10outRequiredPointPosition.IsSignalled;
    fControlPoint->D11inObservedAbilityToMove.Value = map_FObserveAbilityToMove_D11outObservedAbilityToMove_to_FControlPoint_D11inObservedAbilityToMoveValue(fObserveAbilityToMove->D11outObservedAbilityToMove.Value);
    fControlPoint->D11inObservedAbilityToMove.IsSignalled = fObserveAbilityToMove->D11outObservedAbilityToMove.IsSignalled;
    fControlPoint->D13inObservedMovementFailed.Value = fObserveMovementFailed->D13outObservedMovementFailed.Value;
    fControlPoint->D13inObservedMovementFailed.IsSignalled = fObserveMovementFailed->D13outObservedMovementFailed.IsSignalled;
    fControlPoint->D14inObservedPointPosition.Value = map_FObserveOverallPointPosition_D14outObservedPointPosition_to_FControlPoint_D14inObservedPointPositionValue(fObserveOverallPointPosition->D14outObservedPointPosition.Value);
    fControlPoint->D14inObservedPointPosition.IsSignalled = fObserveOverallPointPosition->D14outObservedPointPosition.IsSignalled;
    fControlPoint->D51inEstEfesState.Value = map_FEstEfes_D51outEstEfesState_to_FControlPoint_D51inEstEfesStateValue(fEstEfes->D51outEstEfesState.Value);
    fControlPoint->D51inEstEfesState.IsSignalled = fEstEfes->D51outEstEfesState.IsSignalled;

    fObserveMovementFailed->D12inRequiredPmPosition.Value = map_FControlPoint_D12outRequiredPmPosition_to_FObserveMovementFailed_D12inRequiredPmPositionValue(fControlPoint->D12outRequiredPmPosition.Value);
    fObserveMovementFailed->D12inRequiredPmPosition.IsSignalled = fControlPoint->D12outRequiredPmPosition.IsSignalled;

    // fControlAndObserve4WPm->D26inInternalTriggerAbilityToMovePmAvailable
    // fControlAndObserve4WPm->D27in4WPmPosition
    fControlAndObserve4WPm->D12inRequiredPmPosition.Value = map_FControlPoint_D12outRequiredPmPosition_to_FControlAndObserve4WPm_D12inRequiredPmPositionValue(fControlPoint->D12outRequiredPmPosition.Value);
    fControlAndObserve4WPm->D12inRequiredPmPosition.IsSignalled = fControlPoint->D12outRequiredPmPosition.IsSignalled;
    fControlAndObserve4WPm->D51inEstEfesState.Value = map_FEstEfes_D51outEstEfesState_to_FControlAndObserve4WPm_D51inEstEfesStateValue(fEstEfes->D51outEstEfesState.Value);
    fControlAndObserve4WPm->D51inEstEfesState.IsSignalled = fEstEfes->D51outEstEfesState.IsSignalled;

    // fControlAndObserve4WPm->D10outPmPosition
    // fObserveDegradedPointPosition->D10inPm1CrucialPosition
    // fObserveDegradedPointPosition->D10inPmiCrucialPosition
    // fObserveDegradedPointPosition->D10inPm1NonCrucialPosition
    // fObserveDegradedPointPosition->D10inPmkNonCrucialPosition
    fObserveDegradedPointPosition->D14inObservedPointPosition.Value = map_FObserveOverallPointPosition_D14outObservedPointPosition_to_FObserveDegradedPointPosition_D14inObservedPointPositionValue(fObserveOverallPointPosition->D14outObservedPointPosition.Value);
    fObserveDegradedPointPosition->D14inObservedPointPosition.IsSignalled = fObserveOverallPointPosition->D14outObservedPointPosition.IsSignalled;
    fObserveDegradedPointPosition->D51inEstEfesState.Value = map_FEstEfes_D51outEstEfesState_to_FObserveDegradedPointPosition_D51inEstEfesStateValue(fEstEfes->D51outEstEfesState.Value);
    fObserveDegradedPointPosition->D51inEstEfesState.IsSignalled = fEstEfes->D51outEstEfesState.IsSignalled;

    // fControlAndObserve4WPm->D10outPmPosition
    // fObserveOverallPointPosition->D10inPm1CrucialPosition
    // fObserveOverallPointPosition->D10inPm1NonCrucialPosition
    // fObserveOverallPointPosition->D10inPmiCrucialPosition
    // fObserveOverallPointPosition->D10inPmkNonCrucialPosition
    fObserveOverallPointPosition->D10inPm1CrucialPosition.Value = map_FControlAndObserve4WPm_D10outPmPositionValue_to_FObserveOverallPointPosition_D10inPm1CrucialPositionValue(fControlAndObserve4WPm->D10outPmPosition.Value);
    fObserveOverallPointPosition->D10inPm1CrucialPosition.IsSignalled = fControlAndObserve4WPm->D10outPmPosition.IsSignalled;
    fObserveOverallPointPosition->D51inEstEfesState.Value = map_FEstEfes_D51outEstEfesState_to_FObserveOverallPointPosition_D51inEstEfesStateValue(fEstEfes->D51outEstEfesState.Value);
    fObserveOverallPointPosition->D51inEstEfesState.IsSignalled = fEstEfes->D51outEstEfesState.IsSignalled;

    // fObserveAbilityToMove->D19inAbilityToMovePm1Crucial
    // fObserveAbilityToMove->D19inAbilityToMovePm1nCrucial
    // fObserveAbilityToMove->D19inAbilityToMovePm2nNonCrucial
    // fObserveAbilityToMove->D19inAbilityToMovePm2NonCrucial
    // fObserveAbilityToMove->D33inInternalTriggerAbilityToMovePointAvailable
    fObserveAbilityToMove->D51inEstEfesState.Value = map_FEstEfes_D51outEstEfesState_to_FObserveAbilityToMove_D51inEstEfesStateValue(fEstEfes->D51outEstEfesState.Value);
    fObserveAbilityToMove->D51inEstEfesState.IsSignalled = fEstEfes->D51outEstEfesState.IsSignalled;
}

void cycle(FSciEfesSec *fSciEfesSec, FSciPReport *fSciPReport, FSciPReceive *fSciPReceive, FObserveDegradedPointPosition *fObserveDegradedPointPosition, FObserveOverallPointPosition *fObserveOverallPointPosition, FObserveAbilityToMove *fObserveAbilityToMove, FControlAndObserve4WPm *fControlAndObserve4WPm, FObserveMovementFailed *fObserveMovementFailed, FControlPoint *fControlPoint, FEstEfes *fEstEfes)
{
    transition_FSciEfesSec(fSciEfesSec);
    transition_FSciPReport(fSciPReport);
    transition_FSciPReceive(fSciPReceive);
    transition_FObserveDegradedPointPosition(fObserveDegradedPointPosition);
    transition_FObserveOverallPointPosition(fObserveOverallPointPosition);
    transition_FObserveAbilityToMove(fObserveAbilityToMove);
    transition_FControlAndObserve4WPm(fControlAndObserve4WPm);
    transition_FObserveMovementFailed(fObserveMovementFailed);
    transition_FControlPoint(fControlPoint);
    transition_FEstEfes(fEstEfes);

    propagate(fSciEfesSec, fSciPReport, fSciPReceive, fObserveDegradedPointPosition, fObserveOverallPointPosition, fObserveAbilityToMove, fControlAndObserve4WPm, fObserveMovementFailed, fControlPoint, fEstEfes);

    LOG("===TICK===");
}
